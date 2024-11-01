/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#ifndef HSA_PLUGIN_H 
#define HSA_PLUGIN_H 

#include "ratelprof_buffer_manager.h"

void on_enter_hsa_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity);
void on_exit_hsa_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity);
void process_hsa_args_for(hsa_api_id_t funid, const hsa_api_args_t* args, ratelprof_buffer_t* buf);


#define PROCESS_ARGS_hsa_queue_load_read_index_scacquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_load_read_index_scacquire.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"}", args->hsa_queue_load_read_index_scacquire.queue); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_ext_image_t image ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_ext_image_clear(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_ext_image_clear.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_clear.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"image\":{\"type\":\"struct hsa_ext_image_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_clear.image.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hsa_ext_image_clear.data); \
	ratelprof_add_to_buffer(buf, "\"image_region\":{\"type\":\"const hsa_ext_image_region_t *\",\"value\":\"%p\"}", args->hsa_ext_image_clear.image_region); \
};

//	uint64_t expected (unsigned long);
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_cas_write_index_acquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_cas_write_index_acquire.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_cas_write_index_acquire.queue); \
	ratelprof_add_to_buffer(buf, "\"expected\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_cas_write_index_acquire.expected); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_cas_write_index_acquire.value); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	int32_t call_convention (int);
#define PROCESS_ARGS_hsa_executable_get_symbol(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_get_symbol.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_get_symbol.executable.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"module_name\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_executable_get_symbol.module_name); \
	ratelprof_add_to_buffer(buf, "\"symbol_name\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_executable_get_symbol.symbol_name); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_get_symbol.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"call_convention\":{\"type\":\"int32_t\",\"value\":\"%d\"},", args->hsa_executable_get_symbol.call_convention); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"hsa_executable_symbol_t *\",\"value\":\"%p\"}", args->hsa_executable_get_symbol.symbol); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_and_scacq_screl(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_and_scacq_screl.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_and_scacq_screl.value); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_agent_global_variable_define(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_agent_global_variable_define.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_agent_global_variable_define.executable.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_agent_global_variable_define.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"variable_name\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_executable_agent_global_variable_define.variable_name); \
	ratelprof_add_to_buffer(buf, "\"address\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_executable_agent_global_variable_define.address); \
};

//	hsa_code_object_t code_object ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_code_object_get_symbol(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_code_object_get_symbol.retval); \
	ratelprof_add_to_buffer(buf, "\"code_object\":{\"type\":\"struct hsa_code_object_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_code_object_get_symbol.code_object.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"symbol_name\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_code_object_get_symbol.symbol_name); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"hsa_code_symbol_t *\",\"value\":\"%p\"}", args->hsa_code_object_get_symbol.symbol); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_condition_t cond (enum);
//	hsa_signal_value_t value (long);
//	hsa_amd_signal_handler handler (function);
#define PROCESS_ARGS_hsa_amd_signal_async_handler(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_signal_async_handler.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_signal_async_handler.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"cond\":{\"type\":\"hsa_signal_condition_t\",\"value\":\"%d\"},", args->hsa_amd_signal_async_handler.cond); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_amd_signal_async_handler.value); \
	ratelprof_add_to_buffer(buf, "\"handler\":{\"type\":\"hsa_amd_signal_handler\",\"value\":\"%p\"},", args->hsa_amd_signal_async_handler.handler); \
	ratelprof_add_to_buffer(buf, "\"arg\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_amd_signal_async_handler.arg); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_xor_scacq_screl(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_xor_scacq_screl.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_xor_scacq_screl.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_and_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_and_relaxed.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_and_relaxed.value); \
};

//	hsa_wavefront_t wavefront ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_wavefront_info_t attribute (enum);
#define PROCESS_ARGS_hsa_wavefront_get_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_wavefront_get_info.retval); \
	ratelprof_add_to_buffer(buf, "\"wavefront\":{\"type\":\"struct hsa_wavefront_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_wavefront_get_info.wavefront.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hsa_wavefront_info_t\",\"value\":\"%d\"},", args->hsa_wavefront_get_info.attribute); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_wavefront_get_info.value); \
};

//	size_t size (unsigned long);
//	int num_agent (int);
#define PROCESS_ARGS_hsa_amd_memory_lock(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_memory_lock.retval); \
	ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_memory_lock.host_ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_memory_lock.size); \
	ratelprof_add_to_buffer(buf, "\"agents\":{\"type\":\"hsa_agent_t *\",\"value\":\"%p\"},", args->hsa_amd_memory_lock.agents); \
	ratelprof_add_to_buffer(buf, "\"num_agent\":{\"type\":\"int\",\"value\":\"%d\"},", args->hsa_amd_memory_lock.num_agent); \
	ratelprof_add_to_buffer(buf, "\"agent_ptr\":{\"type\":\"void **\",\"value\":\"%p\"}", args->hsa_amd_memory_lock.agent_ptr); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_or_screlease(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_or_screlease.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_or_screlease.value); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_validate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_validate.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_validate.executable.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"result\":{\"type\":\"uint32_t *\",\"value\":\"%p\"}", args->hsa_executable_validate.result); \
};


#define PROCESS_ARGS_hsa_queue_destroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_queue_destroy.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"hsa_queue_t *\",\"value\":\"%p\"}", args->hsa_queue_destroy.queue); \
};

//	hsa_isa_t isa ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_isa_info_t attribute (enum);
//	uint32_t index (unsigned int);
#define PROCESS_ARGS_hsa_isa_get_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_isa_get_info.retval); \
	ratelprof_add_to_buffer(buf, "\"isa\":{\"type\":\"struct hsa_isa_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_isa_get_info.isa.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hsa_isa_info_t\",\"value\":\"%d\"},", args->hsa_isa_get_info.attribute); \
	ratelprof_add_to_buffer(buf, "\"index\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_isa_get_info.index); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_isa_get_info.value); \
};

//	size_t size (unsigned long);
//	int num_agent (int);
//	hsa_amd_memory_pool_t pool ({
//		uint64_t handle (unsigned long);
//	});
//	uint32_t flags (unsigned int);
#define PROCESS_ARGS_hsa_amd_memory_lock_to_pool(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_memory_lock_to_pool.retval); \
	ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_memory_lock_to_pool.host_ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_memory_lock_to_pool.size); \
	ratelprof_add_to_buffer(buf, "\"agents\":{\"type\":\"hsa_agent_t *\",\"value\":\"%p\"},", args->hsa_amd_memory_lock_to_pool.agents); \
	ratelprof_add_to_buffer(buf, "\"num_agent\":{\"type\":\"int\",\"value\":\"%d\"},", args->hsa_amd_memory_lock_to_pool.num_agent); \
	ratelprof_add_to_buffer(buf, "\"pool\":{\"type\":\"struct hsa_amd_memory_pool_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_lock_to_pool.pool.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_memory_lock_to_pool.flags); \
	ratelprof_add_to_buffer(buf, "\"agent_ptr\":{\"type\":\"void **\",\"value\":\"%p\"}", args->hsa_amd_memory_lock_to_pool.agent_ptr); \
};

//	uint16_t extension (unsigned short);
//	uint16_t version_major (unsigned short);
//	_Bool * result (unknown);
#define PROCESS_ARGS_hsa_system_major_extension_supported(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_system_major_extension_supported.retval); \
	ratelprof_add_to_buffer(buf, "\"extension\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_system_major_extension_supported.extension); \
	ratelprof_add_to_buffer(buf, "\"version_major\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_system_major_extension_supported.version_major); \
	ratelprof_add_to_buffer(buf, "\"version_minor\":{\"type\":\"uint16_t *\",\"value\":\"%p\"},", args->hsa_system_major_extension_supported.version_minor); \
	ratelprof_add_to_buffer(buf, "\"result\":{\"type\":\"_Bool *\",\"value\":\"N/A\"},"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_profiling_get_async_copy_time(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_profiling_get_async_copy_time.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_profiling_get_async_copy_time.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"time\":{\"type\":\"hsa_amd_profiling_async_copy_time_t *\",\"value\":\"%p\"}", args->hsa_amd_profiling_get_async_copy_time.time); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_or_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_or_relaxed.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_or_relaxed.value); \
};

//	uint64_t expected (unsigned long);
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_cas_write_index_scacquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_cas_write_index_scacquire.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_cas_write_index_scacquire.queue); \
	ratelprof_add_to_buffer(buf, "\"expected\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_cas_write_index_scacquire.expected); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_cas_write_index_scacquire.value); \
};

//	hsa_code_object_t code_object ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_code_object_info_t attribute (enum);
#define PROCESS_ARGS_hsa_code_object_get_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_code_object_get_info.retval); \
	ratelprof_add_to_buffer(buf, "\"code_object\":{\"type\":\"struct hsa_code_object_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_code_object_get_info.code_object.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hsa_code_object_info_t\",\"value\":\"%d\"},", args->hsa_code_object_get_info.attribute); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_code_object_get_info.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_and_screlease(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_and_screlease.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_and_screlease.value); \
};

//	void *(*)(size_t) alloc (function);
#define PROCESS_ARGS_hsa_amd_pointer_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_pointer_info.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hsa_amd_pointer_info.ptr); \
	ratelprof_add_to_buffer(buf, "\"info\":{\"type\":\"hsa_amd_pointer_info_t *\",\"value\":\"%p\"},", args->hsa_amd_pointer_info.info); \
	ratelprof_add_to_buffer(buf, "\"alloc\":{\"type\":\"void *(*)(size_t)\",\"value\":\"%p\"},", args->hsa_amd_pointer_info.alloc); \
	ratelprof_add_to_buffer(buf, "\"num_agents_accessible\":{\"type\":\"uint32_t *\",\"value\":\"%p\"},", args->hsa_amd_pointer_info.num_agents_accessible); \
	ratelprof_add_to_buffer(buf, "\"accessible\":{\"type\":\"hsa_agent_t **\",\"value\":\"%p\"}", args->hsa_amd_pointer_info.accessible); \
};

//	hsa_cache_t cache ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_cache_info_t attribute (enum);
#define PROCESS_ARGS_hsa_cache_get_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_cache_get_info.retval); \
	ratelprof_add_to_buffer(buf, "\"cache\":{\"type\":\"struct hsa_cache_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_cache_get_info.cache.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hsa_cache_info_t\",\"value\":\"%d\"},", args->hsa_cache_get_info.attribute); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_cache_get_info.value); \
};

//	size_t size (unsigned long);
//	size_t attribute_count (unsigned long);
#define PROCESS_ARGS_hsa_amd_svm_attributes_get(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_svm_attributes_get.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_svm_attributes_get.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_svm_attributes_get.size); \
	ratelprof_add_to_buffer(buf, "\"attribute_list\":{\"type\":\"hsa_amd_svm_attribute_pair_t *\",\"value\":\"%p\"},", args->hsa_amd_svm_attributes_get.attribute_list); \
	ratelprof_add_to_buffer(buf, "\"attribute_count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hsa_amd_svm_attributes_get.attribute_count); \
};

//	uint32_t num_signals (unsigned int);
//	uint32_t num_consumers (unsigned int);
#define PROCESS_ARGS_hsa_signal_group_create(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_signal_group_create.retval); \
	ratelprof_add_to_buffer(buf, "\"num_signals\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_signal_group_create.num_signals); \
	ratelprof_add_to_buffer(buf, "\"signals\":{\"type\":\"const hsa_signal_t *\",\"value\":\"%p\"},", args->hsa_signal_group_create.signals); \
	ratelprof_add_to_buffer(buf, "\"num_consumers\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_signal_group_create.num_consumers); \
	ratelprof_add_to_buffer(buf, "\"consumers\":{\"type\":\"const hsa_agent_t *\",\"value\":\"%p\"},", args->hsa_signal_group_create.consumers); \
	ratelprof_add_to_buffer(buf, "\"signal_group\":{\"type\":\"hsa_signal_group_t *\",\"value\":\"%p\"}", args->hsa_signal_group_create.signal_group); \
};

//	size_t size (unsigned long);
#define PROCESS_ARGS_hsa_memory_deregister(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_memory_deregister.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_memory_deregister.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hsa_memory_deregister.size); \
};

