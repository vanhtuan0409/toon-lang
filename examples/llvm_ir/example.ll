define i32 @main() {
  %x = alloca i32
  store i32 2, i32* %x

  %1 = load i32, i32* %x
  %result = mul i32 %1, 2
  ret i32 %result
}
