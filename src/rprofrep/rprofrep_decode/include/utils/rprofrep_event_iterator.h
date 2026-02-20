#ifndef RPROFREP_EVENT_ITERATOR_H
#define RPROFREP_EVENT_ITERATOR_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "utils/rprofrep_decode_type.h"

#include "sections/rprofrep_section_events.h"

#include "rprofrep_status.h"

typedef struct rprofrep_event_iterator_s {
    rprofrep_decode_context_t* ctx;
    rprofrep_group_entry_t** groups;
    size_t group_count;
    rprofrep_event_filter_t* filter;

    size_t* cursors;
    rprofrep_event_data_t* cached_events;  // one per group
    bool* cache_valid;                     // same size
    bool initialized;
} rprofrep_event_iterator_t;


rprofrep_status_t rprofrep_event_iterator_init(
    rprofrep_event_iterator_t* iterator,
    rprofrep_decode_context_t* ctx,
    rprofrep_tree_node_t* group_tree,
    bool requiered_domains[RATELPROF_NB_DOMAIN_EXT],
    rprofrep_event_filter_t* filter
);

rprofrep_status_t rprofrep_event_iterator_next(
    rprofrep_event_iterator_t* iterator,
    rprofrep_event_data_t* out_event
);

rprofrep_status_t rprofrep_event_iterator_destroy(rprofrep_event_iterator_t* iterator);

rprofrep_status_t rprofrep_event_iterator_count_events(rprofrep_event_iterator_t* iterator, size_t* num_events);

#endif // RPROFREP_EVENT_ITERATOR_H