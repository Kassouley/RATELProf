#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "rprofrep_core.h"
#include "rprofrep_encode_type.h"

#include "structure/ref_hash_table.h"

#include "ref/rprofrep_reference.h"

rprofrep_status_t rprofrep_init_ref_section(rprofrep_reference_t* ref, const char* filename) {
    ref->ref_counter = 0;
    ref->ref_table = ht_create(0xFFFF);
    msgpack_init(&ref->buffer, 0xFFFF, MSGPACK_OVERFLOW_WRITE_TO_FILE, filename);
    RPROFREP_CHECK_ALLOC(ref->ref_table);
    return RPROFREP_STATUS_SUCCESS;
}


void rprofrep_free_ref_section(rprofrep_reference_t* ref)
{
    ht_destroy(ref->ref_table);
    ref->ref_counter = 0;
    ref->ref_table   = NULL;
    msgpack_free(&ref->buffer);
}


rprofrep_status_t rprofrep_write_ref_section(
    rprofrep_encode_context_t* ctx, 
    rprofrep_reference_t* data, 
    const char* filename
) {
    (void) ctx;
    (void) filename;
    msgpack_push_bytes(&data->buffer, &data->ref_counter, sizeof(data->ref_counter));
    msgpack_write(&data->buffer);
    msgpack_flush(&data->buffer);
    return RPROFREP_STATUS_SUCCESS;
}

static inline uint64_t get_ref_id(
    rprofrep_reference_t* ref,
    ht_key_t key, 
    bool *was_inserted
) {
    uint64_t ref_id = ref->ref_counter; 
    ht_get_or_insert(ref->ref_table, key, &ref_id, was_inserted);
    if (*was_inserted) ref->ref_counter++;
    return ref_id;
}

static inline rprofrep_reference_t* get_ref(rprofrep_encode_context_t* ctx, rprofrep_section_id_t id)
{
    return ctx->sections[id].data;
}


uint64_t rprofrep_string_get_ref(rprofrep_encode_context_t* ctx, const char* str)
{
    rprofrep_reference_t* ref = get_ref(ctx, RPROFREP_SECTION_STRING);
    ht_key_t key = {.mode = HT_STRING_KEY, .strkey = str};
    bool was_inserted = false;
    uint64_t ref_id = get_ref_id(ref, key, &was_inserted);

    if (was_inserted) msgpack_encode_string(&ref->buffer, str);
    return ref_id;
}


uint64_t rprofrep_location_get_ref(rprofrep_encode_context_t* ctx, void* addr)
{
    rprofrep_reference_t* ref = get_ref(ctx, RPROFREP_SECTION_LOCATION);
    ht_key_t key = {.mode = HT_UINT64_KEY, .u64key = (uint64_t)addr};
    bool was_inserted = false;
    uint64_t ref_id = get_ref_id(ref, key, &was_inserted);

    if (was_inserted) {
        ratelprof_source_data_t loc = {0};
        ratelprof_get_source_location(&loc, addr);

        #define str_or_unknown(str) str ? str : "??"
        uint64_t objfile_ref = rprofrep_string_get_ref(ctx, str_or_unknown(loc.object_file));
        uint64_t func_ref    = rprofrep_string_get_ref(ctx, str_or_unknown(loc.func));
        uint64_t source_ref  = rprofrep_string_get_ref(ctx, str_or_unknown(loc.source));
        #undef str_or_unknown

        msgpack_encode_uint(&ref->buffer, (uintptr_t) loc.addr);
        msgpack_encode_uint(&ref->buffer, objfile_ref);
        msgpack_encode_uint(&ref->buffer, func_ref);
        msgpack_encode_uint(&ref->buffer, source_ref);
        msgpack_encode_uint(&ref->buffer, loc.line);
    };
    return ref_id;
}


uint64_t rprofrep_kernel_get_ref(rprofrep_encode_context_t* ctx, rprofrep_kernel_static_data_t* data)
{
    rprofrep_reference_t* ref = get_ref(ctx, RPROFREP_SECTION_KERNEL);
    ht_key_t key = {.mode = HT_UINT64_KEY, .u64key = data->kernel_object};
    bool was_inserted = false;
    uint64_t ref_id = get_ref_id(ref, key, &was_inserted);

    if (was_inserted) {
        const char* kernel_name = get_kernel_name(data->kernel_object);
        msgpack_encode_string(&ref->buffer, kernel_name);
        msgpack_encode_uint(&ref->buffer, data->kernel_object);
        msgpack_encode_uint(&ref->buffer, data->group_segment_size);
        msgpack_encode_uint(&ref->buffer, data->private_segment_size);
    }
    return ref_id;
}