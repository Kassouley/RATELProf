/* # THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * # DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * # ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA.
 */ 

#include "logger.h"

Logger logger = { NULL, {0}, 0 };  // Definition of the logger instance

// Function to get current time as a string
char* current_time() {
    time_t rawtime;
    struct tm *timeinfo;
    static char buffer[20];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return buffer;
}