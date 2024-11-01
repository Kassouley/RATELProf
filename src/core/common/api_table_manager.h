/* # THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * # DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * # ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA.
 */ 

#ifndef API_TABLE_MANAGER_H 
#define API_TABLE_MANAGER_H 

#include <stddef.h>
#include <stdbool.h>
#include "ratelprof.h"

// Structure representing an API table entry
typedef struct api_table_s {
    ratelprof_domain_t domain;
    void* handler;
    void** api_fn;
    void** api_ptr;
    ratelprof_api_id_t size;
    bool is_populate;
} api_table_t;

// Function declarations

/**
 * Initializes the API table for a given domain.
 * @param domain The domain for which to initialize the API table.
 * @param api_table A pointer to the API table structure to initialize.
 * @param size The number of entries in the API table.
 * @return ratelprof_status_t indicating success or failure.
 */
ratelprof_status_t ratelprof_init_api_table(ratelprof_domain_t domain, api_table_t* api_table, ratelprof_api_id_t size);

/**
 * Populate the API table.
 * @param api_table A pointer to the API table structure to initialize.
 * @param lib_path The library to dlopen.
 * @return ratelprof_status_t indicating success or failure.
 */
ratelprof_status_t ratelprof_populate_api_table(api_table_t* api_table, const char* lib_path);

/**
 * Cleans up resources allocated for the API table.
 * @param api_table A pointer to the API table structure to clean up.
 * @return ratelprof_status_t indicating success or failure.
 */
ratelprof_status_t ratelprof_cleanup_api_table(api_table_t* api_table);

/**
 * Enables the API table by mapping functions according to the provided environment variable.
 * @param api_table A pointer to the API table structure to enable.
 * @param env_var_name The name of the environment variable containing the function filter.
 * @return ratelprof_status_t indicating success or failure.
 */
ratelprof_status_t ratelprof_enable_api_table(api_table_t* api_table, const char* env_var_name);

/**
 * Disables the API table by restoring the original function pointers.
 * @param api_table A pointer to the API table structure to disable.
 * @return ratelprof_status_t indicating success or failure.
 */
ratelprof_status_t ratelprof_disable_api_table(api_table_t* api_table);

/**
 * Fallback function that handles errors when an API function cannot be loaded.
 */
void fallback(void);

#endif // API_TABLE_MANAGER_H