//	size_t len (unsigned long);
//	uint32_t num_agents (unsigned int);
#define PROCESS_ARGS_hsa_amd_ipc_memory_attach(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_ipc_memory_attach.retval); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"const hsa_amd_ipc_memory_t *\",\"value\":\"%p\"},", args->hsa_amd_ipc_memory_attach.handle); \
	ratelprof_add_to_buffer(buf, "\"len\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_ipc_memory_attach.len); \
	ratelprof_add_to_buffer(buf, "\"num_agents\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_ipc_memory_attach.num_agents); \
	ratelprof_add_to_buffer(buf, "\"mapping_agents\":{\"type\":\"const hsa_agent_t *\",\"value\":\"%p\"},", args->hsa_amd_ipc_memory_attach.mapping_agents); \
	ratelprof_add_to_buffer(buf, "\"mapped_ptr\":{\"type\":\"void **\",\"value\":\"%p\"}", args->hsa_amd_ipc_memory_attach.mapped_ptr); \
};

//	uint32_t num_cu_mask_count (unsigned int);
#define PROCESS_ARGS_hsa_amd_queue_cu_get_mask(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_queue_cu_get_mask.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_amd_queue_cu_get_mask.queue); \
	ratelprof_add_to_buffer(buf, "\"num_cu_mask_count\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_queue_cu_get_mask.num_cu_mask_count); \
	ratelprof_add_to_buffer(buf, "\"cu_mask\":{\"type\":\"uint32_t *\",\"value\":\"%p\"}", args->hsa_amd_queue_cu_get_mask.cu_mask); \
};

//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_add_write_index_scacq_screl(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_add_write_index_scacq_screl.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_add_write_index_scacq_screl.queue); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_add_write_index_scacq_screl.value); \
};

//	uint16_t extension (unsigned short);
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	uint16_t version_major (unsigned short);
//	_Bool * result (unknown);
#define PROCESS_ARGS_hsa_agent_major_extension_supported(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_agent_major_extension_supported.retval); \
	ratelprof_add_to_buffer(buf, "\"extension\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_agent_major_extension_supported.extension); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_agent_major_extension_supported.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"version_major\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_agent_major_extension_supported.version_major); \
	ratelprof_add_to_buffer(buf, "\"version_minor\":{\"type\":\"uint16_t *\",\"value\":\"%p\"},", args->hsa_agent_major_extension_supported.version_minor); \
	ratelprof_add_to_buffer(buf, "\"result\":{\"type\":\"_Bool *\",\"value\":\"N/A\"},"); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_ext_sampler_t sampler ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_ext_sampler_destroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_ext_sampler_destroy.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_sampler_destroy.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sampler\":{\"type\":\"struct hsa_ext_sampler_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_sampler_destroy.sampler.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	uint32_t size (unsigned int);
//	hsa_queue_type32_t type (unsigned int);
//	void (*)(hsa_status_t, hsa_queue_t *, void *) callback (function);
//	uint32_t private_segment_size (unsigned int);
//	uint32_t group_segment_size (unsigned int);
#define PROCESS_ARGS_hsa_queue_create(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_queue_create.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_create.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_queue_create.size); \
	ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hsa_queue_type32_t\",\"value\":\"%u\"},", args->hsa_queue_create.type); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"void (*)(hsa_status_t, hsa_queue_t *, void *)\",\"value\":\"%p\"},", args->hsa_queue_create.callback); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_queue_create.data); \
	ratelprof_add_to_buffer(buf, "\"private_segment_size\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_queue_create.private_segment_size); \
	ratelprof_add_to_buffer(buf, "\"group_segment_size\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_queue_create.group_segment_size); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"hsa_queue_t **\",\"value\":\"%p\"}", args->hsa_queue_create.queue); \
};

//	hsa_amd_vmem_alloc_handle_t memory_handle ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_vmem_get_alloc_properties_from_handle(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_vmem_get_alloc_properties_from_handle.retval); \
	ratelprof_add_to_buffer(buf, "\"memory_handle\":{\"type\":\"struct hsa_amd_vmem_alloc_handle_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_vmem_get_alloc_properties_from_handle.memory_handle.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"pool\":{\"type\":\"hsa_amd_memory_pool_t *\",\"value\":\"%p\"},", args->hsa_amd_vmem_get_alloc_properties_from_handle.pool); \
	ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hsa_amd_memory_type_t *\",\"value\":\"%p\"}", args->hsa_amd_vmem_get_alloc_properties_from_handle.type); \
};

//	hsa_amd_memory_pool_t memory_pool ({
//		uint64_t handle (unsigned long);
//	});
//	size_t size (unsigned long);
//	uint32_t flags (unsigned int);
#define PROCESS_ARGS_hsa_amd_memory_pool_allocate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_memory_pool_allocate.retval); \
	ratelprof_add_to_buffer(buf, "\"memory_pool\":{\"type\":\"struct hsa_amd_memory_pool_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_pool_allocate.memory_pool.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_memory_pool_allocate.size); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_memory_pool_allocate.flags); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":\"%p\"}", args->hsa_amd_memory_pool_allocate.ptr); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_or_release(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_or_release.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_or_release.value); \
};

//	uint64_t expected (unsigned long);
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_cas_write_index_acq_rel(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_cas_write_index_acq_rel.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_cas_write_index_acq_rel.queue); \
	ratelprof_add_to_buffer(buf, "\"expected\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_cas_write_index_acq_rel.expected); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_cas_write_index_acq_rel.value); \
};

//	hsa_code_object_t code_object ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(size_t, hsa_callback_data_t, void **) alloc_callback (function);
//	hsa_callback_data_t callback_data ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_code_object_serialize(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_code_object_serialize.retval); \
	ratelprof_add_to_buffer(buf, "\"code_object\":{\"type\":\"struct hsa_code_object_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_code_object_serialize.code_object.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"alloc_callback\":{\"type\":\"hsa_status_t (*)(size_t, hsa_callback_data_t, void **)\",\"value\":\"%p\"},", args->hsa_code_object_serialize.alloc_callback); \
	ratelprof_add_to_buffer(buf, "\"callback_data\":{\"type\":\"struct hsa_callback_data_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_code_object_serialize.callback_data.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"options\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_code_object_serialize.options); \
	ratelprof_add_to_buffer(buf, "\"serialized_code_object\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hsa_code_object_serialize.serialized_code_object); \
	ratelprof_add_to_buffer(buf, "\"serialized_code_object_size\":{\"type\":\"size_t *\",\"value\":\"%p\"}", args->hsa_code_object_serialize.serialized_code_object_size); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_xor_acquire(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_xor_acquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_xor_acquire.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	uint64_t agent_tick (unsigned long);
#define PROCESS_ARGS_hsa_amd_profiling_convert_tick_to_system_domain(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_profiling_convert_tick_to_system_domain.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_profiling_convert_tick_to_system_domain.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"agent_tick\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_amd_profiling_convert_tick_to_system_domain.agent_tick); \
	ratelprof_add_to_buffer(buf, "\"system_tick\":{\"type\":\"uint64_t *\",\"value\":\"%p\"}", args->hsa_amd_profiling_convert_tick_to_system_domain.system_tick); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_destroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_destroy.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_destroy.executable.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_add_screlease(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_add_screlease.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_add_screlease.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_signal_load_acquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_load_acquire.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_load_acquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hsa_profile_t profile (enum);
//	hsa_default_float_rounding_mode_t default_float_rounding_mode (enum);
#define PROCESS_ARGS_hsa_executable_create_alt(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_create_alt.retval); \
	ratelprof_add_to_buffer(buf, "\"profile\":{\"type\":\"hsa_profile_t\",\"value\":\"%d\"},", args->hsa_executable_create_alt.profile); \
	ratelprof_add_to_buffer(buf, "\"default_float_rounding_mode\":{\"type\":\"hsa_default_float_rounding_mode_t\",\"value\":\"%d\"},", args->hsa_executable_create_alt.default_float_rounding_mode); \
	ratelprof_add_to_buffer(buf, "\"options\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_executable_create_alt.options); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"hsa_executable_t *\",\"value\":\"%p\"}", args->hsa_executable_create_alt.executable); \
};

//	hsa_agent_t copy_agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_copy_direction_t dir (enum);
//	uint32_t num_dep_signals (unsigned int);
//	hsa_signal_t completion_signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_memory_async_copy_rect(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_memory_async_copy_rect.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"const hsa_pitched_ptr_t *\",\"value\":\"%p\"},", args->hsa_amd_memory_async_copy_rect.dst); \
	ratelprof_add_to_buffer(buf, "\"dst_offset\":{\"type\":\"const hsa_dim3_t *\",\"value\":\"%p\"},", args->hsa_amd_memory_async_copy_rect.dst_offset); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const hsa_pitched_ptr_t *\",\"value\":\"%p\"},", args->hsa_amd_memory_async_copy_rect.src); \
	ratelprof_add_to_buffer(buf, "\"src_offset\":{\"type\":\"const hsa_dim3_t *\",\"value\":\"%p\"},", args->hsa_amd_memory_async_copy_rect.src_offset); \
	ratelprof_add_to_buffer(buf, "\"range\":{\"type\":\"const hsa_dim3_t *\",\"value\":\"%p\"},", args->hsa_amd_memory_async_copy_rect.range); \
	ratelprof_add_to_buffer(buf, "\"copy_agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_async_copy_rect.copy_agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dir\":{\"type\":\"hsa_amd_copy_direction_t\",\"value\":\"%d\"},", args->hsa_amd_memory_async_copy_rect.dir); \
	ratelprof_add_to_buffer(buf, "\"num_dep_signals\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_memory_async_copy_rect.num_dep_signals); \
	ratelprof_add_to_buffer(buf, "\"dep_signals\":{\"type\":\"const hsa_signal_t *\",\"value\":\"%p\"},", args->hsa_amd_memory_async_copy_rect.dep_signals); \
	ratelprof_add_to_buffer(buf, "\"completion_signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_async_copy_rect.completion_signal.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_signal_load_scacquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_load_scacquire.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_load_scacquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_cache_t, void *) callback (function);
#define PROCESS_ARGS_hsa_agent_iterate_caches(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_agent_iterate_caches.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_agent_iterate_caches.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"hsa_status_t (*)(hsa_cache_t, void *)\",\"value\":\"%p\"},", args->hsa_agent_iterate_caches.callback); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_agent_iterate_caches.data); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t expected (long);
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_cas_acq_rel(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_cas_acq_rel.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_cas_acq_rel.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"expected\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_cas_acq_rel.expected); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_cas_acq_rel.value); \
};


#define PROCESS_ARGS_hsa_queue_load_read_index_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_load_read_index_relaxed.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"}", args->hsa_queue_load_read_index_relaxed.queue); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_isa_t, void *) callback (function);
#define PROCESS_ARGS_hsa_agent_iterate_isas(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_agent_iterate_isas.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_agent_iterate_isas.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"hsa_status_t (*)(hsa_isa_t, void *)\",\"value\":\"%p\"},", args->hsa_agent_iterate_isas.callback); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_agent_iterate_isas.data); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_xor_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_xor_relaxed.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_xor_relaxed.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_subtract_acq_rel(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_subtract_acq_rel.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_subtract_acq_rel.value); \
};


#define PROCESS_ARGS_hsa_queue_load_read_index_acquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_load_read_index_acquire.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"}", args->hsa_queue_load_read_index_acquire.queue); \
};

//	hsa_isa_t isa ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_isa_info_t attribute (enum);
#define PROCESS_ARGS_hsa_isa_get_info_alt(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_isa_get_info_alt.retval); \
	ratelprof_add_to_buffer(buf, "\"isa\":{\"type\":\"struct hsa_isa_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_isa_get_info_alt.isa.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hsa_isa_info_t\",\"value\":\"%d\"},", args->hsa_isa_get_info_alt.attribute); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_isa_get_info_alt.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_and_scacquire(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_and_scacquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_and_scacquire.value); \
};

//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_add_write_index_release(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_add_write_index_release.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_add_write_index_release.queue); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_add_write_index_release.value); \
};

