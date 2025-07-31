#ifndef PROFILING_HSA_API_HELPER_H
#define PROFILING_HSA_API_HELPER_H

#ifdef ADD_API_PREFIX
#undef ADD_API_PREFIX
#endif
#define ADD_API_PREFIX(str) PROFILING_##str

#define FOR_EACH_PROFILING_FUNC(macro) \
    macro(hsa_signal_create) \
    macro(hsa_signal_destroy) \
    macro(hsa_signal_store_screlease) \
    macro(hsa_agent_get_info) \
    macro(hsa_amd_profiling_get_async_copy_time) \
    macro(hsa_amd_profiling_get_dispatch_time) \
    macro(hsa_amd_profiling_set_profiler_enabled) \
    macro(hsa_amd_profiling_async_copy_enable) \
    macro(hsa_executable_symbol_get_info) \
    macro(hsa_amd_signal_async_handler) \
    macro(hsa_iterate_agents)

    

typedef enum {
    FOR_EACH_PROFILING_FUNC(GET_FUNC_API_ID)
    ADD_API_PREFIX(ID_NB_FUNCTION),
    ADD_API_PREFIX(ID_UNKNOWN)
} profiling_id_t;


static inline const char* get_profiling_funame_by_id(profiling_id_t id) 
{
    switch(id) {
		FOR_EACH_PROFILING_FUNC(GET_FUNAME_BY_ID_OF)
        default : return NULL;
    }
    return NULL;
}
 

static inline profiling_id_t get_profiling_funid_by_name(const char* name) 
{
    if (name == NULL) return ADD_API_PREFIX(ID_UNKNOWN);
    FOR_EACH_PROFILING_FUNC(GET_FUNID_BY_NAME_OF)
    return ADD_API_PREFIX(ID_UNKNOWN);
}
 

static inline void* get_profiling_funaddr_by_id(profiling_id_t id) 
{
    switch(id) {
		FOR_EACH_PROFILING_FUNC(GET_FUNADDR_BY_ID_OF)
        default : return NULL;
    }
    return NULL;
}
 

#endif // PROFILING_HSA_API_HELPER_H
