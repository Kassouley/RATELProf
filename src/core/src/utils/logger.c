#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "utils/logger.h"
#include "utils/env.h"

// Logger function with updatable messages
void LOG(int level, const char *format, ...) 
{
    static int current_log_level = -1;
    if (current_log_level == -1) {
        current_log_level = envtoi("RATELPROF_LOG_LEVEL", 9);
    }
    
    if ((current_log_level & level) == 0) {
        return; // Skip logging if level is not enabled
    }

    const char *level_str;
    const char *color_code;
    FILE* stream = stdout;
    switch (level) {
        case LOG_LEVEL_INFO:
            level_str = "INFO";
            color_code = COLOR_INFO;
            break;
        case LOG_LEVEL_DEBUG:
            level_str = "DEBUG";
            color_code = COLOR_DEBUG;
            break;
        case LOG_LEVEL_WARN:
            level_str = "WARNING";
            color_code = COLOR_WARNING;
            stream = stderr;
            break;
        case LOG_LEVEL_ERROR:
            level_str = "ERROR";
            color_code = COLOR_ERROR;
            stream = stderr;
            break;
        case LOG_LEVEL_FATAL:
            level_str = "FATAL";
            color_code = COLOR_FATAL;
            stream = stderr;
            break;
        default:
            return;
    }

    va_list args;
    va_start(args, format);
    fprintf(stream, "%s[%s]%s RPROF: ", color_code, level_str, COLOR_RESET);
    vfprintf(stream, format, args);
    fflush(stream);
    va_end(args);
    if (level == LOG_LEVEL_FATAL) exit(-1);
}