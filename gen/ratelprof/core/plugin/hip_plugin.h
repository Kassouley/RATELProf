/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#ifndef HIP_PLUGIN_H 
#define HIP_PLUGIN_H 

void process_hip_args_for(hip_api_id_t funid, const hip_api_args_t* args);

//	textureReference* texRef (unknown);
//	enum hipTextureFilterMode fm (enum);
#define PROCESS_ARGS_hipTexRefSetMipmapFilterMode(args) { \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tenum hipTextureFilterMode fm = %d\n", args->hipTexRefSetMipmapFilterMode.fm); \
};

//	hipArray_t dstArray (unknown);
//	size_t dstOffset (unsigned long);
//	const void * srcHost (void*);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemcpyHtoA(args) { \
	printf("\thipArray_t dstArray = N/A, try to update csv files\n"); \
	printf("\tsize_t dstOffset = %lu\n", args->hipMemcpyHtoA.dstOffset); \
	printf("\tconst void * srcHost = %p", args->hipMemcpyHtoA.srcHost); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipMemcpyHtoA.count); \
};

//	hipCtx_t ctx (unknown);
//	int * apiVersion (int*);
#define PROCESS_ARGS_hipCtxGetApiVersion(args) { \
	printf("\thipCtx_t ctx = N/A, try to update csv files\n"); \
	printf("\tint * apiVersion = %p", args->hipCtxGetApiVersion.apiVersion); \
	if (args->hipCtxGetApiVersion.apiVersion != NULL) { \
		printf(" -> %d\n", *args->hipCtxGetApiVersion.apiVersion); \
	} else { printf("\n"); }; \
};

//	char * name (char*);
//	int len (int);
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceGetName(args) { \
	printf("\tchar * name = %p", args->hipDeviceGetName.name); \
	if (args->hipDeviceGetName.name != NULL) { \
		printf(" -> %c\n", *args->hipDeviceGetName.name); \
	} else { printf("\n"); }; \
	printf("\tint len = %d\n", args->hipDeviceGetName.len); \
	printf("\thipDevice_t device = %d\n", args->hipDeviceGetName.device); \
};

//	hipStream_t stream (unknown);
//	hipStreamCaptureStatus * pCaptureStatus (enum*);
#define PROCESS_ARGS_hipStreamIsCapturing(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\thipStreamCaptureStatus * pCaptureStatus = %p", args->hipStreamIsCapturing.pCaptureStatus); \
	if (args->hipStreamIsCapturing.pCaptureStatus != NULL) { \
		printf(" -> %d\n", *args->hipStreamIsCapturing.pCaptureStatus); \
	} else { printf("\n"); }; \
};

//	hipStream_t stream (unknown);
//	void * dev_ptr (void*);
//	size_t length (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamAttachMemAsync(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\tvoid * dev_ptr = %p", args->hipStreamAttachMemAsync.dev_ptr); \
	printf("\n"); \
	printf("\tsize_t length = %lu\n", args->hipStreamAttachMemAsync.length); \
	printf("\tunsigned int flags = %u\n", args->hipStreamAttachMemAsync.flags); \
};

//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipFreeArray(args) { \
	printf("\thipArray_t array = N/A, try to update csv files\n"); \
};

//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipSetDeviceFlags(args) { \
	printf("\tunsigned int flags = %u\n", args->hipSetDeviceFlags.flags); \
};

//	hipEvent_t * event (unknown);
//	hipIpcEventHandle_t handle ({
//		char[64] reserved (char*);
//	});
#define PROCESS_ARGS_hipIpcOpenEventHandle(args) { \
	printf("\thipEvent_t * event = N/A, try to update csv files\n"); \
	printf("\tstruct hipIpcEventHandle_t handle = {\n"); \
	printf("\t\tchar[64] reserved = %p", args->hipIpcOpenEventHandle.handle.reserved); \
	if (args->hipIpcOpenEventHandle.handle.reserved != NULL) { \
		printf(" -> %c\n", *args->hipIpcOpenEventHandle.handle.reserved); \
	} else { printf("\n"); }; \
	printf("\t}\n"); \
};

//	hipModule_t * module (unknown);
//	const char * fname (char*);
#define PROCESS_ARGS_hipModuleLoad(args) { \
	printf("\thipModule_t * module = N/A, try to update csv files\n"); \
	printf("\tconst char * fname = %p", args->hipModuleLoad.fname); \
	if (args->hipModuleLoad.fname != NULL) { \
		printf(" -> %c\n", *args->hipModuleLoad.fname); \
	} else { printf("\n"); }; \
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
	printf("\tvoid ** devPtr = %p", args->hipExternalMemoryGetMappedBuffer.devPtr); \
	if (args->hipExternalMemoryGetMappedBuffer.devPtr != NULL) { \
		printf("-> %p", *args->hipExternalMemoryGetMappedBuffer.devPtr); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\thipExternalMemory_t extMem = %p", args->hipExternalMemoryGetMappedBuffer.extMem); \
	printf("\n"); \
	printf("\tstruct const hipExternalMemoryBufferDesc * bufferDesc = %p", args->hipExternalMemoryGetMappedBuffer.bufferDesc); \
	if (args->hipExternalMemoryGetMappedBuffer.bufferDesc != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned long long offset = %llu\n", (*args->hipExternalMemoryGetMappedBuffer.bufferDesc).offset); \
		printf("\t\tunsigned long long size = %llu\n", (*args->hipExternalMemoryGetMappedBuffer.bufferDesc).size); \
		printf("\t\tunsigned int flags = %u\n", (*args->hipExternalMemoryGetMappedBuffer.bufferDesc).flags); \
		printf("\t\tunsigned int[16] reserved = %p", (*args->hipExternalMemoryGetMappedBuffer.bufferDesc).reserved); \
		if ((*args->hipExternalMemoryGetMappedBuffer.bufferDesc).reserved != NULL) { \
			printf(" -> %u\n", *(*args->hipExternalMemoryGetMappedBuffer.bufferDesc).reserved); \
		} else { printf("\n"); }; \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipMemGenericAllocationHandle_t * handle (unknown);
//	void * osHandle (void*);
//	hipMemAllocationHandleType shHandleType (enum);
#define PROCESS_ARGS_hipMemImportFromShareableHandle(args) { \
	printf("\thipMemGenericAllocationHandle_t * handle = N/A, try to update csv files\n"); \
	printf("\tvoid * osHandle = %p", args->hipMemImportFromShareableHandle.osHandle); \
	printf("\n"); \
	printf("\thipMemAllocationHandleType shHandleType = %d\n", args->hipMemImportFromShareableHandle.shHandleType); \
};

//	void * dst (void*);
//	hipDeviceptr_t src (unknown);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemcpyDtoH(args) { \
	printf("\tvoid * dst = %p", args->hipMemcpyDtoH.dst); \
	printf("\n"); \
	printf("\thipDeviceptr_t src = N/A, try to update csv files\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyDtoH.sizeBytes); \
};

//	hipStream_t stream (unknown);
//	hipGraph_t * pGraph (unknown);
#define PROCESS_ARGS_hipStreamEndCapture(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\thipGraph_t * pGraph = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t node (unknown);
//	void * dev_ptr (void*);
#define PROCESS_ARGS_hipGraphMemFreeNodeGetParams(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\tvoid * dev_ptr = %p", args->hipGraphMemFreeNodeGetParams.dev_ptr); \
	printf("\n"); \
};

//	hipStreamCaptureMode * mode (enum*);
#define PROCESS_ARGS_hipThreadExchangeStreamCaptureMode(args) { \
	printf("\thipStreamCaptureMode * mode = %p", args->hipThreadExchangeStreamCaptureMode.mode); \
	if (args->hipThreadExchangeStreamCaptureMode.mode != NULL) { \
		printf(" -> %d\n", *args->hipThreadExchangeStreamCaptureMode.mode); \
	} else { printf("\n"); }; \
};

//	hipModule_t module (unknown);
#define PROCESS_ARGS_hipModuleUnload(args) { \
	printf("\thipModule_t module = N/A, try to update csv files\n"); \
};

//	int * gridSize (int*);
//	int * blockSize (int*);
//	hipFunction_t f (unknown);
//	size_t dynSharedMemPerBlk (unsigned long);
//	int blockSizeLimit (int);
#define PROCESS_ARGS_hipModuleOccupancyMaxPotentialBlockSize(args) { \
	printf("\tint * gridSize = %p", args->hipModuleOccupancyMaxPotentialBlockSize.gridSize); \
	if (args->hipModuleOccupancyMaxPotentialBlockSize.gridSize != NULL) { \
		printf(" -> %d\n", *args->hipModuleOccupancyMaxPotentialBlockSize.gridSize); \
	} else { printf("\n"); }; \
	printf("\tint * blockSize = %p", args->hipModuleOccupancyMaxPotentialBlockSize.blockSize); \
	if (args->hipModuleOccupancyMaxPotentialBlockSize.blockSize != NULL) { \
		printf(" -> %d\n", *args->hipModuleOccupancyMaxPotentialBlockSize.blockSize); \
	} else { printf("\n"); }; \
	printf("\thipFunction_t f = N/A, try to update csv files\n"); \
	printf("\tsize_t dynSharedMemPerBlk = %lu\n", args->hipModuleOccupancyMaxPotentialBlockSize.dynSharedMemPerBlk); \
	printf("\tint blockSizeLimit = %d\n", args->hipModuleOccupancyMaxPotentialBlockSize.blockSizeLimit); \
};

//	const hip_Memcpy2D * pCopy (unknown);
#define PROCESS_ARGS_hipMemcpyParam2D(args) { \
	printf("\tconst hip_Memcpy2D * pCopy = N/A, try to update csv files\n"); \
};


#define PROCESS_ARGS_hipPeekAtLastError(args) { \
\
};

//	hipMemGenericAllocationHandle_t handle (unknown);
#define PROCESS_ARGS_hipMemRelease(args) { \
	printf("\thipMemGenericAllocationHandle_t handle = N/A, try to update csv files\n"); \
};

//	hipSharedMemConfig * pConfig (enum*);
#define PROCESS_ARGS_hipDeviceGetSharedMemConfig(args) { \
	printf("\thipSharedMemConfig * pConfig = %p", args->hipDeviceGetSharedMemConfig.pConfig); \
	if (args->hipDeviceGetSharedMemConfig.pConfig != NULL) { \
		printf(" -> %d\n", *args->hipDeviceGetSharedMemConfig.pConfig); \
	} else { printf("\n"); }; \
};

//	hipUserObject_t object (unknown);
//	unsigned int count (unsigned int);
#define PROCESS_ARGS_hipUserObjectRelease(args) { \
	printf("\thipUserObject_t object = N/A, try to update csv files\n"); \
	printf("\tunsigned int count = %u\n", args->hipUserObjectRelease.count); \
};

//	hipStream_t stream (unknown);
//	void * ptr (void*);
//	uint32_t value (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamWriteValue32(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\tvoid * ptr = %p", args->hipStreamWriteValue32.ptr); \
	printf("\n"); \
	printf("\tuint32_t value = %u\n", args->hipStreamWriteValue32.value); \
	printf("\tunsigned int flags = %u\n", args->hipStreamWriteValue32.flags); \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMemAllocHost(args) { \
	printf("\tvoid ** ptr = %p", args->hipMemAllocHost.ptr); \
	if (args->hipMemAllocHost.ptr != NULL) { \
		printf("-> %p", *args->hipMemAllocHost.ptr); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipMemAllocHost.size); \
};

//	hipGraph_t * pGraph (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipGraphCreate(args) { \
	printf("\thipGraph_t * pGraph = N/A, try to update csv files\n"); \
	printf("\tunsigned int flags = %u\n", args->hipGraphCreate.flags); \
};

//	int * gridSize (int*);
//	int * blockSize (int*);
//	hipFunction_t f (unknown);
//	size_t dynSharedMemPerBlk (unsigned long);
//	int blockSizeLimit (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipModuleOccupancyMaxPotentialBlockSizeWithFlags(args) { \
	printf("\tint * gridSize = %p", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.gridSize); \
	if (args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.gridSize != NULL) { \
		printf(" -> %d\n", *args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.gridSize); \
	} else { printf("\n"); }; \
	printf("\tint * blockSize = %p", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSize); \
	if (args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSize != NULL) { \
		printf(" -> %d\n", *args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSize); \
	} else { printf("\n"); }; \
	printf("\thipFunction_t f = N/A, try to update csv files\n"); \
	printf("\tsize_t dynSharedMemPerBlk = %lu\n", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.dynSharedMemPerBlk); \
	printf("\tint blockSizeLimit = %d\n", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.blockSizeLimit); \
	printf("\tunsigned int flags = %u\n", args->hipModuleOccupancyMaxPotentialBlockSizeWithFlags.flags); \
};

//	hipArray_t * array (unknown);
//	const struct hipChannelFormatDesc * desc (unknown);
//	struct hipExtent extent (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMalloc3DArray(args) { \
	printf("\thipArray_t * array = N/A, try to update csv files\n"); \
	printf("\tconst struct hipChannelFormatDesc * desc = N/A, try to update csv files\n"); \
	printf("\tstruct hipExtent extent = N/A, try to update csv files\n"); \
	printf("\tunsigned int flags = %u\n", args->hipMalloc3DArray.flags); \
};

//	hipFuncCache_t * cacheConfig (enum*);
#define PROCESS_ARGS_hipCtxGetCacheConfig(args) { \
	printf("\thipFuncCache_t * cacheConfig = %p", args->hipCtxGetCacheConfig.cacheConfig); \
	if (args->hipCtxGetCacheConfig.cacheConfig != NULL) { \
		printf(" -> %d\n", *args->hipCtxGetCacheConfig.cacheConfig); \
	} else { printf("\n"); }; \
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
	printf("\thipFunction_t f = N/A, try to update csv files\n"); \
	printf("\tunsigned int gridDimX = %u\n", args->hipModuleLaunchCooperativeKernel.gridDimX); \
	printf("\tunsigned int gridDimY = %u\n", args->hipModuleLaunchCooperativeKernel.gridDimY); \
	printf("\tunsigned int gridDimZ = %u\n", args->hipModuleLaunchCooperativeKernel.gridDimZ); \
	printf("\tunsigned int blockDimX = %u\n", args->hipModuleLaunchCooperativeKernel.blockDimX); \
	printf("\tunsigned int blockDimY = %u\n", args->hipModuleLaunchCooperativeKernel.blockDimY); \
	printf("\tunsigned int blockDimZ = %u\n", args->hipModuleLaunchCooperativeKernel.blockDimZ); \
	printf("\tunsigned int sharedMemBytes = %u\n", args->hipModuleLaunchCooperativeKernel.sharedMemBytes); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\tvoid ** kernelParams = %p", args->hipModuleLaunchCooperativeKernel.kernelParams); \
	if (args->hipModuleLaunchCooperativeKernel.kernelParams != NULL) { \
		printf("-> %p", *args->hipModuleLaunchCooperativeKernel.kernelParams); \
		printf("\n"); \
	} else { printf("\n"); }; \
};

//	enum hipTextureAddressMode * pam (enum);
//	const textureReference* texRef (unknown);
//	int dim (int);
#define PROCESS_ARGS_hipTexRefGetAddressMode(args) { \
	printf("\tenum hipTextureAddressMode * pam = %d\n", args->hipTexRefGetAddressMode.pam); \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tint dim = %d\n", args->hipTexRefGetAddressMode.dim); \
};

//	hipGraphNode_t node (unknown);
//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipGraphEventWaitNodeSetEvent(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\thipEvent_t event = N/A, try to update csv files\n"); \
};

//	hipMemPool_t * mem_pool (unknown);
//	int device (int);
#define PROCESS_ARGS_hipDeviceGetDefaultMemPool(args) { \
	printf("\thipMemPool_t * mem_pool = N/A, try to update csv files\n"); \
	printf("\tint device = %d\n", args->hipDeviceGetDefaultMemPool.device); \
};

//	hipMemPool_t mem_pool (unknown);
//	size_t min_bytes_to_hold (unsigned long);
#define PROCESS_ARGS_hipMemPoolTrimTo(args) { \
	printf("\thipMemPool_t mem_pool = N/A, try to update csv files\n"); \
	printf("\tsize_t min_bytes_to_hold = %lu\n", args->hipMemPoolTrimTo.min_bytes_to_hold); \
};

//	hipGraphExec_t graphExec (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipGraphUpload(args) { \
	printf("\thipGraphExec_t graphExec = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
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
	printf("\thipMipmappedArray_t * mipmap = N/A, try to update csv files\n"); \
	printf("\thipExternalMemory_t extMem = %p", args->hipExternalMemoryGetMappedMipmappedArray.extMem); \
	printf("\n"); \
	printf("\tstruct const hipExternalMemoryMipmappedArrayDesc * mipmapDesc = %p", args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc); \
	if (args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned long long offset = %llu\n", (*args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc).offset); \
		printf("\t\tint formatDesc = %d\n", (*args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc).formatDesc); \
		printf("\t\tint extent = %d\n", (*args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc).extent); \
		printf("\t\tunsigned int flags = %u\n", (*args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc).flags); \
		printf("\t\tunsigned int numLevels = %u\n", (*args->hipExternalMemoryGetMappedMipmappedArray.mipmapDesc).numLevels); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
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
	printf("\thipGraphNode_t hNode = N/A, try to update csv files\n"); \
	printf("\tstruct const hipExternalSemaphoreWaitNodeParams * nodeParams = %p", args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams); \
	if (args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipExternalSemaphore_t * extSemArray = %p", (*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).extSemArray); \
		if ((*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).extSemArray != NULL) { \
			printf("-> %p", *(*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).extSemArray); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tstruct const hipExternalSemaphoreWaitParams * paramsArray = %p", (*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray); \
		if ((*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray != NULL) { \
			printf(" -> {\n"); \
			printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1156:3) params = N/A, try to update csv files\n"); \
			printf("\t\t\tunsigned int flags = %u\n", (*(*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).flags); \
			printf("\t\t\tunsigned int[16] reserved = %p", (*(*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).reserved); \
			if ((*(*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).reserved != NULL) { \
				printf(" -> %u\n", *(*(*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).reserved); \
			} else { printf("\n"); }; \
			printf("\t\t}\n"); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int numExtSems = %u\n", (*args->hipGraphExternalSemaphoresWaitNodeSetParams.nodeParams).numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	const void * symbol (void*);
//	const void * src (void*);
//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpyToSymbol(args) { \
	printf("\tconst void * symbol = %p", args->hipMemcpyToSymbol.symbol); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipMemcpyToSymbol.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyToSymbol.sizeBytes); \
	printf("\tsize_t offset = %lu\n", args->hipMemcpyToSymbol.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
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
	printf("\thipGraphNode_t * pGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddMemsetNode.numDependencies); \
	printf("\tstruct const hipMemsetParams * pMemsetParams = %p", args->hipGraphAddMemsetNode.pMemsetParams); \
	if (args->hipGraphAddMemsetNode.pMemsetParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tvoid * dst = %p", (*args->hipGraphAddMemsetNode.pMemsetParams).dst); \
		printf("\n"); \
		printf("\t\tunsigned int elementSize = %u\n", (*args->hipGraphAddMemsetNode.pMemsetParams).elementSize); \
		printf("\t\tint height = %d\n", (*args->hipGraphAddMemsetNode.pMemsetParams).height); \
		printf("\t\tint pitch = %d\n", (*args->hipGraphAddMemsetNode.pMemsetParams).pitch); \
		printf("\t\tunsigned int value = %u\n", (*args->hipGraphAddMemsetNode.pMemsetParams).value); \
		printf("\t\tint width = %d\n", (*args->hipGraphAddMemsetNode.pMemsetParams).width); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraph_t * pGraphClone (unknown);
//	hipGraph_t originalGraph (unknown);
#define PROCESS_ARGS_hipGraphClone(args) { \
	printf("\thipGraph_t * pGraphClone = N/A, try to update csv files\n"); \
	printf("\thipGraph_t originalGraph = N/A, try to update csv files\n"); \
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
	printf("\thipGraphNode_t hNode = N/A, try to update csv files\n"); \
	printf("\thipKernelNodeAttrID attr = %d\n", args->hipGraphKernelNodeGetAttribute.attr); \
	printf("\tunion hipKernelNodeAttrValue * value = %p", args->hipGraphKernelNodeGetAttribute.value); \
	if (args->hipGraphKernelNodeGetAttribute.value != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tstruct hipAccessPolicyWindow accessPolicyWindow = {\n"); \
		printf("\t\t\tvoid * base_ptr = %p", ((*args->hipGraphKernelNodeGetAttribute.value).accessPolicyWindow).base_ptr); \
		printf("\n"); \
		printf("\t\t\thipAccessProperty hitProp = %d\n", ((*args->hipGraphKernelNodeGetAttribute.value).accessPolicyWindow).hitProp); \
		printf("\t\t\tfloat hitRatio = %f\n", ((*args->hipGraphKernelNodeGetAttribute.value).accessPolicyWindow).hitRatio); \
		printf("\t\t\thipAccessProperty missProp = %d\n", ((*args->hipGraphKernelNodeGetAttribute.value).accessPolicyWindow).missProp); \
		printf("\t\t\tint num_bytes = %d\n", ((*args->hipGraphKernelNodeGetAttribute.value).accessPolicyWindow).num_bytes); \
		printf("\t\t}\n"); \
		printf("\t\tint cooperative = %d\n", (*args->hipGraphKernelNodeGetAttribute.value).cooperative); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipEvent_t event (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipEventRecord(args) { \
	printf("\thipEvent_t event = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
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
	printf("\tstruct hipMemAllocationProp * prop = %p", args->hipMemGetAllocationPropertiesFromHandle.prop); \
	if (args->hipMemGetAllocationPropertiesFromHandle.prop != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemAllocationType type = %d\n", (*args->hipMemGetAllocationPropertiesFromHandle.prop).type); \
		printf("\t\thipMemAllocationHandleType requestedHandleType = %d\n", (*args->hipMemGetAllocationPropertiesFromHandle.prop).requestedHandleType); \
		printf("\t\tstruct hipMemLocation location = {\n"); \
		printf("\t\t\thipMemLocationType type = %d\n", ((*args->hipMemGetAllocationPropertiesFromHandle.prop).location).type); \
		printf("\t\t\tint id = %d\n", ((*args->hipMemGetAllocationPropertiesFromHandle.prop).location).id); \
		printf("\t\t}\n"); \
		printf("\t\tvoid * win32HandleMetaData = %p", (*args->hipMemGetAllocationPropertiesFromHandle.prop).win32HandleMetaData); \
		printf("\n"); \
		printf("\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1393:5) allocFlags = N/A, try to update csv files\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thipMemGenericAllocationHandle_t handle = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipGraphAddEventWaitNode(args) { \
	printf("\thipGraphNode_t * pGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddEventWaitNode.numDependencies); \
	printf("\thipEvent_t event = N/A, try to update csv files\n"); \
};

//	void ** dev_ptr (void**);
//	hipMemPool_t mem_pool (unknown);
//	struct hipMemPoolPtrExportData * export_data ({
//		unsigned char[64] reserved (unsigned char*);
//	});
#define PROCESS_ARGS_hipMemPoolImportPointer(args) { \
	printf("\tvoid ** dev_ptr = %p", args->hipMemPoolImportPointer.dev_ptr); \
	if (args->hipMemPoolImportPointer.dev_ptr != NULL) { \
		printf("-> %p", *args->hipMemPoolImportPointer.dev_ptr); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\thipMemPool_t mem_pool = N/A, try to update csv files\n"); \
	printf("\tstruct hipMemPoolPtrExportData * export_data = %p", args->hipMemPoolImportPointer.export_data); \
	if (args->hipMemPoolImportPointer.export_data != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned char[64] reserved = %p", (*args->hipMemPoolImportPointer.export_data).reserved); \
		if ((*args->hipMemPoolImportPointer.export_data).reserved != NULL) { \
			printf(" -> %hhu\n", *(*args->hipMemPoolImportPointer.export_data).reserved); \
		} else { printf("\n"); }; \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	void * ptr (void*);
#define PROCESS_ARGS_hipFree(args) { \
	printf("\tvoid * ptr = %p", args->hipFree.ptr); \
	printf("\n"); \
};

//	hipGraphNode_t node (unknown);
//	hipEvent_t * event_out (unknown);
#define PROCESS_ARGS_hipGraphEventRecordNodeGetEvent(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\thipEvent_t * event_out = N/A, try to update csv files\n"); \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMalloc(args) { \
	printf("\tvoid ** ptr = %p", args->hipMalloc.ptr); \
	if (args->hipMalloc.ptr != NULL) { \
		printf("-> %p", *args->hipMalloc.ptr); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipMalloc.size); \
};

//	void * dst (void*);
//	const void * src (void*);
//	size_t sizeBytes (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyWithStream(args) { \
	printf("\tvoid * dst = %p", args->hipMemcpyWithStream.dst); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipMemcpyWithStream.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyWithStream.sizeBytes); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	const HIP_MEMCPY3D* pCopy (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipDrvMemcpy3DAsync(args) { \
	printf("\tconst HIP_MEMCPY3D* pCopy = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
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
	printf("\thipGraphNode_t * pGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddMemAllocNode.numDependencies); \
	printf("\tstruct hipMemAllocNodeParams * pNodeParams = %p", args->hipGraphAddMemAllocNode.pNodeParams); \
	if (args->hipGraphAddMemAllocNode.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tstruct hipMemPoolProps poolProps = {\n"); \
		printf("\t\t\thipMemAllocationType allocType = %d\n", ((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).allocType); \
		printf("\t\t\thipMemAllocationHandleType handleTypes = %d\n", ((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).handleTypes); \
		printf("\t\t\tstruct hipMemLocation location = {\n"); \
		printf("\t\t\t\thipMemLocationType type = %d\n", (((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).location).type); \
		printf("\t\t\t\tint id = %d\n", (((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).location).id); \
		printf("\t\t\t}\n"); \
		printf("\t\t\tvoid * win32SecurityAttributes = %p", ((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).win32SecurityAttributes); \
		printf("\n"); \
		printf("\t\t\tunsigned char[64] reserved = %p", ((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).reserved); \
		if (((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).reserved != NULL) { \
			printf(" -> %hhu\n", *((*args->hipGraphAddMemAllocNode.pNodeParams).poolProps).reserved); \
		} else { printf("\n"); }; \
		printf("\t\t}\n"); \
		printf("\t\tstruct const hipMemAccessDesc * accessDescs = %p", (*args->hipGraphAddMemAllocNode.pNodeParams).accessDescs); \
		if ((*args->hipGraphAddMemAllocNode.pNodeParams).accessDescs != NULL) { \
			printf(" -> {\n"); \
			printf("\t\t\tstruct hipMemLocation location = {\n"); \
			printf("\t\t\t\thipMemLocationType type = %d\n", ((*(*args->hipGraphAddMemAllocNode.pNodeParams).accessDescs).location).type); \
			printf("\t\t\t\tint id = %d\n", ((*(*args->hipGraphAddMemAllocNode.pNodeParams).accessDescs).location).id); \
			printf("\t\t\t}\n"); \
			printf("\t\t\thipMemAccessFlags flags = %d\n", (*(*args->hipGraphAddMemAllocNode.pNodeParams).accessDescs).flags); \
			printf("\t\t}\n"); \
		} else { printf("\n"); }; \
		printf("\t\tint accessDescCount = %d\n", (*args->hipGraphAddMemAllocNode.pNodeParams).accessDescCount); \
		printf("\t\tint bytesize = %d\n", (*args->hipGraphAddMemAllocNode.pNodeParams).bytesize); \
		printf("\t\tvoid * dptr = %p", (*args->hipGraphAddMemAllocNode.pNodeParams).dptr); \
		printf("\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostMalloc(args) { \
	printf("\tvoid ** ptr = %p", args->hipHostMalloc.ptr); \
	if (args->hipHostMalloc.ptr != NULL) { \
		printf("-> %p", *args->hipHostMalloc.ptr); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipHostMalloc.size); \
	printf("\tunsigned int flags = %u\n", args->hipHostMalloc.flags); \
};

//	hipGraphNode_t node (unknown);
//	hipMemcpy3DParms * pNodeParams (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeGetParams(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\thipMemcpy3DParms * pNodeParams = N/A, try to update csv files\n"); \
};

//	textureReference * texRef (unknown);
//	unsigned int Flags (unsigned int);
#define PROCESS_ARGS_hipTexRefSetFlags(args) { \
	printf("\ttextureReference * texRef = N/A, try to update csv files\n"); \
	printf("\tunsigned int Flags = %u\n", args->hipTexRefSetFlags.Flags); \
};

//	hipMemPool_t * mem_pool (unknown);
//	void * shared_handle (void*);
//	hipMemAllocationHandleType handle_type (enum);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMemPoolImportFromShareableHandle(args) { \
	printf("\thipMemPool_t * mem_pool = N/A, try to update csv files\n"); \
	printf("\tvoid * shared_handle = %p", args->hipMemPoolImportFromShareableHandle.shared_handle); \
	printf("\n"); \
	printf("\thipMemAllocationHandleType handle_type = %d\n", args->hipMemPoolImportFromShareableHandle.handle_type); \
	printf("\tunsigned int flags = %u\n", args->hipMemPoolImportFromShareableHandle.flags); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t hNode (unknown);
//	unsigned int isEnabled (unsigned int);
#define PROCESS_ARGS_hipGraphNodeSetEnabled(args) { \
	printf("\thipGraphExec_t hGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t hNode = N/A, try to update csv files\n"); \
	printf("\tunsigned int isEnabled = %u\n", args->hipGraphNodeSetEnabled.isEnabled); \
};

//	textureReference * texRef (unknown);
//	float bias (float);
#define PROCESS_ARGS_hipTexRefSetMipmapLevelBias(args) { \
	printf("\ttextureReference * texRef = N/A, try to update csv files\n"); \
	printf("\tfloat bias = %f\n", args->hipTexRefSetMipmapLevelBias.bias); \
};

//	hipStream_t stream (unknown);
//	void * ptr (void*);
//	uint32_t value (unsigned int);
//	unsigned int flags (unsigned int);
//	uint32_t mask (unsigned int);
#define PROCESS_ARGS_hipStreamWaitValue32(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\tvoid * ptr = %p", args->hipStreamWaitValue32.ptr); \
	printf("\n"); \
	printf("\tuint32_t value = %u\n", args->hipStreamWaitValue32.value); \
	printf("\tunsigned int flags = %u\n", args->hipStreamWaitValue32.flags); \
	printf("\tuint32_t mask = %u\n", args->hipStreamWaitValue32.mask); \
};

//	hipMipmappedArray_t hMipmappedArray (unknown);
#define PROCESS_ARGS_hipMipmappedArrayDestroy(args) { \
	printf("\thipMipmappedArray_t hMipmappedArray = N/A, try to update csv files\n"); \
};

//	hipCtx_t ctx (unknown);
#define PROCESS_ARGS_hipCtxDestroy(args) { \
	printf("\thipCtx_t ctx = N/A, try to update csv files\n"); \
};


#define PROCESS_ARGS_hipDeviceReset(args) { \
\
};

//	const void * dev_ptr (void*);
//	size_t count (unsigned long);
//	int device (int);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemPrefetchAsync(args) { \
	printf("\tconst void * dev_ptr = %p", args->hipMemPrefetchAsync.dev_ptr); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipMemPrefetchAsync.count); \
	printf("\tint device = %d\n", args->hipMemPrefetchAsync.device); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipDeviceptr_t dest (unknown);
//	unsigned short value (unsigned short);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemsetD16(args) { \
	printf("\thipDeviceptr_t dest = N/A, try to update csv files\n"); \
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
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpy2DAsync(args) { \
	printf("\tvoid * dst = %p", args->hipMemcpy2DAsync.dst); \
	printf("\n"); \
	printf("\tsize_t dpitch = %lu\n", args->hipMemcpy2DAsync.dpitch); \
	printf("\tconst void * src = %p", args->hipMemcpy2DAsync.src); \
	printf("\n"); \
	printf("\tsize_t spitch = %lu\n", args->hipMemcpy2DAsync.spitch); \
	printf("\tsize_t width = %lu\n", args->hipMemcpy2DAsync.width); \
	printf("\tsize_t height = %lu\n", args->hipMemcpy2DAsync.height); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipDevice_t dev (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipDevicePrimaryCtxSetFlags(args) { \
	printf("\thipDevice_t dev = %d\n", args->hipDevicePrimaryCtxSetFlags.dev); \
	printf("\tunsigned int flags = %u\n", args->hipDevicePrimaryCtxSetFlags.flags); \
};

//	hipGraphExec_t * pGraphExec (unknown);
//	hipGraph_t graph (unknown);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipGraphInstantiateWithFlags(args) { \
	printf("\thipGraphExec_t * pGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tunsigned long long flags = %llu\n", args->hipGraphInstantiateWithFlags.flags); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphAddEmptyNode(args) { \
	printf("\thipGraphNode_t * pGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddEmptyNode.numDependencies); \
};

//	hipMipmappedArray_t mipmappedArray (unknown);
#define PROCESS_ARGS_hipFreeMipmappedArray(args) { \
	printf("\thipMipmappedArray_t mipmappedArray = N/A, try to update csv files\n"); \
};

//	hipArray_t * pHandle (unknown);
//	const HIP_ARRAY_DESCRIPTOR * pAllocateArray (unknown);
#define PROCESS_ARGS_hipArrayCreate(args) { \
	printf("\thipArray_t * pHandle = N/A, try to update csv files\n"); \
	printf("\tconst HIP_ARRAY_DESCRIPTOR * pAllocateArray = N/A, try to update csv files\n"); \
};

//	const textureReference * tex (unknown);
#define PROCESS_ARGS_hipUnbindTexture(args) { \
	printf("\tconst textureReference * tex = N/A, try to update csv files\n"); \
};

//	hipCtx_t * ctx (unknown);
#define PROCESS_ARGS_hipCtxPopCurrent(args) { \
	printf("\thipCtx_t * ctx = N/A, try to update csv files\n"); \
};

//	hipDeviceptr_t dest (unknown);
//	unsigned short value (unsigned short);
//	size_t count (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemsetD16Async(args) { \
	printf("\thipDeviceptr_t dest = N/A, try to update csv files\n"); \
	printf("\tunsigned short value = %hu\n", args->hipMemsetD16Async.value); \
	printf("\tsize_t count = %lu\n", args->hipMemsetD16Async.count); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	HIP_RESOURCE_DESC * pResDesc (unknown);
//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectGetResourceDesc(args) { \
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
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipLaunchKernel(args) { \
	printf("\tconst void * function_address = %p", args->hipLaunchKernel.function_address); \
	printf("\n"); \
	printf("\tstruct dim3 numBlocks = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipLaunchKernel.numBlocks.x); \
	printf("\t\tuint32_t y = %u\n", args->hipLaunchKernel.numBlocks.y); \
	printf("\t\tuint32_t z = %u\n", args->hipLaunchKernel.numBlocks.z); \
	printf("\t}\n"); \
	printf("\tstruct dim3 dimBlocks = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipLaunchKernel.dimBlocks.x); \
	printf("\t\tuint32_t y = %u\n", args->hipLaunchKernel.dimBlocks.y); \
	printf("\t\tuint32_t z = %u\n", args->hipLaunchKernel.dimBlocks.z); \
	printf("\t}\n"); \
	printf("\tvoid ** args = %p", args->hipLaunchKernel.args); \
	if (args->hipLaunchKernel.args != NULL) { \
		printf("-> %p", *args->hipLaunchKernel.args); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t sharedMemBytes = %lu\n", args->hipLaunchKernel.sharedMemBytes); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
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
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\tstruct hipMemsetParams * pNodeParams = %p", args->hipGraphMemsetNodeGetParams.pNodeParams); \
	if (args->hipGraphMemsetNodeGetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tvoid * dst = %p", (*args->hipGraphMemsetNodeGetParams.pNodeParams).dst); \
		printf("\n"); \
		printf("\t\tunsigned int elementSize = %u\n", (*args->hipGraphMemsetNodeGetParams.pNodeParams).elementSize); \
		printf("\t\tint height = %d\n", (*args->hipGraphMemsetNodeGetParams.pNodeParams).height); \
		printf("\t\tint pitch = %d\n", (*args->hipGraphMemsetNodeGetParams.pNodeParams).pitch); \
		printf("\t\tunsigned int value = %u\n", (*args->hipGraphMemsetNodeGetParams.pNodeParams).value); \
		printf("\t\tint width = %d\n", (*args->hipGraphMemsetNodeGetParams.pNodeParams).width); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	unsigned int * flagsPtr (unsigned int*);
//	void * hostPtr (void*);
#define PROCESS_ARGS_hipHostGetFlags(args) { \
	printf("\tunsigned int * flagsPtr = %p", args->hipHostGetFlags.flagsPtr); \
	if (args->hipHostGetFlags.flagsPtr != NULL) { \
		printf(" -> %u\n", *args->hipHostGetFlags.flagsPtr); \
	} else { printf("\n"); }; \
	printf("\tvoid * hostPtr = %p", args->hipHostGetFlags.hostPtr); \
	printf("\n"); \
};

//	hipGraphExec_t graphExec (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipGraphLaunch(args) { \
	printf("\thipGraphExec_t graphExec = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	void * dst (void*);
//	const void * src (void*);
//	size_t sizeBytes (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyAsync(args) { \
	printf("\tvoid * dst = %p", args->hipMemcpyAsync.dst); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipMemcpyAsync.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyAsync.sizeBytes); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipArray_t * array (unknown);
//	const hipChannelFormatDesc * desc (unknown);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMallocArray(args) { \
	printf("\thipArray_t * array = N/A, try to update csv files\n"); \
	printf("\tconst hipChannelFormatDesc * desc = N/A, try to update csv files\n"); \
	printf("\tsize_t width = %lu\n", args->hipMallocArray.width); \
	printf("\tsize_t height = %lu\n", args->hipMallocArray.height); \
	printf("\tunsigned int flags = %u\n", args->hipMallocArray.flags); \
};

//	const void * func (void*);
//	hipFuncCache_t config (enum);
#define PROCESS_ARGS_hipFuncSetCacheConfig(args) { \
	printf("\tconst void * func = %p", args->hipFuncSetCacheConfig.func); \
	printf("\n"); \
	printf("\thipFuncCache_t config = %d\n", args->hipFuncSetCacheConfig.config); \
};

//	void ** dev_ptr (void**);
//	size_t size (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMallocManaged(args) { \
	printf("\tvoid ** dev_ptr = %p", args->hipMallocManaged.dev_ptr); \
	if (args->hipMallocManaged.dev_ptr != NULL) { \
		printf("-> %p", *args->hipMallocManaged.dev_ptr); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipMallocManaged.size); \
	printf("\tunsigned int flags = %u\n", args->hipMallocManaged.flags); \
};

//	uint32_t id (unsigned int);
#define PROCESS_ARGS_hipApiName(args) { \
	printf("\tuint32_t id = %u\n", args->hipApiName.id); \
};

