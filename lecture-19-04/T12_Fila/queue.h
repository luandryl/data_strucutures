#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int v;
    struct Node *next;
}Node;

typedef struct Queue {
    Node *start;
    Node *end;
    int lenght;
}Queue;

Queue * create () {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->start = NULL;
    q->end = NULL;
    q->lenght = 0;

    return q;
}

void insert (Queue *q, int e) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->v = e;
    n->next = NULL;

    if (q->lenght < 10) {
        if (q->end != NULL)
            q->end->next = n;
        else
            q->start = n;

        q->end = n;
        q->lenght += 1;
    } else {
        printf("\n\nError: Max of 10 elements only\n\n");
    }
}

void printQueue (Queue *q) {
    Node *tmp = q->start;
    if (tmp != NULL)
        while (tmp != NULL){
            printf("[%d] \n", tmp->v);
            tmp = tmp->next;
        }
}

Node * search (Queue *q, int e) {
    Node *tmp;

    for (tmp = q->start; tmp != NULL; tmp = tmp->next) {
        if (tmp->v == e) 
            return tmp;
    }

    return NULL;
}

int removeQueue (Queue *q) {
    Node *tmp;
    int v;

    if (q->start != NULL) {
        tmp = q->start;
        v = tmp->v;
        q->start = tmp->next;

        if (q->start == NULL)
            q->end = NULL;

        q->lenght -= 1; 
        free(tmp);

        return v; 
    }
}

void furaFila (Queue *q, int e) {

    Node *n = (Node *) malloc (sizeof(Node));
    n->v = e;
    n->next = NULL;

    if (q->start != NULL) {
        n->next = q->start;
        q->start = n;
    } else {
        q->start = n;
        q->end = n;
    }

}