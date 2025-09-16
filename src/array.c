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

void deleteArray(Array* arr, int index) {
    if (arr == NULL || index < 0 || index >= arr->size) {
        return;
    }
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

int getArray(Array* arr, int index) {
    if (arr == NULL || index < 0 || index >= arr->size) {
        return INT_MIN;
    }
    return arr->data[index];
}

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

void freeArray(Array* arr) {
    if (arr != NULL) {
        free(arr->data);
        free(arr);
    }
}

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
