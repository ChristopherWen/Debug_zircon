#pragma once
#define MODULE_COMPILEFLAGS ""
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS "-Wno-invalid-offsetof"
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-arm64/config-kernel.h"
#define MODULE_DEPS "kernel/lib/fbl_kernel/lib/pci_kernel/lib/region-alloc_kernel/lib/zxcpp"
#define MODULE_SRCS "kernel/dev/pcie/debug.cpp_kernel/dev/pcie/pci_config.cpp_kernel/dev/pcie/pcie_bridge.cpp_kernel/dev/pcie/pcie_bus_driver.cpp_kernel/dev/pcie/pcie_caps.cpp_kernel/dev/pcie/pcie_device.cpp_kernel/dev/pcie/pcie_irqs.cpp_kernel/dev/pcie/pcie_quirks.cpp_kernel/dev/pcie/pcie_root.cpp_kernel/dev/pcie/pcie_upstream_node.cpp"
#define MODULE_HEADER_DEPS "kernel/lib/fbl_kernel/lib/pci_kernel/lib/region-alloc_kernel/lib/zxcpp"
#define MODULE_TYPE ""

