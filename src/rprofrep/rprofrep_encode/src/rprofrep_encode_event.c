#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "rprofrep_core.h"

#include "utils/rprofrep_msgpack_ext.h"

#include "rprofrep_event_pool_buffer.h"
#include "rprofrep_encode_event.h"
#include "rprofrep_encode_type.h"

static uint64_t engine_id_from_mask(unsigned int mask) {
    if (mask == 0 || (mask & (mask - 1)) != 0) {
        return -1;
    }
    return -(__builtin_ctz(mask) + 2);
}

static ratelprof_agent_object_t* get_agent_object_from_handle(uint64_t handle) {
    ratelprof_agent_object_t* agent_obj = NULL;
    ratelprof_status_t status = ratelprof_object_tracking_pool_get_agent_from_handle(handle, (void*)&agent_obj);
    if (status != RATELPROF_STATUS_SUCCESS) {
        LOG(LOG_LEVEL_FATAL, "Failed to get agent object from handle. %s (code %d)\n", get_error_string_ext(status), status);
    }
    return agent_obj;
}

static void add_memory_activity_data_to_buffer(
    rprofrep_encode_context_t* ctx,
    ratelprof_domain_t domain, 
    const ratelprof_gpu_activity_t* activity
) {
    ratelprof_time_t start = activity->start_time;
    ratelprof_time_t stop  = activity->stop_time;
    ratelprof_time_t dur   = stop - start;

    uint64_t gpu_handle = 0;
    uint64_t other_handle = 0;
    char* event_name = NULL;

    ratelprof_memory_op_t memop = activity->args.memory.memop;
    int64_t sub_unit = 0;
    if (memop == RATELPROF_MEMORY_OP_SDMA_COPY) {
        sub_unit = engine_id_from_mask(activity->args.memory.engine_id);
    } else {
        sub_unit = activity->args.memory.blit.queue_id;
    }

    if (is_blit_copy_kernel(memop) || memop == RATELPROF_MEMORY_OP_SDMA_COPY) {
        uint64_t src_agent_handle = activity->args.memory.copy.src_agent.handle;
        uint64_t dst_agent_handle = activity->args.memory.copy.dst_agent.handle;
        ratelprof_agent_object_t* src_agent_obj = get_agent_object_from_handle(src_agent_handle);
        ratelprof_agent_object_t* dst_agent_obj = get_agent_object_from_handle(dst_agent_handle);

        uint8_t src_type = src_agent_obj->type;
        uint8_t dst_type = dst_agent_obj->type;
        event_name = get_copy_name(src_type, dst_type);
        if (src_type == 1) {
            gpu_handle = src_agent_handle;
            other_handle = dst_agent_handle;
        } else {
            gpu_handle = dst_agent_handle;
            other_handle = src_agent_handle;
        }
    } else {
        gpu_handle = activity->args.memory.blit.agent.handle;
        event_name = "Memset";
    }

    rprofrep_buffer_entry_t* entry = rprofrep_get_gpu_event_buffer(ctx, domain, gpu_handle, sub_unit);

    msgpack_buffer_t evt = {0};
    msgpack_init(&evt, 0xffff, MSGPACK_OVERFLOW_REALLOC, NULL);
    msgpack_encode_uint(&evt, activity->id);
    msgpack_encode_uint(&evt, ratelprof_get_normalized_time(start));
    msgpack_encode_uint(&evt, dur);

    rprofrep_msgpack_ext_encode_cid(ctx, &evt, activity->id, activity->corr_id, entry);

    rprofrep_msgpack_ext_encode_string(ctx, &evt, event_name);
    msgpack_encode_uint(&evt, memop);

    msgpack_encode_uint(&evt, activity->completion_signal.handle);

    if (is_blit_copy_kernel(memop) || memop == RATELPROF_MEMORY_OP_SDMA_COPY) {
        msgpack_encode_uint(&evt, activity->args.memory.copy.size);
        msgpack_encode_uint(&evt, other_handle);
    } else if (is_blit_set_kernel(memop)) {
        msgpack_encode_uint(&evt, activity->args.memory.fill.size);
        // msgpack_encode_uint(&evt, activity->args.memory.fill.pattern_size);
        // msgpack_encode_uint(&evt, activity->args.memory.fill.pattern); // TODO: encode pattern data in the future if needed
    }
    if (memop != RATELPROF_MEMORY_OP_SDMA_COPY) {
        ratelprof_time_t dispatch_time = ratelprof_get_timestamp_ns(activity->args.memory.blit.dispatch_time);
        msgpack_encode_uint(&evt, ratelprof_get_normalized_time(dispatch_time));
        msgpack_encode_uint(&evt, activity->args.memory.blit.kernel.workgroup_size_x);
    }
    
    rprofrep_msgpack_ext_encode_event(entry, &evt);
}



