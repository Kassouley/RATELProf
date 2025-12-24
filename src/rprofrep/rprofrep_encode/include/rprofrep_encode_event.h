#ifndef RPROFREP_ENCODE_EVENT_H
#define RPROFREP_ENCODE_EVENT_H

#include <ratelprof.h>
#include <ratelprof_ext.h>

#include "rprofrep_encode_context.h"

void rprofrep_encode_activity_to_buffer(
    rprofrep_encode_context_t* ctx,
    ratelprof_domain_t domain,
    const void* activity
);

#endif // RPROFREP_ENCODE_EVENT_H