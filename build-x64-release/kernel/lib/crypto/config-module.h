#pragma once
#define MODULE_COMPILEFLAGS ""
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-x64-release/config-kernel.h"
#define MODULE_DEPS "kernel/dev/hw_rng_kernel/lib/explicit-memory_kernel/lib/fbl_kernel/lib/unittest_third_party/lib/jitterentropy_third_party/lib/uboringssl"
#define MODULE_SRCS "kernel/lib/crypto/entropy/collector.cpp_kernel/lib/crypto/entropy/collector_unittest.cpp_kernel/lib/crypto/entropy/hw_rng_collector.cpp_kernel/lib/crypto/entropy/jitterentropy_collector.cpp_kernel/lib/crypto/entropy/quality_test.cpp_kernel/lib/crypto/global_prng.cpp_kernel/lib/crypto/global_prng_unittest.cpp_kernel/lib/crypto/prng.cpp_kernel/lib/crypto/prng_unittest.cpp"
#define MODULE_HEADER_DEPS "kernel/dev/hw_rng_kernel/lib/explicit-memory_kernel/lib/fbl_kernel/lib/unittest_third_party/lib/jitterentropy_third_party/lib/uboringssl"
#define MODULE_TYPE ""

