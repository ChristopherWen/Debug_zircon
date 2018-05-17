#pragma once
#define HOST_COMPILEFLAGS "-g_-O2_-Isystem/public_-Isystem/private_-I./build-arm64-release/gen/global/include_-Wall_-Wextra_-Wno-unused-parameter_-Wno-sign-compare_--sysroot=./prebuilt/downloads/sysroot"
#define HOST_CFLAGS "-std=c11"
#define HOST_CPPFLAGS "-std=c++14_-fno-exceptions_-fno-rtti"
#define HOST_ASMFLAGS ""
#define HOST_LDFLAGS "_-Lprebuilt/downloads/clang/lib_-ldl_-lpthread_-static-libstdc++_-Wno-unused-command-line-argument"

