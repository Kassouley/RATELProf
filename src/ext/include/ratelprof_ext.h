#ifndef RATELPROF_EXT_H
#define RATELPROF_EXT_H

#include <stdint.h>
#include <ratelprof.h>
#include "ratelprof_ext/ratelprof_ext_status.h"

#include "ratelprof_ext/ratelprof_activity_pool.h"
#include "ratelprof_ext/ratelprof_object_tracking.h"

#include "domains/gpu_hsa_api_helper.h"
#include "domains/profiling_hsa_api_helper.h"

#define RATELPROF_DOMAIN_COPY_NAME          "RATELPROF_DOMAIN_COPY"
#define RATELPROF_DOMAIN_KERNEL_NAME        "RATELPROF_DOMAIN_KERNEL"
#define RATELPROF_DOMAIN_BARRIEROR_NAME     "RATELPROF_DOMAIN_BARRIEROR"
#define RATELPROF_DOMAIN_BARRIERAND_NAME    "RATELPROF_DOMAIN_BARRIERAND"
#define RATELPROF_DOMAIN_PROFILING_NAME     "RATELPROF_DOMAIN_PROFILING"
#define RATELPROF_DOMAIN_OMP_REGION_NAME    "RATELPROF_DOMAIN_OMP_REGION"

#define RATELPROF_DOMAIN_COPY_DESC          "The copy operation in GPU programming is responsible for transferring data between memory locations (between host and device memory or between different regions of GPU memory)."
#define RATELPROF_DOMAIN_KERNEL_DESC        "The kernel dispatch operation is the process of launching a computational kernel on the GPU."
#define RATELPROF_DOMAIN_BARRIEROR_DESC     "The Barrier OR is a less restrictive synchronization mechanism that allows subsequent operations to proceed as soon as any one of the specified preceding operations has completed."
#define RATELPROF_DOMAIN_BARRIERAND_DESC    "The Barrier AND is a synchronization primitive that ensures all preceding operations in the command queue have completed before subsequent operations can begin."
#define RATELPROF_DOMAIN_PROFILING_DESC     "The profiling domain correspond to all HSA function used by RATELProf for GPU Profiling"
#define RATELPROF_DOMAIN_OMP_REGION_DESC    "OpenMP Target region traces given by the OMPT API"

extern ratelprof_api_table_t gpu_api_table;
extern ratelprof_api_table_t profiling_table;

typedef enum {
    RATELPROF_DOMAIN_OMP_REGION = RATELPROF_NB_DOMAIN,
    RATELPROF_DOMAIN_PROFILING,
    RATELPROF_DOMAIN_COPY,
    RATELPROF_DOMAIN_KERNEL,
    RATELPROF_DOMAIN_BARRIERAND,
    RATELPROF_DOMAIN_BARRIEROR,
    RATELPROF_NB_DOMAIN_EXT,    /**< Total number including extensions */
    RATELPROF_DOMAIN_GPU        // Not realy a domain, used to initialize GPU API table.
} ratelprof_domain_ext_t;

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
        int32_t engine_id;
    } mem_copy;
} gpu_args_t;

typedef struct ratelprof_gpu_activity_s {
    ratelprof_domain_ext_t domain;
    ratelprof_phase_t phase;
    uint64_t id;
    uint64_t corr_id;
    uint64_t start_time;
    uint64_t stop_time;
    hsa_signal_t completion_signal;
    hsa_signal_t proxy_signal;
    gpu_args_t args;
    
} ratelprof_gpu_activity_t;

#include "domains/fun_proto/gpu_hsa_traced_functions.h"
#include "domains/fun_proto/prof_hsa_traced_functions.h"
#include "ratelprof_ext/ratelprof_ompt.h"

const char* get_kernel_name(uint64_t kernel_object);
const char* ratelprof_ext_get_domain_name(ratelprof_domain_t domain);
const char* ratelprof_ext_get_domain_desc(ratelprof_domain_t domain);

ratelprof_status_t ratelprof_enable_barrier_dispatch_profiling();
ratelprof_status_t ratelprof_enable_kernel_dispatch_profiling();
ratelprof_status_t ratelprof_enable_memcpy_profiling();
ratelprof_status_t ratelprof_populate_gpu_api_table();

ratelprof_status_t ratelprof_enable_profiling_table();
ratelprof_status_t ratelprof_populate_profiling_table();

ratelprof_status_t ratelprof_ext_init();
ratelprof_status_t ratelprof_ext_fini();

#endif // RATELPROF_EXT_H
