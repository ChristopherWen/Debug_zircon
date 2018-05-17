#pragma once
#define MODULE_COMPILEFLAGS "-I./build-arm64-release/system/ulib/fbl.hostlib/gen/include_-I./build-arm64-release/system/ulib/pretty.hostlib/gen/include_-I./build-arm64-release/system/ulib/trace-reader.hostlib/gen/include_-I./build-arm64-release/system/ulib/unittest.hostlib/gen/include_-Isystem/ulib/fbl.hostlib/include_-Isystem/ulib/fbl/include_-Isystem/ulib/pretty.hostlib/include_-Isystem/ulib/trace-engine/include_-Isystem/ulib/trace-reader.hostlib/include_-Isystem/ulib/trace-reader/include_-Isystem/ulib/unittest.hostlib/include_-Isystem/ulib/unittest/include_-Isystem/utest/trace-reader/include"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-arm64-release/config-host.h_./build-arm64-release/config-user.h"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/utest/trace-reader/main.c_system/utest/trace-reader/reader_tests.cpp_system/utest/trace-reader/records_tests.cpp"
#define MODULE_HEADER_DEPS "system/ulib/fbl.hostlib_system/ulib/pretty.hostlib_system/ulib/trace-reader.hostlib_system/ulib/unittest.hostlib"
#define MODULE_TYPE "hostapp"

