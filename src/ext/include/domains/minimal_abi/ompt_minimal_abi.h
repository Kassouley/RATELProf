#ifndef OMPT_MINIMAL_ABI_H_
#define OMPT_MINIMAL_ABI_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* ============================================================================ *
 * Minimal ABI Header for OMPT
 * Auto-generated from CSV type definitions
 * ============================================================================ */

/* ============================================================================ *
 * Enum Types
 * ============================================================================ */

typedef enum ompt_record_t ompt_record_t;
typedef enum ompt_callbacks_t ompt_callbacks_t;
typedef enum ompt_set_result_t ompt_set_result_t;
typedef enum ompt_scope_endpoint_t ompt_scope_endpoint_t;
typedef enum ompt_sync_region_t ompt_sync_region_t;
typedef enum ompt_target_t ompt_target_t;
typedef enum ompt_work_t ompt_work_t;
typedef enum ompt_parallel_flag_t ompt_parallel_flag_t;
typedef enum ompt_task_flag_t ompt_task_flag_t;
typedef enum ompt_thread_t ompt_thread_t;
typedef enum ompt_target_map_flag_t ompt_target_map_flag_t;
typedef enum ompt_target_data_op_t ompt_target_data_op_t;
typedef enum ompt_dispatch_t ompt_dispatch_t;
typedef enum ompt_task_status_t ompt_task_status_t;
typedef enum ompt_cancel_flag_t ompt_cancel_flag_t;
typedef enum ompt_mutex_t ompt_mutex_t;
typedef enum ompt_frame_flag_t ompt_frame_flag_t;
typedef enum ompt_dependence_type_t ompt_dependence_type_t;
typedef enum ompt_record_native_t ompt_record_native_t;
typedef enum ompt_state_t ompt_state_t;
typedef enum ompt_severity_t ompt_severity_t;
typedef enum ompt_native_mon_flag_t ompt_native_mon_flag_t;

/* ============================================================================ *
 * Enum Definitions
 * ============================================================================ */

