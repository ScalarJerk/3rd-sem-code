/*Write a program in C to read two matrices 
A & B and perform the following:
i.) Multiply two matrices
ii.) Add two matrices
iii.) Read a square matrix and check 
if it a magic square or not.*/ 
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void multiplyMatrices(int A[][MAX], int B[][MAX], int C[][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}



int isMagicSquare(int matrix[][MAX], int n) {
    int sumDiag1 = 0, sumDiag2 = 0;

    for (int i = 0; i < n; i++) {
        sumDiag1 += matrix[i][i];
        sumDiag2 += matrix[i][n - i - 1];
    }

    if (sumDiag1 != sumDiag2)
        return 0;

    for (int i = 0; i < n; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }
        if (rowSum != sumDiag1 || colSum != sumDiag1)
            return 0;
    }

    return 1;
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    
    printf("Enter elements for matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    printf("Enter elements for matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    if (colsA != rowsB) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);
    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
