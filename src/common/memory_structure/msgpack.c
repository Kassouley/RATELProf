#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "msgpack.h"

static int msgpack_reserve(msgpack_buffer_t *buf, size_t additional_size) {
    size_t required_size = buf->size + additional_size;

    if (required_size <= buf->capacity) {
        return 0; // No need to grow or flush
    }

    if (buf->overflow_mode == MSGPACK_OVERFLOW_WRITE_TO_FILE
        || buf->overflow_mode == MSGPACK_OVERFLOW_APPEND_TO_FILE) {
        if (additional_size <= buf->capacity) {
            msgpack_write(buf);
            return 0;
        }
        // else: fall through to reallocation
    }

    // Either in REALLOC mode or WRITE_TO_FILE fallback for very large data
    size_t new_capacity = buf->capacity;
    while (required_size > new_capacity) {
        new_capacity *= 2;
    }

    uint8_t *new_data = (uint8_t *)realloc(buf->data, new_capacity);
    if (!new_data) {
        fprintf(stderr, "msgpack_reserve: memory allocation failed\n");
        return -1;
    }

    buf->data = new_data;
    buf->capacity = new_capacity;

    return 0;
}


int msgpack_write(msgpack_buffer_t *buf) {
    if (buf->file && buf->size > 0) {
        size_t written = fwrite(buf->data, 1, buf->size, buf->file);
        if (written != buf->size) {
            fprintf(stderr, "msgpack_write: failed to write full buffer to file\n");
            // handle error as needed
        }
        buf->size = 0;
    }
    return 0;
}

