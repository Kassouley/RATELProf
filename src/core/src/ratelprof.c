/** THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA. 
 */
 
#include <stdio.h>
#include "ratelprof.h"

ratelprof_api_table_t omp_tgt_api_table;
ratelprof_api_table_t hsa_api_table;
ratelprof_api_table_t omp_tgt_rtl_api_table;
ratelprof_api_table_t hip_api_table; 

void default_callback_function(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity)
{
    fprintf(stderr, "No callback function has been set for domain ID %d.\n", domain); 
}

api_callback_handler_t omp_tgt_callback = {default_callback_function, default_callback_function};
api_callback_handler_t hsa_callback = {default_callback_function, default_callback_function};
api_callback_handler_t omp_tgt_rtl_callback = {default_callback_function, default_callback_function};
api_callback_handler_t hip_callback = {default_callback_function, default_callback_function}; 

const char* ratelprof_get_domain_name(ratelprof_domain_t domain) 
{
	switch(domain) {
		case RATELPROF_DOMAIN_OMP_TGT      : return RATELPROF_DOMAIN_OMP_TGT_NAME;
		case RATELPROF_DOMAIN_HSA          : return RATELPROF_DOMAIN_HSA_NAME;
		case RATELPROF_DOMAIN_OMP_TGT_RTL  : return RATELPROF_DOMAIN_OMP_TGT_RTL_NAME;
		case RATELPROF_DOMAIN_HIP          : return RATELPROF_DOMAIN_HIP_NAME; 
		default : return "Unknown domain";
	}
	return "Unknown domain";
}

const char* ratelprof_get_domain_desc(ratelprof_domain_t domain) 
{
	switch(domain) {
		case RATELPROF_DOMAIN_OMP_TGT      : return RATELPROF_DOMAIN_OMP_TGT_DESC;
		case RATELPROF_DOMAIN_HSA          : return RATELPROF_DOMAIN_HSA_DESC;
		case RATELPROF_DOMAIN_OMP_TGT_RTL  : return RATELPROF_DOMAIN_OMP_TGT_RTL_DESC;
		case RATELPROF_DOMAIN_HIP          : return RATELPROF_DOMAIN_HIP_DESC; 
		default : return "Unknown domain";
	}
	return "Unknown domain";
}

const char* get_funame_by_id(ratelprof_domain_t domain, ratelprof_api_id_t funid) 
{
    switch (domain) {
		case RATELPROF_DOMAIN_OMP_TGT      : return get_omp_tgt_funame_by_id(funid);
		case RATELPROF_DOMAIN_HSA          : return get_hsa_funame_by_id(funid);
		case RATELPROF_DOMAIN_OMP_TGT_RTL  : return get_omp_tgt_rtl_funame_by_id(funid);
		case RATELPROF_DOMAIN_HIP          : return get_hip_funame_by_id(funid); 
        default: break;
    }
    return NULL;
}

ratelprof_api_id_t get_funid_by_name(ratelprof_domain_t domain, const char* funame) 
{
    switch (domain) {
		case RATELPROF_DOMAIN_OMP_TGT      : return get_omp_tgt_funid_by_name(funame);
		case RATELPROF_DOMAIN_HSA          : return get_hsa_funid_by_name(funame);
		case RATELPROF_DOMAIN_OMP_TGT_RTL  : return get_omp_tgt_rtl_funid_by_name(funame);
		case RATELPROF_DOMAIN_HIP          : return get_hip_funid_by_name(funame); 
        default: break;
    }
    return -1;
}

void* get_funaddr_by_id(ratelprof_domain_t domain, ratelprof_api_id_t funid) 
{
    switch (domain) {
		case RATELPROF_DOMAIN_OMP_TGT      : return get_omp_tgt_funaddr_by_id(funid);
		case RATELPROF_DOMAIN_HSA          : return get_hsa_funaddr_by_id(funid);
		case RATELPROF_DOMAIN_OMP_TGT_RTL  : return get_omp_tgt_rtl_funaddr_by_id(funid);
		case RATELPROF_DOMAIN_HIP          : return get_hip_funaddr_by_id(funid); 
        default: break;
    }
    return NULL;
}

ratelprof_status_t ratelprof_enable_domain(ratelprof_domain_t domain) 
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    switch (domain) {
		case RATELPROF_DOMAIN_OMP_TGT      : status = ratelprof_enable_api_table(&omp_tgt_api_table, "RATELPROF_DOMAIN_OMP_TGT_FUNCTIONS_FILTERED", "RATELPROF_DOMAIN_OMP_TGT_FILTER_TYPE"); break;
		case RATELPROF_DOMAIN_HSA          : status = ratelprof_enable_api_table(&hsa_api_table, "RATELPROF_DOMAIN_HSA_FUNCTIONS_FILTERED", "RATELPROF_DOMAIN_HSA_FILTER_TYPE"); break;
		case RATELPROF_DOMAIN_OMP_TGT_RTL  : status = ratelprof_enable_api_table(&omp_tgt_rtl_api_table, "RATELPROF_DOMAIN_OMP_TGT_RTL_FUNCTIONS_FILTERED", "RATELPROF_DOMAIN_OMP_TGT_RTL_FILTER_TYPE"); break;
		case RATELPROF_DOMAIN_HIP          : status = ratelprof_enable_api_table(&hip_api_table, "RATELPROF_DOMAIN_HIP_FUNCTIONS_FILTERED", "RATELPROF_DOMAIN_HIP_FILTER_TYPE"); break; 
        default: status = RATELPROF_STATUS_UNKNOWN_DOMAIN;
    }
    return status;
}

