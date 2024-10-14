/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#include <ratelprof.h>
#include "hsa_plugin.h"
#include "ratelprof_buffer_manager.h"

void on_enter_hsa_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity){
    get_hsa_pointed_args_for(id, &activity->hsa_args, 1);
    activity->domain = domain;
    activity->corr_id = get_correlation_id();
    activity->id = push_id();
    activity->funid = id;
}

void on_exit_hsa_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity){
    get_hsa_pointed_args_for(id, &activity->hsa_args, 0);
    activity->pid = get_pid();
    activity->tid = get_tid();
    printf("-----------\n");
    printf("%s | ID: %lu | CID: %lu\n", get_hsa_funame_by_id(activity->funid), activity->id, activity->corr_id);
    process_hsa_args_for(activity->funid, &activity->hsa_args, NULL);
    pop_id();
}

void process_hsa_args_for(hsa_api_id_t funid, const hsa_api_args_t* args, ratelprof_buffer_t* buf){
    switch(funid) {
		case HSA_API_ID_hsa_queue_load_read_index_scacquire : PROCESS_ARGS_hsa_queue_load_read_index_scacquire(args); break;
		case HSA_API_ID_hsa_ext_image_clear : PROCESS_ARGS_hsa_ext_image_clear(args); break;
		case HSA_API_ID_hsa_queue_cas_write_index_acquire : PROCESS_ARGS_hsa_queue_cas_write_index_acquire(args); break;
		case HSA_API_ID_hsa_executable_get_symbol : PROCESS_ARGS_hsa_executable_get_symbol(args); break;
		case HSA_API_ID_hsa_signal_and_scacq_screl : PROCESS_ARGS_hsa_signal_and_scacq_screl(args); break;
		case HSA_API_ID_hsa_executable_agent_global_variable_define : PROCESS_ARGS_hsa_executable_agent_global_variable_define(args); break;
		case HSA_API_ID_hsa_code_object_get_symbol : PROCESS_ARGS_hsa_code_object_get_symbol(args); break;
		case HSA_API_ID_hsa_amd_signal_async_handler : PROCESS_ARGS_hsa_amd_signal_async_handler(args); break;
		case HSA_API_ID_hsa_signal_xor_scacq_screl : PROCESS_ARGS_hsa_signal_xor_scacq_screl(args); break;
		case HSA_API_ID_hsa_signal_and_relaxed : PROCESS_ARGS_hsa_signal_and_relaxed(args); break;
		case HSA_API_ID_hsa_wavefront_get_info : PROCESS_ARGS_hsa_wavefront_get_info(args); break;
		case HSA_API_ID_hsa_amd_memory_lock : PROCESS_ARGS_hsa_amd_memory_lock(args); break;
		case HSA_API_ID_hsa_signal_or_screlease : PROCESS_ARGS_hsa_signal_or_screlease(args); break;
		case HSA_API_ID_hsa_executable_validate : PROCESS_ARGS_hsa_executable_validate(args); break;
		case HSA_API_ID_hsa_queue_destroy : PROCESS_ARGS_hsa_queue_destroy(args); break;
		case HSA_API_ID_hsa_isa_get_info : PROCESS_ARGS_hsa_isa_get_info(args); break;
		case HSA_API_ID_hsa_amd_memory_lock_to_pool : PROCESS_ARGS_hsa_amd_memory_lock_to_pool(args); break;
		case HSA_API_ID_hsa_system_major_extension_supported : PROCESS_ARGS_hsa_system_major_extension_supported(args); break;
		case HSA_API_ID_hsa_amd_profiling_get_async_copy_time : PROCESS_ARGS_hsa_amd_profiling_get_async_copy_time(args); break;
		case HSA_API_ID_hsa_signal_or_relaxed : PROCESS_ARGS_hsa_signal_or_relaxed(args); break;
		case HSA_API_ID_hsa_queue_cas_write_index_scacquire : PROCESS_ARGS_hsa_queue_cas_write_index_scacquire(args); break;
		case HSA_API_ID_hsa_code_object_get_info : PROCESS_ARGS_hsa_code_object_get_info(args); break;
		case HSA_API_ID_hsa_signal_and_screlease : PROCESS_ARGS_hsa_signal_and_screlease(args); break;
		case HSA_API_ID_hsa_amd_pointer_info : PROCESS_ARGS_hsa_amd_pointer_info(args); break;
		case HSA_API_ID_hsa_cache_get_info : PROCESS_ARGS_hsa_cache_get_info(args); break;
		case HSA_API_ID_hsa_amd_svm_attributes_get : PROCESS_ARGS_hsa_amd_svm_attributes_get(args); break;
		case HSA_API_ID_hsa_signal_group_create : PROCESS_ARGS_hsa_signal_group_create(args); break;
		case HSA_API_ID_hsa_memory_deregister : PROCESS_ARGS_hsa_memory_deregister(args); break;
		case HSA_API_ID_hsa_amd_ipc_memory_attach : PROCESS_ARGS_hsa_amd_ipc_memory_attach(args); break;
		case HSA_API_ID_hsa_amd_queue_cu_get_mask : PROCESS_ARGS_hsa_amd_queue_cu_get_mask(args); break;
		case HSA_API_ID_hsa_queue_add_write_index_scacq_screl : PROCESS_ARGS_hsa_queue_add_write_index_scacq_screl(args); break;
		case HSA_API_ID_hsa_agent_major_extension_supported : PROCESS_ARGS_hsa_agent_major_extension_supported(args); break;
		case HSA_API_ID_hsa_ext_sampler_destroy : PROCESS_ARGS_hsa_ext_sampler_destroy(args); break;
		case HSA_API_ID_hsa_queue_create : PROCESS_ARGS_hsa_queue_create(args); break;
		case HSA_API_ID_hsa_amd_vmem_get_alloc_properties_from_handle : PROCESS_ARGS_hsa_amd_vmem_get_alloc_properties_from_handle(args); break;
		case HSA_API_ID_hsa_amd_memory_pool_allocate : PROCESS_ARGS_hsa_amd_memory_pool_allocate(args); break;
		case HSA_API_ID_hsa_signal_or_release : PROCESS_ARGS_hsa_signal_or_release(args); break;
		case HSA_API_ID_hsa_queue_cas_write_index_acq_rel : PROCESS_ARGS_hsa_queue_cas_write_index_acq_rel(args); break;
		case HSA_API_ID_hsa_code_object_serialize : PROCESS_ARGS_hsa_code_object_serialize(args); break;
		case HSA_API_ID_hsa_signal_xor_acquire : PROCESS_ARGS_hsa_signal_xor_acquire(args); break;
		case HSA_API_ID_hsa_amd_profiling_convert_tick_to_system_domain : PROCESS_ARGS_hsa_amd_profiling_convert_tick_to_system_domain(args); break;
		case HSA_API_ID_hsa_executable_destroy : PROCESS_ARGS_hsa_executable_destroy(args); break;
		case HSA_API_ID_hsa_signal_add_screlease : PROCESS_ARGS_hsa_signal_add_screlease(args); break;
		case HSA_API_ID_hsa_signal_load_acquire : PROCESS_ARGS_hsa_signal_load_acquire(args); break;
		case HSA_API_ID_hsa_executable_create_alt : PROCESS_ARGS_hsa_executable_create_alt(args); break;
		case HSA_API_ID_hsa_amd_memory_async_copy_rect : PROCESS_ARGS_hsa_amd_memory_async_copy_rect(args); break;
		case HSA_API_ID_hsa_signal_load_scacquire : PROCESS_ARGS_hsa_signal_load_scacquire(args); break;
		case HSA_API_ID_hsa_agent_iterate_caches : PROCESS_ARGS_hsa_agent_iterate_caches(args); break;
		case HSA_API_ID_hsa_signal_cas_acq_rel : PROCESS_ARGS_hsa_signal_cas_acq_rel(args); break;
		case HSA_API_ID_hsa_queue_load_read_index_relaxed : PROCESS_ARGS_hsa_queue_load_read_index_relaxed(args); break;
		case HSA_API_ID_hsa_agent_iterate_isas : PROCESS_ARGS_hsa_agent_iterate_isas(args); break;
		case HSA_API_ID_hsa_signal_xor_relaxed : PROCESS_ARGS_hsa_signal_xor_relaxed(args); break;
		case HSA_API_ID_hsa_signal_subtract_acq_rel : PROCESS_ARGS_hsa_signal_subtract_acq_rel(args); break;
		case HSA_API_ID_hsa_queue_load_read_index_acquire : PROCESS_ARGS_hsa_queue_load_read_index_acquire(args); break;
		case HSA_API_ID_hsa_isa_get_info_alt : PROCESS_ARGS_hsa_isa_get_info_alt(args); break;
		case HSA_API_ID_hsa_signal_and_scacquire : PROCESS_ARGS_hsa_signal_and_scacquire(args); break;
		case HSA_API_ID_hsa_queue_add_write_index_release : PROCESS_ARGS_hsa_queue_add_write_index_release(args); break;
		case HSA_API_ID_hsa_system_get_info : PROCESS_ARGS_hsa_system_get_info(args); break;
		case HSA_API_ID_hsa_memory_register : PROCESS_ARGS_hsa_memory_register(args); break;
		case HSA_API_ID_hsa_isa_get_round_method : PROCESS_ARGS_hsa_isa_get_round_method(args); break;
		case HSA_API_ID_hsa_isa_iterate_wavefronts : PROCESS_ARGS_hsa_isa_iterate_wavefronts(args); break;
		case HSA_API_ID_hsa_amd_vmem_unmap : PROCESS_ARGS_hsa_amd_vmem_unmap(args); break;
		case HSA_API_ID_hsa_signal_subtract_acquire : PROCESS_ARGS_hsa_signal_subtract_acquire(args); break;
		case HSA_API_ID_hsa_system_get_major_extension_table : PROCESS_ARGS_hsa_system_get_major_extension_table(args); break;
		case HSA_API_ID_hsa_signal_store_release : PROCESS_ARGS_hsa_signal_store_release(args); break;
		case HSA_API_ID_hsa_queue_load_write_index_scacquire : PROCESS_ARGS_hsa_queue_load_write_index_scacquire(args); break;
		case HSA_API_ID_hsa_amd_spm_release : PROCESS_ARGS_hsa_amd_spm_release(args); break;
		case HSA_API_ID_hsa_code_symbol_get_info : PROCESS_ARGS_hsa_code_symbol_get_info(args); break;
		case HSA_API_ID_hsa_signal_wait_acquire : PROCESS_ARGS_hsa_signal_wait_acquire(args); break;
		case HSA_API_ID_hsa_signal_cas_release : PROCESS_ARGS_hsa_signal_cas_release(args); break;
		case HSA_API_ID_hsa_amd_memory_pool_get_info : PROCESS_ARGS_hsa_amd_memory_pool_get_info(args); break;
		case HSA_API_ID_hsa_amd_pointer_info_set_userdata : PROCESS_ARGS_hsa_amd_pointer_info_set_userdata(args); break;
		case HSA_API_ID_hsa_amd_vmem_get_access : PROCESS_ARGS_hsa_amd_vmem_get_access(args); break;
		case HSA_API_ID_hsa_iterate_agents : PROCESS_ARGS_hsa_iterate_agents(args); break;
		case HSA_API_ID_hsa_queue_store_write_index_screlease : PROCESS_ARGS_hsa_queue_store_write_index_screlease(args); break;
		case HSA_API_ID_hsa_agent_iterate_regions : PROCESS_ARGS_hsa_agent_iterate_regions(args); break;
		case HSA_API_ID_hsa_executable_readonly_variable_define : PROCESS_ARGS_hsa_executable_readonly_variable_define(args); break;
		case HSA_API_ID_hsa_executable_iterate_symbols : PROCESS_ARGS_hsa_executable_iterate_symbols(args); break;
		case HSA_API_ID_hsa_amd_vmem_handle_release : PROCESS_ARGS_hsa_amd_vmem_handle_release(args); break;
		case HSA_API_ID_hsa_amd_memory_pool_can_migrate : PROCESS_ARGS_hsa_amd_memory_pool_can_migrate(args); break;
		case HSA_API_ID_hsa_queue_store_write_index_relaxed : PROCESS_ARGS_hsa_queue_store_write_index_relaxed(args); break;
		case HSA_API_ID_hsa_amd_image_get_info_max_dim : PROCESS_ARGS_hsa_amd_image_get_info_max_dim(args); break;
		case HSA_API_ID_hsa_amd_spm_set_dest_buffer : PROCESS_ARGS_hsa_amd_spm_set_dest_buffer(args); break;
		case HSA_API_ID_hsa_signal_wait_relaxed : PROCESS_ARGS_hsa_signal_wait_relaxed(args); break;
		case HSA_API_ID_hsa_amd_portable_export_dmabuf : PROCESS_ARGS_hsa_amd_portable_export_dmabuf(args); break;
		case HSA_API_ID_hsa_signal_store_screlease : PROCESS_ARGS_hsa_signal_store_screlease(args); break;
		case HSA_API_ID_hsa_signal_or_acquire : PROCESS_ARGS_hsa_signal_or_acquire(args); break;
		case HSA_API_ID_hsa_code_object_destroy : PROCESS_ARGS_hsa_code_object_destroy(args); break;
		case HSA_API_ID_hsa_signal_subtract_screlease : PROCESS_ARGS_hsa_signal_subtract_screlease(args); break;
		case HSA_API_ID_hsa_region_get_info : PROCESS_ARGS_hsa_region_get_info(args); break;
		case HSA_API_ID_hsa_signal_subtract_scacq_screl : PROCESS_ARGS_hsa_signal_subtract_scacq_screl(args); break;
		case HSA_API_ID_hsa_amd_profiling_async_copy_enable : PROCESS_ARGS_hsa_amd_profiling_async_copy_enable(args); break;
		case HSA_API_ID_hsa_soft_queue_create : PROCESS_ARGS_hsa_soft_queue_create(args); break;
		case HSA_API_ID_hsa_shut_down : PROCESS_ARGS_hsa_shut_down(args); break;
		case HSA_API_ID_hsa_code_object_iterate_symbols : PROCESS_ARGS_hsa_code_object_iterate_symbols(args); break;
		case HSA_API_ID_hsa_extension_get_name : PROCESS_ARGS_hsa_extension_get_name(args); break;
		case HSA_API_ID_hsa_signal_exchange_relaxed : PROCESS_ARGS_hsa_signal_exchange_relaxed(args); break;
		case HSA_API_ID_hsa_executable_get_symbol_by_name : PROCESS_ARGS_hsa_executable_get_symbol_by_name(args); break;
		case HSA_API_ID_hsa_ext_image_create_with_layout : PROCESS_ARGS_hsa_ext_image_create_with_layout(args); break;
		case HSA_API_ID_hsa_queue_load_write_index_relaxed : PROCESS_ARGS_hsa_queue_load_write_index_relaxed(args); break;
		case HSA_API_ID_hsa_ext_image_copy : PROCESS_ARGS_hsa_ext_image_copy(args); break;
		case HSA_API_ID_hsa_code_object_reader_create_from_memory : PROCESS_ARGS_hsa_code_object_reader_create_from_memory(args); break;
		case HSA_API_ID_hsa_signal_xor_release : PROCESS_ARGS_hsa_signal_xor_release(args); break;
		case HSA_API_ID_hsa_amd_register_deallocation_callback : PROCESS_ARGS_hsa_amd_register_deallocation_callback(args); break;
		case HSA_API_ID_hsa_signal_group_destroy : PROCESS_ARGS_hsa_signal_group_destroy(args); break;
		case HSA_API_ID_hsa_amd_vmem_export_shareable_handle : PROCESS_ARGS_hsa_amd_vmem_export_shareable_handle(args); break;
		case HSA_API_ID_hsa_queue_add_write_index_acq_rel : PROCESS_ARGS_hsa_queue_add_write_index_acq_rel(args); break;
		case HSA_API_ID_hsa_signal_destroy : PROCESS_ARGS_hsa_signal_destroy(args); break;
		case HSA_API_ID_hsa_agent_extension_supported : PROCESS_ARGS_hsa_agent_extension_supported(args); break;
		case HSA_API_ID_hsa_amd_image_create : PROCESS_ARGS_hsa_amd_image_create(args); break;
		case HSA_API_ID_hsa_isa_compatible : PROCESS_ARGS_hsa_isa_compatible(args); break;
		case HSA_API_ID_hsa_amd_queue_set_priority : PROCESS_ARGS_hsa_amd_queue_set_priority(args); break;
		case HSA_API_ID_hsa_signal_and_acq_rel : PROCESS_ARGS_hsa_signal_and_acq_rel(args); break;
		case HSA_API_ID_hsa_code_object_reader_destroy : PROCESS_ARGS_hsa_code_object_reader_destroy(args); break;
		case HSA_API_ID_hsa_queue_cas_write_index_release : PROCESS_ARGS_hsa_queue_cas_write_index_release(args); break;
		case HSA_API_ID_hsa_executable_load_code_object : PROCESS_ARGS_hsa_executable_load_code_object(args); break;
		case HSA_API_ID_hsa_amd_memory_async_copy : PROCESS_ARGS_hsa_amd_memory_async_copy(args); break;
		case HSA_API_ID_hsa_amd_memory_unlock : PROCESS_ARGS_hsa_amd_memory_unlock(args); break;
		case HSA_API_ID_hsa_signal_subtract_release : PROCESS_ARGS_hsa_signal_subtract_release(args); break;
		case HSA_API_ID_hsa_signal_exchange_acquire : PROCESS_ARGS_hsa_signal_exchange_acquire(args); break;
		case HSA_API_ID_hsa_signal_store_relaxed : PROCESS_ARGS_hsa_signal_store_relaxed(args); break;
		case HSA_API_ID_hsa_signal_subtract_scacquire : PROCESS_ARGS_hsa_signal_subtract_scacquire(args); break;
		case HSA_API_ID_hsa_signal_and_release : PROCESS_ARGS_hsa_signal_and_release(args); break;
		case HSA_API_ID_hsa_signal_cas_acquire : PROCESS_ARGS_hsa_signal_cas_acquire(args); break;
		case HSA_API_ID_hsa_isa_get_exception_policies : PROCESS_ARGS_hsa_isa_get_exception_policies(args); break;
		case HSA_API_ID_hsa_signal_add_release : PROCESS_ARGS_hsa_signal_add_release(args); break;
		case HSA_API_ID_hsa_code_object_reader_create_from_file : PROCESS_ARGS_hsa_code_object_reader_create_from_file(args); break;
		case HSA_API_ID_hsa_executable_symbol_get_info : PROCESS_ARGS_hsa_executable_symbol_get_info(args); break;
		case HSA_API_ID_hsa_amd_ipc_memory_create : PROCESS_ARGS_hsa_amd_ipc_memory_create(args); break;
		case HSA_API_ID_hsa_queue_store_write_index_release : PROCESS_ARGS_hsa_queue_store_write_index_release(args); break;
		case HSA_API_ID_hsa_amd_memory_fill : PROCESS_ARGS_hsa_amd_memory_fill(args); break;
		case HSA_API_ID_hsa_signal_add_acq_rel : PROCESS_ARGS_hsa_signal_add_acq_rel(args); break;
		case HSA_API_ID_hsa_signal_cas_scacq_screl : PROCESS_ARGS_hsa_signal_cas_scacq_screl(args); break;
		case HSA_API_ID_hsa_queue_cas_write_index_scacq_screl : PROCESS_ARGS_hsa_queue_cas_write_index_scacq_screl(args); break;
		case HSA_API_ID_hsa_amd_ipc_signal_create : PROCESS_ARGS_hsa_amd_ipc_signal_create(args); break;
		case HSA_API_ID_hsa_amd_spm_acquire : PROCESS_ARGS_hsa_amd_spm_acquire(args); break;
		case HSA_API_ID_hsa_amd_coherency_get_type : PROCESS_ARGS_hsa_amd_coherency_get_type(args); break;
		case HSA_API_ID_hsa_system_get_extension_table : PROCESS_ARGS_hsa_system_get_extension_table(args); break;
		case HSA_API_ID_hsa_amd_ipc_memory_detach : PROCESS_ARGS_hsa_amd_ipc_memory_detach(args); break;
		case HSA_API_ID_hsa_ext_image_get_capability_with_layout : PROCESS_ARGS_hsa_ext_image_get_capability_with_layout(args); break;
		case HSA_API_ID_hsa_amd_vmem_address_free : PROCESS_ARGS_hsa_amd_vmem_address_free(args); break;
		case HSA_API_ID_hsa_amd_svm_attributes_set : PROCESS_ARGS_hsa_amd_svm_attributes_set(args); break;
		case HSA_API_ID_hsa_ext_image_import : PROCESS_ARGS_hsa_ext_image_import(args); break;
		case HSA_API_ID_hsa_signal_or_scacquire : PROCESS_ARGS_hsa_signal_or_scacquire(args); break;
		case HSA_API_ID_hsa_amd_svm_prefetch_async : PROCESS_ARGS_hsa_amd_svm_prefetch_async(args); break;
		case HSA_API_ID_hsa_signal_add_scacq_screl : PROCESS_ARGS_hsa_signal_add_scacq_screl(args); break;
		case HSA_API_ID_hsa_signal_silent_store_relaxed : PROCESS_ARGS_hsa_signal_silent_store_relaxed(args); break;
		case HSA_API_ID_hsa_queue_store_read_index_relaxed : PROCESS_ARGS_hsa_queue_store_read_index_relaxed(args); break;
		case HSA_API_ID_hsa_agent_get_exception_policies : PROCESS_ARGS_hsa_agent_get_exception_policies(args); break;
		case HSA_API_ID_hsa_signal_add_scacquire : PROCESS_ARGS_hsa_signal_add_scacquire(args); break;
		case HSA_API_ID_hsa_signal_exchange_release : PROCESS_ARGS_hsa_signal_exchange_release(args); break;
		case HSA_API_ID_hsa_signal_add_relaxed : PROCESS_ARGS_hsa_signal_add_relaxed(args); break;
		case HSA_API_ID_hsa_signal_and_acquire : PROCESS_ARGS_hsa_signal_and_acquire(args); break;
		case HSA_API_ID_hsa_queue_add_write_index_relaxed : PROCESS_ARGS_hsa_queue_add_write_index_relaxed(args); break;
		case HSA_API_ID_hsa_amd_agent_memory_pool_get_info : PROCESS_ARGS_hsa_amd_agent_memory_pool_get_info(args); break;
		case HSA_API_ID_hsa_amd_profiling_set_profiler_enabled : PROCESS_ARGS_hsa_amd_profiling_set_profiler_enabled(args); break;
		case HSA_API_ID_hsa_signal_exchange_acq_rel : PROCESS_ARGS_hsa_signal_exchange_acq_rel(args); break;
		case HSA_API_ID_hsa_queue_cas_write_index_screlease : PROCESS_ARGS_hsa_queue_cas_write_index_screlease(args); break;
		case HSA_API_ID_hsa_amd_async_function : PROCESS_ARGS_hsa_amd_async_function(args); break;
		case HSA_API_ID_hsa_queue_store_read_index_screlease : PROCESS_ARGS_hsa_queue_store_read_index_screlease(args); break;
		case HSA_API_ID_hsa_memory_allocate : PROCESS_ARGS_hsa_memory_allocate(args); break;
		case HSA_API_ID_hsa_amd_signal_value_pointer : PROCESS_ARGS_hsa_amd_signal_value_pointer(args); break;
		case HSA_API_ID_hsa_amd_signal_wait_any : PROCESS_ARGS_hsa_amd_signal_wait_any(args); break;
		case HSA_API_ID_hsa_amd_vmem_retain_alloc_handle : PROCESS_ARGS_hsa_amd_vmem_retain_alloc_handle(args); break;
		case HSA_API_ID_hsa_amd_vmem_set_access : PROCESS_ARGS_hsa_amd_vmem_set_access(args); break;
		case HSA_API_ID_hsa_memory_assign_agent : PROCESS_ARGS_hsa_memory_assign_agent(args); break;
		case HSA_API_ID_hsa_amd_vmem_address_reserve : PROCESS_ARGS_hsa_amd_vmem_address_reserve(args); break;
		case HSA_API_ID_hsa_amd_memory_async_copy_on_engine : PROCESS_ARGS_hsa_amd_memory_async_copy_on_engine(args); break;
		case HSA_API_ID_hsa_signal_xor_scacquire : PROCESS_ARGS_hsa_signal_xor_scacquire(args); break;
		case HSA_API_ID_hsa_amd_coherency_set_type : PROCESS_ARGS_hsa_amd_coherency_set_type(args); break;
		case HSA_API_ID_hsa_queue_inactivate : PROCESS_ARGS_hsa_queue_inactivate(args); break;
		case HSA_API_ID_hsa_amd_vmem_import_shareable_handle : PROCESS_ARGS_hsa_amd_vmem_import_shareable_handle(args); break;
		case HSA_API_ID_hsa_signal_cas_relaxed : PROCESS_ARGS_hsa_signal_cas_relaxed(args); break;
		case HSA_API_ID_hsa_queue_add_write_index_scacquire : PROCESS_ARGS_hsa_queue_add_write_index_scacquire(args); break;
		case HSA_API_ID_hsa_signal_exchange_screlease : PROCESS_ARGS_hsa_signal_exchange_screlease(args); break;
		case HSA_API_ID_hsa_amd_vmem_handle_create : PROCESS_ARGS_hsa_amd_vmem_handle_create(args); break;
		case HSA_API_ID_hsa_agent_get_info : PROCESS_ARGS_hsa_agent_get_info(args); break;
		case HSA_API_ID_hsa_signal_or_acq_rel : PROCESS_ARGS_hsa_signal_or_acq_rel(args); break;
		case HSA_API_ID_hsa_signal_xor_acq_rel : PROCESS_ARGS_hsa_signal_xor_acq_rel(args); break;
		case HSA_API_ID_hsa_system_extension_supported : PROCESS_ARGS_hsa_system_extension_supported(args); break;
		case HSA_API_ID_hsa_signal_group_wait_any_relaxed : PROCESS_ARGS_hsa_signal_group_wait_any_relaxed(args); break;
		case HSA_API_ID_hsa_signal_or_scacq_screl : PROCESS_ARGS_hsa_signal_or_scacq_screl(args); break;
		case HSA_API_ID_hsa_executable_iterate_agent_symbols : PROCESS_ARGS_hsa_executable_iterate_agent_symbols(args); break;
		case HSA_API_ID_hsa_amd_deregister_deallocation_callback : PROCESS_ARGS_hsa_amd_deregister_deallocation_callback(args); break;
		case HSA_API_ID_hsa_signal_create : PROCESS_ARGS_hsa_signal_create(args); break;
		case HSA_API_ID_hsa_amd_memory_copy_engine_status : PROCESS_ARGS_hsa_amd_memory_copy_engine_status(args); break;
		case HSA_API_ID_hsa_ext_image_get_capability : PROCESS_ARGS_hsa_ext_image_get_capability(args); break;
		case HSA_API_ID_hsa_ext_image_destroy : PROCESS_ARGS_hsa_ext_image_destroy(args); break;
		case HSA_API_ID_hsa_queue_store_read_index_release : PROCESS_ARGS_hsa_queue_store_read_index_release(args); break;
		case HSA_API_ID_hsa_signal_wait_scacquire : PROCESS_ARGS_hsa_signal_wait_scacquire(args); break;
		case HSA_API_ID_hsa_executable_get_info : PROCESS_ARGS_hsa_executable_get_info(args); break;
		case HSA_API_ID_hsa_signal_silent_store_screlease : PROCESS_ARGS_hsa_signal_silent_store_screlease(args); break;
		case HSA_API_ID_hsa_executable_validate_alt : PROCESS_ARGS_hsa_executable_validate_alt(args); break;
		case HSA_API_ID_hsa_executable_create : PROCESS_ARGS_hsa_executable_create(args); break;
		case HSA_API_ID_hsa_executable_iterate_program_symbols : PROCESS_ARGS_hsa_executable_iterate_program_symbols(args); break;
		case HSA_API_ID_hsa_memory_free : PROCESS_ARGS_hsa_memory_free(args); break;
		case HSA_API_ID_hsa_amd_memory_pool_free : PROCESS_ARGS_hsa_amd_memory_pool_free(args); break;
		case HSA_API_ID_hsa_amd_memory_migrate : PROCESS_ARGS_hsa_amd_memory_migrate(args); break;
		case HSA_API_ID_hsa_amd_interop_unmap_buffer : PROCESS_ARGS_hsa_amd_interop_unmap_buffer(args); break;
		case HSA_API_ID_hsa_amd_signal_create : PROCESS_ARGS_hsa_amd_signal_create(args); break;
		case HSA_API_ID_hsa_executable_load_program_code_object : PROCESS_ARGS_hsa_executable_load_program_code_object(args); break;
		case HSA_API_ID_hsa_signal_load_relaxed : PROCESS_ARGS_hsa_signal_load_relaxed(args); break;
		case HSA_API_ID_hsa_signal_group_wait_any_scacquire : PROCESS_ARGS_hsa_signal_group_wait_any_scacquire(args); break;
		case HSA_API_ID_hsa_queue_cas_write_index_relaxed : PROCESS_ARGS_hsa_queue_cas_write_index_relaxed(args); break;
		case HSA_API_ID_hsa_signal_subtract_relaxed : PROCESS_ARGS_hsa_signal_subtract_relaxed(args); break;
		case HSA_API_ID_hsa_executable_freeze : PROCESS_ARGS_hsa_executable_freeze(args); break;
		case HSA_API_ID_hsa_queue_load_write_index_acquire : PROCESS_ARGS_hsa_queue_load_write_index_acquire(args); break;
		case HSA_API_ID_hsa_amd_vmem_map : PROCESS_ARGS_hsa_amd_vmem_map(args); break;
		case HSA_API_ID_hsa_amd_ipc_signal_attach : PROCESS_ARGS_hsa_amd_ipc_signal_attach(args); break;
		case HSA_API_ID_hsa_amd_register_system_event_handler : PROCESS_ARGS_hsa_amd_register_system_event_handler(args); break;
		case HSA_API_ID_hsa_amd_queue_cu_set_mask : PROCESS_ARGS_hsa_amd_queue_cu_set_mask(args); break;
		case HSA_API_ID_hsa_ext_image_export : PROCESS_ARGS_hsa_ext_image_export(args); break;
		case HSA_API_ID_hsa_status_string : PROCESS_ARGS_hsa_status_string(args); break;
		case HSA_API_ID_hsa_signal_xor_screlease : PROCESS_ARGS_hsa_signal_xor_screlease(args); break;
		case HSA_API_ID_hsa_queue_add_write_index_acquire : PROCESS_ARGS_hsa_queue_add_write_index_acquire(args); break;
		case HSA_API_ID_hsa_queue_add_write_index_screlease : PROCESS_ARGS_hsa_queue_add_write_index_screlease(args); break;
		case HSA_API_ID_hsa_code_object_get_symbol_from_name : PROCESS_ARGS_hsa_code_object_get_symbol_from_name(args); break;
		case HSA_API_ID_hsa_isa_from_name : PROCESS_ARGS_hsa_isa_from_name(args); break;
		case HSA_API_ID_hsa_amd_agent_iterate_memory_pools : PROCESS_ARGS_hsa_amd_agent_iterate_memory_pools(args); break;
		case HSA_API_ID_hsa_amd_agent_set_async_scratch_limit : PROCESS_ARGS_hsa_amd_agent_set_async_scratch_limit(args); break;
		case HSA_API_ID_hsa_ext_image_create : PROCESS_ARGS_hsa_ext_image_create(args); break;
		case HSA_API_ID_hsa_signal_exchange_scacq_screl : PROCESS_ARGS_hsa_signal_exchange_scacq_screl(args); break;
		case HSA_API_ID_hsa_init : PROCESS_ARGS_hsa_init(args); break;
		case HSA_API_ID_hsa_executable_load_agent_code_object : PROCESS_ARGS_hsa_executable_load_agent_code_object(args); break;
		case HSA_API_ID_hsa_signal_cas_screlease : PROCESS_ARGS_hsa_signal_cas_screlease(args); break;
		case HSA_API_ID_hsa_amd_profiling_get_dispatch_time : PROCESS_ARGS_hsa_amd_profiling_get_dispatch_time(args); break;
		case HSA_API_ID_hsa_amd_portable_close_dmabuf : PROCESS_ARGS_hsa_amd_portable_close_dmabuf(args); break;
		case HSA_API_ID_hsa_memory_copy : PROCESS_ARGS_hsa_memory_copy(args); break;
		case HSA_API_ID_hsa_signal_exchange_scacquire : PROCESS_ARGS_hsa_signal_exchange_scacquire(args); break;
		case HSA_API_ID_hsa_ext_image_data_get_info_with_layout : PROCESS_ARGS_hsa_ext_image_data_get_info_with_layout(args); break;
		case HSA_API_ID_hsa_executable_global_variable_define : PROCESS_ARGS_hsa_executable_global_variable_define(args); break;
		case HSA_API_ID_hsa_signal_add_acquire : PROCESS_ARGS_hsa_signal_add_acquire(args); break;
		case HSA_API_ID_hsa_ext_image_data_get_info : PROCESS_ARGS_hsa_ext_image_data_get_info(args); break;
		case HSA_API_ID_hsa_signal_cas_scacquire : PROCESS_ARGS_hsa_signal_cas_scacquire(args); break;
		case HSA_API_ID_hsa_amd_interop_map_buffer : PROCESS_ARGS_hsa_amd_interop_map_buffer(args); break;
		case HSA_API_ID_hsa_ext_sampler_create : PROCESS_ARGS_hsa_ext_sampler_create(args); break;
		case HSA_API_ID_hsa_code_object_deserialize : PROCESS_ARGS_hsa_code_object_deserialize(args); break;
		case HSA_API_ID_hsa_amd_agents_allow_access : PROCESS_ARGS_hsa_amd_agents_allow_access(args); break; 
        default : break;
    }
}
