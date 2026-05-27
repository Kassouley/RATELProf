#ifndef RATELPROF_OBJECT_TRACKING_H
#define RATELPROF_OBJECT_TRACKING_H

#include <ratelprof.h>

#include "domains/memory_op_helper.h"
#include "ratelprof_ext/memory_structure/ratelprof_hash_table.h"

typedef struct {
    hsa_agent_t agent;
    uint32_t node;
    uint8_t type;
} ratelprof_agent_object_t;

typedef struct {
    ratelprof_hash_table_t agent_queueId_map;
    ratelprof_hash_table_t queue_doorbell_map;
    ratelprof_hash_table_t kernelName_kernelObj_map;
    ratelprof_hash_table_t memop_kernelObj_map;
    ratelprof_hash_table_t agents_list;
    
    bool is_barrier_packet_tracked;
    bool is_kernel_packet_tracked;
    bool is_memory_blit_kernel_packet_tracked;
} ratelprof_object_tracking_pool_t;


bool ratelprof_object_tracking_is_barrier_packet_tracked();

bool ratelprof_object_tracking_is_kernel_packet_tracked();

bool ratelprof_object_tracking_is_memory_blit_kernel_packet_tracked();

ratelprof_status_t 
ratelprof_object_tracking_pool_init();

ratelprof_status_t 
ratelprof_object_tracking_pool_fini();

ratelprof_object_tracking_pool_t*
ratelprof_object_tracking_pool_get_pool();

ratelprof_status_t 
ratelprof_object_tracking_pool_get_queue_from_signal(uint64_t sig, hsa_queue_t** queue);

ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_queue_to_signal(uint64_t sig, hsa_queue_t queue);


ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_agent_to_queueId(uint64_t id, hsa_agent_t agent);

ratelprof_status_t 
ratelprof_object_tracking_pool_get_agent_from_queueId(uint64_t id, hsa_agent_t* agent);


ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_agent_to_handle(uint64_t handle, ratelprof_agent_object_t* agent);

ratelprof_status_t 
ratelprof_object_tracking_pool_get_agent_from_handle(uint64_t handle, ratelprof_agent_object_t** agent);
                    

ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_kernelName_to_kernelObj(uint64_t kernel_object, const char* kernel_name);

ratelprof_status_t 
ratelprof_object_tracking_pool_get_kernelName_from_kernelObj(uint64_t kernel_object, const char** kernel_name);


ratelprof_status_t 
ratelprof_object_tracking_pool_map_new_MemOp_to_kernelObj(uint64_t kernel_object, ratelprof_memory_op_t memop);

ratelprof_status_t 
ratelprof_object_tracking_pool_get_MemOp_from_kernelObj(uint64_t kernel_object, ratelprof_memory_op_t* memop);


#endif // RATELPROF_OBJECT_TRACKING_H
