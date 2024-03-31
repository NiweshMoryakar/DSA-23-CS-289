#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *left, *right;
};
struct Node* newNode(int data)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
void printLeftView(struct Node* root)
{
	if (!root)
		return;

	struct Node* queue[10000];
	int front = -1, rear = -1;
	queue[++rear] = root;

	while (front != rear)
	{
		int n = rear - front;
		for(int i = 0; i < n; i++)
		{
			struct Node* temp = queue[++front];
			if (i == 0)
				printf("%d ", temp->data);
			if (temp->left)
				queue[++rear] = temp->left;
			if (temp->right)
				queue[++rear] = temp->right;
		}
	}
}
int main()
{
	struct Node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(8);
	root->right->right = newNode(15);
	root->right->left = newNode(12);
	root->right->right->left = newNode(14);

	printf("Left view of the binary tree: \n");
	printLeftView(root);
	return 0;
}