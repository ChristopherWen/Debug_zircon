#pragma once
#define MODULE_LIBS "system/ulib/fdio"
#define MODULE_STATIC_LIBS ""
#define MODULE_COMPILEFLAGS "-I./build-x64-release/system/ulib/fdio/gen/include_-Iglobal/include_-Isystem/ulib/fdio/include_-Ithird_party/ulib/linenoise/include_-Ithird_party/ulib/musl/include"
#define MODULE_CFLAGS "-Ithird_party/ulib/linenoise/include/linenoise"
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-x64-release/config-user.h_./build-x64-release/system/ulib/fdio/gen-hdr.stamp"
#define MODULE_DEPS ""
#define MODULE_SRCS "third_party/ulib/linenoise/linenoise.c"
#define MODULE_HEADER_DEPS "system/ulib/fdio"
#define MODULE_TYPE "userlib"
