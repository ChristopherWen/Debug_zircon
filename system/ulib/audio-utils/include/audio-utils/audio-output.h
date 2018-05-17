// Copyright 2017 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <audio-utils/audio-device-stream.h>
#include <zircon/types.h>

namespace audio {
namespace utils {

class AudioSource;

class AudioOutput : public AudioDeviceStream {
public:
    static fbl::unique_ptr<AudioOutput> Create(uint32_t dev_id);
    static fbl::unique_ptr<AudioOutput> Create(const char* dev_path);
    zx_status_t Play(AudioSource& source);

private:
    friend class fbl::unique_ptr<AudioOutput>;
    friend class AudioDeviceStream;

    explicit AudioOutput(uint32_t dev_id) : AudioDeviceStream(false, dev_id) { }
    explicit AudioOutput(const char* dev_path) : AudioDeviceStream(true, dev_path) { }
};

}  // namespace utils
}  // namespace audio