//	void * ptr (void*);
#define PROCESS_ARGS_hipFreeHost(args) { \
	printf("\tvoid * ptr = %p", args->hipFreeHost.ptr); \
	printf("\n"); \
};

//	hipCtx_t * ctx (unknown);
#define PROCESS_ARGS_hipCtxGetCurrent(args) { \
	printf("\thipCtx_t * ctx = N/A, try to update csv files\n"); \
};

//	hipSurfaceObject_t surfaceObject (unknown);
#define PROCESS_ARGS_hipDestroySurfaceObject(args) { \
	printf("\thipSurfaceObject_t surfaceObject = N/A, try to update csv files\n"); \
};

//	void ** ptr (void**);
//	size_t * pitch (unsigned long*);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
#define PROCESS_ARGS_hipMallocPitch(args) { \
	printf("\tvoid ** ptr = %p", args->hipMallocPitch.ptr); \
	if (args->hipMallocPitch.ptr != NULL) { \
		printf("-> %p", *args->hipMallocPitch.ptr); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t * pitch = %p", args->hipMallocPitch.pitch); \
	if (args->hipMallocPitch.pitch != NULL) { \
		printf(" -> %lu\n", *args->hipMallocPitch.pitch); \
	} else { printf("\n"); }; \
	printf("\tsize_t width = %lu\n", args->hipMallocPitch.width); \
	printf("\tsize_t height = %lu\n", args->hipMallocPitch.height); \
};

//	hipStream_t stream (unknown);
//	hipStreamCaptureStatus * pCaptureStatus (enum*);
//	unsigned long long * pId (unsigned long long*);
#define PROCESS_ARGS_hipStreamGetCaptureInfo(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\thipStreamCaptureStatus * pCaptureStatus = %p", args->hipStreamGetCaptureInfo.pCaptureStatus); \
	if (args->hipStreamGetCaptureInfo.pCaptureStatus != NULL) { \
		printf(" -> %d\n", *args->hipStreamGetCaptureInfo.pCaptureStatus); \
	} else { printf("\n"); }; \
	printf("\tunsigned long long * pId = %p", args->hipStreamGetCaptureInfo.pId); \
	if (args->hipStreamGetCaptureInfo.pId != NULL) { \
		printf(" -> %llu\n", *args->hipStreamGetCaptureInfo.pId); \
	} else { printf("\n"); }; \
};

//	hipStream_t stream (unknown);
//	hipGraphNode_t * dependencies (unknown);
//	size_t numDependencies (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamUpdateCaptureDependencies(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t * dependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipStreamUpdateCaptureDependencies.numDependencies); \
	printf("\tunsigned int flags = %u\n", args->hipStreamUpdateCaptureDependencies.flags); \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostAlloc(args) { \
	printf("\tvoid ** ptr = %p", args->hipHostAlloc.ptr); \
	if (args->hipHostAlloc.ptr != NULL) { \
		printf("-> %p", *args->hipHostAlloc.ptr); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipHostAlloc.size); \
	printf("\tunsigned int flags = %u\n", args->hipHostAlloc.flags); \
};

//	hipDeviceptr_t dest (unknown);
//	unsigned char value (unsigned char);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemsetD8(args) { \
	printf("\thipDeviceptr_t dest = N/A, try to update csv files\n"); \
	printf("\tunsigned char value = %hhu\n", args->hipMemsetD8.value); \
	printf("\tsize_t count = %lu\n", args->hipMemsetD8.count); \
};

//	hipPitchedPtr pitchedDevPtr (unknown);
//	int value (int);
//	hipExtent extent (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemset3DAsync(args) { \
	printf("\thipPitchedPtr pitchedDevPtr = N/A, try to update csv files\n"); \
	printf("\tint value = %d\n", args->hipMemset3DAsync.value); \
	printf("\thipExtent extent = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	const hip_Memcpy2D * pCopy (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyParam2DAsync(args) { \
	printf("\tconst hip_Memcpy2D * pCopy = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipError_t hipError (enum);
//	const char ** errorString (char**);
#define PROCESS_ARGS_hipDrvGetErrorName(args) { \
	printf("\thipError_t hipError = %d\n", args->hipDrvGetErrorName.hipError); \
	printf("\tconst char ** errorString = %p", args->hipDrvGetErrorName.errorString); \
	if (args->hipDrvGetErrorName.errorString != NULL) { \
		printf("-> %p", *args->hipDrvGetErrorName.errorString); \
		if (*args->hipDrvGetErrorName.errorString != NULL) { \
			printf(" -> %c\n", **args->hipDrvGetErrorName.errorString); \
		} else { printf("\n"); }; \
	} else { printf("\n"); }; \
};

//	const void * value (void*);
//	hipPointer_attribute attribute (unknown);
//	hipDeviceptr_t ptr (unknown);
#define PROCESS_ARGS_hipPointerSetAttribute(args) { \
	printf("\tconst void * value = %p", args->hipPointerSetAttribute.value); \
	printf("\n"); \
	printf("\thipPointer_attribute attribute = N/A, try to update csv files\n"); \
	printf("\thipDeviceptr_t ptr = N/A, try to update csv files\n"); \
};

//	size_t * free (unsigned long*);
//	size_t * total (unsigned long*);
#define PROCESS_ARGS_hipMemGetInfo(args) { \
	printf("\tsize_t * free = %p", args->hipMemGetInfo.free); \
	if (args->hipMemGetInfo.free != NULL) { \
		printf(" -> %lu\n", *args->hipMemGetInfo.free); \
	} else { printf("\n"); }; \
	printf("\tsize_t * total = %p", args->hipMemGetInfo.total); \
	if (args->hipMemGetInfo.total != NULL) { \
		printf(" -> %lu\n", *args->hipMemGetInfo.total); \
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
//	hipStream_t stream (unknown);
#define PROCESS_ARGS___hipPushCallConfiguration(args) { \
	printf("\tstruct dim3 gridDim = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->__hipPushCallConfiguration.gridDim.x); \
	printf("\t\tuint32_t y = %u\n", args->__hipPushCallConfiguration.gridDim.y); \
	printf("\t\tuint32_t z = %u\n", args->__hipPushCallConfiguration.gridDim.z); \
	printf("\t}\n"); \
	printf("\tstruct dim3 blockDim = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->__hipPushCallConfiguration.blockDim.x); \
	printf("\t\tuint32_t y = %u\n", args->__hipPushCallConfiguration.blockDim.y); \
	printf("\t\tuint32_t z = %u\n", args->__hipPushCallConfiguration.blockDim.z); \
	printf("\t}\n"); \
	printf("\tsize_t sharedMem = %lu\n", args->__hipPushCallConfiguration.sharedMem); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipArray_Format * pFormat (unknown);
//	int * pNumChannels (int*);
//	const textureReference * texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetFormat(args) { \
	printf("\thipArray_Format * pFormat = N/A, try to update csv files\n"); \
	printf("\tint * pNumChannels = %p", args->hipTexRefGetFormat.pNumChannels); \
	if (args->hipTexRefGetFormat.pNumChannels != NULL) { \
		printf(" -> %d\n", *args->hipTexRefGetFormat.pNumChannels); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference * texRef = N/A, try to update csv files\n"); \
};

//	void * shareableHandle (void*);
//	hipMemGenericAllocationHandle_t handle (unknown);
//	hipMemAllocationHandleType handleType (enum);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipMemExportToShareableHandle(args) { \
	printf("\tvoid * shareableHandle = %p", args->hipMemExportToShareableHandle.shareableHandle); \
	printf("\n"); \
	printf("\thipMemGenericAllocationHandle_t handle = N/A, try to update csv files\n"); \
	printf("\thipMemAllocationHandleType handleType = %d\n", args->hipMemExportToShareableHandle.handleType); \
	printf("\tunsigned long long flags = %llu\n", args->hipMemExportToShareableHandle.flags); \
};

//	enum hipTextureFilterMode * pfm (enum);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetFilterMode(args) { \
	printf("\tenum hipTextureFilterMode * pfm = %d\n", args->hipTexRefGetFilterMode.pfm); \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t node (unknown);
//	struct const hipHostNodeParams * pNodeParams ({
//		hipHostFn_t fn (void*);
//		void * userData (void*);
//	});
#define PROCESS_ARGS_hipGraphHostNodeSetParams(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\tstruct const hipHostNodeParams * pNodeParams = %p", args->hipGraphHostNodeSetParams.pNodeParams); \
	if (args->hipGraphHostNodeSetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipHostFn_t fn = %p", (*args->hipGraphHostNodeSetParams.pNodeParams).fn); \
		printf("\n"); \
		printf("\t\tvoid * userData = %p", (*args->hipGraphHostNodeSetParams.pNodeParams).userData); \
		printf("\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraph_t graph (unknown);
//	hipGraphNode_t * nodes (unknown);
//	size_t * numNodes (unsigned long*);
#define PROCESS_ARGS_hipGraphGetNodes(args) { \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t * nodes = N/A, try to update csv files\n"); \
	printf("\tsize_t * numNodes = %p", args->hipGraphGetNodes.numNodes); \
	if (args->hipGraphGetNodes.numNodes != NULL) { \
		printf(" -> %lu\n", *args->hipGraphGetNodes.numNodes); \
	} else { printf("\n"); }; \
};

//	hipDevice_t * device (int*);
#define PROCESS_ARGS_hipCtxGetDevice(args) { \
	printf("\thipDevice_t * device = %p", args->hipCtxGetDevice.device); \
	if (args->hipCtxGetDevice.device != NULL) { \
		printf(" -> %d\n", *args->hipCtxGetDevice.device); \
	} else { printf("\n"); }; \
};

//	void ** devPtr (void**);
//	const void * symbol (void*);
#define PROCESS_ARGS_hipGetSymbolAddress(args) { \
	printf("\tvoid ** devPtr = %p", args->hipGetSymbolAddress.devPtr); \
	if (args->hipGetSymbolAddress.devPtr != NULL) { \
		printf("-> %p", *args->hipGetSymbolAddress.devPtr); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tconst void * symbol = %p", args->hipGetSymbolAddress.symbol); \
	printf("\n"); \
};

//	hipStream_t stream (unknown);
//	hipStreamCaptureStatus * captureStatus_out (enum*);
//	unsigned long long * id_out (unsigned long long*);
//	hipGraph_t * graph_out (unknown);
//	const hipGraphNode_t ** dependencies_out (unknown);
//	size_t * numDependencies_out (unsigned long*);
#define PROCESS_ARGS_hipStreamGetCaptureInfo_v2(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\thipStreamCaptureStatus * captureStatus_out = %p", args->hipStreamGetCaptureInfo_v2.captureStatus_out); \
	if (args->hipStreamGetCaptureInfo_v2.captureStatus_out != NULL) { \
		printf(" -> %d\n", *args->hipStreamGetCaptureInfo_v2.captureStatus_out); \
	} else { printf("\n"); }; \
	printf("\tunsigned long long * id_out = %p", args->hipStreamGetCaptureInfo_v2.id_out); \
	if (args->hipStreamGetCaptureInfo_v2.id_out != NULL) { \
		printf(" -> %llu\n", *args->hipStreamGetCaptureInfo_v2.id_out); \
	} else { printf("\n"); }; \
	printf("\thipGraph_t * graph_out = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t ** dependencies_out = N/A, try to update csv files\n"); \
	printf("\tsize_t * numDependencies_out = %p", args->hipStreamGetCaptureInfo_v2.numDependencies_out); \
	if (args->hipStreamGetCaptureInfo_v2.numDependencies_out != NULL) { \
		printf(" -> %lu\n", *args->hipStreamGetCaptureInfo_v2.numDependencies_out); \
	} else { printf("\n"); }; \
};

//	size_t* size (unsigned long*);
//	const void * symbol (void*);
#define PROCESS_ARGS_hipGetSymbolSize(args) { \
	printf("\tsize_t* size = %p", args->hipGetSymbolSize.size); \
	if (args->hipGetSymbolSize.size != NULL) { \
		printf(" -> %lu\n", *args->hipGetSymbolSize.size); \
	} else { printf("\n"); }; \
	printf("\tconst void * symbol = %p", args->hipGetSymbolSize.symbol); \
	printf("\n"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t node (unknown);
//	struct const hipHostNodeParams * pNodeParams ({
//		hipHostFn_t fn (void*);
//		void * userData (void*);
//	});
#define PROCESS_ARGS_hipGraphExecHostNodeSetParams(args) { \
	printf("\thipGraphExec_t hGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\tstruct const hipHostNodeParams * pNodeParams = %p", args->hipGraphExecHostNodeSetParams.pNodeParams); \
	if (args->hipGraphExecHostNodeSetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipHostFn_t fn = %p", (*args->hipGraphExecHostNodeSetParams.pNodeParams).fn); \
		printf("\n"); \
		printf("\t\tvoid * userData = %p", (*args->hipGraphExecHostNodeSetParams.pNodeParams).userData); \
		printf("\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipMemPool_t mem_pool (unknown);
//	hipMemPoolAttr attr (enum);
//	void * value (void*);
#define PROCESS_ARGS_hipMemPoolSetAttribute(args) { \
	printf("\thipMemPool_t mem_pool = N/A, try to update csv files\n"); \
	printf("\thipMemPoolAttr attr = %d\n", args->hipMemPoolSetAttribute.attr); \
	printf("\tvoid * value = %p", args->hipMemPoolSetAttribute.value); \
	printf("\n"); \
};

//	int device (int);
//	hipMemPool_t mem_pool (unknown);
#define PROCESS_ARGS_hipDeviceSetMemPool(args) { \
	printf("\tint device = %d\n", args->hipDeviceSetMemPool.device); \
	printf("\thipMemPool_t mem_pool = N/A, try to update csv files\n"); \
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
	printf("\tstruct dim3 gridDim = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipConfigureCall.gridDim.x); \
	printf("\t\tuint32_t y = %u\n", args->hipConfigureCall.gridDim.y); \
	printf("\t\tuint32_t z = %u\n", args->hipConfigureCall.gridDim.z); \
	printf("\t}\n"); \
	printf("\tstruct dim3 blockDim = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipConfigureCall.blockDim.x); \
	printf("\t\tuint32_t y = %u\n", args->hipConfigureCall.blockDim.y); \
	printf("\t\tuint32_t z = %u\n", args->hipConfigureCall.blockDim.z); \
	printf("\t}\n"); \
	printf("\tsize_t sharedMem = %lu\n", args->hipConfigureCall.sharedMem); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipMipmappedArray_t * pHandle (unknown);
//	HIP_ARRAY3D_DESCRIPTOR * pMipmappedArrayDesc (unknown);
//	unsigned int numMipmapLevels (unsigned int);
#define PROCESS_ARGS_hipMipmappedArrayCreate(args) { \
	printf("\thipMipmappedArray_t * pHandle = N/A, try to update csv files\n"); \
	printf("\tHIP_ARRAY3D_DESCRIPTOR * pMipmappedArrayDesc = N/A, try to update csv files\n"); \
	printf("\tunsigned int numMipmapLevels = %u\n", args->hipMipmappedArrayCreate.numMipmapLevels); \
};

//	void * hostPtr (void*);
//	size_t sizeBytes (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostRegister(args) { \
	printf("\tvoid * hostPtr = %p", args->hipHostRegister.hostPtr); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipHostRegister.sizeBytes); \
	printf("\tunsigned int flags = %u\n", args->hipHostRegister.flags); \
};

//	const textureReference * tex (unknown);
//	hipArray_const_t array (unknown);
//	const hipChannelFormatDesc * desc (unknown);
#define PROCESS_ARGS_hipBindTextureToArray(args) { \
	printf("\tconst textureReference * tex = N/A, try to update csv files\n"); \
	printf("\thipArray_const_t array = N/A, try to update csv files\n"); \
	printf("\tconst hipChannelFormatDesc * desc = N/A, try to update csv files\n"); \
};

//	void ** ptr (void**);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMallocHost(args) { \
	printf("\tvoid ** ptr = %p", args->hipMallocHost.ptr); \
	if (args->hipMallocHost.ptr != NULL) { \
		printf("-> %p", *args->hipMallocHost.ptr); \
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
	printf("\tint * numBlocks = %p", args->hipOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks); \
	if (args->hipOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks != NULL) { \
		printf(" -> %d\n", *args->hipOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks); \
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
	printf("\tint * pi = %p", args->hipDeviceGetAttribute.pi); \
	if (args->hipDeviceGetAttribute.pi != NULL) { \
		printf(" -> %d\n", *args->hipDeviceGetAttribute.pi); \
	} else { printf("\n"); }; \
	printf("\thipDeviceAttribute_t attr = %d\n", args->hipDeviceGetAttribute.attr); \
	printf("\tint deviceId = %d\n", args->hipDeviceGetAttribute.deviceId); \
};

//	hipDevice_t dev (int);
#define PROCESS_ARGS_hipDevicePrimaryCtxReset(args) { \
	printf("\thipDevice_t dev = %d\n", args->hipDevicePrimaryCtxReset.dev); \
};

//	size_t * ByteOffset (unsigned long*);
//	textureReference * texRef (unknown);
//	hipDeviceptr_t dptr (unknown);
//	size_t bytes (unsigned long);
#define PROCESS_ARGS_hipTexRefSetAddress(args) { \
	printf("\tsize_t * ByteOffset = %p", args->hipTexRefSetAddress.ByteOffset); \
	if (args->hipTexRefSetAddress.ByteOffset != NULL) { \
		printf(" -> %lu\n", *args->hipTexRefSetAddress.ByteOffset); \
	} else { printf("\n"); }; \
	printf("\ttextureReference * texRef = N/A, try to update csv files\n"); \
	printf("\thipDeviceptr_t dptr = N/A, try to update csv files\n"); \
	printf("\tsize_t bytes = %lu\n", args->hipTexRefSetAddress.bytes); \
};

//	void ** devPtr (void**);
//	size_t* size (unsigned long*);
//	hipGraphicsResource_t resource (unknown);
#define PROCESS_ARGS_hipGraphicsResourceGetMappedPointer(args) { \
	printf("\tvoid ** devPtr = %p", args->hipGraphicsResourceGetMappedPointer.devPtr); \
	if (args->hipGraphicsResourceGetMappedPointer.devPtr != NULL) { \
		printf("-> %p", *args->hipGraphicsResourceGetMappedPointer.devPtr); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t* size = %p", args->hipGraphicsResourceGetMappedPointer.size); \
	if (args->hipGraphicsResourceGetMappedPointer.size != NULL) { \
		printf(" -> %lu\n", *args->hipGraphicsResourceGetMappedPointer.size); \
	} else { printf("\n"); }; \
	printf("\thipGraphicsResource_t resource = N/A, try to update csv files\n"); \
};

//	hipSharedMemConfig config (enum);
#define PROCESS_ARGS_hipCtxSetSharedMemConfig(args) { \
	printf("\thipSharedMemConfig config = %d\n", args->hipCtxSetSharedMemConfig.config); \
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
	printf("\thipGraphNode_t hNode = N/A, try to update csv files\n"); \
	printf("\tstruct hipExternalSemaphoreSignalNodeParams * params_out = %p", args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out); \
	if (args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipExternalSemaphore_t * extSemArray = %p", (*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).extSemArray); \
		if ((*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).extSemArray != NULL) { \
			printf("-> %p", *(*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).extSemArray); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tstruct const hipExternalSemaphoreSignalParams * paramsArray = %p", (*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).paramsArray); \
		if ((*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).paramsArray != NULL) { \
			printf(" -> {\n"); \
			printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1136:3) params = N/A, try to update csv files\n"); \
			printf("\t\t\tunsigned int flags = %u\n", (*(*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).paramsArray).flags); \
			printf("\t\t\tunsigned int[16] reserved = %p", (*(*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).paramsArray).reserved); \
			if ((*(*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).paramsArray).reserved != NULL) { \
				printf(" -> %u\n", *(*(*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).paramsArray).reserved); \
			} else { printf("\n"); }; \
			printf("\t\t}\n"); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int numExtSems = %u\n", (*args->hipGraphExternalSemaphoresSignalNodeGetParams.params_out).numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipArrayDestroy(args) { \
	printf("\thipArray_t array = N/A, try to update csv files\n"); \
};

//	void * dev_ptr (void*);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipFreeAsync(args) { \
	printf("\tvoid * dev_ptr = %p", args->hipFreeAsync.dev_ptr); \
	printf("\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	HIP_ARRAY3D_DESCRIPTOR * pArrayDescriptor (unknown);
//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipArray3DGetDescriptor(args) { \
	printf("\tHIP_ARRAY3D_DESCRIPTOR * pArrayDescriptor = N/A, try to update csv files\n"); \
	printf("\thipArray_t array = N/A, try to update csv files\n"); \
};

//	char * pciBusId (char*);
//	int len (int);
//	int device (int);
#define PROCESS_ARGS_hipDeviceGetPCIBusId(args) { \
	printf("\tchar * pciBusId = %p", args->hipDeviceGetPCIBusId.pciBusId); \
	if (args->hipDeviceGetPCIBusId.pciBusId != NULL) { \
		printf(" -> %c\n", *args->hipDeviceGetPCIBusId.pciBusId); \
	} else { printf("\n"); }; \
	printf("\tint len = %d\n", args->hipDeviceGetPCIBusId.len); \
	printf("\tint device = %d\n", args->hipDeviceGetPCIBusId.device); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	void * dev_ptr (void*);
