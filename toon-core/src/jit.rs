use inkwell::module::Module;
use inkwell::OptimizationLevel;

pub fn execute<T>(module: &Module, fn_name: &str) -> Result<T, ()> {
    let engine = module
        .create_jit_execution_engine(OptimizationLevel::None)
        .map_err(|_| ())?;

    let selected_fn = unsafe { engine.get_function::<unsafe extern "C" fn() -> T>(fn_name) };
    let selected_fn = selected_fn.map_err(|_| ())?;
    let ret = unsafe { selected_fn.call() };
    Ok(ret)
}
