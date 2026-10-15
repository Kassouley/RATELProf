#ifndef GPU_HSA_MINIMAL_ABI_H_
#define GPU_HSA_MINIMAL_ABI_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdatomic.h>

/* ============================================================================ *
 * Minimal ABI Header for GPU HSA
 * ============================================================================ */

#define CALL_PROF_FUNC(func, ...) ((__##func##_t)profiling_table.api_ptr[PROFILING_ID_##func])(__VA_ARGS__, NULL)

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

static inline amd_signal_t* amd_signal_convert(hsa_signal_t signal) {
    return (amd_signal_t*)(signal.handle);
}

static inline int64_t amd_signal_atomic_load_value(hsa_signal_t signal) {
    // return CALL_PROF_FUNC(hsa_signal_load_scacquire, signal);
    amd_signal_t* signal_ptr = amd_signal_convert(signal);
    return atomic_load_explicit(&signal_ptr->value, memory_order_acquire);
}

static inline void amd_signal_atomic_store_value(hsa_signal_t signal, int64_t value) {
    // CALL_PROF_FUNC(hsa_signal_store_screlease, signal, value);
    amd_signal_t* signal_ptr = amd_signal_convert(signal);
    atomic_store_explicit(&signal_ptr->value, value, memory_order_release);
}

static inline void amd_signal_refresh(hsa_signal_t signal) {
    amd_signal_t* signal_ptr = amd_signal_convert(signal);
    signal_ptr->value = 1;
    signal_ptr->kind = AMD_SIGNAL_KIND_USER;
    signal_ptr->start_ts = 0;
    signal_ptr->end_ts = 0;
}

static inline void amd_signal_invalidate(hsa_signal_t signal) {
    amd_signal_t* signal_ptr = amd_signal_convert(signal);
    signal_ptr->kind = AMD_SIGNAL_KIND_INVALID;
}

static inline void amd_signal_copy_signal(hsa_signal_t dst, hsa_signal_t src) {
    amd_signal_t* dst_ptr = amd_signal_convert(dst);
    amd_signal_t* src_ptr = amd_signal_convert(src);
    // memcpy(dst_ptr, src_ptr, sizeof(amd_signal_t));
    dst_ptr->value = src_ptr->value;
    dst_ptr->start_ts = src_ptr->start_ts;
    dst_ptr->end_ts = src_ptr->end_ts;
}

static inline hsa_queue_t* amd_signal_get_queue(hsa_signal_t signal) {
    amd_signal_t* signal_ptr = amd_signal_convert(signal);
    return (hsa_queue_t*)(signal_ptr->queue_ptr);
}

static inline bool amd_is_same_signal(hsa_signal_t signal1, hsa_signal_t signal2) {
    return signal1.handle == signal2.handle && signal1.handle != 0;
}

static inline hsa_signal_t amd_signal_create() {
    hsa_signal_t signal;
    CALL_PROF_FUNC(hsa_signal_create, 1, 0, NULL, &signal);
    return signal;
}

static inline void amd_signal_destroy(hsa_signal_t signal) {
    CALL_PROF_FUNC(hsa_signal_destroy, signal);
}

static inline bool amd_signal_is_valid(hsa_signal_t signal) {
    amd_signal_t* signal_ptr = amd_signal_convert(signal);
    return signal_ptr && signal_ptr->kind == AMD_SIGNAL_KIND_USER;
}

static inline bool amd_signal_is_doorbell_signal(hsa_signal_t signal) {
    amd_signal_t* signal_ptr = amd_signal_convert(signal);
    return signal_ptr->kind == AMD_SIGNAL_KIND_DOORBELL || signal_ptr->kind == AMD_SIGNAL_KIND_LEGACY_DOORBELL;
}

#endif // GPU_HSA_MINIMAL_ABI_H_