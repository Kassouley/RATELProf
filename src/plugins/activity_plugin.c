#include <ratelprof.h>
#include <ratelprof_ext.h>
#include "activity_plugin.h"
#include "hip_plugin.h"
#include "hsa_plugin.h"

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
    case RATELPROF_DOMAIN_GPU:
        gpu_activity_callback(activity, json_buffer);
        break;

    case RATELPROF_DOMAIN_HIP:
        hip_activity_callback(activity, json_buffer);
        break;
    
    case RATELPROF_DOMAIN_HSA:
        hsa_activity_callback(activity, json_buffer);
        break;

    default:
        break;
    }
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
        "{\"d\":%d,\"operation\":%d,\"corrId\":%lu,\"start\":%lu,\"end\":%lu,",
        activity->domain, activity->op, activity->corr_id, activity->start_time, activity->stop_time);
    ratelprof_add_to_buffer(json_buffer, "\"args\":{");
    
    switch (activity->op)
    {
        case RATELPROF_BARRIEROR_OPERATION: break;
        case RATELPROF_BARRIERAND_OPERATION: break;
        case RATELPROF_KERNEL_OPERATION:
            ratelprof_add_to_buffer(json_buffer, "\"kernel_name\": \"%s\",", 
                get_kernel_name(activity->args.kernel_launch.kernel_object));
            ratelprof_add_to_buffer(json_buffer, "\"dispatch_time\": %lu,", 
                ratelprof_get_timestamp_ns(activity->args.kernel_launch.dispatch_time));
            ratelprof_add_to_buffer(json_buffer, "\"gpu_id\": %d,", 
                activity->args.kernel_launch.agent);
            ratelprof_add_to_buffer(json_buffer, "\"queue_id\": %d,", 
                activity->args.kernel_launch.queue_id);
            ratelprof_add_to_buffer(json_buffer, "\"wrg\": [%u, %u, %u],",
                activity->args.kernel_launch.workgroup_size_x, 
                activity->args.kernel_launch.workgroup_size_y, 
                activity->args.kernel_launch.workgroup_size_z);
            ratelprof_add_to_buffer(json_buffer, "\"grd\": [%u, %u, %u],",
                activity->args.kernel_launch.grid_size_x, 
                activity->args.kernel_launch.grid_size_y, 
                activity->args.kernel_launch.grid_size_z);
            ratelprof_add_to_buffer(json_buffer, "\"private_segment_size\": %u,", 
                activity->args.kernel_launch.private_segment_size);
            ratelprof_add_to_buffer(json_buffer, "\"group_segment_size\": %u,", 
                activity->args.kernel_launch.group_segment_size);
            ratelprof_add_to_buffer(json_buffer, "\"kernel_object\": %lu,", 
                activity->args.kernel_launch.kernel_object);
            ratelprof_add_to_buffer(json_buffer, "\"kernarg_address\": \"%p\"", 
                activity->args.kernel_launch.kernarg_address);
            break;

        case RATELPROF_COPY_OPERATION:
            ratelprof_add_to_buffer(json_buffer, "\"src_agent\": %d,", activity->args.mem_copy.src_agent);
            ratelprof_add_to_buffer(json_buffer, "\"dst_agent\": %d,", activity->args.mem_copy.dst_agent);
            ratelprof_add_to_buffer(json_buffer, "\"src_type\": %d,", activity->args.mem_copy.src_type);
            ratelprof_add_to_buffer(json_buffer, "\"dst_type\": %d,", activity->args.mem_copy.dst_type);
            ratelprof_add_to_buffer(json_buffer, "\"size\": %lu", activity->args.mem_copy.size);
            break;

        default:
            break;
    }
    ratelprof_add_to_buffer(json_buffer, "}}\n");
}
