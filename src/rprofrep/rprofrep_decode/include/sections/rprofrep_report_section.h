#ifndef RPROFREP_REPORT_SECTION_H
#define RPROFREP_REPORT_SECTION_H

rprofrep_status_t rprofrep_decode_section(rprofrep_decode_context_t* ctx, rprofrep_section_id_t sct_id);

rprofrep_status_t rprofrep_get_section(rprofrep_decode_context_t* ctx, rprofrep_section_id_t sct_id, void** out);

rprofrep_status_t rprofrep_destroy_section(rprofrep_decode_context_t* ctx, rprofrep_section_id_t sct_id);

#endif // RPROFREP_REPORT_SECTION_H