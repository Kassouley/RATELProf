#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

typedef struct rb_chunk
{
    struct rb_chunk* next;
    void** data;
} rb_chunk_t;

typedef struct
{
    rb_chunk_t *head_chunk;
    rb_chunk_t *tail_chunk;

    size_t head_off;
    size_t tail_off;

    size_t initial_capacity;
    size_t capacity;

    size_t chunk_size;
} ring_buffer_t;


static inline void debug_print_number_new_chunks(ring_buffer_t *rb)
{
    printf("Number of buffer creation: %zu\n", rb->capacity - rb->initial_capacity);
}

static inline bool rb_is_empty(ring_buffer_t* rb)
{
    return (rb->head_chunk == rb->tail_chunk && rb->head_off == rb->tail_off);
}

static inline bool rb_is_full(ring_buffer_t* rb)
{
    return (rb->head_chunk->next == rb->tail_chunk);
}

static inline rb_chunk_t* rb_grow(ring_buffer_t* rb)
{
    const size_t total_size = sizeof(rb_chunk_t) + (rb->chunk_size * sizeof(void*));
    rb_chunk_t* c = (rb_chunk_t*) malloc(total_size);
    if (!c) return NULL;

    c->next = rb->head_chunk->next;
    c->data = (void**)(c + 1);
    rb->head_chunk->next = c;
    rb->capacity++;

    return c;
}

static inline int rb_init(ring_buffer_t* rb, size_t capacity, size_t chunk_size)
{
    if (capacity == 0)
        return -1;

    size_t data_size = chunk_size * sizeof(void*);

    const size_t total_size = sizeof(rb_chunk_t) + data_size;
    rb_chunk_t* c = (rb_chunk_t*) malloc(total_size);
    if (!c) return -1;

    c->next = c; // circular linked list
    c->data = (void**)(c + 1);
    memset(c->data, 0, data_size);
    rb->head_chunk = c;
    rb->tail_chunk = c;

    rb->head_off = 0;
    rb->tail_off = 0;

    rb->initial_capacity = capacity;
    rb->chunk_size = chunk_size;
    rb->capacity = 1;

    for (size_t i = 0; i < capacity - 1; i++)
    {
        c = rb_grow(rb);
        if (c == NULL)
            return -1;
        memset(c->data, 0, data_size);
    }

    return 0;
}

static inline void rb_destroy(ring_buffer_t* rb)
{
    rb_chunk_t *start = rb->head_chunk;
    rb_chunk_t *cur = start->next;

    while (cur != start)
    {
        rb_chunk_t *tmp = cur;
        cur = cur->next;
        free(tmp);
    }

    free(start);
}


static inline int rb_write(ring_buffer_t *rb, void* addr)
{
    /* ring full -> grow */
    if (rb_is_full(rb)) {
        if (rb_grow(rb) == NULL) {
            return -1;
        }
    }

    if (rb->head_off >= rb->chunk_size) {
        rb->head_chunk = rb->head_chunk->next;
        rb->head_off = 0;
    }

    rb->head_chunk->data[rb->head_off] = addr;
    rb->head_off++;
    return 0;
}

static inline int rb_read(ring_buffer_t *rb, void** addr)
{
    if (rb_is_empty(rb))
    {
        *addr = NULL;
        return -1;
    }

    /* move to next chunk if needed */
    if (rb->tail_off >= rb->chunk_size)
    {
        rb->tail_chunk = rb->tail_chunk->next;
        rb->tail_off = 0;
    }

    *addr = rb->tail_chunk->data[rb->tail_off];
    rb->tail_off++;

    return 0;
}
