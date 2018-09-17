#include <stdio.h>
#include <stdlib.h>

typedef struct d_linked_list{

    int v;
    struct d_linked_list *next;
    struct d_linked_list *prev;

}D_linked_list;

D_linked_list * add_start (D_linked_list *list, int v) {

    
    D_linked_list *n = (D_linked_list *) malloc(sizeof(D_linked_list));
    n->v = v;
    n->next = list;
    n->prev = NULL;
    if (list != NULL) {
        list->prev = n;
    }
    
    return n;

}

D_linked_list * add_end (D_linked_list *list, int v) {
    
    D_linked_list *n = (D_linked_list *) malloc(sizeof(D_linked_list));
    n->v = v;
    n->next = NULL;

    if (list != NULL) {

        D_linked_list *tmp = list;

        while(tmp->next != NULL) 
            tmp = tmp->next;
        
        tmp->next = n;
        n->prev = tmp;

        return list;
    } else {
        n->prev = NULL;
        return n;
    }

}

void print_list (D_linked_list *list) {

    if (list != NULL) {
        printf("[%d]\n", list->v);
        print_list(list->next);
    }

}

int biggest_element (D_linked_list * l) {
    int ctl = l->v;
    if (l != NULL) {
        D_linked_list *h = l;
        while (h != NULL) {
            if (h->v > ctl)
                ctl = h->v;

            h = h->next;
        }
        return ctl;
    }
        

}

int smallest_element (D_linked_list * l) {
    int ctl = l->v;
    if (l != NULL) {
        D_linked_list *h = l;
        while (h != NULL) {
            if (h->v < ctl)
                ctl = h->v;

            h = h->next;
        }
        return ctl;
    }
        

}


D_linked_list * remove_any (D_linked_list *list, int e) 
{

    if (list != NULL) {
        D_linked_list *tmp = list;
        
        while (tmp != NULL && tmp->v != e)
            tmp = tmp->next;
        
        if (tmp->prev == NULL) {
            list = list->next;
            list->next->prev = NULL;
        } else if (tmp->next == NULL) {
            tmp->prev->next = NULL;
        } else {
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
        } 

        free(tmp);

        return list;
    } 

}

D_linked_list * in_order (D_linked_list *list, int v) {

	if (list == NULL) {
		list = (D_linked_list *) malloc(sizeof(D_linked_list));
    	list->v = v;
    	list->next = NULL;
    	list->prev = NULL;
	} else if (v < list->v) {
		list->next = in_order(list->next, v);
	} else {
		list->prev = in_order(list->prev, v);
	}

	return list;
}

void traversal_print (D_linked_list *list) {
	if (list != NULL) {
		D_linked_list *tmp = list;
		traversal_print(tmp->next);
		printf("[%d]\n", tmp->v);
		traversal_print(tmp->prev);
	}
}