//	hsa_system_info_t attribute (enum);
#define PROCESS_ARGS_hsa_system_get_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_system_get_info.retval); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hsa_system_info_t\",\"value\":\"%d\"},", args->hsa_system_get_info.attribute); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_system_get_info.value); \
};

//	size_t size (unsigned long);
#define PROCESS_ARGS_hsa_memory_register(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_memory_register.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_memory_register.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hsa_memory_register.size); \
};

//	hsa_isa_t isa ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_fp_type_t fp_type (enum);
//	hsa_flush_mode_t flush_mode (enum);
#define PROCESS_ARGS_hsa_isa_get_round_method(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_isa_get_round_method.retval); \
	ratelprof_add_to_buffer(buf, "\"isa\":{\"type\":\"struct hsa_isa_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_isa_get_round_method.isa.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"fp_type\":{\"type\":\"hsa_fp_type_t\",\"value\":\"%d\"},", args->hsa_isa_get_round_method.fp_type); \
	ratelprof_add_to_buffer(buf, "\"flush_mode\":{\"type\":\"hsa_flush_mode_t\",\"value\":\"%d\"},", args->hsa_isa_get_round_method.flush_mode); \
	ratelprof_add_to_buffer(buf, "\"round_method\":{\"type\":\"hsa_round_method_t *\",\"value\":\"%p\"}", args->hsa_isa_get_round_method.round_method); \
};

//	hsa_isa_t isa ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_wavefront_t, void *) callback (function);
#define PROCESS_ARGS_hsa_isa_iterate_wavefronts(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_isa_iterate_wavefronts.retval); \
	ratelprof_add_to_buffer(buf, "\"isa\":{\"type\":\"struct hsa_isa_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_isa_iterate_wavefronts.isa.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"hsa_status_t (*)(hsa_wavefront_t, void *)\",\"value\":\"%p\"},", args->hsa_isa_iterate_wavefronts.callback); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_isa_iterate_wavefronts.data); \
};

//	size_t size (unsigned long);
#define PROCESS_ARGS_hsa_amd_vmem_unmap(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_vmem_unmap.retval); \
	ratelprof_add_to_buffer(buf, "\"va\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_vmem_unmap.va); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hsa_amd_vmem_unmap.size); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_subtract_acquire(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_subtract_acquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_subtract_acquire.value); \
};

//	uint16_t extension (unsigned short);
//	uint16_t version_major (unsigned short);
//	size_t table_length (unsigned long);
#define PROCESS_ARGS_hsa_system_get_major_extension_table(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_system_get_major_extension_table.retval); \
	ratelprof_add_to_buffer(buf, "\"extension\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_system_get_major_extension_table.extension); \
	ratelprof_add_to_buffer(buf, "\"version_major\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_system_get_major_extension_table.version_major); \
	ratelprof_add_to_buffer(buf, "\"table_length\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_system_get_major_extension_table.table_length); \
	ratelprof_add_to_buffer(buf, "\"table\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_system_get_major_extension_table.table); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_store_release(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_store_release.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_store_release.value); \
};


#define PROCESS_ARGS_hsa_queue_load_write_index_scacquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_load_write_index_scacquire.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"}", args->hsa_queue_load_write_index_scacquire.queue); \
};

//	hsa_agent_t preferred_agent ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_spm_release(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_spm_release.retval); \
	ratelprof_add_to_buffer(buf, "\"preferred_agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_spm_release.preferred_agent.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hsa_code_symbol_t code_symbol ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_code_symbol_info_t attribute (enum);
#define PROCESS_ARGS_hsa_code_symbol_get_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_code_symbol_get_info.retval); \
	ratelprof_add_to_buffer(buf, "\"code_symbol\":{\"type\":\"struct hsa_code_symbol_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_code_symbol_get_info.code_symbol.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hsa_code_symbol_info_t\",\"value\":\"%d\"},", args->hsa_code_symbol_get_info.attribute); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_code_symbol_get_info.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_condition_t condition (enum);
//	hsa_signal_value_t compare_value (long);
//	uint64_t timeout_hint (unsigned long);
//	hsa_wait_state_t wait_state_hint (enum);
#define PROCESS_ARGS_hsa_signal_wait_acquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_wait_acquire.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_wait_acquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"condition\":{\"type\":\"hsa_signal_condition_t\",\"value\":\"%d\"},", args->hsa_signal_wait_acquire.condition); \
	ratelprof_add_to_buffer(buf, "\"compare_value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_wait_acquire.compare_value); \
	ratelprof_add_to_buffer(buf, "\"timeout_hint\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_signal_wait_acquire.timeout_hint); \
	ratelprof_add_to_buffer(buf, "\"wait_state_hint\":{\"type\":\"hsa_wait_state_t\",\"value\":\"%d\"}", args->hsa_signal_wait_acquire.wait_state_hint); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t expected (long);
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_cas_release(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_cas_release.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_cas_release.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"expected\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_cas_release.expected); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_cas_release.value); \
};

//	hsa_amd_memory_pool_t memory_pool ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_memory_pool_info_t attribute (enum);
#define PROCESS_ARGS_hsa_amd_memory_pool_get_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_memory_pool_get_info.retval); \
	ratelprof_add_to_buffer(buf, "\"memory_pool\":{\"type\":\"struct hsa_amd_memory_pool_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_pool_get_info.memory_pool.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hsa_amd_memory_pool_info_t\",\"value\":\"%d\"},", args->hsa_amd_memory_pool_get_info.attribute); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_amd_memory_pool_get_info.value); \
};


#define PROCESS_ARGS_hsa_amd_pointer_info_set_userdata(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_pointer_info_set_userdata.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hsa_amd_pointer_info_set_userdata.ptr); \
	ratelprof_add_to_buffer(buf, "\"userdata\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_amd_pointer_info_set_userdata.userdata); \
};

//	hsa_agent_t agent_handle ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_vmem_get_access(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_vmem_get_access.retval); \
	ratelprof_add_to_buffer(buf, "\"va\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_vmem_get_access.va); \
	ratelprof_add_to_buffer(buf, "\"perms\":{\"type\":\"hsa_access_permission_t *\",\"value\":\"%p\"},", args->hsa_amd_vmem_get_access.perms); \
	ratelprof_add_to_buffer(buf, "\"agent_handle\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_vmem_get_access.agent_handle.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hsa_status_t (*)(hsa_agent_t, void *) callback (function);
#define PROCESS_ARGS_hsa_iterate_agents(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_iterate_agents.retval); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"hsa_status_t (*)(hsa_agent_t, void *)\",\"value\":\"%p\"},", args->hsa_iterate_agents.callback); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_iterate_agents.data); \
};

//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_store_write_index_screlease(args) { \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_store_write_index_screlease.queue); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_store_write_index_screlease.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_region_t, void *) callback (function);
#define PROCESS_ARGS_hsa_agent_iterate_regions(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_agent_iterate_regions.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_agent_iterate_regions.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"hsa_status_t (*)(hsa_region_t, void *)\",\"value\":\"%p\"},", args->hsa_agent_iterate_regions.callback); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_agent_iterate_regions.data); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_readonly_variable_define(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_readonly_variable_define.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_readonly_variable_define.executable.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_readonly_variable_define.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"variable_name\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_executable_readonly_variable_define.variable_name); \
	ratelprof_add_to_buffer(buf, "\"address\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_executable_readonly_variable_define.address); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_executable_t, hsa_executable_symbol_t, void *) callback (function);
#define PROCESS_ARGS_hsa_executable_iterate_symbols(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_iterate_symbols.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_iterate_symbols.executable.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"hsa_status_t (*)(hsa_executable_t, hsa_executable_symbol_t, void *)\",\"value\":\"%p\"},", args->hsa_executable_iterate_symbols.callback); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_executable_iterate_symbols.data); \
};

//	hsa_amd_vmem_alloc_handle_t memory_handle ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_vmem_handle_release(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_vmem_handle_release.retval); \
	ratelprof_add_to_buffer(buf, "\"memory_handle\":{\"type\":\"struct hsa_amd_vmem_alloc_handle_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_vmem_handle_release.memory_handle.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hsa_amd_memory_pool_t src_memory_pool ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_memory_pool_t dst_memory_pool ({
//		uint64_t handle (unsigned long);
//	});
//	_Bool * result (unknown);
#define PROCESS_ARGS_hsa_amd_memory_pool_can_migrate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_memory_pool_can_migrate.retval); \
	ratelprof_add_to_buffer(buf, "\"src_memory_pool\":{\"type\":\"struct hsa_amd_memory_pool_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_pool_can_migrate.src_memory_pool.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dst_memory_pool\":{\"type\":\"struct hsa_amd_memory_pool_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_pool_can_migrate.dst_memory_pool.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"result\":{\"type\":\"_Bool *\",\"value\":\"N/A\"},"); \
};

//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_store_write_index_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_store_write_index_relaxed.queue); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_store_write_index_relaxed.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_info_t attribute (enum);
#define PROCESS_ARGS_hsa_amd_image_get_info_max_dim(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_image_get_info_max_dim.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_image_get_info_max_dim.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hsa_agent_info_t\",\"value\":\"%d\"},", args->hsa_amd_image_get_info_max_dim.attribute); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_amd_image_get_info_max_dim.value); \
};

//	hsa_agent_t preferred_agent ({
//		uint64_t handle (unsigned long);
//	});
//	size_t size_in_bytes (unsigned long);
//	_Bool * is_data_loss (unknown);
#define PROCESS_ARGS_hsa_amd_spm_set_dest_buffer(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_spm_set_dest_buffer.retval); \
	ratelprof_add_to_buffer(buf, "\"preferred_agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_spm_set_dest_buffer.preferred_agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size_in_bytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_spm_set_dest_buffer.size_in_bytes); \
	ratelprof_add_to_buffer(buf, "\"timeout\":{\"type\":\"uint32_t *\",\"value\":\"%p\"},", args->hsa_amd_spm_set_dest_buffer.timeout); \
	ratelprof_add_to_buffer(buf, "\"size_copied\":{\"type\":\"uint32_t *\",\"value\":\"%p\"},", args->hsa_amd_spm_set_dest_buffer.size_copied); \
	ratelprof_add_to_buffer(buf, "\"dest\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_spm_set_dest_buffer.dest); \
	ratelprof_add_to_buffer(buf, "\"is_data_loss\":{\"type\":\"_Bool *\",\"value\":\"N/A\"},"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_condition_t condition (enum);
//	hsa_signal_value_t compare_value (long);
//	uint64_t timeout_hint (unsigned long);
//	hsa_wait_state_t wait_state_hint (enum);
#define PROCESS_ARGS_hsa_signal_wait_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_wait_relaxed.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_wait_relaxed.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"condition\":{\"type\":\"hsa_signal_condition_t\",\"value\":\"%d\"},", args->hsa_signal_wait_relaxed.condition); \
	ratelprof_add_to_buffer(buf, "\"compare_value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_wait_relaxed.compare_value); \
	ratelprof_add_to_buffer(buf, "\"timeout_hint\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_signal_wait_relaxed.timeout_hint); \
	ratelprof_add_to_buffer(buf, "\"wait_state_hint\":{\"type\":\"hsa_wait_state_t\",\"value\":\"%d\"}", args->hsa_signal_wait_relaxed.wait_state_hint); \
};

//	size_t size (unsigned long);
#define PROCESS_ARGS_hsa_amd_portable_export_dmabuf(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_portable_export_dmabuf.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hsa_amd_portable_export_dmabuf.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_portable_export_dmabuf.size); \
	ratelprof_add_to_buffer(buf, "\"dmabuf\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hsa_amd_portable_export_dmabuf.dmabuf); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"uint64_t *\",\"value\":\"%p\"}", args->hsa_amd_portable_export_dmabuf.offset); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_store_screlease(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_store_screlease.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_store_screlease.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_or_acquire(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_or_acquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_or_acquire.value); \
};

//	hsa_code_object_t code_object ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_code_object_destroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_code_object_destroy.retval); \
	ratelprof_add_to_buffer(buf, "\"code_object\":{\"type\":\"struct hsa_code_object_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_code_object_destroy.code_object.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_subtract_screlease(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_subtract_screlease.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_subtract_screlease.value); \
};

//	hsa_region_t region ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_region_info_t attribute (enum);
#define PROCESS_ARGS_hsa_region_get_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_region_get_info.retval); \
	ratelprof_add_to_buffer(buf, "\"region\":{\"type\":\"struct hsa_region_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_region_get_info.region.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hsa_region_info_t\",\"value\":\"%d\"},", args->hsa_region_get_info.attribute); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_region_get_info.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_subtract_scacq_screl(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_subtract_scacq_screl.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_subtract_scacq_screl.value); \
};

//	_Bool enable (unknown);
#define PROCESS_ARGS_hsa_amd_profiling_async_copy_enable(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_profiling_async_copy_enable.retval); \
	ratelprof_add_to_buffer(buf, "\"enable\":{\"type\":\"_Bool\",\"value\":\"N/A\"},"); \
};

