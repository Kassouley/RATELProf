#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <inttypes.h>
#include <pthread.h>

#include "ratelprof/ratelprof_source_location.h"
#include "ratelprof/ratelprof_status.h"

#include "utils/addr2line.h"

ratelprof_status_t ratelprof_get_source_location(ratelprof_source_data_t* out, void *addr) {    
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;

    out->addr = addr;

    Dl_info info;
    if (!dladdr(addr, &info)) {
        return RATELPROF_STATUS_DLADDR_FAILED;
    }

    out->object_file = info.dli_fname ? strdup(info.dli_fname) : NULL;
    out->base_addr = info.dli_fbase;

    char *func   = NULL;
    char* source = NULL;
    uint64_t line = 0;

    if (addr2line(info.dli_fname, addr, info.dli_fbase, &func, &source, &line)) {
        out->func     = func;
        out->source   = source;
        out->line     = line;
    } 

    return status;
}


const char * ratelprof_format_source_location_string(const ratelprof_source_data_t *loc) {
    const char *func     = loc->func ? loc->func : "??";
    const char *source   = loc->source ? loc->source : "??";

    size_t len = snprintf(NULL, 0, "%s from %s:%ld", func, source, loc->line);
    char *buf = malloc(len + 1);
    if (!buf) return NULL;

    snprintf(buf, len + 1, "%s from %s:%ld", func, source, loc->line);
    return buf;
}

const char * ratelprof_format_binary_location_string(const ratelprof_source_data_t *loc) {
    const char *object   = loc->object_file ? loc->object_file : "<unknown>";
    void *addr           = loc->addr;

    size_t len = snprintf(NULL, 0, "%s at %p", object, addr);
    char *buf = malloc(len + 1);
    if (!buf) return NULL;

    snprintf(buf, len + 1, "%s at %p", object, addr);
    return buf;
}

void ratelprof_print_location(ratelprof_source_data_t loc) {
    printf("%s [%s]\n", 
        ratelprof_format_source_location_string(&loc), 
        ratelprof_format_binary_location_string(&loc));
}

void ratelprof_get_and_print_location(void *addr) {
    ratelprof_source_data_t loc = {0};
    ratelprof_get_source_location(&loc, addr);
    ratelprof_print_location(loc);
}