static void add_barrier_activity_data_to_buffer(
    rprofrep_encode_context_t* ctx,
    ratelprof_domain_t domain, 
    const ratelprof_gpu_activity_t* activity
) {
    ratelprof_time_t start = activity->start_time;
    ratelprof_time_t stop  = activity->stop_time;
    ratelprof_time_t dur   = stop - start;
    ratelprof_time_t dispatch_time = ratelprof_get_timestamp_ns(activity->args.dispatch.dispatch_time);

    rprofrep_buffer_entry_t* entry = rprofrep_get_gpu_event_buffer(ctx, domain, activity->args.dispatch.agent.handle, activity->args.dispatch.queue_id);

    msgpack_buffer_t evt = {0};
    msgpack_init(&evt, 0xffff, MSGPACK_OVERFLOW_REALLOC, NULL);
    msgpack_encode_uint(&evt, activity->id);
    msgpack_encode_uint(&evt, ratelprof_get_normalized_time(start));
    msgpack_encode_uint(&evt, dur);

    rprofrep_msgpack_ext_encode_cid(ctx, &evt, activity->id, activity->corr_id, entry);

    msgpack_encode_uint(&evt, activity->completion_signal.handle);
    msgpack_encode_uint(&evt, ratelprof_get_normalized_time(dispatch_time));
    msgpack_encode_array(&evt, 5);
    for (int i = 0; i < 5; i++)
    {
        msgpack_encode_uint(&evt, activity->args.dispatch.barrier.dep_signal[i].handle);
    }
            

    rprofrep_msgpack_ext_encode_event(entry, &evt);
}


static void add_kernel_activity_data_to_buffer(
    rprofrep_encode_context_t* ctx,
    ratelprof_domain_t domain, 
    const ratelprof_gpu_activity_t* activity
) {
    ratelprof_time_t start = activity->start_time;
    ratelprof_time_t stop  = activity->stop_time;
    ratelprof_time_t dur   = stop - start;
    ratelprof_time_t dispatch_time = ratelprof_get_timestamp_ns(activity->args.dispatch.dispatch_time);

    rprofrep_buffer_entry_t* entry = rprofrep_get_gpu_event_buffer(ctx, domain, activity->args.dispatch.agent.handle, activity->args.dispatch.queue_id);

    msgpack_buffer_t evt = {0};
    msgpack_init(&evt, 0xffff, MSGPACK_OVERFLOW_REALLOC, NULL);
    msgpack_encode_uint(&evt, activity->id);
    msgpack_encode_uint(&evt, ratelprof_get_normalized_time(start));
    msgpack_encode_uint(&evt, dur);

    rprofrep_msgpack_ext_encode_cid(ctx, &evt, activity->id, activity->corr_id, entry);

    rprofrep_msgpack_ext_encode_kernel(ctx, &evt,
        activity->args.dispatch.kernel.private_segment_size,
        activity->args.dispatch.kernel.group_segment_size,
        activity->args.dispatch.kernel.kernel_object
    );

    msgpack_encode_uint(&evt, activity->completion_signal.handle);

    msgpack_encode_uint(&evt, ratelprof_get_normalized_time(dispatch_time));
    
    const uint16_t wgx = activity->args.dispatch.kernel.workgroup_size_x;
    const uint16_t wgy = activity->args.dispatch.kernel.workgroup_size_y;
    const uint16_t wgz = activity->args.dispatch.kernel.workgroup_size_z;

    msgpack_encode_array(&evt, 3);
    msgpack_encode_uint(&evt, wgx);
    msgpack_encode_uint(&evt, wgy);
    msgpack_encode_uint(&evt, wgz);
    
    msgpack_encode_array(&evt, 3);
    msgpack_encode_uint(&evt, activity->args.dispatch.kernel.grid_size_x/wgx);
    msgpack_encode_uint(&evt, activity->args.dispatch.kernel.grid_size_y/wgy);
    msgpack_encode_uint(&evt, activity->args.dispatch.kernel.grid_size_z/wgz);

    msgpack_encode_uint(&evt, (uintptr_t)activity->args.dispatch.kernel.kernarg_address);

    rprofrep_msgpack_ext_encode_event(entry, &evt);
}



