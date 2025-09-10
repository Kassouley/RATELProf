#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "msgpack.h"

#define PP_NARG(...) PP_NARG_(__VA_ARGS__, 2, 1, 0)
#define PP_NARG_(A,B,C,N,...) N

#define __msgpack_put_bytes1(BUF, BYTES) (BUF)->data[(BUF)->size++] = (uint8_t)(BYTES)

#define __msgpack_put_bytes2(BUF, BYTES, LEN) \
    memcpy((BUF)->data + (BUF)->size, (BYTES), (LEN)); \
    (BUF)->size += (LEN)

#define __msgpack_put_bytes_GLUE(NAME, N) NAME##N
#define __msgpack_put_bytes_SELECT(NAME, N) __msgpack_put_bytes_GLUE(NAME, N)

#define __msgpack_put_bytes(...) __msgpack_put_bytes_SELECT(__msgpack_put_bytes, PP_NARG(__VA_ARGS__))(__VA_ARGS__)


#define __msgpack_write_to_file(data, size, err) { \
    size_t written = fwrite(data, 1, size, buf->file); \
    if (written != size) { \
        fprintf(stderr, err); \
    } \
}

static int __msgpack_reserve(msgpack_buffer_t *buf, size_t additional_size) {
    size_t required_size = buf->size + additional_size;

    if (required_size <= buf->capacity) {
        return 0; // No need to grow or flush
    }


    if (MSGPACK_IS_FILE_MODE(buf->overflow_mode)) {
        if (additional_size <= buf->capacity) {
            msgpack_write(buf);
            return 0;
        }
        // else: fall through to reallocation
    }

    // Either in REALLOC mode or WRITE/APPEND fallback for very large data
    size_t new_capacity = buf->capacity;
    while (required_size > new_capacity) {
        new_capacity *= 2;
    }

    uint8_t *new_data = (uint8_t *)realloc(buf->data, new_capacity);
    if (!new_data) {
        fprintf(stderr, "__msgpack_reserve: memory allocation failed\n");
        return -1;
    }

    buf->data = new_data;
    buf->capacity = new_capacity;

    return 0;
}

size_t msgpack_size(msgpack_buffer_t *buf) {
    return buf->flushed + buf->size;
} 

char* msgpack_to_b64(msgpack_buffer_t *buf, size_t* out_len) {
    return base64_encode(buf->data, buf->size, out_len);
}

int msgpack_init(msgpack_buffer_t *buf, size_t capacity, msgpack_overflow_mode_t mode, const char* filename) {
    buf->overflow_mode = mode;
    buf->capacity = capacity;
    buf->size = 0;
    buf->flushed = 0;
    buf->data = (uint8_t *)malloc(capacity);

    if (!buf->data) {
        fprintf(stderr, "msgpack_init: memory allocation failed\n");
        return -1;
    }

    if (MSGPACK_IS_FILE_MODE(mode)) {
        if (!filename) {
            fprintf(stderr, "msgpack_init: filename required for WRITE/APPEND mode\n");
            free(buf->data);
            return -1;
        }

        const char *mode_str;
        if (mode == MSGPACK_OVERFLOW_WRITE_TO_FILE) {
            mode_str = "wb";  // raw binary write
        } else if (mode == MSGPACK_OVERFLOW_APPEND_TO_FILE) {
            mode_str = "ab";  // raw binary append
        } else if (mode == MSGPACK_OVERFLOW_WRITE_B64_TO_FILE) {
            mode_str = "w";   // text (base64) write
        } else if (mode == MSGPACK_OVERFLOW_APPEND_B64_TO_FILE) {
            mode_str = "a";   // text (base64) append
        } else {
            fprintf(stderr, "msgpack_init: unexpected overflow mode %d, defaulting to write binary\n", mode);
            mode_str = "wb"; // fallback to safe default
        }

        buf->file = fopen(filename, mode_str);
        if (!buf->file) {
            fprintf(stderr, "msgpack_init: failed to open file '%s'\n", filename);
            free(buf->data);
            return -1;
        }
    } else {
        buf->file = NULL;
    }
    return 0;
}

int msgpack_free(msgpack_buffer_t *buf) {
    if (MSGPACK_IS_FILE_MODE(buf->overflow_mode) && buf->file) {
        if (buf->size > 0) {
            if (buf->overflow_mode == MSGPACK_OVERFLOW_WRITE_B64_TO_FILE ||
                buf->overflow_mode == MSGPACK_OVERFLOW_APPEND_B64_TO_FILE) {
                // Flush any remaining bytes (less than 3)
                size_t out_len;
                char *b64 = base64_encode(buf->data, buf->size, &out_len);
                if (!b64) {
                    fprintf(stderr, "msgpack_free: base64 encoding failed\n");
                    return -1;
                }
                __msgpack_write_to_file(b64, out_len, "msgpack_free: failed to write base64 buffer to file\n");
                free(b64);
            } else {
                msgpack_write(buf);
            }
        }

        fclose(buf->file);
        buf->file = NULL;
    }

    free(buf->data);
    buf->data = NULL;
    buf->size = 0;
    buf->flushed = 0;
    buf->capacity = 0;
    return 0;
}


