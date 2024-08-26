/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#ifndef PLUGIN_H
#define PLUGIN_H

#include <unistd.h>
#include <sys/syscall.h>

#include "hsa_plugin.h"
#include "hip_plugin.h" 

#include "ratelprof_buffer_manager.h"

static inline uint32_t get_tid() 
{ 
    return syscall(__NR_gettid); 
}

static inline uint32_t get_pid() 
{ 
    return syscall(__NR_getpid); 
}

static inline ratelprof_buffer_t create_json_trace(const char *filename)
{
    ratelprof_buffer_t json_buffer = {};
    ratelprof_init_buffer(&json_buffer, filename, 2048);
    ratelprof_add_to_buffer(&json_buffer, 
            "{\"domain\":{\"%d\":\"HSA\",\"%d\":\"HIP\",\"%d\":\"GPU\"},",
            RATELPROF_DOMAIN_HSA,RATELPROF_DOMAIN_HIP,RATELPROF_DOMAIN_GPU);
    ratelprof_add_to_buffer(&json_buffer, 
            "\"operation\": {\"%d\":\"DISPATCH\",\"%d\":\"COPY\",\"%d\":\"KERNEL\",\"%d\":\"BARRIEROR\",\"%d\":\"BARRIERAND\",\"%d\":\"CPU\"},",
            RATELPROF_DISPATCH_OPERATION, RATELPROF_COPY_OPERATION, RATELPROF_KERNEL_OPERATION, RATELPROF_BARRIEROR_OPERATION, RATELPROF_BARRIERAND_OPERATION, RATELPROF_CPU_OPERATION);
    
    ratelprof_add_to_buffer(&json_buffer, "\"traceEvents\":[");
	return json_buffer; 
} 


static inline void close_json_trace(ratelprof_buffer_t* json_buffer)
{
    ratelprof_add_to_buffer(json_buffer, "]}");
    ratelprof_flush_buffer(json_buffer);
} 


static inline void add_gpu_event(ratelprof_buffer_t* json_buffer, 
                                 const ratelprof_gpu_activity_t *a)
{
    ratelprof_add_to_buffer(json_buffer, 
        "{\"domain\":%d,\"operation\":%d,\"name\":\"%s\",\"corrId\":%lu,\"start\":%lu,\"end\":%lu,\"gpu_id\":%lu,",
        10, a->op, "dummy", a->corrId, a->start_time, a->stop_time, a->gpu_id);
    ratelprof_add_to_buffer(json_buffer, "s},");
}


void hsa_callback(bool is_enter, ratelprof_hsa_api_activity_t* activity);
static inline void add_hsa_event(ratelprof_buffer_t* json_buffer, 
                                 const ratelprof_hsa_api_activity_t *a)
{
    ratelprof_add_to_buffer(json_buffer, 
        "{\"domain\":%d,\"operation\":%d,\"name\":\"%s\",\"corrId\":%lu,\"start\":%lu,\"end\":%lu,\"pid\":%lu,\"tid\":%lu,",
        RATELPROF_DOMAIN_HSA, RATELPROF_CPU_OPERATION, get_hsa_funame_by_id(a->funid), a->corrId, a->start_time, a->stop_time, a->pid, a->tid);
    ratelprof_add_to_buffer(json_buffer, "\"args\":{");
	process_hsa_args_for(a->funid, &a->args, json_buffer);
    ratelprof_add_to_buffer(json_buffer, "}},");
}

void hip_callback(bool is_enter, ratelprof_hip_api_activity_t* activity);
static inline void add_hip_event(ratelprof_buffer_t* json_buffer, 
                                 const ratelprof_hip_api_activity_t *a)
{
    ratelprof_add_to_buffer(json_buffer, 
        "{\"domain\":%d,\"operation\":%d,\"name\":\"%s\",\"corrId\":%lu,\"start\":%lu,\"end\":%lu,\"pid\":%lu,\"tid\":%lu,",
        RATELPROF_DOMAIN_HIP, RATELPROF_CPU_OPERATION, get_hip_funame_by_id(a->funid), a->corrId, a->start_time, a->stop_time, a->pid, a->tid);
    ratelprof_add_to_buffer(json_buffer, "\"args\":{");
	process_hip_args_for(a->funid, &a->args, json_buffer);
    ratelprof_add_to_buffer(json_buffer, "}},");
}


#endif // PLUGIN_H
