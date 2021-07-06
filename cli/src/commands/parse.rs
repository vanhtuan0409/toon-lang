use clap::Clap;
use std::fs;
use std::path::Path;
use toon_core::parse as ast_parse;

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
    let prog = ast_parse(&src).expect("Unable to build AST from source");
    println!("{:#?}", prog)
}
