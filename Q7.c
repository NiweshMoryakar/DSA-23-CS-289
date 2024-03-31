#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int s = 0;
    int e = n - 1; 
    while (s <= e) {
        int mid = (s + e) / 2;
        if (arr[mid] == key) {
            return mid;
        } 
        else if (arr[mid] > key) {
            e = mid - 1;
        } 
        else {
            s = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("\n");
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the number to search: ");
    scanf("%d", &key);
    printf("%d\n", binarySearch(arr, n, key));
    return 0;
}