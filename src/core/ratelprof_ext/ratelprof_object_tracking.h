#ifndef RATELPROF_OBJECT_TRACKING_H
#define RATELPROF_OBJECT_TRACKING_H

#include "ratelprof.h"
#include "ratelprof_ext.h"
#include "ratelprof_hash_table.h"

typedef struct {
    hsa_agent_t agent;
    char name[64];
    char vendor_name[64];
    hsa_agent_feature_t feature;
    uint32_t queues_max;
    uint32_t queue_min_size;
    uint32_t queue_max_size;
    hsa_queue_type32_t queue_type;
    hsa_device_type_t device_type;
    uint16_t version_major;
    uint16_t version_minor;
} ratelprof_agent_object_t;

typedef struct {
    ratelprof_hash_table_t agent_queueId_map;
    ratelprof_hash_table_t queue_doorbell_map;
    ratelprof_hash_table_t kernelName_kernelObj_map;
    ratelprof_agent_object_t* agent_list;
} ratelprof_object_tracking_pool_t;



ratelprof_status_t 
ratelprof_object_tracking_pool_init();

ratelprof_status_t 
ratelprof_object_tracking_pool_fini();

ratelprof_status_t 
ratelprof_object_tracking_pool_get_queue_from_signal(uint64_t sig, 
                                            hsa_queue_t** queue);

ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_queue(uint64_t sig, 
                                    hsa_queue_t queue);

ratelprof_status_t 
ratelprof_object_tracking_pool_get_agent_from_queue(uint64_t id, 
                                           hsa_agent_t* agent);

ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_agent(uint64_t id, 
                                    hsa_agent_t agent);
                    
ratelprof_status_t 
ratelprof_object_tracking_pool_get_kernelName_from_kernelObj(uint64_t kernel_object, 
                                                const char** kernel_name);

ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_kernelName(uint64_t kernel_object, 
                                        const char* kernel_name);


#endif // RATELPROF_OBJECT_TRACKING_H
