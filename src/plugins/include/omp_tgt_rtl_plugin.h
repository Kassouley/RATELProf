/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#ifndef OMP_TGT_RTL_PLUGIN_H 
#define OMP_TGT_RTL_PLUGIN_H 

#include <ratelprof.h>

void on_enter_omp_tgt_rtl_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, void* user_activity);
void on_exit_omp_tgt_rtl_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, void* user_activity);
void process_omp_tgt_rtl_args_for(omp_tgt_rtl_api_id_t funid, const omp_tgt_rtl_api_args_t* args, void* user_args);

#endif // OMP_TGT_RTL_PLUGIN_H