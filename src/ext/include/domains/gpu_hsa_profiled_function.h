#ifndef GPU_SUPPORT_H
#define GPU_SUPPORT_H

#include <hsa/hsa.h>
#include <hsa/amd_hsa_signal.h>
#include <ratelprof.h>

#include "ratelprof_ext.h"
#include "domains/profiling_trace.h"
#include "ratelprof_ext/ratelprof_activity_pool.h"

typedef enum {
    GPU_API_ID_hsa_executable_get_symbol_by_name,
    GPU_API_ID_hsa_signal_store_relaxed,
    GPU_API_ID_hsa_queue_create,
    GPU_API_ID_hsa_signal_store_screlease,
    GPU_API_ID_hsa_signal_store_release,
    GPU_API_ID_hsa_amd_memory_async_copy,
    GPU_API_ID_hsa_amd_memory_async_copy_on_engine,
    GPU_API_ID_hsa_shut_down,
    GPU_API_ID_NB_FUNCTION,
    GPU_API_ID_UNKNOWN
} gpu_api_id_t;


#define CALL_PROF_FUNC(func, ...) ((__##func##_t)profiling_table.api_ptr[PROFILING_ID_##func])(__VA_ARGS__)


static inline void ratelprof_get_agent_type(hsa_agent_t agent, uint32_t* type)  __attribute__((always_inline));
static inline uint64_t ratelprof_get_kernel_obj_from_symbol(hsa_executable_symbol_t symbol)  __attribute__((always_inline)) ; 
static inline void ratelprof_init_agent_list() __attribute__((always_inline)) ;
static inline void ratelprof_enable_profiling(hsa_queue_t* queue) __attribute__((always_inline));
static inline void ratelprof_create_proxy_signal(hsa_signal_t* signal) __attribute__((always_inline));
static inline void ratelprof_destroy_proxy_signal(hsa_signal_t signal) __attribute__((always_inline));
static inline void ratelprof_refresh_original_signal(hsa_signal_t original, hsa_signal_t proxy, hsa_signal_value_t value) __attribute__((always_inline));
static inline void ratelprof_get_copy_time(ratelprof_gpu_activity_t* activity) __attribute__((always_inline));
static inline void ratelprof_get_dispatch_time(ratelprof_gpu_activity_t* activity) __attribute__((always_inline));
static inline void ratelprof_set_signal_handler(hsa_signal_t signal, hsa_amd_signal_handler handler, void *arg) __attribute__((always_inline));

static inline hsa_status_t __count_agents(hsa_agent_t agent, void* data) {
    (void)agent;
    size_t* counter = (size_t*)data;
    (*counter)++;
    return HSA_STATUS_SUCCESS;
}

static inline hsa_status_t __store_agents(hsa_agent_t agent, void* data) {
    ratelprof_agent_object_t* agent_list = (ratelprof_agent_object_t*)data;
    uint32_t node;
    CALL_PROF_FUNC(hsa_agent_get_info, agent, HSA_AGENT_INFO_NODE, &node);
    agent_list[node] = agent;
    return HSA_STATUS_SUCCESS;
}

static inline bool __copy_callback_function(hsa_signal_value_t value, void* arg)
{
    ratelprof_gpu_activity_t* activity = (ratelprof_gpu_activity_t*) arg;
    ratelprof_get_agent_type(activity->args.mem_copy.src_agent, &activity->args.mem_copy.src_type);
    ratelprof_get_agent_type(activity->args.mem_copy.dst_agent, &activity->args.mem_copy.dst_type);
    ratelprof_get_copy_time(activity);
    ratelprof_refresh_original_signal(activity->completion_signal, activity->proxy_signal, value);
    return false;
}

static inline bool __dispatch_callback_function(hsa_signal_value_t value, void* arg)
{
    ratelprof_gpu_activity_t* activity = (ratelprof_gpu_activity_t*) arg;
    ratelprof_get_dispatch_time(activity);
    ratelprof_refresh_original_signal(activity->completion_signal, activity->proxy_signal, value);
    return false;
}


static inline void ratelprof_get_agent_type(hsa_agent_t agent, uint32_t* type) {
    CALL_PROF_FUNC(hsa_agent_get_info, agent, HSA_AGENT_INFO_DEVICE, type);
}


static inline uint64_t ratelprof_get_kernel_obj_from_symbol(hsa_executable_symbol_t symbol) { 
    uint64_t kernel_object; 
    CALL_PROF_FUNC(hsa_executable_symbol_get_info, symbol, HSA_EXECUTABLE_SYMBOL_INFO_KERNEL_OBJECT, &kernel_object);
    return kernel_object; 
};


static inline void ratelprof_init_agent_list() {
    size_t counter = 0;
    CALL_PROF_FUNC(hsa_iterate_agents, __count_agents, &counter);
    if (counter != 0)
    {
        ratelprof_object_tracking_pool_t* pool = ratelprof_object_tracking_pool_get_pool();
        pool->agents_list = (ratelprof_agent_object_t*) malloc(counter * sizeof(ratelprof_agent_object_t));
        pool->agents_count = counter;
        CALL_PROF_FUNC(hsa_iterate_agents, __store_agents, pool->agents_list);
    }
};



static inline void ratelprof_enable_profiling(hsa_queue_t* queue) {
    CALL_PROF_FUNC(hsa_amd_profiling_set_profiler_enabled, queue, 1);
    CALL_PROF_FUNC(hsa_amd_profiling_async_copy_enable, true);
};


static inline void ratelprof_create_proxy_signal(hsa_signal_t* signal) {
    CALL_PROF_FUNC(hsa_signal_create, 1, 0, NULL, signal);
}


static inline void ratelprof_destroy_proxy_signal(hsa_signal_t signal) {
    CALL_PROF_FUNC(hsa_signal_destroy, signal);
}



