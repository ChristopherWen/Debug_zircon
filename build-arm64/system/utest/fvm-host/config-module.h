#pragma once
#define DISABLE_THREAD_ANNOTATIONS
#define MODULE_COMPILEFLAGS "-I./build-arm64/system/uapp/blobfs.hostlib/gen/include_-I./build-arm64/system/ulib/digest.hostlib/gen/include_-I./build-arm64/system/ulib/fbl.hostlib/gen/include_-I./build-arm64/system/ulib/fvm.hostlib/gen/include_-I./build-arm64/system/ulib/minfs.hostlib/gen/include_-I./build-arm64/system/ulib/pretty.hostlib/gen/include_-I./build-arm64/system/ulib/unittest.hostlib/gen/include_-I./build-arm64/third_party/ulib/lz4.hostlib/gen/include_-I./build-arm64/third_party/ulib/uboringssl.hostlib/gen/include_-Isystem/host/fvm/include_-Isystem/uapp/blobfs.hostlib/include_-Isystem/uapp/lz4/include_-Isystem/ulib/bitmap/include_-Isystem/ulib/blobfs/include_-Isystem/ulib/digest.hostlib/include_-Isystem/ulib/digest/include_-Isystem/ulib/fbl.hostlib/include_-Isystem/ulib/fbl/include_-Isystem/ulib/fdio/include_-Isystem/ulib/fs-management/include_-Isystem/ulib/fs/include_-Isystem/ulib/fvm.hostlib/include_-Isystem/ulib/fvm/include_-Isystem/ulib/gpt/include_-Isystem/ulib/minfs.hostlib/include_-Isystem/ulib/minfs/include_-Isystem/ulib/pretty.hostlib/include_-Isystem/ulib/unittest.hostlib/include_-Isystem/ulib/unittest/include_-Isystem/utest/fvm-host/include_-Ithird_party/ulib/lz4.hostlib/include_-Ithird_party/ulib/lz4/include_-Ithird_party/ulib/uboringssl.hostlib/include_-Ithird_party/ulib/uboringssl/include_-Werror-implicit-function-declaration_-Wstrict-prototypes_-Wwrite-strings"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-arm64/config-host.h_./build-arm64/config-user.h"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/host/fvm/container/container.cpp_system/host/fvm/container/fvm.cpp_system/host/fvm/container/sparse.cpp_system/host/fvm/format/blobfs.cpp_system/host/fvm/format/format.cpp_system/host/fvm/format/minfs.cpp_system/utest/fvm-host/main.cpp"
#define MODULE_HEADER_DEPS "system/uapp/blobfs.hostlib_system/ulib/digest.hostlib_system/ulib/fbl.hostlib_system/ulib/fvm.hostlib_system/ulib/minfs.hostlib_system/ulib/pretty.hostlib_system/ulib/unittest.hostlib_third_party/ulib/lz4.hostlib_third_party/ulib/uboringssl.hostlib"
#define MODULE_TYPE "hostapp"

