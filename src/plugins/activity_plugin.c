#include <ratelprof.h>
#include <ratelprof_ext.h>
#include "activity_plugin.h"
#include "hip_plugin.h"
#include "hsa_plugin.h"
#include "omp_tgt_rtl_plugin.h"

// Helper function to add common activity data to the buffer
void add_activity_data_to_buffer(ratelprof_buffer_t* json_buffer, 
                                  const ratelprof_api_activity_t* activity, 
                                  const char* name)
{
    ratelprof_time_t start = ratelprof_get_timestamp_ns(activity->start_time);
    ratelprof_time_t stop = ratelprof_get_timestamp_ns(activity->stop_time);

    ratelprof_add_to_buffer(json_buffer, 
        "{\"d\":%d,\"name\":\"%s\",\"id\":%lu,\"corr_id\":%lu,\"start\":%lu,\"end\":%lu,\"pid\":%lu,\"tid\":%lu,",
        activity->domain, name, activity->id, activity->corr_id, start, stop, activity->pid, activity->tid);
    
    ratelprof_add_to_buffer(json_buffer, "\"args\":{");
}

void activity_callback(ratelprof_domain_t domain, const void* activity, void* user_args)
{
    ratelprof_buffer_t* json_buffer = (ratelprof_buffer_t*)user_args;
    switch ((int)domain)
    {
    case RATELPROF_COPY_DOMAIN:
    case RATELPROF_KERNEL_DOMAIN:
    case RATELPROF_BARRIEROR_DOMAIN:
    case RATELPROF_BARRIERAND_DOMAIN:
        gpu_activity_callback(activity, json_buffer);
        break;

    case RATELPROF_DOMAIN_HIP:
        hip_activity_callback(activity, json_buffer);
        break;
    
    case RATELPROF_DOMAIN_HSA:
        hsa_activity_callback(activity, json_buffer);
        break;
        
    case RATELPROF_DOMAIN_OMP_TGT_RTL:
        omp_tgt_rtl_activity_callback(activity, json_buffer);
        break;

    case RATELPROF_DOMAIN_PROFILING:
        profiling_activity_callback(activity, json_buffer);
        break;

    case RATELPROF_DOMAIN_MAIN:
        main_activity_callback(activity, json_buffer);
        break;

    default:
        fprintf(stderr, "Unknown domain : %d\n", domain);
        break;
    }
}

void main_activity_callback(const ratelprof_main_activity_t* activity, ratelprof_buffer_t* json_buffer)
{
    int i = 0;
    ratelprof_time_t start = ratelprof_get_timestamp_ns(activity->start_time);
    ratelprof_time_t stop = ratelprof_get_timestamp_ns(activity->stop_time);

    ratelprof_add_to_buffer(json_buffer, 
        "{\"d\":%d,\"name\":\"%s\",\"id\":%lu,\"start\":%lu,\"end\":%lu,\"pid\":%lu,\"tid\":%lu,",
        activity->domain, "main", activity->id, start, stop, activity->pid, activity->tid);
    ratelprof_add_to_buffer(json_buffer, "\"args\":{");
	ratelprof_add_to_buffer(json_buffer, "\"ret\":\"%d\",", activity->args.retval);
	ratelprof_add_to_buffer(json_buffer, "\"argv\":[\"%s\"",activity->args.argv[i]);
    for (i = 1; i < activity->args.argc; i++)
    {
	    ratelprof_add_to_buffer(json_buffer, ",\"%s\"", activity->args.argv[i]);
    }
    ratelprof_add_to_buffer(json_buffer, "]}}\n");
}

void profiling_activity_callback(const ratelprof_profiling_activity_t* activity, ratelprof_buffer_t* json_buffer)
{
    ratelprof_time_t start = ratelprof_get_timestamp_ns(activity->start_time);
    ratelprof_time_t stop = ratelprof_get_timestamp_ns(activity->stop_time);

    ratelprof_add_to_buffer(json_buffer, 
        "{\"d\":%d,\"name\":\"%s\",\"id\":%lu,\"corr_id\":%lu,\"start\":%lu,\"end\":%lu,\"pid\":%lu,\"tid\":%lu}\n",
        activity->domain, get_prof_funame_by_id(activity->funid), activity->id, activity->corr_id, start, stop, activity->pid, activity->tid);
}
    

void omp_tgt_rtl_activity_callback(const ratelprof_api_activity_t* activity, ratelprof_buffer_t* json_buffer)
{
    add_activity_data_to_buffer(json_buffer, activity, get_omp_tgt_rtl_funame_by_id(activity->funid));
    process_omp_tgt_rtl_args_for(activity->funid, &activity->omp_tgt_rtl_args, json_buffer);
    ratelprof_add_to_buffer(json_buffer, "}}\n");
}

