#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ratelprof.h>
#include "ratelprof_ext/memory_structure/ratelprof_queue.h"
#include "ratelprof_ext/ratelprof_ext_status.h"

// Initialize the queue
ratelprof_status_t ratelprof_queue_init(ratelprof_queue_t *queue, size_t initial_capacity) {
    queue->data = calloc(initial_capacity, sizeof(void *));
    if (queue->data == NULL) 
        return RATELPROF_STATUS_MALLOC_FAILED;

    queue->front = 0;
    queue->size = 0;
    queue->capacity = initial_capacity;
    return RATELPROF_STATUS_SUCCESS;
}

// Check if the queue is empty
inline bool ratelprof_queue_is_empty(const ratelprof_queue_t *queue) {
    return queue->size == 0;
}

// Check if the queue is full
inline bool ratelprof_queue_is_full(const ratelprof_queue_t *queue) {
    return queue->size == queue->capacity;
}

// Enqueue an item
ratelprof_status_t ratelprof_queue_push(ratelprof_queue_t *queue, void *value) {
    if (queue == NULL || queue->data == NULL)
        return RATELPROF_STATUS_QUEUE_IS_NULL;
    if (ratelprof_queue_is_full(queue)) {
        queue->capacity *= 2;
        queue->data = realloc(queue->data, queue->capacity * sizeof(void *));
        if (queue->data == NULL) 
            return RATELPROF_STATUS_MALLOC_FAILED;
    }
    queue->data[queue->size] = value;
    queue->size++;
    return RATELPROF_STATUS_SUCCESS;
}

// Dequeue an item
ratelprof_status_t ratelprof_queue_pop(ratelprof_queue_t *queue, void **value) {
    if (queue == NULL || queue->data == NULL)
        return RATELPROF_STATUS_QUEUE_IS_NULL;
    if (ratelprof_queue_is_empty(queue)) 
        return RATELPROF_STATUS_QUEUE_EMPTY;
    *value = queue->data[queue->front];
    if (!*value) return RATELPROF_STATUS_QUEUE_POP_NULL;
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return RATELPROF_STATUS_SUCCESS;
}

// Free the queue resources
ratelprof_status_t ratelprof_queue_free(ratelprof_queue_t *queue) {
    if (queue == NULL)
        return RATELPROF_STATUS_QUEUE_IS_NULL;
    if (queue->data) {
        free(queue->data);
        queue->data = NULL;
    }
    queue->front = 0;
    queue->size = 0;
    queue->capacity = 0;
    return RATELPROF_STATUS_SUCCESS;
}
