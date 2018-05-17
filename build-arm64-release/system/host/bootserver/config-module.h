#pragma once
#define MODULE_COMPILEFLAGS "-I./build-arm64-release/system/ulib/tftp/gen/include_-Isystem/host/bootserver/include_-Isystem/ulib/tftp/include"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-arm64-release/config-host.h_./build-arm64-release/config-user.h"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/host/bootserver/bootserver.c_system/host/bootserver/netboot.c_system/host/bootserver/tftp.c"
#define MODULE_HEADER_DEPS "system/ulib/tftp"
#define MODULE_TYPE "hostapp"

