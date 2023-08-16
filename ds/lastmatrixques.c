/*Write a program in C to read two matrices 
A & B and perform the following:
i.) Multiply two matrices
ii.) Add two matrices
iii.) Read a square matrix and check 
if it a magic square or not.*/ 
  
  #include <stdio.h>

#define MAX_SIZE 10

void multiplyMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void addMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int isMagicSquare(int matrix[][MAX_SIZE], int n) {
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
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
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

    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrix addition is not possible.\n");
        return 0;
    }

    addMatrices(A, B, C, rowsA, colsA);
    printf("Result of matrix addition:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    int n;
    printf("Enter the size of the square matrix for magic square check: ");
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
