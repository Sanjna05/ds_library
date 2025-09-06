//
// Created by rahul on 06-09-2025.
//

#ifndef DS_LIBRARY_ARRAY_H
#define DS_LIBRARY_ARRAY_H

// Opaque struct for Array ADT, implementation hidden in src/array.c
typedef struct Array Array;

// Creates an Array with the specified capacity
// Parameters: capacity (maximum number of elements)
// Returns: Pointer to the created Array, or NULL if allocation fails
Array* createArray(int capacity);

// Inserts a value at the specified index, shifting elements right if needed
// Parameters: arr (Array pointer), index (position to insert), value (data to insert)
// Precondition: 0 <= index <= arr->size, arr->size < arr->capacity
void insertArray(Array* arr, int index, int value);

// Deletes the element at the specified index, shifting elements left to fill the gap
// Parameters: arr (Array pointer), index (position to delete)
// Precondition: 0 <= index < arr->size
void deleteArray(Array* arr, int index);

// Retrieves the value at the specified index
// Parameters: arr (Array pointer), index (position to access)
// Returns: Value at index, or INT_MIN if index is invalid
int getArray(Array* arr, int index);

// Traverses the Array, printing all elements for debugging
// Parameters: arr (Array pointer)
void traverseArray(Array* arr);

// Resizes the Array to a new capacity
// Parameters: arr (Array pointer), newCapacity (new maximum size)
// Returns: 1 on success, 0 on failure
int resizeArray(Array* arr, int newCapacity);

// Frees the Array and its internal data
// Parameters: arr (Array pointer)
void freeArray(Array* arr);

// Placement problem: Finds duplicates in the Array
// Parameters: arr (Array pointer)
// Returns: 1 if duplicates exist, 0 otherwise
int findDuplicatesArray(Array* arr);

#endif // DS_LIBRARY_ARRAY_H
