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
	printf("\thipError_t retval = %d\n", args->hipTexRefSetMipmapFilterMode.retval); \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tenum hipTextureFilterMode fm = %d\n", args->hipTexRefSetMipmapFilterMode.fm); \
};

//	hipArray_t dstArray (unknown);
//	size_t dstOffset (unsigned long);
//	const void * srcHost (void*);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemcpyHtoA(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyHtoA.retval); \
	printf("\thipArray_t dstArray = N/A, try to update csv files\n"); \
	printf("\tsize_t dstOffset = %lu\n", args->hipMemcpyHtoA.dstOffset); \
	printf("\tconst void * srcHost = %p", args->hipMemcpyHtoA.srcHost); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipMemcpyHtoA.count); \
};

//	hipCtx_t ctx (opaque);
//	int * apiVersion (int*);
#define PROCESS_ARGS_hipCtxGetApiVersion(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxGetApiVersion.retval); \
	printf("\thipCtx_t ctx = %p\n", args->hipCtxGetApiVersion.ctx); \
	printf("\tint * apiVersion = %p", args->hipCtxGetApiVersion.apiVersion); \
	if (args->hipCtxGetApiVersion.apiVersion != NULL) { \
		printf(" -> %d\n", args->hipCtxGetApiVersion.apiVersion__ref.val); \
	} else { printf("\n"); }; \
};

//	char * name (string*);
//	int len (int);
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceGetName(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceGetName.retval); \
	printf("\tchar * name = %p", args->hipDeviceGetName.name); \
	if (args->hipDeviceGetName.name != NULL) { \
		printf(" -> %s\n", args->hipDeviceGetName.name__ref.val); \
	} else { printf("\n"); }; \
	printf("\tint len = %d\n", args->hipDeviceGetName.len); \
	printf("\thipDevice_t device = %d\n", args->hipDeviceGetName.device); \
};

//	hipStream_t stream (opaque);
//	hipStreamCaptureStatus * pCaptureStatus (enum*);
#define PROCESS_ARGS_hipStreamIsCapturing(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamIsCapturing.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamIsCapturing.stream); \
	printf("\thipStreamCaptureStatus * pCaptureStatus = %p", args->hipStreamIsCapturing.pCaptureStatus); \
	if (args->hipStreamIsCapturing.pCaptureStatus != NULL) { \
		printf(" -> %d\n", args->hipStreamIsCapturing.pCaptureStatus__ref.val); \
	} else { printf("\n"); }; \
};

//	hipStream_t stream (opaque);
//	void * dev_ptr (void*);
//	size_t length (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamAttachMemAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamAttachMemAsync.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamAttachMemAsync.stream); \
	printf("\tvoid * dev_ptr = %p", args->hipStreamAttachMemAsync.dev_ptr); \
	printf("\n"); \
	printf("\tsize_t length = %lu\n", args->hipStreamAttachMemAsync.length); \
	printf("\tunsigned int flags = %u\n", args->hipStreamAttachMemAsync.flags); \
};

//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipFreeArray(args) { \
	printf("\thipError_t retval = %d\n", args->hipFreeArray.retval); \
	printf("\thipArray_t array = N/A, try to update csv files\n"); \
};

//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipSetDeviceFlags(args) { \
	printf("\thipError_t retval = %d\n", args->hipSetDeviceFlags.retval); \
	printf("\tunsigned int flags = %u\n", args->hipSetDeviceFlags.flags); \
};

//	hipEvent_t * event (opaque*);
//	hipIpcEventHandle_t handle ({
//		char[64] reserved (string);
//	});
#define PROCESS_ARGS_hipIpcOpenEventHandle(args) { \
	printf("\thipError_t retval = %d\n", args->hipIpcOpenEventHandle.retval); \
	printf("\thipEvent_t * event = %p", args->hipIpcOpenEventHandle.event); \
	if (args->hipIpcOpenEventHandle.event != NULL) { \
		printf(" -> %p\n", args->hipIpcOpenEventHandle.event__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipIpcEventHandle_t handle = {\n"); \
	printf("\t\tchar[64] reserved = %s\n", args->hipIpcOpenEventHandle.handle.reserved[0]); \
	printf("\t}\n"); \
};

//	hipModule_t * module (opaque*);
//	const char * fname (string*);
#define PROCESS_ARGS_hipModuleLoad(args) { \
	printf("\thipError_t retval = %d\n", args->hipModuleLoad.retval); \
	printf("\thipModule_t * module = %p", args->hipModuleLoad.module); \
	if (args->hipModuleLoad.module != NULL) { \
		printf(" -> %p\n", args->hipModuleLoad.module__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst char * fname = %p", args->hipModuleLoad.fname); \
	if (args->hipModuleLoad.fname != NULL) { \
		printf(" -> %s\n", args->hipModuleLoad.fname__ref.val); \
	} else { printf("\n"); }; \
};

//	void ** devPtr (void**);
//	hipExternalMemory_t extMem (void*);
//	const hipExternalMemoryBufferDesc * bufferDesc ({
//		unsigned long long offset (unsigned long long);
//		unsigned long long size (unsigned long long);
//		unsigned int flags (unsigned int);
//		unsigned int[16] reserved (unsigned int);
//	});
#define PROCESS_ARGS_hipExternalMemoryGetMappedBuffer(args) { \
	printf("\thipError_t retval = %d\n", args->hipExternalMemoryGetMappedBuffer.retval); \
	printf("\tvoid ** devPtr = %p", args->hipExternalMemoryGetMappedBuffer.devPtr); \
	if (args->hipExternalMemoryGetMappedBuffer.devPtr != NULL) { \
		printf("-> %p", args->hipExternalMemoryGetMappedBuffer.devPtr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\thipExternalMemory_t extMem = %p", args->hipExternalMemoryGetMappedBuffer.extMem); \
	printf("\n"); \
	printf("\tconst hipExternalMemoryBufferDesc * bufferDesc = %p", args->hipExternalMemoryGetMappedBuffer.bufferDesc); \
	if (args->hipExternalMemoryGetMappedBuffer.bufferDesc != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned long long offset = %llu\n", args->hipExternalMemoryGetMappedBuffer.bufferDesc__ref.val.offset); \
		printf("\t\tunsigned long long size = %llu\n", args->hipExternalMemoryGetMappedBuffer.bufferDesc__ref.val.size); \
		printf("\t\tunsigned int flags = %u\n", args->hipExternalMemoryGetMappedBuffer.bufferDesc__ref.val.flags); \
		printf("\t\tunsigned int[16] reserved = %u\n", args->hipExternalMemoryGetMappedBuffer.bufferDesc__ref.val.reserved[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipMemGenericAllocationHandle_t * handle (opaque*);
//	void * osHandle (void*);
//	hipMemAllocationHandleType shHandleType (enum);
#define PROCESS_ARGS_hipMemImportFromShareableHandle(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemImportFromShareableHandle.retval); \
	printf("\thipMemGenericAllocationHandle_t * handle = %p", args->hipMemImportFromShareableHandle.handle); \
	if (args->hipMemImportFromShareableHandle.handle != NULL) { \
		printf(" -> %p\n", args->hipMemImportFromShareableHandle.handle__ref.val); \
	} else { printf("\n"); }; \
	printf("\tvoid * osHandle = %p", args->hipMemImportFromShareableHandle.osHandle); \
	printf("\n"); \
	printf("\thipMemAllocationHandleType shHandleType = %d\n", args->hipMemImportFromShareableHandle.shHandleType); \
};

//	void * dst (void*);
//	hipDeviceptr_t src (void*);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemcpyDtoH(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyDtoH.retval); \
	printf("\tvoid * dst = %p", args->hipMemcpyDtoH.dst); \
	printf("\n"); \
	printf("\thipDeviceptr_t src = %p", args->hipMemcpyDtoH.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyDtoH.sizeBytes); \
};

//	hipStream_t stream (opaque);
//	hipGraph_t * pGraph (opaque*);
#define PROCESS_ARGS_hipStreamEndCapture(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamEndCapture.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamEndCapture.stream); \
	printf("\thipGraph_t * pGraph = %p", args->hipStreamEndCapture.pGraph); \
	if (args->hipStreamEndCapture.pGraph != NULL) { \
		printf(" -> %p\n", args->hipStreamEndCapture.pGraph__ref.val); \
	} else { printf("\n"); }; \
};

//	hipGraphNode_t node (opaque);
//	void * dev_ptr (void*);
#define PROCESS_ARGS_hipGraphMemFreeNodeGetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphMemFreeNodeGetParams.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphMemFreeNodeGetParams.node); \
	printf("\tvoid * dev_ptr = %p", args->hipGraphMemFreeNodeGetParams.dev_ptr); \
	printf("\n"); \
};

//	hipStreamCaptureMode * mode (enum*);
#define PROCESS_ARGS_hipThreadExchangeStreamCaptureMode(args) { \
	printf("\thipError_t retval = %d\n", args->hipThreadExchangeStreamCaptureMode.retval); \
	printf("\thipStreamCaptureMode * mode = %p", args->hipThreadExchangeStreamCaptureMode.mode); \
	if (args->hipThreadExchangeStreamCaptureMode.mode != NULL) { \
		printf(" -> %d\n", args->hipThreadExchangeStreamCaptureMode.mode__ref.val); \
	} else { printf("\n"); }; \
};

//	hipModule_t module (opaque);
#define PROCESS_ARGS_hipModuleUnload(args) { \
	printf("\thipError_t retval = %d\n", args->hipModuleUnload.retval); \
	printf("\thipModule_t module = %p\n", args->hipModuleUnload.module); \
};

//	int * gridSize (int*);
//	int * blockSize (int*);
//	hipFunction_t f (opaque);
//	size_t dynSharedMemPerBlk (unsigned long);
//	int blockSizeLimit (int);
#define PROCESS_ARGS_hipModuleOccupancyMaxPotentialBlockSize(args) { \
	printf("\thipError_t retval = %d\n", args->hipModuleOccupancyMaxPotentialBlockSize.retval); \
	printf("\tint * gridSize = %p", args->hipModuleOccupancyMaxPotentialBlockSize.gridSize); \
	if (args->hipModuleOccupancyMaxPotentialBlockSize.gridSize != NULL) { \
		printf(" -> %d\n", args->hipModuleOccupancyMaxPotentialBlockSize.gridSize__ref.val); \
	} else { printf("\n"); }; \
	printf("\tint * blockSize = %p", args->hipModuleOccupancyMaxPotentialBlockSize.blockSize); \
	if (args->hipModuleOccupancyMaxPotentialBlockSize.blockSize != NULL) { \
		printf(" -> %d\n", args->hipModuleOccupancyMaxPotentialBlockSize.blockSize__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipFunction_t f = %p\n", args->hipModuleOccupancyMaxPotentialBlockSize.f); \
	printf("\tsize_t dynSharedMemPerBlk = %lu\n", args->hipModuleOccupancyMaxPotentialBlockSize.dynSharedMemPerBlk); \
	printf("\tint blockSizeLimit = %d\n", args->hipModuleOccupancyMaxPotentialBlockSize.blockSizeLimit); \
};

//	const hip_Memcpy2D * pCopy (unknown);
#define PROCESS_ARGS_hipMemcpyParam2D(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyParam2D.retval); \
	printf("\tconst hip_Memcpy2D * pCopy = N/A, try to update csv files\n"); \
};


#define PROCESS_ARGS_hipPeekAtLastError(args) { \
	printf("\thipError_t retval = %d\n", args->hipPeekAtLastError.retval); \
\
};

//	hipMemGenericAllocationHandle_t handle (opaque);
#define PROCESS_ARGS_hipMemRelease(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemRelease.retval); \
	printf("\thipMemGenericAllocationHandle_t handle = %p\n", args->hipMemRelease.handle); \
};

//	hipSharedMemConfig * pConfig (enum*);
#define PROCESS_ARGS_hipDeviceGetSharedMemConfig(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceGetSharedMemConfig.retval); \
	printf("\thipSharedMemConfig * pConfig = %p", args->hipDeviceGetSharedMemConfig.pConfig); \
	if (args->hipDeviceGetSharedMemConfig.pConfig != NULL) { \
		printf(" -> %d\n", args->hipDeviceGetSharedMemConfig.pConfig__ref.val); \
	} else { printf("\n"); }; \
};

//	hipUserObject_t object (opaque);
//	unsigned int count (unsigned int);
#define PROCESS_ARGS_hipUserObjectRelease(args) { \
	printf("\thipError_t retval = %d\n", args->hipUserObjectRelease.retval); \
	printf("\thipUserObject_t object = %p\n", args->hipUserObjectRelease.object); \
	printf("\tunsigned int count = %u\n", args->hipUserObjectRelease.count); \
};

//	hipStream_t stream (opaque);
//	void * ptr (void*);
//	uint32_t value (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamWriteValue32(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamWriteValue32.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamWriteValue32.stream); \
	printf("\tvoid * ptr = %p", args->hipStreamWriteValue32.ptr); \
	printf("\n"); \
	printf("\tuint32_t value = %u\n", args->hipStreamWriteValue32.value); \
	printf("\tunsigned int flags = %u\n", args->hipStreamWriteValue32.flags); \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMemAllocHost(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemAllocHost.retval); \
	printf("\tvoid ** ptr = %p", args->hipMemAllocHost.ptr); \
	if (args->hipMemAllocHost.ptr != NULL) { \
		printf("-> %p", args->hipMemAllocHost.ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipMemAllocHost.size); \
};

//	hipGraph_t * pGraph (opaque*);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipGraphCreate(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphCreate.retval); \
	printf("\thipGraph_t * pGraph = %p", args->hipGraphCreate.pGraph); \
	if (args->hipGraphCreate.pGraph != NULL) { \
		printf(" -> %p\n", args->hipGraphCreate.pGraph__ref.val); \
	} else { printf("\n"); }; \
	printf("\tunsigned int flags = %u\n", args->hipGraphCreate.flags); \
};

//	int * gridSize (int*);
//	int * blockSize (int*);
//	hipFunction_t f (opaque);
//	size_t dynSharedMemPerBlk (unsigned long);
//	int blockSizeLimit (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipModuleOccupancyMaxPotentialBlockSizeWithFlags(args) { \
	printf("\thipError_t retval = %d\n", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.retval); \
	printf("\tint * gridSize = %p", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.gridSize); \
	if (args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.gridSize != NULL) { \
		printf(" -> %d\n", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.gridSize__ref.val); \
	} else { printf("\n"); }; \
	printf("\tint * blockSize = %p", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSize); \
	if (args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSize != NULL) { \
		printf(" -> %d\n", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSize__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipFunction_t f = %p\n", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.f); \
	printf("\tsize_t dynSharedMemPerBlk = %lu\n", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.dynSharedMemPerBlk); \
	printf("\tint blockSizeLimit = %d\n", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSizeLimit); \
	printf("\tunsigned int flags = %u\n", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.flags); \
};

//	hipArray_t * array (unknown);
//	const struct hipChannelFormatDesc * desc (unknown);
//	struct hipExtent extent (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMalloc3DArray(args) { \
	printf("\thipError_t retval = %d\n", args->hipMalloc3DArray.retval); \
	printf("\thipArray_t * array = N/A, try to update csv files\n"); \
	printf("\tconst struct hipChannelFormatDesc * desc = N/A, try to update csv files\n"); \
	printf("\tstruct hipExtent extent = N/A, try to update csv files\n"); \
	printf("\tunsigned int flags = %u\n", args->hipMalloc3DArray.flags); \
};

//	hipFuncCache_t * cacheConfig (enum*);
#define PROCESS_ARGS_hipCtxGetCacheConfig(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxGetCacheConfig.retval); \
	printf("\thipFuncCache_t * cacheConfig = %p", args->hipCtxGetCacheConfig.cacheConfig); \
	if (args->hipCtxGetCacheConfig.cacheConfig != NULL) { \
		printf(" -> %d\n", args->hipCtxGetCacheConfig.cacheConfig__ref.val); \
	} else { printf("\n"); }; \
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
//	void ** kernelParams (void**);
#define PROCESS_ARGS_hipModuleLaunchCooperativeKernel(args) { \
	printf("\thipError_t retval = %d\n", args->hipModuleLaunchCooperativeKernel.retval); \
	printf("\thipFunction_t f = %p\n", args->hipModuleLaunchCooperativeKernel.f); \
	printf("\tunsigned int gridDimX = %u\n", args->hipModuleLaunchCooperativeKernel.gridDimX); \
	printf("\tunsigned int gridDimY = %u\n", args->hipModuleLaunchCooperativeKernel.gridDimY); \
	printf("\tunsigned int gridDimZ = %u\n", args->hipModuleLaunchCooperativeKernel.gridDimZ); \
	printf("\tunsigned int blockDimX = %u\n", args->hipModuleLaunchCooperativeKernel.blockDimX); \
	printf("\tunsigned int blockDimY = %u\n", args->hipModuleLaunchCooperativeKernel.blockDimY); \
	printf("\tunsigned int blockDimZ = %u\n", args->hipModuleLaunchCooperativeKernel.blockDimZ); \
	printf("\tunsigned int sharedMemBytes = %u\n", args->hipModuleLaunchCooperativeKernel.sharedMemBytes); \
	printf("\thipStream_t stream = %p\n", args->hipModuleLaunchCooperativeKernel.stream); \
	printf("\tvoid ** kernelParams = %p", args->hipModuleLaunchCooperativeKernel.kernelParams); \
	if (args->hipModuleLaunchCooperativeKernel.kernelParams != NULL) { \
		printf("-> %p", args->hipModuleLaunchCooperativeKernel.kernelParams__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
};

//	enum hipTextureAddressMode * pam (enum*);
//	const textureReference* texRef (unknown);
//	int dim (int);
#define PROCESS_ARGS_hipTexRefGetAddressMode(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefGetAddressMode.retval); \
	printf("\tenum hipTextureAddressMode * pam = %p", args->hipTexRefGetAddressMode.pam); \
	if (args->hipTexRefGetAddressMode.pam != NULL) { \
		printf(" -> %d\n", args->hipTexRefGetAddressMode.pam__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tint dim = %d\n", args->hipTexRefGetAddressMode.dim); \
};

//	hipGraphNode_t node (opaque);
//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipGraphEventWaitNodeSetEvent(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphEventWaitNodeSetEvent.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphEventWaitNodeSetEvent.node); \
	printf("\thipEvent_t event = %p\n", args->hipGraphEventWaitNodeSetEvent.event); \
};

//	hipMemPool_t * mem_pool (opaque*);
//	int device (int);
#define PROCESS_ARGS_hipDeviceGetDefaultMemPool(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceGetDefaultMemPool.retval); \
	printf("\thipMemPool_t * mem_pool = %p", args->hipDeviceGetDefaultMemPool.mem_pool); \
	if (args->hipDeviceGetDefaultMemPool.mem_pool != NULL) { \
		printf(" -> %p\n", args->hipDeviceGetDefaultMemPool.mem_pool__ref.val); \
	} else { printf("\n"); }; \
	printf("\tint device = %d\n", args->hipDeviceGetDefaultMemPool.device); \
};

//	hipMemPool_t mem_pool (opaque);
//	size_t min_bytes_to_hold (unsigned long);
#define PROCESS_ARGS_hipMemPoolTrimTo(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemPoolTrimTo.retval); \
	printf("\thipMemPool_t mem_pool = %p\n", args->hipMemPoolTrimTo.mem_pool); \
	printf("\tsize_t min_bytes_to_hold = %lu\n", args->hipMemPoolTrimTo.min_bytes_to_hold); \
};

//	hipGraphExec_t graphExec (opaque);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipGraphUpload(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphUpload.retval); \
	printf("\thipGraphExec_t graphExec = %p\n", args->hipGraphUpload.graphExec); \
	printf("\thipStream_t stream = %p\n", args->hipGraphUpload.stream); \
};

//	hipMipmappedArray_t * mipmap (unknown);
//	hipExternalMemory_t extMem (void*);
//	const hipExternalMemoryMipmappedArrayDesc * mipmapDesc ({
//		unsigned long long offset (unsigned long long);
//		int formatDesc (int);
//		int extent (int);
//		unsigned int flags (unsigned int);
//		unsigned int numLevels (unsigned int);
//	});
#define PROCESS_ARGS_hipExternalMemoryGetMappedMipmappedArray(args) { \
	printf("\thipError_t retval = %d\n", args->hipExternalMemoryGetMappedMipmappedArray.retval); \
	printf("\thipMipmappedArray_t * mipmap = N/A, try to update csv files\n"); \
	printf("\thipExternalMemory_t extMem = %p", args->hipExternalMemoryGetMappedMipmappedArray.extMem); \
	printf("\n"); \
	printf("\tconst hipExternalMemoryMipmappedArrayDesc * mipmapDesc = %p", args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc); \
	if (args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned long long offset = %llu\n", args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc__ref.val.offset); \
		printf("\t\tint formatDesc = %d\n", args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc__ref.val.formatDesc); \
		printf("\t\tint extent = %d\n", args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc__ref.val.extent); \
		printf("\t\tunsigned int flags = %u\n", args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc__ref.val.flags); \
		printf("\t\tunsigned int numLevels = %u\n", args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc__ref.val.numLevels); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraphNode_t hNode (opaque);
//	const hipExternalSemaphoreWaitNodeParams * nodeParams ({
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphExternalSemaphoresWaitNodeSetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExternalSemaphoresWaitNodeSetParams.retval); \
	printf("\thipGraphNode_t hNode = %p\n", args->hipGraphExternalSemaphoresWaitNodeSetParams.hNode); \
	printf("\tconst hipExternalSemaphoreWaitNodeParams * nodeParams = %p", args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams); \
	if (args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned int numExtSems = %u\n", args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams__ref.val.numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	const void * symbol (void*);
//	const void * src (void*);
//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpyToSymbol(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyToSymbol.retval); \
	printf("\tconst void * symbol = %p", args->hipMemcpyToSymbol.symbol); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipMemcpyToSymbol.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyToSymbol.sizeBytes); \
	printf("\tsize_t offset = %lu\n", args->hipMemcpyToSymbol.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t * pGraphNode (opaque*);
//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * pDependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	const hipMemsetParams * pMemsetParams ({
//		unsigned int elementSize (unsigned int);
//		size_t height (unsigned long);
//		size_t pitch (unsigned long);
//		unsigned int value (unsigned int);
//		size_t width (unsigned long);
//	});
#define PROCESS_ARGS_hipGraphAddMemsetNode(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddMemsetNode.retval); \
	printf("\thipGraphNode_t * pGraphNode = %p", args->hipGraphAddMemsetNode.pGraphNode); \
	if (args->hipGraphAddMemsetNode.pGraphNode != NULL) { \
		printf(" -> %p\n", args->hipGraphAddMemsetNode.pGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddMemsetNode.graph); \
	printf("\tconst hipGraphNode_t * pDependencies = %p", args->hipGraphAddMemsetNode.pDependencies); \
	if (args->hipGraphAddMemsetNode.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphAddMemsetNode.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddMemsetNode.numDependencies); \
	printf("\tconst hipMemsetParams * pMemsetParams = %p", args->hipGraphAddMemsetNode.pMemsetParams); \
	if (args->hipGraphAddMemsetNode.pMemsetParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned int elementSize = %u\n", args->hipGraphAddMemsetNode.pMemsetParams__ref.val.elementSize); \
		printf("\t\tsize_t height = %lu\n", args->hipGraphAddMemsetNode.pMemsetParams__ref.val.height); \
		printf("\t\tsize_t pitch = %lu\n", args->hipGraphAddMemsetNode.pMemsetParams__ref.val.pitch); \
		printf("\t\tunsigned int value = %u\n", args->hipGraphAddMemsetNode.pMemsetParams__ref.val.value); \
		printf("\t\tsize_t width = %lu\n", args->hipGraphAddMemsetNode.pMemsetParams__ref.val.width); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraph_t * pGraphClone (opaque*);
//	hipGraph_t originalGraph (opaque);
#define PROCESS_ARGS_hipGraphClone(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphClone.retval); \
	printf("\thipGraph_t * pGraphClone = %p", args->hipGraphClone.pGraphClone); \
	if (args->hipGraphClone.pGraphClone != NULL) { \
		printf(" -> %p\n", args->hipGraphClone.pGraphClone__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t originalGraph = %p\n", args->hipGraphClone.originalGraph); \
};


#define PROCESS_ARGS_hipExtGetLastError(args) { \
	printf("\thipError_t retval = %d\n", args->hipExtGetLastError.retval); \
\
};

//	hipGraphNode_t hNode (opaque);
//	hipKernelNodeAttrID attr (enum);
//	hipKernelNodeAttrValue * value ({
//		hipAccessPolicyWindow accessPolicyWindow ({
//			hipAccessProperty hitProp (enum);
//			float hitRatio (float);
//			hipAccessProperty missProp (enum);
//			int num_bytes (int);
//		});
//		int cooperative (int);
//	});
#define PROCESS_ARGS_hipGraphKernelNodeGetAttribute(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphKernelNodeGetAttribute.retval); \
	printf("\thipGraphNode_t hNode = %p\n", args->hipGraphKernelNodeGetAttribute.hNode); \
	printf("\thipKernelNodeAttrID attr = %d\n", args->hipGraphKernelNodeGetAttribute.attr); \
	printf("\thipKernelNodeAttrValue * value = %p", args->hipGraphKernelNodeGetAttribute.value); \
	if (args->hipGraphKernelNodeGetAttribute.value != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipAccessPolicyWindow accessPolicyWindow = {\n"); \
		printf("\t\t\thipAccessProperty hitProp = %d\n", args->hipGraphKernelNodeGetAttribute.value__ref.val.accessPolicyWindow.hitProp); \
		printf("\t\t\tfloat hitRatio = %f\n", args->hipGraphKernelNodeGetAttribute.value__ref.val.accessPolicyWindow.hitRatio); \
		printf("\t\t\thipAccessProperty missProp = %d\n", args->hipGraphKernelNodeGetAttribute.value__ref.val.accessPolicyWindow.missProp); \
		printf("\t\t\tint num_bytes = %d\n", args->hipGraphKernelNodeGetAttribute.value__ref.val.accessPolicyWindow.num_bytes); \
		printf("\t\t}\n"); \
		printf("\t\tint cooperative = %d\n", args->hipGraphKernelNodeGetAttribute.value__ref.val.cooperative); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipEvent_t event (opaque);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipEventRecord(args) { \
	printf("\thipError_t retval = %d\n", args->hipEventRecord.retval); \
	printf("\thipEvent_t event = %p\n", args->hipEventRecord.event); \
	printf("\thipStream_t stream = %p\n", args->hipEventRecord.stream); \
};

//	hipMemAllocationProp * prop ({
//		hipMemAllocationType type (enum);
//		hipMemAllocationHandleType requestedHandleType (enum);
//		hipMemLocation location ({
//			hipMemLocationType type (enum);
//			int id (int);
//		});
//		struct (unnamed struct at ./input/hip_runtime_api.h:1393:5) allocFlags ({
//			unsigned char compressionType (unsigned char);
//			unsigned char gpuDirectRDMACapable (unsigned char);
//			unsigned short usage (unsigned short);
//		});
//	});
//	hipMemGenericAllocationHandle_t handle (opaque);
#define PROCESS_ARGS_hipMemGetAllocationPropertiesFromHandle(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemGetAllocationPropertiesFromHandle.retval); \
	printf("\thipMemAllocationProp * prop = %p", args->hipMemGetAllocationPropertiesFromHandle.prop); \
	if (args->hipMemGetAllocationPropertiesFromHandle.prop != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemAllocationType type = %d\n", args->hipMemGetAllocationPropertiesFromHandle.prop__ref.val.type); \
		printf("\t\thipMemAllocationHandleType requestedHandleType = %d\n", args->hipMemGetAllocationPropertiesFromHandle.prop__ref.val.requestedHandleType); \
		printf("\t\thipMemLocation location = {\n"); \
		printf("\t\t\thipMemLocationType type = %d\n", args->hipMemGetAllocationPropertiesFromHandle.prop__ref.val.location.type); \
		printf("\t\t\tint id = %d\n", args->hipMemGetAllocationPropertiesFromHandle.prop__ref.val.location.id); \
		printf("\t\t}\n"); \
		printf("\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1393:5) allocFlags = {\n"); \
		printf("\t\t\tunsigned char compressionType = %hhu\n", args->hipMemGetAllocationPropertiesFromHandle.prop__ref.val.allocFlags.compressionType); \
		printf("\t\t\tunsigned char gpuDirectRDMACapable = %hhu\n", args->hipMemGetAllocationPropertiesFromHandle.prop__ref.val.allocFlags.gpuDirectRDMACapable); \
		printf("\t\t\tunsigned short usage = %hu\n", args->hipMemGetAllocationPropertiesFromHandle.prop__ref.val.allocFlags.usage); \
		printf("\t\t}\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thipMemGenericAllocationHandle_t handle = %p\n", args->hipMemGetAllocationPropertiesFromHandle.handle); \
};

//	hipGraphNode_t * pGraphNode (opaque*);
//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * pDependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipGraphAddEventWaitNode(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddEventWaitNode.retval); \
	printf("\thipGraphNode_t * pGraphNode = %p", args->hipGraphAddEventWaitNode.pGraphNode); \
	if (args->hipGraphAddEventWaitNode.pGraphNode != NULL) { \
		printf(" -> %p\n", args->hipGraphAddEventWaitNode.pGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddEventWaitNode.graph); \
	printf("\tconst hipGraphNode_t * pDependencies = %p", args->hipGraphAddEventWaitNode.pDependencies); \
	if (args->hipGraphAddEventWaitNode.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphAddEventWaitNode.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddEventWaitNode.numDependencies); \
	printf("\thipEvent_t event = %p\n", args->hipGraphAddEventWaitNode.event); \
};

//	void ** dev_ptr (void**);
//	hipMemPool_t mem_pool (opaque);
//	hipMemPoolPtrExportData * export_data ({
//		unsigned char[64] reserved (unsigned char);
//	});
#define PROCESS_ARGS_hipMemPoolImportPointer(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemPoolImportPointer.retval); \
	printf("\tvoid ** dev_ptr = %p", args->hipMemPoolImportPointer.dev_ptr); \
	if (args->hipMemPoolImportPointer.dev_ptr != NULL) { \
		printf("-> %p", args->hipMemPoolImportPointer.dev_ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\thipMemPool_t mem_pool = %p\n", args->hipMemPoolImportPointer.mem_pool); \
	printf("\thipMemPoolPtrExportData * export_data = %p", args->hipMemPoolImportPointer.export_data); \
	if (args->hipMemPoolImportPointer.export_data != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned char[64] reserved = %hhu\n", args->hipMemPoolImportPointer.export_data__ref.val.reserved[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	void * ptr (void*);
#define PROCESS_ARGS_hipFree(args) { \
	printf("\thipError_t retval = %d\n", args->hipFree.retval); \
	printf("\tvoid * ptr = %p", args->hipFree.ptr); \
	printf("\n"); \
};

//	hipGraphNode_t node (opaque);
//	hipEvent_t * event_out (opaque*);
#define PROCESS_ARGS_hipGraphEventRecordNodeGetEvent(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphEventRecordNodeGetEvent.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphEventRecordNodeGetEvent.node); \
	printf("\thipEvent_t * event_out = %p", args->hipGraphEventRecordNodeGetEvent.event_out); \
	if (args->hipGraphEventRecordNodeGetEvent.event_out != NULL) { \
		printf(" -> %p\n", args->hipGraphEventRecordNodeGetEvent.event_out__ref.val); \
	} else { printf("\n"); }; \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMalloc(args) { \
	printf("\thipError_t retval = %d\n", args->hipMalloc.retval); \
	printf("\tvoid ** ptr = %p", args->hipMalloc.ptr); \
	if (args->hipMalloc.ptr != NULL) { \
		printf("-> %p", args->hipMalloc.ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipMalloc.size); \
};

//	void * dst (void*);
//	const void * src (void*);
//	size_t sizeBytes (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyWithStream(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyWithStream.retval); \
	printf("\tvoid * dst = %p", args->hipMemcpyWithStream.dst); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipMemcpyWithStream.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyWithStream.sizeBytes); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = %p\n", args->hipMemcpyWithStream.stream); \
};

//	const HIP_MEMCPY3D* pCopy (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipDrvMemcpy3DAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipDrvMemcpy3DAsync.retval); \
	printf("\tconst HIP_MEMCPY3D* pCopy = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = %p\n", args->hipDrvMemcpy3DAsync.stream); \
};

//	hipGraphNode_t * pGraphNode (opaque*);
//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * pDependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	hipMemAllocNodeParams * pNodeParams ({
//		hipMemPoolProps poolProps ({
//			hipMemAllocationType allocType (enum);
//			hipMemAllocationHandleType handleTypes (enum);
//			hipMemLocation location ({
//				hipMemLocationType type (enum);
//				int id (int);
//			});
//			unsigned char[64] reserved (unsigned char);
//		});
//		int accessDescCount (int);
//		int bytesize (int);
//	});
#define PROCESS_ARGS_hipGraphAddMemAllocNode(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddMemAllocNode.retval); \
	printf("\thipGraphNode_t * pGraphNode = %p", args->hipGraphAddMemAllocNode.pGraphNode); \
	if (args->hipGraphAddMemAllocNode.pGraphNode != NULL) { \
		printf(" -> %p\n", args->hipGraphAddMemAllocNode.pGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddMemAllocNode.graph); \
	printf("\tconst hipGraphNode_t * pDependencies = %p", args->hipGraphAddMemAllocNode.pDependencies); \
	if (args->hipGraphAddMemAllocNode.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphAddMemAllocNode.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddMemAllocNode.numDependencies); \
	printf("\thipMemAllocNodeParams * pNodeParams = %p", args->hipGraphAddMemAllocNode.pNodeParams); \
	if (args->hipGraphAddMemAllocNode.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemPoolProps poolProps = {\n"); \
		printf("\t\t\thipMemAllocationType allocType = %d\n", args->hipGraphAddMemAllocNode.pNodeParams__ref.val.poolProps.allocType); \
		printf("\t\t\thipMemAllocationHandleType handleTypes = %d\n", args->hipGraphAddMemAllocNode.pNodeParams__ref.val.poolProps.handleTypes); \
		printf("\t\t\thipMemLocation location = {\n"); \
		printf("\t\t\t\thipMemLocationType type = %d\n", args->hipGraphAddMemAllocNode.pNodeParams__ref.val.poolProps.location.type); \
		printf("\t\t\t\tint id = %d\n", args->hipGraphAddMemAllocNode.pNodeParams__ref.val.poolProps.location.id); \
		printf("\t\t\t}\n"); \
		printf("\t\t\tunsigned char[64] reserved = %hhu\n", args->hipGraphAddMemAllocNode.pNodeParams__ref.val.poolProps.reserved[0]); \
		printf("\t\t}\n"); \
		printf("\t\tint accessDescCount = %d\n", args->hipGraphAddMemAllocNode.pNodeParams__ref.val.accessDescCount); \
		printf("\t\tint bytesize = %d\n", args->hipGraphAddMemAllocNode.pNodeParams__ref.val.bytesize); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostMalloc(args) { \
	printf("\thipError_t retval = %d\n", args->hipHostMalloc.retval); \
	printf("\tvoid ** ptr = %p", args->hipHostMalloc.ptr); \
	if (args->hipHostMalloc.ptr != NULL) { \
		printf("-> %p", args->hipHostMalloc.ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipHostMalloc.size); \
	printf("\tunsigned int flags = %u\n", args->hipHostMalloc.flags); \
};

//	hipGraphNode_t node (opaque);
//	hipMemcpy3DParms * pNodeParams (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeGetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphMemcpyNodeGetParams.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphMemcpyNodeGetParams.node); \
	printf("\thipMemcpy3DParms * pNodeParams = N/A, try to update csv files\n"); \
};

//	textureReference * texRef (unknown);
//	unsigned int Flags (unsigned int);
#define PROCESS_ARGS_hipTexRefSetFlags(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefSetFlags.retval); \
	printf("\ttextureReference * texRef = N/A, try to update csv files\n"); \
	printf("\tunsigned int Flags = %u\n", args->hipTexRefSetFlags.Flags); \
};

//	hipMemPool_t * mem_pool (opaque*);
//	void * shared_handle (void*);
//	hipMemAllocationHandleType handle_type (enum);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMemPoolImportFromShareableHandle(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemPoolImportFromShareableHandle.retval); \
	printf("\thipMemPool_t * mem_pool = %p", args->hipMemPoolImportFromShareableHandle.mem_pool); \
	if (args->hipMemPoolImportFromShareableHandle.mem_pool != NULL) { \
		printf(" -> %p\n", args->hipMemPoolImportFromShareableHandle.mem_pool__ref.val); \
	} else { printf("\n"); }; \
	printf("\tvoid * shared_handle = %p", args->hipMemPoolImportFromShareableHandle.shared_handle); \
	printf("\n"); \
	printf("\thipMemAllocationHandleType handle_type = %d\n", args->hipMemPoolImportFromShareableHandle.handle_type); \
	printf("\tunsigned int flags = %u\n", args->hipMemPoolImportFromShareableHandle.flags); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t hNode (opaque);
//	unsigned int isEnabled (unsigned int);
#define PROCESS_ARGS_hipGraphNodeSetEnabled(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphNodeSetEnabled.retval); \
	printf("\thipGraphExec_t hGraphExec = %p\n", args->hipGraphNodeSetEnabled.hGraphExec); \
	printf("\thipGraphNode_t hNode = %p\n", args->hipGraphNodeSetEnabled.hNode); \
	printf("\tunsigned int isEnabled = %u\n", args->hipGraphNodeSetEnabled.isEnabled); \
};

//	textureReference * texRef (unknown);
//	float bias (float);
#define PROCESS_ARGS_hipTexRefSetMipmapLevelBias(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefSetMipmapLevelBias.retval); \
	printf("\ttextureReference * texRef = N/A, try to update csv files\n"); \
	printf("\tfloat bias = %f\n", args->hipTexRefSetMipmapLevelBias.bias); \
};

//	hipStream_t stream (opaque);
//	void * ptr (void*);
//	uint32_t value (unsigned int);
//	unsigned int flags (unsigned int);
//	uint32_t mask (unsigned int);
#define PROCESS_ARGS_hipStreamWaitValue32(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamWaitValue32.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamWaitValue32.stream); \
	printf("\tvoid * ptr = %p", args->hipStreamWaitValue32.ptr); \
	printf("\n"); \
	printf("\tuint32_t value = %u\n", args->hipStreamWaitValue32.value); \
	printf("\tunsigned int flags = %u\n", args->hipStreamWaitValue32.flags); \
	printf("\tuint32_t mask = %u\n", args->hipStreamWaitValue32.mask); \
};

//	hipMipmappedArray_t hMipmappedArray (unknown);
#define PROCESS_ARGS_hipMipmappedArrayDestroy(args) { \
	printf("\thipError_t retval = %d\n", args->hipMipmappedArrayDestroy.retval); \
	printf("\thipMipmappedArray_t hMipmappedArray = N/A, try to update csv files\n"); \
};

//	hipCtx_t ctx (opaque);
#define PROCESS_ARGS_hipCtxDestroy(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxDestroy.retval); \
	printf("\thipCtx_t ctx = %p\n", args->hipCtxDestroy.ctx); \
};


#define PROCESS_ARGS_hipDeviceReset(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceReset.retval); \
\
};

