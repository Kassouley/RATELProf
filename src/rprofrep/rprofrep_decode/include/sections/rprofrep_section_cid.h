#ifndef RPROFREP_SECTION_CID_H
#define RPROFREP_SECTION_CID_H

#include <stdint.h>

#include "rprofrep_core.h"

#include "utils/rprofrep_decode_type.h"

typedef struct rprofrep_cid_tuple_s {
    uint64_t group_id;
    uint64_t offset;
} rprofrep_cid_tuple_t;

typedef struct rprofrep_cid_section_s {
    void* cid_table;
    size_t num_entries;
} rprofrep_cid_section_t;

// Free the section
rprofrep_status_t rprofrep_free_cid_section(rprofrep_cid_section_t* section);

// Decode the section
rprofrep_status_t rprofrep_decode_cid_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size, 
    rprofrep_cid_section_t* out
);

rprofrep_status_t rprofrep_get_cid_tuple(
    rprofrep_decode_context_t* ctx, 
    uint64_t cid_key, 
    rprofrep_cid_tuple_t* out
);

#endif // RPROFREP_SECTION_CID_H
