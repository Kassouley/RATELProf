#include <stdlib.h>
#include <stdio.h>
#include <ratelprof.h>

#include "domains/fun_proto/prof_hsa_traced_functions.h"
#include "ratelprof_ext.h"

// Function implementations of each profiling wrapper
hsa_status_t profiling_hsa_signal_create(hsa_signal_value_t initial_value, uint32_t num_consumers, const hsa_agent_t * consumers, hsa_signal_t * signal) {
	PROF_FUNCTION_CALL_RET(hsa_signal_create, initial_value, num_consumers, consumers, signal)
};

hsa_status_t profiling_hsa_signal_destroy(hsa_signal_t signal) {
	PROF_FUNCTION_CALL_RET(hsa_signal_destroy, signal)
};

void profiling_hsa_signal_store_screlease(hsa_signal_t signal, hsa_signal_value_t value) {
	PROF_FUNCTION_CALL(hsa_signal_store_screlease, signal, value)
};

hsa_status_t profiling_hsa_agent_get_info(hsa_agent_t agent, hsa_agent_info_t attribute, void * value) {
	PROF_FUNCTION_CALL_RET(hsa_agent_get_info, agent, attribute, value)
};

hsa_status_t profiling_hsa_amd_profiling_get_async_copy_time(hsa_signal_t signal, hsa_amd_profiling_async_copy_time_t * time) {
	PROF_FUNCTION_CALL_RET(hsa_amd_profiling_get_async_copy_time, signal, time)
};

hsa_status_t profiling_hsa_amd_profiling_get_dispatch_time(hsa_agent_t agent, hsa_signal_t signal, hsa_amd_profiling_dispatch_time_t * time) {
	PROF_FUNCTION_CALL_RET(hsa_amd_profiling_get_dispatch_time, agent, signal, time)
};

hsa_status_t profiling_hsa_amd_profiling_set_profiler_enabled(hsa_queue_t * queue, int enable) {
	PROF_FUNCTION_CALL_RET(hsa_amd_profiling_set_profiler_enabled, queue, enable)
};

hsa_status_t profiling_hsa_amd_profiling_async_copy_enable(_Bool enable) {
	PROF_FUNCTION_CALL_RET(hsa_amd_profiling_async_copy_enable, enable)
};

hsa_status_t profiling_hsa_executable_symbol_get_info(hsa_executable_symbol_t executable_symbol, hsa_executable_symbol_info_t attribute, void * value) {
	PROF_FUNCTION_CALL_RET(hsa_executable_symbol_get_info, executable_symbol, attribute, value)
};

hsa_status_t profiling_hsa_amd_signal_async_handler(hsa_signal_t signal, hsa_signal_condition_t cond, hsa_signal_value_t value, hsa_amd_signal_handler handler, void * arg) {
	PROF_FUNCTION_CALL_RET(hsa_amd_signal_async_handler, signal, cond, value, handler, arg)
};

hsa_status_t profiling_hsa_iterate_agents(hsa_status_t (*callback)(hsa_agent_t, void *), void * data) {
	PROF_FUNCTION_CALL_RET(hsa_iterate_agents, callback, data);
};