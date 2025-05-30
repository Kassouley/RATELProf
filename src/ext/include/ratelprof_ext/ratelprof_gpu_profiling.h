#ifndef RATELPROF_GPU_PROFILING_H
#define RATELPROF_GPU_PROFILING_H

#include <hsa/hsa.h>
#include <hsa/amd_hsa_signal.h>
#include <ratelprof.h>

#include "ratelprof_ext.h"

#include "ratelprof_ext/ratelprof_activity_pool.h"
#include "ratelprof_ext/ratelprof_gpu_profiling.h"

#include "domains/fun_proto/prof_hsa_traced_functions.h"

#define CALL_PROF_FUNC(func, ...) ((__##func##_t)profiling_table.api_ptr[PROFILING_ID_##func])(__VA_ARGS__)

static inline ratelprof_status_t ratelprof_intercept_copy(
    hsa_agent_t dst_agent, 
    hsa_agent_t src_agent, 
    size_t size,
    hsa_signal_t* completion_signal, 
    hsa_amd_sdma_engine_id_t engine_id) 
    __attribute__((always_inline));

static inline ratelprof_status_t ratelprof_create_kernel_dispatch_activity(
    hsa_kernel_dispatch_packet_t* packet, 
    uint64_t queue_id) 
    __attribute__((always_inline));

static inline ratelprof_status_t ratelprof_create_barrier_dispatch_activity(
    void* packet, 
    uint64_t queue_id, 
    ratelprof_domain_ext_t domain) 
    __attribute__((always_inline));

static inline ratelprof_status_t ratelprof_intercept_dispatch(
    hsa_signal_t signal, 
    hsa_signal_value_t value) 
    __attribute__((always_inline));

static inline ratelprof_status_t ratelprof_intercept_queue_object(
    hsa_agent_t agent, 
    hsa_queue_t** queue) 
    __attribute__((always_inline));

static inline ratelprof_status_t ratelprof_intercept_kernel_object(
    const char* symbol_name,  
    hsa_executable_symbol_t* symbol) 
    __attribute__((always_inline));

static inline ratelprof_status_t ratelprof_intercept_agent_object() 
    __attribute__((always_inline));

static inline void ratelprof_create_proxy_signal(
    hsa_signal_t* signal) 
    __attribute__((always_inline));

static inline void ratelprof_destroy_proxy_signal(
    hsa_signal_t signal) 
    __attribute__((always_inline));

static inline void ratelprof_refresh_original_signal(
    hsa_signal_t original, 
    hsa_signal_t proxy, 
    hsa_signal_value_t value) 
    __attribute__((always_inline));

static inline void ratelprof_set_signal_handler(
    hsa_signal_t signal, 
    hsa_amd_signal_handler handler, 
    void* arg) 
    __attribute__((always_inline));


/**
 * The above functions are related to managing signals in the profiling system, including creating proxy
 * signals, refreshing original signals, and setting signal handlers.
 */
static inline void ratelprof_create_proxy_signal(hsa_signal_t* signal) {
    CALL_PROF_FUNC(hsa_signal_create, 1, 0, NULL, signal);
}

static inline void ratelprof_destroy_proxy_signal(hsa_signal_t signal) {
    CALL_PROF_FUNC(hsa_signal_destroy, signal);
}

static inline void ratelprof_refresh_original_signal(hsa_signal_t original, hsa_signal_t proxy, hsa_signal_value_t value) {
    if (original.handle && proxy.handle && original.handle != proxy.handle ) {
        amd_signal_t* original_signal_ptr = (amd_signal_t*)(original.handle);
        amd_signal_t* proxy_signal_ptr = (amd_signal_t*)(proxy.handle);
        original_signal_ptr->start_ts = proxy_signal_ptr->start_ts;
        original_signal_ptr->end_ts = proxy_signal_ptr->end_ts;
        CALL_PROF_FUNC(hsa_signal_store_screlease, original, value);
    }
    if (original.handle != proxy.handle)
        ratelprof_destroy_proxy_signal(proxy);
};

static inline void ratelprof_set_signal_handler(hsa_signal_t signal, hsa_amd_signal_handler handler, void *arg) {
    hsa_status_t status = CALL_PROF_FUNC(hsa_amd_signal_async_handler, signal, HSA_SIGNAL_CONDITION_LT, 1, handler, arg);
    if (status != HSA_STATUS_SUCCESS) {
        LOG(LOG_LEVEL_ERROR, "Failed to set async handler: hsa error(%d)\n", status);
    }
}


/**
 * The above functions are related to intercepting and profiling memory copy operations on a GPU.
 */

