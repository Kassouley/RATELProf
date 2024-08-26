/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#ifndef HIP_PLUGIN_H 
#define HIP_PLUGIN_H 

#include "ratelprof_buffer_manager.h"

void process_hip_args_for(hip_api_id_t funid, const hip_api_args_t* args, ratelprof_buffer_t* buf);

//	textureReference* texRef (unknown);
//	enum hipTextureFilterMode fm (enum);
#define PROCESS_ARGS_hipTexRefSetMipmapFilterMode(args) { \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"fm\":{\"type\":\"enum hipTextureFilterMode\",\"value\":\"%d\"}", args->hipTexRefSetMipmapFilterMode.fm); \
};

//	hipArray_t dstArray (unknown);
//	size_t dstOffset (unsigned long);
//	const void * srcHost (void*);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemcpyHtoA(args) { \
	ratelprof_add_to_buffer(buf, "\"dstArray\":{\"type\":\"hipArray_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dstOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyHtoA.dstOffset); \
	ratelprof_add_to_buffer(buf, "\"srcHost\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyHtoA.srcHost); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemcpyHtoA.count); \
};

//	hipCtx_t ctx (unknown);
//	int * apiVersion (int*);
#define PROCESS_ARGS_hipCtxGetApiVersion(args) { \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"apiVersion\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipCtxGetApiVersion.apiVersion); \
	if (args->hipCtxGetApiVersion.apiVersion != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipCtxGetApiVersion.apiVersion); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	char * name (char*);
//	int len (int);
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceGetName(args) { \
	ratelprof_add_to_buffer(buf, "\"name\":{\"type\":\"char *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceGetName.name); \
	if (args->hipDeviceGetName.name != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *args->hipDeviceGetName.name); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"len\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceGetName.len); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipDeviceGetName.device); \
};

//	hipStream_t stream (unknown);
//	hipStreamCaptureStatus * pCaptureStatus (enum*);
#define PROCESS_ARGS_hipStreamIsCapturing(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pCaptureStatus\":{\"type\":\"hipStreamCaptureStatus *\",\"value\":{\"addr\":\"%p\"", args->hipStreamIsCapturing.pCaptureStatus); \
	if (args->hipStreamIsCapturing.pCaptureStatus != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipStreamIsCapturing.pCaptureStatus); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipStream_t stream (unknown);
//	void * dev_ptr (void*);
//	size_t length (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamAttachMemAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipStreamAttachMemAsync.dev_ptr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"length\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipStreamAttachMemAsync.length); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipStreamAttachMemAsync.flags); \
};

//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipFreeArray(args) { \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t\",\"value\":\"NULL\"}"); \
};

//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipSetDeviceFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipSetDeviceFlags.flags); \
};

//	hipEvent_t * event (unknown);
//	hipIpcEventHandle_t handle ({
//		char[64] reserved (char*);
//	});
#define PROCESS_ARGS_hipIpcOpenEventHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"struct hipIpcEventHandle_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"char[64]\",\"value\":{\"addr\":\"%p\"", args->hipIpcOpenEventHandle.handle.reserved); \
	if (args->hipIpcOpenEventHandle.handle.reserved != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *args->hipIpcOpenEventHandle.handle.reserved); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipModule_t * module (unknown);
//	const char * fname (char*);
#define PROCESS_ARGS_hipModuleLoad(args) { \
	ratelprof_add_to_buffer(buf, "\"module\":{\"type\":\"hipModule_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"fname\":{\"type\":\"const char *\",\"value\":{\"addr\":\"%p\"", args->hipModuleLoad.fname); \
	if (args->hipModuleLoad.fname != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *args->hipModuleLoad.fname); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	void ** devPtr (void**);
//	hipExternalMemory_t extMem (void*);
//	struct const hipExternalMemoryBufferDesc * bufferDesc ({
//		unsigned long long offset (unsigned long long);
//		unsigned long long size (unsigned long long);
//		unsigned int flags (unsigned int);
//		unsigned int[16] reserved (unsigned int*);
//	});
#define PROCESS_ARGS_hipExternalMemoryGetMappedBuffer(args) { \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipExternalMemoryGetMappedBuffer.devPtr); \
	if (args->hipExternalMemoryGetMappedBuffer.devPtr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipExternalMemoryGetMappedBuffer.devPtr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"extMem\":{\"type\":\"hipExternalMemory_t\",\"value\":{\"addr\":\"%p\"", args->hipExternalMemoryGetMappedBuffer.extMem); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"bufferDesc\":{\"type\":\"struct const hipExternalMemoryBufferDesc *\",\"value\":{\"addr\":\"%p\"", args->hipExternalMemoryGetMappedBuffer.bufferDesc); \
	if (args->hipExternalMemoryGetMappedBuffer.bufferDesc != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"unsigned long long\",\"value\":\"%llu\"},", (*args->hipExternalMemoryGetMappedBuffer.bufferDesc).offset); \
		ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"unsigned long long\",\"value\":\"%llu\"},", (*args->hipExternalMemoryGetMappedBuffer.bufferDesc).size); \
		ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipExternalMemoryGetMappedBuffer.bufferDesc).flags); \
		ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned int[16]\",\"value\":{\"addr\":\"%p\"", (*args->hipExternalMemoryGetMappedBuffer.bufferDesc).reserved); \
		if ((*args->hipExternalMemoryGetMappedBuffer.bufferDesc).reserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*args->hipExternalMemoryGetMappedBuffer.bufferDesc).reserved); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipMemGenericAllocationHandle_t * handle (unknown);
//	void * osHandle (void*);
//	hipMemAllocationHandleType shHandleType (enum);
#define PROCESS_ARGS_hipMemImportFromShareableHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipMemGenericAllocationHandle_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"osHandle\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemImportFromShareableHandle.osHandle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"shHandleType\":{\"type\":\"hipMemAllocationHandleType\",\"value\":\"%d\"}", args->hipMemImportFromShareableHandle.shHandleType); \
};

//	void * dst (void*);
//	hipDeviceptr_t src (unknown);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemcpyDtoH(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyDtoH.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemcpyDtoH.sizeBytes); \
};

//	hipStream_t stream (unknown);
//	hipGraph_t * pGraph (unknown);
#define PROCESS_ARGS_hipStreamEndCapture(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pGraph\":{\"type\":\"hipGraph_t *\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t node (unknown);
//	void * dev_ptr (void*);
#define PROCESS_ARGS_hipGraphMemFreeNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphMemFreeNodeGetParams.dev_ptr); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipStreamCaptureMode * mode (enum*);
#define PROCESS_ARGS_hipThreadExchangeStreamCaptureMode(args) { \
	ratelprof_add_to_buffer(buf, "\"mode\":{\"type\":\"hipStreamCaptureMode *\",\"value\":{\"addr\":\"%p\"", args->hipThreadExchangeStreamCaptureMode.mode); \
	if (args->hipThreadExchangeStreamCaptureMode.mode != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipThreadExchangeStreamCaptureMode.mode); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipModule_t module (unknown);
#define PROCESS_ARGS_hipModuleUnload(args) { \
	ratelprof_add_to_buffer(buf, "\"module\":{\"type\":\"hipModule_t\",\"value\":\"NULL\"}"); \
};

//	int * gridSize (int*);
//	int * blockSize (int*);
//	hipFunction_t f (unknown);
//	size_t dynSharedMemPerBlk (unsigned long);
//	int blockSizeLimit (int);
#define PROCESS_ARGS_hipModuleOccupancyMaxPotentialBlockSize(args) { \
	ratelprof_add_to_buffer(buf, "\"gridSize\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipModuleOccupancyMaxPotentialBlockSize.gridSize); \
	if (args->hipModuleOccupancyMaxPotentialBlockSize.gridSize != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipModuleOccupancyMaxPotentialBlockSize.gridSize); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"blockSize\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipModuleOccupancyMaxPotentialBlockSize.blockSize); \
	if (args->hipModuleOccupancyMaxPotentialBlockSize.blockSize != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipModuleOccupancyMaxPotentialBlockSize.blockSize); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"hipFunction_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dynSharedMemPerBlk\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipModuleOccupancyMaxPotentialBlockSize.dynSharedMemPerBlk); \
	ratelprof_add_to_buffer(buf, "\"blockSizeLimit\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipModuleOccupancyMaxPotentialBlockSize.blockSizeLimit); \
};

//	const hip_Memcpy2D * pCopy (unknown);
#define PROCESS_ARGS_hipMemcpyParam2D(args) { \
	ratelprof_add_to_buffer(buf, "\"pCopy\":{\"type\":\"const hip_Memcpy2D *\",\"value\":\"NULL\"}"); \
};


#define PROCESS_ARGS_hipPeekAtLastError(args) { \
\
};

//	hipMemGenericAllocationHandle_t handle (unknown);
#define PROCESS_ARGS_hipMemRelease(args) { \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipMemGenericAllocationHandle_t\",\"value\":\"NULL\"}"); \
};

//	hipSharedMemConfig * pConfig (enum*);
#define PROCESS_ARGS_hipDeviceGetSharedMemConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"pConfig\":{\"type\":\"hipSharedMemConfig *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceGetSharedMemConfig.pConfig); \
	if (args->hipDeviceGetSharedMemConfig.pConfig != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipDeviceGetSharedMemConfig.pConfig); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipUserObject_t object (unknown);
//	unsigned int count (unsigned int);
#define PROCESS_ARGS_hipUserObjectRelease(args) { \
	ratelprof_add_to_buffer(buf, "\"object\":{\"type\":\"hipUserObject_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipUserObjectRelease.count); \
};

//	hipStream_t stream (unknown);
//	void * ptr (void*);
//	uint32_t value (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamWriteValue32(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipStreamWriteValue32.ptr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipStreamWriteValue32.value); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipStreamWriteValue32.flags); \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMemAllocHost(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipMemAllocHost.ptr); \
	if (args->hipMemAllocHost.ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipMemAllocHost.ptr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemAllocHost.size); \
};

//	hipGraph_t * pGraph (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipGraphCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraph\":{\"type\":\"hipGraph_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipGraphCreate.flags); \
};

//	int * gridSize (int*);
//	int * blockSize (int*);
//	hipFunction_t f (unknown);
//	size_t dynSharedMemPerBlk (unsigned long);
//	int blockSizeLimit (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipModuleOccupancyMaxPotentialBlockSizeWithFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"gridSize\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.gridSize); \
	if (args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.gridSize != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.gridSize); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"blockSize\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSize); \
	if (args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSize != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSize); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"hipFunction_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dynSharedMemPerBlk\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.dynSharedMemPerBlk); \
	ratelprof_add_to_buffer(buf, "\"blockSizeLimit\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSizeLimit); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.flags); \
};

//	hipArray_t * array (unknown);
//	const struct hipChannelFormatDesc * desc (unknown);
//	struct hipExtent extent (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMalloc3DArray(args) { \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const struct hipChannelFormatDesc *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"extent\":{\"type\":\"struct hipExtent\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMalloc3DArray.flags); \
};

//	hipFuncCache_t * cacheConfig (enum*);
#define PROCESS_ARGS_hipCtxGetCacheConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"cacheConfig\":{\"type\":\"hipFuncCache_t *\",\"value\":{\"addr\":\"%p\"", args->hipCtxGetCacheConfig.cacheConfig); \
	if (args->hipCtxGetCacheConfig.cacheConfig != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipCtxGetCacheConfig.cacheConfig); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipFunction_t f (unknown);
//	unsigned int gridDimX (unsigned int);
//	unsigned int gridDimY (unsigned int);
//	unsigned int gridDimZ (unsigned int);
//	unsigned int blockDimX (unsigned int);
//	unsigned int blockDimY (unsigned int);
//	unsigned int blockDimZ (unsigned int);
//	unsigned int sharedMemBytes (unsigned int);
//	hipStream_t stream (unknown);
//	void ** kernelParams (void**);
#define PROCESS_ARGS_hipModuleLaunchCooperativeKernel(args) { \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"hipFunction_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"gridDimX\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernel.gridDimX); \
	ratelprof_add_to_buffer(buf, "\"gridDimY\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernel.gridDimY); \
	ratelprof_add_to_buffer(buf, "\"gridDimZ\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernel.gridDimZ); \
	ratelprof_add_to_buffer(buf, "\"blockDimX\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernel.blockDimX); \
	ratelprof_add_to_buffer(buf, "\"blockDimY\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernel.blockDimY); \
	ratelprof_add_to_buffer(buf, "\"blockDimZ\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernel.blockDimZ); \
	ratelprof_add_to_buffer(buf, "\"sharedMemBytes\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernel.sharedMemBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"kernelParams\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipModuleLaunchCooperativeKernel.kernelParams); \
	if (args->hipModuleLaunchCooperativeKernel.kernelParams != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipModuleLaunchCooperativeKernel.kernelParams); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	enum hipTextureAddressMode * pam (enum);
//	const textureReference* texRef (unknown);
//	int dim (int);
#define PROCESS_ARGS_hipTexRefGetAddressMode(args) { \
	ratelprof_add_to_buffer(buf, "\"pam\":{\"type\":\"enum hipTextureAddressMode *\",\"value\":\"%d\"},", args->hipTexRefGetAddressMode.pam); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dim\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipTexRefGetAddressMode.dim); \
};

//	hipGraphNode_t node (unknown);
//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipGraphEventWaitNodeSetEvent(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
};

//	hipMemPool_t * mem_pool (unknown);
//	int device (int);
#define PROCESS_ARGS_hipDeviceGetDefaultMemPool(args) { \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceGetDefaultMemPool.device); \
};

//	hipMemPool_t mem_pool (unknown);
//	size_t min_bytes_to_hold (unsigned long);
#define PROCESS_ARGS_hipMemPoolTrimTo(args) { \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"min_bytes_to_hold\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemPoolTrimTo.min_bytes_to_hold); \
};

//	hipGraphExec_t graphExec (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipGraphUpload(args) { \
	ratelprof_add_to_buffer(buf, "\"graphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipMipmappedArray_t * mipmap (unknown);
//	hipExternalMemory_t extMem (void*);
//	struct const hipExternalMemoryMipmappedArrayDesc * mipmapDesc ({
//		unsigned long long offset (unsigned long long);
//		int formatDesc (int);
//		int extent (int);
//		unsigned int flags (unsigned int);
//		unsigned int numLevels (unsigned int);
//	});
#define PROCESS_ARGS_hipExternalMemoryGetMappedMipmappedArray(args) { \
	ratelprof_add_to_buffer(buf, "\"mipmap\":{\"type\":\"hipMipmappedArray_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"extMem\":{\"type\":\"hipExternalMemory_t\",\"value\":{\"addr\":\"%p\"", args->hipExternalMemoryGetMappedMipmappedArray.extMem); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"mipmapDesc\":{\"type\":\"struct const hipExternalMemoryMipmappedArrayDesc *\",\"value\":{\"addr\":\"%p\"", args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc); \
	if (args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"unsigned long long\",\"value\":\"%llu\"},", (*args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc).offset); \
		ratelprof_add_to_buffer(buf, "\"formatDesc\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc).formatDesc); \
		ratelprof_add_to_buffer(buf, "\"extent\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc).extent); \
		ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc).flags); \
		ratelprof_add_to_buffer(buf, "\"numLevels\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", (*args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc).numLevels); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphNode_t hNode (unknown);
//	struct const hipExternalSemaphoreWaitNodeParams * nodeParams ({
//		hipExternalSemaphore_t * extSemArray (void**);
//		struct const hipExternalSemaphoreWaitParams * paramsArray ({
//			struct (unnamed struct at ./input/hip_runtime_api.h:1156:3) params (unknown);
//			unsigned int flags (unsigned int);
//			unsigned int[16] reserved (unsigned int*);
//		});
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphExternalSemaphoresWaitNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"nodeParams\":{\"type\":\"struct const hipExternalSemaphoreWaitNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams); \
	if (args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"extSemArray\":{\"type\":\"hipExternalSemaphore_t *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).extSemArray); \
		if ((*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).extSemArray != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).extSemArray); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"paramsArray\":{\"type\":\"struct const hipExternalSemaphoreWaitParams *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray); \
		if ((*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray != NULL) { \
			ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
			ratelprof_add_to_buffer(buf, "\"params\":{\"type\":\"struct (unnamed struct at ./input/hip_runtime_api.h:1156:3)\",\"value\":\"NULL\"}"); \
			ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*(*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).flags); \
			ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned int[16]\",\"value\":{\"addr\":\"%p\"", (*(*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).reserved); \
			if ((*(*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).reserved != NULL) { \
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*(*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).reserved); \
			} \
			ratelprof_add_to_buffer(buf, "}}"); \
			ratelprof_add_to_buffer(buf, "}"); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"numExtSems\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", (*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).numExtSems); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	const void * symbol (void*);
//	const void * src (void*);
//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpyToSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyToSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyToSymbol.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyToSymbol.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyToSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	struct const hipMemsetParams * pMemsetParams ({
//		void * dst (void*);
//		unsigned int elementSize (unsigned int);
//		int height (int);
//		int pitch (int);
//		unsigned int value (unsigned int);
//		int width (int);
//	});
#define PROCESS_ARGS_hipGraphAddMemsetNode(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemsetNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"pMemsetParams\":{\"type\":\"struct const hipMemsetParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphAddMemsetNode.pMemsetParams); \
	if (args->hipGraphAddMemsetNode.pMemsetParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphAddMemsetNode.pMemsetParams).dst); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"elementSize\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipGraphAddMemsetNode.pMemsetParams).elementSize); \
		ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGraphAddMemsetNode.pMemsetParams).height); \
		ratelprof_add_to_buffer(buf, "\"pitch\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGraphAddMemsetNode.pMemsetParams).pitch); \
		ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipGraphAddMemsetNode.pMemsetParams).value); \
		ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"int\",\"value\":\"%d\"}", (*args->hipGraphAddMemsetNode.pMemsetParams).width); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraph_t * pGraphClone (unknown);
//	hipGraph_t originalGraph (unknown);
#define PROCESS_ARGS_hipGraphClone(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphClone\":{\"type\":\"hipGraph_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"originalGraph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
};


#define PROCESS_ARGS_hipExtGetLastError(args) { \
\
};

//	hipGraphNode_t hNode (unknown);
//	hipKernelNodeAttrID attr (enum);
//	union hipKernelNodeAttrValue * value ({
//		hipAccessPolicyWindow accessPolicyWindow ({
//			void * base_ptr (void*);
//			hipAccessProperty hitProp (enum);
//			float hitRatio (float);
//			hipAccessProperty missProp (enum);
//			int num_bytes (int);
//		});
//		int cooperative (int);
//	});
#define PROCESS_ARGS_hipGraphKernelNodeGetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipKernelNodeAttrID\",\"value\":\"%d\"},", args->hipGraphKernelNodeGetAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"union hipKernelNodeAttrValue *\",\"value\":{\"addr\":\"%p\"", args->hipGraphKernelNodeGetAttribute.value); \
	if (args->hipGraphKernelNodeGetAttribute.value != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"accessPolicyWindow\":{\"type\":\"struct hipAccessPolicyWindow\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"base_ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", ((*args->hipGraphKernelNodeGetAttribute.value).accessPolicyWindow).base_ptr); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"hitProp\":{\"type\":\"hipAccessProperty\",\"value\":\"%d\"},", ((*args->hipGraphKernelNodeGetAttribute.value).accessPolicyWindow).hitProp); \
		ratelprof_add_to_buffer(buf, "\"hitRatio\":{\"type\":\"float\",\"value\":\"%f\"},", ((*args->hipGraphKernelNodeGetAttribute.value).accessPolicyWindow).hitRatio); \
		ratelprof_add_to_buffer(buf, "\"missProp\":{\"type\":\"hipAccessProperty\",\"value\":\"%d\"},", ((*args->hipGraphKernelNodeGetAttribute.value).accessPolicyWindow).missProp); \
		ratelprof_add_to_buffer(buf, "\"num_bytes\":{\"type\":\"int\",\"value\":\"%d\"}", ((*args->hipGraphKernelNodeGetAttribute.value).accessPolicyWindow).num_bytes); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"cooperative\":{\"type\":\"int\",\"value\":\"%d\"}", (*args->hipGraphKernelNodeGetAttribute.value).cooperative); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipEvent_t event (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipEventRecord(args) { \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	struct hipMemAllocationProp * prop ({
//		hipMemAllocationType type (enum);
//		hipMemAllocationHandleType requestedHandleType (enum);
//		hipMemLocation location ({
//			hipMemLocationType type (enum);
//			int id (int);
//		});
//		void * win32HandleMetaData (void*);
//		struct (unnamed struct at ./input/hip_runtime_api.h:1393:5) allocFlags (unknown);
//	});
//	hipMemGenericAllocationHandle_t handle (unknown);
#define PROCESS_ARGS_hipMemGetAllocationPropertiesFromHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"struct hipMemAllocationProp *\",\"value\":{\"addr\":\"%p\"", args->hipMemGetAllocationPropertiesFromHandle.prop); \
	if (args->hipMemGetAllocationPropertiesFromHandle.prop != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipMemAllocationType\",\"value\":\"%d\"},", (*args->hipMemGetAllocationPropertiesFromHandle.prop).type); \
		ratelprof_add_to_buffer(buf, "\"requestedHandleType\":{\"type\":\"hipMemAllocationHandleType\",\"value\":\"%d\"},", (*args->hipMemGetAllocationPropertiesFromHandle.prop).requestedHandleType); \
		ratelprof_add_to_buffer(buf, "\"location\":{\"type\":\"struct hipMemLocation\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipMemLocationType\",\"value\":\"%d\"},", ((*args->hipMemGetAllocationPropertiesFromHandle.prop).location).type); \
		ratelprof_add_to_buffer(buf, "\"id\":{\"type\":\"int\",\"value\":\"%d\"}", ((*args->hipMemGetAllocationPropertiesFromHandle.prop).location).id); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"win32HandleMetaData\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipMemGetAllocationPropertiesFromHandle.prop).win32HandleMetaData); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"allocFlags\":{\"type\":\"struct (unnamed struct at ./input/hip_runtime_api.h:1393:5)\",\"value\":\"NULL\"}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipMemGenericAllocationHandle_t\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipGraphAddEventWaitNode(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddEventWaitNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
};

//	void ** dev_ptr (void**);
//	hipMemPool_t mem_pool (unknown);
//	struct hipMemPoolPtrExportData * export_data ({
//		unsigned char[64] reserved (unsigned char*);
//	});
#define PROCESS_ARGS_hipMemPoolImportPointer(args) { \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipMemPoolImportPointer.dev_ptr); \
	if (args->hipMemPoolImportPointer.dev_ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipMemPoolImportPointer.dev_ptr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"export_data\":{\"type\":\"struct hipMemPoolPtrExportData *\",\"value\":{\"addr\":\"%p\"", args->hipMemPoolImportPointer.export_data); \
	if (args->hipMemPoolImportPointer.export_data != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned char[64]\",\"value\":{\"addr\":\"%p\"", (*args->hipMemPoolImportPointer.export_data).reserved); \
		if ((*args->hipMemPoolImportPointer.export_data).reserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%hhu\"", *(*args->hipMemPoolImportPointer.export_data).reserved); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	void * ptr (void*);
#define PROCESS_ARGS_hipFree(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipFree.ptr); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphNode_t node (unknown);
//	hipEvent_t * event_out (unknown);
#define PROCESS_ARGS_hipGraphEventRecordNodeGetEvent(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"event_out\":{\"type\":\"hipEvent_t *\",\"value\":\"NULL\"}"); \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMalloc(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipMalloc.ptr); \
	if (args->hipMalloc.ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipMalloc.ptr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMalloc.size); \
};

//	void * dst (void*);
//	const void * src (void*);
//	size_t sizeBytes (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyWithStream(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyWithStream.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyWithStream.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyWithStream.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	const HIP_MEMCPY3D* pCopy (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipDrvMemcpy3DAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"pCopy\":{\"type\":\"const HIP_MEMCPY3D*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	struct hipMemAllocNodeParams * pNodeParams ({
//		hipMemPoolProps poolProps ({
//			hipMemAllocationType allocType (enum);
//			hipMemAllocationHandleType handleTypes (enum);
//			hipMemLocation location ({
//				hipMemLocationType type (enum);
//				int id (int);
//			});
//			void * win32SecurityAttributes (void*);
//			unsigned char[64] reserved (unsigned char*);
//		});
//		struct const hipMemAccessDesc * accessDescs ({
//			hipMemLocation location ({
//				hipMemLocationType type (enum);
//				int id (int);
//			});
//			hipMemAccessFlags flags (enum);
//		});
//		int accessDescCount (int);
//		int bytesize (int);
//		void * dptr (void*);
//	});
#define PROCESS_ARGS_hipGraphAddMemAllocNode(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemAllocNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"struct hipMemAllocNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphAddMemAllocNode.pNodeParams); \
	if (args->hipGraphAddMemAllocNode.pNodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"poolProps\":{\"type\":\"struct hipMemPoolProps\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"allocType\":{\"type\":\"hipMemAllocationType\",\"value\":\"%d\"},", ((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).allocType); \
		ratelprof_add_to_buffer(buf, "\"handleTypes\":{\"type\":\"hipMemAllocationHandleType\",\"value\":\"%d\"},", ((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).handleTypes); \
		ratelprof_add_to_buffer(buf, "\"location\":{\"type\":\"struct hipMemLocation\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipMemLocationType\",\"value\":\"%d\"},", (((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).location).type); \
		ratelprof_add_to_buffer(buf, "\"id\":{\"type\":\"int\",\"value\":\"%d\"}", (((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).location).id); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"win32SecurityAttributes\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", ((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).win32SecurityAttributes); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned char[64]\",\"value\":{\"addr\":\"%p\"", ((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).reserved); \
		if (((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).reserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%hhu\"", *((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).reserved); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"accessDescs\":{\"type\":\"struct const hipMemAccessDesc *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphAddMemAllocNode.pNodeParams).accessDescs); \
		if ((*args->hipGraphAddMemAllocNode.pNodeParams).accessDescs != NULL) { \
			ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
			ratelprof_add_to_buffer(buf, "\"location\":{\"type\":\"struct hipMemLocation\",\"value\":{"); \
			ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipMemLocationType\",\"value\":\"%d\"},", ((*(*args->hipGraphAddMemAllocNode.pNodeParams).accessDescs).location).type); \
			ratelprof_add_to_buffer(buf, "\"id\":{\"type\":\"int\",\"value\":\"%d\"}", ((*(*args->hipGraphAddMemAllocNode.pNodeParams).accessDescs).location).id); \
			ratelprof_add_to_buffer(buf, "}},"); \
			ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"hipMemAccessFlags\",\"value\":\"%d\"}", (*(*args->hipGraphAddMemAllocNode.pNodeParams).accessDescs).flags); \
			ratelprof_add_to_buffer(buf, "}"); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"accessDescCount\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGraphAddMemAllocNode.pNodeParams).accessDescCount); \
		ratelprof_add_to_buffer(buf, "\"bytesize\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGraphAddMemAllocNode.pNodeParams).bytesize); \
		ratelprof_add_to_buffer(buf, "\"dptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphAddMemAllocNode.pNodeParams).dptr); \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostMalloc(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipHostMalloc.ptr); \
	if (args->hipHostMalloc.ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipHostMalloc.ptr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipHostMalloc.size); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipHostMalloc.flags); \
};

//	hipGraphNode_t node (unknown);
//	hipMemcpy3DParms * pNodeParams (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"hipMemcpy3DParms *\",\"value\":\"NULL\"}"); \
};

//	textureReference * texRef (unknown);
//	unsigned int Flags (unsigned int);
#define PROCESS_ARGS_hipTexRefSetFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"Flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipTexRefSetFlags.Flags); \
};

//	hipMemPool_t * mem_pool (unknown);
//	void * shared_handle (void*);
//	hipMemAllocationHandleType handle_type (enum);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMemPoolImportFromShareableHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"shared_handle\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemPoolImportFromShareableHandle.shared_handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"handle_type\":{\"type\":\"hipMemAllocationHandleType\",\"value\":\"%d\"},", args->hipMemPoolImportFromShareableHandle.handle_type); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMemPoolImportFromShareableHandle.flags); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t hNode (unknown);
//	unsigned int isEnabled (unsigned int);
#define PROCESS_ARGS_hipGraphNodeSetEnabled(args) { \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"isEnabled\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipGraphNodeSetEnabled.isEnabled); \
};

//	textureReference * texRef (unknown);
//	float bias (float);
#define PROCESS_ARGS_hipTexRefSetMipmapLevelBias(args) { \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"bias\":{\"type\":\"float\",\"value\":\"%f\"}", args->hipTexRefSetMipmapLevelBias.bias); \
};

//	hipStream_t stream (unknown);
//	void * ptr (void*);
//	uint32_t value (unsigned int);
//	unsigned int flags (unsigned int);
//	uint32_t mask (unsigned int);
#define PROCESS_ARGS_hipStreamWaitValue32(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipStreamWaitValue32.ptr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipStreamWaitValue32.value); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipStreamWaitValue32.flags); \
	ratelprof_add_to_buffer(buf, "\"mask\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->hipStreamWaitValue32.mask); \
};

//	hipMipmappedArray_t hMipmappedArray (unknown);
#define PROCESS_ARGS_hipMipmappedArrayDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"hMipmappedArray\":{\"type\":\"hipMipmappedArray_t\",\"value\":\"NULL\"}"); \
};

//	hipCtx_t ctx (unknown);
#define PROCESS_ARGS_hipCtxDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t\",\"value\":\"NULL\"}"); \
};


#define PROCESS_ARGS_hipDeviceReset(args) { \
\
};

