#ifndef HSA_MINIMAL_ABI_H_
#define HSA_MINIMAL_ABI_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* ============================================================================ *
 * Minimal ABI Header for HSA
 * Auto-generated from CSV type definitions
 * ============================================================================ */

/* ============================================================================ *
 * Enum Types
 * ============================================================================ */

typedef enum hsa_symbol_linkage_t hsa_symbol_linkage_t;
typedef enum hsa_amd_queue_create_flag_t hsa_amd_queue_create_flag_t;
typedef enum hsa_variable_segment_t hsa_variable_segment_t;
typedef enum hsa_amd_event_type_s hsa_amd_event_type_t;
typedef enum hsa_code_symbol_info_t hsa_code_symbol_info_t;
typedef enum hsa_amd_link_info_type_t hsa_amd_link_info_type_t;
typedef enum hsa_exception_policy_t hsa_exception_policy_t;
typedef enum hsa_amd_copy_direction_t hsa_amd_copy_direction_t;
typedef enum hsa_status_t hsa_status_t;
typedef enum hsa_machine_model_t hsa_machine_model_t;
typedef enum hsa_flush_mode_t hsa_flush_mode_t;
typedef enum hsa_amd_vmem_address_reserve_flag_s hsa_amd_vmem_address_reserve_flag_t;
typedef enum hsa_region_segment_t hsa_region_segment_t;
typedef enum hsa_amd_region_info_s hsa_amd_region_info_t;
typedef enum hsa_agent_info_t hsa_agent_info_t;
typedef enum hsa_isa_info_t hsa_isa_info_t;
typedef enum hsa_amd_svm_attribute_s hsa_amd_svm_attribute_t;
typedef enum hsa_ven_amd_pcs_method_kind_t hsa_ven_amd_pcs_method_kind_t;
typedef enum hsa_fp_type_t hsa_fp_type_t;
typedef enum hsa_endianness_t hsa_endianness_t;
typedef enum hsa_ext_sampler_addressing_mode_t hsa_ext_sampler_addressing_mode_t;
typedef enum hsa_amd_memory_error_reason_t hsa_amd_memory_error_reason_t;
typedef enum hsa_ven_amd_pcs_units_t hsa_ven_amd_pcs_units_t;
typedef enum hsa_amd_packet_type_t hsa_amd_packet_type_t;
typedef enum hsa_executable_state_t hsa_executable_state_t;
typedef enum hsa_amd_memory_pool_location_s hsa_amd_memory_pool_location_t;
typedef enum hsa_signal_condition_t hsa_signal_condition_t;
typedef enum hsa_amd_memory_pool_global_flag_s hsa_amd_memory_pool_global_flag_t;
typedef enum hsa_ext_image_channel_order_t hsa_ext_image_channel_order_t;
typedef enum hsa_extension_t hsa_extension_t;
typedef enum hsa_amd_agent_memory_properties_s hsa_amd_agent_memory_properties_t;
typedef enum hsa_amd_hw_exception_reset_cause_t hsa_amd_hw_exception_reset_cause_t;
typedef enum hsa_executable_symbol_info_t hsa_executable_symbol_info_t;
typedef enum hsa_region_info_t hsa_region_info_t;
typedef enum hsa_amd_signal_attribute_t hsa_amd_signal_attribute_t;
typedef enum hsa_amd_segment_t hsa_amd_segment_t;
typedef enum hsa_ext_sampler_filter_mode_t hsa_ext_sampler_filter_mode_t;
typedef enum hsa_amd_svm_model_s hsa_amd_svm_model_t;
typedef enum hsa_code_object_type_t hsa_code_object_type_t;
typedef enum hsa_amd_agent_memory_pool_info_t hsa_amd_agent_memory_pool_info_t;
typedef enum hsa_amd_aie_ert_state hsa_amd_aie_ert_state;
typedef enum hsa_system_info_t hsa_system_info_t;
typedef enum hsa_amd_sdma_engine_id hsa_amd_sdma_engine_id_t;
typedef enum hsa_executable_info_t hsa_executable_info_t;
typedef enum hsa_ext_image_channel_type_t hsa_ext_image_channel_type_t;
typedef enum hsa_amd_agent_info_s hsa_amd_agent_info_t;
typedef enum hsa_amd_pointer_type_t hsa_amd_pointer_type_t;
typedef enum hsa_ext_image_data_layout_t hsa_ext_image_data_layout_t;
typedef enum hsa_amd_aie_ert_cmd_opcode_t hsa_amd_aie_ert_cmd_opcode_t;
typedef enum hsa_wavefront_info_t hsa_wavefront_info_t;
typedef enum hsa_round_method_t hsa_round_method_t;
typedef enum hsa_amd_memory_pool_access_t hsa_amd_memory_pool_access_t;
typedef enum hsa_agent_feature_t hsa_agent_feature_t;
typedef enum hsa_ven_amd_pcs_configuration_flags_t hsa_ven_amd_pcs_configuration_flags_t;
typedef enum hsa_packet_header_t hsa_packet_header_t;
typedef enum hsa_variable_allocation_t hsa_variable_allocation_t;
typedef enum hsa_ext_image_geometry_t hsa_ext_image_geometry_t;
typedef enum hsa_packet_header_width_t hsa_packet_header_width_t;
typedef enum hsa_queue_type_t hsa_queue_type_t;
typedef enum hsa_wait_state_t hsa_wait_state_t;
typedef enum hsa_region_global_flag_t hsa_region_global_flag_t;
typedef enum hsa_symbol_kind_t hsa_symbol_kind_t;
typedef enum hsa_amd_memory_type_t hsa_amd_memory_type_t;
typedef enum hsa_amd_iommu_version_t hsa_amd_iommu_version_t;
typedef enum hsa_amd_memory_pool_flag_s hsa_amd_memory_pool_flag_t;
typedef enum hsa_queue_info_attribute_t hsa_queue_info_attribute_t;
typedef enum hsa_queue_feature_t hsa_queue_feature_t;
typedef enum hsa_ext_image_capability_t hsa_ext_image_capability_t;
typedef enum hsa_default_float_rounding_mode_t hsa_default_float_rounding_mode_t;
typedef enum hsa_amd_memory_fault_reason_t hsa_amd_memory_fault_reason_t;
typedef enum hsa_fence_scope_t hsa_fence_scope_t;
typedef enum hsa_code_object_info_t hsa_code_object_info_t;
typedef enum hsa_packet_type_t hsa_packet_type_t;
typedef enum hsa_ext_sampler_coordinate_mode_t hsa_ext_sampler_coordinate_mode_t;
typedef enum hsa_amd_dma_buf_mapping_type_s hsa_amd_dma_buf_mapping_type_t;
typedef enum hsa_amd_memory_pool_info_t hsa_amd_memory_pool_info_t;
typedef enum hsa_kernel_dispatch_packet_setup_width_t hsa_kernel_dispatch_packet_setup_width_t;
typedef enum hsa_cache_info_t hsa_cache_info_t;
typedef enum hsa_profile_t hsa_profile_t;
typedef enum hsa_kernel_dispatch_packet_setup_t hsa_kernel_dispatch_packet_setup_t;
typedef enum hsa_amd_log_flag_s hsa_amd_log_flag_t;
typedef enum hsa_amd_queue_priority_s hsa_amd_queue_priority_t;
typedef enum hsa_device_type_t hsa_device_type_t;
typedef enum hsa_access_permission_t hsa_access_permission_t;
typedef enum hsa_amd_coherency_type_s hsa_amd_coherency_type_t;
typedef enum hsa_amd_hw_exception_reset_type_t hsa_amd_hw_exception_reset_type_t;

/* ============================================================================ *
 * Enum Definitions
 * ============================================================================ */

