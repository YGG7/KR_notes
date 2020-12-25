//
// Created by Aurora on 2020/12/23.
//
#include "../Workspace/Hashtable.c"

void testHashTable() {
    HashTable *hashTable = createHashTable();
    if (hashTable==NULL) {
        printf("NULL hash table");
        return;
    }
    else printf("create hash table successfully");
    long cap = hashTable->capacity;
    long num = hashTable->num_node;
    long size_table = sizeof(hashTable->table);
    // only for test.
    // Take automatic variables as values is not a good idea
    putKeyValue(hashTable, "course1", "15641");
    putKeyValue(hashTable, "course2", "18613");
    putKeyValue(hashTable, "course3", "18661");
    putKeyValue(hashTable, "course4", "15640");
    putKeyValue(hashTable, "course5", "15619");

    int c1 = containsKey(hashTable, "1");
    int c2 = containsKey(hashTable, "gaegax");
    int c3 = containsKey(hashTable, "course1");
    int c4 = containsKey(hashTable, "course2");
    int c5 = containsKey(hashTable, "course3");
    int c6 = containsKey(hashTable, "course4");
    int c7 = containsKey(hashTable, "course5");

    char *v1 = (char*) getValue(hashTable, "1");
    char *v2 = (char*) getValue(hashTable, "aghozxn");
    char *v3 = (char*) getValue(hashTable, "course1");
    char *v4 = (char*) getValue(hashTable, "course3");
    char *v5 = (char*) getValue(hashTable, "course5");
    clearKeyValue(hashTable);
    printf("test over");
}