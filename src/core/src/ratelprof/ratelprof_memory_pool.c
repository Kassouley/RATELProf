#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "ratelprof/ratelprof_status.h"
#include "ratelprof/ratelprof_memory_pool.h"


ratelprof_status_t ratelprof_memory_pool_init() {
    // No initialization needed for this simple implementation
    return RATELPROF_STATUS_SUCCESS;
}

ratelprof_status_t ratelprof_memory_pool_fini() {
    // No cleanup needed for this simple implementation
    return RATELPROF_STATUS_SUCCESS;
}

void* ratelprof_memory_pool_alloc(size_t size) {
    return malloc(size);
}

void ratelprof_memory_pool_free(void* ptr) {
    free(ptr);
}