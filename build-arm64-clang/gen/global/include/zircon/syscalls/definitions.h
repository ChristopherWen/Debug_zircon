// Copyright 2018 The Fuchsia Authors. All rights reserved.
// This is a GENERATED file, see //zircon/system/host/abigen.
// The license governing this file can be found in the LICENSE file.

extern zx_time_t zx_clock_get(
    uint32_t clock_id) __LEAF_FN;

extern zx_time_t _zx_clock_get(
    uint32_t clock_id) __LEAF_FN;

extern zx_status_t zx_nanosleep(
    zx_time_t deadline) __LEAF_FN;

extern zx_status_t _zx_nanosleep(
    zx_time_t deadline) __LEAF_FN;

extern uint64_t zx_ticks_get(
    void) __LEAF_FN;

extern uint64_t _zx_ticks_get(
    void) __LEAF_FN;

extern uint64_t zx_ticks_per_second(
    void) __LEAF_FN __CONST;

extern uint64_t _zx_ticks_per_second(
    void) __LEAF_FN __CONST;

extern zx_time_t zx_deadline_after(
    zx_duration_t nanoseconds) __LEAF_FN;

extern zx_time_t _zx_deadline_after(
    zx_duration_t nanoseconds) __LEAF_FN;

extern zx_status_t zx_clock_adjust(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t clock_id,
    int64_t offset) __LEAF_FN;

extern zx_status_t _zx_clock_adjust(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t clock_id,
    int64_t offset) __LEAF_FN;

extern uint32_t zx_system_get_dcache_line_size(
    void) __LEAF_FN __CONST;

extern uint32_t _zx_system_get_dcache_line_size(
    void) __LEAF_FN __CONST;

extern uint32_t zx_system_get_num_cpus(
    void) __LEAF_FN __CONST;

extern uint32_t _zx_system_get_num_cpus(
    void) __LEAF_FN __CONST;

extern zx_status_t zx_system_get_version(
    char* version,
    uint32_t version_len) __LEAF_FN;

extern zx_status_t _zx_system_get_version(
    char* version,
    uint32_t version_len) __LEAF_FN;

extern uint64_t zx_system_get_physmem(
    void) __LEAF_FN;

extern uint64_t _zx_system_get_physmem(
    void) __LEAF_FN;

extern zx_status_t zx_system_get_features(
    uint32_t kind,
    ZX_SYSCALL_PARAM_ATTR(features) uint32_t* out) __NONNULL((2)) __LEAF_FN;

extern zx_status_t _zx_system_get_features(
    uint32_t kind,
    ZX_SYSCALL_PARAM_ATTR(features) uint32_t* out) __NONNULL((2)) __LEAF_FN;

extern zx_status_t zx_cache_flush(
    const void* addr,
    size_t len,
    uint32_t options) __LEAF_FN;

extern zx_status_t _zx_cache_flush(
    const void* addr,
    size_t len,
    uint32_t options) __LEAF_FN;

extern zx_status_t zx_handle_close(
    ZX_SYSCALL_PARAM_ATTR(handle_release_always) zx_handle_t handle) __LEAF_FN;

extern zx_status_t _zx_handle_close(
    ZX_SYSCALL_PARAM_ATTR(handle_release_always) zx_handle_t handle) __LEAF_FN;

