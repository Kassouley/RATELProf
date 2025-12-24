#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <inttypes.h>
#include <pthread.h>

#include "ratelprof/ratelprof_source_location.h"
#include "ratelprof/ratelprof_status.h"


/*
 * addr2line:
 *  - object_path: path to binary/shared-object (from dladdr->dli_fname)
 *  - addr: the runtime address
 *  - dli_fbase: base address (from dladdr->dli_fbase if available)
 *
 * On success:
 *   *out_func = strdup(<function name>)
 *   *out_file = strdup(<file>)
 *   *out_line = line_number
 * Caller must free() them.
 */
static bool addr2line(const char *object_path, void *addr, void *dli_fbase,
                                   char **out_func, char **out_file, uint64_t *out_line)
{
    // TODO (23/09/2025) : Support escape char in object_path ("'`\s etc.)
    if (!object_path || !addr || !out_func || !out_file || !out_line) return false;
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
    
    /* split file and line */
    char *colon = strrchr(line, ':');
    if (!colon) {
        *out_file = strdup(line);
        *out_line = 0;
    } else {
        *colon = '\0';
        *out_file = strdup(line);
        *out_line = atoi(colon + 1);
    }

    free(line);
    pclose(fp);
    return true;
}



ratelprof_status_t ratelprof_get_source_location(ratelprof_source_data_t* out, void *addr) {    
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;

    out->addr = addr;

    Dl_info info;
    if (!dladdr(addr, &info)) {
        return RATELPROF_STATUS_DLADDR_FAILED;
    }

    out->object_file = info.dli_fname ? strdup(info.dli_fname) : NULL;

    char *func   = NULL;
    char* source = NULL;
    uint64_t line = 0;

    if (info.dli_fname && addr2line(info.dli_fname, addr, info.dli_fbase, &func, &source, &line)) {
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