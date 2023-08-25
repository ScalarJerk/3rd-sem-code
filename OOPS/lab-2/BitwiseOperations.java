/* This program performs bitwise operations on two numbers. */
import java.util.Scanner;

public class BitwiseOperations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter value for 'a': ");
        int a = scanner.nextInt();
        System.out.print("Enter value for 'b': ");
        int b = scanner.nextInt();

        int result1 = (a << 2) + (b >> 2);
        boolean result2 = b > 0;
        int result3 = (a + b * 100) / 10;
        int result4 = a & b;

        System.out.println("(a << 2) + (b >> 2) = " + result1);
        System.out.println("b > 0 is " + result2);
        System.out.println("(a + b * 100) / 10 = " + result3);
        System.out.println("a & b = " + result4);

        scanner.close();
    }
}
