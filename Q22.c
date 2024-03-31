#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
void detectAndRemoveCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return; 
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break; 
        }
    }

    if (slow == fast) { 
        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
struct ListNode* createLinkedListWithCycle(int arr[], int n, int pos) {
    struct ListNode *head = newNode(arr[0]);
    struct ListNode *tail = head;
    struct ListNode *cycleStart = NULL;
    for (int i = 1; i < n; i++) {
        tail->next = newNode(arr[i]);
        tail = tail->next;

        if (i == pos) {
            cycleStart = tail;
        }
    }
    if (cycleStart) {
        tail->next = cycleStart;
    }

    return head;
}
void printList(struct ListNode *head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pos = 1;
    struct ListNode *head = createLinkedListWithCycle(arr, n, pos);

    printf("Linked List before cycle detection and removal:\n");
    printList(head);
    detectAndRemoveCycle(head);
    printf("Linked List after cycle detection and removal:\n");
    printList(head);
    struct ListNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}