extern zx_status_t zx_handle_duplicate(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_rights_t rights,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((3)) __LEAF_FN;

extern zx_status_t _zx_handle_duplicate(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_rights_t rights,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((3)) __LEAF_FN;

extern zx_status_t zx_handle_replace(
    ZX_SYSCALL_PARAM_ATTR(handle_release) zx_handle_t handle,
    zx_rights_t rights,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((3)) __LEAF_FN;

extern zx_status_t _zx_handle_replace(
    ZX_SYSCALL_PARAM_ATTR(handle_release) zx_handle_t handle,
    zx_rights_t rights,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((3)) __LEAF_FN;

extern zx_status_t zx_object_wait_one(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_signals_t waitfor,
    zx_time_t deadline,
    zx_signals_t* observed) __LEAF_FN;

extern zx_status_t _zx_object_wait_one(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_signals_t waitfor,
    zx_time_t deadline,
    zx_signals_t* observed) __LEAF_FN;

extern zx_status_t zx_object_wait_many(
    zx_wait_item_t* items,
    uint32_t count,
    zx_time_t deadline) __LEAF_FN;

extern zx_status_t _zx_object_wait_many(
    zx_wait_item_t* items,
    uint32_t count,
    zx_time_t deadline) __LEAF_FN;

extern zx_status_t zx_object_wait_async(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t port_handle,
    uint64_t key,
    zx_signals_t signals,
    uint32_t options) __LEAF_FN;

extern zx_status_t _zx_object_wait_async(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t port_handle,
    uint64_t key,
    zx_signals_t signals,
    uint32_t options) __LEAF_FN;

extern zx_status_t zx_object_signal(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t clear_mask,
    uint32_t set_mask) __LEAF_FN;

extern zx_status_t _zx_object_signal(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t clear_mask,
    uint32_t set_mask) __LEAF_FN;

extern zx_status_t zx_object_signal_peer(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t clear_mask,
    uint32_t set_mask) __LEAF_FN;

extern zx_status_t _zx_object_signal_peer(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t clear_mask,
    uint32_t set_mask) __LEAF_FN;

extern zx_status_t zx_object_get_property(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t property,
    void* value,
    size_t size) __LEAF_FN;

extern zx_status_t _zx_object_get_property(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t property,
    void* value,
    size_t size) __LEAF_FN;

extern zx_status_t zx_object_set_property(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t property,
    const void* value,
    size_t size) __LEAF_FN;

extern zx_status_t _zx_object_set_property(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t property,
    const void* value,
    size_t size) __LEAF_FN;

extern zx_status_t zx_object_set_cookie(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t scope,
    uint64_t cookie) __LEAF_FN;

extern zx_status_t _zx_object_set_cookie(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t scope,
    uint64_t cookie) __LEAF_FN;

extern zx_status_t zx_object_get_cookie(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t scope,
    uint64_t* cookie) __NONNULL((3)) __LEAF_FN;

extern zx_status_t _zx_object_get_cookie(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t scope,
    uint64_t* cookie) __NONNULL((3)) __LEAF_FN;

extern zx_status_t zx_object_get_info(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t topic,
    void* buffer,
    size_t buffer_size,
    size_t* actual_count,
    size_t* avail_count) __LEAF_FN;

extern zx_status_t _zx_object_get_info(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t topic,
    void* buffer,
    size_t buffer_size,
    size_t* actual_count,
    size_t* avail_count) __LEAF_FN;

extern zx_status_t zx_object_get_child(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint64_t koid,
    zx_rights_t rights,
    zx_handle_t* out) __NONNULL((4)) __LEAF_FN;

extern zx_status_t _zx_object_get_child(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint64_t koid,
    zx_rights_t rights,
    zx_handle_t* out) __NONNULL((4)) __LEAF_FN;

extern zx_status_t zx_object_set_profile(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t profile,
    uint32_t options) __LEAF_FN;

extern zx_status_t _zx_object_set_profile(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t profile,
    uint32_t options) __LEAF_FN;

extern zx_status_t zx_channel_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out0,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out1) __NONNULL((2, 3)) __LEAF_FN;

extern zx_status_t _zx_channel_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out0,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out1) __NONNULL((2, 3)) __LEAF_FN;

extern zx_status_t zx_channel_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    void* bytes,
    zx_handle_t* handles,
    uint32_t num_bytes,
    uint32_t num_handles,
    uint32_t* actual_bytes,
    uint32_t* actual_handles) __LEAF_FN;

extern zx_status_t _zx_channel_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    void* bytes,
    zx_handle_t* handles,
    uint32_t num_bytes,
    uint32_t num_handles,
    uint32_t* actual_bytes,
    uint32_t* actual_handles) __LEAF_FN;

extern zx_status_t zx_channel_read_etc(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    void* bytes,
    zx_handle_info_t* handles,
    uint32_t num_bytes,
    uint32_t num_handles,
    uint32_t* actual_bytes,
    uint32_t* actual_handles) __LEAF_FN;

extern zx_status_t _zx_channel_read_etc(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    void* bytes,
    zx_handle_info_t* handles,
    uint32_t num_bytes,
    uint32_t num_handles,
    uint32_t* actual_bytes,
    uint32_t* actual_handles) __LEAF_FN;

extern zx_status_t zx_channel_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    const void* bytes,
    uint32_t num_bytes,
    const zx_handle_t* handles,
    uint32_t num_handles) __LEAF_FN;

extern zx_status_t _zx_channel_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    const void* bytes,
    uint32_t num_bytes,
    const zx_handle_t* handles,
    uint32_t num_handles) __LEAF_FN;

extern zx_status_t zx_channel_call(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    zx_time_t deadline,
    const zx_channel_call_args_t* args,
    uint32_t* actual_bytes,
    uint32_t* actual_handles,
    zx_status_t* read_status) __NONNULL((5, 6)) __LEAF_FN;

extern zx_status_t _zx_channel_call(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    zx_time_t deadline,
    const zx_channel_call_args_t* args,
    uint32_t* actual_bytes,
    uint32_t* actual_handles,
    zx_status_t* read_status) __NONNULL((5, 6)) __LEAF_FN;

extern zx_status_t zx_socket_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out0,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out1) __NONNULL((2, 3)) __LEAF_FN;

extern zx_status_t _zx_socket_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out0,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out1) __NONNULL((2, 3)) __LEAF_FN;

extern zx_status_t zx_socket_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    const void* buffer,
    size_t size,
    size_t* actual) __LEAF_FN;

extern zx_status_t _zx_socket_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    const void* buffer,
    size_t size,
    size_t* actual) __LEAF_FN;

extern zx_status_t zx_socket_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    void* buffer,
    size_t size,
    size_t* actual) __LEAF_FN;

extern zx_status_t _zx_socket_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    void* buffer,
    size_t size,
    size_t* actual) __LEAF_FN;

extern zx_status_t zx_socket_share(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t socket_to_share) __LEAF_FN;

extern zx_status_t _zx_socket_share(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t socket_to_share) __LEAF_FN;

extern zx_status_t zx_socket_accept(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out_socket) __NONNULL((2)) __LEAF_FN;

extern zx_status_t _zx_socket_accept(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out_socket) __NONNULL((2)) __LEAF_FN;

extern void zx_thread_exit(
    void) __LEAF_FN __NO_RETURN;

extern void _zx_thread_exit(
    void) __LEAF_FN __NO_RETURN;

extern zx_status_t zx_thread_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t process,
    const char* name,
    uint32_t name_len,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((5)) __LEAF_FN;

extern zx_status_t _zx_thread_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t process,
    const char* name,
    uint32_t name_len,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((5)) __LEAF_FN;

extern zx_status_t zx_thread_start(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uintptr_t thread_entry,
    uintptr_t stack,
    uintptr_t arg1,
    uintptr_t arg2) __LEAF_FN;

