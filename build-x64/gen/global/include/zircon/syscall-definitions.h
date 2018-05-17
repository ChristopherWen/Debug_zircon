// Copyright 2018 The Fuchsia Authors. All rights reserved.
// This is a GENERATED file, see //zircon/system/host/abigen.
// The license governing this file can be found in the LICENSE file.

zx_time_t sys_clock_get(
    uint32_t clock_id);

zx_status_t sys_nanosleep(
    zx_time_t deadline);

zx_status_t sys_clock_adjust(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t clock_id,
    int64_t offset);

zx_status_t sys_handle_close(
    ZX_SYSCALL_PARAM_ATTR(handle_release_always) zx_handle_t handle);

zx_status_t sys_handle_duplicate(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_rights_t rights,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_handle_replace(
    ZX_SYSCALL_PARAM_ATTR(handle_release) zx_handle_t handle,
    zx_rights_t rights,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_object_wait_one(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_signals_t waitfor,
    zx_time_t deadline,
    user_out_ptr<zx_signals_t> observed);

zx_status_t sys_object_wait_many(
    user_inout_ptr<zx_wait_item_t> items,
    uint32_t count,
    zx_time_t deadline);

zx_status_t sys_object_wait_async(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t port_handle,
    uint64_t key,
    zx_signals_t signals,
    uint32_t options);

zx_status_t sys_object_signal(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t clear_mask,
    uint32_t set_mask);

zx_status_t sys_object_signal_peer(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t clear_mask,
    uint32_t set_mask);

zx_status_t sys_object_get_property(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t property,
    user_out_ptr<void> value,
    size_t size);

zx_status_t sys_object_set_property(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t property,
    user_in_ptr<const void> value,
    size_t size);

zx_status_t sys_object_set_cookie(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t scope,
    uint64_t cookie);

zx_status_t sys_object_get_cookie(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t scope,
    user_out_ptr<uint64_t> cookie);

zx_status_t sys_object_get_info(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t topic,
    user_out_ptr<void> buffer,
    size_t buffer_size,
    user_out_ptr<size_t> actual_count,
    user_out_ptr<size_t> avail_count);

zx_status_t sys_object_get_child(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint64_t koid,
    zx_rights_t rights,
    user_out_handle* out);

zx_status_t sys_object_set_profile(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t profile,
    uint32_t options);

zx_status_t sys_channel_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out0,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out1);

zx_status_t sys_channel_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    user_out_ptr<void> bytes,
    user_out_ptr<zx_handle_t> handles,
    uint32_t num_bytes,
    uint32_t num_handles,
    user_out_ptr<uint32_t> actual_bytes,
    user_out_ptr<uint32_t> actual_handles);

zx_status_t sys_channel_read_etc(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    user_out_ptr<void> bytes,
    user_out_ptr<zx_handle_info_t> handles,
    uint32_t num_bytes,
    uint32_t num_handles,
    user_out_ptr<uint32_t> actual_bytes,
    user_out_ptr<uint32_t> actual_handles);

zx_status_t sys_channel_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    user_in_ptr<const void> bytes,
    uint32_t num_bytes,
    user_in_ptr<const zx_handle_t> handles,
    uint32_t num_handles);

zx_status_t sys_channel_call_noretry(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    zx_time_t deadline,
    user_in_ptr<const zx_channel_call_args_t> args,
    user_out_ptr<uint32_t> actual_bytes,
    user_out_ptr<uint32_t> actual_handles,
    user_out_ptr<zx_status_t> read_status);

zx_status_t sys_channel_call_finish(
    zx_time_t deadline,
    user_in_ptr<const zx_channel_call_args_t> args,
    user_out_ptr<uint32_t> actual_bytes,
    user_out_ptr<uint32_t> actual_handles,
    user_out_ptr<zx_status_t> read_status);

zx_status_t sys_socket_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out0,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out1);

zx_status_t sys_socket_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    user_in_ptr<const void> buffer,
    size_t size,
    user_out_ptr<size_t> actual);

zx_status_t sys_socket_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    user_out_ptr<void> buffer,
    size_t size,
    user_out_ptr<size_t> actual);

zx_status_t sys_socket_share(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t socket_to_share);

zx_status_t sys_socket_accept(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out_socket);

void sys_thread_exit(
    ) __NO_RETURN;

zx_status_t sys_thread_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t process,
    user_in_ptr<const char> name,
    uint32_t name_len,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_thread_start(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uintptr_t thread_entry,
    uintptr_t stack,
    uintptr_t arg1,
    uintptr_t arg2);

