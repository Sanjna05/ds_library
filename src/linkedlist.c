<<<<<<< HEAD
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
=======
#include <stdio.h>
#include <stdlib.h>


typedef struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node; // created by divya


typedef struct 
{
    Node* head;
    int size;
} SinglyLinkedList; // created by divya


typedef struct 
{
    Node* head;
    Node* tail;
    int size;
} DoublyLinkedList; // created by divya


typedef struct 
{
    Node* head;
    int size;
} CircularLinkedList; // created by divya


SinglyLinkedList* createSinglyLinkedList() 
{
    SinglyLinkedList* list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    if (!list) return NULL;
    list->head = NULL;
    list->size = 0;
    return list;
} // created by divya


void insertSinglyLinkedList(SinglyLinkedList* list, int index, int value) 
{
    if (!list || index < 0 || index > list->size) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->data = value;
    newNode->next = NULL;
    if (index == 0) 
    {
        newNode->next = list->head;
        list->head = newNode;
    } 
    else 
    {
        Node* current = list->head;
        for (int i = 0; i < index - 1; i++) 
        {
>>>>>>> d57cb21 (Created by Divya,Keshav,Jatin,Kartik,Dhruv)
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
<<<<<<< HEAD
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
=======
    list->size++;
} // created by divya


void deleteSinglyLinkedList(SinglyLinkedList* list, int index) 
{
    if (!list || index < 0 || index >= list->size) return;
    Node* temp;
    if (index == 0) 
    {
        temp = list->head;
        list->head = list->head->next;
    } else 
    {
        Node* current = list->head;
        for (int i = 0; i < index - 1; i++) 
        {
>>>>>>> d57cb21 (Created by Divya,Keshav,Jatin,Kartik,Dhruv)
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }
    free(temp);
<<<<<<< HEAD
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
=======
    list->size--;
} // created by divya


void traverseSinglyLinkedList(SinglyLinkedList* list) 
{
    printf("Singly Linked List: ");
    Node* current = list->head;
    while (current) 
    {
>>>>>>> d57cb21 (Created by Divya,Keshav,Jatin,Kartik,Dhruv)
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
<<<<<<< HEAD
}

void freeSinglyLinkedList(SinglyLinkedList* ll) {
    Node* current = ll->head;
    while (current != NULL) {
=======
} // created by divya


int hasCycleSinglyLinkedList(SinglyLinkedList* list) 
{
    if (!list || !list->head) return 0;
    Node* slow = list->head;
    Node* fast = list->head;
    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
} // created by divya


void freeSinglyLinkedList(SinglyLinkedList* list) {
    if (!list) return;
    Node* current = list->head;
    while (current) 
    {
>>>>>>> d57cb21 (Created by Divya,Keshav,Jatin,Kartik,Dhruv)
        Node* temp = current;
        current = current->next;
        free(temp);
    }
<<<<<<< HEAD
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
=======
    free(list);
} // created by divya


DoublyLinkedList* createDoublyLinkedList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (!list) return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
} // created by divya


void insertDoublyLinkedList(DoublyLinkedList* list, int index, int value) 
{
    if (!list || index < 0 || index > list->size) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (index == 0) 
    {
        newNode->next = list->head;
        if (list->head) list->head->prev = newNode;
        list->head = newNode;
        if (!list->tail) list->tail = newNode;
    } 
    else if (index == list->size) 
    {
        newNode->prev = list->tail;
        if (list->tail) list->tail->next = newNode;
        list->tail = newNode;
    } 
    else 
    {
        Node* current = list->head;
        for (int i = 0; i < index; i++) current = current->next;
        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev) current->prev->next = newNode;
        current->prev = newNode;
    }
    list->size++;
} // created by keshav


void deleteDoublyLinkedList(DoublyLinkedList* list, int index) {
    if (!list || index < 0 || index >= list->size) return;
    Node* temp = list->head;
    if (index == 0) 
    {
        temp = list->head;
        list->head = list->head->next;
        if (list->head) list->head->prev = NULL;
        if (list->tail == temp) list->tail = NULL;
    } 
    else 
    {
        for (int i = 0; i < index; i++) temp = temp->next;
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        if (list->tail == temp) list->tail = temp->prev;
    }
    free(temp);
    list->size--;
} // created by keshav


void traverseDoublyLinkedList(DoublyLinkedList* list) 
{
    printf("Doubly Linked List: ");
    Node* current = list->head;
    while (current) 
    {
>>>>>>> d57cb21 (Created by Divya,Keshav,Jatin,Kartik,Dhruv)
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
<<<<<<< HEAD
}

void freeDoublyLinkedList(DoublyLinkedList* dll) {
    Node* current = dll->head;
    while (current != NULL) {
=======
} // created by dhruv


void freeDoublyLinkedList(DoublyLinkedList* list) 
{
    if (!list) return;
    Node* current = list->head;
    while (current) 
    {
>>>>>>> d57cb21 (Created by Divya,Keshav,Jatin,Kartik,Dhruv)
        Node* temp = current;
        current = current->next;
        free(temp);
    }
<<<<<<< HEAD
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
=======
    free(list);
} // created by dhruv


CircularLinkedList* createCircularLinkedList() 
{
    CircularLinkedList* list = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    if (!list) return NULL;
    list->head = NULL;
    list->size = 0;
    return list;
} // created by kartik


void insertCircularLinkedList(CircularLinkedList* list, int index, int value) 
{
    if (!list || index < 0 || index > list->size) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->data = value;
    if (!list->head) 
    {
        list->head = newNode;
        newNode->next = newNode;
    } 
    else 
    {
        Node* current = list->head;
        for (int i = 0; i < index - 1; i++) current = current->next;
        newNode->next = current->next;
        current->next = newNode;
        if (index == 0) list->head = newNode;
    }
    list->size++;
} // created by kartik


void deleteCircularLinkedList(CircularLinkedList* list, int index) {
    if (!list || index < 0 || index >= list->size) return;
    Node* temp;
    if (index == 0) 
    {
        if (list->size == 1) 
        {
            temp = list->head;
            list->head = NULL;
        } 
        else 
        {
            temp = list->head;
            Node* last = list->head;
            while (last->next != list->head) last = last->next;
            list->head = list->head->next;
            last->next = list->head;
        }
    } else 
    {
        Node* current = list->head;
        for (int i = 0; i < index - 1; i++) current = current->next;
>>>>>>> d57cb21 (Created by Divya,Keshav,Jatin,Kartik,Dhruv)
        temp = current->next;
        current->next = temp->next;
    }
    free(temp);
<<<<<<< HEAD
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
=======
    list->size--;
} // created by jatin


void traverseCircularLinkedList(CircularLinkedList* list) 
{
    if (!list || !list->head) 
    {
        printf("Circular Linked List: Empty\n");
        return;
    }
    Node* current = list->head;
    printf("Circular Linked List: ");
    int count = 0;
    do 
    {
        printf("%d -> ", current->data);
        current = current->next;
        count++;
    } 
    while (current != list->head && count < list->size);
    printf("(back to head)\n");
} // created by jatin


void freeCircularLinkedList(CircularLinkedList* list) {
    if (!list || !list->head) 
    {
        free(list);
        return;
    }
    Node* current = list->head->next;
    while (current != list->head) 
    {
>>>>>>> d57cb21 (Created by Divya,Keshav,Jatin,Kartik,Dhruv)
        Node* temp = current;
        current = current->next;
        free(temp);
    }
<<<<<<< HEAD
    free(cll->head);
    free(cll);
}
=======
    free(list->head);
    free(list);
} // created by keshav
>>>>>>> d57cb21 (Created by Divya,Keshav,Jatin,Kartik,Dhruv)