//	const void * dev_ptr (void*);
//	size_t count (unsigned long);
//	int device (int);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemPrefetchAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemPrefetchAsync.retval); \
	printf("\tconst void * dev_ptr = %p", args->hipMemPrefetchAsync.dev_ptr); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipMemPrefetchAsync.count); \
	printf("\tint device = %d\n", args->hipMemPrefetchAsync.device); \
	printf("\thipStream_t stream = %p\n", args->hipMemPrefetchAsync.stream); \
};

//	hipDeviceptr_t dest (void*);
//	unsigned short value (unsigned short);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemsetD16(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemsetD16.retval); \
	printf("\thipDeviceptr_t dest = %p", args->hipMemsetD16.dest); \
	printf("\n"); \
	printf("\tunsigned short value = %hu\n", args->hipMemsetD16.value); \
	printf("\tsize_t count = %lu\n", args->hipMemsetD16.count); \
};

//	void * dst (void*);
//	size_t dpitch (unsigned long);
//	const void * src (void*);
//	size_t spitch (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpy2DAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpy2DAsync.retval); \
	printf("\tvoid * dst = %p", args->hipMemcpy2DAsync.dst); \
	printf("\n"); \
	printf("\tsize_t dpitch = %lu\n", args->hipMemcpy2DAsync.dpitch); \
	printf("\tconst void * src = %p", args->hipMemcpy2DAsync.src); \
	printf("\n"); \
	printf("\tsize_t spitch = %lu\n", args->hipMemcpy2DAsync.spitch); \
	printf("\tsize_t width = %lu\n", args->hipMemcpy2DAsync.width); \
	printf("\tsize_t height = %lu\n", args->hipMemcpy2DAsync.height); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = %p\n", args->hipMemcpy2DAsync.stream); \
};

//	hipDevice_t dev (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipDevicePrimaryCtxSetFlags(args) { \
	printf("\thipError_t retval = %d\n", args->hipDevicePrimaryCtxSetFlags.retval); \
	printf("\thipDevice_t dev = %d\n", args->hipDevicePrimaryCtxSetFlags.dev); \
	printf("\tunsigned int flags = %u\n", args->hipDevicePrimaryCtxSetFlags.flags); \
};

//	hipGraphExec_t * pGraphExec (opaque*);
//	hipGraph_t graph (opaque);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipGraphInstantiateWithFlags(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphInstantiateWithFlags.retval); \
	printf("\thipGraphExec_t * pGraphExec = %p", args->hipGraphInstantiateWithFlags.pGraphExec); \
	if (args->hipGraphInstantiateWithFlags.pGraphExec != NULL) { \
		printf(" -> %p\n", args->hipGraphInstantiateWithFlags.pGraphExec__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphInstantiateWithFlags.graph); \
	printf("\tunsigned long long flags = %llu\n", args->hipGraphInstantiateWithFlags.flags); \
};

//	hipGraphNode_t * pGraphNode (opaque*);
//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * pDependencies (opaque*);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphAddEmptyNode(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddEmptyNode.retval); \
	printf("\thipGraphNode_t * pGraphNode = %p", args->hipGraphAddEmptyNode.pGraphNode); \
	if (args->hipGraphAddEmptyNode.pGraphNode != NULL) { \
		printf(" -> %p\n", args->hipGraphAddEmptyNode.pGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddEmptyNode.graph); \
	printf("\tconst hipGraphNode_t * pDependencies = %p", args->hipGraphAddEmptyNode.pDependencies); \
	if (args->hipGraphAddEmptyNode.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphAddEmptyNode.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddEmptyNode.numDependencies); \
};

//	hipMipmappedArray_t mipmappedArray (unknown);
#define PROCESS_ARGS_hipFreeMipmappedArray(args) { \
	printf("\thipError_t retval = %d\n", args->hipFreeMipmappedArray.retval); \
	printf("\thipMipmappedArray_t mipmappedArray = N/A, try to update csv files\n"); \
};

//	hipArray_t * pHandle (unknown);
//	const HIP_ARRAY_DESCRIPTOR * pAllocateArray (unknown);
#define PROCESS_ARGS_hipArrayCreate(args) { \
	printf("\thipError_t retval = %d\n", args->hipArrayCreate.retval); \
	printf("\thipArray_t * pHandle = N/A, try to update csv files\n"); \
	printf("\tconst HIP_ARRAY_DESCRIPTOR * pAllocateArray = N/A, try to update csv files\n"); \
};

//	const textureReference * tex (unknown);
#define PROCESS_ARGS_hipUnbindTexture(args) { \
	printf("\thipError_t retval = %d\n", args->hipUnbindTexture.retval); \
	printf("\tconst textureReference * tex = N/A, try to update csv files\n"); \
};

//	hipCtx_t * ctx (opaque*);
#define PROCESS_ARGS_hipCtxPopCurrent(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxPopCurrent.retval); \
	printf("\thipCtx_t * ctx = %p", args->hipCtxPopCurrent.ctx); \
	if (args->hipCtxPopCurrent.ctx != NULL) { \
		printf(" -> %p\n", args->hipCtxPopCurrent.ctx__ref.val); \
	} else { printf("\n"); }; \
};

//	hipDeviceptr_t dest (void*);
//	unsigned short value (unsigned short);
//	size_t count (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemsetD16Async(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemsetD16Async.retval); \
	printf("\thipDeviceptr_t dest = %p", args->hipMemsetD16Async.dest); \
	printf("\n"); \
	printf("\tunsigned short value = %hu\n", args->hipMemsetD16Async.value); \
	printf("\tsize_t count = %lu\n", args->hipMemsetD16Async.count); \
	printf("\thipStream_t stream = %p\n", args->hipMemsetD16Async.stream); \
};

//	HIP_RESOURCE_DESC * pResDesc (unknown);
//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectGetResourceDesc(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexObjectGetResourceDesc.retval); \
	printf("\tHIP_RESOURCE_DESC * pResDesc = N/A, try to update csv files\n"); \
	printf("\thipTextureObject_t texObject = N/A, try to update csv files\n"); \
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
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipLaunchKernel(args) { \
	printf("\thipError_t retval = %d\n", args->hipLaunchKernel.retval); \
	printf("\tconst void * function_address = %p", args->hipLaunchKernel.function_address); \
	printf("\n"); \
	printf("\tdim3 numBlocks = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipLaunchKernel.numBlocks.x); \
	printf("\t\tuint32_t y = %u\n", args->hipLaunchKernel.numBlocks.y); \
	printf("\t\tuint32_t z = %u\n", args->hipLaunchKernel.numBlocks.z); \
	printf("\t}\n"); \
	printf("\tdim3 dimBlocks = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipLaunchKernel.dimBlocks.x); \
	printf("\t\tuint32_t y = %u\n", args->hipLaunchKernel.dimBlocks.y); \
	printf("\t\tuint32_t z = %u\n", args->hipLaunchKernel.dimBlocks.z); \
	printf("\t}\n"); \
	printf("\tvoid ** args = %p", args->hipLaunchKernel.args); \
	if (args->hipLaunchKernel.args != NULL) { \
		printf("-> %p", args->hipLaunchKernel.args__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t sharedMemBytes = %lu\n", args->hipLaunchKernel.sharedMemBytes); \
	printf("\thipStream_t stream = %p\n", args->hipLaunchKernel.stream); \
};

//	hipGraphNode_t node (opaque);
//	hipMemsetParams * pNodeParams ({
//		unsigned int elementSize (unsigned int);
//		size_t height (unsigned long);
//		size_t pitch (unsigned long);
//		unsigned int value (unsigned int);
//		size_t width (unsigned long);
//	});
#define PROCESS_ARGS_hipGraphMemsetNodeGetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphMemsetNodeGetParams.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphMemsetNodeGetParams.node); \
	printf("\thipMemsetParams * pNodeParams = %p", args->hipGraphMemsetNodeGetParams.pNodeParams); \
	if (args->hipGraphMemsetNodeGetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned int elementSize = %u\n", args->hipGraphMemsetNodeGetParams.pNodeParams__ref.val.elementSize); \
		printf("\t\tsize_t height = %lu\n", args->hipGraphMemsetNodeGetParams.pNodeParams__ref.val.height); \
		printf("\t\tsize_t pitch = %lu\n", args->hipGraphMemsetNodeGetParams.pNodeParams__ref.val.pitch); \
		printf("\t\tunsigned int value = %u\n", args->hipGraphMemsetNodeGetParams.pNodeParams__ref.val.value); \
		printf("\t\tsize_t width = %lu\n", args->hipGraphMemsetNodeGetParams.pNodeParams__ref.val.width); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	unsigned int * flagsPtr (unsigned int*);
//	void * hostPtr (void*);
#define PROCESS_ARGS_hipHostGetFlags(args) { \
	printf("\thipError_t retval = %d\n", args->hipHostGetFlags.retval); \
	printf("\tunsigned int * flagsPtr = %p", args->hipHostGetFlags.flagsPtr); \
	if (args->hipHostGetFlags.flagsPtr != NULL) { \
		printf(" -> %u\n", args->hipHostGetFlags.flagsPtr__ref.val); \
	} else { printf("\n"); }; \
	printf("\tvoid * hostPtr = %p", args->hipHostGetFlags.hostPtr); \
	printf("\n"); \
};

//	hipGraphExec_t graphExec (opaque);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipGraphLaunch(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphLaunch.retval); \
	printf("\thipGraphExec_t graphExec = %p\n", args->hipGraphLaunch.graphExec); \
	printf("\thipStream_t stream = %p\n", args->hipGraphLaunch.stream); \
};

//	void * dst (void*);
//	const void * src (void*);
//	size_t sizeBytes (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyAsync.retval); \
	printf("\tvoid * dst = %p", args->hipMemcpyAsync.dst); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipMemcpyAsync.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyAsync.sizeBytes); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = %p\n", args->hipMemcpyAsync.stream); \
};

//	hipArray_t * array (unknown);
//	const hipChannelFormatDesc * desc (unknown);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMallocArray(args) { \
	printf("\thipError_t retval = %d\n", args->hipMallocArray.retval); \
	printf("\thipArray_t * array = N/A, try to update csv files\n"); \
	printf("\tconst hipChannelFormatDesc * desc = N/A, try to update csv files\n"); \
	printf("\tsize_t width = %lu\n", args->hipMallocArray.width); \
	printf("\tsize_t height = %lu\n", args->hipMallocArray.height); \
	printf("\tunsigned int flags = %u\n", args->hipMallocArray.flags); \
};

//	const void * func (void*);
//	hipFuncCache_t config (enum);
#define PROCESS_ARGS_hipFuncSetCacheConfig(args) { \
	printf("\thipError_t retval = %d\n", args->hipFuncSetCacheConfig.retval); \
	printf("\tconst void * func = %p", args->hipFuncSetCacheConfig.func); \
	printf("\n"); \
	printf("\thipFuncCache_t config = %d\n", args->hipFuncSetCacheConfig.config); \
};

//	void ** dev_ptr (void**);
//	size_t size (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMallocManaged(args) { \
	printf("\thipError_t retval = %d\n", args->hipMallocManaged.retval); \
	printf("\tvoid ** dev_ptr = %p", args->hipMallocManaged.dev_ptr); \
	if (args->hipMallocManaged.dev_ptr != NULL) { \
		printf("-> %p", args->hipMallocManaged.dev_ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipMallocManaged.size); \
	printf("\tunsigned int flags = %u\n", args->hipMallocManaged.flags); \
};

//	uint32_t id (unsigned int);
#define PROCESS_ARGS_hipApiName(args) { \
	printf("\tconst char * retval = %s\n", args->hipApiName.retval); \
	printf("\tuint32_t id = %u\n", args->hipApiName.id); \
};

//	void * ptr (void*);
#define PROCESS_ARGS_hipFreeHost(args) { \
	printf("\thipError_t retval = %d\n", args->hipFreeHost.retval); \
	printf("\tvoid * ptr = %p", args->hipFreeHost.ptr); \
	printf("\n"); \
};

//	hipCtx_t * ctx (opaque*);
#define PROCESS_ARGS_hipCtxGetCurrent(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxGetCurrent.retval); \
	printf("\thipCtx_t * ctx = %p", args->hipCtxGetCurrent.ctx); \
	if (args->hipCtxGetCurrent.ctx != NULL) { \
		printf(" -> %p\n", args->hipCtxGetCurrent.ctx__ref.val); \
	} else { printf("\n"); }; \
};

//	hipSurfaceObject_t surfaceObject (unknown);
#define PROCESS_ARGS_hipDestroySurfaceObject(args) { \
	printf("\thipError_t retval = %d\n", args->hipDestroySurfaceObject.retval); \
	printf("\thipSurfaceObject_t surfaceObject = N/A, try to update csv files\n"); \
};

//	void ** ptr (void**);
//	size_t * pitch (unsigned long*);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
#define PROCESS_ARGS_hipMallocPitch(args) { \
	printf("\thipError_t retval = %d\n", args->hipMallocPitch.retval); \
	printf("\tvoid ** ptr = %p", args->hipMallocPitch.ptr); \
	if (args->hipMallocPitch.ptr != NULL) { \
		printf("-> %p", args->hipMallocPitch.ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t * pitch = %p", args->hipMallocPitch.pitch); \
	if (args->hipMallocPitch.pitch != NULL) { \
		printf(" -> %lu\n", args->hipMallocPitch.pitch__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t width = %lu\n", args->hipMallocPitch.width); \
	printf("\tsize_t height = %lu\n", args->hipMallocPitch.height); \
};

//	hipStream_t stream (opaque);
//	hipStreamCaptureStatus * pCaptureStatus (enum*);
//	unsigned long long * pId (unsigned long long*);
#define PROCESS_ARGS_hipStreamGetCaptureInfo(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamGetCaptureInfo.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamGetCaptureInfo.stream); \
	printf("\thipStreamCaptureStatus * pCaptureStatus = %p", args->hipStreamGetCaptureInfo.pCaptureStatus); \
	if (args->hipStreamGetCaptureInfo.pCaptureStatus != NULL) { \
		printf(" -> %d\n", args->hipStreamGetCaptureInfo.pCaptureStatus__ref.val); \
	} else { printf("\n"); }; \
	printf("\tunsigned long long * pId = %p", args->hipStreamGetCaptureInfo.pId); \
	if (args->hipStreamGetCaptureInfo.pId != NULL) { \
		printf(" -> %llu\n", args->hipStreamGetCaptureInfo.pId__ref.val); \
	} else { printf("\n"); }; \
};

//	hipStream_t stream (opaque);
//	hipGraphNode_t * dependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamUpdateCaptureDependencies(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamUpdateCaptureDependencies.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamUpdateCaptureDependencies.stream); \
	printf("\thipGraphNode_t * dependencies = %p", args->hipStreamUpdateCaptureDependencies.dependencies); \
	if (args->hipStreamUpdateCaptureDependencies.dependencies != NULL) { \
		printf(" -> %p\n", args->hipStreamUpdateCaptureDependencies.dependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipStreamUpdateCaptureDependencies.numDependencies); \
	printf("\tunsigned int flags = %u\n", args->hipStreamUpdateCaptureDependencies.flags); \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostAlloc(args) { \
	printf("\thipError_t retval = %d\n", args->hipHostAlloc.retval); \
	printf("\tvoid ** ptr = %p", args->hipHostAlloc.ptr); \
	if (args->hipHostAlloc.ptr != NULL) { \
		printf("-> %p", args->hipHostAlloc.ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipHostAlloc.size); \
	printf("\tunsigned int flags = %u\n", args->hipHostAlloc.flags); \
};

//	hipDeviceptr_t dest (void*);
//	unsigned char value (unsigned char);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemsetD8(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemsetD8.retval); \
	printf("\thipDeviceptr_t dest = %p", args->hipMemsetD8.dest); \
	printf("\n"); \
	printf("\tunsigned char value = %hhu\n", args->hipMemsetD8.value); \
	printf("\tsize_t count = %lu\n", args->hipMemsetD8.count); \
};

//	hipPitchedPtr pitchedDevPtr (unknown);
//	int value (int);
//	hipExtent extent (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemset3DAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemset3DAsync.retval); \
	printf("\thipPitchedPtr pitchedDevPtr = N/A, try to update csv files\n"); \
	printf("\tint value = %d\n", args->hipMemset3DAsync.value); \
	printf("\thipExtent extent = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = %p\n", args->hipMemset3DAsync.stream); \
};

//	const hip_Memcpy2D * pCopy (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyParam2DAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyParam2DAsync.retval); \
	printf("\tconst hip_Memcpy2D * pCopy = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = %p\n", args->hipMemcpyParam2DAsync.stream); \
};

//	hipError_t hipError (enum);
//	const char ** errorString (string**);
#define PROCESS_ARGS_hipDrvGetErrorName(args) { \
	printf("\thipError_t retval = %d\n", args->hipDrvGetErrorName.retval); \
	printf("\thipError_t hipError = %d\n", args->hipDrvGetErrorName.hipError); \
	printf("\tconst char ** errorString = %p", args->hipDrvGetErrorName.errorString); \
	if (args->hipDrvGetErrorName.errorString != NULL) { \
		printf("-> %p", args->hipDrvGetErrorName.errorString__ref.ptr1); \
		if (args->hipDrvGetErrorName.errorString__ref.ptr1 != NULL) { \
			printf(" -> %s\n", args->hipDrvGetErrorName.errorString__ref.val); \
		} else { printf("\n"); }; \
	} else { printf("\n"); }; \
};

//	const void * value (void*);
//	hipPointer_attribute attribute (unknown);
//	hipDeviceptr_t ptr (void*);
#define PROCESS_ARGS_hipPointerSetAttribute(args) { \
	printf("\thipError_t retval = %d\n", args->hipPointerSetAttribute.retval); \
	printf("\tconst void * value = %p", args->hipPointerSetAttribute.value); \
	printf("\n"); \
	printf("\thipPointer_attribute attribute = N/A, try to update csv files\n"); \
	printf("\thipDeviceptr_t ptr = %p", args->hipPointerSetAttribute.ptr); \
	printf("\n"); \
};

//	size_t * free (unsigned long*);
//	size_t * total (unsigned long*);
#define PROCESS_ARGS_hipMemGetInfo(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemGetInfo.retval); \
	printf("\tsize_t * free = %p", args->hipMemGetInfo.free); \
	if (args->hipMemGetInfo.free != NULL) { \
		printf(" -> %lu\n", args->hipMemGetInfo.free__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t * total = %p", args->hipMemGetInfo.total); \
	if (args->hipMemGetInfo.total != NULL) { \
		printf(" -> %lu\n", args->hipMemGetInfo.total__ref.val); \
	} else { printf("\n"); }; \
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
	printf("\thipError_t retval = %d\n", args->__hipPushCallConfiguration.retval); \
	printf("\tdim3 gridDim = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->__hipPushCallConfiguration.gridDim.x); \
	printf("\t\tuint32_t y = %u\n", args->__hipPushCallConfiguration.gridDim.y); \
	printf("\t\tuint32_t z = %u\n", args->__hipPushCallConfiguration.gridDim.z); \
	printf("\t}\n"); \
	printf("\tdim3 blockDim = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->__hipPushCallConfiguration.blockDim.x); \
	printf("\t\tuint32_t y = %u\n", args->__hipPushCallConfiguration.blockDim.y); \
	printf("\t\tuint32_t z = %u\n", args->__hipPushCallConfiguration.blockDim.z); \
	printf("\t}\n"); \
	printf("\tsize_t sharedMem = %lu\n", args->__hipPushCallConfiguration.sharedMem); \
	printf("\thipStream_t stream = %p\n", args->__hipPushCallConfiguration.stream); \
};

//	hipArray_Format * pFormat (unknown);
//	int * pNumChannels (int*);
//	const textureReference * texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetFormat(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefGetFormat.retval); \
	printf("\thipArray_Format * pFormat = N/A, try to update csv files\n"); \
	printf("\tint * pNumChannels = %p", args->hipTexRefGetFormat.pNumChannels); \
	if (args->hipTexRefGetFormat.pNumChannels != NULL) { \
		printf(" -> %d\n", args->hipTexRefGetFormat.pNumChannels__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference * texRef = N/A, try to update csv files\n"); \
};

//	void * shareableHandle (void*);
//	hipMemGenericAllocationHandle_t handle (opaque);
//	hipMemAllocationHandleType handleType (enum);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipMemExportToShareableHandle(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemExportToShareableHandle.retval); \
	printf("\tvoid * shareableHandle = %p", args->hipMemExportToShareableHandle.shareableHandle); \
	printf("\n"); \
	printf("\thipMemGenericAllocationHandle_t handle = %p\n", args->hipMemExportToShareableHandle.handle); \
	printf("\thipMemAllocationHandleType handleType = %d\n", args->hipMemExportToShareableHandle.handleType); \
	printf("\tunsigned long long flags = %llu\n", args->hipMemExportToShareableHandle.flags); \
};

//	enum hipTextureFilterMode * pfm (enum*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetFilterMode(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefGetFilterMode.retval); \
	printf("\tenum hipTextureFilterMode * pfm = %p", args->hipTexRefGetFilterMode.pfm); \
	if (args->hipTexRefGetFilterMode.pfm != NULL) { \
		printf(" -> %d\n", args->hipTexRefGetFilterMode.pfm__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t node (opaque);
//	const hipHostNodeParams * pNodeParams ({
//		hipHostFn_t fn (function);
//	});
#define PROCESS_ARGS_hipGraphHostNodeSetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphHostNodeSetParams.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphHostNodeSetParams.node); \
	printf("\tconst hipHostNodeParams * pNodeParams = %p", args->hipGraphHostNodeSetParams.pNodeParams); \
	if (args->hipGraphHostNodeSetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipHostFn_t fn = %p\n", args->hipGraphHostNodeSetParams.pNodeParams__ref.val.fn); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraph_t graph (opaque);
//	hipGraphNode_t * nodes (opaque*);
//	size_t * numNodes (unsigned long*);
#define PROCESS_ARGS_hipGraphGetNodes(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphGetNodes.retval); \
	printf("\thipGraph_t graph = %p\n", args->hipGraphGetNodes.graph); \
	printf("\thipGraphNode_t * nodes = %p", args->hipGraphGetNodes.nodes); \
	if (args->hipGraphGetNodes.nodes != NULL) { \
		printf(" -> %p\n", args->hipGraphGetNodes.nodes__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t * numNodes = %p", args->hipGraphGetNodes.numNodes); \
	if (args->hipGraphGetNodes.numNodes != NULL) { \
		printf(" -> %lu\n", args->hipGraphGetNodes.numNodes__ref.val); \
	} else { printf("\n"); }; \
};

//	hipDevice_t * device (int*);
#define PROCESS_ARGS_hipCtxGetDevice(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxGetDevice.retval); \
	printf("\thipDevice_t * device = %p", args->hipCtxGetDevice.device); \
	if (args->hipCtxGetDevice.device != NULL) { \
		printf(" -> %d\n", args->hipCtxGetDevice.device__ref.val); \
	} else { printf("\n"); }; \
};

//	void ** devPtr (void**);
//	const void * symbol (void*);
#define PROCESS_ARGS_hipGetSymbolAddress(args) { \
	printf("\thipError_t retval = %d\n", args->hipGetSymbolAddress.retval); \
	printf("\tvoid ** devPtr = %p", args->hipGetSymbolAddress.devPtr); \
	if (args->hipGetSymbolAddress.devPtr != NULL) { \
		printf("-> %p", args->hipGetSymbolAddress.devPtr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tconst void * symbol = %p", args->hipGetSymbolAddress.symbol); \
	printf("\n"); \
};

//	hipStream_t stream (opaque);
//	hipStreamCaptureStatus * captureStatus_out (enum*);
//	unsigned long long * id_out (unsigned long long*);
//	hipGraph_t * graph_out (opaque*);
//	const hipGraphNode_t ** dependencies_out (opaque**);
//	size_t * numDependencies_out (unsigned long*);
#define PROCESS_ARGS_hipStreamGetCaptureInfo_v2(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamGetCaptureInfo_v2.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamGetCaptureInfo_v2.stream); \
	printf("\thipStreamCaptureStatus * captureStatus_out = %p", args->hipStreamGetCaptureInfo_v2.captureStatus_out); \
	if (args->hipStreamGetCaptureInfo_v2.captureStatus_out != NULL) { \
		printf(" -> %d\n", args->hipStreamGetCaptureInfo_v2.captureStatus_out__ref.val); \
	} else { printf("\n"); }; \
	printf("\tunsigned long long * id_out = %p", args->hipStreamGetCaptureInfo_v2.id_out); \
	if (args->hipStreamGetCaptureInfo_v2.id_out != NULL) { \
		printf(" -> %llu\n", args->hipStreamGetCaptureInfo_v2.id_out__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t * graph_out = %p", args->hipStreamGetCaptureInfo_v2.graph_out); \
	if (args->hipStreamGetCaptureInfo_v2.graph_out != NULL) { \
		printf(" -> %p\n", args->hipStreamGetCaptureInfo_v2.graph_out__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst hipGraphNode_t ** dependencies_out = %p", args->hipStreamGetCaptureInfo_v2.dependencies_out); \
	if (args->hipStreamGetCaptureInfo_v2.dependencies_out != NULL) { \
		printf("-> %p", args->hipStreamGetCaptureInfo_v2.dependencies_out__ref.ptr1); \
		if (args->hipStreamGetCaptureInfo_v2.dependencies_out__ref.ptr1 != NULL) { \
			printf(" -> %p\n", args->hipStreamGetCaptureInfo_v2.dependencies_out__ref.val); \
		} else { printf("\n"); }; \
	} else { printf("\n"); }; \
	printf("\tsize_t * numDependencies_out = %p", args->hipStreamGetCaptureInfo_v2.numDependencies_out); \
	if (args->hipStreamGetCaptureInfo_v2.numDependencies_out != NULL) { \
		printf(" -> %lu\n", args->hipStreamGetCaptureInfo_v2.numDependencies_out__ref.val); \
	} else { printf("\n"); }; \
};

//	size_t* size (unsigned long*);
//	const void * symbol (void*);
#define PROCESS_ARGS_hipGetSymbolSize(args) { \
	printf("\thipError_t retval = %d\n", args->hipGetSymbolSize.retval); \
	printf("\tsize_t* size = %p", args->hipGetSymbolSize.size); \
	if (args->hipGetSymbolSize.size != NULL) { \
		printf(" -> %lu\n", args->hipGetSymbolSize.size__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst void * symbol = %p", args->hipGetSymbolSize.symbol); \
	printf("\n"); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
//	const hipHostNodeParams * pNodeParams ({
//		hipHostFn_t fn (function);
//	});
#define PROCESS_ARGS_hipGraphExecHostNodeSetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExecHostNodeSetParams.retval); \
	printf("\thipGraphExec_t hGraphExec = %p\n", args->hipGraphExecHostNodeSetParams.hGraphExec); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphExecHostNodeSetParams.node); \
	printf("\tconst hipHostNodeParams * pNodeParams = %p", args->hipGraphExecHostNodeSetParams.pNodeParams); \
	if (args->hipGraphExecHostNodeSetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipHostFn_t fn = %p\n", args->hipGraphExecHostNodeSetParams.pNodeParams__ref.val.fn); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipMemPool_t mem_pool (opaque);
//	hipMemPoolAttr attr (enum);
//	void * value (void*);
#define PROCESS_ARGS_hipMemPoolSetAttribute(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemPoolSetAttribute.retval); \
	printf("\thipMemPool_t mem_pool = %p\n", args->hipMemPoolSetAttribute.mem_pool); \
	printf("\thipMemPoolAttr attr = %d\n", args->hipMemPoolSetAttribute.attr); \
	printf("\tvoid * value = %p", args->hipMemPoolSetAttribute.value); \
	printf("\n"); \
};

//	int device (int);
//	hipMemPool_t mem_pool (opaque);
#define PROCESS_ARGS_hipDeviceSetMemPool(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceSetMemPool.retval); \
	printf("\tint device = %d\n", args->hipDeviceSetMemPool.device); \
	printf("\thipMemPool_t mem_pool = %p\n", args->hipDeviceSetMemPool.mem_pool); \
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
	printf("\thipError_t retval = %d\n", args->hipConfigureCall.retval); \
	printf("\tdim3 gridDim = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipConfigureCall.gridDim.x); \
	printf("\t\tuint32_t y = %u\n", args->hipConfigureCall.gridDim.y); \
	printf("\t\tuint32_t z = %u\n", args->hipConfigureCall.gridDim.z); \
	printf("\t}\n"); \
	printf("\tdim3 blockDim = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipConfigureCall.blockDim.x); \
	printf("\t\tuint32_t y = %u\n", args->hipConfigureCall.blockDim.y); \
	printf("\t\tuint32_t z = %u\n", args->hipConfigureCall.blockDim.z); \
	printf("\t}\n"); \
	printf("\tsize_t sharedMem = %lu\n", args->hipConfigureCall.sharedMem); \
	printf("\thipStream_t stream = %p\n", args->hipConfigureCall.stream); \
};

//	hipMipmappedArray_t * pHandle (unknown);
//	HIP_ARRAY3D_DESCRIPTOR * pMipmappedArrayDesc (unknown);
//	unsigned int numMipmapLevels (unsigned int);
#define PROCESS_ARGS_hipMipmappedArrayCreate(args) { \
	printf("\thipError_t retval = %d\n", args->hipMipmappedArrayCreate.retval); \
	printf("\thipMipmappedArray_t * pHandle = N/A, try to update csv files\n"); \
	printf("\tHIP_ARRAY3D_DESCRIPTOR * pMipmappedArrayDesc = N/A, try to update csv files\n"); \
	printf("\tunsigned int numMipmapLevels = %u\n", args->hipMipmappedArrayCreate.numMipmapLevels); \
};

//	void * hostPtr (void*);
//	size_t sizeBytes (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostRegister(args) { \
	printf("\thipError_t retval = %d\n", args->hipHostRegister.retval); \
	printf("\tvoid * hostPtr = %p", args->hipHostRegister.hostPtr); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipHostRegister.sizeBytes); \
	printf("\tunsigned int flags = %u\n", args->hipHostRegister.flags); \
};

//	const textureReference * tex (unknown);
//	hipArray_const_t array (unknown);
//	const hipChannelFormatDesc * desc (unknown);
#define PROCESS_ARGS_hipBindTextureToArray(args) { \
	printf("\thipError_t retval = %d\n", args->hipBindTextureToArray.retval); \
	printf("\tconst textureReference * tex = N/A, try to update csv files\n"); \
	printf("\thipArray_const_t array = N/A, try to update csv files\n"); \
	printf("\tconst hipChannelFormatDesc * desc = N/A, try to update csv files\n"); \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMallocHost(args) { \
	printf("\thipError_t retval = %d\n", args->hipMallocHost.retval); \
	printf("\tvoid ** ptr = %p", args->hipMallocHost.ptr); \
	if (args->hipMallocHost.ptr != NULL) { \
		printf("-> %p", args->hipMallocHost.ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipMallocHost.size); \
};

//	void * dst (void*);
//	int dstDeviceId (int);
//	const void * src (void*);
//	int srcDeviceId (int);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemcpyPeer(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyPeer.retval); \
	printf("\tvoid * dst = %p", args->hipMemcpyPeer.dst); \
	printf("\n"); \
	printf("\tint dstDeviceId = %d\n", args->hipMemcpyPeer.dstDeviceId); \
	printf("\tconst void * src = %p", args->hipMemcpyPeer.src); \
	printf("\n"); \
	printf("\tint srcDeviceId = %d\n", args->hipMemcpyPeer.srcDeviceId); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyPeer.sizeBytes); \
};

//	int * numBlocks (int*);
//	const void * f (void*);
//	int blockSize (int);
//	size_t dynSharedMemPerBlk (unsigned long);
#define PROCESS_ARGS_hipOccupancyMaxActiveBlocksPerMultiprocessor(args) { \
	printf("\thipError_t retval = %d\n", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.retval); \
	printf("\tint * numBlocks = %p", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks); \
	if (args->hipOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks != NULL) { \
		printf(" -> %d\n", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst void * f = %p", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.f); \
	printf("\n"); \
	printf("\tint blockSize = %d\n", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.blockSize); \
	printf("\tsize_t dynSharedMemPerBlk = %lu\n", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.dynSharedMemPerBlk); \
};

//	int * pi (int*);
//	hipDeviceAttribute_t attr (enum);
//	int deviceId (int);
#define PROCESS_ARGS_hipDeviceGetAttribute(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceGetAttribute.retval); \
	printf("\tint * pi = %p", args->hipDeviceGetAttribute.pi); \
	if (args->hipDeviceGetAttribute.pi != NULL) { \
		printf(" -> %d\n", args->hipDeviceGetAttribute.pi__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipDeviceAttribute_t attr = %d\n", args->hipDeviceGetAttribute.attr); \
	printf("\tint deviceId = %d\n", args->hipDeviceGetAttribute.deviceId); \
};

//	hipDevice_t dev (int);
#define PROCESS_ARGS_hipDevicePrimaryCtxReset(args) { \
	printf("\thipError_t retval = %d\n", args->hipDevicePrimaryCtxReset.retval); \
	printf("\thipDevice_t dev = %d\n", args->hipDevicePrimaryCtxReset.dev); \
};

//	size_t * ByteOffset (unsigned long*);
//	textureReference * texRef (unknown);
//	hipDeviceptr_t dptr (void*);
//	size_t bytes (unsigned long);
#define PROCESS_ARGS_hipTexRefSetAddress(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefSetAddress.retval); \
	printf("\tsize_t * ByteOffset = %p", args->hipTexRefSetAddress.ByteOffset); \
	if (args->hipTexRefSetAddress.ByteOffset != NULL) { \
		printf(" -> %lu\n", args->hipTexRefSetAddress.ByteOffset__ref.val); \
	} else { printf("\n"); }; \
	printf("\ttextureReference * texRef = N/A, try to update csv files\n"); \
	printf("\thipDeviceptr_t dptr = %p", args->hipTexRefSetAddress.dptr); \
	printf("\n"); \
	printf("\tsize_t bytes = %lu\n", args->hipTexRefSetAddress.bytes); \
};

//	void ** devPtr (void**);
//	size_t* size (unsigned long*);
//	hipGraphicsResource_t resource (opaque);
#define PROCESS_ARGS_hipGraphicsResourceGetMappedPointer(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphicsResourceGetMappedPointer.retval); \
	printf("\tvoid ** devPtr = %p", args->hipGraphicsResourceGetMappedPointer.devPtr); \
	if (args->hipGraphicsResourceGetMappedPointer.devPtr != NULL) { \
		printf("-> %p", args->hipGraphicsResourceGetMappedPointer.devPtr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t* size = %p", args->hipGraphicsResourceGetMappedPointer.size); \
	if (args->hipGraphicsResourceGetMappedPointer.size != NULL) { \
		printf(" -> %lu\n", args->hipGraphicsResourceGetMappedPointer.size__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraphicsResource_t resource = %p\n", args->hipGraphicsResourceGetMappedPointer.resource); \
};

//	hipSharedMemConfig config (enum);
#define PROCESS_ARGS_hipCtxSetSharedMemConfig(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxSetSharedMemConfig.retval); \
	printf("\thipSharedMemConfig config = %d\n", args->hipCtxSetSharedMemConfig.config); \
};

//	hipGraphNode_t hNode (opaque);
//	hipExternalSemaphoreSignalNodeParams * params_out ({
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphExternalSemaphoresSignalNodeGetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExternalSemaphoresSignalNodeGetParams.retval); \
	printf("\thipGraphNode_t hNode = %p\n", args->hipGraphExternalSemaphoresSignalNodeGetParams.hNode); \
	printf("\thipExternalSemaphoreSignalNodeParams * params_out = %p", args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out); \
	if (args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned int numExtSems = %u\n", args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out__ref.val.numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipArrayDestroy(args) { \
	printf("\thipError_t retval = %d\n", args->hipArrayDestroy.retval); \
	printf("\thipArray_t array = N/A, try to update csv files\n"); \
};

//	void * dev_ptr (void*);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipFreeAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipFreeAsync.retval); \
	printf("\tvoid * dev_ptr = %p", args->hipFreeAsync.dev_ptr); \
	printf("\n"); \
	printf("\thipStream_t stream = %p\n", args->hipFreeAsync.stream); \
};

//	HIP_ARRAY3D_DESCRIPTOR * pArrayDescriptor (unknown);
//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipArray3DGetDescriptor(args) { \
	printf("\thipError_t retval = %d\n", args->hipArray3DGetDescriptor.retval); \
	printf("\tHIP_ARRAY3D_DESCRIPTOR * pArrayDescriptor = N/A, try to update csv files\n"); \
	printf("\thipArray_t array = N/A, try to update csv files\n"); \
};

//	char * pciBusId (string*);
//	int len (int);
//	int device (int);
#define PROCESS_ARGS_hipDeviceGetPCIBusId(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceGetPCIBusId.retval); \
	printf("\tchar * pciBusId = %p", args->hipDeviceGetPCIBusId.pciBusId); \
	if (args->hipDeviceGetPCIBusId.pciBusId != NULL) { \
		printf(" -> %s\n", args->hipDeviceGetPCIBusId.pciBusId__ref.val); \
	} else { printf("\n"); }; \
	printf("\tint len = %d\n", args->hipDeviceGetPCIBusId.len); \
	printf("\tint device = %d\n", args->hipDeviceGetPCIBusId.device); \
};

