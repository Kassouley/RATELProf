/** THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA. 
 */
 
#include <stdlib.h>
#include "ratelprof.h"
#include "domains/fun_proto/omp_tgt_profiled_functions.h"

#include "omp.h" 

void * i_omp_target_memset(void * ptr, int value, size_t size, int device_num) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_memset, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(void *, omp_target_memset, ptr, value, size, device_num);
	GET_ARGS_VALUE_omp_target_memset(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_memset, __omp_tgt_activity);
	return __omp_tgt_ret;
};

int i_omp_target_memcpy_async(void * dst, const void * src, size_t size, size_t dst_offset, size_t src_offset, int dst_device_num, int src_device_num, int async_depend_info, omp_depend_t * depend) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_memcpy_async, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(int, omp_target_memcpy_async, dst, src, size, dst_offset, src_offset, dst_device_num, src_device_num, async_depend_info, depend);
	GET_ARGS_VALUE_omp_target_memcpy_async(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_memcpy_async, __omp_tgt_activity);
	return __omp_tgt_ret;
};

int i_omp_target_memcpy_rect_async(void * dst, const void * src, size_t element_size, int num_dims, const size_t * volume, const size_t * dst_offsets, const size_t * src_offsets, const size_t * dst_dimensions, const size_t * src_dimensions, int dst_device_num, int src_device_num, int depobj_count, omp_depend_t * depobj_list) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_memcpy_rect_async, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(int, omp_target_memcpy_rect_async, dst, src, element_size, num_dims, volume, dst_offsets, src_offsets, dst_dimensions, src_dimensions, dst_device_num, src_device_num, depobj_count, depobj_list);
	GET_ARGS_VALUE_omp_target_memcpy_rect_async(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_memcpy_rect_async, __omp_tgt_activity);
	return __omp_tgt_ret;
};

void * i_omp_target_alloc(size_t size, int device_num) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_alloc, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(void *, omp_target_alloc, size, device_num);
	GET_ARGS_VALUE_omp_target_alloc(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_alloc, __omp_tgt_activity);
	return __omp_tgt_ret;
};

void i_omp_target_free(void * device_ptr, int device_num) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_free, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL(omp_target_free, device_ptr, device_num)
	GET_ARGS_VALUE_omp_target_free(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_free, __omp_tgt_activity);
	return;
};

int i_omp_target_memcpy_rect(void * dst, const void * src, size_t element_size, int num_dims, const size_t * volume, const size_t * dst_offsets, const size_t * src_offsets, const size_t * dst_dimensions, const size_t * src_dimensions, int dst_device_num, int src_device_num) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_memcpy_rect, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(int, omp_target_memcpy_rect, dst, src, element_size, num_dims, volume, dst_offsets, src_offsets, dst_dimensions, src_dimensions, dst_device_num, src_device_num);
	GET_ARGS_VALUE_omp_target_memcpy_rect(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_memcpy_rect, __omp_tgt_activity);
	return __omp_tgt_ret;
};

int i_omp_target_disassociate_ptr(const void * host_ptr, int device_num) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_disassociate_ptr, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(int, omp_target_disassociate_ptr, host_ptr, device_num);
	GET_ARGS_VALUE_omp_target_disassociate_ptr(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_disassociate_ptr, __omp_tgt_activity);
	return __omp_tgt_ret;
};

int i_omp_target_memcpy(void * dst, const void * src, size_t size, size_t dst_offset, size_t src_offset, int dst_device_num, int src_device_num) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_memcpy, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(int, omp_target_memcpy, dst, src, size, dst_offset, src_offset, dst_device_num, src_device_num);
	GET_ARGS_VALUE_omp_target_memcpy(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_memcpy, __omp_tgt_activity);
	return __omp_tgt_ret;
};

void * i_omp_target_memset_async(void * ptr, int value, size_t size, int device_num, int async_depend_info, omp_depend_t * depend) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_memset_async, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(void *, omp_target_memset_async, ptr, value, size, device_num, async_depend_info, depend);
	GET_ARGS_VALUE_omp_target_memset_async(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_memset_async, __omp_tgt_activity);
	return __omp_tgt_ret;
};

