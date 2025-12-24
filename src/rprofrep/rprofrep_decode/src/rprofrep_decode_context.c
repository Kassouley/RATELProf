#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rprofrep_decode_context.h"
#include "rprofrep_status.h"
#include "rprofrep_utils.h"

#include "sections/rprofrep_report_section.h"
#include "sections/rprofrep_section_header.h"

rprofrep_status_t rprofrep_decode_context_init(
    rprofrep_decode_context_t* ctx,
    const char* filepath
) {
    RPROFREP_CHECK_VALID_PTR(filepath, ctx);

    ctx->handle = fopen(filepath, "rb");
    RPROFREP_CHECK_FOPEN(ctx->handle, {
        rprofrep_decode_context_free(ctx);
    });

    ctx->size = get_file_size(filepath);

    RPROFREP_CHECK_CALL(rprofrep_decode_header_section(ctx), {
        rprofrep_decode_context_free(ctx);
    });


    for (size_t i = 0; i < RPROFREP_NB_SECTIONS; i++)
    {
        ctx->sections[i].is_decoded = false;
    }

    return RPROFREP_STATUS_SUCCESS;
}

rprofrep_status_t rprofrep_decode_context_free(rprofrep_decode_context_t* ctx) {
    RPROFREP_CHECK_VALID_PTR(ctx);

    for (size_t i = 0; i < RPROFREP_NB_SECTIONS; i++)
    {
        rprofrep_destroy_section(ctx, i);
    }

    if (ctx->handle) {
        fclose(ctx->handle);
    }

    return RPROFREP_STATUS_SUCCESS;
}