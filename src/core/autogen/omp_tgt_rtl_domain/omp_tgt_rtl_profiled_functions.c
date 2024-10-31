/* # THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * # DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * # ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA.
 */ 

#include <stdlib.h>
#include "omp_tgt_rtl_profiled_functions.h"
#include "api_table_manager.h"
#include "api_callback_manager.h"
#include "ratelprof.h"

#include "omp_support.h" 

extern api_table_t omp_tgt_rtl_api_table;
extern api_callback_t __on_enter_omp_tgt_rtl_callback_function;
extern api_callback_t __on_exit_omp_tgt_rtl_callback_function;

#define OMP_TGT_RTL_FUNCTION_CALL(func, ...) { \
	clock_gettime(CLOCK_MONOTONIC, &__omp_tgt_rtl_activity->start_time); \
	((__##func##_t)omp_tgt_rtl_api_table.api_fn[OMP_TGT_RTL_API_ID_##func])(__VA_ARGS__); \
	clock_gettime(CLOCK_MONOTONIC, &__omp_tgt_rtl_activity->stop_time); \
};

#define OMP_TGT_RTL_FUNCTION_CALL_RET(func, ...) { \
	clock_gettime(CLOCK_MONOTONIC, &__omp_tgt_rtl_activity->start_time); \
	__omp_tgt_rtl_ret = ((__##func##_t)omp_tgt_rtl_api_table.api_fn[OMP_TGT_RTL_API_ID_##func])(__VA_ARGS__); \
	clock_gettime(CLOCK_MONOTONIC, &__omp_tgt_rtl_activity->stop_time); \
	__omp_tgt_rtl_activity->omp_tgt_rtl_args.func.retval = __omp_tgt_rtl_ret; \
};

int32_t i___tgt_rtl_query_async(int32_t device_id, __tgt_async_info * AsyncInfoPtr) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_query_async, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_query_async, device_id, AsyncInfoPtr)
	GET_ARGS_VALUE___tgt_rtl_query_async(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_query_async, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_data_submit(int32_t device_id, void * target_ptr, void * host_ptr, int64_t size) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_submit, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_data_submit, device_id, target_ptr, host_ptr, size)
	GET_ARGS_VALUE___tgt_rtl_data_submit(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_submit, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int i___tgt_rtl_are_allocations_for_maps_on_apus_disabled() {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_are_allocations_for_maps_on_apus_disabled, __omp_tgt_rtl_activity);
	int __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_are_allocations_for_maps_on_apus_disabled, )
	GET_ARGS_VALUE___tgt_rtl_are_allocations_for_maps_on_apus_disabled(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_are_allocations_for_maps_on_apus_disabled, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_data_notify_mapped(int32_t device_id, void * host_ptr, int64_t size) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_notify_mapped, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_data_notify_mapped, device_id, host_ptr, size)
	GET_ARGS_VALUE___tgt_rtl_data_notify_mapped(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_notify_mapped, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_data_submit_async(int32_t device_id, void * target_ptr, void * host_ptr, int64_t size, __tgt_async_info * AsyncInfo) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_submit_async, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_data_submit_async, device_id, target_ptr, host_ptr, size, AsyncInfo)
	GET_ARGS_VALUE___tgt_rtl_data_submit_async(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_submit_async, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_init_async_info(int32_t device_id, __tgt_async_info ** async_info_ptr) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_init_async_info, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_init_async_info, device_id, async_info_ptr)
	GET_ARGS_VALUE___tgt_rtl_init_async_info(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_init_async_info, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_is_data_exchangable(int32_t src_dev_id, int32_t dst_dev_id) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_is_data_exchangable, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_is_data_exchangable, src_dev_id, dst_dev_id)
	GET_ARGS_VALUE___tgt_rtl_is_data_exchangable(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_is_data_exchangable, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_data_retrieve_async(int32_t device_id, void * host_ptr, void * target_ptr, int64_t size, __tgt_async_info * AsyncInfo) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_retrieve_async, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_data_retrieve_async, device_id, host_ptr, target_ptr, size, AsyncInfo)
	GET_ARGS_VALUE___tgt_rtl_data_retrieve_async(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_retrieve_async, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_data_delete(int32_t device_id, void * target_ptr, int32_t kind) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_delete, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_data_delete, device_id, target_ptr, kind)
	GET_ARGS_VALUE___tgt_rtl_data_delete(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_delete, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_data_exchange_async(int32_t src_dev_id, void * src_ptr, int32_t dst_dev_id, void * dst_ptr, int64_t size, __tgt_async_info * AsyncInfo) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_exchange_async, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_data_exchange_async, src_dev_id, src_ptr, dst_dev_id, dst_ptr, size, AsyncInfo)
	GET_ARGS_VALUE___tgt_rtl_data_exchange_async(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_exchange_async, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_prepopulate_page_table(int32_t device_id, void * ptr, int64_t size) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_prepopulate_page_table, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_prepopulate_page_table, device_id, ptr, size)
	GET_ARGS_VALUE___tgt_rtl_prepopulate_page_table(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_prepopulate_page_table, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_data_exchange(int32_t src_dev_id, void * src_ptr, int32_t dst_dev_id, void * dst_ptr, int64_t size) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_exchange, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_data_exchange, src_dev_id, src_ptr, dst_dev_id, dst_ptr, size)
	GET_ARGS_VALUE___tgt_rtl_data_exchange(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_exchange, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_launch_kernel(int32_t device_id, void * tgt_entry_ptr, void ** tgt_args, ptrdiff_t * tgt_offsets, KernelArgsTy * KernelArgs, __tgt_async_info * AsyncInfo) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_launch_kernel, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_launch_kernel, device_id, tgt_entry_ptr, tgt_args, tgt_offsets, KernelArgs, AsyncInfo)
	GET_ARGS_VALUE___tgt_rtl_launch_kernel(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_launch_kernel, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_is_valid_binary(__tgt_device_image * image) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_is_valid_binary, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_is_valid_binary, image)
	GET_ARGS_VALUE___tgt_rtl_is_valid_binary(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_is_valid_binary, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_data_retrieve(int32_t device_id, void * host_ptr, void * target_ptr, int64_t size) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_retrieve, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_data_retrieve, device_id, host_ptr, target_ptr, size)
	GET_ARGS_VALUE___tgt_rtl_data_retrieve(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_retrieve, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_data_lock(int32_t device_id, void * host_ptr, int64_t size, void ** LockedHostPtr) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_lock, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_data_lock, device_id, host_ptr, size, LockedHostPtr)
	GET_ARGS_VALUE___tgt_rtl_data_lock(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_lock, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_supports_empty_images() {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_supports_empty_images, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_supports_empty_images, )
	GET_ARGS_VALUE___tgt_rtl_supports_empty_images(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_supports_empty_images, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_destroy_event(int32_t device_id, void * event) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_destroy_event, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_destroy_event, device_id, event)
	GET_ARGS_VALUE___tgt_rtl_destroy_event(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_destroy_event, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_number_of_devices() {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_number_of_devices, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_number_of_devices, )
	GET_ARGS_VALUE___tgt_rtl_number_of_devices(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_number_of_devices, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int64_t i___tgt_rtl_init_requires(int64_t RequiresFlags) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_init_requires, __omp_tgt_rtl_activity);
	int64_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_init_requires, RequiresFlags)
	GET_ARGS_VALUE___tgt_rtl_init_requires(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_init_requires, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_data_notify_unmapped(int32_t device_id, void * host_ptr) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_notify_unmapped, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_data_notify_unmapped, device_id, host_ptr)
	GET_ARGS_VALUE___tgt_rtl_data_notify_unmapped(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_notify_unmapped, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_init_device_info(int32_t device_id, __tgt_device_info * device_info_ptr, const char ** err_str) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_init_device_info, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_init_device_info, device_id, device_info_ptr, err_str)
	GET_ARGS_VALUE___tgt_rtl_init_device_info(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_init_device_info, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_sync_event(int32_t device_id, void * event) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_sync_event, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_sync_event, device_id, event)
	GET_ARGS_VALUE___tgt_rtl_sync_event(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_sync_event, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_synchronize(int32_t device_id, __tgt_async_info * AsyncInfo) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_synchronize, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_synchronize, device_id, AsyncInfo)
	GET_ARGS_VALUE___tgt_rtl_synchronize(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_synchronize, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

void i___tgt_rtl_set_up_env() {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_set_up_env, __omp_tgt_rtl_activity);
	OMP_TGT_RTL_FUNCTION_CALL(__tgt_rtl_set_up_env, )
	GET_ARGS_VALUE___tgt_rtl_set_up_env(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_set_up_env, __omp_tgt_rtl_activity);
	return;
};

int32_t i___tgt_rtl_data_unlock(int device_id, void * host_ptr) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_unlock, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_data_unlock, device_id, host_ptr)
	GET_ARGS_VALUE___tgt_rtl_data_unlock(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_unlock, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int i___tgt_rtl_is_fine_grained_memory_enabled() {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_is_fine_grained_memory_enabled, __omp_tgt_rtl_activity);
	int __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_is_fine_grained_memory_enabled, )
	GET_ARGS_VALUE___tgt_rtl_is_fine_grained_memory_enabled(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_is_fine_grained_memory_enabled, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int i___tgt_rtl_has_USM_capable_dGPU() {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_has_USM_capable_dGPU, __omp_tgt_rtl_activity);
	int __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_has_USM_capable_dGPU, )
	GET_ARGS_VALUE___tgt_rtl_has_USM_capable_dGPU(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_has_USM_capable_dGPU, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int i___tgt_rtl_has_apu_device() {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_has_apu_device, __omp_tgt_rtl_activity);
	int __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_has_apu_device, )
	GET_ARGS_VALUE___tgt_rtl_has_apu_device(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_has_apu_device, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_set_device_offset(int32_t DeviceIdOffset) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_set_device_offset, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_set_device_offset, DeviceIdOffset)
	GET_ARGS_VALUE___tgt_rtl_set_device_offset(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_set_device_offset, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_launch_kernel_sync(int32_t device_id, void * tgt_entry_ptr, void ** tgt_args, ptrdiff_t * tgt_offsets, KernelArgsTy * KernelArgs) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_launch_kernel_sync, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_launch_kernel_sync, device_id, tgt_entry_ptr, tgt_args, tgt_offsets, KernelArgs)
	GET_ARGS_VALUE___tgt_rtl_launch_kernel_sync(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_launch_kernel_sync, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_record_event(int32_t device_id, void * event, __tgt_async_info * AsyncInfo) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_record_event, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_record_event, device_id, event, AsyncInfo)
	GET_ARGS_VALUE___tgt_rtl_record_event(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_record_event, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

void i___tgt_rtl_set_info_flag(uint32_t NewInfoLevel) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_set_info_flag, __omp_tgt_rtl_activity);
	OMP_TGT_RTL_FUNCTION_CALL(__tgt_rtl_set_info_flag, NewInfoLevel)
	GET_ARGS_VALUE___tgt_rtl_set_info_flag(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_set_info_flag, __omp_tgt_rtl_activity);
	return;
};

