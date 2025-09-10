#ifndef MSGPACK_H
#define MSGPACK_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* Buffer overflow handling modes */
typedef enum {
    MSGPACK_OVERFLOW_REALLOC,
    MSGPACK_OVERFLOW_WRITE_TO_FILE,
    MSGPACK_OVERFLOW_APPEND_TO_FILE,
    MSGPACK_OVERFLOW_WRITE_B64_TO_FILE,
    MSGPACK_OVERFLOW_APPEND_B64_TO_FILE
} msgpack_overflow_mode_t;

/* MessagePack buffer structure */
typedef struct {
    uint8_t *data;
    size_t size;
    size_t flushed; 
    size_t capacity;
    FILE* file;
    msgpack_overflow_mode_t overflow_mode;
} msgpack_buffer_t;


#define MSGPACK_IS_FILE_MODE(mode) \
    ((mode) == MSGPACK_OVERFLOW_APPEND_TO_FILE || \
     (mode) == MSGPACK_OVERFLOW_WRITE_TO_FILE  || \
     (mode) == MSGPACK_OVERFLOW_APPEND_B64_TO_FILE || \
     (mode) == MSGPACK_OVERFLOW_WRITE_B64_TO_FILE)


static inline char *base64_encode(const uint8_t *data, size_t input_length, size_t *output_length) {
    static const char encoding_table[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    char *encoded_data;
    size_t output_len = 4 * ((input_length + 2) / 3);
    encoded_data = (char *)malloc(output_len + 1);
    if (encoded_data == NULL) return NULL;

    for (size_t i = 0, j = 0; i < input_length;) {
        uint32_t octet_a = i < input_length ? data[i++] : 0;
        uint32_t octet_b = i < input_length ? data[i++] : 0;
        uint32_t octet_c = i < input_length ? data[i++] : 0;

        uint32_t triple = (octet_a << 16) | (octet_b << 8) | octet_c;

        encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
        encoded_data[j++] = encoding_table[triple & 0x3F];
    }

    for (size_t i = 0; i < (3 - input_length % 3) % 3; i++)
        encoded_data[output_len - 1 - i] = '=';

    encoded_data[output_len] = '\0';
    if (output_length) *output_length = output_len;
    return encoded_data;
}


size_t msgpack_size(msgpack_buffer_t *buf);
char* msgpack_to_b64(msgpack_buffer_t *buf, size_t* out_len);
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

#include "msgpack_ext.h"

#endif // MSGPACK_H