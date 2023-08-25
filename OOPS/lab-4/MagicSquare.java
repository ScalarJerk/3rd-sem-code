/**
 * This program checks whether the matrix is a magic square or not.
 * A magic square is a square matrix where the sum of all rows, columns, and diagonals are equal.
 */

 import java.util.Scanner;

 public class MagicSquare {
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
         
         int magicSum = 0; // Sum of rows, columns, or diagonals
         
         // Calculate the sum of the first row for comparison
         for (int j = 0; j < size; j++) {
             magicSum += matrix[0][j];
         }
         
         // Check rows
         boolean isMagic = true;
         for (int i = 0; i < size; i++) {
             int rowSum = 0;
             for (int j = 0; j < size; j++) {
                 rowSum += matrix[i][j];
             }
             if (rowSum != magicSum) {
                 isMagic = false;
                 break;
             }
         }
         
         // Check columns
         for (int j = 0; j < size; j++) {
             int colSum = 0;
             for (int i = 0; i < size; i++) {
                 colSum += matrix[i][j];
             }
             if (colSum != magicSum) {
                 isMagic = false;
                 break;
             }
         }
         
         // Check principal diagonal
         int diagSum = 0;
         for (int i = 0; i < size; i++) {
             diagSum += matrix[i][i];
         }
         if (diagSum != magicSum) {
             isMagic = false;
         }
         
         // Check non-principal diagonal
         diagSum = 0;
         for (int i = 0; i < size; i++) {
             diagSum += matrix[i][size - 1 - i];
         }
         if (diagSum != magicSum) {
             isMagic = false;
         }
         
         if (isMagic) {
             System.out.println("The matrix is a magic square.");
         } else {
             System.out.println("The matrix is not a magic square.");
         }
         scanner.close();
     }
 }
 