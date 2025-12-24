#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "rprofrep_status.h"
#include "rprofrep_decode_event.h"

#include "utils/rprofrep_decode_type.h"
#include "utils/rprofrep_event_iterator.h"

#include "sections/rprofrep_section_events.h"
#include "sections/rprofrep_section_offsets.h"

typedef struct {
    rprofrep_event_iterator_t* iterator;
    size_t index;
    bool requested_domain[RATELPROF_NB_DOMAIN_EXT];
    rprofrep_status_t status;
} iterator_creator_t;

static bool __create_iterator(rprofrep_tree_node_t* domain_node, void* user_arg) {
    iterator_creator_t* creator = (iterator_creator_t*) user_arg;
    rprofrep_event_iterator_t* iterator = creator->iterator;
    rprofrep_decode_context_t* ctx = iterator->ctx;
    rprofrep_status_t* status = &creator->status;
    *status = RPROFREP_STATUS_SUCCESS;
    
    if (creator->requested_domain[domain_node->value] == false) {
        iterator->group_count--;
        return true;
    }

    uint64_t group_id = rprofrep_tree_get_leaf_value(domain_node);
    if (group_id == (uint64_t)-1) {
        iterator->group_count--;
        printf("Should not happen: leaf node does not have a valid group ID.\n");
        return true;
    }

    size_t i = creator->index;
    *status = rprofrep_get_group_entry_by_id(ctx, group_id, &iterator->groups[i]);
    if (!rprofrep_status_is_success(*status)) {
        return false;
    }

    iterator->cursors[i] = 0;
    
    rprofrep_event_data_t event = {0};
    *status = rprofrep_get_event(
        iterator->ctx,
        iterator->groups[i],
        iterator->cursors[i],
        iterator->filter,
        &event,
        &iterator->cursors[i]);

        
    if (!rprofrep_status_is_success(*status)) {
        return false;
    }

    iterator->cached_events[i] = event;
    iterator->cache_valid[i]   = event.valid;

    creator->index++;
    return true;
}

rprofrep_status_t rprofrep_event_iterator_init(
    rprofrep_event_iterator_t* iterator,
    rprofrep_decode_context_t* ctx,
    rprofrep_tree_node_t* group_tree,
    bool requested_domain[RATELPROF_NB_DOMAIN_EXT],
    rprofrep_event_filter_t* filter
) {
    RPROFREP_CHECK_VALID_PTR(iterator, ctx, group_tree);

    uint64_t group_count = rprofrep_tree_count_leaves(group_tree);

    iterator->ctx             = ctx;
    iterator->filter          = filter;
    iterator->group_count     = group_count;
    iterator->groups          = calloc(group_count, sizeof(rprofrep_group_entry_t*));
    RPROFREP_CHECK_ALLOC(iterator->groups);
    iterator->cached_events   = calloc(group_count, sizeof(rprofrep_event_data_t));
    RPROFREP_CHECK_ALLOC(iterator->cached_events);
    iterator->cache_valid     = calloc(group_count, sizeof(bool));
    RPROFREP_CHECK_ALLOC(iterator->cache_valid);
    iterator->cursors         = calloc(group_count, sizeof(size_t));
    RPROFREP_CHECK_ALLOC(iterator->cursors);
    iterator->initialized = false;
   
    iterator_creator_t creator = {
        .iterator = iterator,
        .index    = 0,
    };
    memcpy(creator.requested_domain, requested_domain, sizeof(creator.requested_domain));

    if (rprofrep_tree_for_each_leaf(group_tree, __create_iterator, &creator) == false) {
        rprofrep_event_iterator_destroy(iterator);
        return creator.status;
    }

    if (iterator->group_count == 0) {
        rprofrep_event_iterator_destroy(iterator);
    } else {
        iterator->initialized = true;
    }

    return RPROFREP_STATUS_SUCCESS;
}


rprofrep_status_t rprofrep_event_iterator_next(
    rprofrep_event_iterator_t* iterator,
    rprofrep_event_data_t* out_event
) {
    RPROFREP_CHECK_VALID_PTR(iterator, out_event);

    if (!iterator->initialized)
        return RPROFREP_STATUS_NOT_INIT("Event iterator is not initialized !\n");

    int64_t  best_idx = -1;
    uint64_t best_start = UINT64_MAX;

    // TODO 05/12/2025 : Can be optimized
    // find the earliest valid event
    for (size_t i = 0; i < iterator->group_count; ++i) {
        if (!iterator->cache_valid[i]) continue;
        if (iterator->cached_events[i].start < best_start) {
            best_start = iterator->cached_events[i].start;
            best_idx = i;
        }
    }

    if (best_idx == -1) {
        out_event->valid = false;
        return RPROFREP_STATUS_SUCCESS; // all groups exhausted
    }

    // return the chosen event
    *out_event = iterator->cached_events[best_idx];

    // fetch the next event for that group
    rprofrep_event_data_t next_event = {0};
    RPROFREP_CHECK_CALL(rprofrep_get_event(
        iterator->ctx,
        iterator->groups[best_idx],
        iterator->cursors[best_idx],
        iterator->filter,
        &next_event,
        &iterator->cursors[best_idx])
    );
    iterator->cached_events[best_idx] = next_event;
    iterator->cache_valid[best_idx]   = next_event.valid;

    return RPROFREP_STATUS_SUCCESS;
}

rprofrep_status_t rprofrep_event_iterator_destroy(rprofrep_event_iterator_t* iterator) {
    RPROFREP_CHECK_VALID_PTR(iterator);
    free(iterator->cached_events);
    free(iterator->cache_valid);
    free(iterator->groups);
    free(iterator->cursors);
    if (iterator->filter) free(iterator->filter);
    iterator->initialized = false;
    return RPROFREP_STATUS_SUCCESS;
}