extern zx_status_t _zx_thread_start(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uintptr_t thread_entry,
    uintptr_t stack,
    uintptr_t arg1,
    uintptr_t arg2) __LEAF_FN;

extern zx_status_t zx_thread_read_state(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t kind,
    void* buffer,
    size_t len) __LEAF_FN;

extern zx_status_t _zx_thread_read_state(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t kind,
    void* buffer,
    size_t len) __LEAF_FN;

extern zx_status_t zx_thread_write_state(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t kind,
    const void* buffer,
    size_t buffer_len) __LEAF_FN;

extern zx_status_t _zx_thread_write_state(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t kind,
    const void* buffer,
    size_t buffer_len) __LEAF_FN;

extern zx_status_t zx_thread_set_priority(
    int32_t prio) __LEAF_FN;

extern zx_status_t _zx_thread_set_priority(
    int32_t prio) __LEAF_FN;

extern void zx_process_exit(
    int retcode) __LEAF_FN __NO_RETURN;

extern void _zx_process_exit(
    int retcode) __LEAF_FN __NO_RETURN;

extern zx_status_t zx_process_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t job,
    const char* name,
    uint32_t name_len,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* proc_handle,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* vmar_handle) __NONNULL((5, 6)) __LEAF_FN;

extern zx_status_t _zx_process_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t job,
    const char* name,
    uint32_t name_len,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* proc_handle,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* vmar_handle) __NONNULL((5, 6)) __LEAF_FN;

extern zx_status_t zx_process_start(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t process_handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t thread_handle,
    uintptr_t entry,
    uintptr_t stack,
    ZX_SYSCALL_PARAM_ATTR(handle_release) zx_handle_t arg_handle,
    uintptr_t arg2) __LEAF_FN;

extern zx_status_t _zx_process_start(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t process_handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t thread_handle,
    uintptr_t entry,
    uintptr_t stack,
    ZX_SYSCALL_PARAM_ATTR(handle_release) zx_handle_t arg_handle,
    uintptr_t arg2) __LEAF_FN;

extern zx_status_t zx_process_read_memory(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t proc,
    uintptr_t vaddr,
    void* buffer,
    size_t len,
    size_t* actual) __NONNULL((5)) __LEAF_FN;

extern zx_status_t _zx_process_read_memory(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t proc,
    uintptr_t vaddr,
    void* buffer,
    size_t len,
    size_t* actual) __NONNULL((5)) __LEAF_FN;

extern zx_status_t zx_process_write_memory(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t proc,
    uintptr_t vaddr,
    const void* buffer,
    size_t len,
    size_t* actual) __NONNULL((5)) __LEAF_FN;

extern zx_status_t _zx_process_write_memory(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t proc,
    uintptr_t vaddr,
    const void* buffer,
    size_t len,
    size_t* actual) __NONNULL((5)) __LEAF_FN;

extern zx_status_t zx_job_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t parent_job,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((3)) __LEAF_FN;

extern zx_status_t _zx_job_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t parent_job,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((3)) __LEAF_FN;

extern zx_status_t zx_job_set_policy(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t job,
    uint32_t options,
    uint32_t topic,
    const void* policy,
    uint32_t count) __LEAF_FN;

extern zx_status_t _zx_job_set_policy(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t job,
    uint32_t options,
    uint32_t topic,
    const void* policy,
    uint32_t count) __LEAF_FN;

extern zx_status_t zx_task_bind_exception_port(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t object,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t eport,
    uint64_t key,
    uint32_t options) __LEAF_FN;

extern zx_status_t _zx_task_bind_exception_port(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t object,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t eport,
    uint64_t key,
    uint32_t options) __LEAF_FN;

extern zx_status_t zx_task_suspend(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t task_handle) __LEAF_FN;

extern zx_status_t _zx_task_suspend(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t task_handle) __LEAF_FN;

extern zx_status_t zx_task_resume(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t task_handle,
    uint32_t options) __LEAF_FN;

extern zx_status_t _zx_task_resume(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t task_handle,
    uint32_t options) __LEAF_FN;

extern zx_status_t zx_task_suspend_token(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t task_handle,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* token) __NONNULL((2)) __LEAF_FN;

extern zx_status_t _zx_task_suspend_token(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t task_handle,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* token) __NONNULL((2)) __LEAF_FN;

extern zx_status_t zx_task_resume_from_exception(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t task_handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t eport,
    uint32_t options) __LEAF_FN;

extern zx_status_t _zx_task_resume_from_exception(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t task_handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t eport,
    uint32_t options) __LEAF_FN;

extern zx_status_t zx_task_kill(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t task_handle) __LEAF_FN;

extern zx_status_t _zx_task_kill(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t task_handle) __LEAF_FN;

extern zx_status_t zx_event_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((2)) __LEAF_FN;

extern zx_status_t _zx_event_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((2)) __LEAF_FN;

extern zx_status_t zx_eventpair_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out0,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out1) __NONNULL((2, 3)) __LEAF_FN;

extern zx_status_t _zx_eventpair_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out0,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out1) __NONNULL((2, 3)) __LEAF_FN;

extern zx_status_t zx_futex_wait(
    const zx_futex_t* value_ptr,
    int current_value,
    zx_time_t deadline) __LEAF_FN;

extern zx_status_t _zx_futex_wait(
    const zx_futex_t* value_ptr,
    int current_value,
    zx_time_t deadline) __LEAF_FN;

extern zx_status_t zx_futex_wake(
    const zx_futex_t* value_ptr,
    uint32_t count) __LEAF_FN;

extern zx_status_t _zx_futex_wake(
    const zx_futex_t* value_ptr,
    uint32_t count) __LEAF_FN;

