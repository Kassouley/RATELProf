#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

#include <ratelprof.h>
#include <ratelprof_ext.h>

#include "rprofrep_status.h"

#include "utils/rprofrep_decode_type.h"
#include "utils/rprofrep_read_utils.h"

#include "sections/rprofrep_section_header.h"
#include "sections/rprofrep_section_offsets.h"
#include "sections/rprofrep_section_events.h"
#include "sections/rprofrep_section_location.h"

#include "sections/rprofrep_report_section.h"

// Freeing the memory allocated for the offsets section in the context of a profiling report.
rprofrep_status_t rprofrep_free_offsets_section(rprofrep_offsets_section_t* sct)
{
    if (sct->groups) {
        free(sct->groups);
    }

    rprofrep_tree_free_tree(sct->gpu_offset_tree);
    rprofrep_tree_free_tree(sct->cpu_offset_tree);

    return RPROFREP_STATUS_SUCCESS;
}


static rprofrep_status_t read_offsets_tree(
    rprofrep_tree_node_t** tree,
    uint8_t* buffer, size_t* offset, rprofrep_group_entry_t* groups,
    rprofrep_group_entry_t** prev_group, uint8_t* event_section_buffer)
{
    uint64_t nunits = __read_mp_uint(buffer, offset);
    if (nunits > 0) {
        *tree = rprofrep_tree_create_node(0, nunits);
        RPROFREP_CHECK_ALLOC(*tree);

        // ---- Read Units ----
        for (uint64_t i = 0; i < nunits; i++) {
            uint64_t unit_value = __read_mp_uint(buffer, offset);
            uint64_t nsubunits  = __read_mp_uint(buffer, offset);

            rprofrep_tree_node_t* unit_node = rprofrep_tree_create_node(unit_value, nsubunits);
            RPROFREP_CHECK_ALLOC(unit_node);
            rprofrep_tree_add_node(*tree, unit_node);

            // ---- Read Sub Units ----
            for (uint64_t j = 0; j < nsubunits; j++) {
                int64_t  subunit_value = __read_mp_int(buffer,  offset);
                // if (subunit_value < 0) {
                //     subunit_value = -(subunit_value + 2); // Convert back to original subunit value
                // }
                uint64_t ndomains      = __read_mp_uint(buffer, offset);

                rprofrep_tree_node_t* subunit_node = rprofrep_tree_create_node(subunit_value, ndomains);
                RPROFREP_CHECK_ALLOC(subunit_node);
                rprofrep_tree_add_node(unit_node, subunit_node);

                // ---- Read Domains ----
                for (uint64_t k = 0; k < ndomains; k++) {  
                    uint64_t domain_value = __read_mp_uint(buffer, offset);

                    if (domain_value >= RATELPROF_NB_DOMAIN_EXT) {
                        return RPROFREP_STATUS_ERROR("Domain value %lu is out of range (max %d).\n", domain_value, RATELPROF_NB_DOMAIN_EXT);
                    }

                    rprofrep_tree_node_t* domain_node = rprofrep_tree_create_node(domain_value, 0);
                    RPROFREP_CHECK_ALLOC(domain_node);
                    rprofrep_tree_add_node(subunit_node, domain_node);

                    uint64_t group_off     = __read_mp_uint(buffer, offset);
                    uint64_t group_nevents = __read_mp_uint(buffer, offset);
                    uint64_t group_id      = __read_mp_uint(buffer, offset);

                    rprofrep_tree_set_leaf_value(domain_node, group_id);

                    rprofrep_group_entry_t* group = &groups[group_id];
                    group->unit     = unit_value;
                    group->sub_unit = subunit_value;
                    group->domain   = domain_value;
                    group->offset_entry.offset  = group_off;
                    group->offset_entry.nevents = group_nevents;
                    group->offset_entry.id      = group_id;
                    group->buffer.buffer_start = event_section_buffer + group->offset_entry.offset;
                    if (*prev_group) {
                        (*prev_group)->buffer.buffer_stop = group->buffer.buffer_start;
                    }
                    *prev_group = group;
                }
            }
        }
    }
    return RPROFREP_STATUS_SUCCESS;
}

// Decode the offsets section of the report file
rprofrep_status_t rprofrep_decode_offsets_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size,
    rprofrep_offsets_section_t* out
) {
    size_t offset = 0; 
    const rprofrep_events_section_t* events_section = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_EVENTS, (void**)&events_section));

    uint64_t num_groups = __read_mp_uint(buffer, &offset);
    out->groups = calloc(num_groups, sizeof(*out->groups));
    out->num_groups = num_groups;
    RPROFREP_CHECK_ALLOC(out->groups);

    rprofrep_group_entry_t* prev_group = NULL;

    rprofrep_tree_node_t* gpu_offset_tree = NULL;
    rprofrep_tree_node_t* cpu_offset_tree = NULL;
    

    RPROFREP_CHECK_CALL(read_offsets_tree(&cpu_offset_tree, buffer, &offset, out->groups, &prev_group, events_section->buffer),
        rprofrep_free_offsets_section(out));

    RPROFREP_CHECK_CALL(read_offsets_tree(&gpu_offset_tree, buffer, &offset, out->groups, &prev_group, events_section->buffer),
        rprofrep_free_offsets_section(out));

    out->domain_mask = __read_mp_uint(buffer, &offset);

    if (prev_group) {
        prev_group->buffer.buffer_stop = events_section->buffer + events_section->size;
    }

    out->gpu_offset_tree = gpu_offset_tree;
    out->cpu_offset_tree = cpu_offset_tree;

    return RPROFREP_STATUS_SUCCESS;
}