int msgpack_init(msgpack_buffer_t *buf, size_t capacity, msgpack_overflow_mode_t mode, const char* filename) {
    buf->overflow_mode = mode;
    buf->capacity = capacity;
    buf->size = 0;
    buf->data = (uint8_t *)malloc(capacity);

    if (!buf->data) {
        fprintf(stderr, "msgpack_init: memory allocation failed\n");
        return -1;
    }

    if (mode == MSGPACK_OVERFLOW_APPEND_TO_FILE || mode == MSGPACK_OVERFLOW_WRITE_TO_FILE) {
        if (!filename) {
            fprintf(stderr, "msgpack_init: filename required for WRITE_TO_FILE mode\n");
            free(buf->data);
            return -1;
        }

        const char *mode_str = (mode == MSGPACK_OVERFLOW_APPEND_TO_FILE) ? "ab" : "wb";
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
    if ((buf->overflow_mode == MSGPACK_OVERFLOW_WRITE_TO_FILE 
        || buf->overflow_mode == MSGPACK_OVERFLOW_APPEND_TO_FILE) && buf->file) {
        msgpack_write(buf);
        fclose(buf->file);
        buf->file = NULL;
    }

    free(buf->data);
    buf->data = NULL;
    buf->size = 0;
    buf->capacity = 0;
    return 0;
}

int msgpack_concat(msgpack_buffer_t *buf, msgpack_buffer_t *buf_src) {
    msgpack_reserve(buf, buf_src->size);
    memcpy(buf->data + buf->size, buf_src->data, buf_src->size);
    buf->size += buf_src->size;
    return 0;
}

int msgpack_encode_int(msgpack_buffer_t *buf, int64_t value) {
    msgpack_reserve(buf, 9);
    if (value >= 0) {
        msgpack_encode_uint(buf, (uint64_t)value);
    } else if (value >= -32) {
        buf->data[buf->size++] = (uint8_t)value;
    } else if (value >= INT8_MIN) {
        buf->data[buf->size++] = 0xd0;
        buf->data[buf->size++] = (uint8_t)value;
    } else if (value >= INT16_MIN) {
        buf->data[buf->size++] = 0xd1;
        buf->data[buf->size++] = (value >> 8) & 0xff;
        buf->data[buf->size++] = value & 0xff;
    } else if (value >= INT32_MIN) {
        buf->data[buf->size++] = 0xd2;
        for (int i = 3; i >= 0; --i)
            buf->data[buf->size++] = (value >> (i * 8)) & 0xff;
    } else {
        buf->data[buf->size++] = 0xd3;
        for (int i = 7; i >= 0; --i)
            buf->data[buf->size++] = (value >> (i * 8)) & 0xff;
    }
    return 0;
}

int msgpack_encode_uint(msgpack_buffer_t *buf, uint64_t value) {
    msgpack_reserve(buf, 9);
    if (value < 128) {
        buf->data[buf->size++] = (uint8_t)value;
    } else if (value <= UINT8_MAX) {
        buf->data[buf->size++] = 0xcc;
        buf->data[buf->size++] = (uint8_t)value;
    } else if (value <= UINT16_MAX) {
        buf->data[buf->size++] = 0xcd;
        buf->data[buf->size++] = (value >> 8) & 0xff;
        buf->data[buf->size++] = value & 0xff;
    } else if (value <= UINT32_MAX) {
        buf->data[buf->size++] = 0xce;
        for (int i = 3; i >= 0; --i)
            buf->data[buf->size++] = (value >> (i * 8)) & 0xff;
    } else {
        buf->data[buf->size++] = 0xcf;
        for (int i = 7; i >= 0; --i)
            buf->data[buf->size++] = (value >> (i * 8)) & 0xff;
    }
    return 0;
}

int msgpack_encode_float(msgpack_buffer_t *buf, float value) {
    msgpack_reserve(buf, 5);
    buf->data[buf->size++] = 0xca;
    uint32_t v;
    memcpy(&v, &value, sizeof(v));
    for (int i = 3; i >= 0; --i)
        buf->data[buf->size++] = (v >> (i * 8)) & 0xff;
    return 0;
}

int msgpack_encode_double(msgpack_buffer_t *buf, double value) {
    msgpack_reserve(buf, 9);
    buf->data[buf->size++] = 0xcb;
    uint64_t v;
    memcpy(&v, &value, sizeof(v));
    for (int i = 7; i >= 0; --i)
        buf->data[buf->size++] = (v >> (i * 8)) & 0xff;
    return 0;
}

int msgpack_encode_bool(msgpack_buffer_t *buf, bool value) {
    msgpack_reserve(buf, 1);
    buf->data[buf->size++] = value ? 0xc3 : 0xc2;
    return 0;
}

int msgpack_encode_nil(msgpack_buffer_t *buf) {
    msgpack_reserve(buf, 1);
    buf->data[buf->size++] = 0xc0;
    return 0;
}

int msgpack_encode_string(msgpack_buffer_t *buf, const char *str) {
    size_t len = strlen(str);
    msgpack_reserve(buf, len + 5);  // Max possible header size is 5

    if (len < 32) {
        buf->data[buf->size++] = 0xa0 | (uint8_t)len;  // fixstr
    } else if (len <= 0xff) {
        buf->data[buf->size++] = 0xd9;                 // str8
        buf->data[buf->size++] = (uint8_t)len;
    } else if (len <= 0xffff) {
        buf->data[buf->size++] = 0xda;                 // str16
        buf->data[buf->size++] = (len >> 8) & 0xff;
        buf->data[buf->size++] = len & 0xff;
    } else {
        buf->data[buf->size++] = 0xdb;                 // str32
        for (int i = 3; i >= 0; --i)
            buf->data[buf->size++] = (len >> (8 * i)) & 0xff;
    }

    memcpy(buf->data + buf->size, str, len);
    buf->size += len;
    return 0;
}


int msgpack_encode_array(msgpack_buffer_t *buf, size_t count) {
    msgpack_reserve(buf, 5);
    if (count < 16) {
        buf->data[buf->size++] = 0x90 | (uint8_t)count;
    } else if (count <= UINT16_MAX) {
        buf->data[buf->size++] = 0xdc;
        buf->data[buf->size++] = (count >> 8) & 0xff;
        buf->data[buf->size++] = count & 0xff;
    } else {
        buf->data[buf->size++] = 0xdd;
        for (int i = 3; i >= 0; --i)
            buf->data[buf->size++] = (count >> (i * 8)) & 0xff;
    }
    return 0;
}

int msgpack_encode_map(msgpack_buffer_t *buf, size_t count) {
    msgpack_reserve(buf, 5);
    if (count < 16) {
        buf->data[buf->size++] = 0x80 | (uint8_t)count;
    } else if (count <= UINT16_MAX) {
        buf->data[buf->size++] = 0xde;
        buf->data[buf->size++] = (count >> 8) & 0xff;
        buf->data[buf->size++] = count & 0xff;
    } else {
        buf->data[buf->size++] = 0xdf;
        for (int i = 3; i >= 0; --i)
            buf->data[buf->size++] = (count >> (i * 8)) & 0xff;
    }
    return 0;
}

int msgpack_encode_ext(msgpack_buffer_t *buf, int8_t type, const uint8_t *data, size_t len) {
    msgpack_reserve(buf, len + 6); // Max 6 bytes header + data

    if (len == 1) {
        buf->data[buf->size++] = 0xd4;
    } else if (len == 2) {
        buf->data[buf->size++] = 0xd5;
    } else if (len == 4) {
        buf->data[buf->size++] = 0xd6;
    } else if (len == 8) {
        buf->data[buf->size++] = 0xd7;
    } else if (len == 16) {
        buf->data[buf->size++] = 0xd8;
    } else if (len <= 0xFF) {
        buf->data[buf->size++] = 0xc7;
        buf->data[buf->size++] = (uint8_t)len;
    } else if (len <= 0xFFFF) {
        buf->data[buf->size++] = 0xc8;
        buf->data[buf->size++] = (len >> 8) & 0xff;
        buf->data[buf->size++] = len & 0xff;
    } else {
        buf->data[buf->size++] = 0xc9;
        for (int i = 3; i >= 0; --i)
            buf->data[buf->size++] = (len >> (8 * i)) & 0xff;
    }

    buf->data[buf->size++] = (uint8_t)type;
    if (data && len) {
        memcpy(buf->data + buf->size, data, len);
        buf->size += len;
    }
    return 0;
}
