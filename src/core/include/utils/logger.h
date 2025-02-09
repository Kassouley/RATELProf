#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

#define LOG_FILE "logfile.txt"
#define LOG_BUFFER_SIZE 1024
#define LOG_FLUSH_THRESHOLD (LOG_BUFFER_SIZE / 2)

// Logger structure
typedef struct {
    FILE *file;
    char buffer[LOG_BUFFER_SIZE];
    size_t buffer_len;
} Logger;

// Instance of the logger
extern Logger logger;

// Initialize the logger
#define INIT_LOGGER() do { \
    if (logger.file == NULL) { \
        logger.file = fopen(LOG_FILE, "a"); \
        if (logger.file == NULL) { \
            perror("Failed to open log file"); \
            exit(EXIT_FAILURE); \
        } \
    } \
} while (0)

// Flush the buffer to the file
#define FLUSH_LOGGER() do { \
    if (logger.file && logger.buffer_len > 0) { \
        fwrite(logger.buffer, 1, logger.buffer_len, logger.file); \
        fflush(logger.file); \
        logger.buffer_len = 0; \
    } \
} while (0)

// Log a message with format
#define LOG_MESSAGE(format, ...) do { \
    if (logger.file != NULL) { \
        int len = snprintf(logger.buffer + logger.buffer_len, \
                           LOG_BUFFER_SIZE - logger.buffer_len, \
                           "[%s] " format "\n", current_time(), ##__VA_ARGS__); \
        if (len > 0) { \
            logger.buffer_len += len; \
            if (logger.buffer_len > LOG_FLUSH_THRESHOLD) { \
                FLUSH_LOGGER(); \
            } \
        } else { \
            fprintf(stderr, "Warning: Log message formatting failed\n"); \
        } \
    } else { \
        fprintf(stderr, "Error: Log file is not open\n"); \
    } \
} while (0)

// Close the logger
#define CLOSE_LOGGER() do { \
    FLUSH_LOGGER(); \
    if (logger.file) { \
        fclose(logger.file); \
        logger.file = NULL; \
    } \
} while (0)

// Function to get current time as a string
char* current_time();

#endif // LOGGER_H
