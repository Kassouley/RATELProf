#include <stdio.h>
#include <stdlib.h>

#include "rprofrep_status.h"
#include "utils/rprofrep_decode_type.h"

#include "sections/rprofrep_report_section.h"

#include "sections/rprofrep_section_api_data.h"
#include "sections/rprofrep_section_kernel.h"
#include "sections/rprofrep_section_location.h"
#include "sections/rprofrep_section_string.h"

#include "sections/rprofrep_section_ref.h"



rprofrep_status_t rprofrep_init_ref_section(
    rprofrep_ref_section_t* out, 
    uint64_t nentries, 
    size_t entry_size
) {
    out->entries = malloc(nentries * entry_size);
    RPROFREP_CHECK_ALLOC(out->entries);
    out->nentries = nentries;
    out->entry_size = entry_size;
    return RPROFREP_STATUS_SUCCESS;
}



static rprofrep_status_t rprofrep_get_ref(
    rprofrep_decode_context_t* ctx, 
    uint64_t id, 
    rprofrep_section_id_t sct_id, 
    void** out
) {
    RPROFREP_CHECK_VALID_PTR(ctx, out);

    rprofrep_ref_section_t* ref_sct = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, sct_id, (void**)&ref_sct));

    RPROFREP_CHECK_VALID_ARG(id < ref_sct->nentries);
    
    uint8_t* base = (uint8_t*) ref_sct->entries;
    *out = (void*)(base + (id * ref_sct->entry_size));

    return RPROFREP_STATUS_SUCCESS;
}

// Get location entry from its ID
rprofrep_status_t rprofrep_get_location(
    rprofrep_decode_context_t* ctx, 
    uint64_t id,
    rprofrep_location_entry_t** out
) {
    return rprofrep_get_ref(ctx, id, RPROFREP_SECTION_LOCATION, (void**)out);
}

// Get string by its ID from string array
rprofrep_status_t rprofrep_get_string_by_id(rprofrep_decode_context_t* ctx, uint64_t id, char** out) {
    RPROFREP_CHECK_VALID_PTR(ctx, out);

    rprofrep_ref_section_t* ref_sct = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_STRING, (void**)&ref_sct));

    RPROFREP_CHECK_VALID_ARG(id < ref_sct->nentries);

    char** strings = (char**)ref_sct->entries;
    *out = strings[id];

    return RPROFREP_STATUS_SUCCESS;
}


// Get api_data entry from its ID
rprofrep_status_t rprofrep_get_api_data(rprofrep_decode_context_t* ctx, uint64_t id, rprofrep_api_data_entry_t** out) {
    return rprofrep_get_ref(ctx, id, RPROFREP_SECTION_API_DATA, (void**)out);
}


rprofrep_status_t rprofrep_get_kernel(rprofrep_decode_context_t* ctx, uint64_t id, rprofrep_kernel_static_data_t** out) {
    return rprofrep_get_ref(ctx, id, RPROFREP_SECTION_KERNEL, (void**)out);
}


// Generic for-each iterator for any ref section
static rprofrep_status_t rprofrep_for_each_ref(
    rprofrep_decode_context_t* ctx,
    rprofrep_section_id_t sct_id,
    foreach_ref_callback_t callback,
    void* user_data)
{
    RPROFREP_CHECK_VALID_PTR(ctx, callback);

    rprofrep_ref_section_t* ref_sct = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, sct_id, (void**)&ref_sct));

    uint8_t* base = (uint8_t*) ref_sct->entries;
    for (uint64_t i = 0; i < ref_sct->nentries; i++) {
        void* entry = (void*)(base + (i * ref_sct->entry_size));
        if (!callback(i, entry, user_data)) break;
    }

    return RPROFREP_STATUS_SUCCESS;
}

rprofrep_status_t rprofrep_for_each_string(
    rprofrep_decode_context_t* ctx,
    bool (*callback)(uint64_t id, char* str, void* user_data),
    void* user_data)
{
    RPROFREP_CHECK_VALID_PTR(ctx, callback);
    
    rprofrep_ref_section_t* ref_sct;
    rprofrep_get_section(ctx, RPROFREP_SECTION_STRING, (void**)&ref_sct);
    char** strings = (char**)ref_sct->entries;

    for (uint64_t i = 0; i < ref_sct->nentries; i++) {
        if (!callback(i, strings[i], user_data)) break;
    }
    return RPROFREP_STATUS_SUCCESS;
}

rprofrep_status_t rprofrep_for_each_location(
    rprofrep_decode_context_t* ctx,
    bool (*callback)(uint64_t id, rprofrep_location_entry_t* entry, void* user_data),
    void* user_data)
{
    return rprofrep_for_each_ref(ctx, RPROFREP_SECTION_LOCATION,
        (foreach_ref_callback_t) callback, user_data);
}

rprofrep_status_t rprofrep_for_each_api_data(
    rprofrep_decode_context_t* ctx,
    bool (*callback)(uint64_t id, rprofrep_api_data_entry_t* entry, void* user_data),
    void* user_data) 
{
    return rprofrep_for_each_ref(ctx, RPROFREP_SECTION_API_DATA, 
        (foreach_ref_callback_t) callback, user_data);
}


rprofrep_status_t rprofrep_for_each_kernel(
    rprofrep_decode_context_t* ctx,
    bool (*callback)(uint64_t id, rprofrep_kernel_static_data_t* entry, void* user_data),
    void* user_data) 
{
    return rprofrep_for_each_ref(ctx, RPROFREP_SECTION_KERNEL, 
        (foreach_ref_callback_t) callback, user_data);
}
