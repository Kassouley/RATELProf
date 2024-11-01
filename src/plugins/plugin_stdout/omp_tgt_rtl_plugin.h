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
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_query_async.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_query_async.device_id); \
	printf("\t__tgt_async_info * AsyncInfoPtr = %p", args->__tgt_rtl_query_async.AsyncInfoPtr); \
	if (args->__tgt_rtl_query_async.AsyncInfoPtr != NULL) { \
		printf(" -> {\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	int32_t device_id (int);
//	void * target_ptr (void*);
//	void * host_ptr (void*);
//	int64_t size (long);
#define PROCESS_ARGS___tgt_rtl_data_submit(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_data_submit.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_data_submit.device_id); \
	printf("\tvoid * target_ptr = %p", args->__tgt_rtl_data_submit.target_ptr); \
	printf("\n"); \
	printf("\tvoid * host_ptr = %p", args->__tgt_rtl_data_submit.host_ptr); \
	printf("\n"); \
	printf("\tint64_t size = %ld\n", args->__tgt_rtl_data_submit.size); \
};


#define PROCESS_ARGS___tgt_rtl_are_allocations_for_maps_on_apus_disabled(args) { \
	printf("\tint retval = %d\n", args->__tgt_rtl_are_allocations_for_maps_on_apus_disabled.retval); \
\
};

//	int32_t device_id (int);
//	void * host_ptr (void*);
//	int64_t size (long);
#define PROCESS_ARGS___tgt_rtl_data_notify_mapped(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_data_notify_mapped.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_data_notify_mapped.device_id); \
	printf("\tvoid * host_ptr = %p", args->__tgt_rtl_data_notify_mapped.host_ptr); \
	printf("\n"); \
	printf("\tint64_t size = %ld\n", args->__tgt_rtl_data_notify_mapped.size); \
};

//	int32_t device_id (int);
//	void * target_ptr (void*);
//	void * host_ptr (void*);
//	int64_t size (long);
//	__tgt_async_info * AsyncInfo ({
//	});
#define PROCESS_ARGS___tgt_rtl_data_submit_async(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_data_submit_async.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_data_submit_async.device_id); \
	printf("\tvoid * target_ptr = %p", args->__tgt_rtl_data_submit_async.target_ptr); \
	printf("\n"); \
	printf("\tvoid * host_ptr = %p", args->__tgt_rtl_data_submit_async.host_ptr); \
	printf("\n"); \
	printf("\tint64_t size = %ld\n", args->__tgt_rtl_data_submit_async.size); \
	printf("\t__tgt_async_info * AsyncInfo = %p", args->__tgt_rtl_data_submit_async.AsyncInfo); \
	if (args->__tgt_rtl_data_submit_async.AsyncInfo != NULL) { \
		printf(" -> {\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	int32_t device_id (int);
//	__tgt_async_info ** async_info_ptr ({
//	});
#define PROCESS_ARGS___tgt_rtl_init_async_info(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_init_async_info.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_init_async_info.device_id); \
	printf("\t__tgt_async_info ** async_info_ptr = %p", args->__tgt_rtl_init_async_info.async_info_ptr); \
	if (args->__tgt_rtl_init_async_info.async_info_ptr != NULL) { \
		printf("-> %p", args->__tgt_rtl_init_async_info.async_info_ptr__ref.ptr1); \
		if (args->__tgt_rtl_init_async_info.async_info_ptr__ref.ptr1 != NULL) { \
			printf(" -> {\n"); \
			printf("\t}\n"); \
		} else { printf("\n"); }; \
	} else { printf("\n"); }; \
};

//	int32_t src_dev_id (int);
//	int32_t dst_dev_id (int);
#define PROCESS_ARGS___tgt_rtl_is_data_exchangable(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_is_data_exchangable.retval); \
	printf("\tint32_t src_dev_id = %d\n", args->__tgt_rtl_is_data_exchangable.src_dev_id); \
	printf("\tint32_t dst_dev_id = %d\n", args->__tgt_rtl_is_data_exchangable.dst_dev_id); \
};