//	hsa_region_t region ({
//		uint64_t handle (unsigned long);
//	});
//	uint32_t size (unsigned int);
//	hsa_queue_type32_t type (unsigned int);
//	uint32_t features (unsigned int);
//	hsa_signal_t doorbell_signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_soft_queue_create(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_soft_queue_create.retval); \
	ratelprof_add_to_buffer(buf, "\"region\":{\"type\":\"struct hsa_region_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_soft_queue_create.region.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_soft_queue_create.size); \
	ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hsa_queue_type32_t\",\"value\":\"%u\"},", args->hsa_soft_queue_create.type); \
	ratelprof_add_to_buffer(buf, "\"features\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_soft_queue_create.features); \
	ratelprof_add_to_buffer(buf, "\"doorbell_signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_soft_queue_create.doorbell_signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"hsa_queue_t **\",\"value\":\"%p\"}", args->hsa_soft_queue_create.queue); \
};


#define PROCESS_ARGS_hsa_shut_down(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_shut_down.retval); \
\
};

//	hsa_code_object_t code_object ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_code_object_t, hsa_code_symbol_t, void *) callback (function);
#define PROCESS_ARGS_hsa_code_object_iterate_symbols(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_code_object_iterate_symbols.retval); \
	ratelprof_add_to_buffer(buf, "\"code_object\":{\"type\":\"struct hsa_code_object_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_code_object_iterate_symbols.code_object.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"hsa_status_t (*)(hsa_code_object_t, hsa_code_symbol_t, void *)\",\"value\":\"%p\"},", args->hsa_code_object_iterate_symbols.callback); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_code_object_iterate_symbols.data); \
};

//	uint16_t extension (unsigned short);
#define PROCESS_ARGS_hsa_extension_get_name(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_extension_get_name.retval); \
	ratelprof_add_to_buffer(buf, "\"extension\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_extension_get_name.extension); \
	ratelprof_add_to_buffer(buf, "\"name\":{\"type\":\"const char **\",\"value\":\"%p\"}", args->hsa_extension_get_name.name); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_exchange_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_exchange_relaxed.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_exchange_relaxed.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_exchange_relaxed.value); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_get_symbol_by_name(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_get_symbol_by_name.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_get_symbol_by_name.executable.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"symbol_name\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_executable_get_symbol_by_name.symbol_name); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"const hsa_agent_t *\",\"value\":\"%p\"},", args->hsa_executable_get_symbol_by_name.agent); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"hsa_executable_symbol_t *\",\"value\":\"%p\"}", args->hsa_executable_get_symbol_by_name.symbol); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_access_permission_t access_permission (enum);
//	hsa_ext_image_data_layout_t image_data_layout (enum);
//	size_t image_data_row_pitch (unsigned long);
//	size_t image_data_slice_pitch (unsigned long);
#define PROCESS_ARGS_hsa_ext_image_create_with_layout(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_ext_image_create_with_layout.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_create_with_layout.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"image_descriptor\":{\"type\":\"const hsa_ext_image_descriptor_t *\",\"value\":\"%p\"},", args->hsa_ext_image_create_with_layout.image_descriptor); \
	ratelprof_add_to_buffer(buf, "\"image_data\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hsa_ext_image_create_with_layout.image_data); \
	ratelprof_add_to_buffer(buf, "\"access_permission\":{\"type\":\"hsa_access_permission_t\",\"value\":\"%d\"},", args->hsa_ext_image_create_with_layout.access_permission); \
	ratelprof_add_to_buffer(buf, "\"image_data_layout\":{\"type\":\"hsa_ext_image_data_layout_t\",\"value\":\"%d\"},", args->hsa_ext_image_create_with_layout.image_data_layout); \
	ratelprof_add_to_buffer(buf, "\"image_data_row_pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_ext_image_create_with_layout.image_data_row_pitch); \
	ratelprof_add_to_buffer(buf, "\"image_data_slice_pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_ext_image_create_with_layout.image_data_slice_pitch); \
	ratelprof_add_to_buffer(buf, "\"image\":{\"type\":\"hsa_ext_image_t *\",\"value\":\"%p\"}", args->hsa_ext_image_create_with_layout.image); \
};


#define PROCESS_ARGS_hsa_queue_load_write_index_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_load_write_index_relaxed.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"}", args->hsa_queue_load_write_index_relaxed.queue); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_ext_image_t src_image ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_ext_image_t dst_image ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_ext_image_copy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_ext_image_copy.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_copy.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src_image\":{\"type\":\"struct hsa_ext_image_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_copy.src_image.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src_offset\":{\"type\":\"const hsa_dim3_t *\",\"value\":\"%p\"},", args->hsa_ext_image_copy.src_offset); \
	ratelprof_add_to_buffer(buf, "\"dst_image\":{\"type\":\"struct hsa_ext_image_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_copy.dst_image.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dst_offset\":{\"type\":\"const hsa_dim3_t *\",\"value\":\"%p\"},", args->hsa_ext_image_copy.dst_offset); \
	ratelprof_add_to_buffer(buf, "\"range\":{\"type\":\"const hsa_dim3_t *\",\"value\":\"%p\"}", args->hsa_ext_image_copy.range); \
};

//	size_t size (unsigned long);
#define PROCESS_ARGS_hsa_code_object_reader_create_from_memory(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_code_object_reader_create_from_memory.retval); \
	ratelprof_add_to_buffer(buf, "\"code_object\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hsa_code_object_reader_create_from_memory.code_object); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_code_object_reader_create_from_memory.size); \
	ratelprof_add_to_buffer(buf, "\"code_object_reader\":{\"type\":\"hsa_code_object_reader_t *\",\"value\":\"%p\"}", args->hsa_code_object_reader_create_from_memory.code_object_reader); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_xor_release(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_xor_release.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_xor_release.value); \
};

//	hsa_amd_deallocation_callback_t callback (function);
#define PROCESS_ARGS_hsa_amd_register_deallocation_callback(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_register_deallocation_callback.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_register_deallocation_callback.ptr); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"hsa_amd_deallocation_callback_t\",\"value\":\"%p\"},", args->hsa_amd_register_deallocation_callback.callback); \
	ratelprof_add_to_buffer(buf, "\"user_data\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_amd_register_deallocation_callback.user_data); \
};

//	hsa_signal_group_t signal_group ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_signal_group_destroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_signal_group_destroy.retval); \
	ratelprof_add_to_buffer(buf, "\"signal_group\":{\"type\":\"struct hsa_signal_group_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_group_destroy.signal_group.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hsa_amd_vmem_alloc_handle_t handle ({
//		uint64_t handle (unsigned long);
//	});
//	uint64_t flags (unsigned long);
#define PROCESS_ARGS_hsa_amd_vmem_export_shareable_handle(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_vmem_export_shareable_handle.retval); \
	ratelprof_add_to_buffer(buf, "\"dmabuf_fd\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hsa_amd_vmem_export_shareable_handle.dmabuf_fd); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"struct hsa_amd_vmem_alloc_handle_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_vmem_export_shareable_handle.handle.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_vmem_export_shareable_handle.flags); \
};

//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_add_write_index_acq_rel(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_add_write_index_acq_rel.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_add_write_index_acq_rel.queue); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_add_write_index_acq_rel.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_signal_destroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_signal_destroy.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_destroy.signal.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	uint16_t extension (unsigned short);
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	uint16_t version_major (unsigned short);
//	uint16_t version_minor (unsigned short);
//	_Bool * result (unknown);
#define PROCESS_ARGS_hsa_agent_extension_supported(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_agent_extension_supported.retval); \
	ratelprof_add_to_buffer(buf, "\"extension\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_agent_extension_supported.extension); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_agent_extension_supported.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"version_major\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_agent_extension_supported.version_major); \
	ratelprof_add_to_buffer(buf, "\"version_minor\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_agent_extension_supported.version_minor); \
	ratelprof_add_to_buffer(buf, "\"result\":{\"type\":\"_Bool *\",\"value\":\"N/A\"},"); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_access_permission_t access_permission (enum);
#define PROCESS_ARGS_hsa_amd_image_create(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_image_create.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_image_create.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"image_descriptor\":{\"type\":\"const hsa_ext_image_descriptor_t *\",\"value\":\"%p\"},", args->hsa_amd_image_create.image_descriptor); \
	ratelprof_add_to_buffer(buf, "\"image_layout\":{\"type\":\"const hsa_amd_image_descriptor_t *\",\"value\":\"%p\"},", args->hsa_amd_image_create.image_layout); \
	ratelprof_add_to_buffer(buf, "\"image_data\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hsa_amd_image_create.image_data); \
	ratelprof_add_to_buffer(buf, "\"access_permission\":{\"type\":\"hsa_access_permission_t\",\"value\":\"%d\"},", args->hsa_amd_image_create.access_permission); \
	ratelprof_add_to_buffer(buf, "\"image\":{\"type\":\"hsa_ext_image_t *\",\"value\":\"%p\"}", args->hsa_amd_image_create.image); \
};

//	hsa_isa_t code_object_isa ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_isa_t agent_isa ({
//		uint64_t handle (unsigned long);
//	});
//	_Bool * result (unknown);
#define PROCESS_ARGS_hsa_isa_compatible(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_isa_compatible.retval); \
	ratelprof_add_to_buffer(buf, "\"code_object_isa\":{\"type\":\"struct hsa_isa_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_isa_compatible.code_object_isa.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"agent_isa\":{\"type\":\"struct hsa_isa_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_isa_compatible.agent_isa.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"result\":{\"type\":\"_Bool *\",\"value\":\"N/A\"},"); \
};

//	hsa_amd_queue_priority_t priority (enum);
#define PROCESS_ARGS_hsa_amd_queue_set_priority(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_queue_set_priority.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_amd_queue_set_priority.queue); \
	ratelprof_add_to_buffer(buf, "\"priority\":{\"type\":\"hsa_amd_queue_priority_t\",\"value\":\"%d\"}", args->hsa_amd_queue_set_priority.priority); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_and_acq_rel(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_and_acq_rel.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_and_acq_rel.value); \
};

//	hsa_code_object_reader_t code_object_reader ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_code_object_reader_destroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_code_object_reader_destroy.retval); \
	ratelprof_add_to_buffer(buf, "\"code_object_reader\":{\"type\":\"struct hsa_code_object_reader_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_code_object_reader_destroy.code_object_reader.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	uint64_t expected (unsigned long);
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_cas_write_index_release(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_cas_write_index_release.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_cas_write_index_release.queue); \
	ratelprof_add_to_buffer(buf, "\"expected\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_cas_write_index_release.expected); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_cas_write_index_release.value); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_code_object_t code_object ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_load_code_object(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_load_code_object.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_load_code_object.executable.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_load_code_object.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"code_object\":{\"type\":\"struct hsa_code_object_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_load_code_object.code_object.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"options\":{\"type\":\"const char *\",\"value\":\"%p\"}", args->hsa_executable_load_code_object.options); \
};

