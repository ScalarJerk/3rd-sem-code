// Recursive Binary Search

#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            return binarySearch(arr, mid + 1, high, target);
        return binarySearch(arr, low, mid - 1, target);
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    
    int result = binarySearch(arr, 0, n - 1, target);
    
    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", result);
    
    return 0;
}
