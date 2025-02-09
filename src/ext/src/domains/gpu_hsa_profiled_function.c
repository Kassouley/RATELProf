#include <stdlib.h>
#include <stdio.h>
#include <ratelprof.h>

#include "ratelprof_ext.h"
#include "domains/gpu_hsa_profiled_function.h"
#include "domains/profiling_trace.h"

#define CALL_GPU_FUNC(func, ...) ((__##func##_t)gpu_api_table.api_fn[GPU_API_ID_##func])(__VA_ARGS__)


hsa_status_t i_gpu_hsa_executable_get_symbol_by_name(hsa_executable_t executable, const char * symbol_name, const hsa_agent_t * agent, hsa_executable_symbol_t * symbol) {
    hsa_status_t __ret; 
    __ret = CALL_GPU_FUNC(hsa_executable_get_symbol_by_name, executable, symbol_name, agent, symbol);
	if (__ret == HSA_STATUS_SUCCESS) {
        uint64_t kernel_object = ratelprof_get_kernel_obj_from_symbol(*symbol);
        CHECK_RATELPROF_CALL(
            ratelprof_object_tracking_pool_map_new_kernelName(kernel_object, symbol_name));
    }
	return __ret;
};


hsa_status_t i_gpu_hsa_queue_create(hsa_agent_t agent, uint32_t size, hsa_queue_type32_t type, void (*callback)(hsa_status_t, hsa_queue_t *, void *), void * data, uint32_t private_segment_size, uint32_t group_segment_size, hsa_queue_t ** queue) {
    hsa_status_t __ret;
    __ret = CALL_GPU_FUNC(hsa_queue_create, agent, size, type, callback, data, private_segment_size, group_segment_size, queue);
	if (__ret == HSA_STATUS_SUCCESS) {
        ratelprof_enable_profiling(*queue);
        CHECK_RATELPROF_CALL(
            ratelprof_object_tracking_pool_map_new_agent((*queue)->id, agent));
        CHECK_RATELPROF_CALL(
            ratelprof_object_tracking_pool_map_new_queue((*queue)->doorbell_signal.handle, **queue));
    } \
	return __ret;
};


void i_gpu_hsa_signal_store_relaxed(hsa_signal_t signal, hsa_signal_value_t value) {
    DISPATCH_INTERCEPT();
    CALL_GPU_FUNC(hsa_signal_store_relaxed, signal, value);
};


void i_gpu_hsa_signal_store_screlease(hsa_signal_t signal, hsa_signal_value_t value) {
    DISPATCH_INTERCEPT();
    CALL_GPU_FUNC(hsa_signal_store_screlease, signal, value);
};


void i_gpu_hsa_signal_store_release(hsa_signal_t signal, hsa_signal_value_t value) {
    DISPATCH_INTERCEPT();
    CALL_GPU_FUNC(hsa_signal_store_release, signal, value);
};


hsa_status_t i_gpu_hsa_amd_memory_async_copy(void * dst, hsa_agent_t dst_agent, const void * src, hsa_agent_t src_agent, size_t size, uint32_t num_dep_signals, const hsa_signal_t * dep_signals, hsa_signal_t completion_signal) {
    hsa_status_t __ret;
    COPY_INTERCEPT();
    __ret = CALL_GPU_FUNC(hsa_amd_memory_async_copy, dst, dst_agent, src, src_agent, size, num_dep_signals, dep_signals, completion_signal);
	return __ret;
};


hsa_status_t i_gpu_hsa_amd_memory_async_copy_on_engine(void * dst, hsa_agent_t dst_agent, const void * src, hsa_agent_t src_agent, size_t size, uint32_t num_dep_signals, const hsa_signal_t * dep_signals, hsa_signal_t completion_signal, hsa_amd_sdma_engine_id_t engine_id, _Bool force_copy_on_sdma) {
    hsa_status_t __ret;
    COPY_INTERCEPT();
    __ret = CALL_GPU_FUNC(hsa_amd_memory_async_copy_on_engine, dst, dst_agent, src, src_agent, size, num_dep_signals, dep_signals, completion_signal, engine_id, force_copy_on_sdma);
	return __ret;
};


hsa_status_t i_gpu_hsa_shut_down() {
    hsa_status_t __ret;
    ratelprof_init_agent_list();
    __ret = CALL_GPU_FUNC(hsa_shut_down, );
	return __ret;
}
