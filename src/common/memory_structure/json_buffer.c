#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "json_buffer.h"

// Initialize the buffer and open the file for writing
int init_json_buffer(json_buffer_t *manager, const char *filename, int buffer_size)
{
    manager->buffer = (char *)malloc(buffer_size);
    if (manager->buffer == NULL) {
        return -1;
    }

    manager->buffer_size = buffer_size;
    manager->buffer_offset = 0;

    manager->file = fopen(filename, "w");
    if (manager->file == NULL) {
        free(manager->buffer);  // Free the buffer if file opening fails
        manager->buffer = NULL;
        return -1;
    }
    return 0;
}

// Write the buffer's content to the file and reset the buffer
int flush_json_buffer(json_buffer_t *manager)
{
    if (manager->buffer == NULL && manager->file == NULL) {
        return -1;
    }
    if (manager->buffer_offset > 0) {
        size_t written = fwrite(manager->buffer, sizeof(char), manager->buffer_offset, manager->file);
        if (written < manager->buffer_offset) {
            return -1;
        }
        manager->buffer_offset = 0;  // Reset buffer offset
    }
    return 0;
}

// Safely add formatted content to the buffer
int add_to_json_buffer(json_buffer_t *manager, const char *format, ...)
{
    if (manager->buffer == NULL) {
        return -1;
    }
    int status = 0;
    va_list args;
    va_start(args, format);

    // Create a temporary buffer for formatted content
    char temp[manager->buffer_size];
    
    // Use snprintf to format the content into the temporary buffer
    int len = vsnprintf(temp, sizeof(temp), format, args);
    va_end(args);

    // Check if formatted content will fit in the main buffer
    if (len <= 0 || len >= manager->buffer_size) {
        return -1;
    }

    // If not enough space in the buffer, flush it first
    if (manager->buffer_offset + len >= manager->buffer_size) {
        int status = flush_json_buffer(manager);
        if (status != 0) return status;
    }

    // Copy formatted content to the main buffer
    if (manager->buffer_offset + len < manager->buffer_size) { // Ensure no overflow
        memcpy(manager->buffer + manager->buffer_offset, temp, len);
        manager->buffer_offset += len;
    } else {
        return -1;
    }

    return status;
}

// Clean up resources and close the file
int close_json_buffer(json_buffer_t *manager)
{
    int status = flush_json_buffer(manager);
    if (status != 0) return status;
    fclose(manager->file);
    free(manager->buffer);
    return 0;
}
