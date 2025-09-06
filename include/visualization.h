//
// Created by rahul on 06-09-2025.
//

#ifndef DS_LIBRARY_VISUALIZATION_H
#define DS_LIBRARY_VISUALIZATION_H

#include "array.h"      // For Array visualization
#include "linkedlist.h" // For Linked List visualization
#include "stack.h"      // For Stack visualization
#include "queue.h"      // For Queue visualization
#include "tree.h"       // For Binary Tree and BST visualization
#include "graph.h"      // For Graph visualization
#include "hashing.h"    // For Hash Table visualization

// Visualizes an Array with an optional highlighted index
// Parameters: arr (Array pointer), highlightIndex (-1 for no highlight)
void visualizeArrayASCII(Array* arr, int highlightIndex);

// Visualizes a Singly Linked List
// Parameters: list (SinglyLinkedList pointer)
void visualizeSinglyLinkedListASCII(SinglyLinkedList* list);

// Visualizes a Doubly Linked List
// Parameters: list (DoublyLinkedList pointer)
void visualizeDoublyLinkedListASCII(DoublyLinkedList* list);

// Visualizes a Stack
// Parameters: stack (Stack pointer)
void visualizeStackASCII(Stack* stack);

// Visualizes a Queue
// Parameters: queue (Queue pointer)
void visualizeQueueASCII(Queue* queue);

// Visualizes a Binary Tree or Binary Search Tree (inorder traversal or tree structure)
// Parameters: bt (BinaryTree pointer, also used for BST via casting)
void visualizeTreeASCII(BinaryTree* bt);

// Visualizes a Graph (adjacency list representation)
// Parameters: graph (Graph pointer)
void visualizeGraphASCII(Graph* graph);

// Visualizes a Hash Table (buckets with linked lists)
// Parameters: ht (HashTable pointer)
void visualizeHashTableASCII(HashTable* ht);

// Visualizes the Tower of Hanoi state (for Recursion module)
// Parameters: source, auxiliary, destination (Stack pointers for each peg)
void visualizeTowerOfHanoiASCII(Stack* source, Stack* auxiliary, Stack* destination);

#endif // DS_LIBRARY_VISUALIZATION_H
