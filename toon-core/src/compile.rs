use inkwell::module::Module;
use inkwell::targets::{
    CodeModel, FileType, InitializationConfig, RelocMode, Target, TargetMachine,
};
use inkwell::OptimizationLevel;
use std::path::Path;
use std::process::{Command, Stdio};
use tempfile::NamedTempFile;

pub fn compile_object_code(module: &Module, path: &Path) -> Result<(), ()> {
    compile(module, path, FileType::Object)
}

pub fn compile_asm(module: &Module, path: &Path) -> Result<(), ()> {
    compile(module, path, FileType::Assembly)
}

pub fn compile_executable(module: &Module, path: &Path) -> Result<(), ()> {
    let tmp_path = NamedTempFile::new().map_err(|_| ())?.into_temp_path();
    compile_object_code(module, &tmp_path)?;
    Command::new("gcc")
        .stdout(Stdio::inherit())
        .stderr(Stdio::inherit())
        .arg("-o")
        .arg(path.as_os_str())
        .arg(tmp_path.as_os_str())
        .output()
        .map_err(|_| ())?;
    tmp_path.close().map_err(|_| ())
}

fn compile(module: &Module, path: &Path, ft: FileType) -> Result<(), ()> {
    // Ref: https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/LangImpl08.html

    // Detect target `name`
    let triple = TargetMachine::get_default_triple();
    let triple_str = triple.as_str().to_string_lossy();
    println!("Compiling to {}", triple_str);

    // Initialize and collecting target information from target name
    Target::initialize_native(&InitializationConfig::default()).map_err(|_| ())?;
    let target = Target::from_triple(&triple).map_err(|_| ())?;

    // Create current machine description
    let cpu_name = TargetMachine::get_host_cpu_name().to_string();
    let cpu_features = TargetMachine::get_host_cpu_features().to_string();
    println!("CPU name {}", cpu_name);
    println!("CPU features {}", cpu_features);
    let machine = target
        .create_target_machine(
            &triple,
            &cpu_name,
            &cpu_features,
            OptimizationLevel::None,
            RelocMode::Default,
            CodeModel::Default,
        )
        .ok_or(())?;

    // Optimize module
    module.set_data_layout(&machine.get_target_data().get_data_layout());
    module.set_triple(&triple);

    machine.write_to_file(module, ft, path).map_err(|_| ())
}
