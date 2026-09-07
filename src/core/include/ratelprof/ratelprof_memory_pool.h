#ifndef RATELPROF_MEMORY_POOL_H
#define RATELPROF_MEMORY_POOL_H

#include <stddef.h>

void* ratelprof_memory_pool_alloc(size_t size);
void ratelprof_memory_pool_free(void* ptr);
ratelprof_status_t ratelprof_memory_pool_init();
ratelprof_status_t ratelprof_memory_pool_fini();

#endif // RATELPROF_MEMORY_POOL_H