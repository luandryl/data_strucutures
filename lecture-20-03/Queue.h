#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct Queue {
    Node *start;
    Node *end;
    int size;
}Queue;


Queue * create () {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->start = NULL;
    q->end = NULL;
    return q;
}

void insertEnd (Queue *q, int e) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->v = e;
    n->next = NULL;

    if (q->end != NULL) {
        q->end->next = n;
        n->prev = q->end;
    } else {
        q->start = n;
        n->prev = NULL;
    }
    q->size += 1;
    q->end = n;
}

void insertStart (Queue *q, int e) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->v = e;
    n->prev = NULL;

    if (q->end != NULL) {
        q->start->prev = n;
        n->next = q->start;
    } else {
        q->end = n;
        n->next = NULL;
    }

    q->size += 1;
    q->start = n;

}

void printQueue (Queue *q) {
    
    if (q->start != NULL) {
        Node *tmp = q->start;
        while (tmp != NULL) {
            printf("[%d] \n", tmp->v);
            tmp = tmp->next;
        }
    }
}

void printInverseQueue (Queue *q) {
    
    if (q->start != NULL) {
        Node *tmp = q->end;
        while (tmp != NULL) {
            printf("[%d] \n", tmp->v);
            tmp = tmp->prev;
        }
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

int removeStartQueue (Queue *q) {

    if (q->start == NULL) {
        Node *tmp = q->start;
        int v = tmp->v;
        q->start = tmp->next;

        if (tmp->next != NULL)
            q->end = NULL;
        else 
            tmp->next->prev = NULL;
        
        q->size -= 1;
        free(tmp);

        return v;
    }

}

int removeEndQueue (Queue *q) {

      if (q->start != NULL) {
        Node *tmp = q->end;
        int v = tmp->v;
        
        q->end= tmp->prev;

        if (tmp->prev == NULL)
            q->start = NULL;
        else 
            tmp->prev->next = NULL;
        
        q->size -= 1;
        free(tmp);

        return v;
    }
}

int isDecreasingQueue (Queue *q) {
    
    if (q->start != NULL) {
        int ct = q->start->v;
        int i = 0;
        Node *tmp;

        for(tmp = q->start;tmp != NULL;tmp = tmp->next) {
            if (ct >= tmp->v) {
                ct = tmp->v;
                i += 1;
            }
        }

        return (i == q->size) ? 1 : 0;   
    }
}

int firstEvenStart (Queue *q) {
    if (q->start != NULL) {
        Node *tmp;
        for(tmp = q->start;tmp != NULL;tmp = tmp->next) {
            if ((tmp->v % 2) == 0) {
                return tmp->v;
            }
        }
    }
}

int firstEvenEnd (Queue *q) {
    if (q->start != NULL) {
        Node *tmp;
        for(tmp = q->end;tmp != NULL;tmp = tmp->prev) {
            if ((tmp->v % 2) == 0) {
                return tmp->v;
            }
        }
    }
}

int compareQueues (Queue *q1, Queue *q2) {

    if (q1->start != NULL && q2->start != NULL) {

        if (q1->size == q2->size) {

            Node *tmp1 = q1->start;
            Node *tmp2 = q2->start;
            int ctl = 0;

            while (tmp1 != NULL && tmp2 != NULL) {
                
                if (tmp1->v == tmp2->v)
                    ctl += 1;

                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }

            return (ctl == q1->size) ? 1 : 0;
        } else {
            return 0;
        }
    } else {
        return 0;
    }

}