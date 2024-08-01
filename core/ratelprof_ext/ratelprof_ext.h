#ifndef RATELPROF_EXT_H
#define RATELPROF_EXT_H

#include "ratelprof.h"
#include "ratelprof_status.h"

typedef enum {
    RATELPROF_COPY_OPERATION,
    RATELPROF_KERNEL_OPERATION,
    RATELPROF_BARRIEROR_OPERATION,
    RATELPROF_BARRIERAND_OPERATION
} ratelprof_gpu_op_t;

typedef struct ratelprof_gpu_activity_s {
    ratelprof_gpu_op_t gpu_operation;
    uint64_t corrId;
    uint64_t queue_d;
    uint64_t gpu_id;
    hsa_signal_t completion_signal;
    union {
        struct {
            uint64_t dispatch_time;
            hsa_agent_t agent;
            uint64_t queue_id;
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
        } kernel_launch;
        struct {
            hsa_agent_t src_agent;
            hsa_agent_t dst_agent;
            size_t size;
        } mem_copy;
    };
} ratelprof_gpu_activity_t;

#include "ratelprof_memory_pool.h"

#endif // RATELPROF_EXT_H
