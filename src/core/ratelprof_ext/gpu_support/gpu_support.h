#ifndef GPU_SUPPORT_H
#define GPU_SUPPORT_H

#include "ratelprof_ext.h"
#include "ratelprof_activity_pool.h"
#include "hsa/hsa.h"
#include "hsa/amd_hsa_signal.h"

#define PROFILING_FUNCTION_CALL(func, ...) ((__##func##_t)profiling_table.api_ptr[PROFILING_ID_##func])(__VA_ARGS__)

#define CREATE_PROXY_SIGNAL(signal) PROFILING_FUNCTION_CALL(SIGNAL_CREATION, 1, 0, NULL, &signal)

#define DESTROY_PROXY_SIGNAL(signal) PROFILING_FUNCTION_CALL(SIGNAL_DESTRUCTION, signal)

#define REFRESH_ORIGNAL_SIGNAL(original, proxy) { \
    if (original.handle) { \
      amd_signal_t* original_signal_ptr = (amd_signal_t*)(original.handle); \
      amd_signal_t* proxy_signal_ptr = (amd_signal_t*)(proxy.handle); \
      original_signal_ptr->start_ts = proxy_signal_ptr->start_ts; \
      original_signal_ptr->end_ts = proxy_signal_ptr->end_ts; \
      PROFILING_FUNCTION_CALL(SIGNAL_REFRESH, original, value); \
    } \
    DESTROY_PROXY_SIGNAL(proxy); \
};


static inline bool __copy_callback_function(hsa_signal_value_t value, void* arg)
{
    hsa_amd_profiling_async_copy_time_t copy_time;
    ratelprof_gpu_activity_t* activity = (ratelprof_gpu_activity_t*) arg;
    PROFILING_FUNCTION_CALL(GET_AGENT_TYPE, activity->args.mem_copy.src_agent, HSA_AGENT_INFO_DEVICE, &activity->args.mem_copy.src_type);
    PROFILING_FUNCTION_CALL(GET_AGENT_TYPE, activity->args.mem_copy.dst_agent, HSA_AGENT_INFO_DEVICE, &activity->args.mem_copy.dst_type);
    hsa_status_t status = PROFILING_FUNCTION_CALL(GET_COPY_TIME, activity->proxy_signal, &copy_time);
    if (status == HSA_STATUS_SUCCESS) {
        activity->start_time = copy_time.start;
        activity->stop_time = copy_time.end;
    } else {
        fprintf(stderr, "Failed to get copy time: error(%d)\n", status);
        activity->start_time = 0;
        activity->stop_time = 0;
    }
    REFRESH_ORIGNAL_SIGNAL(activity->completion_signal, activity->proxy_signal);
    return false;
}

static inline bool __dispatch_callback_function(hsa_signal_value_t value, void* arg)
{
    hsa_agent_t* agent = NULL;
    hsa_amd_profiling_dispatch_time_t dispatch_time;
    ratelprof_gpu_activity_t* activity = (ratelprof_gpu_activity_t*) arg;
    CHECK_RATELPROF_CALL(
        ratelprof_object_tracking_pool_get_agent_from_queue(
            activity->args.dispatch.queue_id, 
            (void*)&agent));
    hsa_status_t status = PROFILING_FUNCTION_CALL(GET_DISPATCH_TIME, *agent, activity->proxy_signal, &dispatch_time);
    if (status == HSA_STATUS_SUCCESS) {
        activity->start_time = dispatch_time.start;
        activity->stop_time = dispatch_time.end;
        activity->args.dispatch.agent = *agent;
    } else {
        fprintf(stderr, "Failed to get dispatch time: error(%d)\n", status);
        activity->start_time = 0;
        activity->stop_time = 0;
    }
    REFRESH_ORIGNAL_SIGNAL(activity->completion_signal, activity->proxy_signal);
    return false;
}

#define AGENT_INTERCEPT(__hsa_ret, queue, agent) { \
    if (__hsa_ret == HSA_STATUS_SUCCESS) { \
        PROFILING_FUNCTION_CALL(ENABLE_DISPATCH_PROFILING, (*queue), 1); \
        PROFILING_FUNCTION_CALL(ENABLE_COPY_PROFILING, true); \
        CHECK_RATELPROF_CALL( \
            ratelprof_object_tracking_pool_map_new_agent((*queue)->id, agent)); \
        CHECK_RATELPROF_CALL( \
            ratelprof_object_tracking_pool_map_new_queue((*queue)->doorbell_signal.handle, **queue)); \
    } \
};

#define SYMBOL_INTERCEPT(__hsa_ret) { \
    if (__hsa_ret == HSA_STATUS_SUCCESS) { \
        uint64_t kernel_object; \
        PROFILING_FUNCTION_CALL(GET_KERNEL_NAME, *symbol, HSA_EXECUTABLE_SYMBOL_INFO_KERNEL_OBJECT, &kernel_object); \
        ratelprof_object_tracking_pool_map_new_kernelName(kernel_object, symbol_name); \
    } \
};


