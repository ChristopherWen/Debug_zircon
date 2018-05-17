// Copyright 2017 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <zircon/compiler.h>
#include <zircon/types.h>

__BEGIN_CDECLS

typedef struct port_handler port_handler_t;

struct port_handler {
    zx_handle_t handle;
    zx_signals_t waitfor;
    // Note: By convention repeating mode handlers return ZX_ERR_NEXT to
    // avoid the wait being re-armed.
    zx_status_t (*func)(port_handler_t* ph, zx_signals_t signals, uint32_t evt);
};

typedef struct {
    zx_handle_t handle;
} port_t;

// Initialize a port
zx_status_t port_init(port_t* port);

// Wait for an event on a handle, as specified by
// the provided port handler.
zx_status_t port_wait(port_t* port, port_handler_t* ph);

// Wait for an event on a handle, as specified by
// the provided port handler, in repeating mode.
zx_status_t port_wait_repeating(port_t* port, port_handler_t* ph);

// Wait for a packet to arrive of for the port to timeout
// If the port wait returns and error or timeout, returns that.
// If once is true, returns ZX_OK after handling a packet.
//
// If a packet is received, the callback for the port handler
// is invoked.  If that callback returns ZX_OK, port_wait()
// is invoked on that port handler again.
zx_status_t port_dispatch(port_t* port, zx_time_t timeout, bool once);

// Cancel pending waits for the handler on this port
zx_status_t port_cancel(port_t* port, port_handler_t* ph);

// Queue an event for the handler on this port
zx_status_t port_queue(port_t* port, port_handler_t* ph, uint32_t evt);



typedef struct port_fd_handler port_fd_handler_t;

struct port_fd_handler {
    port_handler_t ph;
    void* fdio_context;
    zx_status_t (*func)(port_fd_handler_t* fh, unsigned pollevt, uint32_t evt);
};

// On success the embedded port_handler is configured to
// wait on the correct handle and signals to observe the
// specified pollevt (POLLIN, etc), and a reference is held
// to the underlying fd.
zx_status_t port_fd_handler_init(port_fd_handler_t* fh, int fd, unsigned pollevt);

// Releases the reference to the fd held by this port_fd_handler
void port_fd_handler_done(port_fd_handler_t* fh);

__END_CDECLS
