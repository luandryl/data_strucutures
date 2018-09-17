#include <stdio.h> 
#include "libs/linked_list.h"

int main () {
    Linked_list *l = NULL;
    
    printf("Add Start :\n");
    for (int i = 0; i < 5; i++) {
        l = add_start(l, i);
    }
    print_list(l);
    printf("\n\n");
    printf("Add End :\n");
    for (int i = 15; i > 10; i--) {
        l = add_end(l, i);
    }
    print_list(l);
    printf("\n\n");
    
    printf("Biggest element: [%d]\n", biggest_element(l));
    printf("Smallest element: [%d]\n", smallest_element(l));
    printf("\n\n");
    
    printf("Remove: First, middle and Last elements :>\n");
    l = remove_any(l, 4);
    l = remove_any(l, 11);
    l = remove_any(l, 0);
    print_list(l);
    printf("\n\n");
    
    l = NULL;
    printf("Insert in order :>\n");
    for (int i = 10; i > 5; i--) {
        l = insert_in_order(l, i);
    }
    l = insert_in_order(l, 15);
    l = insert_in_order(l, 0);
    l = insert_in_order(l, 9);
    l = insert_in_order(l, 17);
    print_list(l);
    
    return 0;
}