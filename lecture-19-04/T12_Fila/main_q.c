#include <stdio.h>
#include "queue.h"

int main () {

    Queue *q;
    q = create();

    for(int i = 0; i < 5; i++)
        insert(q, i);
    
    printf("Create Queue \n");
    printQueue(q);
    printf("\n\n");

    Node *e = search(q, 2);
    printf("Search Node 2: [%d]\n", e->v);
    printf("\n\n");

    printf("Remove Queue \n");
    removeQueue(q);
    printQueue(q);
    printf("\n\n");

    printf("Fura Fila \n");
    furaFila(q, 10);
    printQueue(q);
    printf("\n\n");

    printf("Max of 10 spaces\n");
    q = create();

    for(int i = 0; i < 11; i++)
        insert(q, i);
    printf("Queue has no [10] element\n");
    printQueue(q);
    printf("\n\n");

    return 0;
}