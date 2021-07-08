use super::*;
use crate::visitor::{MutVisitor, Visitable, Visitor};

#[derive(Debug, Clone)]
pub enum StatementKind {
    VarDecl(VarDecl),
    Assignment(Assignment),
    Expression(ExpressionStm),
    Block(Block),
}

#[derive(Debug, Clone)]
pub struct Statement {
    pub kind: StatementKind,
    pub inferred_ty: Option<PrimeType>,
}

impl Visitable for Statement {
    fn accept<V: Visitor>(&self, visitor: &mut V) -> V::Result {
        match &self.kind {
            StatementKind::VarDecl(stm) => visitor.visit_var_decl(stm),
            StatementKind::Assignment(stm) => visitor.visit_assignment(stm),
            StatementKind::Expression(stm) => visitor.visit_expr_stm(stm),
            StatementKind::Block(stm) => visitor.visit_block(stm),
        }
    }

    fn accept_mut<V: MutVisitor>(&mut self, visitor: &mut V) -> V::Result {
        match &mut self.kind {
            StatementKind::VarDecl(stm) => visitor.visit_var_decl(stm),
            StatementKind::Assignment(stm) => visitor.visit_assignment(stm),
            StatementKind::Expression(stm) => visitor.visit_expr_stm(stm),
            StatementKind::Block(stm) => visitor.visit_block(stm),
        }
    }
}

#[derive(Debug, Clone)]
pub struct VarDecl {
    pub name: String,
    pub ty: Option<PrimeType>,
    pub init_val: Option<Expression>,

    pub inferred_ty: Option<PrimeType>,
}

#[derive(Debug, Clone)]
pub struct Assignment {
    pub name: String,
    pub expr: Expression,

    pub inferred_ty: Option<PrimeType>,
}

#[derive(Debug, Clone)]
pub struct ExpressionStm {
    pub expr: Expression,
    pub inferred_ty: Option<PrimeType>,
}

#[derive(Debug, Clone)]
pub struct Block {
    pub statements: Vec<Statement>,
    pub inferred_ty: Option<PrimeType>,
}
