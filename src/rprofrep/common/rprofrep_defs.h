#ifndef RPROFREP_DEFS_H
#define RPROFREP_DEFS_H

#define RPROFREP_VERSION_MAJOR 1
#define RPROFREP_VERSION_MINOR 1
#define RPROFREP_VERSION_PATCH 1

#define RPROFREP_FILE_MAGIC "RATELProf"
#define RPROFREP_FILE_MAGIC_SIZE sizeof(RPROFREP_FILE_MAGIC)

#include <stdint.h>

typedef enum {
    RPROFREP_SECTION_GLOBAL,
    RPROFREP_SECTION_STRING,
    RPROFREP_SECTION_LOCATION,
    RPROFREP_SECTION_GPU_SPEC,
    RPROFREP_SECTION_API_DATA,
    RPROFREP_SECTION_KERNEL,
    RPROFREP_SECTION_OFFSETS,
    RPROFREP_SECTION_EVENTS,
    RPROFREP_NB_SECTIONS,
    RPROFREP_NO_SECTION
} rprofrep_section_id_t;


typedef struct rprofrep_kernel_static_data_s {
    char* kernel_name;
    uint64_t kernel_strid;
    uint32_t private_segment_size;
    uint32_t group_segment_size;
    uint64_t kernel_object;
} rprofrep_kernel_static_data_t;


typedef struct __attribute__((packed)) rprofrep_header_entry_s {
    uint64_t offset;
    uint64_t size;
} rprofrep_header_entry_t;

typedef struct __attribute__((packed)) rprofrep_header_section_s {
    char             magic[RPROFREP_FILE_MAGIC_SIZE];
    uint8_t          report_version[3];
    rprofrep_header_entry_t sections[RPROFREP_NB_SECTIONS];
} rprofrep_header_section_t;


#endif // RPROFREP_DEFS_H