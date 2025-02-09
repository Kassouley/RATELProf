/**
 * @file env.h
 * @brief Header file for environment variable handling.
 *
 * This file defines a set of environment variables and provides utility functions 
 * to interact with them. These functions are used to retrieve various configuration 
 * values for the tracing tool, such as plugin path, output file path, 
 * buffer size, and more. The environment variables are used to customize the behavior 
 * of the tool without requiring code changes.
 * 
 * @note THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA. 
 *
 */

#ifndef ENV_H
#define ENV_H 

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Environment variable name for the plugin path.
 * 
 * This macro defines the name of the environment variable
 * that specifies the path to the plugin library.
 */
#define ENV_PLUGIN_PATH "RATELPROF_PLUGIN_PATH"


/**
 * @brief Environment variable name for the output file path.
 * 
 * This macro defines the name of the environment variable
 * that specifies the path for the output file.
 */
#define ENV_OUTPUT_FILE "RATELPROF_OUTPUT_FILE"


/**
 * @brief Environment variable name for the buffer size.
 * 
 * This macro defines the name of the environment variable
 * that specifies the size of the buffer to be used in the application.
 */
#define ENV_BUFFER_SIZE "RATELPROF_BUFFER_SIZE"


/**
 * @brief Default output file path.
 * 
 * This macro defines the default path for the output file, which is `report.json`. 
 * It is used when the `RATELPROF_OUTPUT_FILE` environment variable is not set.
 */
#define DEFAULT_OUTPUT_FILE "report.json"


/**
 * @brief Default buffer size.
 * 
 * This macro defines the default buffer size (`0x200000` or 2 MB in hexadecimal). 
 * It is used when the `RATELPROF_BUFFER_SIZE` environment variable is not set.
 */
#define DEFAULT_BUFFER_SIZE 0x200000


/**
 * @enum filter_t
 * @brief Enum for specifying filter types.
 *
 * This enumeration defines different filter types that can be used in 
 * the context of profiling or tracing. Filters help in controlling which 
 * functions are included or excluded during the profiling process.
 *
 * The available filter types are:
 * - `NO_FILTER`: No filtering is applied. Everything is included.
 * - `BLACKLIST`: Specifies a blacklist filter, where the listed items are excluded.
 * - `WHITELIST`: Specifies a whitelist filter, where only the listed items are included.
 */
typedef enum {
    NO_FILTER,
    BLACKLIST,
    WHITELIST,
    NB_FILTER,
} filter_t;


/**
 * @brief Retrieves the filter type from an environment variable.
 *
 * This function checks the environment variable specified by `env_filter_type` 
 * and attempts to retrieve the corresponding filter type. If the environment 
 * variable is not set, or if its value is invalid, it returns `NO_FILTER`. 
 * Otherwise, it converts the environment variable value to an integer and 
 * returns the corresponding `filter_t` value.
 *
 * @param env_filter_type The name of the environment variable containing 
 *                        the filter type value.
 *
 * @return filter_t The filter type based on the environment variable value.
 *         - Returns `NO_FILTER` if the environment variable is not set 
 *           or if the value is invalid.
 *         - Returns `BLACKLIST` or `WHITELIST` if the value is valid and
 *           corresponds to those filters.
 *
 * @note The environment variable value is expected to be an integer corresponding 
 *       to one of the `filter_t` values. If the value is out of range or invalid, 
 *       `NO_FILTER` is returned.
 */
filter_t get_filter_type(const char* env_filter_type);


/**
 * @brief Checks if a specific domain is enabled / profiled based on an environment variable.
 * 
 * This function checks if a given domain is set (enabled) by retrieving its value from an environment variable 
 * corresponding to the domain name. If the environment variable exists and contains a non-empty value, it converts 
 * the value to an integer and interprets it as a boolean (non-zero means true). If the variable is not set or empty, 
 * the function returns `false`.
 *
 * @param domain The name of the environment variable representing the domain to check.
 *
 * @return bool `true` if the domain is enabled (non-zero value in the environment variable), otherwise `false`.
 * 
 * @note The environment variable value is converted to an integer using `atoi`. Any non-zero value is considered `true`, 
 *       and `0` or an unset/empty variable is considered `false`.
 */
bool is_set_domain(const char *domain);


/**
 * @brief Retrieves a whitelist filter of functions to trace.
 *
 * @param env_function_filter The name of the environment variable to retrieve.
 * 
 * @return const char* The value of the environment variable if valid; otherwise, `NULL`.
 * 
 * @note This function only accepts environment variable values containing function name separated with commas. 
 * Any other characters in the value will cause the function to return `NULL`.
 */
const char* get_function_filter(const char* env_function_filter);


/**
 * @brief Loads a plugin library specified by the environment variable.
 * 
 * This function retrieves the path to a plugin library from the environment variable `ENV_PLUGIN_PATH`, 
 * attempts to load the library using `dlopen`, and returns a handle to the loaded library. If the 
 * environment variable is not set or if loading the library fails, the function prints an error message 
 * and terminates the program.
 *
 * @return void* A handle to the loaded plugin library, or the program terminates on failure.
 * 
 * @note This function expects the environment variable `ENV_PLUGIN_PATH` to be set, and it uses the 
 *       `dlopen` function to load the shared library at the specified path. On failure, the program 
 *       terminates with an error message.
 */
void* get_plugin_lib();


/**
 * @brief Retrieves the output file path from the environment variable.
 * 
 * This function attempts to retrieve the output file path from the environment variable `ENV_OUTPUT_FILE`. 
 * If the environment variable is not set, it returns a default output file path (`DEFAULT_OUTPUT_FILE`).
 *
 * @return const char* The output file path. If the environment variable is set, returns its value; 
 *         otherwise, returns the default output file path.
 * 
 * @note This function relies on the environment variable `ENV_OUTPUT_FILE` to specify the output file path.
 *       If the variable is not set, a default file path is returned instead.
 */
const char* get_output_file();


/**
 * @brief Gets a long long value from an environment variable.
 * 
 * Returns the converted value from the environment variable or `default_val` if unset.
 * 
 * @param env The environment variable name.
 * @param default_val The default value if the variable is unset.
 * @return long long The converted value or `default_val`.
 */
long long envtoll(const char* env, long long default_val);


/**
 * @brief Gets an integer value from an environment variable.
 * 
 * Returns the converted value from the environment variable or `default_val` if unset.
 * 
 * @param env The environment variable name.
 * @param default_val The default value if the variable is unset.
 * @return int The converted value or `default_val`.
 */
int envtoi(const char* env, int default_val);


#endif // ENV_H