//	const void * dev_ptr (void*);
//	size_t count (unsigned long);
//	int device (int);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemPrefetchAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemPrefetchAsync.dev_ptr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemPrefetchAsync.count); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemPrefetchAsync.device); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipDeviceptr_t dest (unknown);
//	unsigned short value (unsigned short);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemsetD16(args) { \
	ratelprof_add_to_buffer(buf, "\"dest\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"unsigned short\",\"value\":\"%hu\"},", args->hipMemsetD16.value); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemsetD16.count); \
};

//	void * dst (void*);
//	size_t dpitch (unsigned long);
//	const void * src (void*);
//	size_t spitch (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpy2DAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpy2DAsync.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dpitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DAsync.dpitch); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpy2DAsync.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"spitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DAsync.spitch); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DAsync.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DAsync.height); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipDevice_t dev (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipDevicePrimaryCtxSetFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"dev\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"},", args->hipDevicePrimaryCtxSetFlags.dev); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipDevicePrimaryCtxSetFlags.flags); \
};

//	hipGraphExec_t * pGraphExec (unknown);
//	hipGraph_t graph (unknown);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipGraphInstantiateWithFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphExec\":{\"type\":\"hipGraphExec_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned long long\",\"value\":\"%llu\"}", args->hipGraphInstantiateWithFlags.flags); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphAddEmptyNode(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipGraphAddEmptyNode.numDependencies); \
};

//	hipMipmappedArray_t mipmappedArray (unknown);
#define PROCESS_ARGS_hipFreeMipmappedArray(args) { \
	ratelprof_add_to_buffer(buf, "\"mipmappedArray\":{\"type\":\"hipMipmappedArray_t\",\"value\":\"NULL\"}"); \
};

//	hipArray_t * pHandle (unknown);
//	const HIP_ARRAY_DESCRIPTOR * pAllocateArray (unknown);
#define PROCESS_ARGS_hipArrayCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"pHandle\":{\"type\":\"hipArray_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pAllocateArray\":{\"type\":\"const HIP_ARRAY_DESCRIPTOR *\",\"value\":\"NULL\"}"); \
};

//	const textureReference * tex (unknown);
#define PROCESS_ARGS_hipUnbindTexture(args) { \
	ratelprof_add_to_buffer(buf, "\"tex\":{\"type\":\"const textureReference *\",\"value\":\"NULL\"}"); \
};

//	hipCtx_t * ctx (unknown);
#define PROCESS_ARGS_hipCtxPopCurrent(args) { \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t *\",\"value\":\"NULL\"}"); \
};

//	hipDeviceptr_t dest (unknown);
//	unsigned short value (unsigned short);
//	size_t count (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemsetD16Async(args) { \
	ratelprof_add_to_buffer(buf, "\"dest\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"unsigned short\",\"value\":\"%hu\"},", args->hipMemsetD16Async.value); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemsetD16Async.count); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	HIP_RESOURCE_DESC * pResDesc (unknown);
//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectGetResourceDesc(args) { \
	ratelprof_add_to_buffer(buf, "\"pResDesc\":{\"type\":\"HIP_RESOURCE_DESC *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"texObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"NULL\"}"); \
};

//	const void * function_address (void*);
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
//	void ** args (void**);
//	size_t sharedMemBytes (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipLaunchKernel(args) { \
	ratelprof_add_to_buffer(buf, "\"function_address\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipLaunchKernel.function_address); \
	ratelprof_add_to_buffer(buf, "}},"); \
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
	ratelprof_add_to_buffer(buf, "\"args\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipLaunchKernel.args); \
	if (args->hipLaunchKernel.args != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipLaunchKernel.args); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sharedMemBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipLaunchKernel.sharedMemBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t node (unknown);
//	struct hipMemsetParams * pNodeParams ({
//		void * dst (void*);
//		unsigned int elementSize (unsigned int);
//		int height (int);
//		int pitch (int);
//		unsigned int value (unsigned int);
//		int width (int);
//	});
#define PROCESS_ARGS_hipGraphMemsetNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"struct hipMemsetParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphMemsetNodeGetParams.pNodeParams); \
	if (args->hipGraphMemsetNodeGetParams.pNodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphMemsetNodeGetParams.pNodeParams).dst); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"elementSize\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipGraphMemsetNodeGetParams.pNodeParams).elementSize); \
		ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGraphMemsetNodeGetParams.pNodeParams).height); \
		ratelprof_add_to_buffer(buf, "\"pitch\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGraphMemsetNodeGetParams.pNodeParams).pitch); \
		ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipGraphMemsetNodeGetParams.pNodeParams).value); \
		ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"int\",\"value\":\"%d\"}", (*args->hipGraphMemsetNodeGetParams.pNodeParams).width); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	unsigned int * flagsPtr (unsigned int*);
//	void * hostPtr (void*);
#define PROCESS_ARGS_hipHostGetFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"flagsPtr\":{\"type\":\"unsigned int *\",\"value\":{\"addr\":\"%p\"", args->hipHostGetFlags.flagsPtr); \
	if (args->hipHostGetFlags.flagsPtr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *args->hipHostGetFlags.flagsPtr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"hostPtr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipHostGetFlags.hostPtr); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphExec_t graphExec (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipGraphLaunch(args) { \
	ratelprof_add_to_buffer(buf, "\"graphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	void * dst (void*);
//	const void * src (void*);
//	size_t sizeBytes (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyAsync.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyAsync.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipArray_t * array (unknown);
//	const hipChannelFormatDesc * desc (unknown);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMallocArray(args) { \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const hipChannelFormatDesc *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMallocArray.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMallocArray.height); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMallocArray.flags); \
};

//	const void * func (void*);
//	hipFuncCache_t config (enum);
#define PROCESS_ARGS_hipFuncSetCacheConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipFuncSetCacheConfig.func); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"config\":{\"type\":\"hipFuncCache_t\",\"value\":\"%d\"}", args->hipFuncSetCacheConfig.config); \
};

//	void ** dev_ptr (void**);
//	size_t size (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMallocManaged(args) { \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipMallocManaged.dev_ptr); \
	if (args->hipMallocManaged.dev_ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipMallocManaged.dev_ptr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMallocManaged.size); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMallocManaged.flags); \
};

//	uint32_t id (unsigned int);
#define PROCESS_ARGS_hipApiName(args) { \
	ratelprof_add_to_buffer(buf, "\"id\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", args->hipApiName.id); \
};

//	void * ptr (void*);
#define PROCESS_ARGS_hipFreeHost(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipFreeHost.ptr); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipCtx_t * ctx (unknown);
#define PROCESS_ARGS_hipCtxGetCurrent(args) { \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t *\",\"value\":\"NULL\"}"); \
};

//	hipSurfaceObject_t surfaceObject (unknown);
#define PROCESS_ARGS_hipDestroySurfaceObject(args) { \
	ratelprof_add_to_buffer(buf, "\"surfaceObject\":{\"type\":\"hipSurfaceObject_t\",\"value\":\"NULL\"}"); \
};

//	void ** ptr (void**);
//	size_t * pitch (unsigned long*);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
#define PROCESS_ARGS_hipMallocPitch(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipMallocPitch.ptr); \
	if (args->hipMallocPitch.ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipMallocPitch.ptr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"pitch\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipMallocPitch.pitch); \
	if (args->hipMallocPitch.pitch != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipMallocPitch.pitch); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMallocPitch.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMallocPitch.height); \
};

//	hipStream_t stream (unknown);
//	hipStreamCaptureStatus * pCaptureStatus (enum*);
//	unsigned long long * pId (unsigned long long*);
#define PROCESS_ARGS_hipStreamGetCaptureInfo(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pCaptureStatus\":{\"type\":\"hipStreamCaptureStatus *\",\"value\":{\"addr\":\"%p\"", args->hipStreamGetCaptureInfo.pCaptureStatus); \
	if (args->hipStreamGetCaptureInfo.pCaptureStatus != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipStreamGetCaptureInfo.pCaptureStatus); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"pId\":{\"type\":\"unsigned long long *\",\"value\":{\"addr\":\"%p\"", args->hipStreamGetCaptureInfo.pId); \
	if (args->hipStreamGetCaptureInfo.pId != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%llu\"", *args->hipStreamGetCaptureInfo.pId); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipStream_t stream (unknown);
//	hipGraphNode_t * dependencies (unknown);
//	size_t numDependencies (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamUpdateCaptureDependencies(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dependencies\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipStreamUpdateCaptureDependencies.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipStreamUpdateCaptureDependencies.flags); \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostAlloc(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipHostAlloc.ptr); \
	if (args->hipHostAlloc.ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipHostAlloc.ptr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipHostAlloc.size); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipHostAlloc.flags); \
};

//	hipDeviceptr_t dest (unknown);
//	unsigned char value (unsigned char);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemsetD8(args) { \
	ratelprof_add_to_buffer(buf, "\"dest\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"unsigned char\",\"value\":\"%hhu\"},", args->hipMemsetD8.value); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemsetD8.count); \
};

//	hipPitchedPtr pitchedDevPtr (unknown);
//	int value (int);
//	hipExtent extent (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemset3DAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"pitchedDevPtr\":{\"type\":\"hipPitchedPtr\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemset3DAsync.value); \
	ratelprof_add_to_buffer(buf, "\"extent\":{\"type\":\"hipExtent\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	const hip_Memcpy2D * pCopy (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyParam2DAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"pCopy\":{\"type\":\"const hip_Memcpy2D *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipError_t hipError (enum);
//	const char ** errorString (char**);
#define PROCESS_ARGS_hipDrvGetErrorName(args) { \
	ratelprof_add_to_buffer(buf, "\"hipError\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDrvGetErrorName.hipError); \
	ratelprof_add_to_buffer(buf, "\"errorString\":{\"type\":\"const char **\",\"value\":{\"addr\":\"%p\"", args->hipDrvGetErrorName.errorString); \
	if (args->hipDrvGetErrorName.errorString != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipDrvGetErrorName.errorString); \
		if (*args->hipDrvGetErrorName.errorString != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->**\":\"%c\"", **args->hipDrvGetErrorName.errorString); \
		} \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	const void * value (void*);
//	hipPointer_attribute attribute (unknown);
//	hipDeviceptr_t ptr (unknown);
#define PROCESS_ARGS_hipPointerSetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipPointerSetAttribute.value); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hipPointer_attribute\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
};

//	size_t * free (unsigned long*);
//	size_t * total (unsigned long*);
#define PROCESS_ARGS_hipMemGetInfo(args) { \
	ratelprof_add_to_buffer(buf, "\"free\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipMemGetInfo.free); \
	if (args->hipMemGetInfo.free != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipMemGetInfo.free); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"total\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipMemGetInfo.total); \
	if (args->hipMemGetInfo.total != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipMemGetInfo.total); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
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
//	hipStream_t stream (unknown);
#define PROCESS_ARGS___hipPushCallConfiguration(args) { \
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
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipArray_Format * pFormat (unknown);
//	int * pNumChannels (int*);
//	const textureReference * texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetFormat(args) { \
	ratelprof_add_to_buffer(buf, "\"pFormat\":{\"type\":\"hipArray_Format *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNumChannels\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipTexRefGetFormat.pNumChannels); \
	if (args->hipTexRefGetFormat.pNumChannels != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipTexRefGetFormat.pNumChannels); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference *\",\"value\":\"NULL\"}"); \
};

//	void * shareableHandle (void*);
//	hipMemGenericAllocationHandle_t handle (unknown);
//	hipMemAllocationHandleType handleType (enum);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipMemExportToShareableHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"shareableHandle\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemExportToShareableHandle.shareableHandle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipMemGenericAllocationHandle_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"handleType\":{\"type\":\"hipMemAllocationHandleType\",\"value\":\"%d\"},", args->hipMemExportToShareableHandle.handleType); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned long long\",\"value\":\"%llu\"}", args->hipMemExportToShareableHandle.flags); \
};

//	enum hipTextureFilterMode * pfm (enum);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetFilterMode(args) { \
	ratelprof_add_to_buffer(buf, "\"pfm\":{\"type\":\"enum hipTextureFilterMode *\",\"value\":\"%d\"},", args->hipTexRefGetFilterMode.pfm); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t node (unknown);
//	struct const hipHostNodeParams * pNodeParams ({
//		hipHostFn_t fn (void*);
//		void * userData (void*);
//	});
#define PROCESS_ARGS_hipGraphHostNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"struct const hipHostNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphHostNodeSetParams.pNodeParams); \
	if (args->hipGraphHostNodeSetParams.pNodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"fn\":{\"type\":\"hipHostFn_t\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphHostNodeSetParams.pNodeParams).fn); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"userData\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphHostNodeSetParams.pNodeParams).userData); \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraph_t graph (unknown);
//	hipGraphNode_t * nodes (unknown);
//	size_t * numNodes (unsigned long*);
#define PROCESS_ARGS_hipGraphGetNodes(args) { \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"nodes\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numNodes\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipGraphGetNodes.numNodes); \
	if (args->hipGraphGetNodes.numNodes != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipGraphGetNodes.numNodes); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipDevice_t * device (int*);
#define PROCESS_ARGS_hipCtxGetDevice(args) { \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t *\",\"value\":{\"addr\":\"%p\"", args->hipCtxGetDevice.device); \
	if (args->hipCtxGetDevice.device != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipCtxGetDevice.device); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	void ** devPtr (void**);
//	const void * symbol (void*);
#define PROCESS_ARGS_hipGetSymbolAddress(args) { \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipGetSymbolAddress.devPtr); \
	if (args->hipGetSymbolAddress.devPtr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipGetSymbolAddress.devPtr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipGetSymbolAddress.symbol); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipStream_t stream (unknown);
//	hipStreamCaptureStatus * captureStatus_out (enum*);
//	unsigned long long * id_out (unsigned long long*);
//	hipGraph_t * graph_out (unknown);
//	const hipGraphNode_t ** dependencies_out (unknown);
//	size_t * numDependencies_out (unsigned long*);
#define PROCESS_ARGS_hipStreamGetCaptureInfo_v2(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"captureStatus_out\":{\"type\":\"hipStreamCaptureStatus *\",\"value\":{\"addr\":\"%p\"", args->hipStreamGetCaptureInfo_v2.captureStatus_out); \
	if (args->hipStreamGetCaptureInfo_v2.captureStatus_out != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipStreamGetCaptureInfo_v2.captureStatus_out); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"id_out\":{\"type\":\"unsigned long long *\",\"value\":{\"addr\":\"%p\"", args->hipStreamGetCaptureInfo_v2.id_out); \
	if (args->hipStreamGetCaptureInfo_v2.id_out != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%llu\"", *args->hipStreamGetCaptureInfo_v2.id_out); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"graph_out\":{\"type\":\"hipGraph_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dependencies_out\":{\"type\":\"const hipGraphNode_t **\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies_out\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipStreamGetCaptureInfo_v2.numDependencies_out); \
	if (args->hipStreamGetCaptureInfo_v2.numDependencies_out != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipStreamGetCaptureInfo_v2.numDependencies_out); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	size_t* size (unsigned long*);
//	const void * symbol (void*);
#define PROCESS_ARGS_hipGetSymbolSize(args) { \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t*\",\"value\":{\"addr\":\"%p\"", args->hipGetSymbolSize.size); \
	if (args->hipGetSymbolSize.size != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipGetSymbolSize.size); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipGetSymbolSize.symbol); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t node (unknown);
//	struct const hipHostNodeParams * pNodeParams ({
//		hipHostFn_t fn (void*);
//		void * userData (void*);
//	});
#define PROCESS_ARGS_hipGraphExecHostNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"struct const hipHostNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExecHostNodeSetParams.pNodeParams); \
	if (args->hipGraphExecHostNodeSetParams.pNodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"fn\":{\"type\":\"hipHostFn_t\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExecHostNodeSetParams.pNodeParams).fn); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"userData\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExecHostNodeSetParams.pNodeParams).userData); \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipMemPool_t mem_pool (unknown);
//	hipMemPoolAttr attr (enum);
//	void * value (void*);
#define PROCESS_ARGS_hipMemPoolSetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipMemPoolAttr\",\"value\":\"%d\"},", args->hipMemPoolSetAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemPoolSetAttribute.value); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int device (int);
//	hipMemPool_t mem_pool (unknown);
#define PROCESS_ARGS_hipDeviceSetMemPool(args) { \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceSetMemPool.device); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"NULL\"}"); \
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
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipConfigureCall(args) { \
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
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipMipmappedArray_t * pHandle (unknown);
//	HIP_ARRAY3D_DESCRIPTOR * pMipmappedArrayDesc (unknown);
//	unsigned int numMipmapLevels (unsigned int);
#define PROCESS_ARGS_hipMipmappedArrayCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"pHandle\":{\"type\":\"hipMipmappedArray_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pMipmappedArrayDesc\":{\"type\":\"HIP_ARRAY3D_DESCRIPTOR *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numMipmapLevels\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMipmappedArrayCreate.numMipmapLevels); \
};

//	void * hostPtr (void*);
//	size_t sizeBytes (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostRegister(args) { \
	ratelprof_add_to_buffer(buf, "\"hostPtr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipHostRegister.hostPtr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipHostRegister.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipHostRegister.flags); \
};

//	const textureReference * tex (unknown);
//	hipArray_const_t array (unknown);
//	const hipChannelFormatDesc * desc (unknown);
#define PROCESS_ARGS_hipBindTextureToArray(args) { \
	ratelprof_add_to_buffer(buf, "\"tex\":{\"type\":\"const textureReference *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_const_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const hipChannelFormatDesc *\",\"value\":\"NULL\"}"); \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMallocHost(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipMallocHost.ptr); \
	if (args->hipMallocHost.ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipMallocHost.ptr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMallocHost.size); \
};

//	void * dst (void*);
//	int dstDeviceId (int);
//	const void * src (void*);
//	int srcDeviceId (int);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemcpyPeer(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyPeer.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dstDeviceId\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemcpyPeer.dstDeviceId); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyPeer.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"srcDeviceId\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemcpyPeer.srcDeviceId); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemcpyPeer.sizeBytes); \
};

//	int * numBlocks (int*);
//	const void * f (void*);
//	int blockSize (int);
//	size_t dynSharedMemPerBlk (unsigned long);
#define PROCESS_ARGS_hipOccupancyMaxActiveBlocksPerMultiprocessor(args) { \
	ratelprof_add_to_buffer(buf, "\"numBlocks\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks); \
	if (args->hipOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.f); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"blockSize\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.blockSize); \
	ratelprof_add_to_buffer(buf, "\"dynSharedMemPerBlk\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.dynSharedMemPerBlk); \
};

//	int * pi (int*);
//	hipDeviceAttribute_t attr (enum);
//	int deviceId (int);
#define PROCESS_ARGS_hipDeviceGetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"pi\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceGetAttribute.pi); \
	if (args->hipDeviceGetAttribute.pi != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipDeviceGetAttribute.pi); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipDeviceAttribute_t\",\"value\":\"%d\"},", args->hipDeviceGetAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"deviceId\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceGetAttribute.deviceId); \
};

//	hipDevice_t dev (int);
#define PROCESS_ARGS_hipDevicePrimaryCtxReset(args) { \
	ratelprof_add_to_buffer(buf, "\"dev\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipDevicePrimaryCtxReset.dev); \
};

//	size_t * ByteOffset (unsigned long*);
//	textureReference * texRef (unknown);
//	hipDeviceptr_t dptr (unknown);
//	size_t bytes (unsigned long);
#define PROCESS_ARGS_hipTexRefSetAddress(args) { \
	ratelprof_add_to_buffer(buf, "\"ByteOffset\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipTexRefSetAddress.ByteOffset); \
	if (args->hipTexRefSetAddress.ByteOffset != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipTexRefSetAddress.ByteOffset); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dptr\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"bytes\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipTexRefSetAddress.bytes); \
};

//	void ** devPtr (void**);
//	size_t* size (unsigned long*);
//	hipGraphicsResource_t resource (unknown);
#define PROCESS_ARGS_hipGraphicsResourceGetMappedPointer(args) { \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipGraphicsResourceGetMappedPointer.devPtr); \
	if (args->hipGraphicsResourceGetMappedPointer.devPtr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipGraphicsResourceGetMappedPointer.devPtr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t*\",\"value\":{\"addr\":\"%p\"", args->hipGraphicsResourceGetMappedPointer.size); \
	if (args->hipGraphicsResourceGetMappedPointer.size != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipGraphicsResourceGetMappedPointer.size); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"resource\":{\"type\":\"hipGraphicsResource_t\",\"value\":\"NULL\"}"); \
};

//	hipSharedMemConfig config (enum);
#define PROCESS_ARGS_hipCtxSetSharedMemConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"config\":{\"type\":\"hipSharedMemConfig\",\"value\":\"%d\"}", args->hipCtxSetSharedMemConfig.config); \
};

//	hipGraphNode_t hNode (unknown);
//	struct hipExternalSemaphoreSignalNodeParams * params_out ({
//		hipExternalSemaphore_t * extSemArray (void**);
//		struct const hipExternalSemaphoreSignalParams * paramsArray ({
//			struct (unnamed struct at ./input/hip_runtime_api.h:1136:3) params (unknown);
//			unsigned int flags (unsigned int);
//			unsigned int[16] reserved (unsigned int*);
//		});
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphExternalSemaphoresSignalNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"params_out\":{\"type\":\"struct hipExternalSemaphoreSignalNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out); \
	if (args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"extSemArray\":{\"type\":\"hipExternalSemaphore_t *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).extSemArray); \
		if ((*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).extSemArray != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).extSemArray); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"paramsArray\":{\"type\":\"struct const hipExternalSemaphoreSignalParams *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).paramsArray); \
		if ((*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).paramsArray != NULL) { \
			ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
			ratelprof_add_to_buffer(buf, "\"params\":{\"type\":\"struct (unnamed struct at ./input/hip_runtime_api.h:1136:3)\",\"value\":\"NULL\"}"); \
			ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*(*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).paramsArray).flags); \
			ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned int[16]\",\"value\":{\"addr\":\"%p\"", (*(*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).paramsArray).reserved); \
			if ((*(*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).paramsArray).reserved != NULL) { \
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*(*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).paramsArray).reserved); \
			} \
			ratelprof_add_to_buffer(buf, "}}"); \
			ratelprof_add_to_buffer(buf, "}"); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"numExtSems\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", (*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).numExtSems); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipArrayDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t\",\"value\":\"NULL\"}"); \
};

//	void * dev_ptr (void*);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipFreeAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipFreeAsync.dev_ptr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	HIP_ARRAY3D_DESCRIPTOR * pArrayDescriptor (unknown);
//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipArray3DGetDescriptor(args) { \
	ratelprof_add_to_buffer(buf, "\"pArrayDescriptor\":{\"type\":\"HIP_ARRAY3D_DESCRIPTOR *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t\",\"value\":\"NULL\"}"); \
};

//	char * pciBusId (char*);
//	int len (int);
//	int device (int);
#define PROCESS_ARGS_hipDeviceGetPCIBusId(args) { \
	ratelprof_add_to_buffer(buf, "\"pciBusId\":{\"type\":\"char *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceGetPCIBusId.pciBusId); \
	if (args->hipDeviceGetPCIBusId.pciBusId != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *args->hipDeviceGetPCIBusId.pciBusId); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"len\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceGetPCIBusId.len); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceGetPCIBusId.device); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	void * dev_ptr (void*);
#define PROCESS_ARGS_hipGraphAddMemFreeNode(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemFreeNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphAddMemFreeNode.dev_ptr); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipArray_t * array (unknown);
//	const HIP_ARRAY3D_DESCRIPTOR * pAllocateArray (unknown);
#define PROCESS_ARGS_hipArray3DCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pAllocateArray\":{\"type\":\"const HIP_ARRAY3D_DESCRIPTOR *\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t hNode (unknown);
//	struct const hipExternalSemaphoreSignalNodeParams * nodeParams ({
//		hipExternalSemaphore_t * extSemArray (void**);
//		struct const hipExternalSemaphoreSignalParams * paramsArray ({
//			struct (unnamed struct at ./input/hip_runtime_api.h:1136:3) params (unknown);
//			unsigned int flags (unsigned int);
//			unsigned int[16] reserved (unsigned int*);
//		});
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphExternalSemaphoresSignalNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"nodeParams\":{\"type\":\"struct const hipExternalSemaphoreSignalNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams); \
	if (args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"extSemArray\":{\"type\":\"hipExternalSemaphore_t *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).extSemArray); \
		if ((*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).extSemArray != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).extSemArray); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"paramsArray\":{\"type\":\"struct const hipExternalSemaphoreSignalParams *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray); \
		if ((*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray != NULL) { \
			ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
			ratelprof_add_to_buffer(buf, "\"params\":{\"type\":\"struct (unnamed struct at ./input/hip_runtime_api.h:1136:3)\",\"value\":\"NULL\"}"); \
			ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*(*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).flags); \
			ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned int[16]\",\"value\":{\"addr\":\"%p\"", (*(*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).reserved); \
			if ((*(*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).reserved != NULL) { \
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*(*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).reserved); \
			} \
			ratelprof_add_to_buffer(buf, "}}"); \
			ratelprof_add_to_buffer(buf, "}"); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"numExtSems\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", (*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).numExtSems); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	float * pBorderColor (float*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetBorderColor(args) { \
	ratelprof_add_to_buffer(buf, "\"pBorderColor\":{\"type\":\"float *\",\"value\":{\"addr\":\"%p\"", args->hipTexRefGetBorderColor.pBorderColor); \
	if (args->hipTexRefGetBorderColor.pBorderColor != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%f\"", *args->hipTexRefGetBorderColor.pBorderColor); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"NULL\"}"); \
};

//	hipDeviceptr_t * dptr (unknown);
//	size_t* bytes (unsigned long*);
//	hipModule_t hmod (unknown);
//	const char * name (char*);
#define PROCESS_ARGS_hipModuleGetGlobal(args) { \
	ratelprof_add_to_buffer(buf, "\"dptr\":{\"type\":\"hipDeviceptr_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"bytes\":{\"type\":\"size_t*\",\"value\":{\"addr\":\"%p\"", args->hipModuleGetGlobal.bytes); \
	if (args->hipModuleGetGlobal.bytes != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipModuleGetGlobal.bytes); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"hmod\":{\"type\":\"hipModule_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"name\":{\"type\":\"const char *\",\"value\":{\"addr\":\"%p\"", args->hipModuleGetGlobal.name); \
	if (args->hipModuleGetGlobal.name != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *args->hipModuleGetGlobal.name); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipMipmappedArray_t * mipmappedArray (unknown);
//	const struct hipChannelFormatDesc * desc (unknown);
//	struct hipExtent extent (unknown);
//	unsigned int numLevels (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMallocMipmappedArray(args) { \
	ratelprof_add_to_buffer(buf, "\"mipmappedArray\":{\"type\":\"hipMipmappedArray_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const struct hipChannelFormatDesc *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"extent\":{\"type\":\"struct hipExtent\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numLevels\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipMallocMipmappedArray.numLevels); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMallocMipmappedArray.flags); \
};


#define PROCESS_ARGS_hipProfilerStart(args) { \
\
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t node (unknown);
//	hipMemcpy3DParms * pNodeParams (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"hipMemcpy3DParms *\",\"value\":\"NULL\"}"); \
};

//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipEventSynchronize(args) { \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
};

//	struct hipMemPoolPtrExportData * export_data ({
//		unsigned char[64] reserved (unsigned char*);
//	});
//	void * dev_ptr (void*);
#define PROCESS_ARGS_hipMemPoolExportPointer(args) { \
	ratelprof_add_to_buffer(buf, "\"export_data\":{\"type\":\"struct hipMemPoolPtrExportData *\",\"value\":{\"addr\":\"%p\"", args->hipMemPoolExportPointer.export_data); \
	if (args->hipMemPoolExportPointer.export_data != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned char[64]\",\"value\":{\"addr\":\"%p\"", (*args->hipMemPoolExportPointer.export_data).reserved); \
		if ((*args->hipMemPoolExportPointer.export_data).reserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%hhu\"", *(*args->hipMemPoolExportPointer.export_data).reserved); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemPoolExportPointer.dev_ptr); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	void * hostPtr (void*);
#define PROCESS_ARGS_hipHostUnregister(args) { \
	ratelprof_add_to_buffer(buf, "\"hostPtr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipHostUnregister.hostPtr); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	void * dst (void*);
//	size_t pitch (unsigned long);
//	int value (int);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
#define PROCESS_ARGS_hipMemset2D(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemset2D.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemset2D.pitch); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemset2D.value); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemset2D.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemset2D.height); \
};

