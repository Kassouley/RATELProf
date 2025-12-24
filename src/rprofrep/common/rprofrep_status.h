#ifndef RPROFREP_STATUS_H
#define RPROFREP_STATUS_H

#include <stdio.h>
#include <stdarg.h>


// Internal helper
#define _RPROFREP_EXPAND(x) x
#define _RPROFREP_FOREACH_1(fn, x1) fn(x1)
#define _RPROFREP_FOREACH_2(fn, x1, x2) fn(x1); _RPROFREP_FOREACH_1(fn, x2)
#define _RPROFREP_FOREACH_3(fn, x1, x2, x3) fn(x1); _RPROFREP_FOREACH_2(fn, x2, x3)
#define _RPROFREP_FOREACH_4(fn, x1, x2, x3, x4) fn(x1); _RPROFREP_FOREACH_3(fn, x2, x3, x4)
#define _RPROFREP_FOREACH_5(fn, x1, x2, x3, x4, x5) fn(x1); _RPROFREP_FOREACH_4(fn, x2, x3, x4, x5)

#define _RPROFREP_GET_MACRO9(_1, _2, _3, _4, _5, _6, _7, _8, _9, NAME, ...) NAME
#define _RPROFREP_GET_MACRO8(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME
#define _RPROFREP_GET_MACRO7(_1, _2, _3, _4, _5, _6, _7, NAME, ...) NAME
#define _RPROFREP_GET_MACRO6(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define _RPROFREP_GET_MACRO5(_1, _2, _3, _4, _5, NAME, ...) NAME
#define _RPROFREP_GET_MACRO4(_1, _2, _3, _4, NAME, ...) NAME
#define _RPROFREP_GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define _RPROFREP_GET_MACRO2(_1, _2, NAME, ...) NAME



typedef enum {
    RPROFREP_STATUS_CODE_SUCCESS = 0,
    RPROFREP_STATUS_CODE_ERROR,
    RPROFREP_STATUS_CODE_INVALID_PTR,
    RPROFREP_STATUS_CODE_INVALID_ARG,
    RPROFREP_STATUS_CODE_INVALID_REPORT,
    RPROFREP_STATUS_CODE_INVALID_EVENT,
    RPROFREP_STATUS_CODE_ALLOC_FAILED,
    RPROFREP_STATUS_CODE_MMAP_FAILED,
    RPROFREP_STATUS_CODE_FILE_ERROR,
    RPROFREP_STATUS_CODE_NOT_FOUND,
    RPROFREP_STATUS_CODE_NOT_INIT,
    RPROFREP_STATUS_CODE_AMD_ERROR,
    RPROFREP_NB_STATUS
} rprofrep_status_code_t;

typedef struct {
    rprofrep_status_code_t code;    // numeric status
    const char* msg;                // generic error message
    char user_msg[256];             // user defined error message
    const char* file;               // file where error originated
    const char* func;               // function where error originated
    int line;                       // line where error originated
} rprofrep_status_t;

static inline rprofrep_status_t __rprofrep_wrap_status_fmt(
    rprofrep_status_code_t code, const char* msg, 
    const char* file, const char* func, int line, const char* fmt, ...
) {
    rprofrep_status_t s = {
        .code = code, .msg = msg, .file = file, .func = func, .line = line
    };

    if (fmt) {
        va_list args;
        va_start(args, fmt);
        vsnprintf(s.user_msg, sizeof(s.user_msg), fmt, args);
        va_end(args);
    } else {
        s.user_msg[0] = '\0';
    }

    return s;
}

#define _RSTATUS_NOFMT(code, msg)           __rprofrep_wrap_status_fmt((code), (msg), __FILE__, __func__, __LINE__, NULL)
#define _RSTATUS_FMT(code, msg, fmt, ...)   __rprofrep_wrap_status_fmt((code), (msg), __FILE__, __func__, __LINE__, (fmt), ##__VA_ARGS__)