//	int32_t device_id (int);
//	void * host_ptr (void*);
//	void * target_ptr (void*);
//	int64_t size (long);
//	__tgt_async_info * AsyncInfo ({
//	});
#define PROCESS_ARGS___tgt_rtl_data_retrieve_async(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_data_retrieve_async.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_data_retrieve_async.device_id); \
	printf("\tvoid * host_ptr = %p", args->__tgt_rtl_data_retrieve_async.host_ptr); \
	printf("\n"); \
	printf("\tvoid * target_ptr = %p", args->__tgt_rtl_data_retrieve_async.target_ptr); \
	printf("\n"); \
	printf("\tint64_t size = %ld\n", args->__tgt_rtl_data_retrieve_async.size); \
	printf("\t__tgt_async_info * AsyncInfo = %p", args->__tgt_rtl_data_retrieve_async.AsyncInfo); \
	if (args->__tgt_rtl_data_retrieve_async.AsyncInfo != NULL) { \
		printf(" -> {\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	int32_t device_id (int);
//	void * target_ptr (void*);
//	int32_t kind (int);
#define PROCESS_ARGS___tgt_rtl_data_delete(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_data_delete.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_data_delete.device_id); \
	printf("\tvoid * target_ptr = %p", args->__tgt_rtl_data_delete.target_ptr); \
	printf("\n"); \
	printf("\tint32_t kind = %d\n", args->__tgt_rtl_data_delete.kind); \
};

//	int32_t src_dev_id (int);
//	void * src_ptr (void*);
//	int32_t dst_dev_id (int);
//	void * dst_ptr (void*);
//	int64_t size (long);
//	__tgt_async_info * AsyncInfo ({
//	});
#define PROCESS_ARGS___tgt_rtl_data_exchange_async(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_data_exchange_async.retval); \
	printf("\tint32_t src_dev_id = %d\n", args->__tgt_rtl_data_exchange_async.src_dev_id); \
	printf("\tvoid * src_ptr = %p", args->__tgt_rtl_data_exchange_async.src_ptr); \
	printf("\n"); \
	printf("\tint32_t dst_dev_id = %d\n", args->__tgt_rtl_data_exchange_async.dst_dev_id); \
	printf("\tvoid * dst_ptr = %p", args->__tgt_rtl_data_exchange_async.dst_ptr); \
	printf("\n"); \
	printf("\tint64_t size = %ld\n", args->__tgt_rtl_data_exchange_async.size); \
	printf("\t__tgt_async_info * AsyncInfo = %p", args->__tgt_rtl_data_exchange_async.AsyncInfo); \
	if (args->__tgt_rtl_data_exchange_async.AsyncInfo != NULL) { \
		printf(" -> {\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	int32_t device_id (int);
//	void * ptr (void*);
//	int64_t size (long);
#define PROCESS_ARGS___tgt_rtl_prepopulate_page_table(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_prepopulate_page_table.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_prepopulate_page_table.device_id); \
	printf("\tvoid * ptr = %p", args->__tgt_rtl_prepopulate_page_table.ptr); \
	printf("\n"); \
	printf("\tint64_t size = %ld\n", args->__tgt_rtl_prepopulate_page_table.size); \
};

//	int32_t src_dev_id (int);
//	void * src_ptr (void*);
//	int32_t dst_dev_id (int);
//	void * dst_ptr (void*);
//	int64_t size (long);
#define PROCESS_ARGS___tgt_rtl_data_exchange(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_data_exchange.retval); \
	printf("\tint32_t src_dev_id = %d\n", args->__tgt_rtl_data_exchange.src_dev_id); \
	printf("\tvoid * src_ptr = %p", args->__tgt_rtl_data_exchange.src_ptr); \
	printf("\n"); \
	printf("\tint32_t dst_dev_id = %d\n", args->__tgt_rtl_data_exchange.dst_dev_id); \
	printf("\tvoid * dst_ptr = %p", args->__tgt_rtl_data_exchange.dst_ptr); \
	printf("\n"); \
	printf("\tint64_t size = %ld\n", args->__tgt_rtl_data_exchange.size); \
};

//	int32_t device_id (int);
//	void * tgt_entry_ptr (void*);
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
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_launch_kernel.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_launch_kernel.device_id); \
	printf("\tvoid * tgt_entry_ptr = %p", args->__tgt_rtl_launch_kernel.tgt_entry_ptr); \
	printf("\n"); \
	printf("\tvoid ** tgt_args = %p", args->__tgt_rtl_launch_kernel.tgt_args); \
	if (args->__tgt_rtl_launch_kernel.tgt_args != NULL) { \
		printf("-> %p", args->__tgt_rtl_launch_kernel.tgt_args__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tptrdiff_t * tgt_offsets = %p", args->__tgt_rtl_launch_kernel.tgt_offsets); \
	if (args->__tgt_rtl_launch_kernel.tgt_offsets != NULL) { \
		printf(" -> %ld\n", args->__tgt_rtl_launch_kernel.tgt_offsets__ref.val); \
	} else { printf("\n"); }; \
	printf("\tKernelArgsTy * KernelArgs = %p", args->__tgt_rtl_launch_kernel.KernelArgs); \
	if (args->__tgt_rtl_launch_kernel.KernelArgs != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t Version = %u\n", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.Version); \
		printf("\t\tuint32_t NumArgs = %u\n", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.NumArgs); \
		printf("\t\tuint64_t Tripcount = %lu\n", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.Tripcount); \
		printf("\t\tstruct (unnamed struct at ../GILDA_Content/header/omp/omp_tgt_rtl.h:47:3) Flags = {\n"); \
		printf("\t\t\tuint64_t NoWait = %lu\n", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.Flags.NoWait); \
		printf("\t\t\tuint64_t Unused = %lu\n", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.Flags.Unused); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t[3] NumTeams = %u\n", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.NumTeams[0]); \
		printf("\t\tuint32_t[3] ThreadLimit = %u\n", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.ThreadLimit[0]); \
		printf("\t\tuint32_t DynCGroupMem = %u\n", args->__tgt_rtl_launch_kernel.KernelArgs__ref.val.DynCGroupMem); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\t__tgt_async_info * AsyncInfo = %p", args->__tgt_rtl_launch_kernel.AsyncInfo); \
	if (args->__tgt_rtl_launch_kernel.AsyncInfo != NULL) { \
		printf(" -> {\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	__tgt_device_image * image ({
//	});
#define PROCESS_ARGS___tgt_rtl_is_valid_binary(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_is_valid_binary.retval); \
	printf("\t__tgt_device_image * image = %p", args->__tgt_rtl_is_valid_binary.image); \
	if (args->__tgt_rtl_is_valid_binary.image != NULL) { \
		printf(" -> {\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	int32_t device_id (int);
//	void * host_ptr (void*);
//	void * target_ptr (void*);
//	int64_t size (long);
#define PROCESS_ARGS___tgt_rtl_data_retrieve(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_data_retrieve.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_data_retrieve.device_id); \
	printf("\tvoid * host_ptr = %p", args->__tgt_rtl_data_retrieve.host_ptr); \
	printf("\n"); \
	printf("\tvoid * target_ptr = %p", args->__tgt_rtl_data_retrieve.target_ptr); \
	printf("\n"); \
	printf("\tint64_t size = %ld\n", args->__tgt_rtl_data_retrieve.size); \
};

//	int32_t device_id (int);
//	void * host_ptr (void*);
//	int64_t size (long);
//	void ** LockedHostPtr (void**);
#define PROCESS_ARGS___tgt_rtl_data_lock(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_data_lock.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_data_lock.device_id); \
	printf("\tvoid * host_ptr = %p", args->__tgt_rtl_data_lock.host_ptr); \
	printf("\n"); \
	printf("\tint64_t size = %ld\n", args->__tgt_rtl_data_lock.size); \
	printf("\tvoid ** LockedHostPtr = %p", args->__tgt_rtl_data_lock.LockedHostPtr); \
	if (args->__tgt_rtl_data_lock.LockedHostPtr != NULL) { \
		printf("-> %p", args->__tgt_rtl_data_lock.LockedHostPtr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
};


#define PROCESS_ARGS___tgt_rtl_supports_empty_images(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_supports_empty_images.retval); \
\
};

//	int32_t device_id (int);
//	void * event (void*);
#define PROCESS_ARGS___tgt_rtl_destroy_event(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_destroy_event.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_destroy_event.device_id); \
	printf("\tvoid * event = %p", args->__tgt_rtl_destroy_event.event); \
	printf("\n"); \
};


#define PROCESS_ARGS___tgt_rtl_number_of_devices(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_number_of_devices.retval); \
\
};

//	int64_t RequiresFlags (long);
#define PROCESS_ARGS___tgt_rtl_init_requires(args) { \
	printf("\tint64_t retval = %ld\n", args->__tgt_rtl_init_requires.retval); \
	printf("\tint64_t RequiresFlags = %ld\n", args->__tgt_rtl_init_requires.RequiresFlags); \
};

