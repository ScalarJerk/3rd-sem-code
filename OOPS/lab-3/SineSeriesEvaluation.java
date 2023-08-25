import java.util.Scanner;

/**
 * This program evaluates the series Sin(x) = x - (x^3 / 3!) + (x^5 / 5!) - ...
 */
public class SineSeriesEvaluation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the value of x: ");
        double x = scanner.nextDouble();
        scanner.close();
        
        int terms = 10; // Number of terms in the series
        double result = 0;
        int sign = 1;
        
        for (int i = 1; i <= terms; i += 2) {
            result += sign * (Math.pow(x, i) / factorial(i));
            sign *= -1;
        }
        
        System.out.println("Sin(" + x + ") = " + result);
    }
    
    static int factorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }
}