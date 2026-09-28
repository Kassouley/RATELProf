#ifndef PROF_HSA_TRACED_FUNCTIONS_H
#define PROF_HSA_TRACED_FUNCTIONS_H

#include "domains/minimal_abi/hsa_minimal_abi.h"

// Function prototypes
hsa_status_t profiling_hsa_signal_create(hsa_signal_value_t initial_value, uint32_t num_consumers, const hsa_agent_t * consumers, hsa_signal_t * signal);
hsa_status_t profiling_hsa_signal_destroy(hsa_signal_t signal);
void profiling_hsa_signal_store_screlease(hsa_signal_t signal, hsa_signal_value_t value);
hsa_signal_value_t profiling_hsa_signal_load_scacquire(hsa_signal_t signal);
hsa_status_t profiling_hsa_agent_get_info(hsa_agent_t agent, hsa_agent_info_t attribute, void * value);
hsa_status_t profiling_hsa_amd_profiling_get_async_copy_time(hsa_signal_t signal, hsa_amd_profiling_async_copy_time_t * time);
hsa_status_t profiling_hsa_amd_profiling_get_dispatch_time(hsa_agent_t agent, hsa_signal_t signal, hsa_amd_profiling_dispatch_time_t * time);
hsa_status_t profiling_hsa_amd_profiling_set_profiler_enabled(hsa_queue_t * queue, int enable);
hsa_status_t profiling_hsa_amd_profiling_async_copy_enable(_Bool enable);
hsa_status_t profiling_hsa_executable_symbol_get_info(hsa_executable_symbol_t executable_symbol, hsa_executable_symbol_info_t attribute, void * value);
hsa_status_t profiling_hsa_amd_signal_async_handler(hsa_signal_t signal, hsa_signal_condition_t cond, hsa_signal_value_t value, hsa_amd_signal_handler handler, void * arg);
hsa_status_t profiling_hsa_iterate_agents(hsa_status_t (*callback)(hsa_agent_t, void *), void * data);
hsa_status_t profiling_hsa_amd_pointer_info(const void *ptr, hsa_amd_pointer_info_t *info, void *(*alloc)(size_t), uint32_t *num_agents_accessible, hsa_agent_t **accessible);
hsa_status_t profiling_hsa_amd_queue_get_info(hsa_queue_t* queue, hsa_queue_info_attribute_t attribute, void * value);

#endif // PROF_HSA_TRACED_FUNCTIONS_H
