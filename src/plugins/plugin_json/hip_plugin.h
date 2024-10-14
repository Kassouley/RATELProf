/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#ifndef HIP_PLUGIN_H 
#define HIP_PLUGIN_H 

#include "ratelprof_buffer_manager.h"

void on_enter_hip_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity);
void on_exit_hip_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity);
void process_hip_args_for(hip_api_id_t funid, const hip_api_args_t* args, ratelprof_buffer_t* buf);

//	textureReference* texRef (unknown);
//	enum hipTextureFilterMode fm (enum);
#define PROCESS_ARGS_hipTexRefSetMipmapFilterMode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefSetMipmapFilterMode.retval); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"fm\":{\"type\":\"enum hipTextureFilterMode\",\"value\":\"%d\"}", args->hipTexRefSetMipmapFilterMode.fm); \
};

//	hipArray_t dstArray (unknown);
//	size_t dstOffset (unsigned long);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemcpyHtoA(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyHtoA.retval); \
	ratelprof_add_to_buffer(buf, "\"dstArray\":{\"type\":\"hipArray_t\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"dstOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyHtoA.dstOffset); \
	ratelprof_add_to_buffer(buf, "\"srcHost\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpyHtoA.srcHost); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemcpyHtoA.count); \
};

//	hipCtx_t ctx (opaque);
#define PROCESS_ARGS_hipCtxGetApiVersion(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxGetApiVersion.retval); \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t\",\"value\":\"%p\"},", args->hipCtxGetApiVersion.ctx); \
	ratelprof_add_to_buffer(buf, "\"apiVersion\":{\"type\":\"int *\",\"value\":\"%p\"}", args->hipCtxGetApiVersion.apiVersion); \
};

//	int len (int);
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceGetName(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceGetName.retval); \
	ratelprof_add_to_buffer(buf, "\"name\":{\"type\":\"char *\",\"value\":\"%p\"},", args->hipDeviceGetName.name); \
	ratelprof_add_to_buffer(buf, "\"len\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceGetName.len); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipDeviceGetName.device); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipStreamIsCapturing(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamIsCapturing.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamIsCapturing.stream); \
	ratelprof_add_to_buffer(buf, "\"pCaptureStatus\":{\"type\":\"hipStreamCaptureStatus *\",\"value\":\"%p\"}", args->hipStreamIsCapturing.pCaptureStatus); \
};

//	hipStream_t stream (opaque);
//	size_t length (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamAttachMemAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamAttachMemAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamAttachMemAsync.stream); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipStreamAttachMemAsync.dev_ptr); \
	ratelprof_add_to_buffer(buf, "\"length\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipStreamAttachMemAsync.length); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipStreamAttachMemAsync.flags); \
};

//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipFreeArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipFreeArray.retval); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t\",\"value\":\"N/A\"},"); \
};

//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipSetDeviceFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipSetDeviceFlags.retval); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipSetDeviceFlags.flags); \
};

//	hipIpcEventHandle_t handle ({
//		char[64] reserved (string);
//	});
#define PROCESS_ARGS_hipIpcOpenEventHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipIpcOpenEventHandle.retval); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t *\",\"value\":\"%p\"},", args->hipIpcOpenEventHandle.event); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"struct hipIpcEventHandle_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"char[64]\",\"value\":\"%s\"}", args->hipIpcOpenEventHandle.handle.reserved[0]); \
	ratelprof_add_to_buffer(buf, "}}"); \
};


#define PROCESS_ARGS_hipModuleLoad(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipModuleLoad.retval); \
	ratelprof_add_to_buffer(buf, "\"module\":{\"type\":\"hipModule_t *\",\"value\":\"%p\"},", args->hipModuleLoad.module); \
	ratelprof_add_to_buffer(buf, "\"fname\":{\"type\":\"const char *\",\"value\":\"%p\"}", args->hipModuleLoad.fname); \
};


#define PROCESS_ARGS_hipExternalMemoryGetMappedBuffer(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipExternalMemoryGetMappedBuffer.retval); \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipExternalMemoryGetMappedBuffer.devPtr); \
	ratelprof_add_to_buffer(buf, "\"extMem\":{\"type\":\"hipExternalMemory_t\",\"value\":\"%p\"},", args->hipExternalMemoryGetMappedBuffer.extMem); \
	ratelprof_add_to_buffer(buf, "\"bufferDesc\":{\"type\":\"const hipExternalMemoryBufferDesc *\",\"value\":\"%p\"}", args->hipExternalMemoryGetMappedBuffer.bufferDesc); \
};

//	hipMemAllocationHandleType shHandleType (enum);
#define PROCESS_ARGS_hipMemImportFromShareableHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemImportFromShareableHandle.retval); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipMemGenericAllocationHandle_t *\",\"value\":\"%p\"},", args->hipMemImportFromShareableHandle.handle); \
	ratelprof_add_to_buffer(buf, "\"osHandle\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemImportFromShareableHandle.osHandle); \
	ratelprof_add_to_buffer(buf, "\"shHandleType\":{\"type\":\"hipMemAllocationHandleType\",\"value\":\"%d\"}", args->hipMemImportFromShareableHandle.shHandleType); \
};

//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemcpyDtoH(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyDtoH.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpyDtoH.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipMemcpyDtoH.src); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemcpyDtoH.sizeBytes); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipStreamEndCapture(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamEndCapture.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamEndCapture.stream); \
	ratelprof_add_to_buffer(buf, "\"pGraph\":{\"type\":\"hipGraph_t *\",\"value\":\"%p\"}", args->hipStreamEndCapture.pGraph); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphMemFreeNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphMemFreeNodeGetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphMemFreeNodeGetParams.node); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipGraphMemFreeNodeGetParams.dev_ptr); \
};


#define PROCESS_ARGS_hipThreadExchangeStreamCaptureMode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipThreadExchangeStreamCaptureMode.retval); \
	ratelprof_add_to_buffer(buf, "\"mode\":{\"type\":\"hipStreamCaptureMode *\",\"value\":\"%p\"}", args->hipThreadExchangeStreamCaptureMode.mode); \
};

//	hipModule_t module (opaque);
#define PROCESS_ARGS_hipModuleUnload(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipModuleUnload.retval); \
	ratelprof_add_to_buffer(buf, "\"module\":{\"type\":\"hipModule_t\",\"value\":\"%p\"}", args->hipModuleUnload.module); \
};

//	hipFunction_t f (opaque);
//	size_t dynSharedMemPerBlk (unsigned long);
//	int blockSizeLimit (int);
#define PROCESS_ARGS_hipModuleOccupancyMaxPotentialBlockSize(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipModuleOccupancyMaxPotentialBlockSize.retval); \
	ratelprof_add_to_buffer(buf, "\"gridSize\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipModuleOccupancyMaxPotentialBlockSize.gridSize); \
	ratelprof_add_to_buffer(buf, "\"blockSize\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipModuleOccupancyMaxPotentialBlockSize.blockSize); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"hipFunction_t\",\"value\":\"%p\"},", args->hipModuleOccupancyMaxPotentialBlockSize.f); \
	ratelprof_add_to_buffer(buf, "\"dynSharedMemPerBlk\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipModuleOccupancyMaxPotentialBlockSize.dynSharedMemPerBlk); \
	ratelprof_add_to_buffer(buf, "\"blockSizeLimit\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipModuleOccupancyMaxPotentialBlockSize.blockSizeLimit); \
};

//	const hip_Memcpy2D * pCopy (unknown);
#define PROCESS_ARGS_hipMemcpyParam2D(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyParam2D.retval); \
	ratelprof_add_to_buffer(buf, "\"pCopy\":{\"type\":\"const hip_Memcpy2D *\",\"value\":\"N/A\"},"); \
};


#define PROCESS_ARGS_hipPeekAtLastError(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipPeekAtLastError.retval); \
\
};

//	hipMemGenericAllocationHandle_t handle (opaque);
#define PROCESS_ARGS_hipMemRelease(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemRelease.retval); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipMemGenericAllocationHandle_t\",\"value\":\"%p\"}", args->hipMemRelease.handle); \
};


#define PROCESS_ARGS_hipDeviceGetSharedMemConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceGetSharedMemConfig.retval); \
	ratelprof_add_to_buffer(buf, "\"pConfig\":{\"type\":\"hipSharedMemConfig *\",\"value\":\"%p\"}", args->hipDeviceGetSharedMemConfig.pConfig); \
};

//	hipUserObject_t object (opaque);
//	unsigned int count (unsigned int);
#define PROCESS_ARGS_hipUserObjectRelease(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipUserObjectRelease.retval); \
	ratelprof_add_to_buffer(buf, "\"object\":{\"type\":\"hipUserObject_t\",\"value\":\"%p\"},", args->hipUserObjectRelease.object); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipUserObjectRelease.count); \
};

//	hipStream_t stream (opaque);
//	uint32_t value (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamWriteValue32(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamWriteValue32.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamWriteValue32.stream); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipStreamWriteValue32.ptr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipStreamWriteValue32.value); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipStreamWriteValue32.flags); \
};

//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMemAllocHost(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemAllocHost.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipMemAllocHost.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemAllocHost.size); \
};

//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipGraphCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphCreate.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraph\":{\"type\":\"hipGraph_t *\",\"value\":\"%p\"},", args->hipGraphCreate.pGraph); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipGraphCreate.flags); \
};

//	hipFunction_t f (opaque);
//	size_t dynSharedMemPerBlk (unsigned long);
//	int blockSizeLimit (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipModuleOccupancyMaxPotentialBlockSizeWithFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.retval); \
	ratelprof_add_to_buffer(buf, "\"gridSize\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.gridSize); \
	ratelprof_add_to_buffer(buf, "\"blockSize\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSize); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"hipFunction_t\",\"value\":\"%p\"},", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.f); \
	ratelprof_add_to_buffer(buf, "\"dynSharedMemPerBlk\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.dynSharedMemPerBlk); \
	ratelprof_add_to_buffer(buf, "\"blockSizeLimit\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSizeLimit); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.flags); \
};

//	hipArray_t * array (unknown);
//	const struct hipChannelFormatDesc * desc (unknown);
//	struct hipExtent extent (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMalloc3DArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMalloc3DArray.retval); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const struct hipChannelFormatDesc *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"extent\":{\"type\":\"struct hipExtent\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMalloc3DArray.flags); \
};


#define PROCESS_ARGS_hipCtxGetCacheConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxGetCacheConfig.retval); \
	ratelprof_add_to_buffer(buf, "\"cacheConfig\":{\"type\":\"hipFuncCache_t *\",\"value\":\"%p\"}", args->hipCtxGetCacheConfig.cacheConfig); \
};

//	hipFunction_t f (opaque);
//	unsigned int gridDimX (unsigned int);
//	unsigned int gridDimY (unsigned int);
//	unsigned int gridDimZ (unsigned int);
//	unsigned int blockDimX (unsigned int);
//	unsigned int blockDimY (unsigned int);
//	unsigned int blockDimZ (unsigned int);
//	unsigned int sharedMemBytes (unsigned int);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipModuleLaunchCooperativeKernel(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipModuleLaunchCooperativeKernel.retval); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"hipFunction_t\",\"value\":\"%p\"},", args->hipModuleLaunchCooperativeKernel.f); \
	ratelprof_add_to_buffer(buf, "\"gridDimX\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernel.gridDimX); \
	ratelprof_add_to_buffer(buf, "\"gridDimY\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernel.gridDimY); \
	ratelprof_add_to_buffer(buf, "\"gridDimZ\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernel.gridDimZ); \
	ratelprof_add_to_buffer(buf, "\"blockDimX\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernel.blockDimX); \
	ratelprof_add_to_buffer(buf, "\"blockDimY\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernel.blockDimY); \
	ratelprof_add_to_buffer(buf, "\"blockDimZ\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernel.blockDimZ); \
	ratelprof_add_to_buffer(buf, "\"sharedMemBytes\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernel.sharedMemBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipModuleLaunchCooperativeKernel.stream); \
	ratelprof_add_to_buffer(buf, "\"kernelParams\":{\"type\":\"void **\",\"value\":\"%p\"}", args->hipModuleLaunchCooperativeKernel.kernelParams); \
};

//	const textureReference* texRef (unknown);
//	int dim (int);
#define PROCESS_ARGS_hipTexRefGetAddressMode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefGetAddressMode.retval); \
	ratelprof_add_to_buffer(buf, "\"pam\":{\"type\":\"enum hipTextureAddressMode *\",\"value\":\"%p\"},", args->hipTexRefGetAddressMode.pam); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"dim\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipTexRefGetAddressMode.dim); \
};

//	hipGraphNode_t node (opaque);
//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipGraphEventWaitNodeSetEvent(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphEventWaitNodeSetEvent.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphEventWaitNodeSetEvent.node); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"}", args->hipGraphEventWaitNodeSetEvent.event); \
};

//	int device (int);
#define PROCESS_ARGS_hipDeviceGetDefaultMemPool(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceGetDefaultMemPool.retval); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t *\",\"value\":\"%p\"},", args->hipDeviceGetDefaultMemPool.mem_pool); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceGetDefaultMemPool.device); \
};

//	hipMemPool_t mem_pool (opaque);
//	size_t min_bytes_to_hold (unsigned long);
#define PROCESS_ARGS_hipMemPoolTrimTo(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemPoolTrimTo.retval); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"%p\"},", args->hipMemPoolTrimTo.mem_pool); \
	ratelprof_add_to_buffer(buf, "\"min_bytes_to_hold\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemPoolTrimTo.min_bytes_to_hold); \
};

//	hipGraphExec_t graphExec (opaque);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipGraphUpload(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphUpload.retval); \
	ratelprof_add_to_buffer(buf, "\"graphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphUpload.graphExec); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipGraphUpload.stream); \
};

//	hipMipmappedArray_t * mipmap (unknown);
#define PROCESS_ARGS_hipExternalMemoryGetMappedMipmappedArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipExternalMemoryGetMappedMipmappedArray.retval); \
	ratelprof_add_to_buffer(buf, "\"mipmap\":{\"type\":\"hipMipmappedArray_t *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"extMem\":{\"type\":\"hipExternalMemory_t\",\"value\":\"%p\"},", args->hipExternalMemoryGetMappedMipmappedArray.extMem); \
	ratelprof_add_to_buffer(buf, "\"mipmapDesc\":{\"type\":\"const hipExternalMemoryMipmappedArrayDesc *\",\"value\":\"%p\"}", args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc); \
};

//	hipGraphNode_t hNode (opaque);
#define PROCESS_ARGS_hipGraphExternalSemaphoresWaitNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExternalSemaphoresWaitNodeSetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExternalSemaphoresWaitNodeSetParams.hNode); \
	ratelprof_add_to_buffer(buf, "\"nodeParams\":{\"type\":\"const hipExternalSemaphoreWaitNodeParams *\",\"value\":\"%p\"}", args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams); \
};

//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpyToSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyToSymbol.retval); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpyToSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpyToSymbol.src); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyToSymbol.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyToSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphAddMemsetNode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddMemsetNode.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddMemsetNode.pGraphNode); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddMemsetNode.graph); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddMemsetNode.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemsetNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"pMemsetParams\":{\"type\":\"const hipMemsetParams *\",\"value\":\"%p\"}", args->hipGraphAddMemsetNode.pMemsetParams); \
};

//	hipGraph_t originalGraph (opaque);
#define PROCESS_ARGS_hipGraphClone(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphClone.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphClone\":{\"type\":\"hipGraph_t *\",\"value\":\"%p\"},", args->hipGraphClone.pGraphClone); \
	ratelprof_add_to_buffer(buf, "\"originalGraph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"}", args->hipGraphClone.originalGraph); \
};


#define PROCESS_ARGS_hipExtGetLastError(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipExtGetLastError.retval); \
\
};

//	hipGraphNode_t hNode (opaque);
//	hipKernelNodeAttrID attr (enum);
#define PROCESS_ARGS_hipGraphKernelNodeGetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphKernelNodeGetAttribute.retval); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphKernelNodeGetAttribute.hNode); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipKernelNodeAttrID\",\"value\":\"%d\"},", args->hipGraphKernelNodeGetAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"hipKernelNodeAttrValue *\",\"value\":\"%p\"}", args->hipGraphKernelNodeGetAttribute.value); \
};

//	hipEvent_t event (opaque);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipEventRecord(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipEventRecord.retval); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"},", args->hipEventRecord.event); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipEventRecord.stream); \
};

//	hipMemGenericAllocationHandle_t handle (opaque);
#define PROCESS_ARGS_hipMemGetAllocationPropertiesFromHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemGetAllocationPropertiesFromHandle.retval); \
	ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"hipMemAllocationProp *\",\"value\":\"%p\"},", args->hipMemGetAllocationPropertiesFromHandle.prop); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipMemGenericAllocationHandle_t\",\"value\":\"%p\"}", args->hipMemGetAllocationPropertiesFromHandle.handle); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipGraphAddEventWaitNode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddEventWaitNode.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddEventWaitNode.pGraphNode); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddEventWaitNode.graph); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddEventWaitNode.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddEventWaitNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"}", args->hipGraphAddEventWaitNode.event); \
};

//	hipMemPool_t mem_pool (opaque);
#define PROCESS_ARGS_hipMemPoolImportPointer(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemPoolImportPointer.retval); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipMemPoolImportPointer.dev_ptr); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"%p\"},", args->hipMemPoolImportPointer.mem_pool); \
	ratelprof_add_to_buffer(buf, "\"export_data\":{\"type\":\"hipMemPoolPtrExportData *\",\"value\":\"%p\"}", args->hipMemPoolImportPointer.export_data); \
};


#define PROCESS_ARGS_hipFree(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipFree.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipFree.ptr); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphEventRecordNodeGetEvent(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphEventRecordNodeGetEvent.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphEventRecordNodeGetEvent.node); \
	ratelprof_add_to_buffer(buf, "\"event_out\":{\"type\":\"hipEvent_t *\",\"value\":\"%p\"}", args->hipGraphEventRecordNodeGetEvent.event_out); \
};

//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMalloc(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMalloc.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipMalloc.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMalloc.size); \
};

//	size_t sizeBytes (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyWithStream(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyWithStream.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpyWithStream.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpyWithStream.src); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyWithStream.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemcpyWithStream.stream); \
};

