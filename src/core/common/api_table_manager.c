/* # THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * # DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * # ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA.
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <stdbool.h>
#include "logger.h"
#include "api_table_manager.h"
#include "ratelprof.h"

ratelprof_status_t ratelprof_init_api_table(ratelprof_domain_t domain, api_table_t* api_table, ratelprof_api_id_t size) 
{
    if (!api_table) return RATELPROF_STATUS_INVALID_PTR;
    api_table->size = size;
    api_table->domain = domain;
    api_table->api_ptr = (void**)malloc(size * sizeof(void*));
    if (!api_table->api_ptr) return RATELPROF_STATUS_MALLOC_FAILED;
    api_table->api_fn = (void**)malloc(size * sizeof(void*));
    if (!api_table->api_fn) return RATELPROF_STATUS_MALLOC_FAILED;
    api_table->handler = NULL;
    api_table->is_populate = false;
    
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t ratelprof_populate_api_table(api_table_t* api_table, const char* lib_path) 
{
    api_table->handler = dlopen(lib_path, RTLD_LOCAL | RTLD_LAZY);
    if (!api_table->handler) return RATELPROF_STATUS_DLOPEN_FAILED;
    for (ratelprof_api_id_t id = 0; id < api_table->size; id++)
    {
        const char* funame = get_funame_by_id(api_table->domain, id);
        void* fn = (void*)(dlsym(api_table->handler, funame));
        if (!fn) {
            LOG_MESSAGE("Failed to load \"%s\". (%s) Skipping.", funame, dlerror());
            fn = (void*)fallback;
        }
        api_table->api_fn[id] = fn;
        api_table->api_ptr[id] = fn;
    }
    api_table->is_populate = true;
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t ratelprof_cleanup_api_table(api_table_t* api_table) 
{
    if (api_table == NULL) return RATELPROF_STATUS_API_TABLE_IS_NULL;
    dlclose(api_table->handler);
    free(api_table->api_ptr);
    free(api_table->api_fn);
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t ratelprof_enable_api_table(api_table_t* api_table, const char* env_var_name) 
{
    if (api_table == NULL) return RATELPROF_STATUS_API_TABLE_IS_NULL;
    if (api_table->api_fn == NULL) return RATELPROF_STATUS_API_TABLE_NOT_INIT;
    if (api_table->api_ptr == NULL) return RATELPROF_STATUS_API_TABLE_NOT_INIT;
    const char *env_var = get_function_filter(env_var_name);
    ratelprof_api_id_t id = 0;
    if (env_var != NULL) {
        char* functions = strdup(env_var);
        char* token = strtok(functions, ",");

        while (token) {
            id = get_funid_by_name(api_table->domain, token);
            if (id >= 0 && id < api_table->size) {
                api_table->api_ptr[id] = get_funaddr_by_id(api_table->domain, id);
            }
            token = strtok(NULL, ",");
        }
        free(functions);
    } else {
        for (id = 0; id < api_table->size; id++)
        {
            api_table->api_ptr[id] = get_funaddr_by_id(api_table->domain, id);
        }
    }
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t ratelprof_disable_api_table(api_table_t* api_table) 
{
    if (api_table == NULL) return RATELPROF_STATUS_API_TABLE_IS_NULL;
    if (api_table->api_fn == NULL) return RATELPROF_STATUS_API_TABLE_NOT_INIT;
    if (api_table->api_ptr == NULL) return RATELPROF_STATUS_API_TABLE_NOT_INIT;
    for (ratelprof_api_id_t id = 0; id < api_table->size; id++)
    {
        api_table->api_ptr[id] = api_table->api_fn[id];
    }
    return RATELPROF_STATUS_SUCCESS;
}

void fallback(void) {
    fprintf(stderr, "Critical error: Unable to load a function. See logs for more details.\n");
    exit(EXIT_FAILURE);
}
