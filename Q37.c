#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
struct Node
{
	int data;
	int hd;
	struct Node *left, *right;
};
struct Node* newNode(int key)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = key;
	temp->hd = INT_MAX;
	temp->left = temp->right = NULL;
	return temp;
}
void bottomView(struct Node *root)
{
	if (root == NULL)
		return;

	int hd = 0;
	int m[10000] = {0};
	struct Node* queue[10000];
	int front = -1, rear = -1;

	root->hd = hd;
	queue[++rear] = root;

	while (front != rear)
	{
		struct Node *temp = queue[++front];
		hd = temp->hd;

		m[hd] = temp->data;

		if (temp->left != NULL)
		{
			temp->left->hd = hd - 1;
			queue[++rear] = temp->left;
		}

		if (temp->right != NULL)
		{
			temp->right->hd = hd + 1;
			queue[++rear] = temp->right;
		}
	}

	for (int i = 0; i < 10000; i++)
	{
		if (m[i] != 0)
			printf("%d ", m[i]);
	}
}
int main()
{
	struct Node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(5);
	root->left->right = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(25);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	printf("Bottom view of the given binary tree :\n");
	bottomView(root);
	return 0;
}