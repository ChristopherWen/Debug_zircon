#pragma once
#define DISABLE_THREAD_ANNOTATIONS
#define MODULE_COMPILEFLAGS "-I./build-x64-release/system/ulib/digest.hostlib/gen/include_-I./build-x64-release/system/ulib/fbl.hostlib/gen/include_-I./build-x64-release/third_party/ulib/lz4.hostlib/gen/include_-I./build-x64-release/third_party/ulib/uboringssl.hostlib/gen/include_-Isystem/ulib/block-client/include_-Isystem/ulib/digest.hostlib/include_-Isystem/ulib/digest/include_-Isystem/ulib/fbl.hostlib/include_-Isystem/ulib/fbl/include_-Isystem/ulib/fdio/include_-Isystem/ulib/fs/include_-Isystem/ulib/fvm/include_-Isystem/ulib/gpt/include_-Isystem/ulib/zircon/include_-Isystem/ulib/zx/include_-Ithird_party/ulib/lz4.hostlib/include_-Ithird_party/ulib/lz4/include_-Ithird_party/ulib/uboringssl.hostlib/include_-Werror-implicit-function-declaration_-Wstrict-prototypes_-Wwrite-strings"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-x64-release/config-host.h_./build-x64-release/config-user.h"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/ulib/fvm/fvm-lz4.cpp_system/ulib/fvm/fvm.cpp"
#define MODULE_HEADER_DEPS "system/ulib/digest.hostlib_system/ulib/fbl.hostlib_third_party/ulib/lz4.hostlib_third_party/ulib/uboringssl.hostlib"
#define MODULE_TYPE "hostlib"

