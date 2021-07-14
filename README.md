# Toon lang

### Compiler features

- [x] Treesitter
  - [x] Grammar parser
  - [x] Syntax highlight
- [x] AST parser
  - [x] Visitor pattern support
- [x] Semantic checker
  - [x] Type checker
  - [x] Type inference
  - [x] Default value inference
- [x] LLVM IR code gen
- [ ] Support module linker (via gcc linker)

### Language features

- [x] Var declaration
- [x] Simple primary types (number, bool, string, void)
- [x] Simple operations (binary and unary op)
- [x] Scopes
- [ ] Control operations (if-else, for-loop)
- [ ] Function declaration
- [x] Function call expression
- [ ] Lambda function call
- [ ] Standard lib

### CLI

```
toon 0.1.0
Tuan Vuong <vanhtuan0409@gmail.com>

USAGE:
    toon <SUBCOMMAND>

FLAGS:
    -h, --help       Prints help information
    -V, --version    Prints version information

SUBCOMMANDS:
    compile    Compile source code to asm or object code
    help       Prints this message or the help of the given subcommand(s)
    parse      Parse AST tree from source code
    run        Run generated IR code via JIT engine
```

### Inspired by

- https://github.com/MQuy/mlang
- https://github.com/trinnguyen/gao
