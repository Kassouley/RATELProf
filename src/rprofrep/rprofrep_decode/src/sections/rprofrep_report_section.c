#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <sys/sendfile.h>
#include <fcntl.h>
#include <errno.h>

#include "rprofrep_status.h"
#include "rprofrep_log.h"

#include "utils/rprofrep_decode_type.h"
#include "utils/rprofrep_read_utils.h"

#include "sections/rprofrep_section_header.h"
#include "sections/rprofrep_section_events.h"
#include "sections/rprofrep_section_global.h"
#include "sections/rprofrep_section_string.h"
#include "sections/rprofrep_section_location.h"
#include "sections/rprofrep_section_gpu_spec.h"
#include "sections/rprofrep_section_api_data.h"
#include "sections/rprofrep_section_offsets.h"
#include "sections/rprofrep_section_kernel.h"

#include "sections/rprofrep_section_ref.h"
#include "sections/rprofrep_report_section.h"

typedef rprofrep_status_t (*section_data_decoder_t)   (rprofrep_decode_context_t* ctx, uint8_t* buffer, size_t size, void* data_out);

typedef rprofrep_status_t (*section_data_destroyer_t) (void* sct);

rprofrep_status_t default_decoder(rprofrep_decode_context_t* ctx, uint8_t* buffer, size_t* offset, void* data_out) {
    rprofrep_log(RPROFREP_LOG_ERROR, "No decoder setted for this section.");
    return RPROFREP_STATUS_SUCCESS;
}

rprofrep_status_t default_destroyer(void* sct) {
    rprofrep_log(RPROFREP_LOG_ERROR, "No destroyer setted for this section.");
    return RPROFREP_STATUS_SUCCESS;
}

static section_data_decoder_t __rprofrep_decode_section[RPROFREP_NB_SECTIONS] = {
    [RPROFREP_SECTION_GLOBAL]   = (section_data_decoder_t) rprofrep_decode_global_section,
    [RPROFREP_SECTION_STRING]   = (section_data_decoder_t) rprofrep_decode_string_section,
    [RPROFREP_SECTION_LOCATION] = (section_data_decoder_t) rprofrep_decode_location_section,
    [RPROFREP_SECTION_GPU_SPEC] = (section_data_decoder_t) rprofrep_decode_gpu_spec_section,
    [RPROFREP_SECTION_API_DATA] = (section_data_decoder_t) rprofrep_decode_api_data_section,
    [RPROFREP_SECTION_KERNEL]   = (section_data_decoder_t) rprofrep_decode_kernel_section,
    [RPROFREP_SECTION_OFFSETS]  = (section_data_decoder_t) rprofrep_decode_offsets_section,
    [RPROFREP_SECTION_EVENTS]   = (section_data_decoder_t) default_decoder,
};


static section_data_destroyer_t __rprofrep_destroy_section[RPROFREP_NB_SECTIONS] = {
    [RPROFREP_SECTION_GLOBAL]   = (section_data_destroyer_t) rprofrep_free_global_section,
    [RPROFREP_SECTION_STRING]   = (section_data_destroyer_t) rprofrep_free_string_section,
    [RPROFREP_SECTION_LOCATION] = (section_data_destroyer_t) rprofrep_free_location_section,
    [RPROFREP_SECTION_GPU_SPEC] = (section_data_destroyer_t) rprofrep_free_gpu_spec_section,
    [RPROFREP_SECTION_API_DATA] = (section_data_destroyer_t) rprofrep_free_api_data_section,
    [RPROFREP_SECTION_KERNEL]   = (section_data_destroyer_t) rprofrep_free_kernel_section,
    [RPROFREP_SECTION_OFFSETS]  = (section_data_destroyer_t) rprofrep_free_offsets_section,
    [RPROFREP_SECTION_EVENTS]   = (section_data_destroyer_t) rprofrep_free_events_section,
};


static size_t __rprofprep_section_size[RPROFREP_NB_SECTIONS] = {
    [RPROFREP_SECTION_GLOBAL]   = sizeof(rprofrep_global_data_t),
    [RPROFREP_SECTION_STRING]   = sizeof(rprofrep_ref_section_t),
    [RPROFREP_SECTION_LOCATION] = sizeof(rprofrep_ref_section_t),
    [RPROFREP_SECTION_GPU_SPEC] = sizeof(rprofrep_gpu_spec_data_t),
    [RPROFREP_SECTION_API_DATA] = sizeof(rprofrep_ref_section_t),
    [RPROFREP_SECTION_KERNEL]   = sizeof(rprofrep_ref_section_t),
    [RPROFREP_SECTION_OFFSETS]  = sizeof(rprofrep_offsets_section_t),
    [RPROFREP_SECTION_EVENTS]   = sizeof(rprofrep_events_section_t),
};