//	hipGraphNode_t * pGraphNode (opaque*);
//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * pDependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	void * dev_ptr (void*);
#define PROCESS_ARGS_hipGraphAddMemFreeNode(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddMemFreeNode.retval); \
	printf("\thipGraphNode_t * pGraphNode = %p", args->hipGraphAddMemFreeNode.pGraphNode); \
	if (args->hipGraphAddMemFreeNode.pGraphNode != NULL) { \
		printf(" -> %p\n", args->hipGraphAddMemFreeNode.pGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddMemFreeNode.graph); \
	printf("\tconst hipGraphNode_t * pDependencies = %p", args->hipGraphAddMemFreeNode.pDependencies); \
	if (args->hipGraphAddMemFreeNode.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphAddMemFreeNode.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddMemFreeNode.numDependencies); \
	printf("\tvoid * dev_ptr = %p", args->hipGraphAddMemFreeNode.dev_ptr); \
	printf("\n"); \
};

//	hipArray_t * array (unknown);
//	const HIP_ARRAY3D_DESCRIPTOR * pAllocateArray (unknown);
#define PROCESS_ARGS_hipArray3DCreate(args) { \
	printf("\thipError_t retval = %d\n", args->hipArray3DCreate.retval); \
	printf("\thipArray_t * array = N/A, try to update csv files\n"); \
	printf("\tconst HIP_ARRAY3D_DESCRIPTOR * pAllocateArray = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t hNode (opaque);
//	const hipExternalSemaphoreSignalNodeParams * nodeParams ({
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphExternalSemaphoresSignalNodeSetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExternalSemaphoresSignalNodeSetParams.retval); \
	printf("\thipGraphNode_t hNode = %p\n", args->hipGraphExternalSemaphoresSignalNodeSetParams.hNode); \
	printf("\tconst hipExternalSemaphoreSignalNodeParams * nodeParams = %p", args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams); \
	if (args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned int numExtSems = %u\n", args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams__ref.val.numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	float * pBorderColor (float*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetBorderColor(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefGetBorderColor.retval); \
	printf("\tfloat * pBorderColor = %p", args->hipTexRefGetBorderColor.pBorderColor); \
	if (args->hipTexRefGetBorderColor.pBorderColor != NULL) { \
		printf(" -> %f\n", args->hipTexRefGetBorderColor.pBorderColor__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	hipDeviceptr_t * dptr (void**);
//	size_t* bytes (unsigned long*);
//	hipModule_t hmod (opaque);
//	const char * name (string*);
#define PROCESS_ARGS_hipModuleGetGlobal(args) { \
	printf("\thipError_t retval = %d\n", args->hipModuleGetGlobal.retval); \
	printf("\thipDeviceptr_t * dptr = %p", args->hipModuleGetGlobal.dptr); \
	if (args->hipModuleGetGlobal.dptr != NULL) { \
		printf("-> %p", args->hipModuleGetGlobal.dptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t* bytes = %p", args->hipModuleGetGlobal.bytes); \
	if (args->hipModuleGetGlobal.bytes != NULL) { \
		printf(" -> %lu\n", args->hipModuleGetGlobal.bytes__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipModule_t hmod = %p\n", args->hipModuleGetGlobal.hmod); \
	printf("\tconst char * name = %p", args->hipModuleGetGlobal.name); \
	if (args->hipModuleGetGlobal.name != NULL) { \
		printf(" -> %s\n", args->hipModuleGetGlobal.name__ref.val); \
	} else { printf("\n"); }; \
};

//	hipMipmappedArray_t * mipmappedArray (unknown);
//	const struct hipChannelFormatDesc * desc (unknown);
//	struct hipExtent extent (unknown);
//	unsigned int numLevels (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMallocMipmappedArray(args) { \
	printf("\thipError_t retval = %d\n", args->hipMallocMipmappedArray.retval); \
	printf("\thipMipmappedArray_t * mipmappedArray = N/A, try to update csv files\n"); \
	printf("\tconst struct hipChannelFormatDesc * desc = N/A, try to update csv files\n"); \
	printf("\tstruct hipExtent extent = N/A, try to update csv files\n"); \
	printf("\tunsigned int numLevels = %u\n", args->hipMallocMipmappedArray.numLevels); \
	printf("\tunsigned int flags = %u\n", args->hipMallocMipmappedArray.flags); \
};


#define PROCESS_ARGS_hipProfilerStart(args) { \
	printf("\thipError_t retval = %d\n", args->hipProfilerStart.retval); \
\
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
//	hipMemcpy3DParms * pNodeParams (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExecMemcpyNodeSetParams.retval); \
	printf("\thipGraphExec_t hGraphExec = %p\n", args->hipGraphExecMemcpyNodeSetParams.hGraphExec); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphExecMemcpyNodeSetParams.node); \
	printf("\thipMemcpy3DParms * pNodeParams = N/A, try to update csv files\n"); \
};

//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipEventSynchronize(args) { \
	printf("\thipError_t retval = %d\n", args->hipEventSynchronize.retval); \
	printf("\thipEvent_t event = %p\n", args->hipEventSynchronize.event); \
};

//	hipMemPoolPtrExportData * export_data ({
//		unsigned char[64] reserved (unsigned char);
//	});
//	void * dev_ptr (void*);
#define PROCESS_ARGS_hipMemPoolExportPointer(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemPoolExportPointer.retval); \
	printf("\thipMemPoolPtrExportData * export_data = %p", args->hipMemPoolExportPointer.export_data); \
	if (args->hipMemPoolExportPointer.export_data != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned char[64] reserved = %hhu\n", args->hipMemPoolExportPointer.export_data__ref.val.reserved[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tvoid * dev_ptr = %p", args->hipMemPoolExportPointer.dev_ptr); \
	printf("\n"); \
};

//	void * hostPtr (void*);
#define PROCESS_ARGS_hipHostUnregister(args) { \
	printf("\thipError_t retval = %d\n", args->hipHostUnregister.retval); \
	printf("\tvoid * hostPtr = %p", args->hipHostUnregister.hostPtr); \
	printf("\n"); \
};

//	void * dst (void*);
//	size_t pitch (unsigned long);
//	int value (int);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
#define PROCESS_ARGS_hipMemset2D(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemset2D.retval); \
	printf("\tvoid * dst = %p", args->hipMemset2D.dst); \
	printf("\n"); \
	printf("\tsize_t pitch = %lu\n", args->hipMemset2D.pitch); \
	printf("\tint value = %d\n", args->hipMemset2D.value); \
	printf("\tsize_t width = %lu\n", args->hipMemset2D.width); \
	printf("\tsize_t height = %lu\n", args->hipMemset2D.height); \
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
	printf("\thipError_t retval = %d\n", args->hipMemcpy2DFromArray.retval); \
	printf("\tvoid * dst = %p", args->hipMemcpy2DFromArray.dst); \
	printf("\n"); \
	printf("\tsize_t dpitch = %lu\n", args->hipMemcpy2DFromArray.dpitch); \
	printf("\thipArray_const_t src = N/A, try to update csv files\n"); \
	printf("\tsize_t wOffset = %lu\n", args->hipMemcpy2DFromArray.wOffset); \
	printf("\tsize_t hOffset = %lu\n", args->hipMemcpy2DFromArray.hOffset); \
	printf("\tsize_t width = %lu\n", args->hipMemcpy2DFromArray.width); \
	printf("\tsize_t height = %lu\n", args->hipMemcpy2DFromArray.height); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
//	size_t alignment (unsigned long);
//	void * addr (void*);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipMemAddressReserve(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemAddressReserve.retval); \
	printf("\tvoid ** ptr = %p", args->hipMemAddressReserve.ptr); \
	if (args->hipMemAddressReserve.ptr != NULL) { \
		printf("-> %p", args->hipMemAddressReserve.ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipMemAddressReserve.size); \
	printf("\tsize_t alignment = %lu\n", args->hipMemAddressReserve.alignment); \
	printf("\tvoid * addr = %p", args->hipMemAddressReserve.addr); \
	printf("\n"); \
	printf("\tunsigned long long flags = %llu\n", args->hipMemAddressReserve.flags); \
};

//	const void * func (void*);
//	hipSharedMemConfig config (enum);
#define PROCESS_ARGS_hipFuncSetSharedMemConfig(args) { \
	printf("\thipError_t retval = %d\n", args->hipFuncSetSharedMemConfig.retval); \
	printf("\tconst void * func = %p", args->hipFuncSetSharedMemConfig.func); \
	printf("\n"); \
	printf("\thipSharedMemConfig config = %d\n", args->hipFuncSetSharedMemConfig.config); \
};

//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipDestroyTextureObject(args) { \
	printf("\thipError_t retval = %d\n", args->hipDestroyTextureObject.retval); \
	printf("\thipTextureObject_t textureObject = N/A, try to update csv files\n"); \
};

//	textureReference* texRef (unknown);
//	unsigned int maxAniso (unsigned int);
#define PROCESS_ARGS_hipTexRefSetMaxAnisotropy(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefSetMaxAnisotropy.retval); \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tunsigned int maxAniso = %u\n", args->hipTexRefSetMaxAnisotropy.maxAniso); \
};

//	textureReference* texRef (unknown);
//	const HIP_ARRAY_DESCRIPTOR * desc (unknown);
//	hipDeviceptr_t dptr (void*);
//	size_t Pitch (unsigned long);
#define PROCESS_ARGS_hipTexRefSetAddress2D(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefSetAddress2D.retval); \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tconst HIP_ARRAY_DESCRIPTOR * desc = N/A, try to update csv files\n"); \
	printf("\thipDeviceptr_t dptr = %p", args->hipTexRefSetAddress2D.dptr); \
	printf("\n"); \
	printf("\tsize_t Pitch = %lu\n", args->hipTexRefSetAddress2D.Pitch); \
};

//	int * deviceId (int*);
#define PROCESS_ARGS_hipGetDevice(args) { \
	printf("\thipError_t retval = %d\n", args->hipGetDevice.retval); \
	printf("\tint * deviceId = %p", args->hipGetDevice.deviceId); \
	if (args->hipGetDevice.deviceId != NULL) { \
		printf(" -> %d\n", args->hipGetDevice.deviceId__ref.val); \
	} else { printf("\n"); }; \
};

//	int device (int);
//	hipGraphMemAttributeType attr (enum);
//	void * value (void*);
#define PROCESS_ARGS_hipDeviceGetGraphMemAttribute(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceGetGraphMemAttribute.retval); \
	printf("\tint device = %d\n", args->hipDeviceGetGraphMemAttribute.device); \
	printf("\thipGraphMemAttributeType attr = %d\n", args->hipDeviceGetGraphMemAttribute.attr); \
	printf("\tvoid * value = %p", args->hipDeviceGetGraphMemAttribute.value); \
	printf("\n"); \
};

//	hipArray_t * array (unknown);
//	hipGraphicsResource_t resource (opaque);
//	unsigned int arrayIndex (unsigned int);
//	unsigned int mipLevel (unsigned int);
#define PROCESS_ARGS_hipGraphicsSubResourceGetMappedArray(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphicsSubResourceGetMappedArray.retval); \
	printf("\thipArray_t * array = N/A, try to update csv files\n"); \
	printf("\thipGraphicsResource_t resource = %p\n", args->hipGraphicsSubResourceGetMappedArray.resource); \
	printf("\tunsigned int arrayIndex = %u\n", args->hipGraphicsSubResourceGetMappedArray.arrayIndex); \
	printf("\tunsigned int mipLevel = %u\n", args->hipGraphicsSubResourceGetMappedArray.mipLevel); \
};

//	hipGraphNode_t node (opaque);
//	const void * symbol (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParamsToSymbol(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphMemcpyNodeSetParamsToSymbol.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphMemcpyNodeSetParamsToSymbol.node); \
	printf("\tconst void * symbol = %p", args->hipGraphMemcpyNodeSetParamsToSymbol.symbol); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipGraphMemcpyNodeSetParamsToSymbol.src); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipGraphMemcpyNodeSetParamsToSymbol.count); \
	printf("\tsize_t offset = %lu\n", args->hipGraphMemcpyNodeSetParamsToSymbol.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	hipStream_t * stream (opaque*);
#define PROCESS_ARGS_hipStreamCreate(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamCreate.retval); \
	printf("\thipStream_t * stream = %p", args->hipStreamCreate.stream); \
	if (args->hipStreamCreate.stream != NULL) { \
		printf(" -> %p\n", args->hipStreamCreate.stream__ref.val); \
	} else { printf("\n"); }; \
};

//	hipGraphNode_t node (opaque);
//	hipGraphNode_t * pDependencies (opaque*);
//	size_t* pNumDependencies (unsigned long*);
#define PROCESS_ARGS_hipGraphNodeGetDependencies(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphNodeGetDependencies.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphNodeGetDependencies.node); \
	printf("\thipGraphNode_t * pDependencies = %p", args->hipGraphNodeGetDependencies.pDependencies); \
	if (args->hipGraphNodeGetDependencies.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphNodeGetDependencies.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t* pNumDependencies = %p", args->hipGraphNodeGetDependencies.pNumDependencies); \
	if (args->hipGraphNodeGetDependencies.pNumDependencies != NULL) { \
		printf(" -> %lu\n", args->hipGraphNodeGetDependencies.pNumDependencies__ref.val); \
	} else { printf("\n"); }; \
};

//	const textureReference* tex (unknown);
//	hipMipmappedArray_const_t mipmappedArray (unknown);
//	const hipChannelFormatDesc* desc (unknown);
#define PROCESS_ARGS_hipBindTextureToMipmappedArray(args) { \
	printf("\thipError_t retval = %d\n", args->hipBindTextureToMipmappedArray.retval); \
	printf("\tconst textureReference* tex = N/A, try to update csv files\n"); \
	printf("\thipMipmappedArray_const_t mipmappedArray = N/A, try to update csv files\n"); \
	printf("\tconst hipChannelFormatDesc* desc = N/A, try to update csv files\n"); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraph_t hGraph (opaque);
//	hipGraphNode_t * hErrorNode_out (opaque*);
//	hipGraphExecUpdateResult * updateResult_out (enum*);
#define PROCESS_ARGS_hipGraphExecUpdate(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExecUpdate.retval); \
	printf("\thipGraphExec_t hGraphExec = %p\n", args->hipGraphExecUpdate.hGraphExec); \
	printf("\thipGraph_t hGraph = %p\n", args->hipGraphExecUpdate.hGraph); \
	printf("\thipGraphNode_t * hErrorNode_out = %p", args->hipGraphExecUpdate.hErrorNode_out); \
	if (args->hipGraphExecUpdate.hErrorNode_out != NULL) { \
		printf(" -> %p\n", args->hipGraphExecUpdate.hErrorNode_out__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraphExecUpdateResult * updateResult_out = %p", args->hipGraphExecUpdate.updateResult_out); \
	if (args->hipGraphExecUpdate.updateResult_out != NULL) { \
		printf(" -> %d\n", args->hipGraphExecUpdate.updateResult_out__ref.val); \
	} else { printf("\n"); }; \
};

//	size_t* bytes (unsigned long*);
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceTotalMem(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceTotalMem.retval); \
	printf("\tsize_t* bytes = %p", args->hipDeviceTotalMem.bytes); \
	if (args->hipDeviceTotalMem.bytes != NULL) { \
		printf(" -> %lu\n", args->hipDeviceTotalMem.bytes__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipDevice_t device = %d\n", args->hipDeviceTotalMem.device); \
};

//	void * dst (void*);
//	hipArray_const_t srcArray (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpyFromArray(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyFromArray.retval); \
	printf("\tvoid * dst = %p", args->hipMemcpyFromArray.dst); \
	printf("\n"); \
	printf("\thipArray_const_t srcArray = N/A, try to update csv files\n"); \
	printf("\tsize_t wOffset = %lu\n", args->hipMemcpyFromArray.wOffset); \
	printf("\tsize_t hOffset = %lu\n", args->hipMemcpyFromArray.hOffset); \
	printf("\tsize_t count = %lu\n", args->hipMemcpyFromArray.count); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	hipEvent_t * event (opaque*);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipEventCreateWithFlags(args) { \
	printf("\thipError_t retval = %d\n", args->hipEventCreateWithFlags.retval); \
	printf("\thipEvent_t * event = %p", args->hipEventCreateWithFlags.event); \
	if (args->hipEventCreateWithFlags.event != NULL) { \
		printf(" -> %p\n", args->hipEventCreateWithFlags.event__ref.val); \
	} else { printf("\n"); }; \
	printf("\tunsigned int flags = %u\n", args->hipEventCreateWithFlags.flags); \
};

//	hipFuncCache_t * cacheConfig (enum*);
#define PROCESS_ARGS_hipDeviceGetCacheConfig(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceGetCacheConfig.retval); \
	printf("\thipFuncCache_t * cacheConfig = %p", args->hipDeviceGetCacheConfig.cacheConfig); \
	if (args->hipDeviceGetCacheConfig.cacheConfig != NULL) { \
		printf(" -> %d\n", args->hipDeviceGetCacheConfig.cacheConfig__ref.val); \
	} else { printf("\n"); }; \
};

//	int * driverVersion (int*);
#define PROCESS_ARGS_hipDriverGetVersion(args) { \
	printf("\thipError_t retval = %d\n", args->hipDriverGetVersion.retval); \
	printf("\tint * driverVersion = %p", args->hipDriverGetVersion.driverVersion); \
	if (args->hipDriverGetVersion.driverVersion != NULL) { \
		printf(" -> %d\n", args->hipDriverGetVersion.driverVersion__ref.val); \
	} else { printf("\n"); }; \
};

//	hipGraphNode_t node (opaque);
//	void * dst (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParams1D(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphMemcpyNodeSetParams1D.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphMemcpyNodeSetParams1D.node); \
	printf("\tvoid * dst = %p", args->hipGraphMemcpyNodeSetParams1D.dst); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipGraphMemcpyNodeSetParams1D.src); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipGraphMemcpyNodeSetParams1D.count); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	textureReference* texRef (unknown);
//	float minMipMapLevelClamp (float);
//	float maxMipMapLevelClamp (float);
#define PROCESS_ARGS_hipTexRefSetMipmapLevelClamp(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefSetMipmapLevelClamp.retval); \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tfloat minMipMapLevelClamp = %f\n", args->hipTexRefSetMipmapLevelClamp.minMipMapLevelClamp); \
	printf("\tfloat maxMipMapLevelClamp = %f\n", args->hipTexRefSetMipmapLevelClamp.maxMipMapLevelClamp); \
};

//	hipGraphNode_t node (opaque);
//	hipMemAllocNodeParams * pNodeParams ({
//		hipMemPoolProps poolProps ({
//			hipMemAllocationType allocType (enum);
//			hipMemAllocationHandleType handleTypes (enum);
//			hipMemLocation location ({
//				hipMemLocationType type (enum);
//				int id (int);
//			});
//			unsigned char[64] reserved (unsigned char);
//		});
//		int accessDescCount (int);
//		int bytesize (int);
//	});
#define PROCESS_ARGS_hipGraphMemAllocNodeGetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphMemAllocNodeGetParams.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphMemAllocNodeGetParams.node); \
	printf("\thipMemAllocNodeParams * pNodeParams = %p", args->hipGraphMemAllocNodeGetParams.pNodeParams); \
	if (args->hipGraphMemAllocNodeGetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemPoolProps poolProps = {\n"); \
		printf("\t\t\thipMemAllocationType allocType = %d\n", args->hipGraphMemAllocNodeGetParams.pNodeParams__ref.val.poolProps.allocType); \
		printf("\t\t\thipMemAllocationHandleType handleTypes = %d\n", args->hipGraphMemAllocNodeGetParams.pNodeParams__ref.val.poolProps.handleTypes); \
		printf("\t\t\thipMemLocation location = {\n"); \
		printf("\t\t\t\thipMemLocationType type = %d\n", args->hipGraphMemAllocNodeGetParams.pNodeParams__ref.val.poolProps.location.type); \
		printf("\t\t\t\tint id = %d\n", args->hipGraphMemAllocNodeGetParams.pNodeParams__ref.val.poolProps.location.id); \
		printf("\t\t\t}\n"); \
		printf("\t\t\tunsigned char[64] reserved = %hhu\n", args->hipGraphMemAllocNodeGetParams.pNodeParams__ref.val.poolProps.reserved[0]); \
		printf("\t\t}\n"); \
		printf("\t\tint accessDescCount = %d\n", args->hipGraphMemAllocNodeGetParams.pNodeParams__ref.val.accessDescCount); \
		printf("\t\tint bytesize = %d\n", args->hipGraphMemAllocNodeGetParams.pNodeParams__ref.val.bytesize); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectDestroy(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexObjectDestroy.retval); \
	printf("\thipTextureObject_t texObject = N/A, try to update csv files\n"); \
};

//	hipStream_t * stream (opaque*);
//	uint32_t cuMaskSize (unsigned int);
//	const uint32_t * cuMask (unsigned int*);
#define PROCESS_ARGS_hipExtStreamCreateWithCUMask(args) { \
	printf("\thipError_t retval = %d\n", args->hipExtStreamCreateWithCUMask.retval); \
	printf("\thipStream_t * stream = %p", args->hipExtStreamCreateWithCUMask.stream); \
	if (args->hipExtStreamCreateWithCUMask.stream != NULL) { \
		printf(" -> %p\n", args->hipExtStreamCreateWithCUMask.stream__ref.val); \
	} else { printf("\n"); }; \
	printf("\tuint32_t cuMaskSize = %u\n", args->hipExtStreamCreateWithCUMask.cuMaskSize); \
	printf("\tconst uint32_t * cuMask = %p", args->hipExtStreamCreateWithCUMask.cuMask); \
	if (args->hipExtStreamCreateWithCUMask.cuMask != NULL) { \
		printf(" -> %u\n", args->hipExtStreamCreateWithCUMask.cuMask__ref.val); \
	} else { printf("\n"); }; \
};

//	dim3 * gridDim ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	dim3 * blockDim ({
//		uint32_t x (unsigned int);
//		uint32_t y (unsigned int);
//		uint32_t z (unsigned int);
//	});
//	size_t * sharedMem (unsigned long*);
//	hipStream_t * stream (opaque*);
#define PROCESS_ARGS___hipPopCallConfiguration(args) { \
	printf("\thipError_t retval = %d\n", args->__hipPopCallConfiguration.retval); \
	printf("\tdim3 * gridDim = %p", args->__hipPopCallConfiguration.gridDim); \
	if (args->__hipPopCallConfiguration.gridDim != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t x = %u\n", args->__hipPopCallConfiguration.gridDim__ref.val.x); \
		printf("\t\tuint32_t y = %u\n", args->__hipPopCallConfiguration.gridDim__ref.val.y); \
		printf("\t\tuint32_t z = %u\n", args->__hipPopCallConfiguration.gridDim__ref.val.z); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tdim3 * blockDim = %p", args->__hipPopCallConfiguration.blockDim); \
	if (args->__hipPopCallConfiguration.blockDim != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t x = %u\n", args->__hipPopCallConfiguration.blockDim__ref.val.x); \
		printf("\t\tuint32_t y = %u\n", args->__hipPopCallConfiguration.blockDim__ref.val.y); \
		printf("\t\tuint32_t z = %u\n", args->__hipPopCallConfiguration.blockDim__ref.val.z); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t * sharedMem = %p", args->__hipPopCallConfiguration.sharedMem); \
	if (args->__hipPopCallConfiguration.sharedMem != NULL) { \
		printf(" -> %lu\n", args->__hipPopCallConfiguration.sharedMem__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipStream_t * stream = %p", args->__hipPopCallConfiguration.stream); \
	if (args->__hipPopCallConfiguration.stream != NULL) { \
		printf(" -> %p\n", args->__hipPopCallConfiguration.stream__ref.val); \
	} else { printf("\n"); }; \
};

//	void * data (void*);
//	size_t data_size (unsigned long);
//	hipMemRangeAttribute attribute (enum);
//	const void * dev_ptr (void*);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemRangeGetAttribute(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemRangeGetAttribute.retval); \
	printf("\tvoid * data = %p", args->hipMemRangeGetAttribute.data); \
	printf("\n"); \
	printf("\tsize_t data_size = %lu\n", args->hipMemRangeGetAttribute.data_size); \
	printf("\thipMemRangeAttribute attribute = %d\n", args->hipMemRangeGetAttribute.attribute); \
	printf("\tconst void * dev_ptr = %p", args->hipMemRangeGetAttribute.dev_ptr); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipMemRangeGetAttribute.count); \
};

//	void * ptr (void*);
//	size_t size (unsigned long);
//	size_t offset (unsigned long);
//	hipMemGenericAllocationHandle_t handle (opaque);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipMemMap(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemMap.retval); \
	printf("\tvoid * ptr = %p", args->hipMemMap.ptr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hipMemMap.size); \
	printf("\tsize_t offset = %lu\n", args->hipMemMap.offset); \
	printf("\thipMemGenericAllocationHandle_t handle = %p\n", args->hipMemMap.handle); \
	printf("\tunsigned long long flags = %llu\n", args->hipMemMap.flags); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipStreamSynchronize(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamSynchronize.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamSynchronize.stream); \
};

//	hipUserObject_t * object_out (opaque*);
//	void * ptr (void*);
//	hipHostFn_t destroy (function);
//	unsigned int initialRefcount (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipUserObjectCreate(args) { \
	printf("\thipError_t retval = %d\n", args->hipUserObjectCreate.retval); \
	printf("\thipUserObject_t * object_out = %p", args->hipUserObjectCreate.object_out); \
	if (args->hipUserObjectCreate.object_out != NULL) { \
		printf(" -> %p\n", args->hipUserObjectCreate.object_out__ref.val); \
	} else { printf("\n"); }; \
	printf("\tvoid * ptr = %p", args->hipUserObjectCreate.ptr); \
	printf("\n"); \
	printf("\thipHostFn_t destroy = %p\n", args->hipUserObjectCreate.destroy); \
	printf("\tunsigned int initialRefcount = %u\n", args->hipUserObjectCreate.initialRefcount); \
	printf("\tunsigned int flags = %u\n", args->hipUserObjectCreate.flags); \
};

//	hipArray_t * levelArray (unknown);
//	hipMipmappedArray_const_t mipmappedArray (unknown);
//	unsigned int level (unsigned int);
#define PROCESS_ARGS_hipGetMipmappedArrayLevel(args) { \
	printf("\thipError_t retval = %d\n", args->hipGetMipmappedArrayLevel.retval); \
	printf("\thipArray_t * levelArray = N/A, try to update csv files\n"); \
	printf("\thipMipmappedArray_const_t mipmappedArray = N/A, try to update csv files\n"); \
	printf("\tunsigned int level = %u\n", args->hipGetMipmappedArrayLevel.level); \
};

//	hipDeviceptr_t dst (void*);
//	void * src (void*);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemcpyHtoD(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyHtoD.retval); \
	printf("\thipDeviceptr_t dst = %p", args->hipMemcpyHtoD.dst); \
	printf("\n"); \
	printf("\tvoid * src = %p", args->hipMemcpyHtoD.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyHtoD.sizeBytes); \
};

//	hipDeviceptr_t * pbase (void**);
//	size_t * psize (unsigned long*);
//	hipDeviceptr_t dptr (void*);
#define PROCESS_ARGS_hipMemGetAddressRange(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemGetAddressRange.retval); \
	printf("\thipDeviceptr_t * pbase = %p", args->hipMemGetAddressRange.pbase); \
	if (args->hipMemGetAddressRange.pbase != NULL) { \
		printf("-> %p", args->hipMemGetAddressRange.pbase__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t * psize = %p", args->hipMemGetAddressRange.psize); \
	if (args->hipMemGetAddressRange.psize != NULL) { \
		printf(" -> %lu\n", args->hipMemGetAddressRange.psize__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipDeviceptr_t dptr = %p", args->hipMemGetAddressRange.dptr); \
	printf("\n"); \
};

//	hipGraphNode_t * pGraphNode (opaque*);
//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * pDependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	void * dst (void*);
//	const void * symbol (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphAddMemcpyNodeFromSymbol(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddMemcpyNodeFromSymbol.retval); \
	printf("\thipGraphNode_t * pGraphNode = %p", args->hipGraphAddMemcpyNodeFromSymbol.pGraphNode); \
	if (args->hipGraphAddMemcpyNodeFromSymbol.pGraphNode != NULL) { \
		printf(" -> %p\n", args->hipGraphAddMemcpyNodeFromSymbol.pGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddMemcpyNodeFromSymbol.graph); \
	printf("\tconst hipGraphNode_t * pDependencies = %p", args->hipGraphAddMemcpyNodeFromSymbol.pDependencies); \
	if (args->hipGraphAddMemcpyNodeFromSymbol.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphAddMemcpyNodeFromSymbol.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddMemcpyNodeFromSymbol.numDependencies); \
	printf("\tvoid * dst = %p", args->hipGraphAddMemcpyNodeFromSymbol.dst); \
	printf("\n"); \
	printf("\tconst void * symbol = %p", args->hipGraphAddMemcpyNodeFromSymbol.symbol); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipGraphAddMemcpyNodeFromSymbol.count); \
	printf("\tsize_t offset = %lu\n", args->hipGraphAddMemcpyNodeFromSymbol.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	void * ptr (void*);
//	size_t* size (unsigned long*);
#define PROCESS_ARGS_hipMemPtrGetInfo(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemPtrGetInfo.retval); \
	printf("\tvoid * ptr = %p", args->hipMemPtrGetInfo.ptr); \
	printf("\n"); \
	printf("\tsize_t* size = %p", args->hipMemPtrGetInfo.size); \
	if (args->hipMemPtrGetInfo.size != NULL) { \
		printf(" -> %lu\n", args->hipMemPtrGetInfo.size__ref.val); \
	} else { printf("\n"); }; \
};

//	textureReference* texRef (unknown);
//	struct hipMipmappedArray * mipmappedArray (unknown);
//	unsigned int Flags (unsigned int);
#define PROCESS_ARGS_hipTexRefSetMipmappedArray(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefSetMipmappedArray.retval); \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tstruct hipMipmappedArray * mipmappedArray = N/A, try to update csv files\n"); \
	printf("\tunsigned int Flags = %u\n", args->hipTexRefSetMipmappedArray.Flags); \
};

//	hipExternalSemaphore_t * extSem_out (void**);
//	const hipExternalSemaphoreHandleDesc * semHandleDesc ({
//		hipExternalSemaphoreHandleType type (enum);
//		union (unnamed union at ./input/hip_runtime_api.h:1123:3) handle ({
//			int fd (int);
//			struct (unnamed struct at ./input/hip_runtime_api.h:1125:5) win32 ({
//			});
//		});
//		unsigned int flags (unsigned int);
//		unsigned int[16] reserved (unsigned int);
//	});
#define PROCESS_ARGS_hipImportExternalSemaphore(args) { \
	printf("\thipError_t retval = %d\n", args->hipImportExternalSemaphore.retval); \
	printf("\thipExternalSemaphore_t * extSem_out = %p", args->hipImportExternalSemaphore.extSem_out); \
	if (args->hipImportExternalSemaphore.extSem_out != NULL) { \
		printf("-> %p", args->hipImportExternalSemaphore.extSem_out__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tconst hipExternalSemaphoreHandleDesc * semHandleDesc = %p", args->hipImportExternalSemaphore.semHandleDesc); \
	if (args->hipImportExternalSemaphore.semHandleDesc != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipExternalSemaphoreHandleType type = %d\n", args->hipImportExternalSemaphore.semHandleDesc__ref.val.type); \
		printf("\t\tunion (unnamed union at ./input/hip_runtime_api.h:1123:3) handle = {\n"); \
		printf("\t\t\tint fd = %d\n", args->hipImportExternalSemaphore.semHandleDesc__ref.val.handle.fd); \
		printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1125:5) win32 = {\n"); \
		printf("\t\t\t}\n"); \
		printf("\t\t}\n"); \
		printf("\t\tunsigned int flags = %u\n", args->hipImportExternalSemaphore.semHandleDesc__ref.val.flags); \
		printf("\t\tunsigned int[16] reserved = %u\n", args->hipImportExternalSemaphore.semHandleDesc__ref.val.reserved[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipStream_t stream (opaque);
//	hipEvent_t event (opaque);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamWaitEvent(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamWaitEvent.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamWaitEvent.stream); \
	printf("\thipEvent_t event = %p\n", args->hipStreamWaitEvent.event); \
	printf("\tunsigned int flags = %u\n", args->hipStreamWaitEvent.flags); \
};

//	int * count (int*);
#define PROCESS_ARGS_hipGetDeviceCount(args) { \
	printf("\thipError_t retval = %d\n", args->hipGetDeviceCount.retval); \
	printf("\tint * count = %p", args->hipGetDeviceCount.count); \
	if (args->hipGetDeviceCount.count != NULL) { \
		printf(" -> %d\n", args->hipGetDeviceCount.count__ref.val); \
	} else { printf("\n"); }; \
};

//	hipGraphNode_t hSrc (opaque);
//	hipGraphNode_t hDst (opaque);
#define PROCESS_ARGS_hipGraphKernelNodeCopyAttributes(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphKernelNodeCopyAttributes.retval); \
	printf("\thipGraphNode_t hSrc = %p\n", args->hipGraphKernelNodeCopyAttributes.hSrc); \
	printf("\thipGraphNode_t hDst = %p\n", args->hipGraphKernelNodeCopyAttributes.hDst); \
};

//	hipExternalSemaphore_t extSem (void*);
#define PROCESS_ARGS_hipDestroyExternalSemaphore(args) { \
	printf("\thipError_t retval = %d\n", args->hipDestroyExternalSemaphore.retval); \
	printf("\thipExternalSemaphore_t extSem = %p", args->hipDestroyExternalSemaphore.extSem); \
	printf("\n"); \
};

//	hipGraphNode_t node (opaque);
//	const hipMemcpy3DParms* pNodeParams (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphMemcpyNodeSetParams.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphMemcpyNodeSetParams.node); \
	printf("\tconst hipMemcpy3DParms* pNodeParams = N/A, try to update csv files\n"); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipStreamQuery(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamQuery.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamQuery.stream); \
};