enum ompt_mutex_t {
	ompt_mutex_lock = 1,
	ompt_mutex_test_lock = 2,
	ompt_mutex_nest_lock = 3,
	ompt_mutex_test_nest_lock = 4,
	ompt_mutex_critical = 5,
	ompt_mutex_atomic = 6,
	ompt_mutex_ordered = 7,
};
enum ompt_dependence_type_t {
	ompt_dependence_type_in = 1,
	ompt_dependence_type_out = 2,
	ompt_dependence_type_inout = 3,
	ompt_dependence_type_mutexinoutset = 4,
	ompt_dependence_type_source = 5,
	ompt_dependence_type_sink = 6,
	ompt_dependence_type_inoutset = 7,
	ompt_dependence_type_out_all_memory = 34,
	ompt_dependence_type_inout_all_memory = 35,
};
enum ompt_sync_region_t {
	ompt_sync_region_barrier = 1,
	ompt_sync_region_barrier_implicit = 2,
	ompt_sync_region_barrier_explicit = 3,
	ompt_sync_region_barrier_implementation = 4,
	ompt_sync_region_taskwait = 5,
	ompt_sync_region_taskgroup = 6,
	ompt_sync_region_reduction = 7,
	ompt_sync_region_barrier_implicit_workshare = 8,
	ompt_sync_region_barrier_implicit_parallel = 9,
	ompt_sync_region_barrier_teams = 10,
};
enum ompt_scope_endpoint_t {
	ompt_scope_begin = 1,
	ompt_scope_end = 2,
	ompt_scope_beginend = 3,
};
enum ompt_cancel_flag_t {
	ompt_cancel_parallel = 1,
	ompt_cancel_sections = 2,
	ompt_cancel_loop = 4,
	ompt_cancel_taskgroup = 8,
	ompt_cancel_activated = 16,
	ompt_cancel_detected = 32,
	ompt_cancel_discarded_task = 64,
};
enum ompt_task_flag_t {
	ompt_task_initial = 1,
	ompt_task_implicit = 2,
	ompt_task_explicit = 4,
	ompt_task_target = 8,
	ompt_task_taskwait = 16,
	ompt_task_undeferred = 134217728,
	ompt_task_untied = 268435456,
	ompt_task_final = 536870912,
	ompt_task_mergeable = 1073741824,
	ompt_task_merged = 2147483648,
};
enum ompt_target_map_flag_t {
	ompt_target_map_flag_to = 1,
	ompt_target_map_flag_from = 2,
	ompt_target_map_flag_alloc = 4,
	ompt_target_map_flag_release = 8,
	ompt_target_map_flag_delete = 16,
	ompt_target_map_flag_implicit = 32,
};
enum ompt_thread_t {
	ompt_thread_initial = 1,
	ompt_thread_worker = 2,
	ompt_thread_other = 3,
	ompt_thread_unknown = 4,
};
enum ompt_dispatch_t {
	ompt_dispatch_iteration = 1,
	ompt_dispatch_section = 2,
	ompt_dispatch_ws_loop_chunk = 3,
	ompt_dispatch_taskloop_chunk = 4,
	ompt_dispatch_distribute_chunk = 5,
};
enum ompt_state_t {
	ompt_state_work_serial = 0,
	ompt_state_work_parallel = 1,
	ompt_state_work_reduction = 2,
	ompt_state_wait_barrier = 16,
	ompt_state_wait_barrier_implicit_parallel = 17,
	ompt_state_wait_barrier_implicit_workshare = 18,
	ompt_state_wait_barrier_implicit = 19,
	ompt_state_wait_barrier_explicit = 20,
	ompt_state_wait_barrier_implementation = 21,
	ompt_state_wait_barrier_teams = 22,
	ompt_state_wait_taskwait = 32,
	ompt_state_wait_taskgroup = 33,
	ompt_state_wait_mutex = 64,
	ompt_state_wait_lock = 65,
	ompt_state_wait_critical = 66,
	ompt_state_wait_atomic = 67,
	ompt_state_wait_ordered = 68,
	ompt_state_wait_target = 128,
	ompt_state_wait_target_map = 129,
	ompt_state_wait_target_update = 130,
	ompt_state_idle = 256,
	ompt_state_overhead = 257,
	ompt_state_undefined = 258,
};
enum ompt_native_mon_flag_t {
	ompt_native_data_motion_explicit = 1,
	ompt_native_data_motion_implicit = 2,
	ompt_native_kernel_invocation = 4,
	ompt_native_kernel_execution = 8,
	ompt_native_driver = 16,
	ompt_native_runtime = 32,
	ompt_native_overhead = 64,
	ompt_native_idleness = 128,
};
enum ompt_work_t {
	ompt_work_loop = 1,
	ompt_work_sections = 2,
	ompt_work_single_executor = 3,
	ompt_work_single_other = 4,
	ompt_work_workshare = 5,
	ompt_work_distribute = 6,
	ompt_work_taskloop = 7,
	ompt_work_scope = 8,
	ompt_work_loop_static = 10,
	ompt_work_loop_dynamic = 11,
	ompt_work_loop_guided = 12,
	ompt_work_loop_other = 13,
};
enum ompt_set_result_t {
	ompt_set_error = 0,
	ompt_set_never = 1,
	ompt_set_impossible = 2,
	ompt_set_sometimes = 3,
	ompt_set_sometimes_paired = 4,
	ompt_set_always = 5,
};
enum ompt_task_status_t {
	ompt_task_complete = 1,
	ompt_task_yield = 2,
	ompt_task_cancel = 3,
	ompt_task_detach = 4,
	ompt_task_early_fulfill = 5,
	ompt_task_late_fulfill = 6,
	ompt_task_switch = 7,
	ompt_taskwait_complete = 8,
};
enum ompt_callbacks_t {
	ompt_callback_thread_begin = 1,
	ompt_callback_thread_end = 2,
	ompt_callback_parallel_begin = 3,
	ompt_callback_parallel_end = 4,
	ompt_callback_task_create = 5,
	ompt_callback_task_schedule = 6,
	ompt_callback_implicit_task = 7,
	ompt_callback_target = 8,
	ompt_callback_target_data_op = 9,
	ompt_callback_target_submit = 10,
	ompt_callback_control_tool = 11,
	ompt_callback_device_initialize = 12,
	ompt_callback_device_finalize = 13,
	ompt_callback_device_load = 14,
	ompt_callback_device_unload = 15,
	ompt_callback_sync_region_wait = 16,
	ompt_callback_mutex_released = 17,
	ompt_callback_dependences = 18,
	ompt_callback_task_dependence = 19,
	ompt_callback_work = 20,
	ompt_callback_master = 21,
	ompt_callback_masked = 21,
	ompt_callback_target_map = 22,
	ompt_callback_sync_region = 23,
	ompt_callback_lock_init = 24,
	ompt_callback_lock_destroy = 25,
	ompt_callback_mutex_acquire = 26,
	ompt_callback_mutex_acquired = 27,
	ompt_callback_nest_lock = 28,
	ompt_callback_flush = 29,
	ompt_callback_cancel = 30,
	ompt_callback_reduction = 31,
	ompt_callback_dispatch = 32,
	ompt_callback_target_emi = 33,
	ompt_callback_target_data_op_emi = 34,
	ompt_callback_target_submit_emi = 35,
	ompt_callback_target_map_emi = 36,
	ompt_callback_error = 37,
};
enum ompt_target_t {
	ompt_target = 1,
	ompt_target_enter_data = 2,
	ompt_target_exit_data = 3,
	ompt_target_update = 4,
	ompt_target_nowait = 9,
	ompt_target_enter_data_nowait = 10,
	ompt_target_exit_data_nowait = 11,
	ompt_target_update_nowait = 12,
};
enum ompt_target_data_op_t {
	ompt_target_data_alloc = 1,
	ompt_target_data_transfer_to_device = 2,
	ompt_target_data_transfer_from_device = 3,
	ompt_target_data_delete = 4,
	ompt_target_data_associate = 5,
	ompt_target_data_disassociate = 6,
	ompt_target_data_alloc_async = 17,
	ompt_target_data_transfer_to_device_async = 18,
	ompt_target_data_transfer_from_device_async = 19,
	ompt_target_data_delete_async = 20,
};
enum ompt_record_t {
	ompt_record_ompt = 1,
	ompt_record_native = 2,
	ompt_record_invalid = 3,
};
enum ompt_severity_t {
	ompt_warning = 1,
	ompt_fatal = 2,
};
enum ompt_record_native_t {
	ompt_record_native_info = 1,
	ompt_record_native_event = 2,
};
enum ompt_parallel_flag_t {
	ompt_parallel_invoker_program = 1,
	ompt_parallel_invoker_runtime = 2,
	ompt_parallel_league = 1073741824,
	ompt_parallel_team = 2147483648,
};
enum ompt_frame_flag_t {
	ompt_frame_runtime = 0,
	ompt_frame_application = 1,
	ompt_frame_cfa = 16,
	ompt_frame_framepointer = 32,
	ompt_frame_stackaddress = 48,
};

