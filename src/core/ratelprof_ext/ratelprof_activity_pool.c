#include "ratelprof.h"
#include "ratelprof_ext.h"
#include "ratelprof_activity_pool.h"

ratelprof_activity_pool_t* activity_pool = NULL;

ratelprof_status_t 
ratelprof_activity_pool_init(ratelprof_pool_properties_t* prop)
{
    uint32_t max_queues_av = get_max_queue_available() + 1;
    uint32_t nb_kernel_av = get_nb_kernel_available() + 1;

    activity_pool = (ratelprof_activity_pool_t*)malloc(sizeof(ratelprof_activity_pool_t));
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_init(&activity_pool->agent_queueId_map, max_queues_av));
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_init(&activity_pool->queue_doorbell_map, max_queues_av));
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_init(&activity_pool->kernelName_kernelObj_map, nb_kernel_av));
    CHECK_RATELPROF_CALL(
        ratelprof_queue_init(&activity_pool->activities, prop->buffer_size));

    memcpy(&activity_pool->prop, prop, sizeof(ratelprof_pool_properties_t));
    return RATELPROF_STATUS_SUCCESS;
}


ratelprof_status_t 
ratelprof_activity_pool_fini()
{
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_free(&activity_pool->agent_queueId_map));
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_free(&activity_pool->queue_doorbell_map));
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_free(&activity_pool->kernelName_kernelObj_map));
    CHECK_RATELPROF_CALL(
        ratelprof_queue_free(&activity_pool->activities));

    free(activity_pool);
    return RATELPROF_STATUS_SUCCESS;
}


ratelprof_status_t 
ratelprof_activity_pool_map_new_agent(uint64_t id, 
                                    hsa_agent_t agent)
{
    hsa_agent_t* agent_ptr = (hsa_agent_t*) malloc(sizeof(hsa_agent_t));
    *agent_ptr = agent;
    return ratelprof_insert_hash(&activity_pool->agent_queueId_map, id, agent_ptr);
}

ratelprof_status_t 
ratelprof_activity_pool_get_agent_from_queue(uint64_t id, 
                                            hsa_agent_t* agent)
{
    return ratelprof_find_hash(&activity_pool->agent_queueId_map, id, (void*)agent);
}

ratelprof_status_t 
ratelprof_activity_pool_map_new_queue(uint64_t sig, 
                                    hsa_queue_t queue)
{
    hsa_queue_t* queue_ptr = (hsa_queue_t*) malloc(sizeof(hsa_queue_t));
    *queue_ptr = queue;
    return ratelprof_insert_hash(&activity_pool->queue_doorbell_map, sig, queue_ptr); 
}

ratelprof_status_t 
ratelprof_activity_pool_get_queue_from_signal(uint64_t sig, 
                                            hsa_queue_t** queue)
{
    // ratelprof_status_t t = ratelprof_find_hash(&activity_pool->queue_doorbell_map, sig, (void**)queue);
    // return t;
    return ratelprof_find_hash(&activity_pool->queue_doorbell_map, sig, (void**)queue);
}


ratelprof_status_t 
ratelprof_activity_pool_map_new_kernelName(uint64_t kernel_object, 
                                        const char* kernel_name)
{
    char* kernel_name_copy = (char*)malloc(strlen(kernel_name) + 1);
    strcpy(kernel_name_copy, kernel_name);
    return ratelprof_insert_hash(&activity_pool->kernelName_kernelObj_map, kernel_object, kernel_name_copy);
}

ratelprof_status_t 
ratelprof_activity_pool_get_kernelName_from_kernelObj(uint64_t kernel_object, 
                                                const char** kernel_name)
{
    return ratelprof_find_hash(&activity_pool->kernelName_kernelObj_map, kernel_object, (void*)kernel_name);
}

ratelprof_status_t 
ratelprof_activity_pool_push_activity(void* activity)
{
    return ratelprof_queue_push(&activity_pool->activities, activity);
}

ratelprof_activity_pool_t* 
ratelprof_get_activity_pool()
{
    return activity_pool;
}

ratelprof_status_t 
ratelprof_activity_pool_flush_activities()
{
    if (activity_pool->prop.activity_callback == NULL) {
        return RATELPROF_STATUS_NO_CALLBACK_SET;
    }
    while(!ratelprof_queue_is_empty(&activity_pool->activities)) {
        void* activity = NULL;
        CHECK_RATELPROF_CALL(
            ratelprof_queue_pop(&activity_pool->activities, (void*)&activity));
        ratelprof_domain_t* domain_ptr = (ratelprof_domain_t*)activity;
        activity_pool->prop.activity_callback(*domain_ptr, activity, activity_pool->prop.activity_callback_user_args);
        free(activity);
    }
    return RATELPROF_STATUS_SUCCESS;
}