extern zx_status_t zx_futex_requeue(
    const zx_futex_t* wake_ptr,
    uint32_t wake_count,
    int current_value,
    const zx_futex_t* requeue_ptr,
    uint32_t requeue_count) __LEAF_FN;

extern zx_status_t _zx_futex_requeue(
    const zx_futex_t* wake_ptr,
    uint32_t wake_count,
    int current_value,
    const zx_futex_t* requeue_ptr,
    uint32_t requeue_count) __LEAF_FN;

extern zx_status_t zx_port_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((2)) __LEAF_FN;

extern zx_status_t _zx_port_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((2)) __LEAF_FN;

extern zx_status_t zx_port_queue(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    const zx_port_packet_t* packet,
    size_t count) __LEAF_FN;

extern zx_status_t _zx_port_queue(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    const zx_port_packet_t* packet,
    size_t count) __LEAF_FN;

extern zx_status_t zx_port_wait(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_time_t deadline,
    zx_port_packet_t* packet,
    size_t count) __LEAF_FN;

extern zx_status_t _zx_port_wait(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_time_t deadline,
    zx_port_packet_t* packet,
    size_t count) __LEAF_FN;

extern zx_status_t zx_port_cancel(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t source,
    uint64_t key) __LEAF_FN;

extern zx_status_t _zx_port_cancel(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t source,
    uint64_t key) __LEAF_FN;

extern zx_status_t zx_timer_create(
    uint32_t options,
    uint32_t clock_id,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((3)) __LEAF_FN;

extern zx_status_t _zx_timer_create(
    uint32_t options,
    uint32_t clock_id,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((3)) __LEAF_FN;

extern zx_status_t zx_timer_set(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_time_t deadline,
    zx_duration_t slack) __LEAF_FN;

extern zx_status_t _zx_timer_set(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_time_t deadline,
    zx_duration_t slack) __LEAF_FN;

extern zx_status_t zx_timer_cancel(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle) __LEAF_FN;

extern zx_status_t _zx_timer_cancel(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle) __LEAF_FN;

extern zx_status_t zx_vmo_create(
    uint64_t size,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((3)) __LEAF_FN;

extern zx_status_t _zx_vmo_create(
    uint64_t size,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((3)) __LEAF_FN;

extern zx_status_t zx_vmo_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    void* data,
    uint64_t offset,
    size_t len) __LEAF_FN;

extern zx_status_t _zx_vmo_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    void* data,
    uint64_t offset,
    size_t len) __LEAF_FN;

extern zx_status_t zx_vmo_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    const void* data,
    uint64_t offset,
    size_t len) __LEAF_FN;

extern zx_status_t _zx_vmo_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    const void* data,
    uint64_t offset,
    size_t len) __LEAF_FN;

extern zx_status_t zx_vmo_get_size(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint64_t* size) __NONNULL((2)) __LEAF_FN;

extern zx_status_t _zx_vmo_get_size(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint64_t* size) __NONNULL((2)) __LEAF_FN;

extern zx_status_t zx_vmo_set_size(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint64_t size) __LEAF_FN;

extern zx_status_t _zx_vmo_set_size(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint64_t size) __LEAF_FN;

extern zx_status_t zx_vmo_op_range(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t op,
    uint64_t offset,
    uint64_t size,
    void* buffer,
    size_t buffer_size) __LEAF_FN;

extern zx_status_t _zx_vmo_op_range(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t op,
    uint64_t offset,
    uint64_t size,
    void* buffer,
    size_t buffer_size) __LEAF_FN;

extern zx_status_t zx_vmo_clone(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    uint64_t offset,
    uint64_t size,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((5)) __LEAF_FN;

extern zx_status_t _zx_vmo_clone(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    uint64_t offset,
    uint64_t size,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((5)) __LEAF_FN;

extern zx_status_t zx_vmo_set_cache_policy(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t cache_policy) __LEAF_FN;

extern zx_status_t _zx_vmo_set_cache_policy(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t cache_policy) __LEAF_FN;

extern zx_status_t zx_vmar_allocate(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t parent_vmar_handle,
    size_t offset,
    size_t size,
    uint32_t map_flags,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* child_vmar,
    uintptr_t* child_addr) __NONNULL((5, 6)) __LEAF_FN;

extern zx_status_t _zx_vmar_allocate(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t parent_vmar_handle,
    size_t offset,
    size_t size,
    uint32_t map_flags,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* child_vmar,
    uintptr_t* child_addr) __NONNULL((5, 6)) __LEAF_FN;

extern zx_status_t zx_vmar_destroy(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmar_handle) __LEAF_FN;

extern zx_status_t _zx_vmar_destroy(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmar_handle) __LEAF_FN;

extern zx_status_t zx_vmar_map(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmar_handle,
    size_t vmar_offset,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmo_handle,
    uint64_t vmo_offset,
    size_t len,
    uint32_t map_flags,
    uintptr_t* mapped_addr) __NONNULL((7)) __LEAF_FN;

extern zx_status_t _zx_vmar_map(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmar_handle,
    size_t vmar_offset,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmo_handle,
    uint64_t vmo_offset,
    size_t len,
    uint32_t map_flags,
    uintptr_t* mapped_addr) __NONNULL((7)) __LEAF_FN;

extern zx_status_t zx_vmar_unmap(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmar_handle,
    uintptr_t addr,
    size_t len) __LEAF_FN;

extern zx_status_t _zx_vmar_unmap(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmar_handle,
    uintptr_t addr,
    size_t len) __LEAF_FN;

extern zx_status_t zx_vmar_protect(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmar_handle,
    uintptr_t addr,
    size_t len,
    uint32_t prot_flags) __LEAF_FN;

extern zx_status_t _zx_vmar_protect(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmar_handle,
    uintptr_t addr,
    size_t len,
    uint32_t prot_flags) __LEAF_FN;

extern zx_status_t zx_cprng_draw(
    void* buffer,
    size_t len,
    size_t* actual) __NONNULL((3)) __LEAF_FN;

extern zx_status_t _zx_cprng_draw(
    void* buffer,
    size_t len,
    size_t* actual) __NONNULL((3)) __LEAF_FN;

extern zx_status_t zx_cprng_add_entropy(
    const void* buffer,
    size_t len) __LEAF_FN;

extern zx_status_t _zx_cprng_add_entropy(
    const void* buffer,
    size_t len) __LEAF_FN;

extern zx_status_t zx_fifo_create(
    uint32_t elem_count,
    uint32_t elem_size,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out0,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out1) __NONNULL((4, 5)) __LEAF_FN;

extern zx_status_t _zx_fifo_create(
    uint32_t elem_count,
    uint32_t elem_size,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out0,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out1) __NONNULL((4, 5)) __LEAF_FN;

extern zx_status_t zx_fifo_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    void* data,
    size_t len,
    uint32_t* num_written) __NONNULL((4)) __LEAF_FN __DEPRECATE;

extern zx_status_t _zx_fifo_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    void* data,
    size_t len,
    uint32_t* num_written) __NONNULL((4)) __LEAF_FN __DEPRECATE;

