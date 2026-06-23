#ifndef HIP_MINIMAL_ABI_H_
#define HIP_MINIMAL_ABI_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* ============================================================================ *
 * Minimal ABI Header for HIP
 * Auto-generated from CSV type definitions
 * ============================================================================ */

/* ============================================================================ *
 * Enum Types
 * ============================================================================ */

typedef enum hipMemOperationType hipMemOperationType;
typedef enum hipDriverEntryPointQueryResult hipDriverEntryPointQueryResult;
typedef enum hipStreamCaptureMode hipStreamCaptureMode;
typedef enum hipStreamCaptureStatus hipStreamCaptureStatus;
typedef enum hipGraphInstantiateResult hipGraphInstantiateResult;
typedef enum hipExternalMemoryHandleType_enum hipExternalMemoryHandleType;
typedef enum hipMemcpyKind hipMemcpyKind;
typedef enum hipLibraryOption_e hipLibraryOption;
typedef enum hipMemAllocationGranularity_flags hipMemAllocationGranularity_flags;
typedef enum hipJitFallback hipJitFallback;
typedef enum hipGraphMemAttributeType hipGraphMemAttributeType;
typedef enum hipMemAllocationType hipMemAllocationType;
typedef enum hipMemRangeCoherencyMode hipMemRangeCoherencyMode;
typedef enum hipMemcpyFlags hipMemcpyFlags;
typedef enum hipJitCacheMode hipJitCacheMode;
typedef enum hipError_t hipError_t;
typedef enum hipFuncCache_t hipFuncCache_t;
typedef enum hipGraphNodeType hipGraphNodeType;
typedef enum HIPresourceViewFormat_enum HIPresourceViewFormat;
typedef enum hipArray_Format hipArray_Format;
typedef enum hipGraphExecUpdateResult hipGraphExecUpdateResult;
typedef enum hipGraphInstantiateFlags hipGraphInstantiateFlags;
typedef enum hipLaunchAttributeID hipLaunchAttributeID;
typedef enum hipChannelFormatKind hipChannelFormatKind;
typedef enum hipMemRangeAttribute hipMemRangeAttribute;
typedef enum hipResourceViewFormat hipResourceViewFormat;
typedef enum hipMemoryAdvise hipMemoryAdvise;
typedef enum hipMemLocationType hipMemLocationType;
typedef enum hipSynchronizationPolicy hipSynchronizationPolicy;
typedef enum hipLaunchMemSyncDomain hipLaunchMemSyncDomain;
typedef enum HIPfilter_mode_enum HIPfilter_mode;
typedef enum HIPresourcetype_enum HIPresourcetype;
typedef enum hipGraphicsRegisterFlags hipGraphicsRegisterFlags;
typedef enum hipDeviceP2PAttr hipDeviceP2PAttr;
typedef enum hipUserObjectRetainFlags hipUserObjectRetainFlags;
typedef enum hipUserObjectFlags hipUserObjectFlags;
typedef enum hipDataType hipDataType;
typedef enum hipMemRangeFlags hipMemRangeFlags;
typedef enum hipStreamUpdateCaptureDependenciesFlags hipStreamUpdateCaptureDependenciesFlags;
typedef enum hipJitOption hipJitOption;
typedef enum hipMemcpy3DOperandType hipMemcpy3DOperandType;
typedef enum hipMemPoolAttr hipMemPoolAttr;
typedef enum hipStreamBatchMemOpType hipStreamBatchMemOpType;
typedef enum HIPaddress_mode_enum HIPaddress_mode;
typedef enum hipSharedMemConfig hipSharedMemConfig;
typedef enum HIPresourcetype_enum hipResourcetype;
typedef enum hipResourceType hipResourceType;
typedef enum hipDriverProcAddressQueryResult hipDriverProcAddressQueryResult;
typedef enum hipMemHandleType hipMemHandleType;
typedef enum hipExternalSemaphoreHandleType_enum hipExternalSemaphoreHandleType;
typedef enum hipPointer_attribute hipPointer_attribute;
typedef enum hipDeviceAttribute_t hipDeviceAttribute_t;
typedef enum hipMemoryType hipMemoryType;
typedef enum hipMemcpySrcAccessOrder hipMemcpySrcAccessOrder;
typedef enum hipMemRangeHandleType hipMemRangeHandleType;
typedef enum hipFuncAttribute hipFuncAttribute;
typedef enum hipAccessProperty hipAccessProperty;
typedef enum hipMemAllocationHandleType hipMemAllocationHandleType;
typedef enum hipMemAccessFlags hipMemAccessFlags;
typedef enum hipArraySparseSubresourceType hipArraySparseSubresourceType;
typedef enum hipLibraryPropertyType hipLibraryPropertyType;
typedef enum hipJitInputType hipJitInputType;
typedef enum hipGraphDependencyType hipGraphDependencyType;
typedef enum hipFunction_attribute hipFunction_attribute;

/* ============================================================================ *
 * Enum Definitions
 * ============================================================================ */

