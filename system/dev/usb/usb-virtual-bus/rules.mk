# Copyright 2017 The Fuchsia Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_TYPE := driver

MODULE_SRCS += \
    $(LOCAL_DIR)/usb-virtual-bus.c \
    $(LOCAL_DIR)/usb-virtual-device.c \
    $(LOCAL_DIR)/usb-virtual-host.c \

MODULE_STATIC_LIBS := \
    system/ulib/ddk \
    system/ulib/sync

MODULE_LIBS := \
    system/ulib/driver \
    system/ulib/zircon \
    system/ulib/c

include make/module.mk
