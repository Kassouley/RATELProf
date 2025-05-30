#include <ratelprof.h>
#include <ratelprof_ext.h>
#include "json_buffer.h"
#include "activity_plugin.h"

// Helper function to add common activity data to the buffer
void add_activity_data_to_buffer(json_buffer_t* json_buffer, 
                                  const ratelprof_api_activity_t* activity, 
                                  const char* name)
{
    ratelprof_time_t start = ratelprof_get_timestamp_ns(activity->start_time);
    ratelprof_time_t stop = ratelprof_get_timestamp_ns(activity->stop_time);

    add_to_json_buffer(json_buffer, 
        "\t\t{\"d\":%d,\"p\":%d,\"name\":\"%s\",\"id\":%lu,\"corr_id\":%lu,\"start\":%lu,\"end\":%lu,\"dur\":%lu,\"pid\":%lu,\"tid\":%lu,",
        activity->domain, activity->phase, name, activity->id, activity->corr_id, start, stop, stop-start, activity->pid, activity->tid);
    
    add_to_json_buffer(json_buffer, "\"args\":{");
}

    
void omp_routine_activity_callback(const ratelprof_api_activity_t* activity, json_buffer_t* json_buffer)
{
    add_activity_data_to_buffer(json_buffer, activity, get_omp_routine_funame_by_id(activity->funid));
    process_omp_routine_args_for(activity->funid, &activity->omp_routine_args, json_buffer);
    add_to_json_buffer(json_buffer, "}");
}

void omp_tgt_rtl_activity_callback(const ratelprof_api_activity_t* activity, json_buffer_t* json_buffer)
{
    add_activity_data_to_buffer(json_buffer, activity, get_omp_tgt_rtl_funame_by_id(activity->funid));
    process_omp_tgt_rtl_args_for(activity->funid, &activity->omp_tgt_rtl_args, json_buffer);
    add_to_json_buffer(json_buffer, "}");
}

void hsa_activity_callback(const ratelprof_api_activity_t* activity, json_buffer_t* json_buffer)
{
    add_activity_data_to_buffer(json_buffer, activity, get_hsa_funame_by_id(activity->funid));
    process_hsa_args_for(activity->funid, &activity->hsa_args, json_buffer);
    add_to_json_buffer(json_buffer, "}");
}

void hip_activity_callback(const ratelprof_api_activity_t* activity, json_buffer_t* json_buffer)
{
    add_activity_data_to_buffer(json_buffer, activity, get_hip_funame_by_id(activity->funid));
    process_hip_args_for(activity->funid, &activity->hip_args, json_buffer);
    add_to_json_buffer(json_buffer, "}");
}

void ompt_activity_callback(const ratelprof_ompt_api_activity_t* activity, json_buffer_t* json_buffer)
{
    ratelprof_time_t start = ratelprof_get_timestamp_ns(activity->start_time);
    ratelprof_time_t stop = ratelprof_get_timestamp_ns(activity->stop_time);

    add_to_json_buffer(json_buffer, 
        "\t\t{\"d\":%d,\"p\":%d,\"name\":\"%s\",\"id\":%lu,\"corr_id\":%lu,\"start\":%lu,\"end\":%lu,\"dur\":%lu,\"pid\":%lu,\"tid\":%lu,",
        activity->domain, activity->phase, get_ompt_funame_by_id(activity->funid), activity->id, activity->corr_id, start, stop, stop-start, activity->pid, activity->tid);
    
    add_to_json_buffer(json_buffer, "\"args\":{");
    process_ompt_args_for(activity->funid, &activity->args, json_buffer);
    add_to_json_buffer(json_buffer, "}");
}

