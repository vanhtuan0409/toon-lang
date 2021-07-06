use clap::Clap;
use std::fs;
use std::path::Path;
use toon_core::ASTBuilder;

#[derive(Clap)]
pub struct Opts {
    #[clap(about = "Path to source file")]
    path: String,
}

pub fn parse(args: Opts) {
    let path = Path::new(&args.path)
        .canonicalize()
        .expect("Invalid file path");
    let src = fs::read(&path).expect("Unable to read source file");
    let src_ast = ASTBuilder::new()
        .build(&src)
        .expect("Unable to build AST from source");
    println!("{:#?}", src_ast.node)
}
