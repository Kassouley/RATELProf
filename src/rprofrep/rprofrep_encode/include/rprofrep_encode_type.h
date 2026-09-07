#ifndef RPROFREP_ENCODE_TYPE_H
#define RPROFREP_ENCODE_TYPE_H

#define BUILD_FILENAME(dst, dir, fmt, ...) snprintf((dst), sizeof(dst), "%s/" fmt, (dir), ##__VA_ARGS__)

#include "rprofrep_fwd.h"

#include "sections/rprofrep_report_section.h"
#include "utils/rprofrep_argument_manager.h"
#include "rprofrep_concatenator.h"
#include "rprofrep_event_pool_buffer.h"

struct rprofrep_encode_context_s
{
    rprofrep_report_section_t sections[RPROFREP_NB_SECTIONS];

    rprofrep_concatenator_t concatenator;

    rprofrep_buffer_pool_t* event_pool;

    rprofrep_argument_manager_t arg_manager;

    char exp_tmp_dir[128];
};


#endif // RPROFREP_ENCODE_TYPE_H