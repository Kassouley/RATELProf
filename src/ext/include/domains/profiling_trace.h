#ifndef PROFILING_TRACE_H
#define PROFILING_TRACE_H

#include <hsa/hsa.h>
#include <hsa/hsa_ext_amd.h>
#include <stdint.h>
#include <time.h>
#include <ratelprof.h>
#include "ratelprof_ext/ratelprof_object_tracking.h"

// API table definition
typedef enum {
    PROFILING_ID_hsa_signal_create,
    PROFILING_ID_hsa_signal_destroy,
    PROFILING_ID_hsa_signal_store_screlease,
    PROFILING_ID_hsa_agent_get_info,
    PROFILING_ID_hsa_amd_profiling_get_async_copy_time,
    PROFILING_ID_hsa_amd_profiling_get_dispatch_time,
    PROFILING_ID_hsa_amd_profiling_set_profiler_enabled,
    PROFILING_ID_hsa_amd_profiling_async_copy_enable,
    PROFILING_ID_hsa_executable_symbol_get_info,
    PROFILING_ID_hsa_amd_signal_async_handler,
    PROFILING_ID_hsa_iterate_agents,
    PROFILING_ID_NB_FUNCTION,
    PROFILING_ID_UNKNOWN
} profiling_id_t;


// Function prototypes
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
hsa_status_t profiling_hsa_iterate_agents(hsa_status_t (*callback)(hsa_agent_t, void *), void * data);

#endif // PROFILING_TRACE_H
