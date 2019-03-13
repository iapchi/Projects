/**
opcodetable.h implementation*/
#include "opcodeTable.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



/*Private methods*/
void freeBST(BSTNode* root);
BSTNode* newBSTNode(char instruction[6], int opcode, int format);
void insertHelper(BSTNode** node, char instruction[6], int opcode, int format);
BSTNode* searchHelper(BSTNode* root, char instruction[6]);
void inorderHelper(BSTNode* root, char* isFirst);
int max(int, int);
int heightHelper(BSTNode* root);

BSTTree* newTree() {
    BSTTree* tree = calloc(1, sizeof(BSTTree));
    tree->root = NULL;
    return tree;
}

void freeBST(BSTNode* root) {
    if (root == NULL) return;
    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

void deleteTree(BSTTree** tree) {
    freeBST((*tree)->root);
    free(*tree);
    *tree = NULL;
}

BSTNode* newBSTNode(char instruction[6], int opcode, int format) {
    BSTNode* node = (BSTNode*)calloc(1, sizeof(BSTNode));
    node->left = NULL;
    node->right = NULL;
    node->opcode = opcode;
    strcpy(node->instruction, instruction);
    node->format = format;
    return node;
}

void insertHelper(BSTNode** node, char instruction[6], int opcode, int format) {
    if (*node == NULL) {
        *node = newBSTNode(instruction, opcode, format);
        return;
    }
    /* Otherwise, recur down the tree */
    int ret = strcmp((*node)->instruction, instruction);
    if (ret > 0) {
        insertHelper(&(*node)->left, instruction, opcode, format);
    }
    else if (ret < 0) {
        insertHelper(&(*node)->right, instruction, opcode, format);
    }
}

void insert(BSTTree* tree, char instruction[6], int opcode, int format) {
   insertHelper(&tree->root, instruction, opcode, format);
}


// C function to search a given key in a given BST
BSTNode* searchHelper(BSTNode* root, char instruction[6])
{
    // Base Cases: root is null or key is present at root
    if (root == NULL) {
       return root;
    }
    int res = strcmp(root->instruction, instruction);
    if (res == 0) {
        return root;
    }

    // Key is greater than root's key
    if (res < 0) {
       return searchHelper(root->right, instruction);
    }

    // Key is smaller than root's key
    return searchHelper(root->left, instruction);
}

BSTNode* search(BSTTree* tree, char instruction[6]) {
    return searchHelper(tree->root, instruction);
}

void inorderHelper(BSTNode* root, char* isFirst) {
    if (root != NULL) {
        inorderHelper(root->left, isFirst);
        if (*isFirst) {
            printf("%s", root->instruction);
            *isFirst = 0;
        }
        else
            printf (" %s", root->instruction);
        inorderHelper(root->right, isFirst);
    }
}

void inorder(BSTTree* tree) {
    char isFirst = 1;
    inorderHelper(tree->root, &isFirst);
}

int height(BSTTree* tree) {
    heightHelper(tree->root);
}

int heightHelper(BSTNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
    return 1 + max(heightHelper(root->left), heightHelper(root->right));
}

int max(int first, int second) {
    return (first > second) ? first : second;
}

int getOpCode(BSTTree* tree, char instruction[6]) {
    BSTNode* node = search(tree, instruction);
    if (node != NULL) {
        return node->opcode;
    }
    return 0;
}

int getFormat(BSTTree* tree, char instruction[6], int* found) {
    BSTNode* node = search(tree, instruction);
    if (node != NULL) {
        *found = 1;
        return node->format;
    }
    *found = 0;
}
