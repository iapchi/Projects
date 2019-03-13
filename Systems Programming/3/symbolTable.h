/*
* Structure definition(s) for a hash table to store your symbol table
* Function prototypes for functions to interact with the hash table. For example:
  . Inserting a node (symbol + LC value) into the hash table
  . Retrieiving the LC value for a given symbol
  . Printing the contents of the hash table to stdout
*/

#ifndef __SYMBOL_TABLE_H__
#define __SYMBOL_TABLE_H__
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hashFunction.h"

struct node;

typedef struct node {
    int lcValue;
    char symbol[8];

    struct node* next;
} Node;

typedef struct table {
    Node** nodeList;
    int size;
} HashTable;

HashTable* newHashTable(int size);
void insertNode(HashTable* table, char symbol[8], int lcValue);
void printHashTable(HashTable* table);
void deleteHashTable(HashTable**);
int getLC(HashTable*, char symbol[8]);
Node* getNode(HashTable* table, char symbol[8]);

#endif