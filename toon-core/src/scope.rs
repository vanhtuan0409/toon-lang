use std::collections::HashMap;

#[derive(Debug, Clone)]
pub struct Scope<T> {
    pub symbols: HashMap<String, T>,
    pub parent: Option<Box<Scope<T>>>,
}

impl<T> std::default::Default for Scope<T> {
    fn default() -> Self {
        Self {
            symbols: HashMap::new(),
            parent: None,
        }
    }
}

impl<T> Scope<T> {
    pub fn new(parent: Option<Scope<T>>) -> Self {
        Scope {
            symbols: HashMap::new(),
            parent: match parent {
                Some(ctx) => Some(Box::new(ctx)),
                None => None,
            },
        }
    }

    pub fn lookup(&self, name: &str) -> Option<&T> {
        match self.symbols.get(name) {
            Some(val) => Some(val),
            None => match &self.parent {
                Some(ctx) => ctx.lookup(name),
                None => None,
            },
        }
    }

    pub fn register(&mut self, name: String, val: T) {
        self.symbols.insert(name, val);
    }
}
