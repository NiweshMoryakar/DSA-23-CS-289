#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int postIndex;

void fillPre(int iN[], int post[], int inStrt, int inEnd, int stack[], int *top, int hm[])
{
	if (inStrt > inEnd)
		return;

	int val = post[postIndex];
	int inIndex = hm[val];
	postIndex--;

	fillPre(iN, post, inIndex + 1, inEnd, stack, top, hm);
	fillPre(iN, post, inStrt, inIndex - 1, stack, top, hm);

	stack[++(*top)] = val;
}

void printPreMain(int iN[], int post[], int N)
{
	int stack[MAX_SIZE];
	int top = -1;

	int len = N;
	postIndex = len - 1;

	int hm[MAX_SIZE];
	for (int i = 0; i < N; i++)
		hm[iN[i]] = i;

	fillPre(iN, post, 0, len - 1, stack, &top, hm);

	while (top != -1)
	{
		printf("%d ", stack[top--]);
	}
}

int main()
{
	int iN[] = { 4, 10, 12, 15, 18, 22, 24, 25, 31, 35, 44, 50, 66, 70, 90 };
	int N = sizeof(iN) / sizeof(iN[0]);
	int post[] = { 4, 12, 10, 18, 24, 22, 15, 31, 44, 35, 66, 90, 70, 50, 25 };
	printPreMain(iN, post, N);

	return 0;
}