/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#ifndef HSA_PLUGIN_H 
#define HSA_PLUGIN_H 

#include "ratelprof_buffer_manager.h"

void on_enter_hsa_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity);
void on_exit_hsa_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity);
void process_hsa_args_for(hsa_api_id_t funid, const hsa_api_args_t* args, ratelprof_buffer_t* buf);

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
#define PROCESS_ARGS_hsa_queue_load_read_index_scacquire(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_load_read_index_scacquire.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_load_read_index_scacquire.queue); \
	if (args->hsa_queue_load_read_index_scacquire.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_load_read_index_scacquire.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_load_read_index_scacquire.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_load_read_index_scacquire.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_load_read_index_scacquire.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_load_read_index_scacquire.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_load_read_index_scacquire.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_ext_image_t image ({
//		uint64_t handle (unsigned long);
//	});
//	const void * data (void*);
//	const hsa_ext_image_region_t * image_region ({
//		hsa_dim3_t offset ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		hsa_dim3_t range ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//	});
#define PROCESS_ARGS_hsa_ext_image_clear(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_ext_image_clear.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_clear.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_ext_image_t image = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_clear.image.handle); \
	printf("\t}\n"); \
	printf("\tconst void * data = %p", args->hsa_ext_image_clear.data); \
	printf("\n"); \
	printf("\tconst hsa_ext_image_region_t * image_region = %p", args->hsa_ext_image_clear.image_region); \
	if (args->hsa_ext_image_clear.image_region != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_dim3_t offset = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hsa_ext_image_clear.image_region__ref.val.offset.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hsa_ext_image_clear.image_region__ref.val.offset.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hsa_ext_image_clear.image_region__ref.val.offset.z); \
		printf("\t\t}\n"); \
		printf("\t\thsa_dim3_t range = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hsa_ext_image_clear.image_region__ref.val.range.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hsa_ext_image_clear.image_region__ref.val.range.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hsa_ext_image_clear.image_region__ref.val.range.z); \
		printf("\t\t}\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t expected (unsigned long);
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_cas_write_index_acquire(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_cas_write_index_acquire.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_cas_write_index_acquire.queue); \
	if (args->hsa_queue_cas_write_index_acquire.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_cas_write_index_acquire.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_cas_write_index_acquire.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_cas_write_index_acquire.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_cas_write_index_acquire.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_cas_write_index_acquire.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_cas_write_index_acquire.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t expected = %lu\n", args->hsa_queue_cas_write_index_acquire.expected); \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_cas_write_index_acquire.value); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	const char * module_name (string*);
//	const char * symbol_name (string*);
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	int32_t call_convention (int);
//	hsa_executable_symbol_t * symbol ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_get_symbol(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_get_symbol.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_get_symbol.executable.handle); \
	printf("\t}\n"); \
	printf("\tconst char * module_name = %p", args->hsa_executable_get_symbol.module_name); \
	if (args->hsa_executable_get_symbol.module_name != NULL) { \
		printf(" -> %s\n", args->hsa_executable_get_symbol.module_name__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst char * symbol_name = %p", args->hsa_executable_get_symbol.symbol_name); \
	if (args->hsa_executable_get_symbol.symbol_name != NULL) { \
		printf(" -> %s\n", args->hsa_executable_get_symbol.symbol_name__ref.val); \
	} else { printf("\n"); }; \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_get_symbol.agent.handle); \
	printf("\t}\n"); \
	printf("\tint32_t call_convention = %d\n", args->hsa_executable_get_symbol.call_convention); \
	printf("\thsa_executable_symbol_t * symbol = %p", args->hsa_executable_get_symbol.symbol); \
	if (args->hsa_executable_get_symbol.symbol != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_get_symbol.symbol__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_and_scacq_screl(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_and_scacq_screl.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_and_scacq_screl.value); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	const char * variable_name (string*);
//	void * address (void*);
#define PROCESS_ARGS_hsa_executable_agent_global_variable_define(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_agent_global_variable_define.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_agent_global_variable_define.executable.handle); \
	printf("\t}\n"); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_agent_global_variable_define.agent.handle); \
	printf("\t}\n"); \
	printf("\tconst char * variable_name = %p", args->hsa_executable_agent_global_variable_define.variable_name); \
	if (args->hsa_executable_agent_global_variable_define.variable_name != NULL) { \
		printf(" -> %s\n", args->hsa_executable_agent_global_variable_define.variable_name__ref.val); \
	} else { printf("\n"); }; \
	printf("\tvoid * address = %p", args->hsa_executable_agent_global_variable_define.address); \
	printf("\n"); \
};

//	hsa_code_object_t code_object ({
//		uint64_t handle (unsigned long);
//	});
//	const char * symbol_name (string*);
//	hsa_code_symbol_t * symbol ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_code_object_get_symbol(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_code_object_get_symbol.retval); \
	printf("\thsa_code_object_t code_object = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_code_object_get_symbol.code_object.handle); \
	printf("\t}\n"); \
	printf("\tconst char * symbol_name = %p", args->hsa_code_object_get_symbol.symbol_name); \
	if (args->hsa_code_object_get_symbol.symbol_name != NULL) { \
		printf(" -> %s\n", args->hsa_code_object_get_symbol.symbol_name__ref.val); \
	} else { printf("\n"); }; \
	printf("\thsa_code_symbol_t * symbol = %p", args->hsa_code_object_get_symbol.symbol); \
	if (args->hsa_code_object_get_symbol.symbol != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_code_object_get_symbol.symbol__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_condition_t cond (enum);
//	hsa_signal_value_t value (long);
//	hsa_amd_signal_handler handler (function);
//	void * arg (void*);
#define PROCESS_ARGS_hsa_amd_signal_async_handler(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_signal_async_handler.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_signal_async_handler.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_condition_t cond = %d\n", args->hsa_amd_signal_async_handler.cond); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_amd_signal_async_handler.value); \
	printf("\thsa_amd_signal_handler handler = %p\n", args->hsa_amd_signal_async_handler.handler); \
	printf("\tvoid * arg = %p", args->hsa_amd_signal_async_handler.arg); \
	printf("\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_xor_scacq_screl(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_xor_scacq_screl.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_xor_scacq_screl.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_and_relaxed(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_and_relaxed.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_and_relaxed.value); \
};

//	hsa_wavefront_t wavefront ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_wavefront_info_t attribute (enum);
//	void * value (void*);
#define PROCESS_ARGS_hsa_wavefront_get_info(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_wavefront_get_info.retval); \
	printf("\thsa_wavefront_t wavefront = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_wavefront_get_info.wavefront.handle); \
	printf("\t}\n"); \
	printf("\thsa_wavefront_info_t attribute = %d\n", args->hsa_wavefront_get_info.attribute); \
	printf("\tvoid * value = %p", args->hsa_wavefront_get_info.value); \
	printf("\n"); \
};

//	void * host_ptr (void*);
//	size_t size (unsigned long);
//	hsa_agent_t * agents ({
//		uint64_t handle (unsigned long);
//	});
//	int num_agent (int);
//	void ** agent_ptr (void**);
#define PROCESS_ARGS_hsa_amd_memory_lock(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_memory_lock.retval); \
	printf("\tvoid * host_ptr = %p", args->hsa_amd_memory_lock.host_ptr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_amd_memory_lock.size); \
	printf("\thsa_agent_t * agents = %p", args->hsa_amd_memory_lock.agents); \
	if (args->hsa_amd_memory_lock.agents != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_lock.agents__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tint num_agent = %d\n", args->hsa_amd_memory_lock.num_agent); \
	printf("\tvoid ** agent_ptr = %p", args->hsa_amd_memory_lock.agent_ptr); \
	if (args->hsa_amd_memory_lock.agent_ptr != NULL) { \
		printf("-> %p", args->hsa_amd_memory_lock.agent_ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_or_screlease(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_or_screlease.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_or_screlease.value); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	uint32_t * result (unsigned int*);
#define PROCESS_ARGS_hsa_executable_validate(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_validate.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_validate.executable.handle); \
	printf("\t}\n"); \
	printf("\tuint32_t * result = %p", args->hsa_executable_validate.result); \
	if (args->hsa_executable_validate.result != NULL) { \
		printf(" -> %u\n", args->hsa_executable_validate.result__ref.val); \
	} else { printf("\n"); }; \
};

//	hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
#define PROCESS_ARGS_hsa_queue_destroy(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_queue_destroy.retval); \
	printf("\thsa_queue_t * queue = %p", args->hsa_queue_destroy.queue); \
	if (args->hsa_queue_destroy.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_destroy.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_destroy.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_destroy.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_destroy.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_destroy.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_destroy.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_isa_t isa ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_isa_info_t attribute (enum);
//	uint32_t index (unsigned int);
//	void * value (void*);
#define PROCESS_ARGS_hsa_isa_get_info(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_isa_get_info.retval); \
	printf("\thsa_isa_t isa = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_isa_get_info.isa.handle); \
	printf("\t}\n"); \
	printf("\thsa_isa_info_t attribute = %d\n", args->hsa_isa_get_info.attribute); \
	printf("\tuint32_t index = %u\n", args->hsa_isa_get_info.index); \
	printf("\tvoid * value = %p", args->hsa_isa_get_info.value); \
	printf("\n"); \
};

//	void * host_ptr (void*);
//	size_t size (unsigned long);
//	hsa_agent_t * agents ({
//		uint64_t handle (unsigned long);
//	});
//	int num_agent (int);
//	hsa_amd_memory_pool_t pool ({
//		uint64_t handle (unsigned long);
//	});
//	uint32_t flags (unsigned int);
//	void ** agent_ptr (void**);
#define PROCESS_ARGS_hsa_amd_memory_lock_to_pool(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_memory_lock_to_pool.retval); \
	printf("\tvoid * host_ptr = %p", args->hsa_amd_memory_lock_to_pool.host_ptr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_amd_memory_lock_to_pool.size); \
	printf("\thsa_agent_t * agents = %p", args->hsa_amd_memory_lock_to_pool.agents); \
	if (args->hsa_amd_memory_lock_to_pool.agents != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_lock_to_pool.agents__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tint num_agent = %d\n", args->hsa_amd_memory_lock_to_pool.num_agent); \
	printf("\thsa_amd_memory_pool_t pool = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_lock_to_pool.pool.handle); \
	printf("\t}\n"); \
	printf("\tuint32_t flags = %u\n", args->hsa_amd_memory_lock_to_pool.flags); \
	printf("\tvoid ** agent_ptr = %p", args->hsa_amd_memory_lock_to_pool.agent_ptr); \
	if (args->hsa_amd_memory_lock_to_pool.agent_ptr != NULL) { \
		printf("-> %p", args->hsa_amd_memory_lock_to_pool.agent_ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
};

//	uint16_t extension (unsigned short);
//	uint16_t version_major (unsigned short);
//	uint16_t * version_minor (unsigned short*);
//	_Bool * result (unknown);
#define PROCESS_ARGS_hsa_system_major_extension_supported(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_system_major_extension_supported.retval); \
	printf("\tuint16_t extension = %hu\n", args->hsa_system_major_extension_supported.extension); \
	printf("\tuint16_t version_major = %hu\n", args->hsa_system_major_extension_supported.version_major); \
	printf("\tuint16_t * version_minor = %p", args->hsa_system_major_extension_supported.version_minor); \
	if (args->hsa_system_major_extension_supported.version_minor != NULL) { \
		printf(" -> %hu\n", args->hsa_system_major_extension_supported.version_minor__ref.val); \
	} else { printf("\n"); }; \
	printf("\t_Bool * result = N/A, try to update csv files\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_profiling_async_copy_time_t * time ({
//		uint64_t start (unsigned long);
//		uint64_t end (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_profiling_get_async_copy_time(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_profiling_get_async_copy_time.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_profiling_get_async_copy_time.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_amd_profiling_async_copy_time_t * time = %p", args->hsa_amd_profiling_get_async_copy_time.time); \
	if (args->hsa_amd_profiling_get_async_copy_time.time != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t start = %lu\n", args->hsa_amd_profiling_get_async_copy_time.time__ref.val.start); \
		printf("\t\tuint64_t end = %lu\n", args->hsa_amd_profiling_get_async_copy_time.time__ref.val.end); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_or_relaxed(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_or_relaxed.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_or_relaxed.value); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t expected (unsigned long);
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_cas_write_index_scacquire(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_cas_write_index_scacquire.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_cas_write_index_scacquire.queue); \
	if (args->hsa_queue_cas_write_index_scacquire.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_cas_write_index_scacquire.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_cas_write_index_scacquire.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_cas_write_index_scacquire.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_cas_write_index_scacquire.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_cas_write_index_scacquire.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_cas_write_index_scacquire.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t expected = %lu\n", args->hsa_queue_cas_write_index_scacquire.expected); \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_cas_write_index_scacquire.value); \
};

//	hsa_code_object_t code_object ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_code_object_info_t attribute (enum);
//	void * value (void*);
#define PROCESS_ARGS_hsa_code_object_get_info(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_code_object_get_info.retval); \
	printf("\thsa_code_object_t code_object = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_code_object_get_info.code_object.handle); \
	printf("\t}\n"); \
	printf("\thsa_code_object_info_t attribute = %d\n", args->hsa_code_object_get_info.attribute); \
	printf("\tvoid * value = %p", args->hsa_code_object_get_info.value); \
	printf("\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_and_screlease(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_and_screlease.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_and_screlease.value); \
};

//	const void * ptr (void*);
//	hsa_amd_pointer_info_t * info ({
//		uint32_t size (unsigned int);
//		hsa_amd_pointer_type_t type (enum);
//		size_t sizeInBytes (unsigned long);
//		hsa_agent_t agentOwner ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t global_flags (unsigned int);
//	});
//	void *(*)(size_t) alloc (function);
//	uint32_t * num_agents_accessible (unsigned int*);
//	hsa_agent_t ** accessible ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_pointer_info(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_pointer_info.retval); \
	printf("\tconst void * ptr = %p", args->hsa_amd_pointer_info.ptr); \
	printf("\n"); \
	printf("\thsa_amd_pointer_info_t * info = %p", args->hsa_amd_pointer_info.info); \
	if (args->hsa_amd_pointer_info.info != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_amd_pointer_info.info__ref.val.size); \
		printf("\t\thsa_amd_pointer_type_t type = %d\n", args->hsa_amd_pointer_info.info__ref.val.type); \
		printf("\t\tsize_t sizeInBytes = %lu\n", args->hsa_amd_pointer_info.info__ref.val.sizeInBytes); \
		printf("\t\thsa_agent_t agentOwner = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_amd_pointer_info.info__ref.val.agentOwner.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t global_flags = %u\n", args->hsa_amd_pointer_info.info__ref.val.global_flags); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tvoid *(*)(size_t) alloc = %p\n", args->hsa_amd_pointer_info.alloc); \
	printf("\tuint32_t * num_agents_accessible = %p", args->hsa_amd_pointer_info.num_agents_accessible); \
	if (args->hsa_amd_pointer_info.num_agents_accessible != NULL) { \
		printf(" -> %u\n", args->hsa_amd_pointer_info.num_agents_accessible__ref.val); \
	} else { printf("\n"); }; \
	printf("\thsa_agent_t ** accessible = %p", args->hsa_amd_pointer_info.accessible); \
	if (args->hsa_amd_pointer_info.accessible != NULL) { \
		printf("-> %p", args->hsa_amd_pointer_info.accessible__ref.ptr1); \
		if (args->hsa_amd_pointer_info.accessible__ref.ptr1 != NULL) { \
			printf(" -> {\n"); \
			printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_pointer_info.accessible__ref.val.handle); \
			printf("\t}\n"); \
		} else { printf("\n"); }; \
	} else { printf("\n"); }; \
};

//	hsa_cache_t cache ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_cache_info_t attribute (enum);
//	void * value (void*);
#define PROCESS_ARGS_hsa_cache_get_info(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_cache_get_info.retval); \
	printf("\thsa_cache_t cache = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_cache_get_info.cache.handle); \
	printf("\t}\n"); \
	printf("\thsa_cache_info_t attribute = %d\n", args->hsa_cache_get_info.attribute); \
	printf("\tvoid * value = %p", args->hsa_cache_get_info.value); \
	printf("\n"); \
};

//	void * ptr (void*);
//	size_t size (unsigned long);
//	hsa_amd_svm_attribute_pair_t * attribute_list ({
//		uint64_t attribute (unsigned long);
//		uint64_t value (unsigned long);
//	});
//	size_t attribute_count (unsigned long);
#define PROCESS_ARGS_hsa_amd_svm_attributes_get(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_svm_attributes_get.retval); \
	printf("\tvoid * ptr = %p", args->hsa_amd_svm_attributes_get.ptr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_amd_svm_attributes_get.size); \
	printf("\thsa_amd_svm_attribute_pair_t * attribute_list = %p", args->hsa_amd_svm_attributes_get.attribute_list); \
	if (args->hsa_amd_svm_attributes_get.attribute_list != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t attribute = %lu\n", args->hsa_amd_svm_attributes_get.attribute_list__ref.val.attribute); \
		printf("\t\tuint64_t value = %lu\n", args->hsa_amd_svm_attributes_get.attribute_list__ref.val.value); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t attribute_count = %lu\n", args->hsa_amd_svm_attributes_get.attribute_count); \
};

//	uint32_t num_signals (unsigned int);
//	const hsa_signal_t * signals ({
//		uint64_t handle (unsigned long);
//	});
//	uint32_t num_consumers (unsigned int);
//	const hsa_agent_t * consumers ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_group_t * signal_group ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_signal_group_create(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_signal_group_create.retval); \
	printf("\tuint32_t num_signals = %u\n", args->hsa_signal_group_create.num_signals); \
	printf("\tconst hsa_signal_t * signals = %p", args->hsa_signal_group_create.signals); \
	if (args->hsa_signal_group_create.signals != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_group_create.signals__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint32_t num_consumers = %u\n", args->hsa_signal_group_create.num_consumers); \
	printf("\tconst hsa_agent_t * consumers = %p", args->hsa_signal_group_create.consumers); \
	if (args->hsa_signal_group_create.consumers != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_group_create.consumers__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_signal_group_t * signal_group = %p", args->hsa_signal_group_create.signal_group); \
	if (args->hsa_signal_group_create.signal_group != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_group_create.signal_group__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	void * ptr (void*);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hsa_memory_deregister(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_memory_deregister.retval); \
	printf("\tvoid * ptr = %p", args->hsa_memory_deregister.ptr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_memory_deregister.size); \
};

//	const hsa_amd_ipc_memory_t * handle ({
//		uint32_t[8] handle (unsigned int);
//	});
//	size_t len (unsigned long);
//	uint32_t num_agents (unsigned int);
//	const hsa_agent_t * mapping_agents ({
//		uint64_t handle (unsigned long);
//	});
//	void ** mapped_ptr (void**);
#define PROCESS_ARGS_hsa_amd_ipc_memory_attach(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_ipc_memory_attach.retval); \
	printf("\tconst hsa_amd_ipc_memory_t * handle = %p", args->hsa_amd_ipc_memory_attach.handle); \
	if (args->hsa_amd_ipc_memory_attach.handle != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t[8] handle = %u\n", args->hsa_amd_ipc_memory_attach.handle__ref.val.handle[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t len = %lu\n", args->hsa_amd_ipc_memory_attach.len); \
	printf("\tuint32_t num_agents = %u\n", args->hsa_amd_ipc_memory_attach.num_agents); \
	printf("\tconst hsa_agent_t * mapping_agents = %p", args->hsa_amd_ipc_memory_attach.mapping_agents); \
	if (args->hsa_amd_ipc_memory_attach.mapping_agents != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_ipc_memory_attach.mapping_agents__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tvoid ** mapped_ptr = %p", args->hsa_amd_ipc_memory_attach.mapped_ptr); \
	if (args->hsa_amd_ipc_memory_attach.mapped_ptr != NULL) { \
		printf("-> %p", args->hsa_amd_ipc_memory_attach.mapped_ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint32_t num_cu_mask_count (unsigned int);
//	uint32_t * cu_mask (unsigned int*);
#define PROCESS_ARGS_hsa_amd_queue_cu_get_mask(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_queue_cu_get_mask.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_amd_queue_cu_get_mask.queue); \
	if (args->hsa_amd_queue_cu_get_mask.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_amd_queue_cu_get_mask.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_amd_queue_cu_get_mask.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_amd_queue_cu_get_mask.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_amd_queue_cu_get_mask.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_amd_queue_cu_get_mask.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_amd_queue_cu_get_mask.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint32_t num_cu_mask_count = %u\n", args->hsa_amd_queue_cu_get_mask.num_cu_mask_count); \
	printf("\tuint32_t * cu_mask = %p", args->hsa_amd_queue_cu_get_mask.cu_mask); \
	if (args->hsa_amd_queue_cu_get_mask.cu_mask != NULL) { \
		printf(" -> %u\n", args->hsa_amd_queue_cu_get_mask.cu_mask__ref.val); \
	} else { printf("\n"); }; \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_add_write_index_scacq_screl(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_add_write_index_scacq_screl.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_add_write_index_scacq_screl.queue); \
	if (args->hsa_queue_add_write_index_scacq_screl.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_add_write_index_scacq_screl.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_add_write_index_scacq_screl.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_add_write_index_scacq_screl.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_add_write_index_scacq_screl.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_add_write_index_scacq_screl.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_add_write_index_scacq_screl.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_add_write_index_scacq_screl.value); \
};

//	uint16_t extension (unsigned short);
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	uint16_t version_major (unsigned short);
//	uint16_t * version_minor (unsigned short*);
//	_Bool * result (unknown);
#define PROCESS_ARGS_hsa_agent_major_extension_supported(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_agent_major_extension_supported.retval); \
	printf("\tuint16_t extension = %hu\n", args->hsa_agent_major_extension_supported.extension); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_agent_major_extension_supported.agent.handle); \
	printf("\t}\n"); \
	printf("\tuint16_t version_major = %hu\n", args->hsa_agent_major_extension_supported.version_major); \
	printf("\tuint16_t * version_minor = %p", args->hsa_agent_major_extension_supported.version_minor); \
	if (args->hsa_agent_major_extension_supported.version_minor != NULL) { \
		printf(" -> %hu\n", args->hsa_agent_major_extension_supported.version_minor__ref.val); \
	} else { printf("\n"); }; \
	printf("\t_Bool * result = N/A, try to update csv files\n"); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_ext_sampler_t sampler ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_ext_sampler_destroy(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_ext_sampler_destroy.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_sampler_destroy.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_ext_sampler_t sampler = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_sampler_destroy.sampler.handle); \
	printf("\t}\n"); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	uint32_t size (unsigned int);
//	hsa_queue_type32_t type (unsigned int);
//	void (*)(hsa_status_t, hsa_queue_t *, void *) callback (function);
//	void * data (void*);
//	uint32_t private_segment_size (unsigned int);
//	uint32_t group_segment_size (unsigned int);
//	hsa_queue_t ** queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
#define PROCESS_ARGS_hsa_queue_create(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_queue_create.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_queue_create.agent.handle); \
	printf("\t}\n"); \
	printf("\tuint32_t size = %u\n", args->hsa_queue_create.size); \
	printf("\thsa_queue_type32_t type = %u\n", args->hsa_queue_create.type); \
	printf("\tvoid (*)(hsa_status_t, hsa_queue_t *, void *) callback = %p\n", args->hsa_queue_create.callback); \
	printf("\tvoid * data = %p", args->hsa_queue_create.data); \
	printf("\n"); \
	printf("\tuint32_t private_segment_size = %u\n", args->hsa_queue_create.private_segment_size); \
	printf("\tuint32_t group_segment_size = %u\n", args->hsa_queue_create.group_segment_size); \
	printf("\thsa_queue_t ** queue = %p", args->hsa_queue_create.queue); \
	if (args->hsa_queue_create.queue != NULL) { \
		printf("-> %p", args->hsa_queue_create.queue__ref.ptr1); \
		if (args->hsa_queue_create.queue__ref.ptr1 != NULL) { \
			printf(" -> {\n"); \
			printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_create.queue__ref.val.type); \
			printf("\t\tuint32_t features = %u\n", args->hsa_queue_create.queue__ref.val.features); \
			printf("\t\thsa_signal_t doorbell_signal = {\n"); \
			printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_create.queue__ref.val.doorbell_signal.handle); \
			printf("\t\t}\n"); \
			printf("\t\tuint32_t size = %u\n", args->hsa_queue_create.queue__ref.val.size); \
			printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_create.queue__ref.val.reserved1); \
			printf("\t\tuint64_t id = %lu\n", args->hsa_queue_create.queue__ref.val.id); \
			printf("\t}\n"); \
		} else { printf("\n"); }; \
	} else { printf("\n"); }; \
};

//	hsa_amd_vmem_alloc_handle_t memory_handle ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_memory_pool_t * pool ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_memory_type_t * type (enum*);
#define PROCESS_ARGS_hsa_amd_vmem_get_alloc_properties_from_handle(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_vmem_get_alloc_properties_from_handle.retval); \
	printf("\thsa_amd_vmem_alloc_handle_t memory_handle = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_vmem_get_alloc_properties_from_handle.memory_handle.handle); \
	printf("\t}\n"); \
	printf("\thsa_amd_memory_pool_t * pool = %p", args->hsa_amd_vmem_get_alloc_properties_from_handle.pool); \
	if (args->hsa_amd_vmem_get_alloc_properties_from_handle.pool != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_vmem_get_alloc_properties_from_handle.pool__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_amd_memory_type_t * type = %p", args->hsa_amd_vmem_get_alloc_properties_from_handle.type); \
	if (args->hsa_amd_vmem_get_alloc_properties_from_handle.type != NULL) { \
		printf(" -> %d\n", args->hsa_amd_vmem_get_alloc_properties_from_handle.type__ref.val); \
	} else { printf("\n"); }; \
};

//	hsa_amd_memory_pool_t memory_pool ({
//		uint64_t handle (unsigned long);
//	});
//	size_t size (unsigned long);
//	uint32_t flags (unsigned int);
//	void ** ptr (void**);
#define PROCESS_ARGS_hsa_amd_memory_pool_allocate(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_memory_pool_allocate.retval); \
	printf("\thsa_amd_memory_pool_t memory_pool = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_pool_allocate.memory_pool.handle); \
	printf("\t}\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_amd_memory_pool_allocate.size); \
	printf("\tuint32_t flags = %u\n", args->hsa_amd_memory_pool_allocate.flags); \
	printf("\tvoid ** ptr = %p", args->hsa_amd_memory_pool_allocate.ptr); \
	if (args->hsa_amd_memory_pool_allocate.ptr != NULL) { \
		printf("-> %p", args->hsa_amd_memory_pool_allocate.ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_or_release(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_or_release.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_or_release.value); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t expected (unsigned long);
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_cas_write_index_acq_rel(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_cas_write_index_acq_rel.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_cas_write_index_acq_rel.queue); \
	if (args->hsa_queue_cas_write_index_acq_rel.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_cas_write_index_acq_rel.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_cas_write_index_acq_rel.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_cas_write_index_acq_rel.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_cas_write_index_acq_rel.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_cas_write_index_acq_rel.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_cas_write_index_acq_rel.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t expected = %lu\n", args->hsa_queue_cas_write_index_acq_rel.expected); \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_cas_write_index_acq_rel.value); \
};

//	hsa_code_object_t code_object ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(size_t, hsa_callback_data_t, void **) alloc_callback (function);
//	hsa_callback_data_t callback_data ({
//		uint64_t handle (unsigned long);
//	});
//	const char * options (string*);
//	void ** serialized_code_object (void**);
//	size_t * serialized_code_object_size (unsigned long*);
#define PROCESS_ARGS_hsa_code_object_serialize(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_code_object_serialize.retval); \
	printf("\thsa_code_object_t code_object = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_code_object_serialize.code_object.handle); \
	printf("\t}\n"); \
	printf("\thsa_status_t (*)(size_t, hsa_callback_data_t, void **) alloc_callback = %p\n", args->hsa_code_object_serialize.alloc_callback); \
	printf("\thsa_callback_data_t callback_data = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_code_object_serialize.callback_data.handle); \
	printf("\t}\n"); \
	printf("\tconst char * options = %p", args->hsa_code_object_serialize.options); \
	if (args->hsa_code_object_serialize.options != NULL) { \
		printf(" -> %s\n", args->hsa_code_object_serialize.options__ref.val); \
	} else { printf("\n"); }; \
	printf("\tvoid ** serialized_code_object = %p", args->hsa_code_object_serialize.serialized_code_object); \
	if (args->hsa_code_object_serialize.serialized_code_object != NULL) { \
		printf("-> %p", args->hsa_code_object_serialize.serialized_code_object__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t * serialized_code_object_size = %p", args->hsa_code_object_serialize.serialized_code_object_size); \
	if (args->hsa_code_object_serialize.serialized_code_object_size != NULL) { \
		printf(" -> %lu\n", args->hsa_code_object_serialize.serialized_code_object_size__ref.val); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_xor_acquire(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_xor_acquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_xor_acquire.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	uint64_t agent_tick (unsigned long);
//	uint64_t * system_tick (unsigned long*);
#define PROCESS_ARGS_hsa_amd_profiling_convert_tick_to_system_domain(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_profiling_convert_tick_to_system_domain.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_profiling_convert_tick_to_system_domain.agent.handle); \
	printf("\t}\n"); \
	printf("\tuint64_t agent_tick = %lu\n", args->hsa_amd_profiling_convert_tick_to_system_domain.agent_tick); \
	printf("\tuint64_t * system_tick = %p", args->hsa_amd_profiling_convert_tick_to_system_domain.system_tick); \
	if (args->hsa_amd_profiling_convert_tick_to_system_domain.system_tick != NULL) { \
		printf(" -> %lu\n", args->hsa_amd_profiling_convert_tick_to_system_domain.system_tick__ref.val); \
	} else { printf("\n"); }; \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_destroy(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_destroy.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_destroy.executable.handle); \
	printf("\t}\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_add_screlease(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_add_screlease.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_add_screlease.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_signal_load_acquire(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_load_acquire.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_load_acquire.signal.handle); \
	printf("\t}\n"); \
};

//	hsa_profile_t profile (enum);
//	hsa_default_float_rounding_mode_t default_float_rounding_mode (enum);
//	const char * options (string*);
//	hsa_executable_t * executable ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_create_alt(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_create_alt.retval); \
	printf("\thsa_profile_t profile = %d\n", args->hsa_executable_create_alt.profile); \
	printf("\thsa_default_float_rounding_mode_t default_float_rounding_mode = %d\n", args->hsa_executable_create_alt.default_float_rounding_mode); \
	printf("\tconst char * options = %p", args->hsa_executable_create_alt.options); \
	if (args->hsa_executable_create_alt.options != NULL) { \
		printf(" -> %s\n", args->hsa_executable_create_alt.options__ref.val); \
	} else { printf("\n"); }; \
	printf("\thsa_executable_t * executable = %p", args->hsa_executable_create_alt.executable); \
	if (args->hsa_executable_create_alt.executable != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_create_alt.executable__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	const hsa_pitched_ptr_t * dst ({
//		size_t pitch (unsigned long);
//		size_t slice (unsigned long);
//	});
//	const hsa_dim3_t * dst_offset ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	const hsa_pitched_ptr_t * src ({
//		size_t pitch (unsigned long);
//		size_t slice (unsigned long);
//	});
//	const hsa_dim3_t * src_offset ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	const hsa_dim3_t * range ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	hsa_agent_t copy_agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_copy_direction_t dir (enum);
//	uint32_t num_dep_signals (unsigned int);
//	const hsa_signal_t * dep_signals ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_t completion_signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_memory_async_copy_rect(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_memory_async_copy_rect.retval); \
	printf("\tconst hsa_pitched_ptr_t * dst = %p", args->hsa_amd_memory_async_copy_rect.dst); \
	if (args->hsa_amd_memory_async_copy_rect.dst != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tsize_t pitch = %lu\n", args->hsa_amd_memory_async_copy_rect.dst__ref.val.pitch); \
		printf("\t\tsize_t slice = %lu\n", args->hsa_amd_memory_async_copy_rect.dst__ref.val.slice); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tconst hsa_dim3_t * dst_offset = %p", args->hsa_amd_memory_async_copy_rect.dst_offset); \
	if (args->hsa_amd_memory_async_copy_rect.dst_offset != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t x = %u\n", args->hsa_amd_memory_async_copy_rect.dst_offset__ref.val.x); \
		printf("\t\tuint32_t y = %u\n", args->hsa_amd_memory_async_copy_rect.dst_offset__ref.val.y); \
		printf("\t\tuint32_t z = %u\n", args->hsa_amd_memory_async_copy_rect.dst_offset__ref.val.z); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tconst hsa_pitched_ptr_t * src = %p", args->hsa_amd_memory_async_copy_rect.src); \
	if (args->hsa_amd_memory_async_copy_rect.src != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tsize_t pitch = %lu\n", args->hsa_amd_memory_async_copy_rect.src__ref.val.pitch); \
		printf("\t\tsize_t slice = %lu\n", args->hsa_amd_memory_async_copy_rect.src__ref.val.slice); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tconst hsa_dim3_t * src_offset = %p", args->hsa_amd_memory_async_copy_rect.src_offset); \
	if (args->hsa_amd_memory_async_copy_rect.src_offset != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t x = %u\n", args->hsa_amd_memory_async_copy_rect.src_offset__ref.val.x); \
		printf("\t\tuint32_t y = %u\n", args->hsa_amd_memory_async_copy_rect.src_offset__ref.val.y); \
		printf("\t\tuint32_t z = %u\n", args->hsa_amd_memory_async_copy_rect.src_offset__ref.val.z); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tconst hsa_dim3_t * range = %p", args->hsa_amd_memory_async_copy_rect.range); \
	if (args->hsa_amd_memory_async_copy_rect.range != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t x = %u\n", args->hsa_amd_memory_async_copy_rect.range__ref.val.x); \
		printf("\t\tuint32_t y = %u\n", args->hsa_amd_memory_async_copy_rect.range__ref.val.y); \
		printf("\t\tuint32_t z = %u\n", args->hsa_amd_memory_async_copy_rect.range__ref.val.z); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_agent_t copy_agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_async_copy_rect.copy_agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_amd_copy_direction_t dir = %d\n", args->hsa_amd_memory_async_copy_rect.dir); \
	printf("\tuint32_t num_dep_signals = %u\n", args->hsa_amd_memory_async_copy_rect.num_dep_signals); \
	printf("\tconst hsa_signal_t * dep_signals = %p", args->hsa_amd_memory_async_copy_rect.dep_signals); \
	if (args->hsa_amd_memory_async_copy_rect.dep_signals != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_async_copy_rect.dep_signals__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_signal_t completion_signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_async_copy_rect.completion_signal.handle); \
	printf("\t}\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_signal_load_scacquire(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_load_scacquire.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_load_scacquire.signal.handle); \
	printf("\t}\n"); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_cache_t, void *) callback (function);
//	void * data (void*);
#define PROCESS_ARGS_hsa_agent_iterate_caches(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_agent_iterate_caches.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_agent_iterate_caches.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_status_t (*)(hsa_cache_t, void *) callback = %p\n", args->hsa_agent_iterate_caches.callback); \
	printf("\tvoid * data = %p", args->hsa_agent_iterate_caches.data); \
	printf("\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t expected (long);
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_cas_acq_rel(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_cas_acq_rel.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_cas_acq_rel.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t expected = %ld\n", args->hsa_signal_cas_acq_rel.expected); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_cas_acq_rel.value); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
#define PROCESS_ARGS_hsa_queue_load_read_index_relaxed(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_load_read_index_relaxed.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_load_read_index_relaxed.queue); \
	if (args->hsa_queue_load_read_index_relaxed.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_load_read_index_relaxed.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_load_read_index_relaxed.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_load_read_index_relaxed.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_load_read_index_relaxed.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_load_read_index_relaxed.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_load_read_index_relaxed.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_isa_t, void *) callback (function);
//	void * data (void*);
#define PROCESS_ARGS_hsa_agent_iterate_isas(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_agent_iterate_isas.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_agent_iterate_isas.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_status_t (*)(hsa_isa_t, void *) callback = %p\n", args->hsa_agent_iterate_isas.callback); \
	printf("\tvoid * data = %p", args->hsa_agent_iterate_isas.data); \
	printf("\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_xor_relaxed(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_xor_relaxed.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_xor_relaxed.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_subtract_acq_rel(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_subtract_acq_rel.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_subtract_acq_rel.value); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
#define PROCESS_ARGS_hsa_queue_load_read_index_acquire(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_load_read_index_acquire.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_load_read_index_acquire.queue); \
	if (args->hsa_queue_load_read_index_acquire.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_load_read_index_acquire.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_load_read_index_acquire.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_load_read_index_acquire.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_load_read_index_acquire.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_load_read_index_acquire.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_load_read_index_acquire.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_isa_t isa ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_isa_info_t attribute (enum);
//	void * value (void*);
#define PROCESS_ARGS_hsa_isa_get_info_alt(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_isa_get_info_alt.retval); \
	printf("\thsa_isa_t isa = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_isa_get_info_alt.isa.handle); \
	printf("\t}\n"); \
	printf("\thsa_isa_info_t attribute = %d\n", args->hsa_isa_get_info_alt.attribute); \
	printf("\tvoid * value = %p", args->hsa_isa_get_info_alt.value); \
	printf("\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_and_scacquire(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_and_scacquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_and_scacquire.value); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_add_write_index_release(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_add_write_index_release.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_add_write_index_release.queue); \
	if (args->hsa_queue_add_write_index_release.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_add_write_index_release.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_add_write_index_release.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_add_write_index_release.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_add_write_index_release.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_add_write_index_release.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_add_write_index_release.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_add_write_index_release.value); \
};

//	hsa_system_info_t attribute (enum);
//	void * value (void*);
#define PROCESS_ARGS_hsa_system_get_info(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_system_get_info.retval); \
	printf("\thsa_system_info_t attribute = %d\n", args->hsa_system_get_info.attribute); \
	printf("\tvoid * value = %p", args->hsa_system_get_info.value); \
	printf("\n"); \
};

//	void * ptr (void*);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hsa_memory_register(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_memory_register.retval); \
	printf("\tvoid * ptr = %p", args->hsa_memory_register.ptr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_memory_register.size); \
};

//	hsa_isa_t isa ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_fp_type_t fp_type (enum);
//	hsa_flush_mode_t flush_mode (enum);
//	hsa_round_method_t * round_method (enum*);
#define PROCESS_ARGS_hsa_isa_get_round_method(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_isa_get_round_method.retval); \
	printf("\thsa_isa_t isa = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_isa_get_round_method.isa.handle); \
	printf("\t}\n"); \
	printf("\thsa_fp_type_t fp_type = %d\n", args->hsa_isa_get_round_method.fp_type); \
	printf("\thsa_flush_mode_t flush_mode = %d\n", args->hsa_isa_get_round_method.flush_mode); \
	printf("\thsa_round_method_t * round_method = %p", args->hsa_isa_get_round_method.round_method); \
	if (args->hsa_isa_get_round_method.round_method != NULL) { \
		printf(" -> %d\n", args->hsa_isa_get_round_method.round_method__ref.val); \
	} else { printf("\n"); }; \
};

//	hsa_isa_t isa ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_wavefront_t, void *) callback (function);
//	void * data (void*);
#define PROCESS_ARGS_hsa_isa_iterate_wavefronts(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_isa_iterate_wavefronts.retval); \
	printf("\thsa_isa_t isa = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_isa_iterate_wavefronts.isa.handle); \
	printf("\t}\n"); \
	printf("\thsa_status_t (*)(hsa_wavefront_t, void *) callback = %p\n", args->hsa_isa_iterate_wavefronts.callback); \
	printf("\tvoid * data = %p", args->hsa_isa_iterate_wavefronts.data); \
	printf("\n"); \
};

//	void * va (void*);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hsa_amd_vmem_unmap(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_vmem_unmap.retval); \
	printf("\tvoid * va = %p", args->hsa_amd_vmem_unmap.va); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_amd_vmem_unmap.size); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_subtract_acquire(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_subtract_acquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_subtract_acquire.value); \
};

//	uint16_t extension (unsigned short);
//	uint16_t version_major (unsigned short);
//	size_t table_length (unsigned long);
//	void * table (void*);
#define PROCESS_ARGS_hsa_system_get_major_extension_table(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_system_get_major_extension_table.retval); \
	printf("\tuint16_t extension = %hu\n", args->hsa_system_get_major_extension_table.extension); \
	printf("\tuint16_t version_major = %hu\n", args->hsa_system_get_major_extension_table.version_major); \
	printf("\tsize_t table_length = %lu\n", args->hsa_system_get_major_extension_table.table_length); \
	printf("\tvoid * table = %p", args->hsa_system_get_major_extension_table.table); \
	printf("\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_store_release(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_store_release.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_store_release.value); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
#define PROCESS_ARGS_hsa_queue_load_write_index_scacquire(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_load_write_index_scacquire.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_load_write_index_scacquire.queue); \
	if (args->hsa_queue_load_write_index_scacquire.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_load_write_index_scacquire.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_load_write_index_scacquire.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_load_write_index_scacquire.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_load_write_index_scacquire.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_load_write_index_scacquire.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_load_write_index_scacquire.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_agent_t preferred_agent ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_spm_release(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_spm_release.retval); \
	printf("\thsa_agent_t preferred_agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_spm_release.preferred_agent.handle); \
	printf("\t}\n"); \
};

//	hsa_code_symbol_t code_symbol ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_code_symbol_info_t attribute (enum);
//	void * value (void*);
#define PROCESS_ARGS_hsa_code_symbol_get_info(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_code_symbol_get_info.retval); \
	printf("\thsa_code_symbol_t code_symbol = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_code_symbol_get_info.code_symbol.handle); \
	printf("\t}\n"); \
	printf("\thsa_code_symbol_info_t attribute = %d\n", args->hsa_code_symbol_get_info.attribute); \
	printf("\tvoid * value = %p", args->hsa_code_symbol_get_info.value); \
	printf("\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_condition_t condition (enum);
//	hsa_signal_value_t compare_value (long);
//	uint64_t timeout_hint (unsigned long);
//	hsa_wait_state_t wait_state_hint (enum);
#define PROCESS_ARGS_hsa_signal_wait_acquire(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_wait_acquire.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_wait_acquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_condition_t condition = %d\n", args->hsa_signal_wait_acquire.condition); \
	printf("\thsa_signal_value_t compare_value = %ld\n", args->hsa_signal_wait_acquire.compare_value); \
	printf("\tuint64_t timeout_hint = %lu\n", args->hsa_signal_wait_acquire.timeout_hint); \
	printf("\thsa_wait_state_t wait_state_hint = %d\n", args->hsa_signal_wait_acquire.wait_state_hint); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t expected (long);
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_cas_release(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_cas_release.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_cas_release.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t expected = %ld\n", args->hsa_signal_cas_release.expected); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_cas_release.value); \
};

//	hsa_amd_memory_pool_t memory_pool ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_memory_pool_info_t attribute (enum);
//	void * value (void*);
#define PROCESS_ARGS_hsa_amd_memory_pool_get_info(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_memory_pool_get_info.retval); \
	printf("\thsa_amd_memory_pool_t memory_pool = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_pool_get_info.memory_pool.handle); \
	printf("\t}\n"); \
	printf("\thsa_amd_memory_pool_info_t attribute = %d\n", args->hsa_amd_memory_pool_get_info.attribute); \
	printf("\tvoid * value = %p", args->hsa_amd_memory_pool_get_info.value); \
	printf("\n"); \
};

//	const void * ptr (void*);
//	void * userdata (void*);
#define PROCESS_ARGS_hsa_amd_pointer_info_set_userdata(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_pointer_info_set_userdata.retval); \
	printf("\tconst void * ptr = %p", args->hsa_amd_pointer_info_set_userdata.ptr); \
	printf("\n"); \
	printf("\tvoid * userdata = %p", args->hsa_amd_pointer_info_set_userdata.userdata); \
	printf("\n"); \
};

//	void * va (void*);
//	hsa_access_permission_t * perms (enum*);
//	hsa_agent_t agent_handle ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_vmem_get_access(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_vmem_get_access.retval); \
	printf("\tvoid * va = %p", args->hsa_amd_vmem_get_access.va); \
	printf("\n"); \
	printf("\thsa_access_permission_t * perms = %p", args->hsa_amd_vmem_get_access.perms); \
	if (args->hsa_amd_vmem_get_access.perms != NULL) { \
		printf(" -> %d\n", args->hsa_amd_vmem_get_access.perms__ref.val); \
	} else { printf("\n"); }; \
	printf("\thsa_agent_t agent_handle = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_vmem_get_access.agent_handle.handle); \
	printf("\t}\n"); \
};

//	hsa_status_t (*)(hsa_agent_t, void *) callback (function);
//	void * data (void*);
#define PROCESS_ARGS_hsa_iterate_agents(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_iterate_agents.retval); \
	printf("\thsa_status_t (*)(hsa_agent_t, void *) callback = %p\n", args->hsa_iterate_agents.callback); \
	printf("\tvoid * data = %p", args->hsa_iterate_agents.data); \
	printf("\n"); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_store_write_index_screlease(args) { \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_store_write_index_screlease.queue); \
	if (args->hsa_queue_store_write_index_screlease.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_store_write_index_screlease.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_store_write_index_screlease.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_store_write_index_screlease.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_store_write_index_screlease.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_store_write_index_screlease.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_store_write_index_screlease.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_store_write_index_screlease.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_region_t, void *) callback (function);
//	void * data (void*);
#define PROCESS_ARGS_hsa_agent_iterate_regions(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_agent_iterate_regions.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_agent_iterate_regions.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_status_t (*)(hsa_region_t, void *) callback = %p\n", args->hsa_agent_iterate_regions.callback); \
	printf("\tvoid * data = %p", args->hsa_agent_iterate_regions.data); \
	printf("\n"); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	const char * variable_name (string*);
//	void * address (void*);
#define PROCESS_ARGS_hsa_executable_readonly_variable_define(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_readonly_variable_define.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_readonly_variable_define.executable.handle); \
	printf("\t}\n"); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_readonly_variable_define.agent.handle); \
	printf("\t}\n"); \
	printf("\tconst char * variable_name = %p", args->hsa_executable_readonly_variable_define.variable_name); \
	if (args->hsa_executable_readonly_variable_define.variable_name != NULL) { \
		printf(" -> %s\n", args->hsa_executable_readonly_variable_define.variable_name__ref.val); \
	} else { printf("\n"); }; \
	printf("\tvoid * address = %p", args->hsa_executable_readonly_variable_define.address); \
	printf("\n"); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_executable_t, hsa_executable_symbol_t, void *) callback (function);
//	void * data (void*);
#define PROCESS_ARGS_hsa_executable_iterate_symbols(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_iterate_symbols.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_iterate_symbols.executable.handle); \
	printf("\t}\n"); \
	printf("\thsa_status_t (*)(hsa_executable_t, hsa_executable_symbol_t, void *) callback = %p\n", args->hsa_executable_iterate_symbols.callback); \
	printf("\tvoid * data = %p", args->hsa_executable_iterate_symbols.data); \
	printf("\n"); \
};

//	hsa_amd_vmem_alloc_handle_t memory_handle ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_vmem_handle_release(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_vmem_handle_release.retval); \
	printf("\thsa_amd_vmem_alloc_handle_t memory_handle = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_vmem_handle_release.memory_handle.handle); \
	printf("\t}\n"); \
};

//	hsa_amd_memory_pool_t src_memory_pool ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_memory_pool_t dst_memory_pool ({
//		uint64_t handle (unsigned long);
//	});
//	_Bool * result (unknown);
#define PROCESS_ARGS_hsa_amd_memory_pool_can_migrate(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_memory_pool_can_migrate.retval); \
	printf("\thsa_amd_memory_pool_t src_memory_pool = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_pool_can_migrate.src_memory_pool.handle); \
	printf("\t}\n"); \
	printf("\thsa_amd_memory_pool_t dst_memory_pool = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_pool_can_migrate.dst_memory_pool.handle); \
	printf("\t}\n"); \
	printf("\t_Bool * result = N/A, try to update csv files\n"); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_store_write_index_relaxed(args) { \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_store_write_index_relaxed.queue); \
	if (args->hsa_queue_store_write_index_relaxed.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_store_write_index_relaxed.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_store_write_index_relaxed.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_store_write_index_relaxed.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_store_write_index_relaxed.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_store_write_index_relaxed.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_store_write_index_relaxed.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_store_write_index_relaxed.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_info_t attribute (enum);
//	void * value (void*);
#define PROCESS_ARGS_hsa_amd_image_get_info_max_dim(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_image_get_info_max_dim.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_image_get_info_max_dim.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_agent_info_t attribute = %d\n", args->hsa_amd_image_get_info_max_dim.attribute); \
	printf("\tvoid * value = %p", args->hsa_amd_image_get_info_max_dim.value); \
	printf("\n"); \
};

//	hsa_agent_t preferred_agent ({
//		uint64_t handle (unsigned long);
//	});
//	size_t size_in_bytes (unsigned long);
//	uint32_t * timeout (unsigned int*);
//	uint32_t * size_copied (unsigned int*);
//	void * dest (void*);
//	_Bool * is_data_loss (unknown);
#define PROCESS_ARGS_hsa_amd_spm_set_dest_buffer(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_spm_set_dest_buffer.retval); \
	printf("\thsa_agent_t preferred_agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_spm_set_dest_buffer.preferred_agent.handle); \
	printf("\t}\n"); \
	printf("\tsize_t size_in_bytes = %lu\n", args->hsa_amd_spm_set_dest_buffer.size_in_bytes); \
	printf("\tuint32_t * timeout = %p", args->hsa_amd_spm_set_dest_buffer.timeout); \
	if (args->hsa_amd_spm_set_dest_buffer.timeout != NULL) { \
		printf(" -> %u\n", args->hsa_amd_spm_set_dest_buffer.timeout__ref.val); \
	} else { printf("\n"); }; \
	printf("\tuint32_t * size_copied = %p", args->hsa_amd_spm_set_dest_buffer.size_copied); \
	if (args->hsa_amd_spm_set_dest_buffer.size_copied != NULL) { \
		printf(" -> %u\n", args->hsa_amd_spm_set_dest_buffer.size_copied__ref.val); \
	} else { printf("\n"); }; \
	printf("\tvoid * dest = %p", args->hsa_amd_spm_set_dest_buffer.dest); \
	printf("\n"); \
	printf("\t_Bool * is_data_loss = N/A, try to update csv files\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_condition_t condition (enum);
//	hsa_signal_value_t compare_value (long);
//	uint64_t timeout_hint (unsigned long);
//	hsa_wait_state_t wait_state_hint (enum);
#define PROCESS_ARGS_hsa_signal_wait_relaxed(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_wait_relaxed.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_wait_relaxed.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_condition_t condition = %d\n", args->hsa_signal_wait_relaxed.condition); \
	printf("\thsa_signal_value_t compare_value = %ld\n", args->hsa_signal_wait_relaxed.compare_value); \
	printf("\tuint64_t timeout_hint = %lu\n", args->hsa_signal_wait_relaxed.timeout_hint); \
	printf("\thsa_wait_state_t wait_state_hint = %d\n", args->hsa_signal_wait_relaxed.wait_state_hint); \
};

//	const void * ptr (void*);
//	size_t size (unsigned long);
//	int * dmabuf (int*);
//	uint64_t * offset (unsigned long*);
#define PROCESS_ARGS_hsa_amd_portable_export_dmabuf(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_portable_export_dmabuf.retval); \
	printf("\tconst void * ptr = %p", args->hsa_amd_portable_export_dmabuf.ptr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_amd_portable_export_dmabuf.size); \
	printf("\tint * dmabuf = %p", args->hsa_amd_portable_export_dmabuf.dmabuf); \
	if (args->hsa_amd_portable_export_dmabuf.dmabuf != NULL) { \
		printf(" -> %d\n", args->hsa_amd_portable_export_dmabuf.dmabuf__ref.val); \
	} else { printf("\n"); }; \
	printf("\tuint64_t * offset = %p", args->hsa_amd_portable_export_dmabuf.offset); \
	if (args->hsa_amd_portable_export_dmabuf.offset != NULL) { \
		printf(" -> %lu\n", args->hsa_amd_portable_export_dmabuf.offset__ref.val); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_store_screlease(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_store_screlease.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_store_screlease.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_or_acquire(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_or_acquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_or_acquire.value); \
};

//	hsa_code_object_t code_object ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_code_object_destroy(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_code_object_destroy.retval); \
	printf("\thsa_code_object_t code_object = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_code_object_destroy.code_object.handle); \
	printf("\t}\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_subtract_screlease(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_subtract_screlease.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_subtract_screlease.value); \
};

//	hsa_region_t region ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_region_info_t attribute (enum);
//	void * value (void*);
#define PROCESS_ARGS_hsa_region_get_info(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_region_get_info.retval); \
	printf("\thsa_region_t region = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_region_get_info.region.handle); \
	printf("\t}\n"); \
	printf("\thsa_region_info_t attribute = %d\n", args->hsa_region_get_info.attribute); \
	printf("\tvoid * value = %p", args->hsa_region_get_info.value); \
	printf("\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_subtract_scacq_screl(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_subtract_scacq_screl.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_subtract_scacq_screl.value); \
};

//	_Bool enable (unknown);
#define PROCESS_ARGS_hsa_amd_profiling_async_copy_enable(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_profiling_async_copy_enable.retval); \
	printf("\t_Bool enable = N/A, try to update csv files\n"); \
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
//	hsa_queue_t ** queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
#define PROCESS_ARGS_hsa_soft_queue_create(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_soft_queue_create.retval); \
	printf("\thsa_region_t region = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_soft_queue_create.region.handle); \
	printf("\t}\n"); \
	printf("\tuint32_t size = %u\n", args->hsa_soft_queue_create.size); \
	printf("\thsa_queue_type32_t type = %u\n", args->hsa_soft_queue_create.type); \
	printf("\tuint32_t features = %u\n", args->hsa_soft_queue_create.features); \
	printf("\thsa_signal_t doorbell_signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_soft_queue_create.doorbell_signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_queue_t ** queue = %p", args->hsa_soft_queue_create.queue); \
	if (args->hsa_soft_queue_create.queue != NULL) { \
		printf("-> %p", args->hsa_soft_queue_create.queue__ref.ptr1); \
		if (args->hsa_soft_queue_create.queue__ref.ptr1 != NULL) { \
			printf(" -> {\n"); \
			printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_soft_queue_create.queue__ref.val.type); \
			printf("\t\tuint32_t features = %u\n", args->hsa_soft_queue_create.queue__ref.val.features); \
			printf("\t\thsa_signal_t doorbell_signal = {\n"); \
			printf("\t\t\tuint64_t handle = %lu\n", args->hsa_soft_queue_create.queue__ref.val.doorbell_signal.handle); \
			printf("\t\t}\n"); \
			printf("\t\tuint32_t size = %u\n", args->hsa_soft_queue_create.queue__ref.val.size); \
			printf("\t\tuint32_t reserved1 = %u\n", args->hsa_soft_queue_create.queue__ref.val.reserved1); \
			printf("\t\tuint64_t id = %lu\n", args->hsa_soft_queue_create.queue__ref.val.id); \
			printf("\t}\n"); \
		} else { printf("\n"); }; \
	} else { printf("\n"); }; \
};


#define PROCESS_ARGS_hsa_shut_down(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_shut_down.retval); \
\
};

//	hsa_code_object_t code_object ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_code_object_t, hsa_code_symbol_t, void *) callback (function);
//	void * data (void*);
#define PROCESS_ARGS_hsa_code_object_iterate_symbols(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_code_object_iterate_symbols.retval); \
	printf("\thsa_code_object_t code_object = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_code_object_iterate_symbols.code_object.handle); \
	printf("\t}\n"); \
	printf("\thsa_status_t (*)(hsa_code_object_t, hsa_code_symbol_t, void *) callback = %p\n", args->hsa_code_object_iterate_symbols.callback); \
	printf("\tvoid * data = %p", args->hsa_code_object_iterate_symbols.data); \
	printf("\n"); \
};

//	uint16_t extension (unsigned short);
//	const char ** name (string**);
#define PROCESS_ARGS_hsa_extension_get_name(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_extension_get_name.retval); \
	printf("\tuint16_t extension = %hu\n", args->hsa_extension_get_name.extension); \
	printf("\tconst char ** name = %p", args->hsa_extension_get_name.name); \
	if (args->hsa_extension_get_name.name != NULL) { \
		printf("-> %p", args->hsa_extension_get_name.name__ref.ptr1); \
		if (args->hsa_extension_get_name.name__ref.ptr1 != NULL) { \
			printf(" -> %s\n", args->hsa_extension_get_name.name__ref.val); \
		} else { printf("\n"); }; \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_exchange_relaxed(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_exchange_relaxed.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_exchange_relaxed.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_exchange_relaxed.value); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	const char * symbol_name (string*);
//	const hsa_agent_t * agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_executable_symbol_t * symbol ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_get_symbol_by_name(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_get_symbol_by_name.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_get_symbol_by_name.executable.handle); \
	printf("\t}\n"); \
	printf("\tconst char * symbol_name = %p", args->hsa_executable_get_symbol_by_name.symbol_name); \
	if (args->hsa_executable_get_symbol_by_name.symbol_name != NULL) { \
		printf(" -> %s\n", args->hsa_executable_get_symbol_by_name.symbol_name__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst hsa_agent_t * agent = %p", args->hsa_executable_get_symbol_by_name.agent); \
	if (args->hsa_executable_get_symbol_by_name.agent != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_get_symbol_by_name.agent__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_executable_symbol_t * symbol = %p", args->hsa_executable_get_symbol_by_name.symbol); \
	if (args->hsa_executable_get_symbol_by_name.symbol != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_get_symbol_by_name.symbol__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	const hsa_ext_image_descriptor_t * image_descriptor ({
//		hsa_ext_image_geometry_t geometry (enum);
//		size_t width (unsigned long);
//		size_t height (unsigned long);
//		size_t depth (unsigned long);
//		size_t array_size (unsigned long);
//		hsa_ext_image_format_t format ({
//			hsa_ext_image_channel_type32_t channel_type (unsigned int);
//			hsa_ext_image_channel_order32_t channel_order (unsigned int);
//		});
//	});
//	const void * image_data (void*);
//	hsa_access_permission_t access_permission (enum);
//	hsa_ext_image_data_layout_t image_data_layout (enum);
//	size_t image_data_row_pitch (unsigned long);
//	size_t image_data_slice_pitch (unsigned long);
//	hsa_ext_image_t * image ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_ext_image_create_with_layout(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_ext_image_create_with_layout.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_create_with_layout.agent.handle); \
	printf("\t}\n"); \
	printf("\tconst hsa_ext_image_descriptor_t * image_descriptor = %p", args->hsa_ext_image_create_with_layout.image_descriptor); \
	if (args->hsa_ext_image_create_with_layout.image_descriptor != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_ext_image_geometry_t geometry = %d\n", args->hsa_ext_image_create_with_layout.image_descriptor__ref.val.geometry); \
		printf("\t\tsize_t width = %lu\n", args->hsa_ext_image_create_with_layout.image_descriptor__ref.val.width); \
		printf("\t\tsize_t height = %lu\n", args->hsa_ext_image_create_with_layout.image_descriptor__ref.val.height); \
		printf("\t\tsize_t depth = %lu\n", args->hsa_ext_image_create_with_layout.image_descriptor__ref.val.depth); \
		printf("\t\tsize_t array_size = %lu\n", args->hsa_ext_image_create_with_layout.image_descriptor__ref.val.array_size); \
		printf("\t\thsa_ext_image_format_t format = {\n"); \
		printf("\t\t\thsa_ext_image_channel_type32_t channel_type = %u\n", args->hsa_ext_image_create_with_layout.image_descriptor__ref.val.format.channel_type); \
		printf("\t\t\thsa_ext_image_channel_order32_t channel_order = %u\n", args->hsa_ext_image_create_with_layout.image_descriptor__ref.val.format.channel_order); \
		printf("\t\t}\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tconst void * image_data = %p", args->hsa_ext_image_create_with_layout.image_data); \
	printf("\n"); \
	printf("\thsa_access_permission_t access_permission = %d\n", args->hsa_ext_image_create_with_layout.access_permission); \
	printf("\thsa_ext_image_data_layout_t image_data_layout = %d\n", args->hsa_ext_image_create_with_layout.image_data_layout); \
	printf("\tsize_t image_data_row_pitch = %lu\n", args->hsa_ext_image_create_with_layout.image_data_row_pitch); \
	printf("\tsize_t image_data_slice_pitch = %lu\n", args->hsa_ext_image_create_with_layout.image_data_slice_pitch); \
	printf("\thsa_ext_image_t * image = %p", args->hsa_ext_image_create_with_layout.image); \
	if (args->hsa_ext_image_create_with_layout.image != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_create_with_layout.image__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
#define PROCESS_ARGS_hsa_queue_load_write_index_relaxed(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_load_write_index_relaxed.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_load_write_index_relaxed.queue); \
	if (args->hsa_queue_load_write_index_relaxed.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_load_write_index_relaxed.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_load_write_index_relaxed.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_load_write_index_relaxed.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_load_write_index_relaxed.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_load_write_index_relaxed.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_load_write_index_relaxed.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_ext_image_t src_image ({
//		uint64_t handle (unsigned long);
//	});
//	const hsa_dim3_t * src_offset ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	hsa_ext_image_t dst_image ({
//		uint64_t handle (unsigned long);
//	});
//	const hsa_dim3_t * dst_offset ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	const hsa_dim3_t * range ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
#define PROCESS_ARGS_hsa_ext_image_copy(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_ext_image_copy.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_copy.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_ext_image_t src_image = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_copy.src_image.handle); \
	printf("\t}\n"); \
	printf("\tconst hsa_dim3_t * src_offset = %p", args->hsa_ext_image_copy.src_offset); \
	if (args->hsa_ext_image_copy.src_offset != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t x = %u\n", args->hsa_ext_image_copy.src_offset__ref.val.x); \
		printf("\t\tuint32_t y = %u\n", args->hsa_ext_image_copy.src_offset__ref.val.y); \
		printf("\t\tuint32_t z = %u\n", args->hsa_ext_image_copy.src_offset__ref.val.z); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_ext_image_t dst_image = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_copy.dst_image.handle); \
	printf("\t}\n"); \
	printf("\tconst hsa_dim3_t * dst_offset = %p", args->hsa_ext_image_copy.dst_offset); \
	if (args->hsa_ext_image_copy.dst_offset != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t x = %u\n", args->hsa_ext_image_copy.dst_offset__ref.val.x); \
		printf("\t\tuint32_t y = %u\n", args->hsa_ext_image_copy.dst_offset__ref.val.y); \
		printf("\t\tuint32_t z = %u\n", args->hsa_ext_image_copy.dst_offset__ref.val.z); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tconst hsa_dim3_t * range = %p", args->hsa_ext_image_copy.range); \
	if (args->hsa_ext_image_copy.range != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t x = %u\n", args->hsa_ext_image_copy.range__ref.val.x); \
		printf("\t\tuint32_t y = %u\n", args->hsa_ext_image_copy.range__ref.val.y); \
		printf("\t\tuint32_t z = %u\n", args->hsa_ext_image_copy.range__ref.val.z); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	const void * code_object (void*);
//	size_t size (unsigned long);
//	hsa_code_object_reader_t * code_object_reader ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_code_object_reader_create_from_memory(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_code_object_reader_create_from_memory.retval); \
	printf("\tconst void * code_object = %p", args->hsa_code_object_reader_create_from_memory.code_object); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_code_object_reader_create_from_memory.size); \
	printf("\thsa_code_object_reader_t * code_object_reader = %p", args->hsa_code_object_reader_create_from_memory.code_object_reader); \
	if (args->hsa_code_object_reader_create_from_memory.code_object_reader != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_code_object_reader_create_from_memory.code_object_reader__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_xor_release(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_xor_release.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_xor_release.value); \
};

//	void * ptr (void*);
//	hsa_amd_deallocation_callback_t callback (function);
//	void * user_data (void*);
#define PROCESS_ARGS_hsa_amd_register_deallocation_callback(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_register_deallocation_callback.retval); \
	printf("\tvoid * ptr = %p", args->hsa_amd_register_deallocation_callback.ptr); \
	printf("\n"); \
	printf("\thsa_amd_deallocation_callback_t callback = %p\n", args->hsa_amd_register_deallocation_callback.callback); \
	printf("\tvoid * user_data = %p", args->hsa_amd_register_deallocation_callback.user_data); \
	printf("\n"); \
};

//	hsa_signal_group_t signal_group ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_signal_group_destroy(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_signal_group_destroy.retval); \
	printf("\thsa_signal_group_t signal_group = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_group_destroy.signal_group.handle); \
	printf("\t}\n"); \
};

//	int * dmabuf_fd (int*);
//	hsa_amd_vmem_alloc_handle_t handle ({
//		uint64_t handle (unsigned long);
//	});
//	uint64_t flags (unsigned long);
#define PROCESS_ARGS_hsa_amd_vmem_export_shareable_handle(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_vmem_export_shareable_handle.retval); \
	printf("\tint * dmabuf_fd = %p", args->hsa_amd_vmem_export_shareable_handle.dmabuf_fd); \
	if (args->hsa_amd_vmem_export_shareable_handle.dmabuf_fd != NULL) { \
		printf(" -> %d\n", args->hsa_amd_vmem_export_shareable_handle.dmabuf_fd__ref.val); \
	} else { printf("\n"); }; \
	printf("\thsa_amd_vmem_alloc_handle_t handle = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_vmem_export_shareable_handle.handle.handle); \
	printf("\t}\n"); \
	printf("\tuint64_t flags = %lu\n", args->hsa_amd_vmem_export_shareable_handle.flags); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_add_write_index_acq_rel(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_add_write_index_acq_rel.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_add_write_index_acq_rel.queue); \
	if (args->hsa_queue_add_write_index_acq_rel.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_add_write_index_acq_rel.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_add_write_index_acq_rel.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_add_write_index_acq_rel.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_add_write_index_acq_rel.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_add_write_index_acq_rel.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_add_write_index_acq_rel.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_add_write_index_acq_rel.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_signal_destroy(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_signal_destroy.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_destroy.signal.handle); \
	printf("\t}\n"); \
};

//	uint16_t extension (unsigned short);
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	uint16_t version_major (unsigned short);
//	uint16_t version_minor (unsigned short);
//	_Bool * result (unknown);
#define PROCESS_ARGS_hsa_agent_extension_supported(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_agent_extension_supported.retval); \
	printf("\tuint16_t extension = %hu\n", args->hsa_agent_extension_supported.extension); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_agent_extension_supported.agent.handle); \
	printf("\t}\n"); \
	printf("\tuint16_t version_major = %hu\n", args->hsa_agent_extension_supported.version_major); \
	printf("\tuint16_t version_minor = %hu\n", args->hsa_agent_extension_supported.version_minor); \
	printf("\t_Bool * result = N/A, try to update csv files\n"); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	const hsa_ext_image_descriptor_t * image_descriptor ({
//		hsa_ext_image_geometry_t geometry (enum);
//		size_t width (unsigned long);
//		size_t height (unsigned long);
//		size_t depth (unsigned long);
//		size_t array_size (unsigned long);
//		hsa_ext_image_format_t format ({
//			hsa_ext_image_channel_type32_t channel_type (unsigned int);
//			hsa_ext_image_channel_order32_t channel_order (unsigned int);
//		});
//	});
//	const hsa_amd_image_descriptor_t * image_layout ({
//		uint32_t version (unsigned int);
//		uint32_t deviceID (unsigned int);
//		uint32_t[1] data (unsigned int);
//	});
//	const void * image_data (void*);
//	hsa_access_permission_t access_permission (enum);
//	hsa_ext_image_t * image ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_image_create(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_image_create.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_image_create.agent.handle); \
	printf("\t}\n"); \
	printf("\tconst hsa_ext_image_descriptor_t * image_descriptor = %p", args->hsa_amd_image_create.image_descriptor); \
	if (args->hsa_amd_image_create.image_descriptor != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_ext_image_geometry_t geometry = %d\n", args->hsa_amd_image_create.image_descriptor__ref.val.geometry); \
		printf("\t\tsize_t width = %lu\n", args->hsa_amd_image_create.image_descriptor__ref.val.width); \
		printf("\t\tsize_t height = %lu\n", args->hsa_amd_image_create.image_descriptor__ref.val.height); \
		printf("\t\tsize_t depth = %lu\n", args->hsa_amd_image_create.image_descriptor__ref.val.depth); \
		printf("\t\tsize_t array_size = %lu\n", args->hsa_amd_image_create.image_descriptor__ref.val.array_size); \
		printf("\t\thsa_ext_image_format_t format = {\n"); \
		printf("\t\t\thsa_ext_image_channel_type32_t channel_type = %u\n", args->hsa_amd_image_create.image_descriptor__ref.val.format.channel_type); \
		printf("\t\t\thsa_ext_image_channel_order32_t channel_order = %u\n", args->hsa_amd_image_create.image_descriptor__ref.val.format.channel_order); \
		printf("\t\t}\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tconst hsa_amd_image_descriptor_t * image_layout = %p", args->hsa_amd_image_create.image_layout); \
	if (args->hsa_amd_image_create.image_layout != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t version = %u\n", args->hsa_amd_image_create.image_layout__ref.val.version); \
		printf("\t\tuint32_t deviceID = %u\n", args->hsa_amd_image_create.image_layout__ref.val.deviceID); \
		printf("\t\tuint32_t[1] data = %u\n", args->hsa_amd_image_create.image_layout__ref.val.data[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tconst void * image_data = %p", args->hsa_amd_image_create.image_data); \
	printf("\n"); \
	printf("\thsa_access_permission_t access_permission = %d\n", args->hsa_amd_image_create.access_permission); \
	printf("\thsa_ext_image_t * image = %p", args->hsa_amd_image_create.image); \
	if (args->hsa_amd_image_create.image != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_image_create.image__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_isa_t code_object_isa ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_isa_t agent_isa ({
//		uint64_t handle (unsigned long);
//	});
//	_Bool * result (unknown);
#define PROCESS_ARGS_hsa_isa_compatible(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_isa_compatible.retval); \
	printf("\thsa_isa_t code_object_isa = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_isa_compatible.code_object_isa.handle); \
	printf("\t}\n"); \
	printf("\thsa_isa_t agent_isa = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_isa_compatible.agent_isa.handle); \
	printf("\t}\n"); \
	printf("\t_Bool * result = N/A, try to update csv files\n"); \
};

//	hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	hsa_amd_queue_priority_t priority (enum);
#define PROCESS_ARGS_hsa_amd_queue_set_priority(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_queue_set_priority.retval); \
	printf("\thsa_queue_t * queue = %p", args->hsa_amd_queue_set_priority.queue); \
	if (args->hsa_amd_queue_set_priority.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_amd_queue_set_priority.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_amd_queue_set_priority.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_amd_queue_set_priority.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_amd_queue_set_priority.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_amd_queue_set_priority.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_amd_queue_set_priority.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_amd_queue_priority_t priority = %d\n", args->hsa_amd_queue_set_priority.priority); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_and_acq_rel(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_and_acq_rel.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_and_acq_rel.value); \
};

//	hsa_code_object_reader_t code_object_reader ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_code_object_reader_destroy(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_code_object_reader_destroy.retval); \
	printf("\thsa_code_object_reader_t code_object_reader = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_code_object_reader_destroy.code_object_reader.handle); \
	printf("\t}\n"); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t expected (unsigned long);
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_cas_write_index_release(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_cas_write_index_release.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_cas_write_index_release.queue); \
	if (args->hsa_queue_cas_write_index_release.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_cas_write_index_release.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_cas_write_index_release.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_cas_write_index_release.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_cas_write_index_release.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_cas_write_index_release.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_cas_write_index_release.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t expected = %lu\n", args->hsa_queue_cas_write_index_release.expected); \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_cas_write_index_release.value); \
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
//	const char * options (string*);
#define PROCESS_ARGS_hsa_executable_load_code_object(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_load_code_object.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_load_code_object.executable.handle); \
	printf("\t}\n"); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_load_code_object.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_code_object_t code_object = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_load_code_object.code_object.handle); \
	printf("\t}\n"); \
	printf("\tconst char * options = %p", args->hsa_executable_load_code_object.options); \
	if (args->hsa_executable_load_code_object.options != NULL) { \
		printf(" -> %s\n", args->hsa_executable_load_code_object.options__ref.val); \
	} else { printf("\n"); }; \
};

//	void * dst (void*);
//	hsa_agent_t dst_agent ({
//		uint64_t handle (unsigned long);
//	});
//	const void * src (void*);
//	hsa_agent_t src_agent ({
//		uint64_t handle (unsigned long);
//	});
//	size_t size (unsigned long);
//	uint32_t num_dep_signals (unsigned int);
//	const hsa_signal_t * dep_signals ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_t completion_signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_memory_async_copy(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_memory_async_copy.retval); \
	printf("\tvoid * dst = %p", args->hsa_amd_memory_async_copy.dst); \
	printf("\n"); \
	printf("\thsa_agent_t dst_agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_async_copy.dst_agent.handle); \
	printf("\t}\n"); \
	printf("\tconst void * src = %p", args->hsa_amd_memory_async_copy.src); \
	printf("\n"); \
	printf("\thsa_agent_t src_agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_async_copy.src_agent.handle); \
	printf("\t}\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_amd_memory_async_copy.size); \
	printf("\tuint32_t num_dep_signals = %u\n", args->hsa_amd_memory_async_copy.num_dep_signals); \
	printf("\tconst hsa_signal_t * dep_signals = %p", args->hsa_amd_memory_async_copy.dep_signals); \
	if (args->hsa_amd_memory_async_copy.dep_signals != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_async_copy.dep_signals__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_signal_t completion_signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_async_copy.completion_signal.handle); \
	printf("\t}\n"); \
};

//	void * host_ptr (void*);
#define PROCESS_ARGS_hsa_amd_memory_unlock(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_memory_unlock.retval); \
	printf("\tvoid * host_ptr = %p", args->hsa_amd_memory_unlock.host_ptr); \
	printf("\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_subtract_release(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_subtract_release.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_subtract_release.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_exchange_acquire(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_exchange_acquire.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_exchange_acquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_exchange_acquire.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_store_relaxed(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_store_relaxed.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_store_relaxed.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_subtract_scacquire(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_subtract_scacquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_subtract_scacquire.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_and_release(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_and_release.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_and_release.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t expected (long);
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_cas_acquire(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_cas_acquire.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_cas_acquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t expected = %ld\n", args->hsa_signal_cas_acquire.expected); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_cas_acquire.value); \
};

//	hsa_isa_t isa ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_profile_t profile (enum);
//	uint16_t * mask (unsigned short*);
#define PROCESS_ARGS_hsa_isa_get_exception_policies(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_isa_get_exception_policies.retval); \
	printf("\thsa_isa_t isa = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_isa_get_exception_policies.isa.handle); \
	printf("\t}\n"); \
	printf("\thsa_profile_t profile = %d\n", args->hsa_isa_get_exception_policies.profile); \
	printf("\tuint16_t * mask = %p", args->hsa_isa_get_exception_policies.mask); \
	if (args->hsa_isa_get_exception_policies.mask != NULL) { \
		printf(" -> %hu\n", args->hsa_isa_get_exception_policies.mask__ref.val); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_add_release(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_add_release.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_add_release.value); \
};

//	hsa_file_t file (int);
//	hsa_code_object_reader_t * code_object_reader ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_code_object_reader_create_from_file(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_code_object_reader_create_from_file.retval); \
	printf("\thsa_file_t file = %d\n", args->hsa_code_object_reader_create_from_file.file); \
	printf("\thsa_code_object_reader_t * code_object_reader = %p", args->hsa_code_object_reader_create_from_file.code_object_reader); \
	if (args->hsa_code_object_reader_create_from_file.code_object_reader != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_code_object_reader_create_from_file.code_object_reader__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_executable_symbol_t executable_symbol ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_executable_symbol_info_t attribute (enum);
//	void * value (void*);
#define PROCESS_ARGS_hsa_executable_symbol_get_info(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_symbol_get_info.retval); \
	printf("\thsa_executable_symbol_t executable_symbol = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_symbol_get_info.executable_symbol.handle); \
	printf("\t}\n"); \
	printf("\thsa_executable_symbol_info_t attribute = %d\n", args->hsa_executable_symbol_get_info.attribute); \
	printf("\tvoid * value = %p", args->hsa_executable_symbol_get_info.value); \
	printf("\n"); \
};

//	void * ptr (void*);
//	size_t len (unsigned long);
//	hsa_amd_ipc_memory_t * handle ({
//		uint32_t[8] handle (unsigned int);
//	});
#define PROCESS_ARGS_hsa_amd_ipc_memory_create(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_ipc_memory_create.retval); \
	printf("\tvoid * ptr = %p", args->hsa_amd_ipc_memory_create.ptr); \
	printf("\n"); \
	printf("\tsize_t len = %lu\n", args->hsa_amd_ipc_memory_create.len); \
	printf("\thsa_amd_ipc_memory_t * handle = %p", args->hsa_amd_ipc_memory_create.handle); \
	if (args->hsa_amd_ipc_memory_create.handle != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t[8] handle = %u\n", args->hsa_amd_ipc_memory_create.handle__ref.val.handle[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_store_write_index_release(args) { \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_store_write_index_release.queue); \
	if (args->hsa_queue_store_write_index_release.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_store_write_index_release.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_store_write_index_release.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_store_write_index_release.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_store_write_index_release.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_store_write_index_release.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_store_write_index_release.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_store_write_index_release.value); \
};

//	void * ptr (void*);
//	uint32_t value (unsigned int);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hsa_amd_memory_fill(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_memory_fill.retval); \
	printf("\tvoid * ptr = %p", args->hsa_amd_memory_fill.ptr); \
	printf("\n"); \
	printf("\tuint32_t value = %u\n", args->hsa_amd_memory_fill.value); \
	printf("\tsize_t count = %lu\n", args->hsa_amd_memory_fill.count); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_add_acq_rel(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_add_acq_rel.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_add_acq_rel.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t expected (long);
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_cas_scacq_screl(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_cas_scacq_screl.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_cas_scacq_screl.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t expected = %ld\n", args->hsa_signal_cas_scacq_screl.expected); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_cas_scacq_screl.value); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t expected (unsigned long);
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_cas_write_index_scacq_screl(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_cas_write_index_scacq_screl.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_cas_write_index_scacq_screl.queue); \
	if (args->hsa_queue_cas_write_index_scacq_screl.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_cas_write_index_scacq_screl.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_cas_write_index_scacq_screl.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_cas_write_index_scacq_screl.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_cas_write_index_scacq_screl.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_cas_write_index_scacq_screl.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_cas_write_index_scacq_screl.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t expected = %lu\n", args->hsa_queue_cas_write_index_scacq_screl.expected); \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_cas_write_index_scacq_screl.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_ipc_signal_t * handle ({
//		uint32_t[8] handle (unsigned int);
//	});
#define PROCESS_ARGS_hsa_amd_ipc_signal_create(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_ipc_signal_create.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_ipc_signal_create.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_amd_ipc_signal_t * handle = %p", args->hsa_amd_ipc_signal_create.handle); \
	if (args->hsa_amd_ipc_signal_create.handle != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t[8] handle = %u\n", args->hsa_amd_ipc_signal_create.handle__ref.val.handle[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_agent_t preferred_agent ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_spm_acquire(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_spm_acquire.retval); \
	printf("\thsa_agent_t preferred_agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_spm_acquire.preferred_agent.handle); \
	printf("\t}\n"); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_coherency_type_t * type (enum*);
#define PROCESS_ARGS_hsa_amd_coherency_get_type(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_coherency_get_type.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_coherency_get_type.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_amd_coherency_type_t * type = %p", args->hsa_amd_coherency_get_type.type); \
	if (args->hsa_amd_coherency_get_type.type != NULL) { \
		printf(" -> %d\n", args->hsa_amd_coherency_get_type.type__ref.val); \
	} else { printf("\n"); }; \
};

//	uint16_t extension (unsigned short);
//	uint16_t version_major (unsigned short);
//	uint16_t version_minor (unsigned short);
//	void * table (void*);
#define PROCESS_ARGS_hsa_system_get_extension_table(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_system_get_extension_table.retval); \
	printf("\tuint16_t extension = %hu\n", args->hsa_system_get_extension_table.extension); \
	printf("\tuint16_t version_major = %hu\n", args->hsa_system_get_extension_table.version_major); \
	printf("\tuint16_t version_minor = %hu\n", args->hsa_system_get_extension_table.version_minor); \
	printf("\tvoid * table = %p", args->hsa_system_get_extension_table.table); \
	printf("\n"); \
};

//	void * mapped_ptr (void*);
#define PROCESS_ARGS_hsa_amd_ipc_memory_detach(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_ipc_memory_detach.retval); \
	printf("\tvoid * mapped_ptr = %p", args->hsa_amd_ipc_memory_detach.mapped_ptr); \
	printf("\n"); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_ext_image_geometry_t geometry (enum);
//	const hsa_ext_image_format_t * image_format ({
//		hsa_ext_image_channel_type32_t channel_type (unsigned int);
//		hsa_ext_image_channel_order32_t channel_order (unsigned int);
//	});
//	hsa_ext_image_data_layout_t image_data_layout (enum);
//	uint32_t * capability_mask (unsigned int*);
#define PROCESS_ARGS_hsa_ext_image_get_capability_with_layout(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_ext_image_get_capability_with_layout.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_get_capability_with_layout.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_ext_image_geometry_t geometry = %d\n", args->hsa_ext_image_get_capability_with_layout.geometry); \
	printf("\tconst hsa_ext_image_format_t * image_format = %p", args->hsa_ext_image_get_capability_with_layout.image_format); \
	if (args->hsa_ext_image_get_capability_with_layout.image_format != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_ext_image_channel_type32_t channel_type = %u\n", args->hsa_ext_image_get_capability_with_layout.image_format__ref.val.channel_type); \
		printf("\t\thsa_ext_image_channel_order32_t channel_order = %u\n", args->hsa_ext_image_get_capability_with_layout.image_format__ref.val.channel_order); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_ext_image_data_layout_t image_data_layout = %d\n", args->hsa_ext_image_get_capability_with_layout.image_data_layout); \
	printf("\tuint32_t * capability_mask = %p", args->hsa_ext_image_get_capability_with_layout.capability_mask); \
	if (args->hsa_ext_image_get_capability_with_layout.capability_mask != NULL) { \
		printf(" -> %u\n", args->hsa_ext_image_get_capability_with_layout.capability_mask__ref.val); \
	} else { printf("\n"); }; \
};

//	void * va (void*);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hsa_amd_vmem_address_free(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_vmem_address_free.retval); \
	printf("\tvoid * va = %p", args->hsa_amd_vmem_address_free.va); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_amd_vmem_address_free.size); \
};

//	void * ptr (void*);
//	size_t size (unsigned long);
//	hsa_amd_svm_attribute_pair_t * attribute_list ({
//		uint64_t attribute (unsigned long);
//		uint64_t value (unsigned long);
//	});
//	size_t attribute_count (unsigned long);
#define PROCESS_ARGS_hsa_amd_svm_attributes_set(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_svm_attributes_set.retval); \
	printf("\tvoid * ptr = %p", args->hsa_amd_svm_attributes_set.ptr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_amd_svm_attributes_set.size); \
	printf("\thsa_amd_svm_attribute_pair_t * attribute_list = %p", args->hsa_amd_svm_attributes_set.attribute_list); \
	if (args->hsa_amd_svm_attributes_set.attribute_list != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t attribute = %lu\n", args->hsa_amd_svm_attributes_set.attribute_list__ref.val.attribute); \
		printf("\t\tuint64_t value = %lu\n", args->hsa_amd_svm_attributes_set.attribute_list__ref.val.value); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t attribute_count = %lu\n", args->hsa_amd_svm_attributes_set.attribute_count); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	const void * src_memory (void*);
//	size_t src_row_pitch (unsigned long);
//	size_t src_slice_pitch (unsigned long);
//	hsa_ext_image_t dst_image ({
//		uint64_t handle (unsigned long);
//	});
//	const hsa_ext_image_region_t * image_region ({
//		hsa_dim3_t offset ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		hsa_dim3_t range ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//	});
#define PROCESS_ARGS_hsa_ext_image_import(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_ext_image_import.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_import.agent.handle); \
	printf("\t}\n"); \
	printf("\tconst void * src_memory = %p", args->hsa_ext_image_import.src_memory); \
	printf("\n"); \
	printf("\tsize_t src_row_pitch = %lu\n", args->hsa_ext_image_import.src_row_pitch); \
	printf("\tsize_t src_slice_pitch = %lu\n", args->hsa_ext_image_import.src_slice_pitch); \
	printf("\thsa_ext_image_t dst_image = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_import.dst_image.handle); \
	printf("\t}\n"); \
	printf("\tconst hsa_ext_image_region_t * image_region = %p", args->hsa_ext_image_import.image_region); \
	if (args->hsa_ext_image_import.image_region != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_dim3_t offset = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hsa_ext_image_import.image_region__ref.val.offset.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hsa_ext_image_import.image_region__ref.val.offset.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hsa_ext_image_import.image_region__ref.val.offset.z); \
		printf("\t\t}\n"); \
		printf("\t\thsa_dim3_t range = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hsa_ext_image_import.image_region__ref.val.range.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hsa_ext_image_import.image_region__ref.val.range.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hsa_ext_image_import.image_region__ref.val.range.z); \
		printf("\t\t}\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_or_scacquire(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_or_scacquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_or_scacquire.value); \
};

//	void * ptr (void*);
//	size_t size (unsigned long);
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	uint32_t num_dep_signals (unsigned int);
//	const hsa_signal_t * dep_signals ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_t completion_signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_svm_prefetch_async(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_svm_prefetch_async.retval); \
	printf("\tvoid * ptr = %p", args->hsa_amd_svm_prefetch_async.ptr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_amd_svm_prefetch_async.size); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_svm_prefetch_async.agent.handle); \
	printf("\t}\n"); \
	printf("\tuint32_t num_dep_signals = %u\n", args->hsa_amd_svm_prefetch_async.num_dep_signals); \
	printf("\tconst hsa_signal_t * dep_signals = %p", args->hsa_amd_svm_prefetch_async.dep_signals); \
	if (args->hsa_amd_svm_prefetch_async.dep_signals != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_svm_prefetch_async.dep_signals__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_signal_t completion_signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_svm_prefetch_async.completion_signal.handle); \
	printf("\t}\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_add_scacq_screl(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_add_scacq_screl.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_add_scacq_screl.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_silent_store_relaxed(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_silent_store_relaxed.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_silent_store_relaxed.value); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_store_read_index_relaxed(args) { \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_store_read_index_relaxed.queue); \
	if (args->hsa_queue_store_read_index_relaxed.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_store_read_index_relaxed.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_store_read_index_relaxed.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_store_read_index_relaxed.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_store_read_index_relaxed.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_store_read_index_relaxed.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_store_read_index_relaxed.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_store_read_index_relaxed.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_profile_t profile (enum);
//	uint16_t * mask (unsigned short*);
#define PROCESS_ARGS_hsa_agent_get_exception_policies(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_agent_get_exception_policies.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_agent_get_exception_policies.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_profile_t profile = %d\n", args->hsa_agent_get_exception_policies.profile); \
	printf("\tuint16_t * mask = %p", args->hsa_agent_get_exception_policies.mask); \
	if (args->hsa_agent_get_exception_policies.mask != NULL) { \
		printf(" -> %hu\n", args->hsa_agent_get_exception_policies.mask__ref.val); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_add_scacquire(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_add_scacquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_add_scacquire.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_exchange_release(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_exchange_release.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_exchange_release.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_exchange_release.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_add_relaxed(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_add_relaxed.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_add_relaxed.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_and_acquire(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_and_acquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_and_acquire.value); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_add_write_index_relaxed(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_add_write_index_relaxed.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_add_write_index_relaxed.queue); \
	if (args->hsa_queue_add_write_index_relaxed.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_add_write_index_relaxed.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_add_write_index_relaxed.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_add_write_index_relaxed.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_add_write_index_relaxed.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_add_write_index_relaxed.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_add_write_index_relaxed.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_add_write_index_relaxed.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_memory_pool_t memory_pool ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_agent_memory_pool_info_t attribute (enum);
//	void * value (void*);
#define PROCESS_ARGS_hsa_amd_agent_memory_pool_get_info(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_agent_memory_pool_get_info.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_agent_memory_pool_get_info.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_amd_memory_pool_t memory_pool = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_agent_memory_pool_get_info.memory_pool.handle); \
	printf("\t}\n"); \
	printf("\thsa_amd_agent_memory_pool_info_t attribute = %d\n", args->hsa_amd_agent_memory_pool_get_info.attribute); \
	printf("\tvoid * value = %p", args->hsa_amd_agent_memory_pool_get_info.value); \
	printf("\n"); \
};

//	hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	int enable (int);
#define PROCESS_ARGS_hsa_amd_profiling_set_profiler_enabled(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_profiling_set_profiler_enabled.retval); \
	printf("\thsa_queue_t * queue = %p", args->hsa_amd_profiling_set_profiler_enabled.queue); \
	if (args->hsa_amd_profiling_set_profiler_enabled.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_amd_profiling_set_profiler_enabled.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_amd_profiling_set_profiler_enabled.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_amd_profiling_set_profiler_enabled.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_amd_profiling_set_profiler_enabled.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_amd_profiling_set_profiler_enabled.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_amd_profiling_set_profiler_enabled.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tint enable = %d\n", args->hsa_amd_profiling_set_profiler_enabled.enable); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_exchange_acq_rel(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_exchange_acq_rel.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_exchange_acq_rel.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_exchange_acq_rel.value); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t expected (unsigned long);
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_cas_write_index_screlease(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_cas_write_index_screlease.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_cas_write_index_screlease.queue); \
	if (args->hsa_queue_cas_write_index_screlease.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_cas_write_index_screlease.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_cas_write_index_screlease.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_cas_write_index_screlease.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_cas_write_index_screlease.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_cas_write_index_screlease.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_cas_write_index_screlease.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t expected = %lu\n", args->hsa_queue_cas_write_index_screlease.expected); \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_cas_write_index_screlease.value); \
};

//	void (*)(void *) callback (function);
//	void * arg (void*);
#define PROCESS_ARGS_hsa_amd_async_function(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_async_function.retval); \
	printf("\tvoid (*)(void *) callback = %p\n", args->hsa_amd_async_function.callback); \
	printf("\tvoid * arg = %p", args->hsa_amd_async_function.arg); \
	printf("\n"); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_store_read_index_screlease(args) { \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_store_read_index_screlease.queue); \
	if (args->hsa_queue_store_read_index_screlease.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_store_read_index_screlease.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_store_read_index_screlease.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_store_read_index_screlease.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_store_read_index_screlease.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_store_read_index_screlease.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_store_read_index_screlease.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_store_read_index_screlease.value); \
};

//	hsa_region_t region ({
//		uint64_t handle (unsigned long);
//	});
//	size_t size (unsigned long);
//	void ** ptr (void**);
#define PROCESS_ARGS_hsa_memory_allocate(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_memory_allocate.retval); \
	printf("\thsa_region_t region = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_memory_allocate.region.handle); \
	printf("\t}\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_memory_allocate.size); \
	printf("\tvoid ** ptr = %p", args->hsa_memory_allocate.ptr); \
	if (args->hsa_memory_allocate.ptr != NULL) { \
		printf("-> %p", args->hsa_memory_allocate.ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	volatile hsa_signal_value_t ** value_ptr (long**);
#define PROCESS_ARGS_hsa_amd_signal_value_pointer(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_signal_value_pointer.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_signal_value_pointer.signal.handle); \
	printf("\t}\n"); \
	printf("\tvolatile hsa_signal_value_t ** value_ptr = %p", args->hsa_amd_signal_value_pointer.value_ptr); \
	if (args->hsa_amd_signal_value_pointer.value_ptr != NULL) { \
		printf("-> %p", args->hsa_amd_signal_value_pointer.value_ptr__ref.ptr1); \
		if (args->hsa_amd_signal_value_pointer.value_ptr__ref.ptr1 != NULL) { \
			printf(" -> %ld\n", args->hsa_amd_signal_value_pointer.value_ptr__ref.val); \
		} else { printf("\n"); }; \
	} else { printf("\n"); }; \
};

//	uint32_t signal_count (unsigned int);
//	hsa_signal_t * signals ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_condition_t * conds (enum*);
//	hsa_signal_value_t * values (long*);
//	uint64_t timeout_hint (unsigned long);
//	hsa_wait_state_t wait_hint (enum);
//	hsa_signal_value_t * satisfying_value (long*);
#define PROCESS_ARGS_hsa_amd_signal_wait_any(args) { \
	printf("\tuint32_t retval = %u\n", args->hsa_amd_signal_wait_any.retval); \
	printf("\tuint32_t signal_count = %u\n", args->hsa_amd_signal_wait_any.signal_count); \
	printf("\thsa_signal_t * signals = %p", args->hsa_amd_signal_wait_any.signals); \
	if (args->hsa_amd_signal_wait_any.signals != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_signal_wait_any.signals__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_signal_condition_t * conds = %p", args->hsa_amd_signal_wait_any.conds); \
	if (args->hsa_amd_signal_wait_any.conds != NULL) { \
		printf(" -> %d\n", args->hsa_amd_signal_wait_any.conds__ref.val); \
	} else { printf("\n"); }; \
	printf("\thsa_signal_value_t * values = %p", args->hsa_amd_signal_wait_any.values); \
	if (args->hsa_amd_signal_wait_any.values != NULL) { \
		printf(" -> %ld\n", args->hsa_amd_signal_wait_any.values__ref.val); \
	} else { printf("\n"); }; \
	printf("\tuint64_t timeout_hint = %lu\n", args->hsa_amd_signal_wait_any.timeout_hint); \
	printf("\thsa_wait_state_t wait_hint = %d\n", args->hsa_amd_signal_wait_any.wait_hint); \
	printf("\thsa_signal_value_t * satisfying_value = %p", args->hsa_amd_signal_wait_any.satisfying_value); \
	if (args->hsa_amd_signal_wait_any.satisfying_value != NULL) { \
		printf(" -> %ld\n", args->hsa_amd_signal_wait_any.satisfying_value__ref.val); \
	} else { printf("\n"); }; \
};

//	hsa_amd_vmem_alloc_handle_t * memory_handle ({
//		uint64_t handle (unsigned long);
//	});
//	void * addr (void*);
#define PROCESS_ARGS_hsa_amd_vmem_retain_alloc_handle(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_vmem_retain_alloc_handle.retval); \
	printf("\thsa_amd_vmem_alloc_handle_t * memory_handle = %p", args->hsa_amd_vmem_retain_alloc_handle.memory_handle); \
	if (args->hsa_amd_vmem_retain_alloc_handle.memory_handle != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_vmem_retain_alloc_handle.memory_handle__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tvoid * addr = %p", args->hsa_amd_vmem_retain_alloc_handle.addr); \
	printf("\n"); \
};

//	void * va (void*);
//	size_t size (unsigned long);
//	const hsa_amd_memory_access_desc_t * desc ({
//		hsa_access_permission_t permissions (enum);
//		hsa_agent_t agent_handle ({
//			uint64_t handle (unsigned long);
//		});
//	});
//	size_t desc_cnt (unsigned long);
#define PROCESS_ARGS_hsa_amd_vmem_set_access(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_vmem_set_access.retval); \
	printf("\tvoid * va = %p", args->hsa_amd_vmem_set_access.va); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_amd_vmem_set_access.size); \
	printf("\tconst hsa_amd_memory_access_desc_t * desc = %p", args->hsa_amd_vmem_set_access.desc); \
	if (args->hsa_amd_vmem_set_access.desc != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_access_permission_t permissions = %d\n", args->hsa_amd_vmem_set_access.desc__ref.val.permissions); \
		printf("\t\thsa_agent_t agent_handle = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_amd_vmem_set_access.desc__ref.val.agent_handle.handle); \
		printf("\t\t}\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t desc_cnt = %lu\n", args->hsa_amd_vmem_set_access.desc_cnt); \
};

//	void * ptr (void*);
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_access_permission_t access (enum);
#define PROCESS_ARGS_hsa_memory_assign_agent(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_memory_assign_agent.retval); \
	printf("\tvoid * ptr = %p", args->hsa_memory_assign_agent.ptr); \
	printf("\n"); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_memory_assign_agent.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_access_permission_t access = %d\n", args->hsa_memory_assign_agent.access); \
};

//	void ** va (void**);
//	size_t size (unsigned long);
//	uint64_t address (unsigned long);
//	uint64_t flags (unsigned long);
#define PROCESS_ARGS_hsa_amd_vmem_address_reserve(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_vmem_address_reserve.retval); \
	printf("\tvoid ** va = %p", args->hsa_amd_vmem_address_reserve.va); \
	if (args->hsa_amd_vmem_address_reserve.va != NULL) { \
		printf("-> %p", args->hsa_amd_vmem_address_reserve.va__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hsa_amd_vmem_address_reserve.size); \
	printf("\tuint64_t address = %lu\n", args->hsa_amd_vmem_address_reserve.address); \
	printf("\tuint64_t flags = %lu\n", args->hsa_amd_vmem_address_reserve.flags); \
};

//	void * dst (void*);
//	hsa_agent_t dst_agent ({
//		uint64_t handle (unsigned long);
//	});
//	const void * src (void*);
//	hsa_agent_t src_agent ({
//		uint64_t handle (unsigned long);
//	});
//	size_t size (unsigned long);
//	uint32_t num_dep_signals (unsigned int);
//	const hsa_signal_t * dep_signals ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_t completion_signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_sdma_engine_id_t engine_id (enum);
//	_Bool force_copy_on_sdma (unknown);
#define PROCESS_ARGS_hsa_amd_memory_async_copy_on_engine(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_memory_async_copy_on_engine.retval); \
	printf("\tvoid * dst = %p", args->hsa_amd_memory_async_copy_on_engine.dst); \
	printf("\n"); \
	printf("\thsa_agent_t dst_agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_async_copy_on_engine.dst_agent.handle); \
	printf("\t}\n"); \
	printf("\tconst void * src = %p", args->hsa_amd_memory_async_copy_on_engine.src); \
	printf("\n"); \
	printf("\thsa_agent_t src_agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_async_copy_on_engine.src_agent.handle); \
	printf("\t}\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_amd_memory_async_copy_on_engine.size); \
	printf("\tuint32_t num_dep_signals = %u\n", args->hsa_amd_memory_async_copy_on_engine.num_dep_signals); \
	printf("\tconst hsa_signal_t * dep_signals = %p", args->hsa_amd_memory_async_copy_on_engine.dep_signals); \
	if (args->hsa_amd_memory_async_copy_on_engine.dep_signals != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_async_copy_on_engine.dep_signals__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_signal_t completion_signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_async_copy_on_engine.completion_signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_amd_sdma_engine_id_t engine_id = %d\n", args->hsa_amd_memory_async_copy_on_engine.engine_id); \
	printf("\t_Bool force_copy_on_sdma = N/A, try to update csv files\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_xor_scacquire(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_xor_scacquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_xor_scacquire.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_coherency_type_t type (enum);
#define PROCESS_ARGS_hsa_amd_coherency_set_type(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_coherency_set_type.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_coherency_set_type.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_amd_coherency_type_t type = %d\n", args->hsa_amd_coherency_set_type.type); \
};

//	hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
#define PROCESS_ARGS_hsa_queue_inactivate(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_queue_inactivate.retval); \
	printf("\thsa_queue_t * queue = %p", args->hsa_queue_inactivate.queue); \
	if (args->hsa_queue_inactivate.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_inactivate.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_inactivate.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_inactivate.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_inactivate.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_inactivate.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_inactivate.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	int dmabuf_fd (int);
//	hsa_amd_vmem_alloc_handle_t * handle ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_vmem_import_shareable_handle(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_vmem_import_shareable_handle.retval); \
	printf("\tint dmabuf_fd = %d\n", args->hsa_amd_vmem_import_shareable_handle.dmabuf_fd); \
	printf("\thsa_amd_vmem_alloc_handle_t * handle = %p", args->hsa_amd_vmem_import_shareable_handle.handle); \
	if (args->hsa_amd_vmem_import_shareable_handle.handle != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_vmem_import_shareable_handle.handle__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t expected (long);
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_cas_relaxed(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_cas_relaxed.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_cas_relaxed.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t expected = %ld\n", args->hsa_signal_cas_relaxed.expected); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_cas_relaxed.value); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_add_write_index_scacquire(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_add_write_index_scacquire.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_add_write_index_scacquire.queue); \
	if (args->hsa_queue_add_write_index_scacquire.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_add_write_index_scacquire.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_add_write_index_scacquire.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_add_write_index_scacquire.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_add_write_index_scacquire.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_add_write_index_scacquire.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_add_write_index_scacquire.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_add_write_index_scacquire.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_exchange_screlease(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_exchange_screlease.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_exchange_screlease.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_exchange_screlease.value); \
};

//	hsa_amd_memory_pool_t pool ({
//		uint64_t handle (unsigned long);
//	});
//	size_t size (unsigned long);
//	hsa_amd_memory_type_t type (enum);
//	uint64_t flags (unsigned long);
//	hsa_amd_vmem_alloc_handle_t * memory_handle ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_vmem_handle_create(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_vmem_handle_create.retval); \
	printf("\thsa_amd_memory_pool_t pool = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_vmem_handle_create.pool.handle); \
	printf("\t}\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_amd_vmem_handle_create.size); \
	printf("\thsa_amd_memory_type_t type = %d\n", args->hsa_amd_vmem_handle_create.type); \
	printf("\tuint64_t flags = %lu\n", args->hsa_amd_vmem_handle_create.flags); \
	printf("\thsa_amd_vmem_alloc_handle_t * memory_handle = %p", args->hsa_amd_vmem_handle_create.memory_handle); \
	if (args->hsa_amd_vmem_handle_create.memory_handle != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_vmem_handle_create.memory_handle__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_info_t attribute (enum);
//	void * value (void*);
#define PROCESS_ARGS_hsa_agent_get_info(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_agent_get_info.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_agent_get_info.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_agent_info_t attribute = %d\n", args->hsa_agent_get_info.attribute); \
	printf("\tvoid * value = %p", args->hsa_agent_get_info.value); \
	printf("\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_or_acq_rel(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_or_acq_rel.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_or_acq_rel.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_xor_acq_rel(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_xor_acq_rel.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_xor_acq_rel.value); \
};

//	uint16_t extension (unsigned short);
//	uint16_t version_major (unsigned short);
//	uint16_t version_minor (unsigned short);
//	_Bool * result (unknown);
#define PROCESS_ARGS_hsa_system_extension_supported(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_system_extension_supported.retval); \
	printf("\tuint16_t extension = %hu\n", args->hsa_system_extension_supported.extension); \
	printf("\tuint16_t version_major = %hu\n", args->hsa_system_extension_supported.version_major); \
	printf("\tuint16_t version_minor = %hu\n", args->hsa_system_extension_supported.version_minor); \
	printf("\t_Bool * result = N/A, try to update csv files\n"); \
};

//	hsa_signal_group_t signal_group ({
//		uint64_t handle (unsigned long);
//	});
//	const hsa_signal_condition_t * conditions (enum*);
//	const hsa_signal_value_t * compare_values (long*);
//	hsa_wait_state_t wait_state_hint (enum);
//	hsa_signal_t * signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t * value (long*);
#define PROCESS_ARGS_hsa_signal_group_wait_any_relaxed(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_signal_group_wait_any_relaxed.retval); \
	printf("\thsa_signal_group_t signal_group = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_group_wait_any_relaxed.signal_group.handle); \
	printf("\t}\n"); \
	printf("\tconst hsa_signal_condition_t * conditions = %p", args->hsa_signal_group_wait_any_relaxed.conditions); \
	if (args->hsa_signal_group_wait_any_relaxed.conditions != NULL) { \
		printf(" -> %d\n", args->hsa_signal_group_wait_any_relaxed.conditions__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst hsa_signal_value_t * compare_values = %p", args->hsa_signal_group_wait_any_relaxed.compare_values); \
	if (args->hsa_signal_group_wait_any_relaxed.compare_values != NULL) { \
		printf(" -> %ld\n", args->hsa_signal_group_wait_any_relaxed.compare_values__ref.val); \
	} else { printf("\n"); }; \
	printf("\thsa_wait_state_t wait_state_hint = %d\n", args->hsa_signal_group_wait_any_relaxed.wait_state_hint); \
	printf("\thsa_signal_t * signal = %p", args->hsa_signal_group_wait_any_relaxed.signal); \
	if (args->hsa_signal_group_wait_any_relaxed.signal != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_group_wait_any_relaxed.signal__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_signal_value_t * value = %p", args->hsa_signal_group_wait_any_relaxed.value); \
	if (args->hsa_signal_group_wait_any_relaxed.value != NULL) { \
		printf(" -> %ld\n", args->hsa_signal_group_wait_any_relaxed.value__ref.val); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_or_scacq_screl(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_or_scacq_screl.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_or_scacq_screl.value); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_executable_t, hsa_agent_t, hsa_executable_symbol_t, void *) callback (function);
//	void * data (void*);
#define PROCESS_ARGS_hsa_executable_iterate_agent_symbols(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_iterate_agent_symbols.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_iterate_agent_symbols.executable.handle); \
	printf("\t}\n"); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_iterate_agent_symbols.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_status_t (*)(hsa_executable_t, hsa_agent_t, hsa_executable_symbol_t, void *) callback = %p\n", args->hsa_executable_iterate_agent_symbols.callback); \
	printf("\tvoid * data = %p", args->hsa_executable_iterate_agent_symbols.data); \
	printf("\n"); \
};

//	void * ptr (void*);
//	hsa_amd_deallocation_callback_t callback (function);
#define PROCESS_ARGS_hsa_amd_deregister_deallocation_callback(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_deregister_deallocation_callback.retval); \
	printf("\tvoid * ptr = %p", args->hsa_amd_deregister_deallocation_callback.ptr); \
	printf("\n"); \
	printf("\thsa_amd_deallocation_callback_t callback = %p\n", args->hsa_amd_deregister_deallocation_callback.callback); \
};

//	hsa_signal_value_t initial_value (long);
//	uint32_t num_consumers (unsigned int);
//	const hsa_agent_t * consumers ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_t * signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_signal_create(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_signal_create.retval); \
	printf("\thsa_signal_value_t initial_value = %ld\n", args->hsa_signal_create.initial_value); \
	printf("\tuint32_t num_consumers = %u\n", args->hsa_signal_create.num_consumers); \
	printf("\tconst hsa_agent_t * consumers = %p", args->hsa_signal_create.consumers); \
	if (args->hsa_signal_create.consumers != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_create.consumers__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_signal_t * signal = %p", args->hsa_signal_create.signal); \
	if (args->hsa_signal_create.signal != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_create.signal__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_agent_t dst_agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_agent_t src_agent ({
//		uint64_t handle (unsigned long);
//	});
//	uint32_t * engine_ids_mask (unsigned int*);
#define PROCESS_ARGS_hsa_amd_memory_copy_engine_status(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_memory_copy_engine_status.retval); \
	printf("\thsa_agent_t dst_agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_copy_engine_status.dst_agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_agent_t src_agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_copy_engine_status.src_agent.handle); \
	printf("\t}\n"); \
	printf("\tuint32_t * engine_ids_mask = %p", args->hsa_amd_memory_copy_engine_status.engine_ids_mask); \
	if (args->hsa_amd_memory_copy_engine_status.engine_ids_mask != NULL) { \
		printf(" -> %u\n", args->hsa_amd_memory_copy_engine_status.engine_ids_mask__ref.val); \
	} else { printf("\n"); }; \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_ext_image_geometry_t geometry (enum);
//	const hsa_ext_image_format_t * image_format ({
//		hsa_ext_image_channel_type32_t channel_type (unsigned int);
//		hsa_ext_image_channel_order32_t channel_order (unsigned int);
//	});
//	uint32_t * capability_mask (unsigned int*);
#define PROCESS_ARGS_hsa_ext_image_get_capability(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_ext_image_get_capability.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_get_capability.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_ext_image_geometry_t geometry = %d\n", args->hsa_ext_image_get_capability.geometry); \
	printf("\tconst hsa_ext_image_format_t * image_format = %p", args->hsa_ext_image_get_capability.image_format); \
	if (args->hsa_ext_image_get_capability.image_format != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_ext_image_channel_type32_t channel_type = %u\n", args->hsa_ext_image_get_capability.image_format__ref.val.channel_type); \
		printf("\t\thsa_ext_image_channel_order32_t channel_order = %u\n", args->hsa_ext_image_get_capability.image_format__ref.val.channel_order); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint32_t * capability_mask = %p", args->hsa_ext_image_get_capability.capability_mask); \
	if (args->hsa_ext_image_get_capability.capability_mask != NULL) { \
		printf(" -> %u\n", args->hsa_ext_image_get_capability.capability_mask__ref.val); \
	} else { printf("\n"); }; \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_ext_image_t image ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_ext_image_destroy(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_ext_image_destroy.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_destroy.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_ext_image_t image = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_destroy.image.handle); \
	printf("\t}\n"); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_store_read_index_release(args) { \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_store_read_index_release.queue); \
	if (args->hsa_queue_store_read_index_release.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_store_read_index_release.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_store_read_index_release.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_store_read_index_release.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_store_read_index_release.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_store_read_index_release.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_store_read_index_release.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_store_read_index_release.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_condition_t condition (enum);
//	hsa_signal_value_t compare_value (long);
//	uint64_t timeout_hint (unsigned long);
//	hsa_wait_state_t wait_state_hint (enum);
#define PROCESS_ARGS_hsa_signal_wait_scacquire(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_wait_scacquire.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_wait_scacquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_condition_t condition = %d\n", args->hsa_signal_wait_scacquire.condition); \
	printf("\thsa_signal_value_t compare_value = %ld\n", args->hsa_signal_wait_scacquire.compare_value); \
	printf("\tuint64_t timeout_hint = %lu\n", args->hsa_signal_wait_scacquire.timeout_hint); \
	printf("\thsa_wait_state_t wait_state_hint = %d\n", args->hsa_signal_wait_scacquire.wait_state_hint); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_executable_info_t attribute (enum);
//	void * value (void*);
#define PROCESS_ARGS_hsa_executable_get_info(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_get_info.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_get_info.executable.handle); \
	printf("\t}\n"); \
	printf("\thsa_executable_info_t attribute = %d\n", args->hsa_executable_get_info.attribute); \
	printf("\tvoid * value = %p", args->hsa_executable_get_info.value); \
	printf("\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_silent_store_screlease(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_silent_store_screlease.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_silent_store_screlease.value); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	const char * options (string*);
//	uint32_t * result (unsigned int*);
#define PROCESS_ARGS_hsa_executable_validate_alt(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_validate_alt.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_validate_alt.executable.handle); \
	printf("\t}\n"); \
	printf("\tconst char * options = %p", args->hsa_executable_validate_alt.options); \
	if (args->hsa_executable_validate_alt.options != NULL) { \
		printf(" -> %s\n", args->hsa_executable_validate_alt.options__ref.val); \
	} else { printf("\n"); }; \
	printf("\tuint32_t * result = %p", args->hsa_executable_validate_alt.result); \
	if (args->hsa_executable_validate_alt.result != NULL) { \
		printf(" -> %u\n", args->hsa_executable_validate_alt.result__ref.val); \
	} else { printf("\n"); }; \
};

//	hsa_profile_t profile (enum);
//	hsa_executable_state_t executable_state (enum);
//	const char * options (string*);
//	hsa_executable_t * executable ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_create(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_create.retval); \
	printf("\thsa_profile_t profile = %d\n", args->hsa_executable_create.profile); \
	printf("\thsa_executable_state_t executable_state = %d\n", args->hsa_executable_create.executable_state); \
	printf("\tconst char * options = %p", args->hsa_executable_create.options); \
	if (args->hsa_executable_create.options != NULL) { \
		printf(" -> %s\n", args->hsa_executable_create.options__ref.val); \
	} else { printf("\n"); }; \
	printf("\thsa_executable_t * executable = %p", args->hsa_executable_create.executable); \
	if (args->hsa_executable_create.executable != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_create.executable__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_executable_t, hsa_executable_symbol_t, void *) callback (function);
//	void * data (void*);
#define PROCESS_ARGS_hsa_executable_iterate_program_symbols(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_iterate_program_symbols.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_iterate_program_symbols.executable.handle); \
	printf("\t}\n"); \
	printf("\thsa_status_t (*)(hsa_executable_t, hsa_executable_symbol_t, void *) callback = %p\n", args->hsa_executable_iterate_program_symbols.callback); \
	printf("\tvoid * data = %p", args->hsa_executable_iterate_program_symbols.data); \
	printf("\n"); \
};

//	void * ptr (void*);
#define PROCESS_ARGS_hsa_memory_free(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_memory_free.retval); \
	printf("\tvoid * ptr = %p", args->hsa_memory_free.ptr); \
	printf("\n"); \
};

//	void * ptr (void*);
#define PROCESS_ARGS_hsa_amd_memory_pool_free(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_memory_pool_free.retval); \
	printf("\tvoid * ptr = %p", args->hsa_amd_memory_pool_free.ptr); \
	printf("\n"); \
};

//	const void * ptr (void*);
//	hsa_amd_memory_pool_t memory_pool ({
//		uint64_t handle (unsigned long);
//	});
//	uint32_t flags (unsigned int);
#define PROCESS_ARGS_hsa_amd_memory_migrate(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_memory_migrate.retval); \
	printf("\tconst void * ptr = %p", args->hsa_amd_memory_migrate.ptr); \
	printf("\n"); \
	printf("\thsa_amd_memory_pool_t memory_pool = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_memory_migrate.memory_pool.handle); \
	printf("\t}\n"); \
	printf("\tuint32_t flags = %u\n", args->hsa_amd_memory_migrate.flags); \
};

//	void * ptr (void*);
#define PROCESS_ARGS_hsa_amd_interop_unmap_buffer(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_interop_unmap_buffer.retval); \
	printf("\tvoid * ptr = %p", args->hsa_amd_interop_unmap_buffer.ptr); \
	printf("\n"); \
};

//	hsa_signal_value_t initial_value (long);
//	uint32_t num_consumers (unsigned int);
//	const hsa_agent_t * consumers ({
//		uint64_t handle (unsigned long);
//	});
//	uint64_t attributes (unsigned long);
//	hsa_signal_t * signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_signal_create(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_signal_create.retval); \
	printf("\thsa_signal_value_t initial_value = %ld\n", args->hsa_amd_signal_create.initial_value); \
	printf("\tuint32_t num_consumers = %u\n", args->hsa_amd_signal_create.num_consumers); \
	printf("\tconst hsa_agent_t * consumers = %p", args->hsa_amd_signal_create.consumers); \
	if (args->hsa_amd_signal_create.consumers != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_signal_create.consumers__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t attributes = %lu\n", args->hsa_amd_signal_create.attributes); \
	printf("\thsa_signal_t * signal = %p", args->hsa_amd_signal_create.signal); \
	if (args->hsa_amd_signal_create.signal != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_signal_create.signal__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_code_object_reader_t code_object_reader ({
//		uint64_t handle (unsigned long);
//	});
//	const char * options (string*);
//	hsa_loaded_code_object_t * loaded_code_object ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_load_program_code_object(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_load_program_code_object.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_load_program_code_object.executable.handle); \
	printf("\t}\n"); \
	printf("\thsa_code_object_reader_t code_object_reader = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_load_program_code_object.code_object_reader.handle); \
	printf("\t}\n"); \
	printf("\tconst char * options = %p", args->hsa_executable_load_program_code_object.options); \
	if (args->hsa_executable_load_program_code_object.options != NULL) { \
		printf(" -> %s\n", args->hsa_executable_load_program_code_object.options__ref.val); \
	} else { printf("\n"); }; \
	printf("\thsa_loaded_code_object_t * loaded_code_object = %p", args->hsa_executable_load_program_code_object.loaded_code_object); \
	if (args->hsa_executable_load_program_code_object.loaded_code_object != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_load_program_code_object.loaded_code_object__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_signal_load_relaxed(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_load_relaxed.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_load_relaxed.signal.handle); \
	printf("\t}\n"); \
};

//	hsa_signal_group_t signal_group ({
//		uint64_t handle (unsigned long);
//	});
//	const hsa_signal_condition_t * conditions (enum*);
//	const hsa_signal_value_t * compare_values (long*);
//	hsa_wait_state_t wait_state_hint (enum);
//	hsa_signal_t * signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t * value (long*);
#define PROCESS_ARGS_hsa_signal_group_wait_any_scacquire(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_signal_group_wait_any_scacquire.retval); \
	printf("\thsa_signal_group_t signal_group = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_group_wait_any_scacquire.signal_group.handle); \
	printf("\t}\n"); \
	printf("\tconst hsa_signal_condition_t * conditions = %p", args->hsa_signal_group_wait_any_scacquire.conditions); \
	if (args->hsa_signal_group_wait_any_scacquire.conditions != NULL) { \
		printf(" -> %d\n", args->hsa_signal_group_wait_any_scacquire.conditions__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst hsa_signal_value_t * compare_values = %p", args->hsa_signal_group_wait_any_scacquire.compare_values); \
	if (args->hsa_signal_group_wait_any_scacquire.compare_values != NULL) { \
		printf(" -> %ld\n", args->hsa_signal_group_wait_any_scacquire.compare_values__ref.val); \
	} else { printf("\n"); }; \
	printf("\thsa_wait_state_t wait_state_hint = %d\n", args->hsa_signal_group_wait_any_scacquire.wait_state_hint); \
	printf("\thsa_signal_t * signal = %p", args->hsa_signal_group_wait_any_scacquire.signal); \
	if (args->hsa_signal_group_wait_any_scacquire.signal != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_group_wait_any_scacquire.signal__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_signal_value_t * value = %p", args->hsa_signal_group_wait_any_scacquire.value); \
	if (args->hsa_signal_group_wait_any_scacquire.value != NULL) { \
		printf(" -> %ld\n", args->hsa_signal_group_wait_any_scacquire.value__ref.val); \
	} else { printf("\n"); }; \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t expected (unsigned long);
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_cas_write_index_relaxed(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_cas_write_index_relaxed.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_cas_write_index_relaxed.queue); \
	if (args->hsa_queue_cas_write_index_relaxed.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_cas_write_index_relaxed.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_cas_write_index_relaxed.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_cas_write_index_relaxed.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_cas_write_index_relaxed.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_cas_write_index_relaxed.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_cas_write_index_relaxed.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t expected = %lu\n", args->hsa_queue_cas_write_index_relaxed.expected); \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_cas_write_index_relaxed.value); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_subtract_relaxed(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_subtract_relaxed.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_subtract_relaxed.value); \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	const char * options (string*);
#define PROCESS_ARGS_hsa_executable_freeze(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_freeze.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_freeze.executable.handle); \
	printf("\t}\n"); \
	printf("\tconst char * options = %p", args->hsa_executable_freeze.options); \
	if (args->hsa_executable_freeze.options != NULL) { \
		printf(" -> %s\n", args->hsa_executable_freeze.options__ref.val); \
	} else { printf("\n"); }; \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
#define PROCESS_ARGS_hsa_queue_load_write_index_acquire(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_load_write_index_acquire.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_load_write_index_acquire.queue); \
	if (args->hsa_queue_load_write_index_acquire.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_load_write_index_acquire.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_load_write_index_acquire.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_load_write_index_acquire.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_load_write_index_acquire.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_load_write_index_acquire.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_load_write_index_acquire.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	void * va (void*);
//	size_t size (unsigned long);
//	size_t in_offset (unsigned long);
//	hsa_amd_vmem_alloc_handle_t memory_handle ({
//		uint64_t handle (unsigned long);
//	});
//	uint64_t flags (unsigned long);
#define PROCESS_ARGS_hsa_amd_vmem_map(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_vmem_map.retval); \
	printf("\tvoid * va = %p", args->hsa_amd_vmem_map.va); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_amd_vmem_map.size); \
	printf("\tsize_t in_offset = %lu\n", args->hsa_amd_vmem_map.in_offset); \
	printf("\thsa_amd_vmem_alloc_handle_t memory_handle = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_vmem_map.memory_handle.handle); \
	printf("\t}\n"); \
	printf("\tuint64_t flags = %lu\n", args->hsa_amd_vmem_map.flags); \
};

//	const hsa_amd_ipc_signal_t * handle ({
//		uint32_t[8] handle (unsigned int);
//	});
//	hsa_signal_t * signal ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_ipc_signal_attach(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_ipc_signal_attach.retval); \
	printf("\tconst hsa_amd_ipc_signal_t * handle = %p", args->hsa_amd_ipc_signal_attach.handle); \
	if (args->hsa_amd_ipc_signal_attach.handle != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t[8] handle = %u\n", args->hsa_amd_ipc_signal_attach.handle__ref.val.handle[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_signal_t * signal = %p", args->hsa_amd_ipc_signal_attach.signal); \
	if (args->hsa_amd_ipc_signal_attach.signal != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_ipc_signal_attach.signal__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_amd_system_event_callback_t callback (function);
//	void * data (void*);
#define PROCESS_ARGS_hsa_amd_register_system_event_handler(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_register_system_event_handler.retval); \
	printf("\thsa_amd_system_event_callback_t callback = %p\n", args->hsa_amd_register_system_event_handler.callback); \
	printf("\tvoid * data = %p", args->hsa_amd_register_system_event_handler.data); \
	printf("\n"); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint32_t num_cu_mask_count (unsigned int);
//	const uint32_t * cu_mask (unsigned int*);
#define PROCESS_ARGS_hsa_amd_queue_cu_set_mask(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_queue_cu_set_mask.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_amd_queue_cu_set_mask.queue); \
	if (args->hsa_amd_queue_cu_set_mask.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_amd_queue_cu_set_mask.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_amd_queue_cu_set_mask.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_amd_queue_cu_set_mask.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_amd_queue_cu_set_mask.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_amd_queue_cu_set_mask.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_amd_queue_cu_set_mask.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint32_t num_cu_mask_count = %u\n", args->hsa_amd_queue_cu_set_mask.num_cu_mask_count); \
	printf("\tconst uint32_t * cu_mask = %p", args->hsa_amd_queue_cu_set_mask.cu_mask); \
	if (args->hsa_amd_queue_cu_set_mask.cu_mask != NULL) { \
		printf(" -> %u\n", args->hsa_amd_queue_cu_set_mask.cu_mask__ref.val); \
	} else { printf("\n"); }; \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_ext_image_t src_image ({
//		uint64_t handle (unsigned long);
//	});
//	void * dst_memory (void*);
//	size_t dst_row_pitch (unsigned long);
//	size_t dst_slice_pitch (unsigned long);
//	const hsa_ext_image_region_t * image_region ({
//		hsa_dim3_t offset ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		hsa_dim3_t range ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//	});
#define PROCESS_ARGS_hsa_ext_image_export(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_ext_image_export.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_export.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_ext_image_t src_image = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_export.src_image.handle); \
	printf("\t}\n"); \
	printf("\tvoid * dst_memory = %p", args->hsa_ext_image_export.dst_memory); \
	printf("\n"); \
	printf("\tsize_t dst_row_pitch = %lu\n", args->hsa_ext_image_export.dst_row_pitch); \
	printf("\tsize_t dst_slice_pitch = %lu\n", args->hsa_ext_image_export.dst_slice_pitch); \
	printf("\tconst hsa_ext_image_region_t * image_region = %p", args->hsa_ext_image_export.image_region); \
	if (args->hsa_ext_image_export.image_region != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_dim3_t offset = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hsa_ext_image_export.image_region__ref.val.offset.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hsa_ext_image_export.image_region__ref.val.offset.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hsa_ext_image_export.image_region__ref.val.offset.z); \
		printf("\t\t}\n"); \
		printf("\t\thsa_dim3_t range = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hsa_ext_image_export.image_region__ref.val.range.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hsa_ext_image_export.image_region__ref.val.range.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hsa_ext_image_export.image_region__ref.val.range.z); \
		printf("\t\t}\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_status_t status (enum);
//	const char ** status_string (string**);
#define PROCESS_ARGS_hsa_status_string(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_status_string.retval); \
	printf("\thsa_status_t status = %d\n", args->hsa_status_string.status); \
	printf("\tconst char ** status_string = %p", args->hsa_status_string.status_string); \
	if (args->hsa_status_string.status_string != NULL) { \
		printf("-> %p", args->hsa_status_string.status_string__ref.ptr1); \
		if (args->hsa_status_string.status_string__ref.ptr1 != NULL) { \
			printf(" -> %s\n", args->hsa_status_string.status_string__ref.val); \
		} else { printf("\n"); }; \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_xor_screlease(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_xor_screlease.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_xor_screlease.value); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_add_write_index_acquire(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_add_write_index_acquire.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_add_write_index_acquire.queue); \
	if (args->hsa_queue_add_write_index_acquire.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_add_write_index_acquire.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_add_write_index_acquire.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_add_write_index_acquire.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_add_write_index_acquire.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_add_write_index_acquire.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_add_write_index_acquire.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_add_write_index_acquire.value); \
};

//	const hsa_queue_t * queue ({
//		hsa_queue_type32_t type (unsigned int);
//		uint32_t features (unsigned int);
//		hsa_signal_t doorbell_signal ({
//			uint64_t handle (unsigned long);
//		});
//		uint32_t size (unsigned int);
//		uint32_t reserved1 (unsigned int);
//		uint64_t id (unsigned long);
//	});
//	uint64_t value (unsigned long);
#define PROCESS_ARGS_hsa_queue_add_write_index_screlease(args) { \
	printf("\tuint64_t retval = %lu\n", args->hsa_queue_add_write_index_screlease.retval); \
	printf("\tconst hsa_queue_t * queue = %p", args->hsa_queue_add_write_index_screlease.queue); \
	if (args->hsa_queue_add_write_index_screlease.queue != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_queue_type32_t type = %u\n", args->hsa_queue_add_write_index_screlease.queue__ref.val.type); \
		printf("\t\tuint32_t features = %u\n", args->hsa_queue_add_write_index_screlease.queue__ref.val.features); \
		printf("\t\thsa_signal_t doorbell_signal = {\n"); \
		printf("\t\t\tuint64_t handle = %lu\n", args->hsa_queue_add_write_index_screlease.queue__ref.val.doorbell_signal.handle); \
		printf("\t\t}\n"); \
		printf("\t\tuint32_t size = %u\n", args->hsa_queue_add_write_index_screlease.queue__ref.val.size); \
		printf("\t\tuint32_t reserved1 = %u\n", args->hsa_queue_add_write_index_screlease.queue__ref.val.reserved1); \
		printf("\t\tuint64_t id = %lu\n", args->hsa_queue_add_write_index_screlease.queue__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tuint64_t value = %lu\n", args->hsa_queue_add_write_index_screlease.value); \
};

//	hsa_code_object_t code_object ({
//		uint64_t handle (unsigned long);
//	});
//	const char * module_name (string*);
//	const char * symbol_name (string*);
//	hsa_code_symbol_t * symbol ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_code_object_get_symbol_from_name(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_code_object_get_symbol_from_name.retval); \
	printf("\thsa_code_object_t code_object = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_code_object_get_symbol_from_name.code_object.handle); \
	printf("\t}\n"); \
	printf("\tconst char * module_name = %p", args->hsa_code_object_get_symbol_from_name.module_name); \
	if (args->hsa_code_object_get_symbol_from_name.module_name != NULL) { \
		printf(" -> %s\n", args->hsa_code_object_get_symbol_from_name.module_name__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst char * symbol_name = %p", args->hsa_code_object_get_symbol_from_name.symbol_name); \
	if (args->hsa_code_object_get_symbol_from_name.symbol_name != NULL) { \
		printf(" -> %s\n", args->hsa_code_object_get_symbol_from_name.symbol_name__ref.val); \
	} else { printf("\n"); }; \
	printf("\thsa_code_symbol_t * symbol = %p", args->hsa_code_object_get_symbol_from_name.symbol); \
	if (args->hsa_code_object_get_symbol_from_name.symbol != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_code_object_get_symbol_from_name.symbol__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	const char * name (string*);
//	hsa_isa_t * isa ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_isa_from_name(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_isa_from_name.retval); \
	printf("\tconst char * name = %p", args->hsa_isa_from_name.name); \
	if (args->hsa_isa_from_name.name != NULL) { \
		printf(" -> %s\n", args->hsa_isa_from_name.name__ref.val); \
	} else { printf("\n"); }; \
	printf("\thsa_isa_t * isa = %p", args->hsa_isa_from_name.isa); \
	if (args->hsa_isa_from_name.isa != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_isa_from_name.isa__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_status_t (*)(hsa_amd_memory_pool_t, void *) callback (function);
//	void * data (void*);
#define PROCESS_ARGS_hsa_amd_agent_iterate_memory_pools(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_agent_iterate_memory_pools.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_agent_iterate_memory_pools.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_status_t (*)(hsa_amd_memory_pool_t, void *) callback = %p\n", args->hsa_amd_agent_iterate_memory_pools.callback); \
	printf("\tvoid * data = %p", args->hsa_amd_agent_iterate_memory_pools.data); \
	printf("\n"); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	size_t threshold (unsigned long);
#define PROCESS_ARGS_hsa_amd_agent_set_async_scratch_limit(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_agent_set_async_scratch_limit.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_agent_set_async_scratch_limit.agent.handle); \
	printf("\t}\n"); \
	printf("\tsize_t threshold = %lu\n", args->hsa_amd_agent_set_async_scratch_limit.threshold); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	const hsa_ext_image_descriptor_t * image_descriptor ({
//		hsa_ext_image_geometry_t geometry (enum);
//		size_t width (unsigned long);
//		size_t height (unsigned long);
//		size_t depth (unsigned long);
//		size_t array_size (unsigned long);
//		hsa_ext_image_format_t format ({
//			hsa_ext_image_channel_type32_t channel_type (unsigned int);
//			hsa_ext_image_channel_order32_t channel_order (unsigned int);
//		});
//	});
//	const void * image_data (void*);
//	hsa_access_permission_t access_permission (enum);
//	hsa_ext_image_t * image ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_ext_image_create(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_ext_image_create.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_create.agent.handle); \
	printf("\t}\n"); \
	printf("\tconst hsa_ext_image_descriptor_t * image_descriptor = %p", args->hsa_ext_image_create.image_descriptor); \
	if (args->hsa_ext_image_create.image_descriptor != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_ext_image_geometry_t geometry = %d\n", args->hsa_ext_image_create.image_descriptor__ref.val.geometry); \
		printf("\t\tsize_t width = %lu\n", args->hsa_ext_image_create.image_descriptor__ref.val.width); \
		printf("\t\tsize_t height = %lu\n", args->hsa_ext_image_create.image_descriptor__ref.val.height); \
		printf("\t\tsize_t depth = %lu\n", args->hsa_ext_image_create.image_descriptor__ref.val.depth); \
		printf("\t\tsize_t array_size = %lu\n", args->hsa_ext_image_create.image_descriptor__ref.val.array_size); \
		printf("\t\thsa_ext_image_format_t format = {\n"); \
		printf("\t\t\thsa_ext_image_channel_type32_t channel_type = %u\n", args->hsa_ext_image_create.image_descriptor__ref.val.format.channel_type); \
		printf("\t\t\thsa_ext_image_channel_order32_t channel_order = %u\n", args->hsa_ext_image_create.image_descriptor__ref.val.format.channel_order); \
		printf("\t\t}\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tconst void * image_data = %p", args->hsa_ext_image_create.image_data); \
	printf("\n"); \
	printf("\thsa_access_permission_t access_permission = %d\n", args->hsa_ext_image_create.access_permission); \
	printf("\thsa_ext_image_t * image = %p", args->hsa_ext_image_create.image); \
	if (args->hsa_ext_image_create.image != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_create.image__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_exchange_scacq_screl(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_exchange_scacq_screl.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_exchange_scacq_screl.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_exchange_scacq_screl.value); \
};


#define PROCESS_ARGS_hsa_init(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_init.retval); \
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
//	const char * options (string*);
//	hsa_loaded_code_object_t * loaded_code_object ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_executable_load_agent_code_object(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_load_agent_code_object.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_load_agent_code_object.executable.handle); \
	printf("\t}\n"); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_load_agent_code_object.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_code_object_reader_t code_object_reader = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_load_agent_code_object.code_object_reader.handle); \
	printf("\t}\n"); \
	printf("\tconst char * options = %p", args->hsa_executable_load_agent_code_object.options); \
	if (args->hsa_executable_load_agent_code_object.options != NULL) { \
		printf(" -> %s\n", args->hsa_executable_load_agent_code_object.options__ref.val); \
	} else { printf("\n"); }; \
	printf("\thsa_loaded_code_object_t * loaded_code_object = %p", args->hsa_executable_load_agent_code_object.loaded_code_object); \
	if (args->hsa_executable_load_agent_code_object.loaded_code_object != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_load_agent_code_object.loaded_code_object__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t expected (long);
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_cas_screlease(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_cas_screlease.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_cas_screlease.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t expected = %ld\n", args->hsa_signal_cas_screlease.expected); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_cas_screlease.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_amd_profiling_dispatch_time_t * time ({
//		uint64_t start (unsigned long);
//		uint64_t end (unsigned long);
//	});
#define PROCESS_ARGS_hsa_amd_profiling_get_dispatch_time(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_profiling_get_dispatch_time.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_profiling_get_dispatch_time.agent.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_profiling_get_dispatch_time.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_amd_profiling_dispatch_time_t * time = %p", args->hsa_amd_profiling_get_dispatch_time.time); \
	if (args->hsa_amd_profiling_get_dispatch_time.time != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t start = %lu\n", args->hsa_amd_profiling_get_dispatch_time.time__ref.val.start); \
		printf("\t\tuint64_t end = %lu\n", args->hsa_amd_profiling_get_dispatch_time.time__ref.val.end); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	int dmabuf (int);
#define PROCESS_ARGS_hsa_amd_portable_close_dmabuf(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_portable_close_dmabuf.retval); \
	printf("\tint dmabuf = %d\n", args->hsa_amd_portable_close_dmabuf.dmabuf); \
};

//	void * dst (void*);
//	const void * src (void*);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hsa_memory_copy(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_memory_copy.retval); \
	printf("\tvoid * dst = %p", args->hsa_memory_copy.dst); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hsa_memory_copy.src); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hsa_memory_copy.size); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_exchange_scacquire(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_exchange_scacquire.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_exchange_scacquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_exchange_scacquire.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	const hsa_ext_image_descriptor_t * image_descriptor ({
//		hsa_ext_image_geometry_t geometry (enum);
//		size_t width (unsigned long);
//		size_t height (unsigned long);
//		size_t depth (unsigned long);
//		size_t array_size (unsigned long);
//		hsa_ext_image_format_t format ({
//			hsa_ext_image_channel_type32_t channel_type (unsigned int);
//			hsa_ext_image_channel_order32_t channel_order (unsigned int);
//		});
//	});
//	hsa_access_permission_t access_permission (enum);
//	hsa_ext_image_data_layout_t image_data_layout (enum);
//	size_t image_data_row_pitch (unsigned long);
//	size_t image_data_slice_pitch (unsigned long);
//	hsa_ext_image_data_info_t * image_data_info ({
//		size_t size (unsigned long);
//		size_t alignment (unsigned long);
//	});
#define PROCESS_ARGS_hsa_ext_image_data_get_info_with_layout(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_ext_image_data_get_info_with_layout.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_data_get_info_with_layout.agent.handle); \
	printf("\t}\n"); \
	printf("\tconst hsa_ext_image_descriptor_t * image_descriptor = %p", args->hsa_ext_image_data_get_info_with_layout.image_descriptor); \
	if (args->hsa_ext_image_data_get_info_with_layout.image_descriptor != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_ext_image_geometry_t geometry = %d\n", args->hsa_ext_image_data_get_info_with_layout.image_descriptor__ref.val.geometry); \
		printf("\t\tsize_t width = %lu\n", args->hsa_ext_image_data_get_info_with_layout.image_descriptor__ref.val.width); \
		printf("\t\tsize_t height = %lu\n", args->hsa_ext_image_data_get_info_with_layout.image_descriptor__ref.val.height); \
		printf("\t\tsize_t depth = %lu\n", args->hsa_ext_image_data_get_info_with_layout.image_descriptor__ref.val.depth); \
		printf("\t\tsize_t array_size = %lu\n", args->hsa_ext_image_data_get_info_with_layout.image_descriptor__ref.val.array_size); \
		printf("\t\thsa_ext_image_format_t format = {\n"); \
		printf("\t\t\thsa_ext_image_channel_type32_t channel_type = %u\n", args->hsa_ext_image_data_get_info_with_layout.image_descriptor__ref.val.format.channel_type); \
		printf("\t\t\thsa_ext_image_channel_order32_t channel_order = %u\n", args->hsa_ext_image_data_get_info_with_layout.image_descriptor__ref.val.format.channel_order); \
		printf("\t\t}\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_access_permission_t access_permission = %d\n", args->hsa_ext_image_data_get_info_with_layout.access_permission); \
	printf("\thsa_ext_image_data_layout_t image_data_layout = %d\n", args->hsa_ext_image_data_get_info_with_layout.image_data_layout); \
	printf("\tsize_t image_data_row_pitch = %lu\n", args->hsa_ext_image_data_get_info_with_layout.image_data_row_pitch); \
	printf("\tsize_t image_data_slice_pitch = %lu\n", args->hsa_ext_image_data_get_info_with_layout.image_data_slice_pitch); \
	printf("\thsa_ext_image_data_info_t * image_data_info = %p", args->hsa_ext_image_data_get_info_with_layout.image_data_info); \
	if (args->hsa_ext_image_data_get_info_with_layout.image_data_info != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tsize_t size = %lu\n", args->hsa_ext_image_data_get_info_with_layout.image_data_info__ref.val.size); \
		printf("\t\tsize_t alignment = %lu\n", args->hsa_ext_image_data_get_info_with_layout.image_data_info__ref.val.alignment); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_executable_t executable ({
//		uint64_t handle (unsigned long);
//	});
//	const char * variable_name (string*);
//	void * address (void*);
#define PROCESS_ARGS_hsa_executable_global_variable_define(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_executable_global_variable_define.retval); \
	printf("\thsa_executable_t executable = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_executable_global_variable_define.executable.handle); \
	printf("\t}\n"); \
	printf("\tconst char * variable_name = %p", args->hsa_executable_global_variable_define.variable_name); \
	if (args->hsa_executable_global_variable_define.variable_name != NULL) { \
		printf(" -> %s\n", args->hsa_executable_global_variable_define.variable_name__ref.val); \
	} else { printf("\n"); }; \
	printf("\tvoid * address = %p", args->hsa_executable_global_variable_define.address); \
	printf("\n"); \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_add_acquire(args) { \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_add_acquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_add_acquire.value); \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	const hsa_ext_image_descriptor_t * image_descriptor ({
//		hsa_ext_image_geometry_t geometry (enum);
//		size_t width (unsigned long);
//		size_t height (unsigned long);
//		size_t depth (unsigned long);
//		size_t array_size (unsigned long);
//		hsa_ext_image_format_t format ({
//			hsa_ext_image_channel_type32_t channel_type (unsigned int);
//			hsa_ext_image_channel_order32_t channel_order (unsigned int);
//		});
//	});
//	hsa_access_permission_t access_permission (enum);
//	hsa_ext_image_data_info_t * image_data_info ({
//		size_t size (unsigned long);
//		size_t alignment (unsigned long);
//	});
#define PROCESS_ARGS_hsa_ext_image_data_get_info(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_ext_image_data_get_info.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_image_data_get_info.agent.handle); \
	printf("\t}\n"); \
	printf("\tconst hsa_ext_image_descriptor_t * image_descriptor = %p", args->hsa_ext_image_data_get_info.image_descriptor); \
	if (args->hsa_ext_image_data_get_info.image_descriptor != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_ext_image_geometry_t geometry = %d\n", args->hsa_ext_image_data_get_info.image_descriptor__ref.val.geometry); \
		printf("\t\tsize_t width = %lu\n", args->hsa_ext_image_data_get_info.image_descriptor__ref.val.width); \
		printf("\t\tsize_t height = %lu\n", args->hsa_ext_image_data_get_info.image_descriptor__ref.val.height); \
		printf("\t\tsize_t depth = %lu\n", args->hsa_ext_image_data_get_info.image_descriptor__ref.val.depth); \
		printf("\t\tsize_t array_size = %lu\n", args->hsa_ext_image_data_get_info.image_descriptor__ref.val.array_size); \
		printf("\t\thsa_ext_image_format_t format = {\n"); \
		printf("\t\t\thsa_ext_image_channel_type32_t channel_type = %u\n", args->hsa_ext_image_data_get_info.image_descriptor__ref.val.format.channel_type); \
		printf("\t\t\thsa_ext_image_channel_order32_t channel_order = %u\n", args->hsa_ext_image_data_get_info.image_descriptor__ref.val.format.channel_order); \
		printf("\t\t}\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_access_permission_t access_permission = %d\n", args->hsa_ext_image_data_get_info.access_permission); \
	printf("\thsa_ext_image_data_info_t * image_data_info = %p", args->hsa_ext_image_data_get_info.image_data_info); \
	if (args->hsa_ext_image_data_get_info.image_data_info != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tsize_t size = %lu\n", args->hsa_ext_image_data_get_info.image_data_info__ref.val.size); \
		printf("\t\tsize_t alignment = %lu\n", args->hsa_ext_image_data_get_info.image_data_info__ref.val.alignment); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hsa_signal_t signal ({
//		uint64_t handle (unsigned long);
//	});
//	hsa_signal_value_t expected (long);
//	hsa_signal_value_t value (long);
#define PROCESS_ARGS_hsa_signal_cas_scacquire(args) { \
	printf("\thsa_signal_value_t retval = %ld\n", args->hsa_signal_cas_scacquire.retval); \
	printf("\thsa_signal_t signal = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_signal_cas_scacquire.signal.handle); \
	printf("\t}\n"); \
	printf("\thsa_signal_value_t expected = %ld\n", args->hsa_signal_cas_scacquire.expected); \
	printf("\thsa_signal_value_t value = %ld\n", args->hsa_signal_cas_scacquire.value); \
};

//	uint32_t num_agents (unsigned int);
//	hsa_agent_t * agents ({
//		uint64_t handle (unsigned long);
//	});
//	int interop_handle (int);
//	uint32_t flags (unsigned int);
//	size_t * size (unsigned long*);
//	void ** ptr (void**);
//	size_t * metadata_size (unsigned long*);
//	const void ** metadata (void**);
#define PROCESS_ARGS_hsa_amd_interop_map_buffer(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_interop_map_buffer.retval); \
	printf("\tuint32_t num_agents = %u\n", args->hsa_amd_interop_map_buffer.num_agents); \
	printf("\thsa_agent_t * agents = %p", args->hsa_amd_interop_map_buffer.agents); \
	if (args->hsa_amd_interop_map_buffer.agents != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_interop_map_buffer.agents__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tint interop_handle = %d\n", args->hsa_amd_interop_map_buffer.interop_handle); \
	printf("\tuint32_t flags = %u\n", args->hsa_amd_interop_map_buffer.flags); \
	printf("\tsize_t * size = %p", args->hsa_amd_interop_map_buffer.size); \
	if (args->hsa_amd_interop_map_buffer.size != NULL) { \
		printf(" -> %lu\n", args->hsa_amd_interop_map_buffer.size__ref.val); \
	} else { printf("\n"); }; \
	printf("\tvoid ** ptr = %p", args->hsa_amd_interop_map_buffer.ptr); \
	if (args->hsa_amd_interop_map_buffer.ptr != NULL) { \
		printf("-> %p", args->hsa_amd_interop_map_buffer.ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t * metadata_size = %p", args->hsa_amd_interop_map_buffer.metadata_size); \
	if (args->hsa_amd_interop_map_buffer.metadata_size != NULL) { \
		printf(" -> %lu\n", args->hsa_amd_interop_map_buffer.metadata_size__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst void ** metadata = %p", args->hsa_amd_interop_map_buffer.metadata); \
	if (args->hsa_amd_interop_map_buffer.metadata != NULL) { \
		printf("-> %p", args->hsa_amd_interop_map_buffer.metadata__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
};

//	hsa_agent_t agent ({
//		uint64_t handle (unsigned long);
//	});
//	const hsa_ext_sampler_descriptor_t * sampler_descriptor ({
//		hsa_ext_sampler_coordinate_mode32_t coordinate_mode (unsigned int);
//		hsa_ext_sampler_filter_mode32_t filter_mode (unsigned int);
//		hsa_ext_sampler_addressing_mode32_t address_mode (unsigned int);
//	});
//	hsa_ext_sampler_t * sampler ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_ext_sampler_create(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_ext_sampler_create.retval); \
	printf("\thsa_agent_t agent = {\n"); \
	printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_sampler_create.agent.handle); \
	printf("\t}\n"); \
	printf("\tconst hsa_ext_sampler_descriptor_t * sampler_descriptor = %p", args->hsa_ext_sampler_create.sampler_descriptor); \
	if (args->hsa_ext_sampler_create.sampler_descriptor != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thsa_ext_sampler_coordinate_mode32_t coordinate_mode = %u\n", args->hsa_ext_sampler_create.sampler_descriptor__ref.val.coordinate_mode); \
		printf("\t\thsa_ext_sampler_filter_mode32_t filter_mode = %u\n", args->hsa_ext_sampler_create.sampler_descriptor__ref.val.filter_mode); \
		printf("\t\thsa_ext_sampler_addressing_mode32_t address_mode = %u\n", args->hsa_ext_sampler_create.sampler_descriptor__ref.val.address_mode); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thsa_ext_sampler_t * sampler = %p", args->hsa_ext_sampler_create.sampler); \
	if (args->hsa_ext_sampler_create.sampler != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_ext_sampler_create.sampler__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	void * serialized_code_object (void*);
//	size_t serialized_code_object_size (unsigned long);
//	const char * options (string*);
//	hsa_code_object_t * code_object ({
//		uint64_t handle (unsigned long);
//	});
#define PROCESS_ARGS_hsa_code_object_deserialize(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_code_object_deserialize.retval); \
	printf("\tvoid * serialized_code_object = %p", args->hsa_code_object_deserialize.serialized_code_object); \
	printf("\n"); \
	printf("\tsize_t serialized_code_object_size = %lu\n", args->hsa_code_object_deserialize.serialized_code_object_size); \
	printf("\tconst char * options = %p", args->hsa_code_object_deserialize.options); \
	if (args->hsa_code_object_deserialize.options != NULL) { \
		printf(" -> %s\n", args->hsa_code_object_deserialize.options__ref.val); \
	} else { printf("\n"); }; \
	printf("\thsa_code_object_t * code_object = %p", args->hsa_code_object_deserialize.code_object); \
	if (args->hsa_code_object_deserialize.code_object != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_code_object_deserialize.code_object__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	uint32_t num_agents (unsigned int);
//	const hsa_agent_t * agents ({
//		uint64_t handle (unsigned long);
//	});
//	const uint32_t * flags (unsigned int*);
//	const void * ptr (void*);
#define PROCESS_ARGS_hsa_amd_agents_allow_access(args) { \
	printf("\thsa_status_t retval = %d\n", args->hsa_amd_agents_allow_access.retval); \
	printf("\tuint32_t num_agents = %u\n", args->hsa_amd_agents_allow_access.num_agents); \
	printf("\tconst hsa_agent_t * agents = %p", args->hsa_amd_agents_allow_access.agents); \
	if (args->hsa_amd_agents_allow_access.agents != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint64_t handle = %lu\n", args->hsa_amd_agents_allow_access.agents__ref.val.handle); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tconst uint32_t * flags = %p", args->hsa_amd_agents_allow_access.flags); \
	if (args->hsa_amd_agents_allow_access.flags != NULL) { \
		printf(" -> %u\n", args->hsa_amd_agents_allow_access.flags__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst void * ptr = %p", args->hsa_amd_agents_allow_access.ptr); \
	printf("\n"); \
};

#endif // HSA_PLUGIN_H