#include "ratelprof.h"
#include "ratelprof_ext.h"
#include "ratelprof_memory_pool.h"

ratelprof_memory_pool_t* memory_pool = NULL;

ratelprof_status_t 
ratelprof_memory_pool_init()
{
    memory_pool = (ratelprof_memory_pool_t*)malloc(sizeof(ratelprof_memory_pool_t));
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_init(&memory_pool->agent_queueId_map, 4*2048));
    CHECK_RATELPROF_CALL(
        ratelprof_hashtable_init(&memory_pool->queue_doorbell_map, 4*2048));
    CHECK_RATELPROF_CALL(
        ratelprof_queue_init(&memory_pool->gpu_activities, 2048));
    CHECK_RATELPROF_CALL(
        ratelprof_queue_init(&memory_pool->hip_activities, 2048));
    CHECK_RATELPROF_CALL(
        ratelprof_queue_init(&memory_pool->hsa_activities, 2048));
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t 
ratelprof_memory_pool_map_new_agent(uint64_t id, 
                                    hsa_agent_t agent)
{
    hsa_agent_t* agent_ptr = (hsa_agent_t*) malloc(sizeof(hsa_agent_t));
    *agent_ptr = agent;
    return ratelprof_insert_hash(&memory_pool->agent_queueId_map, id, agent_ptr);
}

ratelprof_status_t 
ratelprof_memory_pool_get_agent_from_queue(uint64_t id, 
                                            hsa_agent_t* agent)
{
    return ratelprof_find_hash(&memory_pool->agent_queueId_map, id, (void*)agent);
}

ratelprof_status_t 
ratelprof_memory_pool_map_new_queue(uint64_t sig, 
                                    hsa_queue_t* queue)
{
    return ratelprof_insert_hash(&memory_pool->queue_doorbell_map, sig, queue); 
}

ratelprof_status_t 
ratelprof_memory_pool_get_queue_from_signal(uint64_t sig, 
                                            hsa_queue_t** queue)
{
    ratelprof_status_t t = ratelprof_find_hash(&memory_pool->queue_doorbell_map, sig, (void**)queue);
    return t;
}

ratelprof_status_t 
ratelprof_memory_pool_push_gpu_activity(ratelprof_gpu_activity_t* activity)
{
    return ratelprof_queue_push(&memory_pool->gpu_activities, activity);
}

ratelprof_status_t 
ratelprof_memory_pool_push_hsa_activity(ratelprof_hsa_api_activity_t* activity)
{
    return ratelprof_queue_push(&memory_pool->hsa_activities, activity);
}

ratelprof_status_t 
ratelprof_memory_pool_push_hip_activity(ratelprof_hip_api_activity_t* activity)
{
    return ratelprof_queue_push(&memory_pool->hip_activities, activity);
}

ratelprof_memory_pool_t* 
ratelprof_get_memory_pool()
{
    return memory_pool;
}

ratelprof_status_t 
ratelprof_memory_pool_flush_activities() //BETA
{
    ratelprof_memory_pool_flush_gpu_activities();
    ratelprof_memory_pool_flush_hip_activities();
    ratelprof_memory_pool_flush_hsa_activities();
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t 
ratelprof_memory_pool_flush_hsa_activities()
{
    while(!ratelprof_queue_is_empty(&memory_pool->hsa_activities)) {
        ratelprof_hsa_api_activity_t* activity = NULL;
        CHECK_RATELPROF_CALL(
            ratelprof_queue_pop(&memory_pool->hsa_activities, (void*)&activity));
            
        printf("%s | start : %lu | stop : %lu | duration = %lu\n", get_hsa_funame_by_id(activity->funid), 
                                                                    activity->start_time,
                                                                    activity->stop_time,
                                                                    activity->stop_time-activity->start_time );
    }
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t 
ratelprof_memory_pool_flush_hip_activities()
{
    while(!ratelprof_queue_is_empty(&memory_pool->hip_activities)) {
        ratelprof_hip_api_activity_t* activity = NULL;
        CHECK_RATELPROF_CALL(
            ratelprof_queue_pop(&memory_pool->hip_activities, (void*)&activity));
            
        printf("%s | start : %lu | stop : %lu | duration = %lu\n", get_hip_funame_by_id(activity->funid), 
                                                                    activity->start_time,
                                                                    activity->stop_time,
                                                                    activity->stop_time-activity->start_time );
    }
    return RATELPROF_STATUS_SUCCESS;
}


ratelprof_status_t 
ratelprof_memory_pool_flush_gpu_activities() //BETA
{
    while(!ratelprof_queue_is_empty(&memory_pool->gpu_activities)) {
        ratelprof_gpu_activity_t* activity = NULL;
        hsa_agent_t* agent = NULL;
        CHECK_RATELPROF_CALL(
            ratelprof_queue_pop(&memory_pool->gpu_activities, (void*)&activity));
        if (activity->gpu_operation == RATELPROF_KERNEL_OPERATION)
        {
            CHECK_RATELPROF_CALL(
                ratelprof_memory_pool_get_agent_from_queue(activity->kernel_launch.queue_id, (void*)&agent));
            hsa_amd_profiling_dispatch_time_t time;
            hsa_status_t status = hsa_amd_profiling_get_dispatch_time(*agent, activity->completion_signal, &time);
            if (status == HSA_STATUS_SUCCESS) {
                printf("Kernel | start : %lu | stop : %lu | duration : %lu\n", 
                                        time.start, 
                                        time.end,
                                        time.end - time.start);
                printf("\t\tworkgroup_size %u %u %u\n",activity->kernel_launch.workgroup_size_x, activity->kernel_launch.workgroup_size_y, activity->kernel_launch.workgroup_size_z);
                printf("\t\tgrid_size %u %u %u\n",activity->kernel_launch.grid_size_x, activity->kernel_launch.grid_size_y, activity->kernel_launch.grid_size_z);
            } else {
                fprintf(stderr, "Failed to get dispatch time %x \n",status);
            }
        } 
        else if (activity->gpu_operation == RATELPROF_COPY_OPERATION)
        {
            hsa_amd_profiling_async_copy_time_t async_copy_time;
            hsa_status_t status = hsa_amd_profiling_get_async_copy_time(activity->completion_signal, &async_copy_time);
            if (status == HSA_STATUS_SUCCESS) {
                printf("Async memory copy | start : %lu | stop : %lu | duration : %lu\n", 
                                        async_copy_time.start, 
                                        async_copy_time.end,
                                        async_copy_time.end - async_copy_time.start);
            } else {
                fprintf(stderr, "Failed to get copy time %x \n",status);
            }
        }
    }
    
    return RATELPROF_STATUS_SUCCESS;
}

    