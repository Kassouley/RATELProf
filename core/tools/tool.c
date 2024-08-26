#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include "ratelprof.h"
#include "ratelprof_ext.h"
#include "plugin.h"


void hsa_activity_callback(const ratelprof_hsa_api_activity_t* activity, void* user_args)
{
    ratelprof_buffer_t* json_buffer = (ratelprof_buffer_t*)user_args;
    add_hsa_event(json_buffer, activity);
}

void hip_activity_callback(const ratelprof_hip_api_activity_t* activity, void* user_args)
{
    ratelprof_buffer_t* json_buffer = (ratelprof_buffer_t*)user_args;
    add_hip_event(json_buffer, activity);
}

void gpu_activity_callback(const ratelprof_gpu_activity_t* activity, void* user_args)
{
    printf("Operation | start : %lu | stop : %lu | duration : %lu\n", 
                                activity->start_time, 
                                activity->stop_time,
                                activity->stop_time - activity->start_time);
    switch (activity->op)
    {
        case RATELPROF_KERNEL_OPERATION:
        case RATELPROF_BARRIERAND_OPERATION:
        case RATELPROF_BARRIEROR_OPERATION:
            printf("\t\tworkgroup_size %u %u %u\n",activity->args.kernel_launch.workgroup_size_x, activity->args.kernel_launch.workgroup_size_y, activity->args.kernel_launch.workgroup_size_z);
            printf("\t\tgrid_size %u %u %u\n",activity->args.kernel_launch.grid_size_x, activity->args.kernel_launch.grid_size_y, activity->args.kernel_launch.grid_size_z);
            printf("\t\thandle %lu\n",activity->args.kernel_launch.kernel_object);
            break;
        case RATELPROF_COPY_OPERATION:
            break;
        
        default:
            break;
    }
}

ratelprof_buffer_t json_buffer = {};

__attribute__((constructor)) void init(void) 
{
    ratelprof_init();
    json_buffer = create_json_trace("test.json");

    ratelprof_pool_properties_t props = {
        .hsa_activity_callback = hsa_activity_callback,
        .hip_activity_callback = hip_activity_callback,
        .gpu_activity_callback = gpu_activity_callback,
        .hsa_activity_callback_user_args = &json_buffer, 
        .hip_activity_callback_user_args = &json_buffer,
        .gpu_activity_callback_user_args = &json_buffer
    };
    ratelprof_activity_pool_init(&props);

    bool* is_profiled = get_profiled_domain();

    if (is_profiled[RATELPROF_DOMAIN_HSA]) {
        set_hsa_profile_callback(hsa_callback);
        ratelprof_enable_domain(RATELPROF_DOMAIN_HSA);
    }
    if (is_profiled[RATELPROF_DOMAIN_HIP]) {
        set_hip_profile_callback(hip_callback);
        ratelprof_enable_domain(RATELPROF_DOMAIN_HIP);
    }

    free(is_profiled);
}

__attribute__((destructor)) void fini(void) {
    ratelprof_activity_pool_flush_activities();
    close_json_trace(&json_buffer);
    ratelprof_fini();
}
