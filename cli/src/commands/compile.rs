use clap::Clap;
use std::fs;
use std::io::Write;
use std::path::{Path, PathBuf};
use toon_core::{compile_asm, compile_executable, compile_object_code, parse, Generator};

#[derive(Clap)]
pub enum OutputType {
    ASM,
    ObjectCode,
    IR,
    Executable,
}

impl std::str::FromStr for OutputType {
    type Err = &'static str;
    fn from_str(s: &str) -> Result<Self, Self::Err> {
        match s {
            "asm" => Ok(OutputType::ASM),
            "oc" => Ok(OutputType::ObjectCode),
            "ir" => Ok(OutputType::IR),
            "exe" => Ok(OutputType::Executable),
            _ => Err("Invalid output type"),
        }
    }
}

#[derive(Clap)]
pub struct Opts {
    #[clap(about = "Path to source file")]
    path: String,

    #[clap(
        short('t'),
        long,
        about = "Output type llvm ir, assembly or object code",
        default_value = "ir",
        possible_values = &["ir", "asm", "oc", "exe"],
    )]
    out_type: OutputType,

    #[clap(short, long, about = "Output file")]
    out: Option<String>,
}

pub fn compile(args: Opts) {
    let path = Path::new(&args.path)
        .canonicalize()
        .expect("Invalid file path");
    let src = fs::read(&path).expect("Unable to read source file");
    let prog = parse(&src).expect("Unable to build AST from source");

    let ctx = Generator::empty_context();
    let mut generator = Generator::new(&ctx, path.to_str().unwrap());
    let ir_mod = generator.gen(&prog).expect("Unable to generate LLVM IR");

    match (args.out_type, args.out) {
        (OutputType::IR, out) => {
            let ir_code = ir_mod.print_to_string().to_string();
            match out {
                Some(p) => {
                    if p.as_str() == "-" {
                        println!("{}", ir_code);
                        return;
                    }
                    let p = Path::new(&p);
                    let mut file = open_file(p);
                    file.write(ir_code.as_bytes())
                        .expect("Unable to write out file");
                }
                None => {
                    let p = resolve_out_file(&path, OutputType::IR);
                    let mut file = open_file(&p);
                    file.write(ir_code.as_bytes())
                        .expect("Unable to write out file");
                }
            };
        }

        (OutputType::ASM, out) => {
            let p = match out {
                None => resolve_out_file(&path, OutputType::ASM),
                Some(p) => Path::new(&p).to_path_buf(),
            };
            compile_asm(ir_mod, &p).expect("Unable to compile ASM");
        }

        (OutputType::ObjectCode, out) => {
            let p = match out {
                None => resolve_out_file(&path, OutputType::ObjectCode),
                Some(p) => Path::new(&p).to_path_buf(),
            };
            compile_object_code(ir_mod, &p).expect("Unable to compile Object Code");
        }

        (OutputType::Executable, out) => {
            let p = match out {
                None => resolve_out_file(&path, OutputType::Executable),
                Some(p) => Path::new(&p).to_path_buf(),
            };
            compile_executable(ir_mod, &p).expect("Unable to compile Executable");
        }
    };
}

fn open_file(p: &Path) -> fs::File {
    fs::OpenOptions::new()
        .write(true)
        .create(true)
        .truncate(true)
        .open(p)
        .expect("Unable to open out file")
}

fn resolve_out_file(src_path: &Path, out_type: OutputType) -> PathBuf {
    let filename = src_path.file_name().unwrap();
    std::env::current_dir()
        .unwrap()
        .join(Path::new(filename))
        .with_extension(match out_type {
            OutputType::IR => "ll",
            OutputType::ASM => "asm",
            OutputType::ObjectCode => "o",
            OutputType::Executable => "",
        })
}
