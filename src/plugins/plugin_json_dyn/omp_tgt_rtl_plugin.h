/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#ifndef OMP_TGT_RTL_PLUGIN_H 
#define OMP_TGT_RTL_PLUGIN_H 

#include "ratelprof_buffer_manager.h"

void on_enter_omp_tgt_rtl_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity);
void on_exit_omp_tgt_rtl_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity);
void process_omp_tgt_rtl_args_for(omp_tgt_rtl_api_id_t funid, const omp_tgt_rtl_api_args_t* args, ratelprof_buffer_t* buf);

//	int32_t device_id (int);
//	__tgt_async_info * AsyncInfoPtr ({
//	});
#define PROCESS_ARGS___tgt_rtl_query_async(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_query_async.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_query_async.device_id); \
	ratelprof_add_to_buffer(buf, "\"AsyncInfoPtr\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_query_async.AsyncInfoPtr); \
	if (args->__tgt_rtl_query_async.AsyncInfoPtr != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int32_t device_id (int);
//	int64_t size (long);
#define PROCESS_ARGS___tgt_rtl_data_submit(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_submit.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_submit.device_id); \
	ratelprof_add_to_buffer(buf, "\"target_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_submit.target_ptr); \
	ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_submit.host_ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"}", args->__tgt_rtl_data_submit.size); \
};


#define PROCESS_ARGS___tgt_rtl_are_allocations_for_maps_on_apus_disabled(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int\",\"value\":\"%d\"},", args->__tgt_rtl_are_allocations_for_maps_on_apus_disabled.retval); \
\
};

//	int32_t device_id (int);
//	int64_t size (long);
#define PROCESS_ARGS___tgt_rtl_data_notify_mapped(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_notify_mapped.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_notify_mapped.device_id); \
	ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_notify_mapped.host_ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"}", args->__tgt_rtl_data_notify_mapped.size); \
};

//	int32_t device_id (int);
//	int64_t size (long);
//	__tgt_async_info * AsyncInfo ({
//	});
#define PROCESS_ARGS___tgt_rtl_data_submit_async(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_submit_async.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_submit_async.device_id); \
	ratelprof_add_to_buffer(buf, "\"target_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_submit_async.target_ptr); \
	ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_submit_async.host_ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_data_submit_async.size); \
	ratelprof_add_to_buffer(buf, "\"AsyncInfo\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_data_submit_async.AsyncInfo); \
	if (args->__tgt_rtl_data_submit_async.AsyncInfo != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int32_t device_id (int);
//	__tgt_async_info ** async_info_ptr ({
//	});
#define PROCESS_ARGS___tgt_rtl_init_async_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_init_async_info.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_init_async_info.device_id); \
	ratelprof_add_to_buffer(buf, "\"async_info_ptr\":{\"type\":\"__tgt_async_info **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_init_async_info.async_info_ptr); \
	if (args->__tgt_rtl_init_async_info.async_info_ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_init_async_info.async_info_ptr__ref.ptr1); \
		if (args->__tgt_rtl_init_async_info.async_info_ptr__ref.ptr1 != NULL) { \
			ratelprof_add_to_buffer(buf, ", \"->**\":{"); \
			ratelprof_add_to_buffer(buf, "}"); \
		} \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int32_t src_dev_id (int);
