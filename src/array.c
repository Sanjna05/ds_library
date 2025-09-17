//
// Created by rahul on 06-09-2025.
//
#include "../include/array.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Array {
    int* data;
    int size;
    int capacity;
};
//Array Creation
//Created by Dipanjan Aich on 15-09-2025
Array* createArray(int capacity) {
    if (capacity <= 0) {
        return NULL;
    }
    Array* arr = (Array*)malloc(sizeof(Array));
    if (arr == NULL) {
        return NULL;
    }
    arr->data = (int*)malloc(capacity * sizeof(int));
    if (arr->data == NULL) {
        free(arr);
        return NULL;
    }
    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}
//Insert a value at a specific desired index
//Created by Harsh Sangwan on 15-09-2025
void insertArray(Array* arr, int index, int value) {
    if (arr == NULL || arr->size >= arr->capacity || index < 0 || index > arr->size) {
        return;
    }
    for (int i = arr->size - 1; i >= index; i--) {
        arr->data[i + 1] = arr->data[i];
    }
    arr->data[index] = value;
    arr->size++;
}
//Delete a value from a desired specific index
//Created by Kumar Harsh on 15-09-2025
void deleteArray(Array* arr, int index) {
    if (arr == NULL || index < 0 || index >= arr->size) {
        return;
    }
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}
//Resize the array to a new capacity
int getArray(Array* arr, int index) {
    if (arr == NULL || index < 0 || index >= arr->size) {
        return INT_MIN;
    }
    return arr->data[index];
}
//Traverse the array
//Created by Gaurav Kumar Gupta on 16-09-2025
void traverseArray(Array* arr) {
    if (arr == NULL) {
        printf("Array is NULL.\n");
        return;
    }
    printf("[ ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("]\n");
}
//Resize the array to a new capacity
//Created by Dipanjan Aich on 16-09-2025
int resizeArray(Array* arr, int newCapacity) {
    if (arr == NULL || newCapacity < arr->size) {
        return 0;
    }
    int* newData = (int*)realloc(arr->data, newCapacity * sizeof(int));
    if (newData == NULL) {
        return 0;
    }
    arr->data = newData;
    arr->capacity = newCapacity;
    return 1;
}
//Free the array and internal data
void freeArray(Array* arr) {
    if (arr != NULL) {
        free(arr->data);
        free(arr);
    }
}
//Finding any duplicate in the array
//Created by Kishlay Kumar Dubey on 15-09-2025
int findDuplicatesArray(Array* arr) {
    if (arr == NULL) {
        return 0;
    }
    for (int i = 0; i < arr->size; i++) {
        for (int j = i + 1; j < arr->size; j++) {
            if (arr->data[i] == arr->data[j]) {
                return 1;
            }
        }
    }
    return 0;
}
