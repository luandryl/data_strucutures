#include <stdio.h>
#include "Hash.h"

int main () {

	Hash table;

	startHash(table);
	for (int i = 0; i < 340; i++) {
		insertHash(table, 1234+i);
	}
	printHash(table);
	printCollision(table, 45);
	removeFromHashTable(table, 1245);
	printCollision(table, 45);

	return 0;
}