// Copyright 2018 The Fuchsia Authors. All rights reserved.
// This is a GENERATED file, see //zircon/system/host/abigen.
// The license governing this file can be found in the LICENSE file.

zx_status_t _zx_nanosleep(zx_time_t deadline) {
    zx_status_t ret;
    do {
        ret = SYSCALL_zx_nanosleep(deadline);
    } while (unlikely(ret == ZX_ERR_INTERNAL_INTR_RETRY));
    return ret;
}

VDSO_INTERFACE_FUNCTION(zx_nanosleep);

zx_status_t _zx_object_wait_one(ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle, zx_signals_t waitfor, zx_time_t deadline, zx_signals_t* observed) {
    zx_status_t ret;
    do {
        ret = SYSCALL_zx_object_wait_one(handle, waitfor, deadline, observed);
    } while (unlikely(ret == ZX_ERR_INTERNAL_INTR_RETRY));
    return ret;
}

VDSO_INTERFACE_FUNCTION(zx_object_wait_one);

zx_status_t _zx_object_wait_many(zx_wait_item_t* items, uint32_t count, zx_time_t deadline) {
    zx_status_t ret;
    do {
        ret = SYSCALL_zx_object_wait_many(items, count, deadline);
    } while (unlikely(ret == ZX_ERR_INTERNAL_INTR_RETRY));
    return ret;
}

VDSO_INTERFACE_FUNCTION(zx_object_wait_many);

zx_status_t _zx_futex_wait(const zx_futex_t* value_ptr, int current_value, zx_time_t deadline) {
    zx_status_t ret;
    do {
        ret = SYSCALL_zx_futex_wait(value_ptr, current_value, deadline);
    } while (unlikely(ret == ZX_ERR_INTERNAL_INTR_RETRY));
    return ret;
}

VDSO_INTERFACE_FUNCTION(zx_futex_wait);

zx_status_t _zx_port_wait(ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle, zx_time_t deadline, zx_port_packet_t* packet, size_t count) {
    zx_status_t ret;
    do {
        ret = SYSCALL_zx_port_wait(handle, deadline, packet, count);
    } while (unlikely(ret == ZX_ERR_INTERNAL_INTR_RETRY));
    return ret;
}

VDSO_INTERFACE_FUNCTION(zx_port_wait);

zx_status_t _zx_interrupt_wait(ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle, zx_time_t* out_timestamp) {
    zx_status_t ret;
    do {
        ret = SYSCALL_zx_interrupt_wait(handle, out_timestamp);
    } while (unlikely(ret == ZX_ERR_INTERNAL_INTR_RETRY));
    return ret;
}

VDSO_INTERFACE_FUNCTION(zx_interrupt_wait);

zx_status_t _zx_syscall_test_wrapper(int a, int b, int c) {
    zx_status_t ret;
    if (a < 0 || b < 0 || c < 0) return ZX_ERR_INVALID_ARGS;
        ret = SYSCALL_zx_syscall_test_wrapper(a, b, c);
    if (ret > 50) return ZX_ERR_OUT_OF_RANGE;
    return ret;
}

VDSO_INTERFACE_FUNCTION(zx_syscall_test_wrapper);


