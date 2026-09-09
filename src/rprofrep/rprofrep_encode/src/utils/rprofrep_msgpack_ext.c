#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "rprofrep_core.h"

#include "utils/rprofrep_msgpack_ext.h"
#include "utils/rprofrep_argument_manager.h"

#include "ref/rprofrep_reference.h"
#include "ref/rprofrep_api_reference.h"

#include "sections/rprofrep_section_cid.h"

#include "structure/cid_stack.h"

#include "rprofrep_event_pool_buffer.h"

#include "rprofrep_encode_type.h"

void rprofrep_msgpack_ext_encode_loc(
    rprofrep_encode_context_t* ctx, 
    msgpack_buffer_t *buf, 
    void* addr
) {
    uint64_t ref = rprofrep_location_get_ref(ctx, addr);
    msgpack_encode_uint(buf, ref);
}


void rprofrep_msgpack_ext_encode_string(
    rprofrep_encode_context_t* ctx, 
    msgpack_buffer_t *buf, 
    const char* str
) {
    uint64_t ref = rprofrep_string_get_ref(ctx, str);
    msgpack_encode_uint(buf, ref);
}


void rprofrep_msgpack_ext_encode_api_data(
    rprofrep_encode_context_t* ctx, 
    msgpack_buffer_t *buf, 
    ratelprof_domain_t domain, 
    ratelprof_api_id_t funid
) {
    uint64_t ref = rprofrep_api_data_get_ref(ctx, domain, funid);
    msgpack_encode_uint(buf, ref);
}


void rprofrep_msgpack_ext_encode_kernel(
    rprofrep_encode_context_t* ctx, 
    msgpack_buffer_t *buf, 
    uint32_t private_segment_size,
    uint32_t group_segment_size,
    uint64_t kernel_object
) {
    rprofrep_kernel_static_data_t kernel_data = {
        .private_segment_size = private_segment_size,
        .group_segment_size   = group_segment_size,
        .kernel_object        = kernel_object,
    };

    uint64_t ref = rprofrep_kernel_get_ref(ctx, &kernel_data);
    msgpack_encode_uint(buf, ref);
}

void rprofrep_msgpack_ext_encode_cid(
    msgpack_buffer_t *buf, 
    uint64_t cid
) {
    if (cid != 0) {
        msgpack_push_byte(buf, 0xc6);
        msgpack_encode_uint(buf, cid);
    }
}

void rprofrep_msgpack_ext_encode_event(
    rprofrep_encode_context_t* ctx,
    rprofrep_buffer_entry_t* entry,
    size_t event_size,
    uint64_t id,
    bool has_children
) {
    msgpack_buffer_t* buf = &entry->buffer;
    entry->nb_events++;

    msgpack_reverse_encode_uint(buf, event_size);
    msgpack_push_byte(buf, 0xc1);

    if (has_children) {
        rprofrep_cid_write_new_entry(ctx, id, entry->id, msgpack_size(buf));
    }
}

void rprofrep_msgpack_ext_encode_args(
    rprofrep_encode_context_t* ctx,
    msgpack_buffer_t* buf,
    ratelprof_domain_t domain,
    ratelprof_api_id_t funid,
    const void* func_args
) {
    rprofrep_write_args(ctx, buf, domain, funid, func_args);
}