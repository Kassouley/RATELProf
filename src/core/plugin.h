#ifndef RATELPROF_PLUGIN_H
#define RATELPROF_PLUGIN_H

#include <ratelprof.h>

// Forward declaration of the opaque structure
typedef struct ratelprof_plugin_s ratelprof_plugin_t;

// Function declarations

/**
 * @brief Initializes the ratelprof plugin.
 * 
 * @param plugin Pointer to the ratelprof plugin instance.
 * @return ratelprof_status_t The status of the initialization:
 *         - RATELPROF_STATUS_PLUGIN_ALREADY_INIT if the plugin is already initialized.
 *         - RATELPROF_STATUS_MALLOC_FAILED if memory allocation failed.
 *         - RATELPROF_STATUS_SUCCESS if initialization was successful.
 */
ratelprof_status_t ratelprof_plugin_initialize(ratelprof_plugin_t** plugin);

/**
 * @brief Finalizes the ratelprof plugin.
 * 
 * @param plugin Pointer to the ratelprof plugin instance.
 * @return ratelprof_status_t The status of the finalization:
 *         - RATELPROF_STATUS_PLUGIN_IS_NULL if the plugin is NULL.
 *         - RATELPROF_STATUS_SUCCESS if finalization was successful.
 */
ratelprof_status_t ratelprof_plugin_finalize(ratelprof_plugin_t** plugin);

/**
 * @brief Retrieves the API callback handler based on the domain.
 * 
 * @param plugin Pointer to the ratelprof plugin instance.
 * @param domain The domain for which the callback handler is requested (e.g., RATELPROF_DOMAIN_HIP, RATELPROF_DOMAIN_HSA).
 * @param callback_handler Pointer to where the retrieved callback handler will be stored.
 * @return ratelprof_status_t The status of the operation:
 *         - RATELPROF_STATUS_UNKNOWN_DOMAIN if the domain is not recognized.
 *         - RATELPROF_STATUS_SUCCESS if the callback handler was successfully retrieved.
 */
ratelprof_status_t ratelprof_get_api_callback(const ratelprof_plugin_t* plugin, ratelprof_domain_t domain, api_callback_handler_t* callback_handler);

ratelprof_status_t ratelprof_get_activity_callback(const ratelprof_plugin_t* plugin, activity_callback_t* activity_callback, void** activity_callback_user_args);

#endif // RATELPROF_PLUGIN_H