enum hsa_symbol_linkage_t {
	HSA_SYMBOL_LINKAGE_MODULE = 0,
	HSA_SYMBOL_LINKAGE_PROGRAM = 1,
};
enum hsa_amd_hw_exception_reset_cause_t {
	HSA_AMD_HW_EXCEPTION_CAUSE_GPU_HANG = 1,
	HSA_AMD_HW_EXCEPTION_CAUSE_ECC = 2,
};
enum hsa_executable_symbol_info_t {
	HSA_EXECUTABLE_SYMBOL_INFO_TYPE = 0,
	HSA_EXECUTABLE_SYMBOL_INFO_NAME_LENGTH = 1,
	HSA_EXECUTABLE_SYMBOL_INFO_NAME = 2,
	HSA_EXECUTABLE_SYMBOL_INFO_MODULE_NAME_LENGTH = 3,
	HSA_EXECUTABLE_SYMBOL_INFO_MODULE_NAME = 4,
	HSA_EXECUTABLE_SYMBOL_INFO_AGENT = 20,
	HSA_EXECUTABLE_SYMBOL_INFO_VARIABLE_ADDRESS = 21,
	HSA_EXECUTABLE_SYMBOL_INFO_LINKAGE = 5,
	HSA_EXECUTABLE_SYMBOL_INFO_IS_DEFINITION = 17,
	HSA_EXECUTABLE_SYMBOL_INFO_VARIABLE_ALLOCATION = 6,
	HSA_EXECUTABLE_SYMBOL_INFO_VARIABLE_SEGMENT = 7,
	HSA_EXECUTABLE_SYMBOL_INFO_VARIABLE_ALIGNMENT = 8,
	HSA_EXECUTABLE_SYMBOL_INFO_VARIABLE_SIZE = 9,
	HSA_EXECUTABLE_SYMBOL_INFO_VARIABLE_IS_CONST = 10,
	HSA_EXECUTABLE_SYMBOL_INFO_KERNEL_OBJECT = 22,
	HSA_EXECUTABLE_SYMBOL_INFO_KERNEL_KERNARG_SEGMENT_SIZE = 11,
	HSA_EXECUTABLE_SYMBOL_INFO_KERNEL_KERNARG_SEGMENT_ALIGNMENT = 12,
	HSA_EXECUTABLE_SYMBOL_INFO_KERNEL_GROUP_SEGMENT_SIZE = 13,
	HSA_EXECUTABLE_SYMBOL_INFO_KERNEL_PRIVATE_SEGMENT_SIZE = 14,
	HSA_EXECUTABLE_SYMBOL_INFO_KERNEL_DYNAMIC_CALLSTACK = 15,
	HSA_EXECUTABLE_SYMBOL_INFO_KERNEL_CALL_CONVENTION = 18,
	HSA_EXECUTABLE_SYMBOL_INFO_INDIRECT_FUNCTION_OBJECT = 23,
	HSA_EXECUTABLE_SYMBOL_INFO_INDIRECT_FUNCTION_CALL_CONVENTION = 16,
};
enum hsa_amd_queue_create_flag_t {
	HSA_AMD_QUEUE_CREATE_SYSTEM_MEM = 0,
	HSA_AMD_QUEUE_CREATE_DEVICE_MEM_RING_BUF = 1,
	HSA_AMD_QUEUE_CREATE_DEVICE_MEM_QUEUE_DESCRIPTOR = 2,
};
enum hsa_amd_dma_buf_mapping_type_s {
	HSA_AMD_DMABUF_MAPPING_TYPE_NONE = 0,
	HSA_AMD_DMABUF_MAPPING_TYPE_PCIE = 1,
};
enum hsa_amd_queue_priority_s {
	HSA_AMD_QUEUE_PRIORITY_LOW = 0,
	HSA_AMD_QUEUE_PRIORITY_NORMAL = 1,
	HSA_AMD_QUEUE_PRIORITY_HIGH = 2,
};
enum hsa_region_info_t {
	HSA_REGION_INFO_SEGMENT = 0,
	HSA_REGION_INFO_GLOBAL_FLAGS = 1,
	HSA_REGION_INFO_SIZE = 2,
	HSA_REGION_INFO_ALLOC_MAX_SIZE = 4,
	HSA_REGION_INFO_ALLOC_MAX_PRIVATE_WORKGROUP_SIZE = 8,
	HSA_REGION_INFO_RUNTIME_ALLOC_ALLOWED = 5,
	HSA_REGION_INFO_RUNTIME_ALLOC_GRANULE = 6,
	HSA_REGION_INFO_RUNTIME_ALLOC_ALIGNMENT = 7,
};
enum hsa_amd_memory_fault_reason_t {
	HSA_AMD_MEMORY_FAULT_PAGE_NOT_PRESENT = 1,
	HSA_AMD_MEMORY_FAULT_READ_ONLY = 2,
	HSA_AMD_MEMORY_FAULT_NX = 4,
	HSA_AMD_MEMORY_FAULT_HOST_ONLY = 8,
	HSA_AMD_MEMORY_FAULT_DRAMECC = 16,
	HSA_AMD_MEMORY_FAULT_IMPRECISE = 32,
	HSA_AMD_MEMORY_FAULT_SRAMECC = 64,
	HSA_AMD_MEMORY_FAULT_HANG = 2147483648,
};
enum hsa_amd_signal_attribute_t {
	HSA_AMD_SIGNAL_AMD_GPU_ONLY = 1,
	HSA_AMD_SIGNAL_IPC = 2,
};
enum hsa_amd_coherency_type_s {
	HSA_AMD_COHERENCY_TYPE_COHERENT = 0,
	HSA_AMD_COHERENCY_TYPE_NONCOHERENT = 1,
};
enum hsa_amd_segment_t {
	HSA_AMD_SEGMENT_GLOBAL = 0,
	HSA_AMD_SEGMENT_READONLY = 1,
	HSA_AMD_SEGMENT_PRIVATE = 2,
	HSA_AMD_SEGMENT_GROUP = 3,
};
enum hsa_ext_sampler_filter_mode_t {
	HSA_EXT_SAMPLER_FILTER_MODE_NEAREST = 0,
	HSA_EXT_SAMPLER_FILTER_MODE_LINEAR = 1,
};
enum hsa_amd_link_info_type_t {
	HSA_AMD_LINK_INFO_TYPE_HYPERTRANSPORT = 0,
	HSA_AMD_LINK_INFO_TYPE_QPI = 1,
	HSA_AMD_LINK_INFO_TYPE_PCIE = 2,
	HSA_AMD_LINK_INFO_TYPE_INFINBAND = 3,
	HSA_AMD_LINK_INFO_TYPE_XGMI = 4,
};
enum hsa_exception_policy_t {
	HSA_EXCEPTION_POLICY_BREAK = 1,
	HSA_EXCEPTION_POLICY_DETECT = 2,
};
enum hsa_code_object_type_t {
	HSA_CODE_OBJECT_TYPE_PROGRAM = 0,
};
enum hsa_amd_copy_direction_t {
	hsaHostToHost = 0,
	hsaHostToDevice = 1,
	hsaDeviceToHost = 2,
	hsaDeviceToDevice = 3,
};
enum hsa_machine_model_t {
	HSA_MACHINE_MODEL_SMALL = 0,
	HSA_MACHINE_MODEL_LARGE = 1,
};
enum hsa_amd_aie_ert_state {
	HSA_AMD_AIE_ERT_STATE_NEW = 1,
	HSA_AMD_AIE_ERT_STATE_QUEUED = 2,
	HSA_AMD_AIE_ERT_STATE_RUNNING = 3,
	HSA_AMD_AIE_ERT_STATE_COMPLETED = 4,
	HSA_AMD_AIE_ERT_STATE_ERROR = 5,
	HSA_AMD_AIE_ERT_STATE_ABORT = 6,
	HSA_AMD_AIE_ERT_STATE_SUBMITTED = 7,
	HSA_AMD_AIE_ERT_STATE_TIMEOUT = 8,
	HSA_AMD_AIE_ERT_STATE_NORESPONSE = 9,
	HSA_AMD_AIE_ERT_STATE_SKERROR = 10,
	HSA_AMD_AIE_ERT_STATE_SKCRASHED = 11,
	HSA_AMD_AIE_ERT_STATE_MAX = 12,
};
enum hsa_system_info_t {
	HSA_SYSTEM_INFO_VERSION_MAJOR = 0,
	HSA_SYSTEM_INFO_VERSION_MINOR = 1,
	HSA_SYSTEM_INFO_TIMESTAMP = 2,
	HSA_SYSTEM_INFO_TIMESTAMP_FREQUENCY = 3,
	HSA_SYSTEM_INFO_SIGNAL_MAX_WAIT = 4,
	HSA_SYSTEM_INFO_ENDIANNESS = 5,
	HSA_SYSTEM_INFO_MACHINE_MODEL = 6,
	HSA_SYSTEM_INFO_EXTENSIONS = 7,
	HSA_AMD_SYSTEM_INFO_BUILD_VERSION = 512,
	HSA_AMD_SYSTEM_INFO_SVM_SUPPORTED = 513,
	HSA_AMD_SYSTEM_INFO_SVM_ACCESSIBLE_BY_DEFAULT = 514,
	HSA_AMD_SYSTEM_INFO_MWAITX_ENABLED = 515,
	HSA_AMD_SYSTEM_INFO_DMABUF_SUPPORTED = 516,
	HSA_AMD_SYSTEM_INFO_VIRTUAL_MEM_API_SUPPORTED = 517,
	HSA_AMD_SYSTEM_INFO_XNACK_ENABLED = 518,
	HSA_AMD_SYSTEM_INFO_EXT_VERSION_MAJOR = 519,
	HSA_AMD_SYSTEM_INFO_EXT_VERSION_MINOR = 520,
};
enum hsa_region_segment_t {
	HSA_REGION_SEGMENT_GLOBAL = 0,
	HSA_REGION_SEGMENT_READONLY = 1,
	HSA_REGION_SEGMENT_PRIVATE = 2,
	HSA_REGION_SEGMENT_GROUP = 3,
	HSA_REGION_SEGMENT_KERNARG = 4,
};
enum hsa_kernel_dispatch_packet_setup_width_t {
	HSA_KERNEL_DISPATCH_PACKET_SETUP_WIDTH_DIMENSIONS = 2,
};
enum hsa_executable_info_t {
	HSA_EXECUTABLE_INFO_PROFILE = 1,
	HSA_EXECUTABLE_INFO_STATE = 2,
	HSA_EXECUTABLE_INFO_DEFAULT_FLOAT_ROUNDING_MODE = 3,
};
enum hsa_variable_allocation_t {
	HSA_VARIABLE_ALLOCATION_AGENT = 0,
	HSA_VARIABLE_ALLOCATION_PROGRAM = 1,
};
enum hsa_agent_info_t {
	HSA_AGENT_INFO_NAME = 0,
	HSA_AGENT_INFO_VENDOR_NAME = 1,
	HSA_AGENT_INFO_FEATURE = 2,
	HSA_AGENT_INFO_MACHINE_MODEL = 3,
	HSA_AGENT_INFO_PROFILE = 4,
	HSA_AGENT_INFO_DEFAULT_FLOAT_ROUNDING_MODE = 5,
	HSA_AGENT_INFO_BASE_PROFILE_DEFAULT_FLOAT_ROUNDING_MODES = 23,
	HSA_AGENT_INFO_FAST_F16_OPERATION = 24,
	HSA_AGENT_INFO_WAVEFRONT_SIZE = 6,
	HSA_AGENT_INFO_WORKGROUP_MAX_DIM = 7,
	HSA_AGENT_INFO_WORKGROUP_MAX_SIZE = 8,
	HSA_AGENT_INFO_GRID_MAX_DIM = 9,
	HSA_AGENT_INFO_GRID_MAX_SIZE = 10,
	HSA_AGENT_INFO_FBARRIER_MAX_SIZE = 11,
	HSA_AGENT_INFO_QUEUES_MAX = 12,
	HSA_AGENT_INFO_QUEUE_MIN_SIZE = 13,
	HSA_AGENT_INFO_QUEUE_MAX_SIZE = 14,
	HSA_AGENT_INFO_QUEUE_TYPE = 15,
	HSA_AGENT_INFO_NODE = 16,
	HSA_AGENT_INFO_DEVICE = 17,
	HSA_AGENT_INFO_CACHE_SIZE = 18,
	HSA_AGENT_INFO_ISA = 19,
	HSA_AGENT_INFO_EXTENSIONS = 20,
	HSA_AGENT_INFO_VERSION_MAJOR = 21,
	HSA_AGENT_INFO_VERSION_MINOR = 22,
	HSA_AGENT_INFO_LAST = 2147483647,
};
enum hsa_ext_image_channel_type_t {
	HSA_EXT_IMAGE_CHANNEL_TYPE_SNORM_INT8 = 0,
	HSA_EXT_IMAGE_CHANNEL_TYPE_SNORM_INT16 = 1,
	HSA_EXT_IMAGE_CHANNEL_TYPE_UNORM_INT8 = 2,
	HSA_EXT_IMAGE_CHANNEL_TYPE_UNORM_INT16 = 3,
	HSA_EXT_IMAGE_CHANNEL_TYPE_UNORM_INT24 = 4,
	HSA_EXT_IMAGE_CHANNEL_TYPE_UNORM_SHORT_555 = 5,
	HSA_EXT_IMAGE_CHANNEL_TYPE_UNORM_SHORT_565 = 6,
	HSA_EXT_IMAGE_CHANNEL_TYPE_UNORM_SHORT_101010 = 7,
	HSA_EXT_IMAGE_CHANNEL_TYPE_SIGNED_INT8 = 8,
	HSA_EXT_IMAGE_CHANNEL_TYPE_SIGNED_INT16 = 9,
	HSA_EXT_IMAGE_CHANNEL_TYPE_SIGNED_INT32 = 10,
	HSA_EXT_IMAGE_CHANNEL_TYPE_UNSIGNED_INT8 = 11,
	HSA_EXT_IMAGE_CHANNEL_TYPE_UNSIGNED_INT16 = 12,
	HSA_EXT_IMAGE_CHANNEL_TYPE_UNSIGNED_INT32 = 13,
	HSA_EXT_IMAGE_CHANNEL_TYPE_HALF_FLOAT = 14,
	HSA_EXT_IMAGE_CHANNEL_TYPE_FLOAT = 15,
};
enum hsa_amd_svm_model_s {
	HSA_AMD_SVM_GLOBAL_FLAG_FINE_GRAINED = 0,
	HSA_AMD_SVM_GLOBAL_FLAG_COARSE_GRAINED = 1,
	HSA_AMD_SVM_GLOBAL_FLAG_INDETERMINATE = 2,
};
enum hsa_ext_image_data_layout_t {
	HSA_EXT_IMAGE_DATA_LAYOUT_OPAQUE = 0,
	HSA_EXT_IMAGE_DATA_LAYOUT_LINEAR = 1,
};
enum hsa_isa_info_t {
	HSA_ISA_INFO_NAME_LENGTH = 0,
	HSA_ISA_INFO_NAME = 1,
	HSA_ISA_INFO_CALL_CONVENTION_COUNT = 2,
	HSA_ISA_INFO_CALL_CONVENTION_INFO_WAVEFRONT_SIZE = 3,
	HSA_ISA_INFO_CALL_CONVENTION_INFO_WAVEFRONTS_PER_COMPUTE_UNIT = 4,
	HSA_ISA_INFO_MACHINE_MODELS = 5,
	HSA_ISA_INFO_PROFILES = 6,
	HSA_ISA_INFO_DEFAULT_FLOAT_ROUNDING_MODES = 7,
	HSA_ISA_INFO_BASE_PROFILE_DEFAULT_FLOAT_ROUNDING_MODES = 8,
	HSA_ISA_INFO_FAST_F16_OPERATION = 9,
	HSA_ISA_INFO_WORKGROUP_MAX_DIM = 12,
	HSA_ISA_INFO_WORKGROUP_MAX_SIZE = 13,
	HSA_ISA_INFO_GRID_MAX_DIM = 14,
	HSA_ISA_INFO_GRID_MAX_SIZE = 16,
	HSA_ISA_INFO_FBARRIER_MAX_SIZE = 17,
};
enum hsa_amd_agent_memory_properties_s {
	HSA_AMD_MEMORY_PROPERTY_AGENT_IS_APU = 1,
};
enum hsa_access_permission_t {
	HSA_ACCESS_PERMISSION_NONE = 0,
	HSA_ACCESS_PERMISSION_RO = 1,
	HSA_ACCESS_PERMISSION_WO = 2,
	HSA_ACCESS_PERMISSION_RW = 3,
};
enum hsa_wavefront_info_t {
	HSA_WAVEFRONT_INFO_SIZE = 0,
};
enum hsa_wait_state_t {
	HSA_WAIT_STATE_BLOCKED = 0,
	HSA_WAIT_STATE_ACTIVE = 1,
};
enum hsa_queue_type_t {
	HSA_QUEUE_TYPE_MULTI = 0,
	HSA_QUEUE_TYPE_SINGLE = 1,
	HSA_QUEUE_TYPE_COOPERATIVE = 2,
};
enum hsa_variable_segment_t {
	HSA_VARIABLE_SEGMENT_GLOBAL = 0,
	HSA_VARIABLE_SEGMENT_READONLY = 1,
};
enum hsa_amd_memory_pool_access_t {
	HSA_AMD_MEMORY_POOL_ACCESS_NEVER_ALLOWED = 0,
	HSA_AMD_MEMORY_POOL_ACCESS_ALLOWED_BY_DEFAULT = 1,
	HSA_AMD_MEMORY_POOL_ACCESS_DISALLOWED_BY_DEFAULT = 2,
};
enum hsa_ven_amd_pcs_configuration_flags_t {
	HSA_VEN_AMD_PCS_CONFIGURATION_FLAGS_INTERVAL_POWER_OF_2 = 1,
};
enum hsa_agent_feature_t {
	HSA_AGENT_FEATURE_KERNEL_DISPATCH = 1,
	HSA_AGENT_FEATURE_AGENT_DISPATCH = 2,
};
enum hsa_amd_log_flag_s {
	HSA_AMD_LOG_FLAG_BLIT_KERNEL_PKTS = 0,
	HSA_AMD_LOG_FLAG_AQL = 0,
	HSA_AMD_LOG_FLAG_SDMA = 1,
	HSA_AMD_LOG_FLAG_INFO = 2,
};
enum hsa_packet_header_t {
	HSA_PACKET_HEADER_TYPE = 0,
	HSA_PACKET_HEADER_BARRIER = 8,
	HSA_PACKET_HEADER_SCACQUIRE_FENCE_SCOPE = 9,
	HSA_PACKET_HEADER_ACQUIRE_FENCE_SCOPE = 9,
	HSA_PACKET_HEADER_SCRELEASE_FENCE_SCOPE = 11,
	HSA_PACKET_HEADER_RELEASE_FENCE_SCOPE = 11,
};
enum hsa_ven_amd_pcs_method_kind_t {
	HSA_VEN_AMD_PCS_METHOD_HOSTTRAP_V1 = 0,
	HSA_VEN_AMD_PCS_METHOD_STOCHASTIC_V1 = 1,
};
enum hsa_queue_info_attribute_t {
	HSA_AMD_QUEUE_INFO_AGENT = 0,
	HSA_AMD_QUEUE_INFO_DOORBELL_ID = 1,
};
enum hsa_ext_image_geometry_t {
	HSA_EXT_IMAGE_GEOMETRY_1D = 0,
	HSA_EXT_IMAGE_GEOMETRY_2D = 1,
	HSA_EXT_IMAGE_GEOMETRY_3D = 2,
	HSA_EXT_IMAGE_GEOMETRY_1DA = 3,
	HSA_EXT_IMAGE_GEOMETRY_2DA = 4,
	HSA_EXT_IMAGE_GEOMETRY_1DB = 5,
	HSA_EXT_IMAGE_GEOMETRY_2DDEPTH = 6,
	HSA_EXT_IMAGE_GEOMETRY_2DADEPTH = 7,
};
enum hsa_endianness_t {
	HSA_ENDIANNESS_LITTLE = 0,
	HSA_ENDIANNESS_BIG = 1,
};
enum hsa_status_t {
	HSA_STATUS_SUCCESS = 0,
	HSA_STATUS_INFO_BREAK = 1,
	HSA_STATUS_ERROR = 4096,
	HSA_STATUS_ERROR_INVALID_ARGUMENT = 4097,
	HSA_STATUS_ERROR_INVALID_QUEUE_CREATION = 4098,
	HSA_STATUS_ERROR_INVALID_ALLOCATION = 4099,
	HSA_STATUS_ERROR_INVALID_AGENT = 4100,
	HSA_STATUS_ERROR_INVALID_REGION = 4101,
	HSA_STATUS_ERROR_INVALID_SIGNAL = 4102,
	HSA_STATUS_ERROR_INVALID_QUEUE = 4103,
	HSA_STATUS_ERROR_OUT_OF_RESOURCES = 4104,
	HSA_STATUS_ERROR_INVALID_PACKET_FORMAT = 4105,
	HSA_STATUS_ERROR_RESOURCE_FREE = 4106,
	HSA_STATUS_ERROR_NOT_INITIALIZED = 4107,
	HSA_STATUS_ERROR_REFCOUNT_OVERFLOW = 4108,
	HSA_STATUS_ERROR_INCOMPATIBLE_ARGUMENTS = 4109,
	HSA_STATUS_ERROR_INVALID_INDEX = 4110,
	HSA_STATUS_ERROR_INVALID_ISA = 4111,
	HSA_STATUS_ERROR_INVALID_ISA_NAME = 4119,
	HSA_STATUS_ERROR_INVALID_CODE_OBJECT = 4112,
	HSA_STATUS_ERROR_INVALID_EXECUTABLE = 4113,
	HSA_STATUS_ERROR_FROZEN_EXECUTABLE = 4114,
	HSA_STATUS_ERROR_INVALID_SYMBOL_NAME = 4115,
	HSA_STATUS_ERROR_VARIABLE_ALREADY_DEFINED = 4116,
	HSA_STATUS_ERROR_VARIABLE_UNDEFINED = 4117,
	HSA_STATUS_ERROR_EXCEPTION = 4118,
	HSA_STATUS_ERROR_INVALID_CODE_SYMBOL = 4120,
	HSA_STATUS_ERROR_INVALID_EXECUTABLE_SYMBOL = 4121,
	HSA_STATUS_ERROR_INVALID_FILE = 4128,
	HSA_STATUS_ERROR_INVALID_CODE_OBJECT_READER = 4129,
	HSA_STATUS_ERROR_INVALID_CACHE = 4130,
	HSA_STATUS_ERROR_INVALID_WAVEFRONT = 4131,
	HSA_STATUS_ERROR_INVALID_SIGNAL_GROUP = 4132,
	HSA_STATUS_ERROR_INVALID_RUNTIME_STATE = 4133,
	HSA_STATUS_ERROR_FATAL = 4134,
};
enum hsa_signal_condition_t {
	HSA_SIGNAL_CONDITION_EQ = 0,
	HSA_SIGNAL_CONDITION_NE = 1,
	HSA_SIGNAL_CONDITION_LT = 2,
	HSA_SIGNAL_CONDITION_GTE = 3,
};
enum hsa_round_method_t {
	HSA_ROUND_METHOD_SINGLE = 1,
	HSA_ROUND_METHOD_DOUBLE = 2,
};
enum hsa_amd_memory_pool_flag_s {
	HSA_AMD_MEMORY_POOL_STANDARD_FLAG = 0,
	HSA_AMD_MEMORY_POOL_PCIE_FLAG = 1,
	HSA_AMD_MEMORY_POOL_CONTIGUOUS_FLAG = 2,
	HSA_AMD_MEMORY_POOL_EXECUTABLE_FLAG = 4,
	HSA_AMD_MEMORY_POOL_UNCACHED_FLAG = 8,
};
enum hsa_amd_hw_exception_reset_type_t {
	HSA_AMD_HW_EXCEPTION_RESET_TYPE_OTHER = 1,
};
enum hsa_ext_sampler_addressing_mode_t {
	HSA_EXT_SAMPLER_ADDRESSING_MODE_UNDEFINED = 0,
	HSA_EXT_SAMPLER_ADDRESSING_MODE_CLAMP_TO_EDGE = 1,
	HSA_EXT_SAMPLER_ADDRESSING_MODE_CLAMP_TO_BORDER = 2,
	HSA_EXT_SAMPLER_ADDRESSING_MODE_REPEAT = 3,
	HSA_EXT_SAMPLER_ADDRESSING_MODE_MIRRORED_REPEAT = 4,
};
enum hsa_amd_memory_error_reason_t {
	HSA_AMD_MEMORY_ERROR_MEMORY_IN_USE = 1,
};
enum hsa_ven_amd_pcs_units_t {
	HSA_VEN_AMD_PCS_INTERVAL_UNITS_MICRO_SECONDS = 0,
	HSA_VEN_AMD_PCS_INTERVAL_UNITS_CLOCK_CYCLES = 1,
	HSA_VEN_AMD_PCS_INTERVAL_UNITS_INSTRUCTIONS = 2,
};
enum hsa_symbol_kind_t {
	HSA_SYMBOL_KIND_VARIABLE = 0,
	HSA_SYMBOL_KIND_KERNEL = 1,
	HSA_SYMBOL_KIND_INDIRECT_FUNCTION = 2,
};
enum hsa_code_symbol_info_t {
	HSA_CODE_SYMBOL_INFO_TYPE = 0,
	HSA_CODE_SYMBOL_INFO_NAME_LENGTH = 1,
	HSA_CODE_SYMBOL_INFO_NAME = 2,
	HSA_CODE_SYMBOL_INFO_MODULE_NAME_LENGTH = 3,
	HSA_CODE_SYMBOL_INFO_MODULE_NAME = 4,
	HSA_CODE_SYMBOL_INFO_LINKAGE = 5,
	HSA_CODE_SYMBOL_INFO_IS_DEFINITION = 17,
	HSA_CODE_SYMBOL_INFO_VARIABLE_ALLOCATION = 6,
	HSA_CODE_SYMBOL_INFO_VARIABLE_SEGMENT = 7,
	HSA_CODE_SYMBOL_INFO_VARIABLE_ALIGNMENT = 8,
	HSA_CODE_SYMBOL_INFO_VARIABLE_SIZE = 9,
	HSA_CODE_SYMBOL_INFO_VARIABLE_IS_CONST = 10,
	HSA_CODE_SYMBOL_INFO_KERNEL_KERNARG_SEGMENT_SIZE = 11,
	HSA_CODE_SYMBOL_INFO_KERNEL_KERNARG_SEGMENT_ALIGNMENT = 12,
	HSA_CODE_SYMBOL_INFO_KERNEL_GROUP_SEGMENT_SIZE = 13,
	HSA_CODE_SYMBOL_INFO_KERNEL_PRIVATE_SEGMENT_SIZE = 14,
	HSA_CODE_SYMBOL_INFO_KERNEL_DYNAMIC_CALLSTACK = 15,
	HSA_CODE_SYMBOL_INFO_KERNEL_CALL_CONVENTION = 18,
	HSA_CODE_SYMBOL_INFO_INDIRECT_FUNCTION_CALL_CONVENTION = 16,
	HSA_CODE_SYMBOL_INFO_KERNEL_WAVEFRONT_SIZE = 19,
};
enum hsa_amd_memory_type_t {
	MEMORY_TYPE_NONE = 0,
	MEMORY_TYPE_PINNED = 1,
};
enum hsa_amd_packet_type_t {
	HSA_AMD_PACKET_TYPE_BARRIER_VALUE = 2,
	HSA_AMD_PACKET_TYPE_AIE_ERT = 3,
};
enum hsa_executable_state_t {
	HSA_EXECUTABLE_STATE_UNFROZEN = 0,
	HSA_EXECUTABLE_STATE_FROZEN = 1,
};
enum hsa_region_global_flag_t {
	HSA_REGION_GLOBAL_FLAG_KERNARG = 1,
	HSA_REGION_GLOBAL_FLAG_FINE_GRAINED = 2,
	HSA_REGION_GLOBAL_FLAG_COARSE_GRAINED = 4,
	HSA_REGION_GLOBAL_FLAG_EXTENDED_SCOPE_FINE_GRAINED = 8,
};
enum hsa_amd_iommu_version_t {
	HSA_IOMMU_SUPPORT_NONE = 0,
	HSA_IOMMU_SUPPORT_V2 = 1,
};
enum hsa_packet_header_width_t {
	HSA_PACKET_HEADER_WIDTH_TYPE = 8,
	HSA_PACKET_HEADER_WIDTH_BARRIER = 1,
	HSA_PACKET_HEADER_WIDTH_SCACQUIRE_FENCE_SCOPE = 2,
	HSA_PACKET_HEADER_WIDTH_ACQUIRE_FENCE_SCOPE = 2,
	HSA_PACKET_HEADER_WIDTH_SCRELEASE_FENCE_SCOPE = 2,
	HSA_PACKET_HEADER_WIDTH_RELEASE_FENCE_SCOPE = 2,
};
enum hsa_ext_image_capability_t {
	HSA_EXT_IMAGE_CAPABILITY_NOT_SUPPORTED = 0,
	HSA_EXT_IMAGE_CAPABILITY_READ_ONLY = 1,
	HSA_EXT_IMAGE_CAPABILITY_WRITE_ONLY = 2,
	HSA_EXT_IMAGE_CAPABILITY_READ_WRITE = 4,
	HSA_EXT_IMAGE_CAPABILITY_READ_MODIFY_WRITE = 8,
	HSA_EXT_IMAGE_CAPABILITY_ACCESS_INVARIANT_DATA_LAYOUT = 16,
};
enum hsa_amd_svm_attribute_s {
	HSA_AMD_SVM_ATTRIB_GLOBAL_FLAG = 0,
	HSA_AMD_SVM_ATTRIB_READ_ONLY = 1,
	HSA_AMD_SVM_ATTRIB_HIVE_LOCAL = 2,
	HSA_AMD_SVM_ATTRIB_MIGRATION_GRANULARITY = 3,
	HSA_AMD_SVM_ATTRIB_PREFERRED_LOCATION = 4,
	HSA_AMD_SVM_ATTRIB_PREFETCH_LOCATION = 5,
	HSA_AMD_SVM_ATTRIB_READ_MOSTLY = 6,
	HSA_AMD_SVM_ATTRIB_GPU_EXEC = 7,
	HSA_AMD_SVM_ATTRIB_AGENT_ACCESSIBLE = 512,
	HSA_AMD_SVM_ATTRIB_AGENT_ACCESSIBLE_IN_PLACE = 513,
	HSA_AMD_SVM_ATTRIB_AGENT_NO_ACCESS = 514,
	HSA_AMD_SVM_ATTRIB_ACCESS_QUERY = 515,
};
enum hsa_default_float_rounding_mode_t {
	HSA_DEFAULT_FLOAT_ROUNDING_MODE_DEFAULT = 0,
	HSA_DEFAULT_FLOAT_ROUNDING_MODE_ZERO = 1,
	HSA_DEFAULT_FLOAT_ROUNDING_MODE_NEAR = 2,
};
enum hsa_kernel_dispatch_packet_setup_t {
	HSA_KERNEL_DISPATCH_PACKET_SETUP_DIMENSIONS = 0,
};
enum hsa_ext_sampler_coordinate_mode_t {
	HSA_EXT_SAMPLER_COORDINATE_MODE_UNNORMALIZED = 0,
	HSA_EXT_SAMPLER_COORDINATE_MODE_NORMALIZED = 1,
};
enum hsa_fence_scope_t {
	HSA_FENCE_SCOPE_NONE = 0,
	HSA_FENCE_SCOPE_AGENT = 1,
	HSA_FENCE_SCOPE_SYSTEM = 2,
};
enum hsa_code_object_info_t {
	HSA_CODE_OBJECT_INFO_VERSION = 0,
	HSA_CODE_OBJECT_INFO_TYPE = 1,
	HSA_CODE_OBJECT_INFO_ISA = 2,
	HSA_CODE_OBJECT_INFO_MACHINE_MODEL = 3,
	HSA_CODE_OBJECT_INFO_PROFILE = 4,
	HSA_CODE_OBJECT_INFO_DEFAULT_FLOAT_ROUNDING_MODE = 5,
};
enum hsa_packet_type_t {
	HSA_PACKET_TYPE_VENDOR_SPECIFIC = 0,
	HSA_PACKET_TYPE_INVALID = 1,
	HSA_PACKET_TYPE_KERNEL_DISPATCH = 2,
	HSA_PACKET_TYPE_BARRIER_AND = 3,
	HSA_PACKET_TYPE_AGENT_DISPATCH = 4,
	HSA_PACKET_TYPE_BARRIER_OR = 5,
};
enum hsa_fp_type_t {
	HSA_FP_TYPE_16 = 1,
	HSA_FP_TYPE_32 = 2,
	HSA_FP_TYPE_64 = 4,
};
enum hsa_amd_sdma_engine_id {
	HSA_AMD_SDMA_ENGINE_0 = 1,
	HSA_AMD_SDMA_ENGINE_1 = 2,
	HSA_AMD_SDMA_ENGINE_2 = 4,
	HSA_AMD_SDMA_ENGINE_3 = 8,
	HSA_AMD_SDMA_ENGINE_4 = 16,
	HSA_AMD_SDMA_ENGINE_5 = 32,
	HSA_AMD_SDMA_ENGINE_6 = 64,
	HSA_AMD_SDMA_ENGINE_7 = 128,
	HSA_AMD_SDMA_ENGINE_8 = 256,
	HSA_AMD_SDMA_ENGINE_9 = 512,
	HSA_AMD_SDMA_ENGINE_10 = 1024,
	HSA_AMD_SDMA_ENGINE_11 = 2048,
	HSA_AMD_SDMA_ENGINE_12 = 4096,
	HSA_AMD_SDMA_ENGINE_13 = 8192,
	HSA_AMD_SDMA_ENGINE_14 = 16384,
	HSA_AMD_SDMA_ENGINE_15 = 32768,
};
enum hsa_flush_mode_t {
	HSA_FLUSH_MODE_FTZ = 1,
	HSA_FLUSH_MODE_NON_FTZ = 2,
};
enum hsa_queue_feature_t {
	HSA_QUEUE_FEATURE_KERNEL_DISPATCH = 1,
	HSA_QUEUE_FEATURE_AGENT_DISPATCH = 2,
};
enum hsa_amd_pointer_type_t {
	HSA_EXT_POINTER_TYPE_UNKNOWN = 0,
	HSA_EXT_POINTER_TYPE_HSA = 1,
	HSA_EXT_POINTER_TYPE_LOCKED = 2,
	HSA_EXT_POINTER_TYPE_GRAPHICS = 3,
	HSA_EXT_POINTER_TYPE_IPC = 4,
	HSA_EXT_POINTER_TYPE_RESERVED_ADDR = 5,
	HSA_EXT_POINTER_TYPE_HSA_VMEM = 6,
};
enum hsa_cache_info_t {
	HSA_CACHE_INFO_NAME_LENGTH = 0,
	HSA_CACHE_INFO_NAME = 1,
	HSA_CACHE_INFO_LEVEL = 2,
	HSA_CACHE_INFO_SIZE = 3,
};
enum hsa_profile_t {
	HSA_PROFILE_BASE = 0,
	HSA_PROFILE_FULL = 1,
};
enum hsa_amd_vmem_address_reserve_flag_s {
	HSA_AMD_VMEM_ADDRESS_NO_REGISTER = 1,
};
enum hsa_ext_image_channel_order_t {
	HSA_EXT_IMAGE_CHANNEL_ORDER_A = 0,
	HSA_EXT_IMAGE_CHANNEL_ORDER_R = 1,
	HSA_EXT_IMAGE_CHANNEL_ORDER_RX = 2,
	HSA_EXT_IMAGE_CHANNEL_ORDER_RG = 3,
	HSA_EXT_IMAGE_CHANNEL_ORDER_RGX = 4,
	HSA_EXT_IMAGE_CHANNEL_ORDER_RA = 5,
	HSA_EXT_IMAGE_CHANNEL_ORDER_RGB = 6,
	HSA_EXT_IMAGE_CHANNEL_ORDER_RGBX = 7,
	HSA_EXT_IMAGE_CHANNEL_ORDER_RGBA = 8,
	HSA_EXT_IMAGE_CHANNEL_ORDER_BGRA = 9,
	HSA_EXT_IMAGE_CHANNEL_ORDER_ARGB = 10,
	HSA_EXT_IMAGE_CHANNEL_ORDER_ABGR = 11,
	HSA_EXT_IMAGE_CHANNEL_ORDER_SRGB = 12,
	HSA_EXT_IMAGE_CHANNEL_ORDER_SRGBX = 13,
	HSA_EXT_IMAGE_CHANNEL_ORDER_SRGBA = 14,
	HSA_EXT_IMAGE_CHANNEL_ORDER_SBGRA = 15,
	HSA_EXT_IMAGE_CHANNEL_ORDER_INTENSITY = 16,
	HSA_EXT_IMAGE_CHANNEL_ORDER_LUMINANCE = 17,
	HSA_EXT_IMAGE_CHANNEL_ORDER_DEPTH = 18,
	HSA_EXT_IMAGE_CHANNEL_ORDER_DEPTH_STENCIL = 19,
};
enum hsa_device_type_t {
	HSA_DEVICE_TYPE_CPU = 0,
	HSA_DEVICE_TYPE_GPU = 1,
	HSA_DEVICE_TYPE_DSP = 2,
	HSA_DEVICE_TYPE_AIE = 3,
};
enum hsa_amd_memory_pool_global_flag_s {
	HSA_AMD_MEMORY_POOL_GLOBAL_FLAG_KERNARG_INIT = 1,
	HSA_AMD_MEMORY_POOL_GLOBAL_FLAG_FINE_GRAINED = 2,
	HSA_AMD_MEMORY_POOL_GLOBAL_FLAG_COARSE_GRAINED = 4,
	HSA_AMD_MEMORY_POOL_GLOBAL_FLAG_EXTENDED_SCOPE_FINE_GRAINED = 8,
};
enum hsa_amd_aie_ert_cmd_opcode_t {
	HSA_AMD_AIE_ERT_START_CU = 0,
	HSA_AMD_AIE_ERT_START_KERNEL = 0,
	HSA_AMD_AIE_ERT_CONFIGURE = 2,
	HSA_AMD_AIE_ERT_EXIT = 3,
	HSA_AMD_AIE_ERT_ABORT = 4,
	HSA_AMD_AIE_ERT_EXEC_WRITE = 5,
	HSA_AMD_AIE_ERT_CU_STAT = 6,
	HSA_AMD_AIE_ERT_START_COPYBO = 7,
	HSA_AMD_AIE_ERT_SK_CONFIG = 8,
	HSA_AMD_AIE_ERT_SK_START = 9,
	HSA_AMD_AIE_ERT_SK_UNCONFIG = 10,
	HSA_AMD_AIE_ERT_INIT_CU = 11,
	HSA_AMD_AIE_ERT_START_FA = 12,
	HSA_AMD_AIE_ERT_CLK_CALIB = 13,
	HSA_AMD_AIE_ERT_MB_VALIDATE = 14,
	HSA_AMD_AIE_ERT_START_KEY_VAL = 15,
	HSA_AMD_AIE_ERT_ACCESS_TEST_C = 16,
	HSA_AMD_AIE_ERT_ACCESS_TEST = 17,
	HSA_AMD_AIE_ERT_START_DPU = 18,
	HSA_AMD_AIE_ERT_CMD_CHAIN = 19,
	HSA_AMD_AIE_ERT_START_NPU = 20,
	HSA_AMD_AIE_ERT_START_NPU_PREEMPT = 21,
};
enum hsa_amd_agent_info_s {
	HSA_AMD_AGENT_INFO_CHIP_ID = 40960,
	HSA_AMD_AGENT_INFO_CACHELINE_SIZE = 40961,
	HSA_AMD_AGENT_INFO_COMPUTE_UNIT_COUNT = 40962,
	HSA_AMD_AGENT_INFO_MAX_CLOCK_FREQUENCY = 40963,
	HSA_AMD_AGENT_INFO_DRIVER_NODE_ID = 40964,
	HSA_AMD_AGENT_INFO_MAX_ADDRESS_WATCH_POINTS = 40965,
	HSA_AMD_AGENT_INFO_BDFID = 40966,
	HSA_AMD_AGENT_INFO_MEMORY_WIDTH = 40967,
	HSA_AMD_AGENT_INFO_MEMORY_MAX_FREQUENCY = 40968,
	HSA_AMD_AGENT_INFO_PRODUCT_NAME = 40969,
	HSA_AMD_AGENT_INFO_MAX_WAVES_PER_CU = 40970,
	HSA_AMD_AGENT_INFO_NUM_SIMDS_PER_CU = 40971,
	HSA_AMD_AGENT_INFO_NUM_SHADER_ENGINES = 40972,
	HSA_AMD_AGENT_INFO_NUM_SHADER_ARRAYS_PER_SE = 40973,
	HSA_AMD_AGENT_INFO_HDP_FLUSH = 40974,
	HSA_AMD_AGENT_INFO_DOMAIN = 40975,
	HSA_AMD_AGENT_INFO_COOPERATIVE_QUEUES = 40976,
	HSA_AMD_AGENT_INFO_UUID = 40977,
	HSA_AMD_AGENT_INFO_ASIC_REVISION = 40978,
	HSA_AMD_AGENT_INFO_SVM_DIRECT_HOST_ACCESS = 40979,
	HSA_AMD_AGENT_INFO_COOPERATIVE_COMPUTE_UNIT_COUNT = 40980,
	HSA_AMD_AGENT_INFO_MEMORY_AVAIL = 40981,
	HSA_AMD_AGENT_INFO_TIMESTAMP_FREQUENCY = 40982,
	HSA_AMD_AGENT_INFO_ASIC_FAMILY_ID = 41223,
	HSA_AMD_AGENT_INFO_UCODE_VERSION = 41224,
	HSA_AMD_AGENT_INFO_SDMA_UCODE_VERSION = 41225,
	HSA_AMD_AGENT_INFO_NUM_SDMA_ENG = 41226,
	HSA_AMD_AGENT_INFO_NUM_SDMA_XGMI_ENG = 41227,
	HSA_AMD_AGENT_INFO_IOMMU_SUPPORT = 41232,
	HSA_AMD_AGENT_INFO_NUM_XCC = 41233,
	HSA_AMD_AGENT_INFO_DRIVER_UID = 41234,
	HSA_AMD_AGENT_INFO_NEAREST_CPU = 41235,
	HSA_AMD_AGENT_INFO_MEMORY_PROPERTIES = 41236,
	HSA_AMD_AGENT_INFO_AQL_EXTENSIONS = 41237,
	HSA_AMD_AGENT_INFO_SCRATCH_LIMIT_MAX = 41238,
	HSA_AMD_AGENT_INFO_SCRATCH_LIMIT_CURRENT = 41239,
	HSA_AMD_AGENT_INFO_CLOCK_COUNTERS = 41240,
};
enum hsa_amd_memory_pool_info_t {
	HSA_AMD_MEMORY_POOL_INFO_SEGMENT = 0,
	HSA_AMD_MEMORY_POOL_INFO_GLOBAL_FLAGS = 1,
	HSA_AMD_MEMORY_POOL_INFO_SIZE = 2,
	HSA_AMD_MEMORY_POOL_INFO_RUNTIME_ALLOC_ALLOWED = 5,
	HSA_AMD_MEMORY_POOL_INFO_RUNTIME_ALLOC_GRANULE = 6,
	HSA_AMD_MEMORY_POOL_INFO_RUNTIME_ALLOC_ALIGNMENT = 7,
	HSA_AMD_MEMORY_POOL_INFO_ACCESSIBLE_BY_ALL = 15,
	HSA_AMD_MEMORY_POOL_INFO_ALLOC_MAX_SIZE = 16,
	HSA_AMD_MEMORY_POOL_INFO_LOCATION = 17,
	HSA_AMD_MEMORY_POOL_INFO_RUNTIME_ALLOC_REC_GRANULE = 18,
};
enum hsa_extension_t {
	HSA_EXTENSION_FINALIZER = 0,
	HSA_EXTENSION_IMAGES = 1,
	HSA_EXTENSION_PERFORMANCE_COUNTERS = 2,
	HSA_EXTENSION_PROFILING_EVENTS = 3,
	HSA_EXTENSION_STD_LAST = 3,
	HSA_AMD_FIRST_EXTENSION = 512,
	HSA_EXTENSION_AMD_PROFILER = 512,
	HSA_EXTENSION_AMD_LOADER = 513,
	HSA_EXTENSION_AMD_AQLPROFILE = 514,
	HSA_EXTENSION_AMD_PC_SAMPLING = 515,
	HSA_AMD_LAST_EXTENSION = 515,
};
enum hsa_amd_memory_pool_location_s {
	HSA_AMD_MEMORY_POOL_LOCATION_CPU = 0,
	HSA_AMD_MEMORY_POOL_LOCATION_GPU = 1,
};
enum hsa_amd_event_type_s {
	HSA_AMD_GPU_MEMORY_FAULT_EVENT = 0,
	HSA_AMD_GPU_HW_EXCEPTION_EVENT = 1,
	HSA_AMD_GPU_MEMORY_ERROR_EVENT = 2,
	HSA_AMD_SYSTEM_SHUTDOWN_EVENT = 3,
};
enum hsa_amd_agent_memory_pool_info_t {
	HSA_AMD_AGENT_MEMORY_POOL_INFO_ACCESS = 0,
	HSA_AMD_AGENT_MEMORY_POOL_INFO_NUM_LINK_HOPS = 1,
	HSA_AMD_AGENT_MEMORY_POOL_INFO_LINK_INFO = 2,
};
enum hsa_amd_region_info_s {
	HSA_AMD_REGION_INFO_HOST_ACCESSIBLE = 40960,
	HSA_AMD_REGION_INFO_BASE = 40961,
	HSA_AMD_REGION_INFO_BUS_WIDTH = 40962,
	HSA_AMD_REGION_INFO_MAX_CLOCK_FREQUENCY = 40963,
};

