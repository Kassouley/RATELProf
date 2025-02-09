#include <stdlib.h>
#include <stdio.h>
#include <ratelprof.h>
#include "domains/profiling_trace.h"
#include "ratelprof_ext.h"


void __on_enter_profiling_callback_function(ratelprof_api_id_t id, ratelprof_api_activity_t* activity) {
    activity->phase = ratelprof_get_current_phase();
    activity->domain = RATELPROF_DOMAIN_PROFILING;
    get_correlation_id(&activity->corr_id);
    get_id(&activity->id);
    activity->funid = id;
}

void __on_exit_profiling_callback_function(ratelprof_api_activity_t* activity) {
    pop_id();
    activity->pid = get_pid();
    activity->tid = get_tid();
    ratelprof_activity_pool_push_activity(activity);
}


#define PROF_FUNCTION_CALL(func, ...) { \
	ratelprof_api_activity_t* profiling_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t)); \
	__on_enter_profiling_callback_function(HSA_API_ID_##func, profiling_activity); \
    profiling_activity->start_time = ratelprof_get_curr_timespec(); \
    ((__##func##_t)profiling_table.api_fn[PROFILING_ID_##func])(__VA_ARGS__); \
    profiling_activity->stop_time = ratelprof_get_curr_timespec(); \
	GET_ARGS_VALUE_##func(profiling_activity); \
	__on_exit_profiling_callback_function(profiling_activity); \
	return; \
}

#define PROF_FUNCTION_CALL_RET(func, ...) { \
	hsa_status_t __ret; \
	ratelprof_api_activity_t* profiling_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t)); \
	__on_enter_profiling_callback_function(HSA_API_ID_##func, profiling_activity); \
    profiling_activity->start_time = ratelprof_get_curr_timespec(); \
    __ret = ((__##func##_t)profiling_table.api_fn[PROFILING_ID_##func])(__VA_ARGS__); \
    profiling_activity->stop_time = ratelprof_get_curr_timespec(); \
	GET_ARGS_VALUE_##func(profiling_activity); \
    profiling_activity->hsa_args.func.retval = (hsa_status_t)__ret; \
	__on_exit_profiling_callback_function(profiling_activity); \
	return __ret; \
}

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