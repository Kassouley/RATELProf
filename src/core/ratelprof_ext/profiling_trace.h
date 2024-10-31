#ifndef PROFILING_TRACE_H
#define PROFILING_TRACE_H

#include "hsa/hsa.h"
#include "hsa/hsa_ext_amd.h"
#include <stdint.h>
#include <time.h>
#include "ratelprof.h"
#include "ratelprof_ext.h"

typedef enum {
    PROFILING_ID_SIGNAL_CREATION,
    PROFILING_ID_SIGNAL_DESTRUCTION,
    PROFILING_ID_SIGNAL_REFRESH,
    PROFILING_ID_GET_AGENT_TYPE,
    PROFILING_ID_GET_COPY_TIME,
    PROFILING_ID_GET_DISPATCH_TIME,
    PROFILING_ID_ENABLE_DISPATCH_PROFILING,
    PROFILING_ID_ENABLE_COPY_PROFILING,
    PROFILING_ID_GET_KERNEL_NAME,
    PROFILING_ID_SET_SIGNAL_HANDLER,
    PROFILING_ID_NB_FUNCTION,
    PROFILING_ID_UNKNOWN
} profiling_id_t;

typedef struct ratelprof_profiling_activity_s {
    ratelprof_domain_t domain;
    profiling_id_t funid;
    uint64_t id;
    uint64_t corr_id;
    uint64_t pid;
    uint64_t tid;
    ratelprof_timespec_t start_time;
    ratelprof_timespec_t stop_time;
    hsa_status_t retval;
} ratelprof_profiling_activity_t;

// Function prototypes
ratelprof_status_t ratelprof_init_profiling_table();
ratelprof_status_t ratelprof_enable_profiling_table();
ratelprof_status_t ratelprof_disable_profiling_table();
ratelprof_status_t ratelprof_populate_profiling_table();

typedef __hsa_signal_create_t __SIGNAL_CREATION_t;
typedef __hsa_signal_destroy_t __SIGNAL_DESTRUCTION_t;
typedef __hsa_signal_store_screlease_t __SIGNAL_REFRESH_t;
typedef __hsa_agent_get_info_t __GET_AGENT_TYPE_t;
typedef __hsa_amd_profiling_get_async_copy_time_t __GET_COPY_TIME_t;
typedef __hsa_amd_profiling_get_dispatch_time_t __GET_DISPATCH_TIME_t;
typedef __hsa_amd_profiling_set_profiler_enabled_t __ENABLE_DISPATCH_PROFILING_t;
typedef __hsa_amd_profiling_async_copy_enable_t __ENABLE_COPY_PROFILING_t;
typedef __hsa_executable_symbol_get_info_t __GET_KERNEL_NAME_t;
typedef __hsa_amd_signal_async_handler_t __SET_SIGNAL_HANDLER_t;

hsa_status_t profiling_hsa_signal_create(hsa_signal_value_t initial_value, uint32_t num_consumers, const hsa_agent_t * consumers, hsa_signal_t * signal);
hsa_status_t profiling_hsa_signal_destroy(hsa_signal_t signal);
void profiling_hsa_signal_store_screlease(hsa_signal_t signal, hsa_signal_value_t value);
hsa_status_t profiling_hsa_agent_get_info(hsa_agent_t agent, hsa_agent_info_t attribute, void * value);
hsa_status_t profiling_hsa_amd_profiling_get_async_copy_time(hsa_signal_t signal, hsa_amd_profiling_async_copy_time_t * time);
hsa_status_t profiling_hsa_amd_profiling_get_dispatch_time(hsa_agent_t agent, hsa_signal_t signal, hsa_amd_profiling_dispatch_time_t * time);
hsa_status_t profiling_hsa_amd_profiling_set_profiler_enabled(hsa_queue_t * queue, int enable);
hsa_status_t profiling_hsa_amd_profiling_async_copy_enable(_Bool enable);
hsa_status_t profiling_hsa_executable_symbol_get_info(hsa_executable_symbol_t executable_symbol, hsa_executable_symbol_info_t attribute, void * value);
hsa_status_t profiling_hsa_amd_signal_async_handler(hsa_signal_t signal, hsa_signal_condition_t cond, hsa_signal_value_t value, hsa_amd_signal_handler handler, void * arg);

// API table definition
extern api_table_t profiling_table;
extern api_table_t hsa_api_table;

// Return Profiling function name for a given ID
static inline const char* get_prof_funame_by_id(profiling_id_t id) 
{
    switch(id) {
        case PROFILING_ID_SIGNAL_CREATION : return "ratelprof_signal_creation";
        case PROFILING_ID_SIGNAL_DESTRUCTION : return "ratelprof_signal_destruction";
        case PROFILING_ID_SIGNAL_REFRESH : return "ratelprof_signal_refresh";
        case PROFILING_ID_GET_AGENT_TYPE : return "ratelprof_get_agent_type";
        case PROFILING_ID_GET_COPY_TIME : return "ratelprof_get_copy_time";
        case PROFILING_ID_GET_DISPATCH_TIME : return "ratelprof_dispatch_time";
        case PROFILING_ID_ENABLE_DISPATCH_PROFILING : return "ratelprof_enable_dispatch_profiling";
        case PROFILING_ID_ENABLE_COPY_PROFILING : return "ratelprof_enable_copy_profiling";
        case PROFILING_ID_GET_KERNEL_NAME : return "ratelprof_get_kernel_name";
        case PROFILING_ID_SET_SIGNAL_HANDLER : return "ratelprof_register_gpu_callback";
        default : return NULL;
    }
    return NULL;
}

#endif // PROFILING_TRACE_H
