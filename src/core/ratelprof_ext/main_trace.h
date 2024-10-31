#ifndef MAIN_TRACE_H
#define MAIN_TRACE_H

#include <time.h>
#include <stdlib.h>
#include "ratelprof.h"
#include "ratelprof_ext.h"

typedef struct {
    int argc;
    char **argv;
    int retval;
} main_args_t;

typedef struct {
    int domain;
    int id;
    main_args_t args;
    struct timespec start_time;
    struct timespec stop_time;
    pid_t pid;
    pid_t tid;
} ratelprof_main_activity_t;

int i_main(int argc, char **argv, char **envp);

#endif // MAIN_TRACE_H
