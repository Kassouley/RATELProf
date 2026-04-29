#ifndef RPROFREP_SECTION_API_DATA_H
#define RPROFREP_SECTION_API_DATA_H

#include <stdint.h>

#include "rprofrep_status.h"

#include "utils/rprofrep_decode_type.h"

typedef struct rprofrep_api_data_entry_s {
    char* fname;
    uint64_t fname_strid;
    size_t num_args;
    char** arg_types;
    char** arg_names;
} rprofrep_api_data_entry_t;

#include "sections/rprofrep_section_ref.h"

rprofrep_status_t rprofrep_free_api_data_section(rprofrep_ref_section_t* section);

rprofrep_status_t rprofrep_decode_api_data_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size, 
    rprofrep_ref_section_t* data_out
);


#endif // RPROFREP_SECTION_API_DATA_H