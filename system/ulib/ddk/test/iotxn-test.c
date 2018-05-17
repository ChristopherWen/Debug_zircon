// Copyright 2017 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <ddk/iotxn.h>
#include <unittest/unittest.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static bool test_physmap_simple(void) {
    BEGIN_TEST;
    iotxn_t* txn;
    ASSERT_EQ(iotxn_alloc(&txn, 0, PAGE_SIZE * 3), ZX_OK, "");
    ASSERT_NONNULL(txn, "");
    ASSERT_EQ(iotxn_physmap(txn), ZX_OK, "");
    ASSERT_NONNULL(txn->phys, "expected phys to be set");
    ASSERT_EQ(txn->phys_count, 3u, "unexpected phys_count");
    iotxn_release(txn);
    END_TEST;
}

static bool test_physmap_contiguous(void) {
    BEGIN_TEST;
    iotxn_t* txn;
    ASSERT_EQ(iotxn_alloc(&txn, IOTXN_ALLOC_CONTIGUOUS, PAGE_SIZE * 3), ZX_OK, "");
    ASSERT_NONNULL(txn, "");
    ASSERT_EQ(iotxn_physmap(txn), ZX_OK, "");
    ASSERT_EQ(txn->phys, &txn->phys_inline[0], "expected phys to point to inline_phys");
    ASSERT_EQ(txn->phys_count, 1u, "unexpected phys_length");
    iotxn_release(txn);
    END_TEST;
}

static bool test_physmap_clone(void) {
    BEGIN_TEST;
    iotxn_t* txn;
    ASSERT_EQ(iotxn_alloc(&txn, 0, PAGE_SIZE * 3), ZX_OK, "");
    ASSERT_NONNULL(txn, "");
    ASSERT_EQ(iotxn_physmap(txn), ZX_OK, "");
    ASSERT_NONNULL(txn->phys, "expected phys to be set");
    ASSERT_EQ(txn->phys_count, 3u, "unexpected phys_count");

    iotxn_t* clone = NULL;
    ASSERT_EQ(iotxn_clone(txn, &clone), ZX_OK, "");
    ASSERT_EQ(txn->phys, clone->phys, "expected clone to point to the same phys");
    ASSERT_EQ(txn->phys_count, clone->phys_count, "unexpected clone phys_count");
    iotxn_release(txn);
    iotxn_release(clone);
    END_TEST;
}

static bool test_physmap_clone_partial(void) {
    BEGIN_TEST;
    iotxn_t* txn;
    ASSERT_EQ(iotxn_alloc(&txn, 0, PAGE_SIZE * 3), ZX_OK, "");
    ASSERT_NONNULL(txn, "");
    ASSERT_EQ(iotxn_physmap(txn), ZX_OK, "");
    ASSERT_NONNULL(txn->phys, "expected phys to be set");
    ASSERT_EQ(txn->phys_count, 3u, "unexpected phys_count");

    iotxn_t* clone = NULL;
    txn->length = PAGE_SIZE * 3;
    ASSERT_EQ(iotxn_clone_partial(txn, PAGE_SIZE * 2, PAGE_SIZE * 2, &clone),
              ZX_ERR_INVALID_ARGS, "expected vmo not to be large enough");
    ASSERT_EQ(iotxn_clone_partial(txn, PAGE_SIZE * 2, PAGE_SIZE * 1, &clone),
              ZX_OK, "");

    ASSERT_NONNULL(clone->phys, "expected phys to be set");
    ASSERT_EQ(clone->phys_count, 1u, "");
    END_TEST;
}

static bool test_physmap_aligned_offset(void) {
    BEGIN_TEST;
    iotxn_t* txn;
    ASSERT_EQ(iotxn_alloc(&txn, 0, PAGE_SIZE * 3), ZX_OK, "");
    ASSERT_NONNULL(txn, "");
    txn->vmo_offset = PAGE_SIZE;
    txn->vmo_length = PAGE_SIZE * 2;
    ASSERT_EQ(iotxn_physmap(txn), ZX_OK, "");
    ASSERT_NONNULL(txn->phys, "expected phys to be set");
    ASSERT_EQ(txn->phys_count, 2u, "unexpected phys_count");
    iotxn_release(txn);
    END_TEST;
}

static bool test_physmap_unaligned_offset(void) {
    BEGIN_TEST;
    iotxn_t* txn;
    ASSERT_EQ(iotxn_alloc(&txn, 0, PAGE_SIZE * 3), ZX_OK, "");
    ASSERT_NONNULL(txn, "");
    txn->vmo_offset = PAGE_SIZE / 2;
    txn->vmo_length = PAGE_SIZE * 2;
    ASSERT_EQ(iotxn_physmap(txn), ZX_OK, "");
    ASSERT_EQ(txn->phys, &txn->phys_inline[0], "expected phys to point to inline_phys");
    ASSERT_EQ(txn->phys_count, 3u, "unexpected phys_count");
    iotxn_release(txn);
    END_TEST;
}

