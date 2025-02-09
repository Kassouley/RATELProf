#include <ratelprof.h>
#include "ratelprof_ext/ratelprof_object_tracking.h"

ratelprof_object_tracking_pool_t* object_tracking_pool = NULL;



ratelprof_status_t 
ratelprof_object_tracking_pool_init()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    uint32_t max_queues_av = envtoi("RATELPROF_MAX_QUEUE_AVAILABLE", 256);
    uint32_t nb_kernels_av = envtoi("RATELPROF_NB_KERNEL_AVAILABLE", 256);

    object_tracking_pool = (ratelprof_object_tracking_pool_t*)malloc(sizeof(ratelprof_object_tracking_pool_t));
    if (!object_tracking_pool) return RATELPROF_STATUS_MALLOC_FAILED;
    RATELPROF_TRY(ratelprof_hashtable_init(&object_tracking_pool->agent_queueId_map, max_queues_av));
    RATELPROF_TRY(ratelprof_hashtable_init(&object_tracking_pool->queue_doorbell_map, max_queues_av));
    RATELPROF_TRY(ratelprof_hashtable_init(&object_tracking_pool->kernelName_kernelObj_map, nb_kernels_av));
    return status;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_fini()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    RATELPROF_TRY(ratelprof_hashtable_free(&object_tracking_pool->agent_queueId_map));
    RATELPROF_TRY(ratelprof_hashtable_free(&object_tracking_pool->queue_doorbell_map));
    RATELPROF_TRY(ratelprof_hashtable_free(&object_tracking_pool->kernelName_kernelObj_map));
    if (object_tracking_pool->agents_list) free(object_tracking_pool->agents_list);
    return RATELPROF_STATUS_SUCCESS;
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
    hsa_agent_t* agent_ptr = (hsa_agent_t*) malloc(sizeof(hsa_agent_t));
    if (!agent_ptr) return RATELPROF_STATUS_MALLOC_FAILED;
    *agent_ptr = agent;
    return ratelprof_insert_hash(&object_tracking_pool->agent_queueId_map, id, agent_ptr);
}

ratelprof_status_t 
ratelprof_object_tracking_pool_get_agent_from_queue(uint64_t id, 
                                                    hsa_agent_t* agent)
{
    return ratelprof_find_hash(&object_tracking_pool->agent_queueId_map, id, (void*)agent);
}

ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_queue(uint64_t sig, 
                                             hsa_queue_t queue)
{
    hsa_queue_t* queue_ptr = (hsa_queue_t*) malloc(sizeof(hsa_queue_t));
    if (!queue_ptr) return RATELPROF_STATUS_MALLOC_FAILED;
    *queue_ptr = queue;
    return ratelprof_insert_hash(&object_tracking_pool->queue_doorbell_map, sig, queue_ptr); 
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
    char* kernel_name_copy = (char*)malloc(strlen(kernel_name) + 1);
    if (!kernel_name_copy) return RATELPROF_STATUS_MALLOC_FAILED;
    strcpy(kernel_name_copy, kernel_name);
    return ratelprof_insert_hash(&object_tracking_pool->kernelName_kernelObj_map, kernel_object, kernel_name_copy);
}

ratelprof_status_t 
ratelprof_object_tracking_pool_get_kernelName_from_kernelObj(uint64_t kernel_object, 
                                                             const char** kernel_name)
{
    return ratelprof_find_hash(&object_tracking_pool->kernelName_kernelObj_map, kernel_object, (void*)kernel_name);
}
