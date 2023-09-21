// Documentation: This program demonstrates the Insertion Sort algorithm, which efficiently
// sorts an array of integers in ascending order. Insertion Sort builds the sorted array
// one element at a time, shifting elements greater than the current value to the right
// until the correct position is found for insertion.

#include <stdio.h>
#include <stdlib.h>

// Function to perform insertion sort on an array of integers.
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than the key to the right.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;

    // Get the number of elements from the user.
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Get elements from the user.
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using insertion sort algorithm.
    insertionSort(arr, n);

    // Print the sorted elements.
    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
