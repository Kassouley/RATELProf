#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rprofrep_status.h"

#include "utils/rprofrep_decode_type.h"

#include "sections/rprofrep_section_gpu_spec.h"
#include "sections/rprofrep_report_section.h"

#include "lsgpu.h"

// Free the GPU sections
rprofrep_status_t rprofrep_free_gpu_spec_section(rprofrep_gpu_spec_data_t* data) {
    if(data->entries) {
        for(int i = 0; i < data->count; i++)
            lsgpu_destroy_gpu_data(data->entries[i]);
        free(data->entries);
    };
    return RPROFREP_STATUS_SUCCESS;
}


// Decode the section
rprofrep_status_t rprofrep_decode_gpu_spec_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size, 
    rprofrep_gpu_spec_data_t* out
) {
    if(lsgpu_read_gpu_data_from_buffer(out, buffer, size) != 0) {
        return RPROFREP_STATUS_ERROR("lsgpu: failed");
    }

    return RPROFREP_STATUS_SUCCESS;
}


rprofrep_status_t rprofrep_print_gpus_spec(rprofrep_decode_context_t* ctx)
{
    RPROFREP_CHECK_VALID_PTR(ctx);

    rprofrep_gpu_spec_data_t* devices = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_GPU_SPEC, (void**)&devices));

    lsgpu_print_gpus_data(devices);

    return RPROFREP_STATUS_SUCCESS;
}

rprofrep_status_t rprofrep_node_is_gpu(rprofrep_decode_context_t* ctx, uint64_t node_id, bool* is_gpu)
{
    RPROFREP_CHECK_VALID_PTR(ctx, is_gpu);

    rprofrep_gpu_spec_data_t* devices = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_GPU_SPEC, (void**)&devices));

    *is_gpu = false;
    for (uint32_t i = 0; i < devices->count; i++) {
        uint32_t entry_node_id = 0;
        lsgpu_get_attribute(devices->entries[i], LSGPU_ATTRIBUTE_NODE_ID, &entry_node_id);
        if (entry_node_id == node_id) {
            *is_gpu = true;
            break;
        }
    }

    return RPROFREP_STATUS_SUCCESS;
}


rprofrep_status_t rprofrep_gpu_to_json(rprofrep_decode_context_t* ctx, const char* prefix)
{
    RPROFREP_CHECK_VALID_PTR(ctx, prefix);

    rprofrep_gpu_spec_data_t* devices = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_GPU_SPEC, (void**)&devices));

    lsgpu_to_json_gpus_data(prefix, devices);

    return RPROFREP_STATUS_SUCCESS;
}