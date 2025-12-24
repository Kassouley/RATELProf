#ifndef RATELPROF_EXT_UTILS_H
#define RATELPROF_EXT_UTILS_H

#include <stdbool.h>

#include "ratelprof.h"
#include "ratelprof_ext.h"

#define GPU_MASK ((1u << RATELPROF_DOMAIN_COPY)       | \
                  (1u << RATELPROF_DOMAIN_KERNEL)     | \
                  (1u << RATELPROF_DOMAIN_BARRIERAND) | \
                  (1u << RATELPROF_DOMAIN_BARRIEROR))

static inline bool is_gpu_domain(ratelprof_domain_t domain) {
    return (GPU_MASK & (1u << domain)) != 0;
}

#endif // RATELPROF_EXT_UTILS_H