/* # THIS FILE IS A SAMPLE GENERATED ONLY IF THE CORRECT OPTIONS ARE SET.
 * # YOU CAN USE THIS FILE AS A TEMPLATE AND MODIFY IT AS NEEDED.
 */ 

#include <ratelprof.h>
#include "hip_plugin.h"

void on_enter_hip_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity){
    get_hip_pointed_args_for(id, &activity->hip_args, 1);
    activity->domain = domain;
    activity->corr_id = get_correlation_id();
    activity->id = push_id();
    activity->funid = id;
}

void on_exit_hip_callback(ratelprof_domain_t domain, ratelprof_api_id_t id, ratelprof_api_activity_t* activity){
    get_hip_pointed_args_for(id, &activity->hip_args, 0);
    pop_id();
    activity->pid = get_pid();
    activity->tid = get_tid();
    ratelprof_activity_pool_push_activity(activity);
}

void process_hip_args_for(hip_api_id_t funid, const hip_api_args_t* args, ratelprof_buffer_t* buf) 
{
    switch(funid) {
		case HIP_API_ID_hipTexRefSetMipmapFilterMode : PROCESS_ARGS_hipTexRefSetMipmapFilterMode(args); break;
		case HIP_API_ID_hipMemcpyHtoA : PROCESS_ARGS_hipMemcpyHtoA(args); break;
		case HIP_API_ID_hipCtxGetApiVersion : PROCESS_ARGS_hipCtxGetApiVersion(args); break;
		case HIP_API_ID_hipDeviceGetName : PROCESS_ARGS_hipDeviceGetName(args); break;
		case HIP_API_ID_hipStreamIsCapturing : PROCESS_ARGS_hipStreamIsCapturing(args); break;
		case HIP_API_ID_hipStreamAttachMemAsync : PROCESS_ARGS_hipStreamAttachMemAsync(args); break;
		case HIP_API_ID_hipFreeArray : PROCESS_ARGS_hipFreeArray(args); break;
		case HIP_API_ID_hipSetDeviceFlags : PROCESS_ARGS_hipSetDeviceFlags(args); break;
		case HIP_API_ID_hipIpcOpenEventHandle : PROCESS_ARGS_hipIpcOpenEventHandle(args); break;
		case HIP_API_ID_hipModuleLoad : PROCESS_ARGS_hipModuleLoad(args); break;
		case HIP_API_ID_hipExternalMemoryGetMappedBuffer : PROCESS_ARGS_hipExternalMemoryGetMappedBuffer(args); break;
		case HIP_API_ID_hipMemImportFromShareableHandle : PROCESS_ARGS_hipMemImportFromShareableHandle(args); break;
		case HIP_API_ID_hipMemcpyDtoH : PROCESS_ARGS_hipMemcpyDtoH(args); break;
		case HIP_API_ID_hipStreamEndCapture : PROCESS_ARGS_hipStreamEndCapture(args); break;
		case HIP_API_ID_hipGraphMemFreeNodeGetParams : PROCESS_ARGS_hipGraphMemFreeNodeGetParams(args); break;
		case HIP_API_ID_hipThreadExchangeStreamCaptureMode : PROCESS_ARGS_hipThreadExchangeStreamCaptureMode(args); break;
		case HIP_API_ID_hipModuleUnload : PROCESS_ARGS_hipModuleUnload(args); break;
		case HIP_API_ID_hipModuleOccupancyMaxPotentialBlockSize : PROCESS_ARGS_hipModuleOccupancyMaxPotentialBlockSize(args); break;
		case HIP_API_ID_hipMemcpyParam2D : PROCESS_ARGS_hipMemcpyParam2D(args); break;
		case HIP_API_ID_hipPeekAtLastError : PROCESS_ARGS_hipPeekAtLastError(args); break;
		case HIP_API_ID_hipMemRelease : PROCESS_ARGS_hipMemRelease(args); break;
		case HIP_API_ID_hipDeviceGetSharedMemConfig : PROCESS_ARGS_hipDeviceGetSharedMemConfig(args); break;
		case HIP_API_ID_hipUserObjectRelease : PROCESS_ARGS_hipUserObjectRelease(args); break;
		case HIP_API_ID_hipStreamWriteValue32 : PROCESS_ARGS_hipStreamWriteValue32(args); break;
		case HIP_API_ID_hipMemAllocHost : PROCESS_ARGS_hipMemAllocHost(args); break;
		case HIP_API_ID_hipGraphCreate : PROCESS_ARGS_hipGraphCreate(args); break;
		case HIP_API_ID_hipModuleOccupancyMaxPotentialBlockSizeWithFlags : PROCESS_ARGS_hipModuleOccupancyMaxPotentialBlockSizeWithFlags(args); break;
		case HIP_API_ID_hipMalloc3DArray : PROCESS_ARGS_hipMalloc3DArray(args); break;
		case HIP_API_ID_hipCtxGetCacheConfig : PROCESS_ARGS_hipCtxGetCacheConfig(args); break;
		case HIP_API_ID_hipModuleLaunchCooperativeKernel : PROCESS_ARGS_hipModuleLaunchCooperativeKernel(args); break;
		case HIP_API_ID_hipTexRefGetAddressMode : PROCESS_ARGS_hipTexRefGetAddressMode(args); break;
		case HIP_API_ID_hipGraphEventWaitNodeSetEvent : PROCESS_ARGS_hipGraphEventWaitNodeSetEvent(args); break;
		case HIP_API_ID_hipDeviceGetDefaultMemPool : PROCESS_ARGS_hipDeviceGetDefaultMemPool(args); break;
		case HIP_API_ID_hipMemPoolTrimTo : PROCESS_ARGS_hipMemPoolTrimTo(args); break;
		case HIP_API_ID_hipGraphUpload : PROCESS_ARGS_hipGraphUpload(args); break;
		case HIP_API_ID_hipExternalMemoryGetMappedMipmappedArray : PROCESS_ARGS_hipExternalMemoryGetMappedMipmappedArray(args); break;
		case HIP_API_ID_hipGraphExternalSemaphoresWaitNodeSetParams : PROCESS_ARGS_hipGraphExternalSemaphoresWaitNodeSetParams(args); break;
		case HIP_API_ID_hipMemcpyToSymbol : PROCESS_ARGS_hipMemcpyToSymbol(args); break;
		case HIP_API_ID_hipGraphAddMemsetNode : PROCESS_ARGS_hipGraphAddMemsetNode(args); break;
		case HIP_API_ID_hipGraphClone : PROCESS_ARGS_hipGraphClone(args); break;
		case HIP_API_ID_hipExtGetLastError : PROCESS_ARGS_hipExtGetLastError(args); break;
		case HIP_API_ID_hipGraphKernelNodeGetAttribute : PROCESS_ARGS_hipGraphKernelNodeGetAttribute(args); break;
		case HIP_API_ID_hipEventRecord : PROCESS_ARGS_hipEventRecord(args); break;
		case HIP_API_ID_hipMemGetAllocationPropertiesFromHandle : PROCESS_ARGS_hipMemGetAllocationPropertiesFromHandle(args); break;
		case HIP_API_ID_hipGraphAddEventWaitNode : PROCESS_ARGS_hipGraphAddEventWaitNode(args); break;
		case HIP_API_ID_hipMemPoolImportPointer : PROCESS_ARGS_hipMemPoolImportPointer(args); break;
		case HIP_API_ID_hipFree : PROCESS_ARGS_hipFree(args); break;
		case HIP_API_ID_hipGraphEventRecordNodeGetEvent : PROCESS_ARGS_hipGraphEventRecordNodeGetEvent(args); break;
		case HIP_API_ID_hipMalloc : PROCESS_ARGS_hipMalloc(args); break;
		case HIP_API_ID_hipMemcpyWithStream : PROCESS_ARGS_hipMemcpyWithStream(args); break;
		case HIP_API_ID_hipDrvMemcpy3DAsync : PROCESS_ARGS_hipDrvMemcpy3DAsync(args); break;
		case HIP_API_ID_hipGraphAddMemAllocNode : PROCESS_ARGS_hipGraphAddMemAllocNode(args); break;
		case HIP_API_ID_hipHostMalloc : PROCESS_ARGS_hipHostMalloc(args); break;
		case HIP_API_ID_hipGraphMemcpyNodeGetParams : PROCESS_ARGS_hipGraphMemcpyNodeGetParams(args); break;
		case HIP_API_ID_hipTexRefSetFlags : PROCESS_ARGS_hipTexRefSetFlags(args); break;
		case HIP_API_ID_hipMemPoolImportFromShareableHandle : PROCESS_ARGS_hipMemPoolImportFromShareableHandle(args); break;
		case HIP_API_ID_hipGraphNodeSetEnabled : PROCESS_ARGS_hipGraphNodeSetEnabled(args); break;
		case HIP_API_ID_hipTexRefSetMipmapLevelBias : PROCESS_ARGS_hipTexRefSetMipmapLevelBias(args); break;
		case HIP_API_ID_hipStreamWaitValue32 : PROCESS_ARGS_hipStreamWaitValue32(args); break;
		case HIP_API_ID_hipMipmappedArrayDestroy : PROCESS_ARGS_hipMipmappedArrayDestroy(args); break;
		case HIP_API_ID_hipCtxDestroy : PROCESS_ARGS_hipCtxDestroy(args); break;
		case HIP_API_ID_hipDeviceReset : PROCESS_ARGS_hipDeviceReset(args); break;
		case HIP_API_ID_hipMemPrefetchAsync : PROCESS_ARGS_hipMemPrefetchAsync(args); break;
		case HIP_API_ID_hipMemsetD16 : PROCESS_ARGS_hipMemsetD16(args); break;
		case HIP_API_ID_hipMemcpy2DAsync : PROCESS_ARGS_hipMemcpy2DAsync(args); break;
		case HIP_API_ID_hipDevicePrimaryCtxSetFlags : PROCESS_ARGS_hipDevicePrimaryCtxSetFlags(args); break;
		case HIP_API_ID_hipGraphInstantiateWithFlags : PROCESS_ARGS_hipGraphInstantiateWithFlags(args); break;
		case HIP_API_ID_hipGraphAddEmptyNode : PROCESS_ARGS_hipGraphAddEmptyNode(args); break;
		case HIP_API_ID_hipFreeMipmappedArray : PROCESS_ARGS_hipFreeMipmappedArray(args); break;
		case HIP_API_ID_hipArrayCreate : PROCESS_ARGS_hipArrayCreate(args); break;
		case HIP_API_ID_hipUnbindTexture : PROCESS_ARGS_hipUnbindTexture(args); break;
		case HIP_API_ID_hipCtxPopCurrent : PROCESS_ARGS_hipCtxPopCurrent(args); break;
		case HIP_API_ID_hipMemsetD16Async : PROCESS_ARGS_hipMemsetD16Async(args); break;
		case HIP_API_ID_hipTexObjectGetResourceDesc : PROCESS_ARGS_hipTexObjectGetResourceDesc(args); break;
		case HIP_API_ID_hipLaunchKernel : PROCESS_ARGS_hipLaunchKernel(args); break;
		case HIP_API_ID_hipGraphMemsetNodeGetParams : PROCESS_ARGS_hipGraphMemsetNodeGetParams(args); break;
		case HIP_API_ID_hipHostGetFlags : PROCESS_ARGS_hipHostGetFlags(args); break;
		case HIP_API_ID_hipGraphLaunch : PROCESS_ARGS_hipGraphLaunch(args); break;
		case HIP_API_ID_hipMemcpyAsync : PROCESS_ARGS_hipMemcpyAsync(args); break;
		case HIP_API_ID_hipMallocArray : PROCESS_ARGS_hipMallocArray(args); break;
		case HIP_API_ID_hipFuncSetCacheConfig : PROCESS_ARGS_hipFuncSetCacheConfig(args); break;
		case HIP_API_ID_hipMallocManaged : PROCESS_ARGS_hipMallocManaged(args); break;
		case HIP_API_ID_hipApiName : PROCESS_ARGS_hipApiName(args); break;
		case HIP_API_ID_hipFreeHost : PROCESS_ARGS_hipFreeHost(args); break;
		case HIP_API_ID_hipCtxGetCurrent : PROCESS_ARGS_hipCtxGetCurrent(args); break;
		case HIP_API_ID_hipDestroySurfaceObject : PROCESS_ARGS_hipDestroySurfaceObject(args); break;
		case HIP_API_ID_hipMallocPitch : PROCESS_ARGS_hipMallocPitch(args); break;
		case HIP_API_ID_hipStreamGetCaptureInfo : PROCESS_ARGS_hipStreamGetCaptureInfo(args); break;
		case HIP_API_ID_hipStreamUpdateCaptureDependencies : PROCESS_ARGS_hipStreamUpdateCaptureDependencies(args); break;
		case HIP_API_ID_hipHostAlloc : PROCESS_ARGS_hipHostAlloc(args); break;
		case HIP_API_ID_hipMemsetD8 : PROCESS_ARGS_hipMemsetD8(args); break;
		case HIP_API_ID_hipMemset3DAsync : PROCESS_ARGS_hipMemset3DAsync(args); break;
		case HIP_API_ID_hipMemcpyParam2DAsync : PROCESS_ARGS_hipMemcpyParam2DAsync(args); break;
		case HIP_API_ID_hipDrvGetErrorName : PROCESS_ARGS_hipDrvGetErrorName(args); break;
		case HIP_API_ID_hipPointerSetAttribute : PROCESS_ARGS_hipPointerSetAttribute(args); break;
		case HIP_API_ID_hipMemGetInfo : PROCESS_ARGS_hipMemGetInfo(args); break;
		case HIP_API_ID___hipPushCallConfiguration : PROCESS_ARGS___hipPushCallConfiguration(args); break;
		case HIP_API_ID_hipTexRefGetFormat : PROCESS_ARGS_hipTexRefGetFormat(args); break;
		case HIP_API_ID_hipMemExportToShareableHandle : PROCESS_ARGS_hipMemExportToShareableHandle(args); break;
		case HIP_API_ID_hipTexRefGetFilterMode : PROCESS_ARGS_hipTexRefGetFilterMode(args); break;
		case HIP_API_ID_hipGraphHostNodeSetParams : PROCESS_ARGS_hipGraphHostNodeSetParams(args); break;
		case HIP_API_ID_hipGraphGetNodes : PROCESS_ARGS_hipGraphGetNodes(args); break;
		case HIP_API_ID_hipCtxGetDevice : PROCESS_ARGS_hipCtxGetDevice(args); break;
		case HIP_API_ID_hipGetSymbolAddress : PROCESS_ARGS_hipGetSymbolAddress(args); break;
		case HIP_API_ID_hipStreamGetCaptureInfo_v2 : PROCESS_ARGS_hipStreamGetCaptureInfo_v2(args); break;
		case HIP_API_ID_hipGetSymbolSize : PROCESS_ARGS_hipGetSymbolSize(args); break;
		case HIP_API_ID_hipGraphExecHostNodeSetParams : PROCESS_ARGS_hipGraphExecHostNodeSetParams(args); break;
		case HIP_API_ID_hipMemPoolSetAttribute : PROCESS_ARGS_hipMemPoolSetAttribute(args); break;
		case HIP_API_ID_hipDeviceSetMemPool : PROCESS_ARGS_hipDeviceSetMemPool(args); break;
		case HIP_API_ID_hipConfigureCall : PROCESS_ARGS_hipConfigureCall(args); break;
		case HIP_API_ID_hipMipmappedArrayCreate : PROCESS_ARGS_hipMipmappedArrayCreate(args); break;
		case HIP_API_ID_hipHostRegister : PROCESS_ARGS_hipHostRegister(args); break;
		case HIP_API_ID_hipBindTextureToArray : PROCESS_ARGS_hipBindTextureToArray(args); break;
		case HIP_API_ID_hipMallocHost : PROCESS_ARGS_hipMallocHost(args); break;
		case HIP_API_ID_hipMemcpyPeer : PROCESS_ARGS_hipMemcpyPeer(args); break;
		case HIP_API_ID_hipOccupancyMaxActiveBlocksPerMultiprocessor : PROCESS_ARGS_hipOccupancyMaxActiveBlocksPerMultiprocessor(args); break;
		case HIP_API_ID_hipDeviceGetAttribute : PROCESS_ARGS_hipDeviceGetAttribute(args); break;
		case HIP_API_ID_hipDevicePrimaryCtxReset : PROCESS_ARGS_hipDevicePrimaryCtxReset(args); break;
		case HIP_API_ID_hipTexRefSetAddress : PROCESS_ARGS_hipTexRefSetAddress(args); break;
		case HIP_API_ID_hipGraphicsResourceGetMappedPointer : PROCESS_ARGS_hipGraphicsResourceGetMappedPointer(args); break;
		case HIP_API_ID_hipCtxSetSharedMemConfig : PROCESS_ARGS_hipCtxSetSharedMemConfig(args); break;
		case HIP_API_ID_hipGraphExternalSemaphoresSignalNodeGetParams : PROCESS_ARGS_hipGraphExternalSemaphoresSignalNodeGetParams(args); break;
		case HIP_API_ID_hipArrayDestroy : PROCESS_ARGS_hipArrayDestroy(args); break;
		case HIP_API_ID_hipFreeAsync : PROCESS_ARGS_hipFreeAsync(args); break;
		case HIP_API_ID_hipArray3DGetDescriptor : PROCESS_ARGS_hipArray3DGetDescriptor(args); break;
		case HIP_API_ID_hipDeviceGetPCIBusId : PROCESS_ARGS_hipDeviceGetPCIBusId(args); break;
		case HIP_API_ID_hipGraphAddMemFreeNode : PROCESS_ARGS_hipGraphAddMemFreeNode(args); break;
		case HIP_API_ID_hipArray3DCreate : PROCESS_ARGS_hipArray3DCreate(args); break;
		case HIP_API_ID_hipGraphExternalSemaphoresSignalNodeSetParams : PROCESS_ARGS_hipGraphExternalSemaphoresSignalNodeSetParams(args); break;
		case HIP_API_ID_hipTexRefGetBorderColor : PROCESS_ARGS_hipTexRefGetBorderColor(args); break;
		case HIP_API_ID_hipModuleGetGlobal : PROCESS_ARGS_hipModuleGetGlobal(args); break;
		case HIP_API_ID_hipMallocMipmappedArray : PROCESS_ARGS_hipMallocMipmappedArray(args); break;
		case HIP_API_ID_hipProfilerStart : PROCESS_ARGS_hipProfilerStart(args); break;
		case HIP_API_ID_hipGraphExecMemcpyNodeSetParams : PROCESS_ARGS_hipGraphExecMemcpyNodeSetParams(args); break;
		case HIP_API_ID_hipEventSynchronize : PROCESS_ARGS_hipEventSynchronize(args); break;
		case HIP_API_ID_hipMemPoolExportPointer : PROCESS_ARGS_hipMemPoolExportPointer(args); break;
		case HIP_API_ID_hipHostUnregister : PROCESS_ARGS_hipHostUnregister(args); break;
		case HIP_API_ID_hipMemset2D : PROCESS_ARGS_hipMemset2D(args); break;
		case HIP_API_ID_hipMemcpy2DFromArray : PROCESS_ARGS_hipMemcpy2DFromArray(args); break;
		case HIP_API_ID_hipMemAddressReserve : PROCESS_ARGS_hipMemAddressReserve(args); break;
		case HIP_API_ID_hipFuncSetSharedMemConfig : PROCESS_ARGS_hipFuncSetSharedMemConfig(args); break;
		case HIP_API_ID_hipDestroyTextureObject : PROCESS_ARGS_hipDestroyTextureObject(args); break;
		case HIP_API_ID_hipTexRefSetMaxAnisotropy : PROCESS_ARGS_hipTexRefSetMaxAnisotropy(args); break;
		case HIP_API_ID_hipTexRefSetAddress2D : PROCESS_ARGS_hipTexRefSetAddress2D(args); break;
		case HIP_API_ID_hipGetDevice : PROCESS_ARGS_hipGetDevice(args); break;
		case HIP_API_ID_hipDeviceGetGraphMemAttribute : PROCESS_ARGS_hipDeviceGetGraphMemAttribute(args); break;
		case HIP_API_ID_hipGraphicsSubResourceGetMappedArray : PROCESS_ARGS_hipGraphicsSubResourceGetMappedArray(args); break;
		case HIP_API_ID_hipGraphMemcpyNodeSetParamsToSymbol : PROCESS_ARGS_hipGraphMemcpyNodeSetParamsToSymbol(args); break;
		case HIP_API_ID_hipStreamCreate : PROCESS_ARGS_hipStreamCreate(args); break;
		case HIP_API_ID_hipGraphNodeGetDependencies : PROCESS_ARGS_hipGraphNodeGetDependencies(args); break;
		case HIP_API_ID_hipBindTextureToMipmappedArray : PROCESS_ARGS_hipBindTextureToMipmappedArray(args); break;
		case HIP_API_ID_hipGraphExecUpdate : PROCESS_ARGS_hipGraphExecUpdate(args); break;
		case HIP_API_ID_hipDeviceTotalMem : PROCESS_ARGS_hipDeviceTotalMem(args); break;
		case HIP_API_ID_hipMemcpyFromArray : PROCESS_ARGS_hipMemcpyFromArray(args); break;
		case HIP_API_ID_hipEventCreateWithFlags : PROCESS_ARGS_hipEventCreateWithFlags(args); break;
		case HIP_API_ID_hipDeviceGetCacheConfig : PROCESS_ARGS_hipDeviceGetCacheConfig(args); break;
		case HIP_API_ID_hipDriverGetVersion : PROCESS_ARGS_hipDriverGetVersion(args); break;
		case HIP_API_ID_hipGraphMemcpyNodeSetParams1D : PROCESS_ARGS_hipGraphMemcpyNodeSetParams1D(args); break;
		case HIP_API_ID_hipTexRefSetMipmapLevelClamp : PROCESS_ARGS_hipTexRefSetMipmapLevelClamp(args); break;
		case HIP_API_ID_hipGraphMemAllocNodeGetParams : PROCESS_ARGS_hipGraphMemAllocNodeGetParams(args); break;
		case HIP_API_ID_hipTexObjectDestroy : PROCESS_ARGS_hipTexObjectDestroy(args); break;
		case HIP_API_ID_hipExtStreamCreateWithCUMask : PROCESS_ARGS_hipExtStreamCreateWithCUMask(args); break;
		case HIP_API_ID___hipPopCallConfiguration : PROCESS_ARGS___hipPopCallConfiguration(args); break;
		case HIP_API_ID_hipMemRangeGetAttribute : PROCESS_ARGS_hipMemRangeGetAttribute(args); break;
		case HIP_API_ID_hipMemMap : PROCESS_ARGS_hipMemMap(args); break;
		case HIP_API_ID_hipStreamSynchronize : PROCESS_ARGS_hipStreamSynchronize(args); break;
		case HIP_API_ID_hipUserObjectCreate : PROCESS_ARGS_hipUserObjectCreate(args); break;
		case HIP_API_ID_hipGetMipmappedArrayLevel : PROCESS_ARGS_hipGetMipmappedArrayLevel(args); break;
		case HIP_API_ID_hipMemcpyHtoD : PROCESS_ARGS_hipMemcpyHtoD(args); break;
		case HIP_API_ID_hipMemGetAddressRange : PROCESS_ARGS_hipMemGetAddressRange(args); break;
		case HIP_API_ID_hipGraphAddMemcpyNodeFromSymbol : PROCESS_ARGS_hipGraphAddMemcpyNodeFromSymbol(args); break;
		case HIP_API_ID_hipMemPtrGetInfo : PROCESS_ARGS_hipMemPtrGetInfo(args); break;
		case HIP_API_ID_hipTexRefSetMipmappedArray : PROCESS_ARGS_hipTexRefSetMipmappedArray(args); break;
		case HIP_API_ID_hipImportExternalSemaphore : PROCESS_ARGS_hipImportExternalSemaphore(args); break;
		case HIP_API_ID_hipStreamWaitEvent : PROCESS_ARGS_hipStreamWaitEvent(args); break;
		case HIP_API_ID_hipGetDeviceCount : PROCESS_ARGS_hipGetDeviceCount(args); break;
		case HIP_API_ID_hipGraphKernelNodeCopyAttributes : PROCESS_ARGS_hipGraphKernelNodeCopyAttributes(args); break;
		case HIP_API_ID_hipDestroyExternalSemaphore : PROCESS_ARGS_hipDestroyExternalSemaphore(args); break;
		case HIP_API_ID_hipGraphMemcpyNodeSetParams : PROCESS_ARGS_hipGraphMemcpyNodeSetParams(args); break;
		case HIP_API_ID_hipStreamQuery : PROCESS_ARGS_hipStreamQuery(args); break;
		case HIP_API_ID_hipGraphMemsetNodeSetParams : PROCESS_ARGS_hipGraphMemsetNodeSetParams(args); break;
		case HIP_API_ID_hipRuntimeGetVersion : PROCESS_ARGS_hipRuntimeGetVersion(args); break;
		case HIP_API_ID_hipArrayGetDescriptor : PROCESS_ARGS_hipArrayGetDescriptor(args); break;
		case HIP_API_ID_hipMemsetD32Async : PROCESS_ARGS_hipMemsetD32Async(args); break;
		case HIP_API_ID_hipCtxGetSharedMemConfig : PROCESS_ARGS_hipCtxGetSharedMemConfig(args); break;
		case HIP_API_ID_hipModuleLoadDataEx : PROCESS_ARGS_hipModuleLoadDataEx(args); break;
		case HIP_API_ID_hipMemPoolExportToShareableHandle : PROCESS_ARGS_hipMemPoolExportToShareableHandle(args); break;
		case HIP_API_ID_hipMallocFromPoolAsync : PROCESS_ARGS_hipMallocFromPoolAsync(args); break;
		case HIP_API_ID_hipSetDevice : PROCESS_ARGS_hipSetDevice(args); break;
		case HIP_API_ID_hipMallocAsync : PROCESS_ARGS_hipMallocAsync(args); break;
		case HIP_API_ID_hipDeviceGet : PROCESS_ARGS_hipDeviceGet(args); break;
		case HIP_API_ID_hipMemsetAsync : PROCESS_ARGS_hipMemsetAsync(args); break;
		case HIP_API_ID_hipMemSetAccess : PROCESS_ARGS_hipMemSetAccess(args); break;
		case HIP_API_ID_hipMemsetD32 : PROCESS_ARGS_hipMemsetD32(args); break;
		case HIP_API_ID_hipGetDeviceFlags : PROCESS_ARGS_hipGetDeviceFlags(args); break;
		case HIP_API_ID_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags : PROCESS_ARGS_hipOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(args); break;
		case HIP_API_ID_hipDeviceGetUuid : PROCESS_ARGS_hipDeviceGetUuid(args); break;
		case HIP_API_ID_hipMemcpy2D : PROCESS_ARGS_hipMemcpy2D(args); break;
		case HIP_API_ID_hipArrayGetInfo : PROCESS_ARGS_hipArrayGetInfo(args); break;
		case HIP_API_ID_hipUserObjectRetain : PROCESS_ARGS_hipUserObjectRetain(args); break;
		case HIP_API_ID_hipGraphicsMapResources : PROCESS_ARGS_hipGraphicsMapResources(args); break;
		case HIP_API_ID_hipMemcpyHtoDAsync : PROCESS_ARGS_hipMemcpyHtoDAsync(args); break;
		case HIP_API_ID_hipTexObjectGetTextureDesc : PROCESS_ARGS_hipTexObjectGetTextureDesc(args); break;
		case HIP_API_ID_hipMemGetAccess : PROCESS_ARGS_hipMemGetAccess(args); break;
		case HIP_API_ID_hipMemcpy2DToArrayAsync : PROCESS_ARGS_hipMemcpy2DToArrayAsync(args); break;
		case HIP_API_ID_hipTexRefGetAddress : PROCESS_ARGS_hipTexRefGetAddress(args); break;
		case HIP_API_ID_hipGraphNodeGetType : PROCESS_ARGS_hipGraphNodeGetType(args); break;
		case HIP_API_ID_hipStreamGetFlags : PROCESS_ARGS_hipStreamGetFlags(args); break;
		case HIP_API_ID_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor : PROCESS_ARGS_hipModuleOccupancyMaxActiveBlocksPerMultiprocessor(args); break;
		case HIP_API_ID_hipMemset2DAsync : PROCESS_ARGS_hipMemset2DAsync(args); break;
		case HIP_API_ID_hipMemcpyFromSymbol : PROCESS_ARGS_hipMemcpyFromSymbol(args); break;
		case HIP_API_ID_hipHostFree : PROCESS_ARGS_hipHostFree(args); break;
		case HIP_API_ID_hipExtLaunchKernel : PROCESS_ARGS_hipExtLaunchKernel(args); break;
		case HIP_API_ID_hipMemcpyFromSymbolAsync : PROCESS_ARGS_hipMemcpyFromSymbolAsync(args); break;
		case HIP_API_ID_hipCtxCreate : PROCESS_ARGS_hipCtxCreate(args); break;
		case HIP_API_ID_hipLaunchCooperativeKernel : PROCESS_ARGS_hipLaunchCooperativeKernel(args); break;
		case HIP_API_ID_hipExtStreamGetCUMask : PROCESS_ARGS_hipExtStreamGetCUMask(args); break;
		case HIP_API_ID_hipGraphExecDestroy : PROCESS_ARGS_hipGraphExecDestroy(args); break;
		case HIP_API_ID_hipDrvGetErrorString : PROCESS_ARGS_hipDrvGetErrorString(args); break;
		case HIP_API_ID_hipInit : PROCESS_ARGS_hipInit(args); break;
		case HIP_API_ID_hipBindTexture2D : PROCESS_ARGS_hipBindTexture2D(args); break;
		case HIP_API_ID_hipExtGetLinkTypeAndHopCount : PROCESS_ARGS_hipExtGetLinkTypeAndHopCount(args); break;
		case HIP_API_ID_hipGetTextureObjectResourceViewDesc : PROCESS_ARGS_hipGetTextureObjectResourceViewDesc(args); break;
		case HIP_API_ID_hipMemCreate : PROCESS_ARGS_hipMemCreate(args); break;
		case HIP_API_ID_hipMemsetD8Async : PROCESS_ARGS_hipMemsetD8Async(args); break;
		case HIP_API_ID_hipLaunchHostFunc : PROCESS_ARGS_hipLaunchHostFunc(args); break;
		case HIP_API_ID_hipGraphGetEdges : PROCESS_ARGS_hipGraphGetEdges(args); break;
		case HIP_API_ID_hipMemPoolDestroy : PROCESS_ARGS_hipMemPoolDestroy(args); break;
		case HIP_API_ID_hipGraphKernelNodeGetParams : PROCESS_ARGS_hipGraphKernelNodeGetParams(args); break;
		case HIP_API_ID_hipDrvPointerGetAttributes : PROCESS_ARGS_hipDrvPointerGetAttributes(args); break;
		case HIP_API_ID_hipFuncSetAttribute : PROCESS_ARGS_hipFuncSetAttribute(args); break;
		case HIP_API_ID_hipGraphAddDependencies : PROCESS_ARGS_hipGraphAddDependencies(args); break;
		case HIP_API_ID_hipStreamWriteValue64 : PROCESS_ARGS_hipStreamWriteValue64(args); break;
		case HIP_API_ID_hipCreateSurfaceObject : PROCESS_ARGS_hipCreateSurfaceObject(args); break;
		case HIP_API_ID_hipGetTextureObjectTextureDesc : PROCESS_ARGS_hipGetTextureObjectTextureDesc(args); break;
		case HIP_API_ID_hipMemUnmap : PROCESS_ARGS_hipMemUnmap(args); break;
		case HIP_API_ID_hipGraphChildGraphNodeGetGraph : PROCESS_ARGS_hipGraphChildGraphNodeGetGraph(args); break;
		case HIP_API_ID_hipStreamCreateWithFlags : PROCESS_ARGS_hipStreamCreateWithFlags(args); break;
		case HIP_API_ID_hipMemPoolCreate : PROCESS_ARGS_hipMemPoolCreate(args); break;
		case HIP_API_ID_hipLaunchCooperativeKernelMultiDevice : PROCESS_ARGS_hipLaunchCooperativeKernelMultiDevice(args); break;
		case HIP_API_ID_hipTexRefSetFilterMode : PROCESS_ARGS_hipTexRefSetFilterMode(args); break;
		case HIP_API_ID_hipDeviceSetGraphMemAttribute : PROCESS_ARGS_hipDeviceSetGraphMemAttribute(args); break;
		case HIP_API_ID_hipGraphExecMemcpyNodeSetParams1D : PROCESS_ARGS_hipGraphExecMemcpyNodeSetParams1D(args); break;
		case HIP_API_ID_hipGraphExecKernelNodeSetParams : PROCESS_ARGS_hipGraphExecKernelNodeSetParams(args); break;
		case HIP_API_ID_hipGraphInstantiate : PROCESS_ARGS_hipGraphInstantiate(args); break;
		case HIP_API_ID_hipGraphExecExternalSemaphoresSignalNodeSetParams : PROCESS_ARGS_hipGraphExecExternalSemaphoresSignalNodeSetParams(args); break;
		case HIP_API_ID_hipCreateTextureObject : PROCESS_ARGS_hipCreateTextureObject(args); break;
		case HIP_API_ID_hipEventQuery : PROCESS_ARGS_hipEventQuery(args); break;
		case HIP_API_ID_hipCtxPushCurrent : PROCESS_ARGS_hipCtxPushCurrent(args); break;
		case HIP_API_ID_hipGraphGetRootNodes : PROCESS_ARGS_hipGraphGetRootNodes(args); break;
		case HIP_API_ID_hipGetErrorString : PROCESS_ARGS_hipGetErrorString(args); break;
		case HIP_API_ID_hipMemAddressFree : PROCESS_ARGS_hipMemAddressFree(args); break;
		case HIP_API_ID_hipDeviceSynchronize : PROCESS_ARGS_hipDeviceSynchronize(args); break;
		case HIP_API_ID_hipCtxGetFlags : PROCESS_ARGS_hipCtxGetFlags(args); break;
		case HIP_API_ID_hipTexRefGetArray : PROCESS_ARGS_hipTexRefGetArray(args); break;
		case HIP_API_ID_hipMemGetAllocationGranularity : PROCESS_ARGS_hipMemGetAllocationGranularity(args); break;
		case HIP_API_ID_hipProfilerStop : PROCESS_ARGS_hipProfilerStop(args); break;
		case HIP_API_ID_hipTexRefSetArray : PROCESS_ARGS_hipTexRefSetArray(args); break;
		case HIP_API_ID_hipEventDestroy : PROCESS_ARGS_hipEventDestroy(args); break;
		case HIP_API_ID_hipDeviceSetCacheConfig : PROCESS_ARGS_hipDeviceSetCacheConfig(args); break;
		case HIP_API_ID_hipLaunchByPtr : PROCESS_ARGS_hipLaunchByPtr(args); break;
		case HIP_API_ID_hipModuleLaunchCooperativeKernelMultiDevice : PROCESS_ARGS_hipModuleLaunchCooperativeKernelMultiDevice(args); break;
		case HIP_API_ID_hipTexRefSetAddressMode : PROCESS_ARGS_hipTexRefSetAddressMode(args); break;
		case HIP_API_ID_hipModuleLoadData : PROCESS_ARGS_hipModuleLoadData(args); break;
		case HIP_API_ID_hipDrvMemcpy2DUnaligned : PROCESS_ARGS_hipDrvMemcpy2DUnaligned(args); break;
		case HIP_API_ID_hipGraphExecChildGraphNodeSetParams : PROCESS_ARGS_hipGraphExecChildGraphNodeSetParams(args); break;
		case HIP_API_ID_hipPointerGetAttributes : PROCESS_ARGS_hipPointerGetAttributes(args); break;
		case HIP_API_ID_hipMemcpyDtoHAsync : PROCESS_ARGS_hipMemcpyDtoHAsync(args); break;
		case HIP_API_ID_hipGraphAddEventRecordNode : PROCESS_ARGS_hipGraphAddEventRecordNode(args); break;
		case HIP_API_ID_hipGraphAddExternalSemaphoresSignalNode : PROCESS_ARGS_hipGraphAddExternalSemaphoresSignalNode(args); break;
		case HIP_API_ID_hipGraphRetainUserObject : PROCESS_ARGS_hipGraphRetainUserObject(args); break;
		case HIP_API_ID_hipSetupArgument : PROCESS_ARGS_hipSetupArgument(args); break;
		case HIP_API_ID_hipMemAllocPitch : PROCESS_ARGS_hipMemAllocPitch(args); break;
		case HIP_API_ID_hipGraphEventWaitNodeGetEvent : PROCESS_ARGS_hipGraphEventWaitNodeGetEvent(args); break;
		case HIP_API_ID_hipMemcpy2DToArray : PROCESS_ARGS_hipMemcpy2DToArray(args); break;
		case HIP_API_ID_hipMemcpyPeerAsync : PROCESS_ARGS_hipMemcpyPeerAsync(args); break;
		case HIP_API_ID_hipTexObjectCreate : PROCESS_ARGS_hipTexObjectCreate(args); break;
		case HIP_API_ID_hipDeviceGetLimit : PROCESS_ARGS_hipDeviceGetLimit(args); break;
		case HIP_API_ID_hipExtMallocWithFlags : PROCESS_ARGS_hipExtMallocWithFlags(args); break;
		case HIP_API_ID_hipGetErrorName : PROCESS_ARGS_hipGetErrorName(args); break;
		case HIP_API_ID_hipMemcpy3D : PROCESS_ARGS_hipMemcpy3D(args); break;
		case HIP_API_ID_hipGraphMemcpyNodeSetParamsFromSymbol : PROCESS_ARGS_hipGraphMemcpyNodeSetParamsFromSymbol(args); break;
		case HIP_API_ID_hipMemRangeGetAttributes : PROCESS_ARGS_hipMemRangeGetAttributes(args); break;
		case HIP_API_ID_hipGraphDebugDotPrint : PROCESS_ARGS_hipGraphDebugDotPrint(args); break;
		case HIP_API_ID_hipGraphExternalSemaphoresWaitNodeGetParams : PROCESS_ARGS_hipGraphExternalSemaphoresWaitNodeGetParams(args); break;
		case HIP_API_ID_hipMemset : PROCESS_ARGS_hipMemset(args); break;
		case HIP_API_ID_hipGraphAddHostNode : PROCESS_ARGS_hipGraphAddHostNode(args); break;
		case HIP_API_ID_hipGraphAddMemcpyNode : PROCESS_ARGS_hipGraphAddMemcpyNode(args); break;
		case HIP_API_ID_hipGraphHostNodeGetParams : PROCESS_ARGS_hipGraphHostNodeGetParams(args); break;
		case HIP_API_ID_hipDeviceGetByPCIBusId : PROCESS_ARGS_hipDeviceGetByPCIBusId(args); break;
		case HIP_API_ID_hipMemcpyDtoD : PROCESS_ARGS_hipMemcpyDtoD(args); break;
		case HIP_API_ID_hipIpcGetEventHandle : PROCESS_ARGS_hipIpcGetEventHandle(args); break;
		case HIP_API_ID_hipGraphKernelNodeSetParams : PROCESS_ARGS_hipGraphKernelNodeSetParams(args); break;
		case HIP_API_ID_hipModuleGetFunction : PROCESS_ARGS_hipModuleGetFunction(args); break;
		case HIP_API_ID_hipMemcpyAtoH : PROCESS_ARGS_hipMemcpyAtoH(args); break;
		case HIP_API_ID_hipDeviceEnablePeerAccess : PROCESS_ARGS_hipDeviceEnablePeerAccess(args); break;
		case HIP_API_ID_hipMemRetainAllocationHandle : PROCESS_ARGS_hipMemRetainAllocationHandle(args); break;
		case HIP_API_ID_hipTexRefGetMipMappedArray : PROCESS_ARGS_hipTexRefGetMipMappedArray(args); break;
		case HIP_API_ID_hipTexRefGetMipmapLevelBias : PROCESS_ARGS_hipTexRefGetMipmapLevelBias(args); break;
		case HIP_API_ID_hipBindTexture : PROCESS_ARGS_hipBindTexture(args); break;
		case HIP_API_ID_hipGraphAddChildGraphNode : PROCESS_ARGS_hipGraphAddChildGraphNode(args); break;
		case HIP_API_ID_hipDeviceSetLimit : PROCESS_ARGS_hipDeviceSetLimit(args); break;
		case HIP_API_ID_hipGetChannelDesc : PROCESS_ARGS_hipGetChannelDesc(args); break;
		case HIP_API_ID_hipGraphicsUnregisterResource : PROCESS_ARGS_hipGraphicsUnregisterResource(args); break;
		case HIP_API_ID_hipGraphRemoveDependencies : PROCESS_ARGS_hipGraphRemoveDependencies(args); break;
		case HIP_API_ID_hipTexRefSetBorderColor : PROCESS_ARGS_hipTexRefSetBorderColor(args); break;
		case HIP_API_ID_hipDevicePrimaryCtxGetState : PROCESS_ARGS_hipDevicePrimaryCtxGetState(args); break;
		case HIP_API_ID_hipMalloc3D : PROCESS_ARGS_hipMalloc3D(args); break;
		case HIP_API_ID_hipTexRefGetMipmapLevelClamp : PROCESS_ARGS_hipTexRefGetMipmapLevelClamp(args); break;
		case HIP_API_ID_hipModuleLaunchKernel : PROCESS_ARGS_hipModuleLaunchKernel(args); break;
		case HIP_API_ID_hipKernelNameRefByPtr : PROCESS_ARGS_hipKernelNameRefByPtr(args); break;
		case HIP_API_ID_hipDeviceSetSharedMemConfig : PROCESS_ARGS_hipDeviceSetSharedMemConfig(args); break;
		case HIP_API_ID_hipMemcpyToSymbolAsync : PROCESS_ARGS_hipMemcpyToSymbolAsync(args); break;
		case HIP_API_ID_hipHostGetDevicePointer : PROCESS_ARGS_hipHostGetDevicePointer(args); break;
		case HIP_API_ID_hipGraphReleaseUserObject : PROCESS_ARGS_hipGraphReleaseUserObject(args); break;
		case HIP_API_ID_hipDeviceGraphMemTrim : PROCESS_ARGS_hipDeviceGraphMemTrim(args); break;
		case HIP_API_ID_hipDeviceGetStreamPriorityRange : PROCESS_ARGS_hipDeviceGetStreamPriorityRange(args); break;
		case HIP_API_ID_hipPointerGetAttribute : PROCESS_ARGS_hipPointerGetAttribute(args); break;
		case HIP_API_ID_hipMemPoolSetAccess : PROCESS_ARGS_hipMemPoolSetAccess(args); break;
		case HIP_API_ID_hipGraphExecExternalSemaphoresWaitNodeSetParams : PROCESS_ARGS_hipGraphExecExternalSemaphoresWaitNodeSetParams(args); break;
		case HIP_API_ID_hipMemcpy : PROCESS_ARGS_hipMemcpy(args); break;
		case HIP_API_ID_hipDeviceDisablePeerAccess : PROCESS_ARGS_hipDeviceDisablePeerAccess(args); break;
		case HIP_API_ID_hipGraphKernelNodeSetAttribute : PROCESS_ARGS_hipGraphKernelNodeSetAttribute(args); break;
		case HIP_API_ID_hipGraphAddMemcpyNode1D : PROCESS_ARGS_hipGraphAddMemcpyNode1D(args); break;
		case HIP_API_ID_hipGraphExecEventRecordNodeSetEvent : PROCESS_ARGS_hipGraphExecEventRecordNodeSetEvent(args); break;
		case HIP_API_ID_hipGraphicsUnmapResources : PROCESS_ARGS_hipGraphicsUnmapResources(args); break;
		case HIP_API_ID_hipGraphAddExternalSemaphoresWaitNode : PROCESS_ARGS_hipGraphAddExternalSemaphoresWaitNode(args); break;
		case HIP_API_ID_hipDrvGraphAddMemcpyNode : PROCESS_ARGS_hipDrvGraphAddMemcpyNode(args); break;
		case HIP_API_ID_hipEventElapsedTime : PROCESS_ARGS_hipEventElapsedTime(args); break;
		case HIP_API_ID_hipMemcpy3DAsync : PROCESS_ARGS_hipMemcpy3DAsync(args); break;
		case HIP_API_ID_hipTexRefGetMaxAnisotropy : PROCESS_ARGS_hipTexRefGetMaxAnisotropy(args); break;
		case HIP_API_ID_hipGraphNodeGetDependentNodes : PROCESS_ARGS_hipGraphNodeGetDependentNodes(args); break;
		case HIP_API_ID_hipMemPoolGetAttribute : PROCESS_ARGS_hipMemPoolGetAttribute(args); break;
		case HIP_API_ID_hipStreamGetDevice : PROCESS_ARGS_hipStreamGetDevice(args); break;
		case HIP_API_ID_hipGetTextureObjectResourceDesc : PROCESS_ARGS_hipGetTextureObjectResourceDesc(args); break;
		case HIP_API_ID_hipTexRefGetFlags : PROCESS_ARGS_hipTexRefGetFlags(args); break;
		case HIP_API_ID_hipChooseDeviceR0600 : PROCESS_ARGS_hipChooseDeviceR0600(args); break;
		case HIP_API_ID_hipSignalExternalSemaphoresAsync : PROCESS_ARGS_hipSignalExternalSemaphoresAsync(args); break;
		case HIP_API_ID_hipDeviceCanAccessPeer : PROCESS_ARGS_hipDeviceCanAccessPeer(args); break;
		case HIP_API_ID_hipDevicePrimaryCtxRetain : PROCESS_ARGS_hipDevicePrimaryCtxRetain(args); break;
		case HIP_API_ID_hipCtxDisablePeerAccess : PROCESS_ARGS_hipCtxDisablePeerAccess(args); break;
		case HIP_API_ID_hipStreamGetPriority : PROCESS_ARGS_hipStreamGetPriority(args); break;
		case HIP_API_ID_hipEventCreate : PROCESS_ARGS_hipEventCreate(args); break;
		case HIP_API_ID_hipGetLastError : PROCESS_ARGS_hipGetLastError(args); break;
		case HIP_API_ID_hipDeviceComputeCapability : PROCESS_ARGS_hipDeviceComputeCapability(args); break;
		case HIP_API_ID_hipGetDevicePropertiesR0600 : PROCESS_ARGS_hipGetDevicePropertiesR0600(args); break;
		case HIP_API_ID_hipOccupancyMaxPotentialBlockSize : PROCESS_ARGS_hipOccupancyMaxPotentialBlockSize(args); break;
		case HIP_API_ID_hipGetTextureAlignmentOffset : PROCESS_ARGS_hipGetTextureAlignmentOffset(args); break;
		case HIP_API_ID_hipIpcOpenMemHandle : PROCESS_ARGS_hipIpcOpenMemHandle(args); break;
		case HIP_API_ID_hipGraphNodeFindInClone : PROCESS_ARGS_hipGraphNodeFindInClone(args); break;
		case HIP_API_ID_hipDevicePrimaryCtxRelease : PROCESS_ARGS_hipDevicePrimaryCtxRelease(args); break;
		case HIP_API_ID_hipCtxSetCurrent : PROCESS_ARGS_hipCtxSetCurrent(args); break;
		case HIP_API_ID_hipGraphExecMemcpyNodeSetParamsFromSymbol : PROCESS_ARGS_hipGraphExecMemcpyNodeSetParamsFromSymbol(args); break;
		case HIP_API_ID_hipCtxSetCacheConfig : PROCESS_ARGS_hipCtxSetCacheConfig(args); break;
		case HIP_API_ID_hipMemMapArrayAsync : PROCESS_ARGS_hipMemMapArrayAsync(args); break;
		case HIP_API_ID_hipImportExternalMemory : PROCESS_ARGS_hipImportExternalMemory(args); break;
		case HIP_API_ID_hipGraphExecEventWaitNodeSetEvent : PROCESS_ARGS_hipGraphExecEventWaitNodeSetEvent(args); break;
		case HIP_API_ID_hipStreamBeginCapture : PROCESS_ARGS_hipStreamBeginCapture(args); break;
		case HIP_API_ID_hipIpcGetMemHandle : PROCESS_ARGS_hipIpcGetMemHandle(args); break;
		case HIP_API_ID_hipWaitExternalSemaphoresAsync : PROCESS_ARGS_hipWaitExternalSemaphoresAsync(args); break;
		case HIP_API_ID_hipTexRefGetMipmapFilterMode : PROCESS_ARGS_hipTexRefGetMipmapFilterMode(args); break;
		case HIP_API_ID_hipMemPoolGetAccess : PROCESS_ARGS_hipMemPoolGetAccess(args); break;
		case HIP_API_ID_hipDrvGraphAddMemsetNode : PROCESS_ARGS_hipDrvGraphAddMemsetNode(args); break;
		case HIP_API_ID_hipMemset3D : PROCESS_ARGS_hipMemset3D(args); break;
		case HIP_API_ID_hipDrvMemcpy3D : PROCESS_ARGS_hipDrvMemcpy3D(args); break;
		case HIP_API_ID_hipMemcpy2DFromArrayAsync : PROCESS_ARGS_hipMemcpy2DFromArrayAsync(args); break;
		case HIP_API_ID_hipExtLaunchMultiKernelMultiDevice : PROCESS_ARGS_hipExtLaunchMultiKernelMultiDevice(args); break;
		case HIP_API_ID_hipStreamWaitValue64 : PROCESS_ARGS_hipStreamWaitValue64(args); break;
		case HIP_API_ID_hipModuleGetTexRef : PROCESS_ARGS_hipModuleGetTexRef(args); break;
		case HIP_API_ID_hipMemcpyDtoDAsync : PROCESS_ARGS_hipMemcpyDtoDAsync(args); break;
		case HIP_API_ID_hipTexObjectGetResourceViewDesc : PROCESS_ARGS_hipTexObjectGetResourceViewDesc(args); break;
		case HIP_API_ID_hipStreamAddCallback : PROCESS_ARGS_hipStreamAddCallback(args); break;
		case HIP_API_ID_hipTexRefSetFormat : PROCESS_ARGS_hipTexRefSetFormat(args); break;
		case HIP_API_ID_hipFuncGetAttributes : PROCESS_ARGS_hipFuncGetAttributes(args); break;
		case HIP_API_ID_hipStreamCreateWithPriority : PROCESS_ARGS_hipStreamCreateWithPriority(args); break;
		case HIP_API_ID_hipGetTextureReference : PROCESS_ARGS_hipGetTextureReference(args); break;
		case HIP_API_ID_hipGraphAddKernelNode : PROCESS_ARGS_hipGraphAddKernelNode(args); break;
		case HIP_API_ID_hipMemcpyToArray : PROCESS_ARGS_hipMemcpyToArray(args); break;
		case HIP_API_ID_hipIpcCloseMemHandle : PROCESS_ARGS_hipIpcCloseMemHandle(args); break;
		case HIP_API_ID_hipGraphDestroy : PROCESS_ARGS_hipGraphDestroy(args); break;
		case HIP_API_ID_hipMemAdvise : PROCESS_ARGS_hipMemAdvise(args); break;
		case HIP_API_ID_hipGraphDestroyNode : PROCESS_ARGS_hipGraphDestroyNode(args); break;
		case HIP_API_ID_hipFuncGetAttribute : PROCESS_ARGS_hipFuncGetAttribute(args); break;
		case HIP_API_ID_hipCtxEnablePeerAccess : PROCESS_ARGS_hipCtxEnablePeerAccess(args); break;
		case HIP_API_ID_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags : PROCESS_ARGS_hipModuleOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(args); break;
		case HIP_API_ID_hipCtxSynchronize : PROCESS_ARGS_hipCtxSynchronize(args); break;
		case HIP_API_ID_hipDestroyExternalMemory : PROCESS_ARGS_hipDestroyExternalMemory(args); break;
		case HIP_API_ID_hipStreamDestroy : PROCESS_ARGS_hipStreamDestroy(args); break;
		case HIP_API_ID_hipGraphAddMemcpyNodeToSymbol : PROCESS_ARGS_hipGraphAddMemcpyNodeToSymbol(args); break;
		case HIP_API_ID_hipGraphEventRecordNodeSetEvent : PROCESS_ARGS_hipGraphEventRecordNodeSetEvent(args); break;
		case HIP_API_ID_hipDeviceGetP2PAttribute : PROCESS_ARGS_hipDeviceGetP2PAttribute(args); break;
		case HIP_API_ID_hipGetStreamDeviceId : PROCESS_ARGS_hipGetStreamDeviceId(args); break;
		case HIP_API_ID_hipGraphNodeGetEnabled : PROCESS_ARGS_hipGraphNodeGetEnabled(args); break;
		case HIP_API_ID_hipDeviceGetMemPool : PROCESS_ARGS_hipDeviceGetMemPool(args); break;
		case HIP_API_ID_hipMipmappedArrayGetLevel : PROCESS_ARGS_hipMipmappedArrayGetLevel(args); break;
		case HIP_API_ID_hipGraphExecMemcpyNodeSetParamsToSymbol : PROCESS_ARGS_hipGraphExecMemcpyNodeSetParamsToSymbol(args); break;
		case HIP_API_ID_hipGraphExecMemsetNodeSetParams : PROCESS_ARGS_hipGraphExecMemsetNodeSetParams(args); break; 
        default : break;
    }
}

