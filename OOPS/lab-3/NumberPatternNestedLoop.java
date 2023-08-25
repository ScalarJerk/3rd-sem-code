/**
 * This program displays a number pattern using nested for loops.
 */
public class NumberPatternNestedLoop {
    public static void main(String[] args) {
        int rows = 5; // Change this to the number of rows
        
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