/* ============================================================================ *
 * Structure Types
 * ============================================================================ */

typedef union ompt_data_t ompt_data_t;
typedef struct ompt_record_task_create_t ompt_record_task_create_t;
typedef struct ompt_record_target_data_op_t ompt_record_target_data_op_t;
typedef struct ompt_record_dispatch_t ompt_record_dispatch_t;
typedef struct ompt_record_target_map_t ompt_record_target_map_t;
typedef struct ompt_dependence_t ompt_dependence_t;
typedef struct ompt_record_dependences_t ompt_record_dependences_t;
typedef struct ompt_record_target_t ompt_record_target_t;
typedef struct ompt_record_cancel_t ompt_record_cancel_t;
typedef struct ompt_record_abstract_t ompt_record_abstract_t;
typedef struct ompt_record_error_t ompt_record_error_t;
typedef struct ompt_record_mutex_t ompt_record_mutex_t;
typedef struct ompt_record_task_schedule_t ompt_record_task_schedule_t;
typedef struct ompt_record_parallel_begin_t ompt_record_parallel_begin_t;
typedef struct ompt_start_tool_result_t ompt_start_tool_result_t;
typedef struct ompt_record_task_dependence_t ompt_record_task_dependence_t;
typedef struct ompt_record_thread_begin_t ompt_record_thread_begin_t;
typedef struct ompt_record_nest_lock_t ompt_record_nest_lock_t;
typedef struct ompt_record_mutex_acquire_t ompt_record_mutex_acquire_t;
typedef struct ompt_record_ompt_t ompt_record_ompt_t;
typedef struct ompt_record_implicit_task_t ompt_record_implicit_task_t;
typedef struct ompt_frame_t ompt_frame_t;
typedef struct ompt_record_control_tool_t ompt_record_control_tool_t;
typedef struct ompt_record_parallel_end_t ompt_record_parallel_end_t;
typedef struct ompt_record_target_kernel_t ompt_record_target_kernel_t;
typedef struct ompt_record_flush_t ompt_record_flush_t;
typedef struct ompt_dispatch_chunk_t ompt_dispatch_chunk_t;
typedef struct ompt_record_work_t ompt_record_work_t;
typedef struct ompt_record_sync_region_t ompt_record_sync_region_t;
typedef struct ompt_record_masked_t ompt_record_masked_t;