#define PROCESS_ARGS_hipGraphAddMemFreeNode(args) { \
	printf("\thipGraphNode_t * pGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddMemFreeNode.numDependencies); \
	printf("\tvoid * dev_ptr = %p", args->hipGraphAddMemFreeNode.dev_ptr); \
	printf("\n"); \
};

//	hipArray_t * array (unknown);
//	const HIP_ARRAY3D_DESCRIPTOR * pAllocateArray (unknown);
#define PROCESS_ARGS_hipArray3DCreate(args) { \
	printf("\thipArray_t * array = N/A, try to update csv files\n"); \
	printf("\tconst HIP_ARRAY3D_DESCRIPTOR * pAllocateArray = N/A, try to update csv files\n"); \
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
	printf("\thipGraphNode_t hNode = N/A, try to update csv files\n"); \
	printf("\tstruct const hipExternalSemaphoreSignalNodeParams * nodeParams = %p", args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams); \
	if (args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipExternalSemaphore_t * extSemArray = %p", (*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).extSemArray); \
		if ((*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).extSemArray != NULL) { \
			printf("-> %p", *(*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).extSemArray); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tstruct const hipExternalSemaphoreSignalParams * paramsArray = %p", (*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray); \
		if ((*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray != NULL) { \
			printf(" -> {\n"); \
			printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1136:3) params = N/A, try to update csv files\n"); \
			printf("\t\t\tunsigned int flags = %u\n", (*(*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).flags); \
			printf("\t\t\tunsigned int[16] reserved = %p", (*(*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).reserved); \
			if ((*(*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).reserved != NULL) { \
				printf(" -> %u\n", *(*(*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).reserved); \
			} else { printf("\n"); }; \
			printf("\t\t}\n"); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int numExtSems = %u\n", (*args->hipGraphExternalSemaphoresSignalNodeSetParams.nodeParams).numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	float * pBorderColor (float*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetBorderColor(args) { \
	printf("\tfloat * pBorderColor = %p", args->hipTexRefGetBorderColor.pBorderColor); \
	if (args->hipTexRefGetBorderColor.pBorderColor != NULL) { \
		printf(" -> %f\n", *args->hipTexRefGetBorderColor.pBorderColor); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	hipDeviceptr_t * dptr (unknown);
//	size_t* bytes (unsigned long*);
//	hipModule_t hmod (unknown);
//	const char * name (char*);
#define PROCESS_ARGS_hipModuleGetGlobal(args) { \
	printf("\thipDeviceptr_t * dptr = N/A, try to update csv files\n"); \
	printf("\tsize_t* bytes = %p", args->hipModuleGetGlobal.bytes); \
	if (args->hipModuleGetGlobal.bytes != NULL) { \
		printf(" -> %lu\n", *args->hipModuleGetGlobal.bytes); \
	} else { printf("\n"); }; \
	printf("\thipModule_t hmod = N/A, try to update csv files\n"); \
	printf("\tconst char * name = %p", args->hipModuleGetGlobal.name); \
	if (args->hipModuleGetGlobal.name != NULL) { \
		printf(" -> %c\n", *args->hipModuleGetGlobal.name); \
	} else { printf("\n"); }; \
};

//	hipMipmappedArray_t * mipmappedArray (unknown);
//	const struct hipChannelFormatDesc * desc (unknown);
//	struct hipExtent extent (unknown);
//	unsigned int numLevels (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMallocMipmappedArray(args) { \
	printf("\thipMipmappedArray_t * mipmappedArray = N/A, try to update csv files\n"); \
	printf("\tconst struct hipChannelFormatDesc * desc = N/A, try to update csv files\n"); \
	printf("\tstruct hipExtent extent = N/A, try to update csv files\n"); \
	printf("\tunsigned int numLevels = %u\n", args->hipMallocMipmappedArray.numLevels); \
	printf("\tunsigned int flags = %u\n", args->hipMallocMipmappedArray.flags); \
};


#define PROCESS_ARGS_hipProfilerStart(args) { \
\
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t node (unknown);
//	hipMemcpy3DParms * pNodeParams (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParams(args) { \
	printf("\thipGraphExec_t hGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\thipMemcpy3DParms * pNodeParams = N/A, try to update csv files\n"); \
};

//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipEventSynchronize(args) { \
	printf("\thipEvent_t event = N/A, try to update csv files\n"); \
};

//	struct hipMemPoolPtrExportData * export_data ({
//		unsigned char[64] reserved (unsigned char*);
//	});
//	void * dev_ptr (void*);
#define PROCESS_ARGS_hipMemPoolExportPointer(args) { \
	printf("\tstruct hipMemPoolPtrExportData * export_data = %p", args->hipMemPoolExportPointer.export_data); \
	if (args->hipMemPoolExportPointer.export_data != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tunsigned char[64] reserved = %p", (*args->hipMemPoolExportPointer.export_data).reserved); \
		if ((*args->hipMemPoolExportPointer.export_data).reserved != NULL) { \
			printf(" -> %hhu\n", *(*args->hipMemPoolExportPointer.export_data).reserved); \
		} else { printf("\n"); }; \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tvoid * dev_ptr = %p", args->hipMemPoolExportPointer.dev_ptr); \
	printf("\n"); \
};

//	void * hostPtr (void*);
#define PROCESS_ARGS_hipHostUnregister(args) { \
	printf("\tvoid * hostPtr = %p", args->hipHostUnregister.hostPtr); \
	printf("\n"); \
};

//	void * dst (void*);
//	size_t pitch (unsigned long);
//	int value (int);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
#define PROCESS_ARGS_hipMemset2D(args) { \
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
	printf("\tvoid ** ptr = %p", args->hipMemAddressReserve.ptr); \
	if (args->hipMemAddressReserve.ptr != NULL) { \
		printf("-> %p", *args->hipMemAddressReserve.ptr); \
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
	printf("\tconst void * func = %p", args->hipFuncSetSharedMemConfig.func); \
	printf("\n"); \
	printf("\thipSharedMemConfig config = %d\n", args->hipFuncSetSharedMemConfig.config); \
};

//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipDestroyTextureObject(args) { \
	printf("\thipTextureObject_t textureObject = N/A, try to update csv files\n"); \
};

//	textureReference* texRef (unknown);
//	unsigned int maxAniso (unsigned int);
#define PROCESS_ARGS_hipTexRefSetMaxAnisotropy(args) { \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tunsigned int maxAniso = %u\n", args->hipTexRefSetMaxAnisotropy.maxAniso); \
};

//	textureReference* texRef (unknown);
//	const HIP_ARRAY_DESCRIPTOR * desc (unknown);
//	hipDeviceptr_t dptr (unknown);
//	size_t Pitch (unsigned long);
#define PROCESS_ARGS_hipTexRefSetAddress2D(args) { \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tconst HIP_ARRAY_DESCRIPTOR * desc = N/A, try to update csv files\n"); \
	printf("\thipDeviceptr_t dptr = N/A, try to update csv files\n"); \
	printf("\tsize_t Pitch = %lu\n", args->hipTexRefSetAddress2D.Pitch); \
};

//	int * deviceId (int*);
#define PROCESS_ARGS_hipGetDevice(args) { \
	printf("\tint * deviceId = %p", args->hipGetDevice.deviceId); \
	if (args->hipGetDevice.deviceId != NULL) { \
		printf(" -> %d\n", *args->hipGetDevice.deviceId); \
	} else { printf("\n"); }; \
};

//	int device (int);
//	hipGraphMemAttributeType attr (enum);
//	void * value (void*);
#define PROCESS_ARGS_hipDeviceGetGraphMemAttribute(args) { \
	printf("\tint device = %d\n", args->hipDeviceGetGraphMemAttribute.device); \
	printf("\thipGraphMemAttributeType attr = %d\n", args->hipDeviceGetGraphMemAttribute.attr); \
	printf("\tvoid * value = %p", args->hipDeviceGetGraphMemAttribute.value); \
	printf("\n"); \
};

//	hipArray_t * array (unknown);
//	hipGraphicsResource_t resource (unknown);
//	unsigned int arrayIndex (unsigned int);
//	unsigned int mipLevel (unsigned int);
#define PROCESS_ARGS_hipGraphicsSubResourceGetMappedArray(args) { \
	printf("\thipArray_t * array = N/A, try to update csv files\n"); \
	printf("\thipGraphicsResource_t resource = N/A, try to update csv files\n"); \
	printf("\tunsigned int arrayIndex = %u\n", args->hipGraphicsSubResourceGetMappedArray.arrayIndex); \
	printf("\tunsigned int mipLevel = %u\n", args->hipGraphicsSubResourceGetMappedArray.mipLevel); \
};

//	hipGraphNode_t node (unknown);
//	const void * symbol (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParamsToSymbol(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\tconst void * symbol = %p", args->hipGraphMemcpyNodeSetParamsToSymbol.symbol); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipGraphMemcpyNodeSetParamsToSymbol.src); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipGraphMemcpyNodeSetParamsToSymbol.count); \
	printf("\tsize_t offset = %lu\n", args->hipGraphMemcpyNodeSetParamsToSymbol.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	hipStream_t * stream (unknown);
#define PROCESS_ARGS_hipStreamCreate(args) { \
	printf("\thipStream_t * stream = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t node (unknown);
//	hipGraphNode_t * pDependencies (unknown);
//	size_t* pNumDependencies (unsigned long*);
#define PROCESS_ARGS_hipGraphNodeGetDependencies(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t* pNumDependencies = %p", args->hipGraphNodeGetDependencies.pNumDependencies); \
	if (args->hipGraphNodeGetDependencies.pNumDependencies != NULL) { \
		printf(" -> %lu\n", *args->hipGraphNodeGetDependencies.pNumDependencies); \
	} else { printf("\n"); }; \
};

//	const textureReference* tex (unknown);
//	hipMipmappedArray_const_t mipmappedArray (unknown);
//	const hipChannelFormatDesc* desc (unknown);
#define PROCESS_ARGS_hipBindTextureToMipmappedArray(args) { \
	printf("\tconst textureReference* tex = N/A, try to update csv files\n"); \
	printf("\thipMipmappedArray_const_t mipmappedArray = N/A, try to update csv files\n"); \
	printf("\tconst hipChannelFormatDesc* desc = N/A, try to update csv files\n"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraph_t hGraph (unknown);
//	hipGraphNode_t * hErrorNode_out (unknown);
//	hipGraphExecUpdateResult * updateResult_out (enum*);
#define PROCESS_ARGS_hipGraphExecUpdate(args) { \
	printf("\thipGraphExec_t hGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraph_t hGraph = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t * hErrorNode_out = N/A, try to update csv files\n"); \
	printf("\thipGraphExecUpdateResult * updateResult_out = %p", args->hipGraphExecUpdate.updateResult_out); \
	if (args->hipGraphExecUpdate.updateResult_out != NULL) { \
		printf(" -> %d\n", *args->hipGraphExecUpdate.updateResult_out); \
	} else { printf("\n"); }; \
};

//	size_t* bytes (unsigned long*);
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceTotalMem(args) { \
	printf("\tsize_t* bytes = %p", args->hipDeviceTotalMem.bytes); \
	if (args->hipDeviceTotalMem.bytes != NULL) { \
		printf(" -> %lu\n", *args->hipDeviceTotalMem.bytes); \
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
	printf("\tvoid * dst = %p", args->hipMemcpyFromArray.dst); \
	printf("\n"); \
	printf("\thipArray_const_t srcArray = N/A, try to update csv files\n"); \
	printf("\tsize_t wOffset = %lu\n", args->hipMemcpyFromArray.wOffset); \
	printf("\tsize_t hOffset = %lu\n", args->hipMemcpyFromArray.hOffset); \
	printf("\tsize_t count = %lu\n", args->hipMemcpyFromArray.count); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	hipEvent_t * event (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipEventCreateWithFlags(args) { \
	printf("\thipEvent_t * event = N/A, try to update csv files\n"); \
	printf("\tunsigned int flags = %u\n", args->hipEventCreateWithFlags.flags); \
};

//	hipFuncCache_t * cacheConfig (enum*);
#define PROCESS_ARGS_hipDeviceGetCacheConfig(args) { \
	printf("\thipFuncCache_t * cacheConfig = %p", args->hipDeviceGetCacheConfig.cacheConfig); \
	if (args->hipDeviceGetCacheConfig.cacheConfig != NULL) { \
		printf(" -> %d\n", *args->hipDeviceGetCacheConfig.cacheConfig); \
	} else { printf("\n"); }; \
};

//	int * driverVersion (int*);
#define PROCESS_ARGS_hipDriverGetVersion(args) { \
	printf("\tint * driverVersion = %p", args->hipDriverGetVersion.driverVersion); \
	if (args->hipDriverGetVersion.driverVersion != NULL) { \
		printf(" -> %d\n", *args->hipDriverGetVersion.driverVersion); \
	} else { printf("\n"); }; \
};

//	hipGraphNode_t node (unknown);
//	void * dst (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParams1D(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
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
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tfloat minMipMapLevelClamp = %f\n", args->hipTexRefSetMipmapLevelClamp.minMipMapLevelClamp); \
	printf("\tfloat maxMipMapLevelClamp = %f\n", args->hipTexRefSetMipmapLevelClamp.maxMipMapLevelClamp); \
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
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\tstruct hipMemAllocNodeParams * pNodeParams = %p", args->hipGraphMemAllocNodeGetParams.pNodeParams); \
	if (args->hipGraphMemAllocNodeGetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tstruct hipMemPoolProps poolProps = {\n"); \
		printf("\t\t\thipMemAllocationType allocType = %d\n", ((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).allocType); \
		printf("\t\t\thipMemAllocationHandleType handleTypes = %d\n", ((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).handleTypes); \
		printf("\t\t\tstruct hipMemLocation location = {\n"); \
		printf("\t\t\t\thipMemLocationType type = %d\n", (((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).location).type); \
		printf("\t\t\t\tint id = %d\n", (((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).location).id); \
		printf("\t\t\t}\n"); \
		printf("\t\t\tvoid * win32SecurityAttributes = %p", ((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).win32SecurityAttributes); \
		printf("\n"); \
		printf("\t\t\tunsigned char[64] reserved = %p", ((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).reserved); \
		if (((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).reserved != NULL) { \
			printf(" -> %hhu\n", *((*args->hipGraphMemAllocNodeGetParams.pNodeParams).poolProps).reserved); \
		} else { printf("\n"); }; \
		printf("\t\t}\n"); \
		printf("\t\tstruct const hipMemAccessDesc * accessDescs = %p", (*args->hipGraphMemAllocNodeGetParams.pNodeParams).accessDescs); \
		if ((*args->hipGraphMemAllocNodeGetParams.pNodeParams).accessDescs != NULL) { \
			printf(" -> {\n"); \
			printf("\t\t\tstruct hipMemLocation location = {\n"); \
			printf("\t\t\t\thipMemLocationType type = %d\n", ((*(*args->hipGraphMemAllocNodeGetParams.pNodeParams).accessDescs).location).type); \
			printf("\t\t\t\tint id = %d\n", ((*(*args->hipGraphMemAllocNodeGetParams.pNodeParams).accessDescs).location).id); \
			printf("\t\t\t}\n"); \
			printf("\t\t\thipMemAccessFlags flags = %d\n", (*(*args->hipGraphMemAllocNodeGetParams.pNodeParams).accessDescs).flags); \
			printf("\t\t}\n"); \
		} else { printf("\n"); }; \
		printf("\t\tint accessDescCount = %d\n", (*args->hipGraphMemAllocNodeGetParams.pNodeParams).accessDescCount); \
		printf("\t\tint bytesize = %d\n", (*args->hipGraphMemAllocNodeGetParams.pNodeParams).bytesize); \
		printf("\t\tvoid * dptr = %p", (*args->hipGraphMemAllocNodeGetParams.pNodeParams).dptr); \
		printf("\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectDestroy(args) { \
	printf("\thipTextureObject_t texObject = N/A, try to update csv files\n"); \
};

//	hipStream_t * stream (unknown);
//	uint32_t cuMaskSize (unsigned int);
//	const uint32_t * cuMask (unsigned int*);
#define PROCESS_ARGS_hipExtStreamCreateWithCUMask(args) { \
	printf("\thipStream_t * stream = N/A, try to update csv files\n"); \
	printf("\tuint32_t cuMaskSize = %u\n", args->hipExtStreamCreateWithCUMask.cuMaskSize); \
	printf("\tconst uint32_t * cuMask = %p", args->hipExtStreamCreateWithCUMask.cuMask); \
	if (args->hipExtStreamCreateWithCUMask.cuMask != NULL) { \
		printf(" -> %u\n", *args->hipExtStreamCreateWithCUMask.cuMask); \
	} else { printf("\n"); }; \
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
	printf("\tstruct dim3 * gridDim = %p", args->__hipPopCallConfiguration.gridDim); \
	if (args->__hipPopCallConfiguration.gridDim != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t x = %u\n", (*args->__hipPopCallConfiguration.gridDim).x); \
		printf("\t\tuint32_t y = %u\n", (*args->__hipPopCallConfiguration.gridDim).y); \
		printf("\t\tuint32_t z = %u\n", (*args->__hipPopCallConfiguration.gridDim).z); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tstruct dim3 * blockDim = %p", args->__hipPopCallConfiguration.blockDim); \
	if (args->__hipPopCallConfiguration.blockDim != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tuint32_t x = %u\n", (*args->__hipPopCallConfiguration.blockDim).x); \
		printf("\t\tuint32_t y = %u\n", (*args->__hipPopCallConfiguration.blockDim).y); \
		printf("\t\tuint32_t z = %u\n", (*args->__hipPopCallConfiguration.blockDim).z); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t * sharedMem = %p", args->__hipPopCallConfiguration.sharedMem); \
	if (args->__hipPopCallConfiguration.sharedMem != NULL) { \
		printf(" -> %lu\n", *args->__hipPopCallConfiguration.sharedMem); \
	} else { printf("\n"); }; \
	printf("\thipStream_t * stream = N/A, try to update csv files\n"); \
};

//	void * data (void*);
//	size_t data_size (unsigned long);
//	hipMemRangeAttribute attribute (enum);
//	const void * dev_ptr (void*);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemRangeGetAttribute(args) { \
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
//	hipMemGenericAllocationHandle_t handle (unknown);
//	unsigned long long flags (unsigned long long);
#define PROCESS_ARGS_hipMemMap(args) { \
	printf("\tvoid * ptr = %p", args->hipMemMap.ptr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hipMemMap.size); \
	printf("\tsize_t offset = %lu\n", args->hipMemMap.offset); \
	printf("\thipMemGenericAllocationHandle_t handle = N/A, try to update csv files\n"); \
	printf("\tunsigned long long flags = %llu\n", args->hipMemMap.flags); \
};

//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipStreamSynchronize(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipUserObject_t * object_out (unknown);
//	void * ptr (void*);
//	hipHostFn_t destroy (void*);
//	unsigned int initialRefcount (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipUserObjectCreate(args) { \
	printf("\thipUserObject_t * object_out = N/A, try to update csv files\n"); \
	printf("\tvoid * ptr = %p", args->hipUserObjectCreate.ptr); \
	printf("\n"); \
	printf("\thipHostFn_t destroy = %p", args->hipUserObjectCreate.destroy); \
	printf("\n"); \
	printf("\tunsigned int initialRefcount = %u\n", args->hipUserObjectCreate.initialRefcount); \
	printf("\tunsigned int flags = %u\n", args->hipUserObjectCreate.flags); \
};

//	hipArray_t * levelArray (unknown);
//	hipMipmappedArray_const_t mipmappedArray (unknown);
//	unsigned int level (unsigned int);
#define PROCESS_ARGS_hipGetMipmappedArrayLevel(args) { \
	printf("\thipArray_t * levelArray = N/A, try to update csv files\n"); \
	printf("\thipMipmappedArray_const_t mipmappedArray = N/A, try to update csv files\n"); \
	printf("\tunsigned int level = %u\n", args->hipGetMipmappedArrayLevel.level); \
};

//	hipDeviceptr_t dst (unknown);
//	void * src (void*);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemcpyHtoD(args) { \
	printf("\thipDeviceptr_t dst = N/A, try to update csv files\n"); \
	printf("\tvoid * src = %p", args->hipMemcpyHtoD.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyHtoD.sizeBytes); \
};

//	hipDeviceptr_t * pbase (unknown);
//	size_t * psize (unsigned long*);
//	hipDeviceptr_t dptr (unknown);
#define PROCESS_ARGS_hipMemGetAddressRange(args) { \
	printf("\thipDeviceptr_t * pbase = N/A, try to update csv files\n"); \
	printf("\tsize_t * psize = %p", args->hipMemGetAddressRange.psize); \
	if (args->hipMemGetAddressRange.psize != NULL) { \
		printf(" -> %lu\n", *args->hipMemGetAddressRange.psize); \
	} else { printf("\n"); }; \
	printf("\thipDeviceptr_t dptr = N/A, try to update csv files\n"); \
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
	printf("\thipGraphNode_t * pGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
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
	printf("\tvoid * ptr = %p", args->hipMemPtrGetInfo.ptr); \
	printf("\n"); \
	printf("\tsize_t* size = %p", args->hipMemPtrGetInfo.size); \
	if (args->hipMemPtrGetInfo.size != NULL) { \
		printf(" -> %lu\n", *args->hipMemPtrGetInfo.size); \
	} else { printf("\n"); }; \
};

//	textureReference* texRef (unknown);
//	struct hipMipmappedArray * mipmappedArray (unknown);
//	unsigned int Flags (unsigned int);
#define PROCESS_ARGS_hipTexRefSetMipmappedArray(args) { \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tstruct hipMipmappedArray * mipmappedArray = N/A, try to update csv files\n"); \
	printf("\tunsigned int Flags = %u\n", args->hipTexRefSetMipmappedArray.Flags); \
};

//	hipExternalSemaphore_t * extSem_out (void**);
//	struct const hipExternalSemaphoreHandleDesc * semHandleDesc ({
//		hipExternalSemaphoreHandleType type (enum);
//		union (unnamed union at ./input/hip_runtime_api.h:1123:3) handle (unknown);
//		unsigned int flags (unsigned int);
//		unsigned int[16] reserved (unsigned int*);
//	});
#define PROCESS_ARGS_hipImportExternalSemaphore(args) { \
	printf("\thipExternalSemaphore_t * extSem_out = %p", args->hipImportExternalSemaphore.extSem_out); \
	if (args->hipImportExternalSemaphore.extSem_out != NULL) { \
		printf("-> %p", *args->hipImportExternalSemaphore.extSem_out); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tstruct const hipExternalSemaphoreHandleDesc * semHandleDesc = %p", args->hipImportExternalSemaphore.semHandleDesc); \
	if (args->hipImportExternalSemaphore.semHandleDesc != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipExternalSemaphoreHandleType type = %d\n", (*args->hipImportExternalSemaphore.semHandleDesc).type); \
		printf("\t\tunion (unnamed union at ./input/hip_runtime_api.h:1123:3) handle = N/A, try to update csv files\n"); \
		printf("\t\tunsigned int flags = %u\n", (*args->hipImportExternalSemaphore.semHandleDesc).flags); \
		printf("\t\tunsigned int[16] reserved = %p", (*args->hipImportExternalSemaphore.semHandleDesc).reserved); \
		if ((*args->hipImportExternalSemaphore.semHandleDesc).reserved != NULL) { \
			printf(" -> %u\n", *(*args->hipImportExternalSemaphore.semHandleDesc).reserved); \
		} else { printf("\n"); }; \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipStream_t stream (unknown);
//	hipEvent_t event (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamWaitEvent(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\thipEvent_t event = N/A, try to update csv files\n"); \
	printf("\tunsigned int flags = %u\n", args->hipStreamWaitEvent.flags); \
};

//	int * count (int*);
#define PROCESS_ARGS_hipGetDeviceCount(args) { \
	printf("\tint * count = %p", args->hipGetDeviceCount.count); \
	if (args->hipGetDeviceCount.count != NULL) { \
		printf(" -> %d\n", *args->hipGetDeviceCount.count); \
	} else { printf("\n"); }; \
};

//	hipGraphNode_t hSrc (unknown);
//	hipGraphNode_t hDst (unknown);
#define PROCESS_ARGS_hipGraphKernelNodeCopyAttributes(args) { \
	printf("\thipGraphNode_t hSrc = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t hDst = N/A, try to update csv files\n"); \
};

//	hipExternalSemaphore_t extSem (void*);
#define PROCESS_ARGS_hipDestroyExternalSemaphore(args) { \
	printf("\thipExternalSemaphore_t extSem = %p", args->hipDestroyExternalSemaphore.extSem); \
	printf("\n"); \
};

//	hipGraphNode_t node (unknown);
//	const hipMemcpy3DParms* pNodeParams (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParams(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\tconst hipMemcpy3DParms* pNodeParams = N/A, try to update csv files\n"); \
};

//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipStreamQuery(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
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
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\tstruct const hipMemsetParams * pNodeParams = %p", args->hipGraphMemsetNodeSetParams.pNodeParams); \
	if (args->hipGraphMemsetNodeSetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tvoid * dst = %p", (*args->hipGraphMemsetNodeSetParams.pNodeParams).dst); \
		printf("\n"); \
		printf("\t\tunsigned int elementSize = %u\n", (*args->hipGraphMemsetNodeSetParams.pNodeParams).elementSize); \
		printf("\t\tint height = %d\n", (*args->hipGraphMemsetNodeSetParams.pNodeParams).height); \
		printf("\t\tint pitch = %d\n", (*args->hipGraphMemsetNodeSetParams.pNodeParams).pitch); \
		printf("\t\tunsigned int value = %u\n", (*args->hipGraphMemsetNodeSetParams.pNodeParams).value); \
		printf("\t\tint width = %d\n", (*args->hipGraphMemsetNodeSetParams.pNodeParams).width); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	int * runtimeVersion (int*);
#define PROCESS_ARGS_hipRuntimeGetVersion(args) { \
	printf("\tint * runtimeVersion = %p", args->hipRuntimeGetVersion.runtimeVersion); \
	if (args->hipRuntimeGetVersion.runtimeVersion != NULL) { \
		printf(" -> %d\n", *args->hipRuntimeGetVersion.runtimeVersion); \
	} else { printf("\n"); }; \
};

//	HIP_ARRAY_DESCRIPTOR* pArrayDescriptor (unknown);
//	hipArray_t array (unknown);
#define PROCESS_ARGS_hipArrayGetDescriptor(args) { \
	printf("\tHIP_ARRAY_DESCRIPTOR* pArrayDescriptor = N/A, try to update csv files\n"); \
	printf("\thipArray_t array = N/A, try to update csv files\n"); \
};

//	hipDeviceptr_t dst (unknown);
//	int value (int);
//	size_t count (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemsetD32Async(args) { \
	printf("\thipDeviceptr_t dst = N/A, try to update csv files\n"); \
	printf("\tint value = %d\n", args->hipMemsetD32Async.value); \
	printf("\tsize_t count = %lu\n", args->hipMemsetD32Async.count); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipSharedMemConfig * pConfig (enum*);
#define PROCESS_ARGS_hipCtxGetSharedMemConfig(args) { \
	printf("\thipSharedMemConfig * pConfig = %p", args->hipCtxGetSharedMemConfig.pConfig); \
	if (args->hipCtxGetSharedMemConfig.pConfig != NULL) { \
		printf(" -> %d\n", *args->hipCtxGetSharedMemConfig.pConfig); \
	} else { printf("\n"); }; \
};

//	hipModule_t * module (unknown);
//	const void * image (void*);
//	unsigned int numOptions (unsigned int);
//	hipJitOption * options (enum*);
//	void ** optionValues (void**);
#define PROCESS_ARGS_hipModuleLoadDataEx(args) { \
	printf("\thipModule_t * module = N/A, try to update csv files\n"); \
	printf("\tconst void * image = %p", args->hipModuleLoadDataEx.image); \
	printf("\n"); \
	printf("\tunsigned int numOptions = %u\n", args->hipModuleLoadDataEx.numOptions); \
	printf("\thipJitOption * options = %p", args->hipModuleLoadDataEx.options); \
	if (args->hipModuleLoadDataEx.options != NULL) { \
		printf(" -> %d\n", *args->hipModuleLoadDataEx.options); \
	} else { printf("\n"); }; \
	printf("\tvoid ** optionValues = %p", args->hipModuleLoadDataEx.optionValues); \
	if (args->hipModuleLoadDataEx.optionValues != NULL) { \
		printf("-> %p", *args->hipModuleLoadDataEx.optionValues); \
		printf("\n"); \
	} else { printf("\n"); }; \
};

//	void * shared_handle (void*);
//	hipMemPool_t mem_pool (unknown);
//	hipMemAllocationHandleType handle_type (enum);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipMemPoolExportToShareableHandle(args) { \
	printf("\tvoid * shared_handle = %p", args->hipMemPoolExportToShareableHandle.shared_handle); \
	printf("\n"); \
	printf("\thipMemPool_t mem_pool = N/A, try to update csv files\n"); \
	printf("\thipMemAllocationHandleType handle_type = %d\n", args->hipMemPoolExportToShareableHandle.handle_type); \
	printf("\tunsigned int flags = %u\n", args->hipMemPoolExportToShareableHandle.flags); \
};

//	void ** dev_ptr (void**);
//	size_t size (unsigned long);
//	hipMemPool_t mem_pool (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMallocFromPoolAsync(args) { \
	printf("\tvoid ** dev_ptr = %p", args->hipMallocFromPoolAsync.dev_ptr); \
	if (args->hipMallocFromPoolAsync.dev_ptr != NULL) { \
		printf("-> %p", *args->hipMallocFromPoolAsync.dev_ptr); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipMallocFromPoolAsync.size); \
	printf("\thipMemPool_t mem_pool = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	int deviceId (int);
#define PROCESS_ARGS_hipSetDevice(args) { \
	printf("\tint deviceId = %d\n", args->hipSetDevice.deviceId); \
};

//	void ** dev_ptr (void**);
//	size_t size (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMallocAsync(args) { \
	printf("\tvoid ** dev_ptr = %p", args->hipMallocAsync.dev_ptr); \
	if (args->hipMallocAsync.dev_ptr != NULL) { \
		printf("-> %p", *args->hipMallocAsync.dev_ptr); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t size = %lu\n", args->hipMallocAsync.size); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipDevice_t * device (int*);
//	int ordinal (int);
#define PROCESS_ARGS_hipDeviceGet(args) { \
	printf("\thipDevice_t * device = %p", args->hipDeviceGet.device); \
	if (args->hipDeviceGet.device != NULL) { \
		printf(" -> %d\n", *args->hipDeviceGet.device); \
	} else { printf("\n"); }; \
	printf("\tint ordinal = %d\n", args->hipDeviceGet.ordinal); \
};

//	void * dst (void*);
//	int value (int);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemsetAsync(args) { \
	printf("\tvoid * dst = %p", args->hipMemsetAsync.dst); \
	printf("\n"); \
	printf("\tint value = %d\n", args->hipMemsetAsync.value); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemsetAsync.sizeBytes); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
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
	printf("\tvoid * ptr = %p", args->hipMemSetAccess.ptr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hipMemSetAccess.size); \
	printf("\tstruct const hipMemAccessDesc * desc = %p", args->hipMemSetAccess.desc); \
	if (args->hipMemSetAccess.desc != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tstruct hipMemLocation location = {\n"); \
		printf("\t\t\thipMemLocationType type = %d\n", ((*args->hipMemSetAccess.desc).location).type); \
		printf("\t\t\tint id = %d\n", ((*args->hipMemSetAccess.desc).location).id); \
		printf("\t\t}\n"); \
		printf("\t\thipMemAccessFlags flags = %d\n", (*args->hipMemSetAccess.desc).flags); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t count = %lu\n", args->hipMemSetAccess.count); \
};