#define __RPROFREP_WRAP_STATUS(...) \
    _RPROFREP_GET_MACRO9(__VA_ARGS__, \
        _RSTATUS_FMT,  /* 9 args: code,msg,fmt,... */ \
        _RSTATUS_FMT,  /* 8 args: code,msg,fmt,... */ \
        _RSTATUS_FMT,  /* 7 args: code,msg,fmt,... */ \
        _RSTATUS_FMT,  /* 6 args: code,msg,fmt,... */ \
        _RSTATUS_FMT,  /* 5 args: code,msg,fmt,... */ \
        _RSTATUS_FMT,  /* 4 args: code,msg,fmt,... */ \
        _RSTATUS_FMT,  /* 3 args: code,msg,fmt     */ \
        _RSTATUS_NOFMT /* 2 args: code,msg         */ \
    )(__VA_ARGS__)

#define RPROFREP_STATUS_SUCCESS                 (rprofrep_status_t) {.code = RPROFREP_STATUS_CODE_SUCCESS, .msg = NULL, .file = NULL, .func = NULL, .line = 0}
#define RPROFREP_STATUS_ERROR(...)              __RPROFREP_WRAP_STATUS(RPROFREP_STATUS_CODE_ERROR,          "A generic error occured",      ##__VA_ARGS__)
#define RPROFREP_STATUS_INVALID_PTR(...)        __RPROFREP_WRAP_STATUS(RPROFREP_STATUS_CODE_INVALID_PTR,    "Invalid pointer",              ##__VA_ARGS__)
#define RPROFREP_STATUS_INVALID_ARG(...)        __RPROFREP_WRAP_STATUS(RPROFREP_STATUS_CODE_INVALID_ARG,    "Invalid argument",             ##__VA_ARGS__)
#define RPROFREP_STATUS_INVALID_REPORT(...)     __RPROFREP_WRAP_STATUS(RPROFREP_STATUS_CODE_INVALID_REPORT, "Invalid report file",          ##__VA_ARGS__)
#define RPROFREP_STATUS_INVALID_EVENT(...)      __RPROFREP_WRAP_STATUS(RPROFREP_STATUS_CODE_INVALID_EVENT,  "Invalid event",                ##__VA_ARGS__)
#define RPROFREP_STATUS_ALLOC_FAILED(...)       __RPROFREP_WRAP_STATUS(RPROFREP_STATUS_CODE_ALLOC_FAILED,   "Memory allocation failed",     ##__VA_ARGS__)
#define RPROFREP_STATUS_MMAP_FAILED(...)        __RPROFREP_WRAP_STATUS(RPROFREP_STATUS_CODE_MMAP_FAILED,    "Memory mapping failed",        ##__VA_ARGS__)
#define RPROFREP_STATUS_FILE_ERROR(...)         __RPROFREP_WRAP_STATUS(RPROFREP_STATUS_CODE_FILE_ERROR,     "A file error occured",         ##__VA_ARGS__)
#define RPROFREP_STATUS_NOT_FOUND(...)          __RPROFREP_WRAP_STATUS(RPROFREP_STATUS_CODE_NOT_FOUND,      "Something is missing",         ##__VA_ARGS__)
#define RPROFREP_STATUS_NOT_INIT(...)           __RPROFREP_WRAP_STATUS(RPROFREP_STATUS_CODE_NOT_INIT,       "Unitialization",               ##__VA_ARGS__)
#define RPROFREP_STATUS_AMD_ERROR(...)          __RPROFREP_WRAP_STATUS(RPROFREP_STATUS_CODE_AMD_ERROR,      "AMD Error",                    ##__VA_ARGS__)


#define rprofrep_status_is_success(status) ((status).code == RPROFREP_STATUS_CODE_SUCCESS)


static inline void rprofrep_log_status(rprofrep_status_t status) {
    if (status.code == RPROFREP_STATUS_CODE_SUCCESS) return; // success, nothing to log

    // Print main error line
    fprintf(stderr, "[ERROR] [%s:%d %s]\n\t%s",
            status.file ? status.file : "(unknown)",
            status.line,
            status.func ? status.func : "(unknown)",
            status.msg ? status.msg : "Unknown error");

    // Print user-provided message
    if (status.user_msg[0] != '\0') fprintf(stderr, ": %s", status.user_msg);
    fprintf(stderr, "\n");
}



