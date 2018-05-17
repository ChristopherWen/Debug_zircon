#pragma once
#define DISABLE_THREAD_ANNOTATIONS
#define MODULE_COMPILEFLAGS "-Isystem/ulib/bitmap/include_-Isystem/ulib/blobfs/include_-Isystem/ulib/digest/include_-Isystem/ulib/fbl/include_-Isystem/ulib/fdio/include_-Isystem/ulib/fs/include_-Ithird_party/ulib/uboringssl/include_-Werror-implicit-function-declaration_-Wstrict-prototypes_-Wwrite-strings"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-x64-release/config-host.h_./build-x64-release/config-user.h"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/ulib/blobfs/common.cpp_system/ulib/blobfs/fsck.cpp_system/ulib/blobfs/host.cpp"
#define MODULE_HEADER_DEPS ""
#define MODULE_TYPE "hostlib"