//	void * dst (void*);
//	size_t dpitch (unsigned long);
//	hipArray_const_t src (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpy2DFromArray(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpy2DFromArray.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dpitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArray.dpitch); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"hipArray_const_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"wOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArray.wOffset); \
	ratelprof_add_to_buffer(buf, "\"hOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArray.hOffset); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArray.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArray.height); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
//	size_t alignment (unsigned long);
//	void * addr (void*);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipMemAddressReserve(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipMemAddressReserve.ptr); \
	if (args->hipMemAddressReserve.ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipMemAddressReserve.ptr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemAddressReserve.size); \
	ratelprof_add_to_buffer(buf, "\"alignment\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemAddressReserve.alignment); \
	ratelprof_add_to_buffer(buf, "\"addr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemAddressReserve.addr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned long long\",\"value\":\"%llu\"}", args->hipMemAddressReserve.flags); \
};

//	const void * func (void*);
//	hipSharedMemConfig config (enum);
#define PROCESS_ARGS_hipFuncSetSharedMemConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipFuncSetSharedMemConfig.func); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"config\":{\"type\":\"hipSharedMemConfig\",\"value\":\"%d\"}", args->hipFuncSetSharedMemConfig.config); \
};

//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipDestroyTextureObject(args) { \
	ratelprof_add_to_buffer(buf, "\"textureObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"NULL\"}"); \
};

//	textureReference* texRef (unknown);
//	unsigned int maxAniso (unsigned int);
#define PROCESS_ARGS_hipTexRefSetMaxAnisotropy(args) { \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"maxAniso\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipTexRefSetMaxAnisotropy.maxAniso); \
};

//	textureReference* texRef (unknown);
//	const HIP_ARRAY_DESCRIPTOR * desc (unknown);
//	hipDeviceptr_t dptr (unknown);
//	size_t Pitch (unsigned long);
#define PROCESS_ARGS_hipTexRefSetAddress2D(args) { \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const HIP_ARRAY_DESCRIPTOR *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dptr\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"Pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipTexRefSetAddress2D.Pitch); \
};

//	int * deviceId (int*);
#define PROCESS_ARGS_hipGetDevice(args) { \
	ratelprof_add_to_buffer(buf, "\"deviceId\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipGetDevice.deviceId); \
	if (args->hipGetDevice.deviceId != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipGetDevice.deviceId); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int device (int);
//	hipGraphMemAttributeType attr (enum);
//	void * value (void*);
#define PROCESS_ARGS_hipDeviceGetGraphMemAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceGetGraphMemAttribute.device); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipGraphMemAttributeType\",\"value\":\"%d\"},", args->hipDeviceGetGraphMemAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceGetGraphMemAttribute.value); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipArray_t * array (unknown);
//	hipGraphicsResource_t resource (unknown);
//	unsigned int arrayIndex (unsigned int);
//	unsigned int mipLevel (unsigned int);
#define PROCESS_ARGS_hipGraphicsSubResourceGetMappedArray(args) { \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"resource\":{\"type\":\"hipGraphicsResource_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"arrayIndex\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipGraphicsSubResourceGetMappedArray.arrayIndex); \
	ratelprof_add_to_buffer(buf, "\"mipLevel\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipGraphicsSubResourceGetMappedArray.mipLevel); \
};

//	hipGraphNode_t node (unknown);
//	const void * symbol (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParamsToSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphMemcpyNodeSetParamsToSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphMemcpyNodeSetParamsToSymbol.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphMemcpyNodeSetParamsToSymbol.count); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphMemcpyNodeSetParamsToSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	hipStream_t * stream (unknown);
#define PROCESS_ARGS_hipStreamCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t *\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t node (unknown);
//	hipGraphNode_t * pDependencies (unknown);
//	size_t* pNumDependencies (unsigned long*);
#define PROCESS_ARGS_hipGraphNodeGetDependencies(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNumDependencies\":{\"type\":\"size_t*\",\"value\":{\"addr\":\"%p\"", args->hipGraphNodeGetDependencies.pNumDependencies); \
	if (args->hipGraphNodeGetDependencies.pNumDependencies != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipGraphNodeGetDependencies.pNumDependencies); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	const textureReference* tex (unknown);
//	hipMipmappedArray_const_t mipmappedArray (unknown);
//	const hipChannelFormatDesc* desc (unknown);
#define PROCESS_ARGS_hipBindTextureToMipmappedArray(args) { \
	ratelprof_add_to_buffer(buf, "\"tex\":{\"type\":\"const textureReference*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"mipmappedArray\":{\"type\":\"hipMipmappedArray_const_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const hipChannelFormatDesc*\",\"value\":\"NULL\"}"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraph_t hGraph (unknown);
//	hipGraphNode_t * hErrorNode_out (unknown);
//	hipGraphExecUpdateResult * updateResult_out (enum*);
#define PROCESS_ARGS_hipGraphExecUpdate(args) { \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"hGraph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"hErrorNode_out\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"updateResult_out\":{\"type\":\"hipGraphExecUpdateResult *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExecUpdate.updateResult_out); \
	if (args->hipGraphExecUpdate.updateResult_out != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipGraphExecUpdate.updateResult_out); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	size_t* bytes (unsigned long*);
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceTotalMem(args) { \
	ratelprof_add_to_buffer(buf, "\"bytes\":{\"type\":\"size_t*\",\"value\":{\"addr\":\"%p\"", args->hipDeviceTotalMem.bytes); \
	if (args->hipDeviceTotalMem.bytes != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipDeviceTotalMem.bytes); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipDeviceTotalMem.device); \
};

//	void * dst (void*);
//	hipArray_const_t srcArray (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpyFromArray(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyFromArray.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"srcArray\":{\"type\":\"hipArray_const_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"wOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyFromArray.wOffset); \
	ratelprof_add_to_buffer(buf, "\"hOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyFromArray.hOffset); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyFromArray.count); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	hipEvent_t * event (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipEventCreateWithFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipEventCreateWithFlags.flags); \
};

//	hipFuncCache_t * cacheConfig (enum*);
#define PROCESS_ARGS_hipDeviceGetCacheConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"cacheConfig\":{\"type\":\"hipFuncCache_t *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceGetCacheConfig.cacheConfig); \
	if (args->hipDeviceGetCacheConfig.cacheConfig != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipDeviceGetCacheConfig.cacheConfig); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int * driverVersion (int*);
#define PROCESS_ARGS_hipDriverGetVersion(args) { \
	ratelprof_add_to_buffer(buf, "\"driverVersion\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipDriverGetVersion.driverVersion); \
	if (args->hipDriverGetVersion.driverVersion != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipDriverGetVersion.driverVersion); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphNode_t node (unknown);
//	void * dst (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParams1D(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphMemcpyNodeSetParams1D.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphMemcpyNodeSetParams1D.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphMemcpyNodeSetParams1D.count); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	textureReference* texRef (unknown);
//	float minMipMapLevelClamp (float);
//	float maxMipMapLevelClamp (float);
#define PROCESS_ARGS_hipTexRefSetMipmapLevelClamp(args) { \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"minMipMapLevelClamp\":{\"type\":\"float\",\"value\":\"%f\"},", args->hipTexRefSetMipmapLevelClamp.minMipMapLevelClamp); \
	ratelprof_add_to_buffer(buf, "\"maxMipMapLevelClamp\":{\"type\":\"float\",\"value\":\"%f\"}", args->hipTexRefSetMipmapLevelClamp.maxMipMapLevelClamp); \
};

//	hipGraphNode_t node (unknown);
//	struct hipMemAllocNodeParams * pNodeParams ({
//		hipMemPoolProps poolProps ({
//			hipMemAllocationType allocType (enum);
//			hipMemAllocationHandleType handleTypes (enum);
//			hipMemLocation location ({
//				hipMemLocationType type (enum);
//				int id (int);
//			});
//			void * win32SecurityAttributes (void*);
//			unsigned char[64] reserved (unsigned char*);
//		});
//		struct const hipMemAccessDesc * accessDescs ({
//			hipMemLocation location ({
//				hipMemLocationType type (enum);
//				int id (int);
//			});
//			hipMemAccessFlags flags (enum);
//		});
//		int accessDescCount (int);
//		int bytesize (int);
//		void * dptr (void*);
//	});
#define PROCESS_ARGS_hipGraphMemAllocNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"struct hipMemAllocNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphMemAllocNodeGetParams.pNodeParams); \
	if (args->hipGraphMemAllocNodeGetParams.pNodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"poolProps\":{\"type\":\"struct hipMemPoolProps\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"allocType\":{\"type\":\"hipMemAllocationType\",\"value\":\"%d\"},", ((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).allocType); \
		ratelprof_add_to_buffer(buf, "\"handleTypes\":{\"type\":\"hipMemAllocationHandleType\",\"value\":\"%d\"},", ((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).handleTypes); \
		ratelprof_add_to_buffer(buf, "\"location\":{\"type\":\"struct hipMemLocation\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipMemLocationType\",\"value\":\"%d\"},", (((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).location).type); \
		ratelprof_add_to_buffer(buf, "\"id\":{\"type\":\"int\",\"value\":\"%d\"}", (((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).location).id); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"win32SecurityAttributes\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", ((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).win32SecurityAttributes); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned char[64]\",\"value\":{\"addr\":\"%p\"", ((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).reserved); \
		if (((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).reserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%hhu\"", *((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).reserved); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"accessDescs\":{\"type\":\"struct const hipMemAccessDesc *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphMemAllocNodeGetParams.pNodeParams).accessDescs); \
		if ((*args->hipGraphMemAllocNodeGetParams.pNodeParams).accessDescs != NULL) { \
			ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
			ratelprof_add_to_buffer(buf, "\"location\":{\"type\":\"struct hipMemLocation\",\"value\":{"); \
			ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipMemLocationType\",\"value\":\"%d\"},", ((*(*args->hipGraphMemAllocNodeGetParams.pNodeParams).accessDescs).location).type); \
			ratelprof_add_to_buffer(buf, "\"id\":{\"type\":\"int\",\"value\":\"%d\"}", ((*(*args->hipGraphMemAllocNodeGetParams.pNodeParams).accessDescs).location).id); \
			ratelprof_add_to_buffer(buf, "}},"); \
			ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"hipMemAccessFlags\",\"value\":\"%d\"}", (*(*args->hipGraphMemAllocNodeGetParams.pNodeParams).accessDescs).flags); \
			ratelprof_add_to_buffer(buf, "}"); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"accessDescCount\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGraphMemAllocNodeGetParams.pNodeParams).accessDescCount); \
		ratelprof_add_to_buffer(buf, "\"bytesize\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGraphMemAllocNodeGetParams.pNodeParams).bytesize); \
		ratelprof_add_to_buffer(buf, "\"dptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphMemAllocNodeGetParams.pNodeParams).dptr); \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"texObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"NULL\"}"); \
};

//	hipStream_t * stream (unknown);
//	uint32_t cuMaskSize (unsigned int);
//	const uint32_t * cuMask (unsigned int*);
#define PROCESS_ARGS_hipExtStreamCreateWithCUMask(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"cuMaskSize\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipExtStreamCreateWithCUMask.cuMaskSize); \
	ratelprof_add_to_buffer(buf, "\"cuMask\":{\"type\":\"const uint32_t *\",\"value\":{\"addr\":\"%p\"", args->hipExtStreamCreateWithCUMask.cuMask); \
	if (args->hipExtStreamCreateWithCUMask.cuMask != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *args->hipExtStreamCreateWithCUMask.cuMask); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	struct dim3 * gridDim ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	struct dim3 * blockDim ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	size_t * sharedMem (unsigned long*);
//	hipStream_t * stream (unknown);
#define PROCESS_ARGS___hipPopCallConfiguration(args) { \
	ratelprof_add_to_buffer(buf, "\"gridDim\":{\"type\":\"struct dim3 *\",\"value\":{\"addr\":\"%p\"", args->__hipPopCallConfiguration.gridDim); \
	if (args->__hipPopCallConfiguration.gridDim != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", (*args->__hipPopCallConfiguration.gridDim).x); \
		ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", (*args->__hipPopCallConfiguration.gridDim).y); \
		ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", (*args->__hipPopCallConfiguration.gridDim).z); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"blockDim\":{\"type\":\"struct dim3 *\",\"value\":{\"addr\":\"%p\"", args->__hipPopCallConfiguration.blockDim); \
	if (args->__hipPopCallConfiguration.blockDim != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", (*args->__hipPopCallConfiguration.blockDim).x); \
		ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", (*args->__hipPopCallConfiguration.blockDim).y); \
		ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", (*args->__hipPopCallConfiguration.blockDim).z); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sharedMem\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->__hipPopCallConfiguration.sharedMem); \
	if (args->__hipPopCallConfiguration.sharedMem != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->__hipPopCallConfiguration.sharedMem); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t *\",\"value\":\"NULL\"}"); \
};

//	void * data (void*);
//	size_t data_size (unsigned long);
//	hipMemRangeAttribute attribute (enum);
//	const void * dev_ptr (void*);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemRangeGetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemRangeGetAttribute.data); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"data_size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemRangeGetAttribute.data_size); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hipMemRangeAttribute\",\"value\":\"%d\"},", args->hipMemRangeGetAttribute.attribute); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemRangeGetAttribute.dev_ptr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemRangeGetAttribute.count); \
};

//	void * ptr (void*);
//	size_t size (unsigned long);
//	size_t offset (unsigned long);
//	hipMemGenericAllocationHandle_t handle (unknown);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipMemMap(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemMap.ptr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemMap.size); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemMap.offset); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipMemGenericAllocationHandle_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned long long\",\"value\":\"%llu\"}", args->hipMemMap.flags); \
};

//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipStreamSynchronize(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipUserObject_t * object_out (unknown);
//	void * ptr (void*);
//	hipHostFn_t destroy (void*);
//	unsigned int initialRefcount (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipUserObjectCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"object_out\":{\"type\":\"hipUserObject_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipUserObjectCreate.ptr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"destroy\":{\"type\":\"hipHostFn_t\",\"value\":{\"addr\":\"%p\"", args->hipUserObjectCreate.destroy); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"initialRefcount\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipUserObjectCreate.initialRefcount); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipUserObjectCreate.flags); \
};

//	hipArray_t * levelArray (unknown);
//	hipMipmappedArray_const_t mipmappedArray (unknown);
//	unsigned int level (unsigned int);
#define PROCESS_ARGS_hipGetMipmappedArrayLevel(args) { \
	ratelprof_add_to_buffer(buf, "\"levelArray\":{\"type\":\"hipArray_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"mipmappedArray\":{\"type\":\"hipMipmappedArray_const_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"level\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipGetMipmappedArrayLevel.level); \
};

//	hipDeviceptr_t dst (unknown);
//	void * src (void*);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemcpyHtoD(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyHtoD.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemcpyHtoD.sizeBytes); \
};

//	hipDeviceptr_t * pbase (unknown);
//	size_t * psize (unsigned long*);
//	hipDeviceptr_t dptr (unknown);
#define PROCESS_ARGS_hipMemGetAddressRange(args) { \
	ratelprof_add_to_buffer(buf, "\"pbase\":{\"type\":\"hipDeviceptr_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"psize\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipMemGetAddressRange.psize); \
	if (args->hipMemGetAddressRange.psize != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipMemGetAddressRange.psize); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dptr\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	void * dst (void*);
//	const void * symbol (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphAddMemcpyNodeFromSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNodeFromSymbol.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphAddMemcpyNodeFromSymbol.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphAddMemcpyNodeFromSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNodeFromSymbol.count); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNodeFromSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	void * ptr (void*);
//	size_t* size (unsigned long*);
#define PROCESS_ARGS_hipMemPtrGetInfo(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemPtrGetInfo.ptr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t*\",\"value\":{\"addr\":\"%p\"", args->hipMemPtrGetInfo.size); \
	if (args->hipMemPtrGetInfo.size != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipMemPtrGetInfo.size); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	textureReference* texRef (unknown);
//	struct hipMipmappedArray * mipmappedArray (unknown);
//	unsigned int Flags (unsigned int);
#define PROCESS_ARGS_hipTexRefSetMipmappedArray(args) { \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"mipmappedArray\":{\"type\":\"struct hipMipmappedArray *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"Flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipTexRefSetMipmappedArray.Flags); \
};

//	hipExternalSemaphore_t * extSem_out (void**);
//	struct const hipExternalSemaphoreHandleDesc * semHandleDesc ({
//		hipExternalSemaphoreHandleType type (enum);
//		union (unnamed union at ./input/hip_runtime_api.h:1123:3) handle (unknown);
//		unsigned int flags (unsigned int);
//		unsigned int[16] reserved (unsigned int*);
//	});
#define PROCESS_ARGS_hipImportExternalSemaphore(args) { \
	ratelprof_add_to_buffer(buf, "\"extSem_out\":{\"type\":\"hipExternalSemaphore_t *\",\"value\":{\"addr\":\"%p\"", args->hipImportExternalSemaphore.extSem_out); \
	if (args->hipImportExternalSemaphore.extSem_out != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipImportExternalSemaphore.extSem_out); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"semHandleDesc\":{\"type\":\"struct const hipExternalSemaphoreHandleDesc *\",\"value\":{\"addr\":\"%p\"", args->hipImportExternalSemaphore.semHandleDesc); \
	if (args->hipImportExternalSemaphore.semHandleDesc != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipExternalSemaphoreHandleType\",\"value\":\"%d\"},", (*args->hipImportExternalSemaphore.semHandleDesc).type); \
		ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"union (unnamed union at ./input/hip_runtime_api.h:1123:3)\",\"value\":\"NULL\"}"); \
		ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipImportExternalSemaphore.semHandleDesc).flags); \
		ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned int[16]\",\"value\":{\"addr\":\"%p\"", (*args->hipImportExternalSemaphore.semHandleDesc).reserved); \
		if ((*args->hipImportExternalSemaphore.semHandleDesc).reserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*args->hipImportExternalSemaphore.semHandleDesc).reserved); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipStream_t stream (unknown);
//	hipEvent_t event (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamWaitEvent(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipStreamWaitEvent.flags); \
};

//	int * count (int*);
#define PROCESS_ARGS_hipGetDeviceCount(args) { \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipGetDeviceCount.count); \
	if (args->hipGetDeviceCount.count != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipGetDeviceCount.count); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphNode_t hSrc (unknown);
//	hipGraphNode_t hDst (unknown);
#define PROCESS_ARGS_hipGraphKernelNodeCopyAttributes(args) { \
	ratelprof_add_to_buffer(buf, "\"hSrc\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"hDst\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
};

//	hipExternalSemaphore_t extSem (void*);
#define PROCESS_ARGS_hipDestroyExternalSemaphore(args) { \
	ratelprof_add_to_buffer(buf, "\"extSem\":{\"type\":\"hipExternalSemaphore_t\",\"value\":{\"addr\":\"%p\"", args->hipDestroyExternalSemaphore.extSem); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphNode_t node (unknown);
//	const hipMemcpy3DParms* pNodeParams (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"const hipMemcpy3DParms*\",\"value\":\"NULL\"}"); \
};

//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipStreamQuery(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t node (unknown);
//	struct const hipMemsetParams * pNodeParams ({
//		void * dst (void*);
//		unsigned int elementSize (unsigned int);
//		int height (int);
//		int pitch (int);
//		unsigned int value (unsigned int);
//		int width (int);
//	});
#define PROCESS_ARGS_hipGraphMemsetNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"struct const hipMemsetParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphMemsetNodeSetParams.pNodeParams); \
	if (args->hipGraphMemsetNodeSetParams.pNodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphMemsetNodeSetParams.pNodeParams).dst); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"elementSize\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipGraphMemsetNodeSetParams.pNodeParams).elementSize); \
		ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGraphMemsetNodeSetParams.pNodeParams).height); \
		ratelprof_add_to_buffer(buf, "\"pitch\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGraphMemsetNodeSetParams.pNodeParams).pitch); \
		ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipGraphMemsetNodeSetParams.pNodeParams).value); \
		ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"int\",\"value\":\"%d\"}", (*args->hipGraphMemsetNodeSetParams.pNodeParams).width); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int * runtimeVersion (int*);
#define PROCESS_ARGS_hipRuntimeGetVersion(args) { \
	ratelprof_add_to_buffer(buf, "\"runtimeVersion\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipRuntimeGetVersion.runtimeVersion); \
	if (args->hipRuntimeGetVersion.runtimeVersion != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipRuntimeGetVersion.runtimeVersion); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	HIP_ARRAY_DESCRIPTOR* pArrayDescriptor (unknown);
//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipArrayGetDescriptor(args) { \
	ratelprof_add_to_buffer(buf, "\"pArrayDescriptor\":{\"type\":\"HIP_ARRAY_DESCRIPTOR*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t\",\"value\":\"NULL\"}"); \
};

//	hipDeviceptr_t dst (unknown);
//	int value (int);
//	size_t count (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemsetD32Async(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemsetD32Async.value); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemsetD32Async.count); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipSharedMemConfig * pConfig (enum*);
#define PROCESS_ARGS_hipCtxGetSharedMemConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"pConfig\":{\"type\":\"hipSharedMemConfig *\",\"value\":{\"addr\":\"%p\"", args->hipCtxGetSharedMemConfig.pConfig); \
	if (args->hipCtxGetSharedMemConfig.pConfig != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipCtxGetSharedMemConfig.pConfig); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipModule_t * module (unknown);
//	const void * image (void*);
//	unsigned int numOptions (unsigned int);
//	hipJitOption * options (enum*);
//	void ** optionValues (void**);
#define PROCESS_ARGS_hipModuleLoadDataEx(args) { \
	ratelprof_add_to_buffer(buf, "\"module\":{\"type\":\"hipModule_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"image\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipModuleLoadDataEx.image); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"numOptions\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLoadDataEx.numOptions); \
	ratelprof_add_to_buffer(buf, "\"options\":{\"type\":\"hipJitOption *\",\"value\":{\"addr\":\"%p\"", args->hipModuleLoadDataEx.options); \
	if (args->hipModuleLoadDataEx.options != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipModuleLoadDataEx.options); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"optionValues\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipModuleLoadDataEx.optionValues); \
	if (args->hipModuleLoadDataEx.optionValues != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipModuleLoadDataEx.optionValues); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	void * shared_handle (void*);
//	hipMemPool_t mem_pool (unknown);
//	hipMemAllocationHandleType handle_type (enum);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMemPoolExportToShareableHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"shared_handle\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemPoolExportToShareableHandle.shared_handle); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"handle_type\":{\"type\":\"hipMemAllocationHandleType\",\"value\":\"%d\"},", args->hipMemPoolExportToShareableHandle.handle_type); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMemPoolExportToShareableHandle.flags); \
};

//	void ** dev_ptr (void**);
//	size_t size (unsigned long);
//	hipMemPool_t mem_pool (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMallocFromPoolAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipMallocFromPoolAsync.dev_ptr); \
	if (args->hipMallocFromPoolAsync.dev_ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipMallocFromPoolAsync.dev_ptr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMallocFromPoolAsync.size); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	int deviceId (int);
#define PROCESS_ARGS_hipSetDevice(args) { \
	ratelprof_add_to_buffer(buf, "\"deviceId\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipSetDevice.deviceId); \
};

//	void ** dev_ptr (void**);
//	size_t size (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMallocAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipMallocAsync.dev_ptr); \
	if (args->hipMallocAsync.dev_ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipMallocAsync.dev_ptr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMallocAsync.size); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipDevice_t * device (int*);
//	int ordinal (int);
#define PROCESS_ARGS_hipDeviceGet(args) { \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceGet.device); \
	if (args->hipDeviceGet.device != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipDeviceGet.device); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"ordinal\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceGet.ordinal); \
};

//	void * dst (void*);
//	int value (int);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemsetAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemsetAsync.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemsetAsync.value); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemsetAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	void * ptr (void*);
//	size_t size (unsigned long);
//	struct const hipMemAccessDesc * desc ({
//		hipMemLocation location ({
//			hipMemLocationType type (enum);
//			int id (int);
//		});
//		hipMemAccessFlags flags (enum);
//	});
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemSetAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemSetAccess.ptr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemSetAccess.size); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"struct const hipMemAccessDesc *\",\"value\":{\"addr\":\"%p\"", args->hipMemSetAccess.desc); \
	if (args->hipMemSetAccess.desc != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"location\":{\"type\":\"struct hipMemLocation\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipMemLocationType\",\"value\":\"%d\"},", ((*args->hipMemSetAccess.desc).location).type); \
		ratelprof_add_to_buffer(buf, "\"id\":{\"type\":\"int\",\"value\":\"%d\"}", ((*args->hipMemSetAccess.desc).location).id); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"hipMemAccessFlags\",\"value\":\"%d\"}", (*args->hipMemSetAccess.desc).flags); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemSetAccess.count); \
};

//	hipDeviceptr_t dest (unknown);
//	int value (int);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemsetD32(args) { \
	ratelprof_add_to_buffer(buf, "\"dest\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemsetD32.value); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemsetD32.count); \
};

//	unsigned int * flags (unsigned int*);
#define PROCESS_ARGS_hipGetDeviceFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int *\",\"value\":{\"addr\":\"%p\"", args->hipGetDeviceFlags.flags); \
	if (args->hipGetDeviceFlags.flags != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *args->hipGetDeviceFlags.flags); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int * numBlocks (int*);
//	const void * f (void*);
//	int blockSize (int);
//	size_t dynSharedMemPerBlk (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"numBlocks\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks); \
	if (args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.f); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"blockSize\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.blockSize); \
	ratelprof_add_to_buffer(buf, "\"dynSharedMemPerBlk\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.dynSharedMemPerBlk); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.flags); \
};

//	struct hipUUID * uuid ({
//		char[16] bytes (char*);
//	});
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceGetUuid(args) { \
	ratelprof_add_to_buffer(buf, "\"uuid\":{\"type\":\"struct hipUUID *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceGetUuid.uuid); \
	if (args->hipDeviceGetUuid.uuid != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"bytes\":{\"type\":\"char[16]\",\"value\":{\"addr\":\"%p\"", (*args->hipDeviceGetUuid.uuid).bytes); \
		if ((*args->hipDeviceGetUuid.uuid).bytes != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *(*args->hipDeviceGetUuid.uuid).bytes); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipDeviceGetUuid.device); \
};

//	void * dst (void*);
//	size_t dpitch (unsigned long);
//	const void * src (void*);
//	size_t spitch (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpy2D(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpy2D.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dpitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2D.dpitch); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpy2D.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"spitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2D.spitch); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2D.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2D.height); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	hipChannelFormatDesc * desc (unknown);
//	hipExtent * extent (unknown);
//	unsigned int * flags (unsigned int*);
//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipArrayGetInfo(args) { \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"hipChannelFormatDesc *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"extent\":{\"type\":\"hipExtent *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int *\",\"value\":{\"addr\":\"%p\"", args->hipArrayGetInfo.flags); \
	if (args->hipArrayGetInfo.flags != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *args->hipArrayGetInfo.flags); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_t\",\"value\":\"NULL\"}"); \
};

