#ifndef RATELPROF_EXT_H
#define RATELPROF_EXT_H

#include <stdint.h>
#include <ratelprof.h>
#include "domains/profiling_trace.h"
#include "ratelprof_ext/memory_structure/ratelprof_buffer_manager.h"
#include "ratelprof_ext/ratelprof_ext_status.h"

#define RATELPROF_DOMAIN_COPY 0x10
#define RATELPROF_DOMAIN_KERNEL 0x11
#define RATELPROF_DOMAIN_BARRIEROR 0x12
#define RATELPROF_DOMAIN_BARRIERAND 0x13
#define RATELPROF_DOMAIN_PROFILING 0x14
#define RATELPROF_DOMAIN_GPU 0x15

#define RATELPROF_DOMAIN_COPY_NAME "MEMORY_COPY"
#define RATELPROF_DOMAIN_KERNEL_NAME "KERNEL_DISPATCH"
#define RATELPROF_DOMAIN_BARRIEROR_NAME "BARRIER_OR_DISPATCH"
#define RATELPROF_DOMAIN_BARRIERAND_NAME "BARRIER_AND_DISPATCH"
#define RATELPROF_DOMAIN_PROFILING_NAME "PROFILING_DOMAIN"

#define RATELPROF_DOMAIN_COPY_DESC "The copy operation in GPU programming is responsible for transferring data between memory locations, such as between host and device memory or between different regions of GPU memory."
#define RATELPROF_DOMAIN_KERNEL_DESC "The kernel dispatch operation is the process of launching a computational kernel on the GPU."
#define RATELPROF_DOMAIN_BARRIEROR_DESC "The Barrier OR is a less restrictive synchronization mechanism that allows subsequent operations to proceed as soon as any one of the specified preceding operations has completed."
#define RATELPROF_DOMAIN_BARRIERAND_DESC "The Barrier AND is a synchronization primitive that ensures all preceding operations in the command queue have completed before subsequent operations can begin."
#define RATELPROF_DOMAIN_PROFILING_DESC "The profiling domain correspond to all HSA function used by RATELProf for GPU Profiling"

extern ratelprof_api_table_t gpu_api_table;
extern ratelprof_api_table_t profiling_table;

typedef bool (*gpu_callback_t)(hsa_signal_value_t, void*);

typedef union gpu_args_s {
    struct {
        ratelprof_timespec_t dispatch_time;
        hsa_agent_t agent;
        uint64_t queue_id;
        union {
            struct {
                uint16_t workgroup_size_x;
                uint16_t workgroup_size_y;
                uint16_t workgroup_size_z;
                uint32_t grid_size_x;
                uint32_t grid_size_y;
                uint32_t grid_size_z;
                uint32_t private_segment_size;
                uint32_t group_segment_size;
                uint64_t kernel_object;
                void* kernarg_address;
            } kernel;
            struct {
                hsa_signal_t dep_signal[5];
            } barrier;
        };
    } dispatch;
    struct {
        hsa_agent_t src_agent;
        hsa_agent_t dst_agent;
        uint32_t src_type;
        uint32_t dst_type;
        size_t size;
    } mem_copy;
} gpu_args_t;

typedef struct ratelprof_gpu_activity_s {
    ratelprof_domain_t domain;
    ratelprof_phase_t phase;
    uint64_t id;
    uint64_t corr_id;
    uint64_t start_time;
    uint64_t stop_time;
    hsa_signal_t completion_signal;
    hsa_signal_t proxy_signal;
    gpu_args_t args;
    
} ratelprof_gpu_activity_t;

#include "domains/gpu_hsa_profiled_function.h"
#include "ratelprof_ext/ratelprof_activity_pool.h"
#include "ratelprof_ext/ratelprof_object_tracking.h"

const char* get_kernel_name(uint64_t kernel_object);
const char* ratelprof_ext_get_domain_name(ratelprof_domain_t domain);
const char* ratelprof_ext_get_domain_desc(ratelprof_domain_t domain);

ratelprof_status_t ratelprof_enable_gpu_api_table();

ratelprof_status_t ratelprof_enable_profiling_table();
ratelprof_status_t ratelprof_populate_profiling_table();

ratelprof_status_t ratelprof_ext_init();
ratelprof_status_t ratelprof_ext_fini();

#endif // RATELPROF_EXT_H
