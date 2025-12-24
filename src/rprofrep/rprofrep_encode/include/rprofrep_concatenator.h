#ifndef RPROFREP_CONCATENATOR_H
#define RPROFREP_CONCATENATOR_H

#include <stdlib.h>

#include "rprofrep_core.h"

typedef struct { 
    int fd;
    size_t size;
    rprofrep_header_section_t header;
} rprofrep_concatenator_t;


rprofrep_status_t rprofrep_concatenator_write_header(rprofrep_concatenator_t* concatenator);

rprofrep_status_t rprofrep_concatenator_init(rprofrep_concatenator_t* concatenator, const char* filepath);

rprofrep_status_t rprofrep_concatenator_destroy(rprofrep_concatenator_t* concatenator);

rprofrep_status_t rprofrep_concatenator_concat_section(
    rprofrep_concatenator_t* concatenator, 
    const char* filename,
    rprofrep_section_id_t section_id);

#endif // RPROFREP_CONCATENATOR_H