//	hipUserObject_t object (unknown);
//	unsigned int count (unsigned int);
#define PROCESS_ARGS_hipUserObjectRetain(args) { \
	ratelprof_add_to_buffer(buf, "\"object\":{\"type\":\"hipUserObject_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipUserObjectRetain.count); \
};

//	int count (int);
//	hipGraphicsResource_t * resources (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipGraphicsMapResources(args) { \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipGraphicsMapResources.count); \
	ratelprof_add_to_buffer(buf, "\"resources\":{\"type\":\"hipGraphicsResource_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipDeviceptr_t dst (unknown);
//	void * src (void*);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyHtoDAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyHtoDAsync.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyHtoDAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	HIP_TEXTURE_DESC * pTexDesc (unknown);
//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectGetTextureDesc(args) { \
	ratelprof_add_to_buffer(buf, "\"pTexDesc\":{\"type\":\"HIP_TEXTURE_DESC *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"texObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"NULL\"}"); \
};

//	unsigned long long * flags (unsigned long long*);
//	struct const hipMemLocation * location ({
//		hipMemLocationType type (enum);
//		int id (int);
//	});
//	void * ptr (void*);
#define PROCESS_ARGS_hipMemGetAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned long long *\",\"value\":{\"addr\":\"%p\"", args->hipMemGetAccess.flags); \
	if (args->hipMemGetAccess.flags != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%llu\"", *args->hipMemGetAccess.flags); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"location\":{\"type\":\"struct const hipMemLocation *\",\"value\":{\"addr\":\"%p\"", args->hipMemGetAccess.location); \
	if (args->hipMemGetAccess.location != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipMemLocationType\",\"value\":\"%d\"},", (*args->hipMemGetAccess.location).type); \
		ratelprof_add_to_buffer(buf, "\"id\":{\"type\":\"int\",\"value\":\"%d\"}", (*args->hipMemGetAccess.location).id); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemGetAccess.ptr); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipArray_t dst (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	const void * src (void*);
//	size_t spitch (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpy2DToArrayAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipArray_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"wOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArrayAsync.wOffset); \
	ratelprof_add_to_buffer(buf, "\"hOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArrayAsync.hOffset); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpy2DToArrayAsync.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"spitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArrayAsync.spitch); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArrayAsync.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArrayAsync.height); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipDeviceptr_t * dev_ptr (unknown);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetAddress(args) { \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"hipDeviceptr_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t node (unknown);
//	hipGraphNodeType * pType (enum*);
#define PROCESS_ARGS_hipGraphNodeGetType(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pType\":{\"type\":\"hipGraphNodeType *\",\"value\":{\"addr\":\"%p\"", args->hipGraphNodeGetType.pType); \
	if (args->hipGraphNodeGetType.pType != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipGraphNodeGetType.pType); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipStream_t stream (unknown);
//	unsigned int * flags (unsigned int*);
#define PROCESS_ARGS_hipStreamGetFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int *\",\"value\":{\"addr\":\"%p\"", args->hipStreamGetFlags.flags); \
	if (args->hipStreamGetFlags.flags != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *args->hipStreamGetFlags.flags); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int * numBlocks (int*);
//	hipFunction_t f (unknown);
//	int blockSize (int);
//	size_t dynSharedMemPerBlk (unsigned long);
#define PROCESS_ARGS_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor(args) { \
	ratelprof_add_to_buffer(buf, "\"numBlocks\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks); \
	if (args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"hipFunction_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"blockSize\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.blockSize); \
	ratelprof_add_to_buffer(buf, "\"dynSharedMemPerBlk\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.dynSharedMemPerBlk); \
};

//	void * dst (void*);
//	size_t pitch (unsigned long);
//	int value (int);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemset2DAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemset2DAsync.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemset2DAsync.pitch); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemset2DAsync.value); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemset2DAsync.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemset2DAsync.height); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	void * dst (void*);
//	const void * symbol (void*);
//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpyFromSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyFromSymbol.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyFromSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyFromSymbol.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyFromSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	void * ptr (void*);
#define PROCESS_ARGS_hipHostFree(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipHostFree.ptr); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	const void * function_address (void*);
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
//	void ** args (void**);
//	size_t sharedMemBytes (unsigned long);
//	hipStream_t stream (unknown);
//	hipEvent_t startEvent (unknown);
//	hipEvent_t stopEvent (unknown);
//	int flags (int);
#define PROCESS_ARGS_hipExtLaunchKernel(args) { \
	ratelprof_add_to_buffer(buf, "\"function_address\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipExtLaunchKernel.function_address); \
	ratelprof_add_to_buffer(buf, "}},"); \
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
	ratelprof_add_to_buffer(buf, "\"args\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipExtLaunchKernel.args); \
	if (args->hipExtLaunchKernel.args != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipExtLaunchKernel.args); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sharedMemBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipExtLaunchKernel.sharedMemBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"startEvent\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stopEvent\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipExtLaunchKernel.flags); \
};

//	void * dst (void*);
//	const void * symbol (void*);
//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyFromSymbolAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyFromSymbolAsync.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyFromSymbolAsync.symbol); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyFromSymbolAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyFromSymbolAsync.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipCtx_t * ctx (unknown);
//	unsigned int flags (unsigned int);
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipCtxCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipCtxCreate.flags); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipCtxCreate.device); \
};

//	const void * f (void*);
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
//	void ** kernelParams (void**);
//	unsigned int sharedMemBytes (unsigned int);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipLaunchCooperativeKernel(args) { \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipLaunchCooperativeKernel.f); \
	ratelprof_add_to_buffer(buf, "}},"); \
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
	ratelprof_add_to_buffer(buf, "\"kernelParams\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipLaunchCooperativeKernel.kernelParams); \
	if (args->hipLaunchCooperativeKernel.kernelParams != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipLaunchCooperativeKernel.kernelParams); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sharedMemBytes\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipLaunchCooperativeKernel.sharedMemBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipStream_t stream (unknown);
//	uint32_t cuMaskSize (unsigned int);
//	uint32_t * cuMask (unsigned int*);
#define PROCESS_ARGS_hipExtStreamGetCUMask(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"cuMaskSize\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", args->hipExtStreamGetCUMask.cuMaskSize); \
	ratelprof_add_to_buffer(buf, "\"cuMask\":{\"type\":\"uint32_t *\",\"value\":{\"addr\":\"%p\"", args->hipExtStreamGetCUMask.cuMask); \
	if (args->hipExtStreamGetCUMask.cuMask != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *args->hipExtStreamGetCUMask.cuMask); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphExec_t graphExec (unknown);
#define PROCESS_ARGS_hipGraphExecDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"graphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
};

//	hipError_t hipError (enum);
//	const char ** errorString (char**);
#define PROCESS_ARGS_hipDrvGetErrorString(args) { \
	ratelprof_add_to_buffer(buf, "\"hipError\":{\"type\":\"hipError_t\",\"value\":\"%d\"},", args->hipDrvGetErrorString.hipError); \
	ratelprof_add_to_buffer(buf, "\"errorString\":{\"type\":\"const char **\",\"value\":{\"addr\":\"%p\"", args->hipDrvGetErrorString.errorString); \
	if (args->hipDrvGetErrorString.errorString != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipDrvGetErrorString.errorString); \
		if (*args->hipDrvGetErrorString.errorString != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->**\":\"%c\"", **args->hipDrvGetErrorString.errorString); \
		} \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipInit(args) { \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipInit.flags); \
};

//	size_t * offset (unsigned long*);
//	const textureReference * tex (unknown);
//	const void * devPtr (void*);
//	const hipChannelFormatDesc * desc (unknown);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	size_t pitch (unsigned long);
#define PROCESS_ARGS_hipBindTexture2D(args) { \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipBindTexture2D.offset); \
	if (args->hipBindTexture2D.offset != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipBindTexture2D.offset); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"tex\":{\"type\":\"const textureReference *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipBindTexture2D.devPtr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const hipChannelFormatDesc *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipBindTexture2D.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipBindTexture2D.height); \
	ratelprof_add_to_buffer(buf, "\"pitch\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipBindTexture2D.pitch); \
};

//	int device1 (int);
//	int device2 (int);
//	uint32_t * linktype (unsigned int*);
//	uint32_t * hopcount (unsigned int*);
#define PROCESS_ARGS_hipExtGetLinkTypeAndHopCount(args) { \
	ratelprof_add_to_buffer(buf, "\"device1\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipExtGetLinkTypeAndHopCount.device1); \
	ratelprof_add_to_buffer(buf, "\"device2\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipExtGetLinkTypeAndHopCount.device2); \
	ratelprof_add_to_buffer(buf, "\"linktype\":{\"type\":\"uint32_t *\",\"value\":{\"addr\":\"%p\"", args->hipExtGetLinkTypeAndHopCount.linktype); \
	if (args->hipExtGetLinkTypeAndHopCount.linktype != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *args->hipExtGetLinkTypeAndHopCount.linktype); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"hopcount\":{\"type\":\"uint32_t *\",\"value\":{\"addr\":\"%p\"", args->hipExtGetLinkTypeAndHopCount.hopcount); \
	if (args->hipExtGetLinkTypeAndHopCount.hopcount != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *args->hipExtGetLinkTypeAndHopCount.hopcount); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	struct hipResourceViewDesc * pResViewDesc (unknown);
//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipGetTextureObjectResourceViewDesc(args) { \
	ratelprof_add_to_buffer(buf, "\"pResViewDesc\":{\"type\":\"struct hipResourceViewDesc *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"textureObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"NULL\"}"); \
};

//	hipMemGenericAllocationHandle_t * handle (unknown);
//	size_t size (unsigned long);
//	struct const hipMemAllocationProp * prop ({
//		hipMemAllocationType type (enum);
//		hipMemAllocationHandleType requestedHandleType (enum);
//		hipMemLocation location ({
//			hipMemLocationType type (enum);
//			int id (int);
//		});
//		void * win32HandleMetaData (void*);
//		struct (unnamed struct at ./input/hip_runtime_api.h:1393:5) allocFlags (unknown);
//	});
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipMemCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipMemGenericAllocationHandle_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemCreate.size); \
	ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"struct const hipMemAllocationProp *\",\"value\":{\"addr\":\"%p\"", args->hipMemCreate.prop); \
	if (args->hipMemCreate.prop != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipMemAllocationType\",\"value\":\"%d\"},", (*args->hipMemCreate.prop).type); \
		ratelprof_add_to_buffer(buf, "\"requestedHandleType\":{\"type\":\"hipMemAllocationHandleType\",\"value\":\"%d\"},", (*args->hipMemCreate.prop).requestedHandleType); \
		ratelprof_add_to_buffer(buf, "\"location\":{\"type\":\"struct hipMemLocation\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipMemLocationType\",\"value\":\"%d\"},", ((*args->hipMemCreate.prop).location).type); \
		ratelprof_add_to_buffer(buf, "\"id\":{\"type\":\"int\",\"value\":\"%d\"}", ((*args->hipMemCreate.prop).location).id); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"win32HandleMetaData\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipMemCreate.prop).win32HandleMetaData); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"allocFlags\":{\"type\":\"struct (unnamed struct at ./input/hip_runtime_api.h:1393:5)\",\"value\":\"NULL\"}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned long long\",\"value\":\"%llu\"}", args->hipMemCreate.flags); \
};

//	hipDeviceptr_t dest (unknown);
//	unsigned char value (unsigned char);
//	size_t count (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemsetD8Async(args) { \
	ratelprof_add_to_buffer(buf, "\"dest\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"unsigned char\",\"value\":\"%hhu\"},", args->hipMemsetD8Async.value); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemsetD8Async.count); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipStream_t stream (unknown);
//	hipHostFn_t fn (void*);
//	void * userData (void*);
#define PROCESS_ARGS_hipLaunchHostFunc(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"fn\":{\"type\":\"hipHostFn_t\",\"value\":{\"addr\":\"%p\"", args->hipLaunchHostFunc.fn); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"userData\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipLaunchHostFunc.userData); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraph_t graph (unknown);
//	hipGraphNode_t * from (unknown);
//	hipGraphNode_t * to (unknown);
//	size_t * numEdges (unsigned long*);
#define PROCESS_ARGS_hipGraphGetEdges(args) { \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"from\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"to\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numEdges\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipGraphGetEdges.numEdges); \
	if (args->hipGraphGetEdges.numEdges != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipGraphGetEdges.numEdges); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipMemPool_t mem_pool (unknown);
#define PROCESS_ARGS_hipMemPoolDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t node (unknown);
//	struct hipKernelNodeParams * pNodeParams ({
//		dim3 blockDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		void ** extra (void**);
//		void * func (void*);
//		dim3 gridDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		void ** kernelParams (void**);
//		unsigned int sharedMemBytes (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphKernelNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"struct hipKernelNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphKernelNodeGetParams.pNodeParams); \
	if (args->hipGraphKernelNodeGetParams.pNodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"blockDim\":{\"type\":\"struct dim3\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphKernelNodeGetParams.pNodeParams).blockDim).x); \
		ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphKernelNodeGetParams.pNodeParams).blockDim).y); \
		ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", ((*args->hipGraphKernelNodeGetParams.pNodeParams).blockDim).z); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"extra\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphKernelNodeGetParams.pNodeParams).extra); \
		if ((*args->hipGraphKernelNodeGetParams.pNodeParams).extra != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphKernelNodeGetParams.pNodeParams).extra); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphKernelNodeGetParams.pNodeParams).func); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"gridDim\":{\"type\":\"struct dim3\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphKernelNodeGetParams.pNodeParams).gridDim).x); \
		ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphKernelNodeGetParams.pNodeParams).gridDim).y); \
		ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", ((*args->hipGraphKernelNodeGetParams.pNodeParams).gridDim).z); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"kernelParams\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphKernelNodeGetParams.pNodeParams).kernelParams); \
		if ((*args->hipGraphKernelNodeGetParams.pNodeParams).kernelParams != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphKernelNodeGetParams.pNodeParams).kernelParams); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"sharedMemBytes\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", (*args->hipGraphKernelNodeGetParams.pNodeParams).sharedMemBytes); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	unsigned int numAttributes (unsigned int);
//	hipPointer_attribute * attributes (unknown);
//	void ** data (void**);
//	hipDeviceptr_t ptr (unknown);
#define PROCESS_ARGS_hipDrvPointerGetAttributes(args) { \
	ratelprof_add_to_buffer(buf, "\"numAttributes\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipDrvPointerGetAttributes.numAttributes); \
	ratelprof_add_to_buffer(buf, "\"attributes\":{\"type\":\"hipPointer_attribute *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipDrvPointerGetAttributes.data); \
	if (args->hipDrvPointerGetAttributes.data != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipDrvPointerGetAttributes.data); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
};

//	const void * func (void*);
//	hipFuncAttribute attr (enum);
//	int value (int);
#define PROCESS_ARGS_hipFuncSetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipFuncSetAttribute.func); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipFuncAttribute\",\"value\":\"%d\"},", args->hipFuncSetAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipFuncSetAttribute.value); \
};

//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * from (unknown);
//	const hipGraphNode_t * to (unknown);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphAddDependencies(args) { \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"from\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"to\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipGraphAddDependencies.numDependencies); \
};

//	hipStream_t stream (unknown);
//	void * ptr (void*);
//	uint64_t value (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamWriteValue64(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipStreamWriteValue64.ptr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hipStreamWriteValue64.value); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipStreamWriteValue64.flags); \
};

//	hipSurfaceObject_t* pSurfObject (unknown);
//	const hipResourceDesc* pResDesc (unknown);
#define PROCESS_ARGS_hipCreateSurfaceObject(args) { \
	ratelprof_add_to_buffer(buf, "\"pSurfObject\":{\"type\":\"hipSurfaceObject_t*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pResDesc\":{\"type\":\"const hipResourceDesc*\",\"value\":\"NULL\"}"); \
};

//	hipTextureDesc* pTexDesc (unknown);
//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipGetTextureObjectTextureDesc(args) { \
	ratelprof_add_to_buffer(buf, "\"pTexDesc\":{\"type\":\"hipTextureDesc*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"textureObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"NULL\"}"); \
};

//	void * ptr (void*);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMemUnmap(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemUnmap.ptr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemUnmap.size); \
};

//	hipGraphNode_t node (unknown);
//	hipGraph_t * pGraph (unknown);
#define PROCESS_ARGS_hipGraphChildGraphNodeGetGraph(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pGraph\":{\"type\":\"hipGraph_t *\",\"value\":\"NULL\"}"); \
};

//	hipStream_t * stream (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamCreateWithFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipStreamCreateWithFlags.flags); \
};

//	hipMemPool_t * mem_pool (unknown);
//	struct const hipMemPoolProps * pool_props ({
//		hipMemAllocationType allocType (enum);
//		hipMemAllocationHandleType handleTypes (enum);
//		hipMemLocation location ({
//			hipMemLocationType type (enum);
//			int id (int);
//		});
//		void * win32SecurityAttributes (void*);
//		unsigned char[64] reserved (unsigned char*);
//	});
#define PROCESS_ARGS_hipMemPoolCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pool_props\":{\"type\":\"struct const hipMemPoolProps *\",\"value\":{\"addr\":\"%p\"", args->hipMemPoolCreate.pool_props); \
	if (args->hipMemPoolCreate.pool_props != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"allocType\":{\"type\":\"hipMemAllocationType\",\"value\":\"%d\"},", (*args->hipMemPoolCreate.pool_props).allocType); \
		ratelprof_add_to_buffer(buf, "\"handleTypes\":{\"type\":\"hipMemAllocationHandleType\",\"value\":\"%d\"},", (*args->hipMemPoolCreate.pool_props).handleTypes); \
		ratelprof_add_to_buffer(buf, "\"location\":{\"type\":\"struct hipMemLocation\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipMemLocationType\",\"value\":\"%d\"},", ((*args->hipMemPoolCreate.pool_props).location).type); \
		ratelprof_add_to_buffer(buf, "\"id\":{\"type\":\"int\",\"value\":\"%d\"}", ((*args->hipMemPoolCreate.pool_props).location).id); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"win32SecurityAttributes\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipMemPoolCreate.pool_props).win32SecurityAttributes); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned char[64]\",\"value\":{\"addr\":\"%p\"", (*args->hipMemPoolCreate.pool_props).reserved); \
		if ((*args->hipMemPoolCreate.pool_props).reserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%hhu\"", *(*args->hipMemPoolCreate.pool_props).reserved); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	struct hipLaunchParams * launchParamsList ({
//		void * func (void*);
//		dim3 gridDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		dim3 blockDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		void ** args (void**);
//		int sharedMem (int);
//		hipStream_t stream (unknown);
//	});
//	int numDevices (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipLaunchCooperativeKernelMultiDevice(args) { \
	ratelprof_add_to_buffer(buf, "\"launchParamsList\":{\"type\":\"struct hipLaunchParams *\",\"value\":{\"addr\":\"%p\"", args->hipLaunchCooperativeKernelMultiDevice.launchParamsList); \
	if (args->hipLaunchCooperativeKernelMultiDevice.launchParamsList != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).func); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"gridDim\":{\"type\":\"struct dim3\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).gridDim).x); \
		ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).gridDim).y); \
		ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", ((*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).gridDim).z); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"blockDim\":{\"type\":\"struct dim3\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).blockDim).x); \
		ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).blockDim).y); \
		ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", ((*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).blockDim).z); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"args\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", (*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).args); \
		if ((*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).args != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).args); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"sharedMem\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).sharedMem); \
		ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"numDevices\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipLaunchCooperativeKernelMultiDevice.numDevices); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipLaunchCooperativeKernelMultiDevice.flags); \
};

//	textureReference* texRef (unknown);
//	enum hipTextureFilterMode fm (enum);
#define PROCESS_ARGS_hipTexRefSetFilterMode(args) { \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"fm\":{\"type\":\"enum hipTextureFilterMode\",\"value\":\"%d\"}", args->hipTexRefSetFilterMode.fm); \
};

//	int device (int);
//	hipGraphMemAttributeType attr (enum);
//	void * value (void*);
#define PROCESS_ARGS_hipDeviceSetGraphMemAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceSetGraphMemAttribute.device); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipGraphMemAttributeType\",\"value\":\"%d\"},", args->hipDeviceSetGraphMemAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceSetGraphMemAttribute.value); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t node (unknown);
//	void * dst (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParams1D(args) { \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExecMemcpyNodeSetParams1D.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExecMemcpyNodeSetParams1D.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphExecMemcpyNodeSetParams1D.count); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t node (unknown);
//	struct const hipKernelNodeParams * pNodeParams ({
//		dim3 blockDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		void ** extra (void**);
//		void * func (void*);
//		dim3 gridDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		void ** kernelParams (void**);
//		unsigned int sharedMemBytes (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphExecKernelNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"struct const hipKernelNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExecKernelNodeSetParams.pNodeParams); \
	if (args->hipGraphExecKernelNodeSetParams.pNodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"blockDim\":{\"type\":\"struct dim3\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).blockDim).x); \
		ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).blockDim).y); \
		ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).blockDim).z); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"extra\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExecKernelNodeSetParams.pNodeParams).extra); \
		if ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).extra != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphExecKernelNodeSetParams.pNodeParams).extra); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExecKernelNodeSetParams.pNodeParams).func); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"gridDim\":{\"type\":\"struct dim3\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).gridDim).x); \
		ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).gridDim).y); \
		ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).gridDim).z); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"kernelParams\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExecKernelNodeSetParams.pNodeParams).kernelParams); \
		if ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).kernelParams != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphExecKernelNodeSetParams.pNodeParams).kernelParams); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"sharedMemBytes\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", (*args->hipGraphExecKernelNodeSetParams.pNodeParams).sharedMemBytes); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphExec_t * pGraphExec (unknown);
//	hipGraph_t graph (unknown);
//	hipGraphNode_t * pErrorNode (unknown);
//	char * pLogBuffer (char*);
//	size_t bufferSize (unsigned long);
#define PROCESS_ARGS_hipGraphInstantiate(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphExec\":{\"type\":\"hipGraphExec_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pErrorNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pLogBuffer\":{\"type\":\"char *\",\"value\":{\"addr\":\"%p\"", args->hipGraphInstantiate.pLogBuffer); \
	if (args->hipGraphInstantiate.pLogBuffer != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *args->hipGraphInstantiate.pLogBuffer); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"bufferSize\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipGraphInstantiate.bufferSize); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t hNode (unknown);
//	struct const hipExternalSemaphoreSignalNodeParams * nodeParams ({
//		hipExternalSemaphore_t * extSemArray (void**);
//		struct const hipExternalSemaphoreSignalParams * paramsArray ({
//			struct (unnamed struct at ./input/hip_runtime_api.h:1136:3) params (unknown);
//			unsigned int flags (unsigned int);
//			unsigned int[16] reserved (unsigned int*);
//		});
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphExecExternalSemaphoresSignalNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"nodeParams\":{\"type\":\"struct const hipExternalSemaphoreSignalNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams); \
	if (args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"extSemArray\":{\"type\":\"hipExternalSemaphore_t *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).extSemArray); \
		if ((*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).extSemArray != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).extSemArray); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"paramsArray\":{\"type\":\"struct const hipExternalSemaphoreSignalParams *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray); \
		if ((*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray != NULL) { \
			ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
			ratelprof_add_to_buffer(buf, "\"params\":{\"type\":\"struct (unnamed struct at ./input/hip_runtime_api.h:1136:3)\",\"value\":\"NULL\"}"); \
			ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*(*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).flags); \
			ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned int[16]\",\"value\":{\"addr\":\"%p\"", (*(*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).reserved); \
			if ((*(*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).reserved != NULL) { \
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*(*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).reserved); \
			} \
			ratelprof_add_to_buffer(buf, "}}"); \
			ratelprof_add_to_buffer(buf, "}"); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"numExtSems\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", (*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).numExtSems); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipTextureObject_t* pTexObject (unknown);
//	const hipResourceDesc* pResDesc (unknown);
//	const hipTextureDesc* pTexDesc (unknown);
//	const struct hipResourceViewDesc * pResViewDesc (unknown);
#define PROCESS_ARGS_hipCreateTextureObject(args) { \
	ratelprof_add_to_buffer(buf, "\"pTexObject\":{\"type\":\"hipTextureObject_t*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pResDesc\":{\"type\":\"const hipResourceDesc*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pTexDesc\":{\"type\":\"const hipTextureDesc*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pResViewDesc\":{\"type\":\"const struct hipResourceViewDesc *\",\"value\":\"NULL\"}"); \
};

//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipEventQuery(args) { \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
};

//	hipCtx_t ctx (unknown);
#define PROCESS_ARGS_hipCtxPushCurrent(args) { \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t\",\"value\":\"NULL\"}"); \
};

//	hipGraph_t graph (unknown);
//	hipGraphNode_t * pRootNodes (unknown);
//	size_t * pNumRootNodes (unsigned long*);
#define PROCESS_ARGS_hipGraphGetRootNodes(args) { \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pRootNodes\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNumRootNodes\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipGraphGetRootNodes.pNumRootNodes); \
	if (args->hipGraphGetRootNodes.pNumRootNodes != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipGraphGetRootNodes.pNumRootNodes); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipError_t hipError (enum);
#define PROCESS_ARGS_hipGetErrorString(args) { \
	ratelprof_add_to_buffer(buf, "\"hipError\":{\"type\":\"hipError_t\",\"value\":\"%d\"}", args->hipGetErrorString.hipError); \
};

//	void * devPtr (void*);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMemAddressFree(args) { \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemAddressFree.devPtr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemAddressFree.size); \
};


#define PROCESS_ARGS_hipDeviceSynchronize(args) { \
\
};

//	unsigned int * flags (unsigned int*);
#define PROCESS_ARGS_hipCtxGetFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int *\",\"value\":{\"addr\":\"%p\"", args->hipCtxGetFlags.flags); \
	if (args->hipCtxGetFlags.flags != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *args->hipCtxGetFlags.flags); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipArray_t* pArray (unknown);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetArray(args) { \
	ratelprof_add_to_buffer(buf, "\"pArray\":{\"type\":\"hipArray_t*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"NULL\"}"); \
};

//	size_t * granularity (unsigned long*);
//	struct const hipMemAllocationProp * prop ({
//		hipMemAllocationType type (enum);
//		hipMemAllocationHandleType requestedHandleType (enum);
//		hipMemLocation location ({
//			hipMemLocationType type (enum);
//			int id (int);
//		});
//		void * win32HandleMetaData (void*);
//		struct (unnamed struct at ./input/hip_runtime_api.h:1393:5) allocFlags (unknown);
//	});
//	hipMemAllocationGranularity_flags option (enum);
#define PROCESS_ARGS_hipMemGetAllocationGranularity(args) { \
	ratelprof_add_to_buffer(buf, "\"granularity\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipMemGetAllocationGranularity.granularity); \
	if (args->hipMemGetAllocationGranularity.granularity != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipMemGetAllocationGranularity.granularity); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"struct const hipMemAllocationProp *\",\"value\":{\"addr\":\"%p\"", args->hipMemGetAllocationGranularity.prop); \
	if (args->hipMemGetAllocationGranularity.prop != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipMemAllocationType\",\"value\":\"%d\"},", (*args->hipMemGetAllocationGranularity.prop).type); \
		ratelprof_add_to_buffer(buf, "\"requestedHandleType\":{\"type\":\"hipMemAllocationHandleType\",\"value\":\"%d\"},", (*args->hipMemGetAllocationGranularity.prop).requestedHandleType); \
		ratelprof_add_to_buffer(buf, "\"location\":{\"type\":\"struct hipMemLocation\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipMemLocationType\",\"value\":\"%d\"},", ((*args->hipMemGetAllocationGranularity.prop).location).type); \
		ratelprof_add_to_buffer(buf, "\"id\":{\"type\":\"int\",\"value\":\"%d\"}", ((*args->hipMemGetAllocationGranularity.prop).location).id); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"win32HandleMetaData\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipMemGetAllocationGranularity.prop).win32HandleMetaData); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"allocFlags\":{\"type\":\"struct (unnamed struct at ./input/hip_runtime_api.h:1393:5)\",\"value\":\"NULL\"}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"option\":{\"type\":\"hipMemAllocationGranularity_flags\",\"value\":\"%d\"}", args->hipMemGetAllocationGranularity.option); \
};


#define PROCESS_ARGS_hipProfilerStop(args) { \
\
};

//	textureReference* tex (unknown);
//	hipArray_const_t array (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipTexRefSetArray(args) { \
	ratelprof_add_to_buffer(buf, "\"tex\":{\"type\":\"textureReference*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_const_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipTexRefSetArray.flags); \
};

//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipEventDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
};

//	hipFuncCache_t cacheConfig (enum);
#define PROCESS_ARGS_hipDeviceSetCacheConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"cacheConfig\":{\"type\":\"hipFuncCache_t\",\"value\":\"%d\"}", args->hipDeviceSetCacheConfig.cacheConfig); \
};

//	const void * func (void*);
#define PROCESS_ARGS_hipLaunchByPtr(args) { \
	ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipLaunchByPtr.func); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	struct hipFunctionLaunchParams * launchParamsList ({
//		hipFunction_t function (unknown);
//		unsigned int gridDimX (unsigned int);
//		unsigned int gridDimY (unsigned int);
//		unsigned int gridDimZ (unsigned int);
//		unsigned int blockDimX (unsigned int);
//		unsigned int blockDimY (unsigned int);
//		unsigned int blockDimZ (unsigned int);
//		unsigned int sharedMemBytes (unsigned int);
//		hipStream_t hStream (unknown);
//		void ** kernelParams (void**);
//	});
//	unsigned int numDevices (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipModuleLaunchCooperativeKernelMultiDevice(args) { \
	ratelprof_add_to_buffer(buf, "\"launchParamsList\":{\"type\":\"struct hipFunctionLaunchParams *\",\"value\":{\"addr\":\"%p\"", args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList); \
	if (args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"function\":{\"type\":\"hipFunction_t\",\"value\":\"NULL\"}"); \
		ratelprof_add_to_buffer(buf, "\"gridDimX\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).gridDimX); \
		ratelprof_add_to_buffer(buf, "\"gridDimY\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).gridDimY); \
		ratelprof_add_to_buffer(buf, "\"gridDimZ\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).gridDimZ); \
		ratelprof_add_to_buffer(buf, "\"blockDimX\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).blockDimX); \
		ratelprof_add_to_buffer(buf, "\"blockDimY\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).blockDimY); \
		ratelprof_add_to_buffer(buf, "\"blockDimZ\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).blockDimZ); \
		ratelprof_add_to_buffer(buf, "\"sharedMemBytes\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).sharedMemBytes); \
		ratelprof_add_to_buffer(buf, "\"hStream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
		ratelprof_add_to_buffer(buf, "\"kernelParams\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).kernelParams); \
		if ((*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).kernelParams != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).kernelParams); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"numDevices\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchCooperativeKernelMultiDevice.numDevices); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipModuleLaunchCooperativeKernelMultiDevice.flags); \
};

//	textureReference* texRef (unknown);
//	int dim (int);
//	enum hipTextureAddressMode am (enum);
#define PROCESS_ARGS_hipTexRefSetAddressMode(args) { \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dim\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipTexRefSetAddressMode.dim); \
	ratelprof_add_to_buffer(buf, "\"am\":{\"type\":\"enum hipTextureAddressMode\",\"value\":\"%d\"}", args->hipTexRefSetAddressMode.am); \
};

