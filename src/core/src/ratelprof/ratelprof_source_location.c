#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <inttypes.h>
#include <pthread.h>

#include "ratelprof/ratelprof_source_location.h"
#include "ratelprof/ratelprof_status.h"


// Cache for location data
// Save for each address the location data
static cached_source_data_t *location_cache = NULL;
static pthread_mutex_t cache_mutex = PTHREAD_MUTEX_INITIALIZER;


/*
 * addr2line:
 *  - object_path: path to binary/shared-object (from dladdr->dli_fname)
 *  - addr: the runtime address
 *  - dli_fbase: base address (from dladdr->dli_fbase if available)
 *
 * On success:
 *   *out_func = strdup(<function name line>)
 *   *out_fileline = strdup(<file:line line>)
 * Caller must free() them.
 */
static bool addr2line(const char *object_path, void *addr, void *dli_fbase,
                                   char **out_func, char **out_fileline)
{
    // TODO (23/09/2025) : Support escape char in object_path ("'`\s etc.)
    if (!object_path || !addr || !out_func || !out_fileline) return false;
    uintptr_t uaddr = (uintptr_t)addr;
    uintptr_t base  = dli_fbase ? (uintptr_t)dli_fbase : 0;
    uintptr_t offset = base ? (uaddr - base) : uaddr;

    char addr_hex[32];
    snprintf(addr_hex, sizeof(addr_hex), "0x%" PRIxPTR, offset);

    char cmd[1024];
    int n = snprintf(cmd, sizeof(cmd),
                     "addr2line -e %s -f -C -i %s",
                     object_path, addr_hex);
    if (n < 0 || n >= (int)sizeof(cmd)) return false;

    FILE *fp = popen(cmd, "r");
    if (!fp) return false;

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    /* function name */
    read = getline(&line, &len, fp);
    if (read <= 0) { free(line); pclose(fp); return false; }
    if (read > 0 && line[read-1] == '\n') line[read-1] = '\0';
    *out_func = strdup(line);

    /* file:line */
    read = getline(&line, &len, fp);
    if (read <= 0) { free(line); pclose(fp); free(*out_func); *out_func=NULL; return false; }
    if (read > 0 && line[read-1] == '\n') line[read-1] = '\0';
    *out_fileline = strdup(line);

    free(line);
    pclose(fp);
    return true;
}


static bool match_addr_callback(ratelprof_source_data_t *location, void *user_data) {
    ratelprof_source_data_t *args = (ratelprof_source_data_t*) user_data;

    if (location->addr == args->addr) {
        *args = *location;
        return true;
    }
    return false;
}


static ratelprof_status_t add_new_cache_entry(ratelprof_source_data_t data) {
    cached_source_data_t *new_entry = malloc(sizeof(cached_source_data_t));
    if (!new_entry) {
        return RATELPROF_STATUS_MALLOC_FAILED;
    }

    new_entry->location = data;
    new_entry->next = NULL;

    pthread_mutex_lock(&cache_mutex);
    new_entry->next = location_cache;
    location_cache = new_entry;
    pthread_mutex_unlock(&cache_mutex);
    return RATELPROF_STATUS_SUCCESS;
}


ratelprof_status_t ratelprof_get_source_location(ratelprof_source_data_t* out, void *addr) {    
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;

    ratelprof_source_data_t tmp = {0};
    ratelprof_source_data_t *data = out ? out : &tmp;

    data->addr = addr;

    if (ratelprof_iterate_location_cache(match_addr_callback, data)) {
        return RATELPROF_STATUS_SUCCESS;
    }

    Dl_info info;
    if (!dladdr(addr, &info)) {
        status = add_new_cache_entry(*data);
        return status == RATELPROF_STATUS_SUCCESS ? RATELPROF_STATUS_DLADDR_FAILED : status;
    }

    data->object_file = info.dli_fname ? strdup(info.dli_fname) : NULL;

    char *func   = NULL;
    char* source = NULL;

    if (info.dli_fname && addr2line(info.dli_fname, addr, info.dli_fbase, &func, &source)) {
        data->func     = func;
        data->source   = source;
    } else {
        status = add_new_cache_entry(*data);
        return status;
    }

    return add_new_cache_entry(*data);
}


bool ratelprof_iterate_location_cache(ratelprof_cache_iter_cb_t callback, void *user_data) {
    pthread_mutex_lock(&cache_mutex);
    for (cached_source_data_t *entry = location_cache; entry; entry = entry->next) {
        if (callback(&entry->location, user_data)) {
            pthread_mutex_unlock(&cache_mutex);
            return true;
        }
    }
    pthread_mutex_unlock(&cache_mutex);
    return false;
}


const char * ratelprof_format_source_location_string(const ratelprof_source_data_t *loc) {
    const char *func     = loc->func ? loc->func : "??";
    const char *source   = loc->source ? loc->source : "??:??";

    size_t len = snprintf(NULL, 0, "%s from %s", func, source);
    char *buf = malloc(len + 1);
    if (!buf) return NULL;

    snprintf(buf, len + 1, "%s from %s", func, source);
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


void ratelprof_cleanup_source_location(void) {
    // ---- Free caller/source location cache ----
    pthread_mutex_lock(&cache_mutex);
    cached_source_data_t *entry = location_cache;
    while (entry) {
        cached_source_data_t *next = entry->next;

        if (entry->location.object_file)
            free((void *)entry->location.object_file);
        if (entry->location.source)
            free((void *)entry->location.source);
        if (entry->location.func)
            free((void *)entry->location.func);

        free(entry);
        entry = next;
    }
    location_cache = NULL;
    pthread_mutex_unlock(&cache_mutex);
}