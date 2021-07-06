use crate::token::*;
use crate::visitor::{walk_tree_sitter, Visitor};
use tree_sitter::{Parser, Tree};
use tree_sitter_toon;

#[derive(Debug)]
pub enum ASTNode {
    NodeExpr(Expression),
}

pub struct AST<'a> {
    pub src: &'a [u8],
    pub tree: Tree,
    pub node: ASTNode,
}

impl<'a> AST<'a> {}

pub struct ASTBuilder {}

impl ASTBuilder {
    pub fn new() -> Self {
        ASTBuilder {}
    }

    pub fn build<'a>(&mut self, src: &'a [u8]) -> Result<AST<'a>, ()> {
        let mut parser = Parser::new();
        parser
            .set_language(tree_sitter_toon::language())
            .map_err(|_| ())?;
        let tree = parser.parse(src, None).ok_or(())?;
        let node = walk_tree_sitter(&tree.root_node(), src, self)?;
        Ok(AST { src, tree, node })
    }
}

impl Visitor<ASTNode> for ASTBuilder {
    fn visit_bin_op(
        &mut self,
        op: &BinaryOp,
        lhs: &Expression,
        rhs: &Expression,
    ) -> Result<ASTNode, ()> {
        Ok(ASTNode::NodeExpr(Expression::BinaryExpr {
            lhs: Box::new(lhs.clone()),
            rhs: Box::new(rhs.clone()),
            op: op.clone(),
        }))
    }

    fn visit_unary_op(&mut self, op: &UnaryOp, expr: &Expression) -> Result<ASTNode, ()> {
        Ok(ASTNode::NodeExpr(Expression::UnaryExpr {
            expr: Box::new(expr.clone()),
            op: op.clone(),
        }))
    }

    fn visit_number(&mut self, num: &f64) -> Result<ASTNode, ()> {
        Ok(ASTNode::NodeExpr(Expression::NumLit(*num)))
    }
}
