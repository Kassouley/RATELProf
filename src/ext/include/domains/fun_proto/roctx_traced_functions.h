#ifndef ROCTX_TRACED_FUNCTIONS_H
#define ROCTX_TRACED_FUNCTIONS_H

#include "ratelprof_ext.h"

typedef uint64_t roctx_range_id_t;

// Function prototypes
int i_roctxRangePushA(const char* message, void* return_address);
int i_roctxRangePop();
roctx_range_id_t i_roctxRangeStartA(const char* message, void* return_address);
void i_roctxRangeStop(roctx_range_id_t id);
void i_roctxMarkA(const char* message, void* return_address);

// Function type 
typedef int (*__roctxRangePushA_t)(const char* message, void* return_address);
typedef int (*__roctxRangePop_t)();
typedef roctx_range_id_t (*__roctxRangeStartA_t)(const char* message, void* return_address);
typedef void (*__roctxRangeStop_t)(roctx_range_id_t id);
typedef void (*__roctxMarkA_t)(const char* message, void* return_address);

#endif // ROCTX_TRACED_FUNCTIONS_H
