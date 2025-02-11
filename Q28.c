#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

void printNthFromLast(Node* head, int N) {
	int len = 0, i;
	Node* temp = head;

	while (temp != NULL) {
		temp = temp->next;
		len++;
	}

	if (len < N)
		return;
	temp = head;

	for (i = 1; i < len - N + 1; i++)
		temp = temp->next;
	printf("%d", temp->data);
	return;
}

void push(struct Node** head_ref, int new_data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int main() {
	struct Node* head = NULL;
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 35);
	printNthFromLast(head, 4);
	return 0;
}