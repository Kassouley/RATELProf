#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include "id_system.h"

// Mutex for synchronizing access to global_id_counter
static pthread_mutex_t id_mutex = PTHREAD_MUTEX_INITIALIZER;
static unsigned long long global_id_counter = 1;

// TLS key for the thread-local stack
static pthread_key_t thread_stack_key;

// Function to initialize the stack with an initial capacity
void stack_init(Stack* s, int capacity) {
    s->capacity = capacity;
    s->top = 0;
    s->items = (uint64_t*)malloc(s->capacity * sizeof(uint64_t));  // Allocate memory for stack
    if (s->items == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    s->items[s->top] = 0;
}

// Function to double the stack capacity when it's full
void stack_resize(Stack* s) {
    s->capacity *= 2;  // Double the capacity
    s->items = (uint64_t*)realloc(s->items, s->capacity * sizeof(uint64_t));  // Reallocate memory
    if (s->items == NULL) {
        fprintf(stderr, "Memory reallocation failed!\n");
        exit(1);  // Exit if memory reallocation fails
    }
}

// Check if the stack is full
int stack_is_full(Stack* s) {
    return s->top == s->capacity - 1;
}

// Check if the stack is empty
int stack_is_empty(Stack* s) {
    return s->top == -1;
}

// Push operation to add an element to the stack
void stack_push(Stack* s, uint64_t id) {
    if (stack_is_full(s)) {
        stack_resize(s);  // Resize the stack if it's full
    }
    s->items[++(s->top)] = id;  // Increment top and push id
}

// Pop operation to remove the top element from the stack
int stack_pop(Stack* s) {
    if (stack_is_empty(s)) {
        return -1;
    }
    return s->items[(s->top)--];  // Return the top element and decrement top
}

// Peek operation to get the top element without removing it
int stack_peek(Stack* s) {
    if (stack_is_empty(s)) {
        return -1;
    }
    return s->items[s->top];
}

// Function to free the allocated memory when done
void stack_free(Stack* s) {
    free(s->items);
    s->items = NULL;
    s->top = -1;
    s->capacity = 0;
}

// Destructor function that will be called when the thread exits
void cleanup_stack(void* s) {
    if (s != NULL) {
        stack_free((Stack*)s);
        free(s);  // Free the stack structure itself
    }
}

// Ensure the stack is initialized for the current thread
Stack* get_thread_stack() 
{
    Stack* s = (Stack*)pthread_getspecific(thread_stack_key);
    if (s == NULL) {
        s = create_thread_stack();
    }
    return s;
}

Stack* create_thread_stack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    stack_init(s, 2048);
    pthread_setspecific(thread_stack_key, s);  // Associate this stack with the current thread
    return s;
}

uint64_t push_id()
{
    Stack* s = get_thread_stack();  // Ensure the stack is initialized

    uint64_t id;
    // Lock the mutex to ensure safe access to global_id_counter
    pthread_mutex_lock(&id_mutex);
    id = global_id_counter++;
    pthread_mutex_unlock(&id_mutex);
    
    stack_push(s, id);
    return id;
}

void pop_id()
{
    Stack* s = get_thread_stack();  // Ensure the stack is initialized
    stack_pop(s);
}

// Get the next correlation ID for the global thread
uint64_t get_correlation_id()
{
    Stack* s = get_thread_stack();  // Ensure the stack is initialized
    return stack_peek(s);
}

// Initialize the thread-local storage for the stack
void init_id_system()
{
    // Create a TLS key with a destructor that will clean up the stack when the thread exits
    pthread_key_create(&thread_stack_key, cleanup_stack);
    create_thread_stack();
}

// Clean up resources related to the global ID system
void cleanup_id_system() 
{
    // Delete the TLS key when it's no longer needed (e.g., when the program exits)
    pthread_key_delete(thread_stack_key);
}
