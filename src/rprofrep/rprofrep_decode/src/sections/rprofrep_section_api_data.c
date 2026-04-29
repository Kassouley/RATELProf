#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rprofrep_status.h"

#include "utils/rprofrep_decode_type.h"
#include "utils/rprofrep_read_utils.h"

#include "sections/rprofrep_section_api_data.h"
#include "sections/rprofrep_section_string.h"

#include "sections/rprofrep_section_ref.h"

// Free api_data section
rprofrep_status_t rprofrep_free_api_data_section(rprofrep_ref_section_t* section)
{
    rprofrep_api_data_entry_t* api_datas = (rprofrep_api_data_entry_t*) section->entries;
    if (api_datas)  {
        for (uint64_t i = 0; i < section->nentries; i++) {
            free(api_datas[i].arg_types);
            free(api_datas[i].arg_names);
        }
        free(api_datas);
    }

    return RPROFREP_STATUS_SUCCESS;
}

// Decode the api_data section
rprofrep_status_t rprofrep_decode_api_data_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size, 
    rprofrep_ref_section_t* data_out
) {
    size_t offset = 0; 
    char** arg_types = NULL;
    char** arg_names = NULL;
    rprofrep_api_data_entry_t* api_datas = NULL;
    uint64_t num_args      = 0;
    size_t nentries_offset = size - sizeof(uint64_t);
    uint64_t num_api_datas = __read_uint64(buffer, &nentries_offset);

    if (num_api_datas > 0) {
        rprofrep_init_ref_section(data_out, num_api_datas, sizeof(rprofrep_api_data_entry_t));
        api_datas = (rprofrep_api_data_entry_t*) data_out->entries;

        for (uint64_t i = 0; i < num_api_datas; i++) {
            uint64_t str_id = __read_mp_uint(buffer, &offset);
            rprofrep_get_string_by_id(ctx, str_id, &api_datas[i].fname);
            api_datas[i].fname_strid = str_id;
            num_args            = __read_mp_uint(buffer, &offset);

            if (num_args > 0) {
                arg_types = (char**) malloc(num_args * sizeof(char*));
                arg_names = (char**) malloc(num_args * sizeof(char*));
                for (uint64_t j = 0; j < num_args; j++)
                {
                    rprofrep_get_string_by_id(ctx, __read_mp_uint(buffer, &offset), &arg_types[j]);
                    rprofrep_get_string_by_id(ctx, __read_mp_uint(buffer, &offset), &arg_names[j]);
                }
                api_datas[i].num_args = num_args;
                api_datas[i].arg_types = arg_types;
                api_datas[i].arg_names = arg_names;
            }
        }
    }
    
    return RPROFREP_STATUS_SUCCESS;
}