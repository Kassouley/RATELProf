/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#ifndef HIP_PLUGIN_H 
#define HIP_PLUGIN_H 

#include <ratelprof.h>

void on_enter_hip_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, void* user_activity);
void on_exit_hip_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, void* user_activity);
void process_hip_args_for(hip_api_id_t funid, const hip_api_args_t* args, void* user_args);

#endif // HIP_PLUGIN_H