//	hipModule_t * module (unknown);
//	const void * image (void*);
#define PROCESS_ARGS_hipModuleLoadData(args) { \
	ratelprof_add_to_buffer(buf, "\"module\":{\"type\":\"hipModule_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"image\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipModuleLoadData.image); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	const hip_Memcpy2D * pCopy (unknown);
#define PROCESS_ARGS_hipDrvMemcpy2DUnaligned(args) { \
	ratelprof_add_to_buffer(buf, "\"pCopy\":{\"type\":\"const hip_Memcpy2D *\",\"value\":\"NULL\"}"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t node (unknown);
//	hipGraph_t childGraph (unknown);
#define PROCESS_ARGS_hipGraphExecChildGraphNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"childGraph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
};

//	struct hipPointerAttribute_t * attributes ({
//		enum hipMemoryType type (enum);
//		int device (int);
//		void * devicePointer (void*);
//		void * hostPointer (void*);
//		int isManaged (int);
//		unsigned int allocationFlags (unsigned int);
//	});
//	const void * ptr (void*);
#define PROCESS_ARGS_hipPointerGetAttributes(args) { \
	ratelprof_add_to_buffer(buf, "\"attributes\":{\"type\":\"struct hipPointerAttribute_t *\",\"value\":{\"addr\":\"%p\"", args->hipPointerGetAttributes.attributes); \
	if (args->hipPointerGetAttributes.attributes != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"enum hipMemoryType\",\"value\":\"%d\"},", (*args->hipPointerGetAttributes.attributes).type); \
		ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipPointerGetAttributes.attributes).device); \
		ratelprof_add_to_buffer(buf, "\"devicePointer\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipPointerGetAttributes.attributes).devicePointer); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"hostPointer\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipPointerGetAttributes.attributes).hostPointer); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"isManaged\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipPointerGetAttributes.attributes).isManaged); \
		ratelprof_add_to_buffer(buf, "\"allocationFlags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", (*args->hipPointerGetAttributes.attributes).allocationFlags); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipPointerGetAttributes.ptr); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	void * dst (void*);
//	hipDeviceptr_t src (unknown);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyDtoHAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyDtoHAsync.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyDtoHAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipGraphAddEventRecordNode(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddEventRecordNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	struct const hipExternalSemaphoreSignalNodeParams * nodeParams ({
//		hipExternalSemaphore_t * extSemArray (void**);
//		struct const hipExternalSemaphoreSignalParams * paramsArray ({
//			struct (unnamed struct at ./input/hip_runtime_api.h:1136:3) params (unknown);
//			unsigned int flags (unsigned int);
//			unsigned int[16] reserved (unsigned int*);
//		});
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphAddExternalSemaphoresSignalNode(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddExternalSemaphoresSignalNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"nodeParams\":{\"type\":\"struct const hipExternalSemaphoreSignalNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphAddExternalSemaphoresSignalNode.nodeParams); \
	if (args->hipGraphAddExternalSemaphoresSignalNode.nodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"extSemArray\":{\"type\":\"hipExternalSemaphore_t *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).extSemArray); \
		if ((*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).extSemArray != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).extSemArray); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"paramsArray\":{\"type\":\"struct const hipExternalSemaphoreSignalParams *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).paramsArray); \
		if ((*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).paramsArray != NULL) { \
			ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
			ratelprof_add_to_buffer(buf, "\"params\":{\"type\":\"struct (unnamed struct at ./input/hip_runtime_api.h:1136:3)\",\"value\":\"NULL\"}"); \
			ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*(*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).paramsArray).flags); \
			ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned int[16]\",\"value\":{\"addr\":\"%p\"", (*(*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).paramsArray).reserved); \
			if ((*(*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).paramsArray).reserved != NULL) { \
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*(*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).paramsArray).reserved); \
			} \
			ratelprof_add_to_buffer(buf, "}}"); \
			ratelprof_add_to_buffer(buf, "}"); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"numExtSems\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", (*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).numExtSems); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraph_t graph (unknown);
//	hipUserObject_t object (unknown);
//	unsigned int count (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipGraphRetainUserObject(args) { \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"object\":{\"type\":\"hipUserObject_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipGraphRetainUserObject.count); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipGraphRetainUserObject.flags); \
};

//	const void * arg (void*);
//	size_t size (unsigned long);
//	size_t offset (unsigned long);
#define PROCESS_ARGS_hipSetupArgument(args) { \
	ratelprof_add_to_buffer(buf, "\"arg\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipSetupArgument.arg); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipSetupArgument.size); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipSetupArgument.offset); \
};

//	hipDeviceptr_t * dptr (unknown);
//	size_t* pitch (unsigned long*);
//	size_t widthInBytes (unsigned long);
//	size_t height (unsigned long);
//	unsigned int elementSizeBytes (unsigned int);
#define PROCESS_ARGS_hipMemAllocPitch(args) { \
	ratelprof_add_to_buffer(buf, "\"dptr\":{\"type\":\"hipDeviceptr_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pitch\":{\"type\":\"size_t*\",\"value\":{\"addr\":\"%p\"", args->hipMemAllocPitch.pitch); \
	if (args->hipMemAllocPitch.pitch != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipMemAllocPitch.pitch); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"widthInBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemAllocPitch.widthInBytes); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemAllocPitch.height); \
	ratelprof_add_to_buffer(buf, "\"elementSizeBytes\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMemAllocPitch.elementSizeBytes); \
};

//	hipGraphNode_t node (unknown);
//	hipEvent_t * event_out (unknown);
#define PROCESS_ARGS_hipGraphEventWaitNodeGetEvent(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"event_out\":{\"type\":\"hipEvent_t *\",\"value\":\"NULL\"}"); \
};

//	hipArray_t dst (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	const void * src (void*);
//	size_t spitch (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpy2DToArray(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipArray_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"wOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArray.wOffset); \
	ratelprof_add_to_buffer(buf, "\"hOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArray.hOffset); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpy2DToArray.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"spitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArray.spitch); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArray.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DToArray.height); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	void * dst (void*);
//	int dstDeviceId (int);
//	const void * src (void*);
//	int srcDevice (int);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyPeerAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyPeerAsync.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dstDeviceId\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemcpyPeerAsync.dstDeviceId); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyPeerAsync.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"srcDevice\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemcpyPeerAsync.srcDevice); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyPeerAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipTextureObject_t* pTexObject (unknown);
//	const HIP_RESOURCE_DESC* pResDesc (unknown);
//	const HIP_TEXTURE_DESC* pTexDesc (unknown);
//	const HIP_RESOURCE_VIEW_DESC* pResViewDesc (unknown);
#define PROCESS_ARGS_hipTexObjectCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"pTexObject\":{\"type\":\"hipTextureObject_t*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pResDesc\":{\"type\":\"const HIP_RESOURCE_DESC*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pTexDesc\":{\"type\":\"const HIP_TEXTURE_DESC*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pResViewDesc\":{\"type\":\"const HIP_RESOURCE_VIEW_DESC*\",\"value\":\"NULL\"}"); \
};

//	size_t * pValue (unsigned long*);
//	enum hipLimit_t limit (enum);
#define PROCESS_ARGS_hipDeviceGetLimit(args) { \
	ratelprof_add_to_buffer(buf, "\"pValue\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceGetLimit.pValue); \
	if (args->hipDeviceGetLimit.pValue != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipDeviceGetLimit.pValue); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"limit\":{\"type\":\"enum hipLimit_t\",\"value\":\"%d\"}", args->hipDeviceGetLimit.limit); \
};

//	void ** ptr (void**);
//	size_t sizeBytes (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipExtMallocWithFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipExtMallocWithFlags.ptr); \
	if (args->hipExtMallocWithFlags.ptr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipExtMallocWithFlags.ptr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipExtMallocWithFlags.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipExtMallocWithFlags.flags); \
};

//	hipError_t hip_error (enum);
#define PROCESS_ARGS_hipGetErrorName(args) { \
	ratelprof_add_to_buffer(buf, "\"hip_error\":{\"type\":\"hipError_t\",\"value\":\"%d\"}", args->hipGetErrorName.hip_error); \
};

//	const struct hipMemcpy3DParms * p (unknown);
#define PROCESS_ARGS_hipMemcpy3D(args) { \
	ratelprof_add_to_buffer(buf, "\"p\":{\"type\":\"const struct hipMemcpy3DParms *\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t node (unknown);
//	void * dst (void*);
//	const void * symbol (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParamsFromSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphMemcpyNodeSetParamsFromSymbol.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphMemcpyNodeSetParamsFromSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphMemcpyNodeSetParamsFromSymbol.count); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphMemcpyNodeSetParamsFromSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	void ** data (void**);
//	size_t * data_sizes (unsigned long*);
//	hipMemRangeAttribute * attributes (enum*);
//	size_t num_attributes (unsigned long);
//	const void * dev_ptr (void*);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemRangeGetAttributes(args) { \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipMemRangeGetAttributes.data); \
	if (args->hipMemRangeGetAttributes.data != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipMemRangeGetAttributes.data); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"data_sizes\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipMemRangeGetAttributes.data_sizes); \
	if (args->hipMemRangeGetAttributes.data_sizes != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipMemRangeGetAttributes.data_sizes); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attributes\":{\"type\":\"hipMemRangeAttribute *\",\"value\":{\"addr\":\"%p\"", args->hipMemRangeGetAttributes.attributes); \
	if (args->hipMemRangeGetAttributes.attributes != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipMemRangeGetAttributes.attributes); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"num_attributes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemRangeGetAttributes.num_attributes); \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemRangeGetAttributes.dev_ptr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemRangeGetAttributes.count); \
};

//	hipGraph_t graph (unknown);
//	const char * path (char*);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipGraphDebugDotPrint(args) { \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"path\":{\"type\":\"const char *\",\"value\":{\"addr\":\"%p\"", args->hipGraphDebugDotPrint.path); \
	if (args->hipGraphDebugDotPrint.path != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *args->hipGraphDebugDotPrint.path); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipGraphDebugDotPrint.flags); \
};

//	hipGraphNode_t hNode (unknown);
//	struct hipExternalSemaphoreWaitNodeParams * params_out ({
//		hipExternalSemaphore_t * extSemArray (void**);
//		struct const hipExternalSemaphoreWaitParams * paramsArray ({
//			struct (unnamed struct at ./input/hip_runtime_api.h:1156:3) params (unknown);
//			unsigned int flags (unsigned int);
//			unsigned int[16] reserved (unsigned int*);
//		});
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphExternalSemaphoresWaitNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"params_out\":{\"type\":\"struct hipExternalSemaphoreWaitNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out); \
	if (args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"extSemArray\":{\"type\":\"hipExternalSemaphore_t *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).extSemArray); \
		if ((*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).extSemArray != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).extSemArray); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"paramsArray\":{\"type\":\"struct const hipExternalSemaphoreWaitParams *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).paramsArray); \
		if ((*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).paramsArray != NULL) { \
			ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
			ratelprof_add_to_buffer(buf, "\"params\":{\"type\":\"struct (unnamed struct at ./input/hip_runtime_api.h:1156:3)\",\"value\":\"NULL\"}"); \
			ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*(*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).paramsArray).flags); \
			ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned int[16]\",\"value\":{\"addr\":\"%p\"", (*(*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).paramsArray).reserved); \
			if ((*(*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).paramsArray).reserved != NULL) { \
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*(*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).paramsArray).reserved); \
			} \
			ratelprof_add_to_buffer(buf, "}}"); \
			ratelprof_add_to_buffer(buf, "}"); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"numExtSems\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", (*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).numExtSems); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	void * dst (void*);
//	int value (int);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemset(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemset.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemset.value); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemset.sizeBytes); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	struct const hipHostNodeParams* pNodeParams ({
//		hipHostFn_t fn (void*);
//		void * userData (void*);
//	});
#define PROCESS_ARGS_hipGraphAddHostNode(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddHostNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"struct const hipHostNodeParams*\",\"value\":{\"addr\":\"%p\"", args->hipGraphAddHostNode.pNodeParams); \
	if (args->hipGraphAddHostNode.pNodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"fn\":{\"type\":\"hipHostFn_t\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphAddHostNode.pNodeParams).fn); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"userData\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphAddHostNode.pNodeParams).userData); \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	const hipMemcpy3DParms* pCopyParams (unknown);
#define PROCESS_ARGS_hipGraphAddMemcpyNode(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"pCopyParams\":{\"type\":\"const hipMemcpy3DParms*\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t node (unknown);
//	struct hipHostNodeParams * pNodeParams ({
//		hipHostFn_t fn (void*);
//		void * userData (void*);
//	});
#define PROCESS_ARGS_hipGraphHostNodeGetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"struct hipHostNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphHostNodeGetParams.pNodeParams); \
	if (args->hipGraphHostNodeGetParams.pNodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"fn\":{\"type\":\"hipHostFn_t\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphHostNodeGetParams.pNodeParams).fn); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"userData\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphHostNodeGetParams.pNodeParams).userData); \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	int * device (int*);
//	const char * pciBusId (char*);
#define PROCESS_ARGS_hipDeviceGetByPCIBusId(args) { \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceGetByPCIBusId.device); \
	if (args->hipDeviceGetByPCIBusId.device != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipDeviceGetByPCIBusId.device); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"pciBusId\":{\"type\":\"const char *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceGetByPCIBusId.pciBusId); \
	if (args->hipDeviceGetByPCIBusId.pciBusId != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *args->hipDeviceGetByPCIBusId.pciBusId); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipDeviceptr_t dst (unknown);
//	hipDeviceptr_t src (unknown);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemcpyDtoD(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemcpyDtoD.sizeBytes); \
};

//	struct hipIpcEventHandle_t * handle ({
//		char[64] reserved (char*);
//	});
//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipIpcGetEventHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"struct hipIpcEventHandle_t *\",\"value\":{\"addr\":\"%p\"", args->hipIpcGetEventHandle.handle); \
	if (args->hipIpcGetEventHandle.handle != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"char[64]\",\"value\":{\"addr\":\"%p\"", (*args->hipIpcGetEventHandle.handle).reserved); \
		if ((*args->hipIpcGetEventHandle.handle).reserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *(*args->hipIpcGetEventHandle.handle).reserved); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t node (unknown);
//	struct const hipKernelNodeParams * pNodeParams ({
//		dim3 blockDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		void ** extra (void**);
//		void * func (void*);
//		dim3 gridDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		void ** kernelParams (void**);
//		unsigned int sharedMemBytes (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphKernelNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"struct const hipKernelNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphKernelNodeSetParams.pNodeParams); \
	if (args->hipGraphKernelNodeSetParams.pNodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"blockDim\":{\"type\":\"struct dim3\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphKernelNodeSetParams.pNodeParams).blockDim).x); \
		ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphKernelNodeSetParams.pNodeParams).blockDim).y); \
		ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", ((*args->hipGraphKernelNodeSetParams.pNodeParams).blockDim).z); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"extra\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphKernelNodeSetParams.pNodeParams).extra); \
		if ((*args->hipGraphKernelNodeSetParams.pNodeParams).extra != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphKernelNodeSetParams.pNodeParams).extra); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphKernelNodeSetParams.pNodeParams).func); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"gridDim\":{\"type\":\"struct dim3\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphKernelNodeSetParams.pNodeParams).gridDim).x); \
		ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphKernelNodeSetParams.pNodeParams).gridDim).y); \
		ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", ((*args->hipGraphKernelNodeSetParams.pNodeParams).gridDim).z); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"kernelParams\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphKernelNodeSetParams.pNodeParams).kernelParams); \
		if ((*args->hipGraphKernelNodeSetParams.pNodeParams).kernelParams != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphKernelNodeSetParams.pNodeParams).kernelParams); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"sharedMemBytes\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", (*args->hipGraphKernelNodeSetParams.pNodeParams).sharedMemBytes); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipFunction_t * function (unknown);
//	hipModule_t module (unknown);
//	const char * kname (char*);
#define PROCESS_ARGS_hipModuleGetFunction(args) { \
	ratelprof_add_to_buffer(buf, "\"function\":{\"type\":\"hipFunction_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"module\":{\"type\":\"hipModule_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"kname\":{\"type\":\"const char *\",\"value\":{\"addr\":\"%p\"", args->hipModuleGetFunction.kname); \
	if (args->hipModuleGetFunction.kname != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *args->hipModuleGetFunction.kname); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	void * dst (void*);
//	hipArray_t srcArray (unknown);
//	size_t srcOffset (unsigned long);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemcpyAtoH(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyAtoH.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"srcArray\":{\"type\":\"hipArray_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"srcOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyAtoH.srcOffset); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemcpyAtoH.count); \
};

//	int peerDeviceId (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipDeviceEnablePeerAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"peerDeviceId\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceEnablePeerAccess.peerDeviceId); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipDeviceEnablePeerAccess.flags); \
};

//	hipMemGenericAllocationHandle_t * handle (unknown);
//	void * addr (void*);
#define PROCESS_ARGS_hipMemRetainAllocationHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"hipMemGenericAllocationHandle_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"addr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemRetainAllocationHandle.addr); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipMipmappedArray_t* pArray (unknown);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipMappedArray(args) { \
	ratelprof_add_to_buffer(buf, "\"pArray\":{\"type\":\"hipMipmappedArray_t*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"NULL\"}"); \
};

//	float * pbias (float*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipmapLevelBias(args) { \
	ratelprof_add_to_buffer(buf, "\"pbias\":{\"type\":\"float *\",\"value\":{\"addr\":\"%p\"", args->hipTexRefGetMipmapLevelBias.pbias); \
	if (args->hipTexRefGetMipmapLevelBias.pbias != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%f\"", *args->hipTexRefGetMipmapLevelBias.pbias); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"NULL\"}"); \
};

//	size_t * offset (unsigned long*);
//	const textureReference* tex (unknown);
//	const void * devPtr (void*);
//	const hipChannelFormatDesc * desc (unknown);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipBindTexture(args) { \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipBindTexture.offset); \
	if (args->hipBindTexture.offset != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipBindTexture.offset); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"tex\":{\"type\":\"const textureReference*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipBindTexture.devPtr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"const hipChannelFormatDesc *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipBindTexture.size); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	hipGraph_t childGraph (unknown);
#define PROCESS_ARGS_hipGraphAddChildGraphNode(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddChildGraphNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"childGraph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
};

//	enum hipLimit_t limit (enum);
//	size_t value (unsigned long);
#define PROCESS_ARGS_hipDeviceSetLimit(args) { \
	ratelprof_add_to_buffer(buf, "\"limit\":{\"type\":\"enum hipLimit_t\",\"value\":\"%d\"},", args->hipDeviceSetLimit.limit); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipDeviceSetLimit.value); \
};

//	hipChannelFormatDesc * desc (unknown);
//	hipArray_const_t array (unknown);
#define PROCESS_ARGS_hipGetChannelDesc(args) { \
	ratelprof_add_to_buffer(buf, "\"desc\":{\"type\":\"hipChannelFormatDesc *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"array\":{\"type\":\"hipArray_const_t\",\"value\":\"NULL\"}"); \
};

//	hipGraphicsResource_t resource (unknown);
#define PROCESS_ARGS_hipGraphicsUnregisterResource(args) { \
	ratelprof_add_to_buffer(buf, "\"resource\":{\"type\":\"hipGraphicsResource_t\",\"value\":\"NULL\"}"); \
};

//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * from (unknown);
//	const hipGraphNode_t * to (unknown);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphRemoveDependencies(args) { \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"from\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"to\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipGraphRemoveDependencies.numDependencies); \
};

//	textureReference* texRef (unknown);
//	float * pBorderColor (float*);
#define PROCESS_ARGS_hipTexRefSetBorderColor(args) { \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pBorderColor\":{\"type\":\"float *\",\"value\":{\"addr\":\"%p\"", args->hipTexRefSetBorderColor.pBorderColor); \
	if (args->hipTexRefSetBorderColor.pBorderColor != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%f\"", *args->hipTexRefSetBorderColor.pBorderColor); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipDevice_t dev (int);
//	unsigned int * flags (unsigned int*);
//	int * active (int*);
#define PROCESS_ARGS_hipDevicePrimaryCtxGetState(args) { \
	ratelprof_add_to_buffer(buf, "\"dev\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"},", args->hipDevicePrimaryCtxGetState.dev); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int *\",\"value\":{\"addr\":\"%p\"", args->hipDevicePrimaryCtxGetState.flags); \
	if (args->hipDevicePrimaryCtxGetState.flags != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *args->hipDevicePrimaryCtxGetState.flags); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"active\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipDevicePrimaryCtxGetState.active); \
	if (args->hipDevicePrimaryCtxGetState.active != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipDevicePrimaryCtxGetState.active); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipPitchedPtr* pitchedDevPtr (unknown);
//	hipExtent extent (unknown);
#define PROCESS_ARGS_hipMalloc3D(args) { \
	ratelprof_add_to_buffer(buf, "\"pitchedDevPtr\":{\"type\":\"hipPitchedPtr*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"extent\":{\"type\":\"hipExtent\",\"value\":\"NULL\"}"); \
};

//	float * pminMipmapLevelClamp (float*);
//	float * pmaxMipmapLevelClamp (float*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipmapLevelClamp(args) { \
	ratelprof_add_to_buffer(buf, "\"pminMipmapLevelClamp\":{\"type\":\"float *\",\"value\":{\"addr\":\"%p\"", args->hipTexRefGetMipmapLevelClamp.pminMipmapLevelClamp); \
	if (args->hipTexRefGetMipmapLevelClamp.pminMipmapLevelClamp != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%f\"", *args->hipTexRefGetMipmapLevelClamp.pminMipmapLevelClamp); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"pmaxMipmapLevelClamp\":{\"type\":\"float *\",\"value\":{\"addr\":\"%p\"", args->hipTexRefGetMipmapLevelClamp.pmaxMipmapLevelClamp); \
	if (args->hipTexRefGetMipmapLevelClamp.pmaxMipmapLevelClamp != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%f\"", *args->hipTexRefGetMipmapLevelClamp.pmaxMipmapLevelClamp); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"NULL\"}"); \
};

//	hipFunction_t f (unknown);
//	unsigned int gridDimX (unsigned int);
//	unsigned int gridDimY (unsigned int);
//	unsigned int gridDimZ (unsigned int);
//	unsigned int blockDimX (unsigned int);
//	unsigned int blockDimY (unsigned int);
//	unsigned int blockDimZ (unsigned int);
//	unsigned int sharedMemBytes (unsigned int);
//	hipStream_t stream (unknown);
//	void ** kernelParams (void**);
//	void ** extra (void**);
#define PROCESS_ARGS_hipModuleLaunchKernel(args) { \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"hipFunction_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"gridDimX\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchKernel.gridDimX); \
	ratelprof_add_to_buffer(buf, "\"gridDimY\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchKernel.gridDimY); \
	ratelprof_add_to_buffer(buf, "\"gridDimZ\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchKernel.gridDimZ); \
	ratelprof_add_to_buffer(buf, "\"blockDimX\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchKernel.blockDimX); \
	ratelprof_add_to_buffer(buf, "\"blockDimY\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchKernel.blockDimY); \
	ratelprof_add_to_buffer(buf, "\"blockDimZ\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchKernel.blockDimZ); \
	ratelprof_add_to_buffer(buf, "\"sharedMemBytes\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipModuleLaunchKernel.sharedMemBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"kernelParams\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipModuleLaunchKernel.kernelParams); \
	if (args->hipModuleLaunchKernel.kernelParams != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipModuleLaunchKernel.kernelParams); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"extra\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipModuleLaunchKernel.extra); \
	if (args->hipModuleLaunchKernel.extra != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipModuleLaunchKernel.extra); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	const void * hostFunction (void*);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipKernelNameRefByPtr(args) { \
	ratelprof_add_to_buffer(buf, "\"hostFunction\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipKernelNameRefByPtr.hostFunction); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipSharedMemConfig config (enum);
#define PROCESS_ARGS_hipDeviceSetSharedMemConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"config\":{\"type\":\"hipSharedMemConfig\",\"value\":\"%d\"}", args->hipDeviceSetSharedMemConfig.config); \
};

//	const void * symbol (void*);
//	const void * src (void*);
//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyToSymbolAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyToSymbolAsync.symbol); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyToSymbolAsync.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyToSymbolAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyToSymbolAsync.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	void ** devPtr (void**);
//	void * hstPtr (void*);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostGetDevicePointer(args) { \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipHostGetDevicePointer.devPtr); \
	if (args->hipHostGetDevicePointer.devPtr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipHostGetDevicePointer.devPtr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"hstPtr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipHostGetDevicePointer.hstPtr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipHostGetDevicePointer.flags); \
};

//	hipGraph_t graph (unknown);
//	hipUserObject_t object (unknown);
//	unsigned int count (unsigned int);
#define PROCESS_ARGS_hipGraphReleaseUserObject(args) { \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"object\":{\"type\":\"hipUserObject_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipGraphReleaseUserObject.count); \
};

//	int device (int);
#define PROCESS_ARGS_hipDeviceGraphMemTrim(args) { \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceGraphMemTrim.device); \
};

//	int * leastPriority (int*);
//	int * greatestPriority (int*);
#define PROCESS_ARGS_hipDeviceGetStreamPriorityRange(args) { \
	ratelprof_add_to_buffer(buf, "\"leastPriority\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceGetStreamPriorityRange.leastPriority); \
	if (args->hipDeviceGetStreamPriorityRange.leastPriority != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipDeviceGetStreamPriorityRange.leastPriority); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"greatestPriority\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceGetStreamPriorityRange.greatestPriority); \
	if (args->hipDeviceGetStreamPriorityRange.greatestPriority != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipDeviceGetStreamPriorityRange.greatestPriority); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	void * data (void*);
//	hipPointer_attribute attribute (unknown);
//	hipDeviceptr_t ptr (unknown);
#define PROCESS_ARGS_hipPointerGetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"data\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipPointerGetAttribute.data); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attribute\":{\"type\":\"hipPointer_attribute\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
};

//	hipMemPool_t mem_pool (unknown);
//	struct const hipMemAccessDesc * desc_list ({
//		hipMemLocation location ({
//			hipMemLocationType type (enum);
//			int id (int);
//		});
//		hipMemAccessFlags flags (enum);
//	});
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemPoolSetAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"desc_list\":{\"type\":\"struct const hipMemAccessDesc *\",\"value\":{\"addr\":\"%p\"", args->hipMemPoolSetAccess.desc_list); \
	if (args->hipMemPoolSetAccess.desc_list != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"location\":{\"type\":\"struct hipMemLocation\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipMemLocationType\",\"value\":\"%d\"},", ((*args->hipMemPoolSetAccess.desc_list).location).type); \
		ratelprof_add_to_buffer(buf, "\"id\":{\"type\":\"int\",\"value\":\"%d\"}", ((*args->hipMemPoolSetAccess.desc_list).location).id); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"hipMemAccessFlags\",\"value\":\"%d\"}", (*args->hipMemPoolSetAccess.desc_list).flags); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"}", args->hipMemPoolSetAccess.count); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t hNode (unknown);
//	struct const hipExternalSemaphoreWaitNodeParams * nodeParams ({
//		hipExternalSemaphore_t * extSemArray (void**);
//		struct const hipExternalSemaphoreWaitParams * paramsArray ({
//			struct (unnamed struct at ./input/hip_runtime_api.h:1156:3) params (unknown);
//			unsigned int flags (unsigned int);
//			unsigned int[16] reserved (unsigned int*);
//		});
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphExecExternalSemaphoresWaitNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"nodeParams\":{\"type\":\"struct const hipExternalSemaphoreWaitNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams); \
	if (args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"extSemArray\":{\"type\":\"hipExternalSemaphore_t *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).extSemArray); \
		if ((*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).extSemArray != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).extSemArray); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"paramsArray\":{\"type\":\"struct const hipExternalSemaphoreWaitParams *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray); \
		if ((*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray != NULL) { \
			ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
			ratelprof_add_to_buffer(buf, "\"params\":{\"type\":\"struct (unnamed struct at ./input/hip_runtime_api.h:1156:3)\",\"value\":\"NULL\"}"); \
			ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*(*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).flags); \
			ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned int[16]\",\"value\":{\"addr\":\"%p\"", (*(*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).reserved); \
			if ((*(*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).reserved != NULL) { \
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*(*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).reserved); \
			} \
			ratelprof_add_to_buffer(buf, "}}"); \
			ratelprof_add_to_buffer(buf, "}"); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"numExtSems\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", (*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).numExtSems); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	void * dst (void*);
//	const void * src (void*);
//	size_t sizeBytes (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpy(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpy.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpy.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	int peerDeviceId (int);
#define PROCESS_ARGS_hipDeviceDisablePeerAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"peerDeviceId\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceDisablePeerAccess.peerDeviceId); \
};

