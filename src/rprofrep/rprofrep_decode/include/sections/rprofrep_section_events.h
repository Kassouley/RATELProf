#ifndef RPROFREP_SECTION_EVENTS_H
#define RPROFREP_SECTION_EVENTS_H

#include <stdint.h>
#include <stdlib.h>

#include "rprofrep_status.h"

#include "utils/rprofrep_decode_type.h"


typedef struct rprofrep_events_section_s {
    uint8_t* buffer;
    void* base_address;
    size_t size;
    size_t mapped_size;
} rprofrep_events_section_t;


/**
 * The function `rprofrep_get_mmap_events_section` maps a section of a file into memory for reading.
 * 
 * @param ctx Input of type `rprofrep_decode_context_t` used to store the context of the report. 
 * 
 * @return `rprofrep_status_t`
 */
rprofrep_status_t rprofrep_decode_events_section(rprofrep_decode_context_t* ctx, rprofrep_events_section_t* out);


/**
 * The function `rprofrep_free_events_section` frees memory allocated for events section in a report
 * context.
 * 
 * @param section `rprofrep_events_section_t` structure to free.
 * 
 * @return `rprofrep_status_t`
 */
rprofrep_status_t rprofrep_free_events_section(rprofrep_events_section_t* section);

#endif // RPROFREP_SECTION_EVENTS_H