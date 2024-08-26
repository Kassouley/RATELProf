#ifndef RATELPROF_activity_pool_H
#define RATELPROF_activity_pool_H

#include "ratelprof.h"
#include "ratelprof_ext.h"
#include "ratelprof_hash_table.h"
#include "ratelprof_queue.h"

typedef struct ratelprof_pool_properties_s {
    void (*hsa_activity_callback)(const ratelprof_hsa_api_activity_t* activity, void* user_args);
    void (*hip_activity_callback)(const ratelprof_hip_api_activity_t* activity, void* user_args);
    void (*gpu_activity_callback)(const ratelprof_gpu_activity_t* activity, void* user_args);
    void* hsa_activity_callback_user_args;
    void* hip_activity_callback_user_args;
    void* gpu_activity_callback_user_args;
} ratelprof_pool_properties_t;

typedef struct ratelprof_activity_pool_s {
    ratelprof_hash_table_t agent_queueId_map;
    ratelprof_hash_table_t queue_doorbell_map;
    ratelprof_queue_t gpu_activities;
    ratelprof_queue_t hip_activities;
    ratelprof_queue_t hsa_activities;
    ratelprof_pool_properties_t prop;
} ratelprof_activity_pool_t;

ratelprof_status_t 
ratelprof_activity_pool_init(ratelprof_pool_properties_t* prop);

ratelprof_status_t 
ratelprof_activity_pool_flush_activities();


ratelprof_status_t 
ratelprof_activity_pool_flush_gpu_activities();
ratelprof_status_t 
ratelprof_activity_pool_flush_hip_activities();
ratelprof_status_t 
ratelprof_activity_pool_flush_hsa_activities();

ratelprof_activity_pool_t* 
ratelprof_get_activity_pool();

ratelprof_status_t 
ratelprof_activity_pool_push_gpu_activity(ratelprof_gpu_activity_t* activity);

ratelprof_status_t 
ratelprof_activity_pool_push_hsa_activity(ratelprof_hsa_api_activity_t* activity);

ratelprof_status_t 
ratelprof_activity_pool_push_hip_activity(ratelprof_hip_api_activity_t* activity);

ratelprof_status_t 
ratelprof_activity_pool_get_queue_from_signal(uint64_t sig, 
                                            hsa_queue_t** queue);

ratelprof_status_t 
ratelprof_activity_pool_map_new_queue(uint64_t sig, 
                                    hsa_queue_t* queue);

ratelprof_status_t 
ratelprof_activity_pool_get_agent_from_queue(uint64_t id, 
                                           hsa_agent_t* agent);

ratelprof_status_t 
ratelprof_activity_pool_map_new_agent(uint64_t id, 
                                    hsa_agent_t agent);

#endif // RATELPROF_activity_pool_H