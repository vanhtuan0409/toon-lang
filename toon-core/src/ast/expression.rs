use super::*;
use crate::visitor::{Visitable, Visitor};

#[derive(Debug, Clone)]
pub enum ExpressionKind {
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

#[derive(Debug, Clone)]
pub struct Expression {
    pub kind: ExpressionKind,
    pub inferred_ty: Option<PrimeType>,
}

impl Visitable for Expression {
    fn accept<V: Visitor>(&self, visitor: &mut V) -> V::Result {
        match &self.kind {
            ExpressionKind::BinaryExpr { op, lhs, rhs } => visitor.visit_binary_op(op, lhs, rhs),
            ExpressionKind::UnaryExpr { op, expr } => visitor.visit_unary_op(op, expr),
            ExpressionKind::Lit(lit) => visitor.visit_lit(lit),
            ExpressionKind::VarRef(name) => visitor.visit_var_ref(name),
            ExpressionKind::CallExpr { name, args } => {
                visitor.visit_call_expr(name, args.as_slice())
            }
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
