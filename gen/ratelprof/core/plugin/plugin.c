/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#include "ratelprof.h"
#include "plugin.h"

void hsa_callback(bool is_enter, ratelprof_hsa_api_activity_t* activity)
{
    if (is_enter)
        printf("%s | CID: %lu\n", get_hsa_funame_by_id(activity->funid), get_next_correlation_id());
    else if (!is_enter)
        process_hsa_args_for(activity->funid, &activity->args);
}
    
void hip_callback(bool is_enter, ratelprof_hip_api_activity_t* activity)
{
    if (is_enter)
        printf("%s | CID: %lu\n", get_hip_funame_by_id(activity->funid), get_next_correlation_id());
    else if (!is_enter)
        process_hip_args_for(activity->funid, &activity->args);
}
    