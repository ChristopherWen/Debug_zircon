// Copyright 2018 The Fuchsia Authors. All rights reserved.
// This is a GENERATED file, see //zircon/system/host/abigen.
// The license governing this file can be found in the LICENSE file.

#[link(name = "zircon")]
extern {
    pub fn zx_clock_get(
        clock_id: u32
        ) -> zx_time_t;

    pub fn zx_nanosleep(
        deadline: zx_time_t
        ) -> zx_status_t;

    pub fn zx_ticks_get(
        ) -> u64;

    pub fn zx_ticks_per_second(
        ) -> u64;

    pub fn zx_deadline_after(
        nanoseconds: zx_duration_t
        ) -> zx_time_t;

    pub fn zx_clock_adjust(
        handle: zx_handle_t,
        clock_id: u32,
        offset: i64
        ) -> zx_status_t;

    pub fn zx_system_get_dcache_line_size(
        ) -> u32;

    pub fn zx_system_get_num_cpus(
        ) -> u32;

    pub fn zx_system_get_version(
        version: *mut u8,
        version_len: u32
        ) -> zx_status_t;

    pub fn zx_system_get_physmem(
        ) -> u64;

    pub fn zx_system_get_features(
        kind: u32,
        out: *mut u32
        ) -> zx_status_t;

    pub fn zx_cache_flush(
        addr: *const u8,
        len: usize,
        options: u32
        ) -> zx_status_t;

    pub fn zx_handle_close(
        handle: zx_handle_t
        ) -> zx_status_t;

    pub fn zx_handle_duplicate(
        handle: zx_handle_t,
        rights: zx_rights_t,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_handle_replace(
        handle: zx_handle_t,
        rights: zx_rights_t,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_object_wait_one(
        handle: zx_handle_t,
        waitfor: zx_signals_t,
        deadline: zx_time_t,
        observed: *mut zx_signals_t
        ) -> zx_status_t;

    pub fn zx_object_wait_many(
        items: *mut zx_wait_item_t,
        count: u32,
        deadline: zx_time_t
        ) -> zx_status_t;

    pub fn zx_object_wait_async(
        handle: zx_handle_t,
        port_handle: zx_handle_t,
        key: u64,
        signals: zx_signals_t,
        options: u32
        ) -> zx_status_t;

    pub fn zx_object_signal(
        handle: zx_handle_t,
        clear_mask: u32,
        set_mask: u32
        ) -> zx_status_t;

    pub fn zx_object_signal_peer(
        handle: zx_handle_t,
        clear_mask: u32,
        set_mask: u32
        ) -> zx_status_t;

    pub fn zx_object_get_property(
        handle: zx_handle_t,
        property: u32,
        value: *mut u8,
        size: usize
        ) -> zx_status_t;

    pub fn zx_object_set_property(
        handle: zx_handle_t,
        property: u32,
        value: *const u8,
        size: usize
        ) -> zx_status_t;

    pub fn zx_object_set_cookie(
        handle: zx_handle_t,
        scope: zx_handle_t,
        cookie: u64
        ) -> zx_status_t;

    pub fn zx_object_get_cookie(
        handle: zx_handle_t,
        scope: zx_handle_t,
        cookie: *mut u64
        ) -> zx_status_t;

    pub fn zx_object_get_info(
        handle: zx_handle_t,
        topic: u32,
        buffer: *mut u8,
        buffer_size: usize,
        actual_count: *mut usize,
        avail_count: *mut usize
        ) -> zx_status_t;

    pub fn zx_object_get_child(
        handle: zx_handle_t,
        koid: u64,
        rights: zx_rights_t,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_object_set_profile(
        handle: zx_handle_t,
        profile: zx_handle_t,
        options: u32
        ) -> zx_status_t;

    pub fn zx_channel_create(
        options: u32,
        out0: *mut zx_handle_t,
        out1: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_channel_read(
        handle: zx_handle_t,
        options: u32,
        bytes: *mut u8,
        handles: *mut zx_handle_t,
        num_bytes: u32,
        num_handles: u32,
        actual_bytes: *mut u32,
        actual_handles: *mut u32
        ) -> zx_status_t;

    pub fn zx_channel_read_etc(
        handle: zx_handle_t,
        options: u32,
        bytes: *mut u8,
        handles: *mut zx_handle_info_t,
        num_bytes: u32,
        num_handles: u32,
        actual_bytes: *mut u32,
        actual_handles: *mut u32
        ) -> zx_status_t;

    pub fn zx_channel_write(
        handle: zx_handle_t,
        options: u32,
        bytes: *const u8,
        num_bytes: u32,
        handles: *const zx_handle_t,
        num_handles: u32
        ) -> zx_status_t;

    pub fn zx_channel_call_noretry(
        handle: zx_handle_t,
        options: u32,
        deadline: zx_time_t,
        args: *const zx_channel_call_args_t,
        actual_bytes: *mut u32,
        actual_handles: *mut u32,
        read_status: *mut zx_status_t
        ) -> zx_status_t;

    pub fn zx_channel_call_finish(
        deadline: zx_time_t,
        args: *const zx_channel_call_args_t,
        actual_bytes: *mut u32,
        actual_handles: *mut u32,
        read_status: *mut zx_status_t
        ) -> zx_status_t;

    pub fn zx_channel_call(
        handle: zx_handle_t,
        options: u32,
        deadline: zx_time_t,
        args: *const zx_channel_call_args_t,
        actual_bytes: *mut u32,
        actual_handles: *mut u32,
        read_status: *mut zx_status_t
        ) -> zx_status_t;

    pub fn zx_socket_create(
        options: u32,
        out0: *mut zx_handle_t,
        out1: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_socket_write(
        handle: zx_handle_t,
        options: u32,
        buffer: *const u8,
        size: usize,
        actual: *mut usize
        ) -> zx_status_t;

    pub fn zx_socket_read(
        handle: zx_handle_t,
        options: u32,
        buffer: *mut u8,
        size: usize,
        actual: *mut usize
        ) -> zx_status_t;

    pub fn zx_socket_share(
        handle: zx_handle_t,
        socket_to_share: zx_handle_t
        ) -> zx_status_t;

    pub fn zx_socket_accept(
        handle: zx_handle_t,
        out_socket: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_thread_exit(
        );

    pub fn zx_thread_create(
        process: zx_handle_t,
        name: *const u8,
        name_len: u32,
        options: u32,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_thread_start(
        handle: zx_handle_t,
        thread_entry: usize,
        stack: usize,
        arg1: usize,
        arg2: usize
        ) -> zx_status_t;

    pub fn zx_thread_read_state(
        handle: zx_handle_t,
        kind: u32,
        buffer: *mut u8,
        len: usize
        ) -> zx_status_t;

    pub fn zx_thread_write_state(
        handle: zx_handle_t,
        kind: u32,
        buffer: *const u8,
        buffer_len: usize
        ) -> zx_status_t;

    pub fn zx_thread_set_priority(
        prio: i32
        ) -> zx_status_t;

    pub fn zx_process_exit(
        retcode: isize
        );

    pub fn zx_process_create(
        job: zx_handle_t,
        name: *const u8,
        name_len: u32,
        options: u32,
        proc_handle: *mut zx_handle_t,
        vmar_handle: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_process_start(
        process_handle: zx_handle_t,
        thread_handle: zx_handle_t,
        entry: usize,
        stack: usize,
        arg_handle: zx_handle_t,
        arg2: usize
        ) -> zx_status_t;

    pub fn zx_process_read_memory(
        proc_: zx_handle_t,
        vaddr: usize,
        buffer: *mut u8,
        len: usize,
        actual: *mut usize
        ) -> zx_status_t;

    pub fn zx_process_write_memory(
        proc_: zx_handle_t,
        vaddr: usize,
        buffer: *const u8,
        len: usize,
        actual: *mut usize
        ) -> zx_status_t;

    pub fn zx_job_create(
        parent_job: zx_handle_t,
        options: u32,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_job_set_policy(
        job: zx_handle_t,
        options: u32,
        topic: u32,
        policy: *const u8,
        count: u32
        ) -> zx_status_t;

    pub fn zx_task_bind_exception_port(
        object: zx_handle_t,
        eport: zx_handle_t,
        key: u64,
        options: u32
        ) -> zx_status_t;

    pub fn zx_task_suspend(
        task_handle: zx_handle_t
        ) -> zx_status_t;

    pub fn zx_task_resume(
        task_handle: zx_handle_t,
        options: u32
        ) -> zx_status_t;

    pub fn zx_task_suspend_token(
        task_handle: zx_handle_t,
        token: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_task_resume_from_exception(
        task_handle: zx_handle_t,
        eport: zx_handle_t,
        options: u32
        ) -> zx_status_t;

    pub fn zx_task_kill(
        task_handle: zx_handle_t
        ) -> zx_status_t;

    pub fn zx_event_create(
        options: u32,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_eventpair_create(
        options: u32,
        out0: *mut zx_handle_t,
        out1: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_futex_wait(
        value_ptr: *const zx_futex_t,
        current_value: isize,
        deadline: zx_time_t
        ) -> zx_status_t;

    pub fn zx_futex_wake(
        value_ptr: *const zx_futex_t,
        count: u32
        ) -> zx_status_t;

    pub fn zx_futex_requeue(
        wake_ptr: *const zx_futex_t,
        wake_count: u32,
        current_value: isize,
        requeue_ptr: *const zx_futex_t,
        requeue_count: u32
        ) -> zx_status_t;

    pub fn zx_port_create(
        options: u32,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_port_queue(
        handle: zx_handle_t,
        packet: *const zx_port_packet_t,
        count: usize
        ) -> zx_status_t;

    pub fn zx_port_wait(
        handle: zx_handle_t,
        deadline: zx_time_t,
        packet: *mut zx_port_packet_t,
        count: usize
        ) -> zx_status_t;

    pub fn zx_port_cancel(
        handle: zx_handle_t,
        source: zx_handle_t,
        key: u64
        ) -> zx_status_t;

    pub fn zx_timer_create(
        options: u32,
        clock_id: u32,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_timer_set(
        handle: zx_handle_t,
        deadline: zx_time_t,
        slack: zx_duration_t
        ) -> zx_status_t;

    pub fn zx_timer_cancel(
        handle: zx_handle_t
        ) -> zx_status_t;

    pub fn zx_vmo_create(
        size: u64,
        options: u32,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_vmo_read(
        handle: zx_handle_t,
        data: *mut u8,
        offset: u64,
        len: usize
        ) -> zx_status_t;

    pub fn zx_vmo_write(
        handle: zx_handle_t,
        data: *const u8,
        offset: u64,
        len: usize
        ) -> zx_status_t;

    pub fn zx_vmo_get_size(
        handle: zx_handle_t,
        size: *mut u64
        ) -> zx_status_t;

    pub fn zx_vmo_set_size(
        handle: zx_handle_t,
        size: u64
        ) -> zx_status_t;

    pub fn zx_vmo_op_range(
        handle: zx_handle_t,
        op: u32,
        offset: u64,
        size: u64,
        buffer: *mut u8,
        buffer_size: usize
        ) -> zx_status_t;

    pub fn zx_vmo_clone(
        handle: zx_handle_t,
        options: u32,
        offset: u64,
        size: u64,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_vmo_set_cache_policy(
        handle: zx_handle_t,
        cache_policy: u32
        ) -> zx_status_t;

    pub fn zx_vmar_allocate(
        parent_vmar_handle: zx_handle_t,
        offset: usize,
        size: usize,
        map_flags: u32,
        child_vmar: *mut zx_handle_t,
        child_addr: *mut usize
        ) -> zx_status_t;

    pub fn zx_vmar_destroy(
        vmar_handle: zx_handle_t
        ) -> zx_status_t;

    pub fn zx_vmar_map(
        vmar_handle: zx_handle_t,
        vmar_offset: usize,
        vmo_handle: zx_handle_t,
        vmo_offset: u64,
        len: usize,
        map_flags: u32,
        mapped_addr: *mut usize
        ) -> zx_status_t;

    pub fn zx_vmar_unmap(
        vmar_handle: zx_handle_t,
        addr: usize,
        len: usize
        ) -> zx_status_t;

    pub fn zx_vmar_protect(
        vmar_handle: zx_handle_t,
        addr: usize,
        len: usize,
        prot_flags: u32
        ) -> zx_status_t;

    pub fn zx_cprng_draw(
        buffer: *mut u8,
        len: usize,
        actual: *mut usize
        ) -> zx_status_t;

    pub fn zx_cprng_add_entropy(
        buffer: *const u8,
        len: usize
        ) -> zx_status_t;

    pub fn zx_fifo_create(
        elem_count: u32,
        elem_size: u32,
        options: u32,
        out0: *mut zx_handle_t,
        out1: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_fifo_read(
        handle: zx_handle_t,
        data: *mut u8,
        len: usize,
        num_written: *mut u32
        ) -> zx_status_t;

    pub fn zx_fifo_read_old(
        handle: zx_handle_t,
        data: *mut u8,
        len: usize,
        num_written: *mut u32
        ) -> zx_status_t;

    pub fn zx_fifo_write(
        handle: zx_handle_t,
        data: *const u8,
        len: usize,
        num_written: *mut u32
        ) -> zx_status_t;

    pub fn zx_fifo_write_old(
        handle: zx_handle_t,
        data: *const u8,
        len: usize,
        num_written: *mut u32
        ) -> zx_status_t;

    pub fn zx_profile_create(
        resource: zx_handle_t,
        profile: *const zx_profile_info_t,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_vmar_unmap_handle_close_thread_exit(
        vmar_handle: zx_handle_t,
        addr: usize,
        len: usize,
        handle: zx_handle_t
        ) -> zx_status_t;

    pub fn zx_futex_wake_handle_close_thread_exit(
        value_ptr: *const zx_futex_t,
        count: u32,
        new_value: isize,
        handle: zx_handle_t
        );

    pub fn zx_log_create(
        options: u32,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_log_write(
        handle: zx_handle_t,
        len: u32,
        buffer: *const u8,
        options: u32
        ) -> zx_status_t;

    pub fn zx_log_read(
        handle: zx_handle_t,
        len: u32,
        buffer: *mut u8,
        options: u32
        ) -> zx_status_t;

    pub fn zx_debuglog_create(
        resource: zx_handle_t,
        options: u32,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_debuglog_write(
        handle: zx_handle_t,
        options: u32,
        buffer: *const u8,
        len: usize
        ) -> zx_status_t;

    pub fn zx_debuglog_read(
        handle: zx_handle_t,
        options: u32,
        buffer: *mut u8,
        len: usize
        ) -> zx_status_t;

    pub fn zx_ktrace_read(
        handle: zx_handle_t,
        data: *mut u8,
        offset: u32,
        len: u32,
        actual: *mut u32
        ) -> zx_status_t;

    pub fn zx_ktrace_control(
        handle: zx_handle_t,
        action: u32,
        options: u32,
        ptr: *mut u8
        ) -> zx_status_t;

    pub fn zx_ktrace_write(
        handle: zx_handle_t,
        id: u32,
        arg0: u32,
        arg1: u32
        ) -> zx_status_t;

    pub fn zx_mtrace_control(
        handle: zx_handle_t,
        kind: u32,
        action: u32,
        options: u32,
        ptr: *mut u8,
        size: u32
        ) -> zx_status_t;

    pub fn zx_debug_read(
        handle: zx_handle_t,
        buffer: *mut u8,
        length: *mut usize
        ) -> zx_status_t;

    pub fn zx_debug_write(
        buffer: *const u8,
        length: usize
        ) -> zx_status_t;

    pub fn zx_debug_send_command(
        resource_handle: zx_handle_t,
        buffer: *const u8,
        length: usize
        ) -> zx_status_t;

    pub fn zx_interrupt_create(
        src_obj: zx_handle_t,
        src_num: u32,
        options: u32,
        out_handle: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_interrupt_bind(
        inth: zx_handle_t,
        porth: zx_handle_t,
        key: u64,
        options: u32
        ) -> zx_status_t;

    pub fn zx_interrupt_wait(
        handle: zx_handle_t,
        out_timestamp: *mut zx_time_t
        ) -> zx_status_t;

    pub fn zx_interrupt_destroy(
        handle: zx_handle_t
        ) -> zx_status_t;

    pub fn zx_interrupt_ack(
        handle: zx_handle_t
        ) -> zx_status_t;

    pub fn zx_interrupt_trigger(
        handle: zx_handle_t,
        options: u32,
        timestamp: zx_time_t
        ) -> zx_status_t;

    pub fn zx_mmap_device_io(
        handle: zx_handle_t,
        io_addr: u32,
        len: u32
        ) -> zx_status_t;

    pub fn zx_vmo_create_contiguous(
        bti: zx_handle_t,
        size: usize,
        alignment_log2: u32,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_vmo_create_physical(
        rsrc_handle: zx_handle_t,
        paddr: zx_paddr_t,
        size: usize,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_iommu_create(
        rsrc_handle: zx_handle_t,
        type: u32,
        desc: *const u8,
        desc_len: u32,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_bti_create(
        iommu: zx_handle_t,
        options: u32,
        bti_id: u64,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_bti_pin(
        bti: zx_handle_t,
        options: u32,
        vmo: zx_handle_t,
        offset: u64,
        size: u64,
        addrs: *mut zx_paddr_t,
        addrs_count: usize,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_bti_release_quarantine(
        bti: zx_handle_t
        ) -> zx_status_t;

    pub fn zx_pmt_unpin(
        pmt: zx_handle_t
        ) -> zx_status_t;

    pub fn zx_bootloader_fb_get_info(
        format: *mut u32,
        width: *mut u32,
        height: *mut u32,
        stride: *mut u32
        ) -> zx_status_t;

    pub fn zx_set_framebuffer(
        handle: zx_handle_t,
        vaddr: *mut u8,
        len: u32,
        format: u32,
        width: u32,
        height: u32,
        stride: u32
        ) -> zx_status_t;

    pub fn zx_set_framebuffer_vmo(
        handle: zx_handle_t,
        vmo: zx_handle_t,
        len: u32,
        format: u32,
        width: u32,
        height: u32,
        stride: u32
        ) -> zx_status_t;

    pub fn zx_pci_get_nth_device(
        handle: zx_handle_t,
        index: u32,
        out_info: *mut zx_pcie_device_info_t,
        out_handle: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_pci_enable_bus_master(
        handle: zx_handle_t,
        enable: bool
        ) -> zx_status_t;

    pub fn zx_pci_reset_device(
        handle: zx_handle_t
        ) -> zx_status_t;

    pub fn zx_pci_config_read(
        handle: zx_handle_t,
        offset: u16,
        width: usize,
        out_val: *mut u32
        ) -> zx_status_t;

    pub fn zx_pci_config_write(
        handle: zx_handle_t,
        offset: u16,
        width: usize,
        val: u32
        ) -> zx_status_t;

    pub fn zx_pci_cfg_pio_rw(
        handle: zx_handle_t,
        bus: u8,
        dev: u8,
        func: u8,
        offset: u8,
        val: *mut u32,
        width: usize,
        write: bool
        ) -> zx_status_t;

    pub fn zx_pci_get_bar(
        handle: zx_handle_t,
        bar_num: u32,
        out_bar: *mut zx_pci_bar_t,
        out_handle: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_pci_map_interrupt(
        handle: zx_handle_t,
        which_irq: i32,
        out_handle: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_pci_query_irq_mode(
        handle: zx_handle_t,
        mode: u32,
        out_max_irqs: *mut u32
        ) -> zx_status_t;

    pub fn zx_pci_set_irq_mode(
        handle: zx_handle_t,
        mode: u32,
        requested_irq_count: u32
        ) -> zx_status_t;

    pub fn zx_pci_init(
        handle: zx_handle_t,
        init_buf: *const zx_pci_init_arg_t,
        len: u32
        ) -> zx_status_t;

    pub fn zx_pci_add_subtract_io_range(
        handle: zx_handle_t,
        mmio: bool,
        base: u64,
        len: u64,
        add: bool
        ) -> zx_status_t;

    pub fn zx_pc_firmware_tables(
        handle: zx_handle_t,
        acpi_rsdp: *mut zx_paddr_t,
        smbios: *mut zx_paddr_t
        ) -> zx_status_t;

    pub fn zx_smc_call(
        rsrc_handle: zx_handle_t,
        arg0: u64,
        arg1: u64,
        arg2: u64,
        arg3: u64,
        out_smc_status: *mut u64
        ) -> zx_status_t;

    pub fn zx_resource_create(
        parent_handle: zx_handle_t,
        kind: u32,
        low: u64,
        high: u64,
        resource_out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_guest_create(
        resource: zx_handle_t,
        options: u32,
        physmem_vmo: zx_handle_t,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_guest_set_trap(
        guest: zx_handle_t,
        kind: u32,
        addr: zx_vaddr_t,
        len: usize,
        port: zx_handle_t,
        key: u64
        ) -> zx_status_t;

    pub fn zx_vcpu_create(
        guest: zx_handle_t,
        options: u32,
        entry: zx_vaddr_t,
        out: *mut zx_handle_t
        ) -> zx_status_t;

    pub fn zx_vcpu_resume(
        vcpu: zx_handle_t,
        packet: *mut zx_port_packet_t
        ) -> zx_status_t;

    pub fn zx_vcpu_interrupt(
        vcpu: zx_handle_t,
        vector: u32
        ) -> zx_status_t;

    pub fn zx_vcpu_read_state(
        vcpu: zx_handle_t,
        kind: u32,
        buffer: *mut u8,
        len: u32
        ) -> zx_status_t;

    pub fn zx_vcpu_write_state(
        vcpu: zx_handle_t,
        kind: u32,
        buffer: *const u8,
        len: u32
        ) -> zx_status_t;

    pub fn zx_system_mexec(
        kernel: zx_handle_t,
        bootimage: zx_handle_t
        ) -> zx_status_t;

    pub fn zx_system_powerctl(
        root_rsrc: zx_handle_t,
        cmd: u32,
        arg: *const zx_system_powerctl_arg_t
        ) -> zx_status_t;

    pub fn zx_job_set_relative_importance(
        root_resource: zx_handle_t,
        job: zx_handle_t,
        less_important_job: zx_handle_t
        ) -> zx_status_t;

    pub fn zx_syscall_test_0(
        ) -> zx_status_t;

    pub fn zx_syscall_test_1(
        a: isize
        ) -> zx_status_t;

    pub fn zx_syscall_test_2(
        a: isize,
        b: isize
        ) -> zx_status_t;

    pub fn zx_syscall_test_3(
        a: isize,
        b: isize,
        c: isize
        ) -> zx_status_t;

    pub fn zx_syscall_test_4(
        a: isize,
        b: isize,
        c: isize,
        d: isize
        ) -> zx_status_t;

    pub fn zx_syscall_test_5(
        a: isize,
        b: isize,
        c: isize,
        d: isize,
        e: isize
        ) -> zx_status_t;

    pub fn zx_syscall_test_6(
        a: isize,
        b: isize,
        c: isize,
        d: isize,
        e: isize,
        f: isize
        ) -> zx_status_t;

    pub fn zx_syscall_test_7(
        a: isize,
        b: isize,
        c: isize,
        d: isize,
        e: isize,
        f: isize,
        g: isize
        ) -> zx_status_t;

    pub fn zx_syscall_test_8(
        a: isize,
        b: isize,
        c: isize,
        d: isize,
        e: isize,
        f: isize,
        g: isize,
        h: isize
        ) -> zx_status_t;

    pub fn zx_syscall_test_wrapper(
        a: isize,
        b: isize,
        c: isize
        ) -> zx_status_t;


}