static bool test_physmap_unaligned_offset2(void) {
    BEGIN_TEST;
    iotxn_t* txn;
    ASSERT_EQ(iotxn_alloc(&txn, 0, PAGE_SIZE * 4), ZX_OK, "");
    ASSERT_NONNULL(txn, "");
    txn->vmo_offset = PAGE_SIZE - (PAGE_SIZE / 4);
    txn->vmo_length = (PAGE_SIZE * 2) + (PAGE_SIZE / 2);
    ASSERT_EQ(iotxn_physmap(txn), ZX_OK, "");
    ASSERT_NONNULL(txn->phys, "expected phys to be set");
    ASSERT_NE(txn->phys, &txn->phys_inline[0], "expected phys not to point to inline_phys");
    ASSERT_EQ(txn->phys_count, 4u, "unexpected phys_count");
    iotxn_release(txn);
    END_TEST;
}

static bool test_phys_iter(void) {
    BEGIN_TEST;
    iotxn_phys_iter_t iter;
    iotxn_t* txn;
    zx_paddr_t paddr;
    size_t length;
    size_t max_length;

    // create 4 page contiguous iotxn
    ASSERT_EQ(iotxn_alloc(&txn, IOTXN_ALLOC_CONTIGUOUS, PAGE_SIZE * 4), ZX_OK, "");
    txn->length = PAGE_SIZE * 4;
    ASSERT_EQ(iotxn_physmap(txn), ZX_OK, "");
    ASSERT_EQ(txn->phys_count, 1u, "");

    // simple contiguous case
    max_length = txn->length + PAGE_SIZE;
    iotxn_phys_iter_init(&iter, txn, max_length);
    length = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(paddr, txn->phys[0], "iotxn_iter_next returned wrong paddr");
    ASSERT_EQ(length, txn->length, "iotxn_iter_next returned wrong length");
    ASSERT_EQ(iotxn_phys_iter_next(&iter, &paddr), 0u, "");

    // contiguous case with max_length < txn->length
    max_length = PAGE_SIZE;
    iotxn_phys_iter_init(&iter, txn, max_length);
    for (int i = 0; i < 4; i++) {
        length = iotxn_phys_iter_next(&iter, &paddr);
        ASSERT_EQ(paddr, txn->phys[0] + (i * max_length), "iotxn_iter_next returned wrong paddr");
        ASSERT_EQ(length, max_length, "iotxn_iter_next returned wrong length");
    }
    ASSERT_EQ(iotxn_phys_iter_next(&iter, &paddr), 0u, "");

    // contiguous case with unaligned vmo_offset and txn->length
    txn->vmo_offset = 100;
    max_length = txn->length + PAGE_SIZE;
    txn->length -= 1000;
    iotxn_phys_iter_init(&iter, txn, max_length);
    length = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(paddr, txn->phys[0] + txn->vmo_offset, "");
    ASSERT_EQ(length, txn->length, "");
    ASSERT_EQ(iotxn_phys_iter_next(&iter, &paddr), 0u, "");

    iotxn_release(txn);

    // create discontiguous iotxn
    ASSERT_EQ(iotxn_alloc(&txn, 0, PAGE_SIZE * 4), ZX_OK, "");
    txn->length = PAGE_SIZE * 4;
    ASSERT_EQ(iotxn_physmap(txn), ZX_OK, "");
    ASSERT_EQ(txn->phys_count, 4u, "");
    // pretend that first two pages are contiguous and second two are not
    txn->phys[1] = txn->phys[0] + PAGE_SIZE;
    txn->phys[2] = txn->phys[0] + (PAGE_SIZE * 10);
    txn->phys[3] = txn->phys[0] + (PAGE_SIZE * 20);

    // simple discontiguous case
    max_length = txn->length + PAGE_SIZE;
    iotxn_phys_iter_init(&iter, txn, max_length);
    length = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(paddr, txn->phys[0], "iotxn_iter_next returned wrong paddr");
    ASSERT_EQ(length, (size_t)(PAGE_SIZE * 2), "iotxn_iter_next returned wrong length");
    length = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(paddr, txn->phys[2], "iotxn_iter_next returned wrong paddr");
    ASSERT_EQ(length, (size_t)PAGE_SIZE, "iotxn_iter_next returned wrong length");
    length = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(paddr, txn->phys[3], "iotxn_iter_next returned wrong paddr");
    ASSERT_EQ(length, (size_t)PAGE_SIZE, "iotxn_iter_next returned wrong length");
    ASSERT_EQ(iotxn_phys_iter_next(&iter, &paddr), 0u, "");

    // discontiguous case with max_length < txn->length
    max_length = PAGE_SIZE;
    iotxn_phys_iter_init(&iter, txn, max_length);
    for (int i = 0; i < 4; i++) {
        length = iotxn_phys_iter_next(&iter, &paddr);
        ASSERT_EQ(paddr, txn->phys[i], "iotxn_iter_next returned wrong paddr");
        ASSERT_EQ(length, max_length, "iotxn_iter_next returned wrong length");
    }
    ASSERT_EQ(iotxn_phys_iter_next(&iter, &paddr), 0u, "");

    // discontiguous case with unaligned vmo_offset and txn->length
    txn->vmo_offset = 100;
    max_length = txn->length + PAGE_SIZE;
    txn->length -= 1000;
    iotxn_phys_iter_init(&iter, txn, max_length);
    size_t total_length = 0;
    length = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(paddr, txn->phys[0] + txn->vmo_offset, "");
    ASSERT_EQ(length, (size_t)(PAGE_SIZE * 2) - txn->vmo_offset, "iotxn_iter_next returned wrong length");
    total_length += length;
    length = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(paddr, txn->phys[2], "");
    ASSERT_EQ(length, (size_t)PAGE_SIZE, "");
    total_length += length;
    length = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(paddr, txn->phys[3], "");
    total_length += length;
    ASSERT_EQ(total_length, txn->length, "");
    ASSERT_EQ(iotxn_phys_iter_next(&iter, &paddr), 0u, "");

    iotxn_release(txn);

    END_TEST;
}

