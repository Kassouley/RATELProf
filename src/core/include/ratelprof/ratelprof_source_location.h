#ifndef RATELPROF_SOURCE_LOCATION_H
#define RATELPROF_SOURCE_LOCATION_H

#include <stdint.h>
#include <stdbool.h>

#include "ratelprof/ratelprof_status.h"

typedef struct ratelprof_source_data_s {
    void *addr;
    const char *object_file;
    const char *source; 
    const char *func;
} ratelprof_source_data_t;

typedef struct cached_source_data_s {
    ratelprof_source_data_t location;
    struct cached_source_data_s *next;
} cached_source_data_t;

typedef bool (*ratelprof_cache_iter_cb_t)(ratelprof_source_data_t *location, void *user_data);

bool ratelprof_iterate_location_cache(ratelprof_cache_iter_cb_t callback, void *user_data);
ratelprof_status_t ratelprof_get_source_location(ratelprof_source_data_t* out, void *addr);
const char * ratelprof_format_source_location_string(const ratelprof_source_data_t *loc);
const char * ratelprof_format_binary_location_string(const ratelprof_source_data_t *loc);
void ratelprof_print_location(ratelprof_source_data_t loc);
void ratelprof_get_and_print_location(void *addr);
void ratelprof_cleanup_source_location(void);

#endif // RATELPROF_SOURCE_LOCATION_H