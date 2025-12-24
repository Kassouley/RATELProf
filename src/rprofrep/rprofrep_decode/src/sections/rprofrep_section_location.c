#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "rprofrep_status.h"

#include "utils/rprofrep_decode_type.h"
#include "utils/rprofrep_read_utils.h"

#include "sections/rprofrep_section_location.h"
#include "sections/rprofrep_section_string.h"

#include "sections/rprofrep_section_ref.h"

// Free location section
rprofrep_status_t rprofrep_free_location_section(rprofrep_ref_section_t* section) {
    RPROFREP_CHECK_VALID_PTR(section);

    rprofrep_location_entry_t* entries = (rprofrep_location_entry_t*) section->entries;
    if (entries) free(entries);

    return RPROFREP_STATUS_SUCCESS;
}

// Decode the location section
rprofrep_status_t rprofrep_decode_location_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size,
    rprofrep_ref_section_t* data_out
) {
    size_t offset = 0; 
    size_t nentries_offset = size - sizeof(uint64_t);
    uint64_t nentries = __read_uint64(buffer, &nentries_offset);

    if (nentries > 0) {
        rprofrep_init_ref_section(data_out, nentries, sizeof(rprofrep_location_entry_t));
        rprofrep_location_entry_t* entries = (rprofrep_location_entry_t*) data_out->entries;

        for (uint64_t i = 0; i < nentries; i++) {
            entries[i].return_address = __read_mp_uint(buffer, &offset);
            rprofrep_get_string_by_id(ctx, __read_mp_uint(buffer, &offset), &entries[i].objectfile);
            rprofrep_get_string_by_id(ctx, __read_mp_uint(buffer, &offset), &entries[i].function);
            rprofrep_get_string_by_id(ctx, __read_mp_uint(buffer, &offset), &entries[i].filename);
            entries[i].line = __read_mp_uint(buffer, &offset);
        }
    }

    return RPROFREP_STATUS_SUCCESS;
}