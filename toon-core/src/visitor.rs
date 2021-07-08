use crate::ast::*;

pub trait Visitable {
    fn accept<V: Visitor>(&self, visitor: &mut V) -> V::Result;
    fn accept_mut<V: MutVisitor>(&mut self, visitor: &mut V) -> V::Result;
}

pub trait Visitor {
    type Result;

    // Visit statement
    fn visit_statement(&mut self, stm: &Statement) -> Self::Result;
    fn visit_var_decl(&mut self, stm: &VarDecl) -> Self::Result;
    fn visit_assignment(&mut self, stm: &Assignment) -> Self::Result;
    fn visit_block(&mut self, stm: &Block) -> Self::Result;
    fn visit_expr_stm(&mut self, stm: &ExpressionStm) -> Self::Result;

    // Visit expression
    fn visit_expr(&mut self, expr: &Expression) -> Self::Result;
    fn visit_binary_op(&mut self, expr: &BinaryExpr) -> Self::Result;
    fn visit_unary_op(&mut self, expr: &UnaryExpr) -> Self::Result;
    fn visit_var_ref(&mut self, expr: &VarRef) -> Self::Result;
    fn visit_lit(&mut self, lit: &Lit) -> Self::Result;
    fn visit_call_expr(&mut self, expr: &CallExpr) -> Self::Result;
}

pub trait MutVisitor {
    type Result;

    // Visit statement
    fn visit_statement(&mut self, stm: &mut Statement) -> Self::Result;
    fn visit_var_decl(&mut self, stm: &mut VarDecl) -> Self::Result;
    fn visit_assignment(&mut self, stm: &mut Assignment) -> Self::Result;
    fn visit_block(&mut self, stm: &mut Block) -> Self::Result;
    fn visit_expr_stm(&mut self, stm: &mut ExpressionStm) -> Self::Result;

    // Visit expression
    fn visit_expr(&mut self, expr: &mut Expression) -> Self::Result;
    fn visit_binary_op(&mut self, expr: &mut BinaryExpr) -> Self::Result;
    fn visit_unary_op(&mut self, expr: &mut UnaryExpr) -> Self::Result;
    fn visit_var_ref(&mut self, expr: &mut VarRef) -> Self::Result;
    fn visit_lit(&mut self, lit: &mut Lit) -> Self::Result;
    fn visit_call_expr(&mut self, expr: &mut CallExpr) -> Self::Result;
}
