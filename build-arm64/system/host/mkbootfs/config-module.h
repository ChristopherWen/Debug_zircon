#pragma once
#define MODULE_COMPILEFLAGS "-Isystem/host/mkbootfs/include"
#define MODULE_CFLAGS "-Ithird_party/ulib/cksum/include_-Ithird_party/ulib/lz4/include/lz4"
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-arm64/config-host.h_./build-arm64/config-user.h"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/host/mkbootfs/mkbootfs.c_third_party/ulib/cksum/crc32.c_third_party/ulib/lz4/lz4.c_third_party/ulib/lz4/lz4frame.c_third_party/ulib/lz4/lz4hc.c_third_party/ulib/lz4/xxhash.c"
#define MODULE_HEADER_DEPS ""
#define MODULE_TYPE "hostapp"