/* ============================================================================ *
 * Basic Types
 * ============================================================================ */

typedef void (*ompt_callback_dependences_t)(ompt_data_t *, const ompt_dependence_t *, int);
typedef uint64_t ompt_buffer_cursor_t;
typedef void ompt_buffer_t;
typedef ompt_record_t (*ompt_get_record_type_t)(ompt_buffer_t *, ompt_buffer_cursor_t);
typedef void (*ompt_finalize_tool_t)(void);
typedef uint64_t ompt_wait_id_t;
typedef int (*ompt_get_state_t)(ompt_wait_id_t *);
typedef void (*ompt_callback_t)(void);
typedef ompt_set_result_t (*ompt_set_callback_t)(ompt_callbacks_t, ompt_callback_t);
typedef void (*ompt_interface_fn_t)(void);
typedef void (*ompt_callback_sync_region_t)(ompt_sync_region_t, ompt_scope_endpoint_t, ompt_data_t *, ompt_data_t *, const void *);
typedef void (*ompt_callback_target_emi_t)(ompt_target_t, ompt_scope_endpoint_t, int, ompt_data_t *, ompt_data_t *, ompt_data_t *, const void *);
typedef uint64_t ompt_id_t;
typedef void (*ompt_callback_target_t)(ompt_target_t, ompt_scope_endpoint_t, int, ompt_data_t *, ompt_id_t, const void *);
typedef void (*ompt_callback_task_create_t)(ompt_data_t *, const ompt_frame_t *, ompt_data_t *, int, int, const void *);
typedef void (*ompt_callback_buffer_request_t)(int, ompt_buffer_t **, size_t *);
typedef int (*ompt_get_num_devices_t)(void);
typedef int (*ompt_get_target_info_t)(uint64_t *, ompt_id_t *, ompt_id_t *);
typedef void (*ompt_callback_implicit_task_t)(ompt_scope_endpoint_t, ompt_data_t *, ompt_data_t *, unsigned int, unsigned int, int);
typedef uint64_t ompt_hwid_t;
typedef int (*ompt_get_parallel_info_t)(int, ompt_data_t **, int *);
typedef void * (*ompt_get_record_native_t)(ompt_buffer_t *, ompt_buffer_cursor_t, ompt_id_t *);
typedef ompt_data_t * (*ompt_get_thread_data_t)(void);
typedef void (*ompt_callback_device_load_t)(int, const char *, int64_t, void *, size_t, void *, void *, uint64_t);
typedef int (*ompt_get_proc_id_t)(void);
typedef void (*ompt_callback_parallel_begin_t)(ompt_data_t *, const ompt_frame_t *, ompt_data_t *, unsigned int, int, const void *);
typedef void (*ompt_callback_work_t)(ompt_work_t, ompt_scope_endpoint_t, ompt_data_t *, ompt_data_t *, uint64_t, const void *);
typedef int (*ompt_get_num_places_t)(void);
typedef void (*ompt_callback_masked_t)(ompt_scope_endpoint_t, ompt_data_t *, ompt_data_t *, const void *);
typedef ompt_callback_masked_t ompt_callback_master_t;
typedef void ompt_device_t;
typedef void (*ompt_callback_target_data_op_emi_t)(ompt_scope_endpoint_t, ompt_data_t *, ompt_data_t *, ompt_id_t *, ompt_target_data_op_t, void *, int, void *, int, size_t, const void *);
typedef void (*ompt_callback_buffer_complete_t)(int, ompt_buffer_t *, size_t, ompt_buffer_cursor_t, int);
typedef void (*ompt_callback_thread_end_t)(ompt_data_t *);
typedef uint64_t (*ompt_get_unique_id_t)(void);
typedef void (*ompt_callback_flush_t)(ompt_data_t *, const void *);
typedef void (*ompt_callback_dispatch_t)(ompt_data_t *, ompt_data_t *, ompt_dispatch_t, ompt_data_t);
typedef int (*ompt_get_callback_t)(ompt_callbacks_t, ompt_callback_t *);
typedef void (*ompt_callback_device_finalize_t)(int);
typedef ompt_set_result_t (*ompt_set_trace_native_t)(ompt_device_t *, int, int);
typedef void (*ompt_callback_target_submit_t)(ompt_id_t, ompt_id_t, unsigned int);
typedef void (*ompt_callback_nest_lock_t)(ompt_scope_endpoint_t, ompt_wait_id_t, const void *);
typedef void (*ompt_callback_thread_begin_t)(ompt_thread_t, ompt_data_t *);
typedef ompt_interface_fn_t (*ompt_function_lookup_t)(const char *);
typedef int (*ompt_initialize_t)(ompt_function_lookup_t, int, ompt_data_t *);
typedef void (*ompt_callback_mutex_acquire_t)(ompt_mutex_t, unsigned int, unsigned int, ompt_wait_id_t, const void *);
typedef ompt_set_result_t (*ompt_set_trace_ompt_t)(ompt_device_t *, unsigned int, unsigned int);
typedef int (*ompt_pause_trace_t)(ompt_device_t *, int);
typedef ompt_record_abstract_t * (*ompt_get_record_abstract_t)(void *);
typedef uint64_t ompt_device_time_t;
typedef int (*ompt_enumerate_mutex_impls_t)(int, int *, const char **);
typedef int (*ompt_get_task_info_t)(int, int *, ompt_data_t **, ompt_frame_t **, ompt_data_t **, int *);
typedef int (*ompt_get_num_procs_t)(void);
typedef ompt_record_ompt_t * (*ompt_get_record_ompt_t)(ompt_buffer_t *, ompt_buffer_cursor_t);
typedef int (*ompt_advance_buffer_cursor_t)(ompt_device_t *, ompt_buffer_t *, size_t, ompt_buffer_cursor_t, ompt_buffer_cursor_t *);
typedef int (*ompt_get_device_num_procs_t)(ompt_device_t *);
typedef void (*ompt_callback_target_submit_emi_t)(ompt_scope_endpoint_t, ompt_data_t *, ompt_id_t *, unsigned int);
typedef int (*ompt_enumerate_states_t)(int, int *, const char **);
typedef double (*ompt_translate_time_t)(ompt_device_t *, ompt_device_time_t);
typedef int (*ompt_callback_control_tool_t)(uint64_t, uint64_t, void *, const void *);
typedef int (*ompt_get_place_num_t)(void);
typedef void (*ompt_callback_device_unload_t)(int, uint64_t);
typedef void (*ompt_finalize_t)(ompt_data_t *);
typedef int (*ompt_stop_trace_t)(ompt_device_t *);
typedef void (*ompt_callback_device_initialize_t)(int, const char *, ompt_device_t *, ompt_function_lookup_t, const char *);
typedef int (*ompt_start_trace_t)(ompt_device_t *, ompt_callback_buffer_request_t, ompt_callback_buffer_complete_t);
typedef void (*ompt_callback_task_dependence_t)(ompt_data_t *, ompt_data_t *);
typedef void (*ompt_callback_target_data_op_t)(ompt_id_t, ompt_id_t, ompt_target_data_op_t, void *, int, void *, int, size_t, const void *);
typedef int (*ompt_flush_trace_t)(ompt_device_t *);
typedef void (*ompt_callback_error_t)(ompt_severity_t, const char *, size_t, const void *);
typedef void (*ompt_callback_target_map_t)(ompt_id_t, unsigned int, void **, void **, size_t *, unsigned int *, const void *);
typedef void (*ompt_callback_mutex_t)(ompt_mutex_t, ompt_wait_id_t, const void *);
typedef void (*ompt_callback_task_schedule_t)(ompt_data_t *, ompt_task_status_t, ompt_data_t *);
typedef void (*ompt_callback_parallel_end_t)(ompt_data_t *, ompt_data_t *, int, const void *);
typedef int (*ompt_get_place_proc_ids_t)(int, int, int *);
typedef void (*ompt_callback_cancel_t)(ompt_data_t *, int, const void *);
typedef int (*ompt_get_task_memory_t)(void **, size_t *, int);
typedef int (*ompt_get_partition_place_nums_t)(int, int *);
typedef ompt_device_time_t (*ompt_get_device_time_t)(ompt_device_t *);
typedef void (*ompt_callback_target_map_emi_t)(ompt_data_t *, unsigned int, void **, void **, size_t *, unsigned int *, const void *);

