/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#include <ratelprof.h>
#include "omp_tgt_domain/omp_tgt_plugin.h"

void on_enter_omp_tgt_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity){
    activity->phase = ratelprof_get_current_phase();
    activity->domain = domain;
    activity->corr_id = get_correlation_id();
    activity->id = push_id();
    activity->funid = id;
}

void on_exit_omp_tgt_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity){
    pop_id();
    activity->pid = get_pid();
    activity->tid = get_tid();
    ratelprof_activity_pool_push_activity(activity);
}

void process_omp_tgt_args_for(omp_tgt_api_id_t funid, const omp_tgt_api_args_t* args, ratelprof_buffer_t* buf) 
{
    switch(funid) {
		case OMP_TGT_API_ID_omp_target_memset : PROCESS_ARGS_omp_target_memset(args); break;
		case OMP_TGT_API_ID_omp_target_memcpy_async : PROCESS_ARGS_omp_target_memcpy_async(args); break;
		case OMP_TGT_API_ID_omp_target_memcpy_rect_async : PROCESS_ARGS_omp_target_memcpy_rect_async(args); break;
		case OMP_TGT_API_ID_omp_target_alloc : PROCESS_ARGS_omp_target_alloc(args); break;
		case OMP_TGT_API_ID_omp_target_free : PROCESS_ARGS_omp_target_free(args); break;
		case OMP_TGT_API_ID_omp_target_memcpy_rect : PROCESS_ARGS_omp_target_memcpy_rect(args); break;
		case OMP_TGT_API_ID_omp_target_disassociate_ptr : PROCESS_ARGS_omp_target_disassociate_ptr(args); break;
		case OMP_TGT_API_ID_omp_target_memcpy : PROCESS_ARGS_omp_target_memcpy(args); break;
		case OMP_TGT_API_ID_omp_target_memset_async : PROCESS_ARGS_omp_target_memset_async(args); break;
		case OMP_TGT_API_ID_omp_target_is_present : PROCESS_ARGS_omp_target_is_present(args); break;
		case OMP_TGT_API_ID_omp_target_associate_ptr : PROCESS_ARGS_omp_target_associate_ptr(args); break;
		case OMP_TGT_API_ID_omp_get_initial_device : PROCESS_ARGS_omp_get_initial_device(args); break;
		case OMP_TGT_API_ID_llvm_omp_target_dynamic_shared_alloc : PROCESS_ARGS_llvm_omp_target_dynamic_shared_alloc(args); break;
		case OMP_TGT_API_ID_omp_get_interop_int : PROCESS_ARGS_omp_get_interop_int(args); break;
		case OMP_TGT_API_ID_omp_get_interop_name : PROCESS_ARGS_omp_get_interop_name(args); break;
		case OMP_TGT_API_ID_omp_get_interop_ptr : PROCESS_ARGS_omp_get_interop_ptr(args); break;
		case OMP_TGT_API_ID_omp_get_interop_str : PROCESS_ARGS_omp_get_interop_str(args); break;
		case OMP_TGT_API_ID_omp_get_interop_type_desc : PROCESS_ARGS_omp_get_interop_type_desc(args); break;
		case OMP_TGT_API_ID_omp_get_mapped_ptr : PROCESS_ARGS_omp_get_mapped_ptr(args); break;
		case OMP_TGT_API_ID_omp_get_num_devices : PROCESS_ARGS_omp_get_num_devices(args); break;
		case OMP_TGT_API_ID_omp_is_coarse_grain_mem_region : PROCESS_ARGS_omp_is_coarse_grain_mem_region(args); break; 
        default : break;
    }
}