/* ============================================================================ *
 * Structure Types
 * ============================================================================ */

typedef struct hsa_ven_amd_pc_sampling_1_00_pfn_t hsa_ven_amd_pc_sampling_1_00_pfn_t;
typedef struct hsa_ext_images_1_pfn_s hsa_ext_images_1_pfn_t;
typedef struct hsa_ext_sampler_descriptor_v2_s hsa_ext_sampler_descriptor_v2_t;
typedef struct hsa_ven_amd_pcs_configuration_t hsa_ven_amd_pcs_configuration_t;
typedef struct hsa_amd_image_descriptor_s hsa_amd_image_descriptor_t;
typedef struct hsa_ext_images_1_00_pfn_s hsa_ext_images_1_00_pfn_t;
typedef struct hsa_ext_sampler_s hsa_ext_sampler_t;
typedef struct hsa_amd_aie_ert_start_kernel_data_s hsa_amd_aie_ert_start_kernel_data_t;
typedef struct hsa_agent_dispatch_packet_s hsa_agent_dispatch_packet_t;
typedef struct hsa_amd_clock_counters_s hsa_amd_clock_counters_t;
typedef struct hsa_ext_image_s hsa_ext_image_t;
typedef struct hsa_region_s hsa_region_t;
typedef struct hsa_barrier_and_packet_s hsa_barrier_and_packet_t;
typedef struct hsa_wavefront_s hsa_wavefront_t;
typedef struct hsa_code_object_s hsa_code_object_t;
typedef struct hsa_amd_barrier_value_packet_s hsa_amd_barrier_value_packet_t;
typedef struct hsa_code_object_reader_s hsa_code_object_reader_t;
typedef struct hsa_amd_packet_header_s hsa_amd_vendor_packet_header_t;
typedef struct hsa_amd_ais_file_handle_s hsa_amd_ais_file_handle_t;
typedef struct hsa_amd_hdp_flush_s hsa_amd_hdp_flush_t;
typedef struct hsa_amd_gpu_memory_error_info_s hsa_amd_gpu_memory_error_info_t;
typedef struct hsa_executable_s hsa_executable_t;
typedef struct hsa_amd_memory_pool_link_info_s hsa_amd_memory_pool_link_info_t;
typedef struct hsa_ext_image_data_info_s hsa_ext_image_data_info_t;
typedef struct hsa_kernel_dispatch_packet_s hsa_kernel_dispatch_packet_t;
typedef struct hsa_amd_ipc_memory_s hsa_amd_ipc_memory_t;
typedef struct hsa_isa_s hsa_isa_t;
typedef struct hsa_amd_pointer_info_s hsa_amd_pointer_info_t;
typedef struct hsa_amd_memory_pool_s hsa_amd_memory_pool_t;
typedef struct hsa_amd_gpu_memory_fault_info_s hsa_amd_gpu_memory_fault_info_t;
typedef struct hsa_barrier_or_packet_s hsa_barrier_or_packet_t;
typedef struct hsa_executable_symbol_s hsa_executable_symbol_t;
typedef struct hsa_amd_memory_access_desc_s hsa_amd_memory_access_desc_t;
typedef struct hsa_amd_svm_attribute_pair_s hsa_amd_svm_attribute_pair_t;
typedef struct hsa_queue_s hsa_queue_t;
typedef struct hsa_cache_s hsa_cache_t;
typedef struct hsa_ext_image_format_s hsa_ext_image_format_t;
typedef struct hsa_ext_image_region_s hsa_ext_image_region_t;
typedef struct hsa_amd_profiling_async_copy_time_s hsa_amd_profiling_async_copy_time_t;
typedef struct hsa_code_symbol_s hsa_code_symbol_t;
typedef struct hsa_amd_event_s hsa_amd_event_t;
typedef struct perf_sample_snapshot_v1_t perf_sample_snapshot_v1_t;
typedef struct perf_sample_hosttrap_v1_t perf_sample_hosttrap_v1_t;
typedef struct hsa_ext_image_descriptor_s hsa_ext_image_descriptor_t;
typedef struct hsa_amd_profiling_dispatch_time_s hsa_amd_profiling_dispatch_time_t;
typedef struct hsa_ven_amd_pcs_t hsa_ven_amd_pcs_t;
typedef struct hsa_dim3_s hsa_dim3_t;
typedef struct hsa_pitched_ptr_s hsa_pitched_ptr_t;
typedef struct hsa_signal_s hsa_signal_t;
typedef struct hsa_signal_group_s hsa_signal_group_t;
typedef struct hsa_agent_s hsa_agent_t;
typedef struct hsa_callback_data_s hsa_callback_data_t;
typedef struct hsa_amd_aie_ert_packet_s hsa_amd_aie_ert_packet_t;
typedef struct hsa_loaded_code_object_s hsa_loaded_code_object_t;
typedef struct hsa_amd_vmem_alloc_handle_s hsa_amd_vmem_alloc_handle_t;
typedef struct hsa_amd_gpu_hw_exception_info_s hsa_amd_gpu_hw_exception_info_t;
typedef struct hsa_ext_sampler_descriptor_s hsa_ext_sampler_descriptor_t;

