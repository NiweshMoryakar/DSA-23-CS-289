#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size, pos, i, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter elements of the array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }


    printf("Enter 1 for insertion and 2 for deletion: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            printf("Enter the position where you want to insert: ");
            scanf("%d", &pos);
            if (pos < 0 || pos > size) {
                printf("Invalid position!\n");
                return 1;
            }
            printf("Enter the element to insert: ");
            int element;
            scanf("%d", &element);

            for (i = size - 1; i >= pos; i--) {
                arr[i + 1] = arr[i];
            }
            arr[pos] = element;
            size++;
            break;
        case 2: 
            printf("Enter the position of element to delete: ");
            scanf("%d", &pos);
            if (pos < 0 || pos >= size) {
                printf("Invalid position!\n");
                return 1;
            }

            for (i = pos; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--; 
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("Array after operation:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}