/* ============================================================================ *
 * Structure Definitions
 * ============================================================================ */

struct ompt_record_target_t {
    ompt_target_t kind;
    ompt_scope_endpoint_t endpoint;
    int device_num;
    ompt_id_t task_id;
    ompt_id_t target_id;
    const void *codeptr_ra;
};

struct ompt_record_target_kernel_t {
    ompt_id_t host_op_id;
    unsigned int requested_num_teams;
    unsigned int granted_num_teams;
    ompt_device_time_t end_time;
};

struct ompt_record_target_map_t {
    ompt_id_t target_id;
    unsigned int nitems;
    void **host_addr;
    void **device_addr;
    size_t *bytes;
    unsigned int *mapping_flags;
    const void *codeptr_ra;
};

struct ompt_record_flush_t {
    const void *codeptr_ra;
};

struct ompt_record_work_t {
    ompt_work_t work_type;
    ompt_scope_endpoint_t endpoint;
    ompt_id_t parallel_id;
    ompt_id_t task_id;
    uint64_t count;
    const void *codeptr_ra;
};

struct ompt_record_thread_begin_t {
    ompt_thread_t thread_type;
};

struct ompt_record_nest_lock_t {
    ompt_scope_endpoint_t endpoint;
    ompt_wait_id_t wait_id;
    const void *codeptr_ra;
};

