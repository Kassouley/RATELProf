/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#ifndef OMP_TGT_PLUGIN_H 
#define OMP_TGT_PLUGIN_H 

#include "ratelprof_buffer_manager.h"

void on_enter_omp_tgt_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity);
void on_exit_omp_tgt_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity);
void process_omp_tgt_args_for(omp_tgt_api_id_t funid, const omp_tgt_api_args_t* args, ratelprof_buffer_t* buf);

//	int value (int);
//	size_t size (unsigned long);
//	int device_num (int);
#define PROCESS_ARGS_omp_target_memset(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_target_memset.ptr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memset.value); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memset.size); \
	ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memset.device_num); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"void *\",\"value\":\"%p\"}", args->omp_target_memset.retval); \
};

//	size_t size (unsigned long);
//	size_t dst_offset (unsigned long);
//	size_t src_offset (unsigned long);
//	int dst_device_num (int);
//	int src_device_num (int);
//	int async_depend_info (int);
//	omp_depend_t * depend (void**);
//	int retval (int);
#define PROCESS_ARGS_omp_target_memcpy_async(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_target_memcpy_async.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_memcpy_async.src); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy_async.size); \
	ratelprof_add_to_buffer(buf, "\"dst_offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy_async.dst_offset); \
	ratelprof_add_to_buffer(buf, "\"src_offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy_async.src_offset); \
	ratelprof_add_to_buffer(buf, "\"dst_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_async.dst_device_num); \
	ratelprof_add_to_buffer(buf, "\"src_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_async.src_device_num); \
	ratelprof_add_to_buffer(buf, "\"async_depend_info\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_async.async_depend_info); \
	ratelprof_add_to_buffer(buf, "\"depend\":{\"type\":\"omp_depend_t *\",\"value\":{\"addr\":\"%p\"", args->omp_target_memcpy_async.depend); \
	if (args->omp_target_memcpy_async.depend != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->omp_target_memcpy_async.depend__ref.ptr1); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_memcpy_async.retval); \
};

//	size_t element_size (unsigned long);
//	int num_dims (int);
//	const size_t * volume (unsigned long*);
//	const size_t * dst_offsets (unsigned long*);
//	const size_t * src_offsets (unsigned long*);
//	const size_t * dst_dimensions (unsigned long*);
//	const size_t * src_dimensions (unsigned long*);
//	int dst_device_num (int);
//	int src_device_num (int);
//	int depobj_count (int);
//	omp_depend_t * depobj_list (void**);
//	int retval (int);
#define PROCESS_ARGS_omp_target_memcpy_rect_async(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect_async.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect_async.src); \
	ratelprof_add_to_buffer(buf, "\"element_size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy_rect_async.element_size); \
	ratelprof_add_to_buffer(buf, "\"num_dims\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_rect_async.num_dims); \
	ratelprof_add_to_buffer(buf, "\"volume\":{\"type\":\"const size_t *\",\"value\":{\"addr\":\"%p\"", args->omp_target_memcpy_rect_async.volume); \
	if (args->omp_target_memcpy_rect_async.volume != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", args->omp_target_memcpy_rect_async.volume__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dst_offsets\":{\"type\":\"const size_t *\",\"value\":{\"addr\":\"%p\"", args->omp_target_memcpy_rect_async.dst_offsets); \
	if (args->omp_target_memcpy_rect_async.dst_offsets != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", args->omp_target_memcpy_rect_async.dst_offsets__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src_offsets\":{\"type\":\"const size_t *\",\"value\":{\"addr\":\"%p\"", args->omp_target_memcpy_rect_async.src_offsets); \
	if (args->omp_target_memcpy_rect_async.src_offsets != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", args->omp_target_memcpy_rect_async.src_offsets__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dst_dimensions\":{\"type\":\"const size_t *\",\"value\":{\"addr\":\"%p\"", args->omp_target_memcpy_rect_async.dst_dimensions); \
	if (args->omp_target_memcpy_rect_async.dst_dimensions != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", args->omp_target_memcpy_rect_async.dst_dimensions__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src_dimensions\":{\"type\":\"const size_t *\",\"value\":{\"addr\":\"%p\"", args->omp_target_memcpy_rect_async.src_dimensions); \
	if (args->omp_target_memcpy_rect_async.src_dimensions != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", args->omp_target_memcpy_rect_async.src_dimensions__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dst_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_rect_async.dst_device_num); \
	ratelprof_add_to_buffer(buf, "\"src_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_rect_async.src_device_num); \
	ratelprof_add_to_buffer(buf, "\"depobj_count\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_rect_async.depobj_count); \
	ratelprof_add_to_buffer(buf, "\"depobj_list\":{\"type\":\"omp_depend_t *\",\"value\":{\"addr\":\"%p\"", args->omp_target_memcpy_rect_async.depobj_list); \
	if (args->omp_target_memcpy_rect_async.depobj_list != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->omp_target_memcpy_rect_async.depobj_list__ref.ptr1); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_memcpy_rect_async.retval); \
};