ratelprof_status_t ratelprof_disable_domain(ratelprof_domain_t domain) 
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    switch (domain) {
		case RATELPROF_DOMAIN_OMP_TGT      : status = ratelprof_disable_api_table(&omp_tgt_api_table); break;
		case RATELPROF_DOMAIN_HSA          : status = ratelprof_disable_api_table(&hsa_api_table); break;
		case RATELPROF_DOMAIN_OMP_TGT_RTL  : status = ratelprof_disable_api_table(&omp_tgt_rtl_api_table); break;
		case RATELPROF_DOMAIN_HIP          : status = ratelprof_disable_api_table(&hip_api_table); break; 
        default: status = RATELPROF_STATUS_UNKNOWN_DOMAIN;
    }
    return status;
}

ratelprof_status_t ratelprof_set_api_callback(ratelprof_domain_t domain, api_callback_handler_t callback_handler) 
{
    if (!callback_handler.on_enter || !callback_handler.on_exit)
        return RATELPROF_STATUS_CALLBACK_IS_NULL;

    switch (domain) {
		case RATELPROF_DOMAIN_OMP_TGT      : omp_tgt_callback = callback_handler; break;
		case RATELPROF_DOMAIN_HSA          : hsa_callback = callback_handler; break;
		case RATELPROF_DOMAIN_OMP_TGT_RTL  : omp_tgt_rtl_callback = callback_handler; break;
		case RATELPROF_DOMAIN_HIP          : hip_callback = callback_handler; break; 
        default: return RATELPROF_STATUS_UNKNOWN_DOMAIN;
    }
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t ratelprof_start() 
{
	ratelprof_lifecycle_t * lc = ratelprof_get_lifecycle();
    lc->current_phase = RATELPROF_IN_CONSTRUCTOR_PHASE;
    lc->constructor_start = ratelprof_get_curr_timespec();
    return RATELPROF_STATUS_SUCCESS;
}


ratelprof_status_t ratelprof_stop() 
{
	ratelprof_lifecycle_t * lc = ratelprof_get_lifecycle();
    lc->current_phase = RATELPROF_IN_TOOL_FINI_PHASE;
    lc->destructor_stop = ratelprof_get_curr_timespec();
    return RATELPROF_STATUS_SUCCESS;
}


ratelprof_status_t ratelprof_init() 
{
	struct {
		ratelprof_api_table_t* api_table_addr;
		size_t nb_function;
		const char* lib_path;
	} domains_info[] = {
		{&omp_tgt_api_table, OMP_TGT_API_ID_NB_FUNCTION, "/opt/rocm/llvm/lib/libomptarget.so.18git"},
		{&hsa_api_table, HSA_API_ID_NB_FUNCTION, "/opt/rocm/lib/libhsa-runtime64.so"},
		{&omp_tgt_rtl_api_table, OMP_TGT_RTL_API_ID_NB_FUNCTION, "/opt/rocm/llvm/lib/libomptarget.rtl.amdgpu.so"},
		{&hip_api_table, HIP_API_ID_NB_FUNCTION, "/opt/rocm/lib/libamdhip64.so"}, 
    };

    INIT_LOGGER();
    ratelprof_init_lifecycle();
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    RATELPROF_TRY(init_id_system());

	for (int i = 0; i < RATELPROF_NB_DOMAIN; i++)
	{
		RATELPROF_TRY(ratelprof_init_api_table(i, domains_info[i].api_table_addr, domains_info[i].nb_function));
		RATELPROF_TRY(ratelprof_populate_api_table(domains_info[i].api_table_addr, domains_info[i].lib_path));
	}
    return status;
}



ratelprof_status_t ratelprof_fini() 
{
    CLOSE_LOGGER();
    cleanup_id_system();
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
	RATELPROF_TRY(ratelprof_cleanup_api_table(&omp_tgt_api_table));
	RATELPROF_TRY(ratelprof_cleanup_api_table(&hsa_api_table));
	RATELPROF_TRY(ratelprof_cleanup_api_table(&omp_tgt_rtl_api_table));
	RATELPROF_TRY(ratelprof_cleanup_api_table(&hip_api_table)); 
    ratelprof_fini_lifecycle();
    return status;
}

