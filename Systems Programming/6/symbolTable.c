#include "symbolTable.h"
#include <ctype.h>

/**
 * Create a new hash table with given table size
 */
HashTable* newHashTable(int size) {
    HashTable* table = (HashTable*)calloc(1, sizeof(HashTable));
    table->nodeList = (Node**)calloc(size, sizeof(Node*));
    table->size = size;
    return table;
}

/**
 * Insert node in a table
 */
void insertNode(HashTable* table, char symbol[6], int lcValue) {
    if (table == NULL) {
        printf ("HashTable is uninitialized.");
        return;
    }

    Node* node = (Node*)calloc(1, sizeof(Node));

    strcpy(node->symbol, symbol);
    node->lcValue = lcValue;
    /*
     * Find index using hash function
     */
    int pos = hashFunction(symbol, table->size);
    if (table->nodeList[pos] == NULL) {
        table->nodeList[pos] = node;
    } else {
        node->next = table->nodeList[pos];
        table->nodeList[pos] = node;
    }
}

/*
 * Method to print hash table
 */
void printHashTable(HashTable* table) {
    if (table == NULL) {
        printf ("HashTable is uninitialized.");
        return;
    }
    int i;
    for (i = 0; i < table->size; ++i) {
        printf ("%d: ", i);
        Node* temp = table->nodeList[i];
        while(temp != NULL) {
            printf ("(%s / %d", temp->symbol, temp->lcValue);
            printf (") -> ");
            temp = temp->next;
        }
        printf ("NULL\n");
    }
}

/*
 * Method to free hash table
 */
void deleteHashTable(HashTable** tablePtr) {
    void freeList(Node* node);

    HashTable* table = *tablePtr;
    int i;
    for (i = 0; i < table->size; ++i) {
        freeList(table->nodeList[i]);
    }
    free(table);
    *tablePtr = NULL;
}

/*
 * Method to free linked list with given node
 */
void freeList(Node* node) {
    while (node != NULL) {
        Node* temp = node->next;
        free(node);
        node = temp;
    }
}

/*
 * Method to get location value for a given symbol
 */
int getLC(HashTable* table, char symbol[6]) {
    Node* node = getNode(table, symbol);
    if (node == NULL) {
        return -1;
    }
    else {
        return node->lcValue;
    }
}

/*
 * Method to get node for a given symbol
 */
Node* getNode(HashTable* table, char symbol[6]) {
    if (table == NULL) {
        printf ("HashTable is uninitialized.");
        return NULL;
    }

    int i = hashFunction(symbol, table->size);
    Node* node = table->nodeList[i];
    while (node != NULL) {
        if (strcmp(node->symbol, symbol) == 0) {
            return node;
        }
        node = node->next;
    }

    return NULL;
}