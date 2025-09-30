/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#ifndef OMPT_PLUGIN_H 
#define OMPT_PLUGIN_H 

#include <ratelprof.h>
#include <ratelprof_ext.h>

void on_enter_ompt_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, void* user_activity);
void on_exit_ompt_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, void* user_activity);
void process_ompt_args_for(ompt_api_id_t funid, const void* func_args, void* user_args);

#endif // OMPT_PLUGIN_H