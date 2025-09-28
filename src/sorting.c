//
// Created by rahul on 06-09-2025.
//
#include <stdio.h>
#include <stdlib.h>

// -------------------- Array ADT --------------------
typedef struct {
    int *data;
    int size;
} Array;

// Utility to print the array
void printArray(const Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

// -------------------- Bubble Sort --------------------
//Created by - Prakash Tiwari on 28-09-25
void bubbleSort(Array *arr) {
    if (!arr || arr->size <= 1) return;
    for (int i = 0; i < arr->size - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (arr->data[j] > arr->data[j + 1]) {
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

// -------------------- Selection Sort --------------------
//Created by - Prakash Tiwari on 28-09-25
void selectionSort(Array *arr) {
    if (!arr || arr->size <= 1) return;
    for (int i = 0; i < arr->size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < arr->size; j++)
            if (arr->data[j] < arr->data[minIndex])
                minIndex = j;
        if (minIndex != i) {
            int temp = arr->data[i];
            arr->data[i] = arr->data[minIndex];
            arr->data[minIndex] = temp;
        }
    }
}

// -------------------- Insertion Sort --------------------
////Created by - Prakash Tiwari on 28-09-25
void insertionSort(Array *arr) {
    if (!arr || arr->size <= 1) return;
    for (int i = 1; i < arr->size; i++) {
        int key = arr->data[i];
        int j = i - 1;
        while (j >= 0 && arr->data[j] > key) {
            arr->data[j + 1] = arr->data[j];
            j--;
        }
        arr->data[j + 1] = key;
    }
}

// -------------------- Quick Sort --------------------
//Created by - Piyush Kumar on 28-09-25
static void quickSortHelper(int *data, int low, int high) {
    if (low < high) {
        int pivot = data[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (data[j] <= pivot) {
                i++;
                int tmp = data[i]; data[i] = data[j]; data[j] = tmp;
            }
        }
        int tmp = data[i + 1]; data[i + 1] = data[high]; data[high] = tmp;
        int p = i + 1;
        quickSortHelper(data, low, p - 1);
        quickSortHelper(data, p + 1, high);
    }
}
void quickSort(Array *arr) {
    if (!arr || arr->size <= 1) return;
    quickSortHelper(arr->data, 0, arr->size - 1);
}

// -------------------- Merge Sort --------------------
//Created by - Sahil Ahmad on 28-09-25
static void merge(int *data, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = data[left + i];
    for (int j = 0; j < n2; j++) R[j] = data[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) data[k++] = L[i++];
        else data[k++] = R[j++];
    }
    while (i < n1) data[k++] = L[i++];
    while (j < n2) data[k++] = R[j++];
    free(L); free(R);
}
static void mergeSortHelper(int *data, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(data, left, mid);
        mergeSortHelper(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}
void mergeSort(Array *arr) {
    if (!arr || arr->size <= 1) return;
    mergeSortHelper(arr->data, 0, arr->size - 1);
}

// -------------------- Counting Sort (non-negative) --------------------
//Created by - Prince Sagwal on 28-09-25
void countingSort(Array *arr) {
    if (!arr || arr->size <= 1) return;
    int max = arr->data[0];
    for (int i = 1; i < arr->size; i++)
        if (arr->data[i] > max) max = arr->data[i];

    int *count = calloc(max + 1, sizeof(int));
    for (int i = 0; i < arr->size; i++)
        count[arr->data[i]]++;

    int idx = 0;
    for (int i = 0; i <= max; i++)
        while (count[i]-- > 0)
            arr->data[idx++] = i;
    free(count);
}

// -------------------- Heap Sort --------------------
//Created by Sahil Ahmad on 28-09-25
static void heapify(int *data, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && data[left] > data[largest]) largest = left;
    if (right < n && data[right] > data[largest]) largest = right;
    if (largest != i) {
        int tmp = data[i]; data[i] = data[largest]; data[largest] = tmp;
        heapify(data, n, largest);
    }
}
void heapSort(Array *arr) {
    if (!arr || arr->size <= 1) return;
    for (int i = arr->size/2 - 1; i >= 0; i--) heapify(arr->data, arr->size, i);
    for (int i = arr->size - 1; i >= 0; i--) {
        int tmp = arr->data[0]; arr->data[0] = arr->data[i]; arr->data[i] = tmp;
        heapify(arr->data, i, 0);
    }
}

// -------------------- Sort & Remove Duplicates --------------------
//Created by Raghav Dadwal on 28-09-25
int sortAndRemoveDuplicates(Array *arr) {
    if (!arr || arr->size == 0) return 0;
    quickSort(arr);  // sort first
    int uniqueIndex = 0;
    for (int i = 1; i < arr->size; i++) {
        if (arr->data[i] != arr->data[uniqueIndex]) {
            uniqueIndex++;
            arr->data[uniqueIndex] = arr->data[i];
        }
    }
    arr->size = uniqueIndex + 1;
    return arr->size;
}