//	hsa_agent_t dst_agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_t src_agent ({
//		uint64_t handle (unsigned long);
//	});
//	size_t size (unsigned long);
//	uint32_t num_dep_signals (unsigned int);
//	hsa_signal_t completion_signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_memory_async_copy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_memory_async_copy.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_memory_async_copy.dst); \
	ratelprof_add_to_buffer(buf, "\"dst_agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_async_copy.dst_agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hsa_amd_memory_async_copy.src); \
	ratelprof_add_to_buffer(buf, "\"src_agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_async_copy.src_agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_memory_async_copy.size); \
	ratelprof_add_to_buffer(buf, "\"num_dep_signals\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_memory_async_copy.num_dep_signals); \
	ratelprof_add_to_buffer(buf, "\"dep_signals\":{\"type\":\"const hsa_signal_t *\",\"value\":\"%p\"},", args->hsa_amd_memory_async_copy.dep_signals); \
	ratelprof_add_to_buffer(buf, "\"completion_signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_async_copy.completion_signal.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};


#define PROCESS_ARGS_hsa_amd_memory_unlock(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_memory_unlock.retval); \
	ratelprof_add_to_buffer(buf, "\"host_ptr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_amd_memory_unlock.host_ptr); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_subtract_release(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_subtract_release.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_subtract_release.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_exchange_acquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_exchange_acquire.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_exchange_acquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_exchange_acquire.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_store_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_store_relaxed.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_store_relaxed.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_subtract_scacquire(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_subtract_scacquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_subtract_scacquire.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_and_release(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_and_release.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_and_release.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t expected (long);
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_cas_acquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_cas_acquire.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_cas_acquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"expected\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_cas_acquire.expected); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_cas_acquire.value); \
};

//	hsa_isa_t isa ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_profile_t profile (enum);
#define PROCESS_ARGS_hsa_isa_get_exception_policies(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_isa_get_exception_policies.retval); \
	ratelprof_add_to_buffer(buf, "\"isa\":{\"type\":\"struct hsa_isa_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_isa_get_exception_policies.isa.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"profile\":{\"type\":\"hsa_profile_t\",\"value\":\"%d\"},", args->hsa_isa_get_exception_policies.profile); \
	ratelprof_add_to_buffer(buf, "\"mask\":{\"type\":\"uint16_t *\",\"value\":\"%p\"}", args->hsa_isa_get_exception_policies.mask); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_add_release(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_add_release.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_add_release.value); \
};

//	hsa_file_t file (int);
#define PROCESS_ARGS_hsa_code_object_reader_create_from_file(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_code_object_reader_create_from_file.retval); \
	ratelprof_add_to_buffer(buf, "\"file\":{\"type\":\"hsa_file_t\",\"value\":\"%d\"},", args->hsa_code_object_reader_create_from_file.file); \
	ratelprof_add_to_buffer(buf, "\"code_object_reader\":{\"type\":\"hsa_code_object_reader_t *\",\"value\":\"%p\"}", args->hsa_code_object_reader_create_from_file.code_object_reader); \
};

//	hsa_executable_symbol_t executable_symbol ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_executable_symbol_info_t attribute (enum);
#define PROCESS_ARGS_hsa_executable_symbol_get_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_symbol_get_info.retval); \
	ratelprof_add_to_buffer(buf, "\"executable_symbol\":{\"type\":\"struct hsa_executable_symbol_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_symbol_get_info.executable_symbol.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hsa_executable_symbol_info_t\",\"value\":\"%d\"},", args->hsa_executable_symbol_get_info.attribute); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_executable_symbol_get_info.value); \
};

//	size_t len (unsigned long);
#define PROCESS_ARGS_hsa_amd_ipc_memory_create(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_ipc_memory_create.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_ipc_memory_create.ptr); \
	ratelprof_add_to_buffer(buf, "\"len\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_ipc_memory_create.len); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hsa_amd_ipc_memory_t *\",\"value\":\"%p\"}", args->hsa_amd_ipc_memory_create.handle); \
};

//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_store_write_index_release(args) { \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_store_write_index_release.queue); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_store_write_index_release.value); \
};

//	uint32_t value (unsigned int);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hsa_amd_memory_fill(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_memory_fill.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_memory_fill.ptr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_memory_fill.value); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_fill.count); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_add_acq_rel(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_add_acq_rel.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_add_acq_rel.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t expected (long);
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_cas_scacq_screl(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_cas_scacq_screl.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_cas_scacq_screl.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"expected\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_cas_scacq_screl.expected); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_cas_scacq_screl.value); \
};

//	uint64_t expected (unsigned long);
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_cas_write_index_scacq_screl(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_cas_write_index_scacq_screl.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_cas_write_index_scacq_screl.queue); \
	ratelprof_add_to_buffer(buf, "\"expected\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_cas_write_index_scacq_screl.expected); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_cas_write_index_scacq_screl.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_ipc_signal_create(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_ipc_signal_create.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_ipc_signal_create.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hsa_amd_ipc_signal_t *\",\"value\":\"%p\"}", args->hsa_amd_ipc_signal_create.handle); \
};

//	hsa_agent_t preferred_agent ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_spm_acquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_spm_acquire.retval); \
	ratelprof_add_to_buffer(buf, "\"preferred_agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_spm_acquire.preferred_agent.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_coherency_get_type(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_coherency_get_type.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_coherency_get_type.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hsa_amd_coherency_type_t *\",\"value\":\"%p\"}", args->hsa_amd_coherency_get_type.type); \
};

