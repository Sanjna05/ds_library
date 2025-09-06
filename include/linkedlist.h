//
// Created by rahul on 06-09-2025.
//

#ifndef DS_LIBRARY_LINKEDLIST_H
#define DS_LIBRARY_LINKEDLIST_H

// Opaque struct for Node, used by all Linked List variants
typedef struct Node Node;

// Opaque struct for Singly Linked List
typedef struct SinglyLinkedList SinglyLinkedList;

// Opaque struct for Doubly Linked List
typedef struct DoublyLinkedList DoublyLinkedList;

// Opaque struct for Circular Linked List
typedef struct CircularLinkedList CircularLinkedList;

// --- Singly Linked List Functions ---

// Creates an empty Singly Linked List
// Returns: Pointer to the created SinglyLinkedList, or NULL if allocation fails
SinglyLinkedList* createSinglyLinkedList();

// Inserts a value at the specified index
// Parameters: ll (SinglyLinkedList pointer), index (position to insert), value (data to insert)
// Precondition: index >= 0
void insertSinglyLinkedList(SinglyLinkedList* ll, int index, int value);

// Deletes the node at the specified index
// Parameters: ll (SinglyLinkedList pointer), index (position to delete)
// Precondition: index >= 0 and list is not empty
void deleteSinglyLinkedList(SinglyLinkedList* ll, int index);

// Finds the first node with the specified value
// Parameters: ll (SinglyLinkedList pointer), value (data to find)
// Returns: Pointer to the Node, or NULL if not found
Node* findSinglyLinkedList(SinglyLinkedList* ll, int value);

// Traverses the Singly Linked List, printing all elements for debugging
// Parameters: ll (SinglyLinkedList pointer)
void traverseSinglyLinkedList(SinglyLinkedList* ll);

// Frees the Singly Linked List and its nodes
// Parameters: ll (SinglyLinkedList pointer)
void freeSinglyLinkedList(SinglyLinkedList* ll);

// Placement problem: Detects if the Singly Linked List has a cycle
// Parameters: ll (SinglyLinkedList pointer)
// Returns: 1 if a cycle exists, 0 otherwise
int hasCycleSinglyLinkedList(SinglyLinkedList* ll);

// --- Doubly Linked List Functions ---

// Creates an empty Doubly Linked List
// Returns: Pointer to the created DoublyLinkedList, or NULL if allocation fails
DoublyLinkedList* createDoublyLinkedList();

// Inserts a value at the specified index
// Parameters: dll (DoublyLinkedList pointer), index (position to insert), value (data to insert)
// Precondition: index >= 0
void insertDoublyLinkedList(DoublyLinkedList* dll, int index, int value);

// Deletes the node at the specified index
// Parameters: dll (DoublyLinkedList pointer), index (position to delete)
// Precondition: index >= 0 and list is not empty
void deleteDoublyLinkedList(DoublyLinkedList* dll, int index);

// Traverses the Doubly Linked List forward, printing all elements
// Parameters: dll (DoublyLinkedList pointer)
void traverseDoublyLinkedList(DoublyLinkedList* dll);

// Frees the Doubly Linked List and its nodes
// Parameters: dll (DoublyLinkedList pointer)
void freeDoublyLinkedList(DoublyLinkedList* dll);

// --- Circular Linked List Functions ---

// Creates an empty Circular Linked List
// Returns: Pointer to the created CircularLinkedList, or NULL if allocation fails
CircularLinkedList* createCircularLinkedList();

// Inserts a value at the specified index
// Parameters: cll (CircularLinkedList pointer), index (position to insert), value (data to insert)
// Precondition: index >= 0
void insertCircularLinkedList(CircularLinkedList* cll, int index, int value);

// Deletes the node at the specified index
// Parameters: cll (CircularLinkedList pointer), index (position to delete)
// Precondition: index >= 0 and list is not empty
void deleteCircularLinkedList(CircularLinkedList* cll, int index);

// Traverses the Circular Linked List, printing all elements (stops after one cycle)
// Parameters: cll (CircularLinkedList pointer)
void traverseCircularLinkedList(CircularLinkedList* cll);

// Frees the Circular Linked List and its nodes
// Parameters: cll (CircularLinkedList pointer)
void freeCircularLinkedList(CircularLinkedList* cll);

#endif // DS_LIBRARY_LINKEDLIST_H
