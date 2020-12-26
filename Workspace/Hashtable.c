//
// Created by Aurora on 2020/12/22.
//
#define HASH_SIZE 101
/**
 * defines a hash table with fixed size
 * not thread-safe
 * every node stores duplicates of key and hash code, and reference of value
 * put() always try to return the newest value
 */

typedef struct Node {
    // store the hash code to avoid re-hash
    // when the hash table need to grow
    unsigned long hash_code;
    struct Node *next;
    void *value;
//    char key[];
    char *key; // avoid to use flexible array member
} Node;

typedef struct HashTable {
    unsigned long capacity;
    unsigned long num_node;
    Node **table; // a node pointer array
} HashTable;

// hash function djb2 by Dan Bernstein
static unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

// free a list of Nodes recursively
// may lead to recursion too deep
static void freeNodeList(Node *head_np) {
    if (head_np == NULL) return;
    freeNodeList(head_np->next);
    free(head_np);
}

HashTable *createHashTable() {
    HashTable *hashTable = malloc(sizeof(HashTable));
    if (!hashTable) return NULL;
    hashTable->capacity = HASH_SIZE;
    hashTable->num_node = 0;
    if ((hashTable->table = malloc(sizeof(Node *) * hashTable->capacity)) == NULL) {
        free(hashTable->table);
        free(hashTable);
        return NULL;
    }

    for (int i = 0; i < hashTable->capacity; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

int containsKey(HashTable *table, char *k) {
    if (table == NULL || k == NULL) return 0;
    unsigned long index = hash(k) % table->capacity;
    Node *np = table->table[index];
    while (np != NULL) {
        if (!strcmp(np->key, k)) {
            return 1;
        }
        np = np->next;
    }
    return 0;
}

void *putKeyValue(HashTable *table, char *k, void *v) {
    if (table == NULL || k == NULL) return NULL;
    unsigned long index = hash(k) % table->capacity;
    Node *np = table->table[index];
    while (np != NULL) {
        // if the key exists, update value and return the new value
        if (!strcmp(np->key, k)) {
            np->value = v;
            return np->value;
        }
        np = np->next;
    }

    // if program reaches here, we need to add a new node
    Node *newNode = malloc(sizeof(Node));
    // cannot copy a string into a char pointer that has not been allocated enough space
    newNode->key = malloc(sizeof(char) * strlen(k));
    strcpy(newNode->key, k);
    newNode->value = v;
    newNode->hash_code = hash(k);
    newNode->next = table->table[index];
    table->table[index] = newNode;
    table->num_node++;
    return newNode;
}


void *getValue(HashTable *table, char *k) {
    if (table == NULL || k == NULL) return NULL;
    unsigned long index = hash(k) % table->capacity;
    Node *np = table->table[index];
    while (np != NULL) {
        if (!strcmp(np->key, k)) {
            return np->value;
        }
        np = np->next;
    }
    return NULL;
}

// remove the node specified by key, and return the value
void *removeKeyValue(HashTable *table, char *k) {
    if (table == NULL || k == NULL) return NULL;
    unsigned long index = hash(k) % table->capacity;
    Node *np = table->table[index];
    Node *prev_np = NULL;
    while (np != NULL) {
        if (!strcmp(np->key, k)) {
            void *value = np->value;
            if (prev_np == NULL) {
                table->table[index] = np->next;
            } else {
                prev_np->next = np->next;
            }
            free(np); // we add every nodes by malloc
            table->num_node--;
            return value;
        }
        prev_np = np;
        np = np->next;
    }
    return NULL;
}

void clearKeyValue(HashTable *table) {
    for (long i = 0; i < table->capacity; i++) {
        freeNodeList(table->table[i]);
    }
    table->num_node = 0;
}

