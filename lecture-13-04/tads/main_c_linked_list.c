#include <stdio.h> 
#include "libs/c_linked_list.h"

int main () {

    C_linked_list * l = NULL;
    
    printf("create a circular list: \n");
    for (int i = 15; i > 0; i --)
        l = insert(l, i);

    printf("\n\n");
    print_list(l);

    printf("Biggest element: [%d]\n", biggest_element(l));
    printf("Smallest element: [%d]\n", smallest_element(l));
    printf("\n\n");
    
    printf("Remove: First, middle and Last elements :>\n");
    l = remove_node(l, 14);
    l = remove_node(l, 7);
    l = remove_node(l, 1);
    print_list(l);
    printf("\n\n");
    
    return 0;
}