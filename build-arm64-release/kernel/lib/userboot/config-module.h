#pragma once
#define MODULE_COMPILEFLAGS "-I./build-arm64-release/kernel/lib/userboot"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-arm64-release/config-kernel.h_./build-arm64-release/kernel/lib/userboot/userboot-code.h_./build-arm64-release/system/core/userboot/libuserboot.so.strip"
#define MODULE_DEPS "kernel/lib/vdso"
#define MODULE_SRCS "kernel/lib/userboot/userboot-image.S_kernel/lib/userboot/userboot.cpp"
#define MODULE_HEADER_DEPS "kernel/lib/vdso"
#define MODULE_TYPE ""

