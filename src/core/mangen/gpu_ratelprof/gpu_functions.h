#ifndef GPU_FUNCTION_H
#define GPU_FUNCTION_H

#include "ratelprof_ext.h"
#include "ratelprof_activity_pool.h"
#include "hsa/hsa.h"

bool copy_handler(hsa_signal_value_t value, void* arg);
bool kernel_handler(hsa_signal_value_t value, void* arg);

#define AGENT_INTERCEPT(__hsa_ret__, queue, agent) { \
    if (__hsa_ret__ == HSA_STATUS_SUCCESS) { \
        hsa_amd_profiling_set_profiler_enabled((*queue), 1); \
        hsa_amd_profiling_async_copy_enable(true); \
        CHECK_RATELPROF_CALL( \
            ratelprof_activity_pool_map_new_agent((*queue)->id, agent)); \
        CHECK_RATELPROF_CALL( \
            ratelprof_activity_pool_map_new_queue((*queue)->doorbell_signal.handle, **queue)); \
    } \
};

#define SYMBOL_INTERCEPT() { \
    if (__hsa_ret__ == HSA_STATUS_SUCCESS) { \
        uint64_t kernel_object; \
        hsa_executable_symbol_get_info(*symbol, HSA_EXECUTABLE_SYMBOL_INFO_KERNEL_OBJECT, &kernel_object); \
        ratelprof_activity_pool_map_new_kernelName(kernel_object, symbol_name); \
    } \
};


#define COPY_INTERCEPT() { \
    ratelprof_gpu_activity_t* copy_activity = malloc(sizeof(ratelprof_gpu_activity_t)); \
    GET_COPY_ACTIVITY_INFO(copy_activity); \
    hsa_amd_signal_async_handler(completion_signal, HSA_SIGNAL_CONDITION_EQ, 1, copy_handler, copy_activity); \
    CHECK_RATELPROF_CALL( \
        ratelprof_activity_pool_push_activity(copy_activity)); \
};

#define DISPATCH_INTERCEPT() { \
    hsa_queue_t* queue = NULL; \
    ratelprof_status_t s = ratelprof_activity_pool_get_queue_from_signal(signal.handle, &queue); \
    if (s == RATELPROF_STATUS_SUCCESS) { \
        hsa_agent_dispatch_packet_t* packets = (hsa_agent_dispatch_packet_t*) queue->base_address; \
        hsa_kernel_dispatch_packet_t* packet = (hsa_kernel_dispatch_packet_t*)(packets + value % queue->size); \
        if (packet->completion_signal.handle == 0 && \
                (packet->header & (1 << HSA_PACKET_HEADER_WIDTH_TYPE) - 1) == HSA_PACKET_TYPE_KERNEL_DISPATCH) \
            hsa_signal_create(1, 0, NULL, &packet->completion_signal); \
        ratelprof_gpu_activity_t* kernel_activity = malloc(sizeof(ratelprof_gpu_activity_t)); \
        GET_KERNEL_ACTIVITY_INFO(kernel_activity); \
        hsa_amd_signal_async_handler(packet->completion_signal, HSA_SIGNAL_CONDITION_EQ, 0, kernel_handler, kernel_activity); \
        CHECK_RATELPROF_CALL( \
            ratelprof_activity_pool_push_activity(kernel_activity)); \
    } \
};


#define GET_COPY_ACTIVITY_INFO(activity) { \
    activity->domain = RATELPROF_DOMAIN_GPU; \
    activity->op = RATELPROF_COPY_OPERATION; \
    activity->corr_id = get_correlation_id(); \
    activity->completion_signal = completion_signal; \
    activity->args.mem_copy.src_agent = src_agent; \
    activity->args.mem_copy.dst_agent = dst_agent; \
    activity->args.mem_copy.size = size; \
};

#define GET_KERNEL_ACTIVITY_INFO(activity) { \
    activity->domain = RATELPROF_DOMAIN_GPU; \
    activity->op = RATELPROF_KERNEL_OPERATION; \
    activity->completion_signal = packet->completion_signal; \
    activity->corr_id = get_correlation_id(); \
    clock_gettime(CLOCK_MONOTONIC, &activity->args.kernel_launch.dispatch_time); \
    activity->args.kernel_launch.queue_id = queue->id; \
    activity->args.kernel_launch.workgroup_size_x = packet->workgroup_size_x; \
    activity->args.kernel_launch.workgroup_size_y = packet->workgroup_size_y; \
    activity->args.kernel_launch.workgroup_size_z = packet->workgroup_size_z; \
    activity->args.kernel_launch.grid_size_x = packet->grid_size_x; \
    activity->args.kernel_launch.grid_size_y = packet->grid_size_y; \
    activity->args.kernel_launch.grid_size_z = packet->grid_size_z; \
    activity->args.kernel_launch.private_segment_size = packet->private_segment_size; \
    activity->args.kernel_launch.group_segment_size = packet->group_segment_size; \
    activity->args.kernel_launch.kernel_object = packet->kernel_object; \
    activity->args.kernel_launch.kernarg_address = packet->kernarg_address; \
};

#endif // GPU_FUNCTION_H