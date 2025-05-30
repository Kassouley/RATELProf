#ifndef RATELPROF_STATUS_EXT_H 
#define RATELPROF_STATUS_EXT_H 

#include <ratelprof.h>

typedef enum {
    RATELPROF_STATUS_KEY_NOT_FOUND = RATELPROF_NB_STATUS,
    RATELPROF_STATUS_QUEUE_EMPTY,
    RATELPROF_STATUS_TABLE_IS_NULL,
    RATELPROF_STATUS_QUEUE_IS_NULL,
    RATELPROF_STATUS_HASH_TABLE_COLLISION,
    RATELPROF_STATUS_INVALID_FORMAT_SIZE,
    RATELPROF_STATUS_FAILED_OPEN_FILE,
    RATELPROF_STATUS_NO_CALLBACK_SET,
    RATELPROF_STATUS_AGENTS_QUERY_FAILED,
    RATELPROF_STATUS_QUEUE_POP_NULL,
} ratelprof_status_ext_t;


static inline const char* get_error_string_ext(ratelprof_status_t status) {
    switch ((int)status)
    {
        case RATELPROF_STATUS_KEY_NOT_FOUND:         return "Key in hashtable doesn't exist";
        case RATELPROF_STATUS_QUEUE_EMPTY:           return "The queue is empty";
        case RATELPROF_STATUS_TABLE_IS_NULL:         return "The hashtable is not initialized (NULL)";
        case RATELPROF_STATUS_QUEUE_IS_NULL:         return "The queue is not initialized (NULL)";
        case RATELPROF_STATUS_HASH_TABLE_COLLISION:  return "Insert collision in hash table";
        case RATELPROF_STATUS_INVALID_FORMAT_SIZE:   return "Invalid format size specified";
        case RATELPROF_STATUS_FAILED_OPEN_FILE:      return "Failed to open the file";
        case RATELPROF_STATUS_NO_CALLBACK_SET:       return "No callback has been set";
        case RATELPROF_STATUS_AGENTS_QUERY_FAILED:   return "Agents query failed to execute";
        case RATELPROF_STATUS_QUEUE_POP_NULL:        return "A NULL element has been pop from a queue";
        default: return get_error_string(status); break;
    }
    return "Unknown error";
}

#endif // RATELPROF_STATUS_EXT_H