#include <ratelprof.h>
#include "ratelprof_ext/ratelprof_object_tracking.h"
#include "ratelprof_ext/ratelprof_ext_status.h"
#include "memory_structure/cht.h"

static ratelprof_object_tracking_pool_t* object_tracking_pool = NULL;

bool ratelprof_object_tracking_is_kernel_packet_tracked() {
    return object_tracking_pool 
        && (object_tracking_pool->is_kernel_packet_tracked 
        || object_tracking_pool->is_memory_blit_kernel_packet_tracked);
}

bool ratelprof_object_tracking_is_barrier_packet_tracked() {
    return object_tracking_pool && object_tracking_pool->is_barrier_packet_tracked;
}

bool ratelprof_object_tracking_is_memory_blit_kernel_packet_tracked() {
    return object_tracking_pool && object_tracking_pool->is_memory_blit_kernel_packet_tracked;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_init()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    // uint32_t max_queues_av = envtoi("RATELPROF_MAX_QUEUE_AVAILABLE", 256);
    uint32_t max_agents_av = envtoi("RATELPROF_MAX_AGENT_AVAILABLE", 256);

    ratelprof_object_tracking_pool_t* otp = (ratelprof_object_tracking_pool_t*)malloc(sizeof(ratelprof_object_tracking_pool_t));
    if (!otp) return RATELPROF_STATUS_MALLOC_FAILED;

    otp->is_barrier_packet_tracked = is_set_domain("RATELPROF_DOMAIN_BARRIERAND") && is_set_domain("RATELPROF_DOMAIN_BARRIEROR");
    otp->is_kernel_packet_tracked  = is_set_domain("RATELPROF_DOMAIN_KERNEL");
    otp->is_memory_blit_kernel_packet_tracked = is_set_domain("RATELPROF_DOMAIN_MEMORY");

    #define cht_init_and_check(ptr, size) \
        ptr = cht_create(size); \
        if (!ptr) { \
            ratelprof_object_tracking_pool_fini(); \
            return RATELPROF_STATUS_OUT_OF_MEMORY; \
        }

    cht_init_and_check(otp->agents_list, max_agents_av);

    // if (otp->is_kernel_packet_tracked || otp->is_barrier_packet_tracked || otp->is_memory_blit_kernel_packet_tracked)
    // {
    //     cht_init_and_check(otp->queue_doorbell_map, max_queues_av);
    //     cht_init_and_check(otp->agent_queueId_map, max_queues_av);
    // }
    
    uint32_t n = envtoi("RATELPROF_NB_KERNEL_AVAILABLE", 256);
    if (n < 32) n = 32;
    
    if (otp->is_kernel_packet_tracked || otp->is_memory_blit_kernel_packet_tracked) {
        cht_init_and_check(otp->kernelName_kernelObj_map, n);
        cht_init_and_check(otp->memop_kernelObj_map, n);
    }

    object_tracking_pool = otp;
    return status;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_fini()
{
    ratelprof_object_tracking_pool_t* otp = object_tracking_pool;
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    if (!otp) return status;

    // if (otp->is_kernel_packet_tracked || otp->is_barrier_packet_tracked || otp->is_memory_blit_kernel_packet_tracked)
    // {
        // cht_destroy(otp->queue_doorbell_map);
        // cht_destroy(otp->agent_queueId_map);
    // }

    if (otp->is_kernel_packet_tracked || otp->is_memory_blit_kernel_packet_tracked) {
        cht_destroy(otp->kernelName_kernelObj_map, free);
        cht_destroy(otp->memop_kernelObj_map, NULL);
    }

    cht_destroy(otp->agents_list, free);
   
    free(otp);
    object_tracking_pool = NULL;

    return status;
}


ratelprof_object_tracking_pool_t*
ratelprof_object_tracking_pool_get_pool()
{
    return object_tracking_pool;
}

// ratelprof_status_t 
// ratelprof_object_tracking_pool_map_new_agent_to_queueId(
//     uint64_t id, 
//     hsa_agent_t agent
// ) {
//     ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
//     hsa_agent_t* agent_ptr = (hsa_agent_t*) malloc(sizeof(hsa_agent_t));
//     if (!agent_ptr) return RATELPROF_STATUS_MALLOC_FAILED;
//     *agent_ptr = agent;
//     RATELPROF_TRY(
//         ratelprof_insert_hash(&object_tracking_pool->agent_queueId_map, id, agent_ptr),
//         LOG(LOG_LEVEL_ERROR, "Failed to map a new agent. %s (code %d)\n", get_error_string_ext(status), status)
//     );
//     return status;
// }

// ratelprof_status_t 
// ratelprof_object_tracking_pool_get_agent_from_queueId(
//     uint64_t id, 
//     hsa_agent_t* agent
// ) {
//     ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
//     RATELPROF_TRY(
//         ratelprof_find_hash(&object_tracking_pool->agent_queueId_map, id, (void*)agent),
//         LOG(LOG_LEVEL_ERROR, "Failed to get an agent from hash table. %s (code %d)\n", get_error_string_ext(status), status)
//     );
//     return status;
// }

// ratelprof_status_t 
// ratelprof_object_tracking_pool_map_new_queue_to_signal(
//     uint64_t sig, 
//     hsa_queue_t queue
// ) {
//     ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
//     hsa_queue_t* queue_ptr = (hsa_queue_t*) malloc(sizeof(hsa_queue_t));
//     if (!queue_ptr) return RATELPROF_STATUS_MALLOC_FAILED;
//     *queue_ptr = queue;
//     RATELPROF_TRY(
//         ratelprof_insert_hash(&object_tracking_pool->queue_doorbell_map, sig, queue_ptr),
//         LOG(LOG_LEVEL_ERROR, "Failed to map a new queue. %s (code %d)\n", get_error_string_ext(status), status)
//     );
//     return status; 
// }

// ratelprof_status_t 
// ratelprof_object_tracking_pool_get_queue_from_signal(
//     uint64_t sig, 
//     hsa_queue_t** queue
// ) {
//     return ratelprof_find_hash(&object_tracking_pool->queue_doorbell_map, sig, (void**)queue);
// }

ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_kernelName_to_kernelObj(
    uint64_t kernel_object, 
    const char* kernel_name
) {
    char *kernel_name_copy = strdup(kernel_name);
    if (kernel_name_copy == NULL) return RATELPROF_STATUS_MALLOC_FAILED;

    if (cht_set(object_tracking_pool->kernelName_kernelObj_map, kernel_object, kernel_name_copy) != 0) {
        free(kernel_name_copy);
        return RATELPROF_STATUS_OUT_OF_MEMORY;
    }

    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_get_kernelName_from_kernelObj(
    uint64_t kernel_object, 
    const char** kernel_name
) {
    *kernel_name = cht_get(object_tracking_pool->kernelName_kernelObj_map, kernel_object);
    if (*kernel_name == NULL) {
        LOG(LOG_LEVEL_ERROR, "Failed to get a kernel name from hash table.\n");
        return RATELPROF_STATUS_KEY_NOT_FOUND;
    }
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t
ratelprof_object_tracking_pool_map_new_agent_to_handle(
    uint64_t handle, 
    ratelprof_agent_object_t* agent
) {
    if (cht_set(object_tracking_pool->agents_list, handle, agent) != 0) {
        return RATELPROF_STATUS_OUT_OF_MEMORY;
    }
    object_tracking_pool->nagents++;
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t
ratelprof_object_tracking_pool_get_agent_from_handle(
    uint64_t handle,
    ratelprof_agent_object_t** agent
) {
    *agent = cht_get(object_tracking_pool->agents_list, handle);
    if (*agent == NULL) {
        LOG(LOG_LEVEL_ERROR, "Failed to get a agent from hash table.\n");
        return RATELPROF_STATUS_KEY_NOT_FOUND;
    }
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t
ratelprof_object_tracking_pool_for_each_agent(
    void (*callback)(uint64_t, ratelprof_agent_object_t*, void*), 
    void *user_data
) {
    if (!object_tracking_pool || !object_tracking_pool->agents_list) {
        return RATELPROF_STATUS_INVALID_PTR;
    }

    cht_for_each(object_tracking_pool->agents_list, (void (*)(uint64_t, void*, void*))callback, user_data);
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t
ratelprof_object_tracking_pool_map_new_MemOp_to_kernelObj(
    uint64_t kernel_object, 
    ratelprof_memory_op_t memop
) {
    if (cht_set(object_tracking_pool->memop_kernelObj_map, kernel_object, (void*)memop) != 0) {
        return RATELPROF_STATUS_OUT_OF_MEMORY;
    }
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t
ratelprof_object_tracking_pool_get_MemOp_from_kernelObj(
    uint64_t kernel_object,
    ratelprof_memory_op_t* memop
) {
    *memop = (ratelprof_memory_op_t)cht_get(object_tracking_pool->memop_kernelObj_map, kernel_object);
    return RATELPROF_STATUS_SUCCESS;
}