int32_t i___tgt_rtl_create_event(int32_t device_id, void ** event) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_create_event, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_create_event, device_id, event)
	GET_ARGS_VALUE___tgt_rtl_create_event(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_create_event, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

void i___tgt_rtl_print_device_info(int32_t device_id) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_print_device_info, __omp_tgt_rtl_activity);
	OMP_TGT_RTL_FUNCTION_CALL(__tgt_rtl_print_device_info, device_id)
	GET_ARGS_VALUE___tgt_rtl_print_device_info(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_print_device_info, __omp_tgt_rtl_activity);
	return;
};

int32_t i___tgt_rtl_get_function(__tgt_device_binary binary, const char * name, void ** kernel_ptr) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_get_function, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_get_function, binary, name, kernel_ptr)
	GET_ARGS_VALUE___tgt_rtl_get_function(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_get_function, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_init_plugin() {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_init_plugin, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_init_plugin, )
	GET_ARGS_VALUE___tgt_rtl_init_plugin(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_init_plugin, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_number_of_team_procs(int device_id) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_number_of_team_procs, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_number_of_team_procs, device_id)
	GET_ARGS_VALUE___tgt_rtl_number_of_team_procs(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_number_of_team_procs, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_wait_event(int32_t device_id, void * event, __tgt_async_info * AsyncInfo) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_wait_event, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_wait_event, device_id, event, AsyncInfo)
	GET_ARGS_VALUE___tgt_rtl_wait_event(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_wait_event, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

void * i___tgt_rtl_data_alloc(int32_t device_id, int64_t size, void * host_ptr, int32_t kind) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_alloc, __omp_tgt_rtl_activity);
	void * __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_data_alloc, device_id, size, host_ptr, kind)
	GET_ARGS_VALUE___tgt_rtl_data_alloc(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_data_alloc, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_init_device(int32_t device_id) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_init_device, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_init_device, device_id)
	GET_ARGS_VALUE___tgt_rtl_init_device(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_init_device, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int32_t i___tgt_rtl_get_global(__tgt_device_binary binary, uint64_t size, const char * name, void ** device_ptr) {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_get_global, __omp_tgt_rtl_activity);
	int32_t __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_get_global, binary, size, name, device_ptr)
	GET_ARGS_VALUE___tgt_rtl_get_global(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_get_global, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};

int i___tgt_rtl_requested_prepopulate_gpu_page_table() {
	ratelprof_api_activity_t* __omp_tgt_rtl_activity = (ratelprof_api_activity_t*)malloc(sizeof(ratelprof_api_activity_t));
	__on_enter_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_requested_prepopulate_gpu_page_table, __omp_tgt_rtl_activity);
	int __omp_tgt_rtl_ret;
	OMP_TGT_RTL_FUNCTION_CALL_RET(__tgt_rtl_requested_prepopulate_gpu_page_table, )
	GET_ARGS_VALUE___tgt_rtl_requested_prepopulate_gpu_page_table(__omp_tgt_rtl_activity);
	__on_exit_omp_tgt_rtl_callback_function(RATELPROF_DOMAIN_OMP_TGT_RTL, OMP_TGT_RTL_API_ID___tgt_rtl_requested_prepopulate_gpu_page_table, __omp_tgt_rtl_activity);
	return __omp_tgt_rtl_ret;
};
 
