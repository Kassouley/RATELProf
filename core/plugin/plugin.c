/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#include "ratelprof.h"
#include "plugin.h"

#include "ratelprof.h"
#include "ratelprof_ext.h"

void hsa_callback(bool is_enter, ratelprof_hsa_api_activity_t* activity)
{
    ratelprof_time_t timestamp_ns = ratelprof_get_timestamp_ns();
    if (is_enter){
        activity->corrId = get_curr_correlation_id();
        activity->start_time = timestamp_ns;
    } else {
        activity->stop_time = timestamp_ns;
        activity->pid = get_pid();
        activity->tid = get_tid();
        ratelprof_activity_pool_push_hsa_activity(activity);
    }
}
    
void hip_callback(bool is_enter, ratelprof_hip_api_activity_t* activity)
{
    ratelprof_time_t timestamp_ns = ratelprof_get_timestamp_ns();
    if (is_enter){
        activity->corrId = get_next_correlation_id();
        activity->start_time = timestamp_ns;
    } else {
        activity->stop_time = timestamp_ns;
        activity->pid = get_pid();
        activity->tid = get_tid();
        ratelprof_activity_pool_push_hip_activity(activity);
    }
}
    