//	const HIP_MEMCPY3D* pCopy (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipDrvMemcpy3DAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDrvMemcpy3DAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"pCopy\":{\"type\":\"const HIP_MEMCPY3D*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipDrvMemcpy3DAsync.stream); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphAddMemAllocNode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddMemAllocNode.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddMemAllocNode.pGraphNode); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddMemAllocNode.graph); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddMemAllocNode.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemAllocNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"hipMemAllocNodeParams *\",\"value\":\"%p\"}", args->hipGraphAddMemAllocNode.pNodeParams); \
};

//	size_t size (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostMalloc(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipHostMalloc.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipHostMalloc.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipHostMalloc.size); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipHostMalloc.flags); \
};

//	hipGraphNode_t node (opaque);
//	hipMemcpy3DParms * pNodeParams (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphMemcpyNodeGetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphMemcpyNodeGetParams.node); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"hipMemcpy3DParms *\",\"value\":\"N/A\"},"); \
};

//	textureReference * texRef (unknown);
//	unsigned int Flags (unsigned int);
#define PROCESS_ARGS_hipTexRefSetFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefSetFlags.retval); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"Flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipTexRefSetFlags.Flags); \
};

//	hipMemAllocationHandleType handle_type (enum);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMemPoolImportFromShareableHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemPoolImportFromShareableHandle.retval); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t *\",\"value\":\"%p\"},", args->hipMemPoolImportFromShareableHandle.mem_pool); \
	ratelprof_add_to_buffer(buf, "\"shared_handle\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemPoolImportFromShareableHandle.shared_handle); \
	ratelprof_add_to_buffer(buf, "\"handle_type\":{\"type\":\"hipMemAllocationHandleType\",\"value\":\"%d\"},", args->hipMemPoolImportFromShareableHandle.handle_type); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMemPoolImportFromShareableHandle.flags); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t hNode (opaque);
//	unsigned int isEnabled (unsigned int);
#define PROCESS_ARGS_hipGraphNodeSetEnabled(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphNodeSetEnabled.retval); \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphNodeSetEnabled.hGraphExec); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphNodeSetEnabled.hNode); \
	ratelprof_add_to_buffer(buf, "\"isEnabled\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipGraphNodeSetEnabled.isEnabled); \
};

//	textureReference * texRef (unknown);
//	float bias (float);
#define PROCESS_ARGS_hipTexRefSetMipmapLevelBias(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefSetMipmapLevelBias.retval); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"bias\":{\"type\":\"float\",\"value\":\"%f\"}", args->hipTexRefSetMipmapLevelBias.bias); \
};

//	hipStream_t stream (opaque);
//	uint32_t value (unsigned int);
//	unsigned int flags (unsigned int);
//	uint32_t mask (unsigned int);
#define PROCESS_ARGS_hipStreamWaitValue32(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamWaitValue32.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamWaitValue32.stream); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipStreamWaitValue32.ptr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipStreamWaitValue32.value); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipStreamWaitValue32.flags); \
	ratelprof_add_to_buffer(buf, "\"mask\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->hipStreamWaitValue32.mask); \
};

//	hipMipmappedArray_t hMipmappedArray (unknown);
#define PROCESS_ARGS_hipMipmappedArrayDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMipmappedArrayDestroy.retval); \
	ratelprof_add_to_buffer(buf, "\"hMipmappedArray\":{\"type\":\"hipMipmappedArray_t\",\"value\":\"N/A\"},"); \
};

//	hipCtx_t ctx (opaque);
#define PROCESS_ARGS_hipCtxDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxDestroy.retval); \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t\",\"value\":\"%p\"}", args->hipCtxDestroy.ctx); \
};


#define PROCESS_ARGS_hipDeviceReset(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceReset.retval); \
\
};

//	size_t count (unsigned long);
//	int device (int);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemPrefetchAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemPrefetchAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemPrefetchAsync.dev_ptr); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemPrefetchAsync.count); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemPrefetchAsync.device); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemPrefetchAsync.stream); \
};

//	unsigned short value (unsigned short);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemsetD16(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemsetD16.retval); \
	ratelprof_add_to_buffer(buf, "\"dest\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipMemsetD16.dest); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"unsigned short\",\"value\":\"%hu\"},", args->hipMemsetD16.value); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemsetD16.count); \
};

//	size_t dpitch (unsigned long);
//	size_t spitch (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpy2DAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpy2DAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpy2DAsync.dst); \
	ratelprof_add_to_buffer(buf, "\"dpitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DAsync.dpitch); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpy2DAsync.src); \
	ratelprof_add_to_buffer(buf, "\"spitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DAsync.spitch); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DAsync.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DAsync.height); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemcpy2DAsync.stream); \
};

//	hipDevice_t dev (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipDevicePrimaryCtxSetFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDevicePrimaryCtxSetFlags.retval); \
	ratelprof_add_to_buffer(buf, "\"dev\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"},", args->hipDevicePrimaryCtxSetFlags.dev); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipDevicePrimaryCtxSetFlags.flags); \
};

//	hipGraph_t graph (opaque);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipGraphInstantiateWithFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphInstantiateWithFlags.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphExec\":{\"type\":\"hipGraphExec_t *\",\"value\":\"%p\"},", args->hipGraphInstantiateWithFlags.pGraphExec); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphInstantiateWithFlags.graph); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned long long\",\"value\":\"%llu\"}", args->hipGraphInstantiateWithFlags.flags); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphAddEmptyNode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddEmptyNode.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddEmptyNode.pGraphNode); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddEmptyNode.graph); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddEmptyNode.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipGraphAddEmptyNode.numDependencies); \
};

//	hipMipmappedArray_t mipmappedArray (unknown);
#define PROCESS_ARGS_hipFreeMipmappedArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipFreeMipmappedArray.retval); \
	ratelprof_add_to_buffer(buf, "\"mipmappedArray\":{\"type\":\"hipMipmappedArray_t\",\"value\":\"N/A\"},"); \
};

//	hipArray_t * pHandle (unknown);
//	const HIP_ARRAY_DESCRIPTOR * pAllocateArray (unknown);
#define PROCESS_ARGS_hipArrayCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipArrayCreate.retval); \
	ratelprof_add_to_buffer(buf, "\"pHandle\":{\"type\":\"hipArray_t *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"pAllocateArray\":{\"type\":\"const HIP_ARRAY_DESCRIPTOR *\",\"value\":\"N/A\"},"); \
};

//	const textureReference * tex (unknown);
#define PROCESS_ARGS_hipUnbindTexture(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipUnbindTexture.retval); \
	ratelprof_add_to_buffer(buf, "\"tex\":{\"type\":\"const textureReference *\",\"value\":\"N/A\"},"); \
};


#define PROCESS_ARGS_hipCtxPopCurrent(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxPopCurrent.retval); \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t *\",\"value\":\"%p\"}", args->hipCtxPopCurrent.ctx); \
};

//	unsigned short value (unsigned short);
//	size_t count (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemsetD16Async(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemsetD16Async.retval); \
	ratelprof_add_to_buffer(buf, "\"dest\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipMemsetD16Async.dest); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"unsigned short\",\"value\":\"%hu\"},", args->hipMemsetD16Async.value); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemsetD16Async.count); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemsetD16Async.stream); \
};

//	HIP_RESOURCE_DESC * pResDesc (unknown);
//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectGetResourceDesc(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexObjectGetResourceDesc.retval); \
	ratelprof_add_to_buffer(buf, "\"pResDesc\":{\"type\":\"HIP_RESOURCE_DESC *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"texObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"N/A\"},"); \
};

//	dim3 numBlocks ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	dim3 dimBlocks ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	size_t sharedMemBytes (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipLaunchKernel(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipLaunchKernel.retval); \
	ratelprof_add_to_buffer(buf, "\"function_address\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipLaunchKernel.function_address); \
	ratelprof_add_to_buffer(buf, "\"numBlocks\":{\"type\":\"struct dim3\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipLaunchKernel.numBlocks.x); \
	ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipLaunchKernel.numBlocks.y); \
	ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->hipLaunchKernel.numBlocks.z); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dimBlocks\":{\"type\":\"struct dim3\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipLaunchKernel.dimBlocks.x); \
	ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipLaunchKernel.dimBlocks.y); \
	ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->hipLaunchKernel.dimBlocks.z); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"args\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipLaunchKernel.args); \
	ratelprof_add_to_buffer(buf, "\"sharedMemBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipLaunchKernel.sharedMemBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipLaunchKernel.stream); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphMemsetNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphMemsetNodeGetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphMemsetNodeGetParams.node); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"hipMemsetParams *\",\"value\":\"%p\"}", args->hipGraphMemsetNodeGetParams.pNodeParams); \
};


#define PROCESS_ARGS_hipHostGetFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipHostGetFlags.retval); \
	ratelprof_add_to_buffer(buf, "\"flagsPtr\":{\"type\":\"unsigned int *\",\"value\":\"%p\"},", args->hipHostGetFlags.flagsPtr); \
	ratelprof_add_to_buffer(buf, "\"hostPtr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipHostGetFlags.hostPtr); \
};

//	hipGraphExec_t graphExec (opaque);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipGraphLaunch(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphLaunch.retval); \
	ratelprof_add_to_buffer(buf, "\"graphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphLaunch.graphExec); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipGraphLaunch.stream); \
};

//	size_t sizeBytes (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpyAsync.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpyAsync.src); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemcpyAsync.stream); \
};

//	hipArray_t * array (unknown);
//	const hipChannelFormatDesc * desc (unknown);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMallocArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMallocArray.retval); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const hipChannelFormatDesc *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMallocArray.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMallocArray.height); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMallocArray.flags); \
};

//	hipFuncCache_t config (enum);
#define PROCESS_ARGS_hipFuncSetCacheConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipFuncSetCacheConfig.retval); \
	ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipFuncSetCacheConfig.func); \
	ratelprof_add_to_buffer(buf, "\"config\":{\"type\":\"hipFuncCache_t\",\"value\":\"%d\"}", args->hipFuncSetCacheConfig.config); \
};

//	size_t size (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMallocManaged(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMallocManaged.retval); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipMallocManaged.dev_ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMallocManaged.size); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMallocManaged.flags); \
};

//	uint32_t id (unsigned int);
#define PROCESS_ARGS_hipApiName(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"const char *\",\"value\":\"%s\"},", args->hipApiName.retval); \
	ratelprof_add_to_buffer(buf, "\"id\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->hipApiName.id); \
};


#define PROCESS_ARGS_hipFreeHost(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipFreeHost.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipFreeHost.ptr); \
};


#define PROCESS_ARGS_hipCtxGetCurrent(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxGetCurrent.retval); \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t *\",\"value\":\"%p\"}", args->hipCtxGetCurrent.ctx); \
};

//	hipSurfaceObject_t surfaceObject (unknown);
#define PROCESS_ARGS_hipDestroySurfaceObject(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDestroySurfaceObject.retval); \
	ratelprof_add_to_buffer(buf, "\"surfaceObject\":{\"type\":\"hipSurfaceObject_t\",\"value\":\"N/A\"},"); \
};

//	size_t width (unsigned long);
//	size_t height (unsigned long);
#define PROCESS_ARGS_hipMallocPitch(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMallocPitch.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipMallocPitch.ptr); \
	ratelprof_add_to_buffer(buf, "\"pitch\":{\"type\":\"size_t *\",\"value\":\"%p\"},", args->hipMallocPitch.pitch); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMallocPitch.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMallocPitch.height); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipStreamGetCaptureInfo(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamGetCaptureInfo.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamGetCaptureInfo.stream); \
	ratelprof_add_to_buffer(buf, "\"pCaptureStatus\":{\"type\":\"hipStreamCaptureStatus *\",\"value\":\"%p\"},", args->hipStreamGetCaptureInfo.pCaptureStatus); \
	ratelprof_add_to_buffer(buf, "\"pId\":{\"type\":\"unsigned long long *\",\"value\":\"%p\"}", args->hipStreamGetCaptureInfo.pId); \
};

//	hipStream_t stream (opaque);
//	size_t numDependencies (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamUpdateCaptureDependencies(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamUpdateCaptureDependencies.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamUpdateCaptureDependencies.stream); \
	ratelprof_add_to_buffer(buf, "\"dependencies\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipStreamUpdateCaptureDependencies.dependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipStreamUpdateCaptureDependencies.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipStreamUpdateCaptureDependencies.flags); \
};

//	size_t size (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostAlloc(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipHostAlloc.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipHostAlloc.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipHostAlloc.size); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipHostAlloc.flags); \
};

//	unsigned char value (unsigned char);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemsetD8(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemsetD8.retval); \
	ratelprof_add_to_buffer(buf, "\"dest\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipMemsetD8.dest); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"unsigned char\",\"value\":\"%hhu\"},", args->hipMemsetD8.value); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemsetD8.count); \
};

//	hipPitchedPtr pitchedDevPtr (unknown);
//	int value (int);
//	hipExtent extent (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemset3DAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemset3DAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"pitchedDevPtr\":{\"type\":\"hipPitchedPtr\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemset3DAsync.value); \
	ratelprof_add_to_buffer(buf, "\"extent\":{\"type\":\"hipExtent\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemset3DAsync.stream); \
};

//	const hip_Memcpy2D * pCopy (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyParam2DAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyParam2DAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"pCopy\":{\"type\":\"const hip_Memcpy2D *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemcpyParam2DAsync.stream); \
};

//	hipError_t hipError (enum);
#define PROCESS_ARGS_hipDrvGetErrorName(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDrvGetErrorName.retval); \
	ratelprof_add_to_buffer(buf, "\"hipError\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDrvGetErrorName.hipError); \
	ratelprof_add_to_buffer(buf, "\"errorString\":{\"type\":\"const char **\",\"value\":\"%p\"}", args->hipDrvGetErrorName.errorString); \
};

//	hipPointer_attribute attribute (unknown);
#define PROCESS_ARGS_hipPointerSetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipPointerSetAttribute.retval); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipPointerSetAttribute.value); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hipPointer_attribute\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"}", args->hipPointerSetAttribute.ptr); \
};


#define PROCESS_ARGS_hipMemGetInfo(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemGetInfo.retval); \
	ratelprof_add_to_buffer(buf, "\"free\":{\"type\":\"size_t *\",\"value\":\"%p\"},", args->hipMemGetInfo.free); \
	ratelprof_add_to_buffer(buf, "\"total\":{\"type\":\"size_t *\",\"value\":\"%p\"}", args->hipMemGetInfo.total); \
};

//	dim3 gridDim ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	dim3 blockDim ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	size_t sharedMem (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS___hipPushCallConfiguration(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->__hipPushCallConfiguration.retval); \
	ratelprof_add_to_buffer(buf, "\"gridDim\":{\"type\":\"struct dim3\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->__hipPushCallConfiguration.gridDim.x); \
	ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->__hipPushCallConfiguration.gridDim.y); \
	ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->__hipPushCallConfiguration.gridDim.z); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"blockDim\":{\"type\":\"struct dim3\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->__hipPushCallConfiguration.blockDim.x); \
	ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->__hipPushCallConfiguration.blockDim.y); \
	ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->__hipPushCallConfiguration.blockDim.z); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sharedMem\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->__hipPushCallConfiguration.sharedMem); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->__hipPushCallConfiguration.stream); \
};

//	hipArray_Format * pFormat (unknown);
//	const textureReference * texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetFormat(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefGetFormat.retval); \
	ratelprof_add_to_buffer(buf, "\"pFormat\":{\"type\":\"hipArray_Format *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"pNumChannels\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipTexRefGetFormat.pNumChannels); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference *\",\"value\":\"N/A\"},"); \
};

//	hipMemGenericAllocationHandle_t handle (opaque);
//	hipMemAllocationHandleType handleType (enum);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipMemExportToShareableHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemExportToShareableHandle.retval); \
	ratelprof_add_to_buffer(buf, "\"shareableHandle\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemExportToShareableHandle.shareableHandle); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipMemGenericAllocationHandle_t\",\"value\":\"%p\"},", args->hipMemExportToShareableHandle.handle); \
	ratelprof_add_to_buffer(buf, "\"handleType\":{\"type\":\"hipMemAllocationHandleType\",\"value\":\"%d\"},", args->hipMemExportToShareableHandle.handleType); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned long long\",\"value\":\"%llu\"}", args->hipMemExportToShareableHandle.flags); \
};

//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetFilterMode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefGetFilterMode.retval); \
	ratelprof_add_to_buffer(buf, "\"pfm\":{\"type\":\"enum hipTextureFilterMode *\",\"value\":\"%p\"},", args->hipTexRefGetFilterMode.pfm); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"N/A\"},"); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphHostNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphHostNodeSetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphHostNodeSetParams.node); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"const hipHostNodeParams *\",\"value\":\"%p\"}", args->hipGraphHostNodeSetParams.pNodeParams); \
};

//	hipGraph_t graph (opaque);
#define PROCESS_ARGS_hipGraphGetNodes(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphGetNodes.retval); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphGetNodes.graph); \
	ratelprof_add_to_buffer(buf, "\"nodes\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphGetNodes.nodes); \
	ratelprof_add_to_buffer(buf, "\"numNodes\":{\"type\":\"size_t *\",\"value\":\"%p\"}", args->hipGraphGetNodes.numNodes); \
};


#define PROCESS_ARGS_hipCtxGetDevice(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxGetDevice.retval); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t *\",\"value\":\"%p\"}", args->hipCtxGetDevice.device); \
};


#define PROCESS_ARGS_hipGetSymbolAddress(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGetSymbolAddress.retval); \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipGetSymbolAddress.devPtr); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":\"%p\"}", args->hipGetSymbolAddress.symbol); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipStreamGetCaptureInfo_v2(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamGetCaptureInfo_v2.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamGetCaptureInfo_v2.stream); \
	ratelprof_add_to_buffer(buf, "\"captureStatus_out\":{\"type\":\"hipStreamCaptureStatus *\",\"value\":\"%p\"},", args->hipStreamGetCaptureInfo_v2.captureStatus_out); \
	ratelprof_add_to_buffer(buf, "\"id_out\":{\"type\":\"unsigned long long *\",\"value\":\"%p\"},", args->hipStreamGetCaptureInfo_v2.id_out); \
	ratelprof_add_to_buffer(buf, "\"graph_out\":{\"type\":\"hipGraph_t *\",\"value\":\"%p\"},", args->hipStreamGetCaptureInfo_v2.graph_out); \
	ratelprof_add_to_buffer(buf, "\"dependencies_out\":{\"type\":\"const hipGraphNode_t **\",\"value\":\"%p\"},", args->hipStreamGetCaptureInfo_v2.dependencies_out); \
	ratelprof_add_to_buffer(buf, "\"numDependencies_out\":{\"type\":\"size_t *\",\"value\":\"%p\"}", args->hipStreamGetCaptureInfo_v2.numDependencies_out); \
};