int msgpack_write(msgpack_buffer_t *buf) {
    if (!buf->file || buf->size == 0) return 0;

    if (buf->overflow_mode == MSGPACK_OVERFLOW_WRITE_B64_TO_FILE ||
        buf->overflow_mode == MSGPACK_OVERFLOW_APPEND_B64_TO_FILE) {
        
        size_t bytes_to_encode = buf->size - (buf->size % 3); // encode only multiples of 3
        size_t leftover_bytes  = buf->size % 3;               // keep remainder for next flush

        if (bytes_to_encode > 0) {
            size_t out_len;
            char *b64 = base64_encode(buf->data, bytes_to_encode, &out_len);
            if (!b64) {
                fprintf(stderr, "msgpack_write: base64 encoding failed\n");
                return -1;
            }
            __msgpack_write_to_file(b64, out_len, "msgpack_write: failed to write base64 buffer to file\n");
            free(b64);
            buf->flushed += bytes_to_encode;
        }

        // Move leftover bytes to start of buffer
        if (leftover_bytes > 0) {
            memmove(buf->data, buf->data + bytes_to_encode, leftover_bytes);
        }
        buf->size = leftover_bytes;

    } else {
        // Binary write
        __msgpack_write_to_file(buf->data, buf->size, "msgpack_write: failed to write full buffer to file\n");
        buf->flushed += buf->size;
        buf->size = 0;
    }

    return 0;
}

int msgpack_concat(msgpack_buffer_t *buf, msgpack_buffer_t *buf_src) {
    __msgpack_reserve(buf, buf_src->size);
    __msgpack_put_bytes(buf, buf_src->data, buf_src->size);
    return 0;
}

int msgpack_encode_int(msgpack_buffer_t *buf, int64_t value) {
    __msgpack_reserve(buf, 9);
    if (value >= 0) {
        msgpack_encode_uint(buf, (uint64_t)value);
    } else if (value >= -32) {
        __msgpack_put_bytes(buf, value);
    } else if (value >= INT8_MIN) {
        __msgpack_put_bytes(buf, 0xd0);
        __msgpack_put_bytes(buf, value);
    } else if (value >= INT16_MIN) {
        __msgpack_put_bytes(buf, 0xd1);
        __msgpack_put_bytes(buf, (value >> 8) & 0xff);
        __msgpack_put_bytes(buf, value & 0xff);
    } else if (value >= INT32_MIN) {
        __msgpack_put_bytes(buf, 0xd2);
        for (int i = 3; i >= 0; --i)
            __msgpack_put_bytes(buf, (value >> (i * 8)) & 0xff);
    } else {
        __msgpack_put_bytes(buf, 0xd3);
        for (int i = 7; i >= 0; --i)
            __msgpack_put_bytes(buf, (value >> (i * 8)) & 0xff);
    }
    return 0;
}

int msgpack_encode_uint(msgpack_buffer_t *buf, uint64_t value) {
    __msgpack_reserve(buf, 9);
    if (value < 128) {
        __msgpack_put_bytes(buf, value);
    } else if (value <= UINT8_MAX) {
        __msgpack_put_bytes(buf, 0xcc);
        __msgpack_put_bytes(buf, value);
    } else if (value <= UINT16_MAX) {
        __msgpack_put_bytes(buf, 0xcd);
        __msgpack_put_bytes(buf, (value >> 8) & 0xff);
        __msgpack_put_bytes(buf, value & 0xff);
    } else if (value <= UINT32_MAX) {
        __msgpack_put_bytes(buf, 0xce);
        for (int i = 3; i >= 0; --i)
            __msgpack_put_bytes(buf, (value >> (i * 8)) & 0xff);
    } else {
        __msgpack_put_bytes(buf, 0xcf);
        for (int i = 7; i >= 0; --i)
            __msgpack_put_bytes(buf, (value >> (i * 8)) & 0xff);
    }
    return 0;
}

int msgpack_encode_float(msgpack_buffer_t *buf, float value) {
    __msgpack_reserve(buf, 5);
    __msgpack_put_bytes(buf, 0xca);
    uint32_t v;
    memcpy(&v, &value, sizeof(v));
    for (int i = 3; i >= 0; --i)
        __msgpack_put_bytes(buf, (v >> (i * 8)) & 0xff);
    return 0;
}

