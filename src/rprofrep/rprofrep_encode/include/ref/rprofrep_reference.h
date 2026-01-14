#ifndef RPROFREP_REFERENCE_H
#define RPROFREP_REFERENCE_H

#include <stdio.h>
#include <stdlib.h>

#include "rprofrep_core.h"
#include "rprofrep_encode_type.h"

typedef struct rprofrep_reference_s {
    uint64_t ref_counter;
    hash_table_t* ref_table;
    msgpack_buffer_t buffer;
} rprofrep_reference_t;


rprofrep_status_t rprofrep_init_ref_section(rprofrep_reference_t* ref, const char* filename);

void rprofrep_free_ref_section(rprofrep_reference_t* ref);

rprofrep_status_t rprofrep_write_ref_section(
    rprofrep_encode_context_t* ctx, 
    rprofrep_reference_t* data, 
    const char* filename);

uint64_t rprofrep_string_get_ref(rprofrep_encode_context_t* ctx, const char* str);
uint64_t rprofrep_kernel_get_ref(rprofrep_encode_context_t* ctx, rprofrep_kernel_static_data_t* data);
uint64_t rprofrep_location_get_ref(rprofrep_encode_context_t* ctx, void* addr);

#endif // RPROFREP_REFERENCE_H