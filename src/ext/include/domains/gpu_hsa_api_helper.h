#ifndef GPU_HSA_API_HELPER_H
#define GPU_HSA_API_HELPER_H

typedef enum {
    GPU_API_ID_hsa_init,
    GPU_API_ID_hsa_executable_get_symbol_by_name,
    GPU_API_ID_hsa_queue_create,
    GPU_API_ID_hsa_signal_store_relaxed,
    GPU_API_ID_hsa_signal_store_screlease,
    GPU_API_ID_hsa_signal_store_release,
    GPU_API_ID_hsa_amd_memory_async_copy,
    GPU_API_ID_hsa_amd_memory_async_copy_on_engine,
    GPU_API_ID_hsa_shut_down,
    GPU_API_ID_NB_FUNCTION,
    GPU_API_ID_UNKNOWN
} gpu_api_id_t;

#endif // GPU_HSA_API_HELPER_H