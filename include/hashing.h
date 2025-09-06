//
// Created by rahul on 06-09-2025.
//

#ifndef DS_LIBRARY_HASHING_H
#define DS_LIBRARY_HASHING_H

#include "linkedlist.h" // Dependency on Linked List ADT for chaining

// Opaque struct for Hash Table (uses chaining for collision resolution)
typedef struct HashTable HashTable;

// Creates a Hash Table with the specified size
// Parameters: size (number of buckets)
// Returns: Pointer to the created HashTable, or NULL if allocation fails
HashTable* createHashTable(int size);

// Inserts a key into the Hash Table
// Parameters: ht (HashTable pointer), key (data to insert)
// Precondition: ht is not NULL
void insertHashTable(HashTable* ht, int key);

// Searches for a key in the Hash Table
// Parameters: ht (HashTable pointer), key (data to search)
// Returns: 1 if key exists, 0 otherwise
int searchHashTable(HashTable* ht, int key);

// Deletes a key from the Hash Table
// Parameters: ht (HashTable pointer), key (data to delete)
// Precondition: ht is not NULL
void deleteHashTable(HashTable* ht, int key);

// Placement problem: Finds the most frequent key in the Hash Table
// Parameters: ht (HashTable pointer)
// Returns: The most frequent key, or INT_MIN if the table is empty
int findMostFrequent(HashTable* ht);

// Frees the Hash Table and its buckets
// Parameters: ht (HashTable pointer)
void freeHashTable(HashTable* ht);

#endif // DS_LIBRARY_HASHING_H
