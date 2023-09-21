#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int arr[] = {12, 45, 67, 89, 34, 23, 56, 78, 90, 32};
    int n = sizeof(arr) / sizeof(arr[0]);   // number of elements in the array
    int target = 56;

    int index = linearSearch(arr, n, target);

    if (index != -1) {
        printf("Element found at index %d.\n", index);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}
