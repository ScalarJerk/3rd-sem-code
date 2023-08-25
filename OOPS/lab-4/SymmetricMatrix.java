/**
 * This program checks whether a given matrix is symmetric or not.
 * A matrix is symmetric if it is equal to its transpose.
 */

import java.util.Scanner;

public class SymmetricMatrix {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read matrix size
        System.out.print("Enter matrix size: ");
        int size = scanner.nextInt();
        
        int[][] matrix = new int[size][size];
        
        // Read matrix elements
        System.out.println("Enter matrix elements:");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        
        // Check if the matrix is symmetric
        boolean symmetric = true;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] != matrix[j][i]) {
                    symmetric = false;
                    break;
                }
            }
            if (!symmetric) {
                break;
            }
        }
        
        if (symmetric) {
            System.out.println("The matrix is symmetric.");
        } else {
            System.out.println("The matrix is not symmetric.");
        }
        scanner.close();
    }
}
