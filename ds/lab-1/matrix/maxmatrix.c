#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    int A[MAX_ROWS][MAX_COLS], B[MAX_ROWS][MAX_COLS], C[MAX_ROWS][MAX_COLS];
    int numRows, numCols;

    // Read the number of rows and columns for the matrices
    printf("Enter the number of rows: ");
    scanf("%d", &numRows);
    printf("Enter the number of columns: ");
    scanf("%d", &numCols);

    // Read matrix A
    printf("Enter elements for matrix A:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Read matrix B
    printf("Enter elements for matrix B:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Create matrix C
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            C[i][j] = (A[i][j] > B[i][j]) ? A[i][j] : B[i][j];  //is a > b?
        }
    }

    // Display matrix C
    printf("Matrix C (resultant matrix):\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
