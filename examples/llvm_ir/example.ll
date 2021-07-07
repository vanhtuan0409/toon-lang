; ModuleID = '/home/tuan/Workspaces/toon-lang/examples/main.toon'
source_filename = "/home/tuan/Workspaces/toon-lang/examples/main.toon"

@str0 = private unnamed_addr constant [16 x i8] c"Result is: %.2f\00", align 1

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %x = alloca double, align 8
  store double 1.200000e+01, double* %x, align 8
  %x1 = load double, double* %x, align 8
  %tmpadd = fadd double %x1, 1.000000e+00
  %y = alloca double, align 8
  store double %tmpadd, double* %y, align 8
  %z = alloca double, align 8
  %y2 = load double, double* %y, align 8
  %tmpmul = fmul double %y2, 2.000000e+00
  store double %tmpmul, double* %z, align 8
  %k = alloca i1, align 1
  store i1 true, i1* %k, align 1
  %fmt_str = alloca i8*, align 8
  store i8* getelementptr inbounds ([16 x i8], [16 x i8]* @str0, i32 0, i32 0), i8** %fmt_str, align 8
  %fmt_str3 = load i8*, i8** %fmt_str, align 8
  %z4 = load double, double* %z, align 8
  %printf = call i32 (i8*, ...) @printf(i8* %fmt_str3, double %z4)
  ret i32 0
}
