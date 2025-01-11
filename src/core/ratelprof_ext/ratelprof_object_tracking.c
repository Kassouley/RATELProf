#include "ratelprof.h"
#include "ratelprof_ext.h"
#include "ratelprof_object_tracking.h"

ratelprof_object_tracking_pool_t* object_tracking_pool = NULL;

ratelprof_status_t 
ratelprof_object_tracking_pool_init()
{
    uint32_t max_queues_av = get_max_queue_available() + 1;
    uint32_t nb_kernel_av = get_nb_kernel_available() + 1;

    object_tracking_pool = (ratelprof_object_tracking_pool_t*)malloc(sizeof(ratelprof_object_tracking_pool_t));
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_init(&object_tracking_pool->agent_queueId_map, max_queues_av));
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_init(&object_tracking_pool->queue_doorbell_map, max_queues_av));
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_init(&object_tracking_pool->kernelName_kernelObj_map, nb_kernel_av));
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_fini()
{
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_free(&object_tracking_pool->agent_queueId_map));
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_free(&object_tracking_pool->queue_doorbell_map));
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_free(&object_tracking_pool->kernelName_kernelObj_map));
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_agent(uint64_t id, 
                                    hsa_agent_t agent)
{
    hsa_agent_t* agent_ptr = (hsa_agent_t*) malloc(sizeof(hsa_agent_t));
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
    strcpy(kernel_name_copy, kernel_name);
    return ratelprof_insert_hash(&object_tracking_pool->kernelName_kernelObj_map, kernel_object, kernel_name_copy);
}

ratelprof_status_t 
ratelprof_object_tracking_pool_get_kernelName_from_kernelObj(uint64_t kernel_object, 
                                                const char** kernel_name)
{
    return ratelprof_find_hash(&object_tracking_pool->kernelName_kernelObj_map, kernel_object, (void*)kernel_name);
}
