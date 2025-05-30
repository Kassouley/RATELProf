#include <stdlib.h>
#include <stdio.h>
#include <ratelprof.h>

#include "ratelprof_ext.h"
#include "ratelprof_ext/ratelprof_gpu_profiling.h"

#include "domains/fun_proto/gpu_hsa_traced_functions.h"
#include "domains/fun_proto/prof_hsa_traced_functions.h"

#define CALL_GPU_FUNC(func, ...) ((__##func##_t)gpu_api_table.api_fn[GPU_API_ID_##func])(__VA_ARGS__)


hsa_status_t i_gpu_hsa_init() {
    hsa_status_t __ret = CALL_GPU_FUNC(hsa_init, );
    if (__ret == HSA_STATUS_SUCCESS) CALL_PROF_FUNC(hsa_amd_profiling_async_copy_enable, true);
	return __ret;
};



hsa_status_t i_gpu_hsa_executable_get_symbol_by_name(hsa_executable_t executable, const char * symbol_name, const hsa_agent_t * agent, hsa_executable_symbol_t * symbol) {
    hsa_status_t __ret = CALL_GPU_FUNC(hsa_executable_get_symbol_by_name, executable, symbol_name, agent, symbol);
	if (__ret == HSA_STATUS_SUCCESS) ratelprof_intercept_kernel_object(symbol_name,  symbol);
	return __ret;
};


hsa_status_t i_gpu_hsa_queue_create(hsa_agent_t agent, uint32_t size, hsa_queue_type32_t type, void (*callback)(hsa_status_t, hsa_queue_t *, void *), void * data, uint32_t private_segment_size, uint32_t group_segment_size, hsa_queue_t ** queue) {
    hsa_status_t __ret = CALL_GPU_FUNC(hsa_queue_create, agent, size, type, callback, data, private_segment_size, group_segment_size, queue);
	if (__ret == HSA_STATUS_SUCCESS) ratelprof_intercept_queue_object(agent, queue);
	return __ret;
};


void i_gpu_hsa_signal_store_relaxed(hsa_signal_t signal, hsa_signal_value_t value) {
    ratelprof_intercept_dispatch(signal, value);
    CALL_GPU_FUNC(hsa_signal_store_relaxed, signal, value);
};


void i_gpu_hsa_signal_store_screlease(hsa_signal_t signal, hsa_signal_value_t value) {
    ratelprof_intercept_dispatch(signal, value);
    CALL_GPU_FUNC(hsa_signal_store_screlease, signal, value);
};


void i_gpu_hsa_signal_store_release(hsa_signal_t signal, hsa_signal_value_t value) {
    ratelprof_intercept_dispatch(signal, value);
    CALL_GPU_FUNC(hsa_signal_store_release, signal, value);
};


hsa_status_t i_gpu_hsa_amd_memory_async_copy(void * dst, hsa_agent_t dst_agent, const void * src, hsa_agent_t src_agent, size_t size, uint32_t num_dep_signals, const hsa_signal_t * dep_signals, hsa_signal_t completion_signal) {
    ratelprof_intercept_copy(dst_agent, src_agent, size, &completion_signal, -1);
    return CALL_GPU_FUNC(hsa_amd_memory_async_copy, dst, dst_agent, src, src_agent, size, num_dep_signals, dep_signals, completion_signal);
};


hsa_status_t i_gpu_hsa_amd_memory_async_copy_on_engine(void * dst, hsa_agent_t dst_agent, const void * src, hsa_agent_t src_agent, size_t size, uint32_t num_dep_signals, const hsa_signal_t * dep_signals, hsa_signal_t completion_signal, hsa_amd_sdma_engine_id_t engine_id, _Bool force_copy_on_sdma) {
    ratelprof_intercept_copy(dst_agent, src_agent, size, &completion_signal, engine_id);
    return CALL_GPU_FUNC(hsa_amd_memory_async_copy_on_engine, dst, dst_agent, src, src_agent, size, num_dep_signals, dep_signals, completion_signal, engine_id, force_copy_on_sdma);
};


hsa_status_t i_gpu_hsa_shut_down() {
    ratelprof_intercept_agent_object();
    return CALL_GPU_FUNC(hsa_shut_down, );
}