//	hipGraphNode_t node (opaque);
//	const hipMemsetParams * pNodeParams ({
//		unsigned int elementSize (unsigned int);
//		size_t height (unsigned long);
//		size_t pitch (unsigned long);
//		unsigned int value (unsigned int);
//		size_t width (unsigned long);
//	});
#define PROCESS_ARGS_hipGraphMemsetNodeSetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphMemsetNodeSetParams.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphMemsetNodeSetParams.node); \
	printf("\tconst hipMemsetParams * pNodeParams = %p", args->hipGraphMemsetNodeSetParams.pNodeParams); \
	if (args->hipGraphMemsetNodeSetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned int elementSize = %u\n", args->hipGraphMemsetNodeSetParams.pNodeParams__ref.val.elementSize); \
		printf("\t\tsize_t height = %lu\n", args->hipGraphMemsetNodeSetParams.pNodeParams__ref.val.height); \
		printf("\t\tsize_t pitch = %lu\n", args->hipGraphMemsetNodeSetParams.pNodeParams__ref.val.pitch); \
		printf("\t\tunsigned int value = %u\n", args->hipGraphMemsetNodeSetParams.pNodeParams__ref.val.value); \
		printf("\t\tsize_t width = %lu\n", args->hipGraphMemsetNodeSetParams.pNodeParams__ref.val.width); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	int * runtimeVersion (int*);
#define PROCESS_ARGS_hipRuntimeGetVersion(args) { \
	printf("\thipError_t retval = %d\n", args->hipRuntimeGetVersion.retval); \
	printf("\tint * runtimeVersion = %p", args->hipRuntimeGetVersion.runtimeVersion); \
	if (args->hipRuntimeGetVersion.runtimeVersion != NULL) { \
		printf(" -> %d\n", args->hipRuntimeGetVersion.runtimeVersion__ref.val); \
	} else { printf("\n"); }; \
};

//	HIP_ARRAY_DESCRIPTOR* pArrayDescriptor (unknown);
//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipArrayGetDescriptor(args) { \
	printf("\thipError_t retval = %d\n", args->hipArrayGetDescriptor.retval); \
	printf("\tHIP_ARRAY_DESCRIPTOR* pArrayDescriptor = N/A, try to update csv files\n"); \
	printf("\thipArray_t array = N/A, try to update csv files\n"); \
};

//	hipDeviceptr_t dst (void*);
//	int value (int);
//	size_t count (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemsetD32Async(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemsetD32Async.retval); \
	printf("\thipDeviceptr_t dst = %p", args->hipMemsetD32Async.dst); \
	printf("\n"); \
	printf("\tint value = %d\n", args->hipMemsetD32Async.value); \
	printf("\tsize_t count = %lu\n", args->hipMemsetD32Async.count); \
	printf("\thipStream_t stream = %p\n", args->hipMemsetD32Async.stream); \
};

//	hipSharedMemConfig * pConfig (enum*);
#define PROCESS_ARGS_hipCtxGetSharedMemConfig(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxGetSharedMemConfig.retval); \
	printf("\thipSharedMemConfig * pConfig = %p", args->hipCtxGetSharedMemConfig.pConfig); \
	if (args->hipCtxGetSharedMemConfig.pConfig != NULL) { \
		printf(" -> %d\n", args->hipCtxGetSharedMemConfig.pConfig__ref.val); \
	} else { printf("\n"); }; \
};

//	hipModule_t * module (opaque*);
//	const void * image (void*);
//	unsigned int numOptions (unsigned int);
//	hipJitOption * options (enum*);
//	void ** optionValues (void**);
#define PROCESS_ARGS_hipModuleLoadDataEx(args) { \
	printf("\thipError_t retval = %d\n", args->hipModuleLoadDataEx.retval); \
	printf("\thipModule_t * module = %p", args->hipModuleLoadDataEx.module); \
	if (args->hipModuleLoadDataEx.module != NULL) { \
		printf(" -> %p\n", args->hipModuleLoadDataEx.module__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst void * image = %p", args->hipModuleLoadDataEx.image); \
	printf("\n"); \
	printf("\tunsigned int numOptions = %u\n", args->hipModuleLoadDataEx.numOptions); \
	printf("\thipJitOption * options = %p", args->hipModuleLoadDataEx.options); \
	if (args->hipModuleLoadDataEx.options != NULL) { \
		printf(" -> %d\n", args->hipModuleLoadDataEx.options__ref.val); \
	} else { printf("\n"); }; \
	printf("\tvoid ** optionValues = %p", args->hipModuleLoadDataEx.optionValues); \
	if (args->hipModuleLoadDataEx.optionValues != NULL) { \
		printf("-> %p", args->hipModuleLoadDataEx.optionValues__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
};

//	void * shared_handle (void*);
//	hipMemPool_t mem_pool (opaque);
//	hipMemAllocationHandleType handle_type (enum);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMemPoolExportToShareableHandle(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemPoolExportToShareableHandle.retval); \
	printf("\tvoid * shared_handle = %p", args->hipMemPoolExportToShareableHandle.shared_handle); \
	printf("\n"); \
	printf("\thipMemPool_t mem_pool = %p\n", args->hipMemPoolExportToShareableHandle.mem_pool); \
	printf("\thipMemAllocationHandleType handle_type = %d\n", args->hipMemPoolExportToShareableHandle.handle_type); \
	printf("\tunsigned int flags = %u\n", args->hipMemPoolExportToShareableHandle.flags); \
};

//	void ** dev_ptr (void**);
//	size_t size (unsigned long);
//	hipMemPool_t mem_pool (opaque);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMallocFromPoolAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMallocFromPoolAsync.retval); \
	printf("\tvoid ** dev_ptr = %p", args->hipMallocFromPoolAsync.dev_ptr); \
	if (args->hipMallocFromPoolAsync.dev_ptr != NULL) { \
		printf("-> %p", args->hipMallocFromPoolAsync.dev_ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipMallocFromPoolAsync.size); \
	printf("\thipMemPool_t mem_pool = %p\n", args->hipMallocFromPoolAsync.mem_pool); \
	printf("\thipStream_t stream = %p\n", args->hipMallocFromPoolAsync.stream); \
};

//	int deviceId (int);
#define PROCESS_ARGS_hipSetDevice(args) { \
	printf("\thipError_t retval = %d\n", args->hipSetDevice.retval); \
	printf("\tint deviceId = %d\n", args->hipSetDevice.deviceId); \
};

//	void ** dev_ptr (void**);
//	size_t size (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMallocAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMallocAsync.retval); \
	printf("\tvoid ** dev_ptr = %p", args->hipMallocAsync.dev_ptr); \
	if (args->hipMallocAsync.dev_ptr != NULL) { \
		printf("-> %p", args->hipMallocAsync.dev_ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipMallocAsync.size); \
	printf("\thipStream_t stream = %p\n", args->hipMallocAsync.stream); \
};

//	hipDevice_t * device (int*);
//	int ordinal (int);
#define PROCESS_ARGS_hipDeviceGet(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceGet.retval); \
	printf("\thipDevice_t * device = %p", args->hipDeviceGet.device); \
	if (args->hipDeviceGet.device != NULL) { \
		printf(" -> %d\n", args->hipDeviceGet.device__ref.val); \
	} else { printf("\n"); }; \
	printf("\tint ordinal = %d\n", args->hipDeviceGet.ordinal); \
};

//	void * dst (void*);
//	int value (int);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemsetAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemsetAsync.retval); \
	printf("\tvoid * dst = %p", args->hipMemsetAsync.dst); \
	printf("\n"); \
	printf("\tint value = %d\n", args->hipMemsetAsync.value); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemsetAsync.sizeBytes); \
	printf("\thipStream_t stream = %p\n", args->hipMemsetAsync.stream); \
};

//	void * ptr (void*);
//	size_t size (unsigned long);
//	const hipMemAccessDesc * desc ({
//		hipMemLocation location ({
//			hipMemLocationType type (enum);
//			int id (int);
//		});
//		hipMemAccessFlags flags (enum);
//	});
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemSetAccess(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemSetAccess.retval); \
	printf("\tvoid * ptr = %p", args->hipMemSetAccess.ptr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hipMemSetAccess.size); \
	printf("\tconst hipMemAccessDesc * desc = %p", args->hipMemSetAccess.desc); \
	if (args->hipMemSetAccess.desc != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemLocation location = {\n"); \
		printf("\t\t\thipMemLocationType type = %d\n", args->hipMemSetAccess.desc__ref.val.location.type); \
		printf("\t\t\tint id = %d\n", args->hipMemSetAccess.desc__ref.val.location.id); \
		printf("\t\t}\n"); \
		printf("\t\thipMemAccessFlags flags = %d\n", args->hipMemSetAccess.desc__ref.val.flags); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t count = %lu\n", args->hipMemSetAccess.count); \
};

//	hipDeviceptr_t dest (void*);
//	int value (int);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemsetD32(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemsetD32.retval); \
	printf("\thipDeviceptr_t dest = %p", args->hipMemsetD32.dest); \
	printf("\n"); \
	printf("\tint value = %d\n", args->hipMemsetD32.value); \
	printf("\tsize_t count = %lu\n", args->hipMemsetD32.count); \
};

//	unsigned int * flags (unsigned int*);
#define PROCESS_ARGS_hipGetDeviceFlags(args) { \
	printf("\thipError_t retval = %d\n", args->hipGetDeviceFlags.retval); \
	printf("\tunsigned int * flags = %p", args->hipGetDeviceFlags.flags); \
	if (args->hipGetDeviceFlags.flags != NULL) { \
		printf(" -> %u\n", args->hipGetDeviceFlags.flags__ref.val); \
	} else { printf("\n"); }; \
};

//	int * numBlocks (int*);
//	const void * f (void*);
//	int blockSize (int);
//	size_t dynSharedMemPerBlk (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(args) { \
	printf("\thipError_t retval = %d\n", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.retval); \
	printf("\tint * numBlocks = %p", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks); \
	if (args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks != NULL) { \
		printf(" -> %d\n", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst void * f = %p", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.f); \
	printf("\n"); \
	printf("\tint blockSize = %d\n", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.blockSize); \
	printf("\tsize_t dynSharedMemPerBlk = %lu\n", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.dynSharedMemPerBlk); \
	printf("\tunsigned int flags = %u\n", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.flags); \
};

//	hipUUID * uuid ({
//		char[16] bytes (string);
//	});
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceGetUuid(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceGetUuid.retval); \
	printf("\thipUUID * uuid = %p", args->hipDeviceGetUuid.uuid); \
	if (args->hipDeviceGetUuid.uuid != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tchar[16] bytes = %s\n", args->hipDeviceGetUuid.uuid__ref.val.bytes[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thipDevice_t device = %d\n", args->hipDeviceGetUuid.device); \
};

//	void * dst (void*);
//	size_t dpitch (unsigned long);
//	const void * src (void*);
//	size_t spitch (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpy2D(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpy2D.retval); \
	printf("\tvoid * dst = %p", args->hipMemcpy2D.dst); \
	printf("\n"); \
	printf("\tsize_t dpitch = %lu\n", args->hipMemcpy2D.dpitch); \
	printf("\tconst void * src = %p", args->hipMemcpy2D.src); \
	printf("\n"); \
	printf("\tsize_t spitch = %lu\n", args->hipMemcpy2D.spitch); \
	printf("\tsize_t width = %lu\n", args->hipMemcpy2D.width); \
	printf("\tsize_t height = %lu\n", args->hipMemcpy2D.height); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	hipChannelFormatDesc * desc (unknown);
//	hipExtent * extent (unknown);
//	unsigned int * flags (unsigned int*);
//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipArrayGetInfo(args) { \
	printf("\thipError_t retval = %d\n", args->hipArrayGetInfo.retval); \
	printf("\thipChannelFormatDesc * desc = N/A, try to update csv files\n"); \
	printf("\thipExtent * extent = N/A, try to update csv files\n"); \
	printf("\tunsigned int * flags = %p", args->hipArrayGetInfo.flags); \
	if (args->hipArrayGetInfo.flags != NULL) { \
		printf(" -> %u\n", args->hipArrayGetInfo.flags__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipArray_t array = N/A, try to update csv files\n"); \
};

//	hipUserObject_t object (opaque);
//	unsigned int count (unsigned int);
#define PROCESS_ARGS_hipUserObjectRetain(args) { \
	printf("\thipError_t retval = %d\n", args->hipUserObjectRetain.retval); \
	printf("\thipUserObject_t object = %p\n", args->hipUserObjectRetain.object); \
	printf("\tunsigned int count = %u\n", args->hipUserObjectRetain.count); \
};

//	int count (int);
//	hipGraphicsResource_t * resources (opaque*);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipGraphicsMapResources(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphicsMapResources.retval); \
	printf("\tint count = %d\n", args->hipGraphicsMapResources.count); \
	printf("\thipGraphicsResource_t * resources = %p", args->hipGraphicsMapResources.resources); \
	if (args->hipGraphicsMapResources.resources != NULL) { \
		printf(" -> %p\n", args->hipGraphicsMapResources.resources__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipStream_t stream = %p\n", args->hipGraphicsMapResources.stream); \
};

//	hipDeviceptr_t dst (void*);
//	void * src (void*);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyHtoDAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyHtoDAsync.retval); \
	printf("\thipDeviceptr_t dst = %p", args->hipMemcpyHtoDAsync.dst); \
	printf("\n"); \
	printf("\tvoid * src = %p", args->hipMemcpyHtoDAsync.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyHtoDAsync.sizeBytes); \
	printf("\thipStream_t stream = %p\n", args->hipMemcpyHtoDAsync.stream); \
};

//	HIP_TEXTURE_DESC * pTexDesc (unknown);
//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectGetTextureDesc(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexObjectGetTextureDesc.retval); \
	printf("\tHIP_TEXTURE_DESC * pTexDesc = N/A, try to update csv files\n"); \
	printf("\thipTextureObject_t texObject = N/A, try to update csv files\n"); \
};

//	unsigned long long * flags (unsigned long long*);
//	const hipMemLocation * location ({
//		hipMemLocationType type (enum);
//		int id (int);
//	});
//	void * ptr (void*);
#define PROCESS_ARGS_hipMemGetAccess(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemGetAccess.retval); \
	printf("\tunsigned long long * flags = %p", args->hipMemGetAccess.flags); \
	if (args->hipMemGetAccess.flags != NULL) { \
		printf(" -> %llu\n", args->hipMemGetAccess.flags__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst hipMemLocation * location = %p", args->hipMemGetAccess.location); \
	if (args->hipMemGetAccess.location != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemLocationType type = %d\n", args->hipMemGetAccess.location__ref.val.type); \
		printf("\t\tint id = %d\n", args->hipMemGetAccess.location__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tvoid * ptr = %p", args->hipMemGetAccess.ptr); \
	printf("\n"); \
};

//	hipArray_t dst (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	const void * src (void*);
//	size_t spitch (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpy2DToArrayAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpy2DToArrayAsync.retval); \
	printf("\thipArray_t dst = N/A, try to update csv files\n"); \
	printf("\tsize_t wOffset = %lu\n", args->hipMemcpy2DToArrayAsync.wOffset); \
	printf("\tsize_t hOffset = %lu\n", args->hipMemcpy2DToArrayAsync.hOffset); \
	printf("\tconst void * src = %p", args->hipMemcpy2DToArrayAsync.src); \
	printf("\n"); \
	printf("\tsize_t spitch = %lu\n", args->hipMemcpy2DToArrayAsync.spitch); \
	printf("\tsize_t width = %lu\n", args->hipMemcpy2DToArrayAsync.width); \
	printf("\tsize_t height = %lu\n", args->hipMemcpy2DToArrayAsync.height); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = %p\n", args->hipMemcpy2DToArrayAsync.stream); \
};

//	hipDeviceptr_t * dev_ptr (void**);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetAddress(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefGetAddress.retval); \
	printf("\thipDeviceptr_t * dev_ptr = %p", args->hipTexRefGetAddress.dev_ptr); \
	if (args->hipTexRefGetAddress.dev_ptr != NULL) { \
		printf("-> %p", args->hipTexRefGetAddress.dev_ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t node (opaque);
//	hipGraphNodeType * pType (enum*);
#define PROCESS_ARGS_hipGraphNodeGetType(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphNodeGetType.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphNodeGetType.node); \
	printf("\thipGraphNodeType * pType = %p", args->hipGraphNodeGetType.pType); \
	if (args->hipGraphNodeGetType.pType != NULL) { \
		printf(" -> %d\n", args->hipGraphNodeGetType.pType__ref.val); \
	} else { printf("\n"); }; \
};

//	hipStream_t stream (opaque);
//	unsigned int * flags (unsigned int*);
#define PROCESS_ARGS_hipStreamGetFlags(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamGetFlags.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamGetFlags.stream); \
	printf("\tunsigned int * flags = %p", args->hipStreamGetFlags.flags); \
	if (args->hipStreamGetFlags.flags != NULL) { \
		printf(" -> %u\n", args->hipStreamGetFlags.flags__ref.val); \
	} else { printf("\n"); }; \
};

//	int * numBlocks (int*);
//	hipFunction_t f (opaque);
//	int blockSize (int);
//	size_t dynSharedMemPerBlk (unsigned long);
#define PROCESS_ARGS_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor(args) { \
	printf("\thipError_t retval = %d\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.retval); \
	printf("\tint * numBlocks = %p", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks); \
	if (args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks != NULL) { \
		printf(" -> %d\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipFunction_t f = %p\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.f); \
	printf("\tint blockSize = %d\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.blockSize); \
	printf("\tsize_t dynSharedMemPerBlk = %lu\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.dynSharedMemPerBlk); \
};

//	void * dst (void*);
//	size_t pitch (unsigned long);
//	int value (int);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemset2DAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemset2DAsync.retval); \
	printf("\tvoid * dst = %p", args->hipMemset2DAsync.dst); \
	printf("\n"); \
	printf("\tsize_t pitch = %lu\n", args->hipMemset2DAsync.pitch); \
	printf("\tint value = %d\n", args->hipMemset2DAsync.value); \
	printf("\tsize_t width = %lu\n", args->hipMemset2DAsync.width); \
	printf("\tsize_t height = %lu\n", args->hipMemset2DAsync.height); \
	printf("\thipStream_t stream = %p\n", args->hipMemset2DAsync.stream); \
};

//	void * dst (void*);
//	const void * symbol (void*);
//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpyFromSymbol(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyFromSymbol.retval); \
	printf("\tvoid * dst = %p", args->hipMemcpyFromSymbol.dst); \
	printf("\n"); \
	printf("\tconst void * symbol = %p", args->hipMemcpyFromSymbol.symbol); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyFromSymbol.sizeBytes); \
	printf("\tsize_t offset = %lu\n", args->hipMemcpyFromSymbol.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	void * ptr (void*);
#define PROCESS_ARGS_hipHostFree(args) { \
	printf("\thipError_t retval = %d\n", args->hipHostFree.retval); \
	printf("\tvoid * ptr = %p", args->hipHostFree.ptr); \
	printf("\n"); \
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
//	hipStream_t stream (opaque);
//	hipEvent_t startEvent (opaque);
//	hipEvent_t stopEvent (opaque);
//	int flags (int);
#define PROCESS_ARGS_hipExtLaunchKernel(args) { \
	printf("\thipError_t retval = %d\n", args->hipExtLaunchKernel.retval); \
	printf("\tconst void * function_address = %p", args->hipExtLaunchKernel.function_address); \
	printf("\n"); \
	printf("\tdim3 numBlocks = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipExtLaunchKernel.numBlocks.x); \
	printf("\t\tuint32_t y = %u\n", args->hipExtLaunchKernel.numBlocks.y); \
	printf("\t\tuint32_t z = %u\n", args->hipExtLaunchKernel.numBlocks.z); \
	printf("\t}\n"); \
	printf("\tdim3 dimBlocks = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipExtLaunchKernel.dimBlocks.x); \
	printf("\t\tuint32_t y = %u\n", args->hipExtLaunchKernel.dimBlocks.y); \
	printf("\t\tuint32_t z = %u\n", args->hipExtLaunchKernel.dimBlocks.z); \
	printf("\t}\n"); \
	printf("\tvoid ** args = %p", args->hipExtLaunchKernel.args); \
	if (args->hipExtLaunchKernel.args != NULL) { \
		printf("-> %p", args->hipExtLaunchKernel.args__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t sharedMemBytes = %lu\n", args->hipExtLaunchKernel.sharedMemBytes); \
	printf("\thipStream_t stream = %p\n", args->hipExtLaunchKernel.stream); \
	printf("\thipEvent_t startEvent = %p\n", args->hipExtLaunchKernel.startEvent); \
	printf("\thipEvent_t stopEvent = %p\n", args->hipExtLaunchKernel.stopEvent); \
	printf("\tint flags = %d\n", args->hipExtLaunchKernel.flags); \
};

//	void * dst (void*);
//	const void * symbol (void*);
//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyFromSymbolAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyFromSymbolAsync.retval); \
	printf("\tvoid * dst = %p", args->hipMemcpyFromSymbolAsync.dst); \
	printf("\n"); \
	printf("\tconst void * symbol = %p", args->hipMemcpyFromSymbolAsync.symbol); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyFromSymbolAsync.sizeBytes); \
	printf("\tsize_t offset = %lu\n", args->hipMemcpyFromSymbolAsync.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = %p\n", args->hipMemcpyFromSymbolAsync.stream); \
};

//	hipCtx_t * ctx (opaque*);
//	unsigned int flags (unsigned int);
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipCtxCreate(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxCreate.retval); \
	printf("\thipCtx_t * ctx = %p", args->hipCtxCreate.ctx); \
	if (args->hipCtxCreate.ctx != NULL) { \
		printf(" -> %p\n", args->hipCtxCreate.ctx__ref.val); \
	} else { printf("\n"); }; \
	printf("\tunsigned int flags = %u\n", args->hipCtxCreate.flags); \
	printf("\thipDevice_t device = %d\n", args->hipCtxCreate.device); \
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
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipLaunchCooperativeKernel(args) { \
	printf("\thipError_t retval = %d\n", args->hipLaunchCooperativeKernel.retval); \
	printf("\tconst void * f = %p", args->hipLaunchCooperativeKernel.f); \
	printf("\n"); \
	printf("\tdim3 gridDim = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipLaunchCooperativeKernel.gridDim.x); \
	printf("\t\tuint32_t y = %u\n", args->hipLaunchCooperativeKernel.gridDim.y); \
	printf("\t\tuint32_t z = %u\n", args->hipLaunchCooperativeKernel.gridDim.z); \
	printf("\t}\n"); \
	printf("\tdim3 blockDimX = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipLaunchCooperativeKernel.blockDimX.x); \
	printf("\t\tuint32_t y = %u\n", args->hipLaunchCooperativeKernel.blockDimX.y); \
	printf("\t\tuint32_t z = %u\n", args->hipLaunchCooperativeKernel.blockDimX.z); \
	printf("\t}\n"); \
	printf("\tvoid ** kernelParams = %p", args->hipLaunchCooperativeKernel.kernelParams); \
	if (args->hipLaunchCooperativeKernel.kernelParams != NULL) { \
		printf("-> %p", args->hipLaunchCooperativeKernel.kernelParams__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tunsigned int sharedMemBytes = %u\n", args->hipLaunchCooperativeKernel.sharedMemBytes); \
	printf("\thipStream_t stream = %p\n", args->hipLaunchCooperativeKernel.stream); \
};

//	hipStream_t stream (opaque);
//	uint32_t cuMaskSize (unsigned int);
//	uint32_t * cuMask (unsigned int*);
#define PROCESS_ARGS_hipExtStreamGetCUMask(args) { \
	printf("\thipError_t retval = %d\n", args->hipExtStreamGetCUMask.retval); \
	printf("\thipStream_t stream = %p\n", args->hipExtStreamGetCUMask.stream); \
	printf("\tuint32_t cuMaskSize = %u\n", args->hipExtStreamGetCUMask.cuMaskSize); \
	printf("\tuint32_t * cuMask = %p", args->hipExtStreamGetCUMask.cuMask); \
	if (args->hipExtStreamGetCUMask.cuMask != NULL) { \
		printf(" -> %u\n", args->hipExtStreamGetCUMask.cuMask__ref.val); \
	} else { printf("\n"); }; \
};

//	hipGraphExec_t graphExec (opaque);
#define PROCESS_ARGS_hipGraphExecDestroy(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExecDestroy.retval); \
	printf("\thipGraphExec_t graphExec = %p\n", args->hipGraphExecDestroy.graphExec); \
};

//	hipError_t hipError (enum);
//	const char ** errorString (string**);
#define PROCESS_ARGS_hipDrvGetErrorString(args) { \
	printf("\thipError_t retval = %d\n", args->hipDrvGetErrorString.retval); \
	printf("\thipError_t hipError = %d\n", args->hipDrvGetErrorString.hipError); \
	printf("\tconst char ** errorString = %p", args->hipDrvGetErrorString.errorString); \
	if (args->hipDrvGetErrorString.errorString != NULL) { \
		printf("-> %p", args->hipDrvGetErrorString.errorString__ref.ptr1); \
		if (args->hipDrvGetErrorString.errorString__ref.ptr1 != NULL) { \
			printf(" -> %s\n", args->hipDrvGetErrorString.errorString__ref.val); \
		} else { printf("\n"); }; \
	} else { printf("\n"); }; \
};

//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipInit(args) { \
	printf("\thipError_t retval = %d\n", args->hipInit.retval); \
	printf("\tunsigned int flags = %u\n", args->hipInit.flags); \
};

//	size_t * offset (unsigned long*);
//	const textureReference * tex (unknown);
//	const void * devPtr (void*);
//	const hipChannelFormatDesc * desc (unknown);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	size_t pitch (unsigned long);
#define PROCESS_ARGS_hipBindTexture2D(args) { \
	printf("\thipError_t retval = %d\n", args->hipBindTexture2D.retval); \
	printf("\tsize_t * offset = %p", args->hipBindTexture2D.offset); \
	if (args->hipBindTexture2D.offset != NULL) { \
		printf(" -> %lu\n", args->hipBindTexture2D.offset__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference * tex = N/A, try to update csv files\n"); \
	printf("\tconst void * devPtr = %p", args->hipBindTexture2D.devPtr); \
	printf("\n"); \
	printf("\tconst hipChannelFormatDesc * desc = N/A, try to update csv files\n"); \
	printf("\tsize_t width = %lu\n", args->hipBindTexture2D.width); \
	printf("\tsize_t height = %lu\n", args->hipBindTexture2D.height); \
	printf("\tsize_t pitch = %lu\n", args->hipBindTexture2D.pitch); \
};

//	int device1 (int);
//	int device2 (int);
//	uint32_t * linktype (unsigned int*);
//	uint32_t * hopcount (unsigned int*);
#define PROCESS_ARGS_hipExtGetLinkTypeAndHopCount(args) { \
	printf("\thipError_t retval = %d\n", args->hipExtGetLinkTypeAndHopCount.retval); \
	printf("\tint device1 = %d\n", args->hipExtGetLinkTypeAndHopCount.device1); \
	printf("\tint device2 = %d\n", args->hipExtGetLinkTypeAndHopCount.device2); \
	printf("\tuint32_t * linktype = %p", args->hipExtGetLinkTypeAndHopCount.linktype); \
	if (args->hipExtGetLinkTypeAndHopCount.linktype != NULL) { \
		printf(" -> %u\n", args->hipExtGetLinkTypeAndHopCount.linktype__ref.val); \
	} else { printf("\n"); }; \
	printf("\tuint32_t * hopcount = %p", args->hipExtGetLinkTypeAndHopCount.hopcount); \
	if (args->hipExtGetLinkTypeAndHopCount.hopcount != NULL) { \
		printf(" -> %u\n", args->hipExtGetLinkTypeAndHopCount.hopcount__ref.val); \
	} else { printf("\n"); }; \
};

//	struct hipResourceViewDesc * pResViewDesc (unknown);
//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipGetTextureObjectResourceViewDesc(args) { \
	printf("\thipError_t retval = %d\n", args->hipGetTextureObjectResourceViewDesc.retval); \
	printf("\tstruct hipResourceViewDesc * pResViewDesc = N/A, try to update csv files\n"); \
	printf("\thipTextureObject_t textureObject = N/A, try to update csv files\n"); \
};

//	hipMemGenericAllocationHandle_t * handle (opaque*);
//	size_t size (unsigned long);
//	const hipMemAllocationProp * prop ({
//		hipMemAllocationType type (enum);
//		hipMemAllocationHandleType requestedHandleType (enum);
//		hipMemLocation location ({
//			hipMemLocationType type (enum);
//			int id (int);
//		});
//		struct (unnamed struct at ./input/hip_runtime_api.h:1393:5) allocFlags ({
//			unsigned char compressionType (unsigned char);
//			unsigned char gpuDirectRDMACapable (unsigned char);
//			unsigned short usage (unsigned short);
//		});
//	});
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipMemCreate(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemCreate.retval); \
	printf("\thipMemGenericAllocationHandle_t * handle = %p", args->hipMemCreate.handle); \
	if (args->hipMemCreate.handle != NULL) { \
		printf(" -> %p\n", args->hipMemCreate.handle__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipMemCreate.size); \
	printf("\tconst hipMemAllocationProp * prop = %p", args->hipMemCreate.prop); \
	if (args->hipMemCreate.prop != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemAllocationType type = %d\n", args->hipMemCreate.prop__ref.val.type); \
		printf("\t\thipMemAllocationHandleType requestedHandleType = %d\n", args->hipMemCreate.prop__ref.val.requestedHandleType); \
		printf("\t\thipMemLocation location = {\n"); \
		printf("\t\t\thipMemLocationType type = %d\n", args->hipMemCreate.prop__ref.val.location.type); \
		printf("\t\t\tint id = %d\n", args->hipMemCreate.prop__ref.val.location.id); \
		printf("\t\t}\n"); \
		printf("\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1393:5) allocFlags = {\n"); \
		printf("\t\t\tunsigned char compressionType = %hhu\n", args->hipMemCreate.prop__ref.val.allocFlags.compressionType); \
		printf("\t\t\tunsigned char gpuDirectRDMACapable = %hhu\n", args->hipMemCreate.prop__ref.val.allocFlags.gpuDirectRDMACapable); \
		printf("\t\t\tunsigned short usage = %hu\n", args->hipMemCreate.prop__ref.val.allocFlags.usage); \
		printf("\t\t}\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tunsigned long long flags = %llu\n", args->hipMemCreate.flags); \
};

//	hipDeviceptr_t dest (void*);
//	unsigned char value (unsigned char);
//	size_t count (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemsetD8Async(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemsetD8Async.retval); \
	printf("\thipDeviceptr_t dest = %p", args->hipMemsetD8Async.dest); \
	printf("\n"); \
	printf("\tunsigned char value = %hhu\n", args->hipMemsetD8Async.value); \
	printf("\tsize_t count = %lu\n", args->hipMemsetD8Async.count); \
	printf("\thipStream_t stream = %p\n", args->hipMemsetD8Async.stream); \
};

//	hipStream_t stream (opaque);
//	hipHostFn_t fn (function);
//	void * userData (void*);
#define PROCESS_ARGS_hipLaunchHostFunc(args) { \
	printf("\thipError_t retval = %d\n", args->hipLaunchHostFunc.retval); \
	printf("\thipStream_t stream = %p\n", args->hipLaunchHostFunc.stream); \
	printf("\thipHostFn_t fn = %p\n", args->hipLaunchHostFunc.fn); \
	printf("\tvoid * userData = %p", args->hipLaunchHostFunc.userData); \
	printf("\n"); \
};

//	hipGraph_t graph (opaque);
//	hipGraphNode_t * from (opaque*);
//	hipGraphNode_t * to (opaque*);
//	size_t * numEdges (unsigned long*);
#define PROCESS_ARGS_hipGraphGetEdges(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphGetEdges.retval); \
	printf("\thipGraph_t graph = %p\n", args->hipGraphGetEdges.graph); \
	printf("\thipGraphNode_t * from = %p", args->hipGraphGetEdges.from); \
	if (args->hipGraphGetEdges.from != NULL) { \
		printf(" -> %p\n", args->hipGraphGetEdges.from__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraphNode_t * to = %p", args->hipGraphGetEdges.to); \
	if (args->hipGraphGetEdges.to != NULL) { \
		printf(" -> %p\n", args->hipGraphGetEdges.to__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t * numEdges = %p", args->hipGraphGetEdges.numEdges); \
	if (args->hipGraphGetEdges.numEdges != NULL) { \
		printf(" -> %lu\n", args->hipGraphGetEdges.numEdges__ref.val); \
	} else { printf("\n"); }; \
};

//	hipMemPool_t mem_pool (opaque);
#define PROCESS_ARGS_hipMemPoolDestroy(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemPoolDestroy.retval); \
	printf("\thipMemPool_t mem_pool = %p\n", args->hipMemPoolDestroy.mem_pool); \
};

//	hipGraphNode_t node (opaque);
//	hipKernelNodeParams * pNodeParams ({
//		dim3 blockDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		dim3 gridDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		unsigned int sharedMemBytes (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphKernelNodeGetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphKernelNodeGetParams.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphKernelNodeGetParams.node); \
	printf("\thipKernelNodeParams * pNodeParams = %p", args->hipGraphKernelNodeGetParams.pNodeParams); \
	if (args->hipGraphKernelNodeGetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tdim3 blockDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hipGraphKernelNodeGetParams.pNodeParams__ref.val.blockDim.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hipGraphKernelNodeGetParams.pNodeParams__ref.val.blockDim.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hipGraphKernelNodeGetParams.pNodeParams__ref.val.blockDim.z); \
		printf("\t\t}\n"); \
		printf("\t\tdim3 gridDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hipGraphKernelNodeGetParams.pNodeParams__ref.val.gridDim.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hipGraphKernelNodeGetParams.pNodeParams__ref.val.gridDim.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hipGraphKernelNodeGetParams.pNodeParams__ref.val.gridDim.z); \
		printf("\t\t}\n"); \
		printf("\t\tunsigned int sharedMemBytes = %u\n", args->hipGraphKernelNodeGetParams.pNodeParams__ref.val.sharedMemBytes); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	unsigned int numAttributes (unsigned int);
//	hipPointer_attribute * attributes (unknown);
//	void ** data (void**);
//	hipDeviceptr_t ptr (void*);
#define PROCESS_ARGS_hipDrvPointerGetAttributes(args) { \
	printf("\thipError_t retval = %d\n", args->hipDrvPointerGetAttributes.retval); \
	printf("\tunsigned int numAttributes = %u\n", args->hipDrvPointerGetAttributes.numAttributes); \
	printf("\thipPointer_attribute * attributes = N/A, try to update csv files\n"); \
	printf("\tvoid ** data = %p", args->hipDrvPointerGetAttributes.data); \
	if (args->hipDrvPointerGetAttributes.data != NULL) { \
		printf("-> %p", args->hipDrvPointerGetAttributes.data__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\thipDeviceptr_t ptr = %p", args->hipDrvPointerGetAttributes.ptr); \
	printf("\n"); \
};

//	const void * func (void*);
//	hipFuncAttribute attr (enum);
//	int value (int);
#define PROCESS_ARGS_hipFuncSetAttribute(args) { \
	printf("\thipError_t retval = %d\n", args->hipFuncSetAttribute.retval); \
	printf("\tconst void * func = %p", args->hipFuncSetAttribute.func); \
	printf("\n"); \
	printf("\thipFuncAttribute attr = %d\n", args->hipFuncSetAttribute.attr); \
	printf("\tint value = %d\n", args->hipFuncSetAttribute.value); \
};

//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * from (opaque*);
//	const hipGraphNode_t * to (opaque*);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphAddDependencies(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddDependencies.retval); \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddDependencies.graph); \
	printf("\tconst hipGraphNode_t * from = %p", args->hipGraphAddDependencies.from); \
	if (args->hipGraphAddDependencies.from != NULL) { \
		printf(" -> %p\n", args->hipGraphAddDependencies.from__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst hipGraphNode_t * to = %p", args->hipGraphAddDependencies.to); \
	if (args->hipGraphAddDependencies.to != NULL) { \
		printf(" -> %p\n", args->hipGraphAddDependencies.to__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddDependencies.numDependencies); \
};

//	hipStream_t stream (opaque);
//	void * ptr (void*);
//	uint64_t value (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamWriteValue64(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamWriteValue64.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamWriteValue64.stream); \
	printf("\tvoid * ptr = %p", args->hipStreamWriteValue64.ptr); \
	printf("\n"); \
	printf("\tuint64_t value = %lu\n", args->hipStreamWriteValue64.value); \
	printf("\tunsigned int flags = %u\n", args->hipStreamWriteValue64.flags); \
};

//	hipSurfaceObject_t* pSurfObject (unknown);
//	const hipResourceDesc* pResDesc (unknown);
#define PROCESS_ARGS_hipCreateSurfaceObject(args) { \
	printf("\thipError_t retval = %d\n", args->hipCreateSurfaceObject.retval); \
	printf("\thipSurfaceObject_t* pSurfObject = N/A, try to update csv files\n"); \
	printf("\tconst hipResourceDesc* pResDesc = N/A, try to update csv files\n"); \
};

//	hipTextureDesc* pTexDesc (unknown);
//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipGetTextureObjectTextureDesc(args) { \
	printf("\thipError_t retval = %d\n", args->hipGetTextureObjectTextureDesc.retval); \
	printf("\thipTextureDesc* pTexDesc = N/A, try to update csv files\n"); \
	printf("\thipTextureObject_t textureObject = N/A, try to update csv files\n"); \
};

//	void * ptr (void*);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMemUnmap(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemUnmap.retval); \
	printf("\tvoid * ptr = %p", args->hipMemUnmap.ptr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hipMemUnmap.size); \
};

