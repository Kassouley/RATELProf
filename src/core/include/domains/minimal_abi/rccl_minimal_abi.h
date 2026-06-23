#ifndef RCCL_MINIMAL_ABI_H_
#define RCCL_MINIMAL_ABI_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* ============================================================================ *
 * Minimal ABI Header for RCCL
 * Auto-generated from CSV type definitions
 * ============================================================================ */

/* ============================================================================ *
 * Enum Types
 * ============================================================================ */

typedef enum ncclResult_t ncclResult_t;
typedef enum ncclDataType_t ncclDataType_t;
typedef enum ncclRedOp_t ncclRedOp_t;
typedef enum ncclRedOp_dummy_t ncclRedOp_dummy_t;
typedef enum ncclScalarResidence_t ncclScalarResidence_t;

/* ============================================================================ *
 * Enum Definitions
 * ============================================================================ */

enum ncclDataType_t {
	ncclInt8 = 0,
	ncclChar = 0,
	ncclUint8 = 1,
	ncclInt32 = 2,
	ncclInt = 2,
	ncclUint32 = 3,
	ncclInt64 = 4,
	ncclUint64 = 5,
	ncclFloat16 = 6,
	ncclHalf = 6,
	ncclFloat32 = 7,
	ncclFloat = 7,
	ncclFloat64 = 8,
	ncclDouble = 8,
	ncclBfloat16 = 9,
	ncclFloat8e4m3 = 10,
	ncclFloat8e5m2 = 11,
	ncclNumTypes = 12,
};
enum ncclResult_t {
	ncclSuccess = 0,
	ncclUnhandledCudaError = 1,
	ncclSystemError = 2,
	ncclInternalError = 3,
	ncclInvalidArgument = 4,
	ncclInvalidUsage = 5,
	ncclRemoteError = 6,
	ncclInProgress = 7,
	ncclNumResults = 8,
};
enum ncclRedOp_t {
	ncclSum = 0,
	ncclProd = 1,
	ncclMax = 2,
	ncclMin = 3,
	ncclAvg = 4,
	ncclNumOps = 5,
	ncclMaxRedOp = 2147483647,
};
enum ncclRedOp_dummy_t {
	ncclNumOps_dummy = 5,
};
enum ncclScalarResidence_t {
	ncclScalarDevice = 0,
	ncclScalarHostImmediate = 1,
};

/* ============================================================================ *
 * Structure Types
 * ============================================================================ */

typedef struct ncclSimInfo_v22200 ncclSimInfo_t;
typedef struct ncclUniqueId ncclUniqueId;
typedef struct ncclConfig_v22700 ncclConfig_t;

/* ============================================================================ *
 * Opaque Types
 * ============================================================================ */

typedef struct ncclComm *ncclComm_t;
typedef struct ncclWindow *ncclWindow_t;

/* ============================================================================ *
 * Basic Types
 * ============================================================================ */

typedef int mscclAlgoHandle_t;

/* ============================================================================ *
 * Structure Definitions
 * ============================================================================ */

struct ncclUniqueId {
    char internal[128];
};

struct ncclComm;

struct ncclWindow;

struct ncclSimInfo_v22200 {
    size_t size;
    unsigned int magic;
    unsigned int version;
    float estimatedTime;
};

struct ncclConfig_v22700 {
    size_t size;
    unsigned int magic;
    unsigned int version;
    int blocking;
    int cgaClusterSize;
    int minCTAs;
    int maxCTAs;
    const char *netName;
    int splitShare;
    int trafficClass;
    const char *commName;
    int collnetEnable;
    int CTAPolicy;
    int shrinkShare;
    int nvlsCTAs;
};


#endif /* RCCL_MINIMAL_ABI_H_ */
