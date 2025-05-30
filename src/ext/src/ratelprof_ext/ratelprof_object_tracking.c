#include <ratelprof.h>
#include "ratelprof_ext/ratelprof_object_tracking.h"
#include "ratelprof_ext/ratelprof_ext_status.h"

ratelprof_object_tracking_pool_t* object_tracking_pool = NULL;

bool ratelprof_object_tracking_is_kernel_packet_tracked() {
    return object_tracking_pool && object_tracking_pool->is_kernel_packet_tracked;
}

bool ratelprof_object_tracking_is_barrier_packet_tracked() {
    return object_tracking_pool && object_tracking_pool->is_barrier_packet_tracked;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_init()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    uint32_t max_queues_av = envtoi("RATELPROF_MAX_QUEUE_AVAILABLE", 256);

    object_tracking_pool = (ratelprof_object_tracking_pool_t*)malloc(sizeof(ratelprof_object_tracking_pool_t));
    if (!object_tracking_pool) return RATELPROF_STATUS_MALLOC_FAILED;

    object_tracking_pool->agents_count = 0;
    object_tracking_pool->agents_list = NULL;

    object_tracking_pool->is_barrier_packet_tracked = is_set_domain("RATELPROF_DOMAIN_BARRIERAND") && is_set_domain("RATELPROF_DOMAIN_BARRIEROR");
    object_tracking_pool->is_kernel_packet_tracked  = is_set_domain("RATELPROF_DOMAIN_KERNEL");

    if (object_tracking_pool->is_kernel_packet_tracked || object_tracking_pool->is_barrier_packet_tracked) {
        RATELPROF_TRY(
            ratelprof_hashtable_init(&object_tracking_pool->queue_doorbell_map, max_queues_av),
            LOG(LOG_LEVEL_ERROR, "Failed to init Queue/Doorbell hash table. %s (code %d)\n", get_error_string_ext(status), status)
        );
    }

    if (object_tracking_pool->is_barrier_packet_tracked) {
        RATELPROF_TRY(
            ratelprof_hashtable_init(&object_tracking_pool->agent_queueId_map, max_queues_av),
            LOG(LOG_LEVEL_ERROR, "Failed to init Agent/Queue hash table. %s (code %d)\n", get_error_string_ext(status), status)
        );
    }
    
    if (object_tracking_pool->is_kernel_packet_tracked) {
        uint32_t n = envtoi("RATELPROF_NB_KERNEL_AVAILABLE", 256);
        if (n < 32) n = 31;
        n |= (n >> 1);
        n |= (n >> 2);
        n |= (n >> 4);
        n |= (n >> 8);
        n |= (n >> 16);
        n = n + 1;
        
        RATELPROF_TRY(
            ratelprof_hashtable_init(&object_tracking_pool->kernelName_kernelObj_map, n),
            LOG(LOG_LEVEL_ERROR, "Failed to init KernelName/Object hash table. %s (code %d)\n", get_error_string_ext(status), status)
        );
        RATELPROF_TRY(
            ratelprof_hashtable_init(&object_tracking_pool->agent_queueId_map, max_queues_av),
            LOG(LOG_LEVEL_ERROR, "Failed to init Agent/Queue hash table. %s (code %d)\n", get_error_string_ext(status), status)
        );
    }
    return status;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_fini()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    if (object_tracking_pool->is_kernel_packet_tracked || object_tracking_pool->is_barrier_packet_tracked) {
        RATELPROF_TRY(
            ratelprof_hashtable_free(&object_tracking_pool->queue_doorbell_map),
            LOG(LOG_LEVEL_ERROR, "Failed to free Queue/Doorbell hash table. %s (code %d)\n", get_error_string_ext(status), status)
        );
        RATELPROF_TRY(
            ratelprof_hashtable_free(&object_tracking_pool->agent_queueId_map),
            LOG(LOG_LEVEL_ERROR, "Failed to free Agent/Queue hash table. %s (code %d)\n", get_error_string_ext(status), status)
        );
    }

    if (object_tracking_pool->is_kernel_packet_tracked) {
        RATELPROF_TRY(
            ratelprof_hashtable_free(&object_tracking_pool->kernelName_kernelObj_map),
            LOG(LOG_LEVEL_ERROR, "Failed to free KernelName/Object hash table. %s (code %d)\n", get_error_string_ext(status), status)
        );
    }

    if (object_tracking_pool->agents_list) free(object_tracking_pool->agents_list);
    return status;
}


ratelprof_object_tracking_pool_t*
ratelprof_object_tracking_pool_get_pool()
{
    return object_tracking_pool;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_agent(uint64_t id, 
                                             hsa_agent_t agent)
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    hsa_agent_t* agent_ptr = (hsa_agent_t*) malloc(sizeof(hsa_agent_t));
    if (!agent_ptr) return RATELPROF_STATUS_MALLOC_FAILED;
    *agent_ptr = agent;
    RATELPROF_TRY(
        ratelprof_insert_hash(&object_tracking_pool->agent_queueId_map, id, agent_ptr),
        LOG(LOG_LEVEL_ERROR, "Failed to map a new agent. %s (code %d)\n", get_error_string_ext(status), status)
    );
    return status;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_get_agent_from_queue(uint64_t id, 
                                                    hsa_agent_t* agent)
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    RATELPROF_TRY(
        ratelprof_find_hash(&object_tracking_pool->agent_queueId_map, id, (void*)agent),
        LOG(LOG_LEVEL_WARN, "Failed to get an agent from hash table. %s (code %d)\n", get_error_string_ext(status), status)
    );
    return status;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_queue(uint64_t sig, 
                                             hsa_queue_t queue)
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    hsa_queue_t* queue_ptr = (hsa_queue_t*) malloc(sizeof(hsa_queue_t));
    if (!queue_ptr) return RATELPROF_STATUS_MALLOC_FAILED;
    *queue_ptr = queue;
    RATELPROF_TRY(
        ratelprof_insert_hash(&object_tracking_pool->queue_doorbell_map, sig, queue_ptr),
        LOG(LOG_LEVEL_ERROR, "Failed to map a new queue. %s (code %d)\n", get_error_string_ext(status), status)
    );
    return status; 
}

ratelprof_status_t 
ratelprof_object_tracking_pool_get_queue_from_signal(uint64_t sig, 
                                                     hsa_queue_t** queue)
{
    return ratelprof_find_hash(&object_tracking_pool->queue_doorbell_map, sig, (void**)queue);
}

ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_kernelName(uint64_t kernel_object, 
                                                  const char* kernel_name)
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    char* kernel_name_copy = (char*)malloc(strlen(kernel_name) + 1);
    if (!kernel_name_copy) return RATELPROF_STATUS_MALLOC_FAILED;
    strcpy(kernel_name_copy, kernel_name);
    RATELPROF_TRY(
        ratelprof_insert_hash(&object_tracking_pool->kernelName_kernelObj_map, kernel_object, kernel_name_copy),
        LOG(LOG_LEVEL_ERROR, "Failed to map a new kernel name. %s (code %d)\n", get_error_string_ext(status), status)
    );
    return status;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_get_kernelName_from_kernelObj(uint64_t kernel_object, 
                                                             const char** kernel_name)
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    RATELPROF_TRY(
        ratelprof_find_hash(&object_tracking_pool->kernelName_kernelObj_map, kernel_object, (void*)kernel_name),
        LOG(LOG_LEVEL_WARN, "Failed to get a kernel name from hash table. %s (code %d)\n", get_error_string_ext(status), status)
    );
    return status;
}
