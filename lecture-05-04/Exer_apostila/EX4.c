#include <stdio.h>
#include <stdlib.h>
#include "../Exer_Slide/d_linked_list.h"

D_linked_list * order (D_linked_list *l) {

    D_linked_list *tmp = l;
    D_linked_list *arr = NULL;
    
    for (tmp = l; tmp != NULL; tmp = tmp->next) 
        arr = in_order(arr, tmp->v);

    return arr;
}

int main () {
    printf("Add at end of list => \n");
    D_linked_list *l = NULL;

    l = add_end(l, 23);
    l = add_end(l, 256);
    l = add_end(l, 128);
    l = add_end(l, 8);
    l = add_end(l, 17);
    
    print_list(l);
    printf("Order the list => \n");
    l = order(l);
    traversal_print(l);
    return 0;
}