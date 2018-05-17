// Copyright 2017 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <trace/handler.h>

namespace trace {

const trace_handler_ops_t TraceHandler::kOps =
    {.is_category_enabled = &TraceHandler::CallIsCategoryEnabled,
     .trace_started = &TraceHandler::CallTraceStarted,
     .trace_stopped = &TraceHandler::CallTraceStopped,
     .buffer_overflow = &TraceHandler::CallBufferOverflow};

TraceHandler::TraceHandler()
    : trace_handler{.ops = &kOps} {}

TraceHandler::~TraceHandler() = default;

bool TraceHandler::CallIsCategoryEnabled(trace_handler_t* handler, const char* category) {
    return static_cast<TraceHandler*>(handler)->IsCategoryEnabled(category);
}

void TraceHandler::CallTraceStarted(trace_handler_t* handler) {
    static_cast<TraceHandler*>(handler)->TraceStarted();
}

void TraceHandler::CallTraceStopped(trace_handler_t* handler, async_t* async,
                                    zx_status_t disposition, size_t buffer_bytes_written) {
    static_cast<TraceHandler*>(handler)->TraceStopped(async,
                                                      disposition, buffer_bytes_written);
}

void TraceHandler::CallBufferOverflow(trace_handler_t* handler) {
    static_cast<TraceHandler*>(handler)->BufferOverflow();
}

} // namespace trace
