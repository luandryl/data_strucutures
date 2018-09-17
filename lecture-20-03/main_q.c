#include <stdio.h>
#include "Queue.h"

int main () {

    Queue *q = create ();

    printf("Add end elements\n");
    for(int i = 0;i < 3;i++) 
        insertEnd(q, i);
    printQueue(q);
    printf("Add start elements\n");
    for(int i = 3;i < 6;i++) 
        insertStart(q, i);

    printQueue(q);

    printf("\n\n");

    printf("Remove start element\n");
    removeStartQueue(q);    
    printQueue(q);
    printf("Remove end element\n");
    removeStartQueue(q);    
    printQueue(q);

    printf("\n\n");

    printf("Inverse print\n");
    printInverseQueue(q);
    printf("\n\n");

    printf("Is Decreasing Queue? (0, 1): [%d]\n", isDecreasingQueue(q));
    printf("Create a decreasing queue\n");
    Queue *q1 = create();
    for(int i = 3;i > 0;i--) 
        insertEnd(q1, i);
    printQueue(q);
    printf("Is Decreasing Queue? (0, 1): [%d]\n", isDecreasingQueue(q1));
    printf("\n\n");

    printf("First Even Start of q: [%d]\n", firstEvenStart(q));
    printf("First Even End of q: [%d]\n", firstEvenEnd(q));
    printf("q: \n");
    printQueue(q);
    printf("\n\n");
    
    printf("Create two equal queues to compare \n");
    q1 = create();
    Queue *q2 = create();

    for (int i = 0; i < 10; i++) {
        insertEnd(q1, i);
        insertEnd(q2, i);
    }

    printQueue(q1);
    printf("\n");
    printQueue(q2);
    printf("Compare q1 and q2: [%d]\n", compareQueues(q1, q2));
    printf("\n\n");
    
    printf("Create two diferents queues to compare \n");
    q1 = create();
    q2 = create();

    for (int i = 0; i < 10; i++)
        insertEnd(q1, i);
    
    for (int i = 15; i > 0;i--)
        insertEnd(q2, i);

    printQueue(q1);
    printf("\n");
    printQueue(q2);
    printf("Compare q1 and q2 (0,1): [%d]\n", compareQueues(q1, q2));


    return 0;
}