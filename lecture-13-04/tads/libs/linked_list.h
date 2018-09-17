#include <stdio.h> 
#include <stdlib.h>

typedef struct linked_list {
    int v;
    struct linked_list *next;
} Linked_list;

void print_list (Linked_list *l) {
    if (l != NULL) {
        printf("[%d]\n", l->v);
        print_list(l->next);
    }
}

Linked_list * add_start (Linked_list *l, int e) {

    Linked_list *n  = (Linked_list *) malloc(sizeof(Linked_list));
    n->v = e;
    n->next = NULL;
    if (l != NULL) 
        n->next = l;

    return n;
}

Linked_list * add_end (Linked_list *l, int e) {

    Linked_list * n  = (Linked_list *) malloc(sizeof(Linked_list));
    n->v = e;
    n->next = NULL;

    if (l != NULL) {
        Linked_list *tmp = l;
        
        while (tmp->next != NULL) 
            tmp = tmp->next;

        tmp->next = n;
        return l;

    } else {
        return n;
    }
}

int biggest_element (Linked_list * l) {
    int ctl = l->v;
    if (l != NULL) {
        Linked_list *h = l;
        while (h != NULL) {
            if (h->v > ctl)
                ctl = h->v;

            h = h->next;
        }
        return ctl;
    }
        

}

int smallest_element (Linked_list * l) {
    int ctl = l->v;
    if (l != NULL) {
        Linked_list *h = l;
        while (h != NULL) {
            if (h->v < ctl)
                ctl = h->v;

            h = h->next;
        }
        return ctl;
    }
}

Linked_list * remove_any (Linked_list *l, int e) {

    if (l != NULL) {
        Linked_list *tmp = l;
        Linked_list *prev = NULL;

        while (tmp != NULL && (tmp->v != e)) {
            prev = tmp;
            tmp = tmp->next;
        }

        if (prev == NULL) {
            l = l->next;
        } else if (tmp->next == NULL) {
            prev->next = NULL;
        } else {
            prev->next = tmp->next;
        }
        
        free(tmp);
        return l;
    }

}


/*

    in_order Linked_list:list, int:element

    if list != NULL:
        n := new_list_element

        tmp := list
        prev := null

        while element > tmp->v :
            prev := tmp
            tmp := tmp->next
        
        if prev == null:
            n->next := list
            return n
        else if tmp->next == null:
            tmp->next = n
            return list
        else:
            prev->next := n
            n->next := tmp
            return list

    else:
        return new_list_element;
*/

Linked_list * insert_in_order (Linked_list *l, int e) {

    if (l != NULL) {

        Linked_list *n = (Linked_list *) malloc(sizeof(Linked_list));
        n->v = e;
        n->next = NULL;
        
        Linked_list *tmp = l;
        Linked_list *prev = NULL;

    
        while(tmp->next != NULL && (n->v >= tmp->v)) {
            prev = tmp;
            tmp = tmp->next;
        }

        if (prev == NULL) {
            if (e >= tmp->v){
                l->next = n;
                return l; 
            } else {
                n->next = l;
                return n;
            }
        } else if (tmp->next == NULL) {
            tmp->next = n;
            return l;
        } else {
            prev->next = n;
            n->next = tmp;
            return l;
        }
       
    } else {
        l  = (Linked_list *) malloc(sizeof(Linked_list));
        l->v = e;
        l->next = NULL;

        return l;
    }
}
