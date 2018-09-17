#include <stdio.h>
#include "stack.h"


int main () {

    Stack *s = create ();
    printf("Create new stack \n");
    for (int i = 0; i < 5; i++) 
        push (s, i);
    display(s);
    
    printf("\n");

    printf("Search element:[%d]\n", search(s, 2));

    printf("\n");

    printf("Pop element: \n");
    pop(s);
    display(s);

    printf("\n");

    printf("Its a growing Stack? (0,1):[%d]\n", growingStack(s));
    printf("Inverse the stack: \n");
    s = inverse(s);
    display(s);
    printf("Its a growing Stack? (0,1):[%d]\n", growingStack(s));
    
    printf("\n");

    printf("Amount of Prime Numbers on Stack: [%d]\n", amountPrimeNumbersOnStack(s));
    
    printf("\n");

    printf("Equal Stacks ? (0,1):[%d]\n", equalStacks(s, s));
    return 0;
}