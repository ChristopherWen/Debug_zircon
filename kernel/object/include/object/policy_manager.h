// Copyright 2017 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <stddef.h>
#include <stdint.h>

#include <zircon/syscalls/policy.h>
#include <zircon/types.h>

#include <fbl/ref_ptr.h>

struct zx_policy_basic;
class PortDispatcher;

typedef uint64_t pol_cookie_t;
constexpr pol_cookie_t kPolicyEmpty = 0u;

// PolicyManager is in charge of providing a space-efficient encoding of
// the external policy as defined in the policy.h public header which
// the client expresses as an array of zx_policy_basic elements.
//
// For example:
//
//   zx_policy_basic in_policy[] = {
//      { ZX_POL_BAD_HANDLE, ZX_POL_ACTION_KILL },
//      { ZX_POL_NEW_CHANNEL, ZX_POL_ACTION_ALLOW },
//      { ZX_POL_NEW_FIFO, ZX_POL_ACTION_ALLOW | ZX_POL_ACTION_EXCEPTION },
//      { ZX_POL_VMAR_WX, ZX_POL_ACTION_DENY | ZX_POL_ACTION_KILL }}
//
//  Which is 64 bytes but PolicyManager can encode it in the pol_cookie_t
//  itself if it is a simple policy.

class PolicyManager {
public:
    // Creates in the heap a policy manager with a |default_action|
    // which is returned when QueryBasicPolicy() matches no known condition.
    static PolicyManager* Create(uint32_t default_action = ZX_POL_ACTION_ALLOW);

    // Creates a |new_policy| based on an |existing_policy| or based on
    // kPolicyEmpty and an array of |policy_input|. When done with the
    // new policy RemovePolicy() must be called.
    //
    // |mode| can be:
    // - ZX_JOB_POL_RELATIVE which creates a new policy that only uses
    //   the |policy_input| entries that are unespecified in |existing_policy|
    // - ZX_JOB_POL_ABSOLUTE which creates a new policy that requires
    //   that all |policy_input| entries are used.
    //
    // This call can fail in low memory cases and when the |existing_policy|
    // and the policy_input are in conflict given the |mode| paramater.
    zx_status_t AddPolicy(
        uint32_t mode, pol_cookie_t existing_policy,
        const zx_policy_basic* policy_input, size_t policy_count,
        pol_cookie_t* new_policy);

    // Returns whether |condition| (from the ZX_POL_xxxx set) is allowed
    // by |policy| (created using AddPolicy()).
    //
    // If the condition is allowed, returns ZX_POL_ACTION_ALLOW,
    // optionally ORed with ZX_POL_ACTION_EXCEPTION according to the
    // policy.
    //
    // If the condition is not allowed, returns ZX_POL_ACTION_DENY,
    // optionally ORed with zero or more of ZX_POL_ACTION_EXCEPTION and
    // ZX_POL_ACTION_KILL.
    //
    // This method asserts if |policy| is invalid, and returns
    // ZX_POL_ACTION_DENY all other failure modes.
    uint32_t QueryBasicPolicy(pol_cookie_t policy, uint32_t condition);

private:
    explicit PolicyManager(uint32_t default_action);
    ~PolicyManager() = default;

    uint32_t GetEffectiveAction(uint64_t policy);
    bool CanSetEntry(uint64_t existing, uint32_t new_action);

    zx_status_t AddPartial(uint32_t mode, pol_cookie_t existing_policy,
        uint32_t condition, uint32_t policy, uint64_t* partial);

    const uint32_t default_action_;
};

// Returns the singleton policy manager for jobs and processes.
PolicyManager* GetSystemPolicyManager();
