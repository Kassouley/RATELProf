/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#include <ratelprof.h>
#include "omp_tgt_rtl_domain/omp_tgt_rtl_plugin.h"

void on_enter_omp_tgt_rtl_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity){
    activity->phase = ratelprof_get_current_phase();
    activity->domain = domain;
    activity->corr_id = get_correlation_id();
    activity->id = push_id();
    activity->funid = id;
}

void on_exit_omp_tgt_rtl_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity){
    pop_id();
    activity->pid = get_pid();
    activity->tid = get_tid();
    ratelprof_activity_pool_push_activity(activity);
}

void process_omp_tgt_rtl_args_for(omp_tgt_rtl_api_id_t funid, const omp_tgt_rtl_api_args_t* args, ratelprof_buffer_t* buf) 
{
    switch(funid) {
		case OMP_TGT_RTL_API_ID___tgt_rtl_query_async : PROCESS_ARGS___tgt_rtl_query_async(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_data_submit : PROCESS_ARGS___tgt_rtl_data_submit(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_are_allocations_for_maps_on_apus_disabled : PROCESS_ARGS___tgt_rtl_are_allocations_for_maps_on_apus_disabled(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_data_notify_mapped : PROCESS_ARGS___tgt_rtl_data_notify_mapped(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_data_submit_async : PROCESS_ARGS___tgt_rtl_data_submit_async(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_init_async_info : PROCESS_ARGS___tgt_rtl_init_async_info(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_is_data_exchangable : PROCESS_ARGS___tgt_rtl_is_data_exchangable(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_data_retrieve_async : PROCESS_ARGS___tgt_rtl_data_retrieve_async(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_data_delete : PROCESS_ARGS___tgt_rtl_data_delete(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_data_exchange_async : PROCESS_ARGS___tgt_rtl_data_exchange_async(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_prepopulate_page_table : PROCESS_ARGS___tgt_rtl_prepopulate_page_table(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_data_exchange : PROCESS_ARGS___tgt_rtl_data_exchange(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_launch_kernel : PROCESS_ARGS___tgt_rtl_launch_kernel(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_is_valid_binary : PROCESS_ARGS___tgt_rtl_is_valid_binary(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_data_retrieve : PROCESS_ARGS___tgt_rtl_data_retrieve(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_data_lock : PROCESS_ARGS___tgt_rtl_data_lock(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_supports_empty_images : PROCESS_ARGS___tgt_rtl_supports_empty_images(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_destroy_event : PROCESS_ARGS___tgt_rtl_destroy_event(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_number_of_devices : PROCESS_ARGS___tgt_rtl_number_of_devices(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_init_requires : PROCESS_ARGS___tgt_rtl_init_requires(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_data_notify_unmapped : PROCESS_ARGS___tgt_rtl_data_notify_unmapped(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_init_device_info : PROCESS_ARGS___tgt_rtl_init_device_info(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_sync_event : PROCESS_ARGS___tgt_rtl_sync_event(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_synchronize : PROCESS_ARGS___tgt_rtl_synchronize(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_set_up_env : PROCESS_ARGS___tgt_rtl_set_up_env(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_data_unlock : PROCESS_ARGS___tgt_rtl_data_unlock(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_is_fine_grained_memory_enabled : PROCESS_ARGS___tgt_rtl_is_fine_grained_memory_enabled(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_has_USM_capable_dGPU : PROCESS_ARGS___tgt_rtl_has_USM_capable_dGPU(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_has_apu_device : PROCESS_ARGS___tgt_rtl_has_apu_device(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_set_device_offset : PROCESS_ARGS___tgt_rtl_set_device_offset(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_launch_kernel_sync : PROCESS_ARGS___tgt_rtl_launch_kernel_sync(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_record_event : PROCESS_ARGS___tgt_rtl_record_event(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_set_info_flag : PROCESS_ARGS___tgt_rtl_set_info_flag(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_create_event : PROCESS_ARGS___tgt_rtl_create_event(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_print_device_info : PROCESS_ARGS___tgt_rtl_print_device_info(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_get_function : PROCESS_ARGS___tgt_rtl_get_function(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_init_plugin : PROCESS_ARGS___tgt_rtl_init_plugin(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_number_of_team_procs : PROCESS_ARGS___tgt_rtl_number_of_team_procs(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_wait_event : PROCESS_ARGS___tgt_rtl_wait_event(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_data_alloc : PROCESS_ARGS___tgt_rtl_data_alloc(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_init_device : PROCESS_ARGS___tgt_rtl_init_device(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_get_global : PROCESS_ARGS___tgt_rtl_get_global(args); break;
		case OMP_TGT_RTL_API_ID___tgt_rtl_requested_prepopulate_gpu_page_table : PROCESS_ARGS___tgt_rtl_requested_prepopulate_gpu_page_table(args); break; 
        default : break;
    }
}