extern zx_status_t zx_fifo_read_old(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    void* data,
    size_t len,
    uint32_t* num_written) __NONNULL((4)) __LEAF_FN;

extern zx_status_t _zx_fifo_read_old(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    void* data,
    size_t len,
    uint32_t* num_written) __NONNULL((4)) __LEAF_FN;

extern zx_status_t zx_fifo_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    const void* data,
    size_t len,
    uint32_t* num_written) __NONNULL((4)) __LEAF_FN __DEPRECATE;

extern zx_status_t _zx_fifo_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    const void* data,
    size_t len,
    uint32_t* num_written) __NONNULL((4)) __LEAF_FN __DEPRECATE;

extern zx_status_t zx_fifo_write_old(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    const void* data,
    size_t len,
    uint32_t* num_written) __NONNULL((4)) __LEAF_FN;

extern zx_status_t _zx_fifo_write_old(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    const void* data,
    size_t len,
    uint32_t* num_written) __NONNULL((4)) __LEAF_FN;

extern zx_status_t zx_profile_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t resource,
    const zx_profile_info_t* profile,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((3)) __LEAF_FN;

extern zx_status_t _zx_profile_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t resource,
    const zx_profile_info_t* profile,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((3)) __LEAF_FN;

extern zx_status_t zx_vmar_unmap_handle_close_thread_exit(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmar_handle,
    uintptr_t addr,
    size_t len,
    ZX_SYSCALL_PARAM_ATTR(handle_release) zx_handle_t handle) __LEAF_FN;

extern zx_status_t _zx_vmar_unmap_handle_close_thread_exit(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmar_handle,
    uintptr_t addr,
    size_t len,
    ZX_SYSCALL_PARAM_ATTR(handle_release) zx_handle_t handle) __LEAF_FN;

extern void zx_futex_wake_handle_close_thread_exit(
    const zx_futex_t* value_ptr,
    uint32_t count,
    int new_value,
    ZX_SYSCALL_PARAM_ATTR(handle_release) zx_handle_t handle) __LEAF_FN __NO_RETURN;

extern void _zx_futex_wake_handle_close_thread_exit(
    const zx_futex_t* value_ptr,
    uint32_t count,
    int new_value,
    ZX_SYSCALL_PARAM_ATTR(handle_release) zx_handle_t handle) __LEAF_FN __NO_RETURN;

extern zx_status_t zx_log_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((2)) __LEAF_FN;

extern zx_status_t _zx_log_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((2)) __LEAF_FN;

extern zx_status_t zx_log_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t len,
    const void* buffer,
    uint32_t options) __LEAF_FN;

extern zx_status_t _zx_log_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t len,
    const void* buffer,
    uint32_t options) __LEAF_FN;

extern zx_status_t zx_log_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t len,
    void* buffer,
    uint32_t options) __LEAF_FN;

extern zx_status_t _zx_log_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t len,
    void* buffer,
    uint32_t options) __LEAF_FN;

extern zx_status_t zx_debuglog_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t resource,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((3)) __LEAF_FN;

extern zx_status_t _zx_debuglog_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t resource,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((3)) __LEAF_FN;

extern zx_status_t zx_debuglog_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    const void* buffer,
    size_t len) __LEAF_FN;

extern zx_status_t _zx_debuglog_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    const void* buffer,
    size_t len) __LEAF_FN;

extern zx_status_t zx_debuglog_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    void* buffer,
    size_t len) __LEAF_FN;

extern zx_status_t _zx_debuglog_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    void* buffer,
    size_t len) __LEAF_FN;

extern zx_status_t zx_ktrace_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    void* data,
    uint32_t offset,
    uint32_t len,
    uint32_t* actual) __NONNULL((5)) __LEAF_FN;

extern zx_status_t _zx_ktrace_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    void* data,
    uint32_t offset,
    uint32_t len,
    uint32_t* actual) __NONNULL((5)) __LEAF_FN;

extern zx_status_t zx_ktrace_control(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t action,
    uint32_t options,
    void* ptr) __LEAF_FN;

extern zx_status_t _zx_ktrace_control(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t action,
    uint32_t options,
    void* ptr) __LEAF_FN;

