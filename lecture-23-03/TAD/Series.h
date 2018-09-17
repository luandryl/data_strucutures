#include <stdlib.h>
#include <string.h>
#include "Util.h"

typedef struct Node{
    char name[50];
    char max_duration[50];
    struct Node *next;
} Node;

/* 
    Start List 
*/
Node * start () {
    Node * list = NULL;
    return list;
}

/* 
    Insert a new series in head of list
*/
Node * insert_serie (char name[], char duration[], Node * list) {
    Node *new = (Node *) malloc (sizeof(Node));
    strcpy(new->name, name);
    strcpy(new->max_duration, duration);
    new->next = list;
    return new;
}

/* 
    Checking if the list its empty
*/
int isEmpty (Node *list) {
    return (list == NULL);
}

/* 
    Default Printing with for
*/
void impress_series (Node *list) {
    if (list != NULL) {
        Node *h;
        printf("\nList of Series \n");
        for (h = list; h != NULL; h = h->next) {
            printf("\tName: %s\n", h->name);
            printf("\tDuration: %s\n", h->max_duration);
        }
        printf("\n");
    } else {
        printf("Empty List");
    }
}

/* 
    Recursive Printing
*/
void impress_series_recursive (Node *list) {
    Node *h = list;
    if (h != NULL) {
        printf("\tName: %s\n", h ->name);
        printf("\tDuration: %s\n", h ->max_duration);
        impress_series_recursive(h ->next);
    }
}

/* 
    Recursive inverse Printing
*/
void impress_series_recursive_inverse (Node *list) {
    Node *h = list;
    if (h != NULL) {
        impress_series_recursive_inverse(h->next);
        printf("\tName: %s\n", h->name);
        printf("\tDuration: %s\n", h->max_duration);
    }
}

/* 
    Find a element by name;
*/
int search_by_name (Node *list, char name[]) {
    if (list != NULL) {
        Node *h = list;
        return (strcmp(h->name, name) == 0) ? 1+search_by_name (h->next, name) : 0+search_by_name (h->next, name);
    }
}

/* 
    Find a element by max_duration;
*/
int search_by_duration (Node *list, char duration[]) {
    if (list != NULL) {
        Node *h = list;
        return (strcmp(h->max_duration, duration) == 0) ? 1+search_by_duration (h->next, duration) : 0+search_by_duration (h->next, duration);
    }
}
/* 
    Remove a element by its name
*/
Node * remove_by_name (Node *list, char name[]) {
    if (list != NULL) { 
        Node *tmp = list;
        Node *previous = NULL;
        
        if (compare_strings(tmp->name, name) == 0) {
            previous = tmp;
            tmp = tmp->next;
            free(previous);
            return tmp;
        } 
        while (tmp != NULL && (compare_strings(tmp->name, name) == -1)) {
            previous = tmp;
            tmp = tmp->next;
        }

        if (tmp == NULL) {
            return list;
        } else {
            previous->next = tmp->next;
        }
        
        free(tmp);
        return list;
    }
}

/* 
    Free the list of memory
*/
void free_list (Node *list) {
    Node *h = list;
    if (h != NULL) {
        Node *temp = h;
        free(h);
        free_list(temp ->next);
    }
}