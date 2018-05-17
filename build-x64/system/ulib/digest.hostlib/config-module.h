#pragma once
#define DISABLE_THREAD_ANNOTATIONS
#define MODULE_COMPILEFLAGS "-I./build-x64/system/ulib/fbl.hostlib/gen/include_-I./build-x64/third_party/ulib/uboringssl.hostlib/gen/include_-Isystem/ulib/digest/include_-Isystem/ulib/fbl.hostlib/include_-Isystem/ulib/fbl/include_-Ithird_party/ulib/uboringssl.hostlib/include_-Ithird_party/ulib/uboringssl/include"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-x64/config-host.h_./build-x64/config-user.h"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/ulib/digest/digest.cpp_system/ulib/digest/merkle-tree.cpp"
#define MODULE_HEADER_DEPS "system/ulib/fbl.hostlib_third_party/ulib/uboringssl.hostlib"
#define MODULE_TYPE "hostlib"

