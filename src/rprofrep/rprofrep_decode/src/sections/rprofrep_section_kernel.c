#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rprofrep_status.h"

#include "utils/rprofrep_decode_type.h"
#include "utils/rprofrep_read_utils.h"

#include "sections/rprofrep_section_kernel.h"
#include "sections/rprofrep_section_string.h"

#include "sections/rprofrep_section_ref.h"

// Free kernel section
rprofrep_status_t rprofrep_free_kernel_section(rprofrep_ref_section_t* section)
{
    rprofrep_kernel_static_data_t* nentries = (rprofrep_kernel_static_data_t*) section->entries;
    if (nentries)  {
        free(nentries);
    }

    return RPROFREP_STATUS_SUCCESS;
}

// Decode the kernel section
rprofrep_status_t rprofrep_decode_kernel_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size,
    rprofrep_ref_section_t* data_out
) {
    size_t offset = 0;
    rprofrep_kernel_static_data_t* entries = NULL;
    size_t nentries_offset = size - sizeof(uint64_t);
    uint64_t nentries = __read_uint64(buffer, &nentries_offset);

    if (nentries > 0) {
        rprofrep_init_ref_section(data_out, nentries, sizeof(rprofrep_kernel_static_data_t));
        entries = (rprofrep_kernel_static_data_t*) data_out->entries;

        for (uint64_t i = 0; i < nentries; i++) {
            uint64_t str_id = __read_mp_uint(buffer, &offset);
            rprofrep_get_string_by_id(ctx, str_id, &entries[i].kernel_name);
            entries[i].kernel_strid         = str_id;
            entries[i].kernel_object        = __read_mp_uint(buffer, &offset);
            entries[i].group_segment_size   = __read_mp_uint(buffer, &offset);
            entries[i].private_segment_size = __read_mp_uint(buffer, &offset);
        }
    }
    
    return RPROFREP_STATUS_SUCCESS;
}