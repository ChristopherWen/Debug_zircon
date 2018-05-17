# Copyright 2017 The Fuchsia Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_TYPE := userlib

ifeq ($(ARCH),x86)
MODULE_SRCS += \
    $(LOCAL_DIR)/comm-lpc.cpp
endif

include make/module.mk
