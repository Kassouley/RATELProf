#include <stdlib.h>
#include <stdio.h>
#include "profiling_trace.h"
#include "ratelprof.h"
#include "ratelprof_ext.h"

api_table_t profiling_table;

#define PROF_FUNCTION_CALL(func, ...) { \
    clock_gettime(CLOCK_MONOTONIC, &__profiling_activity->start_time); \
    ((__##func##_t)profiling_table.api_fn[PROFILING_ID_##func])(__VA_ARGS__); \
    clock_gettime(CLOCK_MONOTONIC, &__profiling_activity->stop_time); \
}

#define PROF_FUNCTION_CALL_RET(func, ...) { \
    clock_gettime(CLOCK_MONOTONIC, &__profiling_activity->start_time); \
    __ret = ((__##func##_t)profiling_table.api_fn[PROFILING_ID_##func])(__VA_ARGS__); \
    clock_gettime(CLOCK_MONOTONIC, &__profiling_activity->stop_time); \
    __profiling_activity->retval = __ret; \
}

void __on_enter_profiling_callback_function(profiling_id_t id, ratelprof_profiling_activity_t* activity) {
    activity->phase = ratelprof_get_current_phase();
    activity->domain = RATELPROF_DOMAIN_PROFILING;
    activity->corr_id = get_correlation_id();
    activity->id = push_id();
    activity->funid = id;
}

void __on_exit_profiling_callback_function(ratelprof_profiling_activity_t* activity) {
    pop_id();
    activity->pid = get_pid();
    activity->tid = get_tid();
    ratelprof_activity_pool_push_activity(activity);
}

ratelprof_status_t ratelprof_init_profiling_table() {
    if (hsa_api_table.api_fn == NULL) return RATELPROF_STATUS_API_TABLE_NOT_INIT;
    ratelprof_status_t status = ratelprof_init_api_table(RATELPROF_DOMAIN_PROFILING, &profiling_table, PROFILING_ID_NB_FUNCTION);
    if (status != RATELPROF_STATUS_SUCCESS) return status;
    status = ratelprof_populate_profiling_table();
    return status;
}

ratelprof_status_t ratelprof_enable_profiling_table() {
    if (profiling_table.api_ptr == NULL) return RATELPROF_STATUS_API_TABLE_NOT_INIT;
    profiling_table.api_ptr[PROFILING_ID_SIGNAL_CREATION] = profiling_hsa_signal_create;
    profiling_table.api_ptr[PROFILING_ID_SIGNAL_DESTRUCTION] = profiling_hsa_signal_destroy;
    profiling_table.api_ptr[PROFILING_ID_SIGNAL_REFRESH] = profiling_hsa_signal_store_screlease;
    profiling_table.api_ptr[PROFILING_ID_GET_AGENT_TYPE] = profiling_hsa_agent_get_info;
    profiling_table.api_ptr[PROFILING_ID_GET_COPY_TIME] = profiling_hsa_amd_profiling_get_async_copy_time;
    profiling_table.api_ptr[PROFILING_ID_GET_DISPATCH_TIME] = profiling_hsa_amd_profiling_get_dispatch_time;
    profiling_table.api_ptr[PROFILING_ID_ENABLE_DISPATCH_PROFILING] = profiling_hsa_amd_profiling_set_profiler_enabled;
    profiling_table.api_ptr[PROFILING_ID_ENABLE_COPY_PROFILING] = profiling_hsa_amd_profiling_async_copy_enable;
    profiling_table.api_ptr[PROFILING_ID_GET_KERNEL_NAME] = profiling_hsa_executable_symbol_get_info;
    profiling_table.api_ptr[PROFILING_ID_SET_SIGNAL_HANDLER] = profiling_hsa_amd_signal_async_handler;
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t ratelprof_disable_profiling_table() {
    return ratelprof_disable_api_table(&profiling_table);
}

ratelprof_status_t ratelprof_populate_profiling_table() {
    if (profiling_table.api_fn == NULL || hsa_api_table.api_fn == NULL || profiling_table.api_ptr == NULL)
        return RATELPROF_STATUS_API_TABLE_NOT_INIT;

    profiling_id_t profiling_ids[] = {
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
    };

    hsa_api_id_t hsa_api_ids[] = {
        HSA_API_ID_hsa_signal_create,
        HSA_API_ID_hsa_signal_destroy,
        HSA_API_ID_hsa_signal_store_screlease,
        HSA_API_ID_hsa_agent_get_info,
        HSA_API_ID_hsa_amd_profiling_get_async_copy_time,
        HSA_API_ID_hsa_amd_profiling_get_dispatch_time,
        HSA_API_ID_hsa_amd_profiling_set_profiler_enabled,
        HSA_API_ID_hsa_amd_profiling_async_copy_enable,
        HSA_API_ID_hsa_executable_symbol_get_info,
        HSA_API_ID_hsa_amd_signal_async_handler
    };

    for (int i = 0; i < PROFILING_ID_NB_FUNCTION; i++) {
        profiling_table.api_fn[profiling_ids[i]] = hsa_api_table.api_fn[hsa_api_ids[i]];
        profiling_table.api_ptr[profiling_ids[i]] = hsa_api_table.api_fn[hsa_api_ids[i]];
    }

    return RATELPROF_STATUS_SUCCESS;
}

// Function implementations of each profiling wrapper
hsa_status_t profiling_hsa_signal_create(hsa_signal_value_t initial_value, uint32_t num_consumers, const hsa_agent_t * consumers, hsa_signal_t * signal) {
	ratelprof_profiling_activity_t* __profiling_activity = (ratelprof_profiling_activity_t*)malloc(sizeof(ratelprof_profiling_activity_t));
	__on_enter_profiling_callback_function(PROFILING_ID_SIGNAL_CREATION, __profiling_activity);
	hsa_status_t __ret;
	PROF_FUNCTION_CALL_RET(SIGNAL_CREATION, initial_value, num_consumers, consumers, signal)
	__on_exit_profiling_callback_function(__profiling_activity);
	return __ret;
};


hsa_status_t profiling_hsa_signal_destroy(hsa_signal_t signal) {
	ratelprof_profiling_activity_t* __profiling_activity = (ratelprof_profiling_activity_t*)malloc(sizeof(ratelprof_profiling_activity_t));
	__on_enter_profiling_callback_function(PROFILING_ID_SIGNAL_DESTRUCTION, __profiling_activity);
	hsa_status_t __ret;
	PROF_FUNCTION_CALL_RET(SIGNAL_DESTRUCTION, signal)
	__on_exit_profiling_callback_function(__profiling_activity);
	return __ret;
};


void profiling_hsa_signal_store_screlease(hsa_signal_t signal, hsa_signal_value_t value) {
	ratelprof_profiling_activity_t* __profiling_activity = (ratelprof_profiling_activity_t*)malloc(sizeof(ratelprof_profiling_activity_t));
	__on_enter_profiling_callback_function(PROFILING_ID_SIGNAL_REFRESH, __profiling_activity);
	PROF_FUNCTION_CALL(SIGNAL_REFRESH, signal, value)
	__on_exit_profiling_callback_function(__profiling_activity);
	return;
};


hsa_status_t profiling_hsa_agent_get_info(hsa_agent_t agent, hsa_agent_info_t attribute, void * value) {
	ratelprof_profiling_activity_t* __profiling_activity = (ratelprof_profiling_activity_t*)malloc(sizeof(ratelprof_profiling_activity_t));
	__on_enter_profiling_callback_function(PROFILING_ID_GET_AGENT_TYPE, __profiling_activity);
	hsa_status_t __ret;
	PROF_FUNCTION_CALL_RET(GET_AGENT_TYPE, agent, attribute, value)
	__on_exit_profiling_callback_function(__profiling_activity);
	return __ret;
};

hsa_status_t profiling_hsa_amd_profiling_get_async_copy_time(hsa_signal_t signal, hsa_amd_profiling_async_copy_time_t * time) {
	ratelprof_profiling_activity_t* __profiling_activity = (ratelprof_profiling_activity_t*)malloc(sizeof(ratelprof_profiling_activity_t));
	__on_enter_profiling_callback_function(PROFILING_ID_GET_COPY_TIME, __profiling_activity);
	hsa_status_t __ret;
	PROF_FUNCTION_CALL_RET(GET_COPY_TIME, signal, time)
	__on_exit_profiling_callback_function(__profiling_activity);
	return __ret;
};

hsa_status_t profiling_hsa_amd_profiling_get_dispatch_time(hsa_agent_t agent, hsa_signal_t signal, hsa_amd_profiling_dispatch_time_t * time) {
	ratelprof_profiling_activity_t* __profiling_activity = (ratelprof_profiling_activity_t*)malloc(sizeof(ratelprof_profiling_activity_t));
	__on_enter_profiling_callback_function(PROFILING_ID_GET_DISPATCH_TIME, __profiling_activity);
	hsa_status_t __ret;
	PROF_FUNCTION_CALL_RET(GET_DISPATCH_TIME, agent, signal, time)
	__on_exit_profiling_callback_function(__profiling_activity);
	return __ret;
};


hsa_status_t profiling_hsa_amd_profiling_set_profiler_enabled(hsa_queue_t * queue, int enable) {
	ratelprof_profiling_activity_t* __profiling_activity = (ratelprof_profiling_activity_t*)malloc(sizeof(ratelprof_profiling_activity_t));
	__on_enter_profiling_callback_function(PROFILING_ID_ENABLE_DISPATCH_PROFILING, __profiling_activity);
	hsa_status_t __ret;
	PROF_FUNCTION_CALL_RET(ENABLE_DISPATCH_PROFILING, queue, enable)
	__on_exit_profiling_callback_function(__profiling_activity);
	return __ret;
};

hsa_status_t profiling_hsa_amd_profiling_async_copy_enable(_Bool enable) {
	ratelprof_profiling_activity_t* __profiling_activity = (ratelprof_profiling_activity_t*)malloc(sizeof(ratelprof_profiling_activity_t));
	__on_enter_profiling_callback_function(PROFILING_ID_ENABLE_COPY_PROFILING, __profiling_activity);
	hsa_status_t __ret;
	PROF_FUNCTION_CALL_RET(ENABLE_COPY_PROFILING, enable)
	__on_exit_profiling_callback_function(__profiling_activity);
	return __ret;
};


hsa_status_t profiling_hsa_executable_symbol_get_info(hsa_executable_symbol_t executable_symbol, hsa_executable_symbol_info_t attribute, void * value) {
	ratelprof_profiling_activity_t* __profiling_activity = (ratelprof_profiling_activity_t*)malloc(sizeof(ratelprof_profiling_activity_t));
	__on_enter_profiling_callback_function(PROFILING_ID_GET_KERNEL_NAME, __profiling_activity);
	hsa_status_t __ret;
	PROF_FUNCTION_CALL_RET(GET_KERNEL_NAME, executable_symbol, attribute, value)
	__on_exit_profiling_callback_function(__profiling_activity);
	return __ret;
};


hsa_status_t profiling_hsa_amd_signal_async_handler(hsa_signal_t signal, hsa_signal_condition_t cond, hsa_signal_value_t value, hsa_amd_signal_handler handler, void * arg) {
	ratelprof_profiling_activity_t* __profiling_activity = (ratelprof_profiling_activity_t*)malloc(sizeof(ratelprof_profiling_activity_t));
	__on_enter_profiling_callback_function(PROFILING_ID_SET_SIGNAL_HANDLER, __profiling_activity);
	hsa_status_t __ret;
	PROF_FUNCTION_CALL_RET(SET_SIGNAL_HANDLER, signal, cond, value, handler, arg)
	__on_exit_profiling_callback_function(__profiling_activity);
	return __ret;
};