#define PROCESS_ARGS_hipGetSymbolSize(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGetSymbolSize.retval); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t*\",\"value\":\"%p\"},", args->hipGetSymbolSize.size); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":\"%p\"}", args->hipGetSymbolSize.symbol); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphExecHostNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExecHostNodeSetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphExecHostNodeSetParams.hGraphExec); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExecHostNodeSetParams.node); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"const hipHostNodeParams *\",\"value\":\"%p\"}", args->hipGraphExecHostNodeSetParams.pNodeParams); \
};

//	hipMemPool_t mem_pool (opaque);
//	hipMemPoolAttr attr (enum);
#define PROCESS_ARGS_hipMemPoolSetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemPoolSetAttribute.retval); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"%p\"},", args->hipMemPoolSetAttribute.mem_pool); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipMemPoolAttr\",\"value\":\"%d\"},", args->hipMemPoolSetAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipMemPoolSetAttribute.value); \
};

//	int device (int);
//	hipMemPool_t mem_pool (opaque);
#define PROCESS_ARGS_hipDeviceSetMemPool(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceSetMemPool.retval); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceSetMemPool.device); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"%p\"}", args->hipDeviceSetMemPool.mem_pool); \
};

//	dim3 gridDim ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	dim3 blockDim ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	size_t sharedMem (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipConfigureCall(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipConfigureCall.retval); \
	ratelprof_add_to_buffer(buf, "\"gridDim\":{\"type\":\"struct dim3\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipConfigureCall.gridDim.x); \
	ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipConfigureCall.gridDim.y); \
	ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->hipConfigureCall.gridDim.z); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"blockDim\":{\"type\":\"struct dim3\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipConfigureCall.blockDim.x); \
	ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipConfigureCall.blockDim.y); \
	ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->hipConfigureCall.blockDim.z); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sharedMem\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipConfigureCall.sharedMem); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipConfigureCall.stream); \
};

//	hipMipmappedArray_t * pHandle (unknown);
//	HIP_ARRAY3D_DESCRIPTOR * pMipmappedArrayDesc (unknown);
//	unsigned int numMipmapLevels (unsigned int);
#define PROCESS_ARGS_hipMipmappedArrayCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMipmappedArrayCreate.retval); \
	ratelprof_add_to_buffer(buf, "\"pHandle\":{\"type\":\"hipMipmappedArray_t *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"pMipmappedArrayDesc\":{\"type\":\"HIP_ARRAY3D_DESCRIPTOR *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"numMipmapLevels\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMipmappedArrayCreate.numMipmapLevels); \
};

//	size_t sizeBytes (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostRegister(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipHostRegister.retval); \
	ratelprof_add_to_buffer(buf, "\"hostPtr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipHostRegister.hostPtr); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipHostRegister.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipHostRegister.flags); \
};

//	const textureReference * tex (unknown);
//	hipArray_const_t array (unknown);
//	const hipChannelFormatDesc * desc (unknown);
#define PROCESS_ARGS_hipBindTextureToArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipBindTextureToArray.retval); \
	ratelprof_add_to_buffer(buf, "\"tex\":{\"type\":\"const textureReference *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_const_t\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const hipChannelFormatDesc *\",\"value\":\"N/A\"},"); \
};

//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMallocHost(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMallocHost.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipMallocHost.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMallocHost.size); \
};

//	int dstDeviceId (int);
//	int srcDeviceId (int);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemcpyPeer(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyPeer.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpyPeer.dst); \
	ratelprof_add_to_buffer(buf, "\"dstDeviceId\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemcpyPeer.dstDeviceId); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpyPeer.src); \
	ratelprof_add_to_buffer(buf, "\"srcDeviceId\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemcpyPeer.srcDeviceId); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemcpyPeer.sizeBytes); \
};

//	int blockSize (int);
//	size_t dynSharedMemPerBlk (unsigned long);
#define PROCESS_ARGS_hipOccupancyMaxActiveBlocksPerMultiprocessor(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.retval); \
	ratelprof_add_to_buffer(buf, "\"numBlocks\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.f); \
	ratelprof_add_to_buffer(buf, "\"blockSize\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.blockSize); \
	ratelprof_add_to_buffer(buf, "\"dynSharedMemPerBlk\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.dynSharedMemPerBlk); \
};

//	hipDeviceAttribute_t attr (enum);
//	int deviceId (int);
#define PROCESS_ARGS_hipDeviceGetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceGetAttribute.retval); \
	ratelprof_add_to_buffer(buf, "\"pi\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipDeviceGetAttribute.pi); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipDeviceAttribute_t\",\"value\":\"%d\"},", args->hipDeviceGetAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"deviceId\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceGetAttribute.deviceId); \
};

//	hipDevice_t dev (int);
#define PROCESS_ARGS_hipDevicePrimaryCtxReset(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDevicePrimaryCtxReset.retval); \
	ratelprof_add_to_buffer(buf, "\"dev\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipDevicePrimaryCtxReset.dev); \
};

//	textureReference * texRef (unknown);
//	size_t bytes (unsigned long);
#define PROCESS_ARGS_hipTexRefSetAddress(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefSetAddress.retval); \
	ratelprof_add_to_buffer(buf, "\"ByteOffset\":{\"type\":\"size_t *\",\"value\":\"%p\"},", args->hipTexRefSetAddress.ByteOffset); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"dptr\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipTexRefSetAddress.dptr); \
	ratelprof_add_to_buffer(buf, "\"bytes\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipTexRefSetAddress.bytes); \
};

//	hipGraphicsResource_t resource (opaque);
#define PROCESS_ARGS_hipGraphicsResourceGetMappedPointer(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphicsResourceGetMappedPointer.retval); \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipGraphicsResourceGetMappedPointer.devPtr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t*\",\"value\":\"%p\"},", args->hipGraphicsResourceGetMappedPointer.size); \
	ratelprof_add_to_buffer(buf, "\"resource\":{\"type\":\"hipGraphicsResource_t\",\"value\":\"%p\"}", args->hipGraphicsResourceGetMappedPointer.resource); \
};

//	hipSharedMemConfig config (enum);
#define PROCESS_ARGS_hipCtxSetSharedMemConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxSetSharedMemConfig.retval); \
	ratelprof_add_to_buffer(buf, "\"config\":{\"type\":\"hipSharedMemConfig\",\"value\":\"%d\"}", args->hipCtxSetSharedMemConfig.config); \
};

//	hipGraphNode_t hNode (opaque);
#define PROCESS_ARGS_hipGraphExternalSemaphoresSignalNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExternalSemaphoresSignalNodeGetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExternalSemaphoresSignalNodeGetParams.hNode); \
	ratelprof_add_to_buffer(buf, "\"params_out\":{\"type\":\"hipExternalSemaphoreSignalNodeParams *\",\"value\":\"%p\"}", args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out); \
};

//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipArrayDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipArrayDestroy.retval); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t\",\"value\":\"N/A\"},"); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipFreeAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipFreeAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipFreeAsync.dev_ptr); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipFreeAsync.stream); \
};

//	HIP_ARRAY3D_DESCRIPTOR * pArrayDescriptor (unknown);
//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipArray3DGetDescriptor(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipArray3DGetDescriptor.retval); \
	ratelprof_add_to_buffer(buf, "\"pArrayDescriptor\":{\"type\":\"HIP_ARRAY3D_DESCRIPTOR *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t\",\"value\":\"N/A\"},"); \
};

//	int len (int);
//	int device (int);
#define PROCESS_ARGS_hipDeviceGetPCIBusId(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceGetPCIBusId.retval); \
	ratelprof_add_to_buffer(buf, "\"pciBusId\":{\"type\":\"char *\",\"value\":\"%p\"},", args->hipDeviceGetPCIBusId.pciBusId); \
	ratelprof_add_to_buffer(buf, "\"len\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceGetPCIBusId.len); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceGetPCIBusId.device); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphAddMemFreeNode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddMemFreeNode.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddMemFreeNode.pGraphNode); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddMemFreeNode.graph); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddMemFreeNode.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemFreeNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipGraphAddMemFreeNode.dev_ptr); \
};

//	hipArray_t * array (unknown);
//	const HIP_ARRAY3D_DESCRIPTOR * pAllocateArray (unknown);
#define PROCESS_ARGS_hipArray3DCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipArray3DCreate.retval); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"pAllocateArray\":{\"type\":\"const HIP_ARRAY3D_DESCRIPTOR *\",\"value\":\"N/A\"},"); \
};

//	hipGraphNode_t hNode (opaque);
#define PROCESS_ARGS_hipGraphExternalSemaphoresSignalNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExternalSemaphoresSignalNodeSetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExternalSemaphoresSignalNodeSetParams.hNode); \
	ratelprof_add_to_buffer(buf, "\"nodeParams\":{\"type\":\"const hipExternalSemaphoreSignalNodeParams *\",\"value\":\"%p\"}", args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams); \
};

//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetBorderColor(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefGetBorderColor.retval); \
	ratelprof_add_to_buffer(buf, "\"pBorderColor\":{\"type\":\"float *\",\"value\":\"%p\"},", args->hipTexRefGetBorderColor.pBorderColor); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"N/A\"},"); \
};

//	hipModule_t hmod (opaque);
#define PROCESS_ARGS_hipModuleGetGlobal(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipModuleGetGlobal.retval); \
	ratelprof_add_to_buffer(buf, "\"dptr\":{\"type\":\"hipDeviceptr_t *\",\"value\":\"%p\"},", args->hipModuleGetGlobal.dptr); \
	ratelprof_add_to_buffer(buf, "\"bytes\":{\"type\":\"size_t*\",\"value\":\"%p\"},", args->hipModuleGetGlobal.bytes); \
	ratelprof_add_to_buffer(buf, "\"hmod\":{\"type\":\"hipModule_t\",\"value\":\"%p\"},", args->hipModuleGetGlobal.hmod); \
	ratelprof_add_to_buffer(buf, "\"name\":{\"type\":\"const char *\",\"value\":\"%p\"}", args->hipModuleGetGlobal.name); \
};

//	hipMipmappedArray_t * mipmappedArray (unknown);
//	const struct hipChannelFormatDesc * desc (unknown);
//	struct hipExtent extent (unknown);
//	unsigned int numLevels (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMallocMipmappedArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMallocMipmappedArray.retval); \
	ratelprof_add_to_buffer(buf, "\"mipmappedArray\":{\"type\":\"hipMipmappedArray_t *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const struct hipChannelFormatDesc *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"extent\":{\"type\":\"struct hipExtent\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"numLevels\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipMallocMipmappedArray.numLevels); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMallocMipmappedArray.flags); \
};


#define PROCESS_ARGS_hipProfilerStart(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipProfilerStart.retval); \
\
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
//	hipMemcpy3DParms * pNodeParams (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExecMemcpyNodeSetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphExecMemcpyNodeSetParams.hGraphExec); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExecMemcpyNodeSetParams.node); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"hipMemcpy3DParms *\",\"value\":\"N/A\"},"); \
};

//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipEventSynchronize(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipEventSynchronize.retval); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"}", args->hipEventSynchronize.event); \
};


#define PROCESS_ARGS_hipMemPoolExportPointer(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemPoolExportPointer.retval); \
	ratelprof_add_to_buffer(buf, "\"export_data\":{\"type\":\"hipMemPoolPtrExportData *\",\"value\":\"%p\"},", args->hipMemPoolExportPointer.export_data); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipMemPoolExportPointer.dev_ptr); \
};


#define PROCESS_ARGS_hipHostUnregister(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipHostUnregister.retval); \
	ratelprof_add_to_buffer(buf, "\"hostPtr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipHostUnregister.hostPtr); \
};

//	size_t pitch (unsigned long);
//	int value (int);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
#define PROCESS_ARGS_hipMemset2D(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemset2D.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemset2D.dst); \
	ratelprof_add_to_buffer(buf, "\"pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemset2D.pitch); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemset2D.value); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemset2D.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemset2D.height); \
};

//	size_t dpitch (unsigned long);
//	hipArray_const_t src (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpy2DFromArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpy2DFromArray.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpy2DFromArray.dst); \
	ratelprof_add_to_buffer(buf, "\"dpitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArray.dpitch); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"hipArray_const_t\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"wOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArray.wOffset); \
	ratelprof_add_to_buffer(buf, "\"hOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArray.hOffset); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArray.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArray.height); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};

//	size_t size (unsigned long);
//	size_t alignment (unsigned long);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipMemAddressReserve(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemAddressReserve.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipMemAddressReserve.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemAddressReserve.size); \
	ratelprof_add_to_buffer(buf, "\"alignment\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemAddressReserve.alignment); \
	ratelprof_add_to_buffer(buf, "\"addr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemAddressReserve.addr); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned long long\",\"value\":\"%llu\"}", args->hipMemAddressReserve.flags); \
};

//	hipSharedMemConfig config (enum);
#define PROCESS_ARGS_hipFuncSetSharedMemConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipFuncSetSharedMemConfig.retval); \
	ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipFuncSetSharedMemConfig.func); \
	ratelprof_add_to_buffer(buf, "\"config\":{\"type\":\"hipSharedMemConfig\",\"value\":\"%d\"}", args->hipFuncSetSharedMemConfig.config); \
};

//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipDestroyTextureObject(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDestroyTextureObject.retval); \
	ratelprof_add_to_buffer(buf, "\"textureObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"N/A\"},"); \
};

//	textureReference* texRef (unknown);
//	unsigned int maxAniso (unsigned int);
#define PROCESS_ARGS_hipTexRefSetMaxAnisotropy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefSetMaxAnisotropy.retval); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"maxAniso\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipTexRefSetMaxAnisotropy.maxAniso); \
};

//	textureReference* texRef (unknown);
//	const HIP_ARRAY_DESCRIPTOR * desc (unknown);
//	size_t Pitch (unsigned long);
#define PROCESS_ARGS_hipTexRefSetAddress2D(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefSetAddress2D.retval); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const HIP_ARRAY_DESCRIPTOR *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"dptr\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipTexRefSetAddress2D.dptr); \
	ratelprof_add_to_buffer(buf, "\"Pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipTexRefSetAddress2D.Pitch); \
};


#define PROCESS_ARGS_hipGetDevice(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGetDevice.retval); \
	ratelprof_add_to_buffer(buf, "\"deviceId\":{\"type\":\"int *\",\"value\":\"%p\"}", args->hipGetDevice.deviceId); \
};

//	int device (int);
//	hipGraphMemAttributeType attr (enum);
#define PROCESS_ARGS_hipDeviceGetGraphMemAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceGetGraphMemAttribute.retval); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceGetGraphMemAttribute.device); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipGraphMemAttributeType\",\"value\":\"%d\"},", args->hipDeviceGetGraphMemAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipDeviceGetGraphMemAttribute.value); \
};

//	hipArray_t * array (unknown);
//	hipGraphicsResource_t resource (opaque);
//	unsigned int arrayIndex (unsigned int);
//	unsigned int mipLevel (unsigned int);
#define PROCESS_ARGS_hipGraphicsSubResourceGetMappedArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphicsSubResourceGetMappedArray.retval); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"resource\":{\"type\":\"hipGraphicsResource_t\",\"value\":\"%p\"},", args->hipGraphicsSubResourceGetMappedArray.resource); \
	ratelprof_add_to_buffer(buf, "\"arrayIndex\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipGraphicsSubResourceGetMappedArray.arrayIndex); \
	ratelprof_add_to_buffer(buf, "\"mipLevel\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipGraphicsSubResourceGetMappedArray.mipLevel); \
};

//	hipGraphNode_t node (opaque);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParamsToSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphMemcpyNodeSetParamsToSymbol.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphMemcpyNodeSetParamsToSymbol.node); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipGraphMemcpyNodeSetParamsToSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipGraphMemcpyNodeSetParamsToSymbol.src); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphMemcpyNodeSetParamsToSymbol.count); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphMemcpyNodeSetParamsToSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};


#define PROCESS_ARGS_hipStreamCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamCreate.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t *\",\"value\":\"%p\"}", args->hipStreamCreate.stream); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphNodeGetDependencies(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphNodeGetDependencies.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphNodeGetDependencies.node); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphNodeGetDependencies.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"pNumDependencies\":{\"type\":\"size_t*\",\"value\":\"%p\"}", args->hipGraphNodeGetDependencies.pNumDependencies); \
};

//	const textureReference* tex (unknown);
//	hipMipmappedArray_const_t mipmappedArray (unknown);
//	const hipChannelFormatDesc* desc (unknown);
#define PROCESS_ARGS_hipBindTextureToMipmappedArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipBindTextureToMipmappedArray.retval); \
	ratelprof_add_to_buffer(buf, "\"tex\":{\"type\":\"const textureReference*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"mipmappedArray\":{\"type\":\"hipMipmappedArray_const_t\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const hipChannelFormatDesc*\",\"value\":\"N/A\"},"); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraph_t hGraph (opaque);
#define PROCESS_ARGS_hipGraphExecUpdate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExecUpdate.retval); \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphExecUpdate.hGraphExec); \
	ratelprof_add_to_buffer(buf, "\"hGraph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphExecUpdate.hGraph); \
	ratelprof_add_to_buffer(buf, "\"hErrorNode_out\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphExecUpdate.hErrorNode_out); \
	ratelprof_add_to_buffer(buf, "\"updateResult_out\":{\"type\":\"hipGraphExecUpdateResult *\",\"value\":\"%p\"}", args->hipGraphExecUpdate.updateResult_out); \
};

