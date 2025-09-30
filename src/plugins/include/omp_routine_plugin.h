/** THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.

 */

#ifndef OMP_ROUTINE_PLUGIN_H
#define OMP_ROUTINE_PLUGIN_H

#include <ratelprof.h>

void on_enter_omp_routine_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, void* user_activity);
void on_exit_omp_routine_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, void* user_activity);
void process_omp_routine_args_for(omp_routine_api_id_t funid, const void* func_args, void* user_args);

#endif // OMP_ROUTINE_PLUGIN_H