// Return the group ID of the tree at the leaf unit_value->domain_value->sub_unit_value
rprofrep_status_t rprofrep_get_group_id(
    rprofrep_decode_context_t* ctx,
    uint64_t domain_value,
    uint64_t unit_value,
    int64_t  sub_unit_value,
    uint64_t* out_group_id
) {
    RPROFREP_CHECK_VALID_PTR(ctx, out_group_id);

    rprofrep_offsets_section_t* offsets_section = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_OFFSETS, (void**)&offsets_section));

    rprofrep_tree_node_t* offset_tree = NULL;

    if (is_gpu_domain(domain_value)) offset_tree = offsets_section->gpu_offset_tree;
    else offset_tree = offsets_section->cpu_offset_tree;

    rprofrep_tree_node_t* unit_tree = rprofrep_tree_find_node(offset_tree, unit_value);
    if (unit_tree == NULL) {
        return RPROFREP_STATUS_NOT_FOUND("Unit %ld doesn't exist.\n", unit_value);
    }

    rprofrep_tree_node_t* sub_unit_tree = rprofrep_tree_find_node(unit_tree, sub_unit_value);
    if (sub_unit_tree == NULL) {
        return RPROFREP_STATUS_NOT_FOUND("Sub-Unit %ld doesn't exist.\n", sub_unit_value);
    }


    rprofrep_tree_node_t* domain_tree = rprofrep_tree_find_node(sub_unit_tree, domain_value);
    if (domain_tree == NULL) {
        return RPROFREP_STATUS_NOT_FOUND("Domain %ld doesn't exist.\n", domain_value);
    }

    *out_group_id = rprofrep_tree_get_leaf_value(domain_tree);
    return RPROFREP_STATUS_SUCCESS;
}

// Get a group from its id
rprofrep_status_t rprofrep_get_group_entry_by_id(
    rprofrep_decode_context_t* ctx,
    uint64_t group_id,
    rprofrep_group_entry_t** out
) {
    RPROFREP_CHECK_VALID_PTR(ctx, out);

    rprofrep_offsets_section_t* offsets_section = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_OFFSETS, (void**)&offsets_section));

    RPROFREP_CHECK_VALID_ARG(group_id < offsets_section->num_groups);

    *out = &offsets_section->groups[group_id];

    return RPROFREP_STATUS_SUCCESS;
}


static bool __rprofrep_offset_callback(rprofrep_tree_node_t* node, void* user_arg) {
    rprofrep_offset_callback_t callback = ((rprofrep_offset_callback_t*) user_arg)[0];
    rprofrep_decode_context_t* ctx      = ((rprofrep_decode_context_t**) user_arg)[1];
    rprofrep_status_t* status           = ((rprofrep_status_t**)         user_arg)[2];
    void* ua                            = ((void**)                      user_arg)[3];

    *status = callback(ctx, node, ua);
    return rprofrep_status_is_success(*status);
}


static rprofrep_status_t rprofrep_for_each_unit(
    rprofrep_decode_context_t* ctx,
    rprofrep_tree_node_t* tree,
    rprofrep_offset_callback_t callback,
    void* user_arg
) {
    rprofrep_status_t status = RPROFREP_STATUS_SUCCESS;

    if (!tree) return status;

    rprofrep_tree_for_each_child(tree, __rprofrep_offset_callback,
        (void*[4]){ callback, ctx, &status, user_arg });

    return status;
}

rprofrep_status_t rprofrep_for_each_pid(
    rprofrep_decode_context_t* ctx,
    rprofrep_offset_callback_t callback,
    void* user_arg
) {
    RPROFREP_CHECK_VALID_PTR(ctx, callback);

    rprofrep_offsets_section_t* offsets_section = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_OFFSETS, (void**)&offsets_section));

    return rprofrep_for_each_unit(ctx, offsets_section->cpu_offset_tree, callback, user_arg);
}


rprofrep_status_t rprofrep_for_each_gpu(
    rprofrep_decode_context_t* ctx,
    rprofrep_offset_callback_t callback,
    void* user_arg
) {
    RPROFREP_CHECK_VALID_PTR(ctx, callback);

    rprofrep_offsets_section_t* offsets_section = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_OFFSETS, (void**)&offsets_section));

    return rprofrep_for_each_unit(ctx, offsets_section->gpu_offset_tree, callback, user_arg);
}


