#ifndef MSGPACK_H
#define MSGPACK_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* Buffer overflow handling modes */
typedef enum {
    MSGPACK_OVERFLOW_REALLOC,
    MSGPACK_OVERFLOW_WRITE_TO_FILE
} msgpack_overflow_mode_t;

/* MessagePack buffer structure */
typedef struct {
    uint8_t *data;
    size_t size;
    size_t capacity;
    FILE* file;
    msgpack_overflow_mode_t overflow_mode;
} msgpack_buffer_t;

int msgpack_concat(msgpack_buffer_t *buf, msgpack_buffer_t *buf_src);
int msgpack_write(msgpack_buffer_t *buf);
int msgpack_init(msgpack_buffer_t *buf, size_t capacity, msgpack_overflow_mode_t mode, const char* filename);
int msgpack_free(msgpack_buffer_t *buf);
int msgpack_encode_int(msgpack_buffer_t *buf, int64_t value);
int msgpack_encode_uint(msgpack_buffer_t *buf, uint64_t value);
int msgpack_encode_float(msgpack_buffer_t *buf, float value);
int msgpack_encode_double(msgpack_buffer_t *buf, double value);
int msgpack_encode_bool(msgpack_buffer_t *buf, bool value);
int msgpack_encode_nil(msgpack_buffer_t *buf);
int msgpack_encode_string(msgpack_buffer_t *buf, const char *str);
int msgpack_encode_bin(msgpack_buffer_t *buf, const int *data, size_t size);
int msgpack_encode_array(msgpack_buffer_t *buf, size_t count);
int msgpack_encode_map(msgpack_buffer_t *buf, size_t count);
int msgpack_encode_ext(msgpack_buffer_t *buf, int8_t type, const uint8_t *data, size_t len);

#endif // MSGPACK_H