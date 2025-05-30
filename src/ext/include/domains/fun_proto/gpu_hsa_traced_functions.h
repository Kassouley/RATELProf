#ifndef GPU_HSA_TRACED_FUNCTIONS_H
#define GPU_HSA_TRACED_FUNCTIONS_H

#include <hsa/hsa.h>
#include <hsa/amd_hsa_signal.h>

hsa_status_t i_gpu_hsa_init();
hsa_status_t i_gpu_hsa_executable_get_symbol_by_name(hsa_executable_t executable, const char * symbol_name, const hsa_agent_t * agent, hsa_executable_symbol_t * symbol);
hsa_status_t i_gpu_hsa_queue_create(hsa_agent_t agent, uint32_t size, hsa_queue_type32_t type, void (*callback)(hsa_status_t, hsa_queue_t *, void *), void * data, uint32_t private_segment_size, uint32_t group_segment_size, hsa_queue_t ** queue);
void i_gpu_hsa_signal_store_relaxed(hsa_signal_t signal, hsa_signal_value_t value);
void i_gpu_hsa_signal_store_screlease(hsa_signal_t signal, hsa_signal_value_t value);
void i_gpu_hsa_signal_store_release(hsa_signal_t signal, hsa_signal_value_t value);
hsa_status_t i_gpu_hsa_amd_memory_async_copy(void * dst, hsa_agent_t dst_agent, const void * src, hsa_agent_t src_agent, size_t size, uint32_t num_dep_signals, const hsa_signal_t * dep_signals, hsa_signal_t completion_signal);
hsa_status_t i_gpu_hsa_amd_memory_async_copy_on_engine(void * dst, hsa_agent_t dst_agent, const void * src, hsa_agent_t src_agent, size_t size, uint32_t num_dep_signals, const hsa_signal_t * dep_signals, hsa_signal_t completion_signal, hsa_amd_sdma_engine_id_t engine_id, _Bool force_copy_on_sdma);
hsa_status_t i_gpu_hsa_shut_down();

#endif // GPU_HSA_TRACED_FUNCTIONS_H