/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#ifndef HSA_PLUGIN_H 
#define HSA_PLUGIN_H 

#include <ratelprof.h>
#include <ratelprof_ext.h>

void on_enter_hsa_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity);
void on_exit_hsa_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity);
void process_hsa_args_for(hsa_api_id_t funid, const hsa_api_args_t* args, void* user_args);

#endif // HSA_PLUGIN_H