struct ompt_record_task_schedule_t {
    ompt_id_t prior_task_id;
    ompt_task_status_t prior_task_status;
    ompt_id_t next_task_id;
};

struct ompt_record_task_dependence_t {
    ompt_id_t src_task_id;
    ompt_id_t sink_task_id;
};

struct ompt_record_target_data_op_t {
    ompt_id_t host_op_id;
    ompt_target_data_op_t optype;
    void *src_addr;
    int src_device_num;
    void *dest_addr;
    int dest_device_num;
    size_t bytes;
    ompt_device_time_t end_time;
    const void *codeptr_ra;
};

union ompt_data_t {
    uint64_t value;
    void *ptr;
};

struct ompt_frame_t {
    ompt_data_t exit_frame;
    ompt_data_t enter_frame;
    int exit_frame_flags;
    int enter_frame_flags;
};

struct ompt_record_control_tool_t {
    uint64_t command;
    uint64_t modifier;
    const void *codeptr_ra;
};

struct ompt_record_cancel_t {
    ompt_id_t task_id;
    int flags;
    const void *codeptr_ra;
};

struct ompt_record_task_create_t {
    ompt_id_t encountering_task_id;
    ompt_id_t new_task_id;
    int flags;
    int has_dependences;
    const void *codeptr_ra;
};

