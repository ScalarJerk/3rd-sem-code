/**
 * This program adds and multiplies two integer matrices.
 */

import java.util.Scanner;

public class MatrixOperations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read matrix dimensions
        System.out.print("Enter rows of matrix A: ");
        int rowsA = scanner.nextInt();
        System.out.print("Enter columns of matrix A");
        int colsA = scanner.nextInt();
        System.out.print("Enter rows of matrix B: ");
        int rowsB = scanner.nextInt();
        System.out.print("Enter columns of matrix B: ");
        int colsB = scanner.nextInt();

        int[][] matrixA = new int[rowsA][colsA];
        int[][] matrixB = new int[rowsB][colsB];

        // Read matrix A elements
        System.out.println("Enter matrix A elements:");
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsA; j++) {
                matrixA[i][j] = scanner.nextInt();
            }
        }

        // Read matrix B elements
        System.out.println("Enter matrix B elements:");
        for (int i = 0; i < rowsB; i++) {
            for (int j = 0; j < colsB; j++) {
                matrixB[i][j] = scanner.nextInt();
            }
        }

        // Initialize matrix C for multiplication result
        int[][] matrixC = new int[rowsA][colsB];

        // Multiply matrices A and B
        if (colsA != rowsB) {
            System.out.println("Matrix multiplication is not possible");
        } else {
            for (int i = 0; i < rowsA; i++) {
                for (int j = 0; j < colsB; j++) {
                    int sum = 0;
                    for (int k = 0; k < colsA; k++) {
                        sum += matrixA[i][k] * matrixB[k][j];
                    }
                    matrixC[i][j] = sum;
                }
            }
            // Display matrix C (multiplication result)
            System.out.println("Matrix C (Multiplication Result):");
            for (int i = 0; i < rowsA; i++) {
                for (int j = 0; j < colsB; j++) {
                    System.out.print(matrixC[i][j] + " ");
                }
                System.out.println();
            }
        }


        if (rowsA != rowsB && colsA != colsB) {
            System.out.println("Matrix addition not possible");
        } else {
            // Add matrices A and B
            int[][] matrixSum = new int[rowsA][colsA];
            for (int i = 0; i < rowsA; i++) {
                for (int j = 0; j < colsA; j++) {
                    matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
                }
            }

            // Display matrix sum
            System.out.println("Matrix Sum:");
            for (int i = 0; i < rowsA; i++) {
                for (int j = 0; j < colsA; j++) {
                    System.out.print(matrixSum[i][j] + " ");
                }
                System.out.println();
            }
        }
        scanner.close();
    }
}
