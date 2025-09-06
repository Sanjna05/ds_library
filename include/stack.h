//
// Created by rahul on 06-09-2025.
//

#ifndef DS_LIBRARY_STACK_H
#define DS_LIBRARY_STACK_H

// Opaque struct for Stack ADT, implementation hidden in src/stack.c
typedef struct Stack Stack;

// Creates a Stack with the specified capacity
// Parameters: capacity (maximum number of elements)
// Returns: Pointer to the created Stack, or NULL if allocation fails
Stack* createStack(int capacity);

// Pushes a value onto the Stack
// Parameters: stack (Stack pointer), value (data to push)
// Precondition: stack is not full
void push(Stack* stack, int value);

// Pops the top value from the Stack
// Parameters: stack (Stack pointer)
// Returns: Top value, or INT_MIN if stack is empty
int pop(Stack* stack);

// Returns the top value without removing it
// Parameters: stack (Stack pointer)
// Returns: Top value, or INT_MIN if stack is empty
int peek(Stack* stack);

// Checks if the Stack is empty
// Parameters: stack (Stack pointer)
// Returns: 1 if empty, 0 otherwise
int isEmptyStack(Stack* stack);

// Checks if the Stack is full
// Parameters: stack (Stack pointer)
// Returns: 1 if full, 0 otherwise
int isFullStack(Stack* stack);

// Traverses the Stack, printing all elements for debugging (top to bottom)
// Parameters: stack (Stack pointer)
void traverseStack(Stack* stack);

// Frees the Stack and its internal data
// Parameters: stack (Stack pointer)
void freeStack(Stack* stack);

// Placement problem: Evaluates a postfix expression using a Stack
// Parameters: expr (null-terminated string, e.g., "23+")
// Returns: Result of the expression, or INT_MIN on error
int evaluatePostfix(const char* expr);

#endif // DS_LIBRARY_STACK_H
