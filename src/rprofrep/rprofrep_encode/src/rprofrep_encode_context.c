#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "rprofrep_core.h"

#include "sections/rprofrep_report_section.h"

#include "utils/rprofrep_argument_manager.h"

#include "rprofrep_concatenator.h"
#include "rprofrep_event_pool_buffer.h"
#include "rprofrep_encode_context.h"

#include "structure/cid_stack.h"

rprofrep_status_t rprofrep_encode_context_init(
    rprofrep_encode_context_t** ctx, 
    const char* context_id, const char* report_name)
{
    RPROFREP_CHECK_VALID_PTR(ctx, context_id, report_name);

    rprofrep_encode_context_t* c = (rprofrep_encode_context_t*) calloc(1, sizeof(rprofrep_encode_context_t));
    RPROFREP_CHECK_ALLOC(c);

    snprintf(c->exp_tmp_dir, sizeof(c->exp_tmp_dir), "/tmp/rprofrep_%s", context_id);

    if (mkdir(c->exp_tmp_dir, 0755) != 0 && errno != EEXIST) {
        return RPROFREP_STATUS_FILE_ERROR("Cannot create directory '%s'\n", c->exp_tmp_dir);
    }


    for (size_t i = 0; i < RPROFREP_NB_SECTIONS; i++)
    {
        RPROFREP_CHECK_CALL(rprofrep_report_section_init(&c->sections[i], i, c->exp_tmp_dir));
    }
    
    RPROFREP_CHECK_CALL(rprofrep_init_event_pool_buffer(&c->event_pool));

    if(stack_init(&c->cid_stack, 16) == false) {
        return RPROFREP_STATUS_ALLOC_FAILED("Cannot allocated stack\n");
    }

    RPROFREP_CHECK_CALL(rprofrep_concatenator_init(&c->concatenator, report_name));

    rprofrep_init_argument_manager(&c->arg_manager);

    *ctx = c;

    RPROFREP_CHECK_CALL(rprofrep_report_write_section(c, RPROFREP_SECTION_GPU_SPEC));
    return RPROFREP_STATUS_SUCCESS;
}


rprofrep_status_t rprofrep_encode_context_destroy(rprofrep_encode_context_t* ctx)
{
    RPROFREP_CHECK_VALID_PTR(ctx);

    static const rprofrep_section_id_t order[] = {
        RPROFREP_SECTION_GLOBAL,
        RPROFREP_SECTION_LOCATION,
        RPROFREP_SECTION_STRING,
        RPROFREP_SECTION_KERNEL,
        RPROFREP_SECTION_API_DATA,
        RPROFREP_SECTION_OFFSETS
    };

    for (size_t i = 0; i < sizeof(order)/sizeof(order[0]); i++)
        RPROFREP_CHECK_CALL(rprofrep_report_write_section(ctx, order[i]));

    RPROFREP_CHECK_CALL(rprofrep_concatenator_destroy(&ctx->concatenator));

    for (size_t i = 0; i < RPROFREP_NB_SECTIONS; i++)
    {
        rprofrep_report_section_fini(&ctx->sections[i], i);
    }
    
    rprofrep_destroy_event_pool_buffer(ctx->event_pool);
    stack_free(ctx->cid_stack);

    char cmd[256];
    snprintf(cmd, sizeof(cmd), "rm -rf %s", ctx->exp_tmp_dir);
    if (system(cmd) != 0) {
        return RPROFREP_STATUS_FILE_ERROR("Cannot delete directory '%s'\n", ctx->exp_tmp_dir);
    }

    free(ctx);

    return RPROFREP_STATUS_SUCCESS;
}