#ifndef OMP_TGT_RTL_MINIMAL_ABI_H_
#define OMP_TGT_RTL_MINIMAL_ABI_H_

#include <stdint.h>
#include <stddef.h>

/* ============================================================================ *
 * Minimal ABI Header for OMP_TGT_RTL
 * Auto-generated from CSV type definitions
 * ============================================================================ */

/* ============================================================================ *
 * Structure Types
 * ============================================================================ */

typedef struct KernelArgsTy KernelArgsTy;
typedef struct __tgt_async_info __tgt_async_info;
typedef struct __tgt_device_binary __tgt_device_binary;
typedef struct __tgt_device_image __tgt_device_image;
typedef struct __tgt_device_info __tgt_device_info;
typedef struct __tgt_offload_entry __tgt_offload_entry;
typedef struct __tgt_target_table __tgt_target_table;

/* ============================================================================ *
 * Structure Definitions
 * ============================================================================ */

struct __tgt_device_binary {
    uintptr_t handle;
};

struct __tgt_offload_entry {
    void *addr;
    char *name;
    size_t size;
    int32_t flags;
    int32_t reserved;
};

struct __tgt_device_image {
    void *ImageStart;
    void *ImageEnd;
    __tgt_offload_entry *EntriesBegin;
    __tgt_offload_entry *EntriesEnd;
};

struct __tgt_device_info {
    void *Context;
    void *Device;
};

struct __tgt_target_table {
    __tgt_offload_entry *EntriesBegin;
    __tgt_offload_entry *EntriesEnd;
};

struct __tgt_async_info {
    void *Queue;
};

struct KernelArgsTy {
    uint32_t Version;
    uint32_t NumArgs;
    void **ArgBasePtrs;
    void **ArgPtrs;
    int64_t *ArgSizes;
    int64_t *ArgTypes;
    void **ArgNames;
    void **ArgMappers;
    uint64_t Tripcount;
    struct {
        uint64_t NoWait;
        uint64_t Unused;
    } Flags;
    uint32_t NumTeams[3];
    uint32_t ThreadLimit[3];
    uint32_t DynCGroupMem;
};


#endif /* OMP_TGT_RTL_MINIMAL_ABI_H_ */
