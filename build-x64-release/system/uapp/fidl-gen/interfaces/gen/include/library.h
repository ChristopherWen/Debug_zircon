#pragma once

#include <stdalign.h>
#include <stdbool.h>
#include <stdint.h>
#include <zircon/fidl.h>
#include <zircon/syscalls/object.h>
#include <zircon/types.h>

#if defined(__cplusplus)
extern "C" {
#endif


// Forward declarations

typedef struct test_Test test_Test;

// Extern declarations


// Declarations

struct test_Test {
    FIDL_ALIGNDECL
    uint64_t x;
};

#if defined(__cplusplus)
}
#endif
