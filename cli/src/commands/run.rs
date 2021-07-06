use clap::Clap;
use std::fs;
use std::path::Path;
use toon_core::{jit_execute, ASTBuilder, Generator};

#[derive(Clap)]
pub struct Opts {
    #[clap(about = "Path to source file")]
    path: String,
}

pub fn run(args: Opts) {
    let path = Path::new(&args.path)
        .canonicalize()
        .expect("Invalid file path");
    let src = fs::read(&path).expect("Unable to read source file");
    let src_ast = ASTBuilder::new()
        .build(&src)
        .expect("Unable to build AST from source");

    let ctx = Generator::empty_context();
    let mut generator = Generator::new(&ctx, path.to_str().unwrap());
    let ir_mod = generator.gen(&src_ast).expect("Unable to generate LLVM IR");

    let ret: f64 = jit_execute(&ir_mod, "main").expect("Unable to execute code");
    println!("Result: {}", ret);
}
