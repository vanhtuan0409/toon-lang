use crate::ast::*;
use snailquote::unescape;
use tree_sitter::{Node, Parser};
use tree_sitter_toon as toon;

pub fn parse(src: &[u8]) -> Result<Program, ()> {
    let mut parser = Parser::new();
    parser.set_language(toon::language()).map_err(|_| ())?;
    let tree = parser.parse(src, None).ok_or(())?;
    let root = tree.root_node();

    let mut statements = vec![];
    let child_count = root.named_child_count();
    for i in 0..child_count {
        let node = root.named_child(i).unwrap();
        if is_extra_node(&node) {
            continue;
        }

        let stm = parse_statement(node, src)?;
        statements.push(stm);
    }

    Ok(Program { statements })
}

fn parse_statement(node: Node, src: &[u8]) -> Result<Statement, ()> {
    let child = node.named_child(0).ok_or(())?;
    match child.kind() {
        "var_decl" => parse_var_decl(child, src),
        "assign_stm" => parse_assign_stm(child, src),
        "block" => parse_block(child, src),
        _ => {
            let expr = parse_expr(child, src)?;
            let pos = (node.start_byte(), node.end_byte());
            Ok(Statement {
                kind: StatementKind::Expression(ExpressionStm {
                    expr,
                    inferred_ty: None,
                    pos,
                }),
                inferred_ty: None,
                pos,
            })
        }
    }
}

fn parse_var_decl(node: Node, src: &[u8]) -> Result<Statement, ()> {
    let pos = (node.start_byte(), node.end_byte());
    let name = node
        .child_by_field_name("var_name")
        .ok_or(())?
        .utf8_text(src)
        .map_err(|_| ())?
        .to_string();
    let ty: Option<PrimeType> = match node.child_by_field_name("var_type") {
        Some(n) => Some(parse_prime_type(n, src)?),
        None => None,
    };

    let init_val: Option<Expression> = match node.child_by_field_name("var_expr") {
        Some(n) => Some(parse_expr(n, src)?),
        None => None,
    };

    Ok(Statement {
        kind: StatementKind::VarDecl(VarDecl {
            name,
            ty,
            init_val,
            inferred_ty: None,
            pos,
        }),
        inferred_ty: None,
        pos,
    })
}

fn parse_assign_stm(node: Node, src: &[u8]) -> Result<Statement, ()> {
    let pos = (node.start_byte(), node.end_byte());
    let name = node
        .child_by_field_name("var_name")
        .ok_or(())?
        .utf8_text(src)
        .map_err(|_| ())?
        .to_string();
    let expr_node = node.child_by_field_name("var_expr").ok_or(())?;
    let expr = parse_expr(expr_node, src)?;
    Ok(Statement {
        kind: StatementKind::Assignment(Assignment {
            name,
            expr,
            inferred_ty: None,
            pos,
        }),
        inferred_ty: None,
        pos,
    })
}

fn parse_block(node: Node, src: &[u8]) -> Result<Statement, ()> {
    let pos = (node.start_byte(), node.end_byte());
    let child_count = node.named_child_count();
    let mut ret: Vec<Statement> = vec![];
    for i in 0..child_count {
        let child = node.named_child(i).unwrap();
        if is_extra_node(&child) {
            continue;
        }
        ret.push(parse_statement(child, src)?);
    }

    Ok(Statement {
        kind: StatementKind::Block(Block {
            statements: ret,
            inferred_ty: None,
            pos,
        }),
        inferred_ty: None,
        pos,
    })
}

fn parse_prime_type(node: Node, src: &[u8]) -> Result<PrimeType, ()> {
    let ty = node.utf8_text(src).map_err(|_| ())?;
    match ty {
        "number" => Ok(PrimeType::Number),
        "bool" => Ok(PrimeType::Bool),
        "string" => Ok(PrimeType::String),
        "void" => Ok(PrimeType::Void),
        _ => Err(()),
    }
}

fn parse_expr(node: Node, src: &[u8]) -> Result<Expression, ()> {
    match node.kind() {
        "binary_expression" => parse_binary_expr(node, src),
        "unary_expression" => parse_unary_expr(node, src),
        "number_lit" | "bool_lit" | "string_lit" => parse_lit(node, src),
        "ident" => parse_var_ref(node, src),
        "parenthesised_expression" => {
            let inner = node.child_by_field_name("inner").ok_or(())?;
            parse_expr(inner, src)
        }
        "call_expression" => parse_call_expr(node, src),
        _ => Err(()),
    }
}

