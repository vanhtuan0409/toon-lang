use crate::ast::*;

pub trait Visitable {
    fn accept<V: Visitor>(&self, visitor: &mut V) -> V::Result;
}

pub trait Visitor {
    type Result;

    fn visit_var_decl(
        &mut self,
        name: &str,
        ty: Option<&PrimeType>,
        init_val: Option<&Expression>,
    ) -> Self::Result;
    fn visit_binary_op(
        &mut self,
        op: &BinaryOp,
        lhs: &Expression,
        rhs: &Expression,
    ) -> Self::Result;
    fn visit_unary_op(&mut self, op: &UnaryOp, expr: &Expression) -> Self::Result;
    fn visit_var_ref(&mut self, name: &str) -> Self::Result;
    fn visit_lit(&mut self, lit: &Lit) -> Self::Result;
    fn visit_call_expr(&mut self, name: &str, args: &[Expression]) -> Self::Result;
    fn visit_assignment(&mut self, name: &str, expr: &Expression) -> Self::Result;
}
