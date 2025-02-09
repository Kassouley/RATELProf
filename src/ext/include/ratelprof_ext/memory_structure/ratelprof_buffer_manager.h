#ifndef RATELPROF_BUFFER_MANAGER_H
#define RATELPROF_BUFFER_MANAGER_H

#include <stdio.h>
#include <ratelprof.h>

// Structure to manage the buffer and file operations
typedef struct ratelprof_buffer_s {
    char *buffer;         // Pointer to dynamically allocated buffer
    int buffer_offset;    // Current offset in the buffer
    int buffer_size;      // Size of the buffer
    FILE *file;           // File pointer for output
} ratelprof_buffer_t;

// Function to initialize the buffer and open the file for writing
ratelprof_status_t ratelprof_init_buffer(ratelprof_buffer_t *manager, const char *filename, int buffer_size);

// Function to write the buffer's content to the file and reset the buffer
ratelprof_status_t ratelprof_flush_buffer(ratelprof_buffer_t *manager);

// Function to safely add formatted content to the buffer
ratelprof_status_t ratelprof_add_to_buffer(ratelprof_buffer_t *manager, const char *format, ...);

// Function to clean up resources and close the file
ratelprof_status_t ratelprof_close_buffer(ratelprof_buffer_t *manager);

#endif // RATELPROF_BUFFER_MANAGER_H
