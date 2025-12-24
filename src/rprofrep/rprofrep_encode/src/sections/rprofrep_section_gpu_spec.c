#include <stdio.h>
#include <stdlib.h>

#include "rprofrep_core.h"
#include "rprofrep_fwd.h"

#include "sections/rprofrep_section_gpu_spec.h"

#include "lsgpu.h"

rprofrep_status_t rprofrep_write_gpu_spec_section(rprofrep_encode_context_t* ctx, void* data, const char* filename)
{
    (void) ctx;
    (void) data;

    lsgpu_gpu_list_t devices = {0};
    if(lsgpu_init() != 0)
        return RPROFREP_STATUS_AMD_ERROR("Failed to init lsgpu\n");

    if (lsgpu_query_gpus_data(&devices) != 0)
        return RPROFREP_STATUS_AMD_ERROR("Failed to query GPUs\n");


    if (lsgpu_write_gpu_data_binary(&devices, filename) != 0)
        return RPROFREP_STATUS_FILE_ERROR("Failed to write GPU data to binary file '%s'\n", filename);
   
    free(devices.entries);
    
    if(lsgpu_fini() != 0)
        return RPROFREP_STATUS_AMD_ERROR("Failed to fini lsgpu\n");

    return RPROFREP_STATUS_SUCCESS;
}