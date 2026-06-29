#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "rprofrep_status.h"
#include "rprofrep_decode_event.h"

#include "utils/rprofrep_decode_type.h"
#include "utils/rprofrep_read_utils.h"

#include "sections/rprofrep_section_header.h"
#include "sections/rprofrep_section_events.h"
#include "sections/rprofrep_section_offsets.h"
#include "sections/rprofrep_section_location.h"
#include "sections/rprofrep_section_global.h"


rprofrep_status_t rprofrep_find_entry_point_event(
    rprofrep_decode_context_t* ctx,
    rprofrep_event_data_t* event,
    rprofrep_event_data_t* entry_point_event,
    int64_t domain_filter
) {
    RPROFREP_CHECK_VALID_PTR(event, entry_point_event);

    if (!event->valid || !event->cid.valid) {
        entry_point_event->valid = false;
        return RPROFREP_STATUS_SUCCESS;
    }

    rprofrep_event_data_t current_event = *event;
    rprofrep_event_data_t parent_event;
    rprofrep_event_data_t last_matching_event;
    bool found_match = false;

    // Walk up the parent chain
    while (current_event.cid.valid) {
        RPROFREP_CHECK_CALL(
            rprofrep_get_event_by_cid(
                ctx,
                &current_event.cid,
                &parent_event
            )
        );
        current_event = parent_event;
        if (domain_filter != -1 && current_event.domain == domain_filter) {
            last_matching_event = current_event;
            found_match = true;
        }
    }

    *entry_point_event = found_match ? last_matching_event : current_event;
    return RPROFREP_STATUS_SUCCESS;
}

// Get the event for a given cid
rprofrep_status_t rprofrep_get_event_by_cid(
    rprofrep_decode_context_t* ctx, 
    rprofrep_cid_tuple_t* cid,
    rprofrep_event_data_t* out_event
) {
    RPROFREP_CHECK_VALID_PTR(cid);

    if (!cid->valid) {
        out_event->valid = false;
        return RPROFREP_STATUS_SUCCESS;
    }

    rprofrep_group_entry_t* group = NULL;
    RPROFREP_CHECK_CALL(rprofrep_get_group_entry_by_id(ctx, cid->group_id, &group));

    RPROFREP_CHECK_CALL(rprofrep_get_event(ctx, group, cid->offset, NULL, out_event, NULL));
   
    return RPROFREP_STATUS_SUCCESS;
}

