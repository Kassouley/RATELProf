#ifndef PROFILING_HSA_API_HELPER_H
#define PROFILING_HSA_API_HELPER_H

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

#endif // PROFILING_HSA_API_HELPER_H
