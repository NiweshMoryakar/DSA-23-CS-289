#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
int length(struct ListNode *head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = length(headA);
    int lenB = length(headB);
    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }
    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
void printList(struct ListNode *head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode *listA = newNode(1);
    listA->next = newNode(2);
    listA->next->next = newNode(3);
    listA->next->next->next = newNode(4);
    listA->next->next->next->next = newNode(5);

    struct ListNode *listB = newNode(6);
    listB->next = listA->next->next;

    printf("List A: ");
    printList(listA);
    printf("List B: ");
    printList(listB);

    struct ListNode *mergePoint = getIntersectionNode(listA, listB);
    if (mergePoint) {
        printf("Merge Point: %d\n", mergePoint->val);
    } else {
        printf("No merge point found.\n");
    }
    free(listA->next->next->next->next);
    free(listA->next->next->next);
    free(listA->next->next);
    free(listA->next);
    free(listA);

    free(listB->next);
    free(listB);

    return 0;
}