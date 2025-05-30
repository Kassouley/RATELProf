#ifndef RATELPROF_QUEUE_H
#define RATELPROF_QUEUE_H

#include <stdbool.h>
#include <stddef.h>
#include <ratelprof.h>

/**
 * Structure to represent a queue.
 *
 * This structure manages a queue with the following properties:
 * - `data`: Pointer to the array holding the queue elements. The elements are stored in a contiguous memory block.
 * - `front`: The index of the front element in the queue. This is the element that will be popd next.
 * - `size`: The current number of elements in the queue.
 * - `capacity`: The total capacity of the queue. This is the maximum number of elements the queue can hold.
 */
typedef struct {
    /** Pointer to the queue data. The data is stored as a void pointer to accommodate different types of elements. */
    void** data;
    /** Index of the front element. This is the position of the element that will be poped next. */
    size_t front;
    /** Current size of the queue. Indicates how many elements are currently in the queue. */
    size_t size;
    /** Capacity of the queue. Defines the maximum number of elements the queue can hold. */
    size_t capacity;
} ratelprof_queue_t;



/**
 * The function `ratelprof_queue_init` initializes a queue with an initial capacity.
 * 
 * @param queue The `queue` parameter is a pointer to a `ratelprof_queue_t` structure, which is used to
 * represent a queue data structure.
 * @param initial_capacity The `initial_capacity` parameter in the `ratelprof_queue_init` function
 * represents the initial capacity of the queue being initialized. It specifies the initial number of
 * elements that the queue can hold without needing to resize its internal data structure.
 * 
 * @return The function `ratelprof_queue_init` is returning a value of type `ratelprof_status_t`. In
 * this specific case, it will return `RATELPROF_STATUS_SUCCESS` if the initialization is successful,
 * and `RATELPROF_STATUS_MALLOC_FAILED` if the memory allocation using `malloc` fails.
 */
ratelprof_status_t 
ratelprof_queue_init(ratelprof_queue_t *queue, 
                     size_t initial_capacity);



/**
 * The function ratelprof_queue_is_empty checks if a given queue is empty.
 * 
 * @param queue The `queue` parameter is a pointer to a `ratelprof_queue_t` structure, which likely
 * represents a queue data structure. The function `ratelprof_queue_is_empty`
 * checks if the given queue is empty by comparing its size to zero.
 * 
 * @return a boolean value indicating whether the ratelprof_queue is empty or not. It returns `true` if
 * the size of the queue is 0, indicating that the queue is empty, and `false` otherwise.
 */
bool 
ratelprof_queue_is_empty(const ratelprof_queue_t *queue);



/**
 * The function checks if a queue is full by comparing its size to its capacity.
 * 
 * @param queue The `queue` parameter is a pointer to a structure of type `ratelprof_queue_t`. This
 * structure likely contains information about a queue data structure, such as its size and capacity.
 * 
 * @return The function `ratelprof_queue_is_full` is returning a boolean value, either `true` or
 * `false`, based on whether the size of the queue is equal to its capacity.
 */
bool 
ratelprof_queue_is_full(const ratelprof_queue_t *queue);



/**
 * The function `ratelprof_queue_push` pushs a value into a queue, dynamically resizing the queue
 * if necessary.
 * 
 * @param queue The `ratelprof_queue_t` structure represents a queue data structure. It contains the
 * following fields:
 * @param value The `value` parameter in the `ratelprof_queue_push` function represents the data
 * that you want to add to the queue. It is a pointer to the memory location where the data is stored.
 * The function copies this data into the queue's internal data structure for storage.
 * 
 * @return The function `ratelprof_queue_push` returns a `ratelprof_status_t` enum value. The
 * possible return values are:
 * - `RATELPROF_STATUS_SUCCESS` if the push operation was successful.
 * - `RATELPROF_STATUS_QUEUE_IS_NULL` if the input queue pointer is NULL.
 * - `RATELPROF_STATUS_MALLOC_FAILED` if memory allocation using `realloc` failed
 */
ratelprof_status_t 
ratelprof_queue_push(ratelprof_queue_t *queue, 
                     void* value);



/**
 * The function ratelprof_queue_pop pops an element from a queue and returns its value.
 * 
 * @param queue The `ratelprof_queue_t` is a data structure representing a queue in the code snippet
 * you provided. It likely contains information such as the capacity, size, front index, element size,
 * and the actual data elements stored in the queue.
 * @param value The `value` parameter in the `ratelprof_queue_pop` function is a pointer to a
 * memory location where the poped element from the queue will be copied.
 * 
 * @return The function `ratelprof_queue_pop` returns a value of type `ratelprof_status_t`, which
 * is an enum type representing different status codes. The possible return values are:
 * - `RATELPROF_STATUS_SUCCESS` if the pop operation was successful
 * - `RATELPROF_STATUS_QUEUE_IS_NULL` if the input queue pointer is NULL
 * - `RATELPROF_STATUS
 */
ratelprof_status_t 
ratelprof_queue_pop(ratelprof_queue_t *queue, 
                    void** value);



/**
 * The function `ratelprof_queue_free` frees the resources allocated for a queue structure.
 * 
 * @param queue The `ratelprof_queue_t` structure contains the following members:
 * 
 * @return The function `ratelprof_queue_free` returns a `ratelprof_status_t` status code. If the
 * `queue` parameter is `NULL`, it returns `RATELPROF_STATUS_QUEUE_IS_NULL`. If the queue's data is
 * successfully freed and the queue is reset, it returns `RATELPROF_STATUS_SUCCESS`.
 */
ratelprof_status_t 
ratelprof_queue_free(ratelprof_queue_t *queue);

#endif // RATELPROF_QUEUE_H
