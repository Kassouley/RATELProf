#ifndef RPROFREP_READ_UTILS_H
#define RPROFREP_READ_UTILS_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "rprofrep_msgpack_defs.h"

#define __read_field(var, buffer, offset) \
    memcpy(&var, buffer + offset, sizeof(var)); \
    offset += sizeof(var);


#define __read_bytes(v, buf, off) do { \
    size_t n = sizeof(v); \
    memcpy(&v, buf + *(off), n); \
    *(off) += n; \
} while(0)


// Read byte from buffer
static inline uint8_t __read_byte(const uint8_t* buf, size_t* off) {
    return (uint8_t) buf[(*off)++];
}

// Read uint from buffer
static inline uint8_t __read_uint8(const uint8_t* buf, size_t* off) {
    return __read_byte(buf, off);
}

static inline uint16_t __read_uint16(const uint8_t* buf, size_t* off) {
    uint16_t v;
    __read_bytes(v, buf, off);
    return v;
}

static inline uint32_t __read_uint32(const uint8_t* buf, size_t* off) {
    uint32_t v;
    __read_bytes(v, buf, off);
    return v;
}

static inline uint64_t __read_uint64(const uint8_t* buf, size_t* off) {
    uint64_t v;
    __read_bytes(v, buf, off);
    return v;
}


// Read int from buffer
static inline int8_t  __read_int8 (const uint8_t* buf, size_t* off) { return (int8_t)  __read_byte(buf, off);   }
static inline int16_t __read_int16(const uint8_t* buf, size_t* off) { return (int16_t) __read_uint16(buf, off); }
static inline int32_t __read_int32(const uint8_t* buf, size_t* off) { return (int32_t) __read_uint32(buf, off); }
static inline int64_t __read_int64(const uint8_t* buf, size_t* off) { return (int64_t) __read_uint64(buf, off); }


static inline uint64_t __read_mp_uint(const uint8_t* buf, size_t* off) {
    uint64_t val = 0;
    uint8_t b = __read_byte(buf, off);

    if (b <= 0x7f) {
        val = (uint64_t) b;    // positive fixint
    } else {
        switch (b) {
            case 0xcc: val = (uint64_t) __read_uint8(buf, off);      break;
            case 0xcd: val = (uint64_t) __read_uint16(buf, off);     break;
            case 0xce: val = (uint64_t) __read_uint32(buf, off);     break;
            case 0xcf: val = (uint64_t) __read_uint64(buf, off);     break;
            default: fprintf(stderr, "Unsupported uint type: 0x%02x\n", b);  break;
        }
    }

    return val;
}

static inline int64_t __read_mp_int(const uint8_t* buf, size_t* off) {
    int64_t val = 0;
    uint8_t b = __read_byte(buf, off);

    if (b <= 0x7f) {
        val = (int8_t) b;    // positive fixint
    } else if (b >= 0xe0) {
        val = (int8_t) b;     // negative fixint
    } else {
        switch (b) {
            case 0xd0: val = (int8_t)  __read_int8(buf, off);      break;
            case 0xd1: val = (int16_t) __read_int16(buf, off);     break;
            case 0xd2: val = (int32_t) __read_int32(buf, off);     break;
            case 0xd3: val = (int64_t) __read_int64(buf, off);     break;
            case 0xcc: val = (int64_t) __read_uint8(buf, off);     break;
            case 0xcd: val = (int64_t) __read_uint16(buf, off);    break;
            case 0xce: val = (int64_t) __read_uint32(buf, off);    break;
            case 0xcf: val = (int64_t) __read_uint64(buf, off);    break;
            default: fprintf(stderr, "Unsupported int type: 0x%02x\n", b);  break;
        }
    }

    return val;
}


// Read float from buffer
static inline float __read_float32(const uint8_t* buf, size_t* off) {
    union { uint32_t i; float f; } u;
    u.i = __read_uint32(buf, off);
    return u.f;
}

// Read double from buffer
static inline double __read_float64(const uint8_t* buf, size_t* off) {
    union { uint64_t i; double d; } u;
    u.i = __read_uint64(buf, off);
    return u.d;
}

// Read string from buffer
static inline char* __read_string(const uint8_t* buf, size_t* off, size_t len) {
    char *str = (char *) malloc(len + 1);
    if (!buf) {
        return NULL;
    }

    memcpy(str, buf + *off, len);
    str[len] = '\0';
    *off += len;

    return str;
}

// Read string from buffer until null terminator
static inline char* __read_string_until_null(const uint8_t* buf, size_t* off) {
    size_t len = 0;

    // Find the length of the string
    while (buf[*off + len] != '\0') {
        len++;
    }

    char *str = __read_string(buf, off, len);
    if (!str) return NULL;

    (*off)++; // skip the null terminator
    return str;
}


static inline char* __read_mp_string(const uint8_t* buf, size_t* off) {
    char* str = NULL;
    uint8_t b = __read_byte(buf, off);

    if ((b & 0xe0) == 0xa0) {
        str = __read_string(buf, off, b & 0x1f);   // fixstr
    } else {
        switch (b) {
            case 0xd9: str = __read_string(buf, off, __read_uint8(buf, off));   break;     // str8
            case 0xda: str = __read_string(buf, off, __read_uint16(buf, off));  break;     // str16
            case 0xdb: str = __read_string(buf, off, __read_uint32(buf, off));  break;     // str32
            default: fprintf(stderr, "Unsupported string type: 0x%02x\n", b);   break;
        }
    }

    return str;
}


static inline uint64_t __read_mp_cid(const uint8_t* buf, size_t* off) {
    uint64_t cid = 0;
    uint8_t b    = __read_byte(buf, off);
    uint64_t len  = 0;
    switch (b) {
        case 0xd4: len = 1;  break; // fixext 1
        case 0xd5: len = 2;  break; // fixext 2
        case 0xd6: len = 4;  break; // fixext 4
        case 0xd7: len = 8;  break; // fixext 8
        default:
            (*off)--;
            return cid;
    }

    uint8_t type = __read_int8(buf, off);

    if (type != MSGPACK_EXT_CID) {
        (*off) -= 2;
        return cid;
    }

    memcpy(&cid, buf + *off, len);
    (*off) += len;

    return cid;
}

static inline uint8_t bread8(uint8_t **buf)
{
    return *(*buf)--;
}

static inline uint16_t bread16(uint8_t **buf)
{
    return (uint16_t)bread8(buf)
         | ((uint16_t)bread8(buf) << 8);
}

static inline uint32_t bread32(uint8_t **buf)
{
    return (uint32_t)bread16(buf)
         | ((uint32_t)bread8(buf) << 16)
         | ((uint32_t)bread8(buf) << 24);
}

static inline uint64_t bread64(uint8_t **buf)
{
    return (uint64_t)bread32(buf)
         | ((uint64_t)bread32(buf) << 32);
}



#endif // RPROFREP_READ_UTILS_H