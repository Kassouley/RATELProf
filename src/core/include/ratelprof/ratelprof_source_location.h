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
    uint64_t line;
} ratelprof_source_data_t;


ratelprof_status_t ratelprof_get_source_location(ratelprof_source_data_t* out, void *addr);
const char * ratelprof_format_source_location_string(const ratelprof_source_data_t *loc);
const char * ratelprof_format_binary_location_string(const ratelprof_source_data_t *loc);
void ratelprof_print_location(ratelprof_source_data_t loc);
void ratelprof_get_and_print_location(void *addr);

#endif // RATELPROF_SOURCE_LOCATION_H