enum hipMemoryAdvise {
	hipMemAdviseSetReadMostly = 1,
	hipMemAdviseUnsetReadMostly = 2,
	hipMemAdviseSetPreferredLocation = 3,
	hipMemAdviseUnsetPreferredLocation = 4,
	hipMemAdviseSetAccessedBy = 5,
	hipMemAdviseUnsetAccessedBy = 6,
	hipMemAdviseSetCoarseGrain = 100,
	hipMemAdviseUnsetCoarseGrain = 101,
};
enum hipMemOperationType {
	hipMemOperationTypeMap = 1,
	hipMemOperationTypeUnmap = 2,
};
enum hipDriverEntryPointQueryResult {
	hipDriverEntryPointSuccess = 0,
	hipDriverEntryPointSymbolNotFound = 1,
	hipDriverEntryPointVersionNotSufficent = 2,
};
enum HIPresourceViewFormat_enum {
	HIP_RES_VIEW_FORMAT_NONE = 0,
	HIP_RES_VIEW_FORMAT_UINT_1X8 = 1,
	HIP_RES_VIEW_FORMAT_UINT_2X8 = 2,
	HIP_RES_VIEW_FORMAT_UINT_4X8 = 3,
	HIP_RES_VIEW_FORMAT_SINT_1X8 = 4,
	HIP_RES_VIEW_FORMAT_SINT_2X8 = 5,
	HIP_RES_VIEW_FORMAT_SINT_4X8 = 6,
	HIP_RES_VIEW_FORMAT_UINT_1X16 = 7,
	HIP_RES_VIEW_FORMAT_UINT_2X16 = 8,
	HIP_RES_VIEW_FORMAT_UINT_4X16 = 9,
	HIP_RES_VIEW_FORMAT_SINT_1X16 = 10,
	HIP_RES_VIEW_FORMAT_SINT_2X16 = 11,
	HIP_RES_VIEW_FORMAT_SINT_4X16 = 12,
	HIP_RES_VIEW_FORMAT_UINT_1X32 = 13,
	HIP_RES_VIEW_FORMAT_UINT_2X32 = 14,
	HIP_RES_VIEW_FORMAT_UINT_4X32 = 15,
	HIP_RES_VIEW_FORMAT_SINT_1X32 = 16,
	HIP_RES_VIEW_FORMAT_SINT_2X32 = 17,
	HIP_RES_VIEW_FORMAT_SINT_4X32 = 18,
	HIP_RES_VIEW_FORMAT_FLOAT_1X16 = 19,
	HIP_RES_VIEW_FORMAT_FLOAT_2X16 = 20,
	HIP_RES_VIEW_FORMAT_FLOAT_4X16 = 21,
	HIP_RES_VIEW_FORMAT_FLOAT_1X32 = 22,
	HIP_RES_VIEW_FORMAT_FLOAT_2X32 = 23,
	HIP_RES_VIEW_FORMAT_FLOAT_4X32 = 24,
	HIP_RES_VIEW_FORMAT_UNSIGNED_BC1 = 25,
	HIP_RES_VIEW_FORMAT_UNSIGNED_BC2 = 26,
	HIP_RES_VIEW_FORMAT_UNSIGNED_BC3 = 27,
	HIP_RES_VIEW_FORMAT_UNSIGNED_BC4 = 28,
	HIP_RES_VIEW_FORMAT_SIGNED_BC4 = 29,
	HIP_RES_VIEW_FORMAT_UNSIGNED_BC5 = 30,
	HIP_RES_VIEW_FORMAT_SIGNED_BC5 = 31,
	HIP_RES_VIEW_FORMAT_UNSIGNED_BC6H = 32,
	HIP_RES_VIEW_FORMAT_SIGNED_BC6H = 33,
	HIP_RES_VIEW_FORMAT_UNSIGNED_BC7 = 34,
};
enum hipFlushGPUDirectRDMAWritesOptions {
	hipFlushGPUDirectRDMAWritesOptionHost = 1,
	hipFlushGPUDirectRDMAWritesOptionMemOps = 2,
};
enum hipStreamCaptureMode {
	hipStreamCaptureModeGlobal = 0,
	hipStreamCaptureModeThreadLocal = 1,
	hipStreamCaptureModeRelaxed = 2,
};
enum HIPaddress_mode_enum {
	HIP_TR_ADDRESS_MODE_WRAP = 0,
	HIP_TR_ADDRESS_MODE_CLAMP = 1,
	HIP_TR_ADDRESS_MODE_MIRROR = 2,
	HIP_TR_ADDRESS_MODE_BORDER = 3,
};
enum hipArray_Format {
	HIP_AD_FORMAT_UNSIGNED_INT8 = 1,
	HIP_AD_FORMAT_UNSIGNED_INT16 = 2,
	HIP_AD_FORMAT_UNSIGNED_INT32 = 3,
	HIP_AD_FORMAT_SIGNED_INT8 = 8,
	HIP_AD_FORMAT_SIGNED_INT16 = 9,
	HIP_AD_FORMAT_SIGNED_INT32 = 10,
	HIP_AD_FORMAT_HALF = 16,
	HIP_AD_FORMAT_FLOAT = 32,
};
enum hipGraphInstantiateResult {
	hipGraphInstantiateSuccess = 0,
	hipGraphInstantiateError = 1,
	hipGraphInstantiateInvalidStructure = 2,
	hipGraphInstantiateNodeOperationNotSupported = 3,
	hipGraphInstantiateMultipleDevicesNotSupported = 4,
};
enum hipMemcpyKind {
	hipMemcpyHostToHost = 0,
	hipMemcpyHostToDevice = 1,
	hipMemcpyDeviceToHost = 2,
	hipMemcpyDeviceToDevice = 3,
	hipMemcpyDefault = 4,
	hipMemcpyDeviceToDeviceNoCU = 1024,
};
enum hipGraphicsRegisterFlags {
	hipGraphicsRegisterFlagsNone = 0,
	hipGraphicsRegisterFlagsReadOnly = 1,
	hipGraphicsRegisterFlagsWriteDiscard = 2,
	hipGraphicsRegisterFlagsSurfaceLoadStore = 4,
	hipGraphicsRegisterFlagsTextureGather = 8,
};
enum hipDeviceP2PAttr {
	hipDevP2PAttrPerformanceRank = 0,
	hipDevP2PAttrAccessSupported = 1,
	hipDevP2PAttrNativeAtomicSupported = 2,
	hipDevP2PAttrHipArrayAccessSupported = 3,
};
enum hipLimit_t {
	hipLimitStackSize = 0,
	hipLimitPrintfFifoSize = 1,
	hipLimitMallocHeapSize = 2,
	hipExtLimitScratchMin = 4096,
	hipExtLimitScratchMax = 4097,
	hipExtLimitScratchCurrent = 4098,
	hipLimitRange = 4099,
};
enum hipArraySparseSubresourceType {
	hipArraySparseSubresourceTypeSparseLevel = 0,
	hipArraySparseSubresourceTypeMiptail = 1,
};
enum hipUserObjectRetainFlags {
	hipGraphUserObjectMove = 1,
};
enum hipDataType {
	HIP_R_32F = 0,
	HIP_R_64F = 1,
	HIP_R_16F = 2,
	HIP_R_8I = 3,
	HIP_C_32F = 4,
	HIP_C_64F = 5,
	HIP_C_16F = 6,
	HIP_C_8I = 7,
	HIP_R_8U = 8,
	HIP_C_8U = 9,
	HIP_R_32I = 10,
	HIP_C_32I = 11,
	HIP_R_32U = 12,
	HIP_C_32U = 13,
	HIP_R_16BF = 14,
	HIP_C_16BF = 15,
	HIP_R_4I = 16,
	HIP_C_4I = 17,
	HIP_R_4U = 18,
	HIP_C_4U = 19,
	HIP_R_16I = 20,
	HIP_C_16I = 21,
	HIP_R_16U = 22,
	HIP_C_16U = 23,
	HIP_R_64I = 24,
	HIP_C_64I = 25,
	HIP_R_64U = 26,
	HIP_C_64U = 27,
	HIP_R_8F_E4M3 = 28,
	HIP_R_8F_E5M2 = 29,
	HIP_R_8F_UE8M0 = 30,
	HIP_R_6F_E2M3 = 31,
	HIP_R_6F_E3M2 = 32,
	HIP_R_4F_E2M1 = 33,
	HIP_R_8F_E4M3_FNUZ = 1000,
	HIP_R_8F_E5M2_FNUZ = 1001,
};
enum hipJitOption {
	hipJitOptionMaxRegisters = 0,
	hipJitOptionThreadsPerBlock = 1,
	hipJitOptionWallTime = 2,
	hipJitOptionInfoLogBuffer = 3,
	hipJitOptionInfoLogBufferSizeBytes = 4,
	hipJitOptionErrorLogBuffer = 5,
	hipJitOptionErrorLogBufferSizeBytes = 6,
	hipJitOptionOptimizationLevel = 7,
	hipJitOptionTargetFromContext = 8,
	hipJitOptionTarget = 9,
	hipJitOptionFallbackStrategy = 10,
	hipJitOptionGenerateDebugInfo = 11,
	hipJitOptionLogVerbose = 12,
	hipJitOptionGenerateLineInfo = 13,
	hipJitOptionCacheMode = 14,
	hipJitOptionSm3xOpt = 15,
	hipJitOptionFastCompile = 16,
	hipJitOptionGlobalSymbolNames = 17,
	hipJitOptionGlobalSymbolAddresses = 18,
	hipJitOptionGlobalSymbolCount = 19,
	hipJitOptionLto = 20,
	hipJitOptionFtz = 21,
	hipJitOptionPrecDiv = 22,
	hipJitOptionPrecSqrt = 23,
	hipJitOptionFma = 24,
	hipJitOptionPositionIndependentCode = 25,
	hipJitOptionMinCTAPerSM = 26,
	hipJitOptionMaxThreadsPerBlock = 27,
	hipJitOptionOverrideDirectiveValues = 28,
	hipJitOptionNumOptions = 29,
	hipJitOptionIRtoISAOptExt = 10000,
	hipJitOptionIRtoISAOptCountExt = 10001,
};
enum hipMemcpy3DOperandType {
	hipMemcpyOperandTypePointer = 1,
	hipMemcpyOperandTypeArray = 2,
	hipMemcpyOperandTypeMax = 2147483647,
};
enum hipMemPoolAttr {
	hipMemPoolReuseFollowEventDependencies = 1,
	hipMemPoolReuseAllowOpportunistic = 2,
	hipMemPoolReuseAllowInternalDependencies = 3,
	hipMemPoolAttrReleaseThreshold = 4,
	hipMemPoolAttrReservedMemCurrent = 5,
	hipMemPoolAttrReservedMemHigh = 6,
	hipMemPoolAttrUsedMemCurrent = 7,
	hipMemPoolAttrUsedMemHigh = 8,
};
enum hipJitFallback {
	hipJitPreferPTX = 0,
	hipJitPreferBinary = 1,
};
enum HIPfilter_mode_enum {
	HIP_TR_FILTER_MODE_POINT = 0,
	HIP_TR_FILTER_MODE_LINEAR = 1,
};
enum HIPresourcetype_enum {
	HIP_RESOURCE_TYPE_ARRAY = 0,
	HIP_RESOURCE_TYPE_MIPMAPPED_ARRAY = 1,
	HIP_RESOURCE_TYPE_LINEAR = 2,
	HIP_RESOURCE_TYPE_PITCH2D = 3,
};
enum hipDriverProcAddressQueryResult {
	HIP_GET_PROC_ADDRESS_SUCCESS = 0,
	HIP_GET_PROC_ADDRESS_SYMBOL_NOT_FOUND = 1,
	HIP_GET_PROC_ADDRESS_VERSION_NOT_SUFFICIENT = 2,
};
enum hipGraphMemAttributeType {
	hipGraphMemAttrUsedMemCurrent = 0,
	hipGraphMemAttrUsedMemHigh = 1,
	hipGraphMemAttrReservedMemCurrent = 2,
	hipGraphMemAttrReservedMemHigh = 3,
};
enum hipMemHandleType {
	hipMemHandleTypeGeneric = 0,
};
enum hipResourceType {
	hipResourceTypeArray = 0,
	hipResourceTypeMipmappedArray = 1,
	hipResourceTypeLinear = 2,
	hipResourceTypePitch2D = 3,
};
enum hipExternalMemoryHandleType_enum {
	hipExternalMemoryHandleTypeOpaqueFd = 1,
	hipExternalMemoryHandleTypeOpaqueWin32 = 2,
	hipExternalMemoryHandleTypeOpaqueWin32Kmt = 3,
	hipExternalMemoryHandleTypeD3D12Heap = 4,
	hipExternalMemoryHandleTypeD3D12Resource = 5,
	hipExternalMemoryHandleTypeD3D11Resource = 6,
	hipExternalMemoryHandleTypeD3D11ResourceKmt = 7,
	hipExternalMemoryHandleTypeNvSciBuf = 8,
};
enum hipMemcpyFlags {
	hipMemcpyFlagDefault = 0,
	hipMemcpyFlagPreferOverlapWithCompute = 1,
};
enum hipJitCacheMode {
	hipJitCacheOptionNone = 0,
	hipJitCacheOptionCG = 1,
	hipJitCacheOptionCA = 2,
};
enum hipMemRangeAttribute {
	hipMemRangeAttributeReadMostly = 1,
	hipMemRangeAttributePreferredLocation = 2,
	hipMemRangeAttributeAccessedBy = 3,
	hipMemRangeAttributeLastPrefetchLocation = 4,
	hipMemRangeAttributeCoherencyMode = 100,
};
enum hipComputeMode {
	hipComputeModeDefault = 0,
	hipComputeModeExclusive = 1,
	hipComputeModeProhibited = 2,
	hipComputeModeExclusiveProcess = 3,
};
enum hipStreamUpdateCaptureDependenciesFlags {
	hipStreamAddCaptureDependencies = 0,
	hipStreamSetCaptureDependencies = 1,
};
enum hipGPUDirectRDMAWritesOrdering {
	hipGPUDirectRDMAWritesOrderingNone = 0,
	hipGPUDirectRDMAWritesOrderingOwner = 100,
	hipGPUDirectRDMAWritesOrderingAllDevices = 200,
};
enum hipError_t {
	hipSuccess = 0,
	hipErrorInvalidValue = 1,
	hipErrorOutOfMemory = 2,
	hipErrorMemoryAllocation = 2,
	hipErrorNotInitialized = 3,
	hipErrorInitializationError = 3,
	hipErrorDeinitialized = 4,
	hipErrorProfilerDisabled = 5,
	hipErrorProfilerNotInitialized = 6,
	hipErrorProfilerAlreadyStarted = 7,
	hipErrorProfilerAlreadyStopped = 8,
	hipErrorInvalidConfiguration = 9,
	hipErrorInvalidPitchValue = 12,
	hipErrorInvalidSymbol = 13,
	hipErrorInvalidDevicePointer = 17,
	hipErrorInvalidMemcpyDirection = 21,
	hipErrorInsufficientDriver = 35,
	hipErrorMissingConfiguration = 52,
	hipErrorPriorLaunchFailure = 53,
	hipErrorInvalidDeviceFunction = 98,
	hipErrorNoDevice = 100,
	hipErrorInvalidDevice = 101,
	hipErrorInvalidImage = 200,
	hipErrorInvalidContext = 201,
	hipErrorContextAlreadyCurrent = 202,
	hipErrorMapFailed = 205,
	hipErrorMapBufferObjectFailed = 205,
	hipErrorUnmapFailed = 206,
	hipErrorArrayIsMapped = 207,
	hipErrorAlreadyMapped = 208,
	hipErrorNoBinaryForGpu = 209,
	hipErrorAlreadyAcquired = 210,
	hipErrorNotMapped = 211,
	hipErrorNotMappedAsArray = 212,
	hipErrorNotMappedAsPointer = 213,
	hipErrorECCNotCorrectable = 214,
	hipErrorUnsupportedLimit = 215,
	hipErrorContextAlreadyInUse = 216,
	hipErrorPeerAccessUnsupported = 217,
	hipErrorInvalidKernelFile = 218,
	hipErrorInvalidGraphicsContext = 219,
	hipErrorInvalidSource = 300,
	hipErrorFileNotFound = 301,
	hipErrorSharedObjectSymbolNotFound = 302,
	hipErrorSharedObjectInitFailed = 303,
	hipErrorOperatingSystem = 304,
	hipErrorInvalidHandle = 400,
	hipErrorInvalidResourceHandle = 400,
	hipErrorIllegalState = 401,
	hipErrorNotFound = 500,
	hipErrorNotReady = 600,
	hipErrorIllegalAddress = 700,
	hipErrorLaunchOutOfResources = 701,
	hipErrorLaunchTimeOut = 702,
	hipErrorPeerAccessAlreadyEnabled = 704,
	hipErrorPeerAccessNotEnabled = 705,
	hipErrorSetOnActiveProcess = 708,
	hipErrorContextIsDestroyed = 709,
	hipErrorAssert = 710,
	hipErrorHostMemoryAlreadyRegistered = 712,
	hipErrorHostMemoryNotRegistered = 713,
	hipErrorLaunchFailure = 719,
	hipErrorCooperativeLaunchTooLarge = 720,
	hipErrorNotSupported = 801,
	hipErrorStreamCaptureUnsupported = 900,
	hipErrorStreamCaptureInvalidated = 901,
	hipErrorStreamCaptureMerge = 902,
	hipErrorStreamCaptureUnmatched = 903,
	hipErrorStreamCaptureUnjoined = 904,
	hipErrorStreamCaptureIsolation = 905,
	hipErrorStreamCaptureImplicit = 906,
	hipErrorCapturedEvent = 907,
	hipErrorStreamCaptureWrongThread = 908,
	hipErrorGraphExecUpdateFailure = 910,
	hipErrorInvalidChannelDescriptor = 911,
	hipErrorInvalidTexture = 912,
	hipErrorUnknown = 999,
	hipErrorRuntimeMemory = 1052,
	hipErrorRuntimeOther = 1053,
	hipErrorTbd = 1054,
};
enum hipFuncCache_t {
	hipFuncCachePreferNone = 0,
	hipFuncCachePreferShared = 1,
	hipFuncCachePreferL1 = 2,
	hipFuncCachePreferEqual = 3,
};
enum hipUserObjectFlags {
	hipUserObjectNoDestructorSync = 1,
};
enum hipTextureReadMode {
	hipReadModeElementType = 0,
	hipReadModeNormalizedFloat = 1,
};
enum hipMemRangeFlags {
	hipMemRangeFlagDmaBufMappingTypePcie = 1,
	hipMemRangeFlagsMax = 2147483647,
};
enum hipLaunchMemSyncDomain {
	hipLaunchMemSyncDomainDefault = 0,
	hipLaunchMemSyncDomainRemote = 1,
};
enum hipTextureFilterMode {
	hipFilterModePoint = 0,
	hipFilterModeLinear = 1,
};
enum hipJitInputType {
	hipJitInputCubin = 0,
	hipJitInputPtx = 1,
	hipJitInputFatBinary = 2,
	hipJitInputObject = 3,
	hipJitInputLibrary = 4,
	hipJitInputNvvm = 5,
	hipJitNumLegacyInputTypes = 6,
	hipJitInputLLVMBitcode = 100,
	hipJitInputLLVMBundledBitcode = 101,
	hipJitInputLLVMArchivesOfBundledBitcode = 102,
	hipJitInputSpirv = 103,
	hipJitNumInputTypes = 10,
};
enum hipTextureAddressMode {
	hipAddressModeWrap = 0,
	hipAddressModeClamp = 1,
	hipAddressModeMirror = 2,
	hipAddressModeBorder = 3,
};
enum hipSynchronizationPolicy {
	hipSyncPolicyAuto = 1,
	hipSyncPolicySpin = 2,
	hipSyncPolicyYield = 3,
	hipSyncPolicyBlockingSync = 4,
};
enum hipGraphNodeType {
	hipGraphNodeTypeKernel = 0,
	hipGraphNodeTypeMemcpy = 1,
	hipGraphNodeTypeMemset = 2,
	hipGraphNodeTypeHost = 3,
	hipGraphNodeTypeGraph = 4,
	hipGraphNodeTypeEmpty = 5,
	hipGraphNodeTypeWaitEvent = 6,
	hipGraphNodeTypeEventRecord = 7,
	hipGraphNodeTypeExtSemaphoreSignal = 8,
	hipGraphNodeTypeExtSemaphoreWait = 9,
	hipGraphNodeTypeMemAlloc = 10,
	hipGraphNodeTypeMemFree = 11,
	hipGraphNodeTypeMemcpyFromSymbol = 12,
	hipGraphNodeTypeMemcpyToSymbol = 13,
	hipGraphNodeTypeBatchMemOp = 14,
	hipGraphNodeTypeCount = 15,
};
enum hipSurfaceBoundaryMode {
	hipBoundaryModeZero = 0,
	hipBoundaryModeTrap = 1,
	hipBoundaryModeClamp = 2,
};
enum hipStreamCaptureStatus {
	hipStreamCaptureStatusNone = 0,
	hipStreamCaptureStatusActive = 1,
	hipStreamCaptureStatusInvalidated = 2,
};
enum hipMemAllocationType {
	hipMemAllocationTypeInvalid = 0,
	hipMemAllocationTypePinned = 1,
	hipMemAllocationTypeUncached = 1073741824,
	hipMemAllocationTypeMax = 2147483647,
};
enum hipSharedMemConfig {
	hipSharedMemBankSizeDefault = 0,
	hipSharedMemBankSizeFourByte = 1,
	hipSharedMemBankSizeEightByte = 2,
};
enum hipGraphDependencyType {
	hipGraphDependencyTypeDefault = 0,
	hipGraphDependencyTypeProgrammatic = 1,
};
enum hipStreamBatchMemOpType {
	hipStreamMemOpWaitValue32 = 1,
	hipStreamMemOpWriteValue32 = 2,
	hipStreamMemOpWaitValue64 = 4,
	hipStreamMemOpWriteValue64 = 5,
	hipStreamMemOpBarrier = 6,
	hipStreamMemOpFlushRemoteWrites = 3,
};
enum hipFunction_attribute {
	HIP_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 0,
	HIP_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES = 1,
	HIP_FUNC_ATTRIBUTE_CONST_SIZE_BYTES = 2,
	HIP_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES = 3,
	HIP_FUNC_ATTRIBUTE_NUM_REGS = 4,
	HIP_FUNC_ATTRIBUTE_PTX_VERSION = 5,
	HIP_FUNC_ATTRIBUTE_BINARY_VERSION = 6,
	HIP_FUNC_ATTRIBUTE_CACHE_MODE_CA = 7,
	HIP_FUNC_ATTRIBUTE_MAX_DYNAMIC_SHARED_SIZE_BYTES = 8,
	HIP_FUNC_ATTRIBUTE_PREFERRED_SHARED_MEMORY_CARVEOUT = 9,
	HIP_FUNC_ATTRIBUTE_MAX = 10,
};
enum hipDeviceAttribute_t {
	hipDeviceAttributeCudaCompatibleBegin = 0,
	hipDeviceAttributeEccEnabled = 0,
	hipDeviceAttributeAccessPolicyMaxWindowSize = 1,
	hipDeviceAttributeAsyncEngineCount = 2,
	hipDeviceAttributeCanMapHostMemory = 3,
	hipDeviceAttributeCanUseHostPointerForRegisteredMem = 4,
	hipDeviceAttributeClockRate = 5,
	hipDeviceAttributeComputeMode = 6,
	hipDeviceAttributeComputePreemptionSupported = 7,
	hipDeviceAttributeConcurrentKernels = 8,
	hipDeviceAttributeConcurrentManagedAccess = 9,
	hipDeviceAttributeCooperativeLaunch = 10,
	hipDeviceAttributeCooperativeMultiDeviceLaunch = 11,
	hipDeviceAttributeDeviceOverlap = 12,
	hipDeviceAttributeDirectManagedMemAccessFromHost = 13,
	hipDeviceAttributeGlobalL1CacheSupported = 14,
	hipDeviceAttributeHostNativeAtomicSupported = 15,
	hipDeviceAttributeIntegrated = 16,
	hipDeviceAttributeIsMultiGpuBoard = 17,
	hipDeviceAttributeKernelExecTimeout = 18,
	hipDeviceAttributeL2CacheSize = 19,
	hipDeviceAttributeLocalL1CacheSupported = 20,
	hipDeviceAttributeLuid = 21,
	hipDeviceAttributeLuidDeviceNodeMask = 22,
	hipDeviceAttributeComputeCapabilityMajor = 23,
	hipDeviceAttributeManagedMemory = 24,
	hipDeviceAttributeMaxBlocksPerMultiProcessor = 25,
	hipDeviceAttributeMaxBlockDimX = 26,
	hipDeviceAttributeMaxBlockDimY = 27,
	hipDeviceAttributeMaxBlockDimZ = 28,
	hipDeviceAttributeMaxGridDimX = 29,
	hipDeviceAttributeMaxGridDimY = 30,
	hipDeviceAttributeMaxGridDimZ = 31,
	hipDeviceAttributeMaxSurface1D = 32,
	hipDeviceAttributeMaxSurface1DLayered = 33,
	hipDeviceAttributeMaxSurface2D = 34,
	hipDeviceAttributeMaxSurface2DLayered = 35,
	hipDeviceAttributeMaxSurface3D = 36,
	hipDeviceAttributeMaxSurfaceCubemap = 37,
	hipDeviceAttributeMaxSurfaceCubemapLayered = 38,
	hipDeviceAttributeMaxTexture1DWidth = 39,
	hipDeviceAttributeMaxTexture1DLayered = 40,
	hipDeviceAttributeMaxTexture1DLinear = 41,
	hipDeviceAttributeMaxTexture1DMipmap = 42,
	hipDeviceAttributeMaxTexture2DWidth = 43,
	hipDeviceAttributeMaxTexture2DHeight = 44,
	hipDeviceAttributeMaxTexture2DGather = 45,
	hipDeviceAttributeMaxTexture2DLayered = 46,
	hipDeviceAttributeMaxTexture2DLinear = 47,
	hipDeviceAttributeMaxTexture2DMipmap = 48,
	hipDeviceAttributeMaxTexture3DWidth = 49,
	hipDeviceAttributeMaxTexture3DHeight = 50,
	hipDeviceAttributeMaxTexture3DDepth = 51,
	hipDeviceAttributeMaxTexture3DAlt = 52,
	hipDeviceAttributeMaxTextureCubemap = 53,
	hipDeviceAttributeMaxTextureCubemapLayered = 54,
	hipDeviceAttributeMaxThreadsDim = 55,
	hipDeviceAttributeMaxThreadsPerBlock = 56,
	hipDeviceAttributeMaxThreadsPerMultiProcessor = 57,
	hipDeviceAttributeMaxPitch = 58,
	hipDeviceAttributeMemoryBusWidth = 59,
	hipDeviceAttributeMemoryClockRate = 60,
	hipDeviceAttributeComputeCapabilityMinor = 61,
	hipDeviceAttributeMultiGpuBoardGroupID = 62,
	hipDeviceAttributeMultiprocessorCount = 63,
	hipDeviceAttributeUnused1 = 64,
	hipDeviceAttributePageableMemoryAccess = 65,
	hipDeviceAttributePageableMemoryAccessUsesHostPageTables = 66,
	hipDeviceAttributePciBusId = 67,
	hipDeviceAttributePciDeviceId = 68,
	hipDeviceAttributePciDomainId = 69,
	hipDeviceAttributePciDomainID = 69,
	hipDeviceAttributePersistingL2CacheMaxSize = 70,
	hipDeviceAttributeMaxRegistersPerBlock = 71,
	hipDeviceAttributeMaxRegistersPerMultiprocessor = 72,
	hipDeviceAttributeReservedSharedMemPerBlock = 73,
	hipDeviceAttributeMaxSharedMemoryPerBlock = 74,
	hipDeviceAttributeSharedMemPerBlockOptin = 75,
	hipDeviceAttributeSharedMemPerMultiprocessor = 76,
	hipDeviceAttributeSingleToDoublePrecisionPerfRatio = 77,
	hipDeviceAttributeStreamPrioritiesSupported = 78,
	hipDeviceAttributeSurfaceAlignment = 79,
	hipDeviceAttributeTccDriver = 80,
	hipDeviceAttributeTextureAlignment = 81,
	hipDeviceAttributeTexturePitchAlignment = 82,
	hipDeviceAttributeTotalConstantMemory = 83,
	hipDeviceAttributeTotalGlobalMem = 84,
	hipDeviceAttributeUnifiedAddressing = 85,
	hipDeviceAttributeUnused2 = 86,
	hipDeviceAttributeWarpSize = 87,
	hipDeviceAttributeMemoryPoolsSupported = 88,
	hipDeviceAttributeVirtualMemoryManagementSupported = 89,
	hipDeviceAttributeHostRegisterSupported = 90,
	hipDeviceAttributeMemoryPoolSupportedHandleTypes = 91,
	hipDeviceAttributeHostNumaId = 92,
	hipDeviceAttributeCudaCompatibleEnd = 9999,
	hipDeviceAttributeAmdSpecificBegin = 10000,
	hipDeviceAttributeClockInstructionRate = 10000,
	hipDeviceAttributeUnused3 = 10001,
	hipDeviceAttributeMaxSharedMemoryPerMultiprocessor = 10002,
	hipDeviceAttributeUnused4 = 10003,
	hipDeviceAttributeUnused5 = 10004,
	hipDeviceAttributeHdpMemFlushCntl = 10005,
	hipDeviceAttributeHdpRegFlushCntl = 10006,
	hipDeviceAttributeCooperativeMultiDeviceUnmatchedFunc = 10007,
	hipDeviceAttributeCooperativeMultiDeviceUnmatchedGridDim = 10008,
	hipDeviceAttributeCooperativeMultiDeviceUnmatchedBlockDim = 10009,
	hipDeviceAttributeCooperativeMultiDeviceUnmatchedSharedMem = 10010,
	hipDeviceAttributeIsLargeBar = 10011,
	hipDeviceAttributeAsicRevision = 10012,
	hipDeviceAttributeCanUseStreamWaitValue = 10013,
	hipDeviceAttributeImageSupport = 10014,
	hipDeviceAttributePhysicalMultiProcessorCount = 10015,
	hipDeviceAttributeFineGrainSupport = 10016,
	hipDeviceAttributeWallClockRate = 10017,
	hipDeviceAttributeNumberOfXccs = 10018,
	hipDeviceAttributeMaxAvailableVgprsPerThread = 10019,
	hipDeviceAttributePciChipId = 10020,
	hipDeviceAttributeAmdSpecificEnd = 19999,
	hipDeviceAttributeVendorSpecificBegin = 20000,
};
enum hipGraphExecUpdateResult {
	hipGraphExecUpdateSuccess = 0,
	hipGraphExecUpdateError = 1,
	hipGraphExecUpdateErrorTopologyChanged = 2,
	hipGraphExecUpdateErrorNodeTypeChanged = 3,
	hipGraphExecUpdateErrorFunctionChanged = 4,
	hipGraphExecUpdateErrorParametersChanged = 5,
	hipGraphExecUpdateErrorNotSupported = 6,
	hipGraphExecUpdateErrorUnsupportedFunctionChange = 7,
};
enum hipMemLocationType {
	hipMemLocationTypeInvalid = 0,
	hipMemLocationTypeNone = 0,
	hipMemLocationTypeDevice = 1,
	hipMemLocationTypeHost = 2,
	hipMemLocationTypeHostNuma = 3,
	hipMemLocationTypeHostNumaCurrent = 4,
};
enum hipGraphInstantiateFlags {
	hipGraphInstantiateFlagAutoFreeOnLaunch = 1,
	hipGraphInstantiateFlagUpload = 2,
	hipGraphInstantiateFlagDeviceLaunch = 4,
	hipGraphInstantiateFlagUseNodePriority = 8,
};
enum hipPointer_attribute {
	HIP_POINTER_ATTRIBUTE_CONTEXT = 1,
	HIP_POINTER_ATTRIBUTE_MEMORY_TYPE = 2,
	HIP_POINTER_ATTRIBUTE_DEVICE_POINTER = 3,
	HIP_POINTER_ATTRIBUTE_HOST_POINTER = 4,
	HIP_POINTER_ATTRIBUTE_P2P_TOKENS = 5,
	HIP_POINTER_ATTRIBUTE_SYNC_MEMOPS = 6,
	HIP_POINTER_ATTRIBUTE_BUFFER_ID = 7,
	HIP_POINTER_ATTRIBUTE_IS_MANAGED = 8,
	HIP_POINTER_ATTRIBUTE_DEVICE_ORDINAL = 9,
	HIP_POINTER_ATTRIBUTE_IS_LEGACY_HIP_IPC_CAPABLE = 10,
	HIP_POINTER_ATTRIBUTE_RANGE_START_ADDR = 11,
	HIP_POINTER_ATTRIBUTE_RANGE_SIZE = 12,
	HIP_POINTER_ATTRIBUTE_MAPPED = 13,
	HIP_POINTER_ATTRIBUTE_ALLOWED_HANDLE_TYPES = 14,
	HIP_POINTER_ATTRIBUTE_IS_GPU_DIRECT_RDMA_CAPABLE = 15,
	HIP_POINTER_ATTRIBUTE_ACCESS_FLAGS = 16,
	HIP_POINTER_ATTRIBUTE_MEMPOOL_HANDLE = 17,
};
enum hipAccessProperty {
	hipAccessPropertyNormal = 0,
	hipAccessPropertyStreaming = 1,
	hipAccessPropertyPersisting = 2,
};
enum hipMemAccessFlags {
	hipMemAccessFlagsProtNone = 0,
	hipMemAccessFlagsProtRead = 1,
	hipMemAccessFlagsProtReadWrite = 3,
};
enum hipMemoryType {
	hipMemoryTypeUnregistered = 0,
	hipMemoryTypeHost = 1,
	hipMemoryTypeDevice = 2,
	hipMemoryTypeManaged = 3,
	hipMemoryTypeArray = 10,
	hipMemoryTypeUnified = 11,
};
enum hipFuncAttribute {
	hipFuncAttributeMaxDynamicSharedMemorySize = 8,
	hipFuncAttributePreferredSharedMemoryCarveout = 9,
	hipFuncAttributeMax = 10,
};
enum hipMemcpySrcAccessOrder {
	hipMemcpySrcAccessOrderInvalid = 0,
	hipMemcpySrcAccessOrderStream = 1,
	hipMemcpySrcAccessOrderDuringApiCall = 2,
	hipMemcpySrcAccessOrderAny = 3,
	hipMemcpySrcAccessOrderMax = 2147483647,
};
enum hipLibraryPropertyType {
	HIP_LIBRARY_MAJOR_VERSION = 0,
	HIP_LIBRARY_MINOR_VERSION = 1,
	HIP_LIBRARY_PATCH_LEVEL = 2,
};
enum hipMemAllocationHandleType {
	hipMemHandleTypeNone = 0,
	hipMemHandleTypePosixFileDescriptor = 1,
	hipMemHandleTypeWin32 = 2,
	hipMemHandleTypeWin32Kmt = 4,
};
enum hipLaunchAttributeID {
	hipLaunchAttributeAccessPolicyWindow = 1,
	hipLaunchAttributeCooperative = 2,
	hipLaunchAttributeSynchronizationPolicy = 3,
	hipLaunchAttributePriority = 8,
	hipLaunchAttributeMemSyncDomainMap = 9,
	hipLaunchAttributeMemSyncDomain = 10,
	hipLaunchAttributeMax = 11,
};
enum hipExternalSemaphoreHandleType_enum {
	hipExternalSemaphoreHandleTypeOpaqueFd = 1,
	hipExternalSemaphoreHandleTypeOpaqueWin32 = 2,
	hipExternalSemaphoreHandleTypeOpaqueWin32Kmt = 3,
	hipExternalSemaphoreHandleTypeD3D12Fence = 4,
	hipExternalSemaphoreHandleTypeD3D11Fence = 5,
	hipExternalSemaphoreHandleTypeNvSciSync = 6,
	hipExternalSemaphoreHandleTypeKeyedMutex = 7,
	hipExternalSemaphoreHandleTypeKeyedMutexKmt = 8,
	hipExternalSemaphoreHandleTypeTimelineSemaphoreFd = 9,
	hipExternalSemaphoreHandleTypeTimelineSemaphoreWin32 = 10,
};
enum hipLibraryOption_e {
	hipLibraryHostUniversalFunctionAndDataTable = 0,
	hipLibraryBinaryIsPreserved = 1,
};
enum hipMemRangeHandleType {
	hipMemRangeHandleTypeDmaBufFd = 1,
	hipMemRangeHandleTypeMax = 2147483647,
};
enum hipChannelFormatKind {
	hipChannelFormatKindSigned = 0,
	hipChannelFormatKindUnsigned = 1,
	hipChannelFormatKindFloat = 2,
	hipChannelFormatKindNone = 3,
};
enum hipMemRangeCoherencyMode {
	hipMemRangeCoherencyModeFineGrain = 0,
	hipMemRangeCoherencyModeCoarseGrain = 1,
	hipMemRangeCoherencyModeIndeterminate = 2,
};
enum hipGraphDebugDotFlags {
	hipGraphDebugDotFlagsVerbose = 1,
	hipGraphDebugDotFlagsKernelNodeParams = 4,
	hipGraphDebugDotFlagsMemcpyNodeParams = 8,
	hipGraphDebugDotFlagsMemsetNodeParams = 16,
	hipGraphDebugDotFlagsHostNodeParams = 32,
	hipGraphDebugDotFlagsEventNodeParams = 64,
	hipGraphDebugDotFlagsExtSemasSignalNodeParams = 128,
	hipGraphDebugDotFlagsExtSemasWaitNodeParams = 256,
	hipGraphDebugDotFlagsKernelNodeAttributes = 512,
	hipGraphDebugDotFlagsHandles = 1024,
};
enum hipResourceViewFormat {
	hipResViewFormatNone = 0,
	hipResViewFormatUnsignedChar1 = 1,
	hipResViewFormatUnsignedChar2 = 2,
	hipResViewFormatUnsignedChar4 = 3,
	hipResViewFormatSignedChar1 = 4,
	hipResViewFormatSignedChar2 = 5,
	hipResViewFormatSignedChar4 = 6,
	hipResViewFormatUnsignedShort1 = 7,
	hipResViewFormatUnsignedShort2 = 8,
	hipResViewFormatUnsignedShort4 = 9,
	hipResViewFormatSignedShort1 = 10,
	hipResViewFormatSignedShort2 = 11,
	hipResViewFormatSignedShort4 = 12,
	hipResViewFormatUnsignedInt1 = 13,
	hipResViewFormatUnsignedInt2 = 14,
	hipResViewFormatUnsignedInt4 = 15,
	hipResViewFormatSignedInt1 = 16,
	hipResViewFormatSignedInt2 = 17,
	hipResViewFormatSignedInt4 = 18,
	hipResViewFormatHalf1 = 19,
	hipResViewFormatHalf2 = 20,
	hipResViewFormatHalf4 = 21,
	hipResViewFormatFloat1 = 22,
	hipResViewFormatFloat2 = 23,
	hipResViewFormatFloat4 = 24,
	hipResViewFormatUnsignedBlockCompressed1 = 25,
	hipResViewFormatUnsignedBlockCompressed2 = 26,
	hipResViewFormatUnsignedBlockCompressed3 = 27,
	hipResViewFormatUnsignedBlockCompressed4 = 28,
	hipResViewFormatSignedBlockCompressed4 = 29,
	hipResViewFormatUnsignedBlockCompressed5 = 30,
	hipResViewFormatSignedBlockCompressed5 = 31,
	hipResViewFormatUnsignedBlockCompressed6H = 32,
	hipResViewFormatSignedBlockCompressed6H = 33,
	hipResViewFormatUnsignedBlockCompressed7 = 34,
};
enum hipMemAllocationGranularity_flags {
	hipMemAllocationGranularityMinimum = 0,
	hipMemAllocationGranularityRecommended = 1,
};

