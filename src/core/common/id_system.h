#ifndef ID_SYSTEM_H
#define ID_SYSTEM_H

#include <stdint.h>

// Stack structure definition
typedef struct Stack {
    uint64_t* items;    // Dynamic array to store stack elements
    int top;       // Index of the top element
    int capacity;  // Maximum size of the stack
} Stack;

// Function prototypes for stack operations

// Function to initialize the stack with an initial capacity
void stack_init(Stack* s, int capacity);

// Function to double the stack capacity when it's full
void stack_resize(Stack* s);

// Check if the stack is full
int stack_is_full(Stack* s);

// Check if the stack is empty
int stack_is_empty(Stack* s);

// Push operation to add an element to the stack
void stack_push(Stack* s, uint64_t id);

// Pop operation to remove the top element from the stack
int stack_pop(Stack* s);

// Peek operation to get the top element without removing it
int stack_peek(Stack* s);

// Function to free the allocated memory when done
void stack_free(Stack* s);

// Destructor function that will be called when the thread exits
void cleanup_stack(void* s);

// Ensure the stack is initialized for the current thread
Stack* get_thread_stack(void);

// Create and initialize the stack for the current thread
Stack* create_thread_stack(void);

// Push an ID onto the thread-local stack and return the pushed ID
uint64_t push_id(void);

// Pop the top ID from the thread-local stack
void pop_id(void);

// Get the next correlation ID for the current thread
uint64_t get_correlation_id(void);

// Initialize the thread-local storage for the stack system
void init_id_system(void);

// Clean up resources related to the ID system for the current thread
void cleanup_id_system(void);

#endif // ID_SYSTEM_H