extern zx_status_t zx_ktrace_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t id,
    uint32_t arg0,
    uint32_t arg1) __LEAF_FN;

extern zx_status_t _zx_ktrace_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t id,
    uint32_t arg0,
    uint32_t arg1) __LEAF_FN;

extern zx_status_t zx_mtrace_control(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t kind,
    uint32_t action,
    uint32_t options,
    void* ptr,
    uint32_t size) __LEAF_FN;

extern zx_status_t _zx_mtrace_control(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t kind,
    uint32_t action,
    uint32_t options,
    void* ptr,
    uint32_t size) __LEAF_FN;

extern zx_status_t zx_debug_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    char* buffer,
    size_t* length) __LEAF_FN;

extern zx_status_t _zx_debug_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    char* buffer,
    size_t* length) __LEAF_FN;

extern zx_status_t zx_debug_write(
    const char* buffer,
    size_t length) __LEAF_FN;

extern zx_status_t _zx_debug_write(
    const char* buffer,
    size_t length) __LEAF_FN;

extern zx_status_t zx_debug_send_command(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t resource_handle,
    const char* buffer,
    size_t length) __LEAF_FN;

extern zx_status_t _zx_debug_send_command(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t resource_handle,
    const char* buffer,
    size_t length) __LEAF_FN;

extern zx_status_t zx_interrupt_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t src_obj,
    uint32_t src_num,
    uint32_t options,
    zx_handle_t* out_handle) __NONNULL((4)) __LEAF_FN;

extern zx_status_t _zx_interrupt_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t src_obj,
    uint32_t src_num,
    uint32_t options,
    zx_handle_t* out_handle) __NONNULL((4)) __LEAF_FN;

extern zx_status_t zx_interrupt_bind(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t inth,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t porth,
    uint64_t key,
    uint32_t options) __LEAF_FN;

extern zx_status_t _zx_interrupt_bind(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t inth,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t porth,
    uint64_t key,
    uint32_t options) __LEAF_FN;

extern zx_status_t zx_interrupt_wait(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_time_t* out_timestamp) __LEAF_FN;

extern zx_status_t _zx_interrupt_wait(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_time_t* out_timestamp) __LEAF_FN;

extern zx_status_t zx_interrupt_destroy(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle) __LEAF_FN;

extern zx_status_t _zx_interrupt_destroy(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle) __LEAF_FN;

extern zx_status_t zx_interrupt_ack(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle) __LEAF_FN;

extern zx_status_t _zx_interrupt_ack(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle) __LEAF_FN;

extern zx_status_t zx_interrupt_trigger(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    zx_time_t timestamp) __LEAF_FN;

extern zx_status_t _zx_interrupt_trigger(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    zx_time_t timestamp) __LEAF_FN;

extern zx_status_t zx_mmap_device_io(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t io_addr,
    uint32_t len) __LEAF_FN;

extern zx_status_t _zx_mmap_device_io(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t io_addr,
    uint32_t len) __LEAF_FN;

