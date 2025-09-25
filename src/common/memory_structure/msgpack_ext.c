#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "msgpack.h"
#include "msgpack_ext.h"

static string_table_t table;

// Initialize the string table
void msgpack_ext_string_init() {
    table.capacity = INITIAL_CAPACITY;
    table.strings = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
    table.count = 0;
}

// Realloc if array is full
void msgpack_ext_string_if_full() {
    if (table.count >= table.capacity) {
        table.capacity *= 2;
        table.strings = (char **)realloc(table.strings, table.capacity * sizeof(char *));
        if (!table.strings) {
            fprintf(stderr, "Memory allocation failed during resize.\n");
            exit(EXIT_FAILURE);
        }
    }
}

// Get or assign an ID for a string
size_t msgpack_ext_get_string_id(const char *str) {
    // If string already in table, just return ID
    for (size_t i = 0; i < table.count; ++i) {
        if (strcmp(table.strings[i], str) == 0) {
            return i; 
        }
    }

    msgpack_ext_string_if_full();  // Grow table if needed

    // Copy and store new string
    table.strings[table.count] = strdup(str); 

    if (!table.strings[table.count]) {
        fprintf(stderr, "Failed to allocate memory for string.\n");
        exit(EXIT_FAILURE);
    }
    
    return table.count++;
}


// Free memory used by the table
void msgpack_ext_string_free() {
    for (int i = 0; i < table.count; ++i) {
        free(table.strings[i]);
    }
    free(table.strings);
}

int msgpack_encode_string_ext(msgpack_buffer_t *buf, const char *str) {
    size_t id = msgpack_ext_get_string_id(str);

    uint8_t data[4];
    size_t len = 0;

    if (id < 0x100) {          // 1 byte needed
        data[0] = id & 0xFF;
        len = 1;
    } else if (id < 0x10000) {        // 2 bytes needed
        data[0] = (id >> 8) & 0xFF;
        data[1] = id & 0xFF;
        len = 2;
    } else if (id < 0x1000000) {      // 3 bytes needed
        data[0] = (id >> 16) & 0xFF;
        data[1] = (id >> 8) & 0xFF;
        data[2] = id & 0xFF;
        len = 3;
    } else {                         // 4 bytes needed
        data[0] = (id >> 24) & 0xFF;
        data[1] = (id >> 16) & 0xFF;
        data[2] = (id >> 8) & 0xFF;
        data[3] = id & 0xFF;
        len = 4;
    }

    return msgpack_encode_ext(buf, MSGPACK_EXT_STRING, data, len);

    return 0;
}

int msgpack_encode_string_table_ext(msgpack_buffer_t *buf) {
    msgpack_encode_ext(buf, MSGPACK_EXT_STRING_ARRAY, NULL, table.count);
    for (size_t i = 0; i < table.count; i++)
    {
        msgpack_encode_string(buf, table.strings[i]);
    }
    
    return 0;
}
