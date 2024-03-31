#include <stdio.h>
int floorValue(int arr[], int n, int x) {
    int floor = -1;
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return arr[mid];
        else if (arr[mid] < x) {
            floor = arr[mid];
            low = mid + 1;
        } else
            high = mid - 1;
    }
    return floor;
}
int ceilValue(int arr[], int n, int x) {
    int ceil = -1;
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return arr[mid];
        else if (arr[mid] > x) {
            ceil = arr[mid];
            high = mid - 1;
        } else
            low = mid + 1;
    }
    return ceil;
}
int findPeak(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[mid + 1])
            high = mid;
        else
            low = mid + 1;
    }
    return arr[low];
}
int findMinimum(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }
    return arr[low];
}

int main() {
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;
    printf("Floor of %d is: %d\n", x, floorValue(arr, n, x));
    printf("Ceil of %d is: %d\n", x, ceilValue(arr, n, x));
    printf("Peak element is: %d\n", findPeak(arr, n));
    printf("Minimum element is: %d\n", findMinimum(arr, n));
    return 0;
}