//	hipGraphNode_t hNode (unknown);
//	hipKernelNodeAttrID attr (enum);
//	union const hipKernelNodeAttrValue * value ({
//		hipAccessPolicyWindow accessPolicyWindow ({
//			void * base_ptr (void*);
//			hipAccessProperty hitProp (enum);
//			float hitRatio (float);
//			hipAccessProperty missProp (enum);
//			int num_bytes (int);
//		});
//		int cooperative (int);
//	});
#define PROCESS_ARGS_hipGraphKernelNodeSetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipKernelNodeAttrID\",\"value\":\"%d\"},", args->hipGraphKernelNodeSetAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"union const hipKernelNodeAttrValue *\",\"value\":{\"addr\":\"%p\"", args->hipGraphKernelNodeSetAttribute.value); \
	if (args->hipGraphKernelNodeSetAttribute.value != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"accessPolicyWindow\":{\"type\":\"struct hipAccessPolicyWindow\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"base_ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", ((*args->hipGraphKernelNodeSetAttribute.value).accessPolicyWindow).base_ptr); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"hitProp\":{\"type\":\"hipAccessProperty\",\"value\":\"%d\"},", ((*args->hipGraphKernelNodeSetAttribute.value).accessPolicyWindow).hitProp); \
		ratelprof_add_to_buffer(buf, "\"hitRatio\":{\"type\":\"float\",\"value\":\"%f\"},", ((*args->hipGraphKernelNodeSetAttribute.value).accessPolicyWindow).hitRatio); \
		ratelprof_add_to_buffer(buf, "\"missProp\":{\"type\":\"hipAccessProperty\",\"value\":\"%d\"},", ((*args->hipGraphKernelNodeSetAttribute.value).accessPolicyWindow).missProp); \
		ratelprof_add_to_buffer(buf, "\"num_bytes\":{\"type\":\"int\",\"value\":\"%d\"}", ((*args->hipGraphKernelNodeSetAttribute.value).accessPolicyWindow).num_bytes); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"cooperative\":{\"type\":\"int\",\"value\":\"%d\"}", (*args->hipGraphKernelNodeSetAttribute.value).cooperative); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	void * dst (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphAddMemcpyNode1D(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNode1D.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphAddMemcpyNode1D.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphAddMemcpyNode1D.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNode1D.count); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t hNode (unknown);
//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipGraphExecEventRecordNodeSetEvent(args) { \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
};

//	int count (int);
//	hipGraphicsResource_t * resources (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipGraphicsUnmapResources(args) { \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipGraphicsUnmapResources.count); \
	ratelprof_add_to_buffer(buf, "\"resources\":{\"type\":\"hipGraphicsResource_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	struct const hipExternalSemaphoreWaitNodeParams * nodeParams ({
//		hipExternalSemaphore_t * extSemArray (void**);
//		struct const hipExternalSemaphoreWaitParams * paramsArray ({
//			struct (unnamed struct at ./input/hip_runtime_api.h:1156:3) params (unknown);
//			unsigned int flags (unsigned int);
//			unsigned int[16] reserved (unsigned int*);
//		});
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphAddExternalSemaphoresWaitNode(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddExternalSemaphoresWaitNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"nodeParams\":{\"type\":\"struct const hipExternalSemaphoreWaitNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphAddExternalSemaphoresWaitNode.nodeParams); \
	if (args->hipGraphAddExternalSemaphoresWaitNode.nodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"extSemArray\":{\"type\":\"hipExternalSemaphore_t *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).extSemArray); \
		if ((*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).extSemArray != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).extSemArray); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"paramsArray\":{\"type\":\"struct const hipExternalSemaphoreWaitParams *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).paramsArray); \
		if ((*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).paramsArray != NULL) { \
			ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
			ratelprof_add_to_buffer(buf, "\"params\":{\"type\":\"struct (unnamed struct at ./input/hip_runtime_api.h:1156:3)\",\"value\":\"NULL\"}"); \
			ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*(*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).paramsArray).flags); \
			ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned int[16]\",\"value\":{\"addr\":\"%p\"", (*(*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).paramsArray).reserved); \
			if ((*(*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).paramsArray).reserved != NULL) { \
				ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*(*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).paramsArray).reserved); \
			} \
			ratelprof_add_to_buffer(buf, "}}"); \
			ratelprof_add_to_buffer(buf, "}"); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"numExtSems\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", (*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).numExtSems); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphNode_t * phGraphNode (unknown);
//	hipGraph_t hGraph (unknown);
//	const hipGraphNode_t * dependencies (unknown);
//	size_t numDependencies (unsigned long);
//	const HIP_MEMCPY3D * copyParams (unknown);
//	hipCtx_t ctx (unknown);
#define PROCESS_ARGS_hipDrvGraphAddMemcpyNode(args) { \
	ratelprof_add_to_buffer(buf, "\"phGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"hGraph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipDrvGraphAddMemcpyNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"copyParams\":{\"type\":\"const HIP_MEMCPY3D *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t\",\"value\":\"NULL\"}"); \
};

//	float * ms (float*);
//	hipEvent_t start (unknown);
//	hipEvent_t stop (unknown);
#define PROCESS_ARGS_hipEventElapsedTime(args) { \
	ratelprof_add_to_buffer(buf, "\"ms\":{\"type\":\"float *\",\"value\":{\"addr\":\"%p\"", args->hipEventElapsedTime.ms); \
	if (args->hipEventElapsedTime.ms != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%f\"", *args->hipEventElapsedTime.ms); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"start\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stop\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
};

//	const struct hipMemcpy3DParms * p (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpy3DAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"p\":{\"type\":\"const struct hipMemcpy3DParms *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	int * pmaxAnsio (int*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMaxAnisotropy(args) { \
	ratelprof_add_to_buffer(buf, "\"pmaxAnsio\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipTexRefGetMaxAnisotropy.pmaxAnsio); \
	if (args->hipTexRefGetMaxAnisotropy.pmaxAnsio != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipTexRefGetMaxAnisotropy.pmaxAnsio); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t node (unknown);
//	hipGraphNode_t * pDependentNodes (unknown);
//	size_t * pNumDependentNodes (unsigned long*);
#define PROCESS_ARGS_hipGraphNodeGetDependentNodes(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependentNodes\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNumDependentNodes\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipGraphNodeGetDependentNodes.pNumDependentNodes); \
	if (args->hipGraphNodeGetDependentNodes.pNumDependentNodes != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipGraphNodeGetDependentNodes.pNumDependentNodes); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipMemPool_t mem_pool (unknown);
//	hipMemPoolAttr attr (enum);
//	void * value (void*);
#define PROCESS_ARGS_hipMemPoolGetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipMemPoolAttr\",\"value\":\"%d\"},", args->hipMemPoolGetAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemPoolGetAttribute.value); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipStream_t stream (unknown);
//	hipDevice_t * device (int*);
#define PROCESS_ARGS_hipStreamGetDevice(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t *\",\"value\":{\"addr\":\"%p\"", args->hipStreamGetDevice.device); \
	if (args->hipStreamGetDevice.device != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipStreamGetDevice.device); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipResourceDesc* pResDesc (unknown);
//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipGetTextureObjectResourceDesc(args) { \
	ratelprof_add_to_buffer(buf, "\"pResDesc\":{\"type\":\"hipResourceDesc*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"textureObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"NULL\"}"); \
};

//	unsigned int * pFlags (unsigned int*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"pFlags\":{\"type\":\"unsigned int *\",\"value\":{\"addr\":\"%p\"", args->hipTexRefGetFlags.pFlags); \
	if (args->hipTexRefGetFlags.pFlags != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *args->hipTexRefGetFlags.pFlags); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"NULL\"}"); \
};

//	int * device (int*);
//	struct const hipDeviceProp_tR0600 * prop ({
//		char[256] name (char*);
//		hipUUID uuid ({
//			char[16] bytes (char*);
//		});
//		char[8] luid (char*);
//		unsigned int luidDeviceNodeMask (unsigned int);
//		int totalGlobalMem (int);
//		int sharedMemPerBlock (int);
//		int regsPerBlock (int);
//		int warpSize (int);
//		int memPitch (int);
//		int maxThreadsPerBlock (int);
//		int[3] maxThreadsDim (int*);
//		int[3] maxGridSize (int*);
//		int clockRate (int);
//		int totalConstMem (int);
//		int major (int);
//		int minor (int);
//		int textureAlignment (int);
//		int texturePitchAlignment (int);
//		int deviceOverlap (int);
//		int multiProcessorCount (int);
//		int kernelExecTimeoutEnabled (int);
//		int integrated (int);
//		int canMapHostMemory (int);
//		int computeMode (int);
//		int maxTexture1D (int);
//		int maxTexture1DMipmap (int);
//		int maxTexture1DLinear (int);
//		int[2] maxTexture2D (int*);
//		int[2] maxTexture2DMipmap (int*);
//		int[3] maxTexture2DLinear (int*);
//		int[2] maxTexture2DGather (int*);
//		int[3] maxTexture3D (int*);
//		int[3] maxTexture3DAlt (int*);
//		int maxTextureCubemap (int);
//		int[2] maxTexture1DLayered (int*);
//		int[3] maxTexture2DLayered (int*);
//		int[2] maxTextureCubemapLayered (int*);
//		int maxSurface1D (int);
//		int[2] maxSurface2D (int*);
//		int[3] maxSurface3D (int*);
//		int[2] maxSurface1DLayered (int*);
//		int[3] maxSurface2DLayered (int*);
//		int maxSurfaceCubemap (int);
//		int[2] maxSurfaceCubemapLayered (int*);
//		int surfaceAlignment (int);
//		int concurrentKernels (int);
//		int ECCEnabled (int);
//		int pciBusID (int);
//		int pciDeviceID (int);
//		int pciDomainID (int);
//		int tccDriver (int);
//		int asyncEngineCount (int);
//		int unifiedAddressing (int);
//		int memoryClockRate (int);
//		int memoryBusWidth (int);
//		int l2CacheSize (int);
//		int persistingL2CacheMaxSize (int);
//		int maxThreadsPerMultiProcessor (int);
//		int streamPrioritiesSupported (int);
//		int globalL1CacheSupported (int);
//		int localL1CacheSupported (int);
//		int sharedMemPerMultiprocessor (int);
//		int regsPerMultiprocessor (int);
//		int managedMemory (int);
//		int isMultiGpuBoard (int);
//		int multiGpuBoardGroupID (int);
//		int hostNativeAtomicSupported (int);
//		int singleToDoublePrecisionPerfRatio (int);
//		int pageableMemoryAccess (int);
//		int concurrentManagedAccess (int);
//		int computePreemptionSupported (int);
//		int canUseHostPointerForRegisteredMem (int);
//		int cooperativeLaunch (int);
//		int cooperativeMultiDeviceLaunch (int);
//		int sharedMemPerBlockOptin (int);
//		int pageableMemoryAccessUsesHostPageTables (int);
//		int directManagedMemAccessFromHost (int);
//		int maxBlocksPerMultiProcessor (int);
//		int accessPolicyMaxWindowSize (int);
//		int reservedSharedMemPerBlock (int);
//		int hostRegisterSupported (int);
//		int sparseHipArraySupported (int);
//		int hostRegisterReadOnlySupported (int);
//		int timelineSemaphoreInteropSupported (int);
//		int memoryPoolsSupported (int);
//		int gpuDirectRDMASupported (int);
//		unsigned int gpuDirectRDMAFlushWritesOptions (unsigned int);
//		int gpuDirectRDMAWritesOrdering (int);
//		unsigned int memoryPoolSupportedHandleTypes (unsigned int);
//		int deferredMappingHipArraySupported (int);
//		int ipcEventSupported (int);
//		int clusterLaunch (int);
//		int unifiedFunctionPointers (int);
//		int[63] reserved (int*);
//		int[32] hipReserved (int*);
//		char[256] gcnArchName (char*);
//		int maxSharedMemoryPerMultiProcessor (int);
//		int clockInstructionRate (int);
//		hipDeviceArch_t arch ({
//			unsigned int hasGlobalInt32Atomics (unsigned int);
//			unsigned int hasGlobalFloatAtomicExch (unsigned int);
//			unsigned int hasSharedInt32Atomics (unsigned int);
//			unsigned int hasSharedFloatAtomicExch (unsigned int);
//			unsigned int hasFloatAtomicAdd (unsigned int);
//			unsigned int hasGlobalInt64Atomics (unsigned int);
//			unsigned int hasSharedInt64Atomics (unsigned int);
//			unsigned int hasDoubles (unsigned int);
//			unsigned int hasWarpVote (unsigned int);
//			unsigned int hasWarpBallot (unsigned int);
//			unsigned int hasWarpShuffle (unsigned int);
//			unsigned int hasFunnelShift (unsigned int);
//			unsigned int hasThreadFenceSystem (unsigned int);
//			unsigned int hasSyncThreadsExt (unsigned int);
//			unsigned int hasSurfaceFuncs (unsigned int);
//			unsigned int has3dGrid (unsigned int);
//			unsigned int hasDynamicParallelism (unsigned int);
//		});
//		unsigned int * hdpMemFlushCntl (unsigned int*);
//		unsigned int * hdpRegFlushCntl (unsigned int*);
//		int cooperativeMultiDeviceUnmatchedFunc (int);
//		int cooperativeMultiDeviceUnmatchedGridDim (int);
//		int cooperativeMultiDeviceUnmatchedBlockDim (int);
//		int cooperativeMultiDeviceUnmatchedSharedMem (int);
//		int isLargeBar (int);
//		int asicRevision (int);
//	});
#define PROCESS_ARGS_hipChooseDeviceR0600(args) { \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipChooseDeviceR0600.device); \
	if (args->hipChooseDeviceR0600.device != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipChooseDeviceR0600.device); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"struct const hipDeviceProp_tR0600 *\",\"value\":{\"addr\":\"%p\"", args->hipChooseDeviceR0600.prop); \
	if (args->hipChooseDeviceR0600.prop != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"name\":{\"type\":\"char[256]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).name); \
		if ((*args->hipChooseDeviceR0600.prop).name != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *(*args->hipChooseDeviceR0600.prop).name); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"uuid\":{\"type\":\"struct hipUUID\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"bytes\":{\"type\":\"char[16]\",\"value\":{\"addr\":\"%p\"", ((*args->hipChooseDeviceR0600.prop).uuid).bytes); \
		if (((*args->hipChooseDeviceR0600.prop).uuid).bytes != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *((*args->hipChooseDeviceR0600.prop).uuid).bytes); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"luid\":{\"type\":\"char[8]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).luid); \
		if ((*args->hipChooseDeviceR0600.prop).luid != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *(*args->hipChooseDeviceR0600.prop).luid); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"luidDeviceNodeMask\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipChooseDeviceR0600.prop).luidDeviceNodeMask); \
		ratelprof_add_to_buffer(buf, "\"totalGlobalMem\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).totalGlobalMem); \
		ratelprof_add_to_buffer(buf, "\"sharedMemPerBlock\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).sharedMemPerBlock); \
		ratelprof_add_to_buffer(buf, "\"regsPerBlock\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).regsPerBlock); \
		ratelprof_add_to_buffer(buf, "\"warpSize\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).warpSize); \
		ratelprof_add_to_buffer(buf, "\"memPitch\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).memPitch); \
		ratelprof_add_to_buffer(buf, "\"maxThreadsPerBlock\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).maxThreadsPerBlock); \
		ratelprof_add_to_buffer(buf, "\"maxThreadsDim\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxThreadsDim); \
		if ((*args->hipChooseDeviceR0600.prop).maxThreadsDim != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxThreadsDim); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxGridSize\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxGridSize); \
		if ((*args->hipChooseDeviceR0600.prop).maxGridSize != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxGridSize); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"clockRate\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).clockRate); \
		ratelprof_add_to_buffer(buf, "\"totalConstMem\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).totalConstMem); \
		ratelprof_add_to_buffer(buf, "\"major\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).major); \
		ratelprof_add_to_buffer(buf, "\"minor\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).minor); \
		ratelprof_add_to_buffer(buf, "\"textureAlignment\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).textureAlignment); \
		ratelprof_add_to_buffer(buf, "\"texturePitchAlignment\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).texturePitchAlignment); \
		ratelprof_add_to_buffer(buf, "\"deviceOverlap\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).deviceOverlap); \
		ratelprof_add_to_buffer(buf, "\"multiProcessorCount\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).multiProcessorCount); \
		ratelprof_add_to_buffer(buf, "\"kernelExecTimeoutEnabled\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).kernelExecTimeoutEnabled); \
		ratelprof_add_to_buffer(buf, "\"integrated\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).integrated); \
		ratelprof_add_to_buffer(buf, "\"canMapHostMemory\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).canMapHostMemory); \
		ratelprof_add_to_buffer(buf, "\"computeMode\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).computeMode); \
		ratelprof_add_to_buffer(buf, "\"maxTexture1D\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).maxTexture1D); \
		ratelprof_add_to_buffer(buf, "\"maxTexture1DMipmap\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).maxTexture1DMipmap); \
		ratelprof_add_to_buffer(buf, "\"maxTexture1DLinear\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).maxTexture1DLinear); \
		ratelprof_add_to_buffer(buf, "\"maxTexture2D\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxTexture2D); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture2D != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxTexture2D); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTexture2DMipmap\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxTexture2DMipmap); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture2DMipmap != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxTexture2DMipmap); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTexture2DLinear\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxTexture2DLinear); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture2DLinear != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxTexture2DLinear); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTexture2DGather\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxTexture2DGather); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture2DGather != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxTexture2DGather); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTexture3D\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxTexture3D); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture3D != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxTexture3D); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTexture3DAlt\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxTexture3DAlt); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture3DAlt != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxTexture3DAlt); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTextureCubemap\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).maxTextureCubemap); \
		ratelprof_add_to_buffer(buf, "\"maxTexture1DLayered\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxTexture1DLayered); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture1DLayered != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxTexture1DLayered); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTexture2DLayered\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxTexture2DLayered); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture2DLayered != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxTexture2DLayered); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTextureCubemapLayered\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxTextureCubemapLayered); \
		if ((*args->hipChooseDeviceR0600.prop).maxTextureCubemapLayered != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxTextureCubemapLayered); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxSurface1D\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).maxSurface1D); \
		ratelprof_add_to_buffer(buf, "\"maxSurface2D\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxSurface2D); \
		if ((*args->hipChooseDeviceR0600.prop).maxSurface2D != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxSurface2D); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxSurface3D\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxSurface3D); \
		if ((*args->hipChooseDeviceR0600.prop).maxSurface3D != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxSurface3D); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxSurface1DLayered\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxSurface1DLayered); \
		if ((*args->hipChooseDeviceR0600.prop).maxSurface1DLayered != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxSurface1DLayered); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxSurface2DLayered\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxSurface2DLayered); \
		if ((*args->hipChooseDeviceR0600.prop).maxSurface2DLayered != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxSurface2DLayered); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxSurfaceCubemap\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).maxSurfaceCubemap); \
		ratelprof_add_to_buffer(buf, "\"maxSurfaceCubemapLayered\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).maxSurfaceCubemapLayered); \
		if ((*args->hipChooseDeviceR0600.prop).maxSurfaceCubemapLayered != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).maxSurfaceCubemapLayered); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"surfaceAlignment\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).surfaceAlignment); \
		ratelprof_add_to_buffer(buf, "\"concurrentKernels\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).concurrentKernels); \
		ratelprof_add_to_buffer(buf, "\"ECCEnabled\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).ECCEnabled); \
		ratelprof_add_to_buffer(buf, "\"pciBusID\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).pciBusID); \
		ratelprof_add_to_buffer(buf, "\"pciDeviceID\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).pciDeviceID); \
		ratelprof_add_to_buffer(buf, "\"pciDomainID\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).pciDomainID); \
		ratelprof_add_to_buffer(buf, "\"tccDriver\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).tccDriver); \
		ratelprof_add_to_buffer(buf, "\"asyncEngineCount\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).asyncEngineCount); \
		ratelprof_add_to_buffer(buf, "\"unifiedAddressing\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).unifiedAddressing); \
		ratelprof_add_to_buffer(buf, "\"memoryClockRate\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).memoryClockRate); \
		ratelprof_add_to_buffer(buf, "\"memoryBusWidth\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).memoryBusWidth); \
		ratelprof_add_to_buffer(buf, "\"l2CacheSize\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).l2CacheSize); \
		ratelprof_add_to_buffer(buf, "\"persistingL2CacheMaxSize\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).persistingL2CacheMaxSize); \
		ratelprof_add_to_buffer(buf, "\"maxThreadsPerMultiProcessor\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).maxThreadsPerMultiProcessor); \
		ratelprof_add_to_buffer(buf, "\"streamPrioritiesSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).streamPrioritiesSupported); \
		ratelprof_add_to_buffer(buf, "\"globalL1CacheSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).globalL1CacheSupported); \
		ratelprof_add_to_buffer(buf, "\"localL1CacheSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).localL1CacheSupported); \
		ratelprof_add_to_buffer(buf, "\"sharedMemPerMultiprocessor\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).sharedMemPerMultiprocessor); \
		ratelprof_add_to_buffer(buf, "\"regsPerMultiprocessor\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).regsPerMultiprocessor); \
		ratelprof_add_to_buffer(buf, "\"managedMemory\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).managedMemory); \
		ratelprof_add_to_buffer(buf, "\"isMultiGpuBoard\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).isMultiGpuBoard); \
		ratelprof_add_to_buffer(buf, "\"multiGpuBoardGroupID\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).multiGpuBoardGroupID); \
		ratelprof_add_to_buffer(buf, "\"hostNativeAtomicSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).hostNativeAtomicSupported); \
		ratelprof_add_to_buffer(buf, "\"singleToDoublePrecisionPerfRatio\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).singleToDoublePrecisionPerfRatio); \
		ratelprof_add_to_buffer(buf, "\"pageableMemoryAccess\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).pageableMemoryAccess); \
		ratelprof_add_to_buffer(buf, "\"concurrentManagedAccess\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).concurrentManagedAccess); \
		ratelprof_add_to_buffer(buf, "\"computePreemptionSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).computePreemptionSupported); \
		ratelprof_add_to_buffer(buf, "\"canUseHostPointerForRegisteredMem\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).canUseHostPointerForRegisteredMem); \
		ratelprof_add_to_buffer(buf, "\"cooperativeLaunch\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).cooperativeLaunch); \
		ratelprof_add_to_buffer(buf, "\"cooperativeMultiDeviceLaunch\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).cooperativeMultiDeviceLaunch); \
		ratelprof_add_to_buffer(buf, "\"sharedMemPerBlockOptin\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).sharedMemPerBlockOptin); \
		ratelprof_add_to_buffer(buf, "\"pageableMemoryAccessUsesHostPageTables\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).pageableMemoryAccessUsesHostPageTables); \
		ratelprof_add_to_buffer(buf, "\"directManagedMemAccessFromHost\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).directManagedMemAccessFromHost); \
		ratelprof_add_to_buffer(buf, "\"maxBlocksPerMultiProcessor\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).maxBlocksPerMultiProcessor); \
		ratelprof_add_to_buffer(buf, "\"accessPolicyMaxWindowSize\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).accessPolicyMaxWindowSize); \
		ratelprof_add_to_buffer(buf, "\"reservedSharedMemPerBlock\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).reservedSharedMemPerBlock); \
		ratelprof_add_to_buffer(buf, "\"hostRegisterSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).hostRegisterSupported); \
		ratelprof_add_to_buffer(buf, "\"sparseHipArraySupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).sparseHipArraySupported); \
		ratelprof_add_to_buffer(buf, "\"hostRegisterReadOnlySupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).hostRegisterReadOnlySupported); \
		ratelprof_add_to_buffer(buf, "\"timelineSemaphoreInteropSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).timelineSemaphoreInteropSupported); \
		ratelprof_add_to_buffer(buf, "\"memoryPoolsSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).memoryPoolsSupported); \
		ratelprof_add_to_buffer(buf, "\"gpuDirectRDMASupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).gpuDirectRDMASupported); \
		ratelprof_add_to_buffer(buf, "\"gpuDirectRDMAFlushWritesOptions\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipChooseDeviceR0600.prop).gpuDirectRDMAFlushWritesOptions); \
		ratelprof_add_to_buffer(buf, "\"gpuDirectRDMAWritesOrdering\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).gpuDirectRDMAWritesOrdering); \
		ratelprof_add_to_buffer(buf, "\"memoryPoolSupportedHandleTypes\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipChooseDeviceR0600.prop).memoryPoolSupportedHandleTypes); \
		ratelprof_add_to_buffer(buf, "\"deferredMappingHipArraySupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).deferredMappingHipArraySupported); \
		ratelprof_add_to_buffer(buf, "\"ipcEventSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).ipcEventSupported); \
		ratelprof_add_to_buffer(buf, "\"clusterLaunch\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).clusterLaunch); \
		ratelprof_add_to_buffer(buf, "\"unifiedFunctionPointers\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).unifiedFunctionPointers); \
		ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"int[63]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).reserved); \
		if ((*args->hipChooseDeviceR0600.prop).reserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).reserved); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"hipReserved\":{\"type\":\"int[32]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).hipReserved); \
		if ((*args->hipChooseDeviceR0600.prop).hipReserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipChooseDeviceR0600.prop).hipReserved); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"gcnArchName\":{\"type\":\"char[256]\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).gcnArchName); \
		if ((*args->hipChooseDeviceR0600.prop).gcnArchName != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *(*args->hipChooseDeviceR0600.prop).gcnArchName); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxSharedMemoryPerMultiProcessor\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).maxSharedMemoryPerMultiProcessor); \
		ratelprof_add_to_buffer(buf, "\"clockInstructionRate\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).clockInstructionRate); \
		ratelprof_add_to_buffer(buf, "\"arch\":{\"type\":\"struct hipDeviceArch_t\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"hasGlobalInt32Atomics\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).hasGlobalInt32Atomics); \
		ratelprof_add_to_buffer(buf, "\"hasGlobalFloatAtomicExch\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).hasGlobalFloatAtomicExch); \
		ratelprof_add_to_buffer(buf, "\"hasSharedInt32Atomics\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).hasSharedInt32Atomics); \
		ratelprof_add_to_buffer(buf, "\"hasSharedFloatAtomicExch\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).hasSharedFloatAtomicExch); \
		ratelprof_add_to_buffer(buf, "\"hasFloatAtomicAdd\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).hasFloatAtomicAdd); \
		ratelprof_add_to_buffer(buf, "\"hasGlobalInt64Atomics\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).hasGlobalInt64Atomics); \
		ratelprof_add_to_buffer(buf, "\"hasSharedInt64Atomics\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).hasSharedInt64Atomics); \
		ratelprof_add_to_buffer(buf, "\"hasDoubles\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).hasDoubles); \
		ratelprof_add_to_buffer(buf, "\"hasWarpVote\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).hasWarpVote); \
		ratelprof_add_to_buffer(buf, "\"hasWarpBallot\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).hasWarpBallot); \
		ratelprof_add_to_buffer(buf, "\"hasWarpShuffle\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).hasWarpShuffle); \
		ratelprof_add_to_buffer(buf, "\"hasFunnelShift\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).hasFunnelShift); \
		ratelprof_add_to_buffer(buf, "\"hasThreadFenceSystem\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).hasThreadFenceSystem); \
		ratelprof_add_to_buffer(buf, "\"hasSyncThreadsExt\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).hasSyncThreadsExt); \
		ratelprof_add_to_buffer(buf, "\"hasSurfaceFuncs\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).hasSurfaceFuncs); \
		ratelprof_add_to_buffer(buf, "\"has3dGrid\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipChooseDeviceR0600.prop).arch).has3dGrid); \
		ratelprof_add_to_buffer(buf, "\"hasDynamicParallelism\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", ((*args->hipChooseDeviceR0600.prop).arch).hasDynamicParallelism); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"hdpMemFlushCntl\":{\"type\":\"unsigned int *\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).hdpMemFlushCntl); \
		if ((*args->hipChooseDeviceR0600.prop).hdpMemFlushCntl != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*args->hipChooseDeviceR0600.prop).hdpMemFlushCntl); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"hdpRegFlushCntl\":{\"type\":\"unsigned int *\",\"value\":{\"addr\":\"%p\"", (*args->hipChooseDeviceR0600.prop).hdpRegFlushCntl); \
		if ((*args->hipChooseDeviceR0600.prop).hdpRegFlushCntl != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*args->hipChooseDeviceR0600.prop).hdpRegFlushCntl); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"cooperativeMultiDeviceUnmatchedFunc\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).cooperativeMultiDeviceUnmatchedFunc); \
		ratelprof_add_to_buffer(buf, "\"cooperativeMultiDeviceUnmatchedGridDim\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).cooperativeMultiDeviceUnmatchedGridDim); \
		ratelprof_add_to_buffer(buf, "\"cooperativeMultiDeviceUnmatchedBlockDim\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).cooperativeMultiDeviceUnmatchedBlockDim); \
		ratelprof_add_to_buffer(buf, "\"cooperativeMultiDeviceUnmatchedSharedMem\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).cooperativeMultiDeviceUnmatchedSharedMem); \
		ratelprof_add_to_buffer(buf, "\"isLargeBar\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipChooseDeviceR0600.prop).isLargeBar); \
		ratelprof_add_to_buffer(buf, "\"asicRevision\":{\"type\":\"int\",\"value\":\"%d\"}", (*args->hipChooseDeviceR0600.prop).asicRevision); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	const hipExternalSemaphore_t * extSemArray (void**);
