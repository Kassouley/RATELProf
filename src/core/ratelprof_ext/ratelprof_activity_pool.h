#ifndef RATELPROF_ACTIVITY_POOL_H
#define RATELPROF_ACTIVITY_POOL_H

#include "ratelprof.h"
#include "ratelprof_ext.h"
#include "ratelprof_hash_table.h"
#include "ratelprof_queue.h"

typedef void (*activity_callback_t)(ratelprof_domain_t domain, const void* activity, void* user_args);

typedef struct ratelprof_pool_properties_s {
    activity_callback_t activity_callback;
    void* activity_callback_user_args;
    int buffer_size;
} ratelprof_pool_properties_t;

typedef struct ratelprof_activity_pool_s {
    ratelprof_hash_table_t agent_queueId_map;
    ratelprof_hash_table_t queue_doorbell_map;
    ratelprof_hash_table_t kernelName_kernelObj_map;
    ratelprof_queue_t activities;
    ratelprof_pool_properties_t prop;
} ratelprof_activity_pool_t;

ratelprof_status_t 
ratelprof_activity_pool_init(ratelprof_pool_properties_t* prop);

ratelprof_status_t 
ratelprof_activity_pool_fini();

ratelprof_status_t 
ratelprof_activity_pool_flush_activities();

ratelprof_activity_pool_t* 
ratelprof_get_activity_pool();

ratelprof_status_t 
ratelprof_activity_pool_push_activity(void* activity);

ratelprof_status_t 
ratelprof_activity_pool_get_queue_from_signal(uint64_t sig, 
                                            hsa_queue_t** queue);

ratelprof_status_t 
ratelprof_activity_pool_map_new_queue(uint64_t sig, 
                                    hsa_queue_t queue);

ratelprof_status_t 
ratelprof_activity_pool_get_agent_from_queue(uint64_t id, 
                                           hsa_agent_t* agent);

ratelprof_status_t 
ratelprof_activity_pool_map_new_agent(uint64_t id, 
                                    hsa_agent_t agent);

                                    
ratelprof_status_t 
ratelprof_activity_pool_map_new_kernelName(uint64_t kernel_object, 
                                        const char* kernel_name);

ratelprof_status_t 
ratelprof_activity_pool_get_kernelName_from_kernelObj(uint64_t kernel_object, 
                                                const char** kernel_name);


#endif // RATELPROF_ACTIVITY_POOL_H