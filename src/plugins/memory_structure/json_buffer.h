#ifndef JSON_BUFFER_H
#define JSON_BUFFER_H

#include <stdio.h>

// Structure to manage the buffer and file operations
typedef struct {
    char *buffer;         // Pointer to dynamically allocated buffer
    int buffer_offset;    // Current offset in the buffer
    int buffer_size;      // Size of the buffer
    FILE *file;           // File pointer for output
} json_buffer_t;

// Function to initialize the buffer and open the file for writing
int init_json_buffer(json_buffer_t *manager, const char *filename, int buffer_size);

// Function to write the buffer's content to the file and reset the buffer
int flush_json_buffer(json_buffer_t *manager);

// Function to safely add formatted content to the buffer
int add_to_json_buffer(json_buffer_t *manager, const char *format, ...);

// Function to clean up resources and close the file
int close_json_buffer(json_buffer_t *manager);

#endif // JSON_BUFFER_H
