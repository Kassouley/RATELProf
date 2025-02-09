/**
 * @file utils.h
 * @brief Utility functions for retrieving thread and process IDs.
 *
 * This file provides two inline functions, `get_tid()` and `get_pid()`, 
 * which allow you to retrieve the thread ID (TID) and process ID (PID) of 
 * the calling thread or process, respectively. These functions are implemented 
 * using system calls, which provide low-level access to these identifiers 
 * within the operating system.
 *
 * @note THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA. 
 * 
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <unistd.h>
#include <sys/syscall.h>

/**
 * @brief Retrieves the thread ID of the calling thread.
 *
 * This function uses the `syscall` system call with `__NR_gettid` to obtain 
 * the thread ID (TID) of the current thread.
 *
 * @return The thread ID (`uint32_t`) of the calling thread.
 *
 * @note 
 * - The thread ID (TID) is unique within the system and differs from the 
 *   process ID (PID), which `get_pid()` returns.
 * - This function is useful for thread-specific profiling, logging, and debugging.
 *
 * @example
 * ```c
 * uint32_t tid = get_tid();
 * printf("Current Thread ID: %u\n", tid);
 * ```
 */
static inline uint32_t get_tid() 
{ 
    return syscall(__NR_gettid); 
}


/**
 * @brief Retrieves the process ID of the calling process.
 *
 * This function uses the `syscall` system call with `__NR_getpid` to obtain 
 * the process ID (PID) of the current process.
 *
 * @return The process ID (`uint32_t`) of the calling process.
 *
 * @note 
 * - The process ID (PID) is unique for each running process.
 * - This function is useful for process-level profiling, logging, and debugging.
 *
 * @example
 * ```c
 * uint32_t pid = get_pid();
 * printf("Current Process ID: %u\n", pid);
 * ```
 */
static inline uint32_t get_pid() 
{ 
    return syscall(__NR_getpid); 
}

#endif // UTILS_H