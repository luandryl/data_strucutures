#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int height, v;
	struct Node *left;
	struct Node *right;
}Node;

typedef struct AVL {
	Node *root;
}AVL;

AVL * startAVL() {
	return NULL;
}

AVL * create () {
	return (AVL *) malloc(sizeof(AVL));
}

int isEmpty (Node *root) {
	return (root == NULL);
}


int height (Node *root) {
	if (isEmpty (root)) 
		return 0;
	
	int hsl = height(root->left);
	int hsr = height(root->right);

	return hsl > hsr ? 1+hsl : 1+hsr;

}


int FB (Node *root) {
	if (isEmpty (root)) 
		return 0;
	
	return height(root->left) - height(root->right);
}

Node * insertBinary (Node *root, int e) {
    if (isEmpty(root)) {
        root = (Node *) malloc(sizeof(Node));
        root->v = e;
				root->height = 0;
        root->left = root->right = NULL;
    } else if (e < root->v) {
        root->left = insertBinary (root->left, e);
    } else {
				root->right = insertBinary (root->right, e);
    }
		int balance = FB(root);
		printf("[%d]\n", balance);
}

int MAX (int a, int b) {
	return (a > b) ? a : b;
}

Node * L(Node *y) {
	if (isEmpty(y)) {
		Node *x = y->left;
		Node *tmp = x->right;

		x->right = y;
		y->right = tmp;

		x->height = MAX(height(x->left), height(x->right)) + 1;
		y->height = MAX(height(y->left), height(y->right)) + 1;

		return x;
	}
}

Node * R(Node *x) {
	if (isEmpty(x)) {
		Node *y = x->right;
		Node *tmp = y->left;

		y->right = x;
		x->left = tmp;

		x->height = MAX(height(x->left), height(x->right)) + 1;
		y->height = MAX(height(y->left), height(y->right)) + 1;

		return y;
	}
}

Node * insertAVL (Node *node, int e) {
	if (isEmpty(node)) {
        node = (Node *) malloc(sizeof(Node));
        node->v = e;
        node->left = node->right = NULL;
    } else if (e < node->v) {
        node->left = insertAVL (node->left, e);
    } else {
				node->right = insertAVL (node->right, e);
    } 

		node->height = (MAX(height(node->left), height(node->right)) + 1);
		
		int balance = FB(node);
		printf("[%d]\n", balance);
		//printf("[%d]", node->height);

		if (balance > 1) {

			if (FB(node->right) > 0) {
				node->right = R (node->right);
				return L(node);
			} else{
				return L(node);
			}

		} else if (balance < -1){
			if (FB(node->left) > 0) {
				node->left = L (node->left);
				return R(node);
			} else{
				return R(node);
			}
		}

		return node;

}
