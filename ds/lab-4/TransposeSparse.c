#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// Function prototypes
void readSparseMatrix(int[][3]);
void printSparseMatrix(int[][3]);
void transposeSparseMatrix(int[][3], int[][3]);

int main() {
    int mat1[MAX][3], mat2[MAX][3], m, n;
    char anotherInput;

    do {
        printf("Enter the size of matrix (rows, columns): ");
        scanf("%d%d", &m, &n);
        mat1[0][0] = m;
        mat1[0][1] = n;

        readSparseMatrix(mat1);
        transposeSparseMatrix(mat1, mat2);
        printSparseMatrix(mat2);

        printf("Do you want to enter another input? (y/n): ");
        scanf(" %c", &anotherInput);
    } while (anotherInput == 'y' || anotherInput == 'Y');

    return 0;
}

// Function to read a sparse matrix
void readSparseMatrix(int mat[MAX][3]) {
    int i, t;
    printf("\nEnter the number of non-zero elements: ");
    scanf("%d", &t);
    mat[0][2] = t;

    for (i = 1; i <= t; i++) {
        printf("\nEnter the next triple (row, column, value): ");
        scanf("%d%d%d", &mat[i][0], &mat[i][1], &mat[i][2]);
    }
}

// Function to print a sparse matrix
void printSparseMatrix(int mat[MAX][3]) {
    int i, n;
    n = mat[0][2]; // number of non-zero triples
    printf("\nTransposed Matrix:\n");
    printf("\nrow\t\tcolumn\t\tvalue\n");

    for (i = 0; i <= n; i++)
        printf("%d\t\t%d\t\t%d\n", mat[i][0], mat[i][1], mat[i][2]);
}

// Function to transpose a sparse matrix
void transposeSparseMatrix(int mat1[][3], int mat2[][3]) {
    int i, j, k, n;
    mat2[0][0] = mat1[0][1];
    mat2[0][1] = mat1[0][0];
    mat2[0][2] = mat1[0][2];
    k = 1;
    n = mat1[0][2];

    for (i = 0; i < mat1[0][1]; i++) {
        for (j = 1; j <= n; j++) {
            // If a column number of current triple == i, then insert the current triple in mat2
            if (i == mat1[j][1]) {
                mat2[k][0] = i;
                mat2[k][1] = mat1[j][0];
                mat2[k][2] = mat1[j][2];
                k++;
            }
        }
    }
}

