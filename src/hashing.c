//
// Created by rahul on 06-09-2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node structure for chaining
typedef struct Node {
    int key;
    int count;
    struct Node* next;
} Node;

// HashTable structure
struct HashTable {
    int size;
    Node** buckets;
};

// ------------------- Helper: Hash Function -------------------
static int hash(int key, int size) {
    return abs(key) % size;
}

// ------------------- Create Hash Table -------------------
// ...  created by DEVAGYA RAI SHARMA   on   1/10/2025  ...
HashTable* createHashTable(int size) {
    if (size <= 0) return NULL;

    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    if (!ht) return NULL;

    ht->size = size;
    ht->buckets = (Node**)calloc(size, sizeof(Node*));
    if (!ht->buckets) {
        free(ht);
        return NULL;
    }

    return ht;
}

// ------------------- Insert ------------------
// ... Created by  MRIDUL SHARMA  on  1/10/2025 ...
void insertHashTable(HashTable* ht, int key) {
    if (!ht) return;

    int idx = hash(key, ht->size);
    Node* curr = ht->buckets[idx];

    // Check if key already exists, increment count
    while (curr) {
        if (curr->key == key) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }

    // Key not found, create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return; // malloc failure safety

    newNode->key = key;
    newNode->count = 1;
    newNode->next = ht->buckets[idx];
    ht->buckets[idx] = newNode;
}

// ------------------- Search -------------------
// ...Created by MEHAKDEEP KAUR on 1/10/2025 ...
int searchHashTable(HashTable* ht, int key) {
    if (!ht) return 0;

    int idx = hash(key, ht->size);
    Node* curr = ht->buckets[idx];

    while (curr) {
        if (curr->key == key) return 1;
        curr = curr->next;
    }
    return 0;
}

// ------------------- Delete -------------------
// ... Created by DIPA RANI on 1/10/2025 ...
void deleteHashTable(HashTable* ht, int key) {
    if (!ht) return;

    int idx = hash(key, ht->size);
    Node* curr = ht->buckets[idx];
    Node* prev = NULL;

    while (curr) {
        if (curr->key == key) {
            if (prev) prev->next = curr->next;
            else ht->buckets[idx] = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// ------------------- Most Frequent -------------------
// ... Created by KAMODA MEHTA on 1/10/2025 ...
int findMostFrequent(HashTable* ht) {
    if (!ht) return INT_MIN;

    int mostKey = INT_MIN, maxCount = 0;
    for (int i = 0; i < ht->size; i++) {
        Node* curr = ht->buckets[i];
        while (curr) {
            if (curr->count > maxCount) {
                maxCount = curr->count;
                mostKey = curr->key;
            }
            curr = curr->next;
        }
    }
    return mostKey; // INT_MIN if table empty
}

// ------------------- Free -------------------
// ... Created by DEVAGYA and MRIDUL on 1/10/2025 ...
void freeHashTable(HashTable* ht) {
    if (!ht) return;

    for (int i = 0; i < ht->size; i++) {
        Node* curr = ht->buckets[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(ht->buckets);
    free(ht);
}
