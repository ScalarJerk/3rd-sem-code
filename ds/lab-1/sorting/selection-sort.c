// Documentation: This program implements the selection sort algorithm to sort an array of integers in ascending order.
// The selection sort algorithm repeatedly selects the minimum element from the unsorted portion of the array
// and places it at the beginning of the sorted portion.

#include <stdio.h>
#include <stdlib.h>

// Function to perform selection sort on an array of integers
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the index of the minimum element in the unsorted portion
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the minimum element with the first element in the unsorted portion
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input elements into the array
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the selectionSort function to sort the array
    selectionSort(arr, n);

    // Display the sorted elements
    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
