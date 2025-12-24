#ifndef RPROFREP_SECTION_STRING_H
#define RPROFREP_SECTION_STRING_H

#include <stdint.h>

#include "rprofrep_status.h"
#include "utils/rprofrep_decode_type.h"
#include "sections/rprofrep_section_ref.h"

rprofrep_status_t rprofrep_free_string_section(
    rprofrep_ref_section_t* section);

rprofrep_status_t rprofrep_decode_string_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size, 
    rprofrep_ref_section_t* data_out);

#endif // RPROFREP_SECTION_STRING_H