//	uint16_t extension (unsigned short);
//	uint16_t version_major (unsigned short);
//	uint16_t version_minor (unsigned short);
#define PROCESS_ARGS_hsa_system_get_extension_table(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_system_get_extension_table.retval); \
	ratelprof_add_to_buffer(buf, "\"extension\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_system_get_extension_table.extension); \
	ratelprof_add_to_buffer(buf, "\"version_major\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_system_get_extension_table.version_major); \
	ratelprof_add_to_buffer(buf, "\"version_minor\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_system_get_extension_table.version_minor); \
	ratelprof_add_to_buffer(buf, "\"table\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_system_get_extension_table.table); \
};


#define PROCESS_ARGS_hsa_amd_ipc_memory_detach(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_ipc_memory_detach.retval); \
	ratelprof_add_to_buffer(buf, "\"mapped_ptr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_amd_ipc_memory_detach.mapped_ptr); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_ext_image_geometry_t geometry (enum);
//	hsa_ext_image_data_layout_t image_data_layout (enum);
#define PROCESS_ARGS_hsa_ext_image_get_capability_with_layout(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_ext_image_get_capability_with_layout.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_get_capability_with_layout.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"geometry\":{\"type\":\"hsa_ext_image_geometry_t\",\"value\":\"%d\"},", args->hsa_ext_image_get_capability_with_layout.geometry); \
	ratelprof_add_to_buffer(buf, "\"image_format\":{\"type\":\"const hsa_ext_image_format_t *\",\"value\":\"%p\"},", args->hsa_ext_image_get_capability_with_layout.image_format); \
	ratelprof_add_to_buffer(buf, "\"image_data_layout\":{\"type\":\"hsa_ext_image_data_layout_t\",\"value\":\"%d\"},", args->hsa_ext_image_get_capability_with_layout.image_data_layout); \
	ratelprof_add_to_buffer(buf, "\"capability_mask\":{\"type\":\"uint32_t *\",\"value\":\"%p\"}", args->hsa_ext_image_get_capability_with_layout.capability_mask); \
};

//	size_t size (unsigned long);
#define PROCESS_ARGS_hsa_amd_vmem_address_free(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_vmem_address_free.retval); \
	ratelprof_add_to_buffer(buf, "\"va\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_vmem_address_free.va); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hsa_amd_vmem_address_free.size); \
};

//	size_t size (unsigned long);
//	size_t attribute_count (unsigned long);
#define PROCESS_ARGS_hsa_amd_svm_attributes_set(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_svm_attributes_set.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_svm_attributes_set.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_svm_attributes_set.size); \
	ratelprof_add_to_buffer(buf, "\"attribute_list\":{\"type\":\"hsa_amd_svm_attribute_pair_t *\",\"value\":\"%p\"},", args->hsa_amd_svm_attributes_set.attribute_list); \
	ratelprof_add_to_buffer(buf, "\"attribute_count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hsa_amd_svm_attributes_set.attribute_count); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	size_t src_row_pitch (unsigned long);
//	size_t src_slice_pitch (unsigned long);
//	hsa_ext_image_t dst_image ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_ext_image_import(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_ext_image_import.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_import.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src_memory\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hsa_ext_image_import.src_memory); \
	ratelprof_add_to_buffer(buf, "\"src_row_pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_ext_image_import.src_row_pitch); \
	ratelprof_add_to_buffer(buf, "\"src_slice_pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_ext_image_import.src_slice_pitch); \
	ratelprof_add_to_buffer(buf, "\"dst_image\":{\"type\":\"struct hsa_ext_image_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_import.dst_image.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"image_region\":{\"type\":\"const hsa_ext_image_region_t *\",\"value\":\"%p\"}", args->hsa_ext_image_import.image_region); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_or_scacquire(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_or_scacquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_or_scacquire.value); \
};

//	size_t size (unsigned long);
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	uint32_t num_dep_signals (unsigned int);
//	hsa_signal_t completion_signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_svm_prefetch_async(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_svm_prefetch_async.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_svm_prefetch_async.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_svm_prefetch_async.size); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_svm_prefetch_async.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"num_dep_signals\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_svm_prefetch_async.num_dep_signals); \
	ratelprof_add_to_buffer(buf, "\"dep_signals\":{\"type\":\"const hsa_signal_t *\",\"value\":\"%p\"},", args->hsa_amd_svm_prefetch_async.dep_signals); \
	ratelprof_add_to_buffer(buf, "\"completion_signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_svm_prefetch_async.completion_signal.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_add_scacq_screl(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_add_scacq_screl.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_add_scacq_screl.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_silent_store_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_silent_store_relaxed.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_silent_store_relaxed.value); \
};

//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_store_read_index_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_store_read_index_relaxed.queue); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_store_read_index_relaxed.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_profile_t profile (enum);
#define PROCESS_ARGS_hsa_agent_get_exception_policies(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_agent_get_exception_policies.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_agent_get_exception_policies.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"profile\":{\"type\":\"hsa_profile_t\",\"value\":\"%d\"},", args->hsa_agent_get_exception_policies.profile); \
	ratelprof_add_to_buffer(buf, "\"mask\":{\"type\":\"uint16_t *\",\"value\":\"%p\"}", args->hsa_agent_get_exception_policies.mask); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_add_scacquire(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_add_scacquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_add_scacquire.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_exchange_release(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_exchange_release.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_exchange_release.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_exchange_release.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_add_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_add_relaxed.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_add_relaxed.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_and_acquire(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_and_acquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_and_acquire.value); \
};

//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_add_write_index_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_add_write_index_relaxed.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_add_write_index_relaxed.queue); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_add_write_index_relaxed.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_memory_pool_t memory_pool ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_agent_memory_pool_info_t attribute (enum);
#define PROCESS_ARGS_hsa_amd_agent_memory_pool_get_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_agent_memory_pool_get_info.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_agent_memory_pool_get_info.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"memory_pool\":{\"type\":\"struct hsa_amd_memory_pool_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_agent_memory_pool_get_info.memory_pool.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hsa_amd_agent_memory_pool_info_t\",\"value\":\"%d\"},", args->hsa_amd_agent_memory_pool_get_info.attribute); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_amd_agent_memory_pool_get_info.value); \
};

//	int enable (int);
#define PROCESS_ARGS_hsa_amd_profiling_set_profiler_enabled(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_profiling_set_profiler_enabled.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_amd_profiling_set_profiler_enabled.queue); \
	ratelprof_add_to_buffer(buf, "\"enable\":{\"type\":\"int\",\"value\":\"%d\"}", args->hsa_amd_profiling_set_profiler_enabled.enable); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_exchange_acq_rel(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_exchange_acq_rel.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_exchange_acq_rel.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_exchange_acq_rel.value); \
};

//	uint64_t expected (unsigned long);
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_cas_write_index_screlease(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_cas_write_index_screlease.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_cas_write_index_screlease.queue); \
	ratelprof_add_to_buffer(buf, "\"expected\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_cas_write_index_screlease.expected); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_cas_write_index_screlease.value); \
};

//	void (*)(void *) callback (function);
#define PROCESS_ARGS_hsa_amd_async_function(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_async_function.retval); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"void (*)(void *)\",\"value\":\"%p\"},", args->hsa_amd_async_function.callback); \
	ratelprof_add_to_buffer(buf, "\"arg\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_amd_async_function.arg); \
};

//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_store_read_index_screlease(args) { \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_store_read_index_screlease.queue); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_store_read_index_screlease.value); \
};

//	hsa_region_t region ({
//		uint64_t handle (unsigned long);
//	});
//	size_t size (unsigned long);
#define PROCESS_ARGS_hsa_memory_allocate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_memory_allocate.retval); \
	ratelprof_add_to_buffer(buf, "\"region\":{\"type\":\"struct hsa_region_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_memory_allocate.region.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_memory_allocate.size); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":\"%p\"}", args->hsa_memory_allocate.ptr); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_signal_value_pointer(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_signal_value_pointer.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_signal_value_pointer.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value_ptr\":{\"type\":\"volatile hsa_signal_value_t **\",\"value\":\"%p\"}", args->hsa_amd_signal_value_pointer.value_ptr); \
};

//	uint32_t signal_count (unsigned int);
//	uint64_t timeout_hint (unsigned long);
//	hsa_wait_state_t wait_hint (enum);
#define PROCESS_ARGS_hsa_amd_signal_wait_any(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_signal_wait_any.retval); \
	ratelprof_add_to_buffer(buf, "\"signal_count\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_signal_wait_any.signal_count); \
	ratelprof_add_to_buffer(buf, "\"signals\":{\"type\":\"hsa_signal_t *\",\"value\":\"%p\"},", args->hsa_amd_signal_wait_any.signals); \
	ratelprof_add_to_buffer(buf, "\"conds\":{\"type\":\"hsa_signal_condition_t *\",\"value\":\"%p\"},", args->hsa_amd_signal_wait_any.conds); \
	ratelprof_add_to_buffer(buf, "\"values\":{\"type\":\"hsa_signal_value_t *\",\"value\":\"%p\"},", args->hsa_amd_signal_wait_any.values); \
	ratelprof_add_to_buffer(buf, "\"timeout_hint\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_amd_signal_wait_any.timeout_hint); \
	ratelprof_add_to_buffer(buf, "\"wait_hint\":{\"type\":\"hsa_wait_state_t\",\"value\":\"%d\"},", args->hsa_amd_signal_wait_any.wait_hint); \
	ratelprof_add_to_buffer(buf, "\"satisfying_value\":{\"type\":\"hsa_signal_value_t *\",\"value\":\"%p\"}", args->hsa_amd_signal_wait_any.satisfying_value); \
};


#define PROCESS_ARGS_hsa_amd_vmem_retain_alloc_handle(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_vmem_retain_alloc_handle.retval); \
	ratelprof_add_to_buffer(buf, "\"memory_handle\":{\"type\":\"hsa_amd_vmem_alloc_handle_t *\",\"value\":\"%p\"},", args->hsa_amd_vmem_retain_alloc_handle.memory_handle); \
	ratelprof_add_to_buffer(buf, "\"addr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_amd_vmem_retain_alloc_handle.addr); \
};

//	size_t size (unsigned long);
//	size_t desc_cnt (unsigned long);
#define PROCESS_ARGS_hsa_amd_vmem_set_access(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_vmem_set_access.retval); \
	ratelprof_add_to_buffer(buf, "\"va\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_vmem_set_access.va); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_vmem_set_access.size); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const hsa_amd_memory_access_desc_t *\",\"value\":\"%p\"},", args->hsa_amd_vmem_set_access.desc); \
	ratelprof_add_to_buffer(buf, "\"desc_cnt\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hsa_amd_vmem_set_access.desc_cnt); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_access_permission_t access (enum);
#define PROCESS_ARGS_hsa_memory_assign_agent(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_memory_assign_agent.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_memory_assign_agent.ptr); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_memory_assign_agent.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"access\":{\"type\":\"hsa_access_permission_t\",\"value\":\"%d\"}", args->hsa_memory_assign_agent.access); \
};

//	size_t size (unsigned long);
//	uint64_t address (unsigned long);
//	uint64_t flags (unsigned long);
#define PROCESS_ARGS_hsa_amd_vmem_address_reserve(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_vmem_address_reserve.retval); \
	ratelprof_add_to_buffer(buf, "\"va\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hsa_amd_vmem_address_reserve.va); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_vmem_address_reserve.size); \
	ratelprof_add_to_buffer(buf, "\"address\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_amd_vmem_address_reserve.address); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_vmem_address_reserve.flags); \
};

//	hsa_agent_t dst_agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_t src_agent ({
//		uint64_t handle (unsigned long);
//	});
//	size_t size (unsigned long);
//	uint32_t num_dep_signals (unsigned int);
//	hsa_signal_t completion_signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_sdma_engine_id_t engine_id (enum);
//	_Bool force_copy_on_sdma (unknown);
#define PROCESS_ARGS_hsa_amd_memory_async_copy_on_engine(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_memory_async_copy_on_engine.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_memory_async_copy_on_engine.dst); \
	ratelprof_add_to_buffer(buf, "\"dst_agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_async_copy_on_engine.dst_agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hsa_amd_memory_async_copy_on_engine.src); \
	ratelprof_add_to_buffer(buf, "\"src_agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_async_copy_on_engine.src_agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_memory_async_copy_on_engine.size); \
	ratelprof_add_to_buffer(buf, "\"num_dep_signals\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_memory_async_copy_on_engine.num_dep_signals); \
	ratelprof_add_to_buffer(buf, "\"dep_signals\":{\"type\":\"const hsa_signal_t *\",\"value\":\"%p\"},", args->hsa_amd_memory_async_copy_on_engine.dep_signals); \
	ratelprof_add_to_buffer(buf, "\"completion_signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_async_copy_on_engine.completion_signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"engine_id\":{\"type\":\"hsa_amd_sdma_engine_id_t\",\"value\":\"%d\"},", args->hsa_amd_memory_async_copy_on_engine.engine_id); \
	ratelprof_add_to_buffer(buf, "\"force_copy_on_sdma\":{\"type\":\"_Bool\",\"value\":\"N/A\"},"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_xor_scacquire(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_xor_scacquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_xor_scacquire.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_coherency_type_t type (enum);
#define PROCESS_ARGS_hsa_amd_coherency_set_type(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_coherency_set_type.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_coherency_set_type.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hsa_amd_coherency_type_t\",\"value\":\"%d\"}", args->hsa_amd_coherency_set_type.type); \
};


#define PROCESS_ARGS_hsa_queue_inactivate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_queue_inactivate.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"hsa_queue_t *\",\"value\":\"%p\"}", args->hsa_queue_inactivate.queue); \
};

//	int dmabuf_fd (int);
#define PROCESS_ARGS_hsa_amd_vmem_import_shareable_handle(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_vmem_import_shareable_handle.retval); \
	ratelprof_add_to_buffer(buf, "\"dmabuf_fd\":{\"type\":\"int\",\"value\":\"%d\"},", args->hsa_amd_vmem_import_shareable_handle.dmabuf_fd); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hsa_amd_vmem_alloc_handle_t *\",\"value\":\"%p\"}", args->hsa_amd_vmem_import_shareable_handle.handle); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t expected (long);
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_cas_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_cas_relaxed.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_cas_relaxed.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"expected\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_cas_relaxed.expected); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_cas_relaxed.value); \
};

//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_add_write_index_scacquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_add_write_index_scacquire.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_add_write_index_scacquire.queue); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_add_write_index_scacquire.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_exchange_screlease(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_exchange_screlease.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_exchange_screlease.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_exchange_screlease.value); \
};

//	hsa_amd_memory_pool_t pool ({
//		uint64_t handle (unsigned long);
//	});
//	size_t size (unsigned long);
//	hsa_amd_memory_type_t type (enum);
//	uint64_t flags (unsigned long);
#define PROCESS_ARGS_hsa_amd_vmem_handle_create(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_vmem_handle_create.retval); \
	ratelprof_add_to_buffer(buf, "\"pool\":{\"type\":\"struct hsa_amd_memory_pool_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_vmem_handle_create.pool.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_vmem_handle_create.size); \
	ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hsa_amd_memory_type_t\",\"value\":\"%d\"},", args->hsa_amd_vmem_handle_create.type); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_amd_vmem_handle_create.flags); \
	ratelprof_add_to_buffer(buf, "\"memory_handle\":{\"type\":\"hsa_amd_vmem_alloc_handle_t *\",\"value\":\"%p\"}", args->hsa_amd_vmem_handle_create.memory_handle); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_info_t attribute (enum);
#define PROCESS_ARGS_hsa_agent_get_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_agent_get_info.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_agent_get_info.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hsa_agent_info_t\",\"value\":\"%d\"},", args->hsa_agent_get_info.attribute); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_agent_get_info.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_or_acq_rel(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_or_acq_rel.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_or_acq_rel.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_xor_acq_rel(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_xor_acq_rel.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_xor_acq_rel.value); \
};

//	uint16_t extension (unsigned short);
//	uint16_t version_major (unsigned short);
//	uint16_t version_minor (unsigned short);
//	_Bool * result (unknown);
#define PROCESS_ARGS_hsa_system_extension_supported(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_system_extension_supported.retval); \
	ratelprof_add_to_buffer(buf, "\"extension\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_system_extension_supported.extension); \
	ratelprof_add_to_buffer(buf, "\"version_major\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_system_extension_supported.version_major); \
	ratelprof_add_to_buffer(buf, "\"version_minor\":{\"type\":\"uint16_t\",\"value\":\"%hu\"},", args->hsa_system_extension_supported.version_minor); \
	ratelprof_add_to_buffer(buf, "\"result\":{\"type\":\"_Bool *\",\"value\":\"N/A\"},"); \
};

//	hsa_signal_group_t signal_group ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_wait_state_t wait_state_hint (enum);
#define PROCESS_ARGS_hsa_signal_group_wait_any_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_signal_group_wait_any_relaxed.retval); \
	ratelprof_add_to_buffer(buf, "\"signal_group\":{\"type\":\"struct hsa_signal_group_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_group_wait_any_relaxed.signal_group.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"conditions\":{\"type\":\"const hsa_signal_condition_t *\",\"value\":\"%p\"},", args->hsa_signal_group_wait_any_relaxed.conditions); \
	ratelprof_add_to_buffer(buf, "\"compare_values\":{\"type\":\"const hsa_signal_value_t *\",\"value\":\"%p\"},", args->hsa_signal_group_wait_any_relaxed.compare_values); \
	ratelprof_add_to_buffer(buf, "\"wait_state_hint\":{\"type\":\"hsa_wait_state_t\",\"value\":\"%d\"},", args->hsa_signal_group_wait_any_relaxed.wait_state_hint); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"hsa_signal_t *\",\"value\":\"%p\"},", args->hsa_signal_group_wait_any_relaxed.signal); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t *\",\"value\":\"%p\"}", args->hsa_signal_group_wait_any_relaxed.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_or_scacq_screl(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_or_scacq_screl.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_or_scacq_screl.value); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_executable_t, hsa_agent_t, hsa_executable_symbol_t, void *) callback (function);
#define PROCESS_ARGS_hsa_executable_iterate_agent_symbols(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_iterate_agent_symbols.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_iterate_agent_symbols.executable.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_iterate_agent_symbols.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"hsa_status_t (*)(hsa_executable_t, hsa_agent_t, hsa_executable_symbol_t, void *)\",\"value\":\"%p\"},", args->hsa_executable_iterate_agent_symbols.callback); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_executable_iterate_agent_symbols.data); \
};

//	hsa_amd_deallocation_callback_t callback (function);
#define PROCESS_ARGS_hsa_amd_deregister_deallocation_callback(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_deregister_deallocation_callback.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_deregister_deallocation_callback.ptr); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"hsa_amd_deallocation_callback_t\",\"value\":\"%p\"}", args->hsa_amd_deregister_deallocation_callback.callback); \
};

