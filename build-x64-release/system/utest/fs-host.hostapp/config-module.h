#pragma once
#define DISABLE_THREAD_ANNOTATIONS
#define MODULE_COMPILEFLAGS "-I./build-x64-release/system/ulib/fbl.hostlib/gen/include_-I./build-x64-release/system/ulib/minfs.hostlib/gen/include_-I./build-x64-release/system/ulib/pretty.hostlib/gen/include_-I./build-x64-release/system/ulib/unittest.hostlib/gen/include_-Isystem/ulib/bitmap/include_-Isystem/ulib/fbl.hostlib/include_-Isystem/ulib/fbl/include_-Isystem/ulib/fdio/include_-Isystem/ulib/fs-management/include_-Isystem/ulib/fs/include_-Isystem/ulib/minfs.hostlib/include_-Isystem/ulib/minfs/include_-Isystem/ulib/pretty.hostlib/include_-Isystem/ulib/unittest.hostlib/include_-Isystem/ulib/unittest/include_-Isystem/ulib/zircon/include_-Isystem/ulib/zxcpp/include_-Isystem/utest/fs-host/include_-Werror-implicit-function-declaration_-Wstrict-prototypes_-Wwrite-strings"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-x64-release/config-host.h_./build-x64-release/config-user.h"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/ulib/bitmap/raw-bitmap.cpp_system/ulib/fs/vfs.cpp_system/ulib/fs/vnode.cpp_system/utest/fs-host/main.cpp_system/utest/fs-host/test-basic.cpp_system/utest/fs-host/test-directory.cpp_system/utest/fs-host/test-maxfile.cpp_system/utest/fs-host/test-rw-workers.cpp_system/utest/fs-host/test-sparse.cpp_system/utest/fs-host/test-truncate.cpp_system/utest/fs-host/util.cpp"
#define MODULE_HEADER_DEPS "system/ulib/fbl.hostlib_system/ulib/minfs.hostlib_system/ulib/pretty.hostlib_system/ulib/unittest.hostlib"
#define MODULE_TYPE "hostapp"

