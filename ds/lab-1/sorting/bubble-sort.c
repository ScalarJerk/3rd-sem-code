// Documentation: This program implements the Bubble Sort algorithm to sort an array of integers in ascending order.

#include <stdio.h>
#include <stdlib.h>

// Function to perform Bubble Sort on an array of integers.
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // Iterate through the array elements
        for (int j = 0; j < n - i - 1; j++) { // Compare adjacent elements
            if (arr[j] > arr[j + 1]) { // Swap if the current element is greater than the next
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n); // Call the Bubble Sort function

    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print the sorted elements
    }
    printf("\n");

    return 0;
}