//	hipGraphNode_t node (opaque);
//	hipGraph_t * pGraph (opaque*);
#define PROCESS_ARGS_hipGraphChildGraphNodeGetGraph(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphChildGraphNodeGetGraph.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphChildGraphNodeGetGraph.node); \
	printf("\thipGraph_t * pGraph = %p", args->hipGraphChildGraphNodeGetGraph.pGraph); \
	if (args->hipGraphChildGraphNodeGetGraph.pGraph != NULL) { \
		printf(" -> %p\n", args->hipGraphChildGraphNodeGetGraph.pGraph__ref.val); \
	} else { printf("\n"); }; \
};

//	hipStream_t * stream (opaque*);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamCreateWithFlags(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamCreateWithFlags.retval); \
	printf("\thipStream_t * stream = %p", args->hipStreamCreateWithFlags.stream); \
	if (args->hipStreamCreateWithFlags.stream != NULL) { \
		printf(" -> %p\n", args->hipStreamCreateWithFlags.stream__ref.val); \
	} else { printf("\n"); }; \
	printf("\tunsigned int flags = %u\n", args->hipStreamCreateWithFlags.flags); \
};

//	hipMemPool_t * mem_pool (opaque*);
//	const hipMemPoolProps * pool_props ({
//		hipMemAllocationType allocType (enum);
//		hipMemAllocationHandleType handleTypes (enum);
//		hipMemLocation location ({
//			hipMemLocationType type (enum);
//			int id (int);
//		});
//		unsigned char[64] reserved (unsigned char);
//	});
#define PROCESS_ARGS_hipMemPoolCreate(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemPoolCreate.retval); \
	printf("\thipMemPool_t * mem_pool = %p", args->hipMemPoolCreate.mem_pool); \
	if (args->hipMemPoolCreate.mem_pool != NULL) { \
		printf(" -> %p\n", args->hipMemPoolCreate.mem_pool__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst hipMemPoolProps * pool_props = %p", args->hipMemPoolCreate.pool_props); \
	if (args->hipMemPoolCreate.pool_props != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemAllocationType allocType = %d\n", args->hipMemPoolCreate.pool_props__ref.val.allocType); \
		printf("\t\thipMemAllocationHandleType handleTypes = %d\n", args->hipMemPoolCreate.pool_props__ref.val.handleTypes); \
		printf("\t\thipMemLocation location = {\n"); \
		printf("\t\t\thipMemLocationType type = %d\n", args->hipMemPoolCreate.pool_props__ref.val.location.type); \
		printf("\t\t\tint id = %d\n", args->hipMemPoolCreate.pool_props__ref.val.location.id); \
		printf("\t\t}\n"); \
		printf("\t\tunsigned char[64] reserved = %hhu\n", args->hipMemPoolCreate.pool_props__ref.val.reserved[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipLaunchParams * launchParamsList ({
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
//		int sharedMem (int);
//		hipStream_t stream (opaque);
//	});
//	int numDevices (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipLaunchCooperativeKernelMultiDevice(args) { \
	printf("\thipError_t retval = %d\n", args->hipLaunchCooperativeKernelMultiDevice.retval); \
	printf("\thipLaunchParams * launchParamsList = %p", args->hipLaunchCooperativeKernelMultiDevice.launchParamsList); \
	if (args->hipLaunchCooperativeKernelMultiDevice.launchParamsList != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tdim3 gridDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hipLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.gridDim.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hipLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.gridDim.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hipLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.gridDim.z); \
		printf("\t\t}\n"); \
		printf("\t\tdim3 blockDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hipLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.blockDim.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hipLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.blockDim.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hipLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.blockDim.z); \
		printf("\t\t}\n"); \
		printf("\t\tint sharedMem = %d\n", args->hipLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.sharedMem); \
		printf("\t\thipStream_t stream = %p\n", args->hipLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.stream); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tint numDevices = %d\n", args->hipLaunchCooperativeKernelMultiDevice.numDevices); \
	printf("\tunsigned int flags = %u\n", args->hipLaunchCooperativeKernelMultiDevice.flags); \
};

//	textureReference* texRef (unknown);
//	enum hipTextureFilterMode fm (enum);
#define PROCESS_ARGS_hipTexRefSetFilterMode(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefSetFilterMode.retval); \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tenum hipTextureFilterMode fm = %d\n", args->hipTexRefSetFilterMode.fm); \
};

//	int device (int);
//	hipGraphMemAttributeType attr (enum);
//	void * value (void*);
#define PROCESS_ARGS_hipDeviceSetGraphMemAttribute(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceSetGraphMemAttribute.retval); \
	printf("\tint device = %d\n", args->hipDeviceSetGraphMemAttribute.device); \
	printf("\thipGraphMemAttributeType attr = %d\n", args->hipDeviceSetGraphMemAttribute.attr); \
	printf("\tvoid * value = %p", args->hipDeviceSetGraphMemAttribute.value); \
	printf("\n"); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
//	void * dst (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParams1D(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExecMemcpyNodeSetParams1D.retval); \
	printf("\thipGraphExec_t hGraphExec = %p\n", args->hipGraphExecMemcpyNodeSetParams1D.hGraphExec); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphExecMemcpyNodeSetParams1D.node); \
	printf("\tvoid * dst = %p", args->hipGraphExecMemcpyNodeSetParams1D.dst); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipGraphExecMemcpyNodeSetParams1D.src); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipGraphExecMemcpyNodeSetParams1D.count); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
//	const hipKernelNodeParams * pNodeParams ({
//		dim3 blockDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		dim3 gridDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		unsigned int sharedMemBytes (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphExecKernelNodeSetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExecKernelNodeSetParams.retval); \
	printf("\thipGraphExec_t hGraphExec = %p\n", args->hipGraphExecKernelNodeSetParams.hGraphExec); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphExecKernelNodeSetParams.node); \
	printf("\tconst hipKernelNodeParams * pNodeParams = %p", args->hipGraphExecKernelNodeSetParams.pNodeParams); \
	if (args->hipGraphExecKernelNodeSetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tdim3 blockDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hipGraphExecKernelNodeSetParams.pNodeParams__ref.val.blockDim.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hipGraphExecKernelNodeSetParams.pNodeParams__ref.val.blockDim.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hipGraphExecKernelNodeSetParams.pNodeParams__ref.val.blockDim.z); \
		printf("\t\t}\n"); \
		printf("\t\tdim3 gridDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hipGraphExecKernelNodeSetParams.pNodeParams__ref.val.gridDim.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hipGraphExecKernelNodeSetParams.pNodeParams__ref.val.gridDim.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hipGraphExecKernelNodeSetParams.pNodeParams__ref.val.gridDim.z); \
		printf("\t\t}\n"); \
		printf("\t\tunsigned int sharedMemBytes = %u\n", args->hipGraphExecKernelNodeSetParams.pNodeParams__ref.val.sharedMemBytes); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraphExec_t * pGraphExec (opaque*);
//	hipGraph_t graph (opaque);
//	hipGraphNode_t * pErrorNode (opaque*);
//	char * pLogBuffer (string*);
//	size_t bufferSize (unsigned long);
#define PROCESS_ARGS_hipGraphInstantiate(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphInstantiate.retval); \
	printf("\thipGraphExec_t * pGraphExec = %p", args->hipGraphInstantiate.pGraphExec); \
	if (args->hipGraphInstantiate.pGraphExec != NULL) { \
		printf(" -> %p\n", args->hipGraphInstantiate.pGraphExec__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphInstantiate.graph); \
	printf("\thipGraphNode_t * pErrorNode = %p", args->hipGraphInstantiate.pErrorNode); \
	if (args->hipGraphInstantiate.pErrorNode != NULL) { \
		printf(" -> %p\n", args->hipGraphInstantiate.pErrorNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\tchar * pLogBuffer = %p", args->hipGraphInstantiate.pLogBuffer); \
	if (args->hipGraphInstantiate.pLogBuffer != NULL) { \
		printf(" -> %s\n", args->hipGraphInstantiate.pLogBuffer__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t bufferSize = %lu\n", args->hipGraphInstantiate.bufferSize); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t hNode (opaque);
//	const hipExternalSemaphoreSignalNodeParams * nodeParams ({
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphExecExternalSemaphoresSignalNodeSetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExecExternalSemaphoresSignalNodeSetParams.retval); \
	printf("\thipGraphExec_t hGraphExec = %p\n", args->hipGraphExecExternalSemaphoresSignalNodeSetParams.hGraphExec); \
	printf("\thipGraphNode_t hNode = %p\n", args->hipGraphExecExternalSemaphoresSignalNodeSetParams.hNode); \
	printf("\tconst hipExternalSemaphoreSignalNodeParams * nodeParams = %p", args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams); \
	if (args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned int numExtSems = %u\n", args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams__ref.val.numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipTextureObject_t* pTexObject (unknown);
//	const hipResourceDesc* pResDesc (unknown);
//	const hipTextureDesc* pTexDesc (unknown);
//	const struct hipResourceViewDesc * pResViewDesc (unknown);
#define PROCESS_ARGS_hipCreateTextureObject(args) { \
	printf("\thipError_t retval = %d\n", args->hipCreateTextureObject.retval); \
	printf("\thipTextureObject_t* pTexObject = N/A, try to update csv files\n"); \
	printf("\tconst hipResourceDesc* pResDesc = N/A, try to update csv files\n"); \
	printf("\tconst hipTextureDesc* pTexDesc = N/A, try to update csv files\n"); \
	printf("\tconst struct hipResourceViewDesc * pResViewDesc = N/A, try to update csv files\n"); \
};

//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipEventQuery(args) { \
	printf("\thipError_t retval = %d\n", args->hipEventQuery.retval); \
	printf("\thipEvent_t event = %p\n", args->hipEventQuery.event); \
};

//	hipCtx_t ctx (opaque);
#define PROCESS_ARGS_hipCtxPushCurrent(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxPushCurrent.retval); \
	printf("\thipCtx_t ctx = %p\n", args->hipCtxPushCurrent.ctx); \
};

//	hipGraph_t graph (opaque);
//	hipGraphNode_t * pRootNodes (opaque*);
//	size_t * pNumRootNodes (unsigned long*);
#define PROCESS_ARGS_hipGraphGetRootNodes(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphGetRootNodes.retval); \
	printf("\thipGraph_t graph = %p\n", args->hipGraphGetRootNodes.graph); \
	printf("\thipGraphNode_t * pRootNodes = %p", args->hipGraphGetRootNodes.pRootNodes); \
	if (args->hipGraphGetRootNodes.pRootNodes != NULL) { \
		printf(" -> %p\n", args->hipGraphGetRootNodes.pRootNodes__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t * pNumRootNodes = %p", args->hipGraphGetRootNodes.pNumRootNodes); \
	if (args->hipGraphGetRootNodes.pNumRootNodes != NULL) { \
		printf(" -> %lu\n", args->hipGraphGetRootNodes.pNumRootNodes__ref.val); \
	} else { printf("\n"); }; \
};

//	hipError_t hipError (enum);
#define PROCESS_ARGS_hipGetErrorString(args) { \
	printf("\tconst char * retval = %s\n", args->hipGetErrorString.retval); \
	printf("\thipError_t hipError = %d\n", args->hipGetErrorString.hipError); \
};

//	void * devPtr (void*);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMemAddressFree(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemAddressFree.retval); \
	printf("\tvoid * devPtr = %p", args->hipMemAddressFree.devPtr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hipMemAddressFree.size); \
};


#define PROCESS_ARGS_hipDeviceSynchronize(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceSynchronize.retval); \
\
};

//	unsigned int * flags (unsigned int*);
#define PROCESS_ARGS_hipCtxGetFlags(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxGetFlags.retval); \
	printf("\tunsigned int * flags = %p", args->hipCtxGetFlags.flags); \
	if (args->hipCtxGetFlags.flags != NULL) { \
		printf(" -> %u\n", args->hipCtxGetFlags.flags__ref.val); \
	} else { printf("\n"); }; \
};

//	hipArray_t* pArray (unknown);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetArray(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefGetArray.retval); \
	printf("\thipArray_t* pArray = N/A, try to update csv files\n"); \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	size_t * granularity (unsigned long*);
//	const hipMemAllocationProp * prop ({
//		hipMemAllocationType type (enum);
//		hipMemAllocationHandleType requestedHandleType (enum);
//		hipMemLocation location ({
//			hipMemLocationType type (enum);
//			int id (int);
//		});
//		struct (unnamed struct at ./input/hip_runtime_api.h:1393:5) allocFlags ({
//			unsigned char compressionType (unsigned char);
//			unsigned char gpuDirectRDMACapable (unsigned char);
//			unsigned short usage (unsigned short);
//		});
//	});
//	hipMemAllocationGranularity_flags option (enum);
#define PROCESS_ARGS_hipMemGetAllocationGranularity(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemGetAllocationGranularity.retval); \
	printf("\tsize_t * granularity = %p", args->hipMemGetAllocationGranularity.granularity); \
	if (args->hipMemGetAllocationGranularity.granularity != NULL) { \
		printf(" -> %lu\n", args->hipMemGetAllocationGranularity.granularity__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst hipMemAllocationProp * prop = %p", args->hipMemGetAllocationGranularity.prop); \
	if (args->hipMemGetAllocationGranularity.prop != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemAllocationType type = %d\n", args->hipMemGetAllocationGranularity.prop__ref.val.type); \
		printf("\t\thipMemAllocationHandleType requestedHandleType = %d\n", args->hipMemGetAllocationGranularity.prop__ref.val.requestedHandleType); \
		printf("\t\thipMemLocation location = {\n"); \
		printf("\t\t\thipMemLocationType type = %d\n", args->hipMemGetAllocationGranularity.prop__ref.val.location.type); \
		printf("\t\t\tint id = %d\n", args->hipMemGetAllocationGranularity.prop__ref.val.location.id); \
		printf("\t\t}\n"); \
		printf("\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1393:5) allocFlags = {\n"); \
		printf("\t\t\tunsigned char compressionType = %hhu\n", args->hipMemGetAllocationGranularity.prop__ref.val.allocFlags.compressionType); \
		printf("\t\t\tunsigned char gpuDirectRDMACapable = %hhu\n", args->hipMemGetAllocationGranularity.prop__ref.val.allocFlags.gpuDirectRDMACapable); \
		printf("\t\t\tunsigned short usage = %hu\n", args->hipMemGetAllocationGranularity.prop__ref.val.allocFlags.usage); \
		printf("\t\t}\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thipMemAllocationGranularity_flags option = %d\n", args->hipMemGetAllocationGranularity.option); \
};


#define PROCESS_ARGS_hipProfilerStop(args) { \
	printf("\thipError_t retval = %d\n", args->hipProfilerStop.retval); \
\
};

//	textureReference* tex (unknown);
//	hipArray_const_t array (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipTexRefSetArray(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefSetArray.retval); \
	printf("\ttextureReference* tex = N/A, try to update csv files\n"); \
	printf("\thipArray_const_t array = N/A, try to update csv files\n"); \
	printf("\tunsigned int flags = %u\n", args->hipTexRefSetArray.flags); \
};

//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipEventDestroy(args) { \
	printf("\thipError_t retval = %d\n", args->hipEventDestroy.retval); \
	printf("\thipEvent_t event = %p\n", args->hipEventDestroy.event); \
};

//	hipFuncCache_t cacheConfig (enum);
#define PROCESS_ARGS_hipDeviceSetCacheConfig(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceSetCacheConfig.retval); \
	printf("\thipFuncCache_t cacheConfig = %d\n", args->hipDeviceSetCacheConfig.cacheConfig); \
};

//	const void * func (void*);
#define PROCESS_ARGS_hipLaunchByPtr(args) { \
	printf("\thipError_t retval = %d\n", args->hipLaunchByPtr.retval); \
	printf("\tconst void * func = %p", args->hipLaunchByPtr.func); \
	printf("\n"); \
};

//	hipFunctionLaunchParams * launchParamsList ({
//		hipFunction_t function (opaque);
//		unsigned int gridDimX (unsigned int);
//		unsigned int gridDimY (unsigned int);
//		unsigned int gridDimZ (unsigned int);
//		unsigned int blockDimX (unsigned int);
//		unsigned int blockDimY (unsigned int);
//		unsigned int blockDimZ (unsigned int);
//		unsigned int sharedMemBytes (unsigned int);
//		hipStream_t hStream (opaque);
//	});
//	unsigned int numDevices (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipModuleLaunchCooperativeKernelMultiDevice(args) { \
	printf("\thipError_t retval = %d\n", args->hipModuleLaunchCooperativeKernelMultiDevice.retval); \
	printf("\thipFunctionLaunchParams * launchParamsList = %p", args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList); \
	if (args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipFunction_t function = %p\n", args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.function); \
		printf("\t\tunsigned int gridDimX = %u\n", args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.gridDimX); \
		printf("\t\tunsigned int gridDimY = %u\n", args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.gridDimY); \
		printf("\t\tunsigned int gridDimZ = %u\n", args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.gridDimZ); \
		printf("\t\tunsigned int blockDimX = %u\n", args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.blockDimX); \
		printf("\t\tunsigned int blockDimY = %u\n", args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.blockDimY); \
		printf("\t\tunsigned int blockDimZ = %u\n", args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.blockDimZ); \
		printf("\t\tunsigned int sharedMemBytes = %u\n", args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.sharedMemBytes); \
		printf("\t\thipStream_t hStream = %p\n", args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList__ref.val.hStream); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tunsigned int numDevices = %u\n", args->hipModuleLaunchCooperativeKernelMultiDevice.numDevices); \
	printf("\tunsigned int flags = %u\n", args->hipModuleLaunchCooperativeKernelMultiDevice.flags); \
};

//	textureReference* texRef (unknown);
//	int dim (int);
//	enum hipTextureAddressMode am (enum);
#define PROCESS_ARGS_hipTexRefSetAddressMode(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefSetAddressMode.retval); \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tint dim = %d\n", args->hipTexRefSetAddressMode.dim); \
	printf("\tenum hipTextureAddressMode am = %d\n", args->hipTexRefSetAddressMode.am); \
};

//	hipModule_t * module (opaque*);
//	const void * image (void*);
#define PROCESS_ARGS_hipModuleLoadData(args) { \
	printf("\thipError_t retval = %d\n", args->hipModuleLoadData.retval); \
	printf("\thipModule_t * module = %p", args->hipModuleLoadData.module); \
	if (args->hipModuleLoadData.module != NULL) { \
		printf(" -> %p\n", args->hipModuleLoadData.module__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst void * image = %p", args->hipModuleLoadData.image); \
	printf("\n"); \
};

//	const hip_Memcpy2D * pCopy (unknown);
#define PROCESS_ARGS_hipDrvMemcpy2DUnaligned(args) { \
	printf("\thipError_t retval = %d\n", args->hipDrvMemcpy2DUnaligned.retval); \
	printf("\tconst hip_Memcpy2D * pCopy = N/A, try to update csv files\n"); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
//	hipGraph_t childGraph (opaque);
#define PROCESS_ARGS_hipGraphExecChildGraphNodeSetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExecChildGraphNodeSetParams.retval); \
	printf("\thipGraphExec_t hGraphExec = %p\n", args->hipGraphExecChildGraphNodeSetParams.hGraphExec); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphExecChildGraphNodeSetParams.node); \
	printf("\thipGraph_t childGraph = %p\n", args->hipGraphExecChildGraphNodeSetParams.childGraph); \
};

//	hipPointerAttribute_t * attributes ({
//		enum hipMemoryType type (enum);
//		int device (int);
//		int isManaged (int);
//		unsigned int allocationFlags (unsigned int);
//	});
//	const void * ptr (void*);
#define PROCESS_ARGS_hipPointerGetAttributes(args) { \
	printf("\thipError_t retval = %d\n", args->hipPointerGetAttributes.retval); \
	printf("\thipPointerAttribute_t * attributes = %p", args->hipPointerGetAttributes.attributes); \
	if (args->hipPointerGetAttributes.attributes != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tenum hipMemoryType type = %d\n", args->hipPointerGetAttributes.attributes__ref.val.type); \
		printf("\t\tint device = %d\n", args->hipPointerGetAttributes.attributes__ref.val.device); \
		printf("\t\tint isManaged = %d\n", args->hipPointerGetAttributes.attributes__ref.val.isManaged); \
		printf("\t\tunsigned int allocationFlags = %u\n", args->hipPointerGetAttributes.attributes__ref.val.allocationFlags); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tconst void * ptr = %p", args->hipPointerGetAttributes.ptr); \
	printf("\n"); \
};

//	void * dst (void*);
//	hipDeviceptr_t src (void*);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyDtoHAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyDtoHAsync.retval); \
	printf("\tvoid * dst = %p", args->hipMemcpyDtoHAsync.dst); \
	printf("\n"); \
	printf("\thipDeviceptr_t src = %p", args->hipMemcpyDtoHAsync.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyDtoHAsync.sizeBytes); \
	printf("\thipStream_t stream = %p\n", args->hipMemcpyDtoHAsync.stream); \
};

//	hipGraphNode_t * pGraphNode (opaque*);
//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * pDependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipGraphAddEventRecordNode(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddEventRecordNode.retval); \
	printf("\thipGraphNode_t * pGraphNode = %p", args->hipGraphAddEventRecordNode.pGraphNode); \
	if (args->hipGraphAddEventRecordNode.pGraphNode != NULL) { \
		printf(" -> %p\n", args->hipGraphAddEventRecordNode.pGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddEventRecordNode.graph); \
	printf("\tconst hipGraphNode_t * pDependencies = %p", args->hipGraphAddEventRecordNode.pDependencies); \
	if (args->hipGraphAddEventRecordNode.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphAddEventRecordNode.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddEventRecordNode.numDependencies); \
	printf("\thipEvent_t event = %p\n", args->hipGraphAddEventRecordNode.event); \
};

//	hipGraphNode_t * pGraphNode (opaque*);
//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * pDependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	const hipExternalSemaphoreSignalNodeParams * nodeParams ({
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphAddExternalSemaphoresSignalNode(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddExternalSemaphoresSignalNode.retval); \
	printf("\thipGraphNode_t * pGraphNode = %p", args->hipGraphAddExternalSemaphoresSignalNode.pGraphNode); \
	if (args->hipGraphAddExternalSemaphoresSignalNode.pGraphNode != NULL) { \
		printf(" -> %p\n", args->hipGraphAddExternalSemaphoresSignalNode.pGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddExternalSemaphoresSignalNode.graph); \
	printf("\tconst hipGraphNode_t * pDependencies = %p", args->hipGraphAddExternalSemaphoresSignalNode.pDependencies); \
	if (args->hipGraphAddExternalSemaphoresSignalNode.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphAddExternalSemaphoresSignalNode.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddExternalSemaphoresSignalNode.numDependencies); \
	printf("\tconst hipExternalSemaphoreSignalNodeParams * nodeParams = %p", args->hipGraphAddExternalSemaphoresSignalNode.nodeParams); \
	if (args->hipGraphAddExternalSemaphoresSignalNode.nodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned int numExtSems = %u\n", args->hipGraphAddExternalSemaphoresSignalNode.nodeParams__ref.val.numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraph_t graph (opaque);
//	hipUserObject_t object (opaque);
//	unsigned int count (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipGraphRetainUserObject(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphRetainUserObject.retval); \
	printf("\thipGraph_t graph = %p\n", args->hipGraphRetainUserObject.graph); \
	printf("\thipUserObject_t object = %p\n", args->hipGraphRetainUserObject.object); \
	printf("\tunsigned int count = %u\n", args->hipGraphRetainUserObject.count); \
	printf("\tunsigned int flags = %u\n", args->hipGraphRetainUserObject.flags); \
};

//	const void * arg (void*);
//	size_t size (unsigned long);
//	size_t offset (unsigned long);
#define PROCESS_ARGS_hipSetupArgument(args) { \
	printf("\thipError_t retval = %d\n", args->hipSetupArgument.retval); \
	printf("\tconst void * arg = %p", args->hipSetupArgument.arg); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hipSetupArgument.size); \
	printf("\tsize_t offset = %lu\n", args->hipSetupArgument.offset); \
};

//	hipDeviceptr_t * dptr (void**);
//	size_t* pitch (unsigned long*);
//	size_t widthInBytes (unsigned long);
//	size_t height (unsigned long);
//	unsigned int elementSizeBytes (unsigned int);
#define PROCESS_ARGS_hipMemAllocPitch(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemAllocPitch.retval); \
	printf("\thipDeviceptr_t * dptr = %p", args->hipMemAllocPitch.dptr); \
	if (args->hipMemAllocPitch.dptr != NULL) { \
		printf("-> %p", args->hipMemAllocPitch.dptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t* pitch = %p", args->hipMemAllocPitch.pitch); \
	if (args->hipMemAllocPitch.pitch != NULL) { \
		printf(" -> %lu\n", args->hipMemAllocPitch.pitch__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t widthInBytes = %lu\n", args->hipMemAllocPitch.widthInBytes); \
	printf("\tsize_t height = %lu\n", args->hipMemAllocPitch.height); \
	printf("\tunsigned int elementSizeBytes = %u\n", args->hipMemAllocPitch.elementSizeBytes); \
};

//	hipGraphNode_t node (opaque);
//	hipEvent_t * event_out (opaque*);
#define PROCESS_ARGS_hipGraphEventWaitNodeGetEvent(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphEventWaitNodeGetEvent.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphEventWaitNodeGetEvent.node); \
	printf("\thipEvent_t * event_out = %p", args->hipGraphEventWaitNodeGetEvent.event_out); \
	if (args->hipGraphEventWaitNodeGetEvent.event_out != NULL) { \
		printf(" -> %p\n", args->hipGraphEventWaitNodeGetEvent.event_out__ref.val); \
	} else { printf("\n"); }; \
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
	printf("\thipError_t retval = %d\n", args->hipMemcpy2DToArray.retval); \
	printf("\thipArray_t dst = N/A, try to update csv files\n"); \
	printf("\tsize_t wOffset = %lu\n", args->hipMemcpy2DToArray.wOffset); \
	printf("\tsize_t hOffset = %lu\n", args->hipMemcpy2DToArray.hOffset); \
	printf("\tconst void * src = %p", args->hipMemcpy2DToArray.src); \
	printf("\n"); \
	printf("\tsize_t spitch = %lu\n", args->hipMemcpy2DToArray.spitch); \
	printf("\tsize_t width = %lu\n", args->hipMemcpy2DToArray.width); \
	printf("\tsize_t height = %lu\n", args->hipMemcpy2DToArray.height); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	void * dst (void*);
//	int dstDeviceId (int);
//	const void * src (void*);
//	int srcDevice (int);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyPeerAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyPeerAsync.retval); \
	printf("\tvoid * dst = %p", args->hipMemcpyPeerAsync.dst); \
	printf("\n"); \
	printf("\tint dstDeviceId = %d\n", args->hipMemcpyPeerAsync.dstDeviceId); \
	printf("\tconst void * src = %p", args->hipMemcpyPeerAsync.src); \
	printf("\n"); \
	printf("\tint srcDevice = %d\n", args->hipMemcpyPeerAsync.srcDevice); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyPeerAsync.sizeBytes); \
	printf("\thipStream_t stream = %p\n", args->hipMemcpyPeerAsync.stream); \
};

//	hipTextureObject_t* pTexObject (unknown);
//	const HIP_RESOURCE_DESC* pResDesc (unknown);
//	const HIP_TEXTURE_DESC* pTexDesc (unknown);
//	const HIP_RESOURCE_VIEW_DESC* pResViewDesc (unknown);
#define PROCESS_ARGS_hipTexObjectCreate(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexObjectCreate.retval); \
	printf("\thipTextureObject_t* pTexObject = N/A, try to update csv files\n"); \
	printf("\tconst HIP_RESOURCE_DESC* pResDesc = N/A, try to update csv files\n"); \
	printf("\tconst HIP_TEXTURE_DESC* pTexDesc = N/A, try to update csv files\n"); \
	printf("\tconst HIP_RESOURCE_VIEW_DESC* pResViewDesc = N/A, try to update csv files\n"); \
};

//	size_t * pValue (unsigned long*);
//	enum hipLimit_t limit (enum);
#define PROCESS_ARGS_hipDeviceGetLimit(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceGetLimit.retval); \
	printf("\tsize_t * pValue = %p", args->hipDeviceGetLimit.pValue); \
	if (args->hipDeviceGetLimit.pValue != NULL) { \
		printf(" -> %lu\n", args->hipDeviceGetLimit.pValue__ref.val); \
	} else { printf("\n"); }; \
	printf("\tenum hipLimit_t limit = %d\n", args->hipDeviceGetLimit.limit); \
};

