#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ratelprof.h"
#include "ratelprof_ext.h"
#include "ratelprof_queue.h"

// Initialize the queue
ratelprof_status_t ratelprof_queue_init(ratelprof_queue_t *queue, size_t initial_capacity) {
    queue->data = malloc(initial_capacity * sizeof(void *));
    if (queue->data == NULL) 
        return RATELPROF_STATUS_MALLOC_FAILED;

    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = initial_capacity;
    return RATELPROF_STATUS_SUCCESS;
}

// Check if the queue is empty
bool ratelprof_queue_is_empty(const ratelprof_queue_t *queue) {
    return queue->size == 0;
}

// Check if the queue is full
bool ratelprof_queue_is_full(const ratelprof_queue_t *queue) {
    return queue->size == queue->capacity;
}

// Enqueue an item
ratelprof_status_t ratelprof_queue_push(ratelprof_queue_t *queue, void *value) {
    if (queue == NULL || queue->data == NULL)
        return RATELPROF_STATUS_QUEUE_IS_NULL;
    if (ratelprof_queue_is_full(queue)) {
        size_t new_capacity = queue->capacity * 2;
        void **new_data = realloc(queue->data, new_capacity * sizeof(void *));
        if (new_data == NULL) 
            return RATELPROF_STATUS_MALLOC_FAILED;

        // If the queue is not empty, rearrange elements to start from the beginning of the new array
        if (queue->size > 0) {
            for (size_t i = 0; i < queue->size; ++i) {
                new_data[i] = queue->data[(queue->front + i) % queue->capacity];
            }
        }

        queue->data = new_data;
        queue->front = 0;
        queue->rear = queue->size;
        queue->capacity = new_capacity;
    }
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
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
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = 0;
    return RATELPROF_STATUS_SUCCESS;
}
