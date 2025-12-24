#ifndef RPROFREP_EVENT_POOL_BUFFER_H
#define RPROFREP_EVENT_POOL_BUFFER_H

#include "rprofrep_core.h"

typedef struct rprofrep_buffer_entry_s {
    ratelprof_domain_t domain;
    uint64_t unit;
    uint64_t sub_unit;
    size_t nb_events;
    size_t id;
    msgpack_buffer_t buffer;
    char filename[512];
    bool is_initialized;
} rprofrep_buffer_entry_t;


typedef struct hash_table_s hash_table_t;

typedef struct rprofrep_buffer_pool_s {
    hash_table_t* buffer;
    size_t nb_buffers;
} rprofrep_buffer_pool_t;

#include "rprofrep_encode_type.h"

rprofrep_status_t rprofrep_init_event_pool_buffer(rprofrep_buffer_pool_t** out_pool);

void rprofrep_destroy_event_pool_buffer(rprofrep_buffer_pool_t* pool);

rprofrep_buffer_entry_t* rprofrep_get_event_buffer(rprofrep_encode_context_t* ctx, ratelprof_domain_t domain, uint64_t unit, int64_t sub_unit);


#endif // RPROFREP_EVENT_POOL_BUFFER_H