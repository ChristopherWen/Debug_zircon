// Copyright 2016 The Fuchsia Authors
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#include <object/message_packet.h>

#include <err.h>
#include <stdint.h>
#include <string.h>

#include <zxcpp/new.h>
#include <object/handle.h>

// static
zx_status_t MessagePacket::NewPacket(uint32_t data_size, uint32_t num_handles,
                                     fbl::unique_ptr<MessagePacket>* msg) {
    // Although the API uses uint32_t, we pack the handle count into a smaller
    // field internally. Make sure it fits.
    static_assert(kMaxMessageHandles <= UINT16_MAX, "");
    if (data_size > kMaxMessageSize || num_handles > kMaxMessageHandles) {
        return ZX_ERR_OUT_OF_RANGE;
    }

    // Allocate space for the MessagePacket object followed by num_handles
    // Handle*s followed by data_size bytes.
    // TODO(dbort): Use mbuf-style memory for data_size, ideally allocating from
    // somewhere other than the heap. Lets us better track and isolate channel
    // memory usage.
    char* ptr = static_cast<char*>(malloc(sizeof(MessagePacket) +
                                          num_handles * sizeof(Handle*) +
                                          data_size));
    if (ptr == nullptr) {
        return ZX_ERR_NO_MEMORY;
    }

    // The storage space for the Handle*s is not initialized because
    // the only creators of MessagePackets (sys_channel_write and
    // _call, and userboot) fill that array immediately after creation
    // of the object.
    msg->reset(new (ptr) MessagePacket(
        data_size, num_handles,
        reinterpret_cast<Handle**>(ptr + sizeof(MessagePacket))));
    return ZX_OK;
}

// static
zx_status_t MessagePacket::Create(user_in_ptr<const void> data, uint32_t data_size,
                                  uint32_t num_handles,
                                  fbl::unique_ptr<MessagePacket>* msg) {
    zx_status_t status = NewPacket(data_size, num_handles, msg);
    if (status != ZX_OK) {
        return status;
    }
    if (data_size > 0u) {
        if (data.copy_array_from_user((*msg)->data(), data_size) != ZX_OK) {
            msg->reset();
            return ZX_ERR_INVALID_ARGS;
        }
    }
    return ZX_OK;
}

// static
zx_status_t MessagePacket::Create(const void* data, uint32_t data_size,
                                  uint32_t num_handles,
                                  fbl::unique_ptr<MessagePacket>* msg) {
    zx_status_t status = NewPacket(data_size, num_handles, msg);
    if (status != ZX_OK) {
        return status;
    }
    if (data_size > 0u) {
        memcpy((*msg)->data(), data, data_size);
    }
    return ZX_OK;
}

MessagePacket::~MessagePacket() {
    if (owns_handles_) {
        for (size_t ix = 0; ix != num_handles_; ++ix) {
            // Delete the handle via HandleOwner dtor.
            HandleOwner ho(handles_[ix]);
        }
    }
}

MessagePacket::MessagePacket(uint32_t data_size,
                             uint32_t num_handles, Handle** handles)
    : handles_(handles), data_size_(data_size),
      // NewPacket ensures that num_handles fits in 16 bits.
      num_handles_(static_cast<uint16_t>(num_handles)), owns_handles_(false) {
}
