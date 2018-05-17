#pragma once
#define MODULE_COMPILEFLAGS "-I./build-arm64-clang/system/ulib/digest.hostlib/gen/include_-I./build-arm64-clang/system/ulib/fbl.hostlib/gen/include_-I./build-arm64-clang/third_party/ulib/uboringssl.hostlib/gen/include_-Isystem/host/merkleroot/include_-Isystem/ulib/digest.hostlib/include_-Isystem/ulib/digest/include_-Isystem/ulib/fbl.hostlib/include_-Isystem/ulib/fbl/include_-Isystem/ulib/zxcpp/include_-Ithird_party/ulib/uboringssl.hostlib/include_-Ithird_party/ulib/uboringssl/include"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-arm64-clang/config-host.h_./build-arm64-clang/config-user.h"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/host/merkleroot/merkleroot.cpp"
#define MODULE_HEADER_DEPS "system/ulib/digest.hostlib_system/ulib/fbl.hostlib_third_party/ulib/uboringssl.hostlib"
#define MODULE_TYPE "hostapp"