//	int32_t device_id (int);
//	void * host_ptr (void*);
#define PROCESS_ARGS___tgt_rtl_data_notify_unmapped(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_data_notify_unmapped.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_data_notify_unmapped.device_id); \
	printf("\tvoid * host_ptr = %p", args->__tgt_rtl_data_notify_unmapped.host_ptr); \
	printf("\n"); \
};

//	int32_t device_id (int);
//	__tgt_device_info * device_info_ptr ({
//	});
//	const char ** err_str (string**);
#define PROCESS_ARGS___tgt_rtl_init_device_info(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_init_device_info.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_init_device_info.device_id); \
	printf("\t__tgt_device_info * device_info_ptr = %p", args->__tgt_rtl_init_device_info.device_info_ptr); \
	if (args->__tgt_rtl_init_device_info.device_info_ptr != NULL) { \
		printf(" -> {\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tconst char ** err_str = %p", args->__tgt_rtl_init_device_info.err_str); \
	if (args->__tgt_rtl_init_device_info.err_str != NULL) { \
		printf("-> %p", args->__tgt_rtl_init_device_info.err_str__ref.ptr1); \
		if (args->__tgt_rtl_init_device_info.err_str__ref.ptr1 != NULL) { \
			printf(" -> %s\n", args->__tgt_rtl_init_device_info.err_str__ref.val); \
		} else { printf("\n"); }; \
	} else { printf("\n"); }; \
};