//	hipDeviceptr_t dest (unknown);
//	int value (int);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemsetD32(args) { \
	printf("\thipDeviceptr_t dest = N/A, try to update csv files\n"); \
	printf("\tint value = %d\n", args->hipMemsetD32.value); \
	printf("\tsize_t count = %lu\n", args->hipMemsetD32.count); \
};

//	unsigned int * flags (unsigned int*);
#define PROCESS_ARGS_hipGetDeviceFlags(args) { \
	printf("\tunsigned int * flags = %p", args->hipGetDeviceFlags.flags); \
	if (args->hipGetDeviceFlags.flags != NULL) { \
		printf(" -> %u\n", *args->hipGetDeviceFlags.flags); \
	} else { printf("\n"); }; \
};

//	int * numBlocks (int*);
//	const void * f (void*);
//	int blockSize (int);
//	size_t dynSharedMemPerBlk (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(args) { \
	printf("\tint * numBlocks = %p", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks); \
	if (args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks != NULL) { \
		printf(" -> %d\n", *args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks); \
	} else { printf("\n"); }; \
	printf("\tconst void * f = %p", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.f); \
	printf("\n"); \
	printf("\tint blockSize = %d\n", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.blockSize); \
	printf("\tsize_t dynSharedMemPerBlk = %lu\n", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.dynSharedMemPerBlk); \
	printf("\tunsigned int flags = %u\n", args->hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.flags); \
};

//	struct hipUUID * uuid ({
//		char[16] bytes (char*);
//	});
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceGetUuid(args) { \
	printf("\tstruct hipUUID * uuid = %p", args->hipDeviceGetUuid.uuid); \
	if (args->hipDeviceGetUuid.uuid != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tchar[16] bytes = %p", (*args->hipDeviceGetUuid.uuid).bytes); \
		if ((*args->hipDeviceGetUuid.uuid).bytes != NULL) { \
			printf(" -> %c\n", *(*args->hipDeviceGetUuid.uuid).bytes); \
		} else { printf("\n"); }; \
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
	printf("\thipChannelFormatDesc * desc = N/A, try to update csv files\n"); \
	printf("\thipExtent * extent = N/A, try to update csv files\n"); \
	printf("\tunsigned int * flags = %p", args->hipArrayGetInfo.flags); \
	if (args->hipArrayGetInfo.flags != NULL) { \
		printf(" -> %u\n", *args->hipArrayGetInfo.flags); \
	} else { printf("\n"); }; \
	printf("\thipArray_t array = N/A, try to update csv files\n"); \
};

//	hipUserObject_t object (unknown);
//	unsigned int count (unsigned int);
#define PROCESS_ARGS_hipUserObjectRetain(args) { \
	printf("\thipUserObject_t object = N/A, try to update csv files\n"); \
	printf("\tunsigned int count = %u\n", args->hipUserObjectRetain.count); \
};

//	int count (int);
//	hipGraphicsResource_t * resources (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipGraphicsMapResources(args) { \
	printf("\tint count = %d\n", args->hipGraphicsMapResources.count); \
	printf("\thipGraphicsResource_t * resources = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipDeviceptr_t dst (unknown);
//	void * src (void*);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyHtoDAsync(args) { \
	printf("\thipDeviceptr_t dst = N/A, try to update csv files\n"); \
	printf("\tvoid * src = %p", args->hipMemcpyHtoDAsync.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyHtoDAsync.sizeBytes); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	HIP_TEXTURE_DESC * pTexDesc (unknown);
//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectGetTextureDesc(args) { \
	printf("\tHIP_TEXTURE_DESC * pTexDesc = N/A, try to update csv files\n"); \
	printf("\thipTextureObject_t texObject = N/A, try to update csv files\n"); \
};

//	unsigned long long * flags (unsigned long long*);
//	struct const hipMemLocation * location ({
//		hipMemLocationType type (enum);
//		int id (int);
//	});
//	void * ptr (void*);
#define PROCESS_ARGS_hipMemGetAccess(args) { \
	printf("\tunsigned long long * flags = %p", args->hipMemGetAccess.flags); \
	if (args->hipMemGetAccess.flags != NULL) { \
		printf(" -> %llu\n", *args->hipMemGetAccess.flags); \
	} else { printf("\n"); }; \
	printf("\tstruct const hipMemLocation * location = %p", args->hipMemGetAccess.location); \
	if (args->hipMemGetAccess.location != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemLocationType type = %d\n", (*args->hipMemGetAccess.location).type); \
		printf("\t\tint id = %d\n", (*args->hipMemGetAccess.location).id); \
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
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpy2DToArrayAsync(args) { \
	printf("\thipArray_t dst = N/A, try to update csv files\n"); \
	printf("\tsize_t wOffset = %lu\n", args->hipMemcpy2DToArrayAsync.wOffset); \
	printf("\tsize_t hOffset = %lu\n", args->hipMemcpy2DToArrayAsync.hOffset); \
	printf("\tconst void * src = %p", args->hipMemcpy2DToArrayAsync.src); \
	printf("\n"); \
	printf("\tsize_t spitch = %lu\n", args->hipMemcpy2DToArrayAsync.spitch); \
	printf("\tsize_t width = %lu\n", args->hipMemcpy2DToArrayAsync.width); \
	printf("\tsize_t height = %lu\n", args->hipMemcpy2DToArrayAsync.height); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipDeviceptr_t * dev_ptr (unknown);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetAddress(args) { \
	printf("\thipDeviceptr_t * dev_ptr = N/A, try to update csv files\n"); \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t node (unknown);
//	hipGraphNodeType * pType (enum*);
#define PROCESS_ARGS_hipGraphNodeGetType(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\thipGraphNodeType * pType = %p", args->hipGraphNodeGetType.pType); \
	if (args->hipGraphNodeGetType.pType != NULL) { \
		printf(" -> %d\n", *args->hipGraphNodeGetType.pType); \
	} else { printf("\n"); }; \
};

//	hipStream_t stream (unknown);
//	unsigned int * flags (unsigned int*);
#define PROCESS_ARGS_hipStreamGetFlags(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\tunsigned int * flags = %p", args->hipStreamGetFlags.flags); \
	if (args->hipStreamGetFlags.flags != NULL) { \
		printf(" -> %u\n", *args->hipStreamGetFlags.flags); \
	} else { printf("\n"); }; \
};

//	int * numBlocks (int*);
//	hipFunction_t f (unknown);
//	int blockSize (int);
//	size_t dynSharedMemPerBlk (unsigned long);
#define PROCESS_ARGS_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor(args) { \
	printf("\tint * numBlocks = %p", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks); \
	if (args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks != NULL) { \
		printf(" -> %d\n", *args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.numBlocks); \
	} else { printf("\n"); }; \
	printf("\thipFunction_t f = N/A, try to update csv files\n"); \
	printf("\tint blockSize = %d\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.blockSize); \
	printf("\tsize_t dynSharedMemPerBlk = %lu\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessor.dynSharedMemPerBlk); \
};

//	void * dst (void*);
//	size_t pitch (unsigned long);
//	int value (int);
//	size_t width (unsigned long);
//	size_t height (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemset2DAsync(args) { \
	printf("\tvoid * dst = %p", args->hipMemset2DAsync.dst); \
	printf("\n"); \
	printf("\tsize_t pitch = %lu\n", args->hipMemset2DAsync.pitch); \
	printf("\tint value = %d\n", args->hipMemset2DAsync.value); \
	printf("\tsize_t width = %lu\n", args->hipMemset2DAsync.width); \
	printf("\tsize_t height = %lu\n", args->hipMemset2DAsync.height); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	void * dst (void*);
//	const void * symbol (void*);
//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpyFromSymbol(args) { \
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
//	hipStream_t stream (unknown);
//	hipEvent_t startEvent (unknown);
//	hipEvent_t stopEvent (unknown);
//	int flags (int);
#define PROCESS_ARGS_hipExtLaunchKernel(args) { \
	printf("\tconst void * function_address = %p", args->hipExtLaunchKernel.function_address); \
	printf("\n"); \
	printf("\tstruct dim3 numBlocks = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipExtLaunchKernel.numBlocks.x); \
	printf("\t\tuint32_t y = %u\n", args->hipExtLaunchKernel.numBlocks.y); \
	printf("\t\tuint32_t z = %u\n", args->hipExtLaunchKernel.numBlocks.z); \
	printf("\t}\n"); \
	printf("\tstruct dim3 dimBlocks = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipExtLaunchKernel.dimBlocks.x); \
	printf("\t\tuint32_t y = %u\n", args->hipExtLaunchKernel.dimBlocks.y); \
	printf("\t\tuint32_t z = %u\n", args->hipExtLaunchKernel.dimBlocks.z); \
	printf("\t}\n"); \
	printf("\tvoid ** args = %p", args->hipExtLaunchKernel.args); \
	if (args->hipExtLaunchKernel.args != NULL) { \
		printf("-> %p", *args->hipExtLaunchKernel.args); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t sharedMemBytes = %lu\n", args->hipExtLaunchKernel.sharedMemBytes); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\thipEvent_t startEvent = N/A, try to update csv files\n"); \
	printf("\thipEvent_t stopEvent = N/A, try to update csv files\n"); \
	printf("\tint flags = %d\n", args->hipExtLaunchKernel.flags); \
};

//	void * dst (void*);
//	const void * symbol (void*);
//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyFromSymbolAsync(args) { \
	printf("\tvoid * dst = %p", args->hipMemcpyFromSymbolAsync.dst); \
	printf("\n"); \
	printf("\tconst void * symbol = %p", args->hipMemcpyFromSymbolAsync.symbol); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyFromSymbolAsync.sizeBytes); \
	printf("\tsize_t offset = %lu\n", args->hipMemcpyFromSymbolAsync.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipCtx_t * ctx (unknown);
//	unsigned int flags (unsigned int);
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipCtxCreate(args) { \
	printf("\thipCtx_t * ctx = N/A, try to update csv files\n"); \
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
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipLaunchCooperativeKernel(args) { \
	printf("\tconst void * f = %p", args->hipLaunchCooperativeKernel.f); \
	printf("\n"); \
	printf("\tstruct dim3 gridDim = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipLaunchCooperativeKernel.gridDim.x); \
	printf("\t\tuint32_t y = %u\n", args->hipLaunchCooperativeKernel.gridDim.y); \
	printf("\t\tuint32_t z = %u\n", args->hipLaunchCooperativeKernel.gridDim.z); \
	printf("\t}\n"); \
	printf("\tstruct dim3 blockDimX = {\n"); \
	printf("\t\tuint32_t x = %u\n", args->hipLaunchCooperativeKernel.blockDimX.x); \
	printf("\t\tuint32_t y = %u\n", args->hipLaunchCooperativeKernel.blockDimX.y); \
	printf("\t\tuint32_t z = %u\n", args->hipLaunchCooperativeKernel.blockDimX.z); \
	printf("\t}\n"); \
	printf("\tvoid ** kernelParams = %p", args->hipLaunchCooperativeKernel.kernelParams); \
	if (args->hipLaunchCooperativeKernel.kernelParams != NULL) { \
		printf("-> %p", *args->hipLaunchCooperativeKernel.kernelParams); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tunsigned int sharedMemBytes = %u\n", args->hipLaunchCooperativeKernel.sharedMemBytes); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipStream_t stream (unknown);
//	uint32_t cuMaskSize (unsigned int);
//	uint32_t * cuMask (unsigned int*);
#define PROCESS_ARGS_hipExtStreamGetCUMask(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\tuint32_t cuMaskSize = %u\n", args->hipExtStreamGetCUMask.cuMaskSize); \
	printf("\tuint32_t * cuMask = %p", args->hipExtStreamGetCUMask.cuMask); \
	if (args->hipExtStreamGetCUMask.cuMask != NULL) { \
		printf(" -> %u\n", *args->hipExtStreamGetCUMask.cuMask); \
	} else { printf("\n"); }; \
};

//	hipGraphExec_t graphExec (unknown);
#define PROCESS_ARGS_hipGraphExecDestroy(args) { \
	printf("\thipGraphExec_t graphExec = N/A, try to update csv files\n"); \
};

//	hipError_t hipError (enum);
//	const char ** errorString (char**);
#define PROCESS_ARGS_hipDrvGetErrorString(args) { \
	printf("\thipError_t hipError = %d\n", args->hipDrvGetErrorString.hipError); \
	printf("\tconst char ** errorString = %p", args->hipDrvGetErrorString.errorString); \
	if (args->hipDrvGetErrorString.errorString != NULL) { \
		printf("-> %p", *args->hipDrvGetErrorString.errorString); \
		if (*args->hipDrvGetErrorString.errorString != NULL) { \
			printf(" -> %c\n", **args->hipDrvGetErrorString.errorString); \
		} else { printf("\n"); }; \
	} else { printf("\n"); }; \
};

//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipInit(args) { \
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
	printf("\tsize_t * offset = %p", args->hipBindTexture2D.offset); \
	if (args->hipBindTexture2D.offset != NULL) { \
		printf(" -> %lu\n", *args->hipBindTexture2D.offset); \
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
	printf("\tint device1 = %d\n", args->hipExtGetLinkTypeAndHopCount.device1); \
	printf("\tint device2 = %d\n", args->hipExtGetLinkTypeAndHopCount.device2); \
	printf("\tuint32_t * linktype = %p", args->hipExtGetLinkTypeAndHopCount.linktype); \
	if (args->hipExtGetLinkTypeAndHopCount.linktype != NULL) { \
		printf(" -> %u\n", *args->hipExtGetLinkTypeAndHopCount.linktype); \
	} else { printf("\n"); }; \
	printf("\tuint32_t * hopcount = %p", args->hipExtGetLinkTypeAndHopCount.hopcount); \
	if (args->hipExtGetLinkTypeAndHopCount.hopcount != NULL) { \
		printf(" -> %u\n", *args->hipExtGetLinkTypeAndHopCount.hopcount); \
	} else { printf("\n"); }; \
};

//	struct hipResourceViewDesc * pResViewDesc (unknown);
//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipGetTextureObjectResourceViewDesc(args) { \
	printf("\tstruct hipResourceViewDesc * pResViewDesc = N/A, try to update csv files\n"); \
	printf("\thipTextureObject_t textureObject = N/A, try to update csv files\n"); \
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
	printf("\thipMemGenericAllocationHandle_t * handle = N/A, try to update csv files\n"); \
	printf("\tsize_t size = %lu\n", args->hipMemCreate.size); \
	printf("\tstruct const hipMemAllocationProp * prop = %p", args->hipMemCreate.prop); \
	if (args->hipMemCreate.prop != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemAllocationType type = %d\n", (*args->hipMemCreate.prop).type); \
		printf("\t\thipMemAllocationHandleType requestedHandleType = %d\n", (*args->hipMemCreate.prop).requestedHandleType); \
		printf("\t\tstruct hipMemLocation location = {\n"); \
		printf("\t\t\thipMemLocationType type = %d\n", ((*args->hipMemCreate.prop).location).type); \
		printf("\t\t\tint id = %d\n", ((*args->hipMemCreate.prop).location).id); \
		printf("\t\t}\n"); \
		printf("\t\tvoid * win32HandleMetaData = %p", (*args->hipMemCreate.prop).win32HandleMetaData); \
		printf("\n"); \
		printf("\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1393:5) allocFlags = N/A, try to update csv files\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tunsigned long long flags = %llu\n", args->hipMemCreate.flags); \
};

//	hipDeviceptr_t dest (unknown);
//	unsigned char value (unsigned char);
//	size_t count (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemsetD8Async(args) { \
	printf("\thipDeviceptr_t dest = N/A, try to update csv files\n"); \
	printf("\tunsigned char value = %hhu\n", args->hipMemsetD8Async.value); \
	printf("\tsize_t count = %lu\n", args->hipMemsetD8Async.count); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipStream_t stream (unknown);
//	hipHostFn_t fn (void*);
//	void * userData (void*);
#define PROCESS_ARGS_hipLaunchHostFunc(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\thipHostFn_t fn = %p", args->hipLaunchHostFunc.fn); \
	printf("\n"); \
	printf("\tvoid * userData = %p", args->hipLaunchHostFunc.userData); \
	printf("\n"); \
};

//	hipGraph_t graph (unknown);
//	hipGraphNode_t * from (unknown);
//	hipGraphNode_t * to (unknown);
//	size_t * numEdges (unsigned long*);
#define PROCESS_ARGS_hipGraphGetEdges(args) { \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t * from = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t * to = N/A, try to update csv files\n"); \
	printf("\tsize_t * numEdges = %p", args->hipGraphGetEdges.numEdges); \
	if (args->hipGraphGetEdges.numEdges != NULL) { \
		printf(" -> %lu\n", *args->hipGraphGetEdges.numEdges); \
	} else { printf("\n"); }; \
};

//	hipMemPool_t mem_pool (unknown);
#define PROCESS_ARGS_hipMemPoolDestroy(args) { \
	printf("\thipMemPool_t mem_pool = N/A, try to update csv files\n"); \
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
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\tstruct hipKernelNodeParams * pNodeParams = %p", args->hipGraphKernelNodeGetParams.pNodeParams); \
	if (args->hipGraphKernelNodeGetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tstruct dim3 blockDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", ((*args->hipGraphKernelNodeGetParams.pNodeParams).blockDim).x); \
		printf("\t\t\tuint32_t y = %u\n", ((*args->hipGraphKernelNodeGetParams.pNodeParams).blockDim).y); \
		printf("\t\t\tuint32_t z = %u\n", ((*args->hipGraphKernelNodeGetParams.pNodeParams).blockDim).z); \
		printf("\t\t}\n"); \
		printf("\t\tvoid ** extra = %p", (*args->hipGraphKernelNodeGetParams.pNodeParams).extra); \
		if ((*args->hipGraphKernelNodeGetParams.pNodeParams).extra != NULL) { \
			printf("-> %p", *(*args->hipGraphKernelNodeGetParams.pNodeParams).extra); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tvoid * func = %p", (*args->hipGraphKernelNodeGetParams.pNodeParams).func); \
		printf("\n"); \
		printf("\t\tstruct dim3 gridDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", ((*args->hipGraphKernelNodeGetParams.pNodeParams).gridDim).x); \
		printf("\t\t\tuint32_t y = %u\n", ((*args->hipGraphKernelNodeGetParams.pNodeParams).gridDim).y); \
		printf("\t\t\tuint32_t z = %u\n", ((*args->hipGraphKernelNodeGetParams.pNodeParams).gridDim).z); \
		printf("\t\t}\n"); \
		printf("\t\tvoid ** kernelParams = %p", (*args->hipGraphKernelNodeGetParams.pNodeParams).kernelParams); \
		if ((*args->hipGraphKernelNodeGetParams.pNodeParams).kernelParams != NULL) { \
			printf("-> %p", *(*args->hipGraphKernelNodeGetParams.pNodeParams).kernelParams); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int sharedMemBytes = %u\n", (*args->hipGraphKernelNodeGetParams.pNodeParams).sharedMemBytes); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	unsigned int numAttributes (unsigned int);
//	hipPointer_attribute * attributes (unknown);
//	void ** data (void**);
//	hipDeviceptr_t ptr (unknown);
#define PROCESS_ARGS_hipDrvPointerGetAttributes(args) { \
	printf("\tunsigned int numAttributes = %u\n", args->hipDrvPointerGetAttributes.numAttributes); \
	printf("\thipPointer_attribute * attributes = N/A, try to update csv files\n"); \
	printf("\tvoid ** data = %p", args->hipDrvPointerGetAttributes.data); \
	if (args->hipDrvPointerGetAttributes.data != NULL) { \
		printf("-> %p", *args->hipDrvPointerGetAttributes.data); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\thipDeviceptr_t ptr = N/A, try to update csv files\n"); \
};

//	const void * func (void*);
//	hipFuncAttribute attr (enum);
//	int value (int);
#define PROCESS_ARGS_hipFuncSetAttribute(args) { \
	printf("\tconst void * func = %p", args->hipFuncSetAttribute.func); \
	printf("\n"); \
	printf("\thipFuncAttribute attr = %d\n", args->hipFuncSetAttribute.attr); \
	printf("\tint value = %d\n", args->hipFuncSetAttribute.value); \
};

//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * from (unknown);
//	const hipGraphNode_t * to (unknown);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphAddDependencies(args) { \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * from = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * to = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddDependencies.numDependencies); \
};

//	hipStream_t stream (unknown);
//	void * ptr (void*);
//	uint64_t value (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamWriteValue64(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\tvoid * ptr = %p", args->hipStreamWriteValue64.ptr); \
	printf("\n"); \
	printf("\tuint64_t value = %lu\n", args->hipStreamWriteValue64.value); \
	printf("\tunsigned int flags = %u\n", args->hipStreamWriteValue64.flags); \
};

//	hipSurfaceObject_t* pSurfObject (unknown);
//	const hipResourceDesc* pResDesc (unknown);
#define PROCESS_ARGS_hipCreateSurfaceObject(args) { \
	printf("\thipSurfaceObject_t* pSurfObject = N/A, try to update csv files\n"); \
	printf("\tconst hipResourceDesc* pResDesc = N/A, try to update csv files\n"); \
};

//	hipTextureDesc* pTexDesc (unknown);
//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipGetTextureObjectTextureDesc(args) { \
	printf("\thipTextureDesc* pTexDesc = N/A, try to update csv files\n"); \
	printf("\thipTextureObject_t textureObject = N/A, try to update csv files\n"); \
};

//	void * ptr (void*);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMemUnmap(args) { \
	printf("\tvoid * ptr = %p", args->hipMemUnmap.ptr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hipMemUnmap.size); \
};

//	hipGraphNode_t node (unknown);
//	hipGraph_t * pGraph (unknown);
#define PROCESS_ARGS_hipGraphChildGraphNodeGetGraph(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\thipGraph_t * pGraph = N/A, try to update csv files\n"); \
};

//	hipStream_t * stream (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamCreateWithFlags(args) { \
	printf("\thipStream_t * stream = N/A, try to update csv files\n"); \
	printf("\tunsigned int flags = %u\n", args->hipStreamCreateWithFlags.flags); \
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
	printf("\thipMemPool_t * mem_pool = N/A, try to update csv files\n"); \
	printf("\tstruct const hipMemPoolProps * pool_props = %p", args->hipMemPoolCreate.pool_props); \
	if (args->hipMemPoolCreate.pool_props != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemAllocationType allocType = %d\n", (*args->hipMemPoolCreate.pool_props).allocType); \
		printf("\t\thipMemAllocationHandleType handleTypes = %d\n", (*args->hipMemPoolCreate.pool_props).handleTypes); \
		printf("\t\tstruct hipMemLocation location = {\n"); \
		printf("\t\t\thipMemLocationType type = %d\n", ((*args->hipMemPoolCreate.pool_props).location).type); \
		printf("\t\t\tint id = %d\n", ((*args->hipMemPoolCreate.pool_props).location).id); \
		printf("\t\t}\n"); \
		printf("\t\tvoid * win32SecurityAttributes = %p", (*args->hipMemPoolCreate.pool_props).win32SecurityAttributes); \
		printf("\n"); \
		printf("\t\tunsigned char[64] reserved = %p", (*args->hipMemPoolCreate.pool_props).reserved); \
		if ((*args->hipMemPoolCreate.pool_props).reserved != NULL) { \
			printf(" -> %hhu\n", *(*args->hipMemPoolCreate.pool_props).reserved); \
		} else { printf("\n"); }; \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
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
	printf("\tstruct hipLaunchParams * launchParamsList = %p", args->hipLaunchCooperativeKernelMultiDevice.launchParamsList); \
	if (args->hipLaunchCooperativeKernelMultiDevice.launchParamsList != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tvoid * func = %p", (*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).func); \
		printf("\n"); \
		printf("\t\tstruct dim3 gridDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", ((*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).gridDim).x); \
		printf("\t\t\tuint32_t y = %u\n", ((*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).gridDim).y); \
		printf("\t\t\tuint32_t z = %u\n", ((*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).gridDim).z); \
		printf("\t\t}\n"); \
		printf("\t\tstruct dim3 blockDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", ((*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).blockDim).x); \
		printf("\t\t\tuint32_t y = %u\n", ((*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).blockDim).y); \
		printf("\t\t\tuint32_t z = %u\n", ((*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).blockDim).z); \
		printf("\t\t}\n"); \
		printf("\t\tvoid ** args = %p", (*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).args); \
		if ((*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).args != NULL) { \
			printf("-> %p", *(*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).args); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tint sharedMem = %d\n", (*args->hipLaunchCooperativeKernelMultiDevice.launchParamsList).sharedMem); \
		printf("\t\thipStream_t stream = N/A, try to update csv files\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tint numDevices = %d\n", args->hipLaunchCooperativeKernelMultiDevice.numDevices); \
	printf("\tunsigned int flags = %u\n", args->hipLaunchCooperativeKernelMultiDevice.flags); \
};

//	textureReference* texRef (unknown);
//	enum hipTextureFilterMode fm (enum);
#define PROCESS_ARGS_hipTexRefSetFilterMode(args) { \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tenum hipTextureFilterMode fm = %d\n", args->hipTexRefSetFilterMode.fm); \
};

//	int device (int);
//	hipGraphMemAttributeType attr (enum);
//	void * value (void*);
#define PROCESS_ARGS_hipDeviceSetGraphMemAttribute(args) { \
	printf("\tint device = %d\n", args->hipDeviceSetGraphMemAttribute.device); \
	printf("\thipGraphMemAttributeType attr = %d\n", args->hipDeviceSetGraphMemAttribute.attr); \
	printf("\tvoid * value = %p", args->hipDeviceSetGraphMemAttribute.value); \
	printf("\n"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t node (unknown);
//	void * dst (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParams1D(args) { \
	printf("\thipGraphExec_t hGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\tvoid * dst = %p", args->hipGraphExecMemcpyNodeSetParams1D.dst); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipGraphExecMemcpyNodeSetParams1D.src); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipGraphExecMemcpyNodeSetParams1D.count); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
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
	printf("\thipGraphExec_t hGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\tstruct const hipKernelNodeParams * pNodeParams = %p", args->hipGraphExecKernelNodeSetParams.pNodeParams); \
	if (args->hipGraphExecKernelNodeSetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tstruct dim3 blockDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).blockDim).x); \
		printf("\t\t\tuint32_t y = %u\n", ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).blockDim).y); \
		printf("\t\t\tuint32_t z = %u\n", ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).blockDim).z); \
		printf("\t\t}\n"); \
		printf("\t\tvoid ** extra = %p", (*args->hipGraphExecKernelNodeSetParams.pNodeParams).extra); \
		if ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).extra != NULL) { \
			printf("-> %p", *(*args->hipGraphExecKernelNodeSetParams.pNodeParams).extra); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tvoid * func = %p", (*args->hipGraphExecKernelNodeSetParams.pNodeParams).func); \
		printf("\n"); \
		printf("\t\tstruct dim3 gridDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).gridDim).x); \
		printf("\t\t\tuint32_t y = %u\n", ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).gridDim).y); \
		printf("\t\t\tuint32_t z = %u\n", ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).gridDim).z); \
		printf("\t\t}\n"); \
		printf("\t\tvoid ** kernelParams = %p", (*args->hipGraphExecKernelNodeSetParams.pNodeParams).kernelParams); \
		if ((*args->hipGraphExecKernelNodeSetParams.pNodeParams).kernelParams != NULL) { \
			printf("-> %p", *(*args->hipGraphExecKernelNodeSetParams.pNodeParams).kernelParams); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int sharedMemBytes = %u\n", (*args->hipGraphExecKernelNodeSetParams.pNodeParams).sharedMemBytes); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraphExec_t * pGraphExec (unknown);
//	hipGraph_t graph (unknown);
//	hipGraphNode_t * pErrorNode (unknown);
//	char * pLogBuffer (char*);
//	size_t bufferSize (unsigned long);
#define PROCESS_ARGS_hipGraphInstantiate(args) { \
	printf("\thipGraphExec_t * pGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t * pErrorNode = N/A, try to update csv files\n"); \
	printf("\tchar * pLogBuffer = %p", args->hipGraphInstantiate.pLogBuffer); \
	if (args->hipGraphInstantiate.pLogBuffer != NULL) { \
		printf(" -> %c\n", *args->hipGraphInstantiate.pLogBuffer); \
	} else { printf("\n"); }; \
	printf("\tsize_t bufferSize = %lu\n", args->hipGraphInstantiate.bufferSize); \
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
	printf("\thipGraphExec_t hGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t hNode = N/A, try to update csv files\n"); \
	printf("\tstruct const hipExternalSemaphoreSignalNodeParams * nodeParams = %p", args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams); \
	if (args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipExternalSemaphore_t * extSemArray = %p", (*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).extSemArray); \
		if ((*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).extSemArray != NULL) { \
			printf("-> %p", *(*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).extSemArray); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tstruct const hipExternalSemaphoreSignalParams * paramsArray = %p", (*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray); \
		if ((*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray != NULL) { \
			printf(" -> {\n"); \
			printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1136:3) params = N/A, try to update csv files\n"); \
			printf("\t\t\tunsigned int flags = %u\n", (*(*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).flags); \
			printf("\t\t\tunsigned int[16] reserved = %p", (*(*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).reserved); \
			if ((*(*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).reserved != NULL) { \
				printf(" -> %u\n", *(*(*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).paramsArray).reserved); \
			} else { printf("\n"); }; \
			printf("\t\t}\n"); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int numExtSems = %u\n", (*args->hipGraphExecExternalSemaphoresSignalNodeSetParams.nodeParams).numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipTextureObject_t* pTexObject (unknown);
//	const hipResourceDesc* pResDesc (unknown);
//	const hipTextureDesc* pTexDesc (unknown);
//	const struct hipResourceViewDesc * pResViewDesc (unknown);
#define PROCESS_ARGS_hipCreateTextureObject(args) { \
	printf("\thipTextureObject_t* pTexObject = N/A, try to update csv files\n"); \
	printf("\tconst hipResourceDesc* pResDesc = N/A, try to update csv files\n"); \
	printf("\tconst hipTextureDesc* pTexDesc = N/A, try to update csv files\n"); \
	printf("\tconst struct hipResourceViewDesc * pResViewDesc = N/A, try to update csv files\n"); \
};

//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipEventQuery(args) { \
	printf("\thipEvent_t event = N/A, try to update csv files\n"); \
};

