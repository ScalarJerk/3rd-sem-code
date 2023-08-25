import java.util.Scanner;

/**
 * This program evaluates the series Sum = 1 + (1/2)^2 + (1/3)^3 + ...
 */
public class SeriesSumEvaluation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the value of n: ");
        int n = scanner.nextInt();
        scanner.close();
        
        double sum = 0;
        
        for (int i = 1; i <= n; i++) {
            sum += 1 / Math.pow(i, i);
        }
        
        System.out.println("Sum = " + sum);
    }
}