// Decode the section
rprofrep_status_t rprofrep_decode_section(rprofrep_decode_context_t* ctx, rprofrep_section_id_t sct_id)
{
    RPROFREP_CHECK_VALID_PTR(ctx);
    RPROFREP_CHECK_VALID_ARG(sct_id < RPROFREP_NB_SECTIONS);

    void* decoded_data = malloc(__rprofprep_section_size[sct_id]);
    RPROFREP_CHECK_ALLOC(decoded_data);

    if (sct_id == RPROFREP_SECTION_EVENTS) {
        RPROFREP_CHECK_CALL(rprofrep_decode_events_section(ctx, decoded_data));
    } else {
        size_t size = 0;
        uint8_t* buffer = NULL;

        RPROFREP_CHECK_CALL(rprofrep_get_section_buffer(ctx, sct_id, &buffer, &size));
        if (size > 0 && buffer) {
            RPROFREP_CHECK_CALL(__rprofrep_decode_section[sct_id](ctx, buffer, size, decoded_data));
            free(buffer);
        }
    }

    rprofrep_report_section_t* sct = &ctx->sections[sct_id];
    sct->data       = decoded_data;
    sct->is_decoded = true;

    return RPROFREP_STATUS_SUCCESS;
}

rprofrep_status_t rprofrep_get_section(rprofrep_decode_context_t* ctx, rprofrep_section_id_t sct_id, void** out)
{
    rprofrep_report_section_t* section = &ctx->sections[sct_id];
    if (section->is_decoded == false) {
        RPROFREP_CHECK_CALL(rprofrep_decode_section(ctx, sct_id));
    }
    *out = section->data;
    return RPROFREP_STATUS_SUCCESS;
}

rprofrep_status_t rprofrep_destroy_section(rprofrep_decode_context_t* ctx, rprofrep_section_id_t sct_id)
{
    rprofrep_report_section_t* section = &ctx->sections[sct_id];

    if (!section->is_decoded) return RPROFREP_STATUS_SUCCESS;

    RPROFREP_CHECK_CALL(__rprofrep_destroy_section[sct_id](section->data));

    section->is_decoded = false;
    free(section->data);

    return RPROFREP_STATUS_SUCCESS;
}

rprofrep_status_t rprofrep_export_section(rprofrep_decode_context_t* ctx, rprofrep_section_id_t sct_id, const char* filename, int mode, size_t* out_size) {
    RPROFREP_CHECK_VALID_PTR(ctx, ctx->handle, filename);
    RPROFREP_CHECK_VALID_ARG(sct_id < RPROFREP_NB_SECTIONS);

    uint64_t offset = 0;
    uint64_t size = 0;
    RPROFREP_CHECK_CALL(rprofrep_get_section_metadata(ctx, sct_id, &offset, &size));

    int dst_flags = O_WRONLY | O_CREAT | (mode == 1 ? 0 : O_TRUNC);

    int src_fd = fileno(ctx->handle);
    if (src_fd < 0) return RPROFREP_STATUS_FILE_ERROR("Cannot get fd for handle %x", ctx->handle);

    int dst_fd = open(filename, dst_flags, 0644);
    if (dst_fd < 0) return RPROFREP_STATUS_FILE_ERROR("Cannot open destination file %s", filename);

    if (mode == 1 && lseek(dst_fd, 0, SEEK_END) == (off_t)-1) {
        close(dst_fd);
        return RPROFREP_STATUS_FILE_ERROR("Cannot seek to end of destination file %s", filename);
    }

    off_t off = (off_t)offset;
    size_t remaining = (size_t)size;

    while (remaining > 0) {
        ssize_t sent = sendfile(dst_fd, src_fd, &off, remaining);
        if (sent <= 0) {
            close(dst_fd);
            return RPROFREP_STATUS_FILE_ERROR("sendfile failed");
        }

        remaining -= sent;
    }

    close(dst_fd);

    if (out_size) {
        *out_size = size;
    }

    return RPROFREP_STATUS_SUCCESS;
}