struct ompt_record_parallel_end_t {
    ompt_id_t parallel_id;
    ompt_id_t encountering_task_id;
    int flags;
    const void *codeptr_ra;
};

struct ompt_record_mutex_acquire_t {
    ompt_mutex_t kind;
    unsigned int hint;
    unsigned int impl;
    ompt_wait_id_t wait_id;
    const void *codeptr_ra;
};

struct ompt_record_dispatch_t {
    ompt_id_t parallel_id;
    ompt_id_t task_id;
    ompt_dispatch_t kind;
    ompt_data_t instance;
};

struct ompt_record_sync_region_t {
    ompt_sync_region_t kind;
    ompt_scope_endpoint_t endpoint;
    ompt_id_t parallel_id;
    ompt_id_t task_id;
    const void *codeptr_ra;
};

struct ompt_record_implicit_task_t {
    ompt_scope_endpoint_t endpoint;
    ompt_id_t parallel_id;
    ompt_id_t task_id;
    unsigned int actual_parallelism;
    unsigned int index;
    int flags;
};

struct ompt_record_masked_t {
    ompt_scope_endpoint_t endpoint;
    ompt_id_t parallel_id;
    ompt_id_t task_id;
    const void *codeptr_ra;
};

struct ompt_record_parallel_begin_t {
    ompt_id_t encountering_task_id;
    ompt_id_t parallel_id;
    unsigned int requested_parallelism;
    int flags;
    const void *codeptr_ra;
};

struct ompt_record_mutex_t {
    ompt_mutex_t kind;
    ompt_wait_id_t wait_id;
    const void *codeptr_ra;
};

struct ompt_dependence_t {
    ompt_data_t variable;
    ompt_dependence_type_t dependence_type;
};

struct ompt_record_dependences_t {
    ompt_id_t task_id;
    ompt_dependence_t dep;
    int ndeps;
};

struct ompt_dispatch_chunk_t {
    uint64_t start;
    uint64_t iterations;
};

struct ompt_record_error_t {
    ompt_severity_t severity;
    const char *message;
    size_t length;
    const void *codeptr_ra;
};

struct ompt_record_ompt_t {
    ompt_callbacks_t type;
    ompt_device_time_t time;
    ompt_id_t thread_id;
    ompt_id_t target_id;
    union {
        ompt_record_thread_begin_t thread_begin;
        ompt_record_parallel_begin_t parallel_begin;
        ompt_record_parallel_end_t parallel_end;
        ompt_record_work_t work;
        ompt_record_dispatch_t dispatch;
        ompt_record_task_create_t task_create;
        ompt_record_dependences_t dependences;
        ompt_record_task_dependence_t task_dependence;
        ompt_record_task_schedule_t task_schedule;
        ompt_record_implicit_task_t implicit_task;
        ompt_record_masked_t masked;
        ompt_record_sync_region_t sync_region;
        ompt_record_mutex_acquire_t mutex_acquire;
        ompt_record_mutex_t mutex;
        ompt_record_nest_lock_t nest_lock;
        ompt_record_flush_t flush;
        ompt_record_cancel_t cancel;
        ompt_record_target_t target;
        ompt_record_target_data_op_t target_data_op;
        ompt_record_target_map_t target_map;
        ompt_record_target_kernel_t target_kernel;
        ompt_record_control_tool_t control_tool;
    } record;
};

struct ompt_record_abstract_t {
    ompt_record_native_t rclass;
    const char *type;
    ompt_device_time_t start_time;
    ompt_device_time_t end_time;
    ompt_hwid_t hwid;
};

struct ompt_start_tool_result_t {
    ompt_initialize_t initialize;
    ompt_finalize_t finalize;
    ompt_data_t tool_data;
};


#endif /* OMPT_MINIMAL_ABI_H_ */
