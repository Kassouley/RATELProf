#ifndef LOGGER_H
#define LOGGER_H

// Log level definitions (bitmask)
#define LOG_LEVEL_INFO    1  // 0001
#define LOG_LEVEL_WARN    2  // 0010
#define LOG_LEVEL_ERROR   4  // 0100
#define LOG_LEVEL_FATAL   8  // 1000
#define LOG_LEVEL_DEBUG   16 // 0001 0000

// ANSI color codes
#define COLOR_RESET   "\033[0m"
#define COLOR_INFO    COLOR_RESET       // ("\033[34m"  // Blue)
#define COLOR_DEBUG   "\033[34m"        // Blue
#define COLOR_WARNING "\033[33m"        // Yellow
#define COLOR_ERROR   "\033[31m"        // Red
#define COLOR_FATAL   "\033[38;5;88m"   // Dark Red

// Logger function with updatable messages
void LOG(int level, const char *format, ...);

#endif // LOGGER_H