//	int32_t dst_dev_id (int);
#define PROCESS_ARGS___tgt_rtl_is_data_exchangable(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_is_data_exchangable.retval); \
	ratelprof_add_to_buffer(buf, "\"src_dev_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_is_data_exchangable.src_dev_id); \
	ratelprof_add_to_buffer(buf, "\"dst_dev_id\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_is_data_exchangable.dst_dev_id); \
};

//	int32_t device_id (int);
//	int64_t size (long);
//	__tgt_async_info * AsyncInfo ({
//	});
#define PROCESS_ARGS___tgt_rtl_data_retrieve_async(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_retrieve_async.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_retrieve_async.device_id); \
	ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_retrieve_async.host_ptr); \
	ratelprof_add_to_buffer(buf, "\"target_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_retrieve_async.target_ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_data_retrieve_async.size); \
	ratelprof_add_to_buffer(buf, "\"AsyncInfo\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_data_retrieve_async.AsyncInfo); \
	if (args->__tgt_rtl_data_retrieve_async.AsyncInfo != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int32_t device_id (int);
//	int32_t kind (int);
#define PROCESS_ARGS___tgt_rtl_data_delete(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_delete.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_delete.device_id); \
	ratelprof_add_to_buffer(buf, "\"target_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_delete.target_ptr); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_data_delete.kind); \
};

//	int32_t src_dev_id (int);
//	int32_t dst_dev_id (int);
//	int64_t size (long);
//	__tgt_async_info * AsyncInfo ({
//	});
#define PROCESS_ARGS___tgt_rtl_data_exchange_async(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_exchange_async.retval); \
	ratelprof_add_to_buffer(buf, "\"src_dev_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_exchange_async.src_dev_id); \
	ratelprof_add_to_buffer(buf, "\"src_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_exchange_async.src_ptr); \
	ratelprof_add_to_buffer(buf, "\"dst_dev_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_exchange_async.dst_dev_id); \
	ratelprof_add_to_buffer(buf, "\"dst_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_exchange_async.dst_ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_data_exchange_async.size); \
	ratelprof_add_to_buffer(buf, "\"AsyncInfo\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_data_exchange_async.AsyncInfo); \
	if (args->__tgt_rtl_data_exchange_async.AsyncInfo != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int32_t device_id (int);
//	int64_t size (long);
#define PROCESS_ARGS___tgt_rtl_prepopulate_page_table(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_prepopulate_page_table.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_prepopulate_page_table.device_id); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_prepopulate_page_table.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"}", args->__tgt_rtl_prepopulate_page_table.size); \
};

//	int32_t src_dev_id (int);
//	int32_t dst_dev_id (int);
//	int64_t size (long);
#define PROCESS_ARGS___tgt_rtl_data_exchange(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_exchange.retval); \
	ratelprof_add_to_buffer(buf, "\"src_dev_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_exchange.src_dev_id); \
	ratelprof_add_to_buffer(buf, "\"src_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_exchange.src_ptr); \
	ratelprof_add_to_buffer(buf, "\"dst_dev_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_exchange.dst_dev_id); \
	ratelprof_add_to_buffer(buf, "\"dst_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_exchange.dst_ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"}", args->__tgt_rtl_data_exchange.size); \
};

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
#define PROCESS_ARGS___tgt_rtl_launch_kernel(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_launch_kernel.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_launch_kernel.device_id); \
	ratelprof_add_to_buffer(buf, "\"tgt_entry_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_launch_kernel.tgt_entry_ptr); \
	ratelprof_add_to_buffer(buf, "\"tgt_args\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_launch_kernel.tgt_args); \
	if (args->__tgt_rtl_launch_kernel.tgt_args != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_launch_kernel.tgt_args__ref.ptr1); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"tgt_offsets\":{\"type\":\"ptrdiff_t *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_launch_kernel.tgt_offsets); \
	if (args->__tgt_rtl_launch_kernel.tgt_offsets != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%ld\"", args->__tgt_rtl_launch_kernel.tgt_offsets__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"KernelArgs\":{\"type\":\"KernelArgsTy *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_launch_kernel.KernelArgs); \
	if (args->__tgt_rtl_launch_kernel.KernelArgs != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"Version\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.Version); \
		ratelprof_add_to_buffer(buf, "\"NumArgs\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.NumArgs); \
		ratelprof_add_to_buffer(buf, "\"Tripcount\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.Tripcount); \
		ratelprof_add_to_buffer(buf, "\"Flags\":{\"type\":\"struct struct (unnamed struct at ../GILDA_Content/header/omp/omp_tgt_rtl.h:47:3)\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"NoWait\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.Flags.NoWait); \
		ratelprof_add_to_buffer(buf, "\"Unused\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.Flags.Unused); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"NumTeams\":{\"type\":\"uint32_t[3]\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.NumTeams[0]); \
		ratelprof_add_to_buffer(buf, "\"ThreadLimit\":{\"type\":\"uint32_t[3]\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.ThreadLimit[0]); \
		ratelprof_add_to_buffer(buf, "\"DynCGroupMem\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.DynCGroupMem); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"AsyncInfo\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_launch_kernel.AsyncInfo); \
	if (args->__tgt_rtl_launch_kernel.AsyncInfo != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	__tgt_device_image * image ({
//	});
#define PROCESS_ARGS___tgt_rtl_is_valid_binary(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_is_valid_binary.retval); \
	ratelprof_add_to_buffer(buf, "\"image\":{\"type\":\"__tgt_device_image *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_is_valid_binary.image); \
	if (args->__tgt_rtl_is_valid_binary.image != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int32_t device_id (int);
//	int64_t size (long);
#define PROCESS_ARGS___tgt_rtl_data_retrieve(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_retrieve.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_retrieve.device_id); \
	ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_retrieve.host_ptr); \
	ratelprof_add_to_buffer(buf, "\"target_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_retrieve.target_ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"}", args->__tgt_rtl_data_retrieve.size); \
};

//	int32_t device_id (int);
//	int64_t size (long);
//	void ** LockedHostPtr (void**);
#define PROCESS_ARGS___tgt_rtl_data_lock(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_lock.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_lock.device_id); \
	ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_lock.host_ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_data_lock.size); \
	ratelprof_add_to_buffer(buf, "\"LockedHostPtr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_data_lock.LockedHostPtr); \
	if (args->__tgt_rtl_data_lock.LockedHostPtr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_data_lock.LockedHostPtr__ref.ptr1); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};


#define PROCESS_ARGS___tgt_rtl_supports_empty_images(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_supports_empty_images.retval); \
\
};

//	int32_t device_id (int);
#define PROCESS_ARGS___tgt_rtl_destroy_event(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_destroy_event.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_destroy_event.device_id); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"void *\",\"value\":\"%p\"}", args->__tgt_rtl_destroy_event.event); \
};


#define PROCESS_ARGS___tgt_rtl_number_of_devices(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_number_of_devices.retval); \
\
};

//	int64_t RequiresFlags (long);
#define PROCESS_ARGS___tgt_rtl_init_requires(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_init_requires.retval); \
	ratelprof_add_to_buffer(buf, "\"RequiresFlags\":{\"type\":\"int64_t\",\"value\":\"%ld\"}", args->__tgt_rtl_init_requires.RequiresFlags); \
};

//	int32_t device_id (int);
#define PROCESS_ARGS___tgt_rtl_data_notify_unmapped(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_notify_unmapped.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_notify_unmapped.device_id); \
	ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->__tgt_rtl_data_notify_unmapped.host_ptr); \
};

