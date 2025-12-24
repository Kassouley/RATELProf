#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "rprofrep_core.h"
#include "rprofrep_encode_type.h"

#include "rprofrep_concatenator.h"
#include "rprofrep_event_pool_buffer.h"

#include "sections/rprofrep_section_offsets.h"

#include "structure/dual_key_hash_table.h"

rprofrep_status_t rprofrep_write_offsets_and_concat_events_section(rprofrep_encode_context_t* ctx, void* data, const char* filename)
{
    (void) data;
    RPROFREP_CHECK_VALID_PTR(ctx, filename);
    uint64_t offset = 0;
    rprofrep_buffer_pool_t*    pool         = ctx->event_pool;
    hash_table_t*              table        = pool->buffer;
    rprofrep_concatenator_t*   concatenator = &ctx->concatenator;

    msgpack_buffer_t buf = {0};
    msgpack_init(&buf, 0xFFFF, MSGPACK_OVERFLOW_WRITE_TO_FILE, filename);

    msgpack_encode_uint(&buf, pool->nb_buffers);

    size_t nunits = 0;
    uint64_t *unit_values = ht_unique_k1(table, &nunits);
    RPROFREP_CHECK_ALLOC(unit_values);
    msgpack_encode_uint(&buf, nunits);

    for (size_t i = 0; i < nunits; i++) {
        uint64_t unit_value = unit_values[i];
        size_t nsubunits = 0;
        rprofrep_buffer_entry_t** buffer_entries = NULL;
        uint64_t* subunit_values = NULL;

        if(ht_values_by_k1(table, unit_value, (void***)&buffer_entries, &subunit_values, &nsubunits)) {
            return RPROFREP_STATUS_ALLOC_FAILED("Failed to get buffer entries by unit");
        }

        msgpack_encode_uint(&buf, unit_value);
        msgpack_encode_uint(&buf, nsubunits);

        for (size_t j = 0; j < nsubunits; j++) {
            msgpack_encode_int(&buf, subunit_values[j]);

            size_t domain_utils = 0;
            for (size_t d = 0; d < RATELPROF_NB_DOMAIN_EXT; d++) {
                rprofrep_buffer_entry_t* entry = &buffer_entries[j][d];
                if (entry->is_initialized) domain_utils++;
            }
            if (domain_utils == 0) {
                free(subunit_values);
                free(buffer_entries);
                return RPROFREP_STATUS_ERROR("No domain entries found for unit %lu subunit %ld (SHOULDN'T REACH)", unit_value, subunit_values[j]);
            }
            msgpack_encode_uint(&buf, domain_utils);

            for (size_t d = 0; d < RATELPROF_NB_DOMAIN_EXT; d++) {
                rprofrep_buffer_entry_t* entry = &buffer_entries[j][d];
                if (entry->is_initialized) {
                    msgpack_encode_uint(&buf, entry->domain);
                    msgpack_encode_uint(&buf, offset);
                    msgpack_encode_uint(&buf, entry->nb_events);
                    msgpack_encode_uint(&buf, entry->id);

                    msgpack_write(&entry->buffer);
                    msgpack_flush(&entry->buffer);
                    RPROFREP_CHECK_CALL(rprofrep_concatenator_concat_section(concatenator, entry->filename, RPROFREP_SECTION_EVENTS));
                    
                    offset += msgpack_size(&entry->buffer);
                }
            }
        }
        
        free(subunit_values);
        free(buffer_entries);
    }

    free(unit_values);
    
    msgpack_write(&buf);
    msgpack_free(&buf);

    return RPROFREP_STATUS_SUCCESS;
}