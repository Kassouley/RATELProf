/* # THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * # DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * # ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA.
 */ 

#ifndef RATELPROF_H 
#define RATELPROF_H 

#include "utils.h"
#include "env.h"
#include "id_system.h"
#include "ratelprof_time.h"
#include "hsa_profiled_functions.h"
#include "omp_tgt_rtl_profiled_functions.h"
#include "hip_profiled_functions.h" 

typedef unsigned int ratelprof_api_id_t;

typedef enum {
	RATELPROF_DOMAIN_HSA,
	RATELPROF_DOMAIN_OMP_TGT_RTL,
	RATELPROF_DOMAIN_HIP, 
    RATELPROF_NB_DOMAIN
} ratelprof_domain_t;

typedef enum {
	RATELPROF_STATUS_SUCCESS,
	RATELPROF_STATUS_CALLBACK_IS_NULL,
	RATELPROF_STATUS_MALLOC_FAILED,
	RATELPROF_STATUS_API_TABLE_IS_NULL,
	RATELPROF_STATUS_PLUGIN_IS_NULL,
	RATELPROF_STATUS_API_TABLE_NOT_INIT,
	RATELPROF_STATUS_INVALID_PTR,
	RATELPROF_STATUS_UNKNOWN_DOMAIN,
	RATELPROF_STATUS_DLOPEN_FAILED,
	RATELPROF_STATUS_PLUGIN_ALREADY_INIT 
} ratelprof_status_t;

typedef struct ratelprof_api_activity_s {
	ratelprof_domain_t domain;
	ratelprof_api_id_t funid;
    uint64_t id;
    uint64_t corr_id;
	uint64_t pid;
	uint64_t tid;
    ratelprof_timespec_t start_time;
    ratelprof_timespec_t stop_time;
    union {
		hsa_api_args_t hsa_args;
		omp_tgt_rtl_api_args_t omp_tgt_rtl_args;
		hip_api_args_t hip_args; 
	};
} ratelprof_api_activity_t;

#include "api_callback_manager.h"
#include "api_table_manager.h"

const char* get_domain_name(ratelprof_domain_t domain);
const char* get_funame_by_id(ratelprof_domain_t domain, ratelprof_api_id_t funid);
ratelprof_api_id_t get_funid_by_name(ratelprof_domain_t domain, const char* funame);
void* get_funaddr_by_id(ratelprof_domain_t domain, ratelprof_api_id_t funid);
ratelprof_status_t ratelprof_enable_domain(ratelprof_domain_t domain);
ratelprof_status_t ratelprof_disable_domain(ratelprof_domain_t domain);
ratelprof_status_t ratelprof_set_api_callback(ratelprof_domain_t domain, api_callback_handler_t callback_handler);
ratelprof_status_t ratelprof_init();
ratelprof_status_t ratelprof_fini();

static inline const char* get_error_string(ratelprof_status_t status) {
    switch (status)
    {	
		case RATELPROF_STATUS_CALLBACK_IS_NULL: return "Enter or exit callback has not been correctly set";
		case RATELPROF_STATUS_SUCCESS: return "Function return success";
		case RATELPROF_STATUS_MALLOC_FAILED: return "Memory allocation failed";
		case RATELPROF_STATUS_API_TABLE_IS_NULL: return "The API table is NULL or not initialized";
		case RATELPROF_STATUS_PLUGIN_IS_NULL: return "The plugin is NULL or not initialized";
		case RATELPROF_STATUS_API_TABLE_NOT_INIT: return "Arrays in API table not initialized";
		case RATELPROF_STATUS_INVALID_PTR: return "Invalid structure pointer (NULL)";
		case RATELPROF_STATUS_UNKNOWN_DOMAIN: return "Domain in argument does not exist";
		case RATELPROF_STATUS_DLOPEN_FAILED: return "Failed to open library";
		case RATELPROF_STATUS_PLUGIN_ALREADY_INIT: return "The plugin is not null or has already been initialized";
        default: break;
    }
    return "Unknown error";
}
    
#ifdef RATELPROF_DEBUG

#define CHECK_RATELPROF_CALL(call) { \
    ratelprof_status_t ret = call; \
    if (ret != RATELPROF_STATUS_SUCCESS) \
    { \
        fprintf(stderr, "RATELPROF Error : %s (code: %d)\n", \
                    get_error_string(ret), ret); \
    } \
};

#else

#define CHECK_RATELPROF_CALL(call) { call; }; // for debug

#endif // RATELPROF_DEBUG

#endif // RATELPROF_H