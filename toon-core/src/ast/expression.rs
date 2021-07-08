use super::*;
use crate::visitor::{MutVisitor, Visitable, Visitor};

#[derive(Debug, Clone)]
pub enum ExpressionKind {
    Lit(Lit),
    BinaryExpr(BinaryExpr),
    UnaryExpr(UnaryExpr),
    VarRef(VarRef),
    CallExpr(CallExpr),
}

#[derive(Debug, Clone)]
pub struct Expression {
    pub kind: ExpressionKind,
    pub inferred_ty: Option<PrimeType>,
    pub pos: Pos,
}

impl Expression {
    pub fn set_inferred_ty(&mut self) -> Option<&PrimeType> {
        self.inferred_ty = match &self.kind {
            ExpressionKind::BinaryExpr(expr) => expr.inferred_ty,
            ExpressionKind::UnaryExpr(expr) => expr.inferred_ty,
            ExpressionKind::Lit(_lit) => self.inferred_ty,
            ExpressionKind::VarRef(expr) => expr.inferred_ty,
            ExpressionKind::CallExpr(expr) => expr.inferred_ty,
        };
        self.inferred_ty.as_ref()
    }
}

impl Visitable for Expression {
    fn accept<V: Visitor>(&self, visitor: &mut V) -> V::Result {
        match &self.kind {
            ExpressionKind::BinaryExpr(expr) => visitor.visit_binary_op(expr),
            ExpressionKind::UnaryExpr(expr) => visitor.visit_unary_op(expr),
            ExpressionKind::Lit(lit) => visitor.visit_lit(lit),
            ExpressionKind::VarRef(expr) => visitor.visit_var_ref(expr),
            ExpressionKind::CallExpr(expr) => visitor.visit_call_expr(expr),
        }
    }

    fn accept_mut<V: MutVisitor>(&mut self, visitor: &mut V) -> V::Result {
        match &mut self.kind {
            ExpressionKind::BinaryExpr(expr) => visitor.visit_binary_op(expr),
            ExpressionKind::UnaryExpr(expr) => visitor.visit_unary_op(expr),
            ExpressionKind::Lit(lit) => visitor.visit_lit(lit),
            ExpressionKind::VarRef(epxr) => visitor.visit_var_ref(epxr),
            ExpressionKind::CallExpr(expr) => visitor.visit_call_expr(expr),
        }
    }
}

#[derive(Debug, Clone)]
pub struct BinaryExpr {
    pub op: BinaryOp,
    pub lhs: Box<Expression>,
    pub rhs: Box<Expression>,

    pub inferred_ty: Option<PrimeType>,
    pub pos: Pos,
}

#[derive(Debug, Clone)]
pub struct UnaryExpr {
    pub op: UnaryOp,
    pub expr: Box<Expression>,

    pub inferred_ty: Option<PrimeType>,
    pub pos: Pos,
}

#[derive(Debug, Clone)]
pub struct VarRef {
    pub name: String,
    pub inferred_ty: Option<PrimeType>,
    pub pos: Pos,
}

#[derive(Debug, Clone)]
pub struct CallExpr {
    pub name: String,
    pub args: Vec<Expression>,
    pub inferred_ty: Option<PrimeType>,
    pub pos: Pos,
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
