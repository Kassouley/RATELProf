#ifndef RPROFREP_SECTION_REF_H
#define RPROFREP_SECTION_REF_H

#include "rprofrep_status.h"
#include "utils/rprofrep_decode_type.h"


typedef struct rprofrep_ref_section_s {
    uint64_t nentries;
    size_t entry_size;
    void* entries;
} rprofrep_ref_section_t;

#include "sections/rprofrep_section_location.h"
#include "sections/rprofrep_section_api_data.h"
#include "sections/rprofrep_section_string.h"

rprofrep_status_t rprofrep_init_ref_section(rprofrep_ref_section_t* out, uint64_t nentries, size_t entry_size);

/**
 * The function `rprofrep_get_location` retrieves a location entry based on an ID from a report
 * context.
 * 
 * @param ctx Input of type `rprofrep_decode_context_t` used to store the context of the report. 
 * 
 * @param id The `id` parameter in the `rprofrep_get_location` function is used to specify the index of
 * the location entry that you want to retrieve from the location section.
 * 
 * @param out This parameter is used to store the location entry corresponding
 * to the provided `id` in the `location_section` of the context
 * 
 * @return `rprofrep_status_t`
 */
rprofrep_status_t rprofrep_get_location(rprofrep_decode_context_t* ctx, uint64_t id, rprofrep_location_entry_t** out);


/**
 * The function `rprofrep_get_api_data` retrieves a api_data entry based on an ID from a report
 * context.
 * 
 * @param ctx Input of type `rprofrep_decode_context_t` used to store the context of the report. 
 * 
 * @param id The `id` parameter in the `rprofrep_get_api_data` function is used to specify the index of
 * the api_data entry that you want to retrieve from the api_data section.
 * 
 * @param out This parameter is used to store the api_data entry corresponding
 * to the provided `id` in the `api_data_section` of the context
 * 
 * @return `rprofrep_status_t`
 */
rprofrep_status_t rprofrep_get_api_data(rprofrep_decode_context_t* ctx, uint64_t id, rprofrep_api_data_entry_t** out);


rprofrep_status_t rprofrep_get_string_by_id(rprofrep_decode_context_t* ctx, uint64_t id, char** out);


rprofrep_status_t rprofrep_get_kernel(rprofrep_decode_context_t* ctx, uint64_t id, rprofrep_kernel_static_data_t** out);


typedef bool (*foreach_ref_callback_t)(uint64_t id, void* entry, void* user_data);

rprofrep_status_t rprofrep_for_each_location(
    rprofrep_decode_context_t* ctx,
    bool (*callback)(uint64_t id, rprofrep_location_entry_t* entry, void* user_data),
    void* user_data);

rprofrep_status_t rprofrep_for_each_string(
    rprofrep_decode_context_t* ctx,
    bool (*callback)(uint64_t id, char* str, void* user_data),
    void* user_data);

rprofrep_status_t rprofrep_for_each_api_data(
    rprofrep_decode_context_t* ctx,
    bool (*callback)(uint64_t id, rprofrep_api_data_entry_t* entry, void* user_data),
    void* user_data);

rprofrep_status_t rprofrep_for_each_kernel(
    rprofrep_decode_context_t* ctx,
    bool (*callback)(uint64_t id, rprofrep_kernel_static_data_t* entry, void* user_data),
    void* user_data);

#endif // RPROFREP_SECTION_REF_H