int i_omp_target_is_present(const void * host_ptr, int device_num) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_is_present, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(int, omp_target_is_present, host_ptr, device_num);
	GET_ARGS_VALUE_omp_target_is_present(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_is_present, __omp_tgt_activity);
	return __omp_tgt_ret;
};

int i_omp_target_associate_ptr(const void * host_ptr, const void * device_ptr, size_t size, size_t alignment, int device_num) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_associate_ptr, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(int, omp_target_associate_ptr, host_ptr, device_ptr, size, alignment, device_num);
	GET_ARGS_VALUE_omp_target_associate_ptr(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_target_associate_ptr, __omp_tgt_activity);
	return __omp_tgt_ret;
};

int i_omp_get_initial_device() {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_initial_device, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(int, omp_get_initial_device);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_initial_device, __omp_tgt_activity);
	return __omp_tgt_ret;
};

void * i_llvm_omp_target_dynamic_shared_alloc() {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_llvm_omp_target_dynamic_shared_alloc, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(void *, llvm_omp_target_dynamic_shared_alloc);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_llvm_omp_target_dynamic_shared_alloc, __omp_tgt_activity);
	return __omp_tgt_ret;
};

omp_intptr_t i_omp_get_interop_int(const omp_interop_t interop, omp_interop_property_t prop, int * exists) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_interop_int, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(omp_intptr_t, omp_get_interop_int, interop, prop, exists);
	GET_ARGS_VALUE_omp_get_interop_int(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_interop_int, __omp_tgt_activity);
	return __omp_tgt_ret;
};

const char * i_omp_get_interop_name(const omp_interop_t interop, omp_interop_property_t prop) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_interop_name, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(const char *, omp_get_interop_name, interop, prop);
	GET_ARGS_VALUE_omp_get_interop_name(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_interop_name, __omp_tgt_activity);
	return __omp_tgt_ret;
};

void * i_omp_get_interop_ptr(const omp_interop_t interop, omp_interop_property_t prop, int * exists) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_interop_ptr, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(void *, omp_get_interop_ptr, interop, prop, exists);
	GET_ARGS_VALUE_omp_get_interop_ptr(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_interop_ptr, __omp_tgt_activity);
	return __omp_tgt_ret;
};

const char * i_omp_get_interop_str(const omp_interop_t interop, omp_interop_property_t prop, int * exists) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_interop_str, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(const char *, omp_get_interop_str, interop, prop, exists);
	GET_ARGS_VALUE_omp_get_interop_str(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_interop_str, __omp_tgt_activity);
	return __omp_tgt_ret;
};

const char * i_omp_get_interop_type_desc(const omp_interop_t interop, omp_interop_property_t prop) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_interop_type_desc, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(const char *, omp_get_interop_type_desc, interop, prop);
	GET_ARGS_VALUE_omp_get_interop_type_desc(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_interop_type_desc, __omp_tgt_activity);
	return __omp_tgt_ret;
};

void * i_omp_get_mapped_ptr(const void * ptr, int device_num) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_mapped_ptr, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(void *, omp_get_mapped_ptr, ptr, device_num);
	GET_ARGS_VALUE_omp_get_mapped_ptr(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_mapped_ptr, __omp_tgt_activity);
	return __omp_tgt_ret;
};

int i_omp_get_num_devices() {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_num_devices, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(int, omp_get_num_devices);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_get_num_devices, __omp_tgt_activity);
	return __omp_tgt_ret;
};

int i_omp_is_coarse_grain_mem_region(void * ptr, size_t size) {
	ratelprof_api_activity_t* __omp_tgt_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	omp_tgt_callback.on_enter(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_is_coarse_grain_mem_region, __omp_tgt_activity);
	OMP_TGT_FUNCTION_CALL_RET(int, omp_is_coarse_grain_mem_region, ptr, size);
	GET_ARGS_VALUE_omp_is_coarse_grain_mem_region(__omp_tgt_activity);
	omp_tgt_callback.on_exit(RATELPROF_DOMAIN_OMP_TGT, OMP_TGT_API_ID_omp_is_coarse_grain_mem_region, __omp_tgt_activity);
	return __omp_tgt_ret;
};
 

