#pragma once
#define DISABLE_THREAD_ANNOTATIONS
#define MODULE_COMPILEFLAGS "-I./build-x64/system/ulib/fbl.hostlib/gen/include_-Isystem/ulib/fbl.hostlib/include_-Isystem/ulib/fbl/include_-Isystem/ulib/fs-host/include_-Isystem/ulib/zircon/include_-Werror-implicit-function-declaration_-Wstrict-prototypes_-Wwrite-strings"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-x64/config-host.h_./build-x64/config-user.h"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/ulib/fs-host/common.cpp"
#define MODULE_HEADER_DEPS "system/ulib/fbl.hostlib"
#define MODULE_TYPE "hostlib"

