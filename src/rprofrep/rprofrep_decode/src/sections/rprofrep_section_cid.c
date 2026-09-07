#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rprofrep_core.h"

#include "utils/rprofrep_decode_type.h"
#include "utils/rprofrep_read_utils.h"

#include "sections/rprofrep_report_section.h"
#include "sections/rprofrep_section_cid.h"

#define HT_VALUE_TYPE rprofrep_cid_tuple_t
#define HT_DEFAULT_VALUE (HT_VALUE_TYPE){0, 0}
#include "structure/uint64_key_hash_table.h"


// Free the section
rprofrep_status_t rprofrep_free_cid_section(rprofrep_cid_section_t* section) {
    if (!section) return RPROFREP_STATUS_SUCCESS;
    
    if(section->cid_table) {
        ht_destroy(section->cid_table);
        section->cid_table = NULL;
    }

    return RPROFREP_STATUS_SUCCESS;
}

// Decode the section
rprofrep_status_t rprofrep_decode_cid_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size, 
    rprofrep_cid_section_t* out
) {
    size_t offset = 0;
    size_t nentries_offset = size - sizeof(uint64_t);
    uint64_t num_cids = __read_uint64(buffer, &nentries_offset);

    if (num_cids > 0) {
        out->cid_table = ht_create(num_cids);

        for (uint64_t i = 0; i < num_cids; i++) {
            uint64_t cid_key = __read_mp_uint(buffer, &offset);
            rprofrep_cid_tuple_t cid_value;
            cid_value.group_id = __read_mp_uint(buffer, &offset);
            cid_value.offset = __read_mp_uint(buffer, &offset);
            ht_insert(out->cid_table, cid_key, cid_value);
        }
    }
    return RPROFREP_STATUS_SUCCESS;
}

rprofrep_status_t rprofrep_get_cid_tuple(
    rprofrep_decode_context_t* ctx, 
    uint64_t cid_key, 
    rprofrep_cid_tuple_t* out
) {
    RPROFREP_CHECK_VALID_PTR(ctx, out);
    
    rprofrep_cid_section_t* data = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_CID, (void**)&data));

    rprofrep_cid_tuple_t cid_value = ht_get(data->cid_table, cid_key);
    if (cid_value.group_id == HT_DEFAULT_VALUE.group_id && cid_value.offset == HT_DEFAULT_VALUE.offset) {
        return RPROFREP_STATUS_NOT_FOUND("CID not found in the table");
    }

    *out = cid_value;
    return RPROFREP_STATUS_SUCCESS;
}