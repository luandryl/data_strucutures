#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int v;
    struct Node *next;
}Node;


Node * insert (Node *list, int v) {

    Node *new = (Node *) malloc(sizeof(Node));
    new->v = v;

    if (list == NULL) {
        list = new;
        new->next = list;
        list->next = new;
    } else {
        new->next = list->next;
        list->next = new;
    }

    return list;
}


void print_list(Node *list) {
    Node *tmp = list->next;
    if (list != NULL) {
        while (tmp != list) {
            printf("[%d] \n", tmp->v);
            tmp = tmp->next;
        }
    }
}


Node * remove_node (Node *list, int e) {
    if (list != NULL) {

        Node *tmp = list->next;
        Node *prev = NULL;
        
        while (tmp != list && tmp->v != e) {
            prev = tmp;
            tmp = tmp->next;
        }
        
        if (prev == NULL) {
            list->next = tmp->next;   
        } else {
            prev->next = tmp->next;
        }

        free(tmp);

        return list;
    }
}

float average (Node *list) {

    if (list != NULL) {
        Node *tmp = list->next;
        float sum = 0;
        int i = 0;

        for (tmp = list->next; tmp != list; tmp = tmp->next) {
            sum = sum + tmp->v;
            i += 1;
        }
        return (sum / i);
    }

}

int main () {

    Node *l = NULL;
    for (int i = 0; i < 5; i++) 
        l = insert(l, i);
    printf("create a circular list: \n");
    print_list(l);
    printf("\n\n");
    
    printf("Remove: \n");
    l = remove_node(l, 4);
    print_list(l);
    printf("\n\nAvg : [%.2f]\n", average(l));

    return 0;
}