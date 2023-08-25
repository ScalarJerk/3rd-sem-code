// This program counts the number of positive, negative, and zero numbers.
// It takes 10 numbers as inputs and categorizes them accordingly.

import java.util.Scanner;

public class NumberCategorization {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int positive = 0, negative = 0, zero = 0;
        
        for (int i = 1; i <= 10; i++) {
            System.out.print("Enter number " + i + ": ");
            int number = scanner.nextInt();
            
            if (number > 0) {
                positive++;
            } else if (number < 0) {
                negative++;
            } else {
                zero++;
            }
        }
        
        System.out.println("Positive numbers: " + positive);
        System.out.println("Negative numbers: " + negative);
        System.out.println("Zero numbers: " + zero);
        
        scanner.close();
    }
}
