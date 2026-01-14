#include <stdio.h>
#include <stdlib.h>

#include "rprofrep_core.h"
#include "rprofrep_fwd.h"

#include "sections/rprofrep_section_global.h"

rprofrep_status_t rprofrep_write_global_section(rprofrep_encode_context_t* ctx, void* data, const char* filename)
{
    (void) ctx;
    (void) data;
    
    size_t i = 0;
    ratelprof_lifecycle_t* lc = ratelprof_get_lifecycle();

    msgpack_buffer_t buf = {0};
    msgpack_init(&buf, 0xFFFF, MSGPACK_OVERFLOW_WRITE_TO_FILE, filename);

    // Encode experiment rank
    msgpack_encode_int(&buf, get_mpi_rank_from_env());

    // Encode tool version
    msgpack_encode_uint(&buf, RATELPROF_VERSION_MAJOR);
    msgpack_encode_uint(&buf, RATELPROF_VERSION_MINOR);
    msgpack_encode_uint(&buf, RATELPROF_VERSION_PATCH);

    // Encode experiment start
    msgpack_encode_uint(&buf, ratelprof_get_timestamp_ns(lc->experiment_start_epoch));

    // Encode lifecycle stop time (first start is 0 and other start are prev stop)
    for (i = 0; i < RATELPROF_NB_PHASE; i++)
    {
        ratelprof_time_t t = ratelprof_get_timestamp_ns(lc->phase_stop_ts[i]);
        msgpack_encode_uint(&buf, ratelprof_get_normalized_time(t));
    }

    
    // Encode main data
    msgpack_encode_int(&buf, lc->main_data.retval);
    msgpack_encode_uint(&buf, lc->main_data.argc);
    for (i = 0; i < lc->main_data.argc; i++)
    {
        msgpack_encode_string(&buf, lc->main_data.argv[i]);
    }

    // Encode map Node ID to Agent Object
    ratelprof_object_tracking_pool_t* pool = ratelprof_object_tracking_pool_get_pool();
    ratelprof_agent_object_t*  agents_list = pool->agents_list;
    size_t                    agents_count = pool->agents_count;

    if (agents_list && agents_count > 0) {
        msgpack_encode_uint(&buf, agents_count);
        for (i = 0; i < agents_count; i++) {
            msgpack_encode_uint(&buf, agents_list[i].handle);
            msgpack_encode_uint(&buf, i);
        }
    } else {
        return RPROFREP_STATUS_ERROR("Shouldn't reach\n");
    }

    msgpack_write(&buf);
    msgpack_free(&buf);

    return RPROFREP_STATUS_SUCCESS;
}