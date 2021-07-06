mod commands;

use clap::Clap;
use commands::{compile, parse, run, Opts, SubCommand};

fn main() {
    let opts = Opts::parse();
    match opts.command {
        SubCommand::Parse(parse_opts) => parse(parse_opts),
        SubCommand::Compile(compile_opts) => compile(compile_opts),
        SubCommand::Run(run_opts) => run(run_opts),
    };
}
