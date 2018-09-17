#include <stdio.h>
#include "avl.h"

int main () {

    AVL *tree = startAVL();
    tree = create();
    printf("Create AVL -> tree:[%p] \n", tree);
    printf("\t Planting the tree... \n");
    printf("Its empty? (0,1) \n", isEmpty(tree->root));
    printf("\t our plant not raised yet :( \n");
    printf("Balance Factor[%d] \n", FB(tree->root));
    printf("\t because we dont have roots, the balance factor its 0 :( \n");
    printf("ADD some elements binary \n");
    //tree->root = insertBinary(tree->root, 19);
    for (int i = 0; i < 3; i++)
         tree->root = insertBinary(tree->root, i);
    printf("Balance Factor[%d] \n", FB(tree->root));
    printf("\t oh no, your litte tree its unbalanced :( \n");
    printf("\t lets find out what side \n");
   // printf("Height of left size  \t[%d] \n", height(tree->root->left));
    //printf("Height of right size \t[%d] \n", height(tree->root->right));
    printf("\t we have to balance your little tree and reorder some nodes \n");
    printf("tree:[%p] \n", tree);
    return 0;
   
   
    

    
}