//	void ** ptr (void**);
//	size_t sizeBytes (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipExtMallocWithFlags(args) { \
	printf("\thipError_t retval = %d\n", args->hipExtMallocWithFlags.retval); \
	printf("\tvoid ** ptr = %p", args->hipExtMallocWithFlags.ptr); \
	if (args->hipExtMallocWithFlags.ptr != NULL) { \
		printf("-> %p", args->hipExtMallocWithFlags.ptr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t sizeBytes = %lu\n", args->hipExtMallocWithFlags.sizeBytes); \
	printf("\tunsigned int flags = %u\n", args->hipExtMallocWithFlags.flags); \
};

//	hipError_t hip_error (enum);
#define PROCESS_ARGS_hipGetErrorName(args) { \
	printf("\tconst char * retval = %s\n", args->hipGetErrorName.retval); \
	printf("\thipError_t hip_error = %d\n", args->hipGetErrorName.hip_error); \
};

//	const struct hipMemcpy3DParms * p (unknown);
#define PROCESS_ARGS_hipMemcpy3D(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpy3D.retval); \
	printf("\tconst struct hipMemcpy3DParms * p = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t node (opaque);
//	void * dst (void*);
//	const void * symbol (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParamsFromSymbol(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphMemcpyNodeSetParamsFromSymbol.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphMemcpyNodeSetParamsFromSymbol.node); \
	printf("\tvoid * dst = %p", args->hipGraphMemcpyNodeSetParamsFromSymbol.dst); \
	printf("\n"); \
	printf("\tconst void * symbol = %p", args->hipGraphMemcpyNodeSetParamsFromSymbol.symbol); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipGraphMemcpyNodeSetParamsFromSymbol.count); \
	printf("\tsize_t offset = %lu\n", args->hipGraphMemcpyNodeSetParamsFromSymbol.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	void ** data (void**);
//	size_t * data_sizes (unsigned long*);
//	hipMemRangeAttribute * attributes (enum*);
//	size_t num_attributes (unsigned long);
//	const void * dev_ptr (void*);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemRangeGetAttributes(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemRangeGetAttributes.retval); \
	printf("\tvoid ** data = %p", args->hipMemRangeGetAttributes.data); \
	if (args->hipMemRangeGetAttributes.data != NULL) { \
		printf("-> %p", args->hipMemRangeGetAttributes.data__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t * data_sizes = %p", args->hipMemRangeGetAttributes.data_sizes); \
	if (args->hipMemRangeGetAttributes.data_sizes != NULL) { \
		printf(" -> %lu\n", args->hipMemRangeGetAttributes.data_sizes__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipMemRangeAttribute * attributes = %p", args->hipMemRangeGetAttributes.attributes); \
	if (args->hipMemRangeGetAttributes.attributes != NULL) { \
		printf(" -> %d\n", args->hipMemRangeGetAttributes.attributes__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t num_attributes = %lu\n", args->hipMemRangeGetAttributes.num_attributes); \
	printf("\tconst void * dev_ptr = %p", args->hipMemRangeGetAttributes.dev_ptr); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipMemRangeGetAttributes.count); \
};

//	hipGraph_t graph (opaque);
//	const char * path (string*);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipGraphDebugDotPrint(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphDebugDotPrint.retval); \
	printf("\thipGraph_t graph = %p\n", args->hipGraphDebugDotPrint.graph); \
	printf("\tconst char * path = %p", args->hipGraphDebugDotPrint.path); \
	if (args->hipGraphDebugDotPrint.path != NULL) { \
		printf(" -> %s\n", args->hipGraphDebugDotPrint.path__ref.val); \
	} else { printf("\n"); }; \
	printf("\tunsigned int flags = %u\n", args->hipGraphDebugDotPrint.flags); \
};

//	hipGraphNode_t hNode (opaque);
//	hipExternalSemaphoreWaitNodeParams * params_out ({
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphExternalSemaphoresWaitNodeGetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExternalSemaphoresWaitNodeGetParams.retval); \
	printf("\thipGraphNode_t hNode = %p\n", args->hipGraphExternalSemaphoresWaitNodeGetParams.hNode); \
	printf("\thipExternalSemaphoreWaitNodeParams * params_out = %p", args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out); \
	if (args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned int numExtSems = %u\n", args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out__ref.val.numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	void * dst (void*);
//	int value (int);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemset(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemset.retval); \
	printf("\tvoid * dst = %p", args->hipMemset.dst); \
	printf("\n"); \
	printf("\tint value = %d\n", args->hipMemset.value); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemset.sizeBytes); \
};

//	hipGraphNode_t * pGraphNode (opaque*);
//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * pDependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	const hipHostNodeParams* pNodeParams ({
//		hipHostFn_t fn (function);
//	});
#define PROCESS_ARGS_hipGraphAddHostNode(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddHostNode.retval); \
	printf("\thipGraphNode_t * pGraphNode = %p", args->hipGraphAddHostNode.pGraphNode); \
	if (args->hipGraphAddHostNode.pGraphNode != NULL) { \
		printf(" -> %p\n", args->hipGraphAddHostNode.pGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddHostNode.graph); \
	printf("\tconst hipGraphNode_t * pDependencies = %p", args->hipGraphAddHostNode.pDependencies); \
	if (args->hipGraphAddHostNode.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphAddHostNode.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddHostNode.numDependencies); \
	printf("\tconst hipHostNodeParams* pNodeParams = %p", args->hipGraphAddHostNode.pNodeParams); \
	if (args->hipGraphAddHostNode.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipHostFn_t fn = %p\n", args->hipGraphAddHostNode.pNodeParams__ref.val.fn); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraphNode_t * pGraphNode (opaque*);
//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * pDependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	const hipMemcpy3DParms* pCopyParams (unknown);
#define PROCESS_ARGS_hipGraphAddMemcpyNode(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddMemcpyNode.retval); \
	printf("\thipGraphNode_t * pGraphNode = %p", args->hipGraphAddMemcpyNode.pGraphNode); \
	if (args->hipGraphAddMemcpyNode.pGraphNode != NULL) { \
		printf(" -> %p\n", args->hipGraphAddMemcpyNode.pGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddMemcpyNode.graph); \
	printf("\tconst hipGraphNode_t * pDependencies = %p", args->hipGraphAddMemcpyNode.pDependencies); \
	if (args->hipGraphAddMemcpyNode.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphAddMemcpyNode.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddMemcpyNode.numDependencies); \
	printf("\tconst hipMemcpy3DParms* pCopyParams = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t node (opaque);
//	hipHostNodeParams * pNodeParams ({
//		hipHostFn_t fn (function);
//	});
#define PROCESS_ARGS_hipGraphHostNodeGetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphHostNodeGetParams.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphHostNodeGetParams.node); \
	printf("\thipHostNodeParams * pNodeParams = %p", args->hipGraphHostNodeGetParams.pNodeParams); \
	if (args->hipGraphHostNodeGetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipHostFn_t fn = %p\n", args->hipGraphHostNodeGetParams.pNodeParams__ref.val.fn); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	int * device (int*);
//	const char * pciBusId (string*);
#define PROCESS_ARGS_hipDeviceGetByPCIBusId(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceGetByPCIBusId.retval); \
	printf("\tint * device = %p", args->hipDeviceGetByPCIBusId.device); \
	if (args->hipDeviceGetByPCIBusId.device != NULL) { \
		printf(" -> %d\n", args->hipDeviceGetByPCIBusId.device__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst char * pciBusId = %p", args->hipDeviceGetByPCIBusId.pciBusId); \
	if (args->hipDeviceGetByPCIBusId.pciBusId != NULL) { \
		printf(" -> %s\n", args->hipDeviceGetByPCIBusId.pciBusId__ref.val); \
	} else { printf("\n"); }; \
};

//	hipDeviceptr_t dst (void*);
//	hipDeviceptr_t src (void*);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemcpyDtoD(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyDtoD.retval); \
	printf("\thipDeviceptr_t dst = %p", args->hipMemcpyDtoD.dst); \
	printf("\n"); \
	printf("\thipDeviceptr_t src = %p", args->hipMemcpyDtoD.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyDtoD.sizeBytes); \
};

//	hipIpcEventHandle_t * handle ({
//		char[64] reserved (string);
//	});
//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipIpcGetEventHandle(args) { \
	printf("\thipError_t retval = %d\n", args->hipIpcGetEventHandle.retval); \
	printf("\thipIpcEventHandle_t * handle = %p", args->hipIpcGetEventHandle.handle); \
	if (args->hipIpcGetEventHandle.handle != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tchar[64] reserved = %s\n", args->hipIpcGetEventHandle.handle__ref.val.reserved[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thipEvent_t event = %p\n", args->hipIpcGetEventHandle.event); \
};

//	hipGraphNode_t node (opaque);
//	const hipKernelNodeParams * pNodeParams ({
//		dim3 blockDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		dim3 gridDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		unsigned int sharedMemBytes (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphKernelNodeSetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphKernelNodeSetParams.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphKernelNodeSetParams.node); \
	printf("\tconst hipKernelNodeParams * pNodeParams = %p", args->hipGraphKernelNodeSetParams.pNodeParams); \
	if (args->hipGraphKernelNodeSetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tdim3 blockDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hipGraphKernelNodeSetParams.pNodeParams__ref.val.blockDim.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hipGraphKernelNodeSetParams.pNodeParams__ref.val.blockDim.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hipGraphKernelNodeSetParams.pNodeParams__ref.val.blockDim.z); \
		printf("\t\t}\n"); \
		printf("\t\tdim3 gridDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hipGraphKernelNodeSetParams.pNodeParams__ref.val.gridDim.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hipGraphKernelNodeSetParams.pNodeParams__ref.val.gridDim.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hipGraphKernelNodeSetParams.pNodeParams__ref.val.gridDim.z); \
		printf("\t\t}\n"); \
		printf("\t\tunsigned int sharedMemBytes = %u\n", args->hipGraphKernelNodeSetParams.pNodeParams__ref.val.sharedMemBytes); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipFunction_t * function (opaque*);
//	hipModule_t module (opaque);
//	const char * kname (string*);
#define PROCESS_ARGS_hipModuleGetFunction(args) { \
	printf("\thipError_t retval = %d\n", args->hipModuleGetFunction.retval); \
	printf("\thipFunction_t * function = %p", args->hipModuleGetFunction.function); \
	if (args->hipModuleGetFunction.function != NULL) { \
		printf(" -> %p\n", args->hipModuleGetFunction.function__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipModule_t module = %p\n", args->hipModuleGetFunction.module); \
	printf("\tconst char * kname = %p", args->hipModuleGetFunction.kname); \
	if (args->hipModuleGetFunction.kname != NULL) { \
		printf(" -> %s\n", args->hipModuleGetFunction.kname__ref.val); \
	} else { printf("\n"); }; \
};

//	void * dst (void*);
//	hipArray_t srcArray (unknown);
//	size_t srcOffset (unsigned long);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemcpyAtoH(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyAtoH.retval); \
	printf("\tvoid * dst = %p", args->hipMemcpyAtoH.dst); \
	printf("\n"); \
	printf("\thipArray_t srcArray = N/A, try to update csv files\n"); \
	printf("\tsize_t srcOffset = %lu\n", args->hipMemcpyAtoH.srcOffset); \
	printf("\tsize_t count = %lu\n", args->hipMemcpyAtoH.count); \
};

//	int peerDeviceId (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipDeviceEnablePeerAccess(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceEnablePeerAccess.retval); \
	printf("\tint peerDeviceId = %d\n", args->hipDeviceEnablePeerAccess.peerDeviceId); \
	printf("\tunsigned int flags = %u\n", args->hipDeviceEnablePeerAccess.flags); \
};

//	hipMemGenericAllocationHandle_t * handle (opaque*);
//	void * addr (void*);
#define PROCESS_ARGS_hipMemRetainAllocationHandle(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemRetainAllocationHandle.retval); \
	printf("\thipMemGenericAllocationHandle_t * handle = %p", args->hipMemRetainAllocationHandle.handle); \
	if (args->hipMemRetainAllocationHandle.handle != NULL) { \
		printf(" -> %p\n", args->hipMemRetainAllocationHandle.handle__ref.val); \
	} else { printf("\n"); }; \
	printf("\tvoid * addr = %p", args->hipMemRetainAllocationHandle.addr); \
	printf("\n"); \
};

//	hipMipmappedArray_t* pArray (unknown);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipMappedArray(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefGetMipMappedArray.retval); \
	printf("\thipMipmappedArray_t* pArray = N/A, try to update csv files\n"); \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	float * pbias (float*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipmapLevelBias(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefGetMipmapLevelBias.retval); \
	printf("\tfloat * pbias = %p", args->hipTexRefGetMipmapLevelBias.pbias); \
	if (args->hipTexRefGetMipmapLevelBias.pbias != NULL) { \
		printf(" -> %f\n", args->hipTexRefGetMipmapLevelBias.pbias__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	size_t * offset (unsigned long*);
//	const textureReference* tex (unknown);
//	const void * devPtr (void*);
//	const hipChannelFormatDesc * desc (unknown);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipBindTexture(args) { \
	printf("\thipError_t retval = %d\n", args->hipBindTexture.retval); \
	printf("\tsize_t * offset = %p", args->hipBindTexture.offset); \
	if (args->hipBindTexture.offset != NULL) { \
		printf(" -> %lu\n", args->hipBindTexture.offset__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* tex = N/A, try to update csv files\n"); \
	printf("\tconst void * devPtr = %p", args->hipBindTexture.devPtr); \
	printf("\n"); \
	printf("\tconst hipChannelFormatDesc * desc = N/A, try to update csv files\n"); \
	printf("\tsize_t size = %lu\n", args->hipBindTexture.size); \
};

//	hipGraphNode_t * pGraphNode (opaque*);
//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * pDependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	hipGraph_t childGraph (opaque);
#define PROCESS_ARGS_hipGraphAddChildGraphNode(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddChildGraphNode.retval); \
	printf("\thipGraphNode_t * pGraphNode = %p", args->hipGraphAddChildGraphNode.pGraphNode); \
	if (args->hipGraphAddChildGraphNode.pGraphNode != NULL) { \
		printf(" -> %p\n", args->hipGraphAddChildGraphNode.pGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddChildGraphNode.graph); \
	printf("\tconst hipGraphNode_t * pDependencies = %p", args->hipGraphAddChildGraphNode.pDependencies); \
	if (args->hipGraphAddChildGraphNode.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphAddChildGraphNode.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddChildGraphNode.numDependencies); \
	printf("\thipGraph_t childGraph = %p\n", args->hipGraphAddChildGraphNode.childGraph); \
};

//	enum hipLimit_t limit (enum);
//	size_t value (unsigned long);
#define PROCESS_ARGS_hipDeviceSetLimit(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceSetLimit.retval); \
	printf("\tenum hipLimit_t limit = %d\n", args->hipDeviceSetLimit.limit); \
	printf("\tsize_t value = %lu\n", args->hipDeviceSetLimit.value); \
};

//	hipChannelFormatDesc * desc (unknown);
//	hipArray_const_t array (unknown);
#define PROCESS_ARGS_hipGetChannelDesc(args) { \
	printf("\thipError_t retval = %d\n", args->hipGetChannelDesc.retval); \
	printf("\thipChannelFormatDesc * desc = N/A, try to update csv files\n"); \
	printf("\thipArray_const_t array = N/A, try to update csv files\n"); \
};

//	hipGraphicsResource_t resource (opaque);
#define PROCESS_ARGS_hipGraphicsUnregisterResource(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphicsUnregisterResource.retval); \
	printf("\thipGraphicsResource_t resource = %p\n", args->hipGraphicsUnregisterResource.resource); \
};

//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * from (opaque*);
//	const hipGraphNode_t * to (opaque*);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphRemoveDependencies(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphRemoveDependencies.retval); \
	printf("\thipGraph_t graph = %p\n", args->hipGraphRemoveDependencies.graph); \
	printf("\tconst hipGraphNode_t * from = %p", args->hipGraphRemoveDependencies.from); \
	if (args->hipGraphRemoveDependencies.from != NULL) { \
		printf(" -> %p\n", args->hipGraphRemoveDependencies.from__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst hipGraphNode_t * to = %p", args->hipGraphRemoveDependencies.to); \
	if (args->hipGraphRemoveDependencies.to != NULL) { \
		printf(" -> %p\n", args->hipGraphRemoveDependencies.to__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphRemoveDependencies.numDependencies); \
};

//	textureReference* texRef (unknown);
//	float * pBorderColor (float*);
#define PROCESS_ARGS_hipTexRefSetBorderColor(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefSetBorderColor.retval); \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tfloat * pBorderColor = %p", args->hipTexRefSetBorderColor.pBorderColor); \
	if (args->hipTexRefSetBorderColor.pBorderColor != NULL) { \
		printf(" -> %f\n", args->hipTexRefSetBorderColor.pBorderColor__ref.val); \
	} else { printf("\n"); }; \
};

//	hipDevice_t dev (int);
//	unsigned int * flags (unsigned int*);
//	int * active (int*);
#define PROCESS_ARGS_hipDevicePrimaryCtxGetState(args) { \
	printf("\thipError_t retval = %d\n", args->hipDevicePrimaryCtxGetState.retval); \
	printf("\thipDevice_t dev = %d\n", args->hipDevicePrimaryCtxGetState.dev); \
	printf("\tunsigned int * flags = %p", args->hipDevicePrimaryCtxGetState.flags); \
	if (args->hipDevicePrimaryCtxGetState.flags != NULL) { \
		printf(" -> %u\n", args->hipDevicePrimaryCtxGetState.flags__ref.val); \
	} else { printf("\n"); }; \
	printf("\tint * active = %p", args->hipDevicePrimaryCtxGetState.active); \
	if (args->hipDevicePrimaryCtxGetState.active != NULL) { \
		printf(" -> %d\n", args->hipDevicePrimaryCtxGetState.active__ref.val); \
	} else { printf("\n"); }; \
};

//	hipPitchedPtr* pitchedDevPtr (unknown);
//	hipExtent extent (unknown);
#define PROCESS_ARGS_hipMalloc3D(args) { \
	printf("\thipError_t retval = %d\n", args->hipMalloc3D.retval); \
	printf("\thipPitchedPtr* pitchedDevPtr = N/A, try to update csv files\n"); \
	printf("\thipExtent extent = N/A, try to update csv files\n"); \
};

//	float * pminMipmapLevelClamp (float*);
//	float * pmaxMipmapLevelClamp (float*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipmapLevelClamp(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefGetMipmapLevelClamp.retval); \
	printf("\tfloat * pminMipmapLevelClamp = %p", args->hipTexRefGetMipmapLevelClamp.pminMipmapLevelClamp); \
	if (args->hipTexRefGetMipmapLevelClamp.pminMipmapLevelClamp != NULL) { \
		printf(" -> %f\n", args->hipTexRefGetMipmapLevelClamp.pminMipmapLevelClamp__ref.val); \
	} else { printf("\n"); }; \
	printf("\tfloat * pmaxMipmapLevelClamp = %p", args->hipTexRefGetMipmapLevelClamp.pmaxMipmapLevelClamp); \
	if (args->hipTexRefGetMipmapLevelClamp.pmaxMipmapLevelClamp != NULL) { \
		printf(" -> %f\n", args->hipTexRefGetMipmapLevelClamp.pmaxMipmapLevelClamp__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
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
//	void ** kernelParams (void**);
//	void ** extra (void**);
#define PROCESS_ARGS_hipModuleLaunchKernel(args) { \
	printf("\thipError_t retval = %d\n", args->hipModuleLaunchKernel.retval); \
	printf("\thipFunction_t f = %p\n", args->hipModuleLaunchKernel.f); \
	printf("\tunsigned int gridDimX = %u\n", args->hipModuleLaunchKernel.gridDimX); \
	printf("\tunsigned int gridDimY = %u\n", args->hipModuleLaunchKernel.gridDimY); \
	printf("\tunsigned int gridDimZ = %u\n", args->hipModuleLaunchKernel.gridDimZ); \
	printf("\tunsigned int blockDimX = %u\n", args->hipModuleLaunchKernel.blockDimX); \
	printf("\tunsigned int blockDimY = %u\n", args->hipModuleLaunchKernel.blockDimY); \
	printf("\tunsigned int blockDimZ = %u\n", args->hipModuleLaunchKernel.blockDimZ); \
	printf("\tunsigned int sharedMemBytes = %u\n", args->hipModuleLaunchKernel.sharedMemBytes); \
	printf("\thipStream_t stream = %p\n", args->hipModuleLaunchKernel.stream); \
	printf("\tvoid ** kernelParams = %p", args->hipModuleLaunchKernel.kernelParams); \
	if (args->hipModuleLaunchKernel.kernelParams != NULL) { \
		printf("-> %p", args->hipModuleLaunchKernel.kernelParams__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tvoid ** extra = %p", args->hipModuleLaunchKernel.extra); \
	if (args->hipModuleLaunchKernel.extra != NULL) { \
		printf("-> %p", args->hipModuleLaunchKernel.extra__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
};

//	const void * hostFunction (void*);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipKernelNameRefByPtr(args) { \
	printf("\tconst char * retval = %s\n", args->hipKernelNameRefByPtr.retval); \
	printf("\tconst void * hostFunction = %p", args->hipKernelNameRefByPtr.hostFunction); \
	printf("\n"); \
	printf("\thipStream_t stream = %p\n", args->hipKernelNameRefByPtr.stream); \
};

//	hipSharedMemConfig config (enum);
#define PROCESS_ARGS_hipDeviceSetSharedMemConfig(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceSetSharedMemConfig.retval); \
	printf("\thipSharedMemConfig config = %d\n", args->hipDeviceSetSharedMemConfig.config); \
};

//	const void * symbol (void*);
//	const void * src (void*);
//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyToSymbolAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyToSymbolAsync.retval); \
	printf("\tconst void * symbol = %p", args->hipMemcpyToSymbolAsync.symbol); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipMemcpyToSymbolAsync.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyToSymbolAsync.sizeBytes); \
	printf("\tsize_t offset = %lu\n", args->hipMemcpyToSymbolAsync.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = %p\n", args->hipMemcpyToSymbolAsync.stream); \
};

//	void ** devPtr (void**);
//	void * hstPtr (void*);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostGetDevicePointer(args) { \
	printf("\thipError_t retval = %d\n", args->hipHostGetDevicePointer.retval); \
	printf("\tvoid ** devPtr = %p", args->hipHostGetDevicePointer.devPtr); \
	if (args->hipHostGetDevicePointer.devPtr != NULL) { \
		printf("-> %p", args->hipHostGetDevicePointer.devPtr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tvoid * hstPtr = %p", args->hipHostGetDevicePointer.hstPtr); \
	printf("\n"); \
	printf("\tunsigned int flags = %u\n", args->hipHostGetDevicePointer.flags); \
};

//	hipGraph_t graph (opaque);
//	hipUserObject_t object (opaque);
//	unsigned int count (unsigned int);
#define PROCESS_ARGS_hipGraphReleaseUserObject(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphReleaseUserObject.retval); \
	printf("\thipGraph_t graph = %p\n", args->hipGraphReleaseUserObject.graph); \
	printf("\thipUserObject_t object = %p\n", args->hipGraphReleaseUserObject.object); \
	printf("\tunsigned int count = %u\n", args->hipGraphReleaseUserObject.count); \
};

//	int device (int);
#define PROCESS_ARGS_hipDeviceGraphMemTrim(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceGraphMemTrim.retval); \
	printf("\tint device = %d\n", args->hipDeviceGraphMemTrim.device); \
};

//	int * leastPriority (int*);
//	int * greatestPriority (int*);
#define PROCESS_ARGS_hipDeviceGetStreamPriorityRange(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceGetStreamPriorityRange.retval); \
	printf("\tint * leastPriority = %p", args->hipDeviceGetStreamPriorityRange.leastPriority); \
	if (args->hipDeviceGetStreamPriorityRange.leastPriority != NULL) { \
		printf(" -> %d\n", args->hipDeviceGetStreamPriorityRange.leastPriority__ref.val); \
	} else { printf("\n"); }; \
	printf("\tint * greatestPriority = %p", args->hipDeviceGetStreamPriorityRange.greatestPriority); \
	if (args->hipDeviceGetStreamPriorityRange.greatestPriority != NULL) { \
		printf(" -> %d\n", args->hipDeviceGetStreamPriorityRange.greatestPriority__ref.val); \
	} else { printf("\n"); }; \
};

//	void * data (void*);
//	hipPointer_attribute attribute (unknown);
//	hipDeviceptr_t ptr (void*);
#define PROCESS_ARGS_hipPointerGetAttribute(args) { \
	printf("\thipError_t retval = %d\n", args->hipPointerGetAttribute.retval); \
	printf("\tvoid * data = %p", args->hipPointerGetAttribute.data); \
	printf("\n"); \
	printf("\thipPointer_attribute attribute = N/A, try to update csv files\n"); \
	printf("\thipDeviceptr_t ptr = %p", args->hipPointerGetAttribute.ptr); \
	printf("\n"); \
};

//	hipMemPool_t mem_pool (opaque);
//	const hipMemAccessDesc * desc_list ({
//		hipMemLocation location ({
//			hipMemLocationType type (enum);
//			int id (int);
//		});
//		hipMemAccessFlags flags (enum);
//	});
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemPoolSetAccess(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemPoolSetAccess.retval); \
	printf("\thipMemPool_t mem_pool = %p\n", args->hipMemPoolSetAccess.mem_pool); \
	printf("\tconst hipMemAccessDesc * desc_list = %p", args->hipMemPoolSetAccess.desc_list); \
	if (args->hipMemPoolSetAccess.desc_list != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemLocation location = {\n"); \
		printf("\t\t\thipMemLocationType type = %d\n", args->hipMemPoolSetAccess.desc_list__ref.val.location.type); \
		printf("\t\t\tint id = %d\n", args->hipMemPoolSetAccess.desc_list__ref.val.location.id); \
		printf("\t\t}\n"); \
		printf("\t\thipMemAccessFlags flags = %d\n", args->hipMemPoolSetAccess.desc_list__ref.val.flags); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t count = %lu\n", args->hipMemPoolSetAccess.count); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t hNode (opaque);
//	const hipExternalSemaphoreWaitNodeParams * nodeParams ({
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphExecExternalSemaphoresWaitNodeSetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExecExternalSemaphoresWaitNodeSetParams.retval); \
	printf("\thipGraphExec_t hGraphExec = %p\n", args->hipGraphExecExternalSemaphoresWaitNodeSetParams.hGraphExec); \
	printf("\thipGraphNode_t hNode = %p\n", args->hipGraphExecExternalSemaphoresWaitNodeSetParams.hNode); \
	printf("\tconst hipExternalSemaphoreWaitNodeParams * nodeParams = %p", args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams); \
	if (args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned int numExtSems = %u\n", args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams__ref.val.numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	void * dst (void*);
//	const void * src (void*);
//	size_t sizeBytes (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpy(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpy.retval); \
	printf("\tvoid * dst = %p", args->hipMemcpy.dst); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipMemcpy.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpy.sizeBytes); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	int peerDeviceId (int);
#define PROCESS_ARGS_hipDeviceDisablePeerAccess(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceDisablePeerAccess.retval); \
	printf("\tint peerDeviceId = %d\n", args->hipDeviceDisablePeerAccess.peerDeviceId); \
};

//	hipGraphNode_t hNode (opaque);
//	hipKernelNodeAttrID attr (enum);
//	const hipKernelNodeAttrValue * value ({
//		hipAccessPolicyWindow accessPolicyWindow ({
//			hipAccessProperty hitProp (enum);
//			float hitRatio (float);
//			hipAccessProperty missProp (enum);
//			int num_bytes (int);
//		});
//		int cooperative (int);
//	});
#define PROCESS_ARGS_hipGraphKernelNodeSetAttribute(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphKernelNodeSetAttribute.retval); \
	printf("\thipGraphNode_t hNode = %p\n", args->hipGraphKernelNodeSetAttribute.hNode); \
	printf("\thipKernelNodeAttrID attr = %d\n", args->hipGraphKernelNodeSetAttribute.attr); \
	printf("\tconst hipKernelNodeAttrValue * value = %p", args->hipGraphKernelNodeSetAttribute.value); \
	if (args->hipGraphKernelNodeSetAttribute.value != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipAccessPolicyWindow accessPolicyWindow = {\n"); \
		printf("\t\t\thipAccessProperty hitProp = %d\n", args->hipGraphKernelNodeSetAttribute.value__ref.val.accessPolicyWindow.hitProp); \
		printf("\t\t\tfloat hitRatio = %f\n", args->hipGraphKernelNodeSetAttribute.value__ref.val.accessPolicyWindow.hitRatio); \
		printf("\t\t\thipAccessProperty missProp = %d\n", args->hipGraphKernelNodeSetAttribute.value__ref.val.accessPolicyWindow.missProp); \
		printf("\t\t\tint num_bytes = %d\n", args->hipGraphKernelNodeSetAttribute.value__ref.val.accessPolicyWindow.num_bytes); \
		printf("\t\t}\n"); \
		printf("\t\tint cooperative = %d\n", args->hipGraphKernelNodeSetAttribute.value__ref.val.cooperative); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraphNode_t * pGraphNode (opaque*);
//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * pDependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	void * dst (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphAddMemcpyNode1D(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddMemcpyNode1D.retval); \
	printf("\thipGraphNode_t * pGraphNode = %p", args->hipGraphAddMemcpyNode1D.pGraphNode); \
	if (args->hipGraphAddMemcpyNode1D.pGraphNode != NULL) { \
		printf(" -> %p\n", args->hipGraphAddMemcpyNode1D.pGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddMemcpyNode1D.graph); \
	printf("\tconst hipGraphNode_t * pDependencies = %p", args->hipGraphAddMemcpyNode1D.pDependencies); \
	if (args->hipGraphAddMemcpyNode1D.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphAddMemcpyNode1D.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddMemcpyNode1D.numDependencies); \
	printf("\tvoid * dst = %p", args->hipGraphAddMemcpyNode1D.dst); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipGraphAddMemcpyNode1D.src); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipGraphAddMemcpyNode1D.count); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t hNode (opaque);
//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipGraphExecEventRecordNodeSetEvent(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExecEventRecordNodeSetEvent.retval); \
	printf("\thipGraphExec_t hGraphExec = %p\n", args->hipGraphExecEventRecordNodeSetEvent.hGraphExec); \
	printf("\thipGraphNode_t hNode = %p\n", args->hipGraphExecEventRecordNodeSetEvent.hNode); \
	printf("\thipEvent_t event = %p\n", args->hipGraphExecEventRecordNodeSetEvent.event); \
};

//	int count (int);
//	hipGraphicsResource_t * resources (opaque*);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipGraphicsUnmapResources(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphicsUnmapResources.retval); \
	printf("\tint count = %d\n", args->hipGraphicsUnmapResources.count); \
	printf("\thipGraphicsResource_t * resources = %p", args->hipGraphicsUnmapResources.resources); \
	if (args->hipGraphicsUnmapResources.resources != NULL) { \
		printf(" -> %p\n", args->hipGraphicsUnmapResources.resources__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipStream_t stream = %p\n", args->hipGraphicsUnmapResources.stream); \
};

//	hipGraphNode_t * pGraphNode (opaque*);
//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * pDependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	const hipExternalSemaphoreWaitNodeParams * nodeParams ({
//		unsigned int numExtSems (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphAddExternalSemaphoresWaitNode(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddExternalSemaphoresWaitNode.retval); \
	printf("\thipGraphNode_t * pGraphNode = %p", args->hipGraphAddExternalSemaphoresWaitNode.pGraphNode); \
	if (args->hipGraphAddExternalSemaphoresWaitNode.pGraphNode != NULL) { \
		printf(" -> %p\n", args->hipGraphAddExternalSemaphoresWaitNode.pGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddExternalSemaphoresWaitNode.graph); \
	printf("\tconst hipGraphNode_t * pDependencies = %p", args->hipGraphAddExternalSemaphoresWaitNode.pDependencies); \
	if (args->hipGraphAddExternalSemaphoresWaitNode.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphAddExternalSemaphoresWaitNode.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddExternalSemaphoresWaitNode.numDependencies); \
	printf("\tconst hipExternalSemaphoreWaitNodeParams * nodeParams = %p", args->hipGraphAddExternalSemaphoresWaitNode.nodeParams); \
	if (args->hipGraphAddExternalSemaphoresWaitNode.nodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned int numExtSems = %u\n", args->hipGraphAddExternalSemaphoresWaitNode.nodeParams__ref.val.numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraphNode_t * phGraphNode (opaque*);
//	hipGraph_t hGraph (opaque);
//	const hipGraphNode_t * dependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	const HIP_MEMCPY3D * copyParams (unknown);
//	hipCtx_t ctx (opaque);
#define PROCESS_ARGS_hipDrvGraphAddMemcpyNode(args) { \
	printf("\thipError_t retval = %d\n", args->hipDrvGraphAddMemcpyNode.retval); \
	printf("\thipGraphNode_t * phGraphNode = %p", args->hipDrvGraphAddMemcpyNode.phGraphNode); \
	if (args->hipDrvGraphAddMemcpyNode.phGraphNode != NULL) { \
		printf(" -> %p\n", args->hipDrvGraphAddMemcpyNode.phGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t hGraph = %p\n", args->hipDrvGraphAddMemcpyNode.hGraph); \
	printf("\tconst hipGraphNode_t * dependencies = %p", args->hipDrvGraphAddMemcpyNode.dependencies); \
	if (args->hipDrvGraphAddMemcpyNode.dependencies != NULL) { \
		printf(" -> %p\n", args->hipDrvGraphAddMemcpyNode.dependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipDrvGraphAddMemcpyNode.numDependencies); \
	printf("\tconst HIP_MEMCPY3D * copyParams = N/A, try to update csv files\n"); \
	printf("\thipCtx_t ctx = %p\n", args->hipDrvGraphAddMemcpyNode.ctx); \
};

//	float * ms (float*);
//	hipEvent_t start (opaque);
//	hipEvent_t stop (opaque);
#define PROCESS_ARGS_hipEventElapsedTime(args) { \
	printf("\thipError_t retval = %d\n", args->hipEventElapsedTime.retval); \
	printf("\tfloat * ms = %p", args->hipEventElapsedTime.ms); \
	if (args->hipEventElapsedTime.ms != NULL) { \
		printf(" -> %f\n", args->hipEventElapsedTime.ms__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipEvent_t start = %p\n", args->hipEventElapsedTime.start); \
	printf("\thipEvent_t stop = %p\n", args->hipEventElapsedTime.stop); \
};

//	const struct hipMemcpy3DParms * p (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpy3DAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpy3DAsync.retval); \
	printf("\tconst struct hipMemcpy3DParms * p = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = %p\n", args->hipMemcpy3DAsync.stream); \
};

//	int * pmaxAnsio (int*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMaxAnisotropy(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefGetMaxAnisotropy.retval); \
	printf("\tint * pmaxAnsio = %p", args->hipTexRefGetMaxAnisotropy.pmaxAnsio); \
	if (args->hipTexRefGetMaxAnisotropy.pmaxAnsio != NULL) { \
		printf(" -> %d\n", args->hipTexRefGetMaxAnisotropy.pmaxAnsio__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t node (opaque);
//	hipGraphNode_t * pDependentNodes (opaque*);
//	size_t * pNumDependentNodes (unsigned long*);
#define PROCESS_ARGS_hipGraphNodeGetDependentNodes(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphNodeGetDependentNodes.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphNodeGetDependentNodes.node); \
	printf("\thipGraphNode_t * pDependentNodes = %p", args->hipGraphNodeGetDependentNodes.pDependentNodes); \
	if (args->hipGraphNodeGetDependentNodes.pDependentNodes != NULL) { \
		printf(" -> %p\n", args->hipGraphNodeGetDependentNodes.pDependentNodes__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t * pNumDependentNodes = %p", args->hipGraphNodeGetDependentNodes.pNumDependentNodes); \
	if (args->hipGraphNodeGetDependentNodes.pNumDependentNodes != NULL) { \
		printf(" -> %lu\n", args->hipGraphNodeGetDependentNodes.pNumDependentNodes__ref.val); \
	} else { printf("\n"); }; \
};

//	hipMemPool_t mem_pool (opaque);
//	hipMemPoolAttr attr (enum);
//	void * value (void*);
#define PROCESS_ARGS_hipMemPoolGetAttribute(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemPoolGetAttribute.retval); \
	printf("\thipMemPool_t mem_pool = %p\n", args->hipMemPoolGetAttribute.mem_pool); \
	printf("\thipMemPoolAttr attr = %d\n", args->hipMemPoolGetAttribute.attr); \
	printf("\tvoid * value = %p", args->hipMemPoolGetAttribute.value); \
	printf("\n"); \
};

//	hipStream_t stream (opaque);
//	hipDevice_t * device (int*);
#define PROCESS_ARGS_hipStreamGetDevice(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamGetDevice.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamGetDevice.stream); \
	printf("\thipDevice_t * device = %p", args->hipStreamGetDevice.device); \
	if (args->hipStreamGetDevice.device != NULL) { \
		printf(" -> %d\n", args->hipStreamGetDevice.device__ref.val); \
	} else { printf("\n"); }; \
};

//	hipResourceDesc* pResDesc (unknown);
//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipGetTextureObjectResourceDesc(args) { \
	printf("\thipError_t retval = %d\n", args->hipGetTextureObjectResourceDesc.retval); \
	printf("\thipResourceDesc* pResDesc = N/A, try to update csv files\n"); \
	printf("\thipTextureObject_t textureObject = N/A, try to update csv files\n"); \
};

//	unsigned int * pFlags (unsigned int*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetFlags(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefGetFlags.retval); \
	printf("\tunsigned int * pFlags = %p", args->hipTexRefGetFlags.pFlags); \
	if (args->hipTexRefGetFlags.pFlags != NULL) { \
		printf(" -> %u\n", args->hipTexRefGetFlags.pFlags__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	int * device (int*);
//	const hipDeviceProp_tR0600 * prop ({
//		char[256] name (string);
//		hipUUID uuid ({
//			char[16] bytes (string);
//		});
//		char[8] luid (string);
//		unsigned int luidDeviceNodeMask (unsigned int);
//		int totalGlobalMem (int);
//		int sharedMemPerBlock (int);
//		int regsPerBlock (int);
//		int warpSize (int);
//		int memPitch (int);
//		int maxThreadsPerBlock (int);
//		int[3] maxThreadsDim (int);
//		int[3] maxGridSize (int);
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
//		int[2] maxTexture2D (int);
//		int[2] maxTexture2DMipmap (int);
//		int[3] maxTexture2DLinear (int);
//		int[2] maxTexture2DGather (int);
//		int[3] maxTexture3D (int);
//		int[3] maxTexture3DAlt (int);
//		int maxTextureCubemap (int);
//		int[2] maxTexture1DLayered (int);
//		int[3] maxTexture2DLayered (int);
//		int[2] maxTextureCubemapLayered (int);
//		int maxSurface1D (int);
//		int[2] maxSurface2D (int);
//		int[3] maxSurface3D (int);
//		int[2] maxSurface1DLayered (int);
//		int[3] maxSurface2DLayered (int);
//		int maxSurfaceCubemap (int);
//		int[2] maxSurfaceCubemapLayered (int);
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
//		int[63] reserved (int);
//		int[32] hipReserved (int);
//		char[256] gcnArchName (string);
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
//		int cooperativeMultiDeviceUnmatchedFunc (int);
//		int cooperativeMultiDeviceUnmatchedGridDim (int);
//		int cooperativeMultiDeviceUnmatchedBlockDim (int);
//		int cooperativeMultiDeviceUnmatchedSharedMem (int);
//		int isLargeBar (int);
//		int asicRevision (int);
//	});
#define PROCESS_ARGS_hipChooseDeviceR0600(args) { \
	printf("\thipError_t retval = %d\n", args->hipChooseDeviceR0600.retval); \
	printf("\tint * device = %p", args->hipChooseDeviceR0600.device); \
	if (args->hipChooseDeviceR0600.device != NULL) { \
		printf(" -> %d\n", args->hipChooseDeviceR0600.device__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst hipDeviceProp_tR0600 * prop = %p", args->hipChooseDeviceR0600.prop); \
	if (args->hipChooseDeviceR0600.prop != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tchar[256] name = %s\n", args->hipChooseDeviceR0600.prop__ref.val.name[0]); \
		printf("\t\thipUUID uuid = {\n"); \
		printf("\t\t\tchar[16] bytes = %s\n", args->hipChooseDeviceR0600.prop__ref.val.uuid.bytes[0]); \
		printf("\t\t}\n"); \
		printf("\t\tchar[8] luid = %s\n", args->hipChooseDeviceR0600.prop__ref.val.luid[0]); \
		printf("\t\tunsigned int luidDeviceNodeMask = %u\n", args->hipChooseDeviceR0600.prop__ref.val.luidDeviceNodeMask); \
		printf("\t\tint totalGlobalMem = %d\n", args->hipChooseDeviceR0600.prop__ref.val.totalGlobalMem); \
		printf("\t\tint sharedMemPerBlock = %d\n", args->hipChooseDeviceR0600.prop__ref.val.sharedMemPerBlock); \
		printf("\t\tint regsPerBlock = %d\n", args->hipChooseDeviceR0600.prop__ref.val.regsPerBlock); \
		printf("\t\tint warpSize = %d\n", args->hipChooseDeviceR0600.prop__ref.val.warpSize); \
		printf("\t\tint memPitch = %d\n", args->hipChooseDeviceR0600.prop__ref.val.memPitch); \
		printf("\t\tint maxThreadsPerBlock = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxThreadsPerBlock); \
		printf("\t\tint[3] maxThreadsDim = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxThreadsDim[0]); \
		printf("\t\tint[3] maxGridSize = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxGridSize[0]); \
		printf("\t\tint clockRate = %d\n", args->hipChooseDeviceR0600.prop__ref.val.clockRate); \
		printf("\t\tint totalConstMem = %d\n", args->hipChooseDeviceR0600.prop__ref.val.totalConstMem); \
		printf("\t\tint major = %d\n", args->hipChooseDeviceR0600.prop__ref.val.major); \
		printf("\t\tint minor = %d\n", args->hipChooseDeviceR0600.prop__ref.val.minor); \
		printf("\t\tint textureAlignment = %d\n", args->hipChooseDeviceR0600.prop__ref.val.textureAlignment); \
		printf("\t\tint texturePitchAlignment = %d\n", args->hipChooseDeviceR0600.prop__ref.val.texturePitchAlignment); \
		printf("\t\tint deviceOverlap = %d\n", args->hipChooseDeviceR0600.prop__ref.val.deviceOverlap); \
		printf("\t\tint multiProcessorCount = %d\n", args->hipChooseDeviceR0600.prop__ref.val.multiProcessorCount); \
		printf("\t\tint kernelExecTimeoutEnabled = %d\n", args->hipChooseDeviceR0600.prop__ref.val.kernelExecTimeoutEnabled); \
		printf("\t\tint integrated = %d\n", args->hipChooseDeviceR0600.prop__ref.val.integrated); \
		printf("\t\tint canMapHostMemory = %d\n", args->hipChooseDeviceR0600.prop__ref.val.canMapHostMemory); \
		printf("\t\tint computeMode = %d\n", args->hipChooseDeviceR0600.prop__ref.val.computeMode); \
		printf("\t\tint maxTexture1D = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxTexture1D); \
		printf("\t\tint maxTexture1DMipmap = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxTexture1DMipmap); \
		printf("\t\tint maxTexture1DLinear = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxTexture1DLinear); \
		printf("\t\tint[2] maxTexture2D = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxTexture2D[0]); \
		printf("\t\tint[2] maxTexture2DMipmap = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxTexture2DMipmap[0]); \
		printf("\t\tint[3] maxTexture2DLinear = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxTexture2DLinear[0]); \
		printf("\t\tint[2] maxTexture2DGather = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxTexture2DGather[0]); \
		printf("\t\tint[3] maxTexture3D = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxTexture3D[0]); \
		printf("\t\tint[3] maxTexture3DAlt = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxTexture3DAlt[0]); \
		printf("\t\tint maxTextureCubemap = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxTextureCubemap); \
		printf("\t\tint[2] maxTexture1DLayered = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxTexture1DLayered[0]); \
		printf("\t\tint[3] maxTexture2DLayered = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxTexture2DLayered[0]); \
		printf("\t\tint[2] maxTextureCubemapLayered = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxTextureCubemapLayered[0]); \
		printf("\t\tint maxSurface1D = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxSurface1D); \
		printf("\t\tint[2] maxSurface2D = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxSurface2D[0]); \
		printf("\t\tint[3] maxSurface3D = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxSurface3D[0]); \
		printf("\t\tint[2] maxSurface1DLayered = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxSurface1DLayered[0]); \
		printf("\t\tint[3] maxSurface2DLayered = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxSurface2DLayered[0]); \
		printf("\t\tint maxSurfaceCubemap = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxSurfaceCubemap); \
		printf("\t\tint[2] maxSurfaceCubemapLayered = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxSurfaceCubemapLayered[0]); \
		printf("\t\tint surfaceAlignment = %d\n", args->hipChooseDeviceR0600.prop__ref.val.surfaceAlignment); \
		printf("\t\tint concurrentKernels = %d\n", args->hipChooseDeviceR0600.prop__ref.val.concurrentKernels); \
		printf("\t\tint ECCEnabled = %d\n", args->hipChooseDeviceR0600.prop__ref.val.ECCEnabled); \
		printf("\t\tint pciBusID = %d\n", args->hipChooseDeviceR0600.prop__ref.val.pciBusID); \
		printf("\t\tint pciDeviceID = %d\n", args->hipChooseDeviceR0600.prop__ref.val.pciDeviceID); \
		printf("\t\tint pciDomainID = %d\n", args->hipChooseDeviceR0600.prop__ref.val.pciDomainID); \
		printf("\t\tint tccDriver = %d\n", args->hipChooseDeviceR0600.prop__ref.val.tccDriver); \
		printf("\t\tint asyncEngineCount = %d\n", args->hipChooseDeviceR0600.prop__ref.val.asyncEngineCount); \
		printf("\t\tint unifiedAddressing = %d\n", args->hipChooseDeviceR0600.prop__ref.val.unifiedAddressing); \
		printf("\t\tint memoryClockRate = %d\n", args->hipChooseDeviceR0600.prop__ref.val.memoryClockRate); \
		printf("\t\tint memoryBusWidth = %d\n", args->hipChooseDeviceR0600.prop__ref.val.memoryBusWidth); \
		printf("\t\tint l2CacheSize = %d\n", args->hipChooseDeviceR0600.prop__ref.val.l2CacheSize); \
		printf("\t\tint persistingL2CacheMaxSize = %d\n", args->hipChooseDeviceR0600.prop__ref.val.persistingL2CacheMaxSize); \
		printf("\t\tint maxThreadsPerMultiProcessor = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxThreadsPerMultiProcessor); \
		printf("\t\tint streamPrioritiesSupported = %d\n", args->hipChooseDeviceR0600.prop__ref.val.streamPrioritiesSupported); \
		printf("\t\tint globalL1CacheSupported = %d\n", args->hipChooseDeviceR0600.prop__ref.val.globalL1CacheSupported); \
		printf("\t\tint localL1CacheSupported = %d\n", args->hipChooseDeviceR0600.prop__ref.val.localL1CacheSupported); \
		printf("\t\tint sharedMemPerMultiprocessor = %d\n", args->hipChooseDeviceR0600.prop__ref.val.sharedMemPerMultiprocessor); \
		printf("\t\tint regsPerMultiprocessor = %d\n", args->hipChooseDeviceR0600.prop__ref.val.regsPerMultiprocessor); \
		printf("\t\tint managedMemory = %d\n", args->hipChooseDeviceR0600.prop__ref.val.managedMemory); \
		printf("\t\tint isMultiGpuBoard = %d\n", args->hipChooseDeviceR0600.prop__ref.val.isMultiGpuBoard); \
		printf("\t\tint multiGpuBoardGroupID = %d\n", args->hipChooseDeviceR0600.prop__ref.val.multiGpuBoardGroupID); \
		printf("\t\tint hostNativeAtomicSupported = %d\n", args->hipChooseDeviceR0600.prop__ref.val.hostNativeAtomicSupported); \
		printf("\t\tint singleToDoublePrecisionPerfRatio = %d\n", args->hipChooseDeviceR0600.prop__ref.val.singleToDoublePrecisionPerfRatio); \
		printf("\t\tint pageableMemoryAccess = %d\n", args->hipChooseDeviceR0600.prop__ref.val.pageableMemoryAccess); \
		printf("\t\tint concurrentManagedAccess = %d\n", args->hipChooseDeviceR0600.prop__ref.val.concurrentManagedAccess); \
		printf("\t\tint computePreemptionSupported = %d\n", args->hipChooseDeviceR0600.prop__ref.val.computePreemptionSupported); \
		printf("\t\tint canUseHostPointerForRegisteredMem = %d\n", args->hipChooseDeviceR0600.prop__ref.val.canUseHostPointerForRegisteredMem); \
		printf("\t\tint cooperativeLaunch = %d\n", args->hipChooseDeviceR0600.prop__ref.val.cooperativeLaunch); \
		printf("\t\tint cooperativeMultiDeviceLaunch = %d\n", args->hipChooseDeviceR0600.prop__ref.val.cooperativeMultiDeviceLaunch); \
		printf("\t\tint sharedMemPerBlockOptin = %d\n", args->hipChooseDeviceR0600.prop__ref.val.sharedMemPerBlockOptin); \
		printf("\t\tint pageableMemoryAccessUsesHostPageTables = %d\n", args->hipChooseDeviceR0600.prop__ref.val.pageableMemoryAccessUsesHostPageTables); \
		printf("\t\tint directManagedMemAccessFromHost = %d\n", args->hipChooseDeviceR0600.prop__ref.val.directManagedMemAccessFromHost); \
		printf("\t\tint maxBlocksPerMultiProcessor = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxBlocksPerMultiProcessor); \
		printf("\t\tint accessPolicyMaxWindowSize = %d\n", args->hipChooseDeviceR0600.prop__ref.val.accessPolicyMaxWindowSize); \
		printf("\t\tint reservedSharedMemPerBlock = %d\n", args->hipChooseDeviceR0600.prop__ref.val.reservedSharedMemPerBlock); \
		printf("\t\tint hostRegisterSupported = %d\n", args->hipChooseDeviceR0600.prop__ref.val.hostRegisterSupported); \
		printf("\t\tint sparseHipArraySupported = %d\n", args->hipChooseDeviceR0600.prop__ref.val.sparseHipArraySupported); \
		printf("\t\tint hostRegisterReadOnlySupported = %d\n", args->hipChooseDeviceR0600.prop__ref.val.hostRegisterReadOnlySupported); \
		printf("\t\tint timelineSemaphoreInteropSupported = %d\n", args->hipChooseDeviceR0600.prop__ref.val.timelineSemaphoreInteropSupported); \
		printf("\t\tint memoryPoolsSupported = %d\n", args->hipChooseDeviceR0600.prop__ref.val.memoryPoolsSupported); \
		printf("\t\tint gpuDirectRDMASupported = %d\n", args->hipChooseDeviceR0600.prop__ref.val.gpuDirectRDMASupported); \
		printf("\t\tunsigned int gpuDirectRDMAFlushWritesOptions = %u\n", args->hipChooseDeviceR0600.prop__ref.val.gpuDirectRDMAFlushWritesOptions); \
		printf("\t\tint gpuDirectRDMAWritesOrdering = %d\n", args->hipChooseDeviceR0600.prop__ref.val.gpuDirectRDMAWritesOrdering); \
		printf("\t\tunsigned int memoryPoolSupportedHandleTypes = %u\n", args->hipChooseDeviceR0600.prop__ref.val.memoryPoolSupportedHandleTypes); \
		printf("\t\tint deferredMappingHipArraySupported = %d\n", args->hipChooseDeviceR0600.prop__ref.val.deferredMappingHipArraySupported); \
		printf("\t\tint ipcEventSupported = %d\n", args->hipChooseDeviceR0600.prop__ref.val.ipcEventSupported); \
		printf("\t\tint clusterLaunch = %d\n", args->hipChooseDeviceR0600.prop__ref.val.clusterLaunch); \
		printf("\t\tint unifiedFunctionPointers = %d\n", args->hipChooseDeviceR0600.prop__ref.val.unifiedFunctionPointers); \
		printf("\t\tint[63] reserved = %d\n", args->hipChooseDeviceR0600.prop__ref.val.reserved[0]); \
		printf("\t\tint[32] hipReserved = %d\n", args->hipChooseDeviceR0600.prop__ref.val.hipReserved[0]); \
		printf("\t\tchar[256] gcnArchName = %s\n", args->hipChooseDeviceR0600.prop__ref.val.gcnArchName[0]); \
		printf("\t\tint maxSharedMemoryPerMultiProcessor = %d\n", args->hipChooseDeviceR0600.prop__ref.val.maxSharedMemoryPerMultiProcessor); \
		printf("\t\tint clockInstructionRate = %d\n", args->hipChooseDeviceR0600.prop__ref.val.clockInstructionRate); \
		printf("\t\thipDeviceArch_t arch = {\n"); \
		printf("\t\t\tunsigned int hasGlobalInt32Atomics = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasGlobalInt32Atomics); \
		printf("\t\t\tunsigned int hasGlobalFloatAtomicExch = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasGlobalFloatAtomicExch); \
		printf("\t\t\tunsigned int hasSharedInt32Atomics = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasSharedInt32Atomics); \
		printf("\t\t\tunsigned int hasSharedFloatAtomicExch = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasSharedFloatAtomicExch); \
		printf("\t\t\tunsigned int hasFloatAtomicAdd = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasFloatAtomicAdd); \
		printf("\t\t\tunsigned int hasGlobalInt64Atomics = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasGlobalInt64Atomics); \
		printf("\t\t\tunsigned int hasSharedInt64Atomics = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasSharedInt64Atomics); \
		printf("\t\t\tunsigned int hasDoubles = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasDoubles); \
		printf("\t\t\tunsigned int hasWarpVote = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasWarpVote); \
		printf("\t\t\tunsigned int hasWarpBallot = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasWarpBallot); \
		printf("\t\t\tunsigned int hasWarpShuffle = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasWarpShuffle); \
		printf("\t\t\tunsigned int hasFunnelShift = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasFunnelShift); \
		printf("\t\t\tunsigned int hasThreadFenceSystem = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasThreadFenceSystem); \
		printf("\t\t\tunsigned int hasSyncThreadsExt = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasSyncThreadsExt); \
		printf("\t\t\tunsigned int hasSurfaceFuncs = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasSurfaceFuncs); \
		printf("\t\t\tunsigned int has3dGrid = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.has3dGrid); \
		printf("\t\t\tunsigned int hasDynamicParallelism = %u\n", args->hipChooseDeviceR0600.prop__ref.val.arch.hasDynamicParallelism); \
		printf("\t\t}\n"); \
		printf("\t\tint cooperativeMultiDeviceUnmatchedFunc = %d\n", args->hipChooseDeviceR0600.prop__ref.val.cooperativeMultiDeviceUnmatchedFunc); \
		printf("\t\tint cooperativeMultiDeviceUnmatchedGridDim = %d\n", args->hipChooseDeviceR0600.prop__ref.val.cooperativeMultiDeviceUnmatchedGridDim); \
		printf("\t\tint cooperativeMultiDeviceUnmatchedBlockDim = %d\n", args->hipChooseDeviceR0600.prop__ref.val.cooperativeMultiDeviceUnmatchedBlockDim); \
		printf("\t\tint cooperativeMultiDeviceUnmatchedSharedMem = %d\n", args->hipChooseDeviceR0600.prop__ref.val.cooperativeMultiDeviceUnmatchedSharedMem); \
		printf("\t\tint isLargeBar = %d\n", args->hipChooseDeviceR0600.prop__ref.val.isLargeBar); \
		printf("\t\tint asicRevision = %d\n", args->hipChooseDeviceR0600.prop__ref.val.asicRevision); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	const hipExternalSemaphore_t * extSemArray (void**);
//	const hipExternalSemaphoreSignalParams * paramsArray ({
//		struct (unnamed struct at ./input/hip_runtime_api.h:1136:3) params ({
//			struct (unnamed struct at ./input/hip_runtime_api.h:1137:5) fence ({
//				unsigned long long value (unsigned long long);
//			});
//			union (unnamed union at ./input/hip_runtime_api.h:1140:5) nvSciSync ({
//				unsigned long long reserved (unsigned long long);
//			});
//			struct (unnamed struct at ./input/hip_runtime_api.h:1144:5) keyedMutex ({
//				unsigned long long key (unsigned long long);
//			});
//			unsigned int[12] reserved (unsigned int);
//		});
//		unsigned int flags (unsigned int);
//		unsigned int[16] reserved (unsigned int);
//	});
//	unsigned int numExtSems (unsigned int);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipSignalExternalSemaphoresAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipSignalExternalSemaphoresAsync.retval); \
	printf("\tconst hipExternalSemaphore_t * extSemArray = %p", args->hipSignalExternalSemaphoresAsync.extSemArray); \
	if (args->hipSignalExternalSemaphoresAsync.extSemArray != NULL) { \
		printf("-> %p", args->hipSignalExternalSemaphoresAsync.extSemArray__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tconst hipExternalSemaphoreSignalParams * paramsArray = %p", args->hipSignalExternalSemaphoresAsync.paramsArray); \
	if (args->hipSignalExternalSemaphoresAsync.paramsArray != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1136:3) params = {\n"); \
		printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1137:5) fence = {\n"); \
		printf("\t\t\t\tunsigned long long value = %llu\n", args->hipSignalExternalSemaphoresAsync.paramsArray__ref.val.params.fence.value); \
		printf("\t\t\t}\n"); \
		printf("\t\t\tunion (unnamed union at ./input/hip_runtime_api.h:1140:5) nvSciSync = {\n"); \
		printf("\t\t\t\tunsigned long long reserved = %llu\n", args->hipSignalExternalSemaphoresAsync.paramsArray__ref.val.params.nvSciSync.reserved); \
		printf("\t\t\t}\n"); \
		printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1144:5) keyedMutex = {\n"); \
		printf("\t\t\t\tunsigned long long key = %llu\n", args->hipSignalExternalSemaphoresAsync.paramsArray__ref.val.params.keyedMutex.key); \
		printf("\t\t\t}\n"); \
		printf("\t\t\tunsigned int[12] reserved = %u\n", args->hipSignalExternalSemaphoresAsync.paramsArray__ref.val.params.reserved[0]); \
		printf("\t\t}\n"); \
		printf("\t\tunsigned int flags = %u\n", args->hipSignalExternalSemaphoresAsync.paramsArray__ref.val.flags); \
		printf("\t\tunsigned int[16] reserved = %u\n", args->hipSignalExternalSemaphoresAsync.paramsArray__ref.val.reserved[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tunsigned int numExtSems = %u\n", args->hipSignalExternalSemaphoresAsync.numExtSems); \
	printf("\thipStream_t stream = %p\n", args->hipSignalExternalSemaphoresAsync.stream); \
};

//	int * canAccessPeer (int*);
//	int deviceId (int);
//	int peerDeviceId (int);
#define PROCESS_ARGS_hipDeviceCanAccessPeer(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceCanAccessPeer.retval); \
	printf("\tint * canAccessPeer = %p", args->hipDeviceCanAccessPeer.canAccessPeer); \
	if (args->hipDeviceCanAccessPeer.canAccessPeer != NULL) { \
		printf(" -> %d\n", args->hipDeviceCanAccessPeer.canAccessPeer__ref.val); \
	} else { printf("\n"); }; \
	printf("\tint deviceId = %d\n", args->hipDeviceCanAccessPeer.deviceId); \
	printf("\tint peerDeviceId = %d\n", args->hipDeviceCanAccessPeer.peerDeviceId); \
};

//	hipCtx_t * pctx (opaque*);
//	hipDevice_t dev (int);
#define PROCESS_ARGS_hipDevicePrimaryCtxRetain(args) { \
	printf("\thipError_t retval = %d\n", args->hipDevicePrimaryCtxRetain.retval); \
	printf("\thipCtx_t * pctx = %p", args->hipDevicePrimaryCtxRetain.pctx); \
	if (args->hipDevicePrimaryCtxRetain.pctx != NULL) { \
		printf(" -> %p\n", args->hipDevicePrimaryCtxRetain.pctx__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipDevice_t dev = %d\n", args->hipDevicePrimaryCtxRetain.dev); \
};

//	hipCtx_t peerCtx (opaque);
#define PROCESS_ARGS_hipCtxDisablePeerAccess(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxDisablePeerAccess.retval); \
	printf("\thipCtx_t peerCtx = %p\n", args->hipCtxDisablePeerAccess.peerCtx); \
};

//	hipStream_t stream (opaque);
//	int * priority (int*);
#define PROCESS_ARGS_hipStreamGetPriority(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamGetPriority.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamGetPriority.stream); \
	printf("\tint * priority = %p", args->hipStreamGetPriority.priority); \
	if (args->hipStreamGetPriority.priority != NULL) { \
		printf(" -> %d\n", args->hipStreamGetPriority.priority__ref.val); \
	} else { printf("\n"); }; \
};

//	hipEvent_t * event (opaque*);
#define PROCESS_ARGS_hipEventCreate(args) { \
	printf("\thipError_t retval = %d\n", args->hipEventCreate.retval); \
	printf("\thipEvent_t * event = %p", args->hipEventCreate.event); \
	if (args->hipEventCreate.event != NULL) { \
		printf(" -> %p\n", args->hipEventCreate.event__ref.val); \
	} else { printf("\n"); }; \
};


#define PROCESS_ARGS_hipGetLastError(args) { \
	printf("\thipError_t retval = %d\n", args->hipGetLastError.retval); \
\
};

//	int * major (int*);
//	int * minor (int*);
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceComputeCapability(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceComputeCapability.retval); \
	printf("\tint * major = %p", args->hipDeviceComputeCapability.major); \
	if (args->hipDeviceComputeCapability.major != NULL) { \
		printf(" -> %d\n", args->hipDeviceComputeCapability.major__ref.val); \
	} else { printf("\n"); }; \
	printf("\tint * minor = %p", args->hipDeviceComputeCapability.minor); \
	if (args->hipDeviceComputeCapability.minor != NULL) { \
		printf(" -> %d\n", args->hipDeviceComputeCapability.minor__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipDevice_t device = %d\n", args->hipDeviceComputeCapability.device); \
};

//	hipDeviceProp_tR0600 * prop ({
//		char[256] name (string);
//		hipUUID uuid ({
//			char[16] bytes (string);
//		});
//		char[8] luid (string);
//		unsigned int luidDeviceNodeMask (unsigned int);
//		int totalGlobalMem (int);
//		int sharedMemPerBlock (int);
//		int regsPerBlock (int);
//		int warpSize (int);
//		int memPitch (int);
//		int maxThreadsPerBlock (int);
//		int[3] maxThreadsDim (int);
//		int[3] maxGridSize (int);
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
//		int[2] maxTexture2D (int);
//		int[2] maxTexture2DMipmap (int);
//		int[3] maxTexture2DLinear (int);
//		int[2] maxTexture2DGather (int);
//		int[3] maxTexture3D (int);
//		int[3] maxTexture3DAlt (int);
//		int maxTextureCubemap (int);
//		int[2] maxTexture1DLayered (int);
//		int[3] maxTexture2DLayered (int);
//		int[2] maxTextureCubemapLayered (int);
//		int maxSurface1D (int);
//		int[2] maxSurface2D (int);
//		int[3] maxSurface3D (int);
//		int[2] maxSurface1DLayered (int);
//		int[3] maxSurface2DLayered (int);
//		int maxSurfaceCubemap (int);
//		int[2] maxSurfaceCubemapLayered (int);
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
//		int[63] reserved (int);
//		int[32] hipReserved (int);
//		char[256] gcnArchName (string);
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
//		int cooperativeMultiDeviceUnmatchedFunc (int);
//		int cooperativeMultiDeviceUnmatchedGridDim (int);
//		int cooperativeMultiDeviceUnmatchedBlockDim (int);
//		int cooperativeMultiDeviceUnmatchedSharedMem (int);
//		int isLargeBar (int);
//		int asicRevision (int);
//	});
//	int deviceId (int);
#define PROCESS_ARGS_hipGetDevicePropertiesR0600(args) { \
	printf("\thipError_t retval = %d\n", args->hipGetDevicePropertiesR0600.retval); \
	printf("\thipDeviceProp_tR0600 * prop = %p", args->hipGetDevicePropertiesR0600.prop); \
	if (args->hipGetDevicePropertiesR0600.prop != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tchar[256] name = %s\n", args->hipGetDevicePropertiesR0600.prop__ref.val.name[0]); \
		printf("\t\thipUUID uuid = {\n"); \
		printf("\t\t\tchar[16] bytes = %s\n", args->hipGetDevicePropertiesR0600.prop__ref.val.uuid.bytes[0]); \
		printf("\t\t}\n"); \
		printf("\t\tchar[8] luid = %s\n", args->hipGetDevicePropertiesR0600.prop__ref.val.luid[0]); \
		printf("\t\tunsigned int luidDeviceNodeMask = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.luidDeviceNodeMask); \
		printf("\t\tint totalGlobalMem = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.totalGlobalMem); \
		printf("\t\tint sharedMemPerBlock = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.sharedMemPerBlock); \
		printf("\t\tint regsPerBlock = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.regsPerBlock); \
		printf("\t\tint warpSize = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.warpSize); \
		printf("\t\tint memPitch = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.memPitch); \
		printf("\t\tint maxThreadsPerBlock = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxThreadsPerBlock); \
		printf("\t\tint[3] maxThreadsDim = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxThreadsDim[0]); \
		printf("\t\tint[3] maxGridSize = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxGridSize[0]); \
		printf("\t\tint clockRate = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.clockRate); \
		printf("\t\tint totalConstMem = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.totalConstMem); \
		printf("\t\tint major = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.major); \
		printf("\t\tint minor = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.minor); \
		printf("\t\tint textureAlignment = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.textureAlignment); \
		printf("\t\tint texturePitchAlignment = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.texturePitchAlignment); \
		printf("\t\tint deviceOverlap = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.deviceOverlap); \
		printf("\t\tint multiProcessorCount = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.multiProcessorCount); \
		printf("\t\tint kernelExecTimeoutEnabled = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.kernelExecTimeoutEnabled); \
		printf("\t\tint integrated = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.integrated); \
		printf("\t\tint canMapHostMemory = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.canMapHostMemory); \
		printf("\t\tint computeMode = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.computeMode); \
		printf("\t\tint maxTexture1D = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxTexture1D); \
		printf("\t\tint maxTexture1DMipmap = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxTexture1DMipmap); \
		printf("\t\tint maxTexture1DLinear = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxTexture1DLinear); \
		printf("\t\tint[2] maxTexture2D = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxTexture2D[0]); \
		printf("\t\tint[2] maxTexture2DMipmap = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxTexture2DMipmap[0]); \
		printf("\t\tint[3] maxTexture2DLinear = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxTexture2DLinear[0]); \
		printf("\t\tint[2] maxTexture2DGather = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxTexture2DGather[0]); \
		printf("\t\tint[3] maxTexture3D = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxTexture3D[0]); \
		printf("\t\tint[3] maxTexture3DAlt = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxTexture3DAlt[0]); \
		printf("\t\tint maxTextureCubemap = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxTextureCubemap); \
		printf("\t\tint[2] maxTexture1DLayered = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxTexture1DLayered[0]); \
		printf("\t\tint[3] maxTexture2DLayered = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxTexture2DLayered[0]); \
		printf("\t\tint[2] maxTextureCubemapLayered = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxTextureCubemapLayered[0]); \
		printf("\t\tint maxSurface1D = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxSurface1D); \
		printf("\t\tint[2] maxSurface2D = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxSurface2D[0]); \
		printf("\t\tint[3] maxSurface3D = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxSurface3D[0]); \
		printf("\t\tint[2] maxSurface1DLayered = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxSurface1DLayered[0]); \
		printf("\t\tint[3] maxSurface2DLayered = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxSurface2DLayered[0]); \
		printf("\t\tint maxSurfaceCubemap = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxSurfaceCubemap); \
		printf("\t\tint[2] maxSurfaceCubemapLayered = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxSurfaceCubemapLayered[0]); \
		printf("\t\tint surfaceAlignment = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.surfaceAlignment); \
		printf("\t\tint concurrentKernels = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.concurrentKernels); \
		printf("\t\tint ECCEnabled = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.ECCEnabled); \
		printf("\t\tint pciBusID = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.pciBusID); \
		printf("\t\tint pciDeviceID = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.pciDeviceID); \
		printf("\t\tint pciDomainID = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.pciDomainID); \
		printf("\t\tint tccDriver = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.tccDriver); \
		printf("\t\tint asyncEngineCount = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.asyncEngineCount); \
		printf("\t\tint unifiedAddressing = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.unifiedAddressing); \
		printf("\t\tint memoryClockRate = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.memoryClockRate); \
		printf("\t\tint memoryBusWidth = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.memoryBusWidth); \
		printf("\t\tint l2CacheSize = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.l2CacheSize); \
		printf("\t\tint persistingL2CacheMaxSize = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.persistingL2CacheMaxSize); \
		printf("\t\tint maxThreadsPerMultiProcessor = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxThreadsPerMultiProcessor); \
		printf("\t\tint streamPrioritiesSupported = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.streamPrioritiesSupported); \
		printf("\t\tint globalL1CacheSupported = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.globalL1CacheSupported); \
		printf("\t\tint localL1CacheSupported = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.localL1CacheSupported); \
		printf("\t\tint sharedMemPerMultiprocessor = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.sharedMemPerMultiprocessor); \
		printf("\t\tint regsPerMultiprocessor = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.regsPerMultiprocessor); \
		printf("\t\tint managedMemory = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.managedMemory); \
		printf("\t\tint isMultiGpuBoard = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.isMultiGpuBoard); \
		printf("\t\tint multiGpuBoardGroupID = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.multiGpuBoardGroupID); \
		printf("\t\tint hostNativeAtomicSupported = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.hostNativeAtomicSupported); \
		printf("\t\tint singleToDoublePrecisionPerfRatio = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.singleToDoublePrecisionPerfRatio); \
		printf("\t\tint pageableMemoryAccess = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.pageableMemoryAccess); \
		printf("\t\tint concurrentManagedAccess = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.concurrentManagedAccess); \
		printf("\t\tint computePreemptionSupported = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.computePreemptionSupported); \
		printf("\t\tint canUseHostPointerForRegisteredMem = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.canUseHostPointerForRegisteredMem); \
		printf("\t\tint cooperativeLaunch = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.cooperativeLaunch); \
		printf("\t\tint cooperativeMultiDeviceLaunch = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.cooperativeMultiDeviceLaunch); \
		printf("\t\tint sharedMemPerBlockOptin = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.sharedMemPerBlockOptin); \
		printf("\t\tint pageableMemoryAccessUsesHostPageTables = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.pageableMemoryAccessUsesHostPageTables); \
		printf("\t\tint directManagedMemAccessFromHost = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.directManagedMemAccessFromHost); \
		printf("\t\tint maxBlocksPerMultiProcessor = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxBlocksPerMultiProcessor); \
		printf("\t\tint accessPolicyMaxWindowSize = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.accessPolicyMaxWindowSize); \
		printf("\t\tint reservedSharedMemPerBlock = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.reservedSharedMemPerBlock); \
		printf("\t\tint hostRegisterSupported = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.hostRegisterSupported); \
		printf("\t\tint sparseHipArraySupported = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.sparseHipArraySupported); \
		printf("\t\tint hostRegisterReadOnlySupported = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.hostRegisterReadOnlySupported); \
		printf("\t\tint timelineSemaphoreInteropSupported = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.timelineSemaphoreInteropSupported); \
		printf("\t\tint memoryPoolsSupported = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.memoryPoolsSupported); \
		printf("\t\tint gpuDirectRDMASupported = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.gpuDirectRDMASupported); \
		printf("\t\tunsigned int gpuDirectRDMAFlushWritesOptions = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.gpuDirectRDMAFlushWritesOptions); \
		printf("\t\tint gpuDirectRDMAWritesOrdering = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.gpuDirectRDMAWritesOrdering); \
		printf("\t\tunsigned int memoryPoolSupportedHandleTypes = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.memoryPoolSupportedHandleTypes); \
		printf("\t\tint deferredMappingHipArraySupported = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.deferredMappingHipArraySupported); \
		printf("\t\tint ipcEventSupported = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.ipcEventSupported); \
		printf("\t\tint clusterLaunch = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.clusterLaunch); \
		printf("\t\tint unifiedFunctionPointers = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.unifiedFunctionPointers); \
		printf("\t\tint[63] reserved = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.reserved[0]); \
		printf("\t\tint[32] hipReserved = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.hipReserved[0]); \
		printf("\t\tchar[256] gcnArchName = %s\n", args->hipGetDevicePropertiesR0600.prop__ref.val.gcnArchName[0]); \
		printf("\t\tint maxSharedMemoryPerMultiProcessor = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.maxSharedMemoryPerMultiProcessor); \
		printf("\t\tint clockInstructionRate = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.clockInstructionRate); \
		printf("\t\thipDeviceArch_t arch = {\n"); \
		printf("\t\t\tunsigned int hasGlobalInt32Atomics = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasGlobalInt32Atomics); \
		printf("\t\t\tunsigned int hasGlobalFloatAtomicExch = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasGlobalFloatAtomicExch); \
		printf("\t\t\tunsigned int hasSharedInt32Atomics = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasSharedInt32Atomics); \
		printf("\t\t\tunsigned int hasSharedFloatAtomicExch = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasSharedFloatAtomicExch); \
		printf("\t\t\tunsigned int hasFloatAtomicAdd = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasFloatAtomicAdd); \
		printf("\t\t\tunsigned int hasGlobalInt64Atomics = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasGlobalInt64Atomics); \
		printf("\t\t\tunsigned int hasSharedInt64Atomics = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasSharedInt64Atomics); \
		printf("\t\t\tunsigned int hasDoubles = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasDoubles); \
		printf("\t\t\tunsigned int hasWarpVote = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasWarpVote); \
		printf("\t\t\tunsigned int hasWarpBallot = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasWarpBallot); \
		printf("\t\t\tunsigned int hasWarpShuffle = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasWarpShuffle); \
		printf("\t\t\tunsigned int hasFunnelShift = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasFunnelShift); \
		printf("\t\t\tunsigned int hasThreadFenceSystem = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasThreadFenceSystem); \
		printf("\t\t\tunsigned int hasSyncThreadsExt = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasSyncThreadsExt); \
		printf("\t\t\tunsigned int hasSurfaceFuncs = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasSurfaceFuncs); \
		printf("\t\t\tunsigned int has3dGrid = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.has3dGrid); \
		printf("\t\t\tunsigned int hasDynamicParallelism = %u\n", args->hipGetDevicePropertiesR0600.prop__ref.val.arch.hasDynamicParallelism); \
		printf("\t\t}\n"); \
		printf("\t\tint cooperativeMultiDeviceUnmatchedFunc = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.cooperativeMultiDeviceUnmatchedFunc); \
		printf("\t\tint cooperativeMultiDeviceUnmatchedGridDim = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.cooperativeMultiDeviceUnmatchedGridDim); \
		printf("\t\tint cooperativeMultiDeviceUnmatchedBlockDim = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.cooperativeMultiDeviceUnmatchedBlockDim); \
		printf("\t\tint cooperativeMultiDeviceUnmatchedSharedMem = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.cooperativeMultiDeviceUnmatchedSharedMem); \
		printf("\t\tint isLargeBar = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.isLargeBar); \
		printf("\t\tint asicRevision = %d\n", args->hipGetDevicePropertiesR0600.prop__ref.val.asicRevision); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tint deviceId = %d\n", args->hipGetDevicePropertiesR0600.deviceId); \
};

//	int * gridSize (int*);
//	int * blockSize (int*);
//	const void * f (void*);
//	size_t dynSharedMemPerBlk (unsigned long);
//	int blockSizeLimit (int);
#define PROCESS_ARGS_hipOccupancyMaxPotentialBlockSize(args) { \
	printf("\thipError_t retval = %d\n", args->hipOccupancyMaxPotentialBlockSize.retval); \
	printf("\tint * gridSize = %p", args->hipOccupancyMaxPotentialBlockSize.gridSize); \
	if (args->hipOccupancyMaxPotentialBlockSize.gridSize != NULL) { \
		printf(" -> %d\n", args->hipOccupancyMaxPotentialBlockSize.gridSize__ref.val); \
	} else { printf("\n"); }; \
	printf("\tint * blockSize = %p", args->hipOccupancyMaxPotentialBlockSize.blockSize); \
	if (args->hipOccupancyMaxPotentialBlockSize.blockSize != NULL) { \
		printf(" -> %d\n", args->hipOccupancyMaxPotentialBlockSize.blockSize__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst void * f = %p", args->hipOccupancyMaxPotentialBlockSize.f); \
	printf("\n"); \
	printf("\tsize_t dynSharedMemPerBlk = %lu\n", args->hipOccupancyMaxPotentialBlockSize.dynSharedMemPerBlk); \
	printf("\tint blockSizeLimit = %d\n", args->hipOccupancyMaxPotentialBlockSize.blockSizeLimit); \
};

//	size_t * offset (unsigned long*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipGetTextureAlignmentOffset(args) { \
	printf("\thipError_t retval = %d\n", args->hipGetTextureAlignmentOffset.retval); \
	printf("\tsize_t * offset = %p", args->hipGetTextureAlignmentOffset.offset); \
	if (args->hipGetTextureAlignmentOffset.offset != NULL) { \
		printf(" -> %lu\n", args->hipGetTextureAlignmentOffset.offset__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	void ** devPtr (void**);
//	hipIpcMemHandle_t handle ({
//		char[64] reserved (string);
//	});
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipIpcOpenMemHandle(args) { \
	printf("\thipError_t retval = %d\n", args->hipIpcOpenMemHandle.retval); \
	printf("\tvoid ** devPtr = %p", args->hipIpcOpenMemHandle.devPtr); \
	if (args->hipIpcOpenMemHandle.devPtr != NULL) { \
		printf("-> %p", args->hipIpcOpenMemHandle.devPtr__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\thipIpcMemHandle_t handle = {\n"); \
	printf("\t\tchar[64] reserved = %s\n", args->hipIpcOpenMemHandle.handle.reserved[0]); \
	printf("\t}\n"); \
	printf("\tunsigned int flags = %u\n", args->hipIpcOpenMemHandle.flags); \
};

//	hipGraphNode_t * pNode (opaque*);
//	hipGraphNode_t originalNode (opaque);
//	hipGraph_t clonedGraph (opaque);
#define PROCESS_ARGS_hipGraphNodeFindInClone(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphNodeFindInClone.retval); \
	printf("\thipGraphNode_t * pNode = %p", args->hipGraphNodeFindInClone.pNode); \
	if (args->hipGraphNodeFindInClone.pNode != NULL) { \
		printf(" -> %p\n", args->hipGraphNodeFindInClone.pNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraphNode_t originalNode = %p\n", args->hipGraphNodeFindInClone.originalNode); \
	printf("\thipGraph_t clonedGraph = %p\n", args->hipGraphNodeFindInClone.clonedGraph); \
};

//	hipDevice_t dev (int);
#define PROCESS_ARGS_hipDevicePrimaryCtxRelease(args) { \
	printf("\thipError_t retval = %d\n", args->hipDevicePrimaryCtxRelease.retval); \
	printf("\thipDevice_t dev = %d\n", args->hipDevicePrimaryCtxRelease.dev); \
};

//	hipCtx_t ctx (opaque);
#define PROCESS_ARGS_hipCtxSetCurrent(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxSetCurrent.retval); \
	printf("\thipCtx_t ctx = %p\n", args->hipCtxSetCurrent.ctx); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
//	void * dst (void*);
//	const void * symbol (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParamsFromSymbol(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.retval); \
	printf("\thipGraphExec_t hGraphExec = %p\n", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.hGraphExec); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.node); \
	printf("\tvoid * dst = %p", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.dst); \
	printf("\n"); \
	printf("\tconst void * symbol = %p", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.symbol); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.count); \
	printf("\tsize_t offset = %lu\n", args->hipGraphExecMemcpyNodeSetParamsFromSymbol.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	hipFuncCache_t cacheConfig (enum);
#define PROCESS_ARGS_hipCtxSetCacheConfig(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxSetCacheConfig.retval); \
	printf("\thipFuncCache_t cacheConfig = %d\n", args->hipCtxSetCacheConfig.cacheConfig); \
};

//	hipArrayMapInfo * mapInfoList ({
//		int resourceType (int);
//		union (unnamed union at ./input/hip_runtime_api.h:1465:6) resource ({
//			int mipmap (int);
//			int array (int);
//		});
//		hipArraySparseSubresourceType subresourceType (enum);
//		union (unnamed union at ./input/hip_runtime_api.h:1470:6) subresource ({
//			struct (unnamed struct at ./input/hip_runtime_api.h:1471:10) sparseLevel ({
//				unsigned int level (unsigned int);
//				unsigned int layer (unsigned int);
//				unsigned int offsetX (unsigned int);
//				unsigned int offsetY (unsigned int);
//				unsigned int offsetZ (unsigned int);
//				unsigned int extentWidth (unsigned int);
//				unsigned int extentHeight (unsigned int);
//				unsigned int extentDepth (unsigned int);
//			});
//			struct (unnamed struct at ./input/hip_runtime_api.h:1481:10) miptail ({
//				unsigned int layer (unsigned int);
//				unsigned long long offset (unsigned long long);
//				unsigned long long size (unsigned long long);
//			});
//		});
//		hipMemOperationType memOperationType (enum);
//		hipMemHandleType memHandleType (enum);
//		union (unnamed union at ./input/hip_runtime_api.h:1489:6) memHandle ({
//			hipMemGenericAllocationHandle_t memHandle (opaque);
//		});
//		unsigned long long offset (unsigned long long);
//		unsigned int deviceBitMask (unsigned int);
//		unsigned int flags (unsigned int);
//		unsigned int[2] reserved (unsigned int);
//	});
//	unsigned int count (unsigned int);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemMapArrayAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemMapArrayAsync.retval); \
	printf("\thipArrayMapInfo * mapInfoList = %p", args->hipMemMapArrayAsync.mapInfoList); \
	if (args->hipMemMapArrayAsync.mapInfoList != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tint resourceType = %d\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.resourceType); \
		printf("\t\tunion (unnamed union at ./input/hip_runtime_api.h:1465:6) resource = {\n"); \
		printf("\t\t\tint mipmap = %d\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.resource.mipmap); \
		printf("\t\t\tint array = %d\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.resource.array); \
		printf("\t\t}\n"); \
		printf("\t\thipArraySparseSubresourceType subresourceType = %d\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.subresourceType); \
		printf("\t\tunion (unnamed union at ./input/hip_runtime_api.h:1470:6) subresource = {\n"); \
		printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1471:10) sparseLevel = {\n"); \
		printf("\t\t\t\tunsigned int level = %u\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.subresource.sparseLevel.level); \
		printf("\t\t\t\tunsigned int layer = %u\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.subresource.sparseLevel.layer); \
		printf("\t\t\t\tunsigned int offsetX = %u\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.subresource.sparseLevel.offsetX); \
		printf("\t\t\t\tunsigned int offsetY = %u\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.subresource.sparseLevel.offsetY); \
		printf("\t\t\t\tunsigned int offsetZ = %u\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.subresource.sparseLevel.offsetZ); \
		printf("\t\t\t\tunsigned int extentWidth = %u\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.subresource.sparseLevel.extentWidth); \
		printf("\t\t\t\tunsigned int extentHeight = %u\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.subresource.sparseLevel.extentHeight); \
		printf("\t\t\t\tunsigned int extentDepth = %u\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.subresource.sparseLevel.extentDepth); \
		printf("\t\t\t}\n"); \
		printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1481:10) miptail = {\n"); \
		printf("\t\t\t\tunsigned int layer = %u\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.subresource.miptail.layer); \
		printf("\t\t\t\tunsigned long long offset = %llu\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.subresource.miptail.offset); \
		printf("\t\t\t\tunsigned long long size = %llu\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.subresource.miptail.size); \
		printf("\t\t\t}\n"); \
		printf("\t\t}\n"); \
		printf("\t\thipMemOperationType memOperationType = %d\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.memOperationType); \
		printf("\t\thipMemHandleType memHandleType = %d\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.memHandleType); \
		printf("\t\tunion (unnamed union at ./input/hip_runtime_api.h:1489:6) memHandle = {\n"); \
		printf("\t\t\thipMemGenericAllocationHandle_t memHandle = %p\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.memHandle.memHandle); \
		printf("\t\t}\n"); \
		printf("\t\tunsigned long long offset = %llu\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.offset); \
		printf("\t\tunsigned int deviceBitMask = %u\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.deviceBitMask); \
		printf("\t\tunsigned int flags = %u\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.flags); \
		printf("\t\tunsigned int[2] reserved = %u\n", args->hipMemMapArrayAsync.mapInfoList__ref.val.reserved[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tunsigned int count = %u\n", args->hipMemMapArrayAsync.count); \
	printf("\thipStream_t stream = %p\n", args->hipMemMapArrayAsync.stream); \
};

//	hipExternalMemory_t * extMem_out (void**);
//	const hipExternalMemoryHandleDesc * memHandleDesc ({
//		hipExternalMemoryHandleType type (enum);
//		union (unnamed union at ./input/hip_runtime_api.h:1083:3) handle ({
//			int fd (int);
//			struct (unnamed struct at ./input/hip_runtime_api.h:1085:5) win32 ({
//			});
//		});
//		unsigned long long size (unsigned long long);
//		unsigned int flags (unsigned int);
//		unsigned int[16] reserved (unsigned int);
//	});
#define PROCESS_ARGS_hipImportExternalMemory(args) { \
	printf("\thipError_t retval = %d\n", args->hipImportExternalMemory.retval); \
	printf("\thipExternalMemory_t * extMem_out = %p", args->hipImportExternalMemory.extMem_out); \
	if (args->hipImportExternalMemory.extMem_out != NULL) { \
		printf("-> %p", args->hipImportExternalMemory.extMem_out__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tconst hipExternalMemoryHandleDesc * memHandleDesc = %p", args->hipImportExternalMemory.memHandleDesc); \
	if (args->hipImportExternalMemory.memHandleDesc != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipExternalMemoryHandleType type = %d\n", args->hipImportExternalMemory.memHandleDesc__ref.val.type); \
		printf("\t\tunion (unnamed union at ./input/hip_runtime_api.h:1083:3) handle = {\n"); \
		printf("\t\t\tint fd = %d\n", args->hipImportExternalMemory.memHandleDesc__ref.val.handle.fd); \
		printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1085:5) win32 = {\n"); \
		printf("\t\t\t}\n"); \
		printf("\t\t}\n"); \
		printf("\t\tunsigned long long size = %llu\n", args->hipImportExternalMemory.memHandleDesc__ref.val.size); \
		printf("\t\tunsigned int flags = %u\n", args->hipImportExternalMemory.memHandleDesc__ref.val.flags); \
		printf("\t\tunsigned int[16] reserved = %u\n", args->hipImportExternalMemory.memHandleDesc__ref.val.reserved[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t hNode (opaque);
//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipGraphExecEventWaitNodeSetEvent(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExecEventWaitNodeSetEvent.retval); \
	printf("\thipGraphExec_t hGraphExec = %p\n", args->hipGraphExecEventWaitNodeSetEvent.hGraphExec); \
	printf("\thipGraphNode_t hNode = %p\n", args->hipGraphExecEventWaitNodeSetEvent.hNode); \
	printf("\thipEvent_t event = %p\n", args->hipGraphExecEventWaitNodeSetEvent.event); \
};

//	hipStream_t stream (opaque);
//	hipStreamCaptureMode mode (enum);
#define PROCESS_ARGS_hipStreamBeginCapture(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamBeginCapture.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamBeginCapture.stream); \
	printf("\thipStreamCaptureMode mode = %d\n", args->hipStreamBeginCapture.mode); \
};

//	hipIpcMemHandle_t * handle ({
//		char[64] reserved (string);
//	});
//	void * devPtr (void*);
#define PROCESS_ARGS_hipIpcGetMemHandle(args) { \
	printf("\thipError_t retval = %d\n", args->hipIpcGetMemHandle.retval); \
	printf("\thipIpcMemHandle_t * handle = %p", args->hipIpcGetMemHandle.handle); \
	if (args->hipIpcGetMemHandle.handle != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tchar[64] reserved = %s\n", args->hipIpcGetMemHandle.handle__ref.val.reserved[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tvoid * devPtr = %p", args->hipIpcGetMemHandle.devPtr); \
	printf("\n"); \
};

//	const hipExternalSemaphore_t * extSemArray (void**);
//	const hipExternalSemaphoreWaitParams * paramsArray ({
//		struct (unnamed struct at ./input/hip_runtime_api.h:1156:3) params ({
//			struct (unnamed struct at ./input/hip_runtime_api.h:1157:5) fence ({
//				unsigned long long value (unsigned long long);
//			});
//			union (unnamed union at ./input/hip_runtime_api.h:1160:5) nvSciSync ({
//				unsigned long long reserved (unsigned long long);
//			});
//			struct (unnamed struct at ./input/hip_runtime_api.h:1164:5) keyedMutex ({
//				unsigned long long key (unsigned long long);
//				unsigned int timeoutMs (unsigned int);
//			});
//			unsigned int[10] reserved (unsigned int);
//		});
//		unsigned int flags (unsigned int);
//		unsigned int[16] reserved (unsigned int);
//	});
//	unsigned int numExtSems (unsigned int);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipWaitExternalSemaphoresAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipWaitExternalSemaphoresAsync.retval); \
	printf("\tconst hipExternalSemaphore_t * extSemArray = %p", args->hipWaitExternalSemaphoresAsync.extSemArray); \
	if (args->hipWaitExternalSemaphoresAsync.extSemArray != NULL) { \
		printf("-> %p", args->hipWaitExternalSemaphoresAsync.extSemArray__ref.ptr1); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tconst hipExternalSemaphoreWaitParams * paramsArray = %p", args->hipWaitExternalSemaphoresAsync.paramsArray); \
	if (args->hipWaitExternalSemaphoresAsync.paramsArray != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1156:3) params = {\n"); \
		printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1157:5) fence = {\n"); \
		printf("\t\t\t\tunsigned long long value = %llu\n", args->hipWaitExternalSemaphoresAsync.paramsArray__ref.val.params.fence.value); \
		printf("\t\t\t}\n"); \
		printf("\t\t\tunion (unnamed union at ./input/hip_runtime_api.h:1160:5) nvSciSync = {\n"); \
		printf("\t\t\t\tunsigned long long reserved = %llu\n", args->hipWaitExternalSemaphoresAsync.paramsArray__ref.val.params.nvSciSync.reserved); \
		printf("\t\t\t}\n"); \
		printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1164:5) keyedMutex = {\n"); \
		printf("\t\t\t\tunsigned long long key = %llu\n", args->hipWaitExternalSemaphoresAsync.paramsArray__ref.val.params.keyedMutex.key); \
		printf("\t\t\t\tunsigned int timeoutMs = %u\n", args->hipWaitExternalSemaphoresAsync.paramsArray__ref.val.params.keyedMutex.timeoutMs); \
		printf("\t\t\t}\n"); \
		printf("\t\t\tunsigned int[10] reserved = %u\n", args->hipWaitExternalSemaphoresAsync.paramsArray__ref.val.params.reserved[0]); \
		printf("\t\t}\n"); \
		printf("\t\tunsigned int flags = %u\n", args->hipWaitExternalSemaphoresAsync.paramsArray__ref.val.flags); \
		printf("\t\tunsigned int[16] reserved = %u\n", args->hipWaitExternalSemaphoresAsync.paramsArray__ref.val.reserved[0]); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tunsigned int numExtSems = %u\n", args->hipWaitExternalSemaphoresAsync.numExtSems); \
	printf("\thipStream_t stream = %p\n", args->hipWaitExternalSemaphoresAsync.stream); \
};

//	enum hipTextureFilterMode * pfm (enum*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipmapFilterMode(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefGetMipmapFilterMode.retval); \
	printf("\tenum hipTextureFilterMode * pfm = %p", args->hipTexRefGetMipmapFilterMode.pfm); \
	if (args->hipTexRefGetMipmapFilterMode.pfm != NULL) { \
		printf(" -> %d\n", args->hipTexRefGetMipmapFilterMode.pfm__ref.val); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	hipMemAccessFlags * flags (enum*);
//	hipMemPool_t mem_pool (opaque);
//	hipMemLocation * location ({
//		hipMemLocationType type (enum);
//		int id (int);
//	});
#define PROCESS_ARGS_hipMemPoolGetAccess(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemPoolGetAccess.retval); \
	printf("\thipMemAccessFlags * flags = %p", args->hipMemPoolGetAccess.flags); \
	if (args->hipMemPoolGetAccess.flags != NULL) { \
		printf(" -> %d\n", args->hipMemPoolGetAccess.flags__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipMemPool_t mem_pool = %p\n", args->hipMemPoolGetAccess.mem_pool); \
	printf("\thipMemLocation * location = %p", args->hipMemPoolGetAccess.location); \
	if (args->hipMemPoolGetAccess.location != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemLocationType type = %d\n", args->hipMemPoolGetAccess.location__ref.val.type); \
		printf("\t\tint id = %d\n", args->hipMemPoolGetAccess.location__ref.val.id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraphNode_t * phGraphNode (opaque*);
//	hipGraph_t hGraph (opaque);
//	const hipGraphNode_t * dependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	const HIP_MEMSET_NODE_PARAMS * memsetParams ({
//		int dst (int);
//		size_t pitch (unsigned long);
//		unsigned int value (unsigned int);
//		unsigned int elementSize (unsigned int);
//		size_t width (unsigned long);
//		size_t height (unsigned long);
//	});
//	hipCtx_t ctx (opaque);
#define PROCESS_ARGS_hipDrvGraphAddMemsetNode(args) { \
	printf("\thipError_t retval = %d\n", args->hipDrvGraphAddMemsetNode.retval); \
	printf("\thipGraphNode_t * phGraphNode = %p", args->hipDrvGraphAddMemsetNode.phGraphNode); \
	if (args->hipDrvGraphAddMemsetNode.phGraphNode != NULL) { \
		printf(" -> %p\n", args->hipDrvGraphAddMemsetNode.phGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t hGraph = %p\n", args->hipDrvGraphAddMemsetNode.hGraph); \
	printf("\tconst hipGraphNode_t * dependencies = %p", args->hipDrvGraphAddMemsetNode.dependencies); \
	if (args->hipDrvGraphAddMemsetNode.dependencies != NULL) { \
		printf(" -> %p\n", args->hipDrvGraphAddMemsetNode.dependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipDrvGraphAddMemsetNode.numDependencies); \
	printf("\tconst HIP_MEMSET_NODE_PARAMS * memsetParams = %p", args->hipDrvGraphAddMemsetNode.memsetParams); \
	if (args->hipDrvGraphAddMemsetNode.memsetParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tint dst = %d\n", args->hipDrvGraphAddMemsetNode.memsetParams__ref.val.dst); \
		printf("\t\tsize_t pitch = %lu\n", args->hipDrvGraphAddMemsetNode.memsetParams__ref.val.pitch); \
		printf("\t\tunsigned int value = %u\n", args->hipDrvGraphAddMemsetNode.memsetParams__ref.val.value); \
		printf("\t\tunsigned int elementSize = %u\n", args->hipDrvGraphAddMemsetNode.memsetParams__ref.val.elementSize); \
		printf("\t\tsize_t width = %lu\n", args->hipDrvGraphAddMemsetNode.memsetParams__ref.val.width); \
		printf("\t\tsize_t height = %lu\n", args->hipDrvGraphAddMemsetNode.memsetParams__ref.val.height); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thipCtx_t ctx = %p\n", args->hipDrvGraphAddMemsetNode.ctx); \
};

//	hipPitchedPtr pitchedDevPtr (unknown);
//	int value (int);
//	hipExtent extent (unknown);
#define PROCESS_ARGS_hipMemset3D(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemset3D.retval); \
	printf("\thipPitchedPtr pitchedDevPtr = N/A, try to update csv files\n"); \
	printf("\tint value = %d\n", args->hipMemset3D.value); \
	printf("\thipExtent extent = N/A, try to update csv files\n"); \
};

//	const HIP_MEMCPY3D * pCopy (unknown);
#define PROCESS_ARGS_hipDrvMemcpy3D(args) { \
	printf("\thipError_t retval = %d\n", args->hipDrvMemcpy3D.retval); \
	printf("\tconst HIP_MEMCPY3D * pCopy = N/A, try to update csv files\n"); \
};

//	void * dst (void*);
//	size_t dpitch (unsigned long);
//	hipArray_const_t src (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpy2DFromArrayAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpy2DFromArrayAsync.retval); \
	printf("\tvoid * dst = %p", args->hipMemcpy2DFromArrayAsync.dst); \
	printf("\n"); \
	printf("\tsize_t dpitch = %lu\n", args->hipMemcpy2DFromArrayAsync.dpitch); \
	printf("\thipArray_const_t src = N/A, try to update csv files\n"); \
	printf("\tsize_t wOffset = %lu\n", args->hipMemcpy2DFromArrayAsync.wOffset); \
	printf("\tsize_t hOffset = %lu\n", args->hipMemcpy2DFromArrayAsync.hOffset); \
	printf("\tsize_t width = %lu\n", args->hipMemcpy2DFromArrayAsync.width); \
	printf("\tsize_t height = %lu\n", args->hipMemcpy2DFromArrayAsync.height); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = %p\n", args->hipMemcpy2DFromArrayAsync.stream); \
};

//	hipLaunchParams * launchParamsList ({
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
//		int sharedMem (int);
//		hipStream_t stream (opaque);
//	});
//	int numDevices (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipExtLaunchMultiKernelMultiDevice(args) { \
	printf("\thipError_t retval = %d\n", args->hipExtLaunchMultiKernelMultiDevice.retval); \
	printf("\thipLaunchParams * launchParamsList = %p", args->hipExtLaunchMultiKernelMultiDevice.launchParamsList); \
	if (args->hipExtLaunchMultiKernelMultiDevice.launchParamsList != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tdim3 gridDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hipExtLaunchMultiKernelMultiDevice.launchParamsList__ref.val.gridDim.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hipExtLaunchMultiKernelMultiDevice.launchParamsList__ref.val.gridDim.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hipExtLaunchMultiKernelMultiDevice.launchParamsList__ref.val.gridDim.z); \
		printf("\t\t}\n"); \
		printf("\t\tdim3 blockDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hipExtLaunchMultiKernelMultiDevice.launchParamsList__ref.val.blockDim.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hipExtLaunchMultiKernelMultiDevice.launchParamsList__ref.val.blockDim.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hipExtLaunchMultiKernelMultiDevice.launchParamsList__ref.val.blockDim.z); \
		printf("\t\t}\n"); \
		printf("\t\tint sharedMem = %d\n", args->hipExtLaunchMultiKernelMultiDevice.launchParamsList__ref.val.sharedMem); \
		printf("\t\thipStream_t stream = %p\n", args->hipExtLaunchMultiKernelMultiDevice.launchParamsList__ref.val.stream); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tint numDevices = %d\n", args->hipExtLaunchMultiKernelMultiDevice.numDevices); \
	printf("\tunsigned int flags = %u\n", args->hipExtLaunchMultiKernelMultiDevice.flags); \
};

//	hipStream_t stream (opaque);
//	void * ptr (void*);
//	uint64_t value (unsigned long);
//	unsigned int flags (unsigned int);
//	uint64_t mask (unsigned long);
#define PROCESS_ARGS_hipStreamWaitValue64(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamWaitValue64.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamWaitValue64.stream); \
	printf("\tvoid * ptr = %p", args->hipStreamWaitValue64.ptr); \
	printf("\n"); \
	printf("\tuint64_t value = %lu\n", args->hipStreamWaitValue64.value); \
	printf("\tunsigned int flags = %u\n", args->hipStreamWaitValue64.flags); \
	printf("\tuint64_t mask = %lu\n", args->hipStreamWaitValue64.mask); \
};

//	textureReference** texRef (unknown);
//	hipModule_t hmod (opaque);
//	const char * name (string*);
#define PROCESS_ARGS_hipModuleGetTexRef(args) { \
	printf("\thipError_t retval = %d\n", args->hipModuleGetTexRef.retval); \
	printf("\ttextureReference** texRef = N/A, try to update csv files\n"); \
	printf("\thipModule_t hmod = %p\n", args->hipModuleGetTexRef.hmod); \
	printf("\tconst char * name = %p", args->hipModuleGetTexRef.name); \
	if (args->hipModuleGetTexRef.name != NULL) { \
		printf(" -> %s\n", args->hipModuleGetTexRef.name__ref.val); \
	} else { printf("\n"); }; \
};

//	hipDeviceptr_t dst (void*);
//	hipDeviceptr_t src (void*);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipMemcpyDtoDAsync(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyDtoDAsync.retval); \
	printf("\thipDeviceptr_t dst = %p", args->hipMemcpyDtoDAsync.dst); \
	printf("\n"); \
	printf("\thipDeviceptr_t src = %p", args->hipMemcpyDtoDAsync.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyDtoDAsync.sizeBytes); \
	printf("\thipStream_t stream = %p\n", args->hipMemcpyDtoDAsync.stream); \
};

//	HIP_RESOURCE_VIEW_DESC * pResViewDesc (unknown);
//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectGetResourceViewDesc(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexObjectGetResourceViewDesc.retval); \
	printf("\tHIP_RESOURCE_VIEW_DESC * pResViewDesc = N/A, try to update csv files\n"); \
	printf("\thipTextureObject_t texObject = N/A, try to update csv files\n"); \
};

//	hipStream_t stream (opaque);
//	hipStreamCallback_t callback (function);
//	void * userData (void*);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamAddCallback(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamAddCallback.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamAddCallback.stream); \
	printf("\thipStreamCallback_t callback = %p\n", args->hipStreamAddCallback.callback); \
	printf("\tvoid * userData = %p", args->hipStreamAddCallback.userData); \
	printf("\n"); \
	printf("\tunsigned int flags = %u\n", args->hipStreamAddCallback.flags); \
};

//	textureReference* texRef (unknown);
//	hipArray_Format fmt (unknown);
//	int NumPackedComponents (int);
#define PROCESS_ARGS_hipTexRefSetFormat(args) { \
	printf("\thipError_t retval = %d\n", args->hipTexRefSetFormat.retval); \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\thipArray_Format fmt = N/A, try to update csv files\n"); \
	printf("\tint NumPackedComponents = %d\n", args->hipTexRefSetFormat.NumPackedComponents); \
};

//	struct hipFuncAttributes * attr ({
//		int binaryVersion (int);
//		int cacheModeCA (int);
//		size_t constSizeBytes (unsigned long);
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
	printf("\thipError_t retval = %d\n", args->hipFuncGetAttributes.retval); \
	printf("\tstruct hipFuncAttributes * attr = %p", args->hipFuncGetAttributes.attr); \
	if (args->hipFuncGetAttributes.attr != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tint binaryVersion = %d\n", args->hipFuncGetAttributes.attr__ref.val.binaryVersion); \
		printf("\t\tint cacheModeCA = %d\n", args->hipFuncGetAttributes.attr__ref.val.cacheModeCA); \
		printf("\t\tsize_t constSizeBytes = %lu\n", args->hipFuncGetAttributes.attr__ref.val.constSizeBytes); \
		printf("\t\tint localSizeBytes = %d\n", args->hipFuncGetAttributes.attr__ref.val.localSizeBytes); \
		printf("\t\tint maxDynamicSharedSizeBytes = %d\n", args->hipFuncGetAttributes.attr__ref.val.maxDynamicSharedSizeBytes); \
		printf("\t\tint maxThreadsPerBlock = %d\n", args->hipFuncGetAttributes.attr__ref.val.maxThreadsPerBlock); \
		printf("\t\tint numRegs = %d\n", args->hipFuncGetAttributes.attr__ref.val.numRegs); \
		printf("\t\tint preferredShmemCarveout = %d\n", args->hipFuncGetAttributes.attr__ref.val.preferredShmemCarveout); \
		printf("\t\tint ptxVersion = %d\n", args->hipFuncGetAttributes.attr__ref.val.ptxVersion); \
		printf("\t\tint sharedSizeBytes = %d\n", args->hipFuncGetAttributes.attr__ref.val.sharedSizeBytes); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tconst void * func = %p", args->hipFuncGetAttributes.func); \
	printf("\n"); \
};

//	hipStream_t * stream (opaque*);
//	unsigned int flags (unsigned int);
//	int priority (int);
#define PROCESS_ARGS_hipStreamCreateWithPriority(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamCreateWithPriority.retval); \
	printf("\thipStream_t * stream = %p", args->hipStreamCreateWithPriority.stream); \
	if (args->hipStreamCreateWithPriority.stream != NULL) { \
		printf(" -> %p\n", args->hipStreamCreateWithPriority.stream__ref.val); \
	} else { printf("\n"); }; \
	printf("\tunsigned int flags = %u\n", args->hipStreamCreateWithPriority.flags); \
	printf("\tint priority = %d\n", args->hipStreamCreateWithPriority.priority); \
};

//	const textureReference** texref (unknown);
//	const void * symbol (void*);
#define PROCESS_ARGS_hipGetTextureReference(args) { \
	printf("\thipError_t retval = %d\n", args->hipGetTextureReference.retval); \
	printf("\tconst textureReference** texref = N/A, try to update csv files\n"); \
	printf("\tconst void * symbol = %p", args->hipGetTextureReference.symbol); \
	printf("\n"); \
};

//	hipGraphNode_t * pGraphNode (opaque*);
//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * pDependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	const hipKernelNodeParams * pNodeParams ({
//		dim3 blockDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		dim3 gridDim ({
//			uint32_t x (unsigned int);
//			uint32_t y (unsigned int);
//			uint32_t z (unsigned int);
//		});
//		unsigned int sharedMemBytes (unsigned int);
//	});
#define PROCESS_ARGS_hipGraphAddKernelNode(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddKernelNode.retval); \
	printf("\thipGraphNode_t * pGraphNode = %p", args->hipGraphAddKernelNode.pGraphNode); \
	if (args->hipGraphAddKernelNode.pGraphNode != NULL) { \
		printf(" -> %p\n", args->hipGraphAddKernelNode.pGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddKernelNode.graph); \
	printf("\tconst hipGraphNode_t * pDependencies = %p", args->hipGraphAddKernelNode.pDependencies); \
	if (args->hipGraphAddKernelNode.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphAddKernelNode.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddKernelNode.numDependencies); \
	printf("\tconst hipKernelNodeParams * pNodeParams = %p", args->hipGraphAddKernelNode.pNodeParams); \
	if (args->hipGraphAddKernelNode.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tdim3 blockDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hipGraphAddKernelNode.pNodeParams__ref.val.blockDim.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hipGraphAddKernelNode.pNodeParams__ref.val.blockDim.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hipGraphAddKernelNode.pNodeParams__ref.val.blockDim.z); \
		printf("\t\t}\n"); \
		printf("\t\tdim3 gridDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", args->hipGraphAddKernelNode.pNodeParams__ref.val.gridDim.x); \
		printf("\t\t\tuint32_t y = %u\n", args->hipGraphAddKernelNode.pNodeParams__ref.val.gridDim.y); \
		printf("\t\t\tuint32_t z = %u\n", args->hipGraphAddKernelNode.pNodeParams__ref.val.gridDim.z); \
		printf("\t\t}\n"); \
		printf("\t\tunsigned int sharedMemBytes = %u\n", args->hipGraphAddKernelNode.pNodeParams__ref.val.sharedMemBytes); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipArray_t dst (unknown);
//	size_t wOffset (unsigned long);
//	size_t hOffset (unsigned long);
//	const void * src (void*);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpyToArray(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemcpyToArray.retval); \
	printf("\thipArray_t dst = N/A, try to update csv files\n"); \
	printf("\tsize_t wOffset = %lu\n", args->hipMemcpyToArray.wOffset); \
	printf("\tsize_t hOffset = %lu\n", args->hipMemcpyToArray.hOffset); \
	printf("\tconst void * src = %p", args->hipMemcpyToArray.src); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipMemcpyToArray.count); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	void * devPtr (void*);
#define PROCESS_ARGS_hipIpcCloseMemHandle(args) { \
	printf("\thipError_t retval = %d\n", args->hipIpcCloseMemHandle.retval); \
	printf("\tvoid * devPtr = %p", args->hipIpcCloseMemHandle.devPtr); \
	printf("\n"); \
};

//	hipGraph_t graph (opaque);
#define PROCESS_ARGS_hipGraphDestroy(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphDestroy.retval); \
	printf("\thipGraph_t graph = %p\n", args->hipGraphDestroy.graph); \
};

//	const void * dev_ptr (void*);
//	size_t count (unsigned long);
//	hipMemoryAdvise advice (enum);
//	int device (int);
#define PROCESS_ARGS_hipMemAdvise(args) { \
	printf("\thipError_t retval = %d\n", args->hipMemAdvise.retval); \
	printf("\tconst void * dev_ptr = %p", args->hipMemAdvise.dev_ptr); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipMemAdvise.count); \
	printf("\thipMemoryAdvise advice = %d\n", args->hipMemAdvise.advice); \
	printf("\tint device = %d\n", args->hipMemAdvise.device); \
};

//	hipGraphNode_t node (opaque);
#define PROCESS_ARGS_hipGraphDestroyNode(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphDestroyNode.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphDestroyNode.node); \
};

//	int * value (int*);
//	hipFunction_attribute attrib (unknown);
//	hipFunction_t hfunc (opaque);
#define PROCESS_ARGS_hipFuncGetAttribute(args) { \
	printf("\thipError_t retval = %d\n", args->hipFuncGetAttribute.retval); \
	printf("\tint * value = %p", args->hipFuncGetAttribute.value); \
	if (args->hipFuncGetAttribute.value != NULL) { \
		printf(" -> %d\n", args->hipFuncGetAttribute.value__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipFunction_attribute attrib = N/A, try to update csv files\n"); \
	printf("\thipFunction_t hfunc = %p\n", args->hipFuncGetAttribute.hfunc); \
};

//	hipCtx_t peerCtx (opaque);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipCtxEnablePeerAccess(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxEnablePeerAccess.retval); \
	printf("\thipCtx_t peerCtx = %p\n", args->hipCtxEnablePeerAccess.peerCtx); \
	printf("\tunsigned int flags = %u\n", args->hipCtxEnablePeerAccess.flags); \
};

//	int * numBlocks (int*);
//	hipFunction_t f (opaque);
//	int blockSize (int);
//	size_t dynSharedMemPerBlk (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(args) { \
	printf("\thipError_t retval = %d\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.retval); \
	printf("\tint * numBlocks = %p", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks); \
	if (args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks != NULL) { \
		printf(" -> %d\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipFunction_t f = %p\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.f); \
	printf("\tint blockSize = %d\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.blockSize); \
	printf("\tsize_t dynSharedMemPerBlk = %lu\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.dynSharedMemPerBlk); \
	printf("\tunsigned int flags = %u\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.flags); \
};


#define PROCESS_ARGS_hipCtxSynchronize(args) { \
	printf("\thipError_t retval = %d\n", args->hipCtxSynchronize.retval); \
\
};

//	hipExternalMemory_t extMem (void*);
#define PROCESS_ARGS_hipDestroyExternalMemory(args) { \
	printf("\thipError_t retval = %d\n", args->hipDestroyExternalMemory.retval); \
	printf("\thipExternalMemory_t extMem = %p", args->hipDestroyExternalMemory.extMem); \
	printf("\n"); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipStreamDestroy(args) { \
	printf("\thipError_t retval = %d\n", args->hipStreamDestroy.retval); \
	printf("\thipStream_t stream = %p\n", args->hipStreamDestroy.stream); \
};

//	hipGraphNode_t * pGraphNode (opaque*);
//	hipGraph_t graph (opaque);
//	const hipGraphNode_t * pDependencies (opaque*);
//	size_t numDependencies (unsigned long);
//	const void * symbol (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphAddMemcpyNodeToSymbol(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphAddMemcpyNodeToSymbol.retval); \
	printf("\thipGraphNode_t * pGraphNode = %p", args->hipGraphAddMemcpyNodeToSymbol.pGraphNode); \
	if (args->hipGraphAddMemcpyNodeToSymbol.pGraphNode != NULL) { \
		printf(" -> %p\n", args->hipGraphAddMemcpyNodeToSymbol.pGraphNode__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t graph = %p\n", args->hipGraphAddMemcpyNodeToSymbol.graph); \
	printf("\tconst hipGraphNode_t * pDependencies = %p", args->hipGraphAddMemcpyNodeToSymbol.pDependencies); \
	if (args->hipGraphAddMemcpyNodeToSymbol.pDependencies != NULL) { \
		printf(" -> %p\n", args->hipGraphAddMemcpyNodeToSymbol.pDependencies__ref.val); \
	} else { printf("\n"); }; \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddMemcpyNodeToSymbol.numDependencies); \
	printf("\tconst void * symbol = %p", args->hipGraphAddMemcpyNodeToSymbol.symbol); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipGraphAddMemcpyNodeToSymbol.src); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipGraphAddMemcpyNodeToSymbol.count); \
	printf("\tsize_t offset = %lu\n", args->hipGraphAddMemcpyNodeToSymbol.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t node (opaque);
//	hipEvent_t event (opaque);
#define PROCESS_ARGS_hipGraphEventRecordNodeSetEvent(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphEventRecordNodeSetEvent.retval); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphEventRecordNodeSetEvent.node); \
	printf("\thipEvent_t event = %p\n", args->hipGraphEventRecordNodeSetEvent.event); \
};

//	int * value (int*);
//	hipDeviceP2PAttr attr (enum);
//	int srcDevice (int);
//	int dstDevice (int);
#define PROCESS_ARGS_hipDeviceGetP2PAttribute(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceGetP2PAttribute.retval); \
	printf("\tint * value = %p", args->hipDeviceGetP2PAttribute.value); \
	if (args->hipDeviceGetP2PAttribute.value != NULL) { \
		printf(" -> %d\n", args->hipDeviceGetP2PAttribute.value__ref.val); \
	} else { printf("\n"); }; \
	printf("\thipDeviceP2PAttr attr = %d\n", args->hipDeviceGetP2PAttribute.attr); \
	printf("\tint srcDevice = %d\n", args->hipDeviceGetP2PAttribute.srcDevice); \
	printf("\tint dstDevice = %d\n", args->hipDeviceGetP2PAttribute.dstDevice); \
};

//	hipStream_t stream (opaque);
#define PROCESS_ARGS_hipGetStreamDeviceId(args) { \
	printf("\tint retval = %d\n", args->hipGetStreamDeviceId.retval); \
	printf("\thipStream_t stream = %p\n", args->hipGetStreamDeviceId.stream); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t hNode (opaque);
//	unsigned int * isEnabled (unsigned int*);
#define PROCESS_ARGS_hipGraphNodeGetEnabled(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphNodeGetEnabled.retval); \
	printf("\thipGraphExec_t hGraphExec = %p\n", args->hipGraphNodeGetEnabled.hGraphExec); \
	printf("\thipGraphNode_t hNode = %p\n", args->hipGraphNodeGetEnabled.hNode); \
	printf("\tunsigned int * isEnabled = %p", args->hipGraphNodeGetEnabled.isEnabled); \
	if (args->hipGraphNodeGetEnabled.isEnabled != NULL) { \
		printf(" -> %u\n", args->hipGraphNodeGetEnabled.isEnabled__ref.val); \
	} else { printf("\n"); }; \
};

//	hipMemPool_t * mem_pool (opaque*);
//	int device (int);
#define PROCESS_ARGS_hipDeviceGetMemPool(args) { \
	printf("\thipError_t retval = %d\n", args->hipDeviceGetMemPool.retval); \
	printf("\thipMemPool_t * mem_pool = %p", args->hipDeviceGetMemPool.mem_pool); \
	if (args->hipDeviceGetMemPool.mem_pool != NULL) { \
		printf(" -> %p\n", args->hipDeviceGetMemPool.mem_pool__ref.val); \
	} else { printf("\n"); }; \
	printf("\tint device = %d\n", args->hipDeviceGetMemPool.device); \
};

//	hipArray_t * pLevelArray (unknown);
//	hipMipmappedArray_t hMipMappedArray (unknown);
//	unsigned int level (unsigned int);
#define PROCESS_ARGS_hipMipmappedArrayGetLevel(args) { \
	printf("\thipError_t retval = %d\n", args->hipMipmappedArrayGetLevel.retval); \
	printf("\thipArray_t * pLevelArray = N/A, try to update csv files\n"); \
	printf("\thipMipmappedArray_t hMipMappedArray = N/A, try to update csv files\n"); \
	printf("\tunsigned int level = %u\n", args->hipMipmappedArrayGetLevel.level); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
//	const void * symbol (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParamsToSymbol(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExecMemcpyNodeSetParamsToSymbol.retval); \
	printf("\thipGraphExec_t hGraphExec = %p\n", args->hipGraphExecMemcpyNodeSetParamsToSymbol.hGraphExec); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphExecMemcpyNodeSetParamsToSymbol.node); \
	printf("\tconst void * symbol = %p", args->hipGraphExecMemcpyNodeSetParamsToSymbol.symbol); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipGraphExecMemcpyNodeSetParamsToSymbol.src); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipGraphExecMemcpyNodeSetParamsToSymbol.count); \
	printf("\tsize_t offset = %lu\n", args->hipGraphExecMemcpyNodeSetParamsToSymbol.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	hipGraphExec_t hGraphExec (opaque);
//	hipGraphNode_t node (opaque);
//	const hipMemsetParams * pNodeParams ({
//		unsigned int elementSize (unsigned int);
//		size_t height (unsigned long);
//		size_t pitch (unsigned long);
//		unsigned int value (unsigned int);
//		size_t width (unsigned long);
//	});
#define PROCESS_ARGS_hipGraphExecMemsetNodeSetParams(args) { \
	printf("\thipError_t retval = %d\n", args->hipGraphExecMemsetNodeSetParams.retval); \
	printf("\thipGraphExec_t hGraphExec = %p\n", args->hipGraphExecMemsetNodeSetParams.hGraphExec); \
	printf("\thipGraphNode_t node = %p\n", args->hipGraphExecMemsetNodeSetParams.node); \
	printf("\tconst hipMemsetParams * pNodeParams = %p", args->hipGraphExecMemsetNodeSetParams.pNodeParams); \
	if (args->hipGraphExecMemsetNodeSetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned int elementSize = %u\n", args->hipGraphExecMemsetNodeSetParams.pNodeParams__ref.val.elementSize); \
		printf("\t\tsize_t height = %lu\n", args->hipGraphExecMemsetNodeSetParams.pNodeParams__ref.val.height); \
		printf("\t\tsize_t pitch = %lu\n", args->hipGraphExecMemsetNodeSetParams.pNodeParams__ref.val.pitch); \
		printf("\t\tunsigned int value = %u\n", args->hipGraphExecMemsetNodeSetParams.pNodeParams__ref.val.value); \
		printf("\t\tsize_t width = %lu\n", args->hipGraphExecMemsetNodeSetParams.pNodeParams__ref.val.width); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

#endif // HIP_PLUGIN_H