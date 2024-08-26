#ifndef RATELPROF_EXT_H
#define RATELPROF_EXT_H

#include "ratelprof.h"
#include "ratelprof_status.h"
#include "ratelprof_time.h"

#define RATELPROF_DOMAIN_GPU 0x1000

typedef enum {
    RATELPROF_DISPATCH_OPERATION,
    RATELPROF_COPY_OPERATION,
    RATELPROF_KERNEL_OPERATION,
    RATELPROF_BARRIEROR_OPERATION,
    RATELPROF_BARRIERAND_OPERATION,
    RATELPROF_CPU_OPERATION
} ratelprof_op_t;

typedef union gpu_args_s {
    struct {
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
} gpu_args_t;

typedef struct ratelprof_gpu_activity_s {
    ratelprof_op_t op;
    uint64_t corrId;
    uint64_t start_time;
    uint64_t stop_time;
    uint64_t gpu_id;
    hsa_signal_t completion_signal;
    gpu_args_t args;
    
} ratelprof_gpu_activity_t;

#include "ratelprof_activity_pool.h"

#endif // RATELPROF_EXT_H