//	hipCtx_t ctx (unknown);
#define PROCESS_ARGS_hipCtxPushCurrent(args) { \
	printf("\thipCtx_t ctx = N/A, try to update csv files\n"); \
};

//	hipGraph_t graph (unknown);
//	hipGraphNode_t * pRootNodes (unknown);
//	size_t * pNumRootNodes (unsigned long*);
#define PROCESS_ARGS_hipGraphGetRootNodes(args) { \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t * pRootNodes = N/A, try to update csv files\n"); \
	printf("\tsize_t * pNumRootNodes = %p", args->hipGraphGetRootNodes.pNumRootNodes); \
	if (args->hipGraphGetRootNodes.pNumRootNodes != NULL) { \
		printf(" -> %lu\n", *args->hipGraphGetRootNodes.pNumRootNodes); \
	} else { printf("\n"); }; \
};

//	hipError_t hipError (enum);
#define PROCESS_ARGS_hipGetErrorString(args) { \
	printf("\thipError_t hipError = %d\n", args->hipGetErrorString.hipError); \
};

//	void * devPtr (void*);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipMemAddressFree(args) { \
	printf("\tvoid * devPtr = %p", args->hipMemAddressFree.devPtr); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hipMemAddressFree.size); \
};


#define PROCESS_ARGS_hipDeviceSynchronize(args) { \
\
};

//	unsigned int * flags (unsigned int*);
#define PROCESS_ARGS_hipCtxGetFlags(args) { \
	printf("\tunsigned int * flags = %p", args->hipCtxGetFlags.flags); \
	if (args->hipCtxGetFlags.flags != NULL) { \
		printf(" -> %u\n", *args->hipCtxGetFlags.flags); \
	} else { printf("\n"); }; \
};

//	hipArray_t* pArray (unknown);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetArray(args) { \
	printf("\thipArray_t* pArray = N/A, try to update csv files\n"); \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
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
	printf("\tsize_t * granularity = %p", args->hipMemGetAllocationGranularity.granularity); \
	if (args->hipMemGetAllocationGranularity.granularity != NULL) { \
		printf(" -> %lu\n", *args->hipMemGetAllocationGranularity.granularity); \
	} else { printf("\n"); }; \
	printf("\tstruct const hipMemAllocationProp * prop = %p", args->hipMemGetAllocationGranularity.prop); \
	if (args->hipMemGetAllocationGranularity.prop != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemAllocationType type = %d\n", (*args->hipMemGetAllocationGranularity.prop).type); \
		printf("\t\thipMemAllocationHandleType requestedHandleType = %d\n", (*args->hipMemGetAllocationGranularity.prop).requestedHandleType); \
		printf("\t\tstruct hipMemLocation location = {\n"); \
		printf("\t\t\thipMemLocationType type = %d\n", ((*args->hipMemGetAllocationGranularity.prop).location).type); \
		printf("\t\t\tint id = %d\n", ((*args->hipMemGetAllocationGranularity.prop).location).id); \
		printf("\t\t}\n"); \
		printf("\t\tvoid * win32HandleMetaData = %p", (*args->hipMemGetAllocationGranularity.prop).win32HandleMetaData); \
		printf("\n"); \
		printf("\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1393:5) allocFlags = N/A, try to update csv files\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thipMemAllocationGranularity_flags option = %d\n", args->hipMemGetAllocationGranularity.option); \
};


#define PROCESS_ARGS_hipProfilerStop(args) { \
\
};

//	textureReference* tex (unknown);
//	hipArray_const_t array (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipTexRefSetArray(args) { \
	printf("\ttextureReference* tex = N/A, try to update csv files\n"); \
	printf("\thipArray_const_t array = N/A, try to update csv files\n"); \
	printf("\tunsigned int flags = %u\n", args->hipTexRefSetArray.flags); \
};

//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipEventDestroy(args) { \
	printf("\thipEvent_t event = N/A, try to update csv files\n"); \
};

//	hipFuncCache_t cacheConfig (enum);
#define PROCESS_ARGS_hipDeviceSetCacheConfig(args) { \
	printf("\thipFuncCache_t cacheConfig = %d\n", args->hipDeviceSetCacheConfig.cacheConfig); \
};

//	const void * func (void*);
#define PROCESS_ARGS_hipLaunchByPtr(args) { \
	printf("\tconst void * func = %p", args->hipLaunchByPtr.func); \
	printf("\n"); \
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
	printf("\tstruct hipFunctionLaunchParams * launchParamsList = %p", args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList); \
	if (args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipFunction_t function = N/A, try to update csv files\n"); \
		printf("\t\tunsigned int gridDimX = %u\n", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).gridDimX); \
		printf("\t\tunsigned int gridDimY = %u\n", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).gridDimY); \
		printf("\t\tunsigned int gridDimZ = %u\n", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).gridDimZ); \
		printf("\t\tunsigned int blockDimX = %u\n", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).blockDimX); \
		printf("\t\tunsigned int blockDimY = %u\n", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).blockDimY); \
		printf("\t\tunsigned int blockDimZ = %u\n", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).blockDimZ); \
		printf("\t\tunsigned int sharedMemBytes = %u\n", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).sharedMemBytes); \
		printf("\t\thipStream_t hStream = N/A, try to update csv files\n"); \
		printf("\t\tvoid ** kernelParams = %p", (*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).kernelParams); \
		if ((*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).kernelParams != NULL) { \
			printf("-> %p", *(*args->hipModuleLaunchCooperativeKernelMultiDevice.launchParamsList).kernelParams); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tunsigned int numDevices = %u\n", args->hipModuleLaunchCooperativeKernelMultiDevice.numDevices); \
	printf("\tunsigned int flags = %u\n", args->hipModuleLaunchCooperativeKernelMultiDevice.flags); \
};

//	textureReference* texRef (unknown);
//	int dim (int);
//	enum hipTextureAddressMode am (enum);
#define PROCESS_ARGS_hipTexRefSetAddressMode(args) { \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tint dim = %d\n", args->hipTexRefSetAddressMode.dim); \
	printf("\tenum hipTextureAddressMode am = %d\n", args->hipTexRefSetAddressMode.am); \
};

//	hipModule_t * module (unknown);
//	const void * image (void*);
#define PROCESS_ARGS_hipModuleLoadData(args) { \
	printf("\thipModule_t * module = N/A, try to update csv files\n"); \
	printf("\tconst void * image = %p", args->hipModuleLoadData.image); \
	printf("\n"); \
};

//	const hip_Memcpy2D * pCopy (unknown);
#define PROCESS_ARGS_hipDrvMemcpy2DUnaligned(args) { \
	printf("\tconst hip_Memcpy2D * pCopy = N/A, try to update csv files\n"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t node (unknown);
//	hipGraph_t childGraph (unknown);
#define PROCESS_ARGS_hipGraphExecChildGraphNodeSetParams(args) { \
	printf("\thipGraphExec_t hGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\thipGraph_t childGraph = N/A, try to update csv files\n"); \
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
	printf("\tstruct hipPointerAttribute_t * attributes = %p", args->hipPointerGetAttributes.attributes); \
	if (args->hipPointerGetAttributes.attributes != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tenum hipMemoryType type = %d\n", (*args->hipPointerGetAttributes.attributes).type); \
		printf("\t\tint device = %d\n", (*args->hipPointerGetAttributes.attributes).device); \
		printf("\t\tvoid * devicePointer = %p", (*args->hipPointerGetAttributes.attributes).devicePointer); \
		printf("\n"); \
		printf("\t\tvoid * hostPointer = %p", (*args->hipPointerGetAttributes.attributes).hostPointer); \
		printf("\n"); \
		printf("\t\tint isManaged = %d\n", (*args->hipPointerGetAttributes.attributes).isManaged); \
		printf("\t\tunsigned int allocationFlags = %u\n", (*args->hipPointerGetAttributes.attributes).allocationFlags); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tconst void * ptr = %p", args->hipPointerGetAttributes.ptr); \
	printf("\n"); \
};

//	void * dst (void*);
//	hipDeviceptr_t src (unknown);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyDtoHAsync(args) { \
	printf("\tvoid * dst = %p", args->hipMemcpyDtoHAsync.dst); \
	printf("\n"); \
	printf("\thipDeviceptr_t src = N/A, try to update csv files\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyDtoHAsync.sizeBytes); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipGraphAddEventRecordNode(args) { \
	printf("\thipGraphNode_t * pGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddEventRecordNode.numDependencies); \
	printf("\thipEvent_t event = N/A, try to update csv files\n"); \
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
	printf("\thipGraphNode_t * pGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddExternalSemaphoresSignalNode.numDependencies); \
	printf("\tstruct const hipExternalSemaphoreSignalNodeParams * nodeParams = %p", args->hipGraphAddExternalSemaphoresSignalNode.nodeParams); \
	if (args->hipGraphAddExternalSemaphoresSignalNode.nodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipExternalSemaphore_t * extSemArray = %p", (*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).extSemArray); \
		if ((*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).extSemArray != NULL) { \
			printf("-> %p", *(*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).extSemArray); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tstruct const hipExternalSemaphoreSignalParams * paramsArray = %p", (*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).paramsArray); \
		if ((*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).paramsArray != NULL) { \
			printf(" -> {\n"); \
			printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1136:3) params = N/A, try to update csv files\n"); \
			printf("\t\t\tunsigned int flags = %u\n", (*(*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).paramsArray).flags); \
			printf("\t\t\tunsigned int[16] reserved = %p", (*(*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).paramsArray).reserved); \
			if ((*(*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).paramsArray).reserved != NULL) { \
				printf(" -> %u\n", *(*(*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).paramsArray).reserved); \
			} else { printf("\n"); }; \
			printf("\t\t}\n"); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int numExtSems = %u\n", (*args->hipGraphAddExternalSemaphoresSignalNode.nodeParams).numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraph_t graph (unknown);
//	hipUserObject_t object (unknown);
//	unsigned int count (unsigned int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipGraphRetainUserObject(args) { \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\thipUserObject_t object = N/A, try to update csv files\n"); \
	printf("\tunsigned int count = %u\n", args->hipGraphRetainUserObject.count); \
	printf("\tunsigned int flags = %u\n", args->hipGraphRetainUserObject.flags); \
};

//	const void * arg (void*);
//	size_t size (unsigned long);
//	size_t offset (unsigned long);
#define PROCESS_ARGS_hipSetupArgument(args) { \
	printf("\tconst void * arg = %p", args->hipSetupArgument.arg); \
	printf("\n"); \
	printf("\tsize_t size = %lu\n", args->hipSetupArgument.size); \
	printf("\tsize_t offset = %lu\n", args->hipSetupArgument.offset); \
};

//	hipDeviceptr_t * dptr (unknown);
//	size_t* pitch (unsigned long*);
//	size_t widthInBytes (unsigned long);
//	size_t height (unsigned long);
//	unsigned int elementSizeBytes (unsigned int);
#define PROCESS_ARGS_hipMemAllocPitch(args) { \
	printf("\thipDeviceptr_t * dptr = N/A, try to update csv files\n"); \
	printf("\tsize_t* pitch = %p", args->hipMemAllocPitch.pitch); \
	if (args->hipMemAllocPitch.pitch != NULL) { \
		printf(" -> %lu\n", *args->hipMemAllocPitch.pitch); \
	} else { printf("\n"); }; \
	printf("\tsize_t widthInBytes = %lu\n", args->hipMemAllocPitch.widthInBytes); \
	printf("\tsize_t height = %lu\n", args->hipMemAllocPitch.height); \
	printf("\tunsigned int elementSizeBytes = %u\n", args->hipMemAllocPitch.elementSizeBytes); \
};

//	hipGraphNode_t node (unknown);
//	hipEvent_t * event_out (unknown);
#define PROCESS_ARGS_hipGraphEventWaitNodeGetEvent(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\thipEvent_t * event_out = N/A, try to update csv files\n"); \
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
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyPeerAsync(args) { \
	printf("\tvoid * dst = %p", args->hipMemcpyPeerAsync.dst); \
	printf("\n"); \
	printf("\tint dstDeviceId = %d\n", args->hipMemcpyPeerAsync.dstDeviceId); \
	printf("\tconst void * src = %p", args->hipMemcpyPeerAsync.src); \
	printf("\n"); \
	printf("\tint srcDevice = %d\n", args->hipMemcpyPeerAsync.srcDevice); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyPeerAsync.sizeBytes); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipTextureObject_t* pTexObject (unknown);
//	const HIP_RESOURCE_DESC* pResDesc (unknown);
//	const HIP_TEXTURE_DESC* pTexDesc (unknown);
//	const HIP_RESOURCE_VIEW_DESC* pResViewDesc (unknown);
#define PROCESS_ARGS_hipTexObjectCreate(args) { \
	printf("\thipTextureObject_t* pTexObject = N/A, try to update csv files\n"); \
	printf("\tconst HIP_RESOURCE_DESC* pResDesc = N/A, try to update csv files\n"); \
	printf("\tconst HIP_TEXTURE_DESC* pTexDesc = N/A, try to update csv files\n"); \
	printf("\tconst HIP_RESOURCE_VIEW_DESC* pResViewDesc = N/A, try to update csv files\n"); \
};

//	size_t * pValue (unsigned long*);
//	enum hipLimit_t limit (enum);
#define PROCESS_ARGS_hipDeviceGetLimit(args) { \
	printf("\tsize_t * pValue = %p", args->hipDeviceGetLimit.pValue); \
	if (args->hipDeviceGetLimit.pValue != NULL) { \
		printf(" -> %lu\n", *args->hipDeviceGetLimit.pValue); \
	} else { printf("\n"); }; \
	printf("\tenum hipLimit_t limit = %d\n", args->hipDeviceGetLimit.limit); \
};

//	void ** ptr (void**);
//	size_t sizeBytes (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipExtMallocWithFlags(args) { \
	printf("\tvoid ** ptr = %p", args->hipExtMallocWithFlags.ptr); \
	if (args->hipExtMallocWithFlags.ptr != NULL) { \
		printf("-> %p", *args->hipExtMallocWithFlags.ptr); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t sizeBytes = %lu\n", args->hipExtMallocWithFlags.sizeBytes); \
	printf("\tunsigned int flags = %u\n", args->hipExtMallocWithFlags.flags); \
};

//	hipError_t hip_error (enum);
#define PROCESS_ARGS_hipGetErrorName(args) { \
	printf("\thipError_t hip_error = %d\n", args->hipGetErrorName.hip_error); \
};

//	const struct hipMemcpy3DParms * p (unknown);
#define PROCESS_ARGS_hipMemcpy3D(args) { \
	printf("\tconst struct hipMemcpy3DParms * p = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t node (unknown);
//	void * dst (void*);
//	const void * symbol (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphMemcpyNodeSetParamsFromSymbol(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
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
	printf("\tvoid ** data = %p", args->hipMemRangeGetAttributes.data); \
	if (args->hipMemRangeGetAttributes.data != NULL) { \
		printf("-> %p", *args->hipMemRangeGetAttributes.data); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t * data_sizes = %p", args->hipMemRangeGetAttributes.data_sizes); \
	if (args->hipMemRangeGetAttributes.data_sizes != NULL) { \
		printf(" -> %lu\n", *args->hipMemRangeGetAttributes.data_sizes); \
	} else { printf("\n"); }; \
	printf("\thipMemRangeAttribute * attributes = %p", args->hipMemRangeGetAttributes.attributes); \
	if (args->hipMemRangeGetAttributes.attributes != NULL) { \
		printf(" -> %d\n", *args->hipMemRangeGetAttributes.attributes); \
	} else { printf("\n"); }; \
	printf("\tsize_t num_attributes = %lu\n", args->hipMemRangeGetAttributes.num_attributes); \
	printf("\tconst void * dev_ptr = %p", args->hipMemRangeGetAttributes.dev_ptr); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipMemRangeGetAttributes.count); \
};

//	hipGraph_t graph (unknown);
//	const char * path (char*);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipGraphDebugDotPrint(args) { \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst char * path = %p", args->hipGraphDebugDotPrint.path); \
	if (args->hipGraphDebugDotPrint.path != NULL) { \
		printf(" -> %c\n", *args->hipGraphDebugDotPrint.path); \
	} else { printf("\n"); }; \
	printf("\tunsigned int flags = %u\n", args->hipGraphDebugDotPrint.flags); \
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
	printf("\thipGraphNode_t hNode = N/A, try to update csv files\n"); \
	printf("\tstruct hipExternalSemaphoreWaitNodeParams * params_out = %p", args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out); \
	if (args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipExternalSemaphore_t * extSemArray = %p", (*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).extSemArray); \
		if ((*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).extSemArray != NULL) { \
			printf("-> %p", *(*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).extSemArray); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tstruct const hipExternalSemaphoreWaitParams * paramsArray = %p", (*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).paramsArray); \
		if ((*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).paramsArray != NULL) { \
			printf(" -> {\n"); \
			printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1156:3) params = N/A, try to update csv files\n"); \
			printf("\t\t\tunsigned int flags = %u\n", (*(*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).paramsArray).flags); \
			printf("\t\t\tunsigned int[16] reserved = %p", (*(*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).paramsArray).reserved); \
			if ((*(*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).paramsArray).reserved != NULL) { \
				printf(" -> %u\n", *(*(*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).paramsArray).reserved); \
			} else { printf("\n"); }; \
			printf("\t\t}\n"); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int numExtSems = %u\n", (*args->hipGraphExternalSemaphoresWaitNodeGetParams.params_out).numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	void * dst (void*);
//	int value (int);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemset(args) { \
	printf("\tvoid * dst = %p", args->hipMemset.dst); \
	printf("\n"); \
	printf("\tint value = %d\n", args->hipMemset.value); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemset.sizeBytes); \
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
	printf("\thipGraphNode_t * pGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddHostNode.numDependencies); \
	printf("\tstruct const hipHostNodeParams* pNodeParams = %p", args->hipGraphAddHostNode.pNodeParams); \
	if (args->hipGraphAddHostNode.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipHostFn_t fn = %p", (*args->hipGraphAddHostNode.pNodeParams).fn); \
		printf("\n"); \
		printf("\t\tvoid * userData = %p", (*args->hipGraphAddHostNode.pNodeParams).userData); \
		printf("\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	const hipMemcpy3DParms* pCopyParams (unknown);
#define PROCESS_ARGS_hipGraphAddMemcpyNode(args) { \
	printf("\thipGraphNode_t * pGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddMemcpyNode.numDependencies); \
	printf("\tconst hipMemcpy3DParms* pCopyParams = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t node (unknown);
//	struct hipHostNodeParams * pNodeParams ({
//		hipHostFn_t fn (void*);
//		void * userData (void*);
//	});
#define PROCESS_ARGS_hipGraphHostNodeGetParams(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\tstruct hipHostNodeParams * pNodeParams = %p", args->hipGraphHostNodeGetParams.pNodeParams); \
	if (args->hipGraphHostNodeGetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipHostFn_t fn = %p", (*args->hipGraphHostNodeGetParams.pNodeParams).fn); \
		printf("\n"); \
		printf("\t\tvoid * userData = %p", (*args->hipGraphHostNodeGetParams.pNodeParams).userData); \
		printf("\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	int * device (int*);
//	const char * pciBusId (char*);
#define PROCESS_ARGS_hipDeviceGetByPCIBusId(args) { \
	printf("\tint * device = %p", args->hipDeviceGetByPCIBusId.device); \
	if (args->hipDeviceGetByPCIBusId.device != NULL) { \
		printf(" -> %d\n", *args->hipDeviceGetByPCIBusId.device); \
	} else { printf("\n"); }; \
	printf("\tconst char * pciBusId = %p", args->hipDeviceGetByPCIBusId.pciBusId); \
	if (args->hipDeviceGetByPCIBusId.pciBusId != NULL) { \
		printf(" -> %c\n", *args->hipDeviceGetByPCIBusId.pciBusId); \
	} else { printf("\n"); }; \
};

//	hipDeviceptr_t dst (unknown);
//	hipDeviceptr_t src (unknown);
//	size_t sizeBytes (unsigned long);
#define PROCESS_ARGS_hipMemcpyDtoD(args) { \
	printf("\thipDeviceptr_t dst = N/A, try to update csv files\n"); \
	printf("\thipDeviceptr_t src = N/A, try to update csv files\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyDtoD.sizeBytes); \
};

//	struct hipIpcEventHandle_t * handle ({
//		char[64] reserved (char*);
//	});
//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipIpcGetEventHandle(args) { \
	printf("\tstruct hipIpcEventHandle_t * handle = %p", args->hipIpcGetEventHandle.handle); \
	if (args->hipIpcGetEventHandle.handle != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tchar[64] reserved = %p", (*args->hipIpcGetEventHandle.handle).reserved); \
		if ((*args->hipIpcGetEventHandle.handle).reserved != NULL) { \
			printf(" -> %c\n", *(*args->hipIpcGetEventHandle.handle).reserved); \
		} else { printf("\n"); }; \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thipEvent_t event = N/A, try to update csv files\n"); \
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
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\tstruct const hipKernelNodeParams * pNodeParams = %p", args->hipGraphKernelNodeSetParams.pNodeParams); \
	if (args->hipGraphKernelNodeSetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tstruct dim3 blockDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", ((*args->hipGraphKernelNodeSetParams.pNodeParams).blockDim).x); \
		printf("\t\t\tuint32_t y = %u\n", ((*args->hipGraphKernelNodeSetParams.pNodeParams).blockDim).y); \
		printf("\t\t\tuint32_t z = %u\n", ((*args->hipGraphKernelNodeSetParams.pNodeParams).blockDim).z); \
		printf("\t\t}\n"); \
		printf("\t\tvoid ** extra = %p", (*args->hipGraphKernelNodeSetParams.pNodeParams).extra); \
		if ((*args->hipGraphKernelNodeSetParams.pNodeParams).extra != NULL) { \
			printf("-> %p", *(*args->hipGraphKernelNodeSetParams.pNodeParams).extra); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tvoid * func = %p", (*args->hipGraphKernelNodeSetParams.pNodeParams).func); \
		printf("\n"); \
		printf("\t\tstruct dim3 gridDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", ((*args->hipGraphKernelNodeSetParams.pNodeParams).gridDim).x); \
		printf("\t\t\tuint32_t y = %u\n", ((*args->hipGraphKernelNodeSetParams.pNodeParams).gridDim).y); \
		printf("\t\t\tuint32_t z = %u\n", ((*args->hipGraphKernelNodeSetParams.pNodeParams).gridDim).z); \
		printf("\t\t}\n"); \
		printf("\t\tvoid ** kernelParams = %p", (*args->hipGraphKernelNodeSetParams.pNodeParams).kernelParams); \
		if ((*args->hipGraphKernelNodeSetParams.pNodeParams).kernelParams != NULL) { \
			printf("-> %p", *(*args->hipGraphKernelNodeSetParams.pNodeParams).kernelParams); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int sharedMemBytes = %u\n", (*args->hipGraphKernelNodeSetParams.pNodeParams).sharedMemBytes); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipFunction_t * function (unknown);
//	hipModule_t module (unknown);
//	const char * kname (char*);
#define PROCESS_ARGS_hipModuleGetFunction(args) { \
	printf("\thipFunction_t * function = N/A, try to update csv files\n"); \
	printf("\thipModule_t module = N/A, try to update csv files\n"); \
	printf("\tconst char * kname = %p", args->hipModuleGetFunction.kname); \
	if (args->hipModuleGetFunction.kname != NULL) { \
		printf(" -> %c\n", *args->hipModuleGetFunction.kname); \
	} else { printf("\n"); }; \
};

//	void * dst (void*);
//	hipArray_t srcArray (unknown);
//	size_t srcOffset (unsigned long);
//	size_t count (unsigned long);
#define PROCESS_ARGS_hipMemcpyAtoH(args) { \
	printf("\tvoid * dst = %p", args->hipMemcpyAtoH.dst); \
	printf("\n"); \
	printf("\thipArray_t srcArray = N/A, try to update csv files\n"); \
	printf("\tsize_t srcOffset = %lu\n", args->hipMemcpyAtoH.srcOffset); \
	printf("\tsize_t count = %lu\n", args->hipMemcpyAtoH.count); \
};

//	int peerDeviceId (int);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipDeviceEnablePeerAccess(args) { \
	printf("\tint peerDeviceId = %d\n", args->hipDeviceEnablePeerAccess.peerDeviceId); \
	printf("\tunsigned int flags = %u\n", args->hipDeviceEnablePeerAccess.flags); \
};

//	hipMemGenericAllocationHandle_t * handle (unknown);
//	void * addr (void*);
#define PROCESS_ARGS_hipMemRetainAllocationHandle(args) { \
	printf("\thipMemGenericAllocationHandle_t * handle = N/A, try to update csv files\n"); \
	printf("\tvoid * addr = %p", args->hipMemRetainAllocationHandle.addr); \
	printf("\n"); \
};

//	hipMipmappedArray_t* pArray (unknown);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipMappedArray(args) { \
	printf("\thipMipmappedArray_t* pArray = N/A, try to update csv files\n"); \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	float * pbias (float*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipmapLevelBias(args) { \
	printf("\tfloat * pbias = %p", args->hipTexRefGetMipmapLevelBias.pbias); \
	if (args->hipTexRefGetMipmapLevelBias.pbias != NULL) { \
		printf(" -> %f\n", *args->hipTexRefGetMipmapLevelBias.pbias); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	size_t * offset (unsigned long*);
//	const textureReference* tex (unknown);
//	const void * devPtr (void*);
//	const hipChannelFormatDesc * desc (unknown);
//	size_t size (unsigned long);
#define PROCESS_ARGS_hipBindTexture(args) { \
	printf("\tsize_t * offset = %p", args->hipBindTexture.offset); \
	if (args->hipBindTexture.offset != NULL) { \
		printf(" -> %lu\n", *args->hipBindTexture.offset); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* tex = N/A, try to update csv files\n"); \
	printf("\tconst void * devPtr = %p", args->hipBindTexture.devPtr); \
	printf("\n"); \
	printf("\tconst hipChannelFormatDesc * desc = N/A, try to update csv files\n"); \
	printf("\tsize_t size = %lu\n", args->hipBindTexture.size); \
};

//	hipGraphNode_t * pGraphNode (unknown);
//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * pDependencies (unknown);
//	size_t numDependencies (unsigned long);
//	hipGraph_t childGraph (unknown);
#define PROCESS_ARGS_hipGraphAddChildGraphNode(args) { \
	printf("\thipGraphNode_t * pGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddChildGraphNode.numDependencies); \
	printf("\thipGraph_t childGraph = N/A, try to update csv files\n"); \
};

//	enum hipLimit_t limit (enum);
//	size_t value (unsigned long);
#define PROCESS_ARGS_hipDeviceSetLimit(args) { \
	printf("\tenum hipLimit_t limit = %d\n", args->hipDeviceSetLimit.limit); \
	printf("\tsize_t value = %lu\n", args->hipDeviceSetLimit.value); \
};

//	hipChannelFormatDesc * desc (unknown);
//	hipArray_const_t array (unknown);
#define PROCESS_ARGS_hipGetChannelDesc(args) { \
	printf("\thipChannelFormatDesc * desc = N/A, try to update csv files\n"); \
	printf("\thipArray_const_t array = N/A, try to update csv files\n"); \
};

//	hipGraphicsResource_t resource (unknown);
#define PROCESS_ARGS_hipGraphicsUnregisterResource(args) { \
	printf("\thipGraphicsResource_t resource = N/A, try to update csv files\n"); \
};

//	hipGraph_t graph (unknown);
//	const hipGraphNode_t * from (unknown);
//	const hipGraphNode_t * to (unknown);
//	size_t numDependencies (unsigned long);
#define PROCESS_ARGS_hipGraphRemoveDependencies(args) { \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * from = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * to = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphRemoveDependencies.numDependencies); \
};

//	textureReference* texRef (unknown);
//	float * pBorderColor (float*);
#define PROCESS_ARGS_hipTexRefSetBorderColor(args) { \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\tfloat * pBorderColor = %p", args->hipTexRefSetBorderColor.pBorderColor); \
	if (args->hipTexRefSetBorderColor.pBorderColor != NULL) { \
		printf(" -> %f\n", *args->hipTexRefSetBorderColor.pBorderColor); \
	} else { printf("\n"); }; \
};

//	hipDevice_t dev (int);
//	unsigned int * flags (unsigned int*);
//	int * active (int*);
#define PROCESS_ARGS_hipDevicePrimaryCtxGetState(args) { \
	printf("\thipDevice_t dev = %d\n", args->hipDevicePrimaryCtxGetState.dev); \
	printf("\tunsigned int * flags = %p", args->hipDevicePrimaryCtxGetState.flags); \
	if (args->hipDevicePrimaryCtxGetState.flags != NULL) { \
		printf(" -> %u\n", *args->hipDevicePrimaryCtxGetState.flags); \
	} else { printf("\n"); }; \
	printf("\tint * active = %p", args->hipDevicePrimaryCtxGetState.active); \
	if (args->hipDevicePrimaryCtxGetState.active != NULL) { \
		printf(" -> %d\n", *args->hipDevicePrimaryCtxGetState.active); \
	} else { printf("\n"); }; \
};

//	hipPitchedPtr* pitchedDevPtr (unknown);
//	hipExtent extent (unknown);
#define PROCESS_ARGS_hipMalloc3D(args) { \
	printf("\thipPitchedPtr* pitchedDevPtr = N/A, try to update csv files\n"); \
	printf("\thipExtent extent = N/A, try to update csv files\n"); \
};

