#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int v;
    struct BST *left;
    struct BST *right;
}BST;

BST * NewBST () {
    return NULL;
}

int isEmpty (BST *tree) {
    return (tree == NULL);
}

BST * insert (BST *tree, int e) {
    if (isEmpty(tree)) {
        tree = (BST *) malloc(sizeof(BST));
        tree->v = e;
        tree->left = tree->right = NULL;
    } else if (e < tree->v) {
        tree->left = insert (tree->left, e);
    } else {
        tree->right = insert (tree->right, e);
    }
    return tree;
}

void preOrder (BST *tree) {
    if (isEmpty(tree)) {
        preOrder(tree->left);
        printf("[%d]\n", tree->v);
        preOrder(tree->right);
    }
}