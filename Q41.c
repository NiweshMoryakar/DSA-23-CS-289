#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void findPostOrderUtil(int pre[], int n, int minval, int maxval, int *preIndex)
{
	if (*preIndex == n)
		return;

	if (pre[*preIndex] < minval || pre[*preIndex] > maxval) {
		return;
	}

	int val = pre[*preIndex];
	(*preIndex)++;

	findPostOrderUtil(pre, n, minval, val, preIndex);
	findPostOrderUtil(pre, n, val, maxval, preIndex);

	printf("%d ", val);
}

void findPostOrder(int pre[], int n)
{
	int preIndex = 0;
	findPostOrderUtil(pre, n, INT_MIN, INT_MAX, &preIndex);
}

int main()
{
	int pre[] = { 40, 30, 35, 80, 100 };
	int n = sizeof(pre) / sizeof(pre[0]);
	findPostOrder(pre, n);
	return 0;
}