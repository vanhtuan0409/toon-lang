use std::collections::HashMap;

#[derive(Debug)]
pub struct ScopeStack<T> {
    stacks: Vec<Scope<T>>,
}

impl<T> ScopeStack<T> {
    pub fn new() -> Self {
        ScopeStack { stacks: vec![] }
    }

    pub fn enter_scope(&mut self) {
        let scope = Scope {
            symbols: HashMap::new(),
        };
        self.stacks.push(scope);
    }

    pub fn leave_scope(&mut self) {
        let _ = self.stacks.pop();
    }

    pub fn register(&mut self, name: String, val: T) {
        let scope = self.stacks.last_mut().unwrap();
        scope.symbols.insert(name, val);
    }

    pub fn lookup(&mut self, name: &str) -> Option<&T> {
        for scope in self.stacks.iter().rev() {
            if let Some(val) = scope.symbols.get(name) {
                return Some(val);
            }
        }
        None
    }
}

#[derive(Debug)]
struct Scope<T> {
    symbols: HashMap<String, T>,
}