//	hsa_signal_value_t initial_value (long);
//	uint32_t num_consumers (unsigned int);
#define PROCESS_ARGS_hsa_signal_create(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_signal_create.retval); \
	ratelprof_add_to_buffer(buf, "\"initial_value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_create.initial_value); \
	ratelprof_add_to_buffer(buf, "\"num_consumers\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_signal_create.num_consumers); \
	ratelprof_add_to_buffer(buf, "\"consumers\":{\"type\":\"const hsa_agent_t *\",\"value\":\"%p\"},", args->hsa_signal_create.consumers); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"hsa_signal_t *\",\"value\":\"%p\"}", args->hsa_signal_create.signal); \
};

//	hsa_agent_t dst_agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_t src_agent ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_memory_copy_engine_status(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_memory_copy_engine_status.retval); \
	ratelprof_add_to_buffer(buf, "\"dst_agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_copy_engine_status.dst_agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src_agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_copy_engine_status.src_agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"engine_ids_mask\":{\"type\":\"uint32_t *\",\"value\":\"%p\"}", args->hsa_amd_memory_copy_engine_status.engine_ids_mask); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_ext_image_geometry_t geometry (enum);
#define PROCESS_ARGS_hsa_ext_image_get_capability(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_ext_image_get_capability.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_get_capability.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"geometry\":{\"type\":\"hsa_ext_image_geometry_t\",\"value\":\"%d\"},", args->hsa_ext_image_get_capability.geometry); \
	ratelprof_add_to_buffer(buf, "\"image_format\":{\"type\":\"const hsa_ext_image_format_t *\",\"value\":\"%p\"},", args->hsa_ext_image_get_capability.image_format); \
	ratelprof_add_to_buffer(buf, "\"capability_mask\":{\"type\":\"uint32_t *\",\"value\":\"%p\"}", args->hsa_ext_image_get_capability.capability_mask); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_ext_image_t image ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_ext_image_destroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_ext_image_destroy.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_destroy.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"image\":{\"type\":\"struct hsa_ext_image_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_destroy.image.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_store_read_index_release(args) { \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_store_read_index_release.queue); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_store_read_index_release.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_condition_t condition (enum);
//	hsa_signal_value_t compare_value (long);
//	uint64_t timeout_hint (unsigned long);
//	hsa_wait_state_t wait_state_hint (enum);
#define PROCESS_ARGS_hsa_signal_wait_scacquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_wait_scacquire.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_wait_scacquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"condition\":{\"type\":\"hsa_signal_condition_t\",\"value\":\"%d\"},", args->hsa_signal_wait_scacquire.condition); \
	ratelprof_add_to_buffer(buf, "\"compare_value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_wait_scacquire.compare_value); \
	ratelprof_add_to_buffer(buf, "\"timeout_hint\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_signal_wait_scacquire.timeout_hint); \
	ratelprof_add_to_buffer(buf, "\"wait_state_hint\":{\"type\":\"hsa_wait_state_t\",\"value\":\"%d\"}", args->hsa_signal_wait_scacquire.wait_state_hint); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_executable_info_t attribute (enum);
#define PROCESS_ARGS_hsa_executable_get_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_get_info.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_get_info.executable.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hsa_executable_info_t\",\"value\":\"%d\"},", args->hsa_executable_get_info.attribute); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_executable_get_info.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_silent_store_screlease(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_silent_store_screlease.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_silent_store_screlease.value); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_validate_alt(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_validate_alt.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_validate_alt.executable.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"options\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_executable_validate_alt.options); \
	ratelprof_add_to_buffer(buf, "\"result\":{\"type\":\"uint32_t *\",\"value\":\"%p\"}", args->hsa_executable_validate_alt.result); \
};

//	hsa_profile_t profile (enum);
//	hsa_executable_state_t executable_state (enum);
#define PROCESS_ARGS_hsa_executable_create(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_create.retval); \
	ratelprof_add_to_buffer(buf, "\"profile\":{\"type\":\"hsa_profile_t\",\"value\":\"%d\"},", args->hsa_executable_create.profile); \
	ratelprof_add_to_buffer(buf, "\"executable_state\":{\"type\":\"hsa_executable_state_t\",\"value\":\"%d\"},", args->hsa_executable_create.executable_state); \
	ratelprof_add_to_buffer(buf, "\"options\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_executable_create.options); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"hsa_executable_t *\",\"value\":\"%p\"}", args->hsa_executable_create.executable); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_executable_t, hsa_executable_symbol_t, void *) callback (function);
#define PROCESS_ARGS_hsa_executable_iterate_program_symbols(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_iterate_program_symbols.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_iterate_program_symbols.executable.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"hsa_status_t (*)(hsa_executable_t, hsa_executable_symbol_t, void *)\",\"value\":\"%p\"},", args->hsa_executable_iterate_program_symbols.callback); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_executable_iterate_program_symbols.data); \
};


#define PROCESS_ARGS_hsa_memory_free(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_memory_free.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_memory_free.ptr); \
};


#define PROCESS_ARGS_hsa_amd_memory_pool_free(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_memory_pool_free.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_amd_memory_pool_free.ptr); \
};

//	hsa_amd_memory_pool_t memory_pool ({
//		uint64_t handle (unsigned long);
//	});
//	uint32_t flags (unsigned int);
#define PROCESS_ARGS_hsa_amd_memory_migrate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_memory_migrate.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hsa_amd_memory_migrate.ptr); \
	ratelprof_add_to_buffer(buf, "\"memory_pool\":{\"type\":\"struct hsa_amd_memory_pool_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_memory_migrate.memory_pool.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->hsa_amd_memory_migrate.flags); \
};


#define PROCESS_ARGS_hsa_amd_interop_unmap_buffer(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_interop_unmap_buffer.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_amd_interop_unmap_buffer.ptr); \
};

//	hsa_signal_value_t initial_value (long);
//	uint32_t num_consumers (unsigned int);
//	uint64_t attributes (unsigned long);
#define PROCESS_ARGS_hsa_amd_signal_create(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_signal_create.retval); \
	ratelprof_add_to_buffer(buf, "\"initial_value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_amd_signal_create.initial_value); \
	ratelprof_add_to_buffer(buf, "\"num_consumers\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_signal_create.num_consumers); \
	ratelprof_add_to_buffer(buf, "\"consumers\":{\"type\":\"const hsa_agent_t *\",\"value\":\"%p\"},", args->hsa_amd_signal_create.consumers); \
	ratelprof_add_to_buffer(buf, "\"attributes\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_amd_signal_create.attributes); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"hsa_signal_t *\",\"value\":\"%p\"}", args->hsa_amd_signal_create.signal); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_code_object_reader_t code_object_reader ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_load_program_code_object(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_load_program_code_object.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_load_program_code_object.executable.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"code_object_reader\":{\"type\":\"struct hsa_code_object_reader_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_load_program_code_object.code_object_reader.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"options\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_executable_load_program_code_object.options); \
	ratelprof_add_to_buffer(buf, "\"loaded_code_object\":{\"type\":\"hsa_loaded_code_object_t *\",\"value\":\"%p\"}", args->hsa_executable_load_program_code_object.loaded_code_object); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_signal_load_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_load_relaxed.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_load_relaxed.signal.handle); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hsa_signal_group_t signal_group ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_wait_state_t wait_state_hint (enum);
#define PROCESS_ARGS_hsa_signal_group_wait_any_scacquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_signal_group_wait_any_scacquire.retval); \
	ratelprof_add_to_buffer(buf, "\"signal_group\":{\"type\":\"struct hsa_signal_group_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_group_wait_any_scacquire.signal_group.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"conditions\":{\"type\":\"const hsa_signal_condition_t *\",\"value\":\"%p\"},", args->hsa_signal_group_wait_any_scacquire.conditions); \
	ratelprof_add_to_buffer(buf, "\"compare_values\":{\"type\":\"const hsa_signal_value_t *\",\"value\":\"%p\"},", args->hsa_signal_group_wait_any_scacquire.compare_values); \
	ratelprof_add_to_buffer(buf, "\"wait_state_hint\":{\"type\":\"hsa_wait_state_t\",\"value\":\"%d\"},", args->hsa_signal_group_wait_any_scacquire.wait_state_hint); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"hsa_signal_t *\",\"value\":\"%p\"},", args->hsa_signal_group_wait_any_scacquire.signal); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t *\",\"value\":\"%p\"}", args->hsa_signal_group_wait_any_scacquire.value); \
};

//	uint64_t expected (unsigned long);
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_cas_write_index_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_cas_write_index_relaxed.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_cas_write_index_relaxed.queue); \
	ratelprof_add_to_buffer(buf, "\"expected\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_cas_write_index_relaxed.expected); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_cas_write_index_relaxed.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_subtract_relaxed(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_subtract_relaxed.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_subtract_relaxed.value); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_freeze(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_freeze.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_freeze.executable.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"options\":{\"type\":\"const char *\",\"value\":\"%p\"}", args->hsa_executable_freeze.options); \
};


#define PROCESS_ARGS_hsa_queue_load_write_index_acquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_load_write_index_acquire.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"}", args->hsa_queue_load_write_index_acquire.queue); \
};

//	size_t size (unsigned long);
//	size_t in_offset (unsigned long);
//	hsa_amd_vmem_alloc_handle_t memory_handle ({
//		uint64_t handle (unsigned long);
//	});
//	uint64_t flags (unsigned long);
#define PROCESS_ARGS_hsa_amd_vmem_map(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_vmem_map.retval); \
	ratelprof_add_to_buffer(buf, "\"va\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_amd_vmem_map.va); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_vmem_map.size); \
	ratelprof_add_to_buffer(buf, "\"in_offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_amd_vmem_map.in_offset); \
	ratelprof_add_to_buffer(buf, "\"memory_handle\":{\"type\":\"struct hsa_amd_vmem_alloc_handle_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_vmem_map.memory_handle.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_vmem_map.flags); \
};


#define PROCESS_ARGS_hsa_amd_ipc_signal_attach(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_ipc_signal_attach.retval); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"const hsa_amd_ipc_signal_t *\",\"value\":\"%p\"},", args->hsa_amd_ipc_signal_attach.handle); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"hsa_signal_t *\",\"value\":\"%p\"}", args->hsa_amd_ipc_signal_attach.signal); \
};

//	hsa_amd_system_event_callback_t callback (function);
#define PROCESS_ARGS_hsa_amd_register_system_event_handler(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_register_system_event_handler.retval); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"hsa_amd_system_event_callback_t\",\"value\":\"%p\"},", args->hsa_amd_register_system_event_handler.callback); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_amd_register_system_event_handler.data); \
};

//	uint32_t num_cu_mask_count (unsigned int);
#define PROCESS_ARGS_hsa_amd_queue_cu_set_mask(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_queue_cu_set_mask.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_amd_queue_cu_set_mask.queue); \
	ratelprof_add_to_buffer(buf, "\"num_cu_mask_count\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_queue_cu_set_mask.num_cu_mask_count); \
	ratelprof_add_to_buffer(buf, "\"cu_mask\":{\"type\":\"const uint32_t *\",\"value\":\"%p\"}", args->hsa_amd_queue_cu_set_mask.cu_mask); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_ext_image_t src_image ({
//		uint64_t handle (unsigned long);
//	});
//	size_t dst_row_pitch (unsigned long);
//	size_t dst_slice_pitch (unsigned long);
#define PROCESS_ARGS_hsa_ext_image_export(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_ext_image_export.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_export.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src_image\":{\"type\":\"struct hsa_ext_image_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_export.src_image.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dst_memory\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_ext_image_export.dst_memory); \
	ratelprof_add_to_buffer(buf, "\"dst_row_pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_ext_image_export.dst_row_pitch); \
	ratelprof_add_to_buffer(buf, "\"dst_slice_pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_ext_image_export.dst_slice_pitch); \
	ratelprof_add_to_buffer(buf, "\"image_region\":{\"type\":\"const hsa_ext_image_region_t *\",\"value\":\"%p\"}", args->hsa_ext_image_export.image_region); \
};

//	hsa_status_t status (enum);
#define PROCESS_ARGS_hsa_status_string(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_status_string.retval); \
	ratelprof_add_to_buffer(buf, "\"status\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_status_string.status); \
	ratelprof_add_to_buffer(buf, "\"status_string\":{\"type\":\"const char **\",\"value\":\"%p\"}", args->hsa_status_string.status_string); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_xor_screlease(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_xor_screlease.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_xor_screlease.value); \
};

