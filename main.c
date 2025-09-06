#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/array.h"
#include "include/linkedlist.h"
#include "include/stack.h"
#include "include/queue.h"
#include "include/tree.h"
#include "include/sorting.h"
#include "include/hashing.h"
#include "include/graph.h"
#include "include/search.h"
#include "include/recursion.h"
#include "include/visualization.h"

void arrayMenu(Array* arr) {
    int choice, index, value;
    while (1) {
        printf("\nArray Menu\n1. Insert\n2. Delete\n3. Get\n4. Visualize\n5. Placement Problem (Find Duplicates)\n6. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter index and value: ");
                scanf("%d %d", &index, &value);
                insertArray(arr, index, value);
                visualizeArrayASCII(arr);
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                deleteArray(arr, index);
                visualizeArrayASCII(arr);
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d", &index);
                printf("Value at index %d: %d\n", index, getArray(arr, index));
                break;
            case 4:
                visualizeArrayASCII(arr);
                break;
            case 5:
                // Placeholder for placement problem
                printf("Running Find Duplicates (TBD in tests/placement_problems/array_problems.c)\n");
                break;
            case 6:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void singlyLinkedListMenu(SinglyLinkedList* ll) {
    int choice, index, value;
    while (1) {
        printf("\nSingly Linked List Menu\n1. Insert\n2. Delete\n3. Find\n4. Visualize\n5. Placement Problem (Cycle Detection)\n6. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter index and value: ");
                scanf("%d %d", &index, &value);
                insertSinglyLinkedList(ll, index, value);
                visualizeSinglyLinkedListASCII(ll);
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                deleteSinglyLinkedList(ll, index);
                visualizeSinglyLinkedListASCII(ll);
                break;
            case 3:
                printf("Enter value to find: ");
                scanf("%d", &value);
                Node* node = findSinglyLinkedList(ll, value);
                printf("Value %d %s\n", value, node ? "found" : "not found");
                break;
            case 4:
                visualizeSinglyLinkedListASCII(ll);
                break;
            case 5:
                printf("Cycle Detection: %s\n", hasCycleSinglyLinkedList(ll) ? "Cycle exists" : "No cycle");
                break;
            case 6:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void stackMenu(Stack* stack) {
    int choice, value;
    while (1) {
        printf("\nStack Menu\n1. Push\n2. Pop\n3. Peek\n4. Visualize\n5. Placement Problem (Postfix Evaluation)\n6. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(stack, value);
                visualizeStackASCII(stack);
                break;
            case 2:
                printf("Popped: %d\n", pop(stack));
                visualizeStackASCII(stack);
                break;
            case 3:
                printf("Top: %d\n", peek(stack));
                break;
            case 4:
                visualizeStackASCII(stack);
                break;
            case 5:
                printf("Enter postfix expression (e.g., 23+): ");
                char expr[100];
                scanf("%s", expr);
                printf("Result: %d\n", evaluatePostfix(expr));
                break;
            case 6:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void queueMenu(Queue* q) {
    int choice, value;
    while (1) {
        printf("\nQueue Menu\n1. Enqueue\n2. Dequeue\n3. Front\n4. Visualize\n5. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(q, value);
                visualizeQueueASCII(q);
                break;
            case 2:
                printf("Dequeued: %d\n", dequeue(q));
                visualizeQueueASCII(q);
                break;
            case 3:
                printf("Front: %d\n", front(q));
                break;
            case 4:
                visualizeQueueASCII(q);
                break;
            case 5:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void binaryTreeMenu(BinaryTree* bt, Queue* q) {
    int choice, value;
    while (1) {
        printf("\nBinary Tree Menu\n1. Insert\n2. Inorder Traversal\n3. Level-Order Traversal\n4. Visualize\n5. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBinaryTree(bt, value);
                visualizeBinaryTreeASCII(bt);
                break;
            case 2:
                traverseInorder(bt);
                break;
            case 3:
                traverseLevelOrder(bt, q);
                break;
            case 4:
                visualizeBinaryTreeASCII(bt);
                break;
            case 5:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void sortingMenu(Array* arr) {
    int choice;
    while (1) {
        printf("\nSorting Menu\n1. Quick Sort\n2. Merge Sort\n3. Visualize\n4. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                quickSort(arr);
                visualizeArrayASCII(arr);
                break;
            case 2:
                mergeSort(arr);
                visualizeArrayASCII(arr);
                break;
            case 3:
                visualizeArrayASCII(arr);
                break;
            case 4:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void searchMenu(Array* arr) {
    int choice, value;
    while (1) {
        printf("\nSearch Menu\n1. Linear Search\n2. Binary Search\n3. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Index: %d\n", linearSearch(arr, value));
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Index: %d\n", binarySearch(arr, value));
                break;
            case 3:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void hashTableMenu(HashTable* ht) {
    int choice, key, value;
    while (1) {
        printf("\nHash Table Menu\n1. Insert\n2. Search\n3. Delete\n4. Visualize\n5. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &value);
                insertHash(ht, key, value);
                visualizeSinglyLinkedListASCII(ht->buckets[key % ht->size]); // Example visualization
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Value: %d\n", searchHash(ht, key));
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteHash(ht, key);
                break;
            case 4:
                for (int i = 0; i < ht->size; i++) {
                    if (ht->buckets[i]) {
                        printf("Bucket %d: ", i);
                        visualizeSinglyLinkedListASCII(ht->buckets[i]);
                    }
                }
                break;
            case 5:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void graphMenu(Graph* g) {
    int choice, src, dest, start;
    while (1) {
        printf("\nGraph Menu\n1. Add Edge\n2. DFS\n3. BFS\n4. Visualize\n5. Placement Problem (Dijkstra)\n6. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter source and destination: ");
                scanf("%d %d", &src, &dest);
                addEdge(g, src, dest);
                visualizeGraphASCII(g);
                break;
            case 2:
                printf("Enter start vertex: ");
                scanf("%d", &start);
                dfs(g, start);
                break;
            case 3:
                printf("Enter start vertex: ");
                scanf("%d", &start);
                bfs(g, start, createQueue(g->vertices));
                break;
            case 4:
                visualizeGraphASCII(g);
                break;
            case 5:
                printf("Enter start vertex: ");
                scanf("%d", &start);
                dijkstra(g, start, createPriorityQueue());
                break;
            case 6:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void recursionMenu() {
    int choice, n;
    while (1) {
        printf("\nRecursion Menu\n1. Factorial\n2. Fibonacci\n3. Tower of Hanoi\n4. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Factorial(%d) = %d\n", n, factorial(n));
                break;
            case 2:
                printf("Enter n: ");
                scanf("%d", &n);
                printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
                break;
            case 3:
                printf("Enter number of disks: ");
                scanf("%d", &n);
                Stack* stack = createStack(n);
                towerOfHanoi(n, 'A', 'C', 'B', stack);
                freeStack(stack);
                break;
            case 4:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void mainMenu() {
    printf("\nData Structure Library\n");
    printf("1. Array\n2. Singly Linked List\n3. Stack\n4. Queue\n5. Binary Tree\n");
    printf("6. Sorting\n7. Searching\n8. Hash Table\n9. Graph\n10. Recursion\n11. Exit\n");
}

int main() {
    int choice;
    Array* arr = createArray(10);
    SinglyLinkedList* ll = createSinglyLinkedList();
    Stack* stack = createStack(10);
    Queue* q = createQueue(10);
    BinaryTree* bt = createBinaryTree();
    HashTable* ht = createHashTable(10);
    Graph* g = createGraph(5);

    while (1) {
        mainMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                arrayMenu(arr);
                break;
            case 2:
                singlyLinkedListMenu(ll);
                break;
            case 3:
                stackMenu(stack);
                break;
            case 4:
                queueMenu(q);
                break;
            case 5:
                binaryTreeMenu(bt, q);
                break;
            case 6:
                sortingMenu(arr);
                break;
            case 7:
                searchMenu(arr);
                break;
            case 8:
                hashTableMenu(ht);
                break;
            case 9:
                graphMenu(g);
                break;
            case 10:
                recursionMenu();
                break;
            case 11:
                freeArray(arr);
                freeSinglyLinkedList(ll);
                freeStack(stack);
                freeQueue(q);
                freeBinaryTree(bt);
                freeHashTable(ht);
                freeGraph(g);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}