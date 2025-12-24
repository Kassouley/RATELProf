#ifndef RPROFREP_SECTION_HEADER_H
#define RPROFREP_SECTION_HEADER_H

#include <stdint.h>

#include "rprofrep_status.h"
#include "rprofrep_defs.h"

#include "utils/rprofrep_decode_type.h"


/**
 * The function `rprofrep_decode_header_section` reads and decodes the header section of a RATELProf
 * report.
 * 
 * @param ctx Input of type `rprofrep_decode_context_t` used to store the context of the report. 
 * 
 * @return `rprofrep_status_t`
 */
rprofrep_status_t rprofrep_decode_header_section(rprofrep_decode_context_t* ctx);



/**
 * The function `rprofrep_get_section_buffer` reads a specific section from a report context and
 * returns the section buffer and size.
 * 
 * @param ctx Input of type `rprofrep_decode_context_t` used to store the context of the report. 
 * 
 * @param section_id The `section_id` parameter is of type `rprofrep_section_id_t` and represents the
 * identifier of the section that needs to be retrieved from the report context.
 * 
 * @param out_section_buffer This parameter is used to store the address of the
 * buffer where the section data will be read into.
 * 
 * @param out_section_size Variable where the size of the section buffer will be stored
 * after the function completes its operation. If the pointer is not NULL, the function will 
 * not store the size.
 * 
 * @return `rprofrep_status_t`
 */
rprofrep_status_t rprofrep_get_section_buffer(
    rprofrep_decode_context_t* ctx,
    rprofrep_section_id_t section_id,
    uint8_t** out_section_buffer,
    size_t* out_section_size);

#endif // RPROFREP_SECTION_HEADER_H