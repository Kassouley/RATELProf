#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "rprofrep_core.h"

#include "utils/rprofrep_msgpack_ext.h"
#include "utils/rprofrep_argument_manager.h"

#include "ref/rprofrep_reference.h"
#include "ref/rprofrep_api_reference.h"

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
    rprofrep_encode_context_t* ctx, 
    msgpack_buffer_t* buf, 
    uint64_t evt_id,
    uint64_t evt_cid,
    rprofrep_buffer_entry_t* buffer_entry
) {
    rprofrep_cid_manager_t* cid_stack = ctx->cid_stack;
    rprofrep_cid_entry_t cid_entry = {0};
    while (stack_peek(cid_stack, &cid_entry)) {
        if (cid_entry.id == evt_cid) {
            msgpack_encode_ext(buf, MSGPACK_EXT_CID, NULL, 1);
            msgpack_encode_uint(buf, cid_entry.group_id);
            msgpack_encode_uint(buf, cid_entry.event_off);
            break;
        }
        stack_pop(cid_stack, &cid_entry);
    }

    rprofrep_cid_entry_t new_entry = {
        evt_id,
        buffer_entry->id,
        msgpack_size(&buffer_entry->buffer)
    };
    stack_push(cid_stack, new_entry);
    return;
}

void rprofrep_msgpack_ext_encode_event(
    rprofrep_buffer_entry_t* entry,
    msgpack_buffer_t* event_buffer
) {
    msgpack_buffer_t* buf = &entry->buffer;
    entry->nb_events++;

    msgpack_push_byte(buf, 0xc1);
    msgpack_encode_uint(buf, msgpack_size(event_buffer));
    msgpack_concat(buf, event_buffer);

    msgpack_free(event_buffer);
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