#include <stdio.h>
#include "BST.h"

int main (int argc, char *argv[]) {

    BST * t = NewBST();
    
    for (int i = 0; i < 5; i++) {
        t = insert(t, i);
    }

    printf("%d", (t!=NULL));
    preOrder(t);
}