extern zx_status_t zx_vmo_create_contiguous(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t bti,
    size_t size,
    uint32_t alignment_log2,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((4)) __LEAF_FN;

extern zx_status_t _zx_vmo_create_contiguous(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t bti,
    size_t size,
    uint32_t alignment_log2,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((4)) __LEAF_FN;

extern zx_status_t zx_vmo_create_physical(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t rsrc_handle,
    zx_paddr_t paddr,
    size_t size,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((4)) __LEAF_FN;

extern zx_status_t _zx_vmo_create_physical(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t rsrc_handle,
    zx_paddr_t paddr,
    size_t size,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((4)) __LEAF_FN;

extern zx_status_t zx_iommu_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t rsrc_handle,
    uint32_t type,
    const void* desc,
    uint32_t desc_len,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((5)) __LEAF_FN;

extern zx_status_t _zx_iommu_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t rsrc_handle,
    uint32_t type,
    const void* desc,
    uint32_t desc_len,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((5)) __LEAF_FN;

extern zx_status_t zx_bti_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t iommu,
    uint32_t options,
    uint64_t bti_id,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((4)) __LEAF_FN;

extern zx_status_t _zx_bti_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t iommu,
    uint32_t options,
    uint64_t bti_id,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((4)) __LEAF_FN;

extern zx_status_t zx_bti_pin(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t bti,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmo,
    uint64_t offset,
    uint64_t size,
    zx_paddr_t* addrs,
    size_t addrs_count,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((8)) __LEAF_FN;

extern zx_status_t _zx_bti_pin(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t bti,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmo,
    uint64_t offset,
    uint64_t size,
    zx_paddr_t* addrs,
    size_t addrs_count,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((8)) __LEAF_FN;

extern zx_status_t zx_bti_release_quarantine(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t bti) __LEAF_FN;

extern zx_status_t _zx_bti_release_quarantine(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t bti) __LEAF_FN;

extern zx_status_t zx_pmt_unpin(
    ZX_SYSCALL_PARAM_ATTR(handle_release) zx_handle_t pmt) __LEAF_FN;

extern zx_status_t _zx_pmt_unpin(
    ZX_SYSCALL_PARAM_ATTR(handle_release) zx_handle_t pmt) __LEAF_FN;

extern zx_status_t zx_bootloader_fb_get_info(
    uint32_t* format,
    uint32_t* width,
    uint32_t* height,
    uint32_t* stride) __NONNULL((1, 2, 3, 4)) __LEAF_FN;

extern zx_status_t _zx_bootloader_fb_get_info(
    uint32_t* format,
    uint32_t* width,
    uint32_t* height,
    uint32_t* stride) __NONNULL((1, 2, 3, 4)) __LEAF_FN;

extern zx_status_t zx_set_framebuffer(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    void* vaddr,
    uint32_t len,
    uint32_t format,
    uint32_t width,
    uint32_t height,
    uint32_t stride) __LEAF_FN;

extern zx_status_t _zx_set_framebuffer(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    void* vaddr,
    uint32_t len,
    uint32_t format,
    uint32_t width,
    uint32_t height,
    uint32_t stride) __LEAF_FN;

extern zx_status_t zx_set_framebuffer_vmo(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmo,
    uint32_t len,
    uint32_t format,
    uint32_t width,
    uint32_t height,
    uint32_t stride) __LEAF_FN;

extern zx_status_t _zx_set_framebuffer_vmo(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmo,
    uint32_t len,
    uint32_t format,
    uint32_t width,
    uint32_t height,
    uint32_t stride) __LEAF_FN;

extern zx_status_t zx_pci_get_nth_device(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t index,
    zx_pcie_device_info_t* out_info,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out_handle) __NONNULL((3, 4)) __LEAF_FN;

extern zx_status_t _zx_pci_get_nth_device(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t index,
    zx_pcie_device_info_t* out_info,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out_handle) __NONNULL((3, 4)) __LEAF_FN;

extern zx_status_t zx_pci_enable_bus_master(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    bool enable) __LEAF_FN;

extern zx_status_t _zx_pci_enable_bus_master(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    bool enable) __LEAF_FN;

extern zx_status_t zx_pci_reset_device(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle) __LEAF_FN;

extern zx_status_t _zx_pci_reset_device(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle) __LEAF_FN;

extern zx_status_t zx_pci_config_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint16_t offset,
    size_t width,
    uint32_t* out_val) __LEAF_FN;

extern zx_status_t _zx_pci_config_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint16_t offset,
    size_t width,
    uint32_t* out_val) __LEAF_FN;

extern zx_status_t zx_pci_config_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint16_t offset,
    size_t width,
    uint32_t val) __LEAF_FN;

extern zx_status_t _zx_pci_config_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint16_t offset,
    size_t width,
    uint32_t val) __LEAF_FN;

extern zx_status_t zx_pci_cfg_pio_rw(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint8_t bus,
    uint8_t dev,
    uint8_t func,
    uint8_t offset,
    uint32_t* val,
    size_t width,
    bool write) __LEAF_FN;

extern zx_status_t _zx_pci_cfg_pio_rw(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint8_t bus,
    uint8_t dev,
    uint8_t func,
    uint8_t offset,
    uint32_t* val,
    size_t width,
    bool write) __LEAF_FN;

extern zx_status_t zx_pci_get_bar(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t bar_num,
    zx_pci_bar_t* out_bar,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out_handle) __NONNULL((4)) __LEAF_FN;

extern zx_status_t _zx_pci_get_bar(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t bar_num,
    zx_pci_bar_t* out_bar,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out_handle) __NONNULL((4)) __LEAF_FN;

extern zx_status_t zx_pci_map_interrupt(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    int32_t which_irq,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out_handle) __NONNULL((3)) __LEAF_FN;

extern zx_status_t _zx_pci_map_interrupt(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    int32_t which_irq,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out_handle) __NONNULL((3)) __LEAF_FN;

extern zx_status_t zx_pci_query_irq_mode(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t mode,
    uint32_t* out_max_irqs) __NONNULL((3)) __LEAF_FN;

extern zx_status_t _zx_pci_query_irq_mode(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t mode,
    uint32_t* out_max_irqs) __NONNULL((3)) __LEAF_FN;

extern zx_status_t zx_pci_set_irq_mode(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t mode,
    uint32_t requested_irq_count) __LEAF_FN;

extern zx_status_t _zx_pci_set_irq_mode(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t mode,
    uint32_t requested_irq_count) __LEAF_FN;

extern zx_status_t zx_pci_init(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    const zx_pci_init_arg_t* init_buf,
    uint32_t len) __LEAF_FN;

extern zx_status_t _zx_pci_init(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    const zx_pci_init_arg_t* init_buf,
    uint32_t len) __LEAF_FN;

extern zx_status_t zx_pci_add_subtract_io_range(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    bool mmio,
    uint64_t base,
    uint64_t len,
    bool add) __LEAF_FN;

extern zx_status_t _zx_pci_add_subtract_io_range(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    bool mmio,
    uint64_t base,
    uint64_t len,
    bool add) __LEAF_FN;

extern zx_status_t zx_pc_firmware_tables(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_paddr_t* acpi_rsdp,
    zx_paddr_t* smbios) __NONNULL((2, 3)) __LEAF_FN;

extern zx_status_t _zx_pc_firmware_tables(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_paddr_t* acpi_rsdp,
    zx_paddr_t* smbios) __NONNULL((2, 3)) __LEAF_FN;

extern zx_status_t zx_smc_call(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t rsrc_handle,
    uint64_t arg0,
    uint64_t arg1,
    uint64_t arg2,
    uint64_t arg3,
    uint64_t* out_smc_status) __LEAF_FN;

extern zx_status_t _zx_smc_call(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t rsrc_handle,
    uint64_t arg0,
    uint64_t arg1,
    uint64_t arg2,
    uint64_t arg3,
    uint64_t* out_smc_status) __LEAF_FN;

extern zx_status_t zx_resource_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t parent_handle,
    uint32_t kind,
    uint64_t low,
    uint64_t high,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* resource_out) __NONNULL((5)) __LEAF_FN;

extern zx_status_t _zx_resource_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t parent_handle,
    uint32_t kind,
    uint64_t low,
    uint64_t high,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* resource_out) __NONNULL((5)) __LEAF_FN;