//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceTotalMem(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceTotalMem.retval); \
	ratelprof_add_to_buffer(buf, "\"bytes\":{\"type\":\"size_t*\",\"value\":\"%p\"},", args->hipDeviceTotalMem.bytes); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipDeviceTotalMem.device); \
};

//	hipArray_const_t srcArray (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpyFromArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyFromArray.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpyFromArray.dst); \
	ratelprof_add_to_buffer(buf, "\"srcArray\":{\"type\":\"hipArray_const_t\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"wOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyFromArray.wOffset); \
	ratelprof_add_to_buffer(buf, "\"hOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyFromArray.hOffset); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyFromArray.count); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};

//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipEventCreateWithFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipEventCreateWithFlags.retval); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t *\",\"value\":\"%p\"},", args->hipEventCreateWithFlags.event); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipEventCreateWithFlags.flags); \
};


#define PROCESS_ARGS_hipDeviceGetCacheConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceGetCacheConfig.retval); \
	ratelprof_add_to_buffer(buf, "\"cacheConfig\":{\"type\":\"hipFuncCache_t *\",\"value\":\"%p\"}", args->hipDeviceGetCacheConfig.cacheConfig); \
};


#define PROCESS_ARGS_hipDriverGetVersion(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDriverGetVersion.retval); \
	ratelprof_add_to_buffer(buf, "\"driverVersion\":{\"type\":\"int *\",\"value\":\"%p\"}", args->hipDriverGetVersion.driverVersion); \
};

//	hipGraphNode_t node (opaque);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParams1D(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphMemcpyNodeSetParams1D.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphMemcpyNodeSetParams1D.node); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipGraphMemcpyNodeSetParams1D.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipGraphMemcpyNodeSetParams1D.src); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphMemcpyNodeSetParams1D.count); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};

//	textureReference* texRef (unknown);
//	float minMipMapLevelClamp (float);
//	float maxMipMapLevelClamp (float);
#define PROCESS_ARGS_hipTexRefSetMipmapLevelClamp(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefSetMipmapLevelClamp.retval); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"minMipMapLevelClamp\":{\"type\":\"float\",\"value\":\"%f\"},", args->hipTexRefSetMipmapLevelClamp.minMipMapLevelClamp); \
	ratelprof_add_to_buffer(buf, "\"maxMipMapLevelClamp\":{\"type\":\"float\",\"value\":\"%f\"}", args->hipTexRefSetMipmapLevelClamp.maxMipMapLevelClamp); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphMemAllocNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphMemAllocNodeGetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphMemAllocNodeGetParams.node); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"hipMemAllocNodeParams *\",\"value\":\"%p\"}", args->hipGraphMemAllocNodeGetParams.pNodeParams); \
};

//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexObjectDestroy.retval); \
	ratelprof_add_to_buffer(buf, "\"texObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"N/A\"},"); \
};

//	uint32_t cuMaskSize (unsigned int);
#define PROCESS_ARGS_hipExtStreamCreateWithCUMask(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipExtStreamCreateWithCUMask.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t *\",\"value\":\"%p\"},", args->hipExtStreamCreateWithCUMask.stream); \
	ratelprof_add_to_buffer(buf, "\"cuMaskSize\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipExtStreamCreateWithCUMask.cuMaskSize); \
	ratelprof_add_to_buffer(buf, "\"cuMask\":{\"type\":\"const uint32_t *\",\"value\":\"%p\"}", args->hipExtStreamCreateWithCUMask.cuMask); \
};


#define PROCESS_ARGS___hipPopCallConfiguration(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->__hipPopCallConfiguration.retval); \
	ratelprof_add_to_buffer(buf, "\"gridDim\":{\"type\":\"dim3 *\",\"value\":\"%p\"},", args->__hipPopCallConfiguration.gridDim); \
	ratelprof_add_to_buffer(buf, "\"blockDim\":{\"type\":\"dim3 *\",\"value\":\"%p\"},", args->__hipPopCallConfiguration.blockDim); \
	ratelprof_add_to_buffer(buf, "\"sharedMem\":{\"type\":\"size_t *\",\"value\":\"%p\"},", args->__hipPopCallConfiguration.sharedMem); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t *\",\"value\":\"%p\"}", args->__hipPopCallConfiguration.stream); \
};

//	size_t data_size (unsigned long);
//	hipMemRangeAttribute attribute (enum);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemRangeGetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemRangeGetAttribute.retval); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemRangeGetAttribute.data); \
	ratelprof_add_to_buffer(buf, "\"data_size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemRangeGetAttribute.data_size); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hipMemRangeAttribute\",\"value\":\"%d\"},", args->hipMemRangeGetAttribute.attribute); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemRangeGetAttribute.dev_ptr); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemRangeGetAttribute.count); \
};

//	size_t size (unsigned long);
//	size_t offset (unsigned long);
//	hipMemGenericAllocationHandle_t handle (opaque);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipMemMap(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemMap.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemMap.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemMap.size); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemMap.offset); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipMemGenericAllocationHandle_t\",\"value\":\"%p\"},", args->hipMemMap.handle); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned long long\",\"value\":\"%llu\"}", args->hipMemMap.flags); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipStreamSynchronize(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamSynchronize.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipStreamSynchronize.stream); \
};

//	hipHostFn_t destroy (function);
//	unsigned int initialRefcount (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipUserObjectCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipUserObjectCreate.retval); \
	ratelprof_add_to_buffer(buf, "\"object_out\":{\"type\":\"hipUserObject_t *\",\"value\":\"%p\"},", args->hipUserObjectCreate.object_out); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipUserObjectCreate.ptr); \
	ratelprof_add_to_buffer(buf, "\"destroy\":{\"type\":\"hipHostFn_t\",\"value\":\"%p\"},", args->hipUserObjectCreate.destroy); \
	ratelprof_add_to_buffer(buf, "\"initialRefcount\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipUserObjectCreate.initialRefcount); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipUserObjectCreate.flags); \
};

//	hipArray_t * levelArray (unknown);
//	hipMipmappedArray_const_t mipmappedArray (unknown);
//	unsigned int level (unsigned int);
#define PROCESS_ARGS_hipGetMipmappedArrayLevel(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGetMipmappedArrayLevel.retval); \
	ratelprof_add_to_buffer(buf, "\"levelArray\":{\"type\":\"hipArray_t *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"mipmappedArray\":{\"type\":\"hipMipmappedArray_const_t\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"level\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipGetMipmappedArrayLevel.level); \
};

//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemcpyHtoD(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyHtoD.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipMemcpyHtoD.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpyHtoD.src); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemcpyHtoD.sizeBytes); \
};


#define PROCESS_ARGS_hipMemGetAddressRange(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemGetAddressRange.retval); \
	ratelprof_add_to_buffer(buf, "\"pbase\":{\"type\":\"hipDeviceptr_t *\",\"value\":\"%p\"},", args->hipMemGetAddressRange.pbase); \
	ratelprof_add_to_buffer(buf, "\"psize\":{\"type\":\"size_t *\",\"value\":\"%p\"},", args->hipMemGetAddressRange.psize); \
	ratelprof_add_to_buffer(buf, "\"dptr\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"}", args->hipMemGetAddressRange.dptr); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphAddMemcpyNodeFromSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddMemcpyNodeFromSymbol.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNodeFromSymbol.pGraphNode); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNodeFromSymbol.graph); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNodeFromSymbol.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNodeFromSymbol.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNodeFromSymbol.dst); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNodeFromSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNodeFromSymbol.count); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNodeFromSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};


#define PROCESS_ARGS_hipMemPtrGetInfo(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemPtrGetInfo.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemPtrGetInfo.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t*\",\"value\":\"%p\"}", args->hipMemPtrGetInfo.size); \
};

//	textureReference* texRef (unknown);
//	struct hipMipmappedArray * mipmappedArray (unknown);
//	unsigned int Flags (unsigned int);
#define PROCESS_ARGS_hipTexRefSetMipmappedArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefSetMipmappedArray.retval); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"mipmappedArray\":{\"type\":\"struct hipMipmappedArray *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"Flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipTexRefSetMipmappedArray.Flags); \
};


#define PROCESS_ARGS_hipImportExternalSemaphore(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipImportExternalSemaphore.retval); \
	ratelprof_add_to_buffer(buf, "\"extSem_out\":{\"type\":\"hipExternalSemaphore_t *\",\"value\":\"%p\"},", args->hipImportExternalSemaphore.extSem_out); \
	ratelprof_add_to_buffer(buf, "\"semHandleDesc\":{\"type\":\"const hipExternalSemaphoreHandleDesc *\",\"value\":\"%p\"}", args->hipImportExternalSemaphore.semHandleDesc); \
};

//	hipStream_t stream (opaque);
//	hipEvent_t event (opaque);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamWaitEvent(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamWaitEvent.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamWaitEvent.stream); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"},", args->hipStreamWaitEvent.event); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipStreamWaitEvent.flags); \
};


#define PROCESS_ARGS_hipGetDeviceCount(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGetDeviceCount.retval); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"int *\",\"value\":\"%p\"}", args->hipGetDeviceCount.count); \
};

//	hipGraphNode_t hSrc (opaque);
//	hipGraphNode_t hDst (opaque);
#define PROCESS_ARGS_hipGraphKernelNodeCopyAttributes(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphKernelNodeCopyAttributes.retval); \
	ratelprof_add_to_buffer(buf, "\"hSrc\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphKernelNodeCopyAttributes.hSrc); \
	ratelprof_add_to_buffer(buf, "\"hDst\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"}", args->hipGraphKernelNodeCopyAttributes.hDst); \
};


#define PROCESS_ARGS_hipDestroyExternalSemaphore(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDestroyExternalSemaphore.retval); \
	ratelprof_add_to_buffer(buf, "\"extSem\":{\"type\":\"hipExternalSemaphore_t\",\"value\":\"%p\"}", args->hipDestroyExternalSemaphore.extSem); \
};

//	hipGraphNode_t node (opaque);
//	const hipMemcpy3DParms* pNodeParams (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphMemcpyNodeSetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphMemcpyNodeSetParams.node); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"const hipMemcpy3DParms*\",\"value\":\"N/A\"},"); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipStreamQuery(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamQuery.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipStreamQuery.stream); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphMemsetNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphMemsetNodeSetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphMemsetNodeSetParams.node); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"const hipMemsetParams *\",\"value\":\"%p\"}", args->hipGraphMemsetNodeSetParams.pNodeParams); \
};


#define PROCESS_ARGS_hipRuntimeGetVersion(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipRuntimeGetVersion.retval); \
	ratelprof_add_to_buffer(buf, "\"runtimeVersion\":{\"type\":\"int *\",\"value\":\"%p\"}", args->hipRuntimeGetVersion.runtimeVersion); \
};

//	HIP_ARRAY_DESCRIPTOR* pArrayDescriptor (unknown);
//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipArrayGetDescriptor(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipArrayGetDescriptor.retval); \
	ratelprof_add_to_buffer(buf, "\"pArrayDescriptor\":{\"type\":\"HIP_ARRAY_DESCRIPTOR*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t\",\"value\":\"N/A\"},"); \
};

//	int value (int);
//	size_t count (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemsetD32Async(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemsetD32Async.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipMemsetD32Async.dst); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemsetD32Async.value); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemsetD32Async.count); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemsetD32Async.stream); \
};


#define PROCESS_ARGS_hipCtxGetSharedMemConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxGetSharedMemConfig.retval); \
	ratelprof_add_to_buffer(buf, "\"pConfig\":{\"type\":\"hipSharedMemConfig *\",\"value\":\"%p\"}", args->hipCtxGetSharedMemConfig.pConfig); \
};

//	unsigned int numOptions (unsigned int);
#define PROCESS_ARGS_hipModuleLoadDataEx(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipModuleLoadDataEx.retval); \
	ratelprof_add_to_buffer(buf, "\"module\":{\"type\":\"hipModule_t *\",\"value\":\"%p\"},", args->hipModuleLoadDataEx.module); \
	ratelprof_add_to_buffer(buf, "\"image\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipModuleLoadDataEx.image); \
	ratelprof_add_to_buffer(buf, "\"numOptions\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLoadDataEx.numOptions); \
	ratelprof_add_to_buffer(buf, "\"options\":{\"type\":\"hipJitOption *\",\"value\":\"%p\"},", args->hipModuleLoadDataEx.options); \
	ratelprof_add_to_buffer(buf, "\"optionValues\":{\"type\":\"void **\",\"value\":\"%p\"}", args->hipModuleLoadDataEx.optionValues); \
};

//	hipMemPool_t mem_pool (opaque);
//	hipMemAllocationHandleType handle_type (enum);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMemPoolExportToShareableHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemPoolExportToShareableHandle.retval); \
	ratelprof_add_to_buffer(buf, "\"shared_handle\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemPoolExportToShareableHandle.shared_handle); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"%p\"},", args->hipMemPoolExportToShareableHandle.mem_pool); \
	ratelprof_add_to_buffer(buf, "\"handle_type\":{\"type\":\"hipMemAllocationHandleType\",\"value\":\"%d\"},", args->hipMemPoolExportToShareableHandle.handle_type); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMemPoolExportToShareableHandle.flags); \
};

//	size_t size (unsigned long);
//	hipMemPool_t mem_pool (opaque);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMallocFromPoolAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMallocFromPoolAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipMallocFromPoolAsync.dev_ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMallocFromPoolAsync.size); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"%p\"},", args->hipMallocFromPoolAsync.mem_pool); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMallocFromPoolAsync.stream); \
};

//	int deviceId (int);
#define PROCESS_ARGS_hipSetDevice(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipSetDevice.retval); \
	ratelprof_add_to_buffer(buf, "\"deviceId\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipSetDevice.deviceId); \
};

//	size_t size (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMallocAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMallocAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipMallocAsync.dev_ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMallocAsync.size); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMallocAsync.stream); \
};

//	int ordinal (int);
#define PROCESS_ARGS_hipDeviceGet(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceGet.retval); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t *\",\"value\":\"%p\"},", args->hipDeviceGet.device); \
	ratelprof_add_to_buffer(buf, "\"ordinal\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceGet.ordinal); \
};

//	int value (int);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemsetAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemsetAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemsetAsync.dst); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemsetAsync.value); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemsetAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemsetAsync.stream); \
};

//	size_t size (unsigned long);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemSetAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemSetAccess.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemSetAccess.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemSetAccess.size); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const hipMemAccessDesc *\",\"value\":\"%p\"},", args->hipMemSetAccess.desc); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemSetAccess.count); \
};

//	int value (int);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemsetD32(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemsetD32.retval); \
	ratelprof_add_to_buffer(buf, "\"dest\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipMemsetD32.dest); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemsetD32.value); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemsetD32.count); \
};


#define PROCESS_ARGS_hipGetDeviceFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGetDeviceFlags.retval); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int *\",\"value\":\"%p\"}", args->hipGetDeviceFlags.flags); \
};

//	int blockSize (int);
//	size_t dynSharedMemPerBlk (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.retval); \
	ratelprof_add_to_buffer(buf, "\"numBlocks\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.f); \
	ratelprof_add_to_buffer(buf, "\"blockSize\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.blockSize); \
	ratelprof_add_to_buffer(buf, "\"dynSharedMemPerBlk\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.dynSharedMemPerBlk); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.flags); \
};

//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceGetUuid(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceGetUuid.retval); \
	ratelprof_add_to_buffer(buf, "\"uuid\":{\"type\":\"hipUUID *\",\"value\":\"%p\"},", args->hipDeviceGetUuid.uuid); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipDeviceGetUuid.device); \
};

//	size_t dpitch (unsigned long);
//	size_t spitch (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpy2D(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpy2D.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpy2D.dst); \
	ratelprof_add_to_buffer(buf, "\"dpitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2D.dpitch); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpy2D.src); \
	ratelprof_add_to_buffer(buf, "\"spitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2D.spitch); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2D.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2D.height); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};

//	hipChannelFormatDesc * desc (unknown);
//	hipExtent * extent (unknown);
//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipArrayGetInfo(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipArrayGetInfo.retval); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"hipChannelFormatDesc *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"extent\":{\"type\":\"hipExtent *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int *\",\"value\":\"%p\"},", args->hipArrayGetInfo.flags); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t\",\"value\":\"N/A\"},"); \
};

//	hipUserObject_t object (opaque);
//	unsigned int count (unsigned int);
#define PROCESS_ARGS_hipUserObjectRetain(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipUserObjectRetain.retval); \
	ratelprof_add_to_buffer(buf, "\"object\":{\"type\":\"hipUserObject_t\",\"value\":\"%p\"},", args->hipUserObjectRetain.object); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipUserObjectRetain.count); \
};

//	int count (int);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipGraphicsMapResources(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphicsMapResources.retval); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipGraphicsMapResources.count); \
	ratelprof_add_to_buffer(buf, "\"resources\":{\"type\":\"hipGraphicsResource_t *\",\"value\":\"%p\"},", args->hipGraphicsMapResources.resources); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipGraphicsMapResources.stream); \
};

//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyHtoDAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyHtoDAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipMemcpyHtoDAsync.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpyHtoDAsync.src); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyHtoDAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemcpyHtoDAsync.stream); \
};

//	HIP_TEXTURE_DESC * pTexDesc (unknown);
//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectGetTextureDesc(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexObjectGetTextureDesc.retval); \
	ratelprof_add_to_buffer(buf, "\"pTexDesc\":{\"type\":\"HIP_TEXTURE_DESC *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"texObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"N/A\"},"); \
};


#define PROCESS_ARGS_hipMemGetAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemGetAccess.retval); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned long long *\",\"value\":\"%p\"},", args->hipMemGetAccess.flags); \
	ratelprof_add_to_buffer(buf, "\"location\":{\"type\":\"const hipMemLocation *\",\"value\":\"%p\"},", args->hipMemGetAccess.location); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipMemGetAccess.ptr); \
};

