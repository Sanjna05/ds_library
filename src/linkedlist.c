//
// Created by rahul on 06-09-2025.
//
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Node structure definition
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev; // For doubly linked list
} Node;

// Singly Linked List structure
typedef struct SinglyLinkedList {
    Node* head;
    int size;
} SinglyLinkedList;

// Doubly Linked List structure
typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
    int size;
} DoublyLinkedList;

// Circular Linked List structure
typedef struct CircularLinkedList {
    Node* head;
    int size;
} CircularLinkedList;

// --- Singly Linked List Functions ---

SinglyLinkedList* createSinglyLinkedList() {
    SinglyLinkedList* ll = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    if (ll == NULL) return NULL;
    ll->head = NULL;
    ll->size = 0;
    return ll;
}

void insertSinglyLinkedList(SinglyLinkedList* ll, int index, int value) {
    if (index < 0 || index > ll->size) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = value;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = ll->head;
        ll->head = newNode;
    } else {
        Node* current = ll->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    ll->size++;
}

void deleteSinglyLinkedList(SinglyLinkedList* ll, int index) {
    if (index < 0 || index >= ll->size || ll->head == NULL) return;

    Node* temp;
    if (index == 0) {
        temp = ll->head;
        ll->head = ll->head->next;
    } else {
        Node* current = ll->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }
    free(temp);
    ll->size--;
}

Node* findSinglyLinkedList(SinglyLinkedList* ll, int value) {
    Node* current = ll->head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void traverseSinglyLinkedList(SinglyLinkedList* ll) {
    Node* current = ll->head;
    printf("Singly Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeSinglyLinkedList(SinglyLinkedList* ll) {
    Node* current = ll->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(ll);
}

int hasCycleSinglyLinkedList(SinglyLinkedList* ll) {
    if (ll->head == NULL) return 0;

    Node* slow = ll->head;
    Node* fast = ll->head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}

// --- Doubly Linked List Functions ---

DoublyLinkedList* createDoublyLinkedList() {
    DoublyLinkedList* dll = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (dll == NULL) return NULL;
    dll->head = NULL;
    dll->tail = NULL;
    dll->size = 0;
    return dll;
}

void insertDoublyLinkedList(DoublyLinkedList* dll, int index, int value) {
    if (index < 0 || index > dll->size) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (index == 0) {
        newNode->next = dll->head;
        if (dll->head != NULL) {
            dll->head->prev = newNode;
        }
        dll->head = newNode;
        if (dll->tail == NULL) {
            dll->tail = newNode;
        }
    } else if (index == dll->size) {
        newNode->prev = dll->tail;
        if (dll->tail != NULL) {
            dll->tail->next = newNode;
        }
        dll->tail = newNode;
    } else {
        Node* current = dll->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev != NULL) {
            current->prev->next = newNode;
        }
        current->prev = newNode;
    }
    dll->size++;
}

void deleteDoublyLinkedList(DoublyLinkedList* dll, int index) {
    if (index < 0 || index >= dll->size || dll->head == NULL) return;

    Node* temp = dll->head;
    if (index == 0) {
        dll->head = dll->head->next;
        if (dll->head != NULL) {
            dll->head->prev = NULL;
        }
        if (dll->tail == temp) {
            dll->tail = NULL;
        }
    } else {
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        if (dll->tail == temp) {
            dll->tail = temp->prev;
        }
    }
    free(temp);
    dll->size--;
}

void traverseDoublyLinkedList(DoublyLinkedList* dll) {
    Node* current = dll->head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeDoublyLinkedList(DoublyLinkedList* dll) {
    Node* current = dll->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(dll);
}

// --- Circular Linked List Functions ---

CircularLinkedList* createCircularLinkedList() {
    CircularLinkedList* cll = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    if (cll == NULL) return NULL;
    cll->head = NULL;
    cll->size = 0;
    return cll;
}

void insertCircularLinkedList(CircularLinkedList* cll, int index, int value) {
    if (index < 0 || index > cll->size) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = value;
    newNode->next = NULL;

    if (cll->head == NULL) {
        cll->head = newNode;
        newNode->next = newNode;
    } else if (index == 0) {
        newNode->next = cll->head->next;
        cll->head->next = newNode;
        cll->head = newNode;
    } else {
        Node* current = cll->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    cll->size++;
}

void deleteCircularLinkedList(CircularLinkedList* cll, int index) {
    if (index < 0 || index >= cll->size || cll->head == NULL) return;

    Node* temp;
    if (index == 0) {
        if (cll->size == 1) {
            temp = cll->head;
            cll->head = NULL;
        } else {
            temp = cll->head;
            Node* last = cll->head;
            while (last->next != cll->head) {
                last = last->next;
            }
            cll->head = cll->head->next;
            last->next = cll->head;
        }
    } else {
        Node* current = cll->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }
    free(temp);
    cll->size--;
}

void traverseCircularLinkedList(CircularLinkedList* cll) {
    if (cll->head == NULL) {
        printf("Circular Linked List: Empty\n");
        return;
    }

    Node* current = cll->head;
    printf("Circular Linked List: ");
    int count = 0;
    do {
        printf("%d -> ", current->data);
        current = current->next;
        count++;
    } while (current != cll->head && count < cll->size);
    printf("(back to head)\n");
}

void freeCircularLinkedList(CircularLinkedList* cll) {
    if (cll->head == NULL) {
        free(cll);
        return;
    }

    Node* current = cll->head->next;
    while (current != cll->head) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(cll->head);
    free(cll);
}