zx_status_t sys_thread_read_state(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t kind,
    user_out_ptr<void> buffer,
    size_t len);

zx_status_t sys_thread_write_state(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t kind,
    user_in_ptr<const void> buffer,
    size_t buffer_len);

zx_status_t sys_thread_set_priority(
    int32_t prio);

void sys_process_exit(
    int retcode) __NO_RETURN;

zx_status_t sys_process_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t job,
    user_in_ptr<const char> name,
    uint32_t name_len,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* proc_handle,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* vmar_handle);

zx_status_t sys_process_start(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t process_handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t thread_handle,
    uintptr_t entry,
    uintptr_t stack,
    ZX_SYSCALL_PARAM_ATTR(handle_release) zx_handle_t arg_handle,
    uintptr_t arg2);

zx_status_t sys_process_read_memory(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t proc,
    uintptr_t vaddr,
    user_out_ptr<void> buffer,
    size_t len,
    user_out_ptr<size_t> actual);

zx_status_t sys_process_write_memory(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t proc,
    uintptr_t vaddr,
    user_in_ptr<const void> buffer,
    size_t len,
    user_out_ptr<size_t> actual);

zx_status_t sys_job_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t parent_job,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_job_set_policy(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t job,
    uint32_t options,
    uint32_t topic,
    user_in_ptr<const void> policy,
    uint32_t count);

zx_status_t sys_task_bind_exception_port(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t object,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t eport,
    uint64_t key,
    uint32_t options);

zx_status_t sys_task_suspend(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t task_handle);

zx_status_t sys_task_resume(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t task_handle,
    uint32_t options);

zx_status_t sys_task_suspend_token(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t task_handle,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* token);

zx_status_t sys_task_resume_from_exception(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t task_handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t eport,
    uint32_t options);

zx_status_t sys_task_kill(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t task_handle);

zx_status_t sys_event_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_eventpair_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out0,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out1);

zx_status_t sys_futex_wait(
    user_in_ptr<const zx_futex_t> value_ptr,
    int current_value,
    zx_time_t deadline);

zx_status_t sys_futex_wake(
    user_in_ptr<const zx_futex_t> value_ptr,
    uint32_t count);

zx_status_t sys_futex_requeue(
    user_in_ptr<const zx_futex_t> wake_ptr,
    uint32_t wake_count,
    int current_value,
    user_in_ptr<const zx_futex_t> requeue_ptr,
    uint32_t requeue_count);

zx_status_t sys_port_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_port_queue(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    user_in_ptr<const zx_port_packet_t> packet,
    size_t count);

zx_status_t sys_port_wait(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_time_t deadline,
    user_out_ptr<zx_port_packet_t> packet,
    size_t count);

zx_status_t sys_port_cancel(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t source,
    uint64_t key);

zx_status_t sys_timer_create(
    uint32_t options,
    uint32_t clock_id,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_timer_set(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    zx_time_t deadline,
    zx_duration_t slack);

zx_status_t sys_timer_cancel(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle);

zx_status_t sys_vmo_create(
    uint64_t size,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_vmo_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    user_out_ptr<void> data,
    uint64_t offset,
    size_t len);

zx_status_t sys_vmo_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    user_in_ptr<const void> data,
    uint64_t offset,
    size_t len);

zx_status_t sys_vmo_get_size(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    user_out_ptr<uint64_t> size);

zx_status_t sys_vmo_set_size(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint64_t size);

zx_status_t sys_vmo_op_range(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t op,
    uint64_t offset,
    uint64_t size,
    user_inout_ptr<void> buffer,
    size_t buffer_size);

zx_status_t sys_vmo_clone(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    uint64_t offset,
    uint64_t size,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_vmo_set_cache_policy(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t cache_policy);

zx_status_t sys_vmar_allocate(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t parent_vmar_handle,
    size_t offset,
    size_t size,
    uint32_t map_flags,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* child_vmar,
    user_out_ptr<uintptr_t> child_addr);

zx_status_t sys_vmar_destroy(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmar_handle);

zx_status_t sys_vmar_map(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmar_handle,
    size_t vmar_offset,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmo_handle,
    uint64_t vmo_offset,
    size_t len,
    uint32_t map_flags,
    user_out_ptr<uintptr_t> mapped_addr);

zx_status_t sys_vmar_unmap(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmar_handle,
    uintptr_t addr,
    size_t len);

zx_status_t sys_vmar_protect(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmar_handle,
    uintptr_t addr,
    size_t len,
    uint32_t prot_flags);

zx_status_t sys_cprng_draw(
    user_out_ptr<void> buffer,
    size_t len,
    user_out_ptr<size_t> actual);

zx_status_t sys_cprng_add_entropy(
    user_in_ptr<const void> buffer,
    size_t len);

zx_status_t sys_fifo_create(
    uint32_t elem_count,
    uint32_t elem_size,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out0,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out1);

zx_status_t sys_fifo_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    user_out_ptr<void> data,
    size_t len,
    user_out_ptr<uint32_t> num_written);