/* ============================================================================ *
 * Basic Types
 * ============================================================================ */

typedef void (*hsa_amd_deallocation_callback_t)(void *, void *);
typedef uint32_t hsa_ext_sampler_filter_mode32_t;
typedef hsa_status_t (*hsa_ven_amd_pcs_iterate_configuration_callback_t)(const hsa_ven_amd_pcs_configuration_t *, void *);
typedef int hsa_file_t;
typedef uint32_t hsa_ext_sampler_coordinate_mode32_t;
typedef uint32_t hsa_ext_image_channel_type32_t;
typedef int64_t hsa_signal_value_t;
typedef _Bool (*hsa_amd_signal_handler)(hsa_signal_value_t, void *);
typedef uint32_t hsa_ext_image_channel_order32_t;
typedef uint8_t hsa_amd_packet_type8_t;
typedef hsa_status_t (*hsa_ven_amd_pcs_data_copy_callback_t)(void *, size_t, void *);
typedef hsa_status_t (*hsa_amd_system_event_callback_t)(const hsa_amd_event_t *, void *);
typedef void (*hsa_ven_amd_pcs_data_ready_callback_t)(void *, size_t, size_t, hsa_ven_amd_pcs_data_copy_callback_t, void *);
typedef uint32_t hsa_signal_condition32_t;
typedef uint32_t hsa_queue_type32_t;
typedef uint32_t hsa_ext_sampler_addressing_mode32_t;
typedef int hsa_handle_t;
typedef hsa_amd_ipc_memory_t hsa_amd_ipc_signal_t;

