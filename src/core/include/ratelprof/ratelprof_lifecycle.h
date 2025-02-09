/**
 * @file ratelprof_lifecycle.h 
 * @brief Lifecycle Management System
 *
 * This header file defines structures and functions for managing the lifecycle 
 * of a program, tracking different execution phases, and handling lifecycle-related 
 * data such as timestamps, command-line arguments, and process/thread identifiers.
 *
 * Features:
 * - Defines lifecycle phases, including initialization, main execution, and finalization.
 * - Provides mechanisms for tracking timestamps of different phases.
 * - Stores command-line arguments and execution metadata.
 * - Includes functions to initialize, retrieve, and finalize the lifecycle state.
 *
 * @note THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA. 
 * 
 */

#ifndef RATELPROF_LIFECYCLE_H 
#define RATELPROF_LIFECYCLE_H 

#include <stdlib.h>
#include "ratelprof/ratelprof_status.h"
#include "ratelprof/ratelprof_time.h"


/**
 * @brief Enumeration of the phases in the lifecycle.
 *
 * This enumeration defines the different phases of the lifecycle. Each phase represents
 * a distinct stage in the program's execution, from initialization to finalization.
 */
typedef enum {
	RATELPROF_IN_TOOL_INIT_PHASE,    /**< Tool initialization phase: The tool is being initialized. */
	RATELPROF_IN_CONSTRUCTOR_PHASE,  /**< Constructor phase: The constructor is being executed. */
	RATELPROF_IN_MAIN_PHASE,         /**< Main phase: The main execution of the program is in progress. */
	RATELPROF_IN_DESTRUCTOR_PHASE,   /**< Destructor phase: Destructor is being executed. */
	RATELPROF_IN_TOOL_FINI_PHASE     /**< Tool finalization phase: The tool is being finalized. */
} ratelprof_phase_t;


/**
 * @brief Structure to store data related to the main execution of the program.
 *
 * This structure contains information about the program's main execution, including 
 * command-line arguments, return value, and process/thread identifiers.
 */
typedef struct {
    int (*main_fn)(int, char **, char **); /**< Pointer to the orignal main function. */
    int argc;       /**< Number of command-line arguments passed to the program. */
    char **argv;    /**< Array of command-line arguments. */
    int retval;     /**< Return value of the program's main function. */
    uint64_t pid;   /**< Process ID of the current process. */
    uint64_t tid;   /**< Thread ID of the current thread. */
} ratelprof_main_data_t;


/**
 * @brief Structure representing the lifecycle.
 *
 * This structure contains information about the lifecycle phases, including 
 * timing information for each phase and data related to the program's main execution.
 */
typedef struct {
    ratelprof_phase_t current_phase;           /**< The current phase of the program lifecycle. */
    ratelprof_timespec_t tool_init_start;        /**< Timestamp for the start of the tool initialization phase. */
    ratelprof_timespec_t constructor_start;      /**< Timestamp for the start of the constructor phase. */
    ratelprof_timespec_t main_start;             /**< Timestamp for the start of the main execution phase. */
    ratelprof_timespec_t main_stop;              /**< Timestamp for the end of the main execution phase. */
    ratelprof_timespec_t destructor_stop;        /**< Timestamp for the end of the destructor phase. */
    ratelprof_timespec_t tool_fini_stop;         /**< Timestamp for the end of the tool finalization phase. */
    ratelprof_main_data_t main_data;   /**< Data related to the program's main execution. */
} ratelprof_lifecycle_t;


/**
 * @brief Initializes the lifecycle system and sets the current phase to the tool initialization phase.
 *
 * This function initializes the lifecycle management system by setting the `current_phase` to 
 * `RATELPROF_IN_TOOL_INIT_PHASE` and recording the start time of the tool initialization phase 
 * using a monotonic clock.
 *
 * @return RATELPROF_STATUS_SUCCESS Initialization was successful.
 *
 * @example
 * ```c
 * ratelprof_status_t status = ratelprof_init_lifecycle();
 * if (status == RATELPROF_STATUS_SUCCESS) {
 *     printf("Lifecycle system initialized successfully.\n");
 * }
 * ```
 */
ratelprof_status_t ratelprof_init_lifecycle();


/**
 * @brief Finalizes the lifecycle and performs cleanup tasks.
 *
 * This function finalizes the lifecycle by freeing allocated memory for 
 * the command-line arguments (`argv`) stored in the lifecycle's `main_data` structure 
 * and recording the timestamp for the end of the tool finalization phase.
 *
 * @return RATELPROF_STATUS_SUCCESS Finalization was successful.
 *
 * @note This function should be called at the end of the program's execution to ensure 
 *       proper cleanup of resources used during the lifecycle.
 *
 * @example
 * ```c
 * ratelprof_status_t status = ratelprof_fini_lifecycle();
 * if (status == RATELPROF_STATUS_SUCCESS) {
 *     printf("Lifecycle finalized successfully.\n");
 * }
 * ```
 */
ratelprof_status_t ratelprof_fini_lifecycle();


/**
 * @brief Retrieves the current phase of the lifecycle.
 *
 * This function returns the current phase of the lifecycle as stored in the 
 * `lifecycle.current_phase` field.
 *
 * @return The current phase of the lifecycle as a `ratelprof_phase_t` value.
 *
 * @example
 * ```c
 * ratelprof_phase_t current_phase = ratelprof_get_current_phase();
 * printf("Current lifecycle phase: %d\n", current_phase);
 * ```
 */
ratelprof_phase_t ratelprof_get_current_phase();


/**
 * @brief Retrieves a pointer to the lifecycle structure.
 *
 * This function provides access to the `ratelprof_lifecycle_t` structure, which contains 
 * detailed information about the lifecycle of the program, including current phase, 
 * timing data, and program execution details.
 *
 * @return A pointer to the `ratelprof_lifecycle_t` structure representing the current lifecycle state.
 *
 * @example
 * ```c
 * ratelprof_lifecycle_t* lifecycle = ratelprof_get_lifecycle();
 * printf("Current phase: %d\n", lifecycle->current_phase);
 * ```
 */
ratelprof_lifecycle_t* ratelprof_get_lifecycle();


/**
 * @brief Wrapper function for the program's main function.
 *
 * This function acts as an intermediary for the program's main function (`main_fn`), 
 *
 * @param argc The number of command-line arguments passed to the program.
 * @param argv The array of command-line arguments.
 * @param envp The array of environment variables.
 *
 * @return The return value of the program's main function (`main_fn`).
 *
 * @details
 * - The function updates the lifecycle's current phase to `RATELPROF_IN_MAIN_PHASE` and 
 *   records the start and stop times for the main phase using `clock_gettime`.
 * - It duplicates the `argv` array to store it in the lifecycle's `main_data`.
 * - After executing the main function, it updates the `retval`, `pid`, and `tid` fields 
 *   of `main_data` and transitions the lifecycle phase to `RATELPROF_IN_DESTRUCTOR_PHASE`.
 */
int i_main(int argc, char **argv, char **envp);

#endif // RATELPROF_LIFECYCLE_H 
