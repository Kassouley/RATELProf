#include <stdio.h>
#include <stdlib.h>

#include "rprofrep_core.h"
#include "rprofrep_fwd.h"

#include "sections/rprofrep_section_cid.h"

rprofrep_status_t rprofrep_init_cid_section(rprofrep_cid_section_t* sct, const char* filename) {
    msgpack_init(&sct->buf, 0xFFFF, MSGPACK_OVERFLOW_WRITE_TO_FILE, filename);
    sct->nentries = 0;
    return RPROFREP_STATUS_SUCCESS;
}


void rprofrep_free_cid_section(rprofrep_cid_section_t* sct)
{
    msgpack_free(&sct->buf);
}


rprofrep_status_t rprofrep_write_cid_section(
    rprofrep_encode_context_t* ctx, 
    rprofrep_cid_section_t* sct, 
    const char* filename
) {
    (void) ctx;
    (void) filename;
    msgpack_push_bytes(&sct->buf, &sct->nentries, sizeof(sct->nentries));
    msgpack_write(&sct->buf);
    msgpack_flush(&sct->buf);
    return RPROFREP_STATUS_SUCCESS;
}


void rprofrep_cid_write_new_entry(rprofrep_encode_context_t* ctx, uint64_t id, uint64_t group_id, uint64_t group_off) {
    rprofrep_cid_section_t* sct = ctx->sections[RPROFREP_SECTION_CID].data;
    sct->nentries++;
    msgpack_encode_uint(&sct->buf, id);
    msgpack_encode_uint(&sct->buf, group_id);
    msgpack_encode_uint(&sct->buf, group_off - 1);
}
