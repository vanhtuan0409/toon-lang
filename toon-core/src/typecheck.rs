use crate::ast::*;
use crate::scope::ScopeManager;
use crate::visitor::{MutVisitor, Visitable};

pub struct TypeChecker {
    scopes: ScopeManager<PrimeType>,
}

impl TypeChecker {
    pub fn new() -> Self {
        let mut scopes = ScopeManager::new();
        scopes.enter_scope();
        // register printf function symbols
        scopes.register_global("printf".to_string(), PrimeType::Number);

        TypeChecker { scopes }
    }

    pub fn check(&mut self, prog: &mut Program, src: &[u8]) -> Result<(), String> {
        if let Err((pos, msg)) = self.internal_check(prog) {
            let code = std::str::from_utf8(&src[pos.0..pos.1]).unwrap();
            let err = format!("{}. Code:\n---\n{}\n---", msg, code);
            return Err(err);
        }
        Ok(())
    }

    fn internal_check(&mut self, prog: &mut Program) -> Result<(), (Pos, String)> {
        for stm in prog.statements.iter_mut() {
            self.visit_statement(stm)?;
        }
        Ok(())
    }

    pub fn infer_default_lit(&self, ty: &PrimeType) -> Lit {
        match ty {
            PrimeType::Bool => Lit::Bool(false),
            PrimeType::Number => Lit::Number(0.0),
            PrimeType::String => Lit::String("".to_string()),
            PrimeType::Void => {
                panic!("Cannot infer default value for void type")
            }
        }
    }
}

impl MutVisitor for TypeChecker {
    type Result = Result<(), (Pos, String)>;

    fn visit_statement(&mut self, stm: &mut Statement) -> Self::Result {
        stm.accept_mut(self)?;
        let pos = stm.pos;
        stm.set_inferred_ty()
            .ok_or((pos, "Unable to infer type of statement".to_string()))?;
        Ok(())
    }

    fn visit_var_decl(&mut self, stm: &mut VarDecl) -> Self::Result {
        match (&mut stm.ty, &mut stm.init_val) {
            (None, None) => Err((stm.pos, "Invalid syntax of var decl".to_string())),
            (Some(ty), None) => {
                // inferred val type by annocation
                stm.inferred_ty = Some(*ty);

                // inferred default value from type
                stm.init_val = Some(Expression {
                    inferred_ty: Some(*ty),
                    kind: ExpressionKind::Lit(self.infer_default_lit(ty)),
                    pos: stm.pos,
                });
                self.scopes.register_local(stm.name.clone(), *ty);
                Ok(())
            }
            (None, Some(expr)) => {
                // inferred val type by init val
                self.visit_expr(expr)?;
                let ty = expr.inferred_ty.ok_or((
                    expr.pos,
                    "Unable to infer type of init value in var decl".to_string(),
                ))?;
                stm.inferred_ty = Some(ty);
                self.scopes.register_local(stm.name.clone(), ty);
                Ok(())
            }
            (Some(ty), Some(expr)) => {
                // type check val type and init val
                self.visit_expr(expr)?;
                let init_val_ty = expr.inferred_ty.ok_or((
                    expr.pos,
                    "Unable to infer type of init value in var decl".to_string(),
                ))?;
                if ty != &init_val_ty {
                    return Err((
                        stm.pos,
                        "Mismatched type between var and init value in var decl".to_string(),
                    ));
                }
                stm.inferred_ty = Some(*ty);
                self.scopes.register_local(stm.name.clone(), *ty);
                Ok(())
            }
        }
    }

    fn visit_assignment(&mut self, stm: &mut Assignment) -> Self::Result {
        self.visit_expr(&mut stm.expr)?;
        let val_ty = stm.expr.inferred_ty.ok_or((
            stm.expr.pos,
            "Unable to infer type of expr in assignment".to_string(),
        ))?;
        let ty = self
            .scopes
            .lookup(&stm.name)
            .ok_or((stm.pos, format!("Un-identified var {}", &stm.name)))?;
        if ty != &val_ty {
            return Err((
                stm.pos,
                "Mismatched type between var and value in assignment".to_string(),
            ));
        }
        stm.inferred_ty = Some(*ty);
        Ok(())
    }