static rprofrep_status_t __rprofrep_for_each_subunit(
    rprofrep_decode_context_t* ctx,
    rprofrep_tree_node_t* unit_node,
    rprofrep_offset_callback_t callback,
    rprofrep_tree_callback_t tree_callback,
    void* user_arg
) {
    RPROFREP_CHECK_VALID_PTR(unit_node, callback);

    rprofrep_status_t status = RPROFREP_STATUS_SUCCESS;
    rprofrep_tree_for_each_child(unit_node, tree_callback, (void*[4]){callback, ctx, &status, user_arg});
    return status;
}


static bool __rprofrep_offset_callback_for_sdma(rprofrep_tree_node_t* node, void* user_arg) {
    rprofrep_offset_callback_t callback = ((rprofrep_offset_callback_t*) user_arg)[0];
    rprofrep_decode_context_t* ctx      = ((rprofrep_decode_context_t**) user_arg)[1];
    rprofrep_status_t* status           = ((rprofrep_status_t**)         user_arg)[2];
    void* ua                            = ((void**)                      user_arg)[3];

    if ((int64_t) node->value >= 0) {
         *status = RPROFREP_STATUS_SUCCESS; // Skip non-sdma subunits
         return true;
    }
    *status = callback(ctx, node, ua);
    return rprofrep_status_is_success(*status);
}

static bool __rprofrep_offset_callback_for_queue(rprofrep_tree_node_t* node, void* user_arg) {
    rprofrep_offset_callback_t callback = ((rprofrep_offset_callback_t*) user_arg)[0];
    rprofrep_decode_context_t* ctx      = ((rprofrep_decode_context_t**) user_arg)[1];
    rprofrep_status_t* status           = ((rprofrep_status_t**)         user_arg)[2];
    void* ua                            = ((void**)                      user_arg)[3];

    if ((int64_t) node->value < 0) {
         *status = RPROFREP_STATUS_SUCCESS; // Skip sdma subunits
         return true;
    }
    *status = callback(ctx, node, ua);
    return rprofrep_status_is_success(*status);
}


rprofrep_status_t rprofrep_for_each_sdma(
    rprofrep_decode_context_t* ctx,
    rprofrep_tree_node_t* unit_node,
    rprofrep_offset_callback_t callback,
    void* user_arg
) {
    return __rprofrep_for_each_subunit(ctx, unit_node, callback, __rprofrep_offset_callback_for_sdma, user_arg);
}


rprofrep_status_t rprofrep_for_each_queue(
    rprofrep_decode_context_t* ctx,
    rprofrep_tree_node_t* unit_node,
    rprofrep_offset_callback_t callback,
    void* user_arg
) {
    return __rprofrep_for_each_subunit(ctx, unit_node, callback, __rprofrep_offset_callback_for_queue, user_arg);
}


rprofrep_status_t rprofrep_for_each_tid(
    rprofrep_decode_context_t* ctx,
    rprofrep_tree_node_t* unit_node,
    rprofrep_offset_callback_t callback,
    void* user_arg
) {
    return __rprofrep_for_each_subunit(ctx, unit_node, callback, __rprofrep_offset_callback, user_arg);
}


static bool __rprofrep_groups_callback(rprofrep_tree_node_t* node, void* user_arg) {
    rprofrep_groups_callback_t callback = ((rprofrep_groups_callback_t*) user_arg)[0];
    rprofrep_decode_context_t* ctx      = ((rprofrep_decode_context_t**) user_arg)[1];
    rprofrep_status_t* status           = ((rprofrep_status_t**)         user_arg)[2];
    void* ua                            = ((void**)                      user_arg)[3];
    
    uint64_t group_id = rprofrep_tree_get_leaf_value(node);
    if (group_id == (uint64_t)-1) {
        *status = RPROFREP_STATUS_ERROR("Leaf node does not have a valid group ID.\n");
        return false;
    }

    rprofrep_group_entry_t* group = NULL;
    *status = rprofrep_get_group_entry_by_id(ctx, group_id, &group);
    if (rprofrep_status_is_success(*status)) {
        *status = callback(ctx, group, ua);
    }
    return rprofrep_status_is_success(*status);
}



rprofrep_status_t rprofrep_for_each_domain(
    rprofrep_decode_context_t* ctx,
    rprofrep_tree_node_t* sub_unit_node,
    rprofrep_groups_callback_t callback,
    void* user_arg
) {
    RPROFREP_CHECK_VALID_PTR(sub_unit_node, callback);

    rprofrep_status_t status = RPROFREP_STATUS_SUCCESS;
    rprofrep_tree_for_each_child(sub_unit_node, __rprofrep_groups_callback, (void*[4]){callback, ctx, &status, user_arg});
    return status;
}


rprofrep_status_t rprofrep_is_domain_traced(rprofrep_decode_context_t* ctx, ratelprof_domain_t domain, bool* is_traced) {
    
    rprofrep_offsets_section_t* offsets_section = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_section(ctx, RPROFREP_SECTION_OFFSETS, (void**)&offsets_section));

    *is_traced = offsets_section->domain_mask & (1U << domain);

    return RPROFREP_STATUS_SUCCESS;
}

