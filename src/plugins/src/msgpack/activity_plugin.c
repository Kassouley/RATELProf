#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>

#include <ratelprof.h>
#include <ratelprof_ext.h>
#include "msgpack.h"
#include "activity_plugin.h"

typedef struct {
    msgpack_buffer_t buffer;
    size_t size;
} plugin_traces_t;

// Helper function to add common activity data to the buffer
void add_activity_data_to_buffer(msgpack_buffer_t* buf, 
                                  const ratelprof_api_activity_t* activity, 
                                  const char* name)
{
    ratelprof_time_t start = ratelprof_get_timestamp_ns(activity->start_time);
    ratelprof_time_t stop = ratelprof_get_timestamp_ns(activity->stop_time);

    msgpack_encode_uint(buf, activity->id);
    msgpack_encode_map(buf, 9);

    msgpack_encode_string(buf, "p");
    msgpack_encode_uint(buf, activity->phase);
    
    msgpack_encode_string(buf, "name");
    msgpack_encode_string(buf, name);
    
    msgpack_encode_string(buf, "corr_id");
    msgpack_encode_uint(buf, activity->corr_id);
    
    msgpack_encode_string(buf, "start");
    msgpack_encode_uint(buf, start);
    
    msgpack_encode_string(buf, "stop");
    msgpack_encode_uint(buf, stop);
    
    msgpack_encode_string(buf, "dur");
    msgpack_encode_uint(buf, stop-start);
    
    msgpack_encode_string(buf, "pid");
    msgpack_encode_uint(buf, activity->pid);
    
    msgpack_encode_string(buf, "tid");
    msgpack_encode_uint(buf, activity->tid);
    
    msgpack_encode_string(buf, "args");
}

void ompt_activity_callback(const ratelprof_ompt_api_activity_t* activity, msgpack_buffer_t* buf)
{
    ratelprof_time_t start = ratelprof_get_timestamp_ns(activity->start_time);
    ratelprof_time_t stop = ratelprof_get_timestamp_ns(activity->stop_time);

    msgpack_encode_uint(buf, activity->id);
    msgpack_encode_map(buf, 9);

    msgpack_encode_string(buf, "p");
    msgpack_encode_uint(buf, activity->phase);
    
    msgpack_encode_string(buf, "name");
    msgpack_encode_string(buf, get_ompt_funame_by_id(activity->funid));
    
    msgpack_encode_string(buf, "corr_id");
    msgpack_encode_uint(buf, activity->corr_id);
    
    msgpack_encode_string(buf, "start");
    msgpack_encode_uint(buf, start);
    
    msgpack_encode_string(buf, "stop");
    msgpack_encode_uint(buf, stop);
    
    msgpack_encode_string(buf, "dur");
    msgpack_encode_uint(buf, stop-start);
    
    msgpack_encode_string(buf, "pid");
    msgpack_encode_uint(buf, activity->pid);
    
    msgpack_encode_string(buf, "tid");
    msgpack_encode_uint(buf, activity->tid);
    
    msgpack_encode_string(buf, "args");
    process_ompt_args_for(activity->funid, &activity->args, buf);
}

void omp_routine_activity_callback(const ratelprof_api_activity_t* activity, msgpack_buffer_t* buf)
{
    add_activity_data_to_buffer(buf, activity, get_omp_routine_funame_by_id(activity->funid));
    process_omp_routine_args_for(activity->funid, &activity->omp_routine_args, buf);
}

void omp_tgt_rtl_activity_callback(const ratelprof_api_activity_t* activity, msgpack_buffer_t* buf)
{
    add_activity_data_to_buffer(buf, activity, get_omp_tgt_rtl_funame_by_id(activity->funid));
    process_omp_tgt_rtl_args_for(activity->funid, &activity->omp_tgt_rtl_args, buf);
}

void hsa_activity_callback(const ratelprof_api_activity_t* activity, msgpack_buffer_t* buf)
{
    add_activity_data_to_buffer(buf, activity, get_hsa_funame_by_id(activity->funid));
    process_hsa_args_for(activity->funid, &activity->hsa_args, buf);
}

void hip_activity_callback(const ratelprof_api_activity_t* activity, msgpack_buffer_t* buf)
{
    add_activity_data_to_buffer(buf, activity, get_hip_funame_by_id(activity->funid));
    process_hip_args_for(activity->funid, &activity->hip_args, buf);
}


