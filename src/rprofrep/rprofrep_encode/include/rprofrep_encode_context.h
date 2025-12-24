#ifndef RPROFREP_ENCODE_CONTEXT_H
#define RPROFREP_ENCODE_CONTEXT_H

#include "rprofrep_core.h"

#include "rprofrep_concatenator.h"
#include "rprofrep_event_pool_buffer.h"

#include "sections/rprofrep_report_section.h"
#include "utils/rprofrep_argument_manager.h"

#include "rprofrep_encode_type.h"

rprofrep_status_t rprofrep_encode_context_init(rprofrep_encode_context_t** ctx, const char* context_id, const char* report_name);

rprofrep_status_t rprofrep_encode_context_destroy(rprofrep_encode_context_t* ctx);

#endif // RPROFREP_ENCODE_CONTEXT_H