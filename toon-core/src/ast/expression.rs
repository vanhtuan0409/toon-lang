use super::*;
use crate::visitor::{Visitable, Visitor};

#[derive(Debug, Clone)]
pub enum Expression {
    Lit(Lit),
    BinaryExpr {
        lhs: Box<Expression>,
        rhs: Box<Expression>,
        op: BinaryOp,
    },
    UnaryExpr {
        expr: Box<Expression>,
        op: UnaryOp,
    },
    VarRef(String),
    CallExpr {
        name: String,
        args: Vec<Expression>,
    },
}

impl Visitable for Expression {
    fn accept<V: Visitor>(&self, visitor: &mut V) -> V::Result {
        match self {
            Self::BinaryExpr { op, lhs, rhs } => visitor.visit_binary_op(op, lhs, rhs),
            Self::UnaryExpr { op, expr } => visitor.visit_unary_op(op, expr),
            Self::Lit(lit) => visitor.visit_lit(lit),
            Self::VarRef(name) => visitor.visit_var_ref(name),
            Self::CallExpr { name, args } => visitor.visit_call_expr(name, args.as_slice()),
        }
    }
}

#[derive(Debug, Clone)]
pub enum UnaryOp {
    Sub,
}

#[derive(Debug, Clone)]
pub enum BinaryOp {
    Add,
    Sub,
    Mul,
    Div,
}
