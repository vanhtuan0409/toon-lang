use super::*;
use crate::visitor::{Visitable, Visitor};

#[derive(Debug, Clone)]
pub enum Statement {
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
}

impl Visitable for Statement {
    fn accept<V: Visitor>(&self, visitor: &mut V) -> V::Result {
        match self {
            Self::VarDecl { name, ty, init_val } => {
                visitor.visit_var_decl(name, ty.as_ref(), init_val.as_ref())
            }
            Self::Assignment { name, expr } => visitor.visit_assignment(name, expr),
            Self::Expression(expr) => expr.accept(visitor),
        }
    }
}