//	struct const hipExternalSemaphoreSignalParams * paramsArray ({
//		struct (unnamed struct at ./input/hip_runtime_api.h:1136:3) params (unknown);
//		unsigned int flags (unsigned int);
//		unsigned int[16] reserved (unsigned int*);
//	});
//	unsigned int numExtSems (unsigned int);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipSignalExternalSemaphoresAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"extSemArray\":{\"type\":\"const hipExternalSemaphore_t *\",\"value\":{\"addr\":\"%p\"", args->hipSignalExternalSemaphoresAsync.extSemArray); \
	if (args->hipSignalExternalSemaphoresAsync.extSemArray != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipSignalExternalSemaphoresAsync.extSemArray); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"paramsArray\":{\"type\":\"struct const hipExternalSemaphoreSignalParams *\",\"value\":{\"addr\":\"%p\"", args->hipSignalExternalSemaphoresAsync.paramsArray); \
	if (args->hipSignalExternalSemaphoresAsync.paramsArray != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"params\":{\"type\":\"struct (unnamed struct at ./input/hip_runtime_api.h:1136:3)\",\"value\":\"NULL\"}"); \
		ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipSignalExternalSemaphoresAsync.paramsArray).flags); \
		ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned int[16]\",\"value\":{\"addr\":\"%p\"", (*args->hipSignalExternalSemaphoresAsync.paramsArray).reserved); \
		if ((*args->hipSignalExternalSemaphoresAsync.paramsArray).reserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*args->hipSignalExternalSemaphoresAsync.paramsArray).reserved); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"numExtSems\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipSignalExternalSemaphoresAsync.numExtSems); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	int * canAccessPeer (int*);
//	int deviceId (int);
//	int peerDeviceId (int);
#define PROCESS_ARGS_hipDeviceCanAccessPeer(args) { \
	ratelprof_add_to_buffer(buf, "\"canAccessPeer\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceCanAccessPeer.canAccessPeer); \
	if (args->hipDeviceCanAccessPeer.canAccessPeer != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipDeviceCanAccessPeer.canAccessPeer); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"deviceId\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceCanAccessPeer.deviceId); \
	ratelprof_add_to_buffer(buf, "\"peerDeviceId\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceCanAccessPeer.peerDeviceId); \
};

//	hipCtx_t * pctx (unknown);
//	hipDevice_t dev (int);
#define PROCESS_ARGS_hipDevicePrimaryCtxRetain(args) { \
	ratelprof_add_to_buffer(buf, "\"pctx\":{\"type\":\"hipCtx_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dev\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipDevicePrimaryCtxRetain.dev); \
};

//	hipCtx_t peerCtx (unknown);
#define PROCESS_ARGS_hipCtxDisablePeerAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"peerCtx\":{\"type\":\"hipCtx_t\",\"value\":\"NULL\"}"); \
};

//	hipStream_t stream (unknown);
//	int * priority (int*);
#define PROCESS_ARGS_hipStreamGetPriority(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"priority\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipStreamGetPriority.priority); \
	if (args->hipStreamGetPriority.priority != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipStreamGetPriority.priority); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipEvent_t * event (unknown);
#define PROCESS_ARGS_hipEventCreate(args) { \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t *\",\"value\":\"NULL\"}"); \
};


#define PROCESS_ARGS_hipGetLastError(args) { \
\
};

//	int * major (int*);
//	int * minor (int*);
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceComputeCapability(args) { \
	ratelprof_add_to_buffer(buf, "\"major\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceComputeCapability.major); \
	if (args->hipDeviceComputeCapability.major != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipDeviceComputeCapability.major); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"minor\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceComputeCapability.minor); \
	if (args->hipDeviceComputeCapability.minor != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipDeviceComputeCapability.minor); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipDeviceComputeCapability.device); \
};

//	struct hipDeviceProp_tR0600 * prop ({
//		char[256] name (char*);
//		hipUUID uuid ({
//			char[16] bytes (char*);
//		});
//		char[8] luid (char*);
//		unsigned int luidDeviceNodeMask (unsigned int);
//		int totalGlobalMem (int);
//		int sharedMemPerBlock (int);
//		int regsPerBlock (int);
//		int warpSize (int);
//		int memPitch (int);
//		int maxThreadsPerBlock (int);
//		int[3] maxThreadsDim (int*);
//		int[3] maxGridSize (int*);
//		int clockRate (int);
//		int totalConstMem (int);
//		int major (int);
//		int minor (int);
//		int textureAlignment (int);
//		int texturePitchAlignment (int);
//		int deviceOverlap (int);
//		int multiProcessorCount (int);
//		int kernelExecTimeoutEnabled (int);
//		int integrated (int);
//		int canMapHostMemory (int);
//		int computeMode (int);
//		int maxTexture1D (int);
//		int maxTexture1DMipmap (int);
//		int maxTexture1DLinear (int);
//		int[2] maxTexture2D (int*);
//		int[2] maxTexture2DMipmap (int*);
//		int[3] maxTexture2DLinear (int*);
//		int[2] maxTexture2DGather (int*);
//		int[3] maxTexture3D (int*);
//		int[3] maxTexture3DAlt (int*);
//		int maxTextureCubemap (int);
//		int[2] maxTexture1DLayered (int*);
//		int[3] maxTexture2DLayered (int*);
//		int[2] maxTextureCubemapLayered (int*);
//		int maxSurface1D (int);
//		int[2] maxSurface2D (int*);
//		int[3] maxSurface3D (int*);
//		int[2] maxSurface1DLayered (int*);
//		int[3] maxSurface2DLayered (int*);
//		int maxSurfaceCubemap (int);
//		int[2] maxSurfaceCubemapLayered (int*);
//		int surfaceAlignment (int);
//		int concurrentKernels (int);
//		int ECCEnabled (int);
//		int pciBusID (int);
//		int pciDeviceID (int);
//		int pciDomainID (int);
//		int tccDriver (int);
//		int asyncEngineCount (int);
//		int unifiedAddressing (int);
//		int memoryClockRate (int);
//		int memoryBusWidth (int);
//		int l2CacheSize (int);
//		int persistingL2CacheMaxSize (int);
//		int maxThreadsPerMultiProcessor (int);
//		int streamPrioritiesSupported (int);
//		int globalL1CacheSupported (int);
//		int localL1CacheSupported (int);
//		int sharedMemPerMultiprocessor (int);
//		int regsPerMultiprocessor (int);
//		int managedMemory (int);
//		int isMultiGpuBoard (int);
//		int multiGpuBoardGroupID (int);
//		int hostNativeAtomicSupported (int);
//		int singleToDoublePrecisionPerfRatio (int);
//		int pageableMemoryAccess (int);
//		int concurrentManagedAccess (int);
//		int computePreemptionSupported (int);
//		int canUseHostPointerForRegisteredMem (int);
//		int cooperativeLaunch (int);
//		int cooperativeMultiDeviceLaunch (int);
//		int sharedMemPerBlockOptin (int);
//		int pageableMemoryAccessUsesHostPageTables (int);
//		int directManagedMemAccessFromHost (int);
//		int maxBlocksPerMultiProcessor (int);
//		int accessPolicyMaxWindowSize (int);
//		int reservedSharedMemPerBlock (int);
//		int hostRegisterSupported (int);
//		int sparseHipArraySupported (int);
//		int hostRegisterReadOnlySupported (int);
//		int timelineSemaphoreInteropSupported (int);
//		int memoryPoolsSupported (int);
//		int gpuDirectRDMASupported (int);
//		unsigned int gpuDirectRDMAFlushWritesOptions (unsigned int);
//		int gpuDirectRDMAWritesOrdering (int);
//		unsigned int memoryPoolSupportedHandleTypes (unsigned int);
//		int deferredMappingHipArraySupported (int);
//		int ipcEventSupported (int);
//		int clusterLaunch (int);
//		int unifiedFunctionPointers (int);
//		int[63] reserved (int*);
//		int[32] hipReserved (int*);
//		char[256] gcnArchName (char*);
//		int maxSharedMemoryPerMultiProcessor (int);
//		int clockInstructionRate (int);
//		hipDeviceArch_t arch ({
//			unsigned int hasGlobalInt32Atomics (unsigned int);
//			unsigned int hasGlobalFloatAtomicExch (unsigned int);
//			unsigned int hasSharedInt32Atomics (unsigned int);
//			unsigned int hasSharedFloatAtomicExch (unsigned int);
//			unsigned int hasFloatAtomicAdd (unsigned int);
//			unsigned int hasGlobalInt64Atomics (unsigned int);
//			unsigned int hasSharedInt64Atomics (unsigned int);
//			unsigned int hasDoubles (unsigned int);
//			unsigned int hasWarpVote (unsigned int);
//			unsigned int hasWarpBallot (unsigned int);
//			unsigned int hasWarpShuffle (unsigned int);
//			unsigned int hasFunnelShift (unsigned int);
//			unsigned int hasThreadFenceSystem (unsigned int);
//			unsigned int hasSyncThreadsExt (unsigned int);
//			unsigned int hasSurfaceFuncs (unsigned int);
//			unsigned int has3dGrid (unsigned int);
//			unsigned int hasDynamicParallelism (unsigned int);
//		});
//		unsigned int * hdpMemFlushCntl (unsigned int*);
//		unsigned int * hdpRegFlushCntl (unsigned int*);
//		int cooperativeMultiDeviceUnmatchedFunc (int);
//		int cooperativeMultiDeviceUnmatchedGridDim (int);
//		int cooperativeMultiDeviceUnmatchedBlockDim (int);
//		int cooperativeMultiDeviceUnmatchedSharedMem (int);
//		int isLargeBar (int);
//		int asicRevision (int);
//	});
//	int deviceId (int);
#define PROCESS_ARGS_hipGetDevicePropertiesR0600(args) { \
	ratelprof_add_to_buffer(buf, "\"prop\":{\"type\":\"struct hipDeviceProp_tR0600 *\",\"value\":{\"addr\":\"%p\"", args->hipGetDevicePropertiesR0600.prop); \
	if (args->hipGetDevicePropertiesR0600.prop != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"name\":{\"type\":\"char[256]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).name); \
		if ((*args->hipGetDevicePropertiesR0600.prop).name != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *(*args->hipGetDevicePropertiesR0600.prop).name); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"uuid\":{\"type\":\"struct hipUUID\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"bytes\":{\"type\":\"char[16]\",\"value\":{\"addr\":\"%p\"", ((*args->hipGetDevicePropertiesR0600.prop).uuid).bytes); \
		if (((*args->hipGetDevicePropertiesR0600.prop).uuid).bytes != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *((*args->hipGetDevicePropertiesR0600.prop).uuid).bytes); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"luid\":{\"type\":\"char[8]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).luid); \
		if ((*args->hipGetDevicePropertiesR0600.prop).luid != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *(*args->hipGetDevicePropertiesR0600.prop).luid); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"luidDeviceNodeMask\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipGetDevicePropertiesR0600.prop).luidDeviceNodeMask); \
		ratelprof_add_to_buffer(buf, "\"totalGlobalMem\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).totalGlobalMem); \
		ratelprof_add_to_buffer(buf, "\"sharedMemPerBlock\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).sharedMemPerBlock); \
		ratelprof_add_to_buffer(buf, "\"regsPerBlock\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).regsPerBlock); \
		ratelprof_add_to_buffer(buf, "\"warpSize\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).warpSize); \
		ratelprof_add_to_buffer(buf, "\"memPitch\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).memPitch); \
		ratelprof_add_to_buffer(buf, "\"maxThreadsPerBlock\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).maxThreadsPerBlock); \
		ratelprof_add_to_buffer(buf, "\"maxThreadsDim\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxThreadsDim); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxThreadsDim != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxThreadsDim); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxGridSize\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxGridSize); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxGridSize != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxGridSize); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"clockRate\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).clockRate); \
		ratelprof_add_to_buffer(buf, "\"totalConstMem\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).totalConstMem); \
		ratelprof_add_to_buffer(buf, "\"major\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).major); \
		ratelprof_add_to_buffer(buf, "\"minor\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).minor); \
		ratelprof_add_to_buffer(buf, "\"textureAlignment\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).textureAlignment); \
		ratelprof_add_to_buffer(buf, "\"texturePitchAlignment\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).texturePitchAlignment); \
		ratelprof_add_to_buffer(buf, "\"deviceOverlap\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).deviceOverlap); \
		ratelprof_add_to_buffer(buf, "\"multiProcessorCount\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).multiProcessorCount); \
		ratelprof_add_to_buffer(buf, "\"kernelExecTimeoutEnabled\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).kernelExecTimeoutEnabled); \
		ratelprof_add_to_buffer(buf, "\"integrated\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).integrated); \
		ratelprof_add_to_buffer(buf, "\"canMapHostMemory\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).canMapHostMemory); \
		ratelprof_add_to_buffer(buf, "\"computeMode\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).computeMode); \
		ratelprof_add_to_buffer(buf, "\"maxTexture1D\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).maxTexture1D); \
		ratelprof_add_to_buffer(buf, "\"maxTexture1DMipmap\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).maxTexture1DMipmap); \
		ratelprof_add_to_buffer(buf, "\"maxTexture1DLinear\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).maxTexture1DLinear); \
		ratelprof_add_to_buffer(buf, "\"maxTexture2D\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxTexture2D); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture2D != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture2D); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTexture2DMipmap\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxTexture2DMipmap); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture2DMipmap != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture2DMipmap); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTexture2DLinear\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxTexture2DLinear); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture2DLinear != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture2DLinear); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTexture2DGather\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxTexture2DGather); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture2DGather != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture2DGather); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTexture3D\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxTexture3D); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture3D != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture3D); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTexture3DAlt\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxTexture3DAlt); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture3DAlt != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture3DAlt); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTextureCubemap\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).maxTextureCubemap); \
		ratelprof_add_to_buffer(buf, "\"maxTexture1DLayered\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxTexture1DLayered); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture1DLayered != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture1DLayered); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTexture2DLayered\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxTexture2DLayered); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture2DLayered != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture2DLayered); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxTextureCubemapLayered\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxTextureCubemapLayered); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTextureCubemapLayered != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxTextureCubemapLayered); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxSurface1D\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).maxSurface1D); \
		ratelprof_add_to_buffer(buf, "\"maxSurface2D\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxSurface2D); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxSurface2D != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxSurface2D); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxSurface3D\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxSurface3D); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxSurface3D != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxSurface3D); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxSurface1DLayered\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxSurface1DLayered); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxSurface1DLayered != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxSurface1DLayered); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxSurface2DLayered\":{\"type\":\"int[3]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxSurface2DLayered); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxSurface2DLayered != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxSurface2DLayered); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxSurfaceCubemap\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).maxSurfaceCubemap); \
		ratelprof_add_to_buffer(buf, "\"maxSurfaceCubemapLayered\":{\"type\":\"int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).maxSurfaceCubemapLayered); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxSurfaceCubemapLayered != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).maxSurfaceCubemapLayered); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"surfaceAlignment\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).surfaceAlignment); \
		ratelprof_add_to_buffer(buf, "\"concurrentKernels\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).concurrentKernels); \
		ratelprof_add_to_buffer(buf, "\"ECCEnabled\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).ECCEnabled); \
		ratelprof_add_to_buffer(buf, "\"pciBusID\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).pciBusID); \
		ratelprof_add_to_buffer(buf, "\"pciDeviceID\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).pciDeviceID); \
		ratelprof_add_to_buffer(buf, "\"pciDomainID\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).pciDomainID); \
		ratelprof_add_to_buffer(buf, "\"tccDriver\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).tccDriver); \
		ratelprof_add_to_buffer(buf, "\"asyncEngineCount\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).asyncEngineCount); \
		ratelprof_add_to_buffer(buf, "\"unifiedAddressing\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).unifiedAddressing); \
		ratelprof_add_to_buffer(buf, "\"memoryClockRate\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).memoryClockRate); \
		ratelprof_add_to_buffer(buf, "\"memoryBusWidth\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).memoryBusWidth); \
		ratelprof_add_to_buffer(buf, "\"l2CacheSize\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).l2CacheSize); \
		ratelprof_add_to_buffer(buf, "\"persistingL2CacheMaxSize\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).persistingL2CacheMaxSize); \
		ratelprof_add_to_buffer(buf, "\"maxThreadsPerMultiProcessor\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).maxThreadsPerMultiProcessor); \
		ratelprof_add_to_buffer(buf, "\"streamPrioritiesSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).streamPrioritiesSupported); \
		ratelprof_add_to_buffer(buf, "\"globalL1CacheSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).globalL1CacheSupported); \
		ratelprof_add_to_buffer(buf, "\"localL1CacheSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).localL1CacheSupported); \
		ratelprof_add_to_buffer(buf, "\"sharedMemPerMultiprocessor\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).sharedMemPerMultiprocessor); \
		ratelprof_add_to_buffer(buf, "\"regsPerMultiprocessor\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).regsPerMultiprocessor); \
		ratelprof_add_to_buffer(buf, "\"managedMemory\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).managedMemory); \
		ratelprof_add_to_buffer(buf, "\"isMultiGpuBoard\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).isMultiGpuBoard); \
		ratelprof_add_to_buffer(buf, "\"multiGpuBoardGroupID\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).multiGpuBoardGroupID); \
		ratelprof_add_to_buffer(buf, "\"hostNativeAtomicSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).hostNativeAtomicSupported); \
		ratelprof_add_to_buffer(buf, "\"singleToDoublePrecisionPerfRatio\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).singleToDoublePrecisionPerfRatio); \
		ratelprof_add_to_buffer(buf, "\"pageableMemoryAccess\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).pageableMemoryAccess); \
		ratelprof_add_to_buffer(buf, "\"concurrentManagedAccess\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).concurrentManagedAccess); \
		ratelprof_add_to_buffer(buf, "\"computePreemptionSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).computePreemptionSupported); \
		ratelprof_add_to_buffer(buf, "\"canUseHostPointerForRegisteredMem\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).canUseHostPointerForRegisteredMem); \
		ratelprof_add_to_buffer(buf, "\"cooperativeLaunch\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).cooperativeLaunch); \
		ratelprof_add_to_buffer(buf, "\"cooperativeMultiDeviceLaunch\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).cooperativeMultiDeviceLaunch); \
		ratelprof_add_to_buffer(buf, "\"sharedMemPerBlockOptin\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).sharedMemPerBlockOptin); \
		ratelprof_add_to_buffer(buf, "\"pageableMemoryAccessUsesHostPageTables\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).pageableMemoryAccessUsesHostPageTables); \
		ratelprof_add_to_buffer(buf, "\"directManagedMemAccessFromHost\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).directManagedMemAccessFromHost); \
		ratelprof_add_to_buffer(buf, "\"maxBlocksPerMultiProcessor\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).maxBlocksPerMultiProcessor); \
		ratelprof_add_to_buffer(buf, "\"accessPolicyMaxWindowSize\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).accessPolicyMaxWindowSize); \
		ratelprof_add_to_buffer(buf, "\"reservedSharedMemPerBlock\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).reservedSharedMemPerBlock); \
		ratelprof_add_to_buffer(buf, "\"hostRegisterSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).hostRegisterSupported); \
		ratelprof_add_to_buffer(buf, "\"sparseHipArraySupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).sparseHipArraySupported); \
		ratelprof_add_to_buffer(buf, "\"hostRegisterReadOnlySupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).hostRegisterReadOnlySupported); \
		ratelprof_add_to_buffer(buf, "\"timelineSemaphoreInteropSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).timelineSemaphoreInteropSupported); \
		ratelprof_add_to_buffer(buf, "\"memoryPoolsSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).memoryPoolsSupported); \
		ratelprof_add_to_buffer(buf, "\"gpuDirectRDMASupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).gpuDirectRDMASupported); \
		ratelprof_add_to_buffer(buf, "\"gpuDirectRDMAFlushWritesOptions\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipGetDevicePropertiesR0600.prop).gpuDirectRDMAFlushWritesOptions); \
		ratelprof_add_to_buffer(buf, "\"gpuDirectRDMAWritesOrdering\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).gpuDirectRDMAWritesOrdering); \
		ratelprof_add_to_buffer(buf, "\"memoryPoolSupportedHandleTypes\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipGetDevicePropertiesR0600.prop).memoryPoolSupportedHandleTypes); \
		ratelprof_add_to_buffer(buf, "\"deferredMappingHipArraySupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).deferredMappingHipArraySupported); \
		ratelprof_add_to_buffer(buf, "\"ipcEventSupported\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).ipcEventSupported); \
		ratelprof_add_to_buffer(buf, "\"clusterLaunch\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).clusterLaunch); \
		ratelprof_add_to_buffer(buf, "\"unifiedFunctionPointers\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).unifiedFunctionPointers); \
		ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"int[63]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).reserved); \
		if ((*args->hipGetDevicePropertiesR0600.prop).reserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).reserved); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"hipReserved\":{\"type\":\"int[32]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).hipReserved); \
		if ((*args->hipGetDevicePropertiesR0600.prop).hipReserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *(*args->hipGetDevicePropertiesR0600.prop).hipReserved); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"gcnArchName\":{\"type\":\"char[256]\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).gcnArchName); \
		if ((*args->hipGetDevicePropertiesR0600.prop).gcnArchName != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *(*args->hipGetDevicePropertiesR0600.prop).gcnArchName); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"maxSharedMemoryPerMultiProcessor\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).maxSharedMemoryPerMultiProcessor); \
		ratelprof_add_to_buffer(buf, "\"clockInstructionRate\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).clockInstructionRate); \
		ratelprof_add_to_buffer(buf, "\"arch\":{\"type\":\"struct hipDeviceArch_t\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"hasGlobalInt32Atomics\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasGlobalInt32Atomics); \
		ratelprof_add_to_buffer(buf, "\"hasGlobalFloatAtomicExch\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasGlobalFloatAtomicExch); \
		ratelprof_add_to_buffer(buf, "\"hasSharedInt32Atomics\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasSharedInt32Atomics); \
		ratelprof_add_to_buffer(buf, "\"hasSharedFloatAtomicExch\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasSharedFloatAtomicExch); \
		ratelprof_add_to_buffer(buf, "\"hasFloatAtomicAdd\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasFloatAtomicAdd); \
		ratelprof_add_to_buffer(buf, "\"hasGlobalInt64Atomics\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasGlobalInt64Atomics); \
		ratelprof_add_to_buffer(buf, "\"hasSharedInt64Atomics\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasSharedInt64Atomics); \
		ratelprof_add_to_buffer(buf, "\"hasDoubles\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasDoubles); \
		ratelprof_add_to_buffer(buf, "\"hasWarpVote\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasWarpVote); \
		ratelprof_add_to_buffer(buf, "\"hasWarpBallot\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasWarpBallot); \
		ratelprof_add_to_buffer(buf, "\"hasWarpShuffle\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasWarpShuffle); \
		ratelprof_add_to_buffer(buf, "\"hasFunnelShift\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasFunnelShift); \
		ratelprof_add_to_buffer(buf, "\"hasThreadFenceSystem\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasThreadFenceSystem); \
		ratelprof_add_to_buffer(buf, "\"hasSyncThreadsExt\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasSyncThreadsExt); \
		ratelprof_add_to_buffer(buf, "\"hasSurfaceFuncs\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasSurfaceFuncs); \
		ratelprof_add_to_buffer(buf, "\"has3dGrid\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", ((*args->hipGetDevicePropertiesR0600.prop).arch).has3dGrid); \
		ratelprof_add_to_buffer(buf, "\"hasDynamicParallelism\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasDynamicParallelism); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"hdpMemFlushCntl\":{\"type\":\"unsigned int *\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).hdpMemFlushCntl); \
		if ((*args->hipGetDevicePropertiesR0600.prop).hdpMemFlushCntl != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*args->hipGetDevicePropertiesR0600.prop).hdpMemFlushCntl); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"hdpRegFlushCntl\":{\"type\":\"unsigned int *\",\"value\":{\"addr\":\"%p\"", (*args->hipGetDevicePropertiesR0600.prop).hdpRegFlushCntl); \
		if ((*args->hipGetDevicePropertiesR0600.prop).hdpRegFlushCntl != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*args->hipGetDevicePropertiesR0600.prop).hdpRegFlushCntl); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"cooperativeMultiDeviceUnmatchedFunc\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).cooperativeMultiDeviceUnmatchedFunc); \
		ratelprof_add_to_buffer(buf, "\"cooperativeMultiDeviceUnmatchedGridDim\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).cooperativeMultiDeviceUnmatchedGridDim); \
		ratelprof_add_to_buffer(buf, "\"cooperativeMultiDeviceUnmatchedBlockDim\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).cooperativeMultiDeviceUnmatchedBlockDim); \
		ratelprof_add_to_buffer(buf, "\"cooperativeMultiDeviceUnmatchedSharedMem\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).cooperativeMultiDeviceUnmatchedSharedMem); \
		ratelprof_add_to_buffer(buf, "\"isLargeBar\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGetDevicePropertiesR0600.prop).isLargeBar); \
		ratelprof_add_to_buffer(buf, "\"asicRevision\":{\"type\":\"int\",\"value\":\"%d\"}", (*args->hipGetDevicePropertiesR0600.prop).asicRevision); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"deviceId\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipGetDevicePropertiesR0600.deviceId); \
};

//	int * gridSize (int*);
//	int * blockSize (int*);
//	const void * f (void*);
//	size_t dynSharedMemPerBlk (unsigned long);
//	int blockSizeLimit (int);
#define PROCESS_ARGS_hipOccupancyMaxPotentialBlockSize(args) { \
	ratelprof_add_to_buffer(buf, "\"gridSize\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipOccupancyMaxPotentialBlockSize.gridSize); \
	if (args->hipOccupancyMaxPotentialBlockSize.gridSize != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipOccupancyMaxPotentialBlockSize.gridSize); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"blockSize\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipOccupancyMaxPotentialBlockSize.blockSize); \
	if (args->hipOccupancyMaxPotentialBlockSize.blockSize != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipOccupancyMaxPotentialBlockSize.blockSize); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipOccupancyMaxPotentialBlockSize.f); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dynSharedMemPerBlk\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipOccupancyMaxPotentialBlockSize.dynSharedMemPerBlk); \
	ratelprof_add_to_buffer(buf, "\"blockSizeLimit\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipOccupancyMaxPotentialBlockSize.blockSizeLimit); \
};

//	size_t * offset (unsigned long*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipGetTextureAlignmentOffset(args) { \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t *\",\"value\":{\"addr\":\"%p\"", args->hipGetTextureAlignmentOffset.offset); \
	if (args->hipGetTextureAlignmentOffset.offset != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%lu\"", *args->hipGetTextureAlignmentOffset.offset); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"NULL\"}"); \
};

//	void ** devPtr (void**);
//	hipIpcMemHandle_t handle ({
//		char[64] reserved (char*);
//	});
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipIpcOpenMemHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", args->hipIpcOpenMemHandle.devPtr); \
	if (args->hipIpcOpenMemHandle.devPtr != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipIpcOpenMemHandle.devPtr); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"struct hipIpcMemHandle_t\",\"value\":{"); \
	ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"char[64]\",\"value\":{\"addr\":\"%p\"", args->hipIpcOpenMemHandle.handle.reserved); \
	if (args->hipIpcOpenMemHandle.handle.reserved != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *args->hipIpcOpenMemHandle.handle.reserved); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipIpcOpenMemHandle.flags); \
};

//	hipGraphNode_t * pNode (unknown);
//	hipGraphNode_t originalNode (unknown);
//	hipGraph_t clonedGraph (unknown);
#define PROCESS_ARGS_hipGraphNodeFindInClone(args) { \
	ratelprof_add_to_buffer(buf, "\"pNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"originalNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"clonedGraph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
};

//	hipDevice_t dev (int);
#define PROCESS_ARGS_hipDevicePrimaryCtxRelease(args) { \
	ratelprof_add_to_buffer(buf, "\"dev\":{\"type\":\"hipDevice_t\",\"value\":\"%d\"}", args->hipDevicePrimaryCtxRelease.dev); \
};

//	hipCtx_t ctx (unknown);
#define PROCESS_ARGS_hipCtxSetCurrent(args) { \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t\",\"value\":\"NULL\"}"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t node (unknown);
//	void * dst (void*);
//	const void * symbol (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParamsFromSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.count); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	hipFuncCache_t cacheConfig (enum);
#define PROCESS_ARGS_hipCtxSetCacheConfig(args) { \
	ratelprof_add_to_buffer(buf, "\"cacheConfig\":{\"type\":\"hipFuncCache_t\",\"value\":\"%d\"}", args->hipCtxSetCacheConfig.cacheConfig); \
};