//	int32_t device_id (int);
//	__tgt_device_info * device_info_ptr ({
//	});
//	const char ** err_str (string**);
#define PROCESS_ARGS___tgt_rtl_init_device_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_init_device_info.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_init_device_info.device_id); \
	ratelprof_add_to_buffer(buf, "\"device_info_ptr\":{\"type\":\"__tgt_device_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_init_device_info.device_info_ptr); \
	if (args->__tgt_rtl_init_device_info.device_info_ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"err_str\":{\"type\":\"const char **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_init_device_info.err_str); \
	if (args->__tgt_rtl_init_device_info.err_str != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_init_device_info.err_str__ref.ptr1); \
		if (args->__tgt_rtl_init_device_info.err_str__ref.ptr1 != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->**\":\"%s\"", args->__tgt_rtl_init_device_info.err_str__ref.val); \
		} \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int32_t device_id (int);
#define PROCESS_ARGS___tgt_rtl_sync_event(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_sync_event.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_sync_event.device_id); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"void *\",\"value\":\"%p\"}", args->__tgt_rtl_sync_event.event); \
};

//	int32_t device_id (int);
//	__tgt_async_info * AsyncInfo ({
//	});
#define PROCESS_ARGS___tgt_rtl_synchronize(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_synchronize.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_synchronize.device_id); \
	ratelprof_add_to_buffer(buf, "\"AsyncInfo\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_synchronize.AsyncInfo); \
	if (args->__tgt_rtl_synchronize.AsyncInfo != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};


#define PROCESS_ARGS___tgt_rtl_set_up_env(args) { \
\
};

