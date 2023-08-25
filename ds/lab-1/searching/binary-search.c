#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return index if found
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int arr[] = {12, 23, 34, 45, 56, 67, 78, 89, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 56;

    int index = binarySearch(arr, 0, n - 1, target);

    if (index != -1) {
        printf("Element found at index %d.\n", index);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}