/* ============================================================================ *
 * Structure Definitions
 * ============================================================================ */

struct hsa_amd_memory_pool_link_info_s {
    uint32_t min_latency;
    uint32_t max_latency;
    uint32_t min_bandwidth;
    uint32_t max_bandwidth;
    _Bool atomic_support_32bit;
    _Bool atomic_support_64bit;
    _Bool coherent_support;
    hsa_amd_link_info_type_t link_type;
    uint32_t numa_distance;
};

struct hsa_ven_amd_pc_sampling_1_00_pfn_t {
    hsa_status_t (*hsa_ven_amd_pcs_iterate_configuration)(hsa_agent_t, hsa_ven_amd_pcs_iterate_configuration_callback_t, void *);
    hsa_status_t (*hsa_ven_amd_pcs_create)(hsa_agent_t, hsa_ven_amd_pcs_method_kind_t, hsa_ven_amd_pcs_units_t, size_t, size_t, size_t, hsa_ven_amd_pcs_data_ready_callback_t, void *, hsa_ven_amd_pcs_t *);
    hsa_status_t (*hsa_ven_amd_pcs_create_from_id)(uint32_t, hsa_agent_t, hsa_ven_amd_pcs_method_kind_t, hsa_ven_amd_pcs_units_t, size_t, size_t, size_t, hsa_ven_amd_pcs_data_ready_callback_t, void *, hsa_ven_amd_pcs_t *);
    hsa_status_t (*hsa_ven_amd_pcs_destroy)(hsa_ven_amd_pcs_t);
    hsa_status_t (*hsa_ven_amd_pcs_start)(hsa_ven_amd_pcs_t);
    hsa_status_t (*hsa_ven_amd_pcs_stop)(hsa_ven_amd_pcs_t);
    hsa_status_t (*hsa_ven_amd_pcs_flush)(hsa_ven_amd_pcs_t);
};

