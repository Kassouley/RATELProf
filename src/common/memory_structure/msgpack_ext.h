#ifndef MSGPACK_EXT_H
#define MSGPACK_EXT_H

#define INITIAL_CAPACITY 1000

#include "msgpack.h"

enum {
    MSGPACK_EXT_RATELPROF,
    MSGPACK_EXT_STRING,
    MSGPACK_EXT_STRING_ARRAY,
};

typedef struct {
    char **strings;         // Array of string pointers
    size_t count;           // Number of stored strings
    size_t capacity;        // Allocated slots in strings array
} string_table_t;

// Initialize the string table
void msgpack_ext_string_init();

// Realloc if array is full
void msgpack_ext_string_if_full();

// Get or assign an ID for a string
size_t msgpack_ext_get_string_id(const char *str);


// Free memory used by the table
void msgpack_ext_string_free();

int msgpack_encode_string_ext(msgpack_buffer_t *buf, const char *str);

int msgpack_encode_string_table_ext(msgpack_buffer_t *buf);

#endif
