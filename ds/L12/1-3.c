#include <stdio.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int passes(int arr[], int n) {
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (largest < arr[i]) {
            largest = arr[i];
        }
    }
    int pass = 0;
    while (largest > 0) {
        pass += 1;
        largest /= 10;
    }
    return pass;
}

void RadixSort(int arr[], int n) {
    int pass = passes(arr, n);
    int bucket[10][n];
    int divisor = 1;
    for (int p = 0; p < pass; p++) {
        int count[10] = {0};
        for (int i = 0; i < n; i++) {
            int rem = (arr[i] / divisor) % 10;
            bucket[rem][count[rem]] = arr[i];
            count[rem]++;
        }
        int i = 0;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < count[j]; k++) {
                arr[i] = bucket[j][k];
                i++;
            }
        }
        print(arr, n);
        divisor *= 10;
    }
}

int main() {
    int arr[] = {345, 654, 924, 123, 567, 472, 555, 808, 911};
    int n = sizeof(arr) / sizeof(arr[0]);

    print(arr, n);
    RadixSort(arr, n);
    print(arr, n);

    return 0;
}

