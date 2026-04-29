#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rprofrep_status.h"
#include "rprofrep_utils.h"
#include "rprofrep_defs.h"

#include "utils/rprofrep_decode_type.h"
#include "utils/rprofrep_read_utils.h"

#include "sections/rprofrep_section_header.h"


// Decode header report
rprofrep_status_t rprofrep_decode_header_section(rprofrep_decode_context_t* ctx) {
    RPROFREP_CHECK_VALID_PTR(ctx);

    uint8_t* buffer = (uint8_t*) malloc(sizeof(rprofrep_header_section_t));
    RPROFREP_CHECK_ALLOC(buffer);

    size_t readed = fread(buffer, 1, sizeof(rprofrep_header_section_t), ctx->handle);

    if (readed != sizeof(rprofrep_header_section_t)) {
        return RPROFREP_STATUS_INVALID_REPORT("Failed to read the RATELProf report header\n");
    }

    size_t size = ctx->size;
    size_t offset = 0;
    rprofrep_header_section_t* out = &ctx->header;

    __read_bytes(out->magic, buffer, &offset);

    if (strncmp(out->magic, RPROFREP_FILE_MAGIC, sizeof(out->magic)) != 0) {
        return RPROFREP_STATUS_INVALID_REPORT("This file is not a valid RATELProf report (invalid magic)\n");
    }

    __read_bytes(out->report_version, buffer, &offset);

    if (out->report_version[0] != RPROFREP_VERSION_MAJOR ||
        out->report_version[1] != RPROFREP_VERSION_MINOR ||
        out->report_version[2] != RPROFREP_VERSION_PATCH )
    {
        return RPROFREP_STATUS_INVALID_REPORT("Incompatible report file version: expected %d.%d.%d but got %d.%d.%d.\n", 
            RPROFREP_VERSION_MAJOR, RPROFREP_VERSION_MINOR, RPROFREP_VERSION_PATCH, 
            out->report_version[0], out->report_version[1], out->report_version[2]);
    }
    

    uint64_t total_size = 0;
    for (uint64_t i = 0; i < RPROFREP_NB_SECTIONS; i++) {
        __read_bytes(out->sections[i].offset, buffer, &offset);
        __read_bytes(out->sections[i].size, buffer, &offset);
        total_size += out->sections[i].size;
    }

    if (size < offset + total_size) {
        return RPROFREP_STATUS_INVALID_REPORT("The report file is truncated or corrupted (size mismatch)\n");
    }

    return RPROFREP_STATUS_SUCCESS;
}


rprofrep_status_t rprofrep_get_section_metadata(
    rprofrep_decode_context_t* ctx, 
    rprofrep_section_id_t section_id, 
    uint64_t* out_offset, 
    uint64_t* out_size
) {
    RPROFREP_CHECK_VALID_PTR(ctx, out_offset, out_size);
    RPROFREP_CHECK_VALID_ARG(section_id < RPROFREP_NB_SECTIONS);

    rprofrep_header_entry_t* section = &ctx->header.sections[section_id];
    *out_offset = section->offset;
    *out_size = section->size;

    return RPROFREP_STATUS_SUCCESS;
}

 // Get the section buffer from its ID
rprofrep_status_t rprofrep_get_section_buffer(
    rprofrep_decode_context_t* ctx,
    rprofrep_section_id_t section_id,
    uint8_t** out_section_buffer,
    size_t* out_section_size
) {
    RPROFREP_CHECK_VALID_PTR(ctx, out_section_buffer);
    RPROFREP_CHECK_VALID_ARG(section_id < RPROFREP_NB_SECTIONS);

    uint64_t offset = 0;
    uint64_t size = 0;
    RPROFREP_CHECK_CALL(rprofrep_get_section_metadata(ctx, section_id, &offset, &size));

    if (size == 0) return RPROFREP_STATUS_SUCCESS;

    uint8_t* buffer = (uint8_t*) malloc(size * sizeof(uint8_t));
    RPROFREP_CHECK_ALLOC(buffer);

    if (fseek(ctx->handle, (long)offset, SEEK_SET) != 0) {
        free(buffer);
        return RPROFREP_STATUS_INVALID_REPORT("Failed to seek to %s section from report.\n", get_section_name(section_id));
    }

    size_t readed = fread(buffer, 1, size, ctx->handle);
    if (readed != size) {
        free(buffer);
        return RPROFREP_STATUS_INVALID_REPORT("Failed to read the %s section from report.\n", get_section_name(section_id));
    }

    *out_section_buffer = buffer;
    if (out_section_size)
        *out_section_size = (size_t)size;

    return RPROFREP_STATUS_SUCCESS;
}
