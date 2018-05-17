// Copyright 2017 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <audio-utils/audio-stream.h>
#include <zircon/types.h>

#include "wav-common.h"

class WAVSink : public WAVCommon,
                public audio::utils::AudioSink {
public:
    WAVSink() { }
    ~WAVSink() { Finalize(); }
    zx_status_t Initialize(const char* filename) {
        return WAVCommon::Initialize(filename, InitMode::SINK);
    }

    // AudioSink interface
    zx_status_t SetFormat(const AudioStream::Format& format) final;
    zx_status_t PutFrames(const void* buffer, uint32_t amt) final;
    zx_status_t Finalize() final;

private:
    bool format_set_ = false;
    uint64_t bytes_written_ = 0;
};

