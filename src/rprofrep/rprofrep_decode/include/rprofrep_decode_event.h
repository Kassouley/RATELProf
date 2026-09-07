#ifndef RPROFREP_DECODE_EVENT_H
#define RPROFREP_DECODE_EVENT_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "rprofrep_defs.h"
#include "rprofrep_status.h"

#include "utils/rprofrep_decode_type.h"

#include "sections/rprofrep_section_offsets.h"
#include "sections/rprofrep_section_location.h"


typedef struct rprofref_event_data_s {
    bool valid;
    char* name;
    uint64_t ufunid;
    int64_t  rank;
    uint64_t domain;
    uint64_t unit;
    int64_t  sub_unit;
    uint64_t id;
    uint64_t start;
    uint64_t dur;  
    uint64_t cid;
    uint64_t loc_id;
    union {
        rprofrep_api_data_entry_t* api_data;
        rprofrep_kernel_static_data_t* kernel_data;
        uint64_t memop; // For memory operations
    } extra;
    uint64_t extra_id;
    uint8_t* args;
    uint64_t args_len;
} rprofrep_event_data_t;

typedef struct rprofrep_event_filter_s {
    // Filter values
    uint64_t start;
    uint64_t stop;
    uint64_t dur;

    // Comparison flags (1 = enabled, 0 = ignore)
    bool start_GT;
    bool start_LT;
    bool stop_GT;
    bool stop_LT;
    bool dur_GT;
    bool dur_LT;
} rprofrep_event_filter_t;


static inline bool rprofrep_filter_event(
    const rprofrep_event_filter_t* f, 
    uint64_t start, uint64_t stop, uint64_t dur
) {
    if (!f) return true; // No filter means "accept all"
    return
        (!f->start_GT || start >  f->start) &&
        (!f->start_LT || start <  f->start) &&
        (!f->stop_GT  || stop  >  f->stop)  &&
        (!f->stop_LT  || stop  <  f->stop)  &&
        (!f->dur_GT   || dur   >  f->dur)   &&
        (!f->dur_LT   || dur   <  f->dur);
}


rprofrep_status_t rprofrep_find_entry_point_event(
    rprofrep_decode_context_t* ctx,
    rprofrep_event_data_t* event,
    rprofrep_event_data_t* entry_point_event,
    int64_t domain_filter);

/**
 * The function `rprofrep_get_event_by_cid` retrieves event data based on a given context and CID
 * tuple.
 * 
 * @param ctx Input of type `rprofrep_decode_context_t` used to store the context of the report. 

 * @param cid The `cid` parameter in the `rprofrep_get_event_by_cid` function is of type
 * `uint64_t`. It represents the correlation ID of the event to retrieve.
 * 
 * @param out_event This parameter is used to store the event data that is
 * retrieved by the function `rprofrep_get_event_by_cid`.
 * 
 * @return `rprofrep_status_t`
 */
rprofrep_status_t rprofrep_get_event_by_cid(
    rprofrep_decode_context_t* ctx, 
    uint64_t cid,
    rprofrep_event_data_t* out_event);



/**
 * The function `rprofrep_get_event` retrieves event data from a given group buffer based on specified
 * criteria.
 * 
 * @param ctx Input of type `rprofrep_decode_context_t` used to store the context of the report. 
 * 
 * @param group Represents a group entry. It contains information about the buffer where events are 
 * stored for that specific group.
 * 
 * @param event_off Represents the offset within a group's buffer where the event data starts.
 * It is used to locate the specific event within the buffer of events belonging to a group.
 * 
 * @param filter It is used to filter events based on certain criteria such as start time, stop time, and duration.
 * If NULL, accept all events.
 * 
 * @param out_event This parameter is used to store the event data that is
 * retrieved by the function.
 * 
 * @param cursor This variable is used to store the offset of the next event within the group buffer after
 * processing the current event. If the `cursor` parameter is not NULL, the function will not store the next offset.
 * This cursor is used to remember where will be the next event for future call.
 * 
 * @return `rprofrep_status_t`
 */
rprofrep_status_t rprofrep_get_event(
    rprofrep_decode_context_t* ctx, 
    rprofrep_group_entry_t* group,
    size_t event_off, 
    const rprofrep_event_filter_t* filter,
    rprofrep_event_data_t* out_event,
    size_t* cursor); 
    

char** rprofrep_get_event_args_labels(
    rprofrep_event_data_t* event,
    uint64_t* num_args);

#endif // RPROFREP_DECODE_EVENT_H