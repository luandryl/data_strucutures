#include <stdio.h>

int searchR (int element, int size, int v[]) {
    return (v[size - 1] == element) ? size-1 : (size == -1) ? -1 : searchR(element, size-1, v);
}
int main () {

    int v[4] = {1, 5, 10, 12};
    printf("Position: [%d]", searchR(10, 4, v));
}