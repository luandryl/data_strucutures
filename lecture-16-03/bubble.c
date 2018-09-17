#include <stdio.h>

void bubble (int v[], int size) {
	int helper, i, j;

	for (i = 0; i < size; i++) {
		printf("\n [%d]", i);
		for (j = 0; j < size-1; j++) {
			printf("[%d]", j);
			if (v[j] > v[j+1]) {
				helper = v[j];
				v[j] = v[j+1];
				v[j+1] = helper; 
			}
		}
	}
}

void bubble_1 (int v[], int size) {
	int helper, i, j;

	for (i = 0; i < size; i++) {
		printf("\n [%d]", i);
		for (j = 0; j < (size-i) - 1; j++) {
			printf("[%d]", j);
			if (v[j] > v[j+1]) {
				helper = v[j];
				v[j] = v[j+1];
				v[j+1] = helper; 
			}
		}
	}
}

int main () {
	int v[4] = {12, 10, 5, 1 };

	for(int i = 0; i < 4; i++) {
		printf("[%d] \t", v[i]);
	}
	printf("\n");
	bubble_1(v, 4);
//	for(int i = 0; i < 4; i++) {
//		printf("[%d] \t", v[i]);
//	}
printf("\n");
	for(int i = 0; i < 4; i++) {
		printf("[%d] \t", v[i]);
	}
	
printf("\n");
	return 0;
}