//	int32_t device_id (int);
//	void * event (void*);
#define PROCESS_ARGS___tgt_rtl_sync_event(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_sync_event.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_sync_event.device_id); \
	printf("\tvoid * event = %p", args->__tgt_rtl_sync_event.event); \
	printf("\n"); \
};

//	int32_t device_id (int);
//	__tgt_async_info * AsyncInfo ({
//	});
#define PROCESS_ARGS___tgt_rtl_synchronize(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_synchronize.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_synchronize.device_id); \
	printf("\t__tgt_async_info * AsyncInfo = %p", args->__tgt_rtl_synchronize.AsyncInfo); \
	if (args->__tgt_rtl_synchronize.AsyncInfo != NULL) { \
		printf(" -> {\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};


#define PROCESS_ARGS___tgt_rtl_set_up_env(args) { \
\
};

//	int device_id (int);
//	void * host_ptr (void*);
#define PROCESS_ARGS___tgt_rtl_data_unlock(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_data_unlock.retval); \
	printf("\tint device_id = %d\n", args->__tgt_rtl_data_unlock.device_id); \
	printf("\tvoid * host_ptr = %p", args->__tgt_rtl_data_unlock.host_ptr); \
	printf("\n"); \
};


#define PROCESS_ARGS___tgt_rtl_is_fine_grained_memory_enabled(args) { \
	printf("\tint retval = %d\n", args->__tgt_rtl_is_fine_grained_memory_enabled.retval); \
\
};


#define PROCESS_ARGS___tgt_rtl_has_USM_capable_dGPU(args) { \
	printf("\tint retval = %d\n", args->__tgt_rtl_has_USM_capable_dGPU.retval); \
\
};


#define PROCESS_ARGS___tgt_rtl_has_apu_device(args) { \
	printf("\tint retval = %d\n", args->__tgt_rtl_has_apu_device.retval); \
