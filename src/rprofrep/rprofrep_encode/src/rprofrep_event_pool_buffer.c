#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "rprofrep_core.h"

#include "structure/dual_key_hash_table.h"

#include "rprofrep_event_pool_buffer.h"
#include "rprofrep_encode_type.h"


rprofrep_status_t rprofrep_init_event_pool_buffer(rprofrep_buffer_pool_t** out_pool)
{
    RPROFREP_CHECK_VALID_PTR(out_pool);
    rprofrep_buffer_pool_t* pool = (rprofrep_buffer_pool_t*) calloc(1, sizeof(rprofrep_buffer_pool_t));
    RPROFREP_CHECK_ALLOC(pool);

    pool->buffer = ht_create(0xFF);
    RPROFREP_CHECK_ALLOC(pool->buffer);

    pool->nb_buffers = 0;
    *out_pool = pool;
    return RPROFREP_STATUS_SUCCESS;
}

static void destroy_callback(void* value) {
    rprofrep_buffer_entry_t* entry = (rprofrep_buffer_entry_t*) value;
    msgpack_free(&entry->buffer);
    free(entry);
}

void rprofrep_destroy_event_pool_buffer(rprofrep_buffer_pool_t* pool)
{
    if (!pool) return;
    ht_destroy(pool->buffer, destroy_callback);
    free(pool);
}


rprofrep_buffer_entry_t* rprofrep_get_event_buffer(rprofrep_encode_context_t* ctx, ratelprof_domain_t domain, uint64_t unit, int64_t sub_unit)
{
    rprofrep_buffer_pool_t* pool = ctx->event_pool;
    hash_table_t* table = pool->buffer;
    ht_dual_key_t key = {unit, sub_unit};

    rprofrep_buffer_entry_t* entries = ht_get(table, key);
    if (!entries) {
        entries = (rprofrep_buffer_entry_t*) calloc(RATELPROF_NB_DOMAIN_EXT, sizeof(rprofrep_buffer_entry_t));
        ht_insert(table, key, entries);
    }

    rprofrep_buffer_entry_t* entry = &entries[domain];
    if (!entry->is_initialized) {
        entry->is_initialized = true;
        entry->id        = pool->nb_buffers;
        entry->nb_events = 0;
        entry->domain    = domain;
        entry->unit      = unit;
        entry->sub_unit  = sub_unit;
        BUILD_FILENAME(entry->filename, ctx->exp_tmp_dir, "rprofrep_events_%u_%lu_%lu", domain, unit, sub_unit);
        msgpack_init(&entry->buffer, 0xFFFF, MSGPACK_OVERFLOW_WRITE_TO_FILE, entry->filename);
        pool->nb_buffers++;
    }

    return entry;
}