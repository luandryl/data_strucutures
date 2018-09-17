#include <stdio.h>

void swap (int v[], int index1, int index2) {
    int tmp = v[index1];
    v[index1] = v[index2];
    v[index2] = tmp;
}   
/*
    Classic Partition 
*/
int partition (int v[], int start, int end) {
    int pivot = v[end];
    int p_index = start - 1;

    for(int j = start; j <= end - 1; j++) {
        if (v[j] < pivot) {
            p_index++;
            swap(v, p_index, j);
        }
    }
    swap(v, p_index + 1, end);

    return (p_index + 1);
}

void quick_sort (int v[], int start, int end) {
    if (start < end) {
        int p_index = partition(v, start, end);
        quick_sort(v, start, p_index - 1);
        quick_sort(v, p_index + 1, end);
    }
}

int partition_s (int v[], int start, int end) {
    int pivot = v[start];
    int p_index = start + 1;

    for(int j = start; j <= end; j++) {
        if (v[j] < pivot) {
            swap(v, p_index, j);
            p_index++;
        }
    }
    v[start] = v[p_index - 1];
    v[p_index - 1] = pivot;

    return (p_index - 1);
}

void quick_sort_s (int v[], int start, int end) {
    if (start < end) {
        int p_index = partition_s(v, start, end);
        quick_sort(v, start, p_index - 1);
        quick_sort(v, p_index + 1, end);
    }
}

void print_array (int  v[], int size) {
    if (size >= 0) {
        print_array(v, size - 1);
        printf("\t[%d]\n", v[size]);
    }
}

int choose_menu () {
    int opt;
    printf("Choose where the pivot will be?\n");
    printf("1-Start\t");
    printf("2-End\n");
    scanf("%d", &opt);
    return opt;
}

int main () {
    int arr[5] = {10, 4, 8, 1, 9};
    printf("\tUnordered Array\n");
    print_array(arr, 4);
    printf("\nQuick Sort\n\n");
    switch(choose_menu()) {
        case 1: 
            quick_sort_s(arr, 0, 4);
        break;
        case 2:
            quick_sort(arr, 0, 4);
        break;
    }
    printf("\tOrdered Array\n");
    print_array(arr, 4);

    return 0;
}