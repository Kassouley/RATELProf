#include <ratelprof.h>
#include "ratelprof_ext.h"
#include "domains/fun_proto/gpu_hsa_traced_functions.h"
#include "domains/fun_proto/prof_hsa_traced_functions.h"

ratelprof_api_table_t gpu_api_table;
ratelprof_api_table_t profiling_table;

const char* get_kernel_name(uint64_t kernel_object)
{
    char* kernel_name = NULL;
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS; 
    status = ratelprof_object_tracking_pool_get_kernelName_from_kernelObj(kernel_object, (void*)&kernel_name);
    if (status != RATELPROF_STATUS_SUCCESS) {
        LOG(LOG_LEVEL_ERROR, "Failed to get kernel name from kernel object. %s (code %d)\n", get_error_string_ext(status), status);
        return "N/A";
    }
    return kernel_name;
}

const char* ratelprof_ext_get_domain_name(ratelprof_domain_t domain) 
{
	switch((int)domain) {
		case RATELPROF_DOMAIN_COPY:         return RATELPROF_DOMAIN_COPY_NAME;
		case RATELPROF_DOMAIN_KERNEL:       return RATELPROF_DOMAIN_KERNEL_NAME;
		case RATELPROF_DOMAIN_BARRIEROR:    return RATELPROF_DOMAIN_BARRIEROR_NAME;
		case RATELPROF_DOMAIN_BARRIERAND:   return RATELPROF_DOMAIN_BARRIERAND_NAME;
		case RATELPROF_DOMAIN_PROFILING:    return RATELPROF_DOMAIN_PROFILING_NAME;
		case RATELPROF_DOMAIN_OMP_REGION:   return RATELPROF_DOMAIN_OMP_REGION_NAME;
		default : return ratelprof_get_domain_name(domain) ;
	}
	return "Unknown domain";
}


const char* ratelprof_ext_get_domain_desc(ratelprof_domain_t domain) 
{
	switch((int)domain) {
		case RATELPROF_DOMAIN_COPY:         return RATELPROF_DOMAIN_COPY_DESC;
		case RATELPROF_DOMAIN_KERNEL:       return RATELPROF_DOMAIN_KERNEL_DESC;
		case RATELPROF_DOMAIN_BARRIEROR:    return RATELPROF_DOMAIN_BARRIEROR_DESC;
		case RATELPROF_DOMAIN_BARRIERAND:   return RATELPROF_DOMAIN_BARRIERAND_DESC; 
		case RATELPROF_DOMAIN_PROFILING:    return RATELPROF_DOMAIN_PROFILING_DESC; 
		case RATELPROF_DOMAIN_OMP_REGION:   return RATELPROF_DOMAIN_OMP_REGION_DESC; 
		default : return ratelprof_get_domain_desc(domain) ;
	}
	return "Unknown domain";
}

