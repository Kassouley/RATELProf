#ifndef RPROFREP_MSGPACK_EXT_H
#define RPROFREP_MSGPACK_EXT_H

#include <ratelprof.h>
#include <ratelprof_ext.h>

#include "rprofrep_encode_context.h"
#include "rprofrep_event_pool_buffer.h"
#include "rprofrep_msgpack_defs.h"

void rprofrep_msgpack_ext_encode_loc(
    rprofrep_encode_context_t* ctx, 
    msgpack_buffer_t *buf, 
    void* addr
);

void rprofrep_msgpack_ext_encode_string(
    rprofrep_encode_context_t* ctx, 
    msgpack_buffer_t *buf, 
    const char* str
);

void rprofrep_msgpack_ext_encode_api_data(
    rprofrep_encode_context_t* ctx, 
    msgpack_buffer_t *buf, 
    ratelprof_domain_t domain, 
    ratelprof_api_id_t funid
);

void rprofrep_msgpack_ext_encode_kernel(
    rprofrep_encode_context_t* ctx, 
    msgpack_buffer_t *buf, 
    uint32_t private_segment_size,
    uint32_t group_segment_size,
    uint64_t kernel_object
);

void rprofrep_msgpack_ext_encode_event(
    rprofrep_encode_context_t* ctx,
    rprofrep_buffer_entry_t* entry,
    size_t event_size,
    uint64_t id,
    bool has_children
);

void rprofrep_msgpack_ext_encode_cid(
    msgpack_buffer_t *buf, 
    uint64_t cid
);

void rprofrep_msgpack_ext_encode_args(
    rprofrep_encode_context_t* ctx,
    msgpack_buffer_t* buf,
    ratelprof_domain_t domain,
    ratelprof_api_id_t funid,
    const void* func_args
);

#endif // RPROFREP_MSGPACK_EXT_H