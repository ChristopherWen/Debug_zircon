// Copyright 2016 The Fuchsia Authors
// Copyright (c) 2014 Travis Geiselbrecht
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#pragma once

#define CURRENT_PERCPU_PTR_OFFSET 16

#ifndef __ASSEMBLER__

#include <assert.h>
#include <stddef.h>
#include <sys/types.h>
#include <zircon/compiler.h>
#include <zircon/tls.h>

__BEGIN_CDECLS

struct fpstate {
    uint32_t fpcr;
    uint32_t fpsr;
    uint64_t regs[64];
};

struct arm64_percpu;

struct arch_thread {
    // The compiler (when it's Clang with -mcmodel=kernel) knows
    // the position of these two fields relative to TPIDR_EL1,
    // which is what __builtin_thread_pointer() returns.  TPIDR_EL1
    // points just past these, i.e. to &abi[1].
    uintptr_t stack_guard;
    vaddr_t unsafe_sp;
    union {
        char thread_pointer_location;
        vaddr_t sp;
    };

    // Debugger access to userspace general regs while suspended or stopped
    // in an exception.
    // The regs are saved on the stack and then a pointer is stored here.
    // NULL if not suspended or stopped in an exception.
    struct arm64_iframe_long* suspended_general_regs;

    // Point to the current cpu pointer when the thread is running, used to
    // restore x18 on exception entry. Swapped on context switch.
    struct arm64_percpu* current_percpu_ptr;

    // if non-NULL, address to return to on data fault
    void* data_fault_resume;

    // saved fpu state
    struct fpstate fpstate;
};

#define thread_pointer_offsetof(field)          \
    ((int)offsetof(struct arch_thread, field) - \
     (int)offsetof(struct arch_thread, thread_pointer_location))

static_assert(
    thread_pointer_offsetof(stack_guard) == ZX_TLS_STACK_GUARD_OFFSET,
    "stack_guard field in wrong place");
static_assert(
    thread_pointer_offsetof(unsafe_sp) == ZX_TLS_UNSAFE_SP_OFFSET,
    "unsafe_sp field in wrong place");
static_assert(
    thread_pointer_offsetof(current_percpu_ptr) == CURRENT_PERCPU_PTR_OFFSET,
    "per cpu ptr offset in wrong place");

__END_CDECLS

#endif // __ASSEMBLER__
