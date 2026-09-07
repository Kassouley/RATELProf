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
#include "domains/memory_op_helper.h"


#include "ratelprof_version.h"

#define RATELPROF_DOMAIN_MEMORY_NAME        "RATELPROF_DOMAIN_MEMORY"
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
    RATELPROF_DOMAIN_MEMORY,
    RATELPROF_DOMAIN_KERNEL,
    RATELPROF_DOMAIN_BARRIERAND,
    RATELPROF_DOMAIN_BARRIEROR,
    RATELPROF_NB_DOMAIN_EXT,    /**< Total number including extensions */
    RATELPROF_DOMAIN_GPU        // Not realy a domain, used to initialize GPU API table.
} ratelprof_domain_ext_t;


typedef struct copy_args_s {
    hsa_agent_t src_agent;
    hsa_agent_t dst_agent;
    size_t size;
} copy_args_t;

typedef struct fill_args_s {
    uint8_t* pattern;
    uint32_t pattern_size;
    size_t size;
} fill_args_t;


typedef struct kernel_args_s {
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
} kernel_args_t;


typedef struct barrier_args_s {
    hsa_signal_t dep_signal[5];
} barrier_args_t;

typedef struct dispatch_args_s {
    ratelprof_clock_t dispatch_time;
    hsa_agent_t agent;
    uint64_t queue_id;
    union {
        kernel_args_t kernel;
        barrier_args_t barrier;
    };
} dispatch_args_t;


typedef struct memory_args_s {
    ratelprof_memory_op_t memop;
    union {
        copy_args_t copy;
        fill_args_t fill;
    };
    union {
        uint32_t engine_id;
        dispatch_args_t blit;
    };
} memory_args_t;


typedef union gpu_args_s {
    union {
        dispatch_args_t dispatch;
        memory_args_t memory;
    };
} gpu_args_t;


typedef struct ratelprof_gpu_activity_s {
    ratelprof_domain_ext_t domain;
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
	uint64_t tid;
	uint64_t pid;
    uint64_t id;
    uint64_t corr_id;
    bool has_children;
    ratelprof_clock_t start_time;
    ratelprof_clock_t stop_time;
    void * return_address;
    const char* message;
} ratelprof_roctx_activity_t;

typedef bool (*gpu_callback_t)(hsa_signal_value_t, void*);

#include "utils/utils.h"
#include "domains/fun_proto/gpu_hsa_traced_functions.h"
#include "domains/fun_proto/prof_hsa_traced_functions.h"
#include "domains/fun_proto/roctx_traced_functions.h"


const char* get_kernel_name(uint64_t kernel_object);
char* get_copy_name(uint32_t src_type, uint32_t dst_type);
ratelprof_status_t ratelprof_enable_node_id_tracking();

#endif // RATELPROF_EXT_H
