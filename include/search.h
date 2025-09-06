//
// Created by rahul on 06-09-2025.
//

#ifndef DS_LIBRARY_SEARCH_H
#define DS_LIBRARY_SEARCH_H

#include "array.h" // Dependency on Array ADT from Module 1

// Performs Linear Search on an Array to find a value
// Parameters: arr (Array pointer), value (data to find)
// Returns: Index of the first occurrence of value, or -1 if not found
int linearSearch(Array* arr, int value);

// Performs Binary Search on a sorted Array to find a value
// Parameters: arr (Array pointer, must be sorted), value (data to find)
// Returns: Index of the value, or -1 if not found
// Precondition: Array is sorted in ascending order
int binarySearch(Array* arr, int value);

// Placement problem: Finds the first occurrence of a value in an Array
// Parameters: arr (Array pointer), value (data to find)
// Returns: Index of the first occurrence, or -1 if not found
int findFirstOccurrence(Array* arr, int value);

#endif // DS_LIBRARY_SEARCH_H
