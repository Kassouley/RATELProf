#ifndef RPROFREP_SECTION_CID_H
#define RPROFREP_SECTION_CID_H

#include <stdio.h>
#include <stdlib.h>

#include "rprofrep_core.h"
#include "rprofrep_encode_type.h"

typedef struct rprofrep_cid_section_s {
    size_t nentries;
    msgpack_buffer_t buf;
} rprofrep_cid_section_t;


rprofrep_status_t rprofrep_init_cid_section(rprofrep_cid_section_t* sct, const char* filename);

void rprofrep_free_cid_section(rprofrep_cid_section_t* sct);

rprofrep_status_t rprofrep_write_cid_section(
    rprofrep_encode_context_t* ctx, 
    rprofrep_cid_section_t* sct, 
    const char* filename
);

void rprofrep_cid_write_new_entry(rprofrep_encode_context_t* ctx, uint64_t id, uint64_t group_id, uint64_t group_off);

#endif // RPROFREP_SECTION_CID_H