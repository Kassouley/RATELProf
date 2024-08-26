#ifndef RATELPROF_STATUS_H
#define RATELPROF_STATUS_H

#include "ratelprof.h"

#ifdef RATELPROF_DEBUG

#define CHECK_RATELPROF_CALL(call) { \
    ratelprof_status_t ret = call; \
    if (ret != RATELPROF_STATUS_SUCCESS) \
    { \
        fprintf(stderr, "RATELProf Error : %s (code: %d)\n", \
                    get_error_string(ret), ret); \
    } \
};

#else

#define CHECK_RATELPROF_CALL(call) { call; }; // for debug

#endif

typedef enum {
	RATELPROF_STATUS_SUCCESS,
	RATELPROF_STATUS_KEY_NOT_FOUND,
	RATELPROF_STATUS_MALLOC_FAILED,
	RATELPROF_STATUS_QUEUE_EMPTY,
	RATELPROF_STATUS_TABLE_IS_NULL,
	RATELPROF_STATUS_QUEUE_IS_NULL,
    RATELPROF_STATUS_HASH_TABLE_COLLISION,
    RATELPROF_STATUS_INVALID_FORMAT_SIZE,
    RATELPROF_STATUS_FAILED_OPEN_FILE
} ratelprof_status_t;

static inline const char* get_error_string(ratelprof_status_t err) {
    switch (err)
    {	
    case RATELPROF_STATUS_SUCCESS:               return "No error, ggwp"; break;
    case RATELPROF_STATUS_KEY_NOT_FOUND:         return "Key in hashtable doesn't exist"; break;
    case RATELPROF_STATUS_MALLOC_FAILED:         return "Memory allocation failed"; break;
    case RATELPROF_STATUS_QUEUE_EMPTY:           return "The queue is empty"; break;
    case RATELPROF_STATUS_TABLE_IS_NULL:         return "The hashtable is not initialized (NULL)"; break;
    case RATELPROF_STATUS_QUEUE_IS_NULL:         return "The queue is not initialized (NULL)"; break;
    case RATELPROF_STATUS_HASH_TABLE_COLLISION:  return "Insert collision in hash table"; break;
    default: break;
    }
    return NULL;
}

#endif // RATELPROF_STATUS_H