static inline bool __copy_callback_function(hsa_signal_value_t value, void* arg)
{
    ratelprof_gpu_activity_t* activity = (ratelprof_gpu_activity_t*) arg;
    
    CALL_PROF_FUNC(hsa_agent_get_info, activity->args.mem_copy.src_agent, HSA_AGENT_INFO_DEVICE, &activity->args.mem_copy.src_type);
    CALL_PROF_FUNC(hsa_agent_get_info, activity->args.mem_copy.dst_agent, HSA_AGENT_INFO_DEVICE, &activity->args.mem_copy.dst_type);
    
    hsa_amd_profiling_async_copy_time_t copy_time;
    hsa_status_t status = CALL_PROF_FUNC(hsa_amd_profiling_get_async_copy_time, activity->proxy_signal, &copy_time);
    if (status == HSA_STATUS_SUCCESS) {
        activity->start_time = copy_time.start;
        activity->stop_time = copy_time.end;
    } else {
        LOG(LOG_LEVEL_WARN, 
            "Failed to get copy time for activity ID %d (Domain %d) : "
            "HSA error(%d) : Signal(%lu) : Proxy(%lu) : Signal Value (%lu)\n", 
            activity->id, activity->domain, status, activity->completion_signal.handle, activity->proxy_signal.handle, value);
        activity->start_time = 0;
        activity->stop_time = 0;
    }
    
    ratelprof_refresh_original_signal(activity->completion_signal, activity->proxy_signal, value);
    return false;
}


static inline ratelprof_status_t ratelprof_intercept_copy(hsa_agent_t dst_agent, 
                                            hsa_agent_t src_agent, 
                                            size_t size,
                                            hsa_signal_t* completion_signal, 
                                            hsa_amd_sdma_engine_id_t engine_id) {
    ratelprof_gpu_activity_t* activity = calloc(1, sizeof(ratelprof_gpu_activity_t));
    if (!activity) {
        LOG(LOG_LEVEL_FATAL, "Cannot allocate a new activity. Out of memory ?\n");
    }
    ratelprof_activity_pool_push_activity(activity);

    get_correlation_id(&activity->corr_id);
    get_id(&activity->id);
    activity->phase                   = ratelprof_get_current_phase();
    activity->domain                  = RATELPROF_DOMAIN_COPY;
    activity->completion_signal       = *completion_signal;
    activity->args.mem_copy.src_agent = src_agent;
    activity->args.mem_copy.dst_agent = dst_agent;
    activity->args.mem_copy.size      = size;
    activity->args.mem_copy.engine_id = engine_id;
    pop_id();

    ratelprof_create_proxy_signal(&activity->proxy_signal);
    *completion_signal = activity->proxy_signal;
    ratelprof_set_signal_handler(*completion_signal, __copy_callback_function, activity);

    return RATELPROF_STATUS_SUCCESS;
};


/**
 * The above functions are used to create and handle GPU activity dispatch events for kernel and
 * barrier packets in a profiling tool.
 */
static inline bool __dispatch_callback_function(hsa_signal_value_t value, void* arg)
{
    ratelprof_gpu_activity_t* activity = (ratelprof_gpu_activity_t*) arg;
    
    hsa_amd_profiling_dispatch_time_t dispatch_time;
    hsa_status_t status = CALL_PROF_FUNC(hsa_amd_profiling_get_dispatch_time, activity->args.dispatch.agent, activity->proxy_signal, &dispatch_time);
    if (status == HSA_STATUS_SUCCESS) {
        activity->start_time = dispatch_time.start;
        activity->stop_time = dispatch_time.end;
    } else {
        LOG(LOG_LEVEL_WARN, "Failed to get dispatch time for activity ID %d (Domain %d) : HSA error(%d)\n", activity->id, activity->domain, status);
        activity->start_time = 0;
        activity->stop_time = 0;
    }

    ratelprof_refresh_original_signal(activity->completion_signal, activity->proxy_signal, value);
    return false;
}

