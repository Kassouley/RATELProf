/* # THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * # DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * # ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA.
 */ 

#include "ratelprof_ext.h"
#include <ratelprof.h>
#include "activity_plugin.h" 
#include "omp_tgt_domain/omp_tgt_plugin.h"
#include "hsa_domain/hsa_plugin.h"
#include "omp_tgt_rtl_domain/omp_tgt_rtl_plugin.h"
#include "hip_domain/hip_plugin.h" 

typedef struct ratelprof_plugin_s {
	api_callback_handler_t omp_tgt_callback_handler;
	api_callback_handler_t hsa_callback_handler;
	api_callback_handler_t omp_tgt_rtl_callback_handler;
	api_callback_handler_t hip_callback_handler; 
    activity_callback_t activity_callback;
    ratelprof_buffer_t* json_buffer;
} ratelprof_plugin_t;


void init_json_content(ratelprof_buffer_t* json_buffer)
{
    int i = 0;
    ratelprof_add_to_buffer(json_buffer, "{\n\t\"domain_id\": {\n");
    for (i = 0; i < RATELPROF_NB_DOMAIN; i++)
    {
        ratelprof_add_to_buffer(json_buffer, "\t\t\"%d\": {\"name\":\"%s\", \"desc\":\"%s\"},\n", i, ratelprof_get_domain_name(i), ratelprof_get_domain_desc(i));
    }

    int domains[5] = {
        RATELPROF_DOMAIN_COPY, RATELPROF_DOMAIN_KERNEL,
        RATELPROF_DOMAIN_BARRIEROR, RATELPROF_DOMAIN_BARRIERAND,
        RATELPROF_DOMAIN_PROFILING
    };
    for (i = 0; i < 4; i++)
    {
        int d = domains[i]
        ratelprof_add_to_buffer(json_buffer, "\t\t\"%d\": {\"name\":\"%s\", \"desc\":\"%s\"},\n", d, ratelprof_ext_get_domain_name(d), ratelprof_ext_get_domain_desc(d));
    }
    ratelprof_add_to_buffer(json_buffer, "\t\t\"%d\": {\"name\":\"%s\", \"desc\":\"%s\"}\n", domains[4], ratelprof_ext_get_domain_name(domains[4]), ratelprof_ext_get_domain_desc(domains[4]));


    ratelprof_add_to_buffer(json_buffer, "\t\"phase_id\": {\n");
    ratelprof_add_to_buffer(json_buffer, "\t\t\"%d\": \"TOOL_INIT_PHASE\",\n", RATELPROF_IN_TOOL_INIT_PHASE);
    ratelprof_add_to_buffer(json_buffer, "\t\t\"%d\": \"CONSTRUCTOR_PHASE\",\n", RATELPROF_IN_CONSTRUCTOR_PHASE);
    ratelprof_add_to_buffer(json_buffer, "\t\t\"%d\": \"MAIN_PHASE\",\n", RATELPROF_IN_MAIN_PHASE);
    ratelprof_add_to_buffer(json_buffer, "\t\t\"%d\": \"DESTRUCTOR_PHASE\",\n", RATELPROF_IN_DESTRUCTOR_PHASE);
    ratelprof_add_to_buffer(json_buffer, "\t\t\"%d\": \"TOOL_FINI_PHASE\"\n\t},\n",RATELPROF_IN_TOOL_FINI_PHASE);
    ratelprof_add_to_buffer(json_buffer, "\t\"trace_events\": [\n");
}

void fini_json_content(ratelprof_buffer_t* json_buffer)
{
    ratelprof_lifecycle_t* lc = ratelprof_get_lifecycle(); 
    ratelprof_add_to_buffer(json_buffer, "\t],");
    ratelprof_add_to_buffer(json_buffer, "\n\t\"lifecycle\": {\n");
    ratelprof_add_to_buffer(json_buffer, "\t\t\"tool_init_start\": %lu,\n", ratelprof_get_timestamp_ns(lc->tool_init_start));
    ratelprof_add_to_buffer(json_buffer, "\t\t\"constructor_start\": %lu,\n", ratelprof_get_timestamp_ns(lc->constructor_start));
    ratelprof_add_to_buffer(json_buffer, "\t\t\"main_start\": %lu,\n", ratelprof_get_timestamp_ns(lc->main_start));
    ratelprof_add_to_buffer(json_buffer, "\t\t\"main_stop\": %lu,\n", ratelprof_get_timestamp_ns(lc->main_stop));
    ratelprof_add_to_buffer(json_buffer, "\t\t\"destructor_stop\": %lu,\n", ratelprof_get_timestamp_ns(lc->destructor_stop));
    ratelprof_add_to_buffer(json_buffer, "\t\t\"tool_init_stop\": %lu\n\t}\n}", ratelprof_get_timestamp_ns(lc->tool_fini_stop));
}