fn parse_binary_expr(node: Node, src: &[u8]) -> Result<Expression, ()> {
    let left_node = node.child_by_field_name("left").ok_or(())?;
    let right_node = node.child_by_field_name("right").ok_or(())?;
    let op_node = node.child_by_field_name("operator").ok_or(())?;
    let op = match op_node.utf8_text(src).map_err(|_| ())? {
        "+" => BinaryOp::Add,
        "-" => BinaryOp::Sub,
        "*" => BinaryOp::Mul,
        "/" => BinaryOp::Div,
        _ => {
            return Err(());
        }
    };

    let pos = (node.start_byte(), node.end_byte());
    Ok(Expression {
        kind: ExpressionKind::BinaryExpr(BinaryExpr {
            lhs: Box::new(parse_expr(left_node, src)?),
            rhs: Box::new(parse_expr(right_node, src)?),
            op,
            inferred_ty: None,
            pos,
        }),
        inferred_ty: None,
        pos,
    })
}

fn parse_unary_expr(node: Node, src: &[u8]) -> Result<Expression, ()> {
    let operand_node = node.child_by_field_name("operand").ok_or(())?;
    let op_node = node.child_by_field_name("operator").ok_or(())?;
    let op = match op_node.utf8_text(src).map_err(|_| ())? {
        "-" => UnaryOp::Sub,
        _ => {
            return Err(());
        }
    };

    let pos = (node.start_byte(), node.end_byte());
    Ok(Expression {
        kind: ExpressionKind::UnaryExpr(UnaryExpr {
            expr: Box::new(parse_expr(operand_node, src)?),
            op,
            inferred_ty: None,
            pos,
        }),
        inferred_ty: None,
        pos,
    })
}

fn parse_lit(node: Node, src: &[u8]) -> Result<Expression, ()> {
    let pos = (node.start_byte(), node.end_byte());
    match node.kind() {
        "number_lit" => {
            let snip = node.utf8_text(src).map_err(|_| ())?;
            let val: f64 = snip.parse().map_err(|_| ())?;
            Ok(Expression {
                kind: ExpressionKind::Lit(Lit::Number(val)),
                inferred_ty: Some(PrimeType::Number),
                pos,
            })
        }
        "bool_lit" => {
            let snip = node.utf8_text(src).map_err(|_| ())?.to_lowercase();
            let val = match snip.as_str() {
                "true" => true,
                "false" => false,
                _ => return Err(()),
            };
            Ok(Expression {
                kind: ExpressionKind::Lit(Lit::Bool(val)),
                inferred_ty: Some(PrimeType::Bool),
                pos,
            })
        }
        "string_lit" => {
            let snip = node.utf8_text(src).map_err(|_| ())?;
            let snip = unescape(snip).map_err(|_| ())?;
            Ok(Expression {
                kind: ExpressionKind::Lit(Lit::String(snip)),
                inferred_ty: Some(PrimeType::String),
                pos,
            })
        }
        _ => Err(()),
    }
}

fn parse_var_ref(node: Node, src: &[u8]) -> Result<Expression, ()> {
    let var_name = node.utf8_text(src).map_err(|_| ())?.to_string();
    let pos = (node.start_byte(), node.end_byte());
    Ok(Expression {
        kind: ExpressionKind::VarRef(VarRef {
            name: var_name,
            inferred_ty: None,
            pos,
        }),
        inferred_ty: None,
        pos,
    })
}

fn parse_call_expr(node: Node, src: &[u8]) -> Result<Expression, ()> {
    let func_name = node
        .child_by_field_name("func_name")
        .ok_or(())?
        .utf8_text(src)
        .map_err(|_| ())?
        .to_string();
    let args_node = node.child_by_field_name("args").ok_or(())?;
    let args = parse_arg_list(args_node, src)?;
    let pos = (node.start_byte(), node.end_byte());
    Ok(Expression {
        kind: ExpressionKind::CallExpr(CallExpr {
            name: func_name,
            args,
            inferred_ty: None,
            pos,
        }),
        inferred_ty: None,
        pos,
    })
}

fn parse_arg_list(node: Node, src: &[u8]) -> Result<Vec<Expression>, ()> {
    if node.kind() != "argument_list" {
        return Err(());
    }

    let mut ret = vec![];
    let child_count = node.named_child_count();
    for i in 0..child_count {
        let child = node.named_child(i).unwrap();
        ret.push(parse_expr(child, src)?);
    }

    Ok(ret)
}

fn is_extra_node(node: &Node) -> bool {
    return !node.is_named() || node.kind() == "comment";
}
