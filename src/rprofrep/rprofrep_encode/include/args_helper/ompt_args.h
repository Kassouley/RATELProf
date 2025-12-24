
#ifndef OMPT_ARGS_H
#define OMPT_ARGS_H

#include <ratelprof.h>
#include <ratelprof_ext.h>

#include "rprofrep_encode_context.h"
#include "utils/rprofrep_msgpack_ext.h"

#include "msgpack.h"

static void write_target_data_op_args_to_buffer(args_target_data_op_t* args, rprofrep_encode_context_t* ctx, msgpack_buffer_t* buf) {
	//	ompt_id_t* host_op_id (unsigned long);
	//	void* src_addr (void);
	//	int src_device_num (int);
	//	void* dest_addr (void);
	//	int dest_device_num (int);
	//	size_t bytes (unsigned long);
	msgpack_encode_array(buf, 6);
	msgpack_encode_uint(buf, (uintptr_t)args->host_op_id);
	msgpack_encode_uint(buf, (uintptr_t)args->src_addr);
	msgpack_encode_int(buf, args->src_device_num);
	msgpack_encode_uint(buf, (uintptr_t)args->dest_addr);
	msgpack_encode_int(buf, args->dest_device_num);
	msgpack_encode_int(buf, args->bytes);
}

static void write_target_data_op_params_to_buffer(rprofrep_encode_context_t* ctx, msgpack_buffer_t* buf) {
	//	ompt_id_t* host_op_id (unsigned long);
	//	void* src_addr (void);
	//	int src_device_num (int);
	//	void* dest_addr (void);
	//	int dest_device_num (int);
	//	size_t bytes (unsigned long);
	rprofrep_msgpack_ext_encode_string(ctx, buf, "ompt_id_t*");
	rprofrep_msgpack_ext_encode_string(ctx, buf, "host_op_id");

	rprofrep_msgpack_ext_encode_string(ctx, buf, "void*");
	rprofrep_msgpack_ext_encode_string(ctx, buf, "src_addr");

	rprofrep_msgpack_ext_encode_string(ctx, buf, "int");
	rprofrep_msgpack_ext_encode_string(ctx, buf, "src_device_num");

	rprofrep_msgpack_ext_encode_string(ctx, buf, "void*");
	rprofrep_msgpack_ext_encode_string(ctx, buf, "dest_addr");

	rprofrep_msgpack_ext_encode_string(ctx, buf, "int");
	rprofrep_msgpack_ext_encode_string(ctx, buf, "dest_device_num");

	rprofrep_msgpack_ext_encode_string(ctx, buf, "size_t");
	rprofrep_msgpack_ext_encode_string(ctx, buf, "bytes");
}

#define DECL_TARGET_DATA_OP_ARG_WRITER_FUNCTION(name) \
static void write_##name##_args_to_buffer(const void* func_args, rprofrep_encode_context_t* ctx, msgpack_buffer_t* buf) { \
	write_target_data_op_args_to_buffer((args_target_data_op_t*)func_args, ctx, buf); \
}

#define DECL_TARGET_DATA_OP_PARAM_WRITER_FUNCTION(name) \
static void write_##name##_params_to_buffer(rprofrep_encode_context_t* ctx, msgpack_buffer_t* buf) { \
	write_target_data_op_params_to_buffer(ctx, buf); \
}

FOR_EACH_OMPT_TARGET_DATA_FUNC(DECL_TARGET_DATA_OP_ARG_WRITER_FUNCTION)
FOR_EACH_OMPT_TARGET_DATA_FUNC(DECL_TARGET_DATA_OP_PARAM_WRITER_FUNCTION)


static void __write_target_args_to_buffer(args_target_emi_t* args, rprofrep_encode_context_t* ctx, msgpack_buffer_t* buf) {
	//	int device_num (int);
	msgpack_encode_array(buf, 1);
	msgpack_encode_int(buf, args->device_num);
}

static void __write_target_params_to_buffer(rprofrep_encode_context_t* ctx, msgpack_buffer_t* buf) {
	//	int device_num (int);
	rprofrep_msgpack_ext_encode_string(ctx, buf, "int");
	rprofrep_msgpack_ext_encode_string(ctx, buf, "device_num");
}