//	float * pminMipmapLevelClamp (float*);
//	float * pmaxMipmapLevelClamp (float*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipmapLevelClamp(args) { \
	printf("\tfloat * pminMipmapLevelClamp = %p", args->hipTexRefGetMipmapLevelClamp.pminMipmapLevelClamp); \
	if (args->hipTexRefGetMipmapLevelClamp.pminMipmapLevelClamp != NULL) { \
		printf(" -> %f\n", *args->hipTexRefGetMipmapLevelClamp.pminMipmapLevelClamp); \
	} else { printf("\n"); }; \
	printf("\tfloat * pmaxMipmapLevelClamp = %p", args->hipTexRefGetMipmapLevelClamp.pmaxMipmapLevelClamp); \
	if (args->hipTexRefGetMipmapLevelClamp.pmaxMipmapLevelClamp != NULL) { \
		printf(" -> %f\n", *args->hipTexRefGetMipmapLevelClamp.pmaxMipmapLevelClamp); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
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
	printf("\thipFunction_t f = N/A, try to update csv files\n"); \
	printf("\tunsigned int gridDimX = %u\n", args->hipModuleLaunchKernel.gridDimX); \
	printf("\tunsigned int gridDimY = %u\n", args->hipModuleLaunchKernel.gridDimY); \
	printf("\tunsigned int gridDimZ = %u\n", args->hipModuleLaunchKernel.gridDimZ); \
	printf("\tunsigned int blockDimX = %u\n", args->hipModuleLaunchKernel.blockDimX); \
	printf("\tunsigned int blockDimY = %u\n", args->hipModuleLaunchKernel.blockDimY); \
	printf("\tunsigned int blockDimZ = %u\n", args->hipModuleLaunchKernel.blockDimZ); \
	printf("\tunsigned int sharedMemBytes = %u\n", args->hipModuleLaunchKernel.sharedMemBytes); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\tvoid ** kernelParams = %p", args->hipModuleLaunchKernel.kernelParams); \
	if (args->hipModuleLaunchKernel.kernelParams != NULL) { \
		printf("-> %p", *args->hipModuleLaunchKernel.kernelParams); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tvoid ** extra = %p", args->hipModuleLaunchKernel.extra); \
	if (args->hipModuleLaunchKernel.extra != NULL) { \
		printf("-> %p", *args->hipModuleLaunchKernel.extra); \
		printf("\n"); \
	} else { printf("\n"); }; \
};

//	const void * hostFunction (void*);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipKernelNameRefByPtr(args) { \
	printf("\tconst void * hostFunction = %p", args->hipKernelNameRefByPtr.hostFunction); \
	printf("\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipSharedMemConfig config (enum);
#define PROCESS_ARGS_hipDeviceSetSharedMemConfig(args) { \
	printf("\thipSharedMemConfig config = %d\n", args->hipDeviceSetSharedMemConfig.config); \
};

//	const void * symbol (void*);
//	const void * src (void*);
//	size_t sizeBytes (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyToSymbolAsync(args) { \
	printf("\tconst void * symbol = %p", args->hipMemcpyToSymbolAsync.symbol); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipMemcpyToSymbolAsync.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyToSymbolAsync.sizeBytes); \
	printf("\tsize_t offset = %lu\n", args->hipMemcpyToSymbolAsync.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	void ** devPtr (void**);
//	void * hstPtr (void*);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipHostGetDevicePointer(args) { \
	printf("\tvoid ** devPtr = %p", args->hipHostGetDevicePointer.devPtr); \
	if (args->hipHostGetDevicePointer.devPtr != NULL) { \
		printf("-> %p", *args->hipHostGetDevicePointer.devPtr); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tvoid * hstPtr = %p", args->hipHostGetDevicePointer.hstPtr); \
	printf("\n"); \
	printf("\tunsigned int flags = %u\n", args->hipHostGetDevicePointer.flags); \
};

//	hipGraph_t graph (unknown);
//	hipUserObject_t object (unknown);
//	unsigned int count (unsigned int);
#define PROCESS_ARGS_hipGraphReleaseUserObject(args) { \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\thipUserObject_t object = N/A, try to update csv files\n"); \
	printf("\tunsigned int count = %u\n", args->hipGraphReleaseUserObject.count); \
};

//	int device (int);
#define PROCESS_ARGS_hipDeviceGraphMemTrim(args) { \
	printf("\tint device = %d\n", args->hipDeviceGraphMemTrim.device); \
};

//	int * leastPriority (int*);
//	int * greatestPriority (int*);
#define PROCESS_ARGS_hipDeviceGetStreamPriorityRange(args) { \
	printf("\tint * leastPriority = %p", args->hipDeviceGetStreamPriorityRange.leastPriority); \
	if (args->hipDeviceGetStreamPriorityRange.leastPriority != NULL) { \
		printf(" -> %d\n", *args->hipDeviceGetStreamPriorityRange.leastPriority); \
	} else { printf("\n"); }; \
	printf("\tint * greatestPriority = %p", args->hipDeviceGetStreamPriorityRange.greatestPriority); \
	if (args->hipDeviceGetStreamPriorityRange.greatestPriority != NULL) { \
		printf(" -> %d\n", *args->hipDeviceGetStreamPriorityRange.greatestPriority); \
	} else { printf("\n"); }; \
};

//	void * data (void*);
//	hipPointer_attribute attribute (unknown);
//	hipDeviceptr_t ptr (unknown);
#define PROCESS_ARGS_hipPointerGetAttribute(args) { \
	printf("\tvoid * data = %p", args->hipPointerGetAttribute.data); \
	printf("\n"); \
	printf("\thipPointer_attribute attribute = N/A, try to update csv files\n"); \
	printf("\thipDeviceptr_t ptr = N/A, try to update csv files\n"); \
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
	printf("\thipMemPool_t mem_pool = N/A, try to update csv files\n"); \
	printf("\tstruct const hipMemAccessDesc * desc_list = %p", args->hipMemPoolSetAccess.desc_list); \
	if (args->hipMemPoolSetAccess.desc_list != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tstruct hipMemLocation location = {\n"); \
		printf("\t\t\thipMemLocationType type = %d\n", ((*args->hipMemPoolSetAccess.desc_list).location).type); \
		printf("\t\t\tint id = %d\n", ((*args->hipMemPoolSetAccess.desc_list).location).id); \
		printf("\t\t}\n"); \
		printf("\t\thipMemAccessFlags flags = %d\n", (*args->hipMemPoolSetAccess.desc_list).flags); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tsize_t count = %lu\n", args->hipMemPoolSetAccess.count); \
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
	printf("\thipGraphExec_t hGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t hNode = N/A, try to update csv files\n"); \
	printf("\tstruct const hipExternalSemaphoreWaitNodeParams * nodeParams = %p", args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams); \
	if (args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipExternalSemaphore_t * extSemArray = %p", (*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).extSemArray); \
		if ((*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).extSemArray != NULL) { \
			printf("-> %p", *(*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).extSemArray); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tstruct const hipExternalSemaphoreWaitParams * paramsArray = %p", (*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray); \
		if ((*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray != NULL) { \
			printf(" -> {\n"); \
			printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1156:3) params = N/A, try to update csv files\n"); \
			printf("\t\t\tunsigned int flags = %u\n", (*(*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).flags); \
			printf("\t\t\tunsigned int[16] reserved = %p", (*(*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).reserved); \
			if ((*(*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).reserved != NULL) { \
				printf(" -> %u\n", *(*(*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).paramsArray).reserved); \
			} else { printf("\n"); }; \
			printf("\t\t}\n"); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int numExtSems = %u\n", (*args->hipGraphExecExternalSemaphoresWaitNodeSetParams.nodeParams).numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	void * dst (void*);
//	const void * src (void*);
//	size_t sizeBytes (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipMemcpy(args) { \
	printf("\tvoid * dst = %p", args->hipMemcpy.dst); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipMemcpy.src); \
	printf("\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpy.sizeBytes); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	int peerDeviceId (int);
#define PROCESS_ARGS_hipDeviceDisablePeerAccess(args) { \
	printf("\tint peerDeviceId = %d\n", args->hipDeviceDisablePeerAccess.peerDeviceId); \
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
	printf("\thipGraphNode_t hNode = N/A, try to update csv files\n"); \
	printf("\thipKernelNodeAttrID attr = %d\n", args->hipGraphKernelNodeSetAttribute.attr); \
	printf("\tunion const hipKernelNodeAttrValue * value = %p", args->hipGraphKernelNodeSetAttribute.value); \
	if (args->hipGraphKernelNodeSetAttribute.value != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tstruct hipAccessPolicyWindow accessPolicyWindow = {\n"); \
		printf("\t\t\tvoid * base_ptr = %p", ((*args->hipGraphKernelNodeSetAttribute.value).accessPolicyWindow).base_ptr); \
		printf("\n"); \
		printf("\t\t\thipAccessProperty hitProp = %d\n", ((*args->hipGraphKernelNodeSetAttribute.value).accessPolicyWindow).hitProp); \
		printf("\t\t\tfloat hitRatio = %f\n", ((*args->hipGraphKernelNodeSetAttribute.value).accessPolicyWindow).hitRatio); \
		printf("\t\t\thipAccessProperty missProp = %d\n", ((*args->hipGraphKernelNodeSetAttribute.value).accessPolicyWindow).missProp); \
		printf("\t\t\tint num_bytes = %d\n", ((*args->hipGraphKernelNodeSetAttribute.value).accessPolicyWindow).num_bytes); \
		printf("\t\t}\n"); \
		printf("\t\tint cooperative = %d\n", (*args->hipGraphKernelNodeSetAttribute.value).cooperative); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
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
	printf("\thipGraphNode_t * pGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddMemcpyNode1D.numDependencies); \
	printf("\tvoid * dst = %p", args->hipGraphAddMemcpyNode1D.dst); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipGraphAddMemcpyNode1D.src); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipGraphAddMemcpyNode1D.count); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t hNode (unknown);
//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipGraphExecEventRecordNodeSetEvent(args) { \
	printf("\thipGraphExec_t hGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t hNode = N/A, try to update csv files\n"); \
	printf("\thipEvent_t event = N/A, try to update csv files\n"); \
};

//	int count (int);
//	hipGraphicsResource_t * resources (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipGraphicsUnmapResources(args) { \
	printf("\tint count = %d\n", args->hipGraphicsUnmapResources.count); \
	printf("\thipGraphicsResource_t * resources = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
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
	printf("\thipGraphNode_t * pGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddExternalSemaphoresWaitNode.numDependencies); \
	printf("\tstruct const hipExternalSemaphoreWaitNodeParams * nodeParams = %p", args->hipGraphAddExternalSemaphoresWaitNode.nodeParams); \
	if (args->hipGraphAddExternalSemaphoresWaitNode.nodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipExternalSemaphore_t * extSemArray = %p", (*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).extSemArray); \
		if ((*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).extSemArray != NULL) { \
			printf("-> %p", *(*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).extSemArray); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tstruct const hipExternalSemaphoreWaitParams * paramsArray = %p", (*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).paramsArray); \
		if ((*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).paramsArray != NULL) { \
			printf(" -> {\n"); \
			printf("\t\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1156:3) params = N/A, try to update csv files\n"); \
			printf("\t\t\tunsigned int flags = %u\n", (*(*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).paramsArray).flags); \
			printf("\t\t\tunsigned int[16] reserved = %p", (*(*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).paramsArray).reserved); \
			if ((*(*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).paramsArray).reserved != NULL) { \
				printf(" -> %u\n", *(*(*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).paramsArray).reserved); \
			} else { printf("\n"); }; \
			printf("\t\t}\n"); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int numExtSems = %u\n", (*args->hipGraphAddExternalSemaphoresWaitNode.nodeParams).numExtSems); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraphNode_t * phGraphNode (unknown);
//	hipGraph_t hGraph (unknown);
//	const hipGraphNode_t * dependencies (unknown);
//	size_t numDependencies (unsigned long);
//	const HIP_MEMCPY3D * copyParams (unknown);
//	hipCtx_t ctx (unknown);
#define PROCESS_ARGS_hipDrvGraphAddMemcpyNode(args) { \
	printf("\thipGraphNode_t * phGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t hGraph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * dependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipDrvGraphAddMemcpyNode.numDependencies); \
	printf("\tconst HIP_MEMCPY3D * copyParams = N/A, try to update csv files\n"); \
	printf("\thipCtx_t ctx = N/A, try to update csv files\n"); \
};

//	float * ms (float*);
//	hipEvent_t start (unknown);
//	hipEvent_t stop (unknown);
#define PROCESS_ARGS_hipEventElapsedTime(args) { \
	printf("\tfloat * ms = %p", args->hipEventElapsedTime.ms); \
	if (args->hipEventElapsedTime.ms != NULL) { \
		printf(" -> %f\n", *args->hipEventElapsedTime.ms); \
	} else { printf("\n"); }; \
	printf("\thipEvent_t start = N/A, try to update csv files\n"); \
	printf("\thipEvent_t stop = N/A, try to update csv files\n"); \
};

//	const struct hipMemcpy3DParms * p (unknown);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpy3DAsync(args) { \
	printf("\tconst struct hipMemcpy3DParms * p = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	int * pmaxAnsio (int*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMaxAnisotropy(args) { \
	printf("\tint * pmaxAnsio = %p", args->hipTexRefGetMaxAnisotropy.pmaxAnsio); \
	if (args->hipTexRefGetMaxAnisotropy.pmaxAnsio != NULL) { \
		printf(" -> %d\n", *args->hipTexRefGetMaxAnisotropy.pmaxAnsio); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t node (unknown);
//	hipGraphNode_t * pDependentNodes (unknown);
//	size_t * pNumDependentNodes (unsigned long*);
#define PROCESS_ARGS_hipGraphNodeGetDependentNodes(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t * pDependentNodes = N/A, try to update csv files\n"); \
	printf("\tsize_t * pNumDependentNodes = %p", args->hipGraphNodeGetDependentNodes.pNumDependentNodes); \
	if (args->hipGraphNodeGetDependentNodes.pNumDependentNodes != NULL) { \
		printf(" -> %lu\n", *args->hipGraphNodeGetDependentNodes.pNumDependentNodes); \
	} else { printf("\n"); }; \
};

//	hipMemPool_t mem_pool (unknown);
//	hipMemPoolAttr attr (enum);
//	void * value (void*);
#define PROCESS_ARGS_hipMemPoolGetAttribute(args) { \
	printf("\thipMemPool_t mem_pool = N/A, try to update csv files\n"); \
	printf("\thipMemPoolAttr attr = %d\n", args->hipMemPoolGetAttribute.attr); \
	printf("\tvoid * value = %p", args->hipMemPoolGetAttribute.value); \
	printf("\n"); \
};

//	hipStream_t stream (unknown);
//	hipDevice_t * device (int*);
#define PROCESS_ARGS_hipStreamGetDevice(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\thipDevice_t * device = %p", args->hipStreamGetDevice.device); \
	if (args->hipStreamGetDevice.device != NULL) { \
		printf(" -> %d\n", *args->hipStreamGetDevice.device); \
	} else { printf("\n"); }; \
};

//	hipResourceDesc* pResDesc (unknown);
//	hipTextureObject_t textureObject (unknown);
#define PROCESS_ARGS_hipGetTextureObjectResourceDesc(args) { \
	printf("\thipResourceDesc* pResDesc = N/A, try to update csv files\n"); \
	printf("\thipTextureObject_t textureObject = N/A, try to update csv files\n"); \
};

//	unsigned int * pFlags (unsigned int*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetFlags(args) { \
	printf("\tunsigned int * pFlags = %p", args->hipTexRefGetFlags.pFlags); \
	if (args->hipTexRefGetFlags.pFlags != NULL) { \
		printf(" -> %u\n", *args->hipTexRefGetFlags.pFlags); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
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
	printf("\tint * device = %p", args->hipChooseDeviceR0600.device); \
	if (args->hipChooseDeviceR0600.device != NULL) { \
		printf(" -> %d\n", *args->hipChooseDeviceR0600.device); \
	} else { printf("\n"); }; \
	printf("\tstruct const hipDeviceProp_tR0600 * prop = %p", args->hipChooseDeviceR0600.prop); \
	if (args->hipChooseDeviceR0600.prop != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tchar[256] name = %p", (*args->hipChooseDeviceR0600.prop).name); \
		if ((*args->hipChooseDeviceR0600.prop).name != NULL) { \
			printf(" -> %c\n", *(*args->hipChooseDeviceR0600.prop).name); \
		} else { printf("\n"); }; \
		printf("\t\tstruct hipUUID uuid = {\n"); \
		printf("\t\t\tchar[16] bytes = %p", ((*args->hipChooseDeviceR0600.prop).uuid).bytes); \
		if (((*args->hipChooseDeviceR0600.prop).uuid).bytes != NULL) { \
			printf(" -> %c\n", *((*args->hipChooseDeviceR0600.prop).uuid).bytes); \
		} else { printf("\n"); }; \
		printf("\t\t}\n"); \
		printf("\t\tchar[8] luid = %p", (*args->hipChooseDeviceR0600.prop).luid); \
		if ((*args->hipChooseDeviceR0600.prop).luid != NULL) { \
			printf(" -> %c\n", *(*args->hipChooseDeviceR0600.prop).luid); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int luidDeviceNodeMask = %u\n", (*args->hipChooseDeviceR0600.prop).luidDeviceNodeMask); \
		printf("\t\tint totalGlobalMem = %d\n", (*args->hipChooseDeviceR0600.prop).totalGlobalMem); \
		printf("\t\tint sharedMemPerBlock = %d\n", (*args->hipChooseDeviceR0600.prop).sharedMemPerBlock); \
		printf("\t\tint regsPerBlock = %d\n", (*args->hipChooseDeviceR0600.prop).regsPerBlock); \
		printf("\t\tint warpSize = %d\n", (*args->hipChooseDeviceR0600.prop).warpSize); \
		printf("\t\tint memPitch = %d\n", (*args->hipChooseDeviceR0600.prop).memPitch); \
		printf("\t\tint maxThreadsPerBlock = %d\n", (*args->hipChooseDeviceR0600.prop).maxThreadsPerBlock); \
		printf("\t\tint[3] maxThreadsDim = %p", (*args->hipChooseDeviceR0600.prop).maxThreadsDim); \
		if ((*args->hipChooseDeviceR0600.prop).maxThreadsDim != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxThreadsDim); \
		} else { printf("\n"); }; \
		printf("\t\tint[3] maxGridSize = %p", (*args->hipChooseDeviceR0600.prop).maxGridSize); \
		if ((*args->hipChooseDeviceR0600.prop).maxGridSize != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxGridSize); \
		} else { printf("\n"); }; \
		printf("\t\tint clockRate = %d\n", (*args->hipChooseDeviceR0600.prop).clockRate); \
		printf("\t\tint totalConstMem = %d\n", (*args->hipChooseDeviceR0600.prop).totalConstMem); \
		printf("\t\tint major = %d\n", (*args->hipChooseDeviceR0600.prop).major); \
		printf("\t\tint minor = %d\n", (*args->hipChooseDeviceR0600.prop).minor); \
		printf("\t\tint textureAlignment = %d\n", (*args->hipChooseDeviceR0600.prop).textureAlignment); \
		printf("\t\tint texturePitchAlignment = %d\n", (*args->hipChooseDeviceR0600.prop).texturePitchAlignment); \
		printf("\t\tint deviceOverlap = %d\n", (*args->hipChooseDeviceR0600.prop).deviceOverlap); \
		printf("\t\tint multiProcessorCount = %d\n", (*args->hipChooseDeviceR0600.prop).multiProcessorCount); \
		printf("\t\tint kernelExecTimeoutEnabled = %d\n", (*args->hipChooseDeviceR0600.prop).kernelExecTimeoutEnabled); \
		printf("\t\tint integrated = %d\n", (*args->hipChooseDeviceR0600.prop).integrated); \
		printf("\t\tint canMapHostMemory = %d\n", (*args->hipChooseDeviceR0600.prop).canMapHostMemory); \
		printf("\t\tint computeMode = %d\n", (*args->hipChooseDeviceR0600.prop).computeMode); \
		printf("\t\tint maxTexture1D = %d\n", (*args->hipChooseDeviceR0600.prop).maxTexture1D); \
		printf("\t\tint maxTexture1DMipmap = %d\n", (*args->hipChooseDeviceR0600.prop).maxTexture1DMipmap); \
		printf("\t\tint maxTexture1DLinear = %d\n", (*args->hipChooseDeviceR0600.prop).maxTexture1DLinear); \
		printf("\t\tint[2] maxTexture2D = %p", (*args->hipChooseDeviceR0600.prop).maxTexture2D); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture2D != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxTexture2D); \
		} else { printf("\n"); }; \
		printf("\t\tint[2] maxTexture2DMipmap = %p", (*args->hipChooseDeviceR0600.prop).maxTexture2DMipmap); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture2DMipmap != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxTexture2DMipmap); \
		} else { printf("\n"); }; \
		printf("\t\tint[3] maxTexture2DLinear = %p", (*args->hipChooseDeviceR0600.prop).maxTexture2DLinear); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture2DLinear != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxTexture2DLinear); \
		} else { printf("\n"); }; \
		printf("\t\tint[2] maxTexture2DGather = %p", (*args->hipChooseDeviceR0600.prop).maxTexture2DGather); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture2DGather != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxTexture2DGather); \
		} else { printf("\n"); }; \
		printf("\t\tint[3] maxTexture3D = %p", (*args->hipChooseDeviceR0600.prop).maxTexture3D); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture3D != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxTexture3D); \
		} else { printf("\n"); }; \
		printf("\t\tint[3] maxTexture3DAlt = %p", (*args->hipChooseDeviceR0600.prop).maxTexture3DAlt); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture3DAlt != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxTexture3DAlt); \
		} else { printf("\n"); }; \
		printf("\t\tint maxTextureCubemap = %d\n", (*args->hipChooseDeviceR0600.prop).maxTextureCubemap); \
		printf("\t\tint[2] maxTexture1DLayered = %p", (*args->hipChooseDeviceR0600.prop).maxTexture1DLayered); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture1DLayered != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxTexture1DLayered); \
		} else { printf("\n"); }; \
		printf("\t\tint[3] maxTexture2DLayered = %p", (*args->hipChooseDeviceR0600.prop).maxTexture2DLayered); \
		if ((*args->hipChooseDeviceR0600.prop).maxTexture2DLayered != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxTexture2DLayered); \
		} else { printf("\n"); }; \
		printf("\t\tint[2] maxTextureCubemapLayered = %p", (*args->hipChooseDeviceR0600.prop).maxTextureCubemapLayered); \
		if ((*args->hipChooseDeviceR0600.prop).maxTextureCubemapLayered != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxTextureCubemapLayered); \
		} else { printf("\n"); }; \
		printf("\t\tint maxSurface1D = %d\n", (*args->hipChooseDeviceR0600.prop).maxSurface1D); \
		printf("\t\tint[2] maxSurface2D = %p", (*args->hipChooseDeviceR0600.prop).maxSurface2D); \
		if ((*args->hipChooseDeviceR0600.prop).maxSurface2D != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxSurface2D); \
		} else { printf("\n"); }; \
		printf("\t\tint[3] maxSurface3D = %p", (*args->hipChooseDeviceR0600.prop).maxSurface3D); \
		if ((*args->hipChooseDeviceR0600.prop).maxSurface3D != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxSurface3D); \
		} else { printf("\n"); }; \
		printf("\t\tint[2] maxSurface1DLayered = %p", (*args->hipChooseDeviceR0600.prop).maxSurface1DLayered); \
		if ((*args->hipChooseDeviceR0600.prop).maxSurface1DLayered != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxSurface1DLayered); \
		} else { printf("\n"); }; \
		printf("\t\tint[3] maxSurface2DLayered = %p", (*args->hipChooseDeviceR0600.prop).maxSurface2DLayered); \
		if ((*args->hipChooseDeviceR0600.prop).maxSurface2DLayered != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxSurface2DLayered); \
		} else { printf("\n"); }; \
		printf("\t\tint maxSurfaceCubemap = %d\n", (*args->hipChooseDeviceR0600.prop).maxSurfaceCubemap); \
		printf("\t\tint[2] maxSurfaceCubemapLayered = %p", (*args->hipChooseDeviceR0600.prop).maxSurfaceCubemapLayered); \
		if ((*args->hipChooseDeviceR0600.prop).maxSurfaceCubemapLayered != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).maxSurfaceCubemapLayered); \
		} else { printf("\n"); }; \
		printf("\t\tint surfaceAlignment = %d\n", (*args->hipChooseDeviceR0600.prop).surfaceAlignment); \
		printf("\t\tint concurrentKernels = %d\n", (*args->hipChooseDeviceR0600.prop).concurrentKernels); \
		printf("\t\tint ECCEnabled = %d\n", (*args->hipChooseDeviceR0600.prop).ECCEnabled); \
		printf("\t\tint pciBusID = %d\n", (*args->hipChooseDeviceR0600.prop).pciBusID); \
		printf("\t\tint pciDeviceID = %d\n", (*args->hipChooseDeviceR0600.prop).pciDeviceID); \
		printf("\t\tint pciDomainID = %d\n", (*args->hipChooseDeviceR0600.prop).pciDomainID); \
		printf("\t\tint tccDriver = %d\n", (*args->hipChooseDeviceR0600.prop).tccDriver); \
		printf("\t\tint asyncEngineCount = %d\n", (*args->hipChooseDeviceR0600.prop).asyncEngineCount); \
		printf("\t\tint unifiedAddressing = %d\n", (*args->hipChooseDeviceR0600.prop).unifiedAddressing); \
		printf("\t\tint memoryClockRate = %d\n", (*args->hipChooseDeviceR0600.prop).memoryClockRate); \
		printf("\t\tint memoryBusWidth = %d\n", (*args->hipChooseDeviceR0600.prop).memoryBusWidth); \
		printf("\t\tint l2CacheSize = %d\n", (*args->hipChooseDeviceR0600.prop).l2CacheSize); \
		printf("\t\tint persistingL2CacheMaxSize = %d\n", (*args->hipChooseDeviceR0600.prop).persistingL2CacheMaxSize); \
		printf("\t\tint maxThreadsPerMultiProcessor = %d\n", (*args->hipChooseDeviceR0600.prop).maxThreadsPerMultiProcessor); \
		printf("\t\tint streamPrioritiesSupported = %d\n", (*args->hipChooseDeviceR0600.prop).streamPrioritiesSupported); \
		printf("\t\tint globalL1CacheSupported = %d\n", (*args->hipChooseDeviceR0600.prop).globalL1CacheSupported); \
		printf("\t\tint localL1CacheSupported = %d\n", (*args->hipChooseDeviceR0600.prop).localL1CacheSupported); \
		printf("\t\tint sharedMemPerMultiprocessor = %d\n", (*args->hipChooseDeviceR0600.prop).sharedMemPerMultiprocessor); \
		printf("\t\tint regsPerMultiprocessor = %d\n", (*args->hipChooseDeviceR0600.prop).regsPerMultiprocessor); \
		printf("\t\tint managedMemory = %d\n", (*args->hipChooseDeviceR0600.prop).managedMemory); \
		printf("\t\tint isMultiGpuBoard = %d\n", (*args->hipChooseDeviceR0600.prop).isMultiGpuBoard); \
		printf("\t\tint multiGpuBoardGroupID = %d\n", (*args->hipChooseDeviceR0600.prop).multiGpuBoardGroupID); \
		printf("\t\tint hostNativeAtomicSupported = %d\n", (*args->hipChooseDeviceR0600.prop).hostNativeAtomicSupported); \
		printf("\t\tint singleToDoublePrecisionPerfRatio = %d\n", (*args->hipChooseDeviceR0600.prop).singleToDoublePrecisionPerfRatio); \
		printf("\t\tint pageableMemoryAccess = %d\n", (*args->hipChooseDeviceR0600.prop).pageableMemoryAccess); \
		printf("\t\tint concurrentManagedAccess = %d\n", (*args->hipChooseDeviceR0600.prop).concurrentManagedAccess); \
		printf("\t\tint computePreemptionSupported = %d\n", (*args->hipChooseDeviceR0600.prop).computePreemptionSupported); \
		printf("\t\tint canUseHostPointerForRegisteredMem = %d\n", (*args->hipChooseDeviceR0600.prop).canUseHostPointerForRegisteredMem); \
		printf("\t\tint cooperativeLaunch = %d\n", (*args->hipChooseDeviceR0600.prop).cooperativeLaunch); \
		printf("\t\tint cooperativeMultiDeviceLaunch = %d\n", (*args->hipChooseDeviceR0600.prop).cooperativeMultiDeviceLaunch); \
		printf("\t\tint sharedMemPerBlockOptin = %d\n", (*args->hipChooseDeviceR0600.prop).sharedMemPerBlockOptin); \
		printf("\t\tint pageableMemoryAccessUsesHostPageTables = %d\n", (*args->hipChooseDeviceR0600.prop).pageableMemoryAccessUsesHostPageTables); \
		printf("\t\tint directManagedMemAccessFromHost = %d\n", (*args->hipChooseDeviceR0600.prop).directManagedMemAccessFromHost); \
		printf("\t\tint maxBlocksPerMultiProcessor = %d\n", (*args->hipChooseDeviceR0600.prop).maxBlocksPerMultiProcessor); \
		printf("\t\tint accessPolicyMaxWindowSize = %d\n", (*args->hipChooseDeviceR0600.prop).accessPolicyMaxWindowSize); \
		printf("\t\tint reservedSharedMemPerBlock = %d\n", (*args->hipChooseDeviceR0600.prop).reservedSharedMemPerBlock); \
		printf("\t\tint hostRegisterSupported = %d\n", (*args->hipChooseDeviceR0600.prop).hostRegisterSupported); \
		printf("\t\tint sparseHipArraySupported = %d\n", (*args->hipChooseDeviceR0600.prop).sparseHipArraySupported); \
		printf("\t\tint hostRegisterReadOnlySupported = %d\n", (*args->hipChooseDeviceR0600.prop).hostRegisterReadOnlySupported); \
		printf("\t\tint timelineSemaphoreInteropSupported = %d\n", (*args->hipChooseDeviceR0600.prop).timelineSemaphoreInteropSupported); \
		printf("\t\tint memoryPoolsSupported = %d\n", (*args->hipChooseDeviceR0600.prop).memoryPoolsSupported); \
		printf("\t\tint gpuDirectRDMASupported = %d\n", (*args->hipChooseDeviceR0600.prop).gpuDirectRDMASupported); \
		printf("\t\tunsigned int gpuDirectRDMAFlushWritesOptions = %u\n", (*args->hipChooseDeviceR0600.prop).gpuDirectRDMAFlushWritesOptions); \
		printf("\t\tint gpuDirectRDMAWritesOrdering = %d\n", (*args->hipChooseDeviceR0600.prop).gpuDirectRDMAWritesOrdering); \
		printf("\t\tunsigned int memoryPoolSupportedHandleTypes = %u\n", (*args->hipChooseDeviceR0600.prop).memoryPoolSupportedHandleTypes); \
		printf("\t\tint deferredMappingHipArraySupported = %d\n", (*args->hipChooseDeviceR0600.prop).deferredMappingHipArraySupported); \
		printf("\t\tint ipcEventSupported = %d\n", (*args->hipChooseDeviceR0600.prop).ipcEventSupported); \
		printf("\t\tint clusterLaunch = %d\n", (*args->hipChooseDeviceR0600.prop).clusterLaunch); \
		printf("\t\tint unifiedFunctionPointers = %d\n", (*args->hipChooseDeviceR0600.prop).unifiedFunctionPointers); \
		printf("\t\tint[63] reserved = %p", (*args->hipChooseDeviceR0600.prop).reserved); \
		if ((*args->hipChooseDeviceR0600.prop).reserved != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).reserved); \
		} else { printf("\n"); }; \
		printf("\t\tint[32] hipReserved = %p", (*args->hipChooseDeviceR0600.prop).hipReserved); \
		if ((*args->hipChooseDeviceR0600.prop).hipReserved != NULL) { \
			printf(" -> %d\n", *(*args->hipChooseDeviceR0600.prop).hipReserved); \
		} else { printf("\n"); }; \
		printf("\t\tchar[256] gcnArchName = %p", (*args->hipChooseDeviceR0600.prop).gcnArchName); \
		if ((*args->hipChooseDeviceR0600.prop).gcnArchName != NULL) { \
			printf(" -> %c\n", *(*args->hipChooseDeviceR0600.prop).gcnArchName); \
		} else { printf("\n"); }; \
		printf("\t\tint maxSharedMemoryPerMultiProcessor = %d\n", (*args->hipChooseDeviceR0600.prop).maxSharedMemoryPerMultiProcessor); \
		printf("\t\tint clockInstructionRate = %d\n", (*args->hipChooseDeviceR0600.prop).clockInstructionRate); \
		printf("\t\tstruct hipDeviceArch_t arch = {\n"); \
		printf("\t\t\tunsigned int hasGlobalInt32Atomics = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasGlobalInt32Atomics); \
		printf("\t\t\tunsigned int hasGlobalFloatAtomicExch = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasGlobalFloatAtomicExch); \
		printf("\t\t\tunsigned int hasSharedInt32Atomics = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasSharedInt32Atomics); \
		printf("\t\t\tunsigned int hasSharedFloatAtomicExch = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasSharedFloatAtomicExch); \
		printf("\t\t\tunsigned int hasFloatAtomicAdd = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasFloatAtomicAdd); \
		printf("\t\t\tunsigned int hasGlobalInt64Atomics = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasGlobalInt64Atomics); \
		printf("\t\t\tunsigned int hasSharedInt64Atomics = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasSharedInt64Atomics); \
		printf("\t\t\tunsigned int hasDoubles = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasDoubles); \
		printf("\t\t\tunsigned int hasWarpVote = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasWarpVote); \
		printf("\t\t\tunsigned int hasWarpBallot = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasWarpBallot); \
		printf("\t\t\tunsigned int hasWarpShuffle = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasWarpShuffle); \
		printf("\t\t\tunsigned int hasFunnelShift = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasFunnelShift); \
		printf("\t\t\tunsigned int hasThreadFenceSystem = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasThreadFenceSystem); \
		printf("\t\t\tunsigned int hasSyncThreadsExt = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasSyncThreadsExt); \
		printf("\t\t\tunsigned int hasSurfaceFuncs = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasSurfaceFuncs); \
		printf("\t\t\tunsigned int has3dGrid = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).has3dGrid); \
		printf("\t\t\tunsigned int hasDynamicParallelism = %u\n", ((*args->hipChooseDeviceR0600.prop).arch).hasDynamicParallelism); \
		printf("\t\t}\n"); \
		printf("\t\tunsigned int * hdpMemFlushCntl = %p", (*args->hipChooseDeviceR0600.prop).hdpMemFlushCntl); \
		if ((*args->hipChooseDeviceR0600.prop).hdpMemFlushCntl != NULL) { \
			printf(" -> %u\n", *(*args->hipChooseDeviceR0600.prop).hdpMemFlushCntl); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int * hdpRegFlushCntl = %p", (*args->hipChooseDeviceR0600.prop).hdpRegFlushCntl); \
		if ((*args->hipChooseDeviceR0600.prop).hdpRegFlushCntl != NULL) { \
			printf(" -> %u\n", *(*args->hipChooseDeviceR0600.prop).hdpRegFlushCntl); \
		} else { printf("\n"); }; \
		printf("\t\tint cooperativeMultiDeviceUnmatchedFunc = %d\n", (*args->hipChooseDeviceR0600.prop).cooperativeMultiDeviceUnmatchedFunc); \
		printf("\t\tint cooperativeMultiDeviceUnmatchedGridDim = %d\n", (*args->hipChooseDeviceR0600.prop).cooperativeMultiDeviceUnmatchedGridDim); \
		printf("\t\tint cooperativeMultiDeviceUnmatchedBlockDim = %d\n", (*args->hipChooseDeviceR0600.prop).cooperativeMultiDeviceUnmatchedBlockDim); \
		printf("\t\tint cooperativeMultiDeviceUnmatchedSharedMem = %d\n", (*args->hipChooseDeviceR0600.prop).cooperativeMultiDeviceUnmatchedSharedMem); \
		printf("\t\tint isLargeBar = %d\n", (*args->hipChooseDeviceR0600.prop).isLargeBar); \
		printf("\t\tint asicRevision = %d\n", (*args->hipChooseDeviceR0600.prop).asicRevision); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
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
	printf("\tconst hipExternalSemaphore_t * extSemArray = %p", args->hipSignalExternalSemaphoresAsync.extSemArray); \
	if (args->hipSignalExternalSemaphoresAsync.extSemArray != NULL) { \
		printf("-> %p", *args->hipSignalExternalSemaphoresAsync.extSemArray); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tstruct const hipExternalSemaphoreSignalParams * paramsArray = %p", args->hipSignalExternalSemaphoresAsync.paramsArray); \
	if (args->hipSignalExternalSemaphoresAsync.paramsArray != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1136:3) params = N/A, try to update csv files\n"); \
		printf("\t\tunsigned int flags = %u\n", (*args->hipSignalExternalSemaphoresAsync.paramsArray).flags); \
		printf("\t\tunsigned int[16] reserved = %p", (*args->hipSignalExternalSemaphoresAsync.paramsArray).reserved); \
		if ((*args->hipSignalExternalSemaphoresAsync.paramsArray).reserved != NULL) { \
			printf(" -> %u\n", *(*args->hipSignalExternalSemaphoresAsync.paramsArray).reserved); \
		} else { printf("\n"); }; \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tunsigned int numExtSems = %u\n", args->hipSignalExternalSemaphoresAsync.numExtSems); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	int * canAccessPeer (int*);
//	int deviceId (int);
//	int peerDeviceId (int);
#define PROCESS_ARGS_hipDeviceCanAccessPeer(args) { \
	printf("\tint * canAccessPeer = %p", args->hipDeviceCanAccessPeer.canAccessPeer); \
	if (args->hipDeviceCanAccessPeer.canAccessPeer != NULL) { \
		printf(" -> %d\n", *args->hipDeviceCanAccessPeer.canAccessPeer); \
	} else { printf("\n"); }; \
	printf("\tint deviceId = %d\n", args->hipDeviceCanAccessPeer.deviceId); \
	printf("\tint peerDeviceId = %d\n", args->hipDeviceCanAccessPeer.peerDeviceId); \
};

