#ifndef RPROFREP_SECTION_OFFSETS_H
#define RPROFREP_SECTION_OFFSETS_H

#include <stdint.h>
#include <stdbool.h>

#include "utils/rprofrep_tree.h"
#include "utils/rprofrep_decode_type.h"

#include "rprofrep_status.h"


typedef struct rprofrep_offset_entry_s {
    uint64_t offset;
    uint64_t nevents;
    uint64_t id;
} rprofrep_offset_entry_t;

typedef struct rprofrep_group_buffer_s {
    uint8_t* buffer_start;
    uint8_t* buffer_stop;
} rprofrep_group_buffer_t;


typedef struct rprofrep_group_entry_s {
    uint64_t unit;
    uint64_t domain;
    int64_t sub_unit;
    rprofrep_group_buffer_t buffer;
    rprofrep_offset_entry_t offset_entry;
} rprofrep_group_entry_t;


typedef struct rprofrep_offsets_section_s {
    uint64_t num_groups;
    rprofrep_group_entry_t* groups;
    rprofrep_tree_node_t* offsets_tree;
} rprofrep_offsets_section_t;


typedef rprofrep_status_t (*rprofrep_groups_callback_t)(rprofrep_decode_context_t* ctx, rprofrep_group_entry_t* group, void* user_arg);

typedef rprofrep_status_t (*rprofrep_offset_callback_t)(rprofrep_decode_context_t* ctx, rprofrep_tree_node_t* node, void* user_arg);

rprofrep_status_t rprofrep_free_offsets_section(rprofrep_offsets_section_t* sct);

rprofrep_status_t rprofrep_decode_offsets_section(
    rprofrep_decode_context_t* ctx, 
    uint8_t* buffer, 
    size_t size, 
    rprofrep_offsets_section_t* out);


/**
 * The function `rprofrep_get_group_id` retrieves the group ID based on specified unit, domain, and
 * subunit values from the group tree.
 * 
 * @param ctx Input of type `rprofrep_decode_context_t` used to store the context of the report. 
 * 
 * @param unit_value Unit value is used to identify a specific unit.
 * 
 * @param domain_value Domain value is used to identify a specific domain within the unit.
 * 
 * @param sub_unit_value Sub Unit value is used to identify a specific sub unit within the domain.
 * 
 * @param out_group_id Out pointer of the group ID corresponding to the provided `unit_value`,
 * `domain_value`, and `sub_unit_value`. Error if not found.
 * 
 * @return `rprofrep_status_t`
 */
rprofrep_status_t rprofrep_get_group_id(
    rprofrep_decode_context_t* ctx,
    uint64_t domain_value,
    uint64_t unit_value,
    int64_t  sub_unit_value,
    uint64_t* out_group_id);


/**
 * The function `rprofrep_get_group_entry_by_id` retrieves a group entry by its ID from a context report
 * context.
 * 
 * @param ctx Input of type `rprofrep_decode_context_t` used to store the context of the report. 
 * 
 * @param group_id Represents an unique identifier of the group entry store in the report context.
 * 
 * @param out Pointer to a pointer of type `rprofrep_group_entry_t`. This parameter is used to store the address of the group
 * 
 * entry corresponding to the provided `group_id`.
 * 
 * @return `rprofrep_status_t`
 */
rprofrep_status_t rprofrep_get_group_entry_by_id(
    rprofrep_decode_context_t* ctx,
    uint64_t group_id,
    rprofrep_group_entry_t** out);


rprofrep_status_t rprofrep_for_each_unit(
    rprofrep_decode_context_t* ctx,
    rprofrep_offset_callback_t callback,
    void* user_arg);


rprofrep_status_t rprofrep_for_each_subunit(
    rprofrep_decode_context_t* ctx,
    rprofrep_tree_node_t* unit_node,
    rprofrep_offset_callback_t callback,
    void* user_arg);


rprofrep_status_t rprofrep_for_each_domain(
    rprofrep_decode_context_t* ctx,
    rprofrep_tree_node_t* sub_unit_node,
    rprofrep_groups_callback_t callback,
    void* user_arg);


#endif // RPROFREP_SECTION_OFFSETS_H