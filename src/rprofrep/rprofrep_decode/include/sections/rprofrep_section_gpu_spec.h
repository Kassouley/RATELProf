#ifndef RPROFREP_SECTION_GPU_SPEC_H
#define RPROFREP_SECTION_GPU_SPEC_H

#include <stdint.h>

#include "rprofrep_status.h"

#include "utils/rprofrep_decode_type.h"

#include "lsgpu.h"

typedef lsgpu_gpu_list_t rprofrep_gpu_spec_data_t;

rprofrep_status_t rprofrep_free_gpu_spec_section(
    rprofrep_gpu_spec_data_t* data);

rprofrep_status_t rprofrep_decode_gpu_spec_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size, 
    rprofrep_gpu_spec_data_t* out);

rprofrep_status_t rprofrep_print_gpus_spec(rprofrep_decode_context_t* ctx);

rprofrep_status_t rprofrep_node_is_gpu(rprofrep_decode_context_t* ctx, uint64_t node_id, bool* is_gpu);

rprofrep_status_t rprofrep_gpu_to_json(rprofrep_decode_context_t* ctx, const char* prefix);

#endif // RPROFREP_SECTION_GPU_SPEC_H