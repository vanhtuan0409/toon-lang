#[derive(Debug, Clone)]
pub enum Lit {
    Number(f64),
    Bool(bool),
    String(String),
}
