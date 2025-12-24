#include <stdio.h>
#include <stdlib.h>

#include "rprofrep_core.h"

#include "sections/rprofrep_section_gpu_spec.h"
#include "sections/rprofrep_section_offsets.h"
#include "sections/rprofrep_section_global.h"

#include "ref/rprofrep_reference.h"
#include "ref/rprofrep_api_reference.h"

#include "sections/rprofrep_report_section.h"

#include "rprofrep_encode_context.h"

typedef rprofrep_status_t (* fn_init_data_t)(void*, const char*);
typedef rprofrep_status_t (* fn_write_data_t)(rprofrep_encode_context_t*, void*, const char*);
typedef void (* fn_fini_data_t)(void*);

typedef struct {
    const char       *name;
    fn_init_data_t    init;
    fn_write_data_t    write;
    fn_fini_data_t    fini;
    size_t            data_size;
} rprofprep_section_info_t;

#define SCT_ENTRY(ID, NAME, INIT, WRITE, FINI, SIZE) \
    [RPROFREP_SECTION_##ID] = { \
        .name  = NAME, \
        .init  = (fn_init_data_t) INIT, \
        .write = (fn_write_data_t) WRITE, \
        .fini  = (fn_fini_data_t) FINI, \
        .data_size = SIZE \
    }

static const rprofprep_section_info_t rprofprep_sections[RPROFREP_NB_SECTIONS] = {
SCT_ENTRY(GLOBAL,   "global_section",   NULL,                             rprofrep_write_global_section,                    NULL,                           0),
SCT_ENTRY(STRING,   "string_section",   rprofrep_init_string_ref_section, rprofrep_write_ref_section,                       rprofrep_free_ref_section,      sizeof(rprofrep_reference_t)),
SCT_ENTRY(LOCATION, "location_section", rprofrep_init_string_ref_section, rprofrep_write_ref_section,                       rprofrep_free_ref_section,      sizeof(rprofrep_reference_t)),
SCT_ENTRY(GPU_SPEC, "gpu_spec_section", NULL,                             rprofrep_write_gpu_spec_section,                  NULL,                           0),
SCT_ENTRY(API_DATA, "api_data_section", rprofrep_init_api_data_section,   rprofrep_write_api_data_section,                  rprofrep_free_api_data_section, sizeof(rprofrep_api_data_ref_t)),
SCT_ENTRY(KERNEL,   "kernel_section",   rprofrep_init_uint64_ref_section, rprofrep_write_ref_section,                       rprofrep_free_ref_section,      sizeof(rprofrep_reference_t)),
SCT_ENTRY(OFFSETS,  "offsets_section",  NULL,                             rprofrep_write_offsets_and_concat_events_section, NULL,                           0),
SCT_ENTRY(EVENTS,   NULL,               NULL,                             NULL,                                             NULL,                           0),
};


rprofrep_status_t rprofrep_report_section_init(rprofrep_report_section_t* section, rprofrep_section_id_t id, const char* filedir)
{
    RPROFREP_CHECK_VALID_PTR(section, filedir);
    RPROFREP_CHECK_VALID_ARG(id < RPROFREP_NB_SECTIONS);
    const char* filename = rprofprep_sections[id].name;
    if (!filename) return RPROFREP_STATUS_SUCCESS;

    BUILD_FILENAME(section->filename, filedir, "%s", filename);

    fn_init_data_t fn = rprofprep_sections[id].init;
    size_t data_size = rprofprep_sections[id].data_size;
    if (fn && data_size > 0) {
        section->data = malloc(data_size);
        RPROFREP_CHECK_ALLOC(section->data);
        RPROFREP_CHECK_CALL(fn(section->data, section->filename));
    }
    return RPROFREP_STATUS_SUCCESS;
}

void rprofrep_report_section_fini(rprofrep_report_section_t* section, rprofrep_section_id_t id)
{
    fn_fini_data_t fn = rprofprep_sections[id].fini;
    if (fn) fn(section->data);
    if (section->data) free(section->data);
}


rprofrep_status_t rprofrep_report_write_section(
    rprofrep_encode_context_t* ctx, 
    rprofrep_section_id_t section_id
) {
    RPROFREP_CHECK_VALID_PTR(ctx);
    RPROFREP_CHECK_VALID_ARG(section_id < RPROFREP_NB_SECTIONS);
    RPROFREP_CHECK_VALID_ARG(section_id != RPROFREP_SECTION_EVENTS);

    rprofrep_report_section_t* section    = &ctx->sections[section_id];
    rprofrep_concatenator_t* concatenator = &ctx->concatenator;

    const char* filename = section->filename;

    fn_write_data_t fn = rprofprep_sections[section_id].write;
    if (fn) fn(ctx, section->data, filename);

    RPROFREP_CHECK_CALL(rprofrep_concatenator_concat_section(
        concatenator, filename, section_id));
    return RPROFREP_STATUS_SUCCESS;
}