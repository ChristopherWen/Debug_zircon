#pragma once
#define USB_DEVICE_VID 0x18D1
#define USB_DEVICE_PID 0xA020
#define USB_DEVICE_MANUFACTURER "Zircon"
#define USB_DEVICE_PRODUCT "CDC-Ethernet"
#define USB_DEVICE_SERIAL "0123456789ABCDEF"
#define USB_DEVICE_FUNCTIONS "cdc"
#define MODULE_LIBS "system/ulib/driver_system/ulib/zircon_system/ulib/c"
#define MODULE_STATIC_LIBS "system/ulib/ddk"
#define MODULE_COMPILEFLAGS "-I./build-arm64-release/system/ulib/c/gen/include_-I./build-arm64-release/system/ulib/ddk/gen/include_-I./build-arm64-release/system/ulib/driver/gen/include_-I./build-arm64-release/system/ulib/zircon/gen/include_-Iglobal/include_-Isystem/dev/usb/usb-device/include_-Isystem/ulib/c/include_-Isystem/ulib/ddk/include_-Isystem/ulib/driver/include_-Isystem/ulib/zircon/include_-Ithird_party/ulib/musl/include"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-arm64-release/config-user.h_./build-arm64-release/system/ulib/c/gen-hdr.stamp_./build-arm64-release/system/ulib/ddk/gen-hdr.stamp_./build-arm64-release/system/ulib/driver/gen-hdr.stamp_./build-arm64-release/system/ulib/zircon/gen-hdr.stamp"
#define MODULE_DEPS ""
#define MODULE_SRCS "system/dev/usb/usb-device/usb-device.c"
#define MODULE_HEADER_DEPS "system/ulib/c_system/ulib/ddk_system/ulib/driver_system/ulib/zircon"
#define MODULE_TYPE "driver"

