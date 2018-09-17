#include <stdio.h>
#include <string.h>
#include "youtube.h"
#include "Util.h"

int print_menu () {
    printf("Menu: \n");
    printf("\t1-Add channel\n");
    printf("\t2-List Channel\n");
    printf("\t3-Channel with most of views\n");
    printf("\t4-Channel with the lowest of views\n");
    printf("\t5-Remove last channel of the list\n");
    printf("\t6-Remove first channel of the listn\n");
    printf("\t7-Subscribes of each channel\n");
    int menu_opt;
    scanf("%d", &menu_opt);
    return menu_opt;
}


Subscribe * new_sub () {
    Subscribe *list_sub = NULL;
    char anwser[2];
    do {
        char name[50];
        int age;
        printf("Add Sub\n");
        printf("\tName:\n");
        scanf("%s", name);
        printf("\tAge:\n");
        scanf("%d", &age);
    
        list_sub = add_sub(name, age, list_sub);

        printf("Add more sub(y,n)? \n");
        scanf("%s", anwser);

    } while(compare_strings(anwser, "y") != -1);
    
    return list_sub;
}

Channel * new_channel (Channel *list) {
    char name[50];
    int views;
    int videos;

    Subscribe* s_list =  new_sub();

    printf("Add New Channel\n");
    printf("\tName:\n");
    scanf("%s", name);
    printf("\tViews:\n");
    scanf("%d", &views);
    printf("\tVideos:\n");
    scanf("%d", &videos);
    
    list = add_channel(name, s_list, views, videos, list);
    return list;

}


int main () {
    Channel *list_c = NULL;
    while(1) {
        switch(print_menu()) {
            case 1:
                list_c = new_channel(list_c);
            break;
            case 2:
                list_channels(list_c);
            break;
            case 3:
                printf("Most views: [%d]\n", most_views(list_c));
            break;
            case 4:
                printf("Lowest views: [%d]\n", lowest_views(list_c));
            break;
            case 5:
                list_c = remove_last(list_c);
            break;
            case 6:
                list_c = remove_first(list_c);
            break;
            case 7:
                subscribers_list(list_c);
            break;
        }
    }


    return 0;
}