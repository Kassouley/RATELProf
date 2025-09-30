/** THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.

 */

#ifndef MPI_PLUGIN_H
#define MPI_PLUGIN_H

#include <ratelprof.h>

void on_enter_mpi_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, void* user_activity);
void on_exit_mpi_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, void* user_activity);
void process_mpi_args_for(mpi_api_id_t funid, const void* func_args, void* user_args);

#endif // MPI_PLUGIN_H