// ===== RPROFREP_CHECK_CALL =====
#define _RPROFREP_CHECK_CALL_1(call) \
    RPROFREP_CHECK_CALL_2(call, (void)0)

#define RPROFREP_CHECK_CALL_2(call, cleanup_block) \
    do {                                           \
        rprofrep_status_t status = (call);         \
        if (status.code != RPROFREP_STATUS_CODE_SUCCESS) {   \
            cleanup_block;                         \
            return status;                         \
        }                                          \
    } while (0)

#define RPROFREP_CHECK_CALL(...) \
    _RPROFREP_GET_MACRO2(__VA_ARGS__, RPROFREP_CHECK_CALL_2, _RPROFREP_CHECK_CALL_1)(__VA_ARGS__)




// ===== RPROFREP_CHECK_ALLOC =====
#define _RPROFREP_CHECK_ALLOC_1(ptr) \
    RPROFREP_CHECK_ALLOC_2(ptr, (void)0)

#define RPROFREP_CHECK_ALLOC_2(ptr, cleanup_block) \
    do {                                           \
        if ((ptr) == NULL) {                       \
            cleanup_block;                         \
            return RPROFREP_STATUS_ALLOC_FAILED("Out of memory?");   \
        }                                          \
    } while (0)

#define RPROFREP_CHECK_ALLOC(...) \
    _RPROFREP_GET_MACRO2(__VA_ARGS__, RPROFREP_CHECK_ALLOC_2, _RPROFREP_CHECK_ALLOC_1)(__VA_ARGS__)




// ===== RPROFREP_CHECK_VALID_PTR =====
#define _RPROFREP_CHECK_ONE_PTR(p)  \
    do { if ((p) == NULL) return RPROFREP_STATUS_INVALID_PTR(#p " is NULL"); } while (0)


#define RPROFREP_CHECK_VALID_PTR(...) \
    do { \
        _RPROFREP_EXPAND(_RPROFREP_GET_MACRO5(__VA_ARGS__, _RPROFREP_FOREACH_5, _RPROFREP_FOREACH_4, \
                                              _RPROFREP_FOREACH_3, _RPROFREP_FOREACH_2, _RPROFREP_FOREACH_1) \
                                              (_RPROFREP_CHECK_ONE_PTR, __VA_ARGS__)); \
    } while (0)



// ===== RPROFREP_CHECK_VALID_ARG =====
#define _RPROFREP_CHECK_ONE_ARG(cond) \
    do { if (!(cond)) return RPROFREP_STATUS_INVALID_ARG(#cond " is invalid"); } while (0)

#define RPROFREP_CHECK_VALID_ARG(...) \
    do { \
        _RPROFREP_EXPAND(_RPROFREP_GET_MACRO5(__VA_ARGS__, _RPROFREP_FOREACH_5, _RPROFREP_FOREACH_4, \
                                              _RPROFREP_FOREACH_3, _RPROFREP_FOREACH_2, _RPROFREP_FOREACH_1) \
                                              (_RPROFREP_CHECK_ONE_ARG, __VA_ARGS__)); \
    } while (0)


// ===== RPROFREP_CHECK_FOPEN =====
#define _RPROFREP_CHECK_FOPEN_1(ptr) \
    RPROFREP_CHECK_FOPEN_2(ptr, (void)0)

#define RPROFREP_CHECK_FOPEN_2(ptr, cleanup_block) \
    do {                                           \
        if ((ptr) == NULL) {                       \
            cleanup_block;                         \
            return RPROFREP_STATUS_FILE_ERROR("Cannot open the file %s.", filepath);   \
        }                                          \
    } while (0)

#define RPROFREP_CHECK_FOPEN(...) \
    _RPROFREP_GET_MACRO2(__VA_ARGS__, RPROFREP_CHECK_FOPEN_2, _RPROFREP_CHECK_FOPEN_1)(__VA_ARGS__)


#endif // RPROFREP_STATUS_H