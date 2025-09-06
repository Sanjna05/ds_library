#include <stdio.h>
#include <limits.h>
#include "include/array.h"
#include "include/linkedlist.h"
#include "include/stack.h"
#include "include/queue.h"
#include "include/search.h"
#include "include/sorting.h"
#include "include/recursion.h"
#include "include/tree.h"
#include "include/graph.h"
#include "include/hashing.h"
#include "include/visualization.h"

void arrayMenu(Array* arr) {
    int choice, index, value;
    while (1) {
        printf("\nArray Menu\n");
        printf("1. Insert\n2. Delete\n3. Access\n4. Visualize\n5. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter index and value: ");
                scanf("%d %d", &index, &value);
                insertArray(arr, index, value);
                visualizeArrayASCII(arr, -1);
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                deleteArray(arr, index);
                visualizeArrayASCII(arr, -1);
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d", &index);
                printf("Value at index %d: %d\n", index, getArray(arr, index));
                break;
            case 4:
                visualizeArrayASCII(arr, -1);
                break;
            case 5:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void linkedListMenu() {
    SinglyLinkedList* sll = createSinglyLinkedList();
    DoublyLinkedList* dll = createDoublyLinkedList();
    int choice, index, value;
    while (1) {
        printf("\nLinked List Menu\n");
        printf("1. Insert Singly Linked List\n2. Delete Singly Linked List\n3. Insert Doubly Linked List\n");
        printf("4. Delete Doubly Linked List\n5. Visualize Singly Linked List\n6. Visualize Doubly Linked List\n7. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter index and value: ");
                scanf("%d %d", &index, &value);
                insertSinglyLinkedList(sll, index, value);
                visualizeSinglyLinkedListASCII(sll);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteSinglyLinkedList(sll, value);
                visualizeSinglyLinkedListASCII(sll);
                break;
            case 3:
                printf("Enter index and value: ");
                scanf("%d %d", &index, &value);
                insertDoublyLinkedList(dll, index, value);
                visualizeDoublyLinkedListASCII(dll);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteDoublyLinkedList(dll, value);
                visualizeDoublyLinkedListASCII(dll);
                break;
            case 5:
                visualizeSinglyLinkedListASCII(sll);
                break;
            case 6:
                visualizeDoublyLinkedListASCII(dll);
                break;
            case 7:
                freeSinglyLinkedList(sll);
                freeDoublyLinkedList(dll);
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void stackMenu() {
    Stack* stack = createStack(10);
    int choice, value;
    while (1) {
        printf("\nStack Menu\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Visualize\n5. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
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
                freeStack(stack);
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void queueMenu() {
    Queue* queue = createQueue(10);
    int choice, value;
    while (1) {
        printf("\nQueue Menu\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Visualize\n5. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                visualizeQueueASCII(queue);
                break;
            case 2:
                printf("Dequeued: %d\n", dequeue(queue));
                visualizeQueueASCII(queue);
                break;
            case 3:
                printf("Front: %d\n", peekQueue(queue));
                break;
            case 4:
                visualizeQueueASCII(queue);
                break;
            case 5:
                freeQueue(queue);
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void searchMenu(Array* arr) {
    int choice, value;
    while (1) {
        printf("\nSearch Menu\n");
        printf("1. Linear Search\n2. Binary Search\n3. Visualize\n4. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to search: ");
                scanf("%d", &value);
                printf("Linear Search result: %d\n", linearSearch(arr, value));
                visualizeArrayASCII(arr, linearSearch(arr, value));
                break;
            case 2:
                printf("Enter value to search (array must be sorted): ");
                scanf("%d", &value);
                printf("Binary Search result: %d\n", binarySearch(arr, value));
                visualizeArrayASCII(arr, binarySearch(arr, value));
                break;
            case 3:
                visualizeArrayASCII(arr, -1);
                break;
            case 4:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void sortingMenu(Array* arr) {
    int choice;
    while (1) {
        printf("\nSorting Menu\n");
        printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Quick Sort\n");
        printf("5. Merge Sort\n6. Counting Sort\n7. Heap Sort\n8. Sort and Remove Duplicates\n9. Visualize\n10. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                bubbleSort(arr);
                visualizeArrayASCII(arr, -1);
                break;
            case 2:
                selectionSort(arr);
                visualizeArrayASCII(arr, -1);
                break;
            case 3:
                insertionSort(arr);
                visualizeArrayASCII(arr, -1);
                break;
            case 4:
                quickSort(arr);
                visualizeArrayASCII(arr, -1);
                break;
            case 5:
                mergeSort(arr);
                visualizeArrayASCII(arr, -1);
                break;
            case 6:
                countingSort(arr);
                visualizeArrayASCII(arr, -1);
                break;
            case 7:
                heapSort(arr);
                visualizeArrayASCII(arr, -1);
                break;
            case 8:
                printf("Unique elements: %d\n", sortAndRemoveDuplicates(arr));
                visualizeArrayASCII(arr, -1);
                break;
            case 9:
                visualizeArrayASCII(arr, -1);
                break;
            case 10:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void recursionMenu() {
    int n, choice;
    int moveCount = 0;
    Stack* source = createStack(10);
    Stack* auxiliary = createStack(10);
    Stack* destination = createStack(10);
    while (1) {
        printf("\nRecursion Menu\n");
        printf("1. Factorial\n2. Fibonacci\n3. Tower of Hanoi\n4. Visualize Towers\n5. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter n for factorial: ");
                scanf("%d", &n);
                printf("Factorial(%d) = %d\n", n, factorial(n));
                break;
            case 2:
                printf("Enter n for Fibonacci: ");
                scanf("%d", &n);
                printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
                break;
            case 3:
                printf("Enter number of disks for Tower of Hanoi: ");
                scanf("%d", &n);
                moveCount = 0;
                for (int i = n; i >= 1; i--) push(source, i);
                towerOfHanoi(n, source, auxiliary, destination, &moveCount);
                printf("Completed Tower of Hanoi in %d moves\n", moveCount);
                visualizeTowerOfHanoiASCII(source, auxiliary, destination);
                break;
            case 4:
                visualizeTowerOfHanoiASCII(source, auxiliary, destination);
                break;
            case 5:
                freeStack(source);
                freeStack(auxiliary);
                freeStack(destination);
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void treeMenu() {
    BinaryTree* bt = createBinaryTree();
    BinarySearchTree* bst = createBinarySearchTree();
    int choice, value, parentValue, isLeft, value1, value2;
    while (1) {
        printf("\nTree Menu\n");
        printf("1. Insert into Binary Tree\n2. Delete from Binary Tree\n3. Inorder Traversal (BT)\n");
        printf("4. Preorder Traversal (BT)\n5. Postorder Traversal (BT)\n6. Level-Order Traversal (BT)\n");
        printf("7. Insert into BST\n8. Delete from BST\n9. Inorder Traversal (BST)\n");
        printf("10. Find Lowest Common Ancestor (BST)\n11. Visualize Tree\n12. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter parent value (or -1 for root), value to insert, isLeft (1/0): ");
                scanf("%d %d %d", &parentValue, &value, &isLeft);
                insertBinaryTree(bt, parentValue, value, isLeft);
                visualizeTreeASCII(bt);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteBinaryTree(bt, value);
                visualizeTreeASCII(bt);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversalBinaryTree(bt);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorderTraversalBinaryTree(bt);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorderTraversalBinaryTree(bt);
                printf("\n");
                break;
            case 6:
                printf("Level-Order Traversal: ");
                levelOrderTraversalBinaryTree(bt);
                printf("\n");
                break;
            case 7:
                printf("Enter value to insert into BST: ");
                scanf("%d", &value);
                insertBinarySearchTree(bst, value);
                visualizeTreeASCII((BinaryTree*)bst);
                break;
            case 8:
                printf("Enter value to delete from BST: ");
                scanf("%d", &value);
                deleteBinarySearchTree(bst, value);
                visualizeTreeASCII((BinaryTree*)bst);
                break;
            case 9:
                printf("Inorder Traversal (BST): ");
                inorderTraversalBinarySearchTree(bst);
                printf("\n");
                break;
            case 10:
                printf("Enter two values to find LCA: ");
                scanf("%d %d", &value1, &value2);
                printf("LCA: %d\n", findLowestCommonAncestor(bst, value1, value2));
                break;
            case 11:
                printf("Binary Tree: ");
                visualizeTreeASCII(bt);
                printf("BST: ");
                visualizeTreeASCII((BinaryTree*)bst);
                break;
            case 12:
                freeBinaryTree(bt);
                freeBinarySearchTree(bst);
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void graphMenu() {
    int numVertices, isDirected, src, dest, startVertex;
    printf("Enter number of vertices and isDirected (1/0): ");
    scanf("%d %d", &numVertices, &isDirected);
    Graph* graph = createGraph(numVertices, isDirected);
    int choice;
    while (1) {
        printf("\nGraph Menu\n");
        printf("1. Add Edge\n2. BFS\n3. DFS\n4. Detect Cycle (Undirected)\n5. Visualize\n6. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                visualizeGraphASCII(graph);
                break;
            case 2:
                printf("Enter start vertex for BFS: ");
                scanf("%d", &startVertex);
                printf("BFS: ");
                bfs(graph, startVertex);
                printf("\n");
                break;
            case 3:
                printf("Enter start vertex for DFS: ");
                scanf("%d", &startVertex);
                printf("DFS: ");
                dfs(graph, startVertex);
                printf("\n");
                break;
            case 4:
                if (isDirected) {
                    printf("Cycle detection only for undirected graphs!\n");
                } else {
                    printf("Cycle exists: %d\n", detectCycle(graph));
                }
                break;
            case 5:
                visualizeGraphASCII(graph);
                break;
            case 6:
                freeGraph(graph);
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void hashingMenu() {
    int size, key, choice;
    printf("Enter number of buckets for Hash Table: ");
    scanf("%d", &size);
    HashTable* ht = createHashTable(size);
    while (1) {
        printf("\nHashing Menu\n");
        printf("1. Insert Key\n2. Search Key\n3. Delete Key\n4. Find Most Frequent Key\n5. Visualize\n6. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insertHashTable(ht, key);
                visualizeHashTableASCII(ht);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                printf("Key %d exists: %d\n", key, searchHashTable(ht, key));
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteHashTable(ht, key);
                visualizeHashTableASCII(ht);
                break;
            case 4:
                printf("Most frequent key: %d\n", findMostFrequent(ht));
                break;
            case 5:
                visualizeHashTableASCII(ht);
                break;
            case 6:
                freeHashTable(ht);
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

int main() {
    Array* arr = createArray(10);
    int choice;
    while (1) {
        printf("\nMain Menu\n");
        printf("1. Array\n2. Linked List\n3. Stack\n4. Queue\n5. Search\n6. Sorting\n");
        printf("7. Recursion\n8. Tree\n9. Graph\n10. Hashing\n11. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: arrayMenu(arr); break;
            case 2: linkedListMenu(); break;
            case 3: stackMenu(); break;
            case 4: queueMenu(); break;
            case 5: searchMenu(arr); break;
            case 6: sortingMenu(arr); break;
            case 7: recursionMenu(); break;
            case 8: treeMenu(); break;
            case 9: graphMenu(); break;
            case 10: hashingMenu(); break;
            case 11:
                freeArray(arr);
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}