//	size_t size (unsigned long);
//	int device_num (int);
#define PROCESS_ARGS_omp_target_alloc(args) { \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_alloc.size); \
	ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_alloc.device_num); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"void *\",\"value\":\"%p\"}", args->omp_target_alloc.retval); \
};

//	int device_num (int);
#define PROCESS_ARGS_omp_target_free(args) { \
	ratelprof_add_to_buffer(buf, "\"device_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_target_free.device_ptr); \
	ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_free.device_num); \
};

//	size_t element_size (unsigned long);
//	int num_dims (int);
//	const size_t * volume (unsigned long*);
//	const size_t * dst_offsets (unsigned long*);
//	const size_t * src_offsets (unsigned long*);
//	const size_t * dst_dimensions (unsigned long*);
//	const size_t * src_dimensions (unsigned long*);
//	int dst_device_num (int);
//	int src_device_num (int);
//	int retval (int);
#define PROCESS_ARGS_omp_target_memcpy_rect(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect.src); \
	ratelprof_add_to_buffer(buf, "\"element_size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy_rect.element_size); \
	ratelprof_add_to_buffer(buf, "\"num_dims\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_rect.num_dims); \
	ratelprof_add_to_buffer(buf, "\"volume\":{\"type\":\"const size_t *\",\"value\":{\"addr\":\"%p\"", args->omp_target_memcpy_rect.volume); \
	if (args->omp_target_memcpy_rect.volume != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", args->omp_target_memcpy_rect.volume__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dst_offsets\":{\"type\":\"const size_t *\",\"value\":{\"addr\":\"%p\"", args->omp_target_memcpy_rect.dst_offsets); \
	if (args->omp_target_memcpy_rect.dst_offsets != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", args->omp_target_memcpy_rect.dst_offsets__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src_offsets\":{\"type\":\"const size_t *\",\"value\":{\"addr\":\"%p\"", args->omp_target_memcpy_rect.src_offsets); \
	if (args->omp_target_memcpy_rect.src_offsets != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", args->omp_target_memcpy_rect.src_offsets__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dst_dimensions\":{\"type\":\"const size_t *\",\"value\":{\"addr\":\"%p\"", args->omp_target_memcpy_rect.dst_dimensions); \
	if (args->omp_target_memcpy_rect.dst_dimensions != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", args->omp_target_memcpy_rect.dst_dimensions__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src_dimensions\":{\"type\":\"const size_t *\",\"value\":{\"addr\":\"%p\"", args->omp_target_memcpy_rect.src_dimensions); \
	if (args->omp_target_memcpy_rect.src_dimensions != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", args->omp_target_memcpy_rect.src_dimensions__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dst_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_rect.dst_device_num); \
	ratelprof_add_to_buffer(buf, "\"src_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_rect.src_device_num); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_memcpy_rect.retval); \
};

//	int device_num (int);
//	int retval (int);
#define PROCESS_ARGS_omp_target_disassociate_ptr(args) { \
	ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_disassociate_ptr.host_ptr); \
	ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_disassociate_ptr.device_num); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_disassociate_ptr.retval); \
};

//	size_t size (unsigned long);
//	size_t dst_offset (unsigned long);
//	size_t src_offset (unsigned long);
//	int dst_device_num (int);
//	int src_device_num (int);
//	int retval (int);
#define PROCESS_ARGS_omp_target_memcpy(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_target_memcpy.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_memcpy.src); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy.size); \
	ratelprof_add_to_buffer(buf, "\"dst_offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy.dst_offset); \
	ratelprof_add_to_buffer(buf, "\"src_offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy.src_offset); \
	ratelprof_add_to_buffer(buf, "\"dst_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy.dst_device_num); \
	ratelprof_add_to_buffer(buf, "\"src_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy.src_device_num); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_memcpy.retval); \
};

//	int value (int);
//	size_t size (unsigned long);
//	int device_num (int);
//	int async_depend_info (int);
//	omp_depend_t * depend (void**);
#define PROCESS_ARGS_omp_target_memset_async(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_target_memset_async.ptr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memset_async.value); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memset_async.size); \
	ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memset_async.device_num); \
	ratelprof_add_to_buffer(buf, "\"async_depend_info\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memset_async.async_depend_info); \
	ratelprof_add_to_buffer(buf, "\"depend\":{\"type\":\"omp_depend_t *\",\"value\":{\"addr\":\"%p\"", args->omp_target_memset_async.depend); \
	if (args->omp_target_memset_async.depend != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", args->omp_target_memset_async.depend__ref.ptr1); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"void *\",\"value\":\"%p\"}", args->omp_target_memset_async.retval); \
};

//	int device_num (int);
//	int retval (int);
#define PROCESS_ARGS_omp_target_is_present(args) { \
	ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_is_present.host_ptr); \
	ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_is_present.device_num); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_is_present.retval); \
};

