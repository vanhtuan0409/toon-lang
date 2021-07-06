use tree_sitter::Node;

#[derive(Debug, Clone)]
pub enum UnaryOp {
    Sub,
}

impl UnaryOp {
    pub fn from(n: Node, src: &[u8]) -> Option<UnaryOp> {
        let op = n.utf8_text(src).ok()?;
        match op {
            "-" => Some(UnaryOp::Sub),
            _ => None,
        }
    }
}

#[derive(Debug, Clone)]
pub enum BinaryOp {
    Add,
    Sub,
    Mul,
    Div,
}

impl BinaryOp {
    pub fn from(n: Node, src: &[u8]) -> Option<BinaryOp> {
        let op = n.utf8_text(src).ok()?;
        match op {
            "+" => Some(BinaryOp::Add),
            "-" => Some(BinaryOp::Sub),
            "*" => Some(BinaryOp::Mul),
            "/" => Some(BinaryOp::Div),
            _ => None,
        }
    }
}

#[derive(Debug, Clone)]
pub enum Expression {
    NumLit(f64),
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
}

#[derive(Debug, Clone)]
pub enum PrimeType {
    Bool,
    Number,
}

#[derive(Debug, Clone)]
pub enum Statement {
    VarDecl {
        name: String,
        var_type: PrimeType,
        expr: Expression,
    },
}
