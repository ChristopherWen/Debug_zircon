#pragma once
#define MODULE_COMPILEFLAGS "-fno-builtin"
#define MODULE_CFLAGS ""
#define MODULE_CPPFLAGS ""
#define MODULE_ASMFLAGS ""
#define MODULE_OPTFLAGS ""
#define MODULE_LDFLAGS ""
#define MODULE_SRCDEPS "./build-arm64/config-kernel.h"
#define MODULE_DEPS "kernel/lib/crypto_kernel/lib/fbl_kernel/lib/header_tests_kernel/lib/unittest"
#define MODULE_SRCS "kernel/tests/alloc_checker_tests.cpp_kernel/tests/benchmarks.cpp_kernel/tests/cache_tests.cpp_kernel/tests/clock_tests.cpp_kernel/tests/fibo.cpp_kernel/tests/mem_tests.cpp_kernel/tests/preempt_disable_tests.cpp_kernel/tests/printf_tests.cpp_kernel/tests/sleep_tests.cpp_kernel/tests/string_tests.c_kernel/tests/sync_ipi_tests.cpp_kernel/tests/tests.cpp_kernel/tests/thread_tests.cpp_kernel/tests/timer_tests.cpp_kernel/tests/uart_tests.cpp"
#define MODULE_HEADER_DEPS "kernel/lib/crypto_kernel/lib/fbl_kernel/lib/header_tests_kernel/lib/unittest"
#define MODULE_TYPE ""