void gpu_activity_callback(const ratelprof_gpu_activity_t* activity, msgpack_buffer_t* buf)
{
    int i = 0;
    msgpack_encode_uint(buf, activity->id);
    msgpack_encode_map(buf, 7);

    msgpack_encode_string(buf, "p");
    msgpack_encode_uint(buf, activity->phase);
    
    msgpack_encode_string(buf, "corr_id");
    msgpack_encode_uint(buf, activity->corr_id);
    
    msgpack_encode_string(buf, "start");
    msgpack_encode_uint(buf, activity->start_time);
    
    msgpack_encode_string(buf, "stop");
    msgpack_encode_uint(buf, activity->stop_time);
    
    msgpack_encode_string(buf, "dur");
    msgpack_encode_uint(buf, activity->stop_time-activity->start_time);
    
    msgpack_encode_string(buf, "sig");
    msgpack_encode_uint(buf, activity->completion_signal.handle);

    msgpack_encode_string(buf, "args");

    switch ((int)activity->domain)
    {
        case RATELPROF_DOMAIN_BARRIEROR:
        case RATELPROF_DOMAIN_BARRIERAND: {
            msgpack_encode_map(buf, 4);

            msgpack_encode_string(buf, "dispatch_time");
            msgpack_encode_uint(buf, ratelprof_get_timestamp_ns(activity->args.dispatch.dispatch_time));

            msgpack_encode_string(buf, "gpu_id");
            msgpack_encode_uint(buf, activity->args.dispatch.agent.handle);

            msgpack_encode_string(buf, "queue_id");
            msgpack_encode_uint(buf, activity->args.dispatch.queue_id);

            msgpack_encode_string(buf, "dep_signal");
            msgpack_encode_array(buf, 5);
            for (i = 0; i < 5; i++)
            {
                msgpack_encode_uint(buf, activity->args.dispatch.barrier.dep_signal[i].handle);
            }
            
            break;
        }
        case RATELPROF_DOMAIN_KERNEL:
            
            msgpack_encode_map(buf, 10);

            msgpack_encode_string(buf, "kernel_name");
            msgpack_encode_string(buf, get_kernel_name(activity->args.dispatch.kernel.kernel_object));

            msgpack_encode_string(buf, "dispatch_time");
            msgpack_encode_uint(buf, ratelprof_get_timestamp_ns(activity->args.dispatch.dispatch_time));
            
            msgpack_encode_string(buf, "gpu_id");
            msgpack_encode_uint(buf, activity->args.dispatch.agent.handle);

            msgpack_encode_string(buf, "queue_id");
            msgpack_encode_uint(buf, activity->args.dispatch.queue_id);

            msgpack_encode_string(buf, "wrg");
            msgpack_encode_array(buf, 3);
            msgpack_encode_uint(buf, activity->args.dispatch.kernel.workgroup_size_x);
            msgpack_encode_uint(buf, activity->args.dispatch.kernel.workgroup_size_y);
            msgpack_encode_uint(buf, activity->args.dispatch.kernel.workgroup_size_z);
            
            msgpack_encode_string(buf, "grd");
            msgpack_encode_array(buf, 3);
            msgpack_encode_uint(buf, activity->args.dispatch.kernel.grid_size_x);
            msgpack_encode_uint(buf, activity->args.dispatch.kernel.grid_size_y);
            msgpack_encode_uint(buf, activity->args.dispatch.kernel.grid_size_z);

            msgpack_encode_string(buf, "private_segment_size");
            msgpack_encode_uint(buf, activity->args.dispatch.kernel.private_segment_size);

            msgpack_encode_string(buf, "group_segment_size");
            msgpack_encode_uint(buf, activity->args.dispatch.kernel.group_segment_size);

            msgpack_encode_string(buf, "kernel_object");
            msgpack_encode_uint(buf, activity->args.dispatch.kernel.kernel_object);

            msgpack_encode_string(buf, "kernarg_address");
            msgpack_encode_uint(buf, (uintptr_t)activity->args.dispatch.kernel.kernarg_address);
            break;

        case RATELPROF_DOMAIN_COPY:
            msgpack_encode_map(buf, 6);

            msgpack_encode_string(buf, "src_agent");
            msgpack_encode_uint(buf, activity->args.mem_copy.src_agent.handle);

            msgpack_encode_string(buf, "dst_agent");
            msgpack_encode_uint(buf, activity->args.mem_copy.dst_agent.handle);

            msgpack_encode_string(buf, "src_type");
            msgpack_encode_uint(buf, activity->args.mem_copy.src_type);

            msgpack_encode_string(buf, "dst_type");
            msgpack_encode_uint(buf, activity->args.mem_copy.dst_type);

            msgpack_encode_string(buf, "size");
            msgpack_encode_uint(buf, activity->args.mem_copy.size);

            msgpack_encode_string(buf, "engine_id");
            msgpack_encode_int(buf, activity->args.mem_copy.engine_id);
            break;

        default:
            LOG(LOG_LEVEL_FATAL, "Unknown GPU domain ID\n");
            exit(1);
            break;
    }
}


ratelprof_status_t activity_callback(ratelprof_domain_t domain, const void* activity, const void* last_activity, void* user_args)
{
    if (domain < 0 || (int)domain > RATELPROF_NB_DOMAIN_EXT) {
        LOG(LOG_LEVEL_FATAL, "Unknown domain : %d\n", domain);
        exit(1);
    }
    plugin_traces_t* traces = (plugin_traces_t*)user_args;
    msgpack_buffer_t* buf =  &traces[domain].buffer;
    traces[domain].size++;
    switch ((int)domain)
    {
        case RATELPROF_DOMAIN_COPY:
        case RATELPROF_DOMAIN_KERNEL:
        case RATELPROF_DOMAIN_BARRIEROR:
        case RATELPROF_DOMAIN_BARRIERAND:
            gpu_activity_callback(activity, buf);
            break;

        case RATELPROF_DOMAIN_HIP:
            hip_activity_callback(activity, buf);
            break;
        
        case RATELPROF_DOMAIN_HSA:
            hsa_activity_callback(activity, buf);
            break;
            
        case RATELPROF_DOMAIN_OMP_ROUTINE:
            omp_routine_activity_callback(activity, buf);
            break;

        case RATELPROF_DOMAIN_OMP_TGT_RTL:
            omp_tgt_rtl_activity_callback(activity, buf);
            break;

        case RATELPROF_DOMAIN_PROFILING:
            hsa_activity_callback(activity, buf);
            break;

        case RATELPROF_DOMAIN_OMP_REGION:
            ompt_activity_callback(activity, buf);
            break;

        default:
            LOG(LOG_LEVEL_FATAL, "Unknown domain : %d\n", domain);
            exit(1);
    }

    return 0;
}

    