/* ============================================================================ *
 * Structure Types
 * ============================================================================ */

typedef struct hipMemcpy3DPeerParms hipMemcpy3DPeerParms;
typedef struct HIP_TEXTURE_DESC_st HIP_TEXTURE_DESC;
typedef struct hipBatchMemOpNodeParams hipBatchMemOpNodeParams;
typedef struct hipMipmappedArray hipMipmappedArray;
typedef struct ulong1 ulong1;
typedef struct hipMemcpy3DParms hipMemcpy3DParms;
typedef struct hipMemAllocationProp hipMemAllocationProp;
typedef struct HIP_RESOURCE_DESC_st HIP_RESOURCE_DESC;
typedef struct hipExternalMemoryHandleDesc_st hipExternalMemoryHandleDesc;
typedef struct hipResourceDesc hipResourceDesc;
typedef struct longlong3 longlong3;
typedef struct ulonglong3 ulonglong3;
typedef struct hipFuncAttributes hipFuncAttributes;
typedef struct hipPointerAttribute_t hipPointerAttribute_t;
typedef struct hipIpcMemHandle_st hipIpcMemHandle_t;
typedef struct hipExternalSemaphoreSignalNodeParams hipExternalSemaphoreSignalNodeParams;
typedef struct double4 double4;
typedef struct hipGraphInstantiateParams hipGraphInstantiateParams;
typedef struct ulong4 ulong4;
typedef struct hipMemcpy3DOperand hipMemcpy3DOperand;
typedef struct hipExternalMemoryMipmappedArrayDesc_st hipExternalMemoryMipmappedArrayDesc;
typedef struct double2 double2;
typedef struct hipPitchedPtr hipPitchedPtr;
typedef struct hipLaunchParams_t hipLaunchParams;
typedef struct textureReference textureReference;
typedef struct hipExtent hipExtent;
typedef struct hipChildGraphNodeParams hipChildGraphNodeParams;
typedef struct ushort4 ushort4;
typedef struct hipAccessPolicyWindow hipAccessPolicyWindow;
typedef struct ushort2 ushort2;
typedef struct hipMemLocation hipMemLocation;
typedef struct HIP_LAUNCH_CONFIG_st HIP_LAUNCH_CONFIG;
typedef struct ulonglong4 ulonglong4;
typedef struct short1 short1;
typedef struct ulonglong2 ulonglong2;
typedef struct ulonglong1 ulonglong1;
typedef struct ulong3 ulong3;
typedef struct hipDeviceProp_tR0600 hipDeviceProp_tR0600;
typedef struct ulong2 ulong2;
typedef struct uint4 uint4;
typedef struct float1 float1;
typedef struct uint3 uint3;
typedef struct uint2 uint2;
typedef struct uchar4 uchar4;
typedef struct float2 float2;
typedef struct hipMemPoolPtrExportData hipMemPoolPtrExportData;
typedef struct hipMemcpyNodeParams hipMemcpyNodeParams;
typedef struct hipHostNodeParams hipHostNodeParams;
typedef struct long3 long3;
typedef struct hipExternalSemaphoreSignalParams_st hipExternalSemaphoreSignalParams;
typedef struct int1 int1;
typedef struct hipFunctionLaunchParams_t hipFunctionLaunchParams;
typedef struct hipKernelNodeParams hipKernelNodeParams;
typedef struct short3 short3;
typedef struct long2 long2;
typedef struct longlong2 longlong2;
typedef struct char1 char1;
typedef struct long4 long4;
typedef struct longlong4 longlong4;
typedef struct hipMemcpy3DBatchOp hipMemcpy3DBatchOp;
typedef struct int4 int4;
typedef struct hipExternalSemaphoreWaitNodeParams hipExternalSemaphoreWaitNodeParams;
typedef struct int3 int3;
typedef struct double1 double1;
typedef struct int2 int2;
typedef struct hipGraphEdgeData hipGraphEdgeData;
typedef struct HIP_ARRAY3D_DESCRIPTOR HIP_ARRAY3D_DESCRIPTOR;
typedef struct uchar2 uchar2;
typedef struct hip_Memcpy2D hip_Memcpy2D;
typedef struct hipUUID_t hipUUID;
typedef struct hipMemcpyAttributes hipMemcpyAttributes;
typedef struct hipChannelFormatDesc hipChannelFormatDesc;
typedef struct hipOffset3D hipOffset3D;
typedef struct hipTextureDesc hipTextureDesc;
typedef struct short2 short2;
typedef struct hipDeviceArch_t hipDeviceArch_t;
typedef struct hipMemsetParams hipMemsetParams;
typedef struct _hipGraphicsResource hipGraphicsResource;
typedef union hipStreamBatchMemOpParams_union hipStreamBatchMemOpParams;
typedef struct hipLaunchMemSyncDomainMap hipLaunchMemSyncDomainMap;
typedef struct HIP_RESOURCE_VIEW_DESC_st HIP_RESOURCE_VIEW_DESC;
typedef struct hipIpcEventHandle_st hipIpcEventHandle_t;
typedef struct uchar3 uchar3;
typedef struct long1 long1;
typedef struct char3 char3;
typedef struct char2 char2;
typedef struct hipExternalMemoryBufferDesc_st hipExternalMemoryBufferDesc;
typedef struct uint1 uint1;
typedef struct hipEventWaitNodeParams hipEventWaitNodeParams;
typedef struct char4 char4;
typedef struct hipMemPoolProps hipMemPoolProps;
typedef struct hipArrayMapInfo hipArrayMapInfo;
typedef struct longlong1 longlong1;
typedef struct ushort1 ushort1;
typedef struct HIP_MEMCPY3D HIP_MEMCPY3D;
typedef union hipLaunchAttributeValue hipLaunchAttributeValue;
typedef struct hipMemFreeNodeParams hipMemFreeNodeParams;
typedef struct uchar1 uchar1;
typedef struct hipGraphNodeParams hipGraphNodeParams;
typedef struct hipLaunchAttribute_st hipLaunchAttribute;
typedef struct hipMemAllocNodeParams hipMemAllocNodeParams;
typedef struct hipExternalSemaphoreHandleDesc_st hipExternalSemaphoreHandleDesc;
typedef struct double3 double3;
typedef struct hipMemAccessDesc hipMemAccessDesc;
typedef struct float4 float4;
typedef struct hipExternalSemaphoreWaitParams_st hipExternalSemaphoreWaitParams;
typedef struct ushort3 ushort3;
typedef struct HIP_ARRAY_DESCRIPTOR HIP_ARRAY_DESCRIPTOR;
typedef struct hipLaunchConfig_st hipLaunchConfig_t;
typedef struct short4 short4;
typedef struct hipPos hipPos;
typedef struct hipEventRecordNodeParams hipEventRecordNodeParams;
typedef struct dim3 dim3;
typedef struct float3 float3;

