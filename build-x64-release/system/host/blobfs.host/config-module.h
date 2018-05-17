#pragma once
#define DISABLE_THREAD_ANNOTATIONS
#define MODULE_COMPILEFLAGS "-I./build-x64-release/system/ulib/blobfs.hostlib/gen/include_-I./build-x64-release/system/ulib/digest.hostlib/gen/include_-I./build-x64-release/system/ulib/fbl.hostlib/gen/include_-I./build-x64-release/system/ulib/fs-host.hostlib/gen/include_-I./build-x64-release/third_party/ulib/uboringssl.hostlib/gen/include_-Isystem/host/blobfs/include_-Isystem/ulib/bitmap/include_-Isystem/ulib/blobfs.hostlib/include_-Isystem/ulib/blobfs/include_-Isystem/ulib/digest.hostlib/include_-Isystem/ulib/digest/include_-Isystem/ulib/fbl.hostlib/include_-Isystem/ulib/fbl/include_-Isystem/ulib/fdio/include_-Isystem/ulib/fs-host.hostlib/include_-Isystem/ulib/fs-host/include_-Isystem/ulib/fs/include_-Isystem/ulib/zxcpp/include_-Ithird_party/ulib/uboringssl.hostlib/include_-Werror-implicit-function-declaration_-Wstrict-prototypes_-Wwrite-strings"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-x64-release/config-host.h_./build-x64-release/config-user.h"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/host/blobfs/main.cpp_system/ulib/bitmap/raw-bitmap.cpp_system/ulib/fs/vfs.cpp_system/ulib/fs/vnode.cpp"
#define MODULE_HEADER_DEPS "system/ulib/blobfs.hostlib_system/ulib/digest.hostlib_system/ulib/fbl.hostlib_system/ulib/fs-host.hostlib_third_party/ulib/uboringssl.hostlib"
#define MODULE_TYPE "hostapp"