// Test behavior of merging adjacent single-page entries.
static bool test_phys_iter_merge(void) {
    BEGIN_TEST;

    iotxn_t iotxn;
    const size_t buf_size = 9 * PAGE_SIZE;
    iotxn_init(&iotxn, ZX_HANDLE_INVALID, PAGE_SIZE, buf_size);
    iotxn.phys = malloc(sizeof(iotxn.phys[0]) * 9);
    ASSERT_NONNULL(iotxn.phys, "");
    iotxn.phys_count = 9;
    iotxn.phys[0] = 0x12345000;
    iotxn.phys[1] = 0x12346000;
    iotxn.phys[2] = 0x12347000;

    iotxn.phys[3] = 0x12349000;

    iotxn.phys[4] = 0x1234b000;

    iotxn.phys[5] = 0x1234d000;
    iotxn.phys[6] = 0x1234e000;
    iotxn.phys[7] = 0x1234f000;
    iotxn.phys[8] = 0x12350000;

    iotxn_phys_iter_t iter;

    // Try iterating 3 pages at a time
    iotxn_phys_iter_init(&iter, &iotxn, 3 * PAGE_SIZE);
    zx_paddr_t paddr;
    size_t size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 3u * PAGE_SIZE, "");
    ASSERT_EQ(paddr, iotxn.phys[0], "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, (size_t)PAGE_SIZE, "");
    ASSERT_EQ(paddr, iotxn.phys[3], "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, (size_t)PAGE_SIZE, "");
    ASSERT_EQ(paddr, iotxn.phys[4], "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 3u * PAGE_SIZE, "");
    ASSERT_EQ(paddr, iotxn.phys[5], "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, (size_t)PAGE_SIZE, "");
    ASSERT_EQ(paddr, iotxn.phys[8], "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 0u, "");

    // Now try iterating with no cap
    iotxn_phys_iter_init(&iter, &iotxn, 0);
    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 3u * PAGE_SIZE, "");
    ASSERT_EQ(paddr, iotxn.phys[0], "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, (size_t)PAGE_SIZE, "");
    ASSERT_EQ(paddr, iotxn.phys[3], "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, (size_t)PAGE_SIZE, "");
    ASSERT_EQ(paddr, iotxn.phys[4], "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 4u * PAGE_SIZE, "");
    ASSERT_EQ(paddr, iotxn.phys[5], "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 0u, "");

    free(iotxn.phys);

    END_TEST;
}

// Test processing of a non-page-aligned contiguous backing buffer.
static bool test_phys_iter_unaligned_contig(void) {
    BEGIN_TEST;

    iotxn_t iotxn;
    const size_t buf_size = 4 * PAGE_SIZE;
    iotxn_init(&iotxn, ZX_HANDLE_INVALID, 128, buf_size);
    iotxn.phys = malloc(sizeof(iotxn.phys[0]) * 5);
    ASSERT_NONNULL(iotxn.phys, "");
    iotxn.phys_count = 5;
    iotxn.phys[0] = 0x12345000;
    iotxn.phys[1] = 0x12346000;
    iotxn.phys[2] = 0x12347000;
    iotxn.phys[3] = 0x12348000;
    iotxn.phys[4] = 0x12349000;

    iotxn_phys_iter_t iter;

    // Try iterating 3 pages at a time
    iotxn_phys_iter_init(&iter, &iotxn, 3 * PAGE_SIZE);
    zx_paddr_t paddr;
    size_t size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 3u * PAGE_SIZE - 128, "");
    ASSERT_EQ(paddr, iotxn.phys[0] + 128, "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, PAGE_SIZE + 128u, "");
    ASSERT_EQ(paddr, iotxn.phys[3], "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 0u, "");

    // Now try iterating with no cap
    iotxn_phys_iter_init(&iter, &iotxn, 0);
    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 4u * PAGE_SIZE, "");
    ASSERT_EQ(paddr, iotxn.phys[0] + 128, "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 0u, "");

    free(iotxn.phys);

    END_TEST;
}

// Test processing of a non-page-aligned non-contiguous backing buffer.
static bool test_phys_iter_unaligned_noncontig(void) {
    BEGIN_TEST;

    iotxn_t iotxn;
    const size_t buf_size = 2 * PAGE_SIZE;
    iotxn_init(&iotxn, ZX_HANDLE_INVALID, 128, buf_size);
    iotxn.phys = malloc(sizeof(iotxn.phys[0]) * 3);
    ASSERT_NONNULL(iotxn.phys, "");
    iotxn.phys_count = 3;
    iotxn.phys[0] = 0x12345000;
    iotxn.phys[1] = 0x12347000;
    iotxn.phys[2] = 0x12349000;

    iotxn_phys_iter_t iter;

    iotxn_phys_iter_init(&iter, &iotxn, 0);
    zx_paddr_t paddr;

    size_t size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, PAGE_SIZE - 128u, "");
    ASSERT_EQ(paddr, iotxn.phys[0] + 128, "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, (size_t)PAGE_SIZE, "");
    ASSERT_EQ(paddr, iotxn.phys[1], "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 128u, "");
    ASSERT_EQ(paddr, iotxn.phys[2], "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 0u, "");

    free(iotxn.phys);

    END_TEST;
}

// Test processing of a tiny page-aligned buffer.
static bool test_phys_iter_tiny_aligned(void) {
    BEGIN_TEST;

    iotxn_t iotxn;
    const size_t buf_size = 128;
    iotxn_init(&iotxn, ZX_HANDLE_INVALID, 0, buf_size);
    iotxn.phys = malloc(sizeof(iotxn.phys[0]) * 1);
    ASSERT_NONNULL(iotxn.phys, "");
    iotxn.phys_count = 1;
    iotxn.phys[0] = 0x12345000;

    iotxn_phys_iter_t iter;

    iotxn_phys_iter_init(&iter, &iotxn, 0);
    zx_paddr_t paddr;
    size_t size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 128u, "");
    ASSERT_EQ(paddr, iotxn.phys[0], "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 0u, "");

    free(iotxn.phys);

    END_TEST;
}

// Test processing of a tiny non-page-aligned buffer.
static bool test_phys_iter_tiny_unaligned(void) {
    BEGIN_TEST;

    iotxn_t iotxn;
    const size_t buf_size = 128;
    iotxn_init(&iotxn, ZX_HANDLE_INVALID, 128, buf_size);
    iotxn.phys = malloc(sizeof(iotxn.phys[0]) * 1);
    ASSERT_NONNULL(iotxn.phys, "");
    iotxn.phys_count = 1;
    iotxn.phys[0] = 0x12345000;

    iotxn_phys_iter_t iter;

    iotxn_phys_iter_init(&iter, &iotxn, 0);
    zx_paddr_t paddr;
    size_t size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 128u, "");
    ASSERT_EQ(paddr, iotxn.phys[0] + 128, "");

    size = iotxn_phys_iter_next(&iter, &paddr);
    ASSERT_EQ(size, 0u, "");

    free(iotxn.phys);

    END_TEST;
}

BEGIN_TEST_CASE(iotxn_tests)
RUN_TEST(test_physmap_simple)
RUN_TEST(test_physmap_contiguous)
RUN_TEST(test_physmap_clone)
RUN_TEST(test_physmap_clone_partial)
RUN_TEST(test_physmap_aligned_offset)
RUN_TEST(test_physmap_unaligned_offset)
RUN_TEST(test_physmap_unaligned_offset2)
RUN_TEST(test_phys_iter)
RUN_TEST(test_phys_iter_merge)
RUN_TEST(test_phys_iter_unaligned_contig)
RUN_TEST(test_phys_iter_unaligned_noncontig)
RUN_TEST(test_phys_iter_tiny_aligned)
RUN_TEST(test_phys_iter_tiny_unaligned)
END_TEST_CASE(iotxn_tests)

struct test_case_element* test_case_ddk_iotxn = TEST_CASE_ELEMENT(iotxn_tests);
