#ifndef RPROFREP_SECTION_LOCATION_H
#define RPROFREP_SECTION_LOCATION_H

#include <stdint.h>

#include "rprofrep_status.h"

#include "utils/rprofrep_decode_type.h"

typedef struct rprofrep_location_entry_t {
    uint64_t return_address;
    char* objectfile;
    char* function;
    char* filename;
    uint64_t line;
} rprofrep_location_entry_t;

#include "sections/rprofrep_section_ref.h"

rprofrep_status_t rprofrep_free_location_section(rprofrep_ref_section_t* section);

rprofrep_status_t rprofrep_decode_location_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size, 
    rprofrep_ref_section_t* data_out
);

#endif // RPROFREP_SECTION_LOCATION_H