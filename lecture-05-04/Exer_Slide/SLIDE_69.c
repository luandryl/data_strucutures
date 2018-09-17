#include <stdio.h>
#include <stdlib.h>
#include "d_linked_list.h"
int main () {

    D_linked_list *l = NULL;
	
    printf("Add at end of list \n");
    for (int i = 0; i < 10; i++) 
        l = add_end(l, i);

    print_list(l);
    printf("\n");

    printf("Add at the start of list \n");
    l = add_start(l, 50);
    print_list(l);
    printf("\n");

    printf("Remove first \n");
    l = remove_any(l, 0);
    print_list(l);
    printf("\n");
    printf("Remove last \n");
    l = remove_any(l, 9);
    print_list(l);
    printf("\n");
    printf("Remove middle \n");
    l = remove_any(l, 5);
    print_list(l);
    printf("\n");
    
    printf("Bigger element [%d]\n", bigger_element(l));
    printf("Smaller element [%d]\n", smaller_element(l));
	
	D_linked_list *l1 = NULL;
	printf("\nCreate a new sorted List \n");
	l1 = in_order(l1, 19);
	l1 = in_order(l1, 10);
	l1 = in_order(l1, 40);
	l1 = in_order(l1, 5);
	l1 = in_order(l1, 3);
	printf("Print Sorted List \n");
	traversal_print(l1);

    return 0;
}