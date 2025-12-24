#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "rprofrep_status.h"

#include "utils/rprofrep_decode_type.h"

#include "sections/rprofrep_section_events.h"


// Fill the context with the map and event section data
rprofrep_status_t rprofrep_decode_events_section(rprofrep_decode_context_t* ctx, rprofrep_events_section_t* out)
{
    RPROFREP_CHECK_VALID_PTR(ctx, ctx->handle);

    int fd = fileno(ctx->handle);
    if (fd < 0) return RPROFREP_STATUS_FILE_ERROR("Cannot get fd for handle %x", ctx->handle);

    size_t events_offset = ctx->header.sections[RPROFREP_SECTION_EVENTS].offset;
    size_t events_size   = ctx->header.sections[RPROFREP_SECTION_EVENTS].size;

    size_t page_size = sysconf(_SC_PAGESIZE);
    off_t aligned_offset = events_offset & ~(page_size - 1);
    size_t offset_diff = events_offset - aligned_offset;

    void* mapped = mmap(NULL, events_size + offset_diff, PROT_READ, MAP_PRIVATE, fd, aligned_offset);
    if (mapped == MAP_FAILED) return RPROFREP_STATUS_MMAP_FAILED();

    out->base_address = mapped;
    out->buffer       = (uint8_t*)mapped + offset_diff;
    out->mapped_size  = events_size + offset_diff;
    out->size         = events_size;

    return RPROFREP_STATUS_SUCCESS;
}


// Free the event section
rprofrep_status_t rprofrep_free_events_section(rprofrep_events_section_t* section)
{
    RPROFREP_CHECK_VALID_PTR(section, section->base_address);

    munmap(section->base_address, section->mapped_size);
    section->base_address = NULL;
    section->buffer       = NULL;
    section->size         = 0;
    section->mapped_size  = 0;

    return RPROFREP_STATUS_SUCCESS;
}