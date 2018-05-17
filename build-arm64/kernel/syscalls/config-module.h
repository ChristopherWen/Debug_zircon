#pragma once
#define MODULE_COMPILEFLAGS "-I./build-arm64/kernel/lib/vdso"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-arm64/config-kernel.h"
#define MODULE_DEPS "kernel/lib/console_kernel/lib/crypto_kernel/lib/fbl_kernel/lib/pci_kernel/lib/user_copy_kernel/lib/vdso_kernel/object"
#define MODULE_SRCS "kernel/syscalls/bootdata_unittest.cpp_kernel/syscalls/channel.cpp_kernel/syscalls/ddk.cpp_kernel/syscalls/ddk_pci.cpp_kernel/syscalls/debug.cpp_kernel/syscalls/exceptions.cpp_kernel/syscalls/fifo.cpp_kernel/syscalls/futex.cpp_kernel/syscalls/handle_ops.cpp_kernel/syscalls/hypervisor.cpp_kernel/syscalls/object.cpp_kernel/syscalls/object_wait.cpp_kernel/syscalls/port.cpp_kernel/syscalls/profile.cpp_kernel/syscalls/resource.cpp_kernel/syscalls/socket.cpp_kernel/syscalls/syscalls.cpp_kernel/syscalls/system.cpp_kernel/syscalls/system_arm64.cpp_kernel/syscalls/task.cpp_kernel/syscalls/test.cpp_kernel/syscalls/timer.cpp_kernel/syscalls/vmar.cpp_kernel/syscalls/vmo.cpp_kernel/syscalls/zircon.cpp"
#define MODULE_HEADER_DEPS "kernel/lib/console_kernel/lib/crypto_kernel/lib/fbl_kernel/lib/pci_kernel/lib/user_copy_kernel/lib/vdso_kernel/object"
#define MODULE_TYPE ""