void hsa_activity_callback(const ratelprof_api_activity_t* activity, ratelprof_buffer_t* json_buffer)
{
    add_activity_data_to_buffer(json_buffer, activity, get_hsa_funame_by_id(activity->funid));
    process_hsa_args_for(activity->funid, &activity->hsa_args, json_buffer);
    ratelprof_add_to_buffer(json_buffer, "}}\n");
}

void hip_activity_callback(const ratelprof_api_activity_t* activity, ratelprof_buffer_t* json_buffer)
{
    add_activity_data_to_buffer(json_buffer, activity, get_hip_funame_by_id(activity->funid));
    process_hip_args_for(activity->funid, &activity->hip_args, json_buffer);
    ratelprof_add_to_buffer(json_buffer, "}}\n");
}


void gpu_activity_callback(const ratelprof_gpu_activity_t* activity, ratelprof_buffer_t* json_buffer)
{
    ratelprof_add_to_buffer(json_buffer, 
        "{\"d\":%d,\"corrId\":%lu,\"start\":%lu,\"end\":%lu,\"dur\":%lu,\"sig\":%lu,",
        activity->domain, activity->corr_id, activity->start_time, activity->stop_time, activity->stop_time-activity->start_time ,activity->completion_signal.handle);
    ratelprof_add_to_buffer(json_buffer, "\"args\":{");

    switch (activity->domain)
    {
        case RATELPROF_BARRIEROR_DOMAIN:
        case RATELPROF_BARRIERAND_DOMAIN:
            ratelprof_add_to_buffer(json_buffer, "\"dispatch_time\":%lu,", 
                ratelprof_get_timestamp_ns(activity->args.dispatch.dispatch_time));
            ratelprof_add_to_buffer(json_buffer, "\"gpu_id\":%d,", 
                activity->args.dispatch.agent);
            ratelprof_add_to_buffer(json_buffer, "\"queue_id\":%d,", 
                activity->args.dispatch.queue_id);
            ratelprof_add_to_buffer(json_buffer, "\"dep_signal\":[%lu,%lu,%lu,%lu,%lu]", 
                activity->args.dispatch.barrier.dep_signal[0],
                activity->args.dispatch.barrier.dep_signal[1],
                activity->args.dispatch.barrier.dep_signal[2],
                activity->args.dispatch.barrier.dep_signal[3],
                activity->args.dispatch.barrier.dep_signal[4]);
            break;
        case RATELPROF_KERNEL_DOMAIN:
            ratelprof_add_to_buffer(json_buffer, "\"kernel_name\":\"%s\",", 
                get_kernel_name(activity->args.dispatch.kernel.kernel_object));
            ratelprof_add_to_buffer(json_buffer, "\"dispatch_time\":%lu,", 
                ratelprof_get_timestamp_ns(activity->args.dispatch.dispatch_time));
            ratelprof_add_to_buffer(json_buffer, "\"gpu_id\":%d,", 
                activity->args.dispatch.agent);
            ratelprof_add_to_buffer(json_buffer, "\"queue_id\":%d,", 
                activity->args.dispatch.queue_id);
            ratelprof_add_to_buffer(json_buffer, "\"wrg\":[%u, %u, %u],",
                activity->args.dispatch.kernel.workgroup_size_x, 
                activity->args.dispatch.kernel.workgroup_size_y, 
                activity->args.dispatch.kernel.workgroup_size_z);
            ratelprof_add_to_buffer(json_buffer, "\"grd\":[%u, %u, %u],",
                activity->args.dispatch.kernel.grid_size_x, 
                activity->args.dispatch.kernel.grid_size_y, 
                activity->args.dispatch.kernel.grid_size_z);
            ratelprof_add_to_buffer(json_buffer, "\"private_segment_size\":%u,", 
                activity->args.dispatch.kernel.private_segment_size);
            ratelprof_add_to_buffer(json_buffer, "\"group_segment_size\":%u,", 
                activity->args.dispatch.kernel.group_segment_size);
            ratelprof_add_to_buffer(json_buffer, "\"kernel_object\":%lu,", 
                activity->args.dispatch.kernel.kernel_object);
            ratelprof_add_to_buffer(json_buffer, "\"kernarg_address\":\"%p\"", 
                activity->args.dispatch.kernel.kernarg_address);
            break;

        case RATELPROF_COPY_DOMAIN:
            ratelprof_add_to_buffer(json_buffer, "\"src_agent\":%d,", activity->args.mem_copy.src_agent);
            ratelprof_add_to_buffer(json_buffer, "\"dst_agent\":%d,", activity->args.mem_copy.dst_agent);
            ratelprof_add_to_buffer(json_buffer, "\"src_type\":%d,", activity->args.mem_copy.src_type);
            ratelprof_add_to_buffer(json_buffer, "\"dst_type\":%d,", activity->args.mem_copy.dst_type);
            ratelprof_add_to_buffer(json_buffer, "\"size\":%lu", activity->args.mem_copy.size);
            break;

        default:
            break;
    }
    ratelprof_add_to_buffer(json_buffer, "}}\n");
}