//	hipArray_t dst (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	size_t spitch (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpy2DToArrayAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpy2DToArrayAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipArray_t\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"wOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArrayAsync.wOffset); \
	ratelprof_add_to_buffer(buf, "\"hOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArrayAsync.hOffset); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpy2DToArrayAsync.src); \
	ratelprof_add_to_buffer(buf, "\"spitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArrayAsync.spitch); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArrayAsync.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArrayAsync.height); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemcpy2DToArrayAsync.stream); \
};

//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetAddress(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefGetAddress.retval); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"hipDeviceptr_t *\",\"value\":\"%p\"},", args->hipTexRefGetAddress.dev_ptr); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"N/A\"},"); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphNodeGetType(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphNodeGetType.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphNodeGetType.node); \
	ratelprof_add_to_buffer(buf, "\"pType\":{\"type\":\"hipGraphNodeType *\",\"value\":\"%p\"}", args->hipGraphNodeGetType.pType); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipStreamGetFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamGetFlags.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamGetFlags.stream); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int *\",\"value\":\"%p\"}", args->hipStreamGetFlags.flags); \
};

//	hipFunction_t f (opaque);
//	int blockSize (int);
//	size_t dynSharedMemPerBlk (unsigned long);
#define PROCESS_ARGS_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.retval); \
	ratelprof_add_to_buffer(buf, "\"numBlocks\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"hipFunction_t\",\"value\":\"%p\"},", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.f); \
	ratelprof_add_to_buffer(buf, "\"blockSize\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.blockSize); \
	ratelprof_add_to_buffer(buf, "\"dynSharedMemPerBlk\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.dynSharedMemPerBlk); \
};

//	size_t pitch (unsigned long);
//	int value (int);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemset2DAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemset2DAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemset2DAsync.dst); \
	ratelprof_add_to_buffer(buf, "\"pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemset2DAsync.pitch); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemset2DAsync.value); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemset2DAsync.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemset2DAsync.height); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemset2DAsync.stream); \
};

//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpyFromSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyFromSymbol.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpyFromSymbol.dst); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpyFromSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyFromSymbol.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyFromSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};


#define PROCESS_ARGS_hipHostFree(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipHostFree.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipHostFree.ptr); \
};

//	dim3 numBlocks ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	dim3 dimBlocks ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	size_t sharedMemBytes (unsigned long);
//	hipStream_t stream (opaque);
//	hipEvent_t startEvent (opaque);
//	hipEvent_t stopEvent (opaque);
//	int flags (int);
#define PROCESS_ARGS_hipExtLaunchKernel(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipExtLaunchKernel.retval); \
	ratelprof_add_to_buffer(buf, "\"function_address\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipExtLaunchKernel.function_address); \
	ratelprof_add_to_buffer(buf, "\"numBlocks\":{\"type\":\"struct dim3\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipExtLaunchKernel.numBlocks.x); \
	ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipExtLaunchKernel.numBlocks.y); \
	ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->hipExtLaunchKernel.numBlocks.z); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dimBlocks\":{\"type\":\"struct dim3\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipExtLaunchKernel.dimBlocks.x); \
	ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipExtLaunchKernel.dimBlocks.y); \
	ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->hipExtLaunchKernel.dimBlocks.z); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"args\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipExtLaunchKernel.args); \
	ratelprof_add_to_buffer(buf, "\"sharedMemBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipExtLaunchKernel.sharedMemBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipExtLaunchKernel.stream); \
	ratelprof_add_to_buffer(buf, "\"startEvent\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"},", args->hipExtLaunchKernel.startEvent); \
	ratelprof_add_to_buffer(buf, "\"stopEvent\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"},", args->hipExtLaunchKernel.stopEvent); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipExtLaunchKernel.flags); \
};

//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyFromSymbolAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyFromSymbolAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpyFromSymbolAsync.dst); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpyFromSymbolAsync.symbol); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyFromSymbolAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyFromSymbolAsync.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemcpyFromSymbolAsync.stream); \
};

//	unsigned int flags (unsigned int);
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipCtxCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxCreate.retval); \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t *\",\"value\":\"%p\"},", args->hipCtxCreate.ctx); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipCtxCreate.flags); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipCtxCreate.device); \
};

//	dim3 gridDim ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	dim3 blockDimX ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	unsigned int sharedMemBytes (unsigned int);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipLaunchCooperativeKernel(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipLaunchCooperativeKernel.retval); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipLaunchCooperativeKernel.f); \
	ratelprof_add_to_buffer(buf, "\"gridDim\":{\"type\":\"struct dim3\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipLaunchCooperativeKernel.gridDim.x); \
	ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipLaunchCooperativeKernel.gridDim.y); \
	ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->hipLaunchCooperativeKernel.gridDim.z); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"blockDimX\":{\"type\":\"struct dim3\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipLaunchCooperativeKernel.blockDimX.x); \
	ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipLaunchCooperativeKernel.blockDimX.y); \
	ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->hipLaunchCooperativeKernel.blockDimX.z); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"kernelParams\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipLaunchCooperativeKernel.kernelParams); \
	ratelprof_add_to_buffer(buf, "\"sharedMemBytes\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipLaunchCooperativeKernel.sharedMemBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipLaunchCooperativeKernel.stream); \
};

//	hipStream_t stream (opaque);
//	uint32_t cuMaskSize (unsigned int);
#define PROCESS_ARGS_hipExtStreamGetCUMask(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipExtStreamGetCUMask.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipExtStreamGetCUMask.stream); \
	ratelprof_add_to_buffer(buf, "\"cuMaskSize\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipExtStreamGetCUMask.cuMaskSize); \
	ratelprof_add_to_buffer(buf, "\"cuMask\":{\"type\":\"uint32_t *\",\"value\":\"%p\"}", args->hipExtStreamGetCUMask.cuMask); \
};

//	hipGraphExec_t graphExec (opaque);
#define PROCESS_ARGS_hipGraphExecDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExecDestroy.retval); \
	ratelprof_add_to_buffer(buf, "\"graphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"}", args->hipGraphExecDestroy.graphExec); \
};

//	hipError_t hipError (enum);
#define PROCESS_ARGS_hipDrvGetErrorString(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDrvGetErrorString.retval); \
	ratelprof_add_to_buffer(buf, "\"hipError\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDrvGetErrorString.hipError); \
	ratelprof_add_to_buffer(buf, "\"errorString\":{\"type\":\"const char **\",\"value\":\"%p\"}", args->hipDrvGetErrorString.errorString); \
};

//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipInit(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipInit.retval); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipInit.flags); \
};

//	const textureReference * tex (unknown);
//	const hipChannelFormatDesc * desc (unknown);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	size_t pitch (unsigned long);
#define PROCESS_ARGS_hipBindTexture2D(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipBindTexture2D.retval); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t *\",\"value\":\"%p\"},", args->hipBindTexture2D.offset); \
	ratelprof_add_to_buffer(buf, "\"tex\":{\"type\":\"const textureReference *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipBindTexture2D.devPtr); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const hipChannelFormatDesc *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipBindTexture2D.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipBindTexture2D.height); \
	ratelprof_add_to_buffer(buf, "\"pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipBindTexture2D.pitch); \
};

//	int device1 (int);
//	int device2 (int);
#define PROCESS_ARGS_hipExtGetLinkTypeAndHopCount(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipExtGetLinkTypeAndHopCount.retval); \
	ratelprof_add_to_buffer(buf, "\"device1\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipExtGetLinkTypeAndHopCount.device1); \
	ratelprof_add_to_buffer(buf, "\"device2\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipExtGetLinkTypeAndHopCount.device2); \
	ratelprof_add_to_buffer(buf, "\"linktype\":{\"type\":\"uint32_t *\",\"value\":\"%p\"},", args->hipExtGetLinkTypeAndHopCount.linktype); \
	ratelprof_add_to_buffer(buf, "\"hopcount\":{\"type\":\"uint32_t *\",\"value\":\"%p\"}", args->hipExtGetLinkTypeAndHopCount.hopcount); \
};

//	struct hipResourceViewDesc * pResViewDesc (unknown);
//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipGetTextureObjectResourceViewDesc(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGetTextureObjectResourceViewDesc.retval); \
	ratelprof_add_to_buffer(buf, "\"pResViewDesc\":{\"type\":\"struct hipResourceViewDesc *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"textureObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"N/A\"},"); \
};

//	size_t size (unsigned long);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipMemCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemCreate.retval); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipMemGenericAllocationHandle_t *\",\"value\":\"%p\"},", args->hipMemCreate.handle); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemCreate.size); \
	ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"const hipMemAllocationProp *\",\"value\":\"%p\"},", args->hipMemCreate.prop); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned long long\",\"value\":\"%llu\"}", args->hipMemCreate.flags); \
};

//	unsigned char value (unsigned char);
//	size_t count (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemsetD8Async(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemsetD8Async.retval); \
	ratelprof_add_to_buffer(buf, "\"dest\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipMemsetD8Async.dest); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"unsigned char\",\"value\":\"%hhu\"},", args->hipMemsetD8Async.value); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemsetD8Async.count); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemsetD8Async.stream); \
};

//	hipStream_t stream (opaque);
//	hipHostFn_t fn (function);
#define PROCESS_ARGS_hipLaunchHostFunc(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipLaunchHostFunc.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipLaunchHostFunc.stream); \
	ratelprof_add_to_buffer(buf, "\"fn\":{\"type\":\"hipHostFn_t\",\"value\":\"%p\"},", args->hipLaunchHostFunc.fn); \
	ratelprof_add_to_buffer(buf, "\"userData\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipLaunchHostFunc.userData); \
};

//	hipGraph_t graph (opaque);
#define PROCESS_ARGS_hipGraphGetEdges(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphGetEdges.retval); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphGetEdges.graph); \
	ratelprof_add_to_buffer(buf, "\"from\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphGetEdges.from); \
	ratelprof_add_to_buffer(buf, "\"to\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphGetEdges.to); \
	ratelprof_add_to_buffer(buf, "\"numEdges\":{\"type\":\"size_t *\",\"value\":\"%p\"}", args->hipGraphGetEdges.numEdges); \
};

//	hipMemPool_t mem_pool (opaque);
#define PROCESS_ARGS_hipMemPoolDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemPoolDestroy.retval); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"%p\"}", args->hipMemPoolDestroy.mem_pool); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphKernelNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphKernelNodeGetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphKernelNodeGetParams.node); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"hipKernelNodeParams *\",\"value\":\"%p\"}", args->hipGraphKernelNodeGetParams.pNodeParams); \
};

//	unsigned int numAttributes (unsigned int);
//	hipPointer_attribute * attributes (unknown);
#define PROCESS_ARGS_hipDrvPointerGetAttributes(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDrvPointerGetAttributes.retval); \
	ratelprof_add_to_buffer(buf, "\"numAttributes\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipDrvPointerGetAttributes.numAttributes); \
	ratelprof_add_to_buffer(buf, "\"attributes\":{\"type\":\"hipPointer_attribute *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipDrvPointerGetAttributes.data); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"}", args->hipDrvPointerGetAttributes.ptr); \
};

//	hipFuncAttribute attr (enum);
//	int value (int);
#define PROCESS_ARGS_hipFuncSetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipFuncSetAttribute.retval); \
	ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipFuncSetAttribute.func); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipFuncAttribute\",\"value\":\"%d\"},", args->hipFuncSetAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipFuncSetAttribute.value); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphAddDependencies(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddDependencies.retval); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddDependencies.graph); \
	ratelprof_add_to_buffer(buf, "\"from\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddDependencies.from); \
	ratelprof_add_to_buffer(buf, "\"to\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddDependencies.to); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipGraphAddDependencies.numDependencies); \
};

//	hipStream_t stream (opaque);
//	uint64_t value (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamWriteValue64(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamWriteValue64.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamWriteValue64.stream); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipStreamWriteValue64.ptr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hipStreamWriteValue64.value); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipStreamWriteValue64.flags); \
};

//	hipSurfaceObject_t* pSurfObject (unknown);
//	const hipResourceDesc* pResDesc (unknown);
#define PROCESS_ARGS_hipCreateSurfaceObject(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCreateSurfaceObject.retval); \
	ratelprof_add_to_buffer(buf, "\"pSurfObject\":{\"type\":\"hipSurfaceObject_t*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"pResDesc\":{\"type\":\"const hipResourceDesc*\",\"value\":\"N/A\"},"); \
};

//	hipTextureDesc* pTexDesc (unknown);
//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipGetTextureObjectTextureDesc(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGetTextureObjectTextureDesc.retval); \
	ratelprof_add_to_buffer(buf, "\"pTexDesc\":{\"type\":\"hipTextureDesc*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"textureObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"N/A\"},"); \
};

//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMemUnmap(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemUnmap.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemUnmap.ptr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemUnmap.size); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphChildGraphNodeGetGraph(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphChildGraphNodeGetGraph.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphChildGraphNodeGetGraph.node); \
	ratelprof_add_to_buffer(buf, "\"pGraph\":{\"type\":\"hipGraph_t *\",\"value\":\"%p\"}", args->hipGraphChildGraphNodeGetGraph.pGraph); \
};

//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamCreateWithFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamCreateWithFlags.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t *\",\"value\":\"%p\"},", args->hipStreamCreateWithFlags.stream); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipStreamCreateWithFlags.flags); \
};


#define PROCESS_ARGS_hipMemPoolCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemPoolCreate.retval); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t *\",\"value\":\"%p\"},", args->hipMemPoolCreate.mem_pool); \
	ratelprof_add_to_buffer(buf, "\"pool_props\":{\"type\":\"const hipMemPoolProps *\",\"value\":\"%p\"}", args->hipMemPoolCreate.pool_props); \
};

//	int numDevices (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipLaunchCooperativeKernelMultiDevice(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipLaunchCooperativeKernelMultiDevice.retval); \
	ratelprof_add_to_buffer(buf, "\"launchParamsList\":{\"type\":\"hipLaunchParams *\",\"value\":\"%p\"},", args->hipLaunchCooperativeKernelMultiDevice.launchParamsList); \
	ratelprof_add_to_buffer(buf, "\"numDevices\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipLaunchCooperativeKernelMultiDevice.numDevices); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipLaunchCooperativeKernelMultiDevice.flags); \
};

//	textureReference* texRef (unknown);
//	enum hipTextureFilterMode fm (enum);
#define PROCESS_ARGS_hipTexRefSetFilterMode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefSetFilterMode.retval); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"fm\":{\"type\":\"enum hipTextureFilterMode\",\"value\":\"%d\"}", args->hipTexRefSetFilterMode.fm); \
};

//	int device (int);
//	hipGraphMemAttributeType attr (enum);
#define PROCESS_ARGS_hipDeviceSetGraphMemAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceSetGraphMemAttribute.retval); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceSetGraphMemAttribute.device); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipGraphMemAttributeType\",\"value\":\"%d\"},", args->hipDeviceSetGraphMemAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipDeviceSetGraphMemAttribute.value); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParams1D(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExecMemcpyNodeSetParams1D.retval); \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphExecMemcpyNodeSetParams1D.hGraphExec); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExecMemcpyNodeSetParams1D.node); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipGraphExecMemcpyNodeSetParams1D.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipGraphExecMemcpyNodeSetParams1D.src); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphExecMemcpyNodeSetParams1D.count); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphExecKernelNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExecKernelNodeSetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphExecKernelNodeSetParams.hGraphExec); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExecKernelNodeSetParams.node); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"const hipKernelNodeParams *\",\"value\":\"%p\"}", args->hipGraphExecKernelNodeSetParams.pNodeParams); \
};

//	hipGraph_t graph (opaque);
//	size_t bufferSize (unsigned long);
#define PROCESS_ARGS_hipGraphInstantiate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphInstantiate.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphExec\":{\"type\":\"hipGraphExec_t *\",\"value\":\"%p\"},", args->hipGraphInstantiate.pGraphExec); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphInstantiate.graph); \
	ratelprof_add_to_buffer(buf, "\"pErrorNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphInstantiate.pErrorNode); \
	ratelprof_add_to_buffer(buf, "\"pLogBuffer\":{\"type\":\"char *\",\"value\":\"%p\"},", args->hipGraphInstantiate.pLogBuffer); \
	ratelprof_add_to_buffer(buf, "\"bufferSize\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipGraphInstantiate.bufferSize); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t hNode (opaque);
#define PROCESS_ARGS_hipGraphExecExternalSemaphoresSignalNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExecExternalSemaphoresSignalNodeSetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphExecExternalSemaphoresSignalNodeSetParams.hGraphExec); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExecExternalSemaphoresSignalNodeSetParams.hNode); \
	ratelprof_add_to_buffer(buf, "\"nodeParams\":{\"type\":\"const hipExternalSemaphoreSignalNodeParams *\",\"value\":\"%p\"}", args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams); \
};

//	hipTextureObject_t* pTexObject (unknown);
//	const hipResourceDesc* pResDesc (unknown);
//	const hipTextureDesc* pTexDesc (unknown);
//	const struct hipResourceViewDesc * pResViewDesc (unknown);
#define PROCESS_ARGS_hipCreateTextureObject(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCreateTextureObject.retval); \
	ratelprof_add_to_buffer(buf, "\"pTexObject\":{\"type\":\"hipTextureObject_t*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"pResDesc\":{\"type\":\"const hipResourceDesc*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"pTexDesc\":{\"type\":\"const hipTextureDesc*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"pResViewDesc\":{\"type\":\"const struct hipResourceViewDesc *\",\"value\":\"N/A\"},"); \
};

//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipEventQuery(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipEventQuery.retval); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"}", args->hipEventQuery.event); \
};

//	hipCtx_t ctx (opaque);
#define PROCESS_ARGS_hipCtxPushCurrent(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxPushCurrent.retval); \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t\",\"value\":\"%p\"}", args->hipCtxPushCurrent.ctx); \
};

//	hipGraph_t graph (opaque);
#define PROCESS_ARGS_hipGraphGetRootNodes(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphGetRootNodes.retval); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphGetRootNodes.graph); \
	ratelprof_add_to_buffer(buf, "\"pRootNodes\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphGetRootNodes.pRootNodes); \
	ratelprof_add_to_buffer(buf, "\"pNumRootNodes\":{\"type\":\"size_t *\",\"value\":\"%p\"}", args->hipGraphGetRootNodes.pNumRootNodes); \
};

//	hipError_t hipError (enum);
#define PROCESS_ARGS_hipGetErrorString(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"const char *\",\"value\":\"%s\"},", args->hipGetErrorString.retval); \
	ratelprof_add_to_buffer(buf, "\"hipError\":{\"type\":\"hipError_t\",\"value\":\"%d\"}", args->hipGetErrorString.hipError); \
};