extern zx_status_t zx_guest_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t resource,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t physmem_vmo,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((4)) __LEAF_FN;

extern zx_status_t _zx_guest_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t resource,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t physmem_vmo,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((4)) __LEAF_FN;

extern zx_status_t zx_guest_set_trap(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t guest,
    uint32_t kind,
    zx_vaddr_t addr,
    size_t len,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t port,
    uint64_t key) __LEAF_FN;

extern zx_status_t _zx_guest_set_trap(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t guest,
    uint32_t kind,
    zx_vaddr_t addr,
    size_t len,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t port,
    uint64_t key) __LEAF_FN;

extern zx_status_t zx_vcpu_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t guest,
    uint32_t options,
    zx_vaddr_t entry,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((4)) __LEAF_FN;

extern zx_status_t _zx_vcpu_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t guest,
    uint32_t options,
    zx_vaddr_t entry,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) zx_handle_t* out) __NONNULL((4)) __LEAF_FN;

extern zx_status_t zx_vcpu_resume(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vcpu,
    zx_port_packet_t* packet) __NONNULL((2)) __LEAF_FN;

extern zx_status_t _zx_vcpu_resume(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vcpu,
    zx_port_packet_t* packet) __NONNULL((2)) __LEAF_FN;

extern zx_status_t zx_vcpu_interrupt(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vcpu,
    uint32_t vector) __LEAF_FN;

extern zx_status_t _zx_vcpu_interrupt(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vcpu,
    uint32_t vector) __LEAF_FN;

extern zx_status_t zx_vcpu_read_state(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vcpu,
    uint32_t kind,
    void* buffer,
    uint32_t len) __LEAF_FN;

extern zx_status_t _zx_vcpu_read_state(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vcpu,
    uint32_t kind,
    void* buffer,
    uint32_t len) __LEAF_FN;

extern zx_status_t zx_vcpu_write_state(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vcpu,
    uint32_t kind,
    const void* buffer,
    uint32_t len) __LEAF_FN;

extern zx_status_t _zx_vcpu_write_state(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vcpu,
    uint32_t kind,
    const void* buffer,
    uint32_t len) __LEAF_FN;

extern zx_status_t zx_system_mexec(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t kernel,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t bootimage) __LEAF_FN;

extern zx_status_t _zx_system_mexec(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t kernel,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t bootimage) __LEAF_FN;

extern zx_status_t zx_system_powerctl(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t root_rsrc,
    uint32_t cmd,
    const zx_system_powerctl_arg_t* arg) __LEAF_FN;

extern zx_status_t _zx_system_powerctl(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t root_rsrc,
    uint32_t cmd,
    const zx_system_powerctl_arg_t* arg) __LEAF_FN;

extern zx_status_t zx_job_set_relative_importance(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t root_resource,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t job,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t less_important_job) __LEAF_FN;

extern zx_status_t _zx_job_set_relative_importance(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t root_resource,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t job,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t less_important_job) __LEAF_FN;

extern zx_status_t zx_syscall_test_0(
    void) __LEAF_FN;

extern zx_status_t _zx_syscall_test_0(
    void) __LEAF_FN;

extern zx_status_t zx_syscall_test_1(
    int a) __LEAF_FN;

extern zx_status_t _zx_syscall_test_1(
    int a) __LEAF_FN;

extern zx_status_t zx_syscall_test_2(
    int a,
    int b) __LEAF_FN;

extern zx_status_t _zx_syscall_test_2(
    int a,
    int b) __LEAF_FN;

extern zx_status_t zx_syscall_test_3(
    int a,
    int b,
    int c) __LEAF_FN;

extern zx_status_t _zx_syscall_test_3(
    int a,
    int b,
    int c) __LEAF_FN;

extern zx_status_t zx_syscall_test_4(
    int a,
    int b,
    int c,
    int d) __LEAF_FN;

extern zx_status_t _zx_syscall_test_4(
    int a,
    int b,
    int c,
    int d) __LEAF_FN;

extern zx_status_t zx_syscall_test_5(
    int a,
    int b,
    int c,
    int d,
    int e) __LEAF_FN;

extern zx_status_t _zx_syscall_test_5(
    int a,
    int b,
    int c,
    int d,
    int e) __LEAF_FN;

extern zx_status_t zx_syscall_test_6(
    int a,
    int b,
    int c,
    int d,
    int e,
    int f) __LEAF_FN;

extern zx_status_t _zx_syscall_test_6(
    int a,
    int b,
    int c,
    int d,
    int e,
    int f) __LEAF_FN;

extern zx_status_t zx_syscall_test_7(
    int a,
    int b,
    int c,
    int d,
    int e,
    int f,
    int g) __LEAF_FN;

extern zx_status_t _zx_syscall_test_7(
    int a,
    int b,
    int c,
    int d,
    int e,
    int f,
    int g) __LEAF_FN;

extern zx_status_t zx_syscall_test_8(
    int a,
    int b,
    int c,
    int d,
    int e,
    int f,
    int g,
    int h) __LEAF_FN;

extern zx_status_t _zx_syscall_test_8(
    int a,
    int b,
    int c,
    int d,
    int e,
    int f,
    int g,
    int h) __LEAF_FN;

extern zx_status_t zx_syscall_test_wrapper(
    int a,
    int b,
    int c) __LEAF_FN;

extern zx_status_t _zx_syscall_test_wrapper(
    int a,
    int b,
    int c) __LEAF_FN;