/* ============================================================================ *
 * Opaque Types
 * ============================================================================ */

typedef struct hipMipmappedArray *hipMipmappedArray_t;
typedef struct hipGraphNode *hipGraphNode_t;
typedef struct ihipLibrary_t *hipLibrary_t;
typedef struct ihipLinkState_t *hipLinkState_t;
typedef struct ihipMemGenericAllocationHandle *hipMemGenericAllocationHandle_t;
typedef struct ihipKernel_t *hipKernel_t;
typedef struct ihipStream_t *hipStream_t;
typedef struct hipUserObject *hipUserObject_t;
typedef struct __hip_texture *hipTextureObject_t;
typedef struct ihipModule_t *hipModule_t;
typedef struct hipArray *hipArray_t;
typedef const struct hipMipmappedArray *hipMipmappedArray_const_t;
typedef struct ihipEvent_t *hipEvent_t;
typedef struct __hip_surface *hipSurfaceObject_t;
typedef struct ihipMemPoolHandle_t *hipMemPool_t;
typedef struct hipGraphExec *hipGraphExec_t;
typedef const struct hipArray *hipArray_const_t;
typedef struct ihipModuleSymbol_t *hipFunction_t;
typedef struct ihipGraph *hipGraph_t;
typedef struct ihipCtx_t *hipCtx_t;