#define DECL_TARGET_ARG_WRITER_FUNCTION(name) \
static void write_##name##_args_to_buffer(const void* func_args, rprofrep_encode_context_t* ctx, msgpack_buffer_t* buf) { \
	__write_target_args_to_buffer((args_target_emi_t*) func_args, ctx, buf); \
}

#define DECL_TARGET_PARAM_WRITER_FUNCTION(name) \
static void write_##name##_params_to_buffer(rprofrep_encode_context_t* ctx, msgpack_buffer_t* buf) { \
	__write_target_params_to_buffer(ctx, buf); \
}

FOR_EACH_OMPT_TARGET_FUNC(DECL_TARGET_ARG_WRITER_FUNCTION)
FOR_EACH_OMPT_TARGET_FUNC(DECL_TARGET_PARAM_WRITER_FUNCTION)


static void write_target_submit_args_to_buffer(args_target_submit_emi_t* args, rprofrep_encode_context_t* ctx, msgpack_buffer_t* buf) {
	//	ompt_id_t* host_op_id (unsigned long);
	//	unsigned int requested_num_teams (unsigned int);
	msgpack_encode_array(buf, 2);
	msgpack_encode_uint(buf, (uintptr_t)args->host_op_id);
	msgpack_encode_int(buf, args->requested_num_teams);
}

static void write_target_submit_params_to_buffer(rprofrep_encode_context_t* ctx, msgpack_buffer_t* buf) {
	//	ompt_id_t* host_op_id (unsigned long);
	//	unsigned int requested_num_teams (unsigned int);
	rprofrep_msgpack_ext_encode_string(ctx, buf, "ompt_id_t*");
	rprofrep_msgpack_ext_encode_string(ctx, buf, "host_op_id");
	rprofrep_msgpack_ext_encode_string(ctx, buf, "unsigned int");
	rprofrep_msgpack_ext_encode_string(ctx, buf, "requested_num_teams");
}


static void write_target_map_args_to_buffer(args_target_map_emi_t* args, rprofrep_encode_context_t* ctx, msgpack_buffer_t* buf) {
	//	unsigned int nitems (unsigned int);
	//	void** host_addr (void);
	//	void** device_addr (void);
	//	size_t* bytes (unsigned long);
	//	unsigned int* mapping_flags (unsigned int);
	msgpack_encode_int(buf, args->nitems);

	msgpack_encode_array(buf, args->nitems);
	for (int i = 0; i < args->nitems; i++)
	{
		msgpack_encode_uint(buf, (uintptr_t)args->map[i].host_addr);
	}

	msgpack_encode_array(buf, args->nitems);
	for (int i = 0; i < args->nitems; i++)
	{
		msgpack_encode_uint(buf, (uintptr_t)args->map[i].device_addr);
	}
	msgpack_encode_array(buf, args->nitems);
	for (int i = 0; i < args->nitems; i++)
	{
		msgpack_encode_uint(buf, args->map[i].bytes);
	}

	msgpack_encode_array(buf, args->nitems);
	for (int i = 0; i < args->nitems; i++)
	{
		rprofrep_msgpack_ext_encode_string(ctx, buf, get_map_flag_name(args->map[i].mapping_flags));
	}
}

static void write_target_map_params_to_buffer(rprofrep_encode_context_t* ctx, msgpack_buffer_t* buf) {
	//	unsigned int nitems (unsigned int);
	//	void** host_addr (void);
	//	void** device_addr (void);
	//	size_t* bytes (unsigned long);
	//	unsigned int* mapping_flags (unsigned int);
	rprofrep_msgpack_ext_encode_string(ctx, buf, "unsigned int");
	rprofrep_msgpack_ext_encode_string(ctx, buf, "nitems");

	rprofrep_msgpack_ext_encode_string(ctx, buf, "void**");
	rprofrep_msgpack_ext_encode_string(ctx, buf, "host_addr");

	rprofrep_msgpack_ext_encode_string(ctx, buf, "void**");
	rprofrep_msgpack_ext_encode_string(ctx, buf, "device_addr");

	rprofrep_msgpack_ext_encode_string(ctx, buf, "size_t*");
	rprofrep_msgpack_ext_encode_string(ctx, buf, "bytes");

	rprofrep_msgpack_ext_encode_string(ctx, buf, "ompt_target_map_flag_t*");
	rprofrep_msgpack_ext_encode_string(ctx, buf, "mapping_flags");
}

#endif // OMPT_ARGS_H