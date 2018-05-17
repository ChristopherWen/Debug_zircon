#pragma once
#define MODULE_LIBS "system/ulib/fdio_system/ulib/zircon_system/ulib/c"
#define MODULE_STATIC_LIBS "system/ulib/audio-utils_system/ulib/audio-proto-utils_system/ulib/zx_system/ulib/zxcpp_system/ulib/fbl"
#define MODULE_COMPILEFLAGS "-I./build-arm64-release/system/ulib/audio-proto-utils/gen/include_-I./build-arm64-release/system/ulib/audio-utils/gen/include_-I./build-arm64-release/system/ulib/c/gen/include_-I./build-arm64-release/system/ulib/fbl/gen/include_-I./build-arm64-release/system/ulib/fdio/gen/include_-I./build-arm64-release/system/ulib/zircon/gen/include_-I./build-arm64-release/system/ulib/zx/gen/include_-I./build-arm64-release/system/ulib/zxcpp/gen/include_-Iglobal/include_-Isystem/uapp/audio/include_-Isystem/ulib/audio-proto-utils/include_-Isystem/ulib/audio-utils/include_-Isystem/ulib/c/include_-Isystem/ulib/fbl/include_-Isystem/ulib/fdio/include_-Isystem/ulib/zircon/include_-Isystem/ulib/zx/include_-Isystem/ulib/zxcpp/include_-Ithird_party/ulib/musl/include"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-arm64-release/config-user.h_./build-arm64-release/system/ulib/audio-proto-utils/gen-hdr.stamp_./build-arm64-release/system/ulib/audio-utils/gen-hdr.stamp_./build-arm64-release/system/ulib/c/gen-hdr.stamp_./build-arm64-release/system/ulib/fbl/gen-hdr.stamp_./build-arm64-release/system/ulib/fdio/gen-hdr.stamp_./build-arm64-release/system/ulib/zircon/gen-hdr.stamp_./build-arm64-release/system/ulib/zx/gen-hdr.stamp_./build-arm64-release/system/ulib/zxcpp/gen-hdr.stamp"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/uapp/audio/audio.cpp_system/uapp/audio/sine-source.cpp_system/uapp/audio/wav-common.cpp_system/uapp/audio/wav-sink.cpp_system/uapp/audio/wav-source.cpp"
#define MODULE_HEADER_DEPS "system/ulib/audio-proto-utils_system/ulib/audio-utils_system/ulib/c_system/ulib/fbl_system/ulib/fdio_system/ulib/zircon_system/ulib/zx_system/ulib/zxcpp"
#define MODULE_TYPE "userapp"
