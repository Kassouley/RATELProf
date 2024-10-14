#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <unistd.h>
#include <sys/syscall.h>

static inline uint32_t get_tid() 
{ 
    return syscall(__NR_gettid); 
}

static inline uint32_t get_pid() 
{ 
    return syscall(__NR_getpid); 
}

#endif // UTILS_H