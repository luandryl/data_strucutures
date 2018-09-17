#include <stdio.h>
#include <stdlib.h>

#define SIZE 200

typedef struct Node {
	int v;
	struct Node *next;
}Node;

typedef Node * Hash[SIZE];

int hashFunction (int e) {
	return (e%SIZE);
}

void startHash (Hash table) {
	for(int i = 0; i < SIZE; i++) {
		table[i] = NULL;
	}
}

void insertHash (Hash table, int e) {
	
	int hashCode = hashFunction(e);
	Node *tmp = table[hashCode];

	while (tmp != NULL) {
		if (tmp->v == e)
			break;
		tmp = tmp->next;
	}
	if (tmp == NULL) {
		tmp = (Node *) malloc(sizeof(Node));
		tmp->v = e;
		tmp->next = table[hashCode];
		table[hashCode] = tmp;
	} 
}

void printHash (Hash table) {
	for (int i = 0; i < SIZE; i++) {
		if (table[i] != NULL) {
			printf("\n [%d] -> %d", i, table[i]->v);
			Node *tmp = table[i]->next;
			while(tmp != NULL) {
				printf("\t -> %i", tmp->v);
				tmp = tmp->next;
			}
		}
	}
}

void printCollision (Hash table, int position) {
	Node *tmp = table[position];

	if (tmp != NULL) {
		printf("\n[%d] %d", position, tmp->v);
		while(tmp != NULL) {
			printf("\t -> %d", tmp->v);
			tmp = tmp->next;
		}
	} else {
		printf ("\n Empty Position \n");
	}
} 

void removeFromHashTable (Hash table, int e) {
	int hashCode = hashFunction(e);
	Node *tmp = table[hashCode];
	Node *prev = NULL;
	
	if (tmp != NULL) {

		while(tmp != NULL && tmp->v != e) {
			prev = tmp;
			tmp = tmp->next;
		}

		if (tmp->v == e) {
			if (prev == NULL) {
			//first
				table[hashCode] = tmp->next;
				tmp = NULL;
				
			} else if (tmp->next == NULL) {
				prev->next = NULL;
				tmp = NULL;

			} else {
				//middle
				prev->next = tmp->next;
				tmp = NULL;
			}

			free(tmp);

		} else {
			printf ("\nElement Not Found\n");
		}
	} else {
		printf ("\nElement Not Found\n");
	}

} 