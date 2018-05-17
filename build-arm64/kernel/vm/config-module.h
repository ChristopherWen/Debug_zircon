#pragma once
#define MODULE_COMPILEFLAGS ""
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-arm64/config-kernel.h"
#define MODULE_DEPS "kernel/lib/fbl_kernel/lib/pretty_kernel/lib/user_copy_third_party/lib/cryptolib"
#define MODULE_SRCS "kernel/vm/bootalloc.cpp_kernel/vm/bootreserve.cpp_kernel/vm/kstack.cpp_kernel/vm/page.cpp_kernel/vm/pmm.cpp_kernel/vm/pmm_arena.cpp_kernel/vm/vm.cpp_kernel/vm/vm_address_region.cpp_kernel/vm/vm_address_region_or_mapping.cpp_kernel/vm/vm_aspace.cpp_kernel/vm/vm_mapping.cpp_kernel/vm/vm_object.cpp_kernel/vm/vm_object_paged.cpp_kernel/vm/vm_object_physical.cpp_kernel/vm/vm_page_list.cpp_kernel/vm/vm_unittest.cpp_kernel/vm/vmm.cpp"
#define MODULE_HEADER_DEPS "kernel/lib/fbl_kernel/lib/pretty_kernel/lib/user_copy_third_party/lib/cryptolib"
#define MODULE_TYPE ""