//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_add_write_index_acquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_add_write_index_acquire.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_add_write_index_acquire.queue); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_add_write_index_acquire.value); \
};

//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_add_write_index_screlease(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hsa_queue_add_write_index_screlease.retval); \
	ratelprof_add_to_buffer(buf, "\"queue\":{\"type\":\"const hsa_queue_t *\",\"value\":\"%p\"},", args->hsa_queue_add_write_index_screlease.queue); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_queue_add_write_index_screlease.value); \
};

//	hsa_code_object_t code_object ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_code_object_get_symbol_from_name(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_code_object_get_symbol_from_name.retval); \
	ratelprof_add_to_buffer(buf, "\"code_object\":{\"type\":\"struct hsa_code_object_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_code_object_get_symbol_from_name.code_object.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"module_name\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_code_object_get_symbol_from_name.module_name); \
	ratelprof_add_to_buffer(buf, "\"symbol_name\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_code_object_get_symbol_from_name.symbol_name); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"hsa_code_symbol_t *\",\"value\":\"%p\"}", args->hsa_code_object_get_symbol_from_name.symbol); \
};


#define PROCESS_ARGS_hsa_isa_from_name(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_isa_from_name.retval); \
	ratelprof_add_to_buffer(buf, "\"name\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_isa_from_name.name); \
	ratelprof_add_to_buffer(buf, "\"isa\":{\"type\":\"hsa_isa_t *\",\"value\":\"%p\"}", args->hsa_isa_from_name.isa); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_amd_memory_pool_t, void *) callback (function);
#define PROCESS_ARGS_hsa_amd_agent_iterate_memory_pools(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_agent_iterate_memory_pools.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_agent_iterate_memory_pools.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"hsa_status_t (*)(hsa_amd_memory_pool_t, void *)\",\"value\":\"%p\"},", args->hsa_amd_agent_iterate_memory_pools.callback); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_amd_agent_iterate_memory_pools.data); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	size_t threshold (unsigned long);
#define PROCESS_ARGS_hsa_amd_agent_set_async_scratch_limit(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_agent_set_async_scratch_limit.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_agent_set_async_scratch_limit.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"threshold\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hsa_amd_agent_set_async_scratch_limit.threshold); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_access_permission_t access_permission (enum);
#define PROCESS_ARGS_hsa_ext_image_create(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_ext_image_create.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_create.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"image_descriptor\":{\"type\":\"const hsa_ext_image_descriptor_t *\",\"value\":\"%p\"},", args->hsa_ext_image_create.image_descriptor); \
	ratelprof_add_to_buffer(buf, "\"image_data\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hsa_ext_image_create.image_data); \
	ratelprof_add_to_buffer(buf, "\"access_permission\":{\"type\":\"hsa_access_permission_t\",\"value\":\"%d\"},", args->hsa_ext_image_create.access_permission); \
	ratelprof_add_to_buffer(buf, "\"image\":{\"type\":\"hsa_ext_image_t *\",\"value\":\"%p\"}", args->hsa_ext_image_create.image); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_exchange_scacq_screl(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_exchange_scacq_screl.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_exchange_scacq_screl.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_exchange_scacq_screl.value); \
};


#define PROCESS_ARGS_hsa_init(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_init.retval); \
\
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_code_object_reader_t code_object_reader ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_load_agent_code_object(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_load_agent_code_object.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_load_agent_code_object.executable.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_load_agent_code_object.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"code_object_reader\":{\"type\":\"struct hsa_code_object_reader_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_load_agent_code_object.code_object_reader.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"options\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_executable_load_agent_code_object.options); \
	ratelprof_add_to_buffer(buf, "\"loaded_code_object\":{\"type\":\"hsa_loaded_code_object_t *\",\"value\":\"%p\"}", args->hsa_executable_load_agent_code_object.loaded_code_object); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t expected (long);
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_cas_screlease(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_cas_screlease.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_cas_screlease.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"expected\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_cas_screlease.expected); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_cas_screlease.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_profiling_get_dispatch_time(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_profiling_get_dispatch_time.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_profiling_get_dispatch_time.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_amd_profiling_get_dispatch_time.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"time\":{\"type\":\"hsa_amd_profiling_dispatch_time_t *\",\"value\":\"%p\"}", args->hsa_amd_profiling_get_dispatch_time.time); \
};

//	int dmabuf (int);
#define PROCESS_ARGS_hsa_amd_portable_close_dmabuf(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_portable_close_dmabuf.retval); \
	ratelprof_add_to_buffer(buf, "\"dmabuf\":{\"type\":\"int\",\"value\":\"%d\"}", args->hsa_amd_portable_close_dmabuf.dmabuf); \
};

//	size_t size (unsigned long);
#define PROCESS_ARGS_hsa_memory_copy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_memory_copy.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_memory_copy.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hsa_memory_copy.src); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hsa_memory_copy.size); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_exchange_scacquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_exchange_scacquire.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_exchange_scacquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_exchange_scacquire.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_access_permission_t access_permission (enum);
//	hsa_ext_image_data_layout_t image_data_layout (enum);
//	size_t image_data_row_pitch (unsigned long);
//	size_t image_data_slice_pitch (unsigned long);
#define PROCESS_ARGS_hsa_ext_image_data_get_info_with_layout(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_ext_image_data_get_info_with_layout.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_data_get_info_with_layout.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"image_descriptor\":{\"type\":\"const hsa_ext_image_descriptor_t *\",\"value\":\"%p\"},", args->hsa_ext_image_data_get_info_with_layout.image_descriptor); \
	ratelprof_add_to_buffer(buf, "\"access_permission\":{\"type\":\"hsa_access_permission_t\",\"value\":\"%d\"},", args->hsa_ext_image_data_get_info_with_layout.access_permission); \
	ratelprof_add_to_buffer(buf, "\"image_data_layout\":{\"type\":\"hsa_ext_image_data_layout_t\",\"value\":\"%d\"},", args->hsa_ext_image_data_get_info_with_layout.image_data_layout); \
	ratelprof_add_to_buffer(buf, "\"image_data_row_pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_ext_image_data_get_info_with_layout.image_data_row_pitch); \
	ratelprof_add_to_buffer(buf, "\"image_data_slice_pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_ext_image_data_get_info_with_layout.image_data_slice_pitch); \
	ratelprof_add_to_buffer(buf, "\"image_data_info\":{\"type\":\"hsa_ext_image_data_info_t *\",\"value\":\"%p\"}", args->hsa_ext_image_data_get_info_with_layout.image_data_info); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_global_variable_define(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_executable_global_variable_define.retval); \
	ratelprof_add_to_buffer(buf, "\"executable\":{\"type\":\"struct hsa_executable_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_executable_global_variable_define.executable.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"variable_name\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_executable_global_variable_define.variable_name); \
	ratelprof_add_to_buffer(buf, "\"address\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hsa_executable_global_variable_define.address); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_add_acquire(args) { \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_add_acquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_add_acquire.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_access_permission_t access_permission (enum);
#define PROCESS_ARGS_hsa_ext_image_data_get_info(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_ext_image_data_get_info.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_image_data_get_info.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"image_descriptor\":{\"type\":\"const hsa_ext_image_descriptor_t *\",\"value\":\"%p\"},", args->hsa_ext_image_data_get_info.image_descriptor); \
	ratelprof_add_to_buffer(buf, "\"access_permission\":{\"type\":\"hsa_access_permission_t\",\"value\":\"%d\"},", args->hsa_ext_image_data_get_info.access_permission); \
	ratelprof_add_to_buffer(buf, "\"image_data_info\":{\"type\":\"hsa_ext_image_data_info_t *\",\"value\":\"%p\"}", args->hsa_ext_image_data_get_info.image_data_info); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t expected (long);
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_cas_scacquire(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_cas_scacquire.retval); \
	ratelprof_add_to_buffer(buf, "\"signal\":{\"type\":\"struct hsa_signal_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_signal_cas_scacquire.signal.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"expected\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"},", args->hsa_signal_cas_scacquire.expected); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hsa_signal_value_t\",\"value\":\"%ld\"}", args->hsa_signal_cas_scacquire.value); \
};

//	uint32_t num_agents (unsigned int);
//	int interop_handle (int);
//	uint32_t flags (unsigned int);
#define PROCESS_ARGS_hsa_amd_interop_map_buffer(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_interop_map_buffer.retval); \
	ratelprof_add_to_buffer(buf, "\"num_agents\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_interop_map_buffer.num_agents); \
	ratelprof_add_to_buffer(buf, "\"agents\":{\"type\":\"hsa_agent_t *\",\"value\":\"%p\"},", args->hsa_amd_interop_map_buffer.agents); \
	ratelprof_add_to_buffer(buf, "\"interop_handle\":{\"type\":\"int\",\"value\":\"%d\"},", args->hsa_amd_interop_map_buffer.interop_handle); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_interop_map_buffer.flags); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t *\",\"value\":\"%p\"},", args->hsa_amd_interop_map_buffer.size); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hsa_amd_interop_map_buffer.ptr); \
	ratelprof_add_to_buffer(buf, "\"metadata_size\":{\"type\":\"size_t *\",\"value\":\"%p\"},", args->hsa_amd_interop_map_buffer.metadata_size); \
	ratelprof_add_to_buffer(buf, "\"metadata\":{\"type\":\"const void **\",\"value\":\"%p\"}", args->hsa_amd_interop_map_buffer.metadata); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_ext_sampler_create(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_ext_sampler_create.retval); \
	ratelprof_add_to_buffer(buf, "\"agent\":{\"type\":\"struct hsa_agent_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hsa_ext_sampler_create.agent.handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sampler_descriptor\":{\"type\":\"const hsa_ext_sampler_descriptor_t *\",\"value\":\"%p\"},", args->hsa_ext_sampler_create.sampler_descriptor); \
	ratelprof_add_to_buffer(buf, "\"sampler\":{\"type\":\"hsa_ext_sampler_t *\",\"value\":\"%p\"}", args->hsa_ext_sampler_create.sampler); \
};

//	size_t serialized_code_object_size (unsigned long);
#define PROCESS_ARGS_hsa_code_object_deserialize(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_code_object_deserialize.retval); \
	ratelprof_add_to_buffer(buf, "\"serialized_code_object\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hsa_code_object_deserialize.serialized_code_object); \
	ratelprof_add_to_buffer(buf, "\"serialized_code_object_size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hsa_code_object_deserialize.serialized_code_object_size); \
	ratelprof_add_to_buffer(buf, "\"options\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hsa_code_object_deserialize.options); \
	ratelprof_add_to_buffer(buf, "\"code_object\":{\"type\":\"hsa_code_object_t *\",\"value\":\"%p\"}", args->hsa_code_object_deserialize.code_object); \
};

//	uint32_t num_agents (unsigned int);
#define PROCESS_ARGS_hsa_amd_agents_allow_access(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hsa_status_t\",\"value\":\"%d\"},", args->hsa_amd_agents_allow_access.retval); \
	ratelprof_add_to_buffer(buf, "\"num_agents\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hsa_amd_agents_allow_access.num_agents); \
	ratelprof_add_to_buffer(buf, "\"agents\":{\"type\":\"const hsa_agent_t *\",\"value\":\"%p\"},", args->hsa_amd_agents_allow_access.agents); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"const uint32_t *\",\"value\":\"%p\"},", args->hsa_amd_agents_allow_access.flags); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"const void *\",\"value\":\"%p\"}", args->hsa_amd_agents_allow_access.ptr); \
};

#endif // HSA_PLUGIN_H