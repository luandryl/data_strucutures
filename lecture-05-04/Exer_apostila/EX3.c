#include <stdio.h>
#include "Student.h"


int main () {

    Student *s = NULL;

    printf("Create a list for test with add_end function: =>\n");
        s = add_end(s, 567, "Sterling Archer", 5.5, 9, 7.3, 1, 1);
        s = add_end(s, 745, "Bruce Wayne", 3.5, 5.9, 8, 0.6, 1);
        s = add_end(s, 545, "Luke Skywalker", 0, 2, 9.7, 1, 1);
        print_list(s);
    printf("\n");

    printf("Add students from postions: =>\n");
        s = add_n(s, 578, "EXAMPLE STUDENT AT POS 0", 10, 10, 9.8, 1, 1, 0);
        s = add_n(s, 578, "EXAMPLE STUDENT LAST POS", 10, 10, 9.8, 1, 1, 3);
        s = add_n(s, 578, "EXAMPLE STUDENT MIDDLE POS", 10, 10, 9.8, 1, 1, 1);
        print_list(s);
    printf("\n");
    
    printf("Remove students from postions: =>\n");
        s = remove_n(s, 2);
        s = remove_n(s, 0);
        s = remove_n(s, 3);
        print_list(s);
    printf("\n");
    /*
    
    */
    free(s);
    return 0;
}