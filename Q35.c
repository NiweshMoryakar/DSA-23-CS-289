#include <stdio.h>
#include <stdlib.h>

struct Node {
	int key;
	struct Node *left, *right;
};

struct Node* newNode(int k)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->key = k;
	temp->left = temp->right = NULL;
	return temp;
}

int findPath(struct Node* root, int path[], int k)
{
	if (root == NULL)
		return 0;

	path[0] = root->key;

	if (root->key == k)
		return 1;

	if ((root->left && findPath(root->left, path + 1, k))
		|| (root->right && findPath(root->right, path + 1, k)))
		return 1;

	return 0;
}

int findLCA(struct Node* root, int n1, int n2)
{
	int path1[100], path2[100];

	if (!findPath(root, path1, n1)
		|| !findPath(root, path2, n2))
		return -1;

	int i;
	for (i = 0; path1[i] == path2[i]; i++)
		;

	return path1[i - 1];
}

int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	printf("LCA(4, 5) = %d\n", findLCA(root, 4, 5));
	printf("LCA(4, 6) = %d\n", findLCA(root, 4, 6));
	printf("LCA(3, 4) = %d\n", findLCA(root, 3, 4));
	printf("LCA(2, 4) = %d\n", findLCA(root, 2, 4));
	return 0;
}