use crate::ast::{ASTNode, AST};
use crate::token::*;
use crate::visitor::{walk_ast, Visitor};
use inkwell::builder::Builder;
use inkwell::context::Context;
use inkwell::module::Module;
use inkwell::values::FloatValue;

pub struct Generator<'a> {
    context: &'a Context,
    module: Module<'a>,
    builder: Builder<'a>,
}

impl<'a> Generator<'a> {
    pub fn new(ctx: &'a Context, name: &str) -> Self {
        let module = ctx.create_module(name);
        let builder = ctx.create_builder();
        Generator {
            context: ctx,
            module,
            builder,
        }
    }

    pub fn empty_context() -> Context {
        Context::create()
    }

    pub fn gen(&mut self, tree: &AST) -> Result<&Module<'a>, ()> {
        self.gen_main()?;

        let ret_val = walk_ast(&tree.node, self)?;
        self.builder.build_return(Some(&ret_val));

        Ok(&self.module)
    }

    fn gen_main(&mut self) -> Result<(), ()> {
        let fn_type = self.context.f64_type().fn_type(&[], false);
        let main_fn = self.module.add_function("main", fn_type, None);
        let basic_block = self.context.append_basic_block(main_fn, "entry");
        self.builder.position_at_end(basic_block);

        Ok(())
    }
}

impl<'a> Visitor<FloatValue<'a>> for Generator<'a> {
    fn visit_bin_op(
        &mut self,
        op: &BinaryOp,
        lhs: &Expression,
        rhs: &Expression,
    ) -> Result<FloatValue<'a>, ()> {
        let left_val = walk_ast(&ASTNode::NodeExpr(lhs.clone()), self)?;
        let right_val = walk_ast(&ASTNode::NodeExpr(rhs.clone()), self)?;
        let res = match &op {
            BinaryOp::Add => self.builder.build_float_add(left_val, right_val, "tmpadd"),
            BinaryOp::Sub => self.builder.build_float_sub(left_val, right_val, "tmpsub"),
            BinaryOp::Mul => self.builder.build_float_mul(left_val, right_val, "tmpmul"),
            BinaryOp::Div => self.builder.build_float_div(left_val, right_val, "tmpdiv"),
        };
        Ok(res)
    }

    fn visit_unary_op(&mut self, op: &UnaryOp, expr: &Expression) -> Result<FloatValue<'a>, ()> {
        let val = walk_ast(&ASTNode::NodeExpr(expr.clone()), self)?;
        let res = match &op {
            UnaryOp::Sub => self.builder.build_float_neg(val, "tmpunary"),
        };
        Ok(res)
    }

    fn visit_number(&mut self, num: &f64) -> Result<FloatValue<'a>, ()> {
        let val = self.context.f64_type().const_float(*num);
        Ok(val)
    }
}