//	size_t size (unsigned long);
//	size_t alignment (unsigned long);
//	int device_num (int);
//	int retval (int);
#define PROCESS_ARGS_omp_target_associate_ptr(args) { \
	ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_associate_ptr.host_ptr); \
	ratelprof_add_to_buffer(buf, "\"device_ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_associate_ptr.device_ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_associate_ptr.size); \
	ratelprof_add_to_buffer(buf, "\"alignment\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_associate_ptr.alignment); \
	ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_associate_ptr.device_num); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_associate_ptr.retval); \
};

//	int retval (int);
#define PROCESS_ARGS_omp_get_initial_device(args) { \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_get_initial_device.retval); \
};


#define PROCESS_ARGS_llvm_omp_target_dynamic_shared_alloc(args) { \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"void *\",\"value\":\"%p\"}", args->llvm_omp_target_dynamic_shared_alloc.retval); \
};

//	omp_interop_property_t prop (enum);
//	int * exists (int*);
//	omp_intptr_t retval (long);
#define PROCESS_ARGS_omp_get_interop_int(args) { \
	ratelprof_add_to_buffer(buf, "\"interop\":{\"type\":\"const omp_interop_t\",\"value\":\"%p\"},", args->omp_get_interop_int.interop); \
	ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"omp_interop_property_t\",\"value\":\"%d\"},", args->omp_get_interop_int.prop); \
	ratelprof_add_to_buffer(buf, "\"exists\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->omp_get_interop_int.exists); \
	if (args->omp_get_interop_int.exists != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", args->omp_get_interop_int.exists__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"omp_intptr_t\",\"value\":\"%ld\"}", args->omp_get_interop_int.retval); \
};

//	omp_interop_property_t prop (enum);
//	const char * retval (string*);
#define PROCESS_ARGS_omp_get_interop_name(args) { \
	ratelprof_add_to_buffer(buf, "\"interop\":{\"type\":\"const omp_interop_t\",\"value\":\"%p\"},", args->omp_get_interop_name.interop); \
	ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"omp_interop_property_t\",\"value\":\"%d\"},", args->omp_get_interop_name.prop); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"const char *\",\"value\":{\"addr\":\"%p\"", args->omp_get_interop_name.retval); \
	if (args->omp_get_interop_name.retval != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%s\"", args->omp_get_interop_name.retval__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	omp_interop_property_t prop (enum);
//	int * exists (int*);
#define PROCESS_ARGS_omp_get_interop_ptr(args) { \
	ratelprof_add_to_buffer(buf, "\"interop\":{\"type\":\"const omp_interop_t\",\"value\":\"%p\"},", args->omp_get_interop_ptr.interop); \
	ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"omp_interop_property_t\",\"value\":\"%d\"},", args->omp_get_interop_ptr.prop); \
	ratelprof_add_to_buffer(buf, "\"exists\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->omp_get_interop_ptr.exists); \
	if (args->omp_get_interop_ptr.exists != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", args->omp_get_interop_ptr.exists__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"void *\",\"value\":\"%p\"}", args->omp_get_interop_ptr.retval); \
};

//	omp_interop_property_t prop (enum);
//	int * exists (int*);
//	const char * retval (string*);
#define PROCESS_ARGS_omp_get_interop_str(args) { \
	ratelprof_add_to_buffer(buf, "\"interop\":{\"type\":\"const omp_interop_t\",\"value\":\"%p\"},", args->omp_get_interop_str.interop); \
	ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"omp_interop_property_t\",\"value\":\"%d\"},", args->omp_get_interop_str.prop); \
	ratelprof_add_to_buffer(buf, "\"exists\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->omp_get_interop_str.exists); \
	if (args->omp_get_interop_str.exists != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", args->omp_get_interop_str.exists__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"const char *\",\"value\":{\"addr\":\"%p\"", args->omp_get_interop_str.retval); \
	if (args->omp_get_interop_str.retval != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%s\"", args->omp_get_interop_str.retval__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	omp_interop_property_t prop (enum);
//	const char * retval (string*);
#define PROCESS_ARGS_omp_get_interop_type_desc(args) { \
	ratelprof_add_to_buffer(buf, "\"interop\":{\"type\":\"const omp_interop_t\",\"value\":\"%p\"},", args->omp_get_interop_type_desc.interop); \
	ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"omp_interop_property_t\",\"value\":\"%d\"},", args->omp_get_interop_type_desc.prop); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"const char *\",\"value\":{\"addr\":\"%p\"", args->omp_get_interop_type_desc.retval); \
	if (args->omp_get_interop_type_desc.retval != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%s\"", args->omp_get_interop_type_desc.retval__ref.val); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int device_num (int);
#define PROCESS_ARGS_omp_get_mapped_ptr(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_get_mapped_ptr.ptr); \
	ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_get_mapped_ptr.device_num); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"void *\",\"value\":\"%p\"}", args->omp_get_mapped_ptr.retval); \
};

//	int retval (int);
#define PROCESS_ARGS_omp_get_num_devices(args) { \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_get_num_devices.retval); \
};

//	size_t size (unsigned long);
//	int retval (int);
#define PROCESS_ARGS_omp_is_coarse_grain_mem_region(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_is_coarse_grain_mem_region.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_is_coarse_grain_mem_region.size); \
	ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_is_coarse_grain_mem_region.retval); \
};

#endif // OMP_TGT_PLUGIN_H