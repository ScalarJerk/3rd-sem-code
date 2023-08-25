/**
 * This program searches for an element in a matrix and counts its occurrences.
 */
import java.util.*;

public class MatrixElementSearch {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of rows: ");
        int rows = scanner.nextInt();
        System.out.print("Enter the number of columns: ");
        int cols = scanner.nextInt();

        int[][] matrix = new int[rows][cols];
        System.out.println("Enter the matrix elements:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        System.out.print("Enter the element to search: ");
        int target = scanner.nextInt();

        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == target) {
                    count++;
                }
            }
        }

        System.out.println("Occurrences of " + target + " in the matrix: " + count);

        scanner.close();
    }
}
