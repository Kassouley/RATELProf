#ifndef OMP_SUPPORT_H
#define OMP_SUPPORT_H

#include <stddef.h>
#include <stdint.h>

typedef struct __tgt_async_info {
  void *Queue;
}__tgt_async_info;

typedef struct __tgt_device_binary {
  uintptr_t handle;
}__tgt_device_binary;

typedef struct __tgt_device_info {
  void *Context;
  void *Device;
}__tgt_device_info;

typedef struct __tgt_offload_entry {
  void *addr;   // Pointer to the offload entry info (function or global)
  char *name;   // Name of the function or global
  size_t size;  // Size of the entry info (0 if it is a function)
  int32_t flags; // Flags associated with the entry, e.g. 'link'.
  int32_t reserved; // Reserved, to be used by the runtime library.
}__tgt_offload_entry;

typedef struct __tgt_device_image {
  void *ImageStart;                 
  void *ImageEnd;                   
  __tgt_offload_entry *EntriesBegin;
  __tgt_offload_entry *EntriesEnd;  
} __tgt_device_image;

typedef struct __tgt_target_table {
  __tgt_offload_entry  *EntriesBegin;   // Begin of the table with all the entries
  __tgt_offload_entry  *EntriesEnd;     // End of the table with all the entries (non inclusive)
} __tgt_target_table;

typedef struct KernelArgsTy {
  uint32_t Version;       // Version of this struct for ABI compatibility.
  uint32_t NumArgs;       // Number of arguments in each input pointer.
  void **ArgBasePtrs;     // Base pointer of each argument (e.g. a struct).
  void **ArgPtrs;         // Pointer to the argument data.
  int64_t *ArgSizes;      // Size of the argument data in bytes.
  int64_t *ArgTypes;      // Type of the data (e.g. to / from).
  void **ArgNames;        // Name of the data for debugging, possibly null.
  void **ArgMappers;      // User-defined mappers, possibly null.
  uint64_t Tripcount;     // Tripcount for the teams / distribute loop, 0 otherwise.
  struct {
    uint64_t NoWait : 1;  // Was this kernel spawned with a `nowait` clause.
    uint64_t Unused : 63;
  } Flags;
  uint32_t NumTeams[3];    // The number of teams (for x,y,z dimension).
  uint32_t ThreadLimit[3]; // The number of threads (for x,y,z dimension).
  uint32_t DynCGroupMem;   // Amount of dynamic cgroup memory requested.
} KernelArgsTy;

#endif