struct hsa_code_symbol_s {
    uint64_t handle;
};

struct hsa_signal_s {
    uint64_t handle;
};

struct hsa_kernel_dispatch_packet_s {
    union {
        struct {
            uint16_t header;
            uint16_t setup;
        } ;
        uint32_t full_header;
    } ;
    uint16_t workgroup_size_x;
    uint16_t workgroup_size_y;
    uint16_t workgroup_size_z;
    uint16_t reserved0;
    uint32_t grid_size_x;
    uint32_t grid_size_y;
    uint32_t grid_size_z;
    uint32_t private_segment_size;
    uint32_t group_segment_size;
    uint64_t kernel_object;
    void *kernarg_address;
    uint64_t reserved2;
    hsa_signal_t completion_signal;
};

struct hsa_agent_s {
    uint64_t handle;
};

struct hsa_amd_gpu_memory_error_info_s {
    hsa_agent_t agent;
    uint64_t virtual_address;
    uint32_t error_reason_mask;
};

struct hsa_amd_gpu_memory_fault_info_s {
    hsa_agent_t agent;
    uint64_t virtual_address;
    uint32_t fault_reason_mask;
};

struct hsa_amd_gpu_hw_exception_info_s {
    hsa_agent_t agent;
    hsa_amd_hw_exception_reset_type_t reset_type;
    hsa_amd_hw_exception_reset_cause_t reset_cause;
};

