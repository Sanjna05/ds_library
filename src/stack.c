//
// Created by rahul on 06-09-2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

// Define the Stack struct
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) return NULL;
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    if (!stack->array) {
        free(stack);
        return NULL;
    }
    return stack;
}

// Push a value onto the stack
void push(Stack* stack, int value) {
    if (isFullStack(stack)) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->array[++stack->top] = value;
}

// Pop the top value from the stack
int pop(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("Stack Underflow!\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

// Peek the top value
int peek(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("Stack is empty!\n");
        return INT_MIN;
    }
    return stack->array[stack->top];
}

// Check if the stack is empty
int isEmptyStack(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFullStack(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Traverse the stack (top to bottom)
void traverseStack(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = stack->top; i >= 0; i--)
        printf("%d ", stack->array[i]);
    printf("\n");
}

// Free the stack memory
void freeStack(Stack* stack) {
    if (stack) {
        free(stack->array);
        free(stack);
    }
}

// Evaluate a postfix expression
int evaluatePostfix(const char* expr) {
    Stack* stack = createStack(100); // max 100 elements
    if (!stack) return INT_MIN;

    for (int i = 0; expr[i]; i++) {
        char ch = expr[i];
        if (ch >= '0' && ch <= '9') {
            push(stack, ch - '0'); // convert char to int
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int b = pop(stack);
            int a = pop(stack);
            if (a == INT_MIN || b == INT_MIN) {
                freeStack(stack);
                return INT_MIN; // error
            }
            switch (ch) {
                case '+': push(stack, a + b); break;
                case '-': push(stack, a - b); break;
                case '*': push(stack, a * b); break;
                case '/': 
                    if (b == 0) {
                        freeStack(stack);
                        return INT_MIN; // divide by zero
                    }
                    push(stack, a / b); 
                    break;
            }
        }
    }

    int result = pop(stack);
    freeStack(stack);
    return result;
}
