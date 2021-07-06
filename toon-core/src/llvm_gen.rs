use crate::ast::*;
use crate::visitor::{Visitable, Visitor};
use inkwell::builder::Builder;
use inkwell::context::Context;
use inkwell::module::{Linkage, Module};
use inkwell::passes::PassManager;
use inkwell::types::{BasicType, BasicTypeEnum};
use inkwell::values::{AnyValueEnum, BasicValueEnum, FunctionValue, PointerValue};
use inkwell::AddressSpace;
use std::collections::HashMap;
use std::convert::{TryFrom, TryInto};

pub struct Generator<'a> {
    context: &'a Context,
    module: Module<'a>,
    builder: Builder<'a>,
    fpm: PassManager<FunctionValue<'a>>,

    var_pointers: HashMap<String, PointerValue<'a>>,
    global_strings: HashMap<String, (String, PointerValue<'a>)>,

    string_uuid: usize,
}

impl<'a> Generator<'a> {
    pub fn new(ctx: &'a Context, name: &str) -> Self {
        let module = ctx.create_module(name);
        let builder = ctx.create_builder();
        let fpm = PassManager::create(&module);
        fpm.initialize();

        Generator {
            context: ctx,
            module,
            builder,
            fpm,

            var_pointers: HashMap::new(),
            global_strings: HashMap::new(),

            string_uuid: 0,
        }
    }

    pub fn empty_context() -> Context {
        Context::create()
    }

    pub fn gen(&mut self, prog: &Program) -> Result<&Module<'a>, ()> {
        self.link_printf()?;
        self.gen_main()?;
        for stm in prog.statements.iter() {
            stm.accept(self)?;
        }
        self.builder
            .build_return(Some(&self.context.i32_type().const_int(0, false)));
        Ok(&self.module)
    }

    fn link_printf(&mut self) -> Result<(), ()> {
        let pty = self
            .context
            .i8_type()
            .ptr_type(AddressSpace::Generic)
            .as_basic_type_enum();
        let fn_type = self.context.i32_type().fn_type(&[pty], true);
        self.module
            .add_function("printf", fn_type, Some(Linkage::External));

        Ok(())
    }

    fn gen_main(&mut self) -> Result<(), ()> {
        let fn_type = self.context.i32_type().fn_type(&[], false);
        let main_fn = self.module.add_function("main", fn_type, None);
        let basic_block = self.context.append_basic_block(main_fn, "entry");
        self.builder.position_at_end(basic_block);

        Ok(())
    }

    fn get_llvm_data_type(&self, ty: &PrimeType) -> BasicTypeEnum<'a> {
        match ty {
            PrimeType::Number => self.context.f64_type().as_basic_type_enum(),
            PrimeType::Bool => self.context.bool_type().as_basic_type_enum(),
            PrimeType::String => self
                .context
                .i8_type()
                .ptr_type(AddressSpace::Generic)
                .as_basic_type_enum(),
        }
    }

    fn next_string_uuid(&mut self) -> String {
        let id = format!("str{}", self.string_uuid);
        self.string_uuid += 1;
        id
    }
}

impl<'a> Visitor for Generator<'a> {
    type Result = Result<AnyValueEnum<'a>, ()>;

    fn visit_var_decl(
        &mut self,
        name: &str,
        ty: Option<&PrimeType>,
        init_val: Option<&Expression>,
    ) -> Self::Result {
        match (ty, init_val) {
            (None, None) => Err(()),
            (Some(ty), None) => {
                let ty = self.get_llvm_data_type(ty);
                let ptr = self.builder.build_alloca(ty, name);
                self.var_pointers.insert(name.to_string(), ptr);
                Ok(ptr.into())
            }
            (None, Some(expr)) => {
                let val: BasicValueEnum = expr.accept(self)?.try_into()?;
                let ty = val.get_type();
                let ptr = self.builder.build_alloca(ty, name);
                self.var_pointers.insert(name.to_string(), ptr);
                let instr = self.builder.build_store(ptr, val);
                Ok(instr.into())
            }
            (Some(ty), Some(expr)) => {
                let ty = self.get_llvm_data_type(ty);
                let ptr = self.builder.build_alloca(ty, name);
                self.var_pointers.insert(name.to_string(), ptr);
                self.visit_assignment(name, expr)
            }
        }
    }

    fn visit_assignment(&mut self, name: &str, expr: &Expression) -> Self::Result {
        let val: BasicValueEnum = expr.accept(self)?.try_into()?;
        let ptr = self.var_pointers.get(name).ok_or(())?;
        let instr = self.builder.build_store(*ptr, val);
        Ok(instr.into())
    }

    fn visit_binary_op(
        &mut self,
        op: &BinaryOp,
        lhs: &Expression,
        rhs: &Expression,
    ) -> Self::Result {
        let lhs = lhs.accept(self)?.into_float_value();
        let rhs = rhs.accept(self)?.into_float_value();
        let ret = match op {
            BinaryOp::Add => self.builder.build_float_add(lhs, rhs, "tmpadd").into(),
            BinaryOp::Sub => self.builder.build_float_sub(lhs, rhs, "tmpsub").into(),
            BinaryOp::Mul => self.builder.build_float_mul(lhs, rhs, "tmpmul").into(),
            BinaryOp::Div => self.builder.build_float_div(lhs, rhs, "tmpdiv").into(),
        };
        Ok(ret)
    }

    fn visit_unary_op(&mut self, op: &UnaryOp, expr: &Expression) -> Self::Result {
        let val = expr.accept(self)?.into_float_value();
        let res = match op {
            UnaryOp::Sub => self.builder.build_float_neg(val, "tmpneg").into(),
        };
        Ok(res)
    }

    fn visit_var_ref(&mut self, name: &str) -> Self::Result {
        let ptr = self.var_pointers.get(name).ok_or(())?;
        let val = self.builder.build_load(*ptr, name);
        Ok(val.into())
    }

    fn visit_lit(&mut self, lit: &Lit) -> Self::Result {
        let res = match lit {
            Lit::Number(val) => self.context.f64_type().const_float(*val).into(),
            Lit::Bool(val) => self
                .context
                .bool_type()
                .const_int(
                    match *val {
                        true => 1,
                        false => 0,
                    },
                    false,
                )
                .into(),
            Lit::String(val) => match self.global_strings.get(val) {
                Some(record) => record.1.into(),
                None => {
                    let id = self.next_string_uuid();
                    let ptr = self
                        .builder
                        .build_global_string_ptr(val, &id)
                        .as_pointer_value();
                    self.global_strings.insert(val.clone(), (id, ptr));
                    ptr.into()
                }
            },
        };
        Ok(res)
    }

    fn visit_call_expr(&mut self, name: &str, args: &[Expression]) -> Self::Result {
        let called_fn = self.module.get_function(name).ok_or(())?;
        let compiled_args = args
            .iter()
            .map(|a| a.accept(self))
            .map(|res| res.map(|a| BasicValueEnum::try_from(a).map_err(|_| ())))
            .flatten()
            .collect::<Result<Vec<_>, ()>>()?;
        let ret = self
            .builder
            .build_call(called_fn, compiled_args.as_slice(), name)
            .try_as_basic_value()
            .left()
            .ok_or(())?;
        Ok(ret.into())
    }
}