static void add_api_activity_data_to_buffer(
    rprofrep_encode_context_t* ctx,
    ratelprof_domain_t domain, 
    const ratelprof_api_activity_t* activity
) {
    ratelprof_time_t start = ratelprof_get_timestamp_ns(activity->start_time);
    ratelprof_time_t stop  = ratelprof_get_timestamp_ns(activity->stop_time);
    ratelprof_time_t dur   = stop - start;

    rprofrep_buffer_entry_t* entry = rprofrep_get_cpu_event_buffer(ctx, domain, activity->pid, activity->tid);

    msgpack_buffer_t evt = {0};
    msgpack_init(&evt, 0xffff, MSGPACK_OVERFLOW_REALLOC, NULL);
    msgpack_encode_uint(&evt, activity->id);
    msgpack_encode_uint(&evt, ratelprof_get_normalized_time(start));
    msgpack_encode_uint(&evt, dur);

    rprofrep_msgpack_ext_encode_cid(ctx, &evt, activity->id, activity->corr_id, entry);

    rprofrep_msgpack_ext_encode_api_data(ctx, &evt, domain, activity->funid);

    rprofrep_msgpack_ext_encode_loc(ctx, &evt, activity->return_address);

    rprofrep_msgpack_ext_encode_args(ctx, &evt, domain, activity->funid, activity->args);

    rprofrep_msgpack_ext_encode_event(entry, &evt);
}


static void add_roctx_activity_data_to_buffer(
    rprofrep_encode_context_t* ctx,
    ratelprof_domain_t domain, 
    const ratelprof_roctx_activity_t* activity
) {
    ratelprof_time_t start = ratelprof_get_timestamp_ns(activity->start_time);
    ratelprof_time_t stop  = ratelprof_get_timestamp_ns(activity->stop_time);
    ratelprof_time_t dur   = stop - start;

    rprofrep_buffer_entry_t* entry = rprofrep_get_cpu_event_buffer(ctx, domain, activity->pid, activity->tid);

    msgpack_buffer_t evt = {0};
    msgpack_init(&evt, 0xffff, MSGPACK_OVERFLOW_REALLOC, NULL);
    msgpack_encode_uint(&evt, activity->id);
    msgpack_encode_uint(&evt, ratelprof_get_normalized_time(start));
    msgpack_encode_uint(&evt, dur);

    rprofrep_msgpack_ext_encode_cid(ctx, &evt, activity->id, activity->corr_id, entry);

    rprofrep_msgpack_ext_encode_string(ctx, &evt, activity->message);

    rprofrep_msgpack_ext_encode_event(entry, &evt);
}


typedef void (*encode_activity_data_to_buffer_cb_t)(
    rprofrep_encode_context_t* ctx,
    ratelprof_domain_t domain,
    const void* activity
);

static encode_activity_data_to_buffer_cb_t encode_activity_data_to_buffer_cb[RATELPROF_NB_DOMAIN_EXT] = {
    [RATELPROF_DOMAIN_HSA]          = (encode_activity_data_to_buffer_cb_t) add_api_activity_data_to_buffer,
    [RATELPROF_DOMAIN_OMP_TGT_RTL]  = (encode_activity_data_to_buffer_cb_t) add_api_activity_data_to_buffer,
    [RATELPROF_DOMAIN_OMP_ROUTINE]  = (encode_activity_data_to_buffer_cb_t) add_api_activity_data_to_buffer,
    [RATELPROF_DOMAIN_HIP]          = (encode_activity_data_to_buffer_cb_t) add_api_activity_data_to_buffer,
    [RATELPROF_DOMAIN_MPI]          = (encode_activity_data_to_buffer_cb_t) add_api_activity_data_to_buffer,
    [RATELPROF_DOMAIN_OMP_REGION]   = (encode_activity_data_to_buffer_cb_t) add_api_activity_data_to_buffer,
    [RATELPROF_DOMAIN_RCCL]         = (encode_activity_data_to_buffer_cb_t) add_api_activity_data_to_buffer,
    [RATELPROF_DOMAIN_ROCBLAS]      = (encode_activity_data_to_buffer_cb_t) add_api_activity_data_to_buffer,
    [RATELPROF_DOMAIN_ROCTX]        = (encode_activity_data_to_buffer_cb_t) add_roctx_activity_data_to_buffer,
    [RATELPROF_DOMAIN_PROFILING]    = (encode_activity_data_to_buffer_cb_t) add_api_activity_data_to_buffer,
    [RATELPROF_DOMAIN_MEMORY]       = (encode_activity_data_to_buffer_cb_t) add_memory_activity_data_to_buffer,
    [RATELPROF_DOMAIN_KERNEL]       = (encode_activity_data_to_buffer_cb_t) add_kernel_activity_data_to_buffer,
    [RATELPROF_DOMAIN_BARRIERAND]   = (encode_activity_data_to_buffer_cb_t) add_barrier_activity_data_to_buffer,
    [RATELPROF_DOMAIN_BARRIEROR]    = (encode_activity_data_to_buffer_cb_t) add_barrier_activity_data_to_buffer,
};

void rprofrep_encode_activity_to_buffer(
    rprofrep_encode_context_t* ctx,
    ratelprof_domain_t domain,
    const void* activity
) {
    encode_activity_data_to_buffer_cb[domain](ctx, domain, activity);
}