static inline ratelprof_status_t ratelprof_create_kernel_dispatch_activity(hsa_kernel_dispatch_packet_t* packet, uint64_t queue_id) {
    ratelprof_gpu_activity_t* activity = calloc(1, sizeof(ratelprof_gpu_activity_t));
    if (!activity) {
        LOG(LOG_LEVEL_FATAL, "Cannot allocate a new activity. Out of memory ?\n");
    }
    ratelprof_activity_pool_push_activity(activity);

    hsa_agent_t*  agent         = NULL;

    RATELPROF_TRY(
        ratelprof_object_tracking_pool_get_agent_from_queue(queue_id, (void*)&agent),
        LOG(LOG_LEVEL_FATAL, "Cannot retrieve agent object from queue id. This error would lead to a segfault.\n");
    );

    get_correlation_id(&activity->corr_id);
    get_id(&activity->id);

    activity->phase                                     = ratelprof_get_current_phase();
    activity->args.dispatch.agent                       = *agent;
    activity->args.dispatch.queue_id                    = queue_id;
    activity->domain                                    = RATELPROF_DOMAIN_KERNEL;
    activity->args.dispatch.kernel.workgroup_size_x     = packet->workgroup_size_x;
    activity->args.dispatch.kernel.workgroup_size_y     = packet->workgroup_size_y;
    activity->args.dispatch.kernel.workgroup_size_z     = packet->workgroup_size_z;
    activity->args.dispatch.kernel.grid_size_x          = packet->grid_size_x;
    activity->args.dispatch.kernel.grid_size_y          = packet->grid_size_y;
    activity->args.dispatch.kernel.grid_size_z          = packet->grid_size_z;
    activity->args.dispatch.kernel.private_segment_size = packet->private_segment_size;
    activity->args.dispatch.kernel.group_segment_size   = packet->group_segment_size;
    activity->args.dispatch.kernel.kernel_object        = packet->kernel_object;
    activity->args.dispatch.kernel.kernarg_address      = packet->kernarg_address;
    activity->completion_signal                         = packet->completion_signal;

    ratelprof_create_proxy_signal(&activity->proxy_signal);
    packet->completion_signal = activity->proxy_signal;

    ratelprof_set_signal_handler(activity->proxy_signal, __dispatch_callback_function, activity);

    pop_id();
    activity->args.dispatch.dispatch_time = ratelprof_get_curr_timespec();
    return RATELPROF_STATUS_SUCCESS;
}


static inline ratelprof_status_t ratelprof_create_barrier_dispatch_activity(void* packet, uint64_t queue_id, ratelprof_domain_ext_t domain) {
    ratelprof_gpu_activity_t* activity = calloc(1, sizeof(ratelprof_gpu_activity_t));
    if (!activity) {
        LOG(LOG_LEVEL_FATAL, "Cannot allocate a new activity. Out of memory ?\n");
    }
    ratelprof_activity_pool_push_activity(activity);

    hsa_signal_t* packet_signal = NULL;
    hsa_agent_t*  agent         = NULL;

    RATELPROF_TRY(
        ratelprof_object_tracking_pool_get_agent_from_queue(queue_id, (void*)&agent),
        LOG(LOG_LEVEL_FATAL, "Cannot retrieve agent object from queue id. This error would lead to a segfault.\n");
    );

    get_correlation_id(&activity->corr_id);
    get_id(&activity->id);

    activity->phase                  = ratelprof_get_current_phase();
    activity->args.dispatch.agent    = *agent;
    activity->args.dispatch.queue_id = queue_id;
    activity->domain                 = domain;

    if (domain == RATELPROF_DOMAIN_BARRIERAND) {
        hsa_barrier_and_packet_t* and_packet = (hsa_barrier_and_packet_t*)packet;
        packet_signal = &and_packet->completion_signal;
        memcpy(activity->args.dispatch.barrier.dep_signal, and_packet->dep_signal, 5);
    } else if (domain == RATELPROF_DOMAIN_BARRIEROR) {
        hsa_barrier_or_packet_t* or_packet = (hsa_barrier_or_packet_t*)packet;
        packet_signal = &or_packet->completion_signal;
        memcpy(activity->args.dispatch.barrier.dep_signal, or_packet->dep_signal, 5);
    } else {
        LOG(LOG_LEVEL_FATAL, "Unknown packet type for barrier dispatch activity. (shouldn't reach here)\n");
    }
   
    // TODO 03/05/2025 : Fix barrier dispatch interception. 
    // Don't work for some application (e.g AMR WIND)
    activity->completion_signal = *packet_signal;

    if (packet_signal->handle == 0) {
        ratelprof_create_proxy_signal(&activity->proxy_signal);
        *packet_signal = activity->proxy_signal;
    } else {
        activity->proxy_signal = *packet_signal;
    }
    ratelprof_set_signal_handler(activity->proxy_signal, __dispatch_callback_function, activity);
    
    pop_id();
    activity->args.dispatch.dispatch_time = ratelprof_get_curr_timespec();
    return RATELPROF_STATUS_SUCCESS;
}


