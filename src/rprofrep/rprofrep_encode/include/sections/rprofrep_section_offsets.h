#ifndef RPROFREP_SECTION_OFFSETS_H
#define RPROFREP_SECTION_OFFSETS_H

#include "rprofrep_core.h"
#include "rprofrep_fwd.h"

rprofrep_status_t rprofrep_write_offsets_and_concat_events_section(rprofrep_encode_context_t* ctx, void* data, const char* filename);

#endif // RPROFREP_SECTION_OFFSETS_H