//	int device_id (int);
#define PROCESS_ARGS___tgt_rtl_data_unlock(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_unlock.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int\",\"value\":\"%d\"},", args->__tgt_rtl_data_unlock.device_id); \
	ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->__tgt_rtl_data_unlock.host_ptr); \
};


#define PROCESS_ARGS___tgt_rtl_is_fine_grained_memory_enabled(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int\",\"value\":\"%d\"},", args->__tgt_rtl_is_fine_grained_memory_enabled.retval); \
\
};


#define PROCESS_ARGS___tgt_rtl_has_USM_capable_dGPU(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int\",\"value\":\"%d\"},", args->__tgt_rtl_has_USM_capable_dGPU.retval); \
\
};


#define PROCESS_ARGS___tgt_rtl_has_apu_device(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int\",\"value\":\"%d\"},", args->__tgt_rtl_has_apu_device.retval); \
\
};

//	int32_t DeviceIdOffset (int);
#define PROCESS_ARGS___tgt_rtl_set_device_offset(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_set_device_offset.retval); \
	ratelprof_add_to_buffer(buf, "\"DeviceIdOffset\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_set_device_offset.DeviceIdOffset); \
};

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
#define PROCESS_ARGS___tgt_rtl_launch_kernel_sync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_launch_kernel_sync.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_launch_kernel_sync.device_id); \
	ratelprof_add_to_buffer(buf, "\"tgt_entry_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_launch_kernel_sync.tgt_entry_ptr); \
	ratelprof_add_to_buffer(buf, "\"tgt_args\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_launch_kernel_sync.tgt_args); \
	if (args->__tgt_rtl_launch_kernel_sync.tgt_args != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_launch_kernel_sync.tgt_args__ref.ptr1); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"tgt_offsets\":{\"type\":\"ptrdiff_t *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_launch_kernel_sync.tgt_offsets); \
	if (args->__tgt_rtl_launch_kernel_sync.tgt_offsets != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%ld\"", args->__tgt_rtl_launch_kernel_sync.tgt_offsets__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"KernelArgs\":{\"type\":\"KernelArgsTy *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_launch_kernel_sync.KernelArgs); \
	if (args->__tgt_rtl_launch_kernel_sync.KernelArgs != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"Version\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.Version); \
		ratelprof_add_to_buffer(buf, "\"NumArgs\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.NumArgs); \
		ratelprof_add_to_buffer(buf, "\"Tripcount\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.Tripcount); \
		ratelprof_add_to_buffer(buf, "\"Flags\":{\"type\":\"struct struct (unnamed struct at ../GILDA_Content/header/omp/omp_tgt_rtl.h:47:3)\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"NoWait\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.Flags.NoWait); \
		ratelprof_add_to_buffer(buf, "\"Unused\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.Flags.Unused); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"NumTeams\":{\"type\":\"uint32_t[3]\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.NumTeams[0]); \
		ratelprof_add_to_buffer(buf, "\"ThreadLimit\":{\"type\":\"uint32_t[3]\",\"value\":\"%u\"},", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.ThreadLimit[0]); \
		ratelprof_add_to_buffer(buf, "\"DynCGroupMem\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.DynCGroupMem); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int32_t device_id (int);
//	__tgt_async_info * AsyncInfo ({
//	});
#define PROCESS_ARGS___tgt_rtl_record_event(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_record_event.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_record_event.device_id); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_record_event.event); \
	ratelprof_add_to_buffer(buf, "\"AsyncInfo\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_record_event.AsyncInfo); \
	if (args->__tgt_rtl_record_event.AsyncInfo != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	uint32_t NewInfoLevel (unsigned int);
#define PROCESS_ARGS___tgt_rtl_set_info_flag(args) { \
	ratelprof_add_to_buffer(buf, "\"NewInfoLevel\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->__tgt_rtl_set_info_flag.NewInfoLevel); \
};

//	int32_t device_id (int);
//	void ** event (void**);
#define PROCESS_ARGS___tgt_rtl_create_event(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_create_event.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_create_event.device_id); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_create_event.event); \
	if (args->__tgt_rtl_create_event.event != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_create_event.event__ref.ptr1); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int32_t device_id (int);
#define PROCESS_ARGS___tgt_rtl_print_device_info(args) { \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_print_device_info.device_id); \
};

//	__tgt_device_binary binary ({
//		uintptr_t handle (unsigned long);
//	});
//	const char * name (string*);
//	void ** kernel_ptr (void**);
#define PROCESS_ARGS___tgt_rtl_get_function(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_get_function.retval); \
	ratelprof_add_to_buffer(buf, "\"binary\":{\"type\":\"struct __tgt_device_binary\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uintptr_t\",\"value\":\"%lu\"}", args->__tgt_rtl_get_function.binary.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"name\":{\"type\":\"const char *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_get_function.name); \
	if (args->__tgt_rtl_get_function.name != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%s\"", args->__tgt_rtl_get_function.name__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"kernel_ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_get_function.kernel_ptr); \
	if (args->__tgt_rtl_get_function.kernel_ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_get_function.kernel_ptr__ref.ptr1); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};


#define PROCESS_ARGS___tgt_rtl_init_plugin(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_init_plugin.retval); \
\
};

//	int device_id (int);
#define PROCESS_ARGS___tgt_rtl_number_of_team_procs(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_number_of_team_procs.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int\",\"value\":\"%d\"}", args->__tgt_rtl_number_of_team_procs.device_id); \
};

//	int32_t device_id (int);
//	__tgt_async_info * AsyncInfo ({
//	});
#define PROCESS_ARGS___tgt_rtl_wait_event(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_wait_event.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_wait_event.device_id); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_wait_event.event); \
	ratelprof_add_to_buffer(buf, "\"AsyncInfo\":{\"type\":\"__tgt_async_info *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_wait_event.AsyncInfo); \
	if (args->__tgt_rtl_wait_event.AsyncInfo != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int32_t device_id (int);
//	int64_t size (long);
//	int32_t kind (int);
#define PROCESS_ARGS___tgt_rtl_data_alloc(args) { \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_data_alloc.device_id); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"int64_t\",\"value\":\"%ld\"},", args->__tgt_rtl_data_alloc.size); \
	ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->__tgt_rtl_data_alloc.host_ptr); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_data_alloc.kind); \
};

