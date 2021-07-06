mod compile;
mod parse;
mod run;

use clap::{crate_authors, crate_version, AppSettings, Clap};
pub use compile::compile;
pub use parse::parse;
pub use run::run;

#[derive(Clap)]
#[clap(name = "toon", author = crate_authors!(), version = crate_version!())]
#[clap(setting = AppSettings::ColoredHelp)]
pub struct Opts {
    #[clap(subcommand)]
    pub command: SubCommand,
}

#[derive(Clap)]
pub enum SubCommand {
    #[clap(about = "Parse AST tree from source code")]
    Parse(parse::Opts),

    #[clap(about = "Compile source code to asm or object code")]
    Compile(compile::Opts),

    #[clap(about = "Run generated IR code via JIT engine")]
    Run(run::Opts),
}
