#include <stdio.h>
#include <stdlib.h>
int i = 0;
typedef struct node {
	int key;
	struct node* prev;
	struct node* next;

}
node;
node* head = NULL;
node* first = NULL;
node* temp = NULL;
node* tail = NULL;
void addnode(int k){
	node* ptr = (node*)malloc(sizeof(node));
	ptr->key = k;
	ptr->next = NULL;
	ptr->prev = NULL;
	if (head == NULL) {
		head = ptr;
		first = head;
		tail = head;
	}
	else {
		temp = ptr;
		first->next = temp;
		temp->prev = first;
		first = temp;
		tail = temp;
	}
	i++;
}
void traverse(){
	node* ptr = head;
	while (ptr != NULL) {
		printf("%d ", ptr->key);
		ptr = ptr->next;
	}

	printf("\n");
}
void insertatbegin(int k){
	node* ptr = (node*)malloc(sizeof(node));
	ptr->key = k;
	ptr->next = NULL;
	ptr->prev = NULL;
	if (head == NULL) {
		first = ptr;
		first = head;
		tail = head;
	}
	else {
		temp = ptr;
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	i++;
}
void insertatend(int k){
	node* ptr = (node*)malloc(sizeof(node));
	ptr->key = k;
	ptr->next = NULL;
	ptr->prev = NULL;
	if (head == NULL) {
		first = ptr;
		first = head;
		tail = head;
	}
	else {
		temp = ptr;
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	i++;
}
void insertatpos(int k, int pos){
	if (pos < 1 || pos > i + 1) {
		printf("Please enter a"
			" valid position\n");
	}
	else if (pos == 1) {
		insertatbegin(k);
	}
	else if (pos == i + 1) {
		insertatend(k);
	}
	else {
		node* src = head;
		while (pos--) {
			src = src->next;
		}
		node **da, **ba;
		node* ptr=(node*)malloc(sizeof(node));
		ptr->next=NULL;
		ptr->prev=NULL;
		ptr->key=k;
		ba=&src;
		da=&(src->prev);
		ptr->next=(*ba);
		ptr->prev=(*da);
		(*da)->next = ptr;
		(*ba)->prev = ptr;
		i++;
	}
}
void delatbegin(){
	head = head->next;
	i--;
}
void delatend(){
	tail = tail->prev;
	tail->next = NULL;
	i--;
}
void delatpos(int pos){
	if (pos < 1 || pos > i + 1) {
		printf("Please enter a"
			" valid position\n");
	}
	else if (pos == 1) {
		delatbegin();
	}
	else if (pos == i) {
		delatend();
	}
	else {
		node* src = head;
		pos--;
		while (pos--) {
			src = src->next;
		}
		node **pre, **aft;
		pre = &(src->prev);
		aft = &(src->next);
		(*pre)->next = (*aft);
		(*aft)->prev = (*pre);
		i--;
	}
}
int main(){
	addnode(2);
	addnode(4);
	addnode(9);
	addnode(1);
	addnode(21);
	addnode(22);
	printf("Linked List: ");
	traverse();
	printf("\n");
	insertatbegin(1);
	printf("Linked List after"
		" inserting 1 "
		"at beginning: ");
	traverse();
	insertatend(0);
	printf("Linked List after "
		"inserting 0 at end: ");
	traverse();
	insertatpos(44, 3);
	printf("Linked List after "
		"inserting 44 "
		"after 3rd Node: ");
	traverse();
	printf("\n");
	delatbegin();
	printf("Linked List after "
		"deleting node "
		"at beginning: ");
	traverse();
	delatend();
	printf("Linked List after "
		"deleting node at end: ");
	traverse();
	printf("Linked List after "
		"deleting node "
		"at position 5: ");
	delatpos(5);
	traverse();

	return 0;
}