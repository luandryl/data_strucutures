#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int v;
    struct BST *left;
    struct BST *right;
}BST;

BST * create () {
    return NULL;
}

int isEmptyTree(BST * tree) {
    return (tree == NULL);
}

BST * insert (BST * tree, int e) {

    if (isEmptyTree(tree)) {
        tree = (BST *) malloc((sizeof(BST)));
        tree->v = e;
        tree->left = NULL;
        tree->right = NULL;
    } else if (e < tree->v) {
        tree->left = insert(tree->left, e);
    } else {
        tree->right = insert(tree->right, e);
    }

    return tree;
}

void preOrder(BST * tree) {
    if (isEmptyTree(tree)) {
        printTree(tree->left);
        printf("[%d]\n", tree->v);
        printTree(tree->right);    
    }
}