#pragma once
#define MODULE_COMPILEFLAGS "-I./build-x64/system/ulib/fbl.hostlib/gen/include_-I./build-x64/third_party/ulib/cksum.hostlib/gen/include_-I./build-x64/third_party/ulib/lz4.hostlib/gen/include_-Isystem/host/zbi/include_-Isystem/ulib/fbl.hostlib/include_-Isystem/ulib/fbl/include_-Ithird_party/ulib/cksum.hostlib/include_-Ithird_party/ulib/cksum/include_-Ithird_party/ulib/lz4.hostlib/include_-Ithird_party/ulib/lz4/include"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-x64/config-host.h_./build-x64/config-user.h"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/host/zbi/zbi.cpp"
#define MODULE_HEADER_DEPS "system/ulib/fbl.hostlib_third_party/ulib/cksum.hostlib_third_party/ulib/lz4.hostlib"
#define MODULE_TYPE "hostapp"