/* ============================================================================ *
 * Basic Types
 * ============================================================================ */

typedef hipMipmappedArray_t hipmipmappedArray;
typedef hipDeviceProp_tR0600 hipDeviceProp_t;
typedef void *hipExternalMemory_t;
typedef void (*hipHostFn_t)(void *);
typedef void (*hipStreamCallback_t)(hipStream_t, hipError_t, void *);
typedef void *hipDeviceptr_t;
typedef int hipDevice_t;
typedef void *hipExternalSemaphore_t;
typedef hipGraphicsResource *hipGraphicsResource_t;

/* ============================================================================ *
 * Structure Definitions
 * ============================================================================ */

struct hipPitchedPtr {
    void *ptr;
    size_t pitch;
    size_t xsize;
    size_t ysize;
};

struct hipExtent {
    size_t width;
    size_t height;
    size_t depth;
};

struct hipArray;

struct hipPos {
    size_t x;
    size_t y;
    size_t z;
};

struct hipMemcpy3DPeerParms {
    hipArray_t srcArray;
    hipPos srcPos;
    hipPitchedPtr srcPtr;
    int srcDevice;
    hipArray_t dstArray;
    hipPos dstPos;
    hipPitchedPtr dstPtr;
    int dstDevice;
    hipExtent extent;
};

