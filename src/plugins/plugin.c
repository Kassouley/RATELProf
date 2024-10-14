/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#include "ratelprof_ext.h"
#include <ratelprof.h>
#include "activity_plugin.h" 
#include "hip_plugin.h"
#include "hsa_plugin.h" 

typedef struct ratelprof_plugin_s {
	api_callback_handler_t hip_callback_handler;
	api_callback_handler_t hsa_callback_handler; 
    activity_callback_t activity_callback;
    ratelprof_buffer_t* json_buffer;
} ratelprof_plugin_t;
    
ratelprof_status_t ratelprof_plugin_initialize(ratelprof_plugin_t** plugin) 
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    if (plugin == NULL) return RATELPROF_STATUS_INVALID_PTR;
    if (*plugin != NULL) return RATELPROF_STATUS_PLUGIN_ALREADY_INIT;
    *plugin = (ratelprof_plugin_t*)malloc(sizeof(ratelprof_plugin_t));
    if (*plugin == NULL) return RATELPROF_STATUS_MALLOC_FAILED;
	(*plugin)->hip_callback_handler.on_enter_callback = on_enter_hip_callback;
	(*plugin)->hip_callback_handler.on_exit_callback = on_exit_hip_callback;
	(*plugin)->hsa_callback_handler.on_enter_callback = on_enter_hsa_callback;
	(*plugin)->hsa_callback_handler.on_exit_callback = on_exit_hsa_callback; 
	(*plugin)->activity_callback = activity_callback; 
    (*plugin)->json_buffer = (ratelprof_buffer_t*) malloc(sizeof(ratelprof_buffer_t));
    if (!(*plugin)->json_buffer) return RATELPROF_STATUS_MALLOC_FAILED;
    status = ratelprof_init_buffer((*plugin)->json_buffer, get_output_file(), 2048);
    return status;
}

ratelprof_status_t ratelprof_plugin_finalize(ratelprof_plugin_t** plugin) 
{
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    if (plugin == NULL) return RATELPROF_STATUS_INVALID_PTR;
    if (*plugin == NULL) return RATELPROF_STATUS_PLUGIN_IS_NULL;
    if (!(*plugin)->json_buffer) return RATELPROF_STATUS_INVALID_PTR;
    status = ratelprof_flush_buffer((*plugin)->json_buffer);
    if (status != RATELPROF_STATUS_SUCCESS) return status;
    status = ratelprof_close_buffer((*plugin)->json_buffer);
    if (status != RATELPROF_STATUS_SUCCESS) return status;
    free((*plugin)->json_buffer);
    free(*plugin);
    *plugin = NULL;
    return status;
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

ratelprof_status_t ratelprof_get_api_callback(const ratelprof_plugin_t* plugin, ratelprof_domain_t domain, api_callback_handler_t* callback_handler) 
{
    if (plugin == NULL) return RATELPROF_STATUS_INVALID_PTR;
    switch(domain)
    {
		case RATELPROF_DOMAIN_HIP: *callback_handler = plugin->hip_callback_handler; break;
		case RATELPROF_DOMAIN_HSA: *callback_handler = plugin->hsa_callback_handler; break; 
        default: return RATELPROF_STATUS_UNKNOWN_DOMAIN;
    }
    return RATELPROF_STATUS_SUCCESS;
}