//	struct hipArrayMapInfo * mapInfoList ({
//		int resourceType (int);
//		union (unnamed union at ./input/hip_runtime_api.h:1465:6) resource (unknown);
//		hipArraySparseSubresourceType subresourceType (enum);
//		union (unnamed union at ./input/hip_runtime_api.h:1470:6) subresource (unknown);
//		hipMemOperationType memOperationType (enum);
//		hipMemHandleType memHandleType (enum);
//		union (unnamed union at ./input/hip_runtime_api.h:1489:6) memHandle (unknown);
//		unsigned long long offset (unsigned long long);
//		unsigned int deviceBitMask (unsigned int);
//		unsigned int flags (unsigned int);
//		unsigned int[2] reserved (unsigned int*);
//	});
//	unsigned int count (unsigned int);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemMapArrayAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"mapInfoList\":{\"type\":\"struct hipArrayMapInfo *\",\"value\":{\"addr\":\"%p\"", args->hipMemMapArrayAsync.mapInfoList); \
	if (args->hipMemMapArrayAsync.mapInfoList != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"resourceType\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipMemMapArrayAsync.mapInfoList).resourceType); \
		ratelprof_add_to_buffer(buf, "\"resource\":{\"type\":\"union (unnamed union at ./input/hip_runtime_api.h:1465:6)\",\"value\":\"NULL\"}"); \
		ratelprof_add_to_buffer(buf, "\"subresourceType\":{\"type\":\"hipArraySparseSubresourceType\",\"value\":\"%d\"},", (*args->hipMemMapArrayAsync.mapInfoList).subresourceType); \
		ratelprof_add_to_buffer(buf, "\"subresource\":{\"type\":\"union (unnamed union at ./input/hip_runtime_api.h:1470:6)\",\"value\":\"NULL\"}"); \
		ratelprof_add_to_buffer(buf, "\"memOperationType\":{\"type\":\"hipMemOperationType\",\"value\":\"%d\"},", (*args->hipMemMapArrayAsync.mapInfoList).memOperationType); \
		ratelprof_add_to_buffer(buf, "\"memHandleType\":{\"type\":\"hipMemHandleType\",\"value\":\"%d\"},", (*args->hipMemMapArrayAsync.mapInfoList).memHandleType); \
		ratelprof_add_to_buffer(buf, "\"memHandle\":{\"type\":\"union (unnamed union at ./input/hip_runtime_api.h:1489:6)\",\"value\":\"NULL\"}"); \
		ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"unsigned long long\",\"value\":\"%llu\"},", (*args->hipMemMapArrayAsync.mapInfoList).offset); \
		ratelprof_add_to_buffer(buf, "\"deviceBitMask\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipMemMapArrayAsync.mapInfoList).deviceBitMask); \
		ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipMemMapArrayAsync.mapInfoList).flags); \
		ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned int[2]\",\"value\":{\"addr\":\"%p\"", (*args->hipMemMapArrayAsync.mapInfoList).reserved); \
		if ((*args->hipMemMapArrayAsync.mapInfoList).reserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*args->hipMemMapArrayAsync.mapInfoList).reserved); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipMemMapArrayAsync.count); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipExternalMemory_t * extMem_out (void**);
//	struct const hipExternalMemoryHandleDesc * memHandleDesc ({
//		hipExternalMemoryHandleType type (enum);
//		union (unnamed union at ./input/hip_runtime_api.h:1083:3) handle (unknown);
//		unsigned long long size (unsigned long long);
//		unsigned int flags (unsigned int);
//		unsigned int[16] reserved (unsigned int*);
//	});
#define PROCESS_ARGS_hipImportExternalMemory(args) { \
	ratelprof_add_to_buffer(buf, "\"extMem_out\":{\"type\":\"hipExternalMemory_t *\",\"value\":{\"addr\":\"%p\"", args->hipImportExternalMemory.extMem_out); \
	if (args->hipImportExternalMemory.extMem_out != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipImportExternalMemory.extMem_out); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"memHandleDesc\":{\"type\":\"struct const hipExternalMemoryHandleDesc *\",\"value\":{\"addr\":\"%p\"", args->hipImportExternalMemory.memHandleDesc); \
	if (args->hipImportExternalMemory.memHandleDesc != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipExternalMemoryHandleType\",\"value\":\"%d\"},", (*args->hipImportExternalMemory.memHandleDesc).type); \
		ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"union (unnamed union at ./input/hip_runtime_api.h:1083:3)\",\"value\":\"NULL\"}"); \
		ratelprof_add_to_buffer(buf, "\"size\":{\"type\":\"unsigned long long\",\"value\":\"%llu\"},", (*args->hipImportExternalMemory.memHandleDesc).size); \
		ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipImportExternalMemory.memHandleDesc).flags); \
		ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned int[16]\",\"value\":{\"addr\":\"%p\"", (*args->hipImportExternalMemory.memHandleDesc).reserved); \
		if ((*args->hipImportExternalMemory.memHandleDesc).reserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*args->hipImportExternalMemory.memHandleDesc).reserved); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t hNode (unknown);
//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipGraphExecEventWaitNodeSetEvent(args) { \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
};

//	hipStream_t stream (unknown);
//	hipStreamCaptureMode mode (enum);
#define PROCESS_ARGS_hipStreamBeginCapture(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"mode\":{\"type\":\"hipStreamCaptureMode\",\"value\":\"%d\"}", args->hipStreamBeginCapture.mode); \
};

//	struct hipIpcMemHandle_t * handle ({
//		char[64] reserved (char*);
//	});
//	void * devPtr (void*);
#define PROCESS_ARGS_hipIpcGetMemHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"handle\":{\"type\":\"struct hipIpcMemHandle_t *\",\"value\":{\"addr\":\"%p\"", args->hipIpcGetMemHandle.handle); \
	if (args->hipIpcGetMemHandle.handle != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"char[64]\",\"value\":{\"addr\":\"%p\"", (*args->hipIpcGetMemHandle.handle).reserved); \
		if ((*args->hipIpcGetMemHandle.handle).reserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *(*args->hipIpcGetMemHandle.handle).reserved); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipIpcGetMemHandle.devPtr); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	const hipExternalSemaphore_t * extSemArray (void**);
//	struct const hipExternalSemaphoreWaitParams * paramsArray ({
//		struct (unnamed struct at ./input/hip_runtime_api.h:1156:3) params (unknown);
//		unsigned int flags (unsigned int);
//		unsigned int[16] reserved (unsigned int*);
//	});
//	unsigned int numExtSems (unsigned int);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipWaitExternalSemaphoresAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"extSemArray\":{\"type\":\"const hipExternalSemaphore_t *\",\"value\":{\"addr\":\"%p\"", args->hipWaitExternalSemaphoresAsync.extSemArray); \
	if (args->hipWaitExternalSemaphoresAsync.extSemArray != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *args->hipWaitExternalSemaphoresAsync.extSemArray); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"paramsArray\":{\"type\":\"struct const hipExternalSemaphoreWaitParams *\",\"value\":{\"addr\":\"%p\"", args->hipWaitExternalSemaphoresAsync.paramsArray); \
	if (args->hipWaitExternalSemaphoresAsync.paramsArray != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"params\":{\"type\":\"struct (unnamed struct at ./input/hip_runtime_api.h:1156:3)\",\"value\":\"NULL\"}"); \
		ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipWaitExternalSemaphoresAsync.paramsArray).flags); \
		ratelprof_add_to_buffer(buf, "\"reserved\":{\"type\":\"unsigned int[16]\",\"value\":{\"addr\":\"%p\"", (*args->hipWaitExternalSemaphoresAsync.paramsArray).reserved); \
		if ((*args->hipWaitExternalSemaphoresAsync.paramsArray).reserved != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *(*args->hipWaitExternalSemaphoresAsync.paramsArray).reserved); \
		} \
		ratelprof_add_to_buffer(buf, "}}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"numExtSems\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipWaitExternalSemaphoresAsync.numExtSems); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	enum hipTextureFilterMode * pfm (enum);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipmapFilterMode(args) { \
	ratelprof_add_to_buffer(buf, "\"pfm\":{\"type\":\"enum hipTextureFilterMode *\",\"value\":\"%d\"},", args->hipTexRefGetMipmapFilterMode.pfm); \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"const textureReference*\",\"value\":\"NULL\"}"); \
};

//	hipMemAccessFlags * flags (enum*);
//	hipMemPool_t mem_pool (unknown);
//	struct hipMemLocation * location ({
//		hipMemLocationType type (enum);
//		int id (int);
//	});
#define PROCESS_ARGS_hipMemPoolGetAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"hipMemAccessFlags *\",\"value\":{\"addr\":\"%p\"", args->hipMemPoolGetAccess.flags); \
	if (args->hipMemPoolGetAccess.flags != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipMemPoolGetAccess.flags); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"location\":{\"type\":\"struct hipMemLocation *\",\"value\":{\"addr\":\"%p\"", args->hipMemPoolGetAccess.location); \
	if (args->hipMemPoolGetAccess.location != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"type\":{\"type\":\"hipMemLocationType\",\"value\":\"%d\"},", (*args->hipMemPoolGetAccess.location).type); \
		ratelprof_add_to_buffer(buf, "\"id\":{\"type\":\"int\",\"value\":\"%d\"}", (*args->hipMemPoolGetAccess.location).id); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphNode_t * phGraphNode (unknown);
//	hipGraph_t hGraph (unknown);
//	const hipGraphNode_t * dependencies (unknown);
//	size_t numDependencies (unsigned long);
//	struct const HIP_MEMSET_NODE_PARAMS * memsetParams ({
//		int dst (int);
//		int pitch (int);
//		unsigned int value (unsigned int);
//		unsigned int elementSize (unsigned int);
//		int width (int);
//		int height (int);
//	});
//	hipCtx_t ctx (unknown);
#define PROCESS_ARGS_hipDrvGraphAddMemsetNode(args) { \
	ratelprof_add_to_buffer(buf, "\"phGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"hGraph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"dependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipDrvGraphAddMemsetNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"memsetParams\":{\"type\":\"struct const HIP_MEMSET_NODE_PARAMS *\",\"value\":{\"addr\":\"%p\"", args->hipDrvGraphAddMemsetNode.memsetParams); \
	if (args->hipDrvGraphAddMemsetNode.memsetParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipDrvGraphAddMemsetNode.memsetParams).dst); \
		ratelprof_add_to_buffer(buf, "\"pitch\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipDrvGraphAddMemsetNode.memsetParams).pitch); \
		ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipDrvGraphAddMemsetNode.memsetParams).value); \
		ratelprof_add_to_buffer(buf, "\"elementSize\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipDrvGraphAddMemsetNode.memsetParams).elementSize); \
		ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipDrvGraphAddMemsetNode.memsetParams).width); \
		ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"int\",\"value\":\"%d\"}", (*args->hipDrvGraphAddMemsetNode.memsetParams).height); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"ctx\":{\"type\":\"hipCtx_t\",\"value\":\"NULL\"}"); \
};

//	hipPitchedPtr pitchedDevPtr (unknown);
//	int value (int);
//	hipExtent extent (unknown);
#define PROCESS_ARGS_hipMemset3D(args) { \
	ratelprof_add_to_buffer(buf, "\"pitchedDevPtr\":{\"type\":\"hipPitchedPtr\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipMemset3D.value); \
	ratelprof_add_to_buffer(buf, "\"extent\":{\"type\":\"hipExtent\",\"value\":\"NULL\"}"); \
};

//	const HIP_MEMCPY3D * pCopy (unknown);
#define PROCESS_ARGS_hipDrvMemcpy3D(args) { \
	ratelprof_add_to_buffer(buf, "\"pCopy\":{\"type\":\"const HIP_MEMCPY3D *\",\"value\":\"NULL\"}"); \
};

//	void * dst (void*);
//	size_t dpitch (unsigned long);
//	hipArray_const_t src (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpy2DFromArrayAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpy2DFromArrayAsync.dst); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"dpitch\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArrayAsync.dpitch); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"hipArray_const_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"wOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArrayAsync.wOffset); \
	ratelprof_add_to_buffer(buf, "\"hOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArrayAsync.hOffset); \
	ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArrayAsync.width); \
	ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpy2DFromArrayAsync.height); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	struct hipLaunchParams * launchParamsList ({
//		void * func (void*);
//		dim3 gridDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		dim3 blockDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		void ** args (void**);
//		int sharedMem (int);
//		hipStream_t stream (unknown);
//	});
//	int numDevices (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipExtLaunchMultiKernelMultiDevice(args) { \
	ratelprof_add_to_buffer(buf, "\"launchParamsList\":{\"type\":\"struct hipLaunchParams *\",\"value\":{\"addr\":\"%p\"", args->hipExtLaunchMultiKernelMultiDevice.launchParamsList); \
	if (args->hipExtLaunchMultiKernelMultiDevice.launchParamsList != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).func); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"gridDim\":{\"type\":\"struct dim3\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).gridDim).x); \
		ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).gridDim).y); \
		ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", ((*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).gridDim).z); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"blockDim\":{\"type\":\"struct dim3\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).blockDim).x); \
		ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).blockDim).y); \
		ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", ((*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).blockDim).z); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"args\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", (*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).args); \
		if ((*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).args != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).args); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"sharedMem\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).sharedMem); \
		ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"numDevices\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipExtLaunchMultiKernelMultiDevice.numDevices); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipExtLaunchMultiKernelMultiDevice.flags); \
};

//	hipStream_t stream (unknown);
//	void * ptr (void*);
//	uint64_t value (unsigned long);
//	unsigned int flags (unsigned int);
//	uint64_t mask (unsigned long);
#define PROCESS_ARGS_hipStreamWaitValue64(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"ptr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipStreamWaitValue64.ptr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"uint64_t\",\"value\":\"%lu\"},", args->hipStreamWaitValue64.value); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipStreamWaitValue64.flags); \
	ratelprof_add_to_buffer(buf, "\"mask\":{\"type\":\"uint64_t\",\"value\":\"%lu\"}", args->hipStreamWaitValue64.mask); \
};

//	textureReference** texRef (unknown);
//	hipModule_t hmod (unknown);
//	const char * name (char*);
#define PROCESS_ARGS_hipModuleGetTexRef(args) { \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference**\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"hmod\":{\"type\":\"hipModule_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"name\":{\"type\":\"const char *\",\"value\":{\"addr\":\"%p\"", args->hipModuleGetTexRef.name); \
	if (args->hipModuleGetTexRef.name != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%c\"", *args->hipModuleGetTexRef.name); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipDeviceptr_t dst (unknown);
//	hipDeviceptr_t src (unknown);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyDtoDAsync(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"hipDeviceptr_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"sizeBytes\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyDtoDAsync.sizeBytes); \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	HIP_RESOURCE_VIEW_DESC * pResViewDesc (unknown);
//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectGetResourceViewDesc(args) { \
	ratelprof_add_to_buffer(buf, "\"pResViewDesc\":{\"type\":\"HIP_RESOURCE_VIEW_DESC *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"texObject\":{\"type\":\"hipTextureObject_t\",\"value\":\"NULL\"}"); \
};

//	hipStream_t stream (unknown);
//	hipStreamCallback_t callback (void*);
//	void * userData (void*);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamAddCallback(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"callback\":{\"type\":\"hipStreamCallback_t\",\"value\":{\"addr\":\"%p\"", args->hipStreamAddCallback.callback); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"userData\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipStreamAddCallback.userData); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipStreamAddCallback.flags); \
};

//	textureReference* texRef (unknown);
//	hipArray_Format fmt (unknown);
//	int NumPackedComponents (int);
#define PROCESS_ARGS_hipTexRefSetFormat(args) { \
	ratelprof_add_to_buffer(buf, "\"texRef\":{\"type\":\"textureReference*\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"fmt\":{\"type\":\"hipArray_Format\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"NumPackedComponents\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipTexRefSetFormat.NumPackedComponents); \
};

//	struct struct hipFuncAttributes * attr ({
//		int binaryVersion (int);
//		int cacheModeCA (int);
//		int constSizeBytes (int);
//		int localSizeBytes (int);
//		int maxDynamicSharedSizeBytes (int);
//		int maxThreadsPerBlock (int);
//		int numRegs (int);
//		int preferredShmemCarveout (int);
//		int ptxVersion (int);
//		int sharedSizeBytes (int);
//	});
//	const void * func (void*);
#define PROCESS_ARGS_hipFuncGetAttributes(args) { \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"struct struct hipFuncAttributes *\",\"value\":{\"addr\":\"%p\"", args->hipFuncGetAttributes.attr); \
	if (args->hipFuncGetAttributes.attr != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"binaryVersion\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipFuncGetAttributes.attr).binaryVersion); \
		ratelprof_add_to_buffer(buf, "\"cacheModeCA\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipFuncGetAttributes.attr).cacheModeCA); \
		ratelprof_add_to_buffer(buf, "\"constSizeBytes\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipFuncGetAttributes.attr).constSizeBytes); \
		ratelprof_add_to_buffer(buf, "\"localSizeBytes\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipFuncGetAttributes.attr).localSizeBytes); \
		ratelprof_add_to_buffer(buf, "\"maxDynamicSharedSizeBytes\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipFuncGetAttributes.attr).maxDynamicSharedSizeBytes); \
		ratelprof_add_to_buffer(buf, "\"maxThreadsPerBlock\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipFuncGetAttributes.attr).maxThreadsPerBlock); \
		ratelprof_add_to_buffer(buf, "\"numRegs\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipFuncGetAttributes.attr).numRegs); \
		ratelprof_add_to_buffer(buf, "\"preferredShmemCarveout\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipFuncGetAttributes.attr).preferredShmemCarveout); \
		ratelprof_add_to_buffer(buf, "\"ptxVersion\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipFuncGetAttributes.attr).ptxVersion); \
		ratelprof_add_to_buffer(buf, "\"sharedSizeBytes\":{\"type\":\"int\",\"value\":\"%d\"}", (*args->hipFuncGetAttributes.attr).sharedSizeBytes); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipFuncGetAttributes.func); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipStream_t * stream (unknown);
//	unsigned int flags (unsigned int);
//	int priority (int);
#define PROCESS_ARGS_hipStreamCreateWithPriority(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", args->hipStreamCreateWithPriority.flags); \
	ratelprof_add_to_buffer(buf, "\"priority\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipStreamCreateWithPriority.priority); \
};

//	const textureReference** texref (unknown);
//	const void * symbol (void*);
#define PROCESS_ARGS_hipGetTextureReference(args) { \
	ratelprof_add_to_buffer(buf, "\"texref\":{\"type\":\"const textureReference**\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipGetTextureReference.symbol); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	struct const hipKernelNodeParams * pNodeParams ({
//		dim3 blockDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		void ** extra (void**);
//		void * func (void*);
//		dim3 gridDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		void ** kernelParams (void**);
//		unsigned int sharedMemBytes (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphAddKernelNode(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddKernelNode.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"struct const hipKernelNodeParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphAddKernelNode.pNodeParams); \
	if (args->hipGraphAddKernelNode.pNodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"blockDim\":{\"type\":\"struct dim3\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphAddKernelNode.pNodeParams).blockDim).x); \
		ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphAddKernelNode.pNodeParams).blockDim).y); \
		ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", ((*args->hipGraphAddKernelNode.pNodeParams).blockDim).z); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"extra\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphAddKernelNode.pNodeParams).extra); \
		if ((*args->hipGraphAddKernelNode.pNodeParams).extra != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphAddKernelNode.pNodeParams).extra); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"func\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphAddKernelNode.pNodeParams).func); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"gridDim\":{\"type\":\"struct dim3\",\"value\":{"); \
		ratelprof_add_to_buffer(buf, "\"x\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphAddKernelNode.pNodeParams).gridDim).x); \
		ratelprof_add_to_buffer(buf, "\"y\":{\"type\":\"uint32_t\",\"value\":\"%u\"},", ((*args->hipGraphAddKernelNode.pNodeParams).gridDim).y); \
		ratelprof_add_to_buffer(buf, "\"z\":{\"type\":\"uint32_t\",\"value\":\"%u\"}", ((*args->hipGraphAddKernelNode.pNodeParams).gridDim).z); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"kernelParams\":{\"type\":\"void **\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphAddKernelNode.pNodeParams).kernelParams); \
		if ((*args->hipGraphAddKernelNode.pNodeParams).kernelParams != NULL) { \
			ratelprof_add_to_buffer(buf, ",\"->*\":\"%p\"", *(*args->hipGraphAddKernelNode.pNodeParams).kernelParams); \
		} \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"sharedMemBytes\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", (*args->hipGraphAddKernelNode.pNodeParams).sharedMemBytes); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipArray_t dst (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	const void * src (void*);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpyToArray(args) { \
	ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"hipArray_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"wOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyToArray.wOffset); \
	ratelprof_add_to_buffer(buf, "\"hOffset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyToArray.hOffset); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemcpyToArray.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemcpyToArray.count); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	void * devPtr (void*);
#define PROCESS_ARGS_hipIpcCloseMemHandle(args) { \
	ratelprof_add_to_buffer(buf, "\"devPtr\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", args->hipIpcCloseMemHandle.devPtr); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipGraph_t graph (unknown);
#define PROCESS_ARGS_hipGraphDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
};

//	const void * dev_ptr (void*);
//	size_t count (unsigned long);
//	hipMemoryAdvise advice (enum);
//	int device (int);
#define PROCESS_ARGS_hipMemAdvise(args) { \
	ratelprof_add_to_buffer(buf, "\"dev_ptr\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipMemAdvise.dev_ptr); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipMemAdvise.count); \
	ratelprof_add_to_buffer(buf, "\"advice\":{\"type\":\"hipMemoryAdvise\",\"value\":\"%d\"},", args->hipMemAdvise.advice); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipMemAdvise.device); \
};

//	hipGraphNode_t node (unknown);
#define PROCESS_ARGS_hipGraphDestroyNode(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
};

//	int * value (int*);
//	hipFunction_attribute attrib (unknown);
//	hipFunction_t hfunc (unknown);
#define PROCESS_ARGS_hipFuncGetAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipFuncGetAttribute.value); \
	if (args->hipFuncGetAttribute.value != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipFuncGetAttribute.value); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attrib\":{\"type\":\"hipFunction_attribute\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"hfunc\":{\"type\":\"hipFunction_t\",\"value\":\"NULL\"}"); \
};

//	hipCtx_t peerCtx (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipCtxEnablePeerAccess(args) { \
	ratelprof_add_to_buffer(buf, "\"peerCtx\":{\"type\":\"hipCtx_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipCtxEnablePeerAccess.flags); \
};

//	int * numBlocks (int*);
//	hipFunction_t f (unknown);
//	int blockSize (int);
//	size_t dynSharedMemPerBlk (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(args) { \
	ratelprof_add_to_buffer(buf, "\"numBlocks\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks); \
	if (args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"f\":{\"type\":\"hipFunction_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"blockSize\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.blockSize); \
	ratelprof_add_to_buffer(buf, "\"dynSharedMemPerBlk\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.dynSharedMemPerBlk); \
	ratelprof_add_to_buffer(buf, "\"flags\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.flags); \
};


#define PROCESS_ARGS_hipCtxSynchronize(args) { \
\
};

//	hipExternalMemory_t extMem (void*);
#define PROCESS_ARGS_hipDestroyExternalMemory(args) { \
	ratelprof_add_to_buffer(buf, "\"extMem\":{\"type\":\"hipExternalMemory_t\",\"value\":{\"addr\":\"%p\"", args->hipDestroyExternalMemory.extMem); \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipStreamDestroy(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	const void * symbol (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphAddMemcpyNodeToSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"pGraphNode\":{\"type\":\"hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"graph\":{\"type\":\"hipGraph_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pDependencies\":{\"type\":\"const hipGraphNode_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"numDependencies\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNodeToSymbol.numDependencies); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphAddMemcpyNodeToSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphAddMemcpyNodeToSymbol.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNodeToSymbol.count); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphAddMemcpyNodeToSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	hipGraphNode_t node (unknown);
//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipGraphEventRecordNodeSetEvent(args) { \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"event\":{\"type\":\"hipEvent_t\",\"value\":\"NULL\"}"); \
};

//	int * value (int*);
//	hipDeviceP2PAttr attr (enum);
//	int srcDevice (int);
//	int dstDevice (int);
#define PROCESS_ARGS_hipDeviceGetP2PAttribute(args) { \
	ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"int *\",\"value\":{\"addr\":\"%p\"", args->hipDeviceGetP2PAttribute.value); \
	if (args->hipDeviceGetP2PAttribute.value != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%d\"", *args->hipDeviceGetP2PAttribute.value); \
	} \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"attr\":{\"type\":\"hipDeviceP2PAttr\",\"value\":\"%d\"},", args->hipDeviceGetP2PAttribute.attr); \
	ratelprof_add_to_buffer(buf, "\"srcDevice\":{\"type\":\"int\",\"value\":\"%d\"},", args->hipDeviceGetP2PAttribute.srcDevice); \
	ratelprof_add_to_buffer(buf, "\"dstDevice\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceGetP2PAttribute.dstDevice); \
};

//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipGetStreamDeviceId(args) { \
	ratelprof_add_to_buffer(buf, "\"stream\":{\"type\":\"hipStream_t\",\"value\":\"NULL\"}"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t hNode (unknown);
//	unsigned int * isEnabled (unsigned int*);
#define PROCESS_ARGS_hipGraphNodeGetEnabled(args) { \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"hNode\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"isEnabled\":{\"type\":\"unsigned int *\",\"value\":{\"addr\":\"%p\"", args->hipGraphNodeGetEnabled.isEnabled); \
	if (args->hipGraphNodeGetEnabled.isEnabled != NULL) { \
		ratelprof_add_to_buffer(buf, ",\"->*\":\"%u\"", *args->hipGraphNodeGetEnabled.isEnabled); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

//	hipMemPool_t * mem_pool (unknown);
//	int device (int);
#define PROCESS_ARGS_hipDeviceGetMemPool(args) { \
	ratelprof_add_to_buffer(buf, "\"mem_pool\":{\"type\":\"hipMemPool_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"device\":{\"type\":\"int\",\"value\":\"%d\"}", args->hipDeviceGetMemPool.device); \
};

//	hipArray_t * pLevelArray (unknown);
//	hipMipmappedArray_t hMipMappedArray (unknown);
//	unsigned int level (unsigned int);
#define PROCESS_ARGS_hipMipmappedArrayGetLevel(args) { \
	ratelprof_add_to_buffer(buf, "\"pLevelArray\":{\"type\":\"hipArray_t *\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"hMipMappedArray\":{\"type\":\"hipMipmappedArray_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"level\":{\"type\":\"unsigned int\",\"value\":\"%u\"}", args->hipMipmappedArrayGetLevel.level); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t node (unknown);
//	const void * symbol (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParamsToSymbol(args) { \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"symbol\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExecMemcpyNodeSetParamsToSymbol.symbol); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"src\":{\"type\":\"const void *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExecMemcpyNodeSetParamsToSymbol.src); \
	ratelprof_add_to_buffer(buf, "}},"); \
	ratelprof_add_to_buffer(buf, "\"count\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphExecMemcpyNodeSetParamsToSymbol.count); \
	ratelprof_add_to_buffer(buf, "\"offset\":{\"type\":\"size_t\",\"value\":\"%lu\"},", args->hipGraphExecMemcpyNodeSetParamsToSymbol.offset); \
	ratelprof_add_to_buffer(buf, "\"kind\":{\"type\":\"hipMemcpyKind\",\"value\":\"NULL\"}"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t node (unknown);
//	struct const hipMemsetParams * pNodeParams ({
//		void * dst (void*);
//		unsigned int elementSize (unsigned int);
//		int height (int);
//		int pitch (int);
//		unsigned int value (unsigned int);
//		int width (int);
//	});
#define PROCESS_ARGS_hipGraphExecMemsetNodeSetParams(args) { \
	ratelprof_add_to_buffer(buf, "\"hGraphExec\":{\"type\":\"hipGraphExec_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"node\":{\"type\":\"hipGraphNode_t\",\"value\":\"NULL\"}"); \
	ratelprof_add_to_buffer(buf, "\"pNodeParams\":{\"type\":\"struct const hipMemsetParams *\",\"value\":{\"addr\":\"%p\"", args->hipGraphExecMemsetNodeSetParams.pNodeParams); \
	if (args->hipGraphExecMemsetNodeSetParams.pNodeParams != NULL) { \
		ratelprof_add_to_buffer(buf, ", \"->*\":{"); \
		ratelprof_add_to_buffer(buf, "\"dst\":{\"type\":\"void *\",\"value\":{\"addr\":\"%p\"", (*args->hipGraphExecMemsetNodeSetParams.pNodeParams).dst); \
		ratelprof_add_to_buffer(buf, "}},"); \
		ratelprof_add_to_buffer(buf, "\"elementSize\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipGraphExecMemsetNodeSetParams.pNodeParams).elementSize); \
		ratelprof_add_to_buffer(buf, "\"height\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGraphExecMemsetNodeSetParams.pNodeParams).height); \
		ratelprof_add_to_buffer(buf, "\"pitch\":{\"type\":\"int\",\"value\":\"%d\"},", (*args->hipGraphExecMemsetNodeSetParams.pNodeParams).pitch); \
		ratelprof_add_to_buffer(buf, "\"value\":{\"type\":\"unsigned int\",\"value\":\"%u\"},", (*args->hipGraphExecMemsetNodeSetParams.pNodeParams).value); \
		ratelprof_add_to_buffer(buf, "\"width\":{\"type\":\"int\",\"value\":\"%d\"}", (*args->hipGraphExecMemsetNodeSetParams.pNodeParams).width); \
		ratelprof_add_to_buffer(buf, "}"); \
	} \
	ratelprof_add_to_buffer(buf, "}}"); \
};

#endif // HIP_PLUGIN_H