use clap::Clap;
use std::fs;
use std::path::Path;
use toon_core::{jit_execute, parse, Generator, TypeChecker};

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
    let mut prog = parse(&src).expect("Unable to build AST from source");
    if let Err(err) = TypeChecker::new().check(&mut prog, &src) {
        println!("{}", err);
        return;
    }

    let ctx = Generator::empty_context();
    let mut generator = Generator::new(&ctx, path.to_str().unwrap());
    let ir_mod = generator.gen(&prog).expect("Unable to generate LLVM IR");

    let _ret: i8 = jit_execute(&ir_mod, "main").expect("Unable to execute code");
}
