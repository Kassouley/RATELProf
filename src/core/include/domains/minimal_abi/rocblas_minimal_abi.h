#ifndef ROCBLAS_MINIMAL_ABI_H_
#define ROCBLAS_MINIMAL_ABI_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* ============================================================================ *
 * Minimal ABI Header for ROCBLAS
 * Auto-generated from CSV type definitions
 * ============================================================================ */

/* ============================================================================ *
 * Enum Types
 * ============================================================================ */

typedef enum rocblas_fill_ rocblas_fill;
typedef enum rocblas_diagonal_ rocblas_diagonal;
typedef enum rocblas_atomics_mode_ rocblas_atomics_mode;
typedef enum rocblas_layer_mode_ rocblas_layer_mode;
typedef enum rocblas_geam_ex_operation_ rocblas_geam_ex_operation;
typedef enum rocblas_math_mode_ rocblas_math_mode;
typedef enum rocblas_side_ rocblas_side;
typedef enum rocblas_pointer_mode_ rocblas_pointer_mode;
typedef enum rocblas_datatype_ rocblas_datatype;
typedef enum rocblas_performance_metric_ rocblas_performance_metric;
typedef enum rocblas_check_numerics_mode_ rocblas_check_numerics_mode;
typedef enum rocblas_operation_ rocblas_operation;
typedef enum rocblas_status_ rocblas_status;
typedef enum rocblas_gemm_flags_ rocblas_gemm_flags;
typedef enum rocblas_gemm_algo_ rocblas_gemm_algo;

/* ============================================================================ *
 * Enum Definitions
 * ============================================================================ */

enum rocblas_layer_mode_ {
	rocblas_layer_mode_none = 0,
	rocblas_layer_mode_log_trace = 1,
	rocblas_layer_mode_log_bench = 2,
	rocblas_layer_mode_log_profile = 4,
	rocblas_layer_mode_log_internal = 8,
};
enum rocblas_atomics_mode_ {
	rocblas_atomics_not_allowed = 0,
	rocblas_atomics_allowed = 1,
};
enum rocblas_fill_ {
	rocblas_fill_upper = 121,
	rocblas_fill_lower = 122,
	rocblas_fill_full = 123,
};
enum rocblas_status_ {
	rocblas_status_success = 0,
	rocblas_status_invalid_handle = 1,
	rocblas_status_not_implemented = 2,
	rocblas_status_invalid_pointer = 3,
	rocblas_status_invalid_size = 4,
	rocblas_status_memory_error = 5,
	rocblas_status_internal_error = 6,
	rocblas_status_perf_degraded = 7,
	rocblas_status_size_query_mismatch = 8,
	rocblas_status_size_increased = 9,
	rocblas_status_size_unchanged = 10,
	rocblas_status_invalid_value = 11,
	rocblas_status_continue = 12,
	rocblas_status_check_numerics_fail = 13,
	rocblas_status_excluded_from_build = 14,
	rocblas_status_arch_mismatch = 15,
};
enum rocblas_pointer_mode_ {
	rocblas_pointer_mode_host = 0,
	rocblas_pointer_mode_device = 1,
};
enum rocblas_side_ {
	rocblas_side_left = 141,
	rocblas_side_right = 142,
	rocblas_side_both = 143,
};
enum rocblas_geam_ex_operation_ {
	rocblas_geam_ex_operation_min_plus = 0,
	rocblas_geam_ex_operation_plus_min = 1,
};
enum rocblas_check_numerics_mode_ {
	rocblas_check_numerics_mode_no_check = 0,
	rocblas_check_numerics_mode_info = 1,
	rocblas_check_numerics_mode_warn = 2,
	rocblas_check_numerics_mode_fail = 4,
	rocblas_check_numerics_mode_only_nan_inf = 8,
};
enum rocblas_gemm_algo_ {
	rocblas_gemm_algo_standard = 0,
	rocblas_gemm_algo_solution_index = 1,
};
enum rocblas_performance_metric_ {
	rocblas_default_performance_metric = 0,
	rocblas_device_efficiency_performance_metric = 1,
	rocblas_cu_efficiency_performance_metric = 2,
};
enum rocblas_math_mode_ {
	rocblas_default_math = 0,
	rocblas_xf32_xdl_math_op = 1,
};
enum rocblas_operation_ {
	rocblas_operation_none = 111,
	rocblas_operation_transpose = 112,
	rocblas_operation_conjugate_transpose = 113,
};
enum rocblas_datatype_ {
	rocblas_datatype_f16_r = 150,
	rocblas_datatype_f32_r = 151,
	rocblas_datatype_f64_r = 152,
	rocblas_datatype_f16_c = 153,
	rocblas_datatype_f32_c = 154,
	rocblas_datatype_f64_c = 155,
	rocblas_datatype_i8_r = 160,
	rocblas_datatype_u8_r = 161,
	rocblas_datatype_i32_r = 162,
	rocblas_datatype_u32_r = 163,
	rocblas_datatype_i8_c = 164,
	rocblas_datatype_u8_c = 165,
	rocblas_datatype_i32_c = 166,
	rocblas_datatype_u32_c = 167,
	rocblas_datatype_bf16_r = 168,
	rocblas_datatype_bf16_c = 169,
	rocblas_datatype_invalid = 255,
};
enum rocblas_diagonal_ {
	rocblas_diagonal_non_unit = 131,
	rocblas_diagonal_unit = 132,
};
enum rocblas_gemm_flags_ {
	rocblas_gemm_flags_none = 0,
	rocblas_gemm_flags_use_cu_efficiency = 2,
	rocblas_gemm_flags_fp16_alt_impl = 4,
	rocblas_gemm_flags_check_solution_index = 8,
	rocblas_gemm_flags_fp16_alt_impl_rnz = 16,
	rocblas_gemm_flags_stochastic_rounding = 32,
};

/* ============================================================================ *
 * Structure Types
 * ============================================================================ */

typedef struct rocblas_double_complex rocblas_double_complex;
typedef struct rocblas_half rocblas_half;
typedef struct rocblas_bfloat16 rocblas_bfloat16;
typedef struct rocblas_float_complex rocblas_float_complex;
typedef union rocblas_union_u rocblas_union_t;

/* ============================================================================ *
 * Opaque Types
 * ============================================================================ */

typedef struct rocblas_device_malloc_base *rocblas_device_malloc_base;
typedef struct _rocblas_handle *rocblas_handle;

/* ============================================================================ *
 * Basic Types
 * ============================================================================ */

typedef float rocblas_float;
typedef int32_t rocblas_int;
typedef int64_t rocblas_stride;
typedef double rocblas_double;

/* ============================================================================ *
 * Structure Definitions
 * ============================================================================ */

struct ihipEvent_t;

struct rocblas_double_complex {
    double x;
    double y;
};

struct rocblas_device_malloc_base;

struct rocblas_float_complex {
    float x;
    float y;
};

struct rocblas_half {
    uint16_t data;
};

struct ihipStream_t;

struct rocblas_bfloat16 {
    uint16_t data;
};

struct _rocblas_handle;

union rocblas_union_u {
    rocblas_half h;
    float s;
    double d;
    int32_t i;
    rocblas_float_complex c;
    rocblas_double_complex z;
};


#endif /* ROCBLAS_MINIMAL_ABI_H_ */
