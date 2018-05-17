#pragma once
#define MODULE_LIBS "system/ulib/async.cpp_system/ulib/async_system/ulib/c_system/ulib/fs_system/ulib/zircon_system/ulib/fdio_"
#define MODULE_STATIC_LIBS "system/ulib/zx_system/ulib/fbl_"
#define MODULE_COMPILEFLAGS "-I./build-arm64/system/ulib/async.cpp/gen/include_-I./build-arm64/system/ulib/async/gen/include_-I./build-arm64/system/ulib/c/gen/include_-I./build-arm64/system/ulib/fbl/gen/include_-I./build-arm64/system/ulib/fdio/gen/include_-I./build-arm64/system/ulib/fs/gen/include_-I./build-arm64/system/ulib/zircon/gen/include_-I./build-arm64/system/ulib/zx/gen/include_-Iglobal/include_-Isystem/ulib/async.cpp/include_-Isystem/ulib/async/include_-Isystem/ulib/c/include_-Isystem/ulib/fbl/include_-Isystem/ulib/fdio/include_-Isystem/ulib/fs/include_-Isystem/ulib/vmofs/include_-Isystem/ulib/zircon/include_-Isystem/ulib/zx/include_-Ithird_party/ulib/musl/include"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-arm64/config-user.h_./build-arm64/system/ulib/async.cpp/gen-hdr.stamp_./build-arm64/system/ulib/async/gen-hdr.stamp_./build-arm64/system/ulib/c/gen-hdr.stamp_./build-arm64/system/ulib/fbl/gen-hdr.stamp_./build-arm64/system/ulib/fdio/gen-hdr.stamp_./build-arm64/system/ulib/fs/gen-hdr.stamp_./build-arm64/system/ulib/zircon/gen-hdr.stamp_./build-arm64/system/ulib/zx/gen-hdr.stamp"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/ulib/vmofs/vmofs.cpp"
#define MODULE_HEADER_DEPS "system/ulib/async_system/ulib/async.cpp_system/ulib/c_system/ulib/fbl_system/ulib/fdio_system/ulib/fs_system/ulib/zircon_system/ulib/zx"
#define MODULE_TYPE "userlib"
