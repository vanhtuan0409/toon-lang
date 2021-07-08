use clap::Clap;
use std::fs;
use std::path::Path;
use toon_core::{parse as ast_parse, TypeChecker};

#[derive(Clap)]
pub struct Opts {
    #[clap(about = "Path to source file")]
    path: String,

    #[clap(long, about = "Enable type check")]
    typecheck: bool,
}

pub fn parse(args: Opts) {
    let path = Path::new(&args.path)
        .canonicalize()
        .expect("Invalid file path");
    let src = fs::read(&path).expect("Unable to read source file");
    let mut prog = ast_parse(&src).expect("Unable to build AST from source");
    if args.typecheck {
        if let Err(err) = TypeChecker::new().check(&mut prog, &src) {
            println!("{}", err);
            return;
        }
    }
    println!("{:#?}", prog)
}
