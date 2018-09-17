#include <stdio.h>
#include "Series.h"

int main () {
    /*
        Test for Series.h LIB;
    */
    char n[50] = "Bojack Horseman";
    char d[50] = "5 temp";
    char n1[50] = "Rick and Morty";
    char d1[50] = "3 temp";
    char n2[50] = "Archer";
    char d2[50] = "8 temp";
    char n3[50] = "South Park";
    char d3[50] = "21 temp";
    
    printf("\nStart List\n");
    Node * list = start();
    list = insert_serie(n, d, list);
    list = insert_serie(n1, d1, list);
    list = insert_serie(n2, d2, list);
    list = insert_serie(n3, d3, list);

    printf("Is empty List? (0,1): %d\n", isEmpty(list));
    printf("Default Impress\n");
    impress_series(list);

    printf("Search from Bojack Horseman serie: (0,1): %d\n", search_by_name(list, n));
    printf("Search from Duration of Bojack Horseman serie: (0,1): %d\n", search_by_duration(list, d));

    printf("Removing South Park \n");
    list = remove_by_name(list, n3);
    printf("\nImpress Recursive \n");
    impress_series_recursive(list);
    printf("\nImpress Recursive Inverse \n");
    impress_series_recursive_inverse(list);
    printf("\nList Free\n");
    free_list(list);
    return 0;
}