#pragma once
#define ZIRCON_TOOLCHAIN 1
#define USER_COMPILEFLAGS "-include_./build-arm64-clang/config-user.h_-fPIC_-D_ALL_SOURCE=1_-fasynchronous-unwind-tables"
#define USER_CFLAGS ""
#define USER_CPPFLAGS ""
#define USER_ASMFLAGS ""
#define USER_LDFLAGS "-z_combreloc_-z_relro_-z_now_-z_text_--hash-style=gnu_--eh-frame-hdr_-z_rodynamic"