ratelprof_status_t ratelprof_enable_barrier_dispatch_profiling() {
    if (hsa_api_table.api_ptr == NULL) return RATELPROF_STATUS_API_TABLE_NOT_INIT;
    
    hsa_api_table.api_ptr[HSA_API_ID_hsa_queue_create]           = i_gpu_hsa_queue_create;
    hsa_api_table.api_ptr[HSA_API_ID_hsa_signal_store_relaxed]   = i_gpu_hsa_signal_store_relaxed;
    hsa_api_table.api_ptr[HSA_API_ID_hsa_signal_store_screlease] = i_gpu_hsa_signal_store_screlease;
    hsa_api_table.api_ptr[HSA_API_ID_hsa_signal_store_release]   = i_gpu_hsa_signal_store_release;

    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t ratelprof_enable_kernel_dispatch_profiling() {
    if (hsa_api_table.api_ptr == NULL) return RATELPROF_STATUS_API_TABLE_NOT_INIT;
    
    hsa_api_table.api_ptr[HSA_API_ID_hsa_queue_create]                  = i_gpu_hsa_queue_create;
    hsa_api_table.api_ptr[HSA_API_ID_hsa_executable_get_symbol_by_name] = i_gpu_hsa_executable_get_symbol_by_name;
    hsa_api_table.api_ptr[HSA_API_ID_hsa_signal_store_relaxed]          = i_gpu_hsa_signal_store_relaxed;
    hsa_api_table.api_ptr[HSA_API_ID_hsa_signal_store_screlease]        = i_gpu_hsa_signal_store_screlease;
    hsa_api_table.api_ptr[HSA_API_ID_hsa_signal_store_release]          = i_gpu_hsa_signal_store_release;
    
    return RATELPROF_STATUS_SUCCESS;
}


ratelprof_status_t ratelprof_enable_memcpy_profiling() {
    if (hsa_api_table.api_ptr == NULL) return RATELPROF_STATUS_API_TABLE_NOT_INIT;
    
    hsa_api_table.api_ptr[HSA_API_ID_hsa_init]                            = i_gpu_hsa_init;
    hsa_api_table.api_ptr[HSA_API_ID_hsa_amd_memory_async_copy]           = i_gpu_hsa_amd_memory_async_copy;
    hsa_api_table.api_ptr[HSA_API_ID_hsa_amd_memory_async_copy_on_engine] = i_gpu_hsa_amd_memory_async_copy_on_engine;
    
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t ratelprof_populate_gpu_api_table() {
    if (gpu_api_table.api_fn == NULL || hsa_api_table.api_fn == NULL || hsa_api_table.api_ptr == NULL)
        return RATELPROF_STATUS_API_TABLE_NOT_INIT;
    
    // HSA Function ID intercepted for profiling system
    hsa_api_id_t hsa_api_ids[] = {
        HSA_API_ID_hsa_init,
        HSA_API_ID_hsa_executable_get_symbol_by_name,
        HSA_API_ID_hsa_queue_create,
        HSA_API_ID_hsa_signal_store_relaxed,
        HSA_API_ID_hsa_signal_store_screlease,
        HSA_API_ID_hsa_signal_store_release,
        HSA_API_ID_hsa_amd_memory_async_copy,
        HSA_API_ID_hsa_amd_memory_async_copy_on_engine,
        HSA_API_ID_hsa_shut_down
    };
    
    for (int i = 0; i < GPU_API_ID_NB_FUNCTION; i++) {
        gpu_api_table.api_fn[i] = hsa_api_table.api_ptr[hsa_api_ids[i]];
    }

    return RATELPROF_STATUS_SUCCESS;
}


ratelprof_status_t ratelprof_enable_profiling_table() {
    if (profiling_table.api_ptr == NULL) return RATELPROF_STATUS_API_TABLE_NOT_INIT;
    profiling_table.api_ptr[PROFILING_ID_hsa_signal_create]                      = profiling_hsa_signal_create;
    profiling_table.api_ptr[PROFILING_ID_hsa_signal_destroy]                     = profiling_hsa_signal_destroy;
    profiling_table.api_ptr[PROFILING_ID_hsa_signal_store_screlease]             = profiling_hsa_signal_store_screlease;
    profiling_table.api_ptr[PROFILING_ID_hsa_agent_get_info]                     = profiling_hsa_agent_get_info;
    profiling_table.api_ptr[PROFILING_ID_hsa_amd_profiling_get_async_copy_time]  = profiling_hsa_amd_profiling_get_async_copy_time;
    profiling_table.api_ptr[PROFILING_ID_hsa_amd_profiling_get_dispatch_time]    = profiling_hsa_amd_profiling_get_dispatch_time;
    profiling_table.api_ptr[PROFILING_ID_hsa_amd_profiling_set_profiler_enabled] = profiling_hsa_amd_profiling_set_profiler_enabled;
    profiling_table.api_ptr[PROFILING_ID_hsa_amd_profiling_async_copy_enable]    = profiling_hsa_amd_profiling_async_copy_enable;
    profiling_table.api_ptr[PROFILING_ID_hsa_executable_symbol_get_info]         = profiling_hsa_executable_symbol_get_info;
    profiling_table.api_ptr[PROFILING_ID_hsa_amd_signal_async_handler]           = profiling_hsa_amd_signal_async_handler;
    profiling_table.api_ptr[PROFILING_ID_hsa_iterate_agents]                     = profiling_hsa_iterate_agents;
    return RATELPROF_STATUS_SUCCESS;
}


ratelprof_status_t ratelprof_populate_profiling_table() {
    if (profiling_table.api_fn == NULL || hsa_api_table.api_fn == NULL || profiling_table.api_ptr == NULL)
        return RATELPROF_STATUS_API_TABLE_NOT_INIT;

    // HSA Function ID used for profiling system
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
        HSA_API_ID_hsa_amd_signal_async_handler,
        HSA_API_ID_hsa_iterate_agents,
    };

    for (int i = 0; i < PROFILING_ID_NB_FUNCTION; i++) {
        profiling_table.api_fn[i] = hsa_api_table.api_fn[hsa_api_ids[i]];
        profiling_table.api_ptr[i] = hsa_api_table.api_fn[hsa_api_ids[i]];
    }

    return RATELPROF_STATUS_SUCCESS;
}



ratelprof_status_t ratelprof_ext_init()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;

    RATELPROF_TRY(ratelprof_init_api_table(RATELPROF_DOMAIN_GPU, &gpu_api_table, GPU_API_ID_NB_FUNCTION));
    RATELPROF_TRY(ratelprof_populate_gpu_api_table());
    
    RATELPROF_TRY(ratelprof_init_api_table(RATELPROF_DOMAIN_PROFILING, &profiling_table, PROFILING_ID_NB_FUNCTION));
    RATELPROF_TRY(ratelprof_populate_profiling_table());

	RATELPROF_TRY(ratelprof_object_tracking_pool_init());
    
    return status;
}


ratelprof_status_t ratelprof_ext_fini()
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
	RATELPROF_TRY(ratelprof_object_tracking_pool_fini());
	RATELPROF_TRY(ratelprof_cleanup_api_table(&gpu_api_table));
	RATELPROF_TRY(ratelprof_cleanup_api_table(&profiling_table));
    return status;
}