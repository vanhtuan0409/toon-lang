use super::*;
use crate::visitor::{Visitable, Visitor};

#[derive(Debug, Clone)]
pub enum StatementKind {
    VarDecl {
        name: String,
        ty: Option<PrimeType>,
        init_val: Option<Expression>,
    },

    Assignment {
        name: String,
        expr: Expression,
    },

    Expression(Expression),

    Block(Vec<Statement>),
}

#[derive(Debug, Clone)]
pub struct Statement {
    pub kind: StatementKind,
    pub inferred_ty: Option<PrimeType>,
}

impl Visitable for Statement {
    fn accept<V: Visitor>(&self, visitor: &mut V) -> V::Result {
        match &self.kind {
            StatementKind::VarDecl { name, ty, init_val } => {
                visitor.visit_var_decl(name, ty.as_ref(), init_val.as_ref())
            }
            StatementKind::Assignment { name, expr } => visitor.visit_assignment(name, expr),
            StatementKind::Expression(expr) => expr.accept(visitor),
            StatementKind::Block(statements) => visitor.visit_block(&statements),
        }
    }
}
