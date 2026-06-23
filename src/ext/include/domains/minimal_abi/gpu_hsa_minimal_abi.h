#ifndef GPU_HSA_MINIMAL_ABI_H_
#define GPU_HSA_MINIMAL_ABI_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* ============================================================================ *
 * Minimal ABI Header for GPU HSA
 * ============================================================================ */

#include "domains/minimal_abi/hsa_minimal_abi.h"

typedef int64_t amd_signal_kind64_t;
enum amd_signal_kind_t {
  AMD_SIGNAL_KIND_INVALID = 0,
  AMD_SIGNAL_KIND_USER = 1,
  AMD_SIGNAL_KIND_DOORBELL = -1,
  AMD_SIGNAL_KIND_LEGACY_DOORBELL = -2
};

// AMD Signal.
typedef struct amd_queue_v2_s amd_queue_v2_t;

#define __ALIGNED__(x) __attribute__((aligned(x)))
#define AMD_SIGNAL_ALIGN_BYTES 64
#define AMD_SIGNAL_ALIGN __ALIGNED__(AMD_SIGNAL_ALIGN_BYTES)
typedef struct AMD_SIGNAL_ALIGN amd_signal_s {
  amd_signal_kind64_t kind;
  union {
    volatile int64_t value;
    volatile uint64_t* hardware_doorbell_ptr;
  };
  uint64_t event_mailbox_ptr;
  uint32_t event_id;
  uint32_t reserved1;
  uint64_t start_ts;
  uint64_t end_ts;
  union {
    amd_queue_v2_t* queue_ptr;
    uint64_t reserved2;
  };
  uint32_t reserved3[2];
} amd_signal_t;

#endif // GPU_HSA_MINIMAL_ABI_H_