\
};

//	int32_t DeviceIdOffset (int);
#define PROCESS_ARGS___tgt_rtl_set_device_offset(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_set_device_offset.retval); \
	printf("\tint32_t DeviceIdOffset = %d\n", args->__tgt_rtl_set_device_offset.DeviceIdOffset); \
};

//	int32_t device_id (int);
//	void * tgt_entry_ptr (void*);
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
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_launch_kernel_sync.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_launch_kernel_sync.device_id); \
	printf("\tvoid * tgt_entry_ptr = %p", args->__tgt_rtl_launch_kernel_sync.tgt_entry_ptr); \
	printf("\n"); \
	printf("\tvoid ** tgt_args = %p", args->__tgt_rtl_launch_kernel_sync.tgt_args); \
	if (args->__tgt_rtl_launch_kernel_sync.tgt_args != NULL) { \
		printf("-> %p", args->__tgt_rtl_launch_kernel_sync.tgt_args__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tptrdiff_t * tgt_offsets = %p", args->__tgt_rtl_launch_kernel_sync.tgt_offsets); \
	if (args->__tgt_rtl_launch_kernel_sync.tgt_offsets != NULL) { \
		printf(" -> %ld\n", args->__tgt_rtl_launch_kernel_sync.tgt_offsets__ref.val); \
	} else { printf("\n"); }; \
	printf("\tKernelArgsTy * KernelArgs = %p", args->__tgt_rtl_launch_kernel_sync.KernelArgs); \
	if (args->__tgt_rtl_launch_kernel_sync.KernelArgs != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t Version = %u\n", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.Version); \
		printf("\t\tuint32_t NumArgs = %u\n", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.NumArgs); \
		printf("\t\tuint64_t Tripcount = %lu\n", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.Tripcount); \
		printf("\t\tstruct (unnamed struct at ../GILDA_Content/header/omp/omp_tgt_rtl.h:47:3) Flags = {\n"); \
		printf("\t\t\tuint64_t NoWait = %lu\n", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.Flags.NoWait); \
		printf("\t\t\tuint64_t Unused = %lu\n", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.Flags.Unused); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t[3] NumTeams = %u\n", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.NumTeams[0]); \
		printf("\t\tuint32_t[3] ThreadLimit = %u\n", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.ThreadLimit[0]); \
		printf("\t\tuint32_t DynCGroupMem = %u\n", args->__tgt_rtl_launch_kernel_sync.KernelArgs__ref.val.DynCGroupMem); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	int32_t device_id (int);
//	void * event (void*);
//	__tgt_async_info * AsyncInfo ({
//	});
#define PROCESS_ARGS___tgt_rtl_record_event(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_record_event.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_record_event.device_id); \
	printf("\tvoid * event = %p", args->__tgt_rtl_record_event.event); \
	printf("\n"); \
	printf("\t__tgt_async_info * AsyncInfo = %p", args->__tgt_rtl_record_event.AsyncInfo); \
	if (args->__tgt_rtl_record_event.AsyncInfo != NULL) { \
		printf(" -> {\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	uint32_t NewInfoLevel (unsigned int);
#define PROCESS_ARGS___tgt_rtl_set_info_flag(args) { \
	printf("\tuint32_t NewInfoLevel = %u\n", args->__tgt_rtl_set_info_flag.NewInfoLevel); \
};

//	int32_t device_id (int);
//	void ** event (void**);
#define PROCESS_ARGS___tgt_rtl_create_event(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_create_event.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_create_event.device_id); \
	printf("\tvoid ** event = %p", args->__tgt_rtl_create_event.event); \
	if (args->__tgt_rtl_create_event.event != NULL) { \
		printf("-> %p", args->__tgt_rtl_create_event.event__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
};

//	int32_t device_id (int);
#define PROCESS_ARGS___tgt_rtl_print_device_info(args) { \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_print_device_info.device_id); \
};

//	__tgt_device_binary binary ({
//		uintptr_t handle (unsigned long);
//	});
//	const char * name (string*);
//	void ** kernel_ptr (void**);
#define PROCESS_ARGS___tgt_rtl_get_function(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_get_function.retval); \
	printf("\t__tgt_device_binary binary = {\n"); \
	printf("\t\tuintptr_t handle = %lu\n", args->__tgt_rtl_get_function.binary.handle); \
	printf("\t}\n"); \
	printf("\tconst char * name = %p", args->__tgt_rtl_get_function.name); \
	if (args->__tgt_rtl_get_function.name != NULL) { \
		printf(" -> %s\n", args->__tgt_rtl_get_function.name__ref.val); \
	} else { printf("\n"); }; \
	printf("\tvoid ** kernel_ptr = %p", args->__tgt_rtl_get_function.kernel_ptr); \
	if (args->__tgt_rtl_get_function.kernel_ptr != NULL) { \
		printf("-> %p", args->__tgt_rtl_get_function.kernel_ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
};


#define PROCESS_ARGS___tgt_rtl_init_plugin(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_init_plugin.retval); \
\
};

//	int device_id (int);
#define PROCESS_ARGS___tgt_rtl_number_of_team_procs(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_number_of_team_procs.retval); \
	printf("\tint device_id = %d\n", args->__tgt_rtl_number_of_team_procs.device_id); \
};

//	int32_t device_id (int);
//	void * event (void*);
//	__tgt_async_info * AsyncInfo ({
//	});
#define PROCESS_ARGS___tgt_rtl_wait_event(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_wait_event.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_wait_event.device_id); \
	printf("\tvoid * event = %p", args->__tgt_rtl_wait_event.event); \
	printf("\n"); \
	printf("\t__tgt_async_info * AsyncInfo = %p", args->__tgt_rtl_wait_event.AsyncInfo); \
	if (args->__tgt_rtl_wait_event.AsyncInfo != NULL) { \
		printf(" -> {\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	int32_t device_id (int);
//	int64_t size (long);
//	void * host_ptr (void*);
//	int32_t kind (int);
#define PROCESS_ARGS___tgt_rtl_data_alloc(args) { \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_data_alloc.device_id); \
	printf("\tint64_t size = %ld\n", args->__tgt_rtl_data_alloc.size); \
	printf("\tvoid * host_ptr = %p", args->__tgt_rtl_data_alloc.host_ptr); \
	printf("\n"); \
	printf("\tint32_t kind = %d\n", args->__tgt_rtl_data_alloc.kind); \
};

//	int32_t device_id (int);
#define PROCESS_ARGS___tgt_rtl_init_device(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_init_device.retval); \
	printf("\tint32_t device_id = %d\n", args->__tgt_rtl_init_device.device_id); \
};

//	__tgt_device_binary binary ({
//		uintptr_t handle (unsigned long);
//	});
//	uint64_t size (unsigned long);
//	const char * name (string*);
//	void ** device_ptr (void**);
#define PROCESS_ARGS___tgt_rtl_get_global(args) { \
	printf("\tint32_t retval = %d\n", args->__tgt_rtl_get_global.retval); \
	printf("\t__tgt_device_binary binary = {\n"); \
	printf("\t\tuintptr_t handle = %lu\n", args->__tgt_rtl_get_global.binary.handle); \
	printf("\t}\n"); \
	printf("\tuint64_t size = %lu\n", args->__tgt_rtl_get_global.size); \
	printf("\tconst char * name = %p", args->__tgt_rtl_get_global.name); \
	if (args->__tgt_rtl_get_global.name != NULL) { \
		printf(" -> %s\n", args->__tgt_rtl_get_global.name__ref.val); \
	} else { printf("\n"); }; \
	printf("\tvoid ** device_ptr = %p", args->__tgt_rtl_get_global.device_ptr); \
	if (args->__tgt_rtl_get_global.device_ptr != NULL) { \
		printf("-> %p", args->__tgt_rtl_get_global.device_ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
};


#define PROCESS_ARGS___tgt_rtl_requested_prepopulate_gpu_page_table(args) { \
	printf("\tint retval = %d\n", args->__tgt_rtl_requested_prepopulate_gpu_page_table.retval); \
\
};

#endif // OMP_TGT_RTL_PLUGIN_H