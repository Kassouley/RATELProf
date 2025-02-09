/** THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA. 
 */
 
#include <ratelprof_ext.h>
#include <ratelprof.h>
#include "omp_tgt_plugin.h"

void on_enter_omp_tgt_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity){
    activity->phase = ratelprof_get_current_phase();
    activity->domain = domain;
    get_correlation_id(&activity->corr_id);
    get_id(&activity->id);
    activity->funid = id;
}

void on_exit_omp_tgt_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity){
    pop_id();
    activity->pid = get_pid();
    activity->tid = get_tid();
    ratelprof_activity_pool_push_activity(activity);
}

void process_omp_tgt_args_for(omp_tgt_api_id_t funid, const omp_tgt_api_args_t* args, void* user_args) 
{
    ratelprof_buffer_t* buf = (ratelprof_buffer_t*)user_args;
    switch(funid) {
		case OMP_TGT_API_ID_omp_target_memset :
			//	int value (int);
			//	size_t size (unsigned long);
			//	int device_num (int);
			ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_target_memset.ptr);
			ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memset.value);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memset.size);
			ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memset.device_num);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"void *\",\"value\":\"%p\"}", args->omp_target_memset.retval);
			break;

		case OMP_TGT_API_ID_omp_target_memcpy_async :
			//	size_t size (unsigned long);
			//	size_t dst_offset (unsigned long);
			//	size_t src_offset (unsigned long);
			//	int dst_device_num (int);
			//	int src_device_num (int);
			//	int async_depend_info (int);
			//	int retval (int);
			ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_target_memcpy_async.dst);
			ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_memcpy_async.src);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy_async.size);
			ratelprof_add_to_buffer(buf, "\"dst_offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy_async.dst_offset);
			ratelprof_add_to_buffer(buf, "\"src_offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy_async.src_offset);
			ratelprof_add_to_buffer(buf, "\"dst_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_async.dst_device_num);
			ratelprof_add_to_buffer(buf, "\"src_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_async.src_device_num);
			ratelprof_add_to_buffer(buf, "\"async_depend_info\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_async.async_depend_info);
			ratelprof_add_to_buffer(buf, "\"depend\":{\"type\":\"omp_depend_t *\",\"value\":\"%p\"},", args->omp_target_memcpy_async.depend);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_memcpy_async.retval);
			break;

		case OMP_TGT_API_ID_omp_target_memcpy_rect_async :
			//	size_t element_size (unsigned long);
			//	int num_dims (int);
			//	int dst_device_num (int);
			//	int src_device_num (int);
			//	int depobj_count (int);
			//	int retval (int);
			ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect_async.dst);
			ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect_async.src);
			ratelprof_add_to_buffer(buf, "\"element_size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy_rect_async.element_size);
			ratelprof_add_to_buffer(buf, "\"num_dims\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_rect_async.num_dims);
			ratelprof_add_to_buffer(buf, "\"volume\":{\"type\":\"const size_t *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect_async.volume);
			ratelprof_add_to_buffer(buf, "\"dst_offsets\":{\"type\":\"const size_t *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect_async.dst_offsets);
			ratelprof_add_to_buffer(buf, "\"src_offsets\":{\"type\":\"const size_t *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect_async.src_offsets);
			ratelprof_add_to_buffer(buf, "\"dst_dimensions\":{\"type\":\"const size_t *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect_async.dst_dimensions);
			ratelprof_add_to_buffer(buf, "\"src_dimensions\":{\"type\":\"const size_t *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect_async.src_dimensions);
			ratelprof_add_to_buffer(buf, "\"dst_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_rect_async.dst_device_num);
			ratelprof_add_to_buffer(buf, "\"src_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_rect_async.src_device_num);
			ratelprof_add_to_buffer(buf, "\"depobj_count\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_rect_async.depobj_count);
			ratelprof_add_to_buffer(buf, "\"depobj_list\":{\"type\":\"omp_depend_t *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect_async.depobj_list);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_memcpy_rect_async.retval);
			break;

		case OMP_TGT_API_ID_omp_target_alloc :
			//	size_t size (unsigned long);
			//	int device_num (int);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_alloc.size);
			ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_alloc.device_num);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"void *\",\"value\":\"%p\"}", args->omp_target_alloc.retval);
			break;

		case OMP_TGT_API_ID_omp_target_free :
			//	int device_num (int);
			ratelprof_add_to_buffer(buf, "\"device_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_target_free.device_ptr);
			ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_free.device_num);
			break;

		case OMP_TGT_API_ID_omp_target_memcpy_rect :
			//	size_t element_size (unsigned long);
			//	int num_dims (int);
			//	int dst_device_num (int);
			//	int src_device_num (int);
			//	int retval (int);
			ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect.dst);
			ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect.src);
			ratelprof_add_to_buffer(buf, "\"element_size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy_rect.element_size);
			ratelprof_add_to_buffer(buf, "\"num_dims\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_rect.num_dims);
			ratelprof_add_to_buffer(buf, "\"volume\":{\"type\":\"const size_t *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect.volume);
			ratelprof_add_to_buffer(buf, "\"dst_offsets\":{\"type\":\"const size_t *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect.dst_offsets);
			ratelprof_add_to_buffer(buf, "\"src_offsets\":{\"type\":\"const size_t *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect.src_offsets);
			ratelprof_add_to_buffer(buf, "\"dst_dimensions\":{\"type\":\"const size_t *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect.dst_dimensions);
			ratelprof_add_to_buffer(buf, "\"src_dimensions\":{\"type\":\"const size_t *\",\"value\":\"%p\"},", args->omp_target_memcpy_rect.src_dimensions);
			ratelprof_add_to_buffer(buf, "\"dst_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_rect.dst_device_num);
			ratelprof_add_to_buffer(buf, "\"src_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy_rect.src_device_num);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_memcpy_rect.retval);
			break;

		case OMP_TGT_API_ID_omp_target_disassociate_ptr :
			//	int device_num (int);
			//	int retval (int);
			ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_disassociate_ptr.host_ptr);
			ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_disassociate_ptr.device_num);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_disassociate_ptr.retval);
			break;

		case OMP_TGT_API_ID_omp_target_memcpy :
			//	size_t size (unsigned long);
			//	size_t dst_offset (unsigned long);
			//	size_t src_offset (unsigned long);
			//	int dst_device_num (int);
			//	int src_device_num (int);
			//	int retval (int);
			ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_target_memcpy.dst);
			ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_memcpy.src);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy.size);
			ratelprof_add_to_buffer(buf, "\"dst_offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy.dst_offset);
			ratelprof_add_to_buffer(buf, "\"src_offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memcpy.src_offset);
			ratelprof_add_to_buffer(buf, "\"dst_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy.dst_device_num);
			ratelprof_add_to_buffer(buf, "\"src_device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memcpy.src_device_num);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_memcpy.retval);
			break;

		case OMP_TGT_API_ID_omp_target_memset_async :
			//	int value (int);
			//	size_t size (unsigned long);
			//	int device_num (int);
			//	int async_depend_info (int);
			ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_target_memset_async.ptr);
			ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memset_async.value);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_memset_async.size);
			ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memset_async.device_num);
			ratelprof_add_to_buffer(buf, "\"async_depend_info\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_memset_async.async_depend_info);
			ratelprof_add_to_buffer(buf, "\"depend\":{\"type\":\"omp_depend_t *\",\"value\":\"%p\"},", args->omp_target_memset_async.depend);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"void *\",\"value\":\"%p\"}", args->omp_target_memset_async.retval);
			break;

		case OMP_TGT_API_ID_omp_target_is_present :
			//	int device_num (int);
			//	int retval (int);
			ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_is_present.host_ptr);
			ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_is_present.device_num);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_is_present.retval);
			break;

		case OMP_TGT_API_ID_omp_target_associate_ptr :
			//	size_t size (unsigned long);
			//	size_t alignment (unsigned long);
			//	int device_num (int);
			//	int retval (int);
			ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_associate_ptr.host_ptr);
			ratelprof_add_to_buffer(buf, "\"device_ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_target_associate_ptr.device_ptr);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_associate_ptr.size);
			ratelprof_add_to_buffer(buf, "\"alignment\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_target_associate_ptr.alignment);
			ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_target_associate_ptr.device_num);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_target_associate_ptr.retval);
			break;

		case OMP_TGT_API_ID_omp_get_initial_device :
			//	int retval (int);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_get_initial_device.retval);
			break;

		case OMP_TGT_API_ID_llvm_omp_target_dynamic_shared_alloc :

			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"void *\",\"value\":\"%p\"}", args->llvm_omp_target_dynamic_shared_alloc.retval);
			break;

		case OMP_TGT_API_ID_omp_get_interop_int :
			//	omp_interop_property_t prop (enum);
			//	omp_intptr_t retval (long);
			ratelprof_add_to_buffer(buf, "\"interop\":{\"type\":\"const omp_interop_t\",\"value\":\"%p\"},", args->omp_get_interop_int.interop);
			ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"omp_interop_property_t\",\"value\":\"%d\"},", args->omp_get_interop_int.prop);
			ratelprof_add_to_buffer(buf, "\"exists\":{\"type\":\"int *\",\"value\":\"%p\"},", args->omp_get_interop_int.exists);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"omp_intptr_t\",\"value\":\"%ld\"}", args->omp_get_interop_int.retval);
			break;

		case OMP_TGT_API_ID_omp_get_interop_name :
			//	omp_interop_property_t prop (enum);
			ratelprof_add_to_buffer(buf, "\"interop\":{\"type\":\"const omp_interop_t\",\"value\":\"%p\"},", args->omp_get_interop_name.interop);
			ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"omp_interop_property_t\",\"value\":\"%d\"},", args->omp_get_interop_name.prop);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"const char *\",\"value\":\"%p\"}", args->omp_get_interop_name.retval);
			break;

		case OMP_TGT_API_ID_omp_get_interop_ptr :
			//	omp_interop_property_t prop (enum);
			ratelprof_add_to_buffer(buf, "\"interop\":{\"type\":\"const omp_interop_t\",\"value\":\"%p\"},", args->omp_get_interop_ptr.interop);
			ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"omp_interop_property_t\",\"value\":\"%d\"},", args->omp_get_interop_ptr.prop);
			ratelprof_add_to_buffer(buf, "\"exists\":{\"type\":\"int *\",\"value\":\"%p\"},", args->omp_get_interop_ptr.exists);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"void *\",\"value\":\"%p\"}", args->omp_get_interop_ptr.retval);
			break;

		case OMP_TGT_API_ID_omp_get_interop_str :
			//	omp_interop_property_t prop (enum);
			ratelprof_add_to_buffer(buf, "\"interop\":{\"type\":\"const omp_interop_t\",\"value\":\"%p\"},", args->omp_get_interop_str.interop);
			ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"omp_interop_property_t\",\"value\":\"%d\"},", args->omp_get_interop_str.prop);
			ratelprof_add_to_buffer(buf, "\"exists\":{\"type\":\"int *\",\"value\":\"%p\"},", args->omp_get_interop_str.exists);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"const char *\",\"value\":\"%p\"}", args->omp_get_interop_str.retval);
			break;

		case OMP_TGT_API_ID_omp_get_interop_type_desc :
			//	omp_interop_property_t prop (enum);
			ratelprof_add_to_buffer(buf, "\"interop\":{\"type\":\"const omp_interop_t\",\"value\":\"%p\"},", args->omp_get_interop_type_desc.interop);
			ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"omp_interop_property_t\",\"value\":\"%d\"},", args->omp_get_interop_type_desc.prop);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"const char *\",\"value\":\"%p\"}", args->omp_get_interop_type_desc.retval);
			break;

		case OMP_TGT_API_ID_omp_get_mapped_ptr :
			//	int device_num (int);
			ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->omp_get_mapped_ptr.ptr);
			ratelprof_add_to_buffer(buf, "\"device_num\":{\"type\":\"int\",\"value\":\"%d\"},", args->omp_get_mapped_ptr.device_num);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"void *\",\"value\":\"%p\"}", args->omp_get_mapped_ptr.retval);
			break;

		case OMP_TGT_API_ID_omp_get_num_devices :
			//	int retval (int);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_get_num_devices.retval);
			break;

		case OMP_TGT_API_ID_omp_is_coarse_grain_mem_region :
			//	size_t size (unsigned long);
			//	int retval (int);
			ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->omp_is_coarse_grain_mem_region.ptr);
			ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->omp_is_coarse_grain_mem_region.size);
			ratelprof_add_to_buffer(buf, "\"retval\":{\"type\":\"int\",\"value\":\"%d\"}", args->omp_is_coarse_grain_mem_region.retval);
			break;
 
        default : break;
    }
}

