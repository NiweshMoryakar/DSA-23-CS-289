#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	struct Node* left;
	struct Node* right;
	int hd;
	int data;
};

struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->left = node->right = NULL;
	node->data = key;
	return node;
}

void topview(struct Node* root)
{
	if (root == NULL)
		return;

	struct Node* queue[10000];
	int front = -1, rear = -1;
	int m[10000] = {0};
	int hd = 0;
	root->hd = hd;

	queue[++rear] = root;

	printf("The top view of the tree is : \n");

	while (front != rear) {
		root = queue[++front];
		hd = root->hd;

		if (m[hd] == 0)
			m[hd] = root->data;
		if (root->left) {
			root->left->hd = hd - 1;
			queue[++rear] = root->left;
		}
		if (root->right) {
			root->right->hd = hd + 1;
			queue[++rear] = root->right;
		}
	}

	for (int i = 0; i < 10000; i++) {
		if (m[i] != 0)
			printf("%d ", m[i]);
	}
}

int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->left->right->right = newNode(5);
	root->left->right->right->right = newNode(6);
	topview(root);
	return 0;
}