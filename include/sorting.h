//
// Created by rahul on 06-09-2025.
//

#ifndef DS_LIBRARY_SORTING_H
#define DS_LIBRARY_SORTING_H

#include "array.h" // Dependency on Array ADT from Module 1

// Performs Bubble Sort on an Array
// Parameters: arr (Array pointer to be sorted in ascending order)
// Precondition: arr is not NULL
void bubbleSort(Array* arr);

// Performs Selection Sort on an Array
// Parameters: arr (Array pointer to be sorted in ascending order)
// Precondition: arr is not NULL
void selectionSort(Array* arr);

// Performs Insertion Sort on an Array
// Parameters: arr (Array pointer to be sorted in ascending order)
// Precondition: arr is not NULL
void insertionSort(Array* arr);

// Performs Quick Sort on an Array
// Parameters: arr (Array pointer to be sorted in ascending order)
// Precondition: arr is not NULL
void quickSort(Array* arr);

// Performs Merge Sort on an Array
// Parameters: arr (Array pointer to be sorted in ascending order)
// Precondition: arr is not NULL
void mergeSort(Array* arr);

// Performs Counting Sort on an Array
// Parameters: arr (Array pointer to be sorted in ascending order)
// Precondition: arr is not NULL and contains non-negative integers
void countingSort(Array* arr);

// Performs Heap Sort on an Array
// Parameters: arr (Array pointer to be sorted in ascending order)
// Precondition: arr is not NULL
void heapSort(Array* arr);

// Placement problem: Sorts an Array and removes duplicates
// Parameters: arr (Array pointer)
// Returns: Number of unique elements after sorting
// Precondition: arr is not NULL
int sortAndRemoveDuplicates(Array* arr);

#endif // DS_LIBRARY_SORTING_H
