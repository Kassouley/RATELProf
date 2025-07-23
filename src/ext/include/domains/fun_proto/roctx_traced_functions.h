#ifndef ROCTX_TRACED_FUNCTIONS_H
#define ROCTX_TRACED_FUNCTIONS_H

#include "ratelprof_ext.h"

typedef uint64_t roctx_range_id_t;

// Function prototypes
int i_roctxRangePushA(const char* message);
int i_roctxRangePop();
roctx_range_id_t i_roctxRangeStartA(const char* message);
void i_roctxRangeStop(roctx_range_id_t id);
void i_roctxMarkA(const char* message);

// Function type 
typedef int (*__roctxRangePushA_t)(const char* message);
typedef int (*__roctxRangePop_t)();
typedef roctx_range_id_t (*__roctxRangeStartA_t)(const char* message);
typedef void (*__roctxRangeStop_t)(roctx_range_id_t id);
typedef void (*__roctxMarkA_t)(const char* message);

#endif // ROCTX_TRACED_FUNCTIONS_H
