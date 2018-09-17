#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Subscribe {
    char name[50];
    int age;
    struct Subscribe *next;
}Subscribe;

typedef struct Channel {
    char name[50];
    Subscribe *sub_list;
    int views;
    int videos;
    struct Channel *next;
}Channel;

Channel * add_channel (char name[], Subscribe *sub_list, int views, int videos, Channel *list) {
    Channel *new = (Channel *) malloc (sizeof(Channel));
    strcpy(new->name, name);
    new->sub_list = sub_list;
    new->views = views;
    new->videos = videos;
    new->next = list;
    return new;
}

Subscribe * add_sub (char name[], int age, Subscribe *list) {
    Subscribe *new = (Subscribe *) malloc (sizeof(Subscribe));
    strcpy(new->name, name);
    new->age = age;
    new->next = list;
    return new;
}  

void list_channels (Channel *list){
    Channel *h = list;
    if (h != NULL) {
        printf("\tName: %s\n", h->name);
        printf("\tViews: %d\n", h->views);
        printf("\tVideos: %d\n", h->videos);
        list_channels(h->next);
    }
}

int lowest_views (Channel *list) {
    if (list != NULL) {
        Channel *tmp = list;
        int view = tmp->views;

        while (tmp != NULL) {
            if (view > tmp->views) 
                view = tmp->views;

            tmp = tmp->next;
        }

        return view;
    }
}

int most_views (Channel *list) {
    if (list != NULL) {
        Channel *tmp = list;
        int view = tmp->views;

        while (tmp != NULL) {
            if (view < tmp->views) 
                view = tmp->views;

            tmp = tmp->next;
        }

        return view;
    }
}

Channel * remove_last (Channel *list) {
    if (list != NULL) {
        Channel *tmp = list;
        Channel *previous = NULL;

        while (tmp != NULL) {
            previous = tmp;
            tmp = tmp->next;
        }

        previous->next = NULL;
        free(tmp);
        return list;
    }
}

Channel * remove_first (Channel *list) {
    if (list != NULL) {
        Channel *tmp = list->next;
        free(list);
        return tmp;
    }
}

void subscribers_list (Channel * list) {
    Channel *tmp = list;

    if (tmp !=  NULL) { 
        Subscribe *sub_tmp = tmp->sub_list;
        Subscribe *h;
        int i = 0;

        for (h = sub_tmp; h != NULL; h = h->next) 
            i = i+1;
            
        printf("Channel [%s] \tSubs [%d]\n", tmp->name, i);
        
        subscribers_list(tmp->next);
    }

}
