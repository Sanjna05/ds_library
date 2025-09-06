//
// Created by rahul on 06-09-2025.
//

#ifndef DS_LIBRARY_QUEUE_H
#define DS_LIBRARY_QUEUE_H

// Opaque struct for Queue ADT, implementation hidden in src/queue.c
typedef struct Queue Queue;

// Creates a Queue with the specified capacity
// Parameters: capacity (maximum number of elements)
// Returns: Pointer to the created Queue, or NULL if allocation fails
Queue* createQueue(int capacity);

// Adds a value to the rear of the Queue
// Parameters: queue (Queue pointer), value (data to enqueue)
// Precondition: queue is not full
void enqueue(Queue* queue, int value);

// Removes and returns the value at the front of the Queue
// Parameters: queue (Queue pointer)
// Returns: Front value, or INT_MIN if queue is empty
int dequeue(Queue* queue);

// Returns the value at the front without removing it
// Parameters: queue (Queue pointer)
// Returns: Front value, or INT_MIN if queue is empty
int front(Queue* queue);

// Checks if the Queue is empty
// Parameters: queue (Queue pointer)
// Returns: 1 if empty, 0 otherwise
int isEmptyQueue(Queue* queue);

// Checks if the Queue is full
// Parameters: queue (Queue pointer)
// Returns: 1 if full, 0 otherwise
int isFullQueue(Queue* queue);

// Traverses the Queue, printing all elements for debugging (front to rear)
// Parameters: queue (Queue pointer)
void traverseQueue(Queue* queue);

// Frees the Queue and its internal data
// Parameters: queue (Queue pointer)
void freeQueue(Queue* queue);

// Placement problem: Reverses the Queue in-place
// Parameters: queue (Queue pointer)
void reverseQueue(Queue* queue);

#endif // DS_LIBRARY_QUEUE_H