//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMemAddressFree(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemAddressFree.retval); \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemAddressFree.devPtr); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemAddressFree.size); \
};


#define PROCESS_ARGS_hipDeviceSynchronize(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceSynchronize.retval); \
\
};


#define PROCESS_ARGS_hipCtxGetFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxGetFlags.retval); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int *\",\"value\":\"%p\"}", args->hipCtxGetFlags.flags); \
};

//	hipArray_t* pArray (unknown);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefGetArray.retval); \
	ratelprof_add_to_buffer(buf, "\"pArray\":{\"type\":\"hipArray_t*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"N/A\"},"); \
};

//	hipMemAllocationGranularity_flags option (enum);
#define PROCESS_ARGS_hipMemGetAllocationGranularity(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemGetAllocationGranularity.retval); \
	ratelprof_add_to_buffer(buf, "\"granularity\":{\"type\":\"size_t *\",\"value\":\"%p\"},", args->hipMemGetAllocationGranularity.granularity); \
	ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"const hipMemAllocationProp *\",\"value\":\"%p\"},", args->hipMemGetAllocationGranularity.prop); \
	ratelprof_add_to_buffer(buf, "\"option\":{\"type\":\"hipMemAllocationGranularity_flags\",\"value\":\"%d\"}", args->hipMemGetAllocationGranularity.option); \
};


#define PROCESS_ARGS_hipProfilerStop(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipProfilerStop.retval); \
\
};

//	textureReference* tex (unknown);
//	hipArray_const_t array (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipTexRefSetArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefSetArray.retval); \
	ratelprof_add_to_buffer(buf, "\"tex\":{\"type\":\"textureReference*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_const_t\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipTexRefSetArray.flags); \
};

//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipEventDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipEventDestroy.retval); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"}", args->hipEventDestroy.event); \
};

//	hipFuncCache_t cacheConfig (enum);
#define PROCESS_ARGS_hipDeviceSetCacheConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceSetCacheConfig.retval); \
	ratelprof_add_to_buffer(buf, "\"cacheConfig\":{\"type\":\"hipFuncCache_t\",\"value\":\"%d\"}", args->hipDeviceSetCacheConfig.cacheConfig); \
};


#define PROCESS_ARGS_hipLaunchByPtr(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipLaunchByPtr.retval); \
	ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"const void *\",\"value\":\"%p\"}", args->hipLaunchByPtr.func); \
};

//	unsigned int numDevices (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipModuleLaunchCooperativeKernelMultiDevice(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipModuleLaunchCooperativeKernelMultiDevice.retval); \
	ratelprof_add_to_buffer(buf, "\"launchParamsList\":{\"type\":\"hipFunctionLaunchParams *\",\"value\":\"%p\"},", args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList); \
	ratelprof_add_to_buffer(buf, "\"numDevices\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernelMultiDevice.numDevices); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipModuleLaunchCooperativeKernelMultiDevice.flags); \
};

//	textureReference* texRef (unknown);
//	int dim (int);
//	enum hipTextureAddressMode am (enum);
#define PROCESS_ARGS_hipTexRefSetAddressMode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefSetAddressMode.retval); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"dim\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipTexRefSetAddressMode.dim); \
	ratelprof_add_to_buffer(buf, "\"am\":{\"type\":\"enum hipTextureAddressMode\",\"value\":\"%d\"}", args->hipTexRefSetAddressMode.am); \
};


#define PROCESS_ARGS_hipModuleLoadData(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipModuleLoadData.retval); \
	ratelprof_add_to_buffer(buf, "\"module\":{\"type\":\"hipModule_t *\",\"value\":\"%p\"},", args->hipModuleLoadData.module); \
	ratelprof_add_to_buffer(buf, "\"image\":{\"type\":\"const void *\",\"value\":\"%p\"}", args->hipModuleLoadData.image); \
};

//	const hip_Memcpy2D * pCopy (unknown);
#define PROCESS_ARGS_hipDrvMemcpy2DUnaligned(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDrvMemcpy2DUnaligned.retval); \
	ratelprof_add_to_buffer(buf, "\"pCopy\":{\"type\":\"const hip_Memcpy2D *\",\"value\":\"N/A\"},"); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
//	hipGraph_t childGraph (opaque);
#define PROCESS_ARGS_hipGraphExecChildGraphNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExecChildGraphNodeSetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphExecChildGraphNodeSetParams.hGraphExec); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExecChildGraphNodeSetParams.node); \
	ratelprof_add_to_buffer(buf, "\"childGraph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"}", args->hipGraphExecChildGraphNodeSetParams.childGraph); \
};


#define PROCESS_ARGS_hipPointerGetAttributes(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipPointerGetAttributes.retval); \
	ratelprof_add_to_buffer(buf, "\"attributes\":{\"type\":\"hipPointerAttribute_t *\",\"value\":\"%p\"},", args->hipPointerGetAttributes.attributes); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"const void *\",\"value\":\"%p\"}", args->hipPointerGetAttributes.ptr); \
};

//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyDtoHAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyDtoHAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpyDtoHAsync.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipMemcpyDtoHAsync.src); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyDtoHAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemcpyDtoHAsync.stream); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipGraphAddEventRecordNode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddEventRecordNode.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddEventRecordNode.pGraphNode); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddEventRecordNode.graph); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddEventRecordNode.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddEventRecordNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"}", args->hipGraphAddEventRecordNode.event); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphAddExternalSemaphoresSignalNode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddExternalSemaphoresSignalNode.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddExternalSemaphoresSignalNode.pGraphNode); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddExternalSemaphoresSignalNode.graph); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddExternalSemaphoresSignalNode.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddExternalSemaphoresSignalNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"nodeParams\":{\"type\":\"const hipExternalSemaphoreSignalNodeParams *\",\"value\":\"%p\"}", args->hipGraphAddExternalSemaphoresSignalNode.nodeParams); \
};

//	hipGraph_t graph (opaque);
//	hipUserObject_t object (opaque);
//	unsigned int count (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipGraphRetainUserObject(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphRetainUserObject.retval); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphRetainUserObject.graph); \
	ratelprof_add_to_buffer(buf, "\"object\":{\"type\":\"hipUserObject_t\",\"value\":\"%p\"},", args->hipGraphRetainUserObject.object); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipGraphRetainUserObject.count); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipGraphRetainUserObject.flags); \
};

//	size_t size (unsigned long);
//	size_t offset (unsigned long);
#define PROCESS_ARGS_hipSetupArgument(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipSetupArgument.retval); \
	ratelprof_add_to_buffer(buf, "\"arg\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipSetupArgument.arg); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipSetupArgument.size); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipSetupArgument.offset); \
};

//	size_t widthInBytes (unsigned long);
//	size_t height (unsigned long);
//	unsigned int elementSizeBytes (unsigned int);
#define PROCESS_ARGS_hipMemAllocPitch(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemAllocPitch.retval); \
	ratelprof_add_to_buffer(buf, "\"dptr\":{\"type\":\"hipDeviceptr_t *\",\"value\":\"%p\"},", args->hipMemAllocPitch.dptr); \
	ratelprof_add_to_buffer(buf, "\"pitch\":{\"type\":\"size_t*\",\"value\":\"%p\"},", args->hipMemAllocPitch.pitch); \
	ratelprof_add_to_buffer(buf, "\"widthInBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemAllocPitch.widthInBytes); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemAllocPitch.height); \
	ratelprof_add_to_buffer(buf, "\"elementSizeBytes\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMemAllocPitch.elementSizeBytes); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphEventWaitNodeGetEvent(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphEventWaitNodeGetEvent.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphEventWaitNodeGetEvent.node); \
	ratelprof_add_to_buffer(buf, "\"event_out\":{\"type\":\"hipEvent_t *\",\"value\":\"%p\"}", args->hipGraphEventWaitNodeGetEvent.event_out); \
};

//	hipArray_t dst (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	size_t spitch (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpy2DToArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpy2DToArray.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipArray_t\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"wOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArray.wOffset); \
	ratelprof_add_to_buffer(buf, "\"hOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArray.hOffset); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpy2DToArray.src); \
	ratelprof_add_to_buffer(buf, "\"spitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArray.spitch); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArray.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArray.height); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};

//	int dstDeviceId (int);
//	int srcDevice (int);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyPeerAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyPeerAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpyPeerAsync.dst); \
	ratelprof_add_to_buffer(buf, "\"dstDeviceId\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemcpyPeerAsync.dstDeviceId); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpyPeerAsync.src); \
	ratelprof_add_to_buffer(buf, "\"srcDevice\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemcpyPeerAsync.srcDevice); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyPeerAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemcpyPeerAsync.stream); \
};

//	hipTextureObject_t* pTexObject (unknown);
//	const HIP_RESOURCE_DESC* pResDesc (unknown);
//	const HIP_TEXTURE_DESC* pTexDesc (unknown);
//	const HIP_RESOURCE_VIEW_DESC* pResViewDesc (unknown);
#define PROCESS_ARGS_hipTexObjectCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexObjectCreate.retval); \
	ratelprof_add_to_buffer(buf, "\"pTexObject\":{\"type\":\"hipTextureObject_t*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"pResDesc\":{\"type\":\"const HIP_RESOURCE_DESC*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"pTexDesc\":{\"type\":\"const HIP_TEXTURE_DESC*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"pResViewDesc\":{\"type\":\"const HIP_RESOURCE_VIEW_DESC*\",\"value\":\"N/A\"},"); \
};

//	enum hipLimit_t limit (enum);
#define PROCESS_ARGS_hipDeviceGetLimit(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceGetLimit.retval); \
	ratelprof_add_to_buffer(buf, "\"pValue\":{\"type\":\"size_t *\",\"value\":\"%p\"},", args->hipDeviceGetLimit.pValue); \
	ratelprof_add_to_buffer(buf, "\"limit\":{\"type\":\"enum hipLimit_t\",\"value\":\"%d\"}", args->hipDeviceGetLimit.limit); \
};

//	size_t sizeBytes (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipExtMallocWithFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipExtMallocWithFlags.retval); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipExtMallocWithFlags.ptr); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipExtMallocWithFlags.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipExtMallocWithFlags.flags); \
};

//	hipError_t hip_error (enum);
#define PROCESS_ARGS_hipGetErrorName(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"const char *\",\"value\":\"%s\"},", args->hipGetErrorName.retval); \
	ratelprof_add_to_buffer(buf, "\"hip_error\":{\"type\":\"hipError_t\",\"value\":\"%d\"}", args->hipGetErrorName.hip_error); \
};

//	const struct hipMemcpy3DParms * p (unknown);
#define PROCESS_ARGS_hipMemcpy3D(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpy3D.retval); \
	ratelprof_add_to_buffer(buf, "\"p\":{\"type\":\"const struct hipMemcpy3DParms *\",\"value\":\"N/A\"},"); \
};

//	hipGraphNode_t node (opaque);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParamsFromSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphMemcpyNodeSetParamsFromSymbol.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphMemcpyNodeSetParamsFromSymbol.node); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipGraphMemcpyNodeSetParamsFromSymbol.dst); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipGraphMemcpyNodeSetParamsFromSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphMemcpyNodeSetParamsFromSymbol.count); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphMemcpyNodeSetParamsFromSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};

//	size_t num_attributes (unsigned long);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemRangeGetAttributes(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemRangeGetAttributes.retval); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipMemRangeGetAttributes.data); \
	ratelprof_add_to_buffer(buf, "\"data_sizes\":{\"type\":\"size_t *\",\"value\":\"%p\"},", args->hipMemRangeGetAttributes.data_sizes); \
	ratelprof_add_to_buffer(buf, "\"attributes\":{\"type\":\"hipMemRangeAttribute *\",\"value\":\"%p\"},", args->hipMemRangeGetAttributes.attributes); \
	ratelprof_add_to_buffer(buf, "\"num_attributes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemRangeGetAttributes.num_attributes); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemRangeGetAttributes.dev_ptr); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemRangeGetAttributes.count); \
};

//	hipGraph_t graph (opaque);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipGraphDebugDotPrint(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphDebugDotPrint.retval); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphDebugDotPrint.graph); \
	ratelprof_add_to_buffer(buf, "\"path\":{\"type\":\"const char *\",\"value\":\"%p\"},", args->hipGraphDebugDotPrint.path); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipGraphDebugDotPrint.flags); \
};

//	hipGraphNode_t hNode (opaque);
#define PROCESS_ARGS_hipGraphExternalSemaphoresWaitNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExternalSemaphoresWaitNodeGetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExternalSemaphoresWaitNodeGetParams.hNode); \
	ratelprof_add_to_buffer(buf, "\"params_out\":{\"type\":\"hipExternalSemaphoreWaitNodeParams *\",\"value\":\"%p\"}", args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out); \
};

//	int value (int);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemset(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemset.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemset.dst); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemset.value); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemset.sizeBytes); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphAddHostNode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddHostNode.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddHostNode.pGraphNode); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddHostNode.graph); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddHostNode.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddHostNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"const hipHostNodeParams*\",\"value\":\"%p\"}", args->hipGraphAddHostNode.pNodeParams); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
//	const hipMemcpy3DParms* pCopyParams (unknown);
#define PROCESS_ARGS_hipGraphAddMemcpyNode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddMemcpyNode.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNode.pGraphNode); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNode.graph); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNode.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"pCopyParams\":{\"type\":\"const hipMemcpy3DParms*\",\"value\":\"N/A\"},"); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphHostNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphHostNodeGetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphHostNodeGetParams.node); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"hipHostNodeParams *\",\"value\":\"%p\"}", args->hipGraphHostNodeGetParams.pNodeParams); \
};


#define PROCESS_ARGS_hipDeviceGetByPCIBusId(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceGetByPCIBusId.retval); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipDeviceGetByPCIBusId.device); \
	ratelprof_add_to_buffer(buf, "\"pciBusId\":{\"type\":\"const char *\",\"value\":\"%p\"}", args->hipDeviceGetByPCIBusId.pciBusId); \
};

//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemcpyDtoD(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyDtoD.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipMemcpyDtoD.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipMemcpyDtoD.src); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemcpyDtoD.sizeBytes); \
};

//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipIpcGetEventHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipIpcGetEventHandle.retval); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipIpcEventHandle_t *\",\"value\":\"%p\"},", args->hipIpcGetEventHandle.handle); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"}", args->hipIpcGetEventHandle.event); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphKernelNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphKernelNodeSetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphKernelNodeSetParams.node); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"const hipKernelNodeParams *\",\"value\":\"%p\"}", args->hipGraphKernelNodeSetParams.pNodeParams); \
};

//	hipModule_t module (opaque);
#define PROCESS_ARGS_hipModuleGetFunction(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipModuleGetFunction.retval); \
	ratelprof_add_to_buffer(buf, "\"function\":{\"type\":\"hipFunction_t *\",\"value\":\"%p\"},", args->hipModuleGetFunction.function); \
	ratelprof_add_to_buffer(buf, "\"module\":{\"type\":\"hipModule_t\",\"value\":\"%p\"},", args->hipModuleGetFunction.module); \
	ratelprof_add_to_buffer(buf, "\"kname\":{\"type\":\"const char *\",\"value\":\"%p\"}", args->hipModuleGetFunction.kname); \
};

//	hipArray_t srcArray (unknown);
//	size_t srcOffset (unsigned long);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemcpyAtoH(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyAtoH.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpyAtoH.dst); \
	ratelprof_add_to_buffer(buf, "\"srcArray\":{\"type\":\"hipArray_t\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"srcOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyAtoH.srcOffset); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemcpyAtoH.count); \
};

//	int peerDeviceId (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipDeviceEnablePeerAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceEnablePeerAccess.retval); \
	ratelprof_add_to_buffer(buf, "\"peerDeviceId\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceEnablePeerAccess.peerDeviceId); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipDeviceEnablePeerAccess.flags); \
};


#define PROCESS_ARGS_hipMemRetainAllocationHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemRetainAllocationHandle.retval); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipMemGenericAllocationHandle_t *\",\"value\":\"%p\"},", args->hipMemRetainAllocationHandle.handle); \
	ratelprof_add_to_buffer(buf, "\"addr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipMemRetainAllocationHandle.addr); \
};

//	hipMipmappedArray_t* pArray (unknown);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipMappedArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefGetMipMappedArray.retval); \
	ratelprof_add_to_buffer(buf, "\"pArray\":{\"type\":\"hipMipmappedArray_t*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"N/A\"},"); \
};

//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipmapLevelBias(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefGetMipmapLevelBias.retval); \
	ratelprof_add_to_buffer(buf, "\"pbias\":{\"type\":\"float *\",\"value\":\"%p\"},", args->hipTexRefGetMipmapLevelBias.pbias); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"N/A\"},"); \
};

//	const textureReference* tex (unknown);
//	const hipChannelFormatDesc * desc (unknown);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipBindTexture(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipBindTexture.retval); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t *\",\"value\":\"%p\"},", args->hipBindTexture.offset); \
	ratelprof_add_to_buffer(buf, "\"tex\":{\"type\":\"const textureReference*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipBindTexture.devPtr); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const hipChannelFormatDesc *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipBindTexture.size); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
//	hipGraph_t childGraph (opaque);
#define PROCESS_ARGS_hipGraphAddChildGraphNode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddChildGraphNode.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddChildGraphNode.pGraphNode); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddChildGraphNode.graph); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddChildGraphNode.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddChildGraphNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"childGraph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"}", args->hipGraphAddChildGraphNode.childGraph); \
};

//	enum hipLimit_t limit (enum);
//	size_t value (unsigned long);
#define PROCESS_ARGS_hipDeviceSetLimit(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceSetLimit.retval); \
	ratelprof_add_to_buffer(buf, "\"limit\":{\"type\":\"enum hipLimit_t\",\"value\":\"%d\"},", args->hipDeviceSetLimit.limit); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipDeviceSetLimit.value); \
};

//	hipChannelFormatDesc * desc (unknown);
//	hipArray_const_t array (unknown);
#define PROCESS_ARGS_hipGetChannelDesc(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGetChannelDesc.retval); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"hipChannelFormatDesc *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_const_t\",\"value\":\"N/A\"},"); \
};

