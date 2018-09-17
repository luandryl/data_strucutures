#include <stdio.h>

void merge (int v[], int start, int end, int middle) {
    int ordered[end];
    int index_1 = start;
    int index_2 = middle + 1;
    int free_position = start;

    while ((index_1 <= middle) && (index_2 <= end)) {
        if (v[index_1] <= v[index_2]) {
            ordered[free_position] = v[index_1];
            index_1 = index_1 + 1;
        } else {
            ordered[free_position] = v[index_2];
            index_2 = index_2 + 1;
        }

        free_position = free_position + 1;
    }

    for (int i = index_1; i <= middle; i++) {
        ordered[free_position] = v[i];
        free_position = free_position + 1;
    }

    for (int i = index_2; i <= end; i++) {
        ordered[free_position] = v[i];
        free_position = free_position + 1;
    }

    for (int i = start; i <= end; i++) {
        v[i] = ordered[i];
    }

}

void merge_sort (int v[], int start, int end) {
    int middle;
    if (start < end) {
        middle = ((start + end) / 2);
        merge_sort(v, start, middle);
        merge_sort(v, (middle + 1), end);
        merge(v, start, end, middle);
    }
}

void print_arr (int v[], int size) {
    if (size >= 0) {
        print_arr(v, size - 1);
        printf("\t[%d]\n", v[size]);
    }
}

int main () {

    int arr[9] = {4, 40, 34, 5, 6, 1, 2, 50, 57};
    printf("\tUnordered Array\n");
    print_arr(arr, 8);
     printf("\nMerge Sort\n\n");
    merge_sort(arr, 0, 8);
    printf("\n\n\n");
    printf("\tOrdered Array\n");
    print_arr(arr, 8);
    return 0;
}