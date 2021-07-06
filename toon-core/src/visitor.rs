use crate::ast::ASTNode;
use crate::token::*;
use tree_sitter::Node;

pub trait Visitor<T> {
    fn visit_bin_op(&mut self, op: &BinaryOp, lhs: &Expression, rhs: &Expression) -> Result<T, ()>;
    fn visit_unary_op(&mut self, op: &UnaryOp, expr: &Expression) -> Result<T, ()>;
    fn visit_number(&mut self, num: &f64) -> Result<T, ()>;
}

pub fn walk_ast<T>(node: &ASTNode, visitor: &mut impl Visitor<T>) -> Result<T, ()> {
    match node {
        ASTNode::NodeExpr(expr) => match &expr {
            Expression::BinaryExpr { lhs, rhs, op } => visitor.visit_bin_op(op, lhs, rhs),
            Expression::UnaryExpr { expr, op } => visitor.visit_unary_op(op, expr),
            Expression::NumLit(num) => visitor.visit_number(num),
        },
    }
}

pub fn walk_tree_sitter(
    node: &Node,
    src: &[u8],
    visitor: &mut impl Visitor<ASTNode>,
) -> Result<ASTNode, ()> {
    if node.is_missing() {
        return Err(());
    }
    if !node.is_named() || node.kind() == "comment" {
        let next_node = node.next_named_sibling().ok_or(())?;
        return walk_tree_sitter(&next_node, src, visitor);
    }

    match node.kind() {
        "root" => {
            let next_node = node.named_child(0).ok_or(())?;
            walk_tree_sitter(&next_node, src, visitor)
        }
        "binary_expression" => {
            let left_node = node.child_by_field_name("left").ok_or(())?;
            let right_node = node.child_by_field_name("right").ok_or(())?;
            let op_node = node.child_by_field_name("operator").ok_or(())?;

            let left_expr = match walk_tree_sitter(&left_node, src, visitor)? {
                ASTNode::NodeExpr(expr) => expr,
                #[allow(unreachable_patterns)]
                _ => return Err(()),
            };
            let right_expr = match walk_tree_sitter(&right_node, src, visitor)? {
                ASTNode::NodeExpr(expr) => expr,
                #[allow(unreachable_patterns)]
                _ => return Err(()),
            };

            visitor.visit_bin_op(
                &BinaryOp::from(op_node, src).ok_or(())?,
                &left_expr,
                &right_expr,
            )
        }
        "unary_expression" => {
            let expr_node = node.child_by_field_name("operand").ok_or(())?;
            let op_node = node.child_by_field_name("operator").ok_or(())?;

            let expr = match walk_tree_sitter(&expr_node, src, visitor)? {
                ASTNode::NodeExpr(expr) => expr,
                #[allow(unreachable_patterns)]
                _ => return Err(()),
            };
            visitor.visit_unary_op(&UnaryOp::from(op_node, src).ok_or(())?, &expr)
        }
        "number_lit" => {
            let snip = node.utf8_text(src).map_err(|_| ())?;
            let val: f64 = snip.parse().map_err(|_| ())?;
            visitor.visit_number(&val)
        }

        kind => {
            println!("Unknown kind {}", kind);
            Err(())
        }
    }
}
