#include <stdio.h>
#include <stdlib.h>

typedef struct C_linked_list{
    int v;
    struct C_linked_list *next;
}C_linked_list;


C_linked_list * insert (C_linked_list *list, int v) {

    C_linked_list *new = (C_linked_list *) malloc(sizeof(C_linked_list));
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


void print_list(C_linked_list *list) {
    C_linked_list *tmp = list->next;
    if (list != NULL) {
        while (tmp != list) {
            printf("[%d] \n", tmp->v);
            tmp = tmp->next;
        }
    }
}


C_linked_list * remove_node (C_linked_list *list, int e) {
    if (list != NULL) {

        C_linked_list *tmp = list->next;
        C_linked_list *prev = NULL;
        
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

int biggest_element (C_linked_list * l) {
    int ctl = l->next->v;
    if (l != NULL) {
        C_linked_list *h = l->next;
        while (h != l) {
            if (h->v > ctl)
                ctl = h->v;

            h = h->next;
        }
        return ctl;
    }
        

}

int smallest_element (C_linked_list * l) {
    int ctl = l->next->v;
    
    if (l != NULL) {
        C_linked_list *h = l->next;
        while (h != l) {
            if (h->v < ctl)
                ctl = h->v;

            h = h->next;
        }
        return ctl;
    }  
}