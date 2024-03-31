#include <stdio.h>

#define MAX_SIZE 50

int main() {
    int arr[MAX_SIZE]={1,2,3};
    int size = 3; 
    int choice, element;

    while (1) {
        printf("\nArray Operations:\n");
        printf("1. Insertion at beginning\n");
        printf("2. Deletion from beginning\n");
        printf("3. Display array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (size == MAX_SIZE) {
                    printf("Array is full, insertion not possible.\n");
                } else {
                    printf("Enter the element to insert: ");
                    scanf("%d", &element);
                    for (int i = size; i > 0; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[0] = element;
                    size++;
                    printf("Element inserted successfully.\n");
                }
                break;
            case 2:
                if (size == 0) {
                    printf("Array is empty, deletion not possible.\n");
                } else {
                    printf("Deleted element: %d\n", arr[0]);

                    for (int i = 0; i < size - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    size--;
                }
                break;
            case 3: 
                if (size == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            case 4: 
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    }

    return 0;
}