    fn visit_block(&mut self, stm: &mut Block) -> Self::Result {
        self.scopes.enter_scope();
        for stm in &mut stm.statements {
            self.visit_statement(stm)?;
        }
        self.scopes.leave_scope();
        stm.inferred_ty = Some(PrimeType::Void);
        Ok(())
    }

    fn visit_expr_stm(&mut self, stm: &mut ExpressionStm) -> Self::Result {
        self.visit_expr(&mut stm.expr)?;
        let ty = stm.expr.inferred_ty.ok_or((
            stm.expr.pos,
            "Unable to infer type of expression".to_string(),
        ))?;
        stm.inferred_ty = Some(ty);
        Ok(())
    }

    fn visit_expr(&mut self, expr: &mut Expression) -> Self::Result {
        expr.accept_mut(self)?;
        let pos = expr.pos;
        expr.set_inferred_ty()
            .ok_or((pos, "Unable to infer type of expression".to_string()))?;
        Ok(())
    }

    fn visit_binary_op(&mut self, expr: &mut BinaryExpr) -> Self::Result {
        self.visit_expr(&mut expr.lhs)?;
        self.visit_expr(&mut expr.rhs)?;
        let left_ty = expr
            .lhs
            .inferred_ty
            .ok_or((expr.lhs.pos, "Unable to infer type of lhs".to_string()))?;
        let right_ty = expr
            .rhs
            .inferred_ty
            .ok_or((expr.rhs.pos, "Unable to infer type of rhs".to_string()))?;
        if left_ty != right_ty {
            return Err((
                expr.pos,
                "Mismatched type between lhs and rhs of binary op".to_string(),
            ));
        }
        let op_ty = match &expr.op {
            BinaryOp::Add => PrimeType::Number,
            BinaryOp::Sub => PrimeType::Number,
            BinaryOp::Mul => PrimeType::Number,
            BinaryOp::Div => PrimeType::Number,
        };
        if left_ty != op_ty {
            return Err((expr.pos, "Mismatched type between value and op".to_string()));
        }
        expr.inferred_ty = Some(left_ty);
        Ok(())
    }

    fn visit_unary_op(&mut self, expr: &mut UnaryExpr) -> Self::Result {
        self.visit_expr(&mut expr.expr)?;
        let val_ty = expr.expr.inferred_ty.ok_or((
            expr.expr.pos,
            "Unable to inferred type of val in unary op".to_string(),
        ))?;
        let op_ty = match &expr.op {
            UnaryOp::Sub => PrimeType::Number,
        };
        if val_ty != op_ty {
            return Err((expr.pos, "Mismatched type between value and op".to_string()));
        }
        expr.inferred_ty = Some(val_ty);
        Ok(())
    }

    fn visit_var_ref(&mut self, expr: &mut VarRef) -> Self::Result {
        let var_ty = self
            .scopes
            .lookup(&expr.name)
            .ok_or((expr.pos, format!("Un-identified var {}", &expr.name)))?;
        expr.inferred_ty = Some(*var_ty);
        Ok(())
    }

    fn visit_lit(&mut self, _lit: &mut Lit) -> Self::Result {
        // Expect lit is already inferred type during parsing
        Ok(())
    }

    fn visit_call_expr(&mut self, expr: &mut CallExpr) -> Self::Result {
        let var_ty = self
            .scopes
            .lookup(&expr.name)
            .ok_or((expr.pos, format!("Un-identified var {}", &expr.name)))?;
        expr.inferred_ty = Some(*var_ty);
        Ok(())
    }
}
