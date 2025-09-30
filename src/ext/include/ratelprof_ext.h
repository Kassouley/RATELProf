#ifndef RATELPROF_EXT_H
#define RATELPROF_EXT_H

#include <stdint.h>
#include <ratelprof.h>

#include "utils/mpi_helper.h"

#include "ratelprof_ext/ratelprof_ext_status.h"
#include "ratelprof_ext/ratelprof_activity_pool.h"
#include "ratelprof_ext/ratelprof_object_tracking.h"

#include "domains/gpu_hsa_api_helper.h"
#include "domains/profiling_hsa_api_helper.h"
#include "domains/ompt_api_helper.h"
#include "domains/roctx_api_helper.h"

#define RATELPROF_DOMAIN_COPY_NAME          "RATELPROF_DOMAIN_COPY"
#define RATELPROF_DOMAIN_KERNEL_NAME        "RATELPROF_DOMAIN_KERNEL"
#define RATELPROF_DOMAIN_BARRIEROR_NAME     "RATELPROF_DOMAIN_BARRIEROR"
#define RATELPROF_DOMAIN_BARRIERAND_NAME    "RATELPROF_DOMAIN_BARRIERAND"
#define RATELPROF_DOMAIN_PROFILING_NAME     "RATELPROF_DOMAIN_PROFILING"
#define RATELPROF_DOMAIN_OMP_REGION_NAME    "RATELPROF_DOMAIN_OMP_REGION"
#define RATELPROF_DOMAIN_ROCTX_NAME         "RATELPROF_DOMAIN_ROCTX"

extern ratelprof_api_table_t gpu_api_table;
extern ratelprof_api_table_t profiling_table;
extern ratelprof_api_table_t roctx_api_table;

typedef enum {
    RATELPROF_DOMAIN_OMP_REGION = RATELPROF_NB_DOMAIN,
    RATELPROF_DOMAIN_ROCTX,
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


typedef struct ratelprof_roctx_activity_s {
    ratelprof_domain_ext_t domain;
    ratelprof_phase_t phase;
	uint64_t tid;
	uint64_t pid;
    uint64_t id;
    uint64_t corr_id;
    ratelprof_timespec_t start_time;
    ratelprof_timespec_t stop_time;
    const char* message;
} ratelprof_roctx_activity_t;

#include "domains/fun_proto/gpu_hsa_traced_functions.h"
#include "domains/fun_proto/prof_hsa_traced_functions.h"
#include "domains/fun_proto/roctx_traced_functions.h"

const char* get_kernel_name(uint64_t kernel_object);
ratelprof_status_t ratelprof_enable_node_id_tracking();

#endif // RATELPROF_EXT_H