static inline ratelprof_status_t ratelprof_intercept_dispatch(hsa_signal_t signal, hsa_signal_value_t value) {
    hsa_queue_t*  queue = NULL;
    ratelprof_status_t s = ratelprof_object_tracking_pool_get_queue_from_signal(signal.handle, &queue);
    if (s == RATELPROF_STATUS_SUCCESS) {
        hsa_kernel_dispatch_packet_t* packets = (hsa_kernel_dispatch_packet_t*) queue->base_address;
        hsa_kernel_dispatch_packet_t* packet = (hsa_kernel_dispatch_packet_t*)(packets + value % queue->size);
        int packet_type = (packet->header & ((1 << HSA_PACKET_HEADER_WIDTH_TYPE) - 1));

        if (packet_type == HSA_PACKET_TYPE_KERNEL_DISPATCH    && ratelprof_object_tracking_is_kernel_packet_tracked()) {
            ratelprof_create_kernel_dispatch_activity(packet, queue->id);
        } else if (packet_type == HSA_PACKET_TYPE_BARRIER_AND && ratelprof_object_tracking_is_barrier_packet_tracked()) {
            ratelprof_create_barrier_dispatch_activity(packet, queue->id, RATELPROF_DOMAIN_BARRIERAND);
        } else if (packet_type == HSA_PACKET_TYPE_BARRIER_OR  && ratelprof_object_tracking_is_barrier_packet_tracked()) {
            ratelprof_create_barrier_dispatch_activity(packet, queue->id, RATELPROF_DOMAIN_BARRIEROR);
        } else if (packet_type != HSA_PACKET_TYPE_KERNEL_DISPATCH
                && packet_type != HSA_PACKET_TYPE_BARRIER_OR
                && packet_type != HSA_PACKET_TYPE_BARRIER_AND) {
            LOG(LOG_LEVEL_WARN, "An unknown packet (type %d) has been enqueue onto the AQL Queue.\n", packet_type);
        }
    }
    return RATELPROF_STATUS_SUCCESS;
}


/**
 * The above function is used to intercept and track queue object.
 */
static inline ratelprof_status_t ratelprof_intercept_queue_object(hsa_agent_t agent, hsa_queue_t ** queue) {
    CALL_PROF_FUNC(hsa_amd_profiling_set_profiler_enabled, *queue, 1);
    RATELPROF_TRY(
        ratelprof_object_tracking_pool_map_new_agent((*queue)->id, agent),
        LOG(LOG_LEVEL_FATAL, "Failed to intercept queue object.\n");
    );
    RATELPROF_TRY(
        ratelprof_object_tracking_pool_map_new_queue((*queue)->doorbell_signal.handle, **queue),
        LOG(LOG_LEVEL_FATAL, "Failed to intercept queue object.\n");
    );
    return RATELPROF_STATUS_SUCCESS;
}


/**
 * The above function is used to intercept and track kernel object with their name.
 */
static inline ratelprof_status_t ratelprof_intercept_kernel_object(const char * symbol_name,  hsa_executable_symbol_t * symbol) {
    uint64_t kernel_object; 
    CALL_PROF_FUNC(hsa_executable_symbol_get_info, *symbol, HSA_EXECUTABLE_SYMBOL_INFO_KERNEL_OBJECT, &kernel_object);
    RATELPROF_TRY(
        ratelprof_object_tracking_pool_map_new_kernelName(kernel_object, symbol_name),
        LOG(LOG_LEVEL_FATAL, "Failed to intercept kernel object : '%s'.\n", symbol_name);
    );
    return RATELPROF_STATUS_SUCCESS;
}


/**
 * The above functions are used to iterate through HSA agents, count them, and store them in a list for
 * object tracking purposes.
 */
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

static inline ratelprof_status_t ratelprof_intercept_agent_object() {
    size_t counter = 0;
    CALL_PROF_FUNC(hsa_iterate_agents, __count_agents, &counter);
    if (counter != 0)
    {
        ratelprof_object_tracking_pool_t* pool = ratelprof_object_tracking_pool_get_pool();
        pool->agents_count = counter;
        pool->agents_list = (ratelprof_agent_object_t*) malloc(counter * sizeof(ratelprof_agent_object_t));
        if (!pool->agents_list) {
            LOG(LOG_LEVEL_FATAL, "Cannot allocate a agent list. Out of memory ?\n");
        }
        CALL_PROF_FUNC(hsa_iterate_agents, __store_agents, pool->agents_list);
    } else {
        LOG(LOG_LEVEL_WARN, "Agent counter is 0 but shouldn't.\n");
    }
    return RATELPROF_STATUS_SUCCESS;
}
#endif // RATELPROF_GPU_PROFILING_H