struct hsa_barrier_and_packet_s {
    uint16_t header;
    uint16_t reserved0;
    uint32_t reserved1;
    hsa_signal_t dep_signal[5];
    uint64_t reserved2;
    hsa_signal_t completion_signal;
};

struct hsa_amd_packet_header_s {
    uint16_t header;
    hsa_amd_packet_type8_t AmdFormat;
    uint8_t reserved;
};

struct hsa_amd_barrier_value_packet_s {
    hsa_amd_vendor_packet_header_t header;
    uint32_t reserved0;
    hsa_signal_t signal;
    hsa_signal_value_t value;
    hsa_signal_value_t mask;
    hsa_signal_condition32_t cond;
    uint32_t reserved1;
    uint64_t reserved2;
    uint64_t reserved3;
    hsa_signal_t completion_signal;
};

struct hsa_ext_sampler_s {
    uint64_t handle;
};

struct hsa_ven_amd_pcs_configuration_t {
    hsa_ven_amd_pcs_method_kind_t method;
    hsa_ven_amd_pcs_units_t units;
    size_t min_interval;
    size_t max_interval;
    uint64_t flags;
};

struct hsa_signal_group_s {
    uint64_t handle;
};

struct hsa_ven_amd_pcs_t {
    uint64_t handle;
};

struct perf_sample_hosttrap_v1_t {
    uint64_t pc;
    uint64_t exec_mask;
    uint32_t workgroup_id_x;
    uint32_t workgroup_id_y;
    uint32_t workgroup_id_z;
    uint32_t wave_in_wg;
    uint32_t chiplet;
    uint32_t reserved;
    uint32_t hw_id;
    uint32_t reserved0;
    uint64_t reserved1;
    uint64_t timestamp;
    uint64_t correlation_id;
};

struct hsa_pitched_ptr_s {
    void *base;
    size_t pitch;
    size_t slice;
};

struct hsa_ext_image_format_s {
    hsa_ext_image_channel_type32_t channel_type;
    hsa_ext_image_channel_order32_t channel_order;
};

struct hsa_wavefront_s {
    uint64_t handle;
};

struct hsa_code_object_reader_s {
    uint64_t handle;
};

struct hsa_amd_event_s {
    hsa_amd_event_type_t event_type;
    union {
        hsa_amd_gpu_memory_fault_info_t memory_fault;
        hsa_amd_gpu_hw_exception_info_t hw_exception;
        hsa_amd_gpu_memory_error_info_t memory_error;
    } ;
};

