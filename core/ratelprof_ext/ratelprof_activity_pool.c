#include "ratelprof.h"
#include "ratelprof_ext.h"
#include "ratelprof_activity_pool.h"

ratelprof_activity_pool_t* activity_pool = NULL;

ratelprof_status_t 
ratelprof_activity_pool_init(ratelprof_pool_properties_t* prop)
{
    activity_pool = (ratelprof_activity_pool_t*)malloc(sizeof(ratelprof_activity_pool_t));
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_init(&activity_pool->agent_queueId_map, 4*2048));
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_init(&activity_pool->queue_doorbell_map, 4*2048));
    CHECK_RATELPROF_CALL(
        ratelprof_queue_init(&activity_pool->gpu_activities, 4*2048));
    CHECK_RATELPROF_CALL(
        ratelprof_queue_init(&activity_pool->hip_activities, 4*2048));
    CHECK_RATELPROF_CALL(
        ratelprof_queue_init(&activity_pool->hsa_activities, 4*2048));

    memcpy(&activity_pool->prop, prop, sizeof(ratelprof_pool_properties_t));
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
                                    hsa_queue_t* queue)
{
    return ratelprof_insert_hash(&activity_pool->queue_doorbell_map, sig, queue); 
}

ratelprof_status_t 
ratelprof_activity_pool_get_queue_from_signal(uint64_t sig, 
                                            hsa_queue_t** queue)
{
    ratelprof_status_t t = ratelprof_find_hash(&activity_pool->queue_doorbell_map, sig, (void**)queue);
    return t;
}

ratelprof_status_t 
ratelprof_activity_pool_push_gpu_activity(ratelprof_gpu_activity_t* activity)
{
    return ratelprof_queue_push(&activity_pool->gpu_activities, activity);
}

ratelprof_status_t 
ratelprof_activity_pool_push_hsa_activity(ratelprof_hsa_api_activity_t* activity)
{
    return ratelprof_queue_push(&activity_pool->hsa_activities, activity);
}

ratelprof_status_t 
ratelprof_activity_pool_push_hip_activity(ratelprof_hip_api_activity_t* activity)
{
    return ratelprof_queue_push(&activity_pool->hip_activities, activity);
}

ratelprof_activity_pool_t* 
ratelprof_get_activity_pool()
{
    return activity_pool;
}

ratelprof_status_t 
ratelprof_activity_pool_flush_activities() //BETA
{
    ratelprof_activity_pool_flush_hip_activities();
    ratelprof_activity_pool_flush_hsa_activities();
    ratelprof_activity_pool_flush_gpu_activities();
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t 
ratelprof_activity_pool_flush_hsa_activities()
{
    if (activity_pool->prop.hsa_activity_callback == NULL) {
        fprintf(stderr, "No HSA activity callback has been set.\n");
        exit(EXIT_FAILURE);
    }
    while(!ratelprof_queue_is_empty(&activity_pool->hsa_activities)) {
        ratelprof_hsa_api_activity_t* activity = NULL;
        CHECK_RATELPROF_CALL(
            ratelprof_queue_pop(&activity_pool->hsa_activities, (void*)&activity));
        activity_pool->prop.hsa_activity_callback(activity, activity_pool->prop.hsa_activity_callback_user_args);
    }
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t 
ratelprof_activity_pool_flush_hip_activities()
{
    if (activity_pool->prop.hip_activity_callback == NULL) {
        fprintf(stderr, "No HIP activity callback has been set.\n");
        exit(EXIT_FAILURE);
    }
    while(!ratelprof_queue_is_empty(&activity_pool->hip_activities)) {
        ratelprof_hip_api_activity_t* activity = NULL;
        CHECK_RATELPROF_CALL(
            ratelprof_queue_pop(&activity_pool->hip_activities, (void*)&activity));
        activity_pool->prop.hip_activity_callback(activity, activity_pool->prop.hip_activity_callback_user_args);
    }
    return RATELPROF_STATUS_SUCCESS;
}


ratelprof_status_t 
ratelprof_activity_pool_flush_gpu_activities() //BETA
{
    if (activity_pool->prop.gpu_activity_callback == NULL) {
        fprintf(stderr, "No GPU activity callback has been set.\n");
        exit(EXIT_FAILURE);
    }

    while(!ratelprof_queue_is_empty(&activity_pool->gpu_activities)) {
        ratelprof_gpu_activity_t* activity = NULL;
        hsa_amd_profiling_async_copy_time_t copy_time;
        hsa_amd_profiling_dispatch_time_t dispatch_time;
        hsa_agent_t* agent = NULL;

        CHECK_RATELPROF_CALL(
            ratelprof_queue_pop(&activity_pool->gpu_activities, (void*)&activity));
        switch (activity->op)
        {
            case RATELPROF_KERNEL_OPERATION:
            case RATELPROF_BARRIERAND_OPERATION:
            case RATELPROF_BARRIEROR_OPERATION:
                CHECK_RATELPROF_CALL(
                    ratelprof_activity_pool_get_agent_from_queue(activity->args.kernel_launch.queue_id, (void*)&agent));
                if (hsa_amd_profiling_get_dispatch_time(*agent, activity->completion_signal, &dispatch_time) == HSA_STATUS_SUCCESS) {
                    activity->start_time = dispatch_time.start;
                    activity->stop_time = dispatch_time.end;
                } else {
                    fprintf(stderr, "Failed to get dispatch time\n");
                }
                break;
            case RATELPROF_COPY_OPERATION:
                if (hsa_amd_profiling_get_async_copy_time(activity->completion_signal, &copy_time) == HSA_STATUS_SUCCESS) {
                    activity->start_time = copy_time.start;
                    activity->stop_time = copy_time.end;
                } else {
                    fprintf(stderr, "Failed to get copy time\n");
                }
                break;
            
            default:
                break;
        }
        activity_pool->prop.gpu_activity_callback(activity, activity_pool->prop.gpu_activity_callback_user_args);
    }
    
    return RATELPROF_STATUS_SUCCESS;
}

    