//	hipGraphicsResource_t resource (opaque);
#define PROCESS_ARGS_hipGraphicsUnregisterResource(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphicsUnregisterResource.retval); \
	ratelprof_add_to_buffer(buf, "\"resource\":{\"type\":\"hipGraphicsResource_t\",\"value\":\"%p\"}", args->hipGraphicsUnregisterResource.resource); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphRemoveDependencies(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphRemoveDependencies.retval); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphRemoveDependencies.graph); \
	ratelprof_add_to_buffer(buf, "\"from\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphRemoveDependencies.from); \
	ratelprof_add_to_buffer(buf, "\"to\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphRemoveDependencies.to); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipGraphRemoveDependencies.numDependencies); \
};

//	textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefSetBorderColor(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefSetBorderColor.retval); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"pBorderColor\":{\"type\":\"float *\",\"value\":\"%p\"}", args->hipTexRefSetBorderColor.pBorderColor); \
};

//	hipDevice_t dev (int);
#define PROCESS_ARGS_hipDevicePrimaryCtxGetState(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDevicePrimaryCtxGetState.retval); \
	ratelprof_add_to_buffer(buf, "\"dev\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"},", args->hipDevicePrimaryCtxGetState.dev); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int *\",\"value\":\"%p\"},", args->hipDevicePrimaryCtxGetState.flags); \
	ratelprof_add_to_buffer(buf, "\"active\":{\"type\":\"int *\",\"value\":\"%p\"}", args->hipDevicePrimaryCtxGetState.active); \
};

//	hipPitchedPtr* pitchedDevPtr (unknown);
//	hipExtent extent (unknown);
#define PROCESS_ARGS_hipMalloc3D(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMalloc3D.retval); \
	ratelprof_add_to_buffer(buf, "\"pitchedDevPtr\":{\"type\":\"hipPitchedPtr*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"extent\":{\"type\":\"hipExtent\",\"value\":\"N/A\"},"); \
};

//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipmapLevelClamp(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefGetMipmapLevelClamp.retval); \
	ratelprof_add_to_buffer(buf, "\"pminMipmapLevelClamp\":{\"type\":\"float *\",\"value\":\"%p\"},", args->hipTexRefGetMipmapLevelClamp.pminMipmapLevelClamp); \
	ratelprof_add_to_buffer(buf, "\"pmaxMipmapLevelClamp\":{\"type\":\"float *\",\"value\":\"%p\"},", args->hipTexRefGetMipmapLevelClamp.pmaxMipmapLevelClamp); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"N/A\"},"); \
};

//	hipFunction_t f (opaque);
//	unsigned int gridDimX (unsigned int);
//	unsigned int gridDimY (unsigned int);
//	unsigned int gridDimZ (unsigned int);
//	unsigned int blockDimX (unsigned int);
//	unsigned int blockDimY (unsigned int);
//	unsigned int blockDimZ (unsigned int);
//	unsigned int sharedMemBytes (unsigned int);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipModuleLaunchKernel(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipModuleLaunchKernel.retval); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"hipFunction_t\",\"value\":\"%p\"},", args->hipModuleLaunchKernel.f); \
	ratelprof_add_to_buffer(buf, "\"gridDimX\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchKernel.gridDimX); \
	ratelprof_add_to_buffer(buf, "\"gridDimY\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchKernel.gridDimY); \
	ratelprof_add_to_buffer(buf, "\"gridDimZ\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchKernel.gridDimZ); \
	ratelprof_add_to_buffer(buf, "\"blockDimX\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchKernel.blockDimX); \
	ratelprof_add_to_buffer(buf, "\"blockDimY\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchKernel.blockDimY); \
	ratelprof_add_to_buffer(buf, "\"blockDimZ\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchKernel.blockDimZ); \
	ratelprof_add_to_buffer(buf, "\"sharedMemBytes\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchKernel.sharedMemBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipModuleLaunchKernel.stream); \
	ratelprof_add_to_buffer(buf, "\"kernelParams\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipModuleLaunchKernel.kernelParams); \
	ratelprof_add_to_buffer(buf, "\"extra\":{\"type\":\"void **\",\"value\":\"%p\"}", args->hipModuleLaunchKernel.extra); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipKernelNameRefByPtr(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"const char *\",\"value\":\"%s\"},", args->hipKernelNameRefByPtr.retval); \
	ratelprof_add_to_buffer(buf, "\"hostFunction\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipKernelNameRefByPtr.hostFunction); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipKernelNameRefByPtr.stream); \
};

//	hipSharedMemConfig config (enum);
#define PROCESS_ARGS_hipDeviceSetSharedMemConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceSetSharedMemConfig.retval); \
	ratelprof_add_to_buffer(buf, "\"config\":{\"type\":\"hipSharedMemConfig\",\"value\":\"%d\"}", args->hipDeviceSetSharedMemConfig.config); \
};

//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyToSymbolAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyToSymbolAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpyToSymbolAsync.symbol); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpyToSymbolAsync.src); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyToSymbolAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyToSymbolAsync.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemcpyToSymbolAsync.stream); \
};

//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostGetDevicePointer(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipHostGetDevicePointer.retval); \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipHostGetDevicePointer.devPtr); \
	ratelprof_add_to_buffer(buf, "\"hstPtr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipHostGetDevicePointer.hstPtr); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipHostGetDevicePointer.flags); \
};

//	hipGraph_t graph (opaque);
//	hipUserObject_t object (opaque);
//	unsigned int count (unsigned int);
#define PROCESS_ARGS_hipGraphReleaseUserObject(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphReleaseUserObject.retval); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphReleaseUserObject.graph); \
	ratelprof_add_to_buffer(buf, "\"object\":{\"type\":\"hipUserObject_t\",\"value\":\"%p\"},", args->hipGraphReleaseUserObject.object); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipGraphReleaseUserObject.count); \
};

//	int device (int);
#define PROCESS_ARGS_hipDeviceGraphMemTrim(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceGraphMemTrim.retval); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceGraphMemTrim.device); \
};


#define PROCESS_ARGS_hipDeviceGetStreamPriorityRange(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceGetStreamPriorityRange.retval); \
	ratelprof_add_to_buffer(buf, "\"leastPriority\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipDeviceGetStreamPriorityRange.leastPriority); \
	ratelprof_add_to_buffer(buf, "\"greatestPriority\":{\"type\":\"int *\",\"value\":\"%p\"}", args->hipDeviceGetStreamPriorityRange.greatestPriority); \
};

//	hipPointer_attribute attribute (unknown);
#define PROCESS_ARGS_hipPointerGetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipPointerGetAttribute.retval); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipPointerGetAttribute.data); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hipPointer_attribute\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"}", args->hipPointerGetAttribute.ptr); \
};

//	hipMemPool_t mem_pool (opaque);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemPoolSetAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemPoolSetAccess.retval); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"%p\"},", args->hipMemPoolSetAccess.mem_pool); \
	ratelprof_add_to_buffer(buf, "\"desc_list\":{\"type\":\"const hipMemAccessDesc *\",\"value\":\"%p\"},", args->hipMemPoolSetAccess.desc_list); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemPoolSetAccess.count); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t hNode (opaque);
#define PROCESS_ARGS_hipGraphExecExternalSemaphoresWaitNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExecExternalSemaphoresWaitNodeSetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphExecExternalSemaphoresWaitNodeSetParams.hGraphExec); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExecExternalSemaphoresWaitNodeSetParams.hNode); \
	ratelprof_add_to_buffer(buf, "\"nodeParams\":{\"type\":\"const hipExternalSemaphoreWaitNodeParams *\",\"value\":\"%p\"}", args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams); \
};

//	size_t sizeBytes (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpy.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpy.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpy.src); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};

//	int peerDeviceId (int);
#define PROCESS_ARGS_hipDeviceDisablePeerAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceDisablePeerAccess.retval); \
	ratelprof_add_to_buffer(buf, "\"peerDeviceId\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceDisablePeerAccess.peerDeviceId); \
};

//	hipGraphNode_t hNode (opaque);
//	hipKernelNodeAttrID attr (enum);
#define PROCESS_ARGS_hipGraphKernelNodeSetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphKernelNodeSetAttribute.retval); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphKernelNodeSetAttribute.hNode); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipKernelNodeAttrID\",\"value\":\"%d\"},", args->hipGraphKernelNodeSetAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"const hipKernelNodeAttrValue *\",\"value\":\"%p\"}", args->hipGraphKernelNodeSetAttribute.value); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphAddMemcpyNode1D(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddMemcpyNode1D.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNode1D.pGraphNode); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNode1D.graph); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNode1D.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNode1D.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNode1D.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNode1D.src); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNode1D.count); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t hNode (opaque);
//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipGraphExecEventRecordNodeSetEvent(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExecEventRecordNodeSetEvent.retval); \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphExecEventRecordNodeSetEvent.hGraphExec); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExecEventRecordNodeSetEvent.hNode); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"}", args->hipGraphExecEventRecordNodeSetEvent.event); \
};

//	int count (int);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipGraphicsUnmapResources(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphicsUnmapResources.retval); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipGraphicsUnmapResources.count); \
	ratelprof_add_to_buffer(buf, "\"resources\":{\"type\":\"hipGraphicsResource_t *\",\"value\":\"%p\"},", args->hipGraphicsUnmapResources.resources); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipGraphicsUnmapResources.stream); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphAddExternalSemaphoresWaitNode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddExternalSemaphoresWaitNode.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddExternalSemaphoresWaitNode.pGraphNode); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddExternalSemaphoresWaitNode.graph); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddExternalSemaphoresWaitNode.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddExternalSemaphoresWaitNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"nodeParams\":{\"type\":\"const hipExternalSemaphoreWaitNodeParams *\",\"value\":\"%p\"}", args->hipGraphAddExternalSemaphoresWaitNode.nodeParams); \
};

//	hipGraph_t hGraph (opaque);
//	size_t numDependencies (unsigned long);
//	const HIP_MEMCPY3D * copyParams (unknown);
//	hipCtx_t ctx (opaque);
#define PROCESS_ARGS_hipDrvGraphAddMemcpyNode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDrvGraphAddMemcpyNode.retval); \
	ratelprof_add_to_buffer(buf, "\"phGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipDrvGraphAddMemcpyNode.phGraphNode); \
	ratelprof_add_to_buffer(buf, "\"hGraph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipDrvGraphAddMemcpyNode.hGraph); \
	ratelprof_add_to_buffer(buf, "\"dependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipDrvGraphAddMemcpyNode.dependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipDrvGraphAddMemcpyNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"copyParams\":{\"type\":\"const HIP_MEMCPY3D *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t\",\"value\":\"%p\"}", args->hipDrvGraphAddMemcpyNode.ctx); \
};

//	hipEvent_t start (opaque);
//	hipEvent_t stop (opaque);
#define PROCESS_ARGS_hipEventElapsedTime(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipEventElapsedTime.retval); \
	ratelprof_add_to_buffer(buf, "\"ms\":{\"type\":\"float *\",\"value\":\"%p\"},", args->hipEventElapsedTime.ms); \
	ratelprof_add_to_buffer(buf, "\"start\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"},", args->hipEventElapsedTime.start); \
	ratelprof_add_to_buffer(buf, "\"stop\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"}", args->hipEventElapsedTime.stop); \
};

//	const struct hipMemcpy3DParms * p (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpy3DAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpy3DAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"p\":{\"type\":\"const struct hipMemcpy3DParms *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemcpy3DAsync.stream); \
};

//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMaxAnisotropy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefGetMaxAnisotropy.retval); \
	ratelprof_add_to_buffer(buf, "\"pmaxAnsio\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipTexRefGetMaxAnisotropy.pmaxAnsio); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"N/A\"},"); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphNodeGetDependentNodes(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphNodeGetDependentNodes.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphNodeGetDependentNodes.node); \
	ratelprof_add_to_buffer(buf, "\"pDependentNodes\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphNodeGetDependentNodes.pDependentNodes); \
	ratelprof_add_to_buffer(buf, "\"pNumDependentNodes\":{\"type\":\"size_t *\",\"value\":\"%p\"}", args->hipGraphNodeGetDependentNodes.pNumDependentNodes); \
};

//	hipMemPool_t mem_pool (opaque);
//	hipMemPoolAttr attr (enum);
#define PROCESS_ARGS_hipMemPoolGetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemPoolGetAttribute.retval); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"%p\"},", args->hipMemPoolGetAttribute.mem_pool); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipMemPoolAttr\",\"value\":\"%d\"},", args->hipMemPoolGetAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipMemPoolGetAttribute.value); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipStreamGetDevice(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamGetDevice.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamGetDevice.stream); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t *\",\"value\":\"%p\"}", args->hipStreamGetDevice.device); \
};

//	hipResourceDesc* pResDesc (unknown);
//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipGetTextureObjectResourceDesc(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGetTextureObjectResourceDesc.retval); \
	ratelprof_add_to_buffer(buf, "\"pResDesc\":{\"type\":\"hipResourceDesc*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"textureObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"N/A\"},"); \
};

//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefGetFlags.retval); \
	ratelprof_add_to_buffer(buf, "\"pFlags\":{\"type\":\"unsigned int *\",\"value\":\"%p\"},", args->hipTexRefGetFlags.pFlags); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"N/A\"},"); \
};


#define PROCESS_ARGS_hipChooseDeviceR0600(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipChooseDeviceR0600.retval); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipChooseDeviceR0600.device); \
	ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"const hipDeviceProp_tR0600 *\",\"value\":\"%p\"}", args->hipChooseDeviceR0600.prop); \
};

//	unsigned int numExtSems (unsigned int);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipSignalExternalSemaphoresAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipSignalExternalSemaphoresAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"extSemArray\":{\"type\":\"const hipExternalSemaphore_t *\",\"value\":\"%p\"},", args->hipSignalExternalSemaphoresAsync.extSemArray); \
	ratelprof_add_to_buffer(buf, "\"paramsArray\":{\"type\":\"const hipExternalSemaphoreSignalParams *\",\"value\":\"%p\"},", args->hipSignalExternalSemaphoresAsync.paramsArray); \
	ratelprof_add_to_buffer(buf, "\"numExtSems\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipSignalExternalSemaphoresAsync.numExtSems); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipSignalExternalSemaphoresAsync.stream); \
};

//	int deviceId (int);
//	int peerDeviceId (int);
#define PROCESS_ARGS_hipDeviceCanAccessPeer(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceCanAccessPeer.retval); \
	ratelprof_add_to_buffer(buf, "\"canAccessPeer\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipDeviceCanAccessPeer.canAccessPeer); \
	ratelprof_add_to_buffer(buf, "\"deviceId\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceCanAccessPeer.deviceId); \
	ratelprof_add_to_buffer(buf, "\"peerDeviceId\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceCanAccessPeer.peerDeviceId); \
};

//	hipDevice_t dev (int);
#define PROCESS_ARGS_hipDevicePrimaryCtxRetain(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDevicePrimaryCtxRetain.retval); \
	ratelprof_add_to_buffer(buf, "\"pctx\":{\"type\":\"hipCtx_t *\",\"value\":\"%p\"},", args->hipDevicePrimaryCtxRetain.pctx); \
	ratelprof_add_to_buffer(buf, "\"dev\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipDevicePrimaryCtxRetain.dev); \
};

//	hipCtx_t peerCtx (opaque);
#define PROCESS_ARGS_hipCtxDisablePeerAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxDisablePeerAccess.retval); \
	ratelprof_add_to_buffer(buf, "\"peerCtx\":{\"type\":\"hipCtx_t\",\"value\":\"%p\"}", args->hipCtxDisablePeerAccess.peerCtx); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipStreamGetPriority(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamGetPriority.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamGetPriority.stream); \
	ratelprof_add_to_buffer(buf, "\"priority\":{\"type\":\"int *\",\"value\":\"%p\"}", args->hipStreamGetPriority.priority); \
};


#define PROCESS_ARGS_hipEventCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipEventCreate.retval); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t *\",\"value\":\"%p\"}", args->hipEventCreate.event); \
};


#define PROCESS_ARGS_hipGetLastError(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGetLastError.retval); \
\
};

//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceComputeCapability(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceComputeCapability.retval); \
	ratelprof_add_to_buffer(buf, "\"major\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipDeviceComputeCapability.major); \
	ratelprof_add_to_buffer(buf, "\"minor\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipDeviceComputeCapability.minor); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipDeviceComputeCapability.device); \
};

//	int deviceId (int);
#define PROCESS_ARGS_hipGetDevicePropertiesR0600(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGetDevicePropertiesR0600.retval); \
	ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"hipDeviceProp_tR0600 *\",\"value\":\"%p\"},", args->hipGetDevicePropertiesR0600.prop); \
	ratelprof_add_to_buffer(buf, "\"deviceId\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipGetDevicePropertiesR0600.deviceId); \
};

//	size_t dynSharedMemPerBlk (unsigned long);
//	int blockSizeLimit (int);
#define PROCESS_ARGS_hipOccupancyMaxPotentialBlockSize(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipOccupancyMaxPotentialBlockSize.retval); \
	ratelprof_add_to_buffer(buf, "\"gridSize\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipOccupancyMaxPotentialBlockSize.gridSize); \
	ratelprof_add_to_buffer(buf, "\"blockSize\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipOccupancyMaxPotentialBlockSize.blockSize); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipOccupancyMaxPotentialBlockSize.f); \
	ratelprof_add_to_buffer(buf, "\"dynSharedMemPerBlk\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipOccupancyMaxPotentialBlockSize.dynSharedMemPerBlk); \
	ratelprof_add_to_buffer(buf, "\"blockSizeLimit\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipOccupancyMaxPotentialBlockSize.blockSizeLimit); \
};

//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipGetTextureAlignmentOffset(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGetTextureAlignmentOffset.retval); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t *\",\"value\":\"%p\"},", args->hipGetTextureAlignmentOffset.offset); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"N/A\"},"); \
};

//	hipIpcMemHandle_t handle ({
//		char[64] reserved (string);
//	});
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipIpcOpenMemHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipIpcOpenMemHandle.retval); \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void **\",\"value\":\"%p\"},", args->hipIpcOpenMemHandle.devPtr); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"struct hipIpcMemHandle_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"char[64]\",\"value\":\"%s\"}", args->hipIpcOpenMemHandle.handle.reserved[0]); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipIpcOpenMemHandle.flags); \
};

