/** THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA. 
 */
 
#include <ratelprof_ext.h>
#include <ratelprof.h>
#include "omp_tgt_rtl_plugin.h"

void on_enter_omp_tgt_rtl_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity){
    get_omp_tgt_rtl_pointed_args_for(id, &activity->omp_tgt_rtl_args, 1);
    activity->phase = ratelprof_get_current_phase();
    activity->domain = domain;
    get_correlation_id(&activity->corr_id);
    get_id(&activity->id);
    activity->funid = id;
}

void on_exit_omp_tgt_rtl_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity){
    get_omp_tgt_rtl_pointed_args_for(id, &activity->omp_tgt_rtl_args, 0);
    pop_id();
    activity->pid = get_pid();
    activity->tid = get_tid();
    ratelprof_activity_pool_push_activity(activity);
}

void process_omp_tgt_rtl_args_for(omp_tgt_rtl_api_id_t funid, const omp_tgt_rtl_api_args_t* args, void* user_args) 
{
    ratelprof_buffer_t* buf = (ratelprof_buffer_t*)user_args;
    switch(funid) {
		case OMP_TGT_RTL_API_ID___tgt_rtl_query_async :
			//	int32_t device_id (int);
			//	__tgt_async_info * AsyncInfoPtr ({
			//	});
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_query_async.device_id);
			ratelprof_add_to_buffer(buf, "\"AsyncInfoPtr\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_query_async.AsyncInfoPtr);
			if (args->__tgt_rtl_query_async.AsyncInfoPtr != NULL) {
				ratelprof_add_to_buffer(buf, ", \"->*\":{");
				ratelprof_add_to_buffer(buf, "}");
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_query_async.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_data_submit :
			//	int32_t device_id (int);
			//	int64_t size (long);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_submit.device_id);
			ratelprof_add_to_buffer(buf, "\"target_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_submit.target_ptr);
			ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_submit.host_ptr);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_data_submit.size);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_data_submit.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_are_allocations_for_maps_on_apus_disabled :
			//	int retval (int);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->__tgt_rtl_are_allocations_for_maps_on_apus_disabled.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_data_notify_mapped :
			//	int32_t device_id (int);
			//	int64_t size (long);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_notify_mapped.device_id);
			ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_notify_mapped.host_ptr);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_data_notify_mapped.size);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_data_notify_mapped.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_data_submit_async :
			//	int32_t device_id (int);
			//	int64_t size (long);
			//	__tgt_async_info * AsyncInfo ({
			//	});
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_submit_async.device_id);
			ratelprof_add_to_buffer(buf, "\"target_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_submit_async.target_ptr);
			ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_submit_async.host_ptr);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_data_submit_async.size);
			ratelprof_add_to_buffer(buf, "\"AsyncInfo\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_data_submit_async.AsyncInfo);
			if (args->__tgt_rtl_data_submit_async.AsyncInfo != NULL) {
				ratelprof_add_to_buffer(buf, ", \"->*\":{");
				ratelprof_add_to_buffer(buf, "}");
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_data_submit_async.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_init_async_info :
			//	int32_t device_id (int);
			//	__tgt_async_info ** async_info_ptr ({
			//	});
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_init_async_info.device_id);
			ratelprof_add_to_buffer(buf, "\"async_info_ptr\":{\"type\":\"__tgt_async_info **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_init_async_info.async_info_ptr);
			if (args->__tgt_rtl_init_async_info.async_info_ptr != NULL) {
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_init_async_info.async_info_ptr__ref.ptr1);
				if (args->__tgt_rtl_init_async_info.async_info_ptr__ref.ptr1 != NULL) {
					ratelprof_add_to_buffer(buf, ", \"->**\":{");
					ratelprof_add_to_buffer(buf, "}");
				}
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_init_async_info.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_is_data_exchangable :
			//	int32_t src_dev_id (int);
			//	int32_t dst_dev_id (int);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"src_dev_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_is_data_exchangable.src_dev_id);
			ratelprof_add_to_buffer(buf, "\"dst_dev_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_is_data_exchangable.dst_dev_id);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_is_data_exchangable.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_data_retrieve_async :
			//	int32_t device_id (int);
			//	int64_t size (long);
			//	__tgt_async_info * AsyncInfo ({
			//	});
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_retrieve_async.device_id);
			ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_retrieve_async.host_ptr);
			ratelprof_add_to_buffer(buf, "\"target_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_retrieve_async.target_ptr);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_data_retrieve_async.size);
			ratelprof_add_to_buffer(buf, "\"AsyncInfo\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_data_retrieve_async.AsyncInfo);
			if (args->__tgt_rtl_data_retrieve_async.AsyncInfo != NULL) {
				ratelprof_add_to_buffer(buf, ", \"->*\":{");
				ratelprof_add_to_buffer(buf, "}");
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_data_retrieve_async.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_data_delete :
			//	int32_t device_id (int);
			//	int32_t kind (int);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_delete.device_id);
			ratelprof_add_to_buffer(buf, "\"target_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_delete.target_ptr);
			ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_delete.kind);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_data_delete.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_data_exchange_async :
			//	int32_t src_dev_id (int);
			//	int32_t dst_dev_id (int);
			//	int64_t size (long);
			//	__tgt_async_info * AsyncInfo ({
			//	});
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"src_dev_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_exchange_async.src_dev_id);
			ratelprof_add_to_buffer(buf, "\"src_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_exchange_async.src_ptr);
			ratelprof_add_to_buffer(buf, "\"dst_dev_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_exchange_async.dst_dev_id);
			ratelprof_add_to_buffer(buf, "\"dst_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_exchange_async.dst_ptr);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_data_exchange_async.size);
			ratelprof_add_to_buffer(buf, "\"AsyncInfo\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_data_exchange_async.AsyncInfo);
			if (args->__tgt_rtl_data_exchange_async.AsyncInfo != NULL) {
				ratelprof_add_to_buffer(buf, ", \"->*\":{");
				ratelprof_add_to_buffer(buf, "}");
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_data_exchange_async.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_prepopulate_page_table :
			//	int32_t device_id (int);
			//	int64_t size (long);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_prepopulate_page_table.device_id);
			ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_prepopulate_page_table.ptr);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_prepopulate_page_table.size);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_prepopulate_page_table.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_data_exchange :
			//	int32_t src_dev_id (int);
			//	int32_t dst_dev_id (int);
			//	int64_t size (long);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"src_dev_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_exchange.src_dev_id);
			ratelprof_add_to_buffer(buf, "\"src_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_exchange.src_ptr);
			ratelprof_add_to_buffer(buf, "\"dst_dev_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_exchange.dst_dev_id);
			ratelprof_add_to_buffer(buf, "\"dst_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_exchange.dst_ptr);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_data_exchange.size);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_data_exchange.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_launch_kernel :
			//	int32_t device_id (int);
			//	void ** tgt_args (void**);
			//	ptrdiff_t * tgt_offsets (long*);
			//	KernelArgsTy * KernelArgs ({
			//		uint32_t Version (unsigned int);
			//		uint32_t NumArgs (unsigned int);
			//		uint64_t Tripcount (unsigned long);
			//		struct (unnamed struct at ../GILDA_Content/header/omp/omp_tgt_rtl.h:47:3) Flags ({
			//			uint64_t NoWait (unsigned long);
			//			uint64_t Unused (unsigned long);
			//		});
			//		uint32_t[3] NumTeams (unsigned int);
			//		uint32_t[3] ThreadLimit (unsigned int);
			//		uint32_t DynCGroupMem (unsigned int);
			//	});
			//	__tgt_async_info * AsyncInfo ({
			//	});
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_launch_kernel.device_id);
			ratelprof_add_to_buffer(buf, "\"tgt_entry_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_launch_kernel.tgt_entry_ptr);
			ratelprof_add_to_buffer(buf, "\"tgt_args\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_launch_kernel.tgt_args);
			if (args->__tgt_rtl_launch_kernel.tgt_args != NULL) {
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_launch_kernel.tgt_args__ref.ptr1);
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"tgt_offsets\":{\"type\":\"ptrdiff_t *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_launch_kernel.tgt_offsets);
			if (args->__tgt_rtl_launch_kernel.tgt_offsets != NULL) {
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%ld\"", args->__tgt_rtl_launch_kernel.tgt_offsets__ref.val);
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"KernelArgs\":{\"type\":\"KernelArgsTy *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_launch_kernel.KernelArgs);
			if (args->__tgt_rtl_launch_kernel.KernelArgs != NULL) {
				ratelprof_add_to_buffer(buf, ", \"->*\":{");
				ratelprof_add_to_buffer(buf, "\"Version\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.Version);
				ratelprof_add_to_buffer(buf, "\"NumArgs\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.NumArgs);
				ratelprof_add_to_buffer(buf, "\"Tripcount\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.Tripcount);
				ratelprof_add_to_buffer(buf, "\"Flags\":{\"type\":\"struct struct (unnamed struct at ../GILDA_Content/header/omp/omp_tgt_rtl.h:47:3)\",\"value\":{");
				ratelprof_add_to_buffer(buf, "\"NoWait\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.Flags.NoWait);
				ratelprof_add_to_buffer(buf, "\"Unused\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.Flags.Unused);
				ratelprof_add_to_buffer(buf, "}},");
				ratelprof_add_to_buffer(buf, "\"NumTeams\":{\"type\":\"uint32_t[3]\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.NumTeams[0]);
				ratelprof_add_to_buffer(buf, "\"ThreadLimit\":{\"type\":\"uint32_t[3]\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.ThreadLimit[0]);
				ratelprof_add_to_buffer(buf, "\"DynCGroupMem\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.DynCGroupMem);
				ratelprof_add_to_buffer(buf, "}");
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"AsyncInfo\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_launch_kernel.AsyncInfo);
			if (args->__tgt_rtl_launch_kernel.AsyncInfo != NULL) {
				ratelprof_add_to_buffer(buf, ", \"->*\":{");
				ratelprof_add_to_buffer(buf, "}");
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_launch_kernel.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_is_valid_binary :
			//	__tgt_device_image * image ({
			//	});
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"image\":{\"type\":\"__tgt_device_image *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_is_valid_binary.image);
			if (args->__tgt_rtl_is_valid_binary.image != NULL) {
				ratelprof_add_to_buffer(buf, ", \"->*\":{");
				ratelprof_add_to_buffer(buf, "}");
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_is_valid_binary.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_data_retrieve :
			//	int32_t device_id (int);
			//	int64_t size (long);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_retrieve.device_id);
			ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_retrieve.host_ptr);
			ratelprof_add_to_buffer(buf, "\"target_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_retrieve.target_ptr);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_data_retrieve.size);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_data_retrieve.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_data_lock :
			//	int32_t device_id (int);
			//	int64_t size (long);
			//	void ** LockedHostPtr (void**);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_lock.device_id);
			ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_lock.host_ptr);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_data_lock.size);
			ratelprof_add_to_buffer(buf, "\"LockedHostPtr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_data_lock.LockedHostPtr);
			if (args->__tgt_rtl_data_lock.LockedHostPtr != NULL) {
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_data_lock.LockedHostPtr__ref.ptr1);
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_data_lock.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_supports_empty_images :
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_supports_empty_images.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_destroy_event :
			//	int32_t device_id (int);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_destroy_event.device_id);
			ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_destroy_event.event);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_destroy_event.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_number_of_devices :
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_number_of_devices.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_init_requires :
			//	int64_t RequiresFlags (long);
			//	int64_t retval (long);
			ratelprof_add_to_buffer(buf, "\"RequiresFlags\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_init_requires.RequiresFlags);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int64_t\",\"value\":\"%ld\"}", args->__tgt_rtl_init_requires.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_data_notify_unmapped :
			//	int32_t device_id (int);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_notify_unmapped.device_id);
			ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_notify_unmapped.host_ptr);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_data_notify_unmapped.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_init_device_info :
			//	int32_t device_id (int);
			//	__tgt_device_info * device_info_ptr ({
			//	});
			//	const char ** err_str (string**);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_init_device_info.device_id);
			ratelprof_add_to_buffer(buf, "\"device_info_ptr\":{\"type\":\"__tgt_device_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_init_device_info.device_info_ptr);
			if (args->__tgt_rtl_init_device_info.device_info_ptr != NULL) {
				ratelprof_add_to_buffer(buf, ", \"->*\":{");
				ratelprof_add_to_buffer(buf, "}");
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"err_str\":{\"type\":\"const char **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_init_device_info.err_str);
			if (args->__tgt_rtl_init_device_info.err_str != NULL) {
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_init_device_info.err_str__ref.ptr1);
				if (args->__tgt_rtl_init_device_info.err_str__ref.ptr1 != NULL) {
					ratelprof_add_to_buffer(buf, ",\"->**\":\"%s\"", args->__tgt_rtl_init_device_info.err_str__ref.val);
				}
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_init_device_info.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_sync_event :
			//	int32_t device_id (int);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_sync_event.device_id);
			ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_sync_event.event);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_sync_event.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_synchronize :
			//	int32_t device_id (int);
			//	__tgt_async_info * AsyncInfo ({
			//	});
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_synchronize.device_id);
			ratelprof_add_to_buffer(buf, "\"AsyncInfo\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_synchronize.AsyncInfo);
			if (args->__tgt_rtl_synchronize.AsyncInfo != NULL) {
				ratelprof_add_to_buffer(buf, ", \"->*\":{");
				ratelprof_add_to_buffer(buf, "}");
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_synchronize.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_set_up_env :

\
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_data_unlock :
			//	int device_id (int);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int\",\"value\":\"%d\"},", args->__tgt_rtl_data_unlock.device_id);
			ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_unlock.host_ptr);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_data_unlock.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_is_fine_grained_memory_enabled :
			//	int retval (int);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->__tgt_rtl_is_fine_grained_memory_enabled.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_has_USM_capable_dGPU :
			//	int retval (int);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->__tgt_rtl_has_USM_capable_dGPU.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_has_apu_device :
			//	int retval (int);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->__tgt_rtl_has_apu_device.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_set_device_offset :
			//	int32_t DeviceIdOffset (int);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"DeviceIdOffset\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_set_device_offset.DeviceIdOffset);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_set_device_offset.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_launch_kernel_sync :
			//	int32_t device_id (int);
			//	void ** tgt_args (void**);
			//	ptrdiff_t * tgt_offsets (long*);
			//	KernelArgsTy * KernelArgs ({
			//		uint32_t Version (unsigned int);
			//		uint32_t NumArgs (unsigned int);
			//		uint64_t Tripcount (unsigned long);
			//		struct (unnamed struct at ../GILDA_Content/header/omp/omp_tgt_rtl.h:47:3) Flags ({
			//			uint64_t NoWait (unsigned long);
			//			uint64_t Unused (unsigned long);
			//		});
			//		uint32_t[3] NumTeams (unsigned int);
			//		uint32_t[3] ThreadLimit (unsigned int);
			//		uint32_t DynCGroupMem (unsigned int);
			//	});
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_launch_kernel_sync.device_id);
			ratelprof_add_to_buffer(buf, "\"tgt_entry_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_launch_kernel_sync.tgt_entry_ptr);
			ratelprof_add_to_buffer(buf, "\"tgt_args\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_launch_kernel_sync.tgt_args);
			if (args->__tgt_rtl_launch_kernel_sync.tgt_args != NULL) {
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_launch_kernel_sync.tgt_args__ref.ptr1);
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"tgt_offsets\":{\"type\":\"ptrdiff_t *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_launch_kernel_sync.tgt_offsets);
			if (args->__tgt_rtl_launch_kernel_sync.tgt_offsets != NULL) {
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%ld\"", args->__tgt_rtl_launch_kernel_sync.tgt_offsets__ref.val);
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"KernelArgs\":{\"type\":\"KernelArgsTy *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_launch_kernel_sync.KernelArgs);
			if (args->__tgt_rtl_launch_kernel_sync.KernelArgs != NULL) {
				ratelprof_add_to_buffer(buf, ", \"->*\":{");
				ratelprof_add_to_buffer(buf, "\"Version\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.Version);
				ratelprof_add_to_buffer(buf, "\"NumArgs\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.NumArgs);
				ratelprof_add_to_buffer(buf, "\"Tripcount\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.Tripcount);
				ratelprof_add_to_buffer(buf, "\"Flags\":{\"type\":\"struct struct (unnamed struct at ../GILDA_Content/header/omp/omp_tgt_rtl.h:47:3)\",\"value\":{");
				ratelprof_add_to_buffer(buf, "\"NoWait\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.Flags.NoWait);
				ratelprof_add_to_buffer(buf, "\"Unused\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.Flags.Unused);
				ratelprof_add_to_buffer(buf, "}},");
				ratelprof_add_to_buffer(buf, "\"NumTeams\":{\"type\":\"uint32_t[3]\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.NumTeams[0]);
				ratelprof_add_to_buffer(buf, "\"ThreadLimit\":{\"type\":\"uint32_t[3]\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.ThreadLimit[0]);
				ratelprof_add_to_buffer(buf, "\"DynCGroupMem\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.DynCGroupMem);
				ratelprof_add_to_buffer(buf, "}");
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_launch_kernel_sync.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_record_event :
			//	int32_t device_id (int);
			//	__tgt_async_info * AsyncInfo ({
			//	});
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_record_event.device_id);
			ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_record_event.event);
			ratelprof_add_to_buffer(buf, "\"AsyncInfo\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_record_event.AsyncInfo);
			if (args->__tgt_rtl_record_event.AsyncInfo != NULL) {
				ratelprof_add_to_buffer(buf, ", \"->*\":{");
				ratelprof_add_to_buffer(buf, "}");
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_record_event.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_set_info_flag :
			//	uint32_t NewInfoLevel (unsigned int);
			ratelprof_add_to_buffer(buf, "\"NewInfoLevel\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->__tgt_rtl_set_info_flag.NewInfoLevel);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_create_event :
			//	int32_t device_id (int);
			//	void ** event (void**);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_create_event.device_id);
			ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_create_event.event);
			if (args->__tgt_rtl_create_event.event != NULL) {
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_create_event.event__ref.ptr1);
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_create_event.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_print_device_info :
			//	int32_t device_id (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_print_device_info.device_id);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_get_function :
			//	__tgt_device_binary binary ({
			//		uintptr_t handle (unsigned long);
			//	});
			//	const char * name (string*);
			//	void ** kernel_ptr (void**);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"binary\":{\"type\":\"struct __tgt_device_binary\",\"value\":{");
			ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uintptr_t\",\"value\":\"%lu\"}", args->__tgt_rtl_get_function.binary.handle);
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"name\":{\"type\":\"const char *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_get_function.name);
			if (args->__tgt_rtl_get_function.name != NULL) {
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%s\"", args->__tgt_rtl_get_function.name__ref.val);
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"kernel_ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_get_function.kernel_ptr);
			if (args->__tgt_rtl_get_function.kernel_ptr != NULL) {
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_get_function.kernel_ptr__ref.ptr1);
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_get_function.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_init_plugin :
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_init_plugin.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_number_of_team_procs :
			//	int device_id (int);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int\",\"value\":\"%d\"},", args->__tgt_rtl_number_of_team_procs.device_id);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_number_of_team_procs.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_wait_event :
			//	int32_t device_id (int);
			//	__tgt_async_info * AsyncInfo ({
			//	});
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_wait_event.device_id);
			ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_wait_event.event);
			ratelprof_add_to_buffer(buf, "\"AsyncInfo\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_wait_event.AsyncInfo);
			if (args->__tgt_rtl_wait_event.AsyncInfo != NULL) {
				ratelprof_add_to_buffer(buf, ", \"->*\":{");
				ratelprof_add_to_buffer(buf, "}");
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_wait_event.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_data_alloc :
			//	int32_t device_id (int);
			//	int64_t size (long);
			//	int32_t kind (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_alloc.device_id);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_data_alloc.size);
			ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_alloc.host_ptr);
			ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_alloc.kind);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"void *\",\"value\":\"%p\"}", args->__tgt_rtl_data_alloc.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_init_device :
			//	int32_t device_id (int);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_init_device.device_id);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_init_device.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_get_global :
			//	__tgt_device_binary binary ({
			//		uintptr_t handle (unsigned long);
			//	});
			//	uint64_t size (unsigned long);
			//	const char * name (string*);
			//	void ** device_ptr (void**);
			//	int32_t retval (int);
			ratelprof_add_to_buffer(buf, "\"binary\":{\"type\":\"struct __tgt_device_binary\",\"value\":{");
			ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uintptr_t\",\"value\":\"%lu\"}", args->__tgt_rtl_get_global.binary.handle);
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->__tgt_rtl_get_global.size);
			ratelprof_add_to_buffer(buf, "\"name\":{\"type\":\"const char *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_get_global.name);
			if (args->__tgt_rtl_get_global.name != NULL) {
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%s\"", args->__tgt_rtl_get_global.name__ref.val);
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"device_ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_get_global.device_ptr);
			if (args->__tgt_rtl_get_global.device_ptr != NULL) {
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_get_global.device_ptr__ref.ptr1);
			}
			ratelprof_add_to_buffer(buf, "}},");
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_get_global.retval);
			break;

		case OMP_TGT_RTL_API_ID___tgt_rtl_requested_prepopulate_gpu_page_table :
			//	int retval (int);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->__tgt_rtl_requested_prepopulate_gpu_page_table.retval);
			break;
 
        default : break;
    }
}

