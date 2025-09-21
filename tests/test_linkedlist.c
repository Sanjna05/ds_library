//
// Created by rahul on 06-09-2025.
//
#include"..//src/linkedlist.c"
int main() 
{
    SinglyLinkedList* sList = createSinglyLinkedList();
    insertSinglyLinkedList(sList, 0, 10);
    insertSinglyLinkedList(sList, 1, 20);
    insertSinglyLinkedList(sList, 1, 15);
    printf("After inserting 10, 15, 20:\n");
    traverseSinglyLinkedList(sList);

    deleteSinglyLinkedList(sList, 1);
    printf("After deleting index 1 (15):\n");
    traverseSinglyLinkedList(sList);
    freeSinglyLinkedList(sList);

    DoublyLinkedList* dList = createDoublyLinkedList();
    insertDoublyLinkedList(dList, 0, 30);
    insertDoublyLinkedList(dList, 1, 40);
    insertDoublyLinkedList(dList, 1, 35);
    printf("\nAfter inserting 30, 35, 40 (doubly):\n");
    traverseDoublyLinkedList(dList);

    deleteDoublyLinkedList(dList, 2);
    printf("After deleting index 2 (40):\n");
    traverseDoublyLinkedList(dList);
    freeDoublyLinkedList(dList);

    CircularLinkedList* cList = createCircularLinkedList();
    insertCircularLinkedList(cList, 0, 50);
    insertCircularLinkedList(cList, 1, 60);
    insertCircularLinkedList(cList, 1, 55);
    printf("\nAfter inserting 50, 55, 60 (circular):\n");
    traverseCircularLinkedList(cList);

    deleteCircularLinkedList(cList, 0);
    printf("After deleting index 0 (50):\n");
    traverseCircularLinkedList(cList);
    freeCircularLinkedList(cList);

    return 0;
}