//	hipGraphNode_t originalNode (opaque);
//	hipGraph_t clonedGraph (opaque);
#define PROCESS_ARGS_hipGraphNodeFindInClone(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphNodeFindInClone.retval); \
	ratelprof_add_to_buffer(buf, "\"pNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphNodeFindInClone.pNode); \
	ratelprof_add_to_buffer(buf, "\"originalNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphNodeFindInClone.originalNode); \
	ratelprof_add_to_buffer(buf, "\"clonedGraph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"}", args->hipGraphNodeFindInClone.clonedGraph); \
};

//	hipDevice_t dev (int);
#define PROCESS_ARGS_hipDevicePrimaryCtxRelease(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDevicePrimaryCtxRelease.retval); \
	ratelprof_add_to_buffer(buf, "\"dev\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipDevicePrimaryCtxRelease.dev); \
};

//	hipCtx_t ctx (opaque);
#define PROCESS_ARGS_hipCtxSetCurrent(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxSetCurrent.retval); \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t\",\"value\":\"%p\"}", args->hipCtxSetCurrent.ctx); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParamsFromSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.retval); \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.hGraphExec); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.node); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.dst); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.count); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};

//	hipFuncCache_t cacheConfig (enum);
#define PROCESS_ARGS_hipCtxSetCacheConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxSetCacheConfig.retval); \
	ratelprof_add_to_buffer(buf, "\"cacheConfig\":{\"type\":\"hipFuncCache_t\",\"value\":\"%d\"}", args->hipCtxSetCacheConfig.cacheConfig); \
};

//	unsigned int count (unsigned int);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemMapArrayAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemMapArrayAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"mapInfoList\":{\"type\":\"hipArrayMapInfo *\",\"value\":\"%p\"},", args->hipMemMapArrayAsync.mapInfoList); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipMemMapArrayAsync.count); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemMapArrayAsync.stream); \
};


#define PROCESS_ARGS_hipImportExternalMemory(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipImportExternalMemory.retval); \
	ratelprof_add_to_buffer(buf, "\"extMem_out\":{\"type\":\"hipExternalMemory_t *\",\"value\":\"%p\"},", args->hipImportExternalMemory.extMem_out); \
	ratelprof_add_to_buffer(buf, "\"memHandleDesc\":{\"type\":\"const hipExternalMemoryHandleDesc *\",\"value\":\"%p\"}", args->hipImportExternalMemory.memHandleDesc); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t hNode (opaque);
//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipGraphExecEventWaitNodeSetEvent(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExecEventWaitNodeSetEvent.retval); \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphExecEventWaitNodeSetEvent.hGraphExec); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExecEventWaitNodeSetEvent.hNode); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"}", args->hipGraphExecEventWaitNodeSetEvent.event); \
};

//	hipStream_t stream (opaque);
//	hipStreamCaptureMode mode (enum);
#define PROCESS_ARGS_hipStreamBeginCapture(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamBeginCapture.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamBeginCapture.stream); \
	ratelprof_add_to_buffer(buf, "\"mode\":{\"type\":\"hipStreamCaptureMode\",\"value\":\"%d\"}", args->hipStreamBeginCapture.mode); \
};


#define PROCESS_ARGS_hipIpcGetMemHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipIpcGetMemHandle.retval); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipIpcMemHandle_t *\",\"value\":\"%p\"},", args->hipIpcGetMemHandle.handle); \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipIpcGetMemHandle.devPtr); \
};

//	unsigned int numExtSems (unsigned int);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipWaitExternalSemaphoresAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipWaitExternalSemaphoresAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"extSemArray\":{\"type\":\"const hipExternalSemaphore_t *\",\"value\":\"%p\"},", args->hipWaitExternalSemaphoresAsync.extSemArray); \
	ratelprof_add_to_buffer(buf, "\"paramsArray\":{\"type\":\"const hipExternalSemaphoreWaitParams *\",\"value\":\"%p\"},", args->hipWaitExternalSemaphoresAsync.paramsArray); \
	ratelprof_add_to_buffer(buf, "\"numExtSems\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipWaitExternalSemaphoresAsync.numExtSems); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipWaitExternalSemaphoresAsync.stream); \
};

//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipmapFilterMode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefGetMipmapFilterMode.retval); \
	ratelprof_add_to_buffer(buf, "\"pfm\":{\"type\":\"enum hipTextureFilterMode *\",\"value\":\"%p\"},", args->hipTexRefGetMipmapFilterMode.pfm); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"N/A\"},"); \
};

//	hipMemPool_t mem_pool (opaque);
#define PROCESS_ARGS_hipMemPoolGetAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemPoolGetAccess.retval); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"hipMemAccessFlags *\",\"value\":\"%p\"},", args->hipMemPoolGetAccess.flags); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"%p\"},", args->hipMemPoolGetAccess.mem_pool); \
	ratelprof_add_to_buffer(buf, "\"location\":{\"type\":\"hipMemLocation *\",\"value\":\"%p\"}", args->hipMemPoolGetAccess.location); \
};

//	hipGraph_t hGraph (opaque);
//	size_t numDependencies (unsigned long);
//	hipCtx_t ctx (opaque);
#define PROCESS_ARGS_hipDrvGraphAddMemsetNode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDrvGraphAddMemsetNode.retval); \
	ratelprof_add_to_buffer(buf, "\"phGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipDrvGraphAddMemsetNode.phGraphNode); \
	ratelprof_add_to_buffer(buf, "\"hGraph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipDrvGraphAddMemsetNode.hGraph); \
	ratelprof_add_to_buffer(buf, "\"dependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipDrvGraphAddMemsetNode.dependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipDrvGraphAddMemsetNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"memsetParams\":{\"type\":\"const HIP_MEMSET_NODE_PARAMS *\",\"value\":\"%p\"},", args->hipDrvGraphAddMemsetNode.memsetParams); \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t\",\"value\":\"%p\"}", args->hipDrvGraphAddMemsetNode.ctx); \
};

//	hipPitchedPtr pitchedDevPtr (unknown);
//	int value (int);
//	hipExtent extent (unknown);
#define PROCESS_ARGS_hipMemset3D(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemset3D.retval); \
	ratelprof_add_to_buffer(buf, "\"pitchedDevPtr\":{\"type\":\"hipPitchedPtr\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemset3D.value); \
	ratelprof_add_to_buffer(buf, "\"extent\":{\"type\":\"hipExtent\",\"value\":\"N/A\"},"); \
};

//	const HIP_MEMCPY3D * pCopy (unknown);
#define PROCESS_ARGS_hipDrvMemcpy3D(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDrvMemcpy3D.retval); \
	ratelprof_add_to_buffer(buf, "\"pCopy\":{\"type\":\"const HIP_MEMCPY3D *\",\"value\":\"N/A\"},"); \
};

//	size_t dpitch (unsigned long);
//	hipArray_const_t src (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpy2DFromArrayAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpy2DFromArrayAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipMemcpy2DFromArrayAsync.dst); \
	ratelprof_add_to_buffer(buf, "\"dpitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArrayAsync.dpitch); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"hipArray_const_t\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"wOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArrayAsync.wOffset); \
	ratelprof_add_to_buffer(buf, "\"hOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArrayAsync.hOffset); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArrayAsync.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArrayAsync.height); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemcpy2DFromArrayAsync.stream); \
};

//	int numDevices (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipExtLaunchMultiKernelMultiDevice(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipExtLaunchMultiKernelMultiDevice.retval); \
	ratelprof_add_to_buffer(buf, "\"launchParamsList\":{\"type\":\"hipLaunchParams *\",\"value\":\"%p\"},", args->hipExtLaunchMultiKernelMultiDevice.launchParamsList); \
	ratelprof_add_to_buffer(buf, "\"numDevices\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipExtLaunchMultiKernelMultiDevice.numDevices); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipExtLaunchMultiKernelMultiDevice.flags); \
};

//	hipStream_t stream (opaque);
//	uint64_t value (unsigned long);
//	unsigned int flags (unsigned int);
//	uint64_t mask (unsigned long);
#define PROCESS_ARGS_hipStreamWaitValue64(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamWaitValue64.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamWaitValue64.stream); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipStreamWaitValue64.ptr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hipStreamWaitValue64.value); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipStreamWaitValue64.flags); \
	ratelprof_add_to_buffer(buf, "\"mask\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hipStreamWaitValue64.mask); \
};

//	textureReference** texRef (unknown);
//	hipModule_t hmod (opaque);
#define PROCESS_ARGS_hipModuleGetTexRef(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipModuleGetTexRef.retval); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference**\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"hmod\":{\"type\":\"hipModule_t\",\"value\":\"%p\"},", args->hipModuleGetTexRef.hmod); \
	ratelprof_add_to_buffer(buf, "\"name\":{\"type\":\"const char *\",\"value\":\"%p\"}", args->hipModuleGetTexRef.name); \
};

//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyDtoDAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyDtoDAsync.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipMemcpyDtoDAsync.dst); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"hipDeviceptr_t\",\"value\":\"%p\"},", args->hipMemcpyDtoDAsync.src); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyDtoDAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipMemcpyDtoDAsync.stream); \
};

//	HIP_RESOURCE_VIEW_DESC * pResViewDesc (unknown);
//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectGetResourceViewDesc(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexObjectGetResourceViewDesc.retval); \
	ratelprof_add_to_buffer(buf, "\"pResViewDesc\":{\"type\":\"HIP_RESOURCE_VIEW_DESC *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"texObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"N/A\"},"); \
};

//	hipStream_t stream (opaque);
//	hipStreamCallback_t callback (function);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamAddCallback(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamAddCallback.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"},", args->hipStreamAddCallback.stream); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"hipStreamCallback_t\",\"value\":\"%p\"},", args->hipStreamAddCallback.callback); \
	ratelprof_add_to_buffer(buf, "\"userData\":{\"type\":\"void *\",\"value\":\"%p\"},", args->hipStreamAddCallback.userData); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipStreamAddCallback.flags); \
};

//	textureReference* texRef (unknown);
//	hipArray_Format fmt (unknown);
//	int NumPackedComponents (int);
#define PROCESS_ARGS_hipTexRefSetFormat(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipTexRefSetFormat.retval); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"fmt\":{\"type\":\"hipArray_Format\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"NumPackedComponents\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipTexRefSetFormat.NumPackedComponents); \
};


#define PROCESS_ARGS_hipFuncGetAttributes(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipFuncGetAttributes.retval); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"struct hipFuncAttributes *\",\"value\":\"%p\"},", args->hipFuncGetAttributes.attr); \
	ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"const void *\",\"value\":\"%p\"}", args->hipFuncGetAttributes.func); \
};

//	unsigned int flags (unsigned int);
//	int priority (int);
#define PROCESS_ARGS_hipStreamCreateWithPriority(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamCreateWithPriority.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t *\",\"value\":\"%p\"},", args->hipStreamCreateWithPriority.stream); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipStreamCreateWithPriority.flags); \
	ratelprof_add_to_buffer(buf, "\"priority\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipStreamCreateWithPriority.priority); \
};

//	const textureReference** texref (unknown);
#define PROCESS_ARGS_hipGetTextureReference(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGetTextureReference.retval); \
	ratelprof_add_to_buffer(buf, "\"texref\":{\"type\":\"const textureReference**\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":\"%p\"}", args->hipGetTextureReference.symbol); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphAddKernelNode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddKernelNode.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddKernelNode.pGraphNode); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddKernelNode.graph); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddKernelNode.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddKernelNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"const hipKernelNodeParams *\",\"value\":\"%p\"}", args->hipGraphAddKernelNode.pNodeParams); \
};

//	hipArray_t dst (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpyToArray(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemcpyToArray.retval); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipArray_t\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"wOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyToArray.wOffset); \
	ratelprof_add_to_buffer(buf, "\"hOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyToArray.hOffset); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemcpyToArray.src); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyToArray.count); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};


#define PROCESS_ARGS_hipIpcCloseMemHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipIpcCloseMemHandle.retval); \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void *\",\"value\":\"%p\"}", args->hipIpcCloseMemHandle.devPtr); \
};

//	hipGraph_t graph (opaque);
#define PROCESS_ARGS_hipGraphDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphDestroy.retval); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"}", args->hipGraphDestroy.graph); \
};

//	size_t count (unsigned long);
//	hipMemoryAdvise advice (enum);
//	int device (int);
#define PROCESS_ARGS_hipMemAdvise(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMemAdvise.retval); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipMemAdvise.dev_ptr); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemAdvise.count); \
	ratelprof_add_to_buffer(buf, "\"advice\":{\"type\":\"hipMemoryAdvise\",\"value\":\"%d\"},", args->hipMemAdvise.advice); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipMemAdvise.device); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphDestroyNode(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphDestroyNode.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"}", args->hipGraphDestroyNode.node); \
};

//	hipFunction_attribute attrib (unknown);
//	hipFunction_t hfunc (opaque);
#define PROCESS_ARGS_hipFuncGetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipFuncGetAttribute.retval); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipFuncGetAttribute.value); \
	ratelprof_add_to_buffer(buf, "\"attrib\":{\"type\":\"hipFunction_attribute\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"hfunc\":{\"type\":\"hipFunction_t\",\"value\":\"%p\"}", args->hipFuncGetAttribute.hfunc); \
};

//	hipCtx_t peerCtx (opaque);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipCtxEnablePeerAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxEnablePeerAccess.retval); \
	ratelprof_add_to_buffer(buf, "\"peerCtx\":{\"type\":\"hipCtx_t\",\"value\":\"%p\"},", args->hipCtxEnablePeerAccess.peerCtx); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipCtxEnablePeerAccess.flags); \
};

//	hipFunction_t f (opaque);
//	int blockSize (int);
//	size_t dynSharedMemPerBlk (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.retval); \
	ratelprof_add_to_buffer(buf, "\"numBlocks\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"hipFunction_t\",\"value\":\"%p\"},", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.f); \
	ratelprof_add_to_buffer(buf, "\"blockSize\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.blockSize); \
	ratelprof_add_to_buffer(buf, "\"dynSharedMemPerBlk\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.dynSharedMemPerBlk); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.flags); \
};


#define PROCESS_ARGS_hipCtxSynchronize(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipCtxSynchronize.retval); \
\
};


#define PROCESS_ARGS_hipDestroyExternalMemory(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDestroyExternalMemory.retval); \
	ratelprof_add_to_buffer(buf, "\"extMem\":{\"type\":\"hipExternalMemory_t\",\"value\":\"%p\"}", args->hipDestroyExternalMemory.extMem); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipStreamDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipStreamDestroy.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipStreamDestroy.stream); \
};

//	hipGraph_t graph (opaque);
//	size_t numDependencies (unsigned long);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphAddMemcpyNodeToSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphAddMemcpyNodeToSymbol.retval); \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNodeToSymbol.pGraphNode); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNodeToSymbol.graph); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNodeToSymbol.pDependencies); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNodeToSymbol.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNodeToSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipGraphAddMemcpyNodeToSymbol.src); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNodeToSymbol.count); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNodeToSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};

//	hipGraphNode_t node (opaque);
//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipGraphEventRecordNodeSetEvent(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphEventRecordNodeSetEvent.retval); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphEventRecordNodeSetEvent.node); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"%p\"}", args->hipGraphEventRecordNodeSetEvent.event); \
};

//	hipDeviceP2PAttr attr (enum);
//	int srcDevice (int);
//	int dstDevice (int);
#define PROCESS_ARGS_hipDeviceGetP2PAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceGetP2PAttribute.retval); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int *\",\"value\":\"%p\"},", args->hipDeviceGetP2PAttribute.value); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipDeviceP2PAttr\",\"value\":\"%d\"},", args->hipDeviceGetP2PAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"srcDevice\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceGetP2PAttribute.srcDevice); \
	ratelprof_add_to_buffer(buf, "\"dstDevice\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceGetP2PAttribute.dstDevice); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipGetStreamDeviceId(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipGetStreamDeviceId.retval); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"%p\"}", args->hipGetStreamDeviceId.stream); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t hNode (opaque);
#define PROCESS_ARGS_hipGraphNodeGetEnabled(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphNodeGetEnabled.retval); \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphNodeGetEnabled.hGraphExec); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphNodeGetEnabled.hNode); \
	ratelprof_add_to_buffer(buf, "\"isEnabled\":{\"type\":\"unsigned int *\",\"value\":\"%p\"}", args->hipGraphNodeGetEnabled.isEnabled); \
};

//	int device (int);
#define PROCESS_ARGS_hipDeviceGetMemPool(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDeviceGetMemPool.retval); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t *\",\"value\":\"%p\"},", args->hipDeviceGetMemPool.mem_pool); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceGetMemPool.device); \
};

//	hipArray_t * pLevelArray (unknown);
//	hipMipmappedArray_t hMipMappedArray (unknown);
//	unsigned int level (unsigned int);
#define PROCESS_ARGS_hipMipmappedArrayGetLevel(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipMipmappedArrayGetLevel.retval); \
	ratelprof_add_to_buffer(buf, "\"pLevelArray\":{\"type\":\"hipArray_t *\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"hMipMappedArray\":{\"type\":\"hipMipmappedArray_t\",\"value\":\"N/A\"},"); \
	ratelprof_add_to_buffer(buf, "\"level\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMipmappedArrayGetLevel.level); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParamsToSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExecMemcpyNodeSetParamsToSymbol.retval); \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphExecMemcpyNodeSetParamsToSymbol.hGraphExec); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExecMemcpyNodeSetParamsToSymbol.node); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipGraphExecMemcpyNodeSetParamsToSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":\"%p\"},", args->hipGraphExecMemcpyNodeSetParamsToSymbol.src); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphExecMemcpyNodeSetParamsToSymbol.count); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphExecMemcpyNodeSetParamsToSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"N/A\"},"); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphExecMemsetNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"ret\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipGraphExecMemsetNodeSetParams.retval); \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"%p\"},", args->hipGraphExecMemsetNodeSetParams.hGraphExec); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"%p\"},", args->hipGraphExecMemsetNodeSetParams.node); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"const hipMemsetParams *\",\"value\":\"%p\"}", args->hipGraphExecMemsetNodeSetParams.pNodeParams); \
};

#endif // HIP_PLUGIN_H