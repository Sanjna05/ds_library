#include <stdio.h>
#include"..//src/hashing.c"

int main() {
    printf("---- Test 1: Create and Insert ----\n");  
    HashTable* ht = createHashTable(5);
    insertHashTable(ht, 10);
    insertHashTable(ht, 20);
    insertHashTable(ht, 10); // duplicate
    printf("Search 10 (should be 1): %d\n", searchHashTable(ht, 10));
    printf("Search 20 (should be 1): %d\n", searchHashTable(ht, 20));
    printHashTable(ht);

    printf("\n---- Test 2: Search ----\n");
    printf("Search 30 (not inserted, should be 0): %d\n", searchHashTable(ht, 30));

    printf("\n---- Test 3: Delete ----\n");
    deleteHashTable(ht, 10);
    printf("Search 10 after delete (should be 0): %d\n", searchHashTable(ht, 10));
    deleteHashTable(ht, 999); // non-existing key
    printf("Delete non-existing key done successfully.\n");
    printHashTable(ht);

    printf("\n---- Test 4: Most Frequent Key ----\n");
    insertHashTable(ht, 5);
    insertHashTable(ht, 5);
    insertHashTable(ht, 20);
    printf("Most Frequent (should be 5): %d\n", findMostFrequent(ht));
    printHashTable(ht);

    printf("\n---- Test 5: Collisions ----\n");
    HashTable* ht2 = createHashTable(2);
    insertHashTable(ht2, 2);  // hash 2 % 2 = 0
    insertHashTable(ht2, 4);  // hash 4 % 2 = 0
    insertHashTable(ht2, 6);  // hash 6 % 2 = 0
    printf("Search 2 (should be 1): %d\n", searchHashTable(ht2, 2));
    printf("Search 4 (should be 1): %d\n", searchHashTable(ht2, 4));
    printf("Search 6 (should be 1): %d\n", searchHashTable(ht2, 6));
    printHashTable(ht2);

    printf("\n---- Test 6: Large Number of Inserts ----\n");
    for(int i=0; i<1000; i++) insertHashTable(ht, i%10);
    printf("Most Frequent Key after 1000 inserts: %d\n", findMostFrequent(ht));
    printHashTable(ht);

    printf("\n---- Test 7: Free Table ----\n");
    freeHashTable(ht);
    freeHashTable(ht2);
    ht = NULL;
    ht2 = NULL;
    printf("Tables freed successfully.\n");

    return 0;
}
