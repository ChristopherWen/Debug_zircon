// Copyright 2018 The Fuchsia Authors. All rights reserved.
// This is a GENERATED file, see //zircon/system/host/abigen.
// The license governing this file can be found in the LICENSE file.

extern "C" {
syscall_result wrapper_clock_get(uint32_t clock_id, uint64_t pc) {
    return do_syscall(ZX_SYS_clock_get, pc, &VDso::ValidSyscallPC::clock_get, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_clock_get(clock_id);
        return result;
    });
}
syscall_result wrapper_nanosleep(zx_time_t deadline, uint64_t pc) {
    return do_syscall(ZX_SYS_nanosleep, pc, &VDso::ValidSyscallPC::nanosleep, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_nanosleep(deadline);
        return result;
    });
}
syscall_result wrapper_clock_adjust(zx_handle_t handle, uint32_t clock_id, int64_t offset, uint64_t pc) {
    return do_syscall(ZX_SYS_clock_adjust, pc, &VDso::ValidSyscallPC::clock_adjust, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_clock_adjust(handle, clock_id, offset);
        return result;
    });
}
syscall_result wrapper_handle_close(zx_handle_t handle, uint64_t pc) {
    return do_syscall(ZX_SYS_handle_close, pc, &VDso::ValidSyscallPC::handle_close, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_handle_close(handle);
        return result;
    });
}
syscall_result wrapper_handle_duplicate(zx_handle_t handle, zx_rights_t rights, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_handle_duplicate, pc, &VDso::ValidSyscallPC::handle_duplicate, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_handle_duplicate(handle, rights, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_handle_replace(zx_handle_t handle, zx_rights_t rights, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_handle_replace, pc, &VDso::ValidSyscallPC::handle_replace, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_handle_replace(handle, rights, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_object_wait_one(zx_handle_t handle, zx_signals_t waitfor, zx_time_t deadline, zx_signals_t* observed, uint64_t pc) {
    return do_syscall(ZX_SYS_object_wait_one, pc, &VDso::ValidSyscallPC::object_wait_one, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_object_wait_one(handle, waitfor, deadline, make_user_out_ptr(observed));
        return result;
    });
}
syscall_result wrapper_object_wait_many(zx_wait_item_t* items, uint32_t count, zx_time_t deadline, uint64_t pc) {
    return do_syscall(ZX_SYS_object_wait_many, pc, &VDso::ValidSyscallPC::object_wait_many, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_object_wait_many(make_user_inout_ptr(items), count, deadline);
        return result;
    });
}
syscall_result wrapper_object_wait_async(zx_handle_t handle, zx_handle_t port_handle, uint64_t key, zx_signals_t signals, uint32_t options, uint64_t pc) {
    return do_syscall(ZX_SYS_object_wait_async, pc, &VDso::ValidSyscallPC::object_wait_async, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_object_wait_async(handle, port_handle, key, signals, options);
        return result;
    });
}
syscall_result wrapper_object_signal(zx_handle_t handle, uint32_t clear_mask, uint32_t set_mask, uint64_t pc) {
    return do_syscall(ZX_SYS_object_signal, pc, &VDso::ValidSyscallPC::object_signal, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_object_signal(handle, clear_mask, set_mask);
        return result;
    });
}
syscall_result wrapper_object_signal_peer(zx_handle_t handle, uint32_t clear_mask, uint32_t set_mask, uint64_t pc) {
    return do_syscall(ZX_SYS_object_signal_peer, pc, &VDso::ValidSyscallPC::object_signal_peer, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_object_signal_peer(handle, clear_mask, set_mask);
        return result;
    });
}
syscall_result wrapper_object_get_property(zx_handle_t handle, uint32_t property, void* value, size_t size, uint64_t pc) {
    return do_syscall(ZX_SYS_object_get_property, pc, &VDso::ValidSyscallPC::object_get_property, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_object_get_property(handle, property, make_user_out_ptr(value), size);
        return result;
    });
}
syscall_result wrapper_object_set_property(zx_handle_t handle, uint32_t property, const void* value, size_t size, uint64_t pc) {
    return do_syscall(ZX_SYS_object_set_property, pc, &VDso::ValidSyscallPC::object_set_property, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_object_set_property(handle, property, make_user_in_ptr(value), size);
        return result;
    });
}
syscall_result wrapper_object_set_cookie(zx_handle_t handle, zx_handle_t scope, uint64_t cookie, uint64_t pc) {
    return do_syscall(ZX_SYS_object_set_cookie, pc, &VDso::ValidSyscallPC::object_set_cookie, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_object_set_cookie(handle, scope, cookie);
        return result;
    });
}
syscall_result wrapper_object_get_cookie(zx_handle_t handle, zx_handle_t scope, uint64_t* cookie, uint64_t pc) {
    return do_syscall(ZX_SYS_object_get_cookie, pc, &VDso::ValidSyscallPC::object_get_cookie, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_object_get_cookie(handle, scope, make_user_out_ptr(cookie));
        return result;
    });
}
syscall_result wrapper_object_get_info(zx_handle_t handle, uint32_t topic, void* buffer, size_t buffer_size, size_t* actual_count, size_t* avail_count, uint64_t pc) {
    return do_syscall(ZX_SYS_object_get_info, pc, &VDso::ValidSyscallPC::object_get_info, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_object_get_info(handle, topic, make_user_out_ptr(buffer), buffer_size, make_user_out_ptr(actual_count), make_user_out_ptr(avail_count));
        return result;
    });
}
syscall_result wrapper_object_get_child(zx_handle_t handle, uint64_t koid, zx_rights_t rights, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_object_get_child, pc, &VDso::ValidSyscallPC::object_get_child, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_object_get_child(handle, koid, rights, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_object_set_profile(zx_handle_t handle, zx_handle_t profile, uint32_t options, uint64_t pc) {
    return do_syscall(ZX_SYS_object_set_profile, pc, &VDso::ValidSyscallPC::object_set_profile, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_object_set_profile(handle, profile, options);
        return result;
    });
}
syscall_result wrapper_channel_create(uint32_t options, zx_handle_t* out0, zx_handle_t* out1, uint64_t pc) {
    return do_syscall(ZX_SYS_channel_create, pc, &VDso::ValidSyscallPC::channel_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out0;
        user_out_handle out_handle_out1;
        auto result = sys_channel_create(options, &out_handle_out0, &out_handle_out1);
        if (out_handle_out0.begin_copyout(current_process, make_user_out_ptr(out0)))
            return ZX_ERR_INVALID_ARGS;
        if (out_handle_out1.begin_copyout(current_process, make_user_out_ptr(out1)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out0.finish_copyout(current_process);
        out_handle_out1.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_channel_read(zx_handle_t handle, uint32_t options, void* bytes, zx_handle_t* handles, uint32_t num_bytes, uint32_t num_handles, uint32_t* actual_bytes, uint32_t* actual_handles, uint64_t pc) {
    return do_syscall(ZX_SYS_channel_read, pc, &VDso::ValidSyscallPC::channel_read, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_channel_read(handle, options, make_user_out_ptr(bytes), make_user_out_ptr(handles), num_bytes, num_handles, make_user_out_ptr(actual_bytes), make_user_out_ptr(actual_handles));
        return result;
    });
}
syscall_result wrapper_channel_read_etc(zx_handle_t handle, uint32_t options, void* bytes, zx_handle_info_t* handles, uint32_t num_bytes, uint32_t num_handles, uint32_t* actual_bytes, uint32_t* actual_handles, uint64_t pc) {
    return do_syscall(ZX_SYS_channel_read_etc, pc, &VDso::ValidSyscallPC::channel_read_etc, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_channel_read_etc(handle, options, make_user_out_ptr(bytes), make_user_out_ptr(handles), num_bytes, num_handles, make_user_out_ptr(actual_bytes), make_user_out_ptr(actual_handles));
        return result;
    });
}
syscall_result wrapper_channel_write(zx_handle_t handle, uint32_t options, const void* bytes, uint32_t num_bytes, const zx_handle_t* handles, uint32_t num_handles, uint64_t pc) {
    return do_syscall(ZX_SYS_channel_write, pc, &VDso::ValidSyscallPC::channel_write, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_channel_write(handle, options, make_user_in_ptr(bytes), num_bytes, make_user_in_ptr(handles), num_handles);
        return result;
    });
}
syscall_result wrapper_channel_call_noretry(zx_handle_t handle, uint32_t options, zx_time_t deadline, const zx_channel_call_args_t* args, uint32_t* actual_bytes, uint32_t* actual_handles, zx_status_t* read_status, uint64_t pc) {
    return do_syscall(ZX_SYS_channel_call_noretry, pc, &VDso::ValidSyscallPC::channel_call_noretry, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_channel_call_noretry(handle, options, deadline, make_user_in_ptr(args), make_user_out_ptr(actual_bytes), make_user_out_ptr(actual_handles), make_user_out_ptr(read_status));
        return result;
    });
}
syscall_result wrapper_channel_call_finish(zx_time_t deadline, const zx_channel_call_args_t* args, uint32_t* actual_bytes, uint32_t* actual_handles, zx_status_t* read_status, uint64_t pc) {
    return do_syscall(ZX_SYS_channel_call_finish, pc, &VDso::ValidSyscallPC::channel_call_finish, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_channel_call_finish(deadline, make_user_in_ptr(args), make_user_out_ptr(actual_bytes), make_user_out_ptr(actual_handles), make_user_out_ptr(read_status));
        return result;
    });
}
syscall_result wrapper_socket_create(uint32_t options, zx_handle_t* out0, zx_handle_t* out1, uint64_t pc) {
    return do_syscall(ZX_SYS_socket_create, pc, &VDso::ValidSyscallPC::socket_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out0;
        user_out_handle out_handle_out1;
        auto result = sys_socket_create(options, &out_handle_out0, &out_handle_out1);
        if (out_handle_out0.begin_copyout(current_process, make_user_out_ptr(out0)))
            return ZX_ERR_INVALID_ARGS;
        if (out_handle_out1.begin_copyout(current_process, make_user_out_ptr(out1)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out0.finish_copyout(current_process);
        out_handle_out1.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_socket_write(zx_handle_t handle, uint32_t options, const void* buffer, size_t size, size_t* actual, uint64_t pc) {
    return do_syscall(ZX_SYS_socket_write, pc, &VDso::ValidSyscallPC::socket_write, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_socket_write(handle, options, make_user_in_ptr(buffer), size, make_user_out_ptr(actual));
        return result;
    });
}
syscall_result wrapper_socket_read(zx_handle_t handle, uint32_t options, void* buffer, size_t size, size_t* actual, uint64_t pc) {
    return do_syscall(ZX_SYS_socket_read, pc, &VDso::ValidSyscallPC::socket_read, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_socket_read(handle, options, make_user_out_ptr(buffer), size, make_user_out_ptr(actual));
        return result;
    });
}
syscall_result wrapper_socket_share(zx_handle_t handle, zx_handle_t socket_to_share, uint64_t pc) {
    return do_syscall(ZX_SYS_socket_share, pc, &VDso::ValidSyscallPC::socket_share, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_socket_share(handle, socket_to_share);
        return result;
    });
}
syscall_result wrapper_socket_accept(zx_handle_t handle, zx_handle_t* out_socket, uint64_t pc) {
    return do_syscall(ZX_SYS_socket_accept, pc, &VDso::ValidSyscallPC::socket_accept, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out_socket;
        auto result = sys_socket_accept(handle, &out_handle_out_socket);
        if (out_handle_out_socket.begin_copyout(current_process, make_user_out_ptr(out_socket)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out_socket.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_thread_exit(uint64_t pc) {
    return do_syscall(ZX_SYS_thread_exit, pc, &VDso::ValidSyscallPC::thread_exit, [&](ProcessDispatcher* current_process) -> uint64_t {
        /*noreturn*/ sys_thread_exit();
        /* NOTREACHED */
        return ZX_ERR_BAD_STATE;
    });
}
syscall_result wrapper_thread_create(zx_handle_t process, const char* name, uint32_t name_len, uint32_t options, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_thread_create, pc, &VDso::ValidSyscallPC::thread_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_thread_create(process, make_user_in_ptr(name), name_len, options, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_thread_start(zx_handle_t handle, uintptr_t thread_entry, uintptr_t stack, uintptr_t arg1, uintptr_t arg2, uint64_t pc) {
    return do_syscall(ZX_SYS_thread_start, pc, &VDso::ValidSyscallPC::thread_start, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_thread_start(handle, thread_entry, stack, arg1, arg2);
        return result;
    });
}
syscall_result wrapper_thread_read_state(zx_handle_t handle, uint32_t kind, void* buffer, size_t len, uint64_t pc) {
    return do_syscall(ZX_SYS_thread_read_state, pc, &VDso::ValidSyscallPC::thread_read_state, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_thread_read_state(handle, kind, make_user_out_ptr(buffer), len);
        return result;
    });
}
syscall_result wrapper_thread_write_state(zx_handle_t handle, uint32_t kind, const void* buffer, size_t buffer_len, uint64_t pc) {
    return do_syscall(ZX_SYS_thread_write_state, pc, &VDso::ValidSyscallPC::thread_write_state, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_thread_write_state(handle, kind, make_user_in_ptr(buffer), buffer_len);
        return result;
    });
}
syscall_result wrapper_thread_set_priority(int32_t prio, uint64_t pc) {
    return do_syscall(ZX_SYS_thread_set_priority, pc, &VDso::ValidSyscallPC::thread_set_priority, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_thread_set_priority(prio);
        return result;
    });
}
syscall_result wrapper_process_exit(int retcode, uint64_t pc) {
    return do_syscall(ZX_SYS_process_exit, pc, &VDso::ValidSyscallPC::process_exit, [&](ProcessDispatcher* current_process) -> uint64_t {
        /*noreturn*/ sys_process_exit(retcode);
        /* NOTREACHED */
        return ZX_ERR_BAD_STATE;
    });
}
syscall_result wrapper_process_create(zx_handle_t job, const char* name, uint32_t name_len, uint32_t options, zx_handle_t* proc_handle, zx_handle_t* vmar_handle, uint64_t pc) {
    return do_syscall(ZX_SYS_process_create, pc, &VDso::ValidSyscallPC::process_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_proc_handle;
        user_out_handle out_handle_vmar_handle;
        auto result = sys_process_create(job, make_user_in_ptr(name), name_len, options, &out_handle_proc_handle, &out_handle_vmar_handle);
        if (out_handle_proc_handle.begin_copyout(current_process, make_user_out_ptr(proc_handle)))
            return ZX_ERR_INVALID_ARGS;
        if (out_handle_vmar_handle.begin_copyout(current_process, make_user_out_ptr(vmar_handle)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_proc_handle.finish_copyout(current_process);
        out_handle_vmar_handle.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_process_start(zx_handle_t process_handle, zx_handle_t thread_handle, uintptr_t entry, uintptr_t stack, zx_handle_t arg_handle, uintptr_t arg2, uint64_t pc) {
    return do_syscall(ZX_SYS_process_start, pc, &VDso::ValidSyscallPC::process_start, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_process_start(process_handle, thread_handle, entry, stack, arg_handle, arg2);
        return result;
    });
}
syscall_result wrapper_process_read_memory(zx_handle_t proc, uintptr_t vaddr, void* buffer, size_t len, size_t* actual, uint64_t pc) {
    return do_syscall(ZX_SYS_process_read_memory, pc, &VDso::ValidSyscallPC::process_read_memory, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_process_read_memory(proc, vaddr, make_user_out_ptr(buffer), len, make_user_out_ptr(actual));
        return result;
    });
}
syscall_result wrapper_process_write_memory(zx_handle_t proc, uintptr_t vaddr, const void* buffer, size_t len, size_t* actual, uint64_t pc) {
    return do_syscall(ZX_SYS_process_write_memory, pc, &VDso::ValidSyscallPC::process_write_memory, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_process_write_memory(proc, vaddr, make_user_in_ptr(buffer), len, make_user_out_ptr(actual));
        return result;
    });
}
syscall_result wrapper_job_create(zx_handle_t parent_job, uint32_t options, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_job_create, pc, &VDso::ValidSyscallPC::job_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_job_create(parent_job, options, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_job_set_policy(zx_handle_t job, uint32_t options, uint32_t topic, const void* policy, uint32_t count, uint64_t pc) {
    return do_syscall(ZX_SYS_job_set_policy, pc, &VDso::ValidSyscallPC::job_set_policy, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_job_set_policy(job, options, topic, make_user_in_ptr(policy), count);
        return result;
    });
}
syscall_result wrapper_task_bind_exception_port(zx_handle_t object, zx_handle_t eport, uint64_t key, uint32_t options, uint64_t pc) {
    return do_syscall(ZX_SYS_task_bind_exception_port, pc, &VDso::ValidSyscallPC::task_bind_exception_port, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_task_bind_exception_port(object, eport, key, options);
        return result;
    });
}
syscall_result wrapper_task_suspend(zx_handle_t task_handle, uint64_t pc) {
    return do_syscall(ZX_SYS_task_suspend, pc, &VDso::ValidSyscallPC::task_suspend, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_task_suspend(task_handle);
        return result;
    });
}
syscall_result wrapper_task_resume(zx_handle_t task_handle, uint32_t options, uint64_t pc) {
    return do_syscall(ZX_SYS_task_resume, pc, &VDso::ValidSyscallPC::task_resume, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_task_resume(task_handle, options);
        return result;
    });
}
syscall_result wrapper_task_suspend_token(zx_handle_t task_handle, zx_handle_t* token, uint64_t pc) {
    return do_syscall(ZX_SYS_task_suspend_token, pc, &VDso::ValidSyscallPC::task_suspend_token, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_token;
        auto result = sys_task_suspend_token(task_handle, &out_handle_token);
        if (out_handle_token.begin_copyout(current_process, make_user_out_ptr(token)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_token.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_task_resume_from_exception(zx_handle_t task_handle, zx_handle_t eport, uint32_t options, uint64_t pc) {
    return do_syscall(ZX_SYS_task_resume_from_exception, pc, &VDso::ValidSyscallPC::task_resume_from_exception, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_task_resume_from_exception(task_handle, eport, options);
        return result;
    });
}
syscall_result wrapper_task_kill(zx_handle_t task_handle, uint64_t pc) {
    return do_syscall(ZX_SYS_task_kill, pc, &VDso::ValidSyscallPC::task_kill, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_task_kill(task_handle);
        return result;
    });
}
syscall_result wrapper_event_create(uint32_t options, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_event_create, pc, &VDso::ValidSyscallPC::event_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_event_create(options, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_eventpair_create(uint32_t options, zx_handle_t* out0, zx_handle_t* out1, uint64_t pc) {
    return do_syscall(ZX_SYS_eventpair_create, pc, &VDso::ValidSyscallPC::eventpair_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out0;
        user_out_handle out_handle_out1;
        auto result = sys_eventpair_create(options, &out_handle_out0, &out_handle_out1);
        if (out_handle_out0.begin_copyout(current_process, make_user_out_ptr(out0)))
            return ZX_ERR_INVALID_ARGS;
        if (out_handle_out1.begin_copyout(current_process, make_user_out_ptr(out1)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out0.finish_copyout(current_process);
        out_handle_out1.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_futex_wait(const zx_futex_t* value_ptr, int current_value, zx_time_t deadline, uint64_t pc) {
    return do_syscall(ZX_SYS_futex_wait, pc, &VDso::ValidSyscallPC::futex_wait, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_futex_wait(make_user_in_ptr(value_ptr), current_value, deadline);
        return result;
    });
}
syscall_result wrapper_futex_wake(const zx_futex_t* value_ptr, uint32_t count, uint64_t pc) {
    return do_syscall(ZX_SYS_futex_wake, pc, &VDso::ValidSyscallPC::futex_wake, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_futex_wake(make_user_in_ptr(value_ptr), count);
        return result;
    });
}
syscall_result wrapper_futex_requeue(const zx_futex_t* wake_ptr, uint32_t wake_count, int current_value, const zx_futex_t* requeue_ptr, uint32_t requeue_count, uint64_t pc) {
    return do_syscall(ZX_SYS_futex_requeue, pc, &VDso::ValidSyscallPC::futex_requeue, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_futex_requeue(make_user_in_ptr(wake_ptr), wake_count, current_value, make_user_in_ptr(requeue_ptr), requeue_count);
        return result;
    });
}
syscall_result wrapper_port_create(uint32_t options, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_port_create, pc, &VDso::ValidSyscallPC::port_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_port_create(options, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_port_queue(zx_handle_t handle, const zx_port_packet_t* packet, size_t count, uint64_t pc) {
    return do_syscall(ZX_SYS_port_queue, pc, &VDso::ValidSyscallPC::port_queue, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_port_queue(handle, make_user_in_ptr(packet), count);
        return result;
    });
}
syscall_result wrapper_port_wait(zx_handle_t handle, zx_time_t deadline, zx_port_packet_t* packet, size_t count, uint64_t pc) {
    return do_syscall(ZX_SYS_port_wait, pc, &VDso::ValidSyscallPC::port_wait, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_port_wait(handle, deadline, make_user_out_ptr(packet), count);
        return result;
    });
}
syscall_result wrapper_port_cancel(zx_handle_t handle, zx_handle_t source, uint64_t key, uint64_t pc) {
    return do_syscall(ZX_SYS_port_cancel, pc, &VDso::ValidSyscallPC::port_cancel, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_port_cancel(handle, source, key);
        return result;
    });
}
syscall_result wrapper_timer_create(uint32_t options, uint32_t clock_id, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_timer_create, pc, &VDso::ValidSyscallPC::timer_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_timer_create(options, clock_id, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_timer_set(zx_handle_t handle, zx_time_t deadline, zx_duration_t slack, uint64_t pc) {
    return do_syscall(ZX_SYS_timer_set, pc, &VDso::ValidSyscallPC::timer_set, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_timer_set(handle, deadline, slack);
        return result;
    });
}
syscall_result wrapper_timer_cancel(zx_handle_t handle, uint64_t pc) {
    return do_syscall(ZX_SYS_timer_cancel, pc, &VDso::ValidSyscallPC::timer_cancel, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_timer_cancel(handle);
        return result;
    });
}
syscall_result wrapper_vmo_create(uint64_t size, uint32_t options, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_vmo_create, pc, &VDso::ValidSyscallPC::vmo_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_vmo_create(size, options, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_vmo_read(zx_handle_t handle, void* data, uint64_t offset, size_t len, uint64_t pc) {
    return do_syscall(ZX_SYS_vmo_read, pc, &VDso::ValidSyscallPC::vmo_read, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_vmo_read(handle, make_user_out_ptr(data), offset, len);
        return result;
    });
}
syscall_result wrapper_vmo_write(zx_handle_t handle, const void* data, uint64_t offset, size_t len, uint64_t pc) {
    return do_syscall(ZX_SYS_vmo_write, pc, &VDso::ValidSyscallPC::vmo_write, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_vmo_write(handle, make_user_in_ptr(data), offset, len);
        return result;
    });
}
syscall_result wrapper_vmo_get_size(zx_handle_t handle, uint64_t* size, uint64_t pc) {
    return do_syscall(ZX_SYS_vmo_get_size, pc, &VDso::ValidSyscallPC::vmo_get_size, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_vmo_get_size(handle, make_user_out_ptr(size));
        return result;
    });
}
syscall_result wrapper_vmo_set_size(zx_handle_t handle, uint64_t size, uint64_t pc) {
    return do_syscall(ZX_SYS_vmo_set_size, pc, &VDso::ValidSyscallPC::vmo_set_size, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_vmo_set_size(handle, size);
        return result;
    });
}
syscall_result wrapper_vmo_op_range(zx_handle_t handle, uint32_t op, uint64_t offset, uint64_t size, void* buffer, size_t buffer_size, uint64_t pc) {
    return do_syscall(ZX_SYS_vmo_op_range, pc, &VDso::ValidSyscallPC::vmo_op_range, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_vmo_op_range(handle, op, offset, size, make_user_inout_ptr(buffer), buffer_size);
        return result;
    });
}
syscall_result wrapper_vmo_clone(zx_handle_t handle, uint32_t options, uint64_t offset, uint64_t size, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_vmo_clone, pc, &VDso::ValidSyscallPC::vmo_clone, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_vmo_clone(handle, options, offset, size, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_vmo_set_cache_policy(zx_handle_t handle, uint32_t cache_policy, uint64_t pc) {
    return do_syscall(ZX_SYS_vmo_set_cache_policy, pc, &VDso::ValidSyscallPC::vmo_set_cache_policy, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_vmo_set_cache_policy(handle, cache_policy);
        return result;
    });
}
syscall_result wrapper_vmar_allocate(zx_handle_t parent_vmar_handle, size_t offset, size_t size, uint32_t map_flags, zx_handle_t* child_vmar, uintptr_t* child_addr, uint64_t pc) {
    return do_syscall(ZX_SYS_vmar_allocate, pc, &VDso::ValidSyscallPC::vmar_allocate, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_child_vmar;
        auto result = sys_vmar_allocate(parent_vmar_handle, offset, size, map_flags, &out_handle_child_vmar, make_user_out_ptr(child_addr));
        if (out_handle_child_vmar.begin_copyout(current_process, make_user_out_ptr(child_vmar)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_child_vmar.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_vmar_destroy(zx_handle_t vmar_handle, uint64_t pc) {
    return do_syscall(ZX_SYS_vmar_destroy, pc, &VDso::ValidSyscallPC::vmar_destroy, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_vmar_destroy(vmar_handle);
        return result;
    });
}
syscall_result wrapper_vmar_map(zx_handle_t vmar_handle, size_t vmar_offset, zx_handle_t vmo_handle, uint64_t vmo_offset, size_t len, uint32_t map_flags, uintptr_t* mapped_addr, uint64_t pc) {
    return do_syscall(ZX_SYS_vmar_map, pc, &VDso::ValidSyscallPC::vmar_map, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_vmar_map(vmar_handle, vmar_offset, vmo_handle, vmo_offset, len, map_flags, make_user_out_ptr(mapped_addr));
        return result;
    });
}
syscall_result wrapper_vmar_unmap(zx_handle_t vmar_handle, uintptr_t addr, size_t len, uint64_t pc) {
    return do_syscall(ZX_SYS_vmar_unmap, pc, &VDso::ValidSyscallPC::vmar_unmap, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_vmar_unmap(vmar_handle, addr, len);
        return result;
    });
}
syscall_result wrapper_vmar_protect(zx_handle_t vmar_handle, uintptr_t addr, size_t len, uint32_t prot_flags, uint64_t pc) {
    return do_syscall(ZX_SYS_vmar_protect, pc, &VDso::ValidSyscallPC::vmar_protect, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_vmar_protect(vmar_handle, addr, len, prot_flags);
        return result;
    });
}
syscall_result wrapper_cprng_draw(void* buffer, size_t len, size_t* actual, uint64_t pc) {
    return do_syscall(ZX_SYS_cprng_draw, pc, &VDso::ValidSyscallPC::cprng_draw, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_cprng_draw(make_user_out_ptr(buffer), len, make_user_out_ptr(actual));
        return result;
    });
}
syscall_result wrapper_cprng_add_entropy(const void* buffer, size_t len, uint64_t pc) {
    return do_syscall(ZX_SYS_cprng_add_entropy, pc, &VDso::ValidSyscallPC::cprng_add_entropy, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_cprng_add_entropy(make_user_in_ptr(buffer), len);
        return result;
    });
}
syscall_result wrapper_fifo_create(uint32_t elem_count, uint32_t elem_size, uint32_t options, zx_handle_t* out0, zx_handle_t* out1, uint64_t pc) {
    return do_syscall(ZX_SYS_fifo_create, pc, &VDso::ValidSyscallPC::fifo_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out0;
        user_out_handle out_handle_out1;
        auto result = sys_fifo_create(elem_count, elem_size, options, &out_handle_out0, &out_handle_out1);
        if (out_handle_out0.begin_copyout(current_process, make_user_out_ptr(out0)))
            return ZX_ERR_INVALID_ARGS;
        if (out_handle_out1.begin_copyout(current_process, make_user_out_ptr(out1)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out0.finish_copyout(current_process);
        out_handle_out1.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_fifo_read(zx_handle_t handle, void* data, size_t len, uint32_t* num_written, uint64_t pc) {
    return do_syscall(ZX_SYS_fifo_read, pc, &VDso::ValidSyscallPC::fifo_read, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_fifo_read(handle, make_user_out_ptr(data), len, make_user_out_ptr(num_written));
        return result;
    });
}
syscall_result wrapper_fifo_read_old(zx_handle_t handle, void* data, size_t len, uint32_t* num_written, uint64_t pc) {
    return do_syscall(ZX_SYS_fifo_read_old, pc, &VDso::ValidSyscallPC::fifo_read_old, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_fifo_read_old(handle, make_user_out_ptr(data), len, make_user_out_ptr(num_written));
        return result;
    });
}
syscall_result wrapper_fifo_write(zx_handle_t handle, const void* data, size_t len, uint32_t* num_written, uint64_t pc) {
    return do_syscall(ZX_SYS_fifo_write, pc, &VDso::ValidSyscallPC::fifo_write, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_fifo_write(handle, make_user_in_ptr(data), len, make_user_out_ptr(num_written));
        return result;
    });
}
syscall_result wrapper_fifo_write_old(zx_handle_t handle, const void* data, size_t len, uint32_t* num_written, uint64_t pc) {
    return do_syscall(ZX_SYS_fifo_write_old, pc, &VDso::ValidSyscallPC::fifo_write_old, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_fifo_write_old(handle, make_user_in_ptr(data), len, make_user_out_ptr(num_written));
        return result;
    });
}
syscall_result wrapper_profile_create(zx_handle_t resource, const zx_profile_info_t* profile, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_profile_create, pc, &VDso::ValidSyscallPC::profile_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_profile_create(resource, make_user_in_ptr(profile), &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_log_create(uint32_t options, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_log_create, pc, &VDso::ValidSyscallPC::log_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_log_create(options, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_log_write(zx_handle_t handle, uint32_t len, const void* buffer, uint32_t options, uint64_t pc) {
    return do_syscall(ZX_SYS_log_write, pc, &VDso::ValidSyscallPC::log_write, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_log_write(handle, len, make_user_in_ptr(buffer), options);
        return result;
    });
}
syscall_result wrapper_log_read(zx_handle_t handle, uint32_t len, void* buffer, uint32_t options, uint64_t pc) {
    return do_syscall(ZX_SYS_log_read, pc, &VDso::ValidSyscallPC::log_read, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_log_read(handle, len, make_user_out_ptr(buffer), options);
        return result;
    });
}
syscall_result wrapper_debuglog_create(zx_handle_t resource, uint32_t options, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_debuglog_create, pc, &VDso::ValidSyscallPC::debuglog_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_debuglog_create(resource, options, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_debuglog_write(zx_handle_t handle, uint32_t options, const void* buffer, size_t len, uint64_t pc) {
    return do_syscall(ZX_SYS_debuglog_write, pc, &VDso::ValidSyscallPC::debuglog_write, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_debuglog_write(handle, options, make_user_in_ptr(buffer), len);
        return result;
    });
}
syscall_result wrapper_debuglog_read(zx_handle_t handle, uint32_t options, void* buffer, size_t len, uint64_t pc) {
    return do_syscall(ZX_SYS_debuglog_read, pc, &VDso::ValidSyscallPC::debuglog_read, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_debuglog_read(handle, options, make_user_out_ptr(buffer), len);
        return result;
    });
}
syscall_result wrapper_ktrace_read(zx_handle_t handle, void* data, uint32_t offset, uint32_t len, uint32_t* actual, uint64_t pc) {
    return do_syscall(ZX_SYS_ktrace_read, pc, &VDso::ValidSyscallPC::ktrace_read, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_ktrace_read(handle, make_user_out_ptr(data), offset, len, make_user_out_ptr(actual));
        return result;
    });
}
syscall_result wrapper_ktrace_control(zx_handle_t handle, uint32_t action, uint32_t options, void* ptr, uint64_t pc) {
    return do_syscall(ZX_SYS_ktrace_control, pc, &VDso::ValidSyscallPC::ktrace_control, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_ktrace_control(handle, action, options, make_user_inout_ptr(ptr));
        return result;
    });
}
syscall_result wrapper_ktrace_write(zx_handle_t handle, uint32_t id, uint32_t arg0, uint32_t arg1, uint64_t pc) {
    return do_syscall(ZX_SYS_ktrace_write, pc, &VDso::ValidSyscallPC::ktrace_write, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_ktrace_write(handle, id, arg0, arg1);
        return result;
    });
}
syscall_result wrapper_mtrace_control(zx_handle_t handle, uint32_t kind, uint32_t action, uint32_t options, void* ptr, uint32_t size, uint64_t pc) {
    return do_syscall(ZX_SYS_mtrace_control, pc, &VDso::ValidSyscallPC::mtrace_control, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_mtrace_control(handle, kind, action, options, make_user_inout_ptr(ptr), size);
        return result;
    });
}
syscall_result wrapper_debug_read(zx_handle_t handle, char* buffer, size_t* length, uint64_t pc) {
    return do_syscall(ZX_SYS_debug_read, pc, &VDso::ValidSyscallPC::debug_read, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_debug_read(handle, make_user_out_ptr(buffer), make_user_inout_ptr(length));
        return result;
    });
}
syscall_result wrapper_debug_write(const char* buffer, size_t length, uint64_t pc) {
    return do_syscall(ZX_SYS_debug_write, pc, &VDso::ValidSyscallPC::debug_write, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_debug_write(make_user_in_ptr(buffer), length);
        return result;
    });
}
syscall_result wrapper_debug_send_command(zx_handle_t resource_handle, const char* buffer, size_t length, uint64_t pc) {
    return do_syscall(ZX_SYS_debug_send_command, pc, &VDso::ValidSyscallPC::debug_send_command, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_debug_send_command(resource_handle, make_user_in_ptr(buffer), length);
        return result;
    });
}
syscall_result wrapper_interrupt_create(zx_handle_t src_obj, uint32_t src_num, uint32_t options, zx_handle_t* out_handle, uint64_t pc) {
    return do_syscall(ZX_SYS_interrupt_create, pc, &VDso::ValidSyscallPC::interrupt_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out_handle;
        auto result = sys_interrupt_create(src_obj, src_num, options, &out_handle_out_handle);
        if (out_handle_out_handle.begin_copyout(current_process, make_user_out_ptr(out_handle)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out_handle.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_interrupt_bind(zx_handle_t inth, zx_handle_t porth, uint64_t key, uint32_t options, uint64_t pc) {
    return do_syscall(ZX_SYS_interrupt_bind, pc, &VDso::ValidSyscallPC::interrupt_bind, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_interrupt_bind(inth, porth, key, options);
        return result;
    });
}
syscall_result wrapper_interrupt_wait(zx_handle_t handle, zx_time_t* out_timestamp, uint64_t pc) {
    return do_syscall(ZX_SYS_interrupt_wait, pc, &VDso::ValidSyscallPC::interrupt_wait, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_interrupt_wait(handle, make_user_out_ptr(out_timestamp));
        return result;
    });
}
syscall_result wrapper_interrupt_destroy(zx_handle_t handle, uint64_t pc) {
    return do_syscall(ZX_SYS_interrupt_destroy, pc, &VDso::ValidSyscallPC::interrupt_destroy, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_interrupt_destroy(handle);
        return result;
    });
}
syscall_result wrapper_interrupt_ack(zx_handle_t handle, uint64_t pc) {
    return do_syscall(ZX_SYS_interrupt_ack, pc, &VDso::ValidSyscallPC::interrupt_ack, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_interrupt_ack(handle);
        return result;
    });
}
syscall_result wrapper_interrupt_trigger(zx_handle_t handle, uint32_t options, zx_time_t timestamp, uint64_t pc) {
    return do_syscall(ZX_SYS_interrupt_trigger, pc, &VDso::ValidSyscallPC::interrupt_trigger, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_interrupt_trigger(handle, options, timestamp);
        return result;
    });
}
syscall_result wrapper_mmap_device_io(zx_handle_t handle, uint32_t io_addr, uint32_t len, uint64_t pc) {
    return do_syscall(ZX_SYS_mmap_device_io, pc, &VDso::ValidSyscallPC::mmap_device_io, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_mmap_device_io(handle, io_addr, len);
        return result;
    });
}
syscall_result wrapper_vmo_create_contiguous(zx_handle_t bti, size_t size, uint32_t alignment_log2, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_vmo_create_contiguous, pc, &VDso::ValidSyscallPC::vmo_create_contiguous, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_vmo_create_contiguous(bti, size, alignment_log2, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_vmo_create_physical(zx_handle_t rsrc_handle, zx_paddr_t paddr, size_t size, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_vmo_create_physical, pc, &VDso::ValidSyscallPC::vmo_create_physical, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_vmo_create_physical(rsrc_handle, paddr, size, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_iommu_create(zx_handle_t rsrc_handle, uint32_t type, const void* desc, uint32_t desc_len, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_iommu_create, pc, &VDso::ValidSyscallPC::iommu_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_iommu_create(rsrc_handle, type, make_user_in_ptr(desc), desc_len, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_bti_create(zx_handle_t iommu, uint32_t options, uint64_t bti_id, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_bti_create, pc, &VDso::ValidSyscallPC::bti_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_bti_create(iommu, options, bti_id, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_bti_pin(zx_handle_t bti, uint32_t options, zx_handle_t vmo, uint64_t offset, uint64_t size, zx_paddr_t* addrs, size_t addrs_count, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_bti_pin, pc, &VDso::ValidSyscallPC::bti_pin, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_bti_pin(bti, options, vmo, offset, size, make_user_out_ptr(addrs), addrs_count, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_bti_release_quarantine(zx_handle_t bti, uint64_t pc) {
    return do_syscall(ZX_SYS_bti_release_quarantine, pc, &VDso::ValidSyscallPC::bti_release_quarantine, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_bti_release_quarantine(bti);
        return result;
    });
}
syscall_result wrapper_pmt_unpin(zx_handle_t pmt, uint64_t pc) {
    return do_syscall(ZX_SYS_pmt_unpin, pc, &VDso::ValidSyscallPC::pmt_unpin, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_pmt_unpin(pmt);
        return result;
    });
}
syscall_result wrapper_bootloader_fb_get_info(uint32_t* format, uint32_t* width, uint32_t* height, uint32_t* stride, uint64_t pc) {
    return do_syscall(ZX_SYS_bootloader_fb_get_info, pc, &VDso::ValidSyscallPC::bootloader_fb_get_info, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_bootloader_fb_get_info(make_user_out_ptr(format), make_user_out_ptr(width), make_user_out_ptr(height), make_user_out_ptr(stride));
        return result;
    });
}
syscall_result wrapper_set_framebuffer(zx_handle_t handle, void* vaddr, uint32_t len, uint32_t format, uint32_t width, uint32_t height, uint32_t stride, uint64_t pc) {
    return do_syscall(ZX_SYS_set_framebuffer, pc, &VDso::ValidSyscallPC::set_framebuffer, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_set_framebuffer(handle, make_user_inout_ptr(vaddr), len, format, width, height, stride);
        return result;
    });
}
syscall_result wrapper_set_framebuffer_vmo(zx_handle_t handle, zx_handle_t vmo, uint32_t len, uint32_t format, uint32_t width, uint32_t height, uint32_t stride, uint64_t pc) {
    return do_syscall(ZX_SYS_set_framebuffer_vmo, pc, &VDso::ValidSyscallPC::set_framebuffer_vmo, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_set_framebuffer_vmo(handle, vmo, len, format, width, height, stride);
        return result;
    });
}
syscall_result wrapper_pci_get_nth_device(zx_handle_t handle, uint32_t index, zx_pcie_device_info_t* out_info, zx_handle_t* out_handle, uint64_t pc) {
    return do_syscall(ZX_SYS_pci_get_nth_device, pc, &VDso::ValidSyscallPC::pci_get_nth_device, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out_handle;
        auto result = sys_pci_get_nth_device(handle, index, make_user_out_ptr(out_info), &out_handle_out_handle);
        if (out_handle_out_handle.begin_copyout(current_process, make_user_out_ptr(out_handle)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out_handle.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_pci_enable_bus_master(zx_handle_t handle, bool enable, uint64_t pc) {
    return do_syscall(ZX_SYS_pci_enable_bus_master, pc, &VDso::ValidSyscallPC::pci_enable_bus_master, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_pci_enable_bus_master(handle, enable);
        return result;
    });
}
syscall_result wrapper_pci_reset_device(zx_handle_t handle, uint64_t pc) {
    return do_syscall(ZX_SYS_pci_reset_device, pc, &VDso::ValidSyscallPC::pci_reset_device, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_pci_reset_device(handle);
        return result;
    });
}
syscall_result wrapper_pci_config_read(zx_handle_t handle, uint16_t offset, size_t width, uint32_t* out_val, uint64_t pc) {
    return do_syscall(ZX_SYS_pci_config_read, pc, &VDso::ValidSyscallPC::pci_config_read, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_pci_config_read(handle, offset, width, make_user_out_ptr(out_val));
        return result;
    });
}
syscall_result wrapper_pci_config_write(zx_handle_t handle, uint16_t offset, size_t width, uint32_t val, uint64_t pc) {
    return do_syscall(ZX_SYS_pci_config_write, pc, &VDso::ValidSyscallPC::pci_config_write, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_pci_config_write(handle, offset, width, val);
        return result;
    });
}
syscall_result wrapper_pci_cfg_pio_rw(zx_handle_t handle, uint8_t bus, uint8_t dev, uint8_t func, uint8_t offset, uint32_t* val, size_t width, bool write, uint64_t pc) {
    return do_syscall(ZX_SYS_pci_cfg_pio_rw, pc, &VDso::ValidSyscallPC::pci_cfg_pio_rw, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_pci_cfg_pio_rw(handle, bus, dev, func, offset, make_user_inout_ptr(val), width, write);
        return result;
    });
}
syscall_result wrapper_pci_get_bar(zx_handle_t handle, uint32_t bar_num, zx_pci_bar_t* out_bar, zx_handle_t* out_handle, uint64_t pc) {
    return do_syscall(ZX_SYS_pci_get_bar, pc, &VDso::ValidSyscallPC::pci_get_bar, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out_handle;
        auto result = sys_pci_get_bar(handle, bar_num, make_user_out_ptr(out_bar), &out_handle_out_handle);
        if (out_handle_out_handle.begin_copyout(current_process, make_user_out_ptr(out_handle)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out_handle.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_pci_map_interrupt(zx_handle_t handle, int32_t which_irq, zx_handle_t* out_handle, uint64_t pc) {
    return do_syscall(ZX_SYS_pci_map_interrupt, pc, &VDso::ValidSyscallPC::pci_map_interrupt, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out_handle;
        auto result = sys_pci_map_interrupt(handle, which_irq, &out_handle_out_handle);
        if (out_handle_out_handle.begin_copyout(current_process, make_user_out_ptr(out_handle)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out_handle.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_pci_query_irq_mode(zx_handle_t handle, uint32_t mode, uint32_t* out_max_irqs, uint64_t pc) {
    return do_syscall(ZX_SYS_pci_query_irq_mode, pc, &VDso::ValidSyscallPC::pci_query_irq_mode, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_pci_query_irq_mode(handle, mode, make_user_out_ptr(out_max_irqs));
        return result;
    });
}
syscall_result wrapper_pci_set_irq_mode(zx_handle_t handle, uint32_t mode, uint32_t requested_irq_count, uint64_t pc) {
    return do_syscall(ZX_SYS_pci_set_irq_mode, pc, &VDso::ValidSyscallPC::pci_set_irq_mode, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_pci_set_irq_mode(handle, mode, requested_irq_count);
        return result;
    });
}
syscall_result wrapper_pci_init(zx_handle_t handle, const zx_pci_init_arg_t* init_buf, uint32_t len, uint64_t pc) {
    return do_syscall(ZX_SYS_pci_init, pc, &VDso::ValidSyscallPC::pci_init, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_pci_init(handle, make_user_in_ptr(init_buf), len);
        return result;
    });
}
syscall_result wrapper_pci_add_subtract_io_range(zx_handle_t handle, bool mmio, uint64_t base, uint64_t len, bool add, uint64_t pc) {
    return do_syscall(ZX_SYS_pci_add_subtract_io_range, pc, &VDso::ValidSyscallPC::pci_add_subtract_io_range, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_pci_add_subtract_io_range(handle, mmio, base, len, add);
        return result;
    });
}
syscall_result wrapper_pc_firmware_tables(zx_handle_t handle, zx_paddr_t* acpi_rsdp, zx_paddr_t* smbios, uint64_t pc) {
    return do_syscall(ZX_SYS_pc_firmware_tables, pc, &VDso::ValidSyscallPC::pc_firmware_tables, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_pc_firmware_tables(handle, make_user_out_ptr(acpi_rsdp), make_user_out_ptr(smbios));
        return result;
    });
}
syscall_result wrapper_smc_call(zx_handle_t rsrc_handle, uint64_t arg0, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t* out_smc_status, uint64_t pc) {
    return do_syscall(ZX_SYS_smc_call, pc, &VDso::ValidSyscallPC::smc_call, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_smc_call(rsrc_handle, arg0, arg1, arg2, arg3, make_user_out_ptr(out_smc_status));
        return result;
    });
}
syscall_result wrapper_resource_create(zx_handle_t parent_handle, uint32_t kind, uint64_t low, uint64_t high, zx_handle_t* resource_out, uint64_t pc) {
    return do_syscall(ZX_SYS_resource_create, pc, &VDso::ValidSyscallPC::resource_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_resource_out;
        auto result = sys_resource_create(parent_handle, kind, low, high, &out_handle_resource_out);
        if (out_handle_resource_out.begin_copyout(current_process, make_user_out_ptr(resource_out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_resource_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_guest_create(zx_handle_t resource, uint32_t options, zx_handle_t physmem_vmo, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_guest_create, pc, &VDso::ValidSyscallPC::guest_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_guest_create(resource, options, physmem_vmo, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_guest_set_trap(zx_handle_t guest, uint32_t kind, zx_vaddr_t addr, size_t len, zx_handle_t port, uint64_t key, uint64_t pc) {
    return do_syscall(ZX_SYS_guest_set_trap, pc, &VDso::ValidSyscallPC::guest_set_trap, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_guest_set_trap(guest, kind, addr, len, port, key);
        return result;
    });
}
syscall_result wrapper_vcpu_create(zx_handle_t guest, uint32_t options, zx_vaddr_t entry, zx_handle_t* out, uint64_t pc) {
    return do_syscall(ZX_SYS_vcpu_create, pc, &VDso::ValidSyscallPC::vcpu_create, [&](ProcessDispatcher* current_process) -> uint64_t {
        user_out_handle out_handle_out;
        auto result = sys_vcpu_create(guest, options, entry, &out_handle_out);
        if (out_handle_out.begin_copyout(current_process, make_user_out_ptr(out)))
            return ZX_ERR_INVALID_ARGS;
        out_handle_out.finish_copyout(current_process);
        return result;
    });
}
syscall_result wrapper_vcpu_resume(zx_handle_t vcpu, zx_port_packet_t* packet, uint64_t pc) {
    return do_syscall(ZX_SYS_vcpu_resume, pc, &VDso::ValidSyscallPC::vcpu_resume, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_vcpu_resume(vcpu, make_user_out_ptr(packet));
        return result;
    });
}
syscall_result wrapper_vcpu_interrupt(zx_handle_t vcpu, uint32_t vector, uint64_t pc) {
    return do_syscall(ZX_SYS_vcpu_interrupt, pc, &VDso::ValidSyscallPC::vcpu_interrupt, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_vcpu_interrupt(vcpu, vector);
        return result;
    });
}
syscall_result wrapper_vcpu_read_state(zx_handle_t vcpu, uint32_t kind, void* buffer, uint32_t len, uint64_t pc) {
    return do_syscall(ZX_SYS_vcpu_read_state, pc, &VDso::ValidSyscallPC::vcpu_read_state, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_vcpu_read_state(vcpu, kind, make_user_out_ptr(buffer), len);
        return result;
    });
}
syscall_result wrapper_vcpu_write_state(zx_handle_t vcpu, uint32_t kind, const void* buffer, uint32_t len, uint64_t pc) {
    return do_syscall(ZX_SYS_vcpu_write_state, pc, &VDso::ValidSyscallPC::vcpu_write_state, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_vcpu_write_state(vcpu, kind, make_user_in_ptr(buffer), len);
        return result;
    });
}
syscall_result wrapper_system_mexec(zx_handle_t kernel, zx_handle_t bootimage, uint64_t pc) {
    return do_syscall(ZX_SYS_system_mexec, pc, &VDso::ValidSyscallPC::system_mexec, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_system_mexec(kernel, bootimage);
        return result;
    });
}
syscall_result wrapper_system_powerctl(zx_handle_t root_rsrc, uint32_t cmd, const zx_system_powerctl_arg_t* arg, uint64_t pc) {
    return do_syscall(ZX_SYS_system_powerctl, pc, &VDso::ValidSyscallPC::system_powerctl, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_system_powerctl(root_rsrc, cmd, make_user_in_ptr(arg));
        return result;
    });
}
syscall_result wrapper_job_set_relative_importance(zx_handle_t root_resource, zx_handle_t job, zx_handle_t less_important_job, uint64_t pc) {
    return do_syscall(ZX_SYS_job_set_relative_importance, pc, &VDso::ValidSyscallPC::job_set_relative_importance, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_job_set_relative_importance(root_resource, job, less_important_job);
        return result;
    });
}
syscall_result wrapper_syscall_test_0(uint64_t pc) {
    return do_syscall(ZX_SYS_syscall_test_0, pc, &VDso::ValidSyscallPC::syscall_test_0, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_syscall_test_0();
        return result;
    });
}
syscall_result wrapper_syscall_test_1(int a, uint64_t pc) {
    return do_syscall(ZX_SYS_syscall_test_1, pc, &VDso::ValidSyscallPC::syscall_test_1, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_syscall_test_1(a);
        return result;
    });
}
syscall_result wrapper_syscall_test_2(int a, int b, uint64_t pc) {
    return do_syscall(ZX_SYS_syscall_test_2, pc, &VDso::ValidSyscallPC::syscall_test_2, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_syscall_test_2(a, b);
        return result;
    });
}
syscall_result wrapper_syscall_test_3(int a, int b, int c, uint64_t pc) {
    return do_syscall(ZX_SYS_syscall_test_3, pc, &VDso::ValidSyscallPC::syscall_test_3, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_syscall_test_3(a, b, c);
        return result;
    });
}
syscall_result wrapper_syscall_test_4(int a, int b, int c, int d, uint64_t pc) {
    return do_syscall(ZX_SYS_syscall_test_4, pc, &VDso::ValidSyscallPC::syscall_test_4, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_syscall_test_4(a, b, c, d);
        return result;
    });
}
syscall_result wrapper_syscall_test_5(int a, int b, int c, int d, int e, uint64_t pc) {
    return do_syscall(ZX_SYS_syscall_test_5, pc, &VDso::ValidSyscallPC::syscall_test_5, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_syscall_test_5(a, b, c, d, e);
        return result;
    });
}
syscall_result wrapper_syscall_test_6(int a, int b, int c, int d, int e, int f, uint64_t pc) {
    return do_syscall(ZX_SYS_syscall_test_6, pc, &VDso::ValidSyscallPC::syscall_test_6, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_syscall_test_6(a, b, c, d, e, f);
        return result;
    });
}
syscall_result wrapper_syscall_test_7(int a, int b, int c, int d, int e, int f, int g, uint64_t pc) {
    return do_syscall(ZX_SYS_syscall_test_7, pc, &VDso::ValidSyscallPC::syscall_test_7, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_syscall_test_7(a, b, c, d, e, f, g);
        return result;
    });
}
syscall_result wrapper_syscall_test_8(int a, int b, int c, int d, int e, int f, int g, int h, uint64_t pc) {
    return do_syscall(ZX_SYS_syscall_test_8, pc, &VDso::ValidSyscallPC::syscall_test_8, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_syscall_test_8(a, b, c, d, e, f, g, h);
        return result;
    });
}
syscall_result wrapper_syscall_test_wrapper(int a, int b, int c, uint64_t pc) {
    return do_syscall(ZX_SYS_syscall_test_wrapper, pc, &VDso::ValidSyscallPC::syscall_test_wrapper, [&](ProcessDispatcher* current_process) -> uint64_t {
        auto result = sys_syscall_test_wrapper(a, b, c);
        return result;
    });
}
}
