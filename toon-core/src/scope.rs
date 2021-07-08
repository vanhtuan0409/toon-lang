use std::collections::HashMap;

#[derive(Debug)]
pub struct ScopeManager<T> {
    stacks: Vec<Scope<T>>,
    global_scope: Scope<T>,
}

impl<T> ScopeManager<T> {
    pub fn new() -> Self {
        ScopeManager {
            stacks: vec![],
            global_scope: Scope::new(),
        }
    }

    pub fn enter_scope(&mut self) {
        let scope = Scope::new();
        self.stacks.push(scope);
    }

    pub fn leave_scope(&mut self) {
        let _ = self.stacks.pop();
    }

    pub fn register_local(&mut self, name: String, val: T) {
        let scope = self.stacks.last_mut().unwrap();
        scope.symbols.insert(name, val);
    }

    pub fn register_global(&mut self, name: String, val: T) {
        self.global_scope.symbols.insert(name, val);
    }

    pub fn lookup(&mut self, name: &str) -> Option<&T> {
        for scope in self.stacks.iter().rev() {
            if let Some(val) = scope.symbols.get(name) {
                return Some(val);
            }
        }
        self.global_scope.symbols.get(name)
    }
}

#[derive(Debug)]
struct Scope<T> {
    symbols: HashMap<String, T>,
}

impl<T> Scope<T> {
    fn new() -> Self {
        Scope {
            symbols: HashMap::new(),
        }
    }
}
