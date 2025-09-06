//
// Created by rahul on 06-09-2025.
//

#ifndef DS_LIBRARY_RECURSION_H
#define DS_LIBRARY_RECURSION_H

#include "stack.h" // Dependency on Stack ADT for Tower of Hanoi visualization

// Computes factorial of a number recursively
// Parameters: n (non-negative integer)
// Returns: n! (factorial), or -1 if n is negative
int factorial(int n);

// Computes nth Fibonacci number recursively
// Parameters: n (non-negative integer)
// Returns: nth Fibonacci number, or -1 if n is negative
int fibonacci(int n);

// Placement problem: Solves Tower of Hanoi and visualizes moves
// Parameters: n (number of disks), source (source Stack), auxiliary (auxiliary Stack),
//             destination (destination Stack), moveCount (pointer to track moves)
// Precondition: Stacks are initialized, n >= 0
void towerOfHanoi(int n, Stack* source, Stack* auxiliary, Stack* destination, int* moveCount);

#endif // DS_LIBRARY_RECURSION_H