//	hipCtx_t * pctx (unknown);
//	hipDevice_t dev (int);
#define PROCESS_ARGS_hipDevicePrimaryCtxRetain(args) { \
	printf("\thipCtx_t * pctx = N/A, try to update csv files\n"); \
	printf("\thipDevice_t dev = %d\n", args->hipDevicePrimaryCtxRetain.dev); \
};

//	hipCtx_t peerCtx (unknown);
#define PROCESS_ARGS_hipCtxDisablePeerAccess(args) { \
	printf("\thipCtx_t peerCtx = N/A, try to update csv files\n"); \
};

//	hipStream_t stream (unknown);
//	int * priority (int*);
#define PROCESS_ARGS_hipStreamGetPriority(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\tint * priority = %p", args->hipStreamGetPriority.priority); \
	if (args->hipStreamGetPriority.priority != NULL) { \
		printf(" -> %d\n", *args->hipStreamGetPriority.priority); \
	} else { printf("\n"); }; \
};

//	hipEvent_t * event (unknown);
#define PROCESS_ARGS_hipEventCreate(args) { \
	printf("\thipEvent_t * event = N/A, try to update csv files\n"); \
};


#define PROCESS_ARGS_hipGetLastError(args) { \
\
};

//	int * major (int*);
//	int * minor (int*);
//	hipDevice_t device (int);
#define PROCESS_ARGS_hipDeviceComputeCapability(args) { \
	printf("\tint * major = %p", args->hipDeviceComputeCapability.major); \
	if (args->hipDeviceComputeCapability.major != NULL) { \
		printf(" -> %d\n", *args->hipDeviceComputeCapability.major); \
	} else { printf("\n"); }; \
	printf("\tint * minor = %p", args->hipDeviceComputeCapability.minor); \
	if (args->hipDeviceComputeCapability.minor != NULL) { \
		printf(" -> %d\n", *args->hipDeviceComputeCapability.minor); \
	} else { printf("\n"); }; \
	printf("\thipDevice_t device = %d\n", args->hipDeviceComputeCapability.device); \
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
	printf("\tstruct hipDeviceProp_tR0600 * prop = %p", args->hipGetDevicePropertiesR0600.prop); \
	if (args->hipGetDevicePropertiesR0600.prop != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tchar[256] name = %p", (*args->hipGetDevicePropertiesR0600.prop).name); \
		if ((*args->hipGetDevicePropertiesR0600.prop).name != NULL) { \
			printf(" -> %c\n", *(*args->hipGetDevicePropertiesR0600.prop).name); \
		} else { printf("\n"); }; \
		printf("\t\tstruct hipUUID uuid = {\n"); \
		printf("\t\t\tchar[16] bytes = %p", ((*args->hipGetDevicePropertiesR0600.prop).uuid).bytes); \
		if (((*args->hipGetDevicePropertiesR0600.prop).uuid).bytes != NULL) { \
			printf(" -> %c\n", *((*args->hipGetDevicePropertiesR0600.prop).uuid).bytes); \
		} else { printf("\n"); }; \
		printf("\t\t}\n"); \
		printf("\t\tchar[8] luid = %p", (*args->hipGetDevicePropertiesR0600.prop).luid); \
		if ((*args->hipGetDevicePropertiesR0600.prop).luid != NULL) { \
			printf(" -> %c\n", *(*args->hipGetDevicePropertiesR0600.prop).luid); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int luidDeviceNodeMask = %u\n", (*args->hipGetDevicePropertiesR0600.prop).luidDeviceNodeMask); \
		printf("\t\tint totalGlobalMem = %d\n", (*args->hipGetDevicePropertiesR0600.prop).totalGlobalMem); \
		printf("\t\tint sharedMemPerBlock = %d\n", (*args->hipGetDevicePropertiesR0600.prop).sharedMemPerBlock); \
		printf("\t\tint regsPerBlock = %d\n", (*args->hipGetDevicePropertiesR0600.prop).regsPerBlock); \
		printf("\t\tint warpSize = %d\n", (*args->hipGetDevicePropertiesR0600.prop).warpSize); \
		printf("\t\tint memPitch = %d\n", (*args->hipGetDevicePropertiesR0600.prop).memPitch); \
		printf("\t\tint maxThreadsPerBlock = %d\n", (*args->hipGetDevicePropertiesR0600.prop).maxThreadsPerBlock); \
		printf("\t\tint[3] maxThreadsDim = %p", (*args->hipGetDevicePropertiesR0600.prop).maxThreadsDim); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxThreadsDim != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxThreadsDim); \
		} else { printf("\n"); }; \
		printf("\t\tint[3] maxGridSize = %p", (*args->hipGetDevicePropertiesR0600.prop).maxGridSize); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxGridSize != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxGridSize); \
		} else { printf("\n"); }; \
		printf("\t\tint clockRate = %d\n", (*args->hipGetDevicePropertiesR0600.prop).clockRate); \
		printf("\t\tint totalConstMem = %d\n", (*args->hipGetDevicePropertiesR0600.prop).totalConstMem); \
		printf("\t\tint major = %d\n", (*args->hipGetDevicePropertiesR0600.prop).major); \
		printf("\t\tint minor = %d\n", (*args->hipGetDevicePropertiesR0600.prop).minor); \
		printf("\t\tint textureAlignment = %d\n", (*args->hipGetDevicePropertiesR0600.prop).textureAlignment); \
		printf("\t\tint texturePitchAlignment = %d\n", (*args->hipGetDevicePropertiesR0600.prop).texturePitchAlignment); \
		printf("\t\tint deviceOverlap = %d\n", (*args->hipGetDevicePropertiesR0600.prop).deviceOverlap); \
		printf("\t\tint multiProcessorCount = %d\n", (*args->hipGetDevicePropertiesR0600.prop).multiProcessorCount); \
		printf("\t\tint kernelExecTimeoutEnabled = %d\n", (*args->hipGetDevicePropertiesR0600.prop).kernelExecTimeoutEnabled); \
		printf("\t\tint integrated = %d\n", (*args->hipGetDevicePropertiesR0600.prop).integrated); \
		printf("\t\tint canMapHostMemory = %d\n", (*args->hipGetDevicePropertiesR0600.prop).canMapHostMemory); \
		printf("\t\tint computeMode = %d\n", (*args->hipGetDevicePropertiesR0600.prop).computeMode); \
		printf("\t\tint maxTexture1D = %d\n", (*args->hipGetDevicePropertiesR0600.prop).maxTexture1D); \
		printf("\t\tint maxTexture1DMipmap = %d\n", (*args->hipGetDevicePropertiesR0600.prop).maxTexture1DMipmap); \
		printf("\t\tint maxTexture1DLinear = %d\n", (*args->hipGetDevicePropertiesR0600.prop).maxTexture1DLinear); \
		printf("\t\tint[2] maxTexture2D = %p", (*args->hipGetDevicePropertiesR0600.prop).maxTexture2D); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture2D != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture2D); \
		} else { printf("\n"); }; \
		printf("\t\tint[2] maxTexture2DMipmap = %p", (*args->hipGetDevicePropertiesR0600.prop).maxTexture2DMipmap); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture2DMipmap != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture2DMipmap); \
		} else { printf("\n"); }; \
		printf("\t\tint[3] maxTexture2DLinear = %p", (*args->hipGetDevicePropertiesR0600.prop).maxTexture2DLinear); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture2DLinear != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture2DLinear); \
		} else { printf("\n"); }; \
		printf("\t\tint[2] maxTexture2DGather = %p", (*args->hipGetDevicePropertiesR0600.prop).maxTexture2DGather); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture2DGather != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture2DGather); \
		} else { printf("\n"); }; \
		printf("\t\tint[3] maxTexture3D = %p", (*args->hipGetDevicePropertiesR0600.prop).maxTexture3D); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture3D != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture3D); \
		} else { printf("\n"); }; \
		printf("\t\tint[3] maxTexture3DAlt = %p", (*args->hipGetDevicePropertiesR0600.prop).maxTexture3DAlt); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture3DAlt != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture3DAlt); \
		} else { printf("\n"); }; \
		printf("\t\tint maxTextureCubemap = %d\n", (*args->hipGetDevicePropertiesR0600.prop).maxTextureCubemap); \
		printf("\t\tint[2] maxTexture1DLayered = %p", (*args->hipGetDevicePropertiesR0600.prop).maxTexture1DLayered); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture1DLayered != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture1DLayered); \
		} else { printf("\n"); }; \
		printf("\t\tint[3] maxTexture2DLayered = %p", (*args->hipGetDevicePropertiesR0600.prop).maxTexture2DLayered); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTexture2DLayered != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxTexture2DLayered); \
		} else { printf("\n"); }; \
		printf("\t\tint[2] maxTextureCubemapLayered = %p", (*args->hipGetDevicePropertiesR0600.prop).maxTextureCubemapLayered); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxTextureCubemapLayered != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxTextureCubemapLayered); \
		} else { printf("\n"); }; \
		printf("\t\tint maxSurface1D = %d\n", (*args->hipGetDevicePropertiesR0600.prop).maxSurface1D); \
		printf("\t\tint[2] maxSurface2D = %p", (*args->hipGetDevicePropertiesR0600.prop).maxSurface2D); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxSurface2D != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxSurface2D); \
		} else { printf("\n"); }; \
		printf("\t\tint[3] maxSurface3D = %p", (*args->hipGetDevicePropertiesR0600.prop).maxSurface3D); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxSurface3D != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxSurface3D); \
		} else { printf("\n"); }; \
		printf("\t\tint[2] maxSurface1DLayered = %p", (*args->hipGetDevicePropertiesR0600.prop).maxSurface1DLayered); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxSurface1DLayered != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxSurface1DLayered); \
		} else { printf("\n"); }; \
		printf("\t\tint[3] maxSurface2DLayered = %p", (*args->hipGetDevicePropertiesR0600.prop).maxSurface2DLayered); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxSurface2DLayered != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxSurface2DLayered); \
		} else { printf("\n"); }; \
		printf("\t\tint maxSurfaceCubemap = %d\n", (*args->hipGetDevicePropertiesR0600.prop).maxSurfaceCubemap); \
		printf("\t\tint[2] maxSurfaceCubemapLayered = %p", (*args->hipGetDevicePropertiesR0600.prop).maxSurfaceCubemapLayered); \
		if ((*args->hipGetDevicePropertiesR0600.prop).maxSurfaceCubemapLayered != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).maxSurfaceCubemapLayered); \
		} else { printf("\n"); }; \
		printf("\t\tint surfaceAlignment = %d\n", (*args->hipGetDevicePropertiesR0600.prop).surfaceAlignment); \
		printf("\t\tint concurrentKernels = %d\n", (*args->hipGetDevicePropertiesR0600.prop).concurrentKernels); \
		printf("\t\tint ECCEnabled = %d\n", (*args->hipGetDevicePropertiesR0600.prop).ECCEnabled); \
		printf("\t\tint pciBusID = %d\n", (*args->hipGetDevicePropertiesR0600.prop).pciBusID); \
		printf("\t\tint pciDeviceID = %d\n", (*args->hipGetDevicePropertiesR0600.prop).pciDeviceID); \
		printf("\t\tint pciDomainID = %d\n", (*args->hipGetDevicePropertiesR0600.prop).pciDomainID); \
		printf("\t\tint tccDriver = %d\n", (*args->hipGetDevicePropertiesR0600.prop).tccDriver); \
		printf("\t\tint asyncEngineCount = %d\n", (*args->hipGetDevicePropertiesR0600.prop).asyncEngineCount); \
		printf("\t\tint unifiedAddressing = %d\n", (*args->hipGetDevicePropertiesR0600.prop).unifiedAddressing); \
		printf("\t\tint memoryClockRate = %d\n", (*args->hipGetDevicePropertiesR0600.prop).memoryClockRate); \
		printf("\t\tint memoryBusWidth = %d\n", (*args->hipGetDevicePropertiesR0600.prop).memoryBusWidth); \
		printf("\t\tint l2CacheSize = %d\n", (*args->hipGetDevicePropertiesR0600.prop).l2CacheSize); \
		printf("\t\tint persistingL2CacheMaxSize = %d\n", (*args->hipGetDevicePropertiesR0600.prop).persistingL2CacheMaxSize); \
		printf("\t\tint maxThreadsPerMultiProcessor = %d\n", (*args->hipGetDevicePropertiesR0600.prop).maxThreadsPerMultiProcessor); \
		printf("\t\tint streamPrioritiesSupported = %d\n", (*args->hipGetDevicePropertiesR0600.prop).streamPrioritiesSupported); \
		printf("\t\tint globalL1CacheSupported = %d\n", (*args->hipGetDevicePropertiesR0600.prop).globalL1CacheSupported); \
		printf("\t\tint localL1CacheSupported = %d\n", (*args->hipGetDevicePropertiesR0600.prop).localL1CacheSupported); \
		printf("\t\tint sharedMemPerMultiprocessor = %d\n", (*args->hipGetDevicePropertiesR0600.prop).sharedMemPerMultiprocessor); \
		printf("\t\tint regsPerMultiprocessor = %d\n", (*args->hipGetDevicePropertiesR0600.prop).regsPerMultiprocessor); \
		printf("\t\tint managedMemory = %d\n", (*args->hipGetDevicePropertiesR0600.prop).managedMemory); \
		printf("\t\tint isMultiGpuBoard = %d\n", (*args->hipGetDevicePropertiesR0600.prop).isMultiGpuBoard); \
		printf("\t\tint multiGpuBoardGroupID = %d\n", (*args->hipGetDevicePropertiesR0600.prop).multiGpuBoardGroupID); \
		printf("\t\tint hostNativeAtomicSupported = %d\n", (*args->hipGetDevicePropertiesR0600.prop).hostNativeAtomicSupported); \
		printf("\t\tint singleToDoublePrecisionPerfRatio = %d\n", (*args->hipGetDevicePropertiesR0600.prop).singleToDoublePrecisionPerfRatio); \
		printf("\t\tint pageableMemoryAccess = %d\n", (*args->hipGetDevicePropertiesR0600.prop).pageableMemoryAccess); \
		printf("\t\tint concurrentManagedAccess = %d\n", (*args->hipGetDevicePropertiesR0600.prop).concurrentManagedAccess); \
		printf("\t\tint computePreemptionSupported = %d\n", (*args->hipGetDevicePropertiesR0600.prop).computePreemptionSupported); \
		printf("\t\tint canUseHostPointerForRegisteredMem = %d\n", (*args->hipGetDevicePropertiesR0600.prop).canUseHostPointerForRegisteredMem); \
		printf("\t\tint cooperativeLaunch = %d\n", (*args->hipGetDevicePropertiesR0600.prop).cooperativeLaunch); \
		printf("\t\tint cooperativeMultiDeviceLaunch = %d\n", (*args->hipGetDevicePropertiesR0600.prop).cooperativeMultiDeviceLaunch); \
		printf("\t\tint sharedMemPerBlockOptin = %d\n", (*args->hipGetDevicePropertiesR0600.prop).sharedMemPerBlockOptin); \
		printf("\t\tint pageableMemoryAccessUsesHostPageTables = %d\n", (*args->hipGetDevicePropertiesR0600.prop).pageableMemoryAccessUsesHostPageTables); \
		printf("\t\tint directManagedMemAccessFromHost = %d\n", (*args->hipGetDevicePropertiesR0600.prop).directManagedMemAccessFromHost); \
		printf("\t\tint maxBlocksPerMultiProcessor = %d\n", (*args->hipGetDevicePropertiesR0600.prop).maxBlocksPerMultiProcessor); \
		printf("\t\tint accessPolicyMaxWindowSize = %d\n", (*args->hipGetDevicePropertiesR0600.prop).accessPolicyMaxWindowSize); \
		printf("\t\tint reservedSharedMemPerBlock = %d\n", (*args->hipGetDevicePropertiesR0600.prop).reservedSharedMemPerBlock); \
		printf("\t\tint hostRegisterSupported = %d\n", (*args->hipGetDevicePropertiesR0600.prop).hostRegisterSupported); \
		printf("\t\tint sparseHipArraySupported = %d\n", (*args->hipGetDevicePropertiesR0600.prop).sparseHipArraySupported); \
		printf("\t\tint hostRegisterReadOnlySupported = %d\n", (*args->hipGetDevicePropertiesR0600.prop).hostRegisterReadOnlySupported); \
		printf("\t\tint timelineSemaphoreInteropSupported = %d\n", (*args->hipGetDevicePropertiesR0600.prop).timelineSemaphoreInteropSupported); \
		printf("\t\tint memoryPoolsSupported = %d\n", (*args->hipGetDevicePropertiesR0600.prop).memoryPoolsSupported); \
		printf("\t\tint gpuDirectRDMASupported = %d\n", (*args->hipGetDevicePropertiesR0600.prop).gpuDirectRDMASupported); \
		printf("\t\tunsigned int gpuDirectRDMAFlushWritesOptions = %u\n", (*args->hipGetDevicePropertiesR0600.prop).gpuDirectRDMAFlushWritesOptions); \
		printf("\t\tint gpuDirectRDMAWritesOrdering = %d\n", (*args->hipGetDevicePropertiesR0600.prop).gpuDirectRDMAWritesOrdering); \
		printf("\t\tunsigned int memoryPoolSupportedHandleTypes = %u\n", (*args->hipGetDevicePropertiesR0600.prop).memoryPoolSupportedHandleTypes); \
		printf("\t\tint deferredMappingHipArraySupported = %d\n", (*args->hipGetDevicePropertiesR0600.prop).deferredMappingHipArraySupported); \
		printf("\t\tint ipcEventSupported = %d\n", (*args->hipGetDevicePropertiesR0600.prop).ipcEventSupported); \
		printf("\t\tint clusterLaunch = %d\n", (*args->hipGetDevicePropertiesR0600.prop).clusterLaunch); \
		printf("\t\tint unifiedFunctionPointers = %d\n", (*args->hipGetDevicePropertiesR0600.prop).unifiedFunctionPointers); \
		printf("\t\tint[63] reserved = %p", (*args->hipGetDevicePropertiesR0600.prop).reserved); \
		if ((*args->hipGetDevicePropertiesR0600.prop).reserved != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).reserved); \
		} else { printf("\n"); }; \
		printf("\t\tint[32] hipReserved = %p", (*args->hipGetDevicePropertiesR0600.prop).hipReserved); \
		if ((*args->hipGetDevicePropertiesR0600.prop).hipReserved != NULL) { \
			printf(" -> %d\n", *(*args->hipGetDevicePropertiesR0600.prop).hipReserved); \
		} else { printf("\n"); }; \
		printf("\t\tchar[256] gcnArchName = %p", (*args->hipGetDevicePropertiesR0600.prop).gcnArchName); \
		if ((*args->hipGetDevicePropertiesR0600.prop).gcnArchName != NULL) { \
			printf(" -> %c\n", *(*args->hipGetDevicePropertiesR0600.prop).gcnArchName); \
		} else { printf("\n"); }; \
		printf("\t\tint maxSharedMemoryPerMultiProcessor = %d\n", (*args->hipGetDevicePropertiesR0600.prop).maxSharedMemoryPerMultiProcessor); \
		printf("\t\tint clockInstructionRate = %d\n", (*args->hipGetDevicePropertiesR0600.prop).clockInstructionRate); \
		printf("\t\tstruct hipDeviceArch_t arch = {\n"); \
		printf("\t\t\tunsigned int hasGlobalInt32Atomics = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasGlobalInt32Atomics); \
		printf("\t\t\tunsigned int hasGlobalFloatAtomicExch = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasGlobalFloatAtomicExch); \
		printf("\t\t\tunsigned int hasSharedInt32Atomics = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasSharedInt32Atomics); \
		printf("\t\t\tunsigned int hasSharedFloatAtomicExch = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasSharedFloatAtomicExch); \
		printf("\t\t\tunsigned int hasFloatAtomicAdd = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasFloatAtomicAdd); \
		printf("\t\t\tunsigned int hasGlobalInt64Atomics = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasGlobalInt64Atomics); \
		printf("\t\t\tunsigned int hasSharedInt64Atomics = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasSharedInt64Atomics); \
		printf("\t\t\tunsigned int hasDoubles = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasDoubles); \
		printf("\t\t\tunsigned int hasWarpVote = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasWarpVote); \
		printf("\t\t\tunsigned int hasWarpBallot = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasWarpBallot); \
		printf("\t\t\tunsigned int hasWarpShuffle = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasWarpShuffle); \
		printf("\t\t\tunsigned int hasFunnelShift = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasFunnelShift); \
		printf("\t\t\tunsigned int hasThreadFenceSystem = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasThreadFenceSystem); \
		printf("\t\t\tunsigned int hasSyncThreadsExt = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasSyncThreadsExt); \
		printf("\t\t\tunsigned int hasSurfaceFuncs = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasSurfaceFuncs); \
		printf("\t\t\tunsigned int has3dGrid = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).has3dGrid); \
		printf("\t\t\tunsigned int hasDynamicParallelism = %u\n", ((*args->hipGetDevicePropertiesR0600.prop).arch).hasDynamicParallelism); \
		printf("\t\t}\n"); \
		printf("\t\tunsigned int * hdpMemFlushCntl = %p", (*args->hipGetDevicePropertiesR0600.prop).hdpMemFlushCntl); \
		if ((*args->hipGetDevicePropertiesR0600.prop).hdpMemFlushCntl != NULL) { \
			printf(" -> %u\n", *(*args->hipGetDevicePropertiesR0600.prop).hdpMemFlushCntl); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int * hdpRegFlushCntl = %p", (*args->hipGetDevicePropertiesR0600.prop).hdpRegFlushCntl); \
		if ((*args->hipGetDevicePropertiesR0600.prop).hdpRegFlushCntl != NULL) { \
			printf(" -> %u\n", *(*args->hipGetDevicePropertiesR0600.prop).hdpRegFlushCntl); \
		} else { printf("\n"); }; \
		printf("\t\tint cooperativeMultiDeviceUnmatchedFunc = %d\n", (*args->hipGetDevicePropertiesR0600.prop).cooperativeMultiDeviceUnmatchedFunc); \
		printf("\t\tint cooperativeMultiDeviceUnmatchedGridDim = %d\n", (*args->hipGetDevicePropertiesR0600.prop).cooperativeMultiDeviceUnmatchedGridDim); \
		printf("\t\tint cooperativeMultiDeviceUnmatchedBlockDim = %d\n", (*args->hipGetDevicePropertiesR0600.prop).cooperativeMultiDeviceUnmatchedBlockDim); \
		printf("\t\tint cooperativeMultiDeviceUnmatchedSharedMem = %d\n", (*args->hipGetDevicePropertiesR0600.prop).cooperativeMultiDeviceUnmatchedSharedMem); \
		printf("\t\tint isLargeBar = %d\n", (*args->hipGetDevicePropertiesR0600.prop).isLargeBar); \
		printf("\t\tint asicRevision = %d\n", (*args->hipGetDevicePropertiesR0600.prop).asicRevision); \
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
	printf("\tint * gridSize = %p", args->hipOccupancyMaxPotentialBlockSize.gridSize); \
	if (args->hipOccupancyMaxPotentialBlockSize.gridSize != NULL) { \
		printf(" -> %d\n", *args->hipOccupancyMaxPotentialBlockSize.gridSize); \
	} else { printf("\n"); }; \
	printf("\tint * blockSize = %p", args->hipOccupancyMaxPotentialBlockSize.blockSize); \
	if (args->hipOccupancyMaxPotentialBlockSize.blockSize != NULL) { \
		printf(" -> %d\n", *args->hipOccupancyMaxPotentialBlockSize.blockSize); \
	} else { printf("\n"); }; \
	printf("\tconst void * f = %p", args->hipOccupancyMaxPotentialBlockSize.f); \
	printf("\n"); \
	printf("\tsize_t dynSharedMemPerBlk = %lu\n", args->hipOccupancyMaxPotentialBlockSize.dynSharedMemPerBlk); \
	printf("\tint blockSizeLimit = %d\n", args->hipOccupancyMaxPotentialBlockSize.blockSizeLimit); \
};

