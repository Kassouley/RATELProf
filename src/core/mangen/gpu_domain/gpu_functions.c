#include "api_table_manager.h"

#include "gpu_functions.h"

#include "hsa.h"
#include "hsa_ext_amd.h"

extern api_table_t hsa_api_table;

#define HSA_FUNCTION_CALL(func, ...) ((__##func##_t)hsa_api_table.api_ptr[HSA_API_ID_##func])(__VA_ARGS__)

hsa_status_t hsa_executable_get_symbol_by_name(hsa_executable_t executable, const char * symbol_name, const hsa_agent_t * agent, hsa_executable_symbol_t * symbol) {
    hsa_status_t __hsa_ret__ = HSA_FUNCTION_CALL(hsa_executable_get_symbol_by_name, executable, symbol_name, agent, symbol);
    SYMBOL_INTERCEPT();
    return __hsa_ret__;
};

hsa_status_t hsa_amd_memory_async_copy(void* dst, hsa_agent_t dst_agent, const void* src, hsa_agent_t src_agent, size_t size, uint32_t num_dep_signals, const hsa_signal_t* dep_signals, hsa_signal_t completion_signal) { 
    COPY_INTERCEPT();
    return HSA_FUNCTION_CALL(hsa_amd_memory_async_copy, dst, dst_agent, src, src_agent, size, num_dep_signals, dep_signals, completion_signal); 
}

hsa_status_t hsa_amd_memory_async_copy_on_engine(void* dst, hsa_agent_t dst_agent, const void* src, hsa_agent_t src_agent, size_t size, uint32_t num_dep_signals, const hsa_signal_t* dep_signals, hsa_signal_t completion_signal, hsa_amd_sdma_engine_id_t engine_id, bool force_copy_on_sdma) { 
    COPY_INTERCEPT();
    return HSA_FUNCTION_CALL(hsa_amd_memory_async_copy_on_engine, dst, dst_agent, src, src_agent, size, num_dep_signals, dep_signals, completion_signal, engine_id, force_copy_on_sdma); 
}

void hsa_signal_store_relaxed(hsa_signal_t signal, hsa_signal_value_t value) { 
    DISPATCH_INTERCEPT();
    HSA_FUNCTION_CALL(hsa_signal_store_relaxed, signal, value); 
}

void hsa_signal_store_screlease(hsa_signal_t signal, hsa_signal_value_t value) { 
    DISPATCH_INTERCEPT();
    HSA_FUNCTION_CALL(hsa_signal_store_screlease, signal, value); 
}

void hsa_signal_store_release(hsa_signal_t signal, hsa_signal_value_t value) { 
    DISPATCH_INTERCEPT();
    HSA_FUNCTION_CALL(hsa_signal_store_release, signal, value); 
}

void hsa_signal_silent_store_relaxed(hsa_signal_t signal, hsa_signal_value_t value) { 
    HSA_FUNCTION_CALL(hsa_signal_silent_store_relaxed, signal, value); 
}

void hsa_signal_silent_store_screlease(hsa_signal_t signal, hsa_signal_value_t value) { 
    HSA_FUNCTION_CALL(hsa_signal_silent_store_screlease, signal, value); 
}

hsa_status_t hsa_queue_create(hsa_agent_t agent, uint32_t size, hsa_queue_type32_t type, void (*callback)(hsa_status_t status, hsa_queue_t *source, void *data), void *data, uint32_t private_segment_size, uint32_t group_segment_size, hsa_queue_t **queue) { 
    hsa_status_t __hsa_ret__ = HSA_FUNCTION_CALL(hsa_queue_create, agent, size, type, callback, data, private_segment_size, group_segment_size, queue); 
    AGENT_INTERCEPT(__hsa_ret__, queue, agent);
    return __hsa_ret__;
}

hsa_status_t hsa_memory_copy(void *dst, const void *src, size_t size) { 
    return HSA_FUNCTION_CALL(hsa_memory_copy, dst, src, size); 
}



