#include <stdio.h>
#include <stdlib.h>

typedef struct Student{

    int v;
    struct Student *next;
    struct Student *prev;

}Student;

Student * add_start (Student *list, int v) {

    
    Student *n = (Student *) malloc(sizeof(Student));
    n->v = v;
    n->next = list;
    n->prev = NULL;
    if (list != NULL) {
        list->prev = n;
    }
    
    return n;

}

Student * add_end (Student *list, int v) {
    
    Student *n = (Student *) malloc(sizeof(Student));
    n->v = v;
    n->next = NULL;

    if (list != NULL) {

        Student *tmp = list;

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

void print_list (Student *list) {

    if (list != NULL) {
        printf("[%d]\n", list->v);
        print_list(list->next);
    }

}

int bigger_element (Student * l) {
    int ctl = l->v;
    if (l != NULL) {
        Student *h = l;
        while (h != NULL) {
            if (h->v > ctl)
                ctl = h->v;

            h = h->next;
        }
        return ctl;
    }
        

}

int smaller_element (Student * l) {
    int ctl = l->v;
    if (l != NULL) {
        Student *h = l;
        while (h != NULL) {
            if (h->v < ctl)
                ctl = h->v;

            h = h->next;
        }
        return ctl;
    }
        

}


Student * remove_any (Student *list, int e) {

    if (list != NULL) {
        Student *tmp = list;
        
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

Student * in_order (Student *list, int v) {

	if (list == NULL) {
		list = (Student *) malloc(sizeof(Student));
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

void traversal_print (Student *list) {
	if (list != NULL) {
		Student *tmp = list;
		traversal_print(tmp->next);
		printf("[%d]\n", tmp->v);
		traversal_print(tmp->prev);
	}
}