struct perf_sample_snapshot_v1_t {
    uint64_t pc;
    uint64_t exec_mask;
    uint32_t workgroup_id_x;
    uint32_t workgroup_id_y;
    uint32_t workgroup_id_z;
    uint32_t wave_in_wg;
    uint32_t chiplet;
    uint32_t reserved;
    uint32_t hw_id;
    uint32_t perf_snapshot_data;
    uint32_t perf_snapshot_data1;
    uint32_t perf_snapshot_data2;
    uint64_t timestamp;
    uint64_t correlation_id;
};

struct hsa_amd_pointer_info_s {
    uint32_t size;
    hsa_amd_pointer_type_t type;
    void *agentBaseAddress;
    void *hostBaseAddress;
    size_t sizeInBytes;
    void *userData;
    hsa_agent_t agentOwner;
    uint32_t global_flags;
    _Bool registered;
};

struct hsa_amd_vmem_alloc_handle_s {
    uint64_t handle;
};

struct hsa_ext_images_1_pfn_s {
    hsa_status_t (*hsa_ext_image_get_capability)(hsa_agent_t, hsa_ext_image_geometry_t, const hsa_ext_image_format_t *, uint32_t *);
    hsa_status_t (*hsa_ext_image_data_get_info)(hsa_agent_t, const hsa_ext_image_descriptor_t *, hsa_access_permission_t, hsa_ext_image_data_info_t *);
    hsa_status_t (*hsa_ext_image_create)(hsa_agent_t, const hsa_ext_image_descriptor_t *, const void *, hsa_access_permission_t, hsa_ext_image_t *);
    hsa_status_t (*hsa_ext_image_destroy)(hsa_agent_t, hsa_ext_image_t);
    hsa_status_t (*hsa_ext_image_copy)(hsa_agent_t, hsa_ext_image_t, const hsa_dim3_t *, hsa_ext_image_t, const hsa_dim3_t *, const hsa_dim3_t *);
    hsa_status_t (*hsa_ext_image_import)(hsa_agent_t, const void *, size_t, size_t, hsa_ext_image_t, const hsa_ext_image_region_t *);
    hsa_status_t (*hsa_ext_image_export)(hsa_agent_t, hsa_ext_image_t, void *, size_t, size_t, const hsa_ext_image_region_t *);
    hsa_status_t (*hsa_ext_image_clear)(hsa_agent_t, hsa_ext_image_t, const void *, const hsa_ext_image_region_t *);
    hsa_status_t (*hsa_ext_sampler_create)(hsa_agent_t, const hsa_ext_sampler_descriptor_t *, hsa_ext_sampler_t *);
    hsa_status_t (*hsa_ext_sampler_destroy)(hsa_agent_t, hsa_ext_sampler_t);
    hsa_status_t (*hsa_ext_image_get_capability_with_layout)(hsa_agent_t, hsa_ext_image_geometry_t, const hsa_ext_image_format_t *, hsa_ext_image_data_layout_t, uint32_t *);
    hsa_status_t (*hsa_ext_image_data_get_info_with_layout)(hsa_agent_t, const hsa_ext_image_descriptor_t *, hsa_access_permission_t, hsa_ext_image_data_layout_t, size_t, size_t, hsa_ext_image_data_info_t *);
    hsa_status_t (*hsa_ext_image_create_with_layout)(hsa_agent_t, const hsa_ext_image_descriptor_t *, const void *, hsa_access_permission_t, hsa_ext_image_data_layout_t, size_t, size_t, hsa_ext_image_t *);
    hsa_status_t (*hsa_ext_sampler_create_v2)(hsa_agent_t, const hsa_ext_sampler_descriptor_v2_t *, hsa_ext_sampler_t *);
};

struct hsa_barrier_or_packet_s {
    uint16_t header;
    uint16_t reserved0;
    uint32_t reserved1;
    hsa_signal_t dep_signal[5];
    uint64_t reserved2;
    hsa_signal_t completion_signal;
};

struct hsa_ext_sampler_descriptor_s {
    hsa_ext_sampler_coordinate_mode32_t coordinate_mode;
    hsa_ext_sampler_filter_mode32_t filter_mode;
    hsa_ext_sampler_addressing_mode32_t address_mode;
};

struct hsa_queue_s {
    hsa_queue_type32_t type;
    uint32_t features;
    void *base_address;
    hsa_signal_t doorbell_signal;
    uint32_t size;
    uint32_t reserved1;
    uint64_t id;
};

struct hsa_dim3_s {
    uint32_t x;
    uint32_t y;
    uint32_t z;
};

struct hsa_cache_s {
    uint64_t handle;
};

struct hsa_ext_image_s {
    uint64_t handle;
};

struct hsa_ext_images_1_00_pfn_s {
    hsa_status_t (*hsa_ext_image_get_capability)(hsa_agent_t, hsa_ext_image_geometry_t, const hsa_ext_image_format_t *, uint32_t *);
    hsa_status_t (*hsa_ext_image_data_get_info)(hsa_agent_t, const hsa_ext_image_descriptor_t *, hsa_access_permission_t, hsa_ext_image_data_info_t *);
    hsa_status_t (*hsa_ext_image_create)(hsa_agent_t, const hsa_ext_image_descriptor_t *, const void *, hsa_access_permission_t, hsa_ext_image_t *);
    hsa_status_t (*hsa_ext_image_destroy)(hsa_agent_t, hsa_ext_image_t);
    hsa_status_t (*hsa_ext_image_copy)(hsa_agent_t, hsa_ext_image_t, const hsa_dim3_t *, hsa_ext_image_t, const hsa_dim3_t *, const hsa_dim3_t *);
    hsa_status_t (*hsa_ext_image_import)(hsa_agent_t, const void *, size_t, size_t, hsa_ext_image_t, const hsa_ext_image_region_t *);
    hsa_status_t (*hsa_ext_image_export)(hsa_agent_t, hsa_ext_image_t, void *, size_t, size_t, const hsa_ext_image_region_t *);
    hsa_status_t (*hsa_ext_image_clear)(hsa_agent_t, hsa_ext_image_t, const void *, const hsa_ext_image_region_t *);
    hsa_status_t (*hsa_ext_sampler_create)(hsa_agent_t, const hsa_ext_sampler_descriptor_t *, hsa_ext_sampler_t *);
    hsa_status_t (*hsa_ext_sampler_destroy)(hsa_agent_t, hsa_ext_sampler_t);
};

struct hsa_ext_sampler_descriptor_v2_s {
    hsa_ext_sampler_coordinate_mode32_t coordinate_mode;
    hsa_ext_sampler_filter_mode32_t filter_mode;
    hsa_ext_sampler_addressing_mode32_t address_modes[3];
};

struct hsa_amd_profiling_async_copy_time_s {
    uint64_t start;
    uint64_t end;
};

struct hsa_amd_aie_ert_start_kernel_data_s {
    void *pdi_addr;
    uint32_t data[];
};

struct hsa_amd_hdp_flush_s {
    uint32_t *HDP_MEM_FLUSH_CNTL;
    uint32_t *HDP_REG_FLUSH_CNTL;
};

struct hsa_executable_symbol_s {
    uint64_t handle;
};

struct hsa_amd_svm_attribute_pair_s {
    uint64_t attribute;
    uint64_t value;
};

struct hsa_amd_clock_counters_s {
    uint64_t gpu_clock_counter;
    uint64_t cpu_clock_counter;
    uint64_t system_clock_counter;
    uint64_t system_clock_frequency;
};

struct hsa_amd_ipc_memory_s {
    uint32_t handle[8];
};

struct hsa_ext_image_descriptor_s {
    hsa_ext_image_geometry_t geometry;
    size_t width;
    size_t height;
    size_t depth;
    size_t array_size;
    hsa_ext_image_format_t format;
};

struct hsa_ext_image_data_info_s {
    size_t size;
    size_t alignment;
};

struct hsa_amd_image_descriptor_s {
    uint32_t version;
    uint32_t deviceID;
    uint32_t data[1];
};

struct hsa_agent_dispatch_packet_s {
    uint16_t header;
    uint16_t type;
    uint32_t reserved0;
    void *return_address;
    uint64_t arg[4];
    uint64_t reserved2;
    hsa_signal_t completion_signal;
};

struct hsa_ext_image_region_s {
    hsa_dim3_t offset;
    hsa_dim3_t range;
};

struct hsa_loaded_code_object_s {
    uint64_t handle;
};

struct hsa_amd_profiling_dispatch_time_s {
    uint64_t start;
    uint64_t end;
};

struct hsa_code_object_s {
    uint64_t handle;
};

struct hsa_callback_data_s {
    uint64_t handle;
};

struct hsa_isa_s {
    uint64_t handle;
};

struct hsa_region_s {
    uint64_t handle;
};

struct hsa_amd_aie_ert_packet_s {
    hsa_amd_vendor_packet_header_t header;
    struct {
        uint32_t state;
        uint32_t custom;
        uint32_t count;
        uint32_t opcode;
        uint32_t type;
    } ;
    uint64_t reserved0;
    uint64_t reserved1;
    uint64_t reserved2;
    uint64_t reserved3;
    uint64_t reserved4;
    uint64_t reserved5;
    uint64_t payload_data;
};

struct hsa_amd_memory_pool_s {
    uint64_t handle;
};

struct hsa_amd_ais_file_handle_s {
    union {
        void *handle;
        int fd;
        uint8_t pad[8];
    } ;
};

struct hsa_executable_s {
    uint64_t handle;
};

struct hsa_amd_memory_access_desc_s {
    hsa_access_permission_t permissions;
    hsa_agent_t agent_handle;
};


#endif /* HSA_MINIMAL_ABI_H_ */
