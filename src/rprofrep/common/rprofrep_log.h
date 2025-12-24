#ifndef RPROFREP_LOG_H
#define RPROFREP_LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

// Log levels
typedef enum {
    RPROFREP_LOG_INFO,
    RPROFREP_LOG_WARN,
    RPROFREP_LOG_ERROR
} rprofrep_log_level_t;

// Log function
static inline void rprofrep_log(rprofrep_log_level_t level, const char* fmt, ...) {
    const char* level_str = "";
    switch (level) {
        case RPROFREP_LOG_INFO:  level_str = "INFO";  break;
        case RPROFREP_LOG_WARN:  level_str = "WARN";  break;
        case RPROFREP_LOG_ERROR: level_str = "ERROR"; break;
    }

    // Print log message header
    fprintf(stderr, "[%s] ", level_str);

    // Print formatted message
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}


#endif // RPROFREP_LOG_H