int msgpack_encode_double(msgpack_buffer_t *buf, double value) {
    __msgpack_reserve(buf, 9);
    __msgpack_put_bytes(buf, 0xcb);
    uint64_t v;
    memcpy(&v, &value, sizeof(v));
    for (int i = 7; i >= 0; --i)
        __msgpack_put_bytes(buf, (v >> (i * 8)) & 0xff);
    return 0;
}

int msgpack_encode_bool(msgpack_buffer_t *buf, bool value) {
    __msgpack_reserve(buf, 1);
    __msgpack_put_bytes(buf, value ? 0xc3 : 0xc2);
    return 0;
}

int msgpack_encode_nil(msgpack_buffer_t *buf) {
    __msgpack_reserve(buf, 1);
    __msgpack_put_bytes(buf, 0xc0);
    return 0;
}

int msgpack_encode_string(msgpack_buffer_t *buf, const char *str) {
    size_t len = strlen(str);
    __msgpack_reserve(buf, len + 5);

    if (len < 32) {
        __msgpack_put_bytes(buf, 0xa0 | (uint8_t)len);  // fixstr
    } else if (len <= 0xff) {
        __msgpack_put_bytes(buf, 0xd9);                 // str8
        __msgpack_put_bytes(buf, len);
    } else if (len <= 0xffff) {
        __msgpack_put_bytes(buf, 0xda);                 // str16
        __msgpack_put_bytes(buf, (len >> 8) & 0xff);
        __msgpack_put_bytes(buf, len & 0xff);
    } else {
        __msgpack_put_bytes(buf, 0xdb);                 // str32
        for (int i = 3; i >= 0; --i)
            __msgpack_put_bytes(buf, (len >> (8 * i)) & 0xff);
    }
    __msgpack_put_bytes(buf, str, len);
    return 0;
}


int msgpack_encode_array(msgpack_buffer_t *buf, size_t count) {
    __msgpack_reserve(buf, 5);
    if (count < 16) {
        __msgpack_put_bytes(buf, 0x90 | (uint8_t)count);
    } else if (count <= UINT16_MAX) {
        __msgpack_put_bytes(buf, 0xdc);
        __msgpack_put_bytes(buf, (count >> 8) & 0xff);
        __msgpack_put_bytes(buf, count & 0xff);
    } else {
        __msgpack_put_bytes(buf, 0xdd);
        for (int i = 3; i >= 0; --i)
            __msgpack_put_bytes(buf, (count >> (i * 8)) & 0xff);
    }
    return 0;
}

int msgpack_encode_map(msgpack_buffer_t *buf, size_t count) {
    __msgpack_reserve(buf, 5);
    if (count < 16) {
        __msgpack_put_bytes(buf, 0x80 | (uint8_t)count);
    } else if (count <= UINT16_MAX) {
        __msgpack_put_bytes(buf, 0xde);
        __msgpack_put_bytes(buf, (count >> 8) & 0xff);
        __msgpack_put_bytes(buf, count & 0xff);
    } else {
        __msgpack_put_bytes(buf, 0xdf);
        for (int i = 3; i >= 0; --i)
            __msgpack_put_bytes(buf, (count >> (i * 8)) & 0xff);
    }
    return 0;
}

int msgpack_encode_ext(msgpack_buffer_t *buf, int8_t type, const uint8_t *data, size_t len) {
    __msgpack_reserve(buf, len + 6);

    if (len == 1) {
        __msgpack_put_bytes(buf, 0xd4);
    } else if (len == 2) {
        __msgpack_put_bytes(buf, 0xd5);
    } else if (len == 4) {
        __msgpack_put_bytes(buf, 0xd6);
    } else if (len == 8) {
        __msgpack_put_bytes(buf, 0xd7);
    } else if (len == 16) {
        __msgpack_put_bytes(buf, 0xd8);
    } else if (len <= 0xFF) {
        __msgpack_put_bytes(buf, 0xc7);
        __msgpack_put_bytes(buf, len);
    } else if (len <= 0xFFFF) {
        __msgpack_put_bytes(buf, 0xc8);
        __msgpack_put_bytes(buf, (len >> 8) & 0xff);
        __msgpack_put_bytes(buf, len & 0xff);
    } else {
        __msgpack_put_bytes(buf, 0xc9);
        for (int i = 3; i >= 0; --i)
            __msgpack_put_bytes(buf, (len >> (8 * i)) & 0xff);
    }

    __msgpack_put_bytes(buf, type);
    if (data && len) {
        __msgpack_put_bytes(buf, data, len);
    }
    return 0;
}