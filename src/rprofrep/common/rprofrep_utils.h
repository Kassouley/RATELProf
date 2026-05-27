#ifndef RPROFREP_UTILS_H
#define RPROFREP_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include <ratelprof.h>
#include <ratelprof_ext.h>

#include "rprofrep_defs.h"


static inline size_t get_file_size(const char *path) {
    struct stat st;
    if (stat(path, &st) == 0)
        return st.st_size;
    return -1;
}

static inline const char* get_section_name(rprofrep_section_id_t section_id) {
    switch (section_id)
    {
        case RPROFREP_SECTION_GLOBAL:       return "Global";            break;
        case RPROFREP_SECTION_STRING:       return "String";            break;
        case RPROFREP_SECTION_LOCATION:     return "Location";          break;
        case RPROFREP_SECTION_API_DATA:     return "API Data";          break;
        case RPROFREP_SECTION_KERNEL:       return "Kernel";            break;
        case RPROFREP_SECTION_GPU_SPEC:     return "GPU Specification"; break;
        case RPROFREP_SECTION_OFFSETS:      return "Offsets";           break;
        case RPROFREP_SECTION_EVENTS:       return "Events";            break;
        default: return "Unknown"; break;
    }
    return "Unknown";
}

// static inline const char* get_unit_name(ratelprof_domain_t domain) {
//     return is_gpu_domain(domain) ? "GPU" : "PID";
// }

// static inline const char* get_sub_unit_name(ratelprof_domain_t domain)
// {
//     if (!is_gpu_domain(domain))
//         return "TID";

//     return ((int)domain == RATELPROF_DOMAIN_COPY) ? "SDMA" : "QID";
// }

#endif // RPROFREP_UTILS_H