#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

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

int main(){
    int A[MAX][MAX], n;
    printf("Enter the size of the square matrix for a magic square check: ");
    scanf("%d", &n);

    printf("Enter elements for the square matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    if (isMagicSquare(A, n))
        printf("The matrix is a magic square.\n");
    else
        printf("The matrix is not a magic square.\n");
    
    return 0;
}