//	size_t * offset (unsigned long*);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipGetTextureAlignmentOffset(args) { \
	printf("\tsize_t * offset = %p", args->hipGetTextureAlignmentOffset.offset); \
	if (args->hipGetTextureAlignmentOffset.offset != NULL) { \
		printf(" -> %lu\n", *args->hipGetTextureAlignmentOffset.offset); \
	} else { printf("\n"); }; \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	void ** devPtr (void**);
//	hipIpcMemHandle_t handle ({
//		char[64] reserved (char*);
//	});
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipIpcOpenMemHandle(args) { \
	printf("\tvoid ** devPtr = %p", args->hipIpcOpenMemHandle.devPtr); \
	if (args->hipIpcOpenMemHandle.devPtr != NULL) { \
		printf("-> %p", *args->hipIpcOpenMemHandle.devPtr); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tstruct hipIpcMemHandle_t handle = {\n"); \
	printf("\t\tchar[64] reserved = %p", args->hipIpcOpenMemHandle.handle.reserved); \
	if (args->hipIpcOpenMemHandle.handle.reserved != NULL) { \
		printf(" -> %c\n", *args->hipIpcOpenMemHandle.handle.reserved); \
	} else { printf("\n"); }; \
	printf("\t}\n"); \
	printf("\tunsigned int flags = %u\n", args->hipIpcOpenMemHandle.flags); \
};

//	hipGraphNode_t * pNode (unknown);
//	hipGraphNode_t originalNode (unknown);
//	hipGraph_t clonedGraph (unknown);
#define PROCESS_ARGS_hipGraphNodeFindInClone(args) { \
	printf("\thipGraphNode_t * pNode = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t originalNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t clonedGraph = N/A, try to update csv files\n"); \
};

//	hipDevice_t dev (int);
#define PROCESS_ARGS_hipDevicePrimaryCtxRelease(args) { \
	printf("\thipDevice_t dev = %d\n", args->hipDevicePrimaryCtxRelease.dev); \
};

//	hipCtx_t ctx (unknown);
#define PROCESS_ARGS_hipCtxSetCurrent(args) { \
	printf("\thipCtx_t ctx = N/A, try to update csv files\n"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t node (unknown);
//	void * dst (void*);
//	const void * symbol (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParamsFromSymbol(args) { \
	printf("\thipGraphExec_t hGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
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
	printf("\thipFuncCache_t cacheConfig = %d\n", args->hipCtxSetCacheConfig.cacheConfig); \
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
	printf("\tstruct hipArrayMapInfo * mapInfoList = %p", args->hipMemMapArrayAsync.mapInfoList); \
	if (args->hipMemMapArrayAsync.mapInfoList != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tint resourceType = %d\n", (*args->hipMemMapArrayAsync.mapInfoList).resourceType); \
		printf("\t\tunion (unnamed union at ./input/hip_runtime_api.h:1465:6) resource = N/A, try to update csv files\n"); \
		printf("\t\thipArraySparseSubresourceType subresourceType = %d\n", (*args->hipMemMapArrayAsync.mapInfoList).subresourceType); \
		printf("\t\tunion (unnamed union at ./input/hip_runtime_api.h:1470:6) subresource = N/A, try to update csv files\n"); \
		printf("\t\thipMemOperationType memOperationType = %d\n", (*args->hipMemMapArrayAsync.mapInfoList).memOperationType); \
		printf("\t\thipMemHandleType memHandleType = %d\n", (*args->hipMemMapArrayAsync.mapInfoList).memHandleType); \
		printf("\t\tunion (unnamed union at ./input/hip_runtime_api.h:1489:6) memHandle = N/A, try to update csv files\n"); \
		printf("\t\tunsigned long long offset = %llu\n", (*args->hipMemMapArrayAsync.mapInfoList).offset); \
		printf("\t\tunsigned int deviceBitMask = %u\n", (*args->hipMemMapArrayAsync.mapInfoList).deviceBitMask); \
		printf("\t\tunsigned int flags = %u\n", (*args->hipMemMapArrayAsync.mapInfoList).flags); \
		printf("\t\tunsigned int[2] reserved = %p", (*args->hipMemMapArrayAsync.mapInfoList).reserved); \
		if ((*args->hipMemMapArrayAsync.mapInfoList).reserved != NULL) { \
			printf(" -> %u\n", *(*args->hipMemMapArrayAsync.mapInfoList).reserved); \
		} else { printf("\n"); }; \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tunsigned int count = %u\n", args->hipMemMapArrayAsync.count); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
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
	printf("\thipExternalMemory_t * extMem_out = %p", args->hipImportExternalMemory.extMem_out); \
	if (args->hipImportExternalMemory.extMem_out != NULL) { \
		printf("-> %p", *args->hipImportExternalMemory.extMem_out); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tstruct const hipExternalMemoryHandleDesc * memHandleDesc = %p", args->hipImportExternalMemory.memHandleDesc); \
	if (args->hipImportExternalMemory.memHandleDesc != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipExternalMemoryHandleType type = %d\n", (*args->hipImportExternalMemory.memHandleDesc).type); \
		printf("\t\tunion (unnamed union at ./input/hip_runtime_api.h:1083:3) handle = N/A, try to update csv files\n"); \
		printf("\t\tunsigned long long size = %llu\n", (*args->hipImportExternalMemory.memHandleDesc).size); \
		printf("\t\tunsigned int flags = %u\n", (*args->hipImportExternalMemory.memHandleDesc).flags); \
		printf("\t\tunsigned int[16] reserved = %p", (*args->hipImportExternalMemory.memHandleDesc).reserved); \
		if ((*args->hipImportExternalMemory.memHandleDesc).reserved != NULL) { \
			printf(" -> %u\n", *(*args->hipImportExternalMemory.memHandleDesc).reserved); \
		} else { printf("\n"); }; \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t hNode (unknown);
//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipGraphExecEventWaitNodeSetEvent(args) { \
	printf("\thipGraphExec_t hGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t hNode = N/A, try to update csv files\n"); \
	printf("\thipEvent_t event = N/A, try to update csv files\n"); \
};

//	hipStream_t stream (unknown);
//	hipStreamCaptureMode mode (enum);
#define PROCESS_ARGS_hipStreamBeginCapture(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\thipStreamCaptureMode mode = %d\n", args->hipStreamBeginCapture.mode); \
};

//	struct hipIpcMemHandle_t * handle ({
//		char[64] reserved (char*);
//	});
//	void * devPtr (void*);
#define PROCESS_ARGS_hipIpcGetMemHandle(args) { \
	printf("\tstruct hipIpcMemHandle_t * handle = %p", args->hipIpcGetMemHandle.handle); \
	if (args->hipIpcGetMemHandle.handle != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tchar[64] reserved = %p", (*args->hipIpcGetMemHandle.handle).reserved); \
		if ((*args->hipIpcGetMemHandle.handle).reserved != NULL) { \
			printf(" -> %c\n", *(*args->hipIpcGetMemHandle.handle).reserved); \
		} else { printf("\n"); }; \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tvoid * devPtr = %p", args->hipIpcGetMemHandle.devPtr); \
	printf("\n"); \
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
	printf("\tconst hipExternalSemaphore_t * extSemArray = %p", args->hipWaitExternalSemaphoresAsync.extSemArray); \
	if (args->hipWaitExternalSemaphoresAsync.extSemArray != NULL) { \
		printf("-> %p", *args->hipWaitExternalSemaphoresAsync.extSemArray); \
		printf("\n"); \
	} else { printf("\n"); }; \
	printf("\tstruct const hipExternalSemaphoreWaitParams * paramsArray = %p", args->hipWaitExternalSemaphoresAsync.paramsArray); \
	if (args->hipWaitExternalSemaphoresAsync.paramsArray != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tstruct (unnamed struct at ./input/hip_runtime_api.h:1156:3) params = N/A, try to update csv files\n"); \
		printf("\t\tunsigned int flags = %u\n", (*args->hipWaitExternalSemaphoresAsync.paramsArray).flags); \
		printf("\t\tunsigned int[16] reserved = %p", (*args->hipWaitExternalSemaphoresAsync.paramsArray).reserved); \
		if ((*args->hipWaitExternalSemaphoresAsync.paramsArray).reserved != NULL) { \
			printf(" -> %u\n", *(*args->hipWaitExternalSemaphoresAsync.paramsArray).reserved); \
		} else { printf("\n"); }; \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tunsigned int numExtSems = %u\n", args->hipWaitExternalSemaphoresAsync.numExtSems); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	enum hipTextureFilterMode * pfm (enum);
//	const textureReference* texRef (unknown);
#define PROCESS_ARGS_hipTexRefGetMipmapFilterMode(args) { \
	printf("\tenum hipTextureFilterMode * pfm = %d\n", args->hipTexRefGetMipmapFilterMode.pfm); \
	printf("\tconst textureReference* texRef = N/A, try to update csv files\n"); \
};

//	hipMemAccessFlags * flags (enum*);
//	hipMemPool_t mem_pool (unknown);
//	struct hipMemLocation * location ({
//		hipMemLocationType type (enum);
//		int id (int);
//	});
#define PROCESS_ARGS_hipMemPoolGetAccess(args) { \
	printf("\thipMemAccessFlags * flags = %p", args->hipMemPoolGetAccess.flags); \
	if (args->hipMemPoolGetAccess.flags != NULL) { \
		printf(" -> %d\n", *args->hipMemPoolGetAccess.flags); \
	} else { printf("\n"); }; \
	printf("\thipMemPool_t mem_pool = N/A, try to update csv files\n"); \
	printf("\tstruct hipMemLocation * location = %p", args->hipMemPoolGetAccess.location); \
	if (args->hipMemPoolGetAccess.location != NULL) { \
		printf(" -> {\n"); \
		printf("\t\thipMemLocationType type = %d\n", (*args->hipMemPoolGetAccess.location).type); \
		printf("\t\tint id = %d\n", (*args->hipMemPoolGetAccess.location).id); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
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
	printf("\thipGraphNode_t * phGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t hGraph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * dependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipDrvGraphAddMemsetNode.numDependencies); \
	printf("\tstruct const HIP_MEMSET_NODE_PARAMS * memsetParams = %p", args->hipDrvGraphAddMemsetNode.memsetParams); \
	if (args->hipDrvGraphAddMemsetNode.memsetParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tint dst = %d\n", (*args->hipDrvGraphAddMemsetNode.memsetParams).dst); \
		printf("\t\tint pitch = %d\n", (*args->hipDrvGraphAddMemsetNode.memsetParams).pitch); \
		printf("\t\tunsigned int value = %u\n", (*args->hipDrvGraphAddMemsetNode.memsetParams).value); \
		printf("\t\tunsigned int elementSize = %u\n", (*args->hipDrvGraphAddMemsetNode.memsetParams).elementSize); \
		printf("\t\tint width = %d\n", (*args->hipDrvGraphAddMemsetNode.memsetParams).width); \
		printf("\t\tint height = %d\n", (*args->hipDrvGraphAddMemsetNode.memsetParams).height); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\thipCtx_t ctx = N/A, try to update csv files\n"); \
};

//	hipPitchedPtr pitchedDevPtr (unknown);
//	int value (int);
//	hipExtent extent (unknown);
#define PROCESS_ARGS_hipMemset3D(args) { \
	printf("\thipPitchedPtr pitchedDevPtr = N/A, try to update csv files\n"); \
	printf("\tint value = %d\n", args->hipMemset3D.value); \
	printf("\thipExtent extent = N/A, try to update csv files\n"); \
};

//	const HIP_MEMCPY3D * pCopy (unknown);
#define PROCESS_ARGS_hipDrvMemcpy3D(args) { \
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
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpy2DFromArrayAsync(args) { \
	printf("\tvoid * dst = %p", args->hipMemcpy2DFromArrayAsync.dst); \
	printf("\n"); \
	printf("\tsize_t dpitch = %lu\n", args->hipMemcpy2DFromArrayAsync.dpitch); \
	printf("\thipArray_const_t src = N/A, try to update csv files\n"); \
	printf("\tsize_t wOffset = %lu\n", args->hipMemcpy2DFromArrayAsync.wOffset); \
	printf("\tsize_t hOffset = %lu\n", args->hipMemcpy2DFromArrayAsync.hOffset); \
	printf("\tsize_t width = %lu\n", args->hipMemcpy2DFromArrayAsync.width); \
	printf("\tsize_t height = %lu\n", args->hipMemcpy2DFromArrayAsync.height); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
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
	printf("\tstruct hipLaunchParams * launchParamsList = %p", args->hipExtLaunchMultiKernelMultiDevice.launchParamsList); \
	if (args->hipExtLaunchMultiKernelMultiDevice.launchParamsList != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tvoid * func = %p", (*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).func); \
		printf("\n"); \
		printf("\t\tstruct dim3 gridDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", ((*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).gridDim).x); \
		printf("\t\t\tuint32_t y = %u\n", ((*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).gridDim).y); \
		printf("\t\t\tuint32_t z = %u\n", ((*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).gridDim).z); \
		printf("\t\t}\n"); \
		printf("\t\tstruct dim3 blockDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", ((*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).blockDim).x); \
		printf("\t\t\tuint32_t y = %u\n", ((*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).blockDim).y); \
		printf("\t\t\tuint32_t z = %u\n", ((*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).blockDim).z); \
		printf("\t\t}\n"); \
		printf("\t\tvoid ** args = %p", (*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).args); \
		if ((*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).args != NULL) { \
			printf("-> %p", *(*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).args); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tint sharedMem = %d\n", (*args->hipExtLaunchMultiKernelMultiDevice.launchParamsList).sharedMem); \
		printf("\t\thipStream_t stream = N/A, try to update csv files\n"); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tint numDevices = %d\n", args->hipExtLaunchMultiKernelMultiDevice.numDevices); \
	printf("\tunsigned int flags = %u\n", args->hipExtLaunchMultiKernelMultiDevice.flags); \
};

//	hipStream_t stream (unknown);
//	void * ptr (void*);
//	uint64_t value (unsigned long);
//	unsigned int flags (unsigned int);
//	uint64_t mask (unsigned long);
#define PROCESS_ARGS_hipStreamWaitValue64(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\tvoid * ptr = %p", args->hipStreamWaitValue64.ptr); \
	printf("\n"); \
	printf("\tuint64_t value = %lu\n", args->hipStreamWaitValue64.value); \
	printf("\tunsigned int flags = %u\n", args->hipStreamWaitValue64.flags); \
	printf("\tuint64_t mask = %lu\n", args->hipStreamWaitValue64.mask); \
};

//	textureReference** texRef (unknown);
//	hipModule_t hmod (unknown);
//	const char * name (char*);
#define PROCESS_ARGS_hipModuleGetTexRef(args) { \
	printf("\ttextureReference** texRef = N/A, try to update csv files\n"); \
	printf("\thipModule_t hmod = N/A, try to update csv files\n"); \
	printf("\tconst char * name = %p", args->hipModuleGetTexRef.name); \
	if (args->hipModuleGetTexRef.name != NULL) { \
		printf(" -> %c\n", *args->hipModuleGetTexRef.name); \
	} else { printf("\n"); }; \
};

//	hipDeviceptr_t dst (unknown);
//	hipDeviceptr_t src (unknown);
//	size_t sizeBytes (unsigned long);
//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipMemcpyDtoDAsync(args) { \
	printf("\thipDeviceptr_t dst = N/A, try to update csv files\n"); \
	printf("\thipDeviceptr_t src = N/A, try to update csv files\n"); \
	printf("\tsize_t sizeBytes = %lu\n", args->hipMemcpyDtoDAsync.sizeBytes); \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	HIP_RESOURCE_VIEW_DESC * pResViewDesc (unknown);
//	hipTextureObject_t texObject (unknown);
#define PROCESS_ARGS_hipTexObjectGetResourceViewDesc(args) { \
	printf("\tHIP_RESOURCE_VIEW_DESC * pResViewDesc = N/A, try to update csv files\n"); \
	printf("\thipTextureObject_t texObject = N/A, try to update csv files\n"); \
};

//	hipStream_t stream (unknown);
//	hipStreamCallback_t callback (void*);
//	void * userData (void*);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipStreamAddCallback(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
	printf("\thipStreamCallback_t callback = %p", args->hipStreamAddCallback.callback); \
	printf("\n"); \
	printf("\tvoid * userData = %p", args->hipStreamAddCallback.userData); \
	printf("\n"); \
	printf("\tunsigned int flags = %u\n", args->hipStreamAddCallback.flags); \
};

//	textureReference* texRef (unknown);
//	hipArray_Format fmt (unknown);
//	int NumPackedComponents (int);
#define PROCESS_ARGS_hipTexRefSetFormat(args) { \
	printf("\ttextureReference* texRef = N/A, try to update csv files\n"); \
	printf("\thipArray_Format fmt = N/A, try to update csv files\n"); \
	printf("\tint NumPackedComponents = %d\n", args->hipTexRefSetFormat.NumPackedComponents); \
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
	printf("\tstruct struct hipFuncAttributes * attr = %p", args->hipFuncGetAttributes.attr); \
	if (args->hipFuncGetAttributes.attr != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tint binaryVersion = %d\n", (*args->hipFuncGetAttributes.attr).binaryVersion); \
		printf("\t\tint cacheModeCA = %d\n", (*args->hipFuncGetAttributes.attr).cacheModeCA); \
		printf("\t\tint constSizeBytes = %d\n", (*args->hipFuncGetAttributes.attr).constSizeBytes); \
		printf("\t\tint localSizeBytes = %d\n", (*args->hipFuncGetAttributes.attr).localSizeBytes); \
		printf("\t\tint maxDynamicSharedSizeBytes = %d\n", (*args->hipFuncGetAttributes.attr).maxDynamicSharedSizeBytes); \
		printf("\t\tint maxThreadsPerBlock = %d\n", (*args->hipFuncGetAttributes.attr).maxThreadsPerBlock); \
		printf("\t\tint numRegs = %d\n", (*args->hipFuncGetAttributes.attr).numRegs); \
		printf("\t\tint preferredShmemCarveout = %d\n", (*args->hipFuncGetAttributes.attr).preferredShmemCarveout); \
		printf("\t\tint ptxVersion = %d\n", (*args->hipFuncGetAttributes.attr).ptxVersion); \
		printf("\t\tint sharedSizeBytes = %d\n", (*args->hipFuncGetAttributes.attr).sharedSizeBytes); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
	printf("\tconst void * func = %p", args->hipFuncGetAttributes.func); \
	printf("\n"); \
};

//	hipStream_t * stream (unknown);
//	unsigned int flags (unsigned int);
//	int priority (int);
#define PROCESS_ARGS_hipStreamCreateWithPriority(args) { \
	printf("\thipStream_t * stream = N/A, try to update csv files\n"); \
	printf("\tunsigned int flags = %u\n", args->hipStreamCreateWithPriority.flags); \
	printf("\tint priority = %d\n", args->hipStreamCreateWithPriority.priority); \
};

//	const textureReference** texref (unknown);
//	const void * symbol (void*);
#define PROCESS_ARGS_hipGetTextureReference(args) { \
	printf("\tconst textureReference** texref = N/A, try to update csv files\n"); \
	printf("\tconst void * symbol = %p", args->hipGetTextureReference.symbol); \
	printf("\n"); \
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
	printf("\thipGraphNode_t * pGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddKernelNode.numDependencies); \
	printf("\tstruct const hipKernelNodeParams * pNodeParams = %p", args->hipGraphAddKernelNode.pNodeParams); \
	if (args->hipGraphAddKernelNode.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tstruct dim3 blockDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", ((*args->hipGraphAddKernelNode.pNodeParams).blockDim).x); \
		printf("\t\t\tuint32_t y = %u\n", ((*args->hipGraphAddKernelNode.pNodeParams).blockDim).y); \
		printf("\t\t\tuint32_t z = %u\n", ((*args->hipGraphAddKernelNode.pNodeParams).blockDim).z); \
		printf("\t\t}\n"); \
		printf("\t\tvoid ** extra = %p", (*args->hipGraphAddKernelNode.pNodeParams).extra); \
		if ((*args->hipGraphAddKernelNode.pNodeParams).extra != NULL) { \
			printf("-> %p", *(*args->hipGraphAddKernelNode.pNodeParams).extra); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tvoid * func = %p", (*args->hipGraphAddKernelNode.pNodeParams).func); \
		printf("\n"); \
		printf("\t\tstruct dim3 gridDim = {\n"); \
		printf("\t\t\tuint32_t x = %u\n", ((*args->hipGraphAddKernelNode.pNodeParams).gridDim).x); \
		printf("\t\t\tuint32_t y = %u\n", ((*args->hipGraphAddKernelNode.pNodeParams).gridDim).y); \
		printf("\t\t\tuint32_t z = %u\n", ((*args->hipGraphAddKernelNode.pNodeParams).gridDim).z); \
		printf("\t\t}\n"); \
		printf("\t\tvoid ** kernelParams = %p", (*args->hipGraphAddKernelNode.pNodeParams).kernelParams); \
		if ((*args->hipGraphAddKernelNode.pNodeParams).kernelParams != NULL) { \
			printf("-> %p", *(*args->hipGraphAddKernelNode.pNodeParams).kernelParams); \
			printf("\n"); \
		} else { printf("\n"); }; \
		printf("\t\tunsigned int sharedMemBytes = %u\n", (*args->hipGraphAddKernelNode.pNodeParams).sharedMemBytes); \
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
	printf("\tvoid * devPtr = %p", args->hipIpcCloseMemHandle.devPtr); \
	printf("\n"); \
};

//	hipGraph_t graph (unknown);
#define PROCESS_ARGS_hipGraphDestroy(args) { \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
};

//	const void * dev_ptr (void*);
//	size_t count (unsigned long);
//	hipMemoryAdvise advice (enum);
//	int device (int);
#define PROCESS_ARGS_hipMemAdvise(args) { \
	printf("\tconst void * dev_ptr = %p", args->hipMemAdvise.dev_ptr); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipMemAdvise.count); \
	printf("\thipMemoryAdvise advice = %d\n", args->hipMemAdvise.advice); \
	printf("\tint device = %d\n", args->hipMemAdvise.device); \
};

//	hipGraphNode_t node (unknown);
#define PROCESS_ARGS_hipGraphDestroyNode(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
};

//	int * value (int*);
//	hipFunction_attribute attrib (unknown);
//	hipFunction_t hfunc (unknown);
#define PROCESS_ARGS_hipFuncGetAttribute(args) { \
	printf("\tint * value = %p", args->hipFuncGetAttribute.value); \
	if (args->hipFuncGetAttribute.value != NULL) { \
		printf(" -> %d\n", *args->hipFuncGetAttribute.value); \
	} else { printf("\n"); }; \
	printf("\thipFunction_attribute attrib = N/A, try to update csv files\n"); \
	printf("\thipFunction_t hfunc = N/A, try to update csv files\n"); \
};

//	hipCtx_t peerCtx (unknown);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipCtxEnablePeerAccess(args) { \
	printf("\thipCtx_t peerCtx = N/A, try to update csv files\n"); \
	printf("\tunsigned int flags = %u\n", args->hipCtxEnablePeerAccess.flags); \
};

//	int * numBlocks (int*);
//	hipFunction_t f (unknown);
//	int blockSize (int);
//	size_t dynSharedMemPerBlk (unsigned long);
//	unsigned int flags (unsigned int);
#define PROCESS_ARGS_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(args) { \
	printf("\tint * numBlocks = %p", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks); \
	if (args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks != NULL) { \
		printf(" -> %d\n", *args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.numBlocks); \
	} else { printf("\n"); }; \
	printf("\thipFunction_t f = N/A, try to update csv files\n"); \
	printf("\tint blockSize = %d\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.blockSize); \
	printf("\tsize_t dynSharedMemPerBlk = %lu\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.dynSharedMemPerBlk); \
	printf("\tunsigned int flags = %u\n", args->hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags.flags); \
};


#define PROCESS_ARGS_hipCtxSynchronize(args) { \
\
};

//	hipExternalMemory_t extMem (void*);
#define PROCESS_ARGS_hipDestroyExternalMemory(args) { \
	printf("\thipExternalMemory_t extMem = %p", args->hipDestroyExternalMemory.extMem); \
	printf("\n"); \
};

//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipStreamDestroy(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
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
	printf("\thipGraphNode_t * pGraphNode = N/A, try to update csv files\n"); \
	printf("\thipGraph_t graph = N/A, try to update csv files\n"); \
	printf("\tconst hipGraphNode_t * pDependencies = N/A, try to update csv files\n"); \
	printf("\tsize_t numDependencies = %lu\n", args->hipGraphAddMemcpyNodeToSymbol.numDependencies); \
	printf("\tconst void * symbol = %p", args->hipGraphAddMemcpyNodeToSymbol.symbol); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipGraphAddMemcpyNodeToSymbol.src); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipGraphAddMemcpyNodeToSymbol.count); \
	printf("\tsize_t offset = %lu\n", args->hipGraphAddMemcpyNodeToSymbol.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
};

//	hipGraphNode_t node (unknown);
//	hipEvent_t event (unknown);
#define PROCESS_ARGS_hipGraphEventRecordNodeSetEvent(args) { \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\thipEvent_t event = N/A, try to update csv files\n"); \
};

//	int * value (int*);
//	hipDeviceP2PAttr attr (enum);
//	int srcDevice (int);
//	int dstDevice (int);
#define PROCESS_ARGS_hipDeviceGetP2PAttribute(args) { \
	printf("\tint * value = %p", args->hipDeviceGetP2PAttribute.value); \
	if (args->hipDeviceGetP2PAttribute.value != NULL) { \
		printf(" -> %d\n", *args->hipDeviceGetP2PAttribute.value); \
	} else { printf("\n"); }; \
	printf("\thipDeviceP2PAttr attr = %d\n", args->hipDeviceGetP2PAttribute.attr); \
	printf("\tint srcDevice = %d\n", args->hipDeviceGetP2PAttribute.srcDevice); \
	printf("\tint dstDevice = %d\n", args->hipDeviceGetP2PAttribute.dstDevice); \
};

//	hipStream_t stream (unknown);
#define PROCESS_ARGS_hipGetStreamDeviceId(args) { \
	printf("\thipStream_t stream = N/A, try to update csv files\n"); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t hNode (unknown);
//	unsigned int * isEnabled (unsigned int*);
#define PROCESS_ARGS_hipGraphNodeGetEnabled(args) { \
	printf("\thipGraphExec_t hGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t hNode = N/A, try to update csv files\n"); \
	printf("\tunsigned int * isEnabled = %p", args->hipGraphNodeGetEnabled.isEnabled); \
	if (args->hipGraphNodeGetEnabled.isEnabled != NULL) { \
		printf(" -> %u\n", *args->hipGraphNodeGetEnabled.isEnabled); \
	} else { printf("\n"); }; \
};

//	hipMemPool_t * mem_pool (unknown);
//	int device (int);
#define PROCESS_ARGS_hipDeviceGetMemPool(args) { \
	printf("\thipMemPool_t * mem_pool = N/A, try to update csv files\n"); \
	printf("\tint device = %d\n", args->hipDeviceGetMemPool.device); \
};

//	hipArray_t * pLevelArray (unknown);
//	hipMipmappedArray_t hMipMappedArray (unknown);
//	unsigned int level (unsigned int);
#define PROCESS_ARGS_hipMipmappedArrayGetLevel(args) { \
	printf("\thipArray_t * pLevelArray = N/A, try to update csv files\n"); \
	printf("\thipMipmappedArray_t hMipMappedArray = N/A, try to update csv files\n"); \
	printf("\tunsigned int level = %u\n", args->hipMipmappedArrayGetLevel.level); \
};

//	hipGraphExec_t hGraphExec (unknown);
//	hipGraphNode_t node (unknown);
//	const void * symbol (void*);
//	const void * src (void*);
//	size_t count (unsigned long);
//	size_t offset (unsigned long);
//	hipMemcpyKind kind (unknown);
#define PROCESS_ARGS_hipGraphExecMemcpyNodeSetParamsToSymbol(args) { \
	printf("\thipGraphExec_t hGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\tconst void * symbol = %p", args->hipGraphExecMemcpyNodeSetParamsToSymbol.symbol); \
	printf("\n"); \
	printf("\tconst void * src = %p", args->hipGraphExecMemcpyNodeSetParamsToSymbol.src); \
	printf("\n"); \
	printf("\tsize_t count = %lu\n", args->hipGraphExecMemcpyNodeSetParamsToSymbol.count); \
	printf("\tsize_t offset = %lu\n", args->hipGraphExecMemcpyNodeSetParamsToSymbol.offset); \
	printf("\thipMemcpyKind kind = N/A, try to update csv files\n"); \
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
	printf("\thipGraphExec_t hGraphExec = N/A, try to update csv files\n"); \
	printf("\thipGraphNode_t node = N/A, try to update csv files\n"); \
	printf("\tstruct const hipMemsetParams * pNodeParams = %p", args->hipGraphExecMemsetNodeSetParams.pNodeParams); \
	if (args->hipGraphExecMemsetNodeSetParams.pNodeParams != NULL) { \
		printf(" -> {\n"); \
		printf("\t\tvoid * dst = %p", (*args->hipGraphExecMemsetNodeSetParams.pNodeParams).dst); \
		printf("\n"); \
		printf("\t\tunsigned int elementSize = %u\n", (*args->hipGraphExecMemsetNodeSetParams.pNodeParams).elementSize); \
		printf("\t\tint height = %d\n", (*args->hipGraphExecMemsetNodeSetParams.pNodeParams).height); \
		printf("\t\tint pitch = %d\n", (*args->hipGraphExecMemsetNodeSetParams.pNodeParams).pitch); \
		printf("\t\tunsigned int value = %u\n", (*args->hipGraphExecMemsetNodeSetParams.pNodeParams).value); \
		printf("\t\tint width = %d\n", (*args->hipGraphExecMemsetNodeSetParams.pNodeParams).width); \
		printf("\t}\n"); \
	} else { printf("\n"); }; \
};

#endif // HIP_PLUGIN_H