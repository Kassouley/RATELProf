/** THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA.
 */

#include "ratelprof.h"
#include "omp.h"

#define CALL(func, ...) ((__##func##_t)omp_routine_api_table.api_ptr[OMP_ROUTINE_API_ID_##func])(__VA_ARGS__)

void * omp_target_memset(void * ptr, int value, size_t size, int device_num) {
	return CALL(omp_target_memset, ptr, value, size, device_num);
};

int omp_target_memcpy_async(void * dst, const void * src, size_t size, size_t dst_offset, size_t src_offset, int dst_device_num, int src_device_num, int async_depend_info, omp_depend_t * depend) {
	return CALL(omp_target_memcpy_async, dst, src, size, dst_offset, src_offset, dst_device_num, src_device_num, async_depend_info, depend);
};

int omp_target_memcpy_rect_async(void * dst, const void * src, size_t element_size, int num_dims, const size_t * volume, const size_t * dst_offsets, const size_t * src_offsets, const size_t * dst_dimensions, const size_t * src_dimensions, int dst_device_num, int src_device_num, int depobj_count, omp_depend_t * depobj_list) {
	return CALL(omp_target_memcpy_rect_async, dst, src, element_size, num_dims, volume, dst_offsets, src_offsets, dst_dimensions, src_dimensions, dst_device_num, src_device_num, depobj_count, depobj_list);
};

void * omp_target_alloc(size_t size, int device_num) {
	return CALL(omp_target_alloc, size, device_num);
};

void omp_target_free(void * device_ptr, int device_num) {
	CALL(omp_target_free, device_ptr, device_num);
};

int omp_target_memcpy_rect(void * dst, const void * src, size_t element_size, int num_dims, const size_t * volume, const size_t * dst_offsets, const size_t * src_offsets, const size_t * dst_dimensions, const size_t * src_dimensions, int dst_device_num, int src_device_num) {
	return CALL(omp_target_memcpy_rect, dst, src, element_size, num_dims, volume, dst_offsets, src_offsets, dst_dimensions, src_dimensions, dst_device_num, src_device_num);
};

int omp_target_disassociate_ptr(const void * host_ptr, int device_num) {
	return CALL(omp_target_disassociate_ptr, host_ptr, device_num);
};

int omp_target_memcpy(void * dst, const void * src, size_t size, size_t dst_offset, size_t src_offset, int dst_device_num, int src_device_num) {
	return CALL(omp_target_memcpy, dst, src, size, dst_offset, src_offset, dst_device_num, src_device_num);
};

void * omp_target_memset_async(void * ptr, int value, size_t size, int device_num, int async_depend_info, omp_depend_t * depend) {
	return CALL(omp_target_memset_async, ptr, value, size, device_num, async_depend_info, depend);
};

int omp_target_is_present(const void * host_ptr, int device_num) {
	return CALL(omp_target_is_present, host_ptr, device_num);
};

int omp_target_associate_ptr(const void * host_ptr, const void * device_ptr, size_t size, size_t alignment, int device_num) {
	return CALL(omp_target_associate_ptr, host_ptr, device_ptr, size, alignment, device_num);
};

int omp_get_initial_device() {
	return CALL(omp_get_initial_device, );
};

void * llvm_omp_target_dynamic_shared_alloc() {
	return CALL(llvm_omp_target_dynamic_shared_alloc, );
};

omp_intptr_t omp_get_interop_int(const omp_interop_t interop, omp_interop_property_t prop, int * exists) {
	return CALL(omp_get_interop_int, interop, prop, exists);
};

const char * omp_get_interop_name(const omp_interop_t interop, omp_interop_property_t prop) {
	return CALL(omp_get_interop_name, interop, prop);
};

void * omp_get_interop_ptr(const omp_interop_t interop, omp_interop_property_t prop, int * exists) {
	return CALL(omp_get_interop_ptr, interop, prop, exists);
};

const char * omp_get_interop_str(const omp_interop_t interop, omp_interop_property_t prop, int * exists) {
	return CALL(omp_get_interop_str, interop, prop, exists);
};

const char * omp_get_interop_type_desc(const omp_interop_t interop, omp_interop_property_t prop) {
	return CALL(omp_get_interop_type_desc, interop, prop);
};

void * omp_get_mapped_ptr(const void * ptr, int device_num) {
	return CALL(omp_get_mapped_ptr, ptr, device_num);
};

int omp_get_num_devices() {
	return CALL(omp_get_num_devices, );
};

int omp_is_coarse_grain_mem_region(void * ptr, size_t size) {
	return CALL(omp_is_coarse_grain_mem_region, ptr, size);
};

