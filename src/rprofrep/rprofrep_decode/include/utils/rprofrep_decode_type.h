#ifndef RPROFREP_DECODE_TYPE_H
#define RPROFREP_DECODE_TYPE_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include <ratelprof.h>
#include <ratelprof_ext.h>

#include "rprofrep_defs.h"

typedef struct rprofrep_cid_tuple_s {
    bool valid;
    uint64_t group_id;
    uint64_t offset;
} rprofrep_cid_tuple_t;

typedef struct rprofrep_report_section_s {
    bool is_decoded;
    void* data;
} rprofrep_report_section_t;

typedef struct rprofrep_report_context_s {
    rprofrep_header_section_t header;
    rprofrep_report_section_t sections[RPROFREP_NB_SECTIONS];
    size_t size;
    FILE* handle;
} rprofrep_decode_context_t;

#endif // RPROFREP_DECODE_TYPE_H