static inline void ratelprof_refresh_original_signal(hsa_signal_t original, hsa_signal_t proxy, hsa_signal_value_t value) {
    if (original.handle) {
        amd_signal_t* original_signal_ptr = (amd_signal_t*)(original.handle);
        amd_signal_t* proxy_signal_ptr = (amd_signal_t*)(proxy.handle);
        original_signal_ptr->start_ts = proxy_signal_ptr->start_ts;
        original_signal_ptr->end_ts = proxy_signal_ptr->end_ts;
        CALL_PROF_FUNC(hsa_signal_store_screlease, original, value);
    }
    ratelprof_destroy_proxy_signal(proxy);
};




static inline void ratelprof_get_copy_time(ratelprof_gpu_activity_t* activity) {
    hsa_amd_profiling_async_copy_time_t copy_time;
    hsa_status_t status = CALL_PROF_FUNC(hsa_amd_profiling_get_async_copy_time, activity->proxy_signal, &copy_time);
    if (status == HSA_STATUS_SUCCESS) {
        activity->start_time = copy_time.start;
        activity->stop_time = copy_time.end;
    } else {
        fprintf(stderr, "RPROF: Failed to get copy time: hsa error(%d)\n", status);
        activity->start_time = 0;
        activity->stop_time = 0;
    }
}


static inline void ratelprof_get_dispatch_time(ratelprof_gpu_activity_t* activity) {
    hsa_agent_t* agent = NULL;
    CHECK_RATELPROF_CALL(ratelprof_object_tracking_pool_get_agent_from_queue(activity->args.dispatch.queue_id, (void*)&agent));
    hsa_amd_profiling_dispatch_time_t dispatch_time;
    hsa_status_t status = CALL_PROF_FUNC(hsa_amd_profiling_get_dispatch_time, *agent, activity->proxy_signal, &dispatch_time);
    if (status == HSA_STATUS_SUCCESS) {
        activity->start_time = dispatch_time.start;
        activity->stop_time = dispatch_time.end;
        activity->args.dispatch.agent = *agent;
    } else {
        fprintf(stderr, "RPROF: Failed to get dispatch time: hsa error(%d)\n", status);
        activity->start_time = 0;
        activity->stop_time = 0;
    }
}


static inline void ratelprof_set_signal_handler(hsa_signal_t signal, hsa_amd_signal_handler handler, void *arg) {
    CALL_PROF_FUNC(hsa_amd_signal_async_handler, signal, HSA_SIGNAL_CONDITION_LT, 1, handler, arg);
}


#define COPY_INTERCEPT() { \
    ratelprof_gpu_activity_t* activity = malloc(sizeof(ratelprof_gpu_activity_t)); \
    ratelprof_create_proxy_signal(&activity->proxy_signal); \
    activity->phase = ratelprof_get_current_phase(); \
    activity->domain = RATELPROF_DOMAIN_COPY; \
    get_correlation_id(&activity->corr_id); \
    get_id(&activity->id); \
    activity->completion_signal = completion_signal; \
    activity->args.mem_copy.src_agent = src_agent; \
    activity->args.mem_copy.dst_agent = dst_agent; \
    activity->args.mem_copy.size = size; \
    pop_id(); \
    completion_signal = activity->proxy_signal;\
    ratelprof_set_signal_handler(completion_signal, __copy_callback_function, activity); \
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
        ratelprof_create_proxy_signal(&activity->proxy_signal); \
        activity->phase = ratelprof_get_current_phase(); \
        get_correlation_id(&activity->corr_id); \
        get_id(&activity->id); \
        activity->args.dispatch.queue_id = queue->id; \
        pop_id(); \
        if (packet_type == HSA_PACKET_TYPE_KERNEL_DISPATCH) { \
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
        ratelprof_set_signal_handler(activity->proxy_signal, __dispatch_callback_function, activity); \
        clock_gettime(CLOCK_MONOTONIC, &activity->args.dispatch.dispatch_time); \
        CHECK_RATELPROF_CALL(ratelprof_activity_pool_push_activity(activity)); \
    } \
};

hsa_status_t i_gpu_hsa_executable_get_symbol_by_name(hsa_executable_t executable, const char * symbol_name, const hsa_agent_t * agent, hsa_executable_symbol_t * symbol);
hsa_status_t i_gpu_hsa_queue_create(hsa_agent_t agent, uint32_t size, hsa_queue_type32_t type, void (*callback)(hsa_status_t, hsa_queue_t *, void *), void * data, uint32_t private_segment_size, uint32_t group_segment_size, hsa_queue_t ** queue);
void i_gpu_hsa_signal_store_relaxed(hsa_signal_t signal, hsa_signal_value_t value);
void i_gpu_hsa_signal_store_screlease(hsa_signal_t signal, hsa_signal_value_t value);
void i_gpu_hsa_signal_store_release(hsa_signal_t signal, hsa_signal_value_t value);
hsa_status_t i_gpu_hsa_amd_memory_async_copy(void * dst, hsa_agent_t dst_agent, const void * src, hsa_agent_t src_agent, size_t size, uint32_t num_dep_signals, const hsa_signal_t * dep_signals, hsa_signal_t completion_signal);
hsa_status_t i_gpu_hsa_amd_memory_async_copy_on_engine(void * dst, hsa_agent_t dst_agent, const void * src, hsa_agent_t src_agent, size_t size, uint32_t num_dep_signals, const hsa_signal_t * dep_signals, hsa_signal_t completion_signal, hsa_amd_sdma_engine_id_t engine_id, _Bool force_copy_on_sdma);
hsa_status_t i_gpu_hsa_shut_down();


#endif // GPU_SUPPORT_H