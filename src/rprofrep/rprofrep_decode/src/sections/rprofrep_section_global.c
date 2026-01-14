#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rprofrep_core.h"

#include "utils/rprofrep_decode_type.h"
#include "utils/rprofrep_read_utils.h"

#include "sections/rprofrep_report_section.h"
#include "sections/rprofrep_section_global.h"

// Free the section
rprofrep_status_t rprofrep_free_global_section(rprofrep_global_data_t* section) {
    for (uint32_t i = 0; i < section->main_argc; i++) {
        free(section->main_argv[i]);
    }
    if (section->main_argv) free(section->main_argv);
    if (section->agents)    free(section->agents);
    if (section->nodes)     free(section->nodes);

    return RPROFREP_STATUS_SUCCESS;
}

// Decode the section
rprofrep_status_t rprofrep_decode_global_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size, 
    rprofrep_global_data_t* out
) {
    uint64_t i = 0;
    uint64_t offset = 0;

    out->rank             = __read_mp_int(buffer, &offset);

    out->tool_version[0]  = __read_mp_uint(buffer, &offset);
    out->tool_version[1]  = __read_mp_uint(buffer, &offset);
    out->tool_version[2]  = __read_mp_uint(buffer, &offset);

    out->experiment_start = __read_mp_uint(buffer, &offset);
    for (i = 0; i < RATELPROF_NB_PHASE; i++)
        out->lifecycle[i] = __read_mp_uint(buffer, &offset);

    out->main_ret  = __read_mp_int(buffer, &offset);
    out->main_argc = __read_mp_uint(buffer, &offset);

    out->main_argv = (char**)malloc(out->main_argc * sizeof(char*));
    RPROFREP_CHECK_ALLOC(out->main_argv);

    for (i = 0; i < out->main_argc; i++)
        out->main_argv[i] = __read_mp_string(buffer, &offset);

    out->num_agents = __read_mp_uint(buffer, &offset);

    out->agents = (uint64_t*)malloc(out->num_agents * sizeof(uint64_t));
    RPROFREP_CHECK_ALLOC(out->agents, {
        rprofrep_free_global_section(out);
    });
    
    out->nodes = (uint64_t*)malloc(out->num_agents * sizeof(uint64_t));
    RPROFREP_CHECK_ALLOC(out->nodes, {
        rprofrep_free_global_section(out);
    });

    for (i = 0; i < out->num_agents; i++) {
        out->agents[i] = __read_mp_uint(buffer, &offset);
        out->nodes[i] = __read_mp_uint(buffer, &offset);
    }

    return RPROFREP_STATUS_SUCCESS;
}


rprofrep_status_t rprofrep_get_tool_version(rprofrep_decode_context_t* ctx, uint64_t version[3])
{
    RPROFREP_CHECK_VALID_PTR(ctx, version);

    rprofrep_global_data_t* data = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_GLOBAL, (void**)&data));

    version[0] = data->tool_version[0];
    version[1] = data->tool_version[1];
    version[2] = data->tool_version[2];

    return RPROFREP_STATUS_SUCCESS;
}

rprofrep_status_t rprofrep_get_rank(rprofrep_decode_context_t* ctx, int64_t* rank)
{
    RPROFREP_CHECK_VALID_PTR(ctx, rank);

    rprofrep_global_data_t* data = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_GLOBAL, (void**)&data));

    *rank = data->rank;

    return RPROFREP_STATUS_SUCCESS;
}


rprofrep_status_t rprofrep_get_experiment_time(rprofrep_decode_context_t* ctx, uint64_t* experiment_time)
{
    RPROFREP_CHECK_VALID_PTR(ctx, experiment_time);

    rprofrep_global_data_t* data = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_GLOBAL, (void**)&data));

    *experiment_time = data->experiment_start;

    return RPROFREP_STATUS_SUCCESS;
}


rprofrep_status_t rprofrep_get_command_line(rprofrep_decode_context_t* ctx, char*** command_line_buffer, uint64_t* buffer_size)
{
    RPROFREP_CHECK_VALID_PTR(ctx, command_line_buffer);

    rprofrep_global_data_t* data = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_GLOBAL, (void**)&data));

    *command_line_buffer = data->main_argv;

    if (buffer_size) *buffer_size = data->main_argc;

    return RPROFREP_STATUS_SUCCESS;
}



rprofrep_status_t rprofrep_get_exit_code(rprofrep_decode_context_t* ctx, int64_t* exit_code)
{
    RPROFREP_CHECK_VALID_PTR(ctx, exit_code);

    rprofrep_global_data_t* data = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_GLOBAL, (void**)&data));

    *exit_code = data->main_ret;

    return RPROFREP_STATUS_SUCCESS;
}


rprofrep_status_t rprofrep_get_constructor_time(rprofrep_decode_context_t* ctx, uint64_t* time)
{
    RPROFREP_CHECK_VALID_PTR(ctx, time);

    rprofrep_global_data_t* data = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_GLOBAL, (void**)&data));

    *time = data->lifecycle[RATELPROF_IN_CONSTRUCTOR_PHASE];

    return RPROFREP_STATUS_SUCCESS;
}


rprofrep_status_t rprofrep_get_main_time(rprofrep_decode_context_t* ctx, uint64_t* time)
{
    RPROFREP_CHECK_VALID_PTR(ctx, time);

    rprofrep_global_data_t* data = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_GLOBAL, (void**)&data));

    *time = data->lifecycle[RATELPROF_IN_MAIN_PHASE] - data->lifecycle[RATELPROF_IN_CONSTRUCTOR_PHASE];

    return RPROFREP_STATUS_SUCCESS;
}


rprofrep_status_t rprofrep_get_destructor_time(rprofrep_decode_context_t* ctx, uint64_t* time)
{
    RPROFREP_CHECK_VALID_PTR(ctx, time);

    rprofrep_global_data_t* data = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_GLOBAL, (void**)&data));

    *time = data->lifecycle[RATELPROF_IN_DESTRUCTOR_PHASE] - data->lifecycle[RATELPROF_IN_MAIN_PHASE];

    return RPROFREP_STATUS_SUCCESS;
}

rprofrep_status_t rprofrep_get_gpu_id_from_agent(rprofrep_decode_context_t* ctx, uint64_t agent_id, uint64_t* gpu_id)
{
    RPROFREP_CHECK_VALID_PTR(ctx, gpu_id);

    rprofrep_global_data_t* data = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_GLOBAL, (void**)&data));

    for (uint64_t i = 0; i < data->num_agents; i++) {
        if (data->agents[i] == agent_id) {
            *gpu_id = data->nodes[i];
            return RPROFREP_STATUS_SUCCESS;
        }
    }

    return RPROFREP_STATUS_NOT_FOUND("Agent ID %lu not found.\n", agent_id);
}