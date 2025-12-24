#ifndef RPROFREP_REPORT_SECTION_H
#define RPROFREP_REPORT_SECTION_H

#include "rprofrep_core.h"
#include "rprofrep_fwd.h"

typedef struct rprofrep_report_section_s {
    char filename[512];
    void* data;
} rprofrep_report_section_t;

rprofrep_status_t rprofrep_report_section_init(rprofrep_report_section_t* section, rprofrep_section_id_t id, const char* filedir);

void rprofrep_report_section_fini(rprofrep_report_section_t* section, rprofrep_section_id_t id);

rprofrep_status_t rprofrep_report_write_section(
    rprofrep_encode_context_t* ctx, 
    rprofrep_section_id_t section_id);

#endif // RPROFREP_REPORT_SECTION_H