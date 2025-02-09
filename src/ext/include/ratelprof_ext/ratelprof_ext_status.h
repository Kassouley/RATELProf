#ifndef RATELPROF_STATUS_EXT_H 
#define RATELPROF_STATUS_EXT_H 

#include <ratelprof.h>

#define RATELPROF_STATUS_KEY_NOT_FOUND 0x80
#define RATELPROF_STATUS_QUEUE_EMPTY 0x81
#define RATELPROF_STATUS_BUFFER_IS_NULL 0x82
#define RATELPROF_STATUS_TABLE_IS_NULL 0x83
#define RATELPROF_STATUS_QUEUE_IS_NULL 0x84
#define RATELPROF_STATUS_HASH_TABLE_COLLISION 0x85
#define RATELPROF_STATUS_INVALID_FORMAT_SIZE 0x86
#define RATELPROF_STATUS_FAILED_OPEN_FILE 0x87
#define RATELPROF_STATUS_NO_CALLBACK_SET 0x88
#define RATELPROF_STATUS_AGENTS_QUERY_FAILED 0x89


static inline const char* get_error_string_ext(ratelprof_status_t err) {
    switch ((int)err)
    {
        case RATELPROF_STATUS_KEY_NOT_FOUND:         return "Key in hashtable doesn't exist";
        case RATELPROF_STATUS_QUEUE_EMPTY:           return "The queue is empty";
        case RATELPROF_STATUS_BUFFER_IS_NULL:        return "The buffer is NULL";
        case RATELPROF_STATUS_TABLE_IS_NULL:         return "The hashtable is not initialized (NULL)";
        case RATELPROF_STATUS_QUEUE_IS_NULL:         return "The queue is not initialized (NULL)";
        case RATELPROF_STATUS_HASH_TABLE_COLLISION:  return "Insert collision in hash table";
        case RATELPROF_STATUS_INVALID_FORMAT_SIZE:   return "Invalid format size specified";
        case RATELPROF_STATUS_FAILED_OPEN_FILE:      return "Failed to open the file";
        case RATELPROF_STATUS_NO_CALLBACK_SET:       return "No callback has been set";
        case RATELPROF_STATUS_AGENTS_QUERY_FAILED:   return "Agents query failed to execute";
        default: break;
    }
    return NULL;
}

static inline const char* get_combined_error_string(ratelprof_status_t err) {
    const char* extended_msg = get_error_string_ext(err);
    if (extended_msg) {
        return extended_msg;
    }
    const char* original_msg = get_error_string(err);
    return original_msg ? original_msg : "Unknown error";
}

#endif // RATELPROF_STATUS_EXT_H