struct int4 {
    int x;
    int y;
    int z;
    int w;
};

struct __hip_surface;

struct ihipCtx_t;

struct hipBatchMemOpNodeParams {
    hipCtx_t ctx;
    unsigned int count;
    hipStreamBatchMemOpParams *paramArray;
    unsigned int flags;
};

struct ihipMemGenericAllocationHandle;

struct ulong1 {
    unsigned long x;
};

struct uint3 {
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

struct ihipStream_t;

struct ihipModuleSymbol_t;

struct hipFunctionLaunchParams_t {
    hipFunction_t function;
    unsigned int gridDimX;
    unsigned int gridDimY;
    unsigned int gridDimZ;
    unsigned int blockDimX;
    unsigned int blockDimY;
    unsigned int blockDimZ;
    unsigned int sharedMemBytes;
    hipStream_t hStream;
    void **kernelParams;
};

struct hipChannelFormatDesc {
    int x;
    int y;
    int z;
    int w;
    enum hipChannelFormatKind f;
};

struct hipMipmappedArray {
    void *data;
    struct hipChannelFormatDesc desc;
    unsigned int type;
    unsigned int width;
    unsigned int height;
    unsigned int depth;
    unsigned int min_mipmap_level;
    unsigned int max_mipmap_level;
    unsigned int flags;
    enum hipArray_Format format;
    unsigned int num_channels;
};

struct hipMemcpy3DParms {
    hipArray_t srcArray;
    struct hipPos srcPos;
    struct hipPitchedPtr srcPtr;
    hipArray_t dstArray;
    struct hipPos dstPos;
    struct hipPitchedPtr dstPtr;
    struct hipExtent extent;
    enum hipMemcpyKind kind;
};

struct hipMemLocation {
    hipMemLocationType type;
    int id;
};

struct hipMemAllocationProp {
    hipMemAllocationType type;
    union {
        hipMemAllocationHandleType requestedHandleType;
        hipMemAllocationHandleType requestedHandleTypes;
    } ;
    hipMemLocation location;
    void *win32HandleMetaData;
    struct {
        unsigned char compressionType;
        unsigned char gpuDirectRDMACapable;
        unsigned short usage;
    } allocFlags;
};

struct hipResourceDesc {
    enum hipResourceType resType;
    union {
        struct {
            hipArray_t array;
        } array;
        struct {
            hipMipmappedArray_t mipmap;
        } mipmap;
        struct {
            void *devPtr;
            struct hipChannelFormatDesc desc;
            size_t sizeInBytes;
        } linear;
        struct {
            void *devPtr;
            struct hipChannelFormatDesc desc;
            size_t width;
            size_t height;
            size_t pitchInBytes;
        } pitch2D;
    } res;
};

struct longlong3 {
    long long x;
    long long y;
    long long z;
};

struct ulonglong3 {
    unsigned long long x;
    unsigned long long y;
    unsigned long long z;
};

struct hipFuncAttributes {
    int binaryVersion;
    int cacheModeCA;
    size_t constSizeBytes;
    size_t localSizeBytes;
    int maxDynamicSharedSizeBytes;
    int maxThreadsPerBlock;
    int numRegs;
    int preferredShmemCarveout;
    int ptxVersion;
    size_t sharedSizeBytes;
};

struct hipPointerAttribute_t {
    enum hipMemoryType type;
    int device;
    void *devicePointer;
    void *hostPointer;
    int isManaged;
    unsigned int allocationFlags;
};

struct hipResourceViewDesc {
    enum hipResourceViewFormat format;
    size_t width;
    size_t height;
    size_t depth;
    unsigned int firstMipmapLevel;
    unsigned int lastMipmapLevel;
    unsigned int firstLayer;
    unsigned int lastLayer;
};

struct hipAccessPolicyWindow {
    void *base_ptr;
    hipAccessProperty hitProp;
    float hitRatio;
    hipAccessProperty missProp;
    size_t num_bytes;
};

struct hipLaunchMemSyncDomainMap {
    unsigned char default_;
    unsigned char remote;
};

union hipLaunchAttributeValue {
    char pad[64];
    hipAccessPolicyWindow accessPolicyWindow;
    int cooperative;
    int priority;
    hipSynchronizationPolicy syncPolicy;
    hipLaunchMemSyncDomainMap memSyncDomainMap;
    hipLaunchMemSyncDomain memSyncDomain;
};

struct hipLaunchAttribute_st {
    hipLaunchAttributeID id;
    char pad[4];
    union {
        hipLaunchAttributeValue val;
        hipLaunchAttributeValue value;
    } ;
};

struct hipExternalMemoryMipmappedArrayDesc_st {
    unsigned long long offset;
    hipChannelFormatDesc formatDesc;
    hipExtent extent;
    unsigned int flags;
    unsigned int numLevels;
};

struct hipExternalSemaphoreSignalNodeParams {
    hipExternalSemaphore_t *extSemArray;
    const hipExternalSemaphoreSignalParams *paramsArray;
    unsigned int numExtSems;
};

struct double4 {
    double x;
    double y;
    double z;
    double w;
};

struct hipGraphNode;

struct hipGraphInstantiateParams {
    hipGraphNode_t errNode_out;
    unsigned long long flags;
    hipGraphInstantiateResult result_out;
    hipStream_t uploadStream;
};

struct long4 {
    long x;
    long y;
    long z;
    long w;
};

struct hipGraphExec;

struct hipStreamMemOpFlushRemoteWritesParams_t {
    hipStreamBatchMemOpType operation;
    unsigned int flags;
};

struct hipExternalMemoryHandleDesc_st {
    hipExternalMemoryHandleType type;
    union {
        int fd;
        struct {
            void *handle;
            const void *name;
        } win32;
        const void *nvSciBufObject;
    } handle;
    unsigned long long size;
    unsigned int flags;
    unsigned int reserved[16];
};

struct _hipGraphicsResource;

struct hipOffset3D {
    size_t x;
    size_t y;
    size_t z;
};

struct hipMemcpy3DOperand {
    hipMemcpy3DOperandType type;
    union {
        struct {
            void *ptr;
            size_t rowLength;
            size_t layerHeight;
            hipMemLocation locHint;
        } ptr;
        struct {
            hipArray_t array;
            hipOffset3D offset;
        } array;
    } op;
};

struct double2 {
    double x;
    double y;
};

struct ihipKernel_t;

struct HIP_RESOURCE_VIEW_DESC_st {
    HIPresourceViewFormat format;
    size_t width;
    size_t height;
    size_t depth;
    unsigned int firstMipmapLevel;
    unsigned int lastMipmapLevel;
    unsigned int firstLayer;
    unsigned int lastLayer;
    unsigned int reserved[16];
};

struct dim3 {
    uint32_t x;
    uint32_t y;
    uint32_t z;
};

struct hipKernelNodeParams {
    dim3 blockDim;
    void **extra;
    void *func;
    dim3 gridDim;
    void **kernelParams;
    unsigned int sharedMemBytes;
};

struct ihipModule_t;

struct hipLaunchConfig_st {
    dim3 gridDim;
    dim3 blockDim;
    size_t dynamicSmemBytes;
    hipStream_t stream;
    hipLaunchAttribute *attrs;
    unsigned int numAttrs;
};

struct ihipGraph;

struct hipChildGraphNodeParams {
    hipGraph_t graph;
};

struct hipMemAccessDesc {
    hipMemLocation location;
    hipMemAccessFlags flags;
};

struct HIP_LAUNCH_CONFIG_st {
    unsigned int gridDimX;
    unsigned int gridDimY;
    unsigned int gridDimZ;
    unsigned int blockDimX;
    unsigned int blockDimY;
    unsigned int blockDimZ;
    unsigned int sharedMemBytes;
    hipStream_t hStream;
    hipLaunchAttribute *attrs;
    unsigned int numAttrs;
};

struct hipMemPoolProps {
    hipMemAllocationType allocType;
    hipMemAllocationHandleType handleTypes;
    hipMemLocation location;
    void *win32SecurityAttributes;
    size_t maxSize;
    unsigned char reserved[56];
};

struct longlong2 {
    long long x;
    long long y;
};

struct hipStreamMemOpMemoryBarrierParams_t {
    hipStreamBatchMemOpType operation;
    unsigned int flags;
};

struct hipExternalSemaphoreWaitParams_st {
    struct {
        struct {
            unsigned long long value;
        } fence;
        union {
            void *fence;
            unsigned long long reserved;
        } nvSciSync;
        struct {
            unsigned long long key;
            unsigned int timeoutMs;
        } keyedMutex;
        unsigned int reserved[10];
    } params;
    unsigned int flags;
    unsigned int reserved[16];
};

struct short1 {
    short x;
};

struct hipDeviceArch_t {
    unsigned int hasGlobalInt32Atomics;
    unsigned int hasGlobalFloatAtomicExch;
    unsigned int hasSharedInt32Atomics;
    unsigned int hasSharedFloatAtomicExch;
    unsigned int hasFloatAtomicAdd;
    unsigned int hasGlobalInt64Atomics;
    unsigned int hasSharedInt64Atomics;
    unsigned int hasDoubles;
    unsigned int hasWarpVote;
    unsigned int hasWarpBallot;
    unsigned int hasWarpShuffle;
    unsigned int hasFunnelShift;
    unsigned int hasThreadFenceSystem;
    unsigned int hasSyncThreadsExt;
    unsigned int hasSurfaceFuncs;
    unsigned int has3dGrid;
    unsigned int hasDynamicParallelism;
};

struct hipUUID_t {
    char bytes[16];
};

struct hipDeviceProp_tR0600 {
    char name[256];
    hipUUID uuid;
    char luid[8];
    unsigned int luidDeviceNodeMask;
    size_t totalGlobalMem;
    size_t sharedMemPerBlock;
    int regsPerBlock;
    int warpSize;
    size_t memPitch;
    int maxThreadsPerBlock;
    int maxThreadsDim[3];
    int maxGridSize[3];
    int clockRate;
    size_t totalConstMem;
    int major;
    int minor;
    size_t textureAlignment;
    size_t texturePitchAlignment;
    int deviceOverlap;
    int multiProcessorCount;
    int kernelExecTimeoutEnabled;
    int integrated;
    int canMapHostMemory;
    int computeMode;
    int maxTexture1D;
    int maxTexture1DMipmap;
    int maxTexture1DLinear;
    int maxTexture2D[2];
    int maxTexture2DMipmap[2];
    int maxTexture2DLinear[3];
    int maxTexture2DGather[2];
    int maxTexture3D[3];
    int maxTexture3DAlt[3];
    int maxTextureCubemap;
    int maxTexture1DLayered[2];
    int maxTexture2DLayered[3];
    int maxTextureCubemapLayered[2];
    int maxSurface1D;
    int maxSurface2D[2];
    int maxSurface3D[3];
    int maxSurface1DLayered[2];
    int maxSurface2DLayered[3];
    int maxSurfaceCubemap;
    int maxSurfaceCubemapLayered[2];
    size_t surfaceAlignment;
    int concurrentKernels;
    int ECCEnabled;
    int pciBusID;
    int pciDeviceID;
    int pciDomainID;
    int tccDriver;
    int asyncEngineCount;
    int unifiedAddressing;
    int memoryClockRate;
    int memoryBusWidth;
    int l2CacheSize;
    int persistingL2CacheMaxSize;
    int maxThreadsPerMultiProcessor;
    int streamPrioritiesSupported;
    int globalL1CacheSupported;
    int localL1CacheSupported;
    size_t sharedMemPerMultiprocessor;
    int regsPerMultiprocessor;
    int managedMemory;
    int isMultiGpuBoard;
    int multiGpuBoardGroupID;
    int hostNativeAtomicSupported;
    int singleToDoublePrecisionPerfRatio;
    int pageableMemoryAccess;
    int concurrentManagedAccess;
    int computePreemptionSupported;
    int canUseHostPointerForRegisteredMem;
    int cooperativeLaunch;
    int cooperativeMultiDeviceLaunch;
    size_t sharedMemPerBlockOptin;
    int pageableMemoryAccessUsesHostPageTables;
    int directManagedMemAccessFromHost;
    int maxBlocksPerMultiProcessor;
    int accessPolicyMaxWindowSize;
    size_t reservedSharedMemPerBlock;
    int hostRegisterSupported;
    int sparseHipArraySupported;
    int hostRegisterReadOnlySupported;
    int timelineSemaphoreInteropSupported;
    int memoryPoolsSupported;
    int gpuDirectRDMASupported;
    unsigned int gpuDirectRDMAFlushWritesOptions;
    int gpuDirectRDMAWritesOrdering;
    unsigned int memoryPoolSupportedHandleTypes;
    int deferredMappingHipArraySupported;
    int ipcEventSupported;
    int clusterLaunch;
    int unifiedFunctionPointers;
    int reserved[63];
    int hipReserved[32];
    char gcnArchName[256];
    size_t maxSharedMemoryPerMultiProcessor;
    int clockInstructionRate;
    hipDeviceArch_t arch;
    unsigned int *hdpMemFlushCntl;
    unsigned int *hdpRegFlushCntl;
    int cooperativeMultiDeviceUnmatchedFunc;
    int cooperativeMultiDeviceUnmatchedGridDim;
    int cooperativeMultiDeviceUnmatchedBlockDim;
    int cooperativeMultiDeviceUnmatchedSharedMem;
    int isLargeBar;
    int asicRevision;
};

struct float1 {
    float x;
};

struct ihipLibrary_t;

struct surfaceReference {
    hipSurfaceObject_t surfaceObject;
};

struct hipExternalMemoryBufferDesc_st {
    unsigned long long offset;
    unsigned long long size;
    unsigned int flags;
    unsigned int reserved[16];
};

struct float2 {
    float x;
    float y;
};

struct hipMemPoolPtrExportData {
    unsigned char reserved[64];
};

struct ihipLinkState_t;

struct char3 {
    char x;
    char y;
    char z;
};

struct long3 {
    long x;
    long y;
    long z;
};

struct __hip_texture;

struct hipTextureDesc {
    enum hipTextureAddressMode addressMode[3];
    enum hipTextureFilterMode filterMode;
    enum hipTextureReadMode readMode;
    int sRGB;
    float borderColor[4];
    int normalizedCoords;
    unsigned int maxAnisotropy;
    enum hipTextureFilterMode mipmapFilterMode;
    float mipmapLevelBias;
    float minMipmapLevelClamp;
    float maxMipmapLevelClamp;
};

struct HIP_TEXTURE_DESC_st {
    HIPaddress_mode addressMode[3];
    HIPfilter_mode filterMode;
    unsigned int flags;
    unsigned int maxAnisotropy;
    HIPfilter_mode mipmapFilterMode;
    float mipmapLevelBias;
    float minMipmapLevelClamp;
    float maxMipmapLevelClamp;
    float borderColor[4];
    int reserved[12];
};

struct char1 {
    char x;
};

struct longlong4 {
    long long x;
    long long y;
    long long z;
    long long w;
};

struct hipExternalSemaphoreWaitNodeParams {
    hipExternalSemaphore_t *extSemArray;
    const hipExternalSemaphoreWaitParams *paramsArray;
    unsigned int numExtSems;
};

struct double1 {
    double x;
};

struct hipGraphEdgeData {
    unsigned char from_port;
    unsigned char reserved[5];
    unsigned char to_port;
    unsigned char type;
};

struct HIP_ARRAY3D_DESCRIPTOR {
    size_t Width;
    size_t Height;
    size_t Depth;
    enum hipArray_Format Format;
    unsigned int NumChannels;
    unsigned int Flags;
};

struct uchar2 {
    unsigned char x;
    unsigned char y;
};

struct ushort4 {
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned short w;
};

struct ushort2 {
    unsigned short x;
    unsigned short y;
};

struct ulonglong2 {
    unsigned long long x;
    unsigned long long y;
};

struct hipMemcpyAttributes {
    hipMemcpySrcAccessOrder srcAccessOrder;
    hipMemLocation srcLocHint;
    hipMemLocation dstLocHint;
    unsigned int flags;
};

struct short2 {
    short x;
    short y;
};

struct hipMemcpy3DBatchOp {
    hipMemcpy3DOperand src;
    hipMemcpy3DOperand dst;
    hipExtent extent;
    hipMemcpySrcAccessOrder srcAccessOrder;
    unsigned int flags;
};

struct hipLaunchParams_t {
    void *func;
    dim3 gridDim;
    dim3 blockDim;
    void **args;
    size_t sharedMem;
    hipStream_t stream;
};

struct float4 {
    float x;
    float y;
    float z;
    float w;
};

struct hipMemsetParams {
    void *dst;
    unsigned int elementSize;
    size_t height;
    size_t pitch;
    unsigned int value;
    size_t width;
};

struct ulonglong4 {
    unsigned long long x;
    unsigned long long y;
    unsigned long long z;
    unsigned long long w;
};

struct hipMemFreeNodeParams {
    void *dptr;
};

struct ihipEvent_t;

struct hipEventRecordNodeParams {
    hipEvent_t event;
};

struct hipMemcpyNodeParams {
    int flags;
    int reserved[3];
    hipMemcpy3DParms copyParams;
};

struct hipEventWaitNodeParams {
    hipEvent_t event;
};

struct hipMemAllocNodeParams {
    hipMemPoolProps poolProps;
    const hipMemAccessDesc *accessDescs;
    size_t accessDescCount;
    size_t bytesize;
    void *dptr;
};

struct hipHostNodeParams {
    hipHostFn_t fn;
    void *userData;
};

struct ihipMemPoolHandle_t;

struct ulong4 {
    unsigned long x;
    unsigned long y;
    unsigned long z;
    unsigned long w;
};

struct ulonglong1 {
    unsigned long long x;
};

struct ulong3 {
    unsigned long x;
    unsigned long y;
    unsigned long z;
};

struct ulong2 {
    unsigned long x;
    unsigned long y;
};

struct uint4 {
    unsigned int x;
    unsigned int y;
    unsigned int z;
    unsigned int w;
};

struct uint2 {
    unsigned int x;
    unsigned int y;
};

struct uchar4 {
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char w;
};

struct hipStreamMemOpWriteValueParams_t {
    hipStreamBatchMemOpType operation;
    hipDeviceptr_t address;
    union {
        uint32_t value;
        uint64_t value64;
    } ;
    unsigned int flags;
    hipDeviceptr_t alias;
};

struct hipStreamMemOpWaitValueParams_t {
    hipStreamBatchMemOpType operation;
    hipDeviceptr_t address;
    union {
        uint32_t value;
        uint64_t value64;
    } ;
    unsigned int flags;
    hipDeviceptr_t alias;
};

union hipStreamBatchMemOpParams_union {
    hipStreamBatchMemOpType operation;
    struct hipStreamMemOpWaitValueParams_t waitValue;
    struct hipStreamMemOpWriteValueParams_t writeValue;
    struct hipStreamMemOpFlushRemoteWritesParams_t flushRemoteWrites;
    struct hipStreamMemOpMemoryBarrierParams_t memoryBarrier;
    uint64_t pad[6];
};

struct uchar1 {
    unsigned char x;
};

struct uchar3 {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

struct textureReference {
    int normalized;
    enum hipTextureReadMode readMode;
    enum hipTextureFilterMode filterMode;
    enum hipTextureAddressMode addressMode[3];
    struct hipChannelFormatDesc channelDesc;
    int sRGB;
    unsigned int maxAnisotropy;
    enum hipTextureFilterMode mipmapFilterMode;
    float mipmapLevelBias;
    float minMipmapLevelClamp;
    float maxMipmapLevelClamp;
    hipTextureObject_t textureObject;
    int numChannels;
    enum hipArray_Format format;
};

struct long1 {
    long x;
};

struct hipIpcMemHandle_st {
    char reserved[64];
};

struct char2 {
    char x;
    char y;
};

struct uint1 {
    unsigned int x;
};

struct char4 {
    char x;
    char y;
    char z;
    char w;
};

struct hipArrayMapInfo {
    hipResourceType resourceType;
    union {
        hipMipmappedArray mipmap;
        hipArray_t array;
    } resource;
    hipArraySparseSubresourceType subresourceType;
    union {
        struct {
            unsigned int level;
            unsigned int layer;
            unsigned int offsetX;
            unsigned int offsetY;
            unsigned int offsetZ;
            unsigned int extentWidth;
            unsigned int extentHeight;
            unsigned int extentDepth;
        } sparseLevel;
        struct {
            unsigned int layer;
            unsigned long long offset;
            unsigned long long size;
        } miptail;
    } subresource;
    hipMemOperationType memOperationType;
    hipMemHandleType memHandleType;
    union {
        hipMemGenericAllocationHandle_t memHandle;
    } memHandle;
    unsigned long long offset;
    unsigned int deviceBitMask;
    unsigned int flags;
    unsigned int reserved[2];
};

struct longlong1 {
    long long x;
};

struct ushort1 {
    unsigned short x;
};

struct HIP_MEMCPY3D {
    size_t srcXInBytes;
    size_t srcY;
    size_t srcZ;
    size_t srcLOD;
    hipMemoryType srcMemoryType;
    const void *srcHost;
    hipDeviceptr_t srcDevice;
    hipArray_t srcArray;
    size_t srcPitch;
    size_t srcHeight;
    size_t dstXInBytes;
    size_t dstY;
    size_t dstZ;
    size_t dstLOD;
    hipMemoryType dstMemoryType;
    void *dstHost;
    hipDeviceptr_t dstDevice;
    hipArray_t dstArray;
    size_t dstPitch;
    size_t dstHeight;
    size_t WidthInBytes;
    size_t Height;
    size_t Depth;
};

struct hip_Memcpy2D {
    size_t srcXInBytes;
    size_t srcY;
    hipMemoryType srcMemoryType;
    const void *srcHost;
    hipDeviceptr_t srcDevice;
    hipArray_t srcArray;
    size_t srcPitch;
    size_t dstXInBytes;
    size_t dstY;
    hipMemoryType dstMemoryType;
    void *dstHost;
    hipDeviceptr_t dstDevice;
    hipArray_t dstArray;
    size_t dstPitch;
    size_t WidthInBytes;
    size_t Height;
};

struct hipIpcEventHandle_st {
    char reserved[64];
};

struct hipGraphNodeParams {
    hipGraphNodeType type;
    int reserved0[3];
    union {
        long long reserved1[29];
        hipKernelNodeParams kernel;
        hipMemcpyNodeParams memcpy;
        hipMemsetParams memset;
        hipHostNodeParams host;
        hipChildGraphNodeParams graph;
        hipEventWaitNodeParams eventWait;
        hipEventRecordNodeParams eventRecord;
        hipExternalSemaphoreSignalNodeParams extSemSignal;
        hipExternalSemaphoreWaitNodeParams extSemWait;
        hipMemAllocNodeParams alloc;
        hipMemFreeNodeParams free;
    } ;
    long long reserved2;
};

struct hipUserObject;

struct double3 {
    double x;
    double y;
    double z;
};

struct int1 {
    int x;
};

struct ushort3 {
    unsigned short x;
    unsigned short y;
    unsigned short z;
};

struct HIP_ARRAY_DESCRIPTOR {
    size_t Width;
    size_t Height;
    enum hipArray_Format Format;
    unsigned int NumChannels;
};

struct float3 {
    float x;
    float y;
    float z;
};

struct short3 {
    short x;
    short y;
    short z;
};

struct short4 {
    short x;
    short y;
    short z;
    short w;
};

struct long2 {
    long x;
    long y;
};

struct int3 {
    int x;
    int y;
    int z;
};

struct int2 {
    int x;
    int y;
};

struct hipExternalSemaphoreHandleDesc_st {
    hipExternalSemaphoreHandleType type;
    union {
        int fd;
        struct {
            void *handle;
            const void *name;
        } win32;
        const void *NvSciSyncObj;
    } handle;
    unsigned int flags;
    unsigned int reserved[16];
};

struct hipExternalSemaphoreSignalParams_st {
    struct {
        struct {
            unsigned long long value;
        } fence;
        union {
            void *fence;
            unsigned long long reserved;
        } nvSciSync;
        struct {
            unsigned long long key;
        } keyedMutex;
        unsigned int reserved[12];
    } params;
    unsigned int flags;
    unsigned int reserved[16];
};

struct HIP_RESOURCE_DESC_st {
    HIPresourcetype resType;
    union {
        struct {
            hipArray_t hArray;
        } array;
        struct {
            hipMipmappedArray_t hMipmappedArray;
        } mipmap;
        struct {
            hipDeviceptr_t devPtr;
            hipArray_Format format;
            unsigned int numChannels;
            size_t sizeInBytes;
        } linear;
        struct {
            hipDeviceptr_t devPtr;
            hipArray_Format format;
            unsigned int numChannels;
            size_t width;
            size_t height;
            size_t pitchInBytes;
        } pitch2D;
        struct {
            int reserved[32];
        } reserved;
    } res;
    unsigned int flags;
};


#endif /* HIP_MINIMAL_ABI_H_ */
