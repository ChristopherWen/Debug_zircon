#pragma once
#define DISABLE_THREAD_ANNOTATIONS
#define MODULE_COMPILEFLAGS "-I./build-arm64/system/ulib/fbl.hostlib/gen/include_-I./build-arm64/system/ulib/fs-host.hostlib/gen/include_-I./build-arm64/system/ulib/minfs.hostlib/gen/include_-Isystem/host/minfs/include_-Isystem/ulib/bitmap/include_-Isystem/ulib/fbl.hostlib/include_-Isystem/ulib/fbl/include_-Isystem/ulib/fdio/include_-Isystem/ulib/fs-host.hostlib/include_-Isystem/ulib/fs-host/include_-Isystem/ulib/fs/include_-Isystem/ulib/minfs.hostlib/include_-Isystem/ulib/minfs/include_-Isystem/ulib/zxcpp/include_-Werror-implicit-function-declaration_-Wstrict-prototypes_-Wwrite-strings"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-arm64/config-host.h_./build-arm64/config-user.h"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/host/minfs/main.cpp_system/ulib/bitmap/raw-bitmap.cpp_system/ulib/fs/vfs.cpp_system/ulib/fs/vnode.cpp"
#define MODULE_HEADER_DEPS "system/ulib/fbl.hostlib_system/ulib/fs-host.hostlib_system/ulib/minfs.hostlib"
#define MODULE_TYPE "hostapp"