ratelprof_status_t ratelprof_plugin_initialize(ratelprof_plugin_t** plugin) 
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    if (plugin == NULL) return RATELPROF_STATUS_INVALID_PTR;
    if (*plugin != NULL) return RATELPROF_STATUS_PLUGIN_ALREADY_INIT;
    *plugin = (ratelprof_plugin_t*)malloc(sizeof(ratelprof_plugin_t));
    if (*plugin == NULL) return RATELPROF_STATUS_MALLOC_FAILED;
	(*plugin)->omp_tgt_callback_handler.on_enter_callback = on_enter_omp_tgt_callback;
	(*plugin)->omp_tgt_callback_handler.on_exit_callback = on_exit_omp_tgt_callback;
	(*plugin)->hsa_callback_handler.on_enter_callback = on_enter_hsa_callback;
	(*plugin)->hsa_callback_handler.on_exit_callback = on_exit_hsa_callback;
	(*plugin)->omp_tgt_rtl_callback_handler.on_enter_callback = on_enter_omp_tgt_rtl_callback;
	(*plugin)->omp_tgt_rtl_callback_handler.on_exit_callback = on_exit_omp_tgt_rtl_callback;
	(*plugin)->hip_callback_handler.on_enter_callback = on_enter_hip_callback;
	(*plugin)->hip_callback_handler.on_exit_callback = on_exit_hip_callback; 
    (*plugin)->activity_callback = activity_callback; 
    (*plugin)->json_buffer = (ratelprof_buffer_t*) malloc(sizeof(ratelprof_buffer_t));
    if (!(*plugin)->json_buffer) return RATELPROF_STATUS_MALLOC_FAILED;
    status = ratelprof_init_buffer((*plugin)->json_buffer, get_output_file(), 2048);
    init_json_content((*plugin)->json_buffer);
    return status;
}

ratelprof_status_t ratelprof_plugin_finalize(ratelprof_plugin_t** plugin) 
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    if (plugin == NULL) return RATELPROF_STATUS_INVALID_PTR;
    if (*plugin == NULL) return RATELPROF_STATUS_PLUGIN_IS_NULL;
    if (!(*plugin)->json_buffer) return RATELPROF_STATUS_INVALID_PTR;
    fini_json_content((*plugin)->json_buffer);
    status = ratelprof_flush_buffer((*plugin)->json_buffer);
    if (status != RATELPROF_STATUS_SUCCESS) return status;
    status = ratelprof_close_buffer((*plugin)->json_buffer);
    if (status != RATELPROF_STATUS_SUCCESS) return status;
    free((*plugin)->json_buffer);
    free(*plugin);
    *plugin = NULL;
    return status;
}

ratelprof_status_t ratelprof_get_api_callback(const ratelprof_plugin_t* plugin, ratelprof_domain_t domain, api_callback_handler_t* callback_handler) 
{
    if (plugin == NULL) return RATELPROF_STATUS_INVALID_PTR;
    switch(domain)
    {
		case RATELPROF_DOMAIN_OMP_TGT: *callback_handler = plugin->omp_tgt_callback_handler; break;
		case RATELPROF_DOMAIN_HSA: *callback_handler = plugin->hsa_callback_handler; break;
		case RATELPROF_DOMAIN_OMP_TGT_RTL: *callback_handler = plugin->omp_tgt_rtl_callback_handler; break;
		case RATELPROF_DOMAIN_HIP: *callback_handler = plugin->hip_callback_handler; break; 
        default: return RATELPROF_STATUS_UNKNOWN_DOMAIN;
    }
    return RATELPROF_STATUS_SUCCESS;
}


ratelprof_status_t ratelprof_get_activity_callback(const ratelprof_plugin_t* plugin, activity_callback_t* activity_callback, void** activity_callback_user_args) 
{
    if (plugin == NULL) return RATELPROF_STATUS_INVALID_PTR;
    if (activity_callback == NULL) return RATELPROF_STATUS_INVALID_PTR;
    if (activity_callback_user_args == NULL) return RATELPROF_STATUS_INVALID_PTR;
    *activity_callback = plugin->activity_callback;
    *activity_callback_user_args = plugin->json_buffer;
    return RATELPROF_STATUS_SUCCESS;
}
