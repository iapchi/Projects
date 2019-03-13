/*
* Structure definition(s) for a BST to store your machine opcode table.
* Function prototypes for functions related to the machine opcode table. For example:
  . Inserting a node into the table
  . Retrieving an opcode, given the instruction name
  . Retrieving the instruction format, given the instruction name
  . Printing the contents of the tree to stdout
*/

#ifndef __OPCODE_TABLE_H__
#define __OPCODE_TABLE_H__
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct BstNode {
    struct BstNode* left;
    struct BstNode* right;

    char instruction[6];
    int opcode;
    int format;
};

typedef struct BstNode BSTNode;


typedef struct BstTree {
    BSTNode* root;
} BSTTree;

BSTTree* newTree();
void insert(BSTTree* tree, char instruction[6], int opcode, int format);
void inorder(BSTTree*);
void deleteTree(BSTTree**);
int height(BSTTree* root);

BSTNode* search(BSTTree*, char instruction[6]);
int getOpCode(BSTTree*, char instruction[6]);
int getFormat(BSTTree* tree, char instruction[6], int* found) ;
#endif