void gpu_activity_callback(const ratelprof_gpu_activity_t* activity, json_buffer_t* json_buffer)
{
    add_to_json_buffer(json_buffer, 
        "\t\t{\"d\":%d,\"p\":%d,\"id\":%lu,\"corr_id\":%lu,\"start\":%lu,\"end\":%lu,\"dur\":%lu,\"sig\":%lu,",
        activity->domain, activity->phase, activity->id, activity->corr_id, activity->start_time, activity->stop_time, activity->stop_time-activity->start_time ,activity->completion_signal.handle);
    add_to_json_buffer(json_buffer, "\"args\":{");

    switch ((int)activity->domain)
    {
        case RATELPROF_DOMAIN_BARRIEROR:
        case RATELPROF_DOMAIN_BARRIERAND:
            add_to_json_buffer(json_buffer, "\"dispatch_time\":%lu,", 
                ratelprof_get_timestamp_ns(activity->args.dispatch.dispatch_time));
            add_to_json_buffer(json_buffer, "\"gpu_id\":%d,", 
                activity->args.dispatch.agent);
            add_to_json_buffer(json_buffer, "\"queue_id\":%d,", 
                activity->args.dispatch.queue_id);
            add_to_json_buffer(json_buffer, "\"dep_signal\":[%lu,%lu,%lu,%lu,%lu]", 
                activity->args.dispatch.barrier.dep_signal[0],
                activity->args.dispatch.barrier.dep_signal[1],
                activity->args.dispatch.barrier.dep_signal[2],
                activity->args.dispatch.barrier.dep_signal[3],
                activity->args.dispatch.barrier.dep_signal[4]);
            break;
        case RATELPROF_DOMAIN_KERNEL:
            add_to_json_buffer(json_buffer, "\"kernel_name\":\"%s\",", 
                get_kernel_name(activity->args.dispatch.kernel.kernel_object));
            add_to_json_buffer(json_buffer, "\"dispatch_time\":%lu,", 
                ratelprof_get_timestamp_ns(activity->args.dispatch.dispatch_time));
            add_to_json_buffer(json_buffer, "\"gpu_id\":%d,", 
                activity->args.dispatch.agent);
            add_to_json_buffer(json_buffer, "\"queue_id\":%d,", 
                activity->args.dispatch.queue_id);
            add_to_json_buffer(json_buffer, "\"wrg\":[%u, %u, %u],",
                activity->args.dispatch.kernel.workgroup_size_x, 
                activity->args.dispatch.kernel.workgroup_size_y, 
                activity->args.dispatch.kernel.workgroup_size_z);
            add_to_json_buffer(json_buffer, "\"grd\":[%u, %u, %u],",
                activity->args.dispatch.kernel.grid_size_x, 
                activity->args.dispatch.kernel.grid_size_y, 
                activity->args.dispatch.kernel.grid_size_z);
            add_to_json_buffer(json_buffer, "\"private_segment_size\":%u,", 
                activity->args.dispatch.kernel.private_segment_size);
            add_to_json_buffer(json_buffer, "\"group_segment_size\":%u,", 
                activity->args.dispatch.kernel.group_segment_size);
            add_to_json_buffer(json_buffer, "\"kernel_object\":%lu,", 
                activity->args.dispatch.kernel.kernel_object);
            add_to_json_buffer(json_buffer, "\"kernarg_address\":\"%p\"", 
                activity->args.dispatch.kernel.kernarg_address);
            break;

        case RATELPROF_DOMAIN_COPY:
            add_to_json_buffer(json_buffer, "\"src_agent\":%d,", activity->args.mem_copy.src_agent);
            add_to_json_buffer(json_buffer, "\"dst_agent\":%d,", activity->args.mem_copy.dst_agent);
            add_to_json_buffer(json_buffer, "\"src_type\":%d,", activity->args.mem_copy.src_type);
            add_to_json_buffer(json_buffer, "\"dst_type\":%d,", activity->args.mem_copy.dst_type);
            add_to_json_buffer(json_buffer, "\"size\":%lu", activity->args.mem_copy.size);
            break;

        default:
            break;
    }
    add_to_json_buffer(json_buffer, "}");
}


ratelprof_status_t activity_callback(ratelprof_domain_t domain, const void* activity, const void* last_activity, void* user_args)
{
    json_buffer_t* json_buffer = (json_buffer_t*)user_args;
    switch ((int)domain)
    {
        case RATELPROF_DOMAIN_COPY:
        case RATELPROF_DOMAIN_KERNEL:
        case RATELPROF_DOMAIN_BARRIEROR:
        case RATELPROF_DOMAIN_BARRIERAND:
            gpu_activity_callback(activity, json_buffer);
            break;

        case RATELPROF_DOMAIN_HIP:
            hip_activity_callback(activity, json_buffer);
            break;
        
        case RATELPROF_DOMAIN_HSA:
            hsa_activity_callback(activity, json_buffer);
            break;
            
        case RATELPROF_DOMAIN_OMP_ROUTINE:
            omp_routine_activity_callback(activity, json_buffer);
            break;

        case RATELPROF_DOMAIN_OMP_TGT_RTL:
            omp_tgt_rtl_activity_callback(activity, json_buffer);
            break;

        case RATELPROF_DOMAIN_PROFILING:
            hsa_activity_callback(activity, json_buffer);
            break;

        case RATELPROF_DOMAIN_OMP_REGION:
            ompt_activity_callback(activity, json_buffer);
            break;

        default:
            fprintf(stderr, "Unknown domain : %d\n", domain);
            break;
    }
    if ( activity != last_activity ) 
        add_to_json_buffer(json_buffer, "},\n");
    else
        add_to_json_buffer(json_buffer, "}\n");

    return 0;
}