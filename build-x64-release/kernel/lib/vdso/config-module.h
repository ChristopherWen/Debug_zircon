#pragma once
#define MODULE_COMPILEFLAGS "-I./build-x64-release/kernel/lib/vdso"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-x64-release/config-kernel.h_./build-x64-release/kernel/lib/vdso/vdso-code.h_./build-x64-release/kernel/lib/vdso/vdso-valid-sysret.h_./build-x64-release/system/ulib/zircon/libzircon.so.strip"
#define MODULE_DEPS "kernel/lib/fbl"
#define MODULE_SRCS "kernel/lib/vdso/rodso.cpp_kernel/lib/vdso/vdso-image.S_kernel/lib/vdso/vdso.cpp"
#define MODULE_HEADER_DEPS "kernel/lib/fbl"
#define MODULE_TYPE ""

