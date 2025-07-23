#include <stdint.h>
#include <stdlib.h>

#include "domains/fun_proto/roctx_traced_functions.h"

#define DEFAULT_RANGE_ACTIVITIES_CAPACITY 1024

#ifdef ADD_API_PREFIX
#undef ADD_API_PREFIX
#endif
#define ADD_API_PREFIX(str) ROCTX_API_##str


#define FOR_EACH_ROCTX_FUNC(macro) \
    macro(roctxRangePushA)         \
    macro(roctxRangePop)           \
    macro(roctxRangeStartA)        \
    macro(roctxRangeStop)          \
    macro(roctxMarkA)

    

typedef enum {
    FOR_EACH_ROCTX_FUNC(RATELPROF_API_ID)
    ADD_API_PREFIX(ID_NB_FUNCTION),
    ADD_API_PREFIX(ID_UNKNOWN)
} roctx_api_id_t;


static inline const char* get_roctx_funame_by_id(roctx_api_id_t id) 
{
    switch(id) {
		FOR_EACH_ROCTX_FUNC(RATELPROF_GET_FUNAME_BY_ID_OF)
        default : return NULL;
    }
    return NULL;
}
 

static inline roctx_api_id_t get_roctx_funid_by_name(const char* name) 
{
    if (name == NULL) return ADD_API_PREFIX(ID_UNKNOWN);
    FOR_EACH_ROCTX_FUNC(RATELPROF_GET_FUNID_BY_NAME_OF)
    return ADD_API_PREFIX(ID_UNKNOWN);
}
 

static inline void* get_roctx_funaddr_by_id(roctx_api_id_t id) 
{
    switch(id) {
		FOR_EACH_ROCTX_FUNC(RATELPROF_GET_FUNADDR_BY_ID_OF)
        default : return NULL;
    }
    return NULL;
}
 