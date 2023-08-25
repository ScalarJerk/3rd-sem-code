/**
 * Program to display principal diagonal elements and find their sum in a matrix.
 */
import java.util.Scanner;

public class PrincipalDiagonalElements {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Input matrix size and elements
        System.out.print("Enter the number of rows: ");
        int rows = sc.nextInt();
        System.out.print("Enter the number of columns: ");
        int columns = sc.nextInt();
        
        int[][] matrix = new int[rows][columns];
        System.out.println("Enter matrix elements:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        // Display principal diagonal elements and find their sum
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            System.out.print(matrix[i][i] + " ");
            sum += matrix[i][i];
        }

        System.out.println("\nSum of principal diagonal elements: " + sum);

        sc.close();
    }
}
