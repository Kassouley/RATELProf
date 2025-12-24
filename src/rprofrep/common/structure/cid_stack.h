#ifndef CID_STACK_H
#define CID_STACK_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    uint64_t id;
    size_t group_id;
    size_t event_off;
} rprofrep_cid_entry_t;

/* Stack structure */
typedef struct cid_stack_s {
    size_t top;
    size_t capacity;
    rprofrep_cid_entry_t *data;
} cid_stack_t;

/* Initialize the stack with a given initial capacity */
static inline bool stack_init(cid_stack_t **s, size_t initial_capacity) {
    *s = (cid_stack_t *) malloc(sizeof(cid_stack_t));
    if (!s) return false;
    cid_stack_t *stack = *s;
    stack->data = (rprofrep_cid_entry_t *)malloc(initial_capacity * sizeof(rprofrep_cid_entry_t));
    if (!stack->data) return false;
    stack->top = 0;
    stack->capacity = initial_capacity;
    return true;
}

/* Free the stack memory */
static inline void stack_free(cid_stack_t *s) {
    free(s->data);
    s->data = NULL;
    s->top = 0;
    s->capacity = 0;
    free(s);
}

/* Check if the stack is empty */
static inline bool stack_empty(const cid_stack_t *s) {
    return s->top == 0;
}

/* Push an element and doubles capacity if full */
static inline bool stack_push(cid_stack_t *s, rprofrep_cid_entry_t value) {
    if (s->top == s->capacity) {
        size_t new_capacity = s->capacity * 2;
        rprofrep_cid_entry_t *new_data = (rprofrep_cid_entry_t *)realloc(s->data, new_capacity * sizeof(rprofrep_cid_entry_t));
        if (!new_data) return false; // allocation failed
        s->data = new_data;
        s->capacity = new_capacity;
    }
    s->data[s->top++] = value;
    return true;
}

/* Pop an element, returns false if empty */
static inline bool stack_pop(cid_stack_t *s, rprofrep_cid_entry_t *out) {
    if (stack_empty(s)) return false;
    *out = s->data[--s->top];
    return true;
}

/* Peek the top element, returns false if empty */
static inline bool stack_peek(const cid_stack_t *s, rprofrep_cid_entry_t *out) {
    if (stack_empty(s)) return false;
    *out = s->data[s->top - 1];
    return true;
}

#endif // CID_STACK_H