//	int32_t device_id (int);
#define PROCESS_ARGS___tgt_rtl_init_device(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_init_device.retval); \
	ratelprof_add_to_buffer(buf, "\"device_id\":{\"type\":\"int32_t\",\"value\":\"%d\"}", args->__tgt_rtl_init_device.device_id); \
};

//	__tgt_device_binary binary ({
//		uintptr_t handle (unsigned long);
//	});
//	uint64_t size (unsigned long);
//	const char * name (string*);
//	void ** device_ptr (void**);
#define PROCESS_ARGS___tgt_rtl_get_global(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->__tgt_rtl_get_global.retval); \
	ratelprof_add_to_buffer(buf, "\"binary\":{\"type\":\"struct __tgt_device_binary\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uintptr_t\",\"value\":\"%lu\"}", args->__tgt_rtl_get_global.binary.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->__tgt_rtl_get_global.size); \
	ratelprof_add_to_buffer(buf, "\"name\":{\"type\":\"const char *\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_get_global.name); \
	if (args->__tgt_rtl_get_global.name != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%s\"", args->__tgt_rtl_get_global.name__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"device_ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->__tgt_rtl_get_global.device_ptr); \
	if (args->__tgt_rtl_get_global.device_ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->__tgt_rtl_get_global.device_ptr__ref.ptr1); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};


#define PROCESS_ARGS___tgt_rtl_requested_prepopulate_gpu_page_table(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int\",\"value\":\"%d\"},", args->__tgt_rtl_requested_prepopulate_gpu_page_table.retval); \
\
};

#endif // OMP_TGT_RTL_PLUGIN_H