// Get the event at cursor and move the cursor if needed
rprofrep_status_t rprofrep_get_event(
    rprofrep_decode_context_t* ctx, 
    rprofrep_group_entry_t* group,
    size_t event_off, 
    const rprofrep_event_filter_t* filter,
    rprofrep_event_data_t* out_event,
    size_t* cursor
) {
    RPROFREP_CHECK_VALID_PTR(ctx, group, out_event);

    out_event->valid = false;

    rprofrep_events_section_t* evt_sct = (rprofrep_events_section_t*) ctx->sections[RPROFREP_SECTION_EVENTS].data;

    size_t   global_buffer_size = evt_sct->size;
    uint8_t* global_buffer      = evt_sct->buffer;

    uint8_t* buffer_start = group->buffer.buffer_start;
    uint8_t* buffer_stop  = group->buffer.buffer_stop;

    uint8_t* event_buf = buffer_start + event_off;
    if (event_buf >= buffer_stop) {
        return RPROFREP_STATUS_SUCCESS; // Read too far from the group
    }

    size_t offset = 0;

    uint8_t magic = event_buf[offset++];
    if (magic != 0xc1) {
        return RPROFREP_STATUS_INVALID_EVENT("Missing magic byte\n");
    }

    uint64_t event_size  = __read_mp_uint(event_buf, &offset);
    if (event_size == 0) {
        return RPROFREP_STATUS_INVALID_EVENT("Invalid size value\n");
    }

    size_t   event_hdr_size = offset;
    size_t   next_event_off = event_off + offset + event_size;
    uint8_t* next_event_buf = buffer_start + next_event_off;

    if (next_event_buf > buffer_stop) {
        return RPROFREP_STATUS_INVALID_EVENT("Event size exceeds group buffer\n");
    }

    // The next event, whatever its group, must start with the magic byte
    if (next_event_buf < global_buffer + global_buffer_size && next_event_buf[0] != 0xc1) {
        return RPROFREP_STATUS_INVALID_EVENT("The next event is not valid");
    }

    uint64_t id    = __read_mp_uint(event_buf, &offset);
    uint64_t start = __read_mp_uint(event_buf, &offset);
    uint64_t dur   = __read_mp_uint(event_buf, &offset);

    if (!rprofrep_filter_event(filter, start, start + dur, dur)) {
        if (next_event_buf < buffer_stop) {
            return rprofrep_get_event(ctx, group, next_event_off, filter, out_event, cursor);
        }
        return RPROFREP_STATUS_SUCCESS;
    }

    rprofrep_cid_tuple_t cid = __read_mp_cid(event_buf, &offset);

    int64_t rank = -1;
    RPROFREP_CHECK_CALL(rprofrep_get_rank(ctx, &rank));

    char* name = NULL;
    uint64_t loc_id = (uint64_t) -1;
    uint64_t extra_id = (uint64_t) -1;
    uint64_t unique_funid = (uint64_t) -1;

    if(group->domain == RATELPROF_DOMAIN_ROCTX) {
        extra_id = __read_mp_uint(event_buf, &offset);
        loc_id   = __read_mp_uint(event_buf, &offset);
        RPROFREP_CHECK_CALL(rprofrep_get_string_by_id(ctx, extra_id, &name));
        unique_funid = extra_id;
    } else if(!is_gpu_domain(group->domain)) {
        extra_id = __read_mp_uint(event_buf, &offset);
        loc_id   = __read_mp_uint(event_buf, &offset);
        RPROFREP_CHECK_CALL(rprofrep_get_api_data(ctx, extra_id, &out_event->extra.api_data));
        name = out_event->extra.api_data->fname;
        unique_funid = out_event->extra.api_data->fname_strid;

    } else if (group->domain == RATELPROF_DOMAIN_MEMORY) {
        extra_id = __read_mp_uint(event_buf, &offset);
        out_event->extra.memop = __read_mp_uint(event_buf, &offset);
        RPROFREP_CHECK_CALL(rprofrep_get_string_by_id(ctx, extra_id, &name));

        unique_funid = extra_id;

    } else if (group->domain == RATELPROF_DOMAIN_KERNEL) {
        extra_id = __read_mp_uint(event_buf, &offset);
        RPROFREP_CHECK_CALL(rprofrep_get_kernel(ctx, extra_id, &out_event->extra.kernel_data));
        name = out_event->extra.kernel_data->kernel_name;
        unique_funid = out_event->extra.kernel_data->kernel_strid;

    } else {
        name = "Barrier";
    }

    if (cursor) *cursor = next_event_off;

    out_event->valid    = true;
    out_event->name     = name;
    out_event->ufunid   = unique_funid;
    out_event->rank     = rank;
    out_event->unit     = group->unit;
    out_event->domain   = group->domain;
    out_event->sub_unit = group->sub_unit;
    out_event->id       = id;
    out_event->start    = start;
    out_event->dur      = dur;
    out_event->cid      = cid;
    out_event->loc_id   = loc_id;
    out_event->extra_id = extra_id;
    out_event->args     = event_buf + offset;
    out_event->args_len = (event_hdr_size + event_size) - offset;

    return RPROFREP_STATUS_SUCCESS;
}


/* GPU argument labels per domain */
static char* __gpu_kernel_args[]    = {"completion_signal", "dispatch_time", "wgr", "grd", "args_addr"};
static char* __gpu_sdma_copy_args[] = {"completion_signal", "size", "other_handle"};
static char* __gpu_blit_copy_args[] = {"completion_signal", "size", "other_handle", "dispatch_time", "workgroup_size_x"};
static char* __gpu_blit_fill_args[] = {"completion_signal", "size", "dispatch_time", "workgroup_size_x"};
static char* __gpu_barrier_args[]   = {"completion_signal", "dispatch_time", "dep_signal"};

char** rprofrep_get_event_args_labels(
    rprofrep_event_data_t* event,
    uint64_t* num_args
) {
    if (event->domain == RATELPROF_DOMAIN_ROCTX) {
        *num_args = 0;
        return NULL;
    } else if (!is_gpu_domain(event->domain)) {
        *num_args = event->extra.api_data->num_args;
        return event->extra.api_data->arg_names;
    } else if (event->domain == RATELPROF_DOMAIN_MEMORY) {
        if (is_blit_copy_kernel(event->extra.memop)) {
            *num_args = 5;
            return __gpu_blit_copy_args;
        } else if (is_blit_set_kernel(event->extra.memop)) {
            *num_args = 4;
            return __gpu_blit_fill_args;
        } else if (event->extra.memop == RATELPROF_MEMORY_OP_SDMA_COPY) {
            *num_args = 3;
            return __gpu_sdma_copy_args;
        }
    } else if (event->domain == RATELPROF_DOMAIN_BARRIERAND || event->domain == RATELPROF_DOMAIN_BARRIEROR) {
        *num_args = 3;
        return __gpu_barrier_args;
    } else if (event->domain == RATELPROF_DOMAIN_KERNEL) {
        *num_args = 5;
        return __gpu_kernel_args;
    }

    *num_args = 0;
    return NULL;
}
