#ifndef RPROFREP_DECODE_CONTEXT_H
#define RPROFREP_DECODE_CONTEXT_H

#include <stdint.h>

#include "rprofrep_status.h"

#include "utils/rprofrep_decode_type.h"

rprofrep_status_t rprofrep_decode_context_init(
    rprofrep_decode_context_t* ctx,
    const char* filepath
);

rprofrep_status_t rprofrep_decode_context_free(rprofrep_decode_context_t* ctx);


#endif // RPROFREP_DECODE_CONTEXT_H