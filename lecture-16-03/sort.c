#include <stdio.h>

void selection (int v[], int size) {
	int i, j, min, helper;

	for (i = 0; i < size -1; i++) {
		min = i;
		for(j = i+1; j < size; j++) {
			if (v[j] < v[min])
				min = j;
		}
		helper = v[i];
		v[i] = v[min];
		v[min] = helper;
	}
}

void bubble (int v[], int size) {
	int helper, i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size-1; j++) {
			if (v[j] > v[j+1]) {
				helper = v[j];
				v[j] = v[j+1];
				v[j+1] = helper; 
			}
		}
	}
}


void insertion (int v[], int size) {
	int i, j, pivot;

	for (i = 1; i < size; i++) {
		pivot = v[i];
		j = i-1;
		while (j >= 0 && v[j] >  pivot) {
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = pivot;
	}
}

int main () {
	int v[6] = {22, 24, 22, 38, 18, 31};

	insertion(v, 6);
	printf("\n Insertion \n");
	for(int i = 0; i < 6; i++) {
		printf("[%d] \t", v[i]);
	}
	int v1[6] = {22, 24, 22, 38, 18, 31};
	selection(v1, 6);
	printf("\n Selection \n");
	for(int i = 0; i < 6; i++) {
		printf("[%d] \t", v[i]);
	}
	int v2[6] = {22, 24, 22, 38, 18, 31};
	bubble(v2, 6);
	printf("\n Bubble \n");
	for(int i = 0; i < 6; i++) {
		printf("[%d] \t", v[i]);
	}
	

	return 0;
}