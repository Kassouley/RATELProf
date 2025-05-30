/** THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA. 
 */
 
#include <ratelprof.h>
#include <ratelprof_ext.h>
#include "ompt_plugin.h"
#include "msgpack.h"

void on_enter_ompt_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, void* a){
	ratelprof_ompt_api_activity_t* activity = (ratelprof_ompt_api_activity_t*) a;
    ratelprof_activity_pool_push_activity(activity);
    get_correlation_id(&activity->corr_id);
    get_id(&activity->id);
    activity->phase = ratelprof_get_current_phase();
    activity->domain = domain;
    activity->funid = id;
    activity->pid = get_pid();
    activity->tid = get_tid();
    activity->start_time = ratelprof_get_curr_timespec();
}

void on_exit_ompt_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, void* a){
	(void)domain;
	(void)id;
	ratelprof_ompt_api_activity_t* activity = (ratelprof_ompt_api_activity_t*) a;
    activity->stop_time = ratelprof_get_curr_timespec();
    pop_id();
}


void process_ompt_args_for(ompt_api_id_t funid, const ompt_api_args_t* args, void* user_args) 
{
    msgpack_buffer_t* buf = (msgpack_buffer_t*)user_args;
    switch(funid) {
        case OMPT_API_ID_target_data_alloc :
        case OMPT_API_ID_target_data_transfer_to_device :
        case OMPT_API_ID_target_data_transfer_from_device :
        case OMPT_API_ID_target_data_delete :
        case OMPT_API_ID_target_data_associate :
        case OMPT_API_ID_target_data_disassociate :
        case OMPT_API_ID_target_data_alloc_async :
        case OMPT_API_ID_target_data_transfer_to_device_async :
        case OMPT_API_ID_target_data_transfer_from_device_async :
        case OMPT_API_ID_target_data_delete_async :
			//	ompt_id_t* host_op_id (unsigned long);
			//	void* src_addr (void);
			//	int src_device_num (int);
			//	void* dest_addr (void);
			//	int dest_device_num (int);
			//	size_t bytes (unsigned long);
			//	const void* codeptr_ra (void);
			msgpack_encode_map(buf, 7);
			msgpack_encode_string(buf, "host_op_id");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "ompt_id_t*");
			msgpack_encode_string(buf, "value");
			msgpack_encode_uint(buf, (uintptr_t)args->target_data_op.host_op_id);

			msgpack_encode_string(buf, "src_addr");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "void*");
			msgpack_encode_string(buf, "value");
			msgpack_encode_uint(buf, (uintptr_t)args->target_data_op.src_addr);

			msgpack_encode_string(buf, "src_device_num");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "int");
			msgpack_encode_string(buf, "value");
			msgpack_encode_int(buf, args->target_data_op.src_device_num);

			msgpack_encode_string(buf, "dest_addr");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "void*");
			msgpack_encode_string(buf, "value");
			msgpack_encode_uint(buf, (uintptr_t)args->target_data_op.dest_addr);

			msgpack_encode_string(buf, "dest_device_num");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "int");
			msgpack_encode_string(buf, "value");
			msgpack_encode_int(buf, args->target_data_op.dest_device_num);

			msgpack_encode_string(buf, "bytes");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "size_t");
			msgpack_encode_string(buf, "value");
			msgpack_encode_int(buf, args->target_data_op.bytes);

			msgpack_encode_string(buf, "codeptr_ra");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "const void*");
			msgpack_encode_string(buf, "value");
			msgpack_encode_uint(buf, (uintptr_t)args->target_data_op.codeptr_ra);

			break;

		case OMPT_API_ID_target_map :
			//	unsigned int nitems (unsigned int);
			//	void** host_addr (void);
			//	void** device_addr (void);
			//	size_t* bytes (unsigned long);
			//	unsigned int* mapping_flags (unsigned int);
			//	const void* codeptr_ra (void);
			msgpack_encode_map(buf, 6);
			msgpack_encode_string(buf, "nitems");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "unsigned int");
			msgpack_encode_string(buf, "value");
			msgpack_encode_int(buf, args->target_map_emi.nitems);

			msgpack_encode_string(buf, "host_addr");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "void**");
			msgpack_encode_string(buf, "value");
			msgpack_encode_array(buf, args->target_map_emi.nitems);
			for (int i = 0; i < args->target_map_emi.nitems; i++)
			{
				msgpack_encode_uint(buf, (uintptr_t)args->target_map_emi.map[i].host_addr);
			}

			msgpack_encode_string(buf, "device_addr");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "void**");
			msgpack_encode_string(buf, "value");
			msgpack_encode_array(buf, args->target_map_emi.nitems);
			for (int i = 0; i < args->target_map_emi.nitems; i++)
			{
				msgpack_encode_uint(buf, (uintptr_t)args->target_map_emi.map[i].device_addr);
			}

			msgpack_encode_string(buf, "bytes");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "size_t*");
			msgpack_encode_string(buf, "value");
			msgpack_encode_array(buf, args->target_map_emi.nitems);
			for (int i = 0; i < args->target_map_emi.nitems; i++)
			{
				msgpack_encode_uint(buf, args->target_map_emi.map[i].bytes);
			}

			msgpack_encode_string(buf, "mapping_flags");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "ompt_target_map_flag_t*");
			msgpack_encode_string(buf, "value");
			msgpack_encode_array(buf, args->target_map_emi.nitems);
			for (int i = 0; i < args->target_map_emi.nitems; i++)
			{
				msgpack_encode_string(buf, get_map_flag_name(args->target_map_emi.map[i].mapping_flags));
			}

			msgpack_encode_string(buf, "codeptr_ra");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "const void*");
			msgpack_encode_string(buf, "value");
			msgpack_encode_uint(buf, (uintptr_t)args->target_map_emi.codeptr_ra);

			break;

		case OMPT_API_ID_target_submit :
			//	ompt_id_t* host_op_id (unsigned long);
			//	unsigned int requested_num_teams (unsigned int);
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "host_op_id");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "ompt_id_t*");
			msgpack_encode_string(buf, "value");
			msgpack_encode_uint(buf, (uintptr_t)args->target_submit_emi.host_op_id);

			msgpack_encode_string(buf, "requested_num_teams");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "unsigned int");
			msgpack_encode_string(buf, "value");
			msgpack_encode_int(buf, args->target_submit_emi.requested_num_teams);

			break;
        case OMPT_API_ID_target :
        case OMPT_API_ID_target_enter_data :
        case OMPT_API_ID_target_exit_data :
        case OMPT_API_ID_target_update :
        case OMPT_API_ID_target_nowait :
        case OMPT_API_ID_target_enter_data_nowait :
        case OMPT_API_ID_target_exit_data_nowait :
        case OMPT_API_ID_target_update_nowait :
			//	int device_num (int);
			//	const void* codeptr_ra (void);
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "device_num");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "int");
			msgpack_encode_string(buf, "value");
			msgpack_encode_int(buf, args->target_emi.device_num);

			msgpack_encode_string(buf, "codeptr_ra");
			msgpack_encode_map(buf, 2);
			msgpack_encode_string(buf, "type");
			msgpack_encode_string(buf, "const void*");
			msgpack_encode_string(buf, "value");
			msgpack_encode_uint(buf, (uintptr_t)args->target_emi.codeptr_ra);

			break;
 
        default : break;
    }
}


