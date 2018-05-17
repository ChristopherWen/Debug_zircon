// Copyright 2016 The Fuchsia Authors
// Copyright (c) 2009 Corey Tabaka
// Copyright (c) 2015 Intel Corporation
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#pragma once

#define PAGE_SIZE 4096
#define PAGE_SIZE_SHIFT 12
#define PAGE_MASK (PAGE_SIZE - 1)

#define MAX_CACHE_LINE 64

#define ARCH_DEFAULT_STACK_SIZE 8192

#define ARCH_PHYSMAP_SIZE (0x1000000000) // 64GB

