#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rprofrep_status.h"

#include "utils/rprofrep_decode_type.h"
#include "utils/rprofrep_read_utils.h"

#include "sections/rprofrep_section_string.h"

#include "sections/rprofrep_section_ref.h"

// Free string section
rprofrep_status_t rprofrep_free_string_section(rprofrep_ref_section_t* section)
{
    char** strings = (char**) section->entries;

    if (strings)  {
        for (uint64_t i = 0; i < section->nentries; i++) {
            free(strings[i]);
        }
        free(strings);
    }

    return RPROFREP_STATUS_SUCCESS;
}


// Decode the string section
rprofrep_status_t rprofrep_decode_string_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size, 
    rprofrep_ref_section_t* data_out
) {
    size_t offset = 0;
    size_t nentries_offset = size - sizeof(uint64_t);
    uint64_t num_strings = __read_uint64(buffer, &nentries_offset);

    if (num_strings > 0) {
        rprofrep_init_ref_section(data_out, num_strings, sizeof(char*));
        char **strings  = (char**) data_out->entries;

        for (uint64_t i = 0; i < num_strings; i++) {
            strings[i] = __read_mp_string(buffer, &offset);
        }
    }
    return RPROFREP_STATUS_SUCCESS;
}