zx_status_t sys_fifo_read_old(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    user_out_ptr<void> data,
    size_t len,
    user_out_ptr<uint32_t> num_written);

zx_status_t sys_fifo_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    user_in_ptr<const void> data,
    size_t len,
    user_out_ptr<uint32_t> num_written);

zx_status_t sys_fifo_write_old(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    user_in_ptr<const void> data,
    size_t len,
    user_out_ptr<uint32_t> num_written);

zx_status_t sys_profile_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t resource,
    user_in_ptr<const zx_profile_info_t> profile,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_log_create(
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_log_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t len,
    user_in_ptr<const void> buffer,
    uint32_t options);

zx_status_t sys_log_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t len,
    user_out_ptr<void> buffer,
    uint32_t options);

zx_status_t sys_debuglog_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t resource,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_debuglog_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    user_in_ptr<const void> buffer,
    size_t len);

zx_status_t sys_debuglog_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    user_out_ptr<void> buffer,
    size_t len);

zx_status_t sys_ktrace_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    user_out_ptr<void> data,
    uint32_t offset,
    uint32_t len,
    user_out_ptr<uint32_t> actual);

zx_status_t sys_ktrace_control(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t action,
    uint32_t options,
    user_inout_ptr<void> ptr);

zx_status_t sys_ktrace_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t id,
    uint32_t arg0,
    uint32_t arg1);

zx_status_t sys_mtrace_control(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t kind,
    uint32_t action,
    uint32_t options,
    user_inout_ptr<void> ptr,
    uint32_t size);

zx_status_t sys_debug_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    user_out_ptr<char> buffer,
    user_inout_ptr<size_t> length);

zx_status_t sys_debug_write(
    user_in_ptr<const char> buffer,
    size_t length);

zx_status_t sys_debug_send_command(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t resource_handle,
    user_in_ptr<const char> buffer,
    size_t length);

zx_status_t sys_interrupt_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t src_obj,
    uint32_t src_num,
    uint32_t options,
    user_out_handle* out_handle);

zx_status_t sys_interrupt_bind(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t inth,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t porth,
    uint64_t key,
    uint32_t options);

zx_status_t sys_interrupt_wait(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    user_out_ptr<zx_time_t> out_timestamp);

zx_status_t sys_interrupt_destroy(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle);

zx_status_t sys_interrupt_ack(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle);

zx_status_t sys_interrupt_trigger(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t options,
    zx_time_t timestamp);

zx_status_t sys_mmap_device_io(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t io_addr,
    uint32_t len);

zx_status_t sys_vmo_create_contiguous(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t bti,
    size_t size,
    uint32_t alignment_log2,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_vmo_create_physical(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t rsrc_handle,
    zx_paddr_t paddr,
    size_t size,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_iommu_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t rsrc_handle,
    uint32_t type,
    user_in_ptr<const void> desc,
    uint32_t desc_len,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_bti_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t iommu,
    uint32_t options,
    uint64_t bti_id,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_bti_pin(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t bti,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmo,
    uint64_t offset,
    uint64_t size,
    user_out_ptr<zx_paddr_t> addrs,
    size_t addrs_count,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_bti_release_quarantine(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t bti);

zx_status_t sys_pmt_unpin(
    ZX_SYSCALL_PARAM_ATTR(handle_release) zx_handle_t pmt);

zx_status_t sys_bootloader_fb_get_info(
    user_out_ptr<uint32_t> format,
    user_out_ptr<uint32_t> width,
    user_out_ptr<uint32_t> height,
    user_out_ptr<uint32_t> stride);

zx_status_t sys_set_framebuffer(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    user_inout_ptr<void> vaddr,
    uint32_t len,
    uint32_t format,
    uint32_t width,
    uint32_t height,
    uint32_t stride);

zx_status_t sys_set_framebuffer_vmo(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vmo,
    uint32_t len,
    uint32_t format,
    uint32_t width,
    uint32_t height,
    uint32_t stride);

zx_status_t sys_pci_get_nth_device(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t index,
    user_out_ptr<zx_pcie_device_info_t> out_info,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out_handle);

zx_status_t sys_pci_enable_bus_master(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    bool enable);

zx_status_t sys_pci_reset_device(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle);

zx_status_t sys_pci_config_read(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint16_t offset,
    size_t width,
    user_out_ptr<uint32_t> out_val);

zx_status_t sys_pci_config_write(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint16_t offset,
    size_t width,
    uint32_t val);

zx_status_t sys_pci_cfg_pio_rw(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint8_t bus,
    uint8_t dev,
    uint8_t func,
    uint8_t offset,
    user_inout_ptr<uint32_t> val,
    size_t width,
    bool write);

zx_status_t sys_pci_get_bar(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t bar_num,
    user_out_ptr<zx_pci_bar_t> out_bar,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out_handle);

zx_status_t sys_pci_map_interrupt(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    int32_t which_irq,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out_handle);

zx_status_t sys_pci_query_irq_mode(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t mode,
    user_out_ptr<uint32_t> out_max_irqs);

zx_status_t sys_pci_set_irq_mode(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    uint32_t mode,
    uint32_t requested_irq_count);

zx_status_t sys_pci_init(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    user_in_ptr<const zx_pci_init_arg_t> init_buf,
    uint32_t len);

zx_status_t sys_pci_add_subtract_io_range(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    bool mmio,
    uint64_t base,
    uint64_t len,
    bool add);

zx_status_t sys_pc_firmware_tables(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t handle,
    user_out_ptr<zx_paddr_t> acpi_rsdp,
    user_out_ptr<zx_paddr_t> smbios);

zx_status_t sys_smc_call(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t rsrc_handle,
    uint64_t arg0,
    uint64_t arg1,
    uint64_t arg2,
    uint64_t arg3,
    user_out_ptr<uint64_t> out_smc_status);

zx_status_t sys_resource_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t parent_handle,
    uint32_t kind,
    uint64_t low,
    uint64_t high,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* resource_out);

zx_status_t sys_guest_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t resource,
    uint32_t options,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t physmem_vmo,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_guest_set_trap(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t guest,
    uint32_t kind,
    zx_vaddr_t addr,
    size_t len,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t port,
    uint64_t key);

zx_status_t sys_vcpu_create(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t guest,
    uint32_t options,
    zx_vaddr_t entry,
    ZX_SYSCALL_PARAM_ATTR(handle_acquire) user_out_handle* out);

zx_status_t sys_vcpu_resume(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vcpu,
    user_out_ptr<zx_port_packet_t> packet);

zx_status_t sys_vcpu_interrupt(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vcpu,
    uint32_t vector);

zx_status_t sys_vcpu_read_state(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vcpu,
    uint32_t kind,
    user_out_ptr<void> buffer,
    uint32_t len);

zx_status_t sys_vcpu_write_state(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t vcpu,
    uint32_t kind,
    user_in_ptr<const void> buffer,
    uint32_t len);

zx_status_t sys_system_mexec(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t kernel,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t bootimage);

zx_status_t sys_system_powerctl(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t root_rsrc,
    uint32_t cmd,
    user_in_ptr<const zx_system_powerctl_arg_t> arg);

zx_status_t sys_job_set_relative_importance(
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t root_resource,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t job,
    ZX_SYSCALL_PARAM_ATTR(handle_use) zx_handle_t less_important_job);

zx_status_t sys_syscall_test_0(
    );

zx_status_t sys_syscall_test_1(
    int a);

zx_status_t sys_syscall_test_2(
    int a,
    int b);

zx_status_t sys_syscall_test_3(
    int a,
    int b,
    int c);

zx_status_t sys_syscall_test_4(
    int a,
    int b,
    int c,
    int d);

zx_status_t sys_syscall_test_5(
    int a,
    int b,
    int c,
    int d,
    int e);

zx_status_t sys_syscall_test_6(
    int a,
    int b,
    int c,
    int d,
    int e,
    int f);

zx_status_t sys_syscall_test_7(
    int a,
    int b,
    int c,
    int d,
    int e,
    int f,
    int g);

zx_status_t sys_syscall_test_8(
    int a,
    int b,
    int c,
    int d,
    int e,
    int f,
    int g,
    int h);

zx_status_t sys_syscall_test_wrapper(
    int a,
    int b,
    int c);


