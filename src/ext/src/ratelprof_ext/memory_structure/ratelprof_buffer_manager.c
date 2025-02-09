#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ratelprof.h>
#include "ratelprof_ext/memory_structure/ratelprof_buffer_manager.h"
#include "ratelprof_ext/ratelprof_ext_status.h"

// Initialize the buffer and open the file for writing
ratelprof_status_t ratelprof_init_buffer(ratelprof_buffer_t *manager, const char *filename, int buffer_size)
{
    manager->buffer = (char *)malloc(buffer_size);
    if (manager->buffer == NULL) {
        return RATELPROF_STATUS_MALLOC_FAILED;
    }

    manager->buffer_size = buffer_size;
    manager->buffer_offset = 0;

    manager->file = fopen(filename, "w");
    if (manager->file == NULL) {
        free(manager->buffer);  // Free the buffer if file opening fails
        return RATELPROF_STATUS_FAILED_OPEN_FILE;
    }
    return RATELPROF_STATUS_SUCCESS;
}

// Write the buffer's content to the file and reset the buffer
ratelprof_status_t ratelprof_flush_buffer(ratelprof_buffer_t *manager) 
{
    if (manager->buffer == NULL) {
        return RATELPROF_STATUS_BUFFER_IS_NULL;
    }
    if (manager->buffer_offset > 0) {
        fwrite(manager->buffer, 1, manager->buffer_offset, manager->file);
        manager->buffer_offset = 0;  // Reset buffer offset
    }
    return RATELPROF_STATUS_SUCCESS;
}

// Safely add formatted content to the buffer
ratelprof_status_t ratelprof_add_to_buffer(ratelprof_buffer_t *manager, const char *format, ...) 
{
    if (manager->buffer == NULL) {
        return RATELPROF_STATUS_BUFFER_IS_NULL;
    }
    ratelprof_status_t status = RATELPROF_STATUS_SUCCESS;
    va_list args;
    va_start(args, format);

    // Create a temporary buffer for formatted content
    char temp[manager->buffer_size];
    
    // Use snprintf to format the content into the temporary buffer
    int len = vsnprintf(temp, sizeof(temp), format, args);
    va_end(args);

    // Check if formatted content will fit in the main buffer
    if (len < 0 || len >= manager->buffer_size) {
        return RATELPROF_STATUS_INVALID_FORMAT_SIZE;
    }

    // If not enough space in the buffer, flush it first
    if (manager->buffer_offset + len >= manager->buffer_size) {
        status = ratelprof_flush_buffer(manager);
    }

    // Copy formatted content to the main buffer
    if (status == RATELPROF_STATUS_SUCCESS) {
        memcpy(manager->buffer + manager->buffer_offset, temp, len);
        manager->buffer_offset += len;
    }
    return status;
}

// Clean up resources and close the file
ratelprof_status_t ratelprof_close_buffer(ratelprof_buffer_t *manager) 
{
    ratelprof_flush_buffer(manager);  // Write any remaining content in the buffer
    fclose(manager->file);
    free(manager->buffer);
    return RATELPROF_STATUS_SUCCESS;
}
