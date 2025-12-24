#ifndef RPROFREP_SECTION_GLOBAL_H
#define RPROFREP_SECTION_GLOBAL_H

#include "rprofrep_core.h"
#include "rprofrep_fwd.h"

rprofrep_status_t rprofrep_write_global_section(rprofrep_encode_context_t* ctx, void* data, const char* filename);

#endif // RPROFREP_SECTION_GLOBAL_H