#define COPY_INTERCEPT() { \
    ratelprof_gpu_activity_t* activity = malloc(sizeof(ratelprof_gpu_activity_t)); \
    CREATE_PROXY_SIGNAL(activity->proxy_signal); \
    activity->phase = ratelprof_get_current_phase(); \
    activity->domain = RATELPROF_DOMAIN_COPY; \
    activity->corr_id = get_correlation_id(); \
    activity->id = push_id(); \
    activity->completion_signal = completion_signal; \
    activity->args.mem_copy.src_agent = src_agent; \
    activity->args.mem_copy.dst_agent = dst_agent; \
    activity->args.mem_copy.size = size; \
    pop_id(); \
    completion_signal = activity->proxy_signal;\
    PROFILING_FUNCTION_CALL(SET_SIGNAL_HANDLER, completion_signal, HSA_SIGNAL_CONDITION_LT, 1, __copy_callback_function, activity); \
    CHECK_RATELPROF_CALL(ratelprof_activity_pool_push_activity(activity)); \
};

#define DISPATCH_INTERCEPT() { \
    hsa_queue_t* queue = NULL; \
    ratelprof_status_t s = ratelprof_object_tracking_pool_get_queue_from_signal(signal.handle, &queue); \
    if (s == RATELPROF_STATUS_SUCCESS) { \
        hsa_kernel_dispatch_packet_t* packets = (hsa_kernel_dispatch_packet_t*) queue->base_address; \
        hsa_kernel_dispatch_packet_t* packet = (hsa_kernel_dispatch_packet_t*)(packets + value % queue->size); \
        int packet_type = (packet->header & (1 << HSA_PACKET_HEADER_WIDTH_TYPE) - 1); \
        ratelprof_gpu_activity_t* activity = malloc(sizeof(ratelprof_gpu_activity_t)); \
        \
        CREATE_PROXY_SIGNAL(activity->proxy_signal); \
        activity->phase = ratelprof_get_current_phase(); \
        activity->corr_id = get_correlation_id(); \
        activity->id = push_id(); \
        activity->args.dispatch.queue_id = queue->id; \
        pop_id(); \
        if ( packet_type == HSA_PACKET_TYPE_KERNEL_DISPATCH) { \
            hsa_kernel_dispatch_packet_t* kernel_packet = (hsa_kernel_dispatch_packet_t*) packet; \
            activity->domain = RATELPROF_DOMAIN_KERNEL; \
            activity->completion_signal = kernel_packet->completion_signal; \
            activity->args.dispatch.kernel.workgroup_size_x = kernel_packet->workgroup_size_x; \
            activity->args.dispatch.kernel.workgroup_size_y = kernel_packet->workgroup_size_y; \
            activity->args.dispatch.kernel.workgroup_size_z = kernel_packet->workgroup_size_z; \
            activity->args.dispatch.kernel.grid_size_x = kernel_packet->grid_size_x; \
            activity->args.dispatch.kernel.grid_size_y = kernel_packet->grid_size_y; \
            activity->args.dispatch.kernel.grid_size_z = kernel_packet->grid_size_z; \
            activity->args.dispatch.kernel.private_segment_size = kernel_packet->private_segment_size; \
            activity->args.dispatch.kernel.group_segment_size = kernel_packet->group_segment_size; \
            activity->args.dispatch.kernel.kernel_object = kernel_packet->kernel_object; \
            activity->args.dispatch.kernel.kernarg_address = kernel_packet->kernarg_address; \
            kernel_packet->completion_signal = activity->proxy_signal; \
        } else if (packet_type == HSA_PACKET_TYPE_BARRIER_AND) { \
            hsa_barrier_and_packet_t* barrier_and_packet = (hsa_barrier_and_packet_t*) packet; \
            activity->domain = RATELPROF_DOMAIN_BARRIERAND; \
            activity->completion_signal = barrier_and_packet->completion_signal; \
            memcpy(activity->args.dispatch.barrier.dep_signal, barrier_and_packet->dep_signal, 5); \
            barrier_and_packet->completion_signal = activity->proxy_signal; \
        } else if (packet_type == HSA_PACKET_TYPE_BARRIER_OR) { \
            hsa_barrier_or_packet_t* barrier_or_packet = (hsa_barrier_or_packet_t*) packet; \
            activity->domain = RATELPROF_DOMAIN_BARRIEROR; \
            activity->completion_signal = barrier_or_packet->completion_signal; \
            memcpy(activity->args.dispatch.barrier.dep_signal, barrier_or_packet->dep_signal, 5); \
            barrier_or_packet->completion_signal = activity->proxy_signal; \
        } else { \
            fprintf(stderr, "Fatal Error : Unknown packet type %d\n", packet_type); \
        } \
        \
        PROFILING_FUNCTION_CALL(SET_SIGNAL_HANDLER, activity->proxy_signal, HSA_SIGNAL_CONDITION_LT, 1, __dispatch_callback_function, activity); \
        clock_gettime(CLOCK_MONOTONIC, &activity->args.dispatch.dispatch_time); \
        CHECK_RATELPROF_CALL(ratelprof_activity_pool_push_activity(activity)); \
    } \
};

#endif // GPU_SUPPORT_H