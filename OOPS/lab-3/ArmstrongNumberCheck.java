/**
 * This program checks if a number is an Armstrong number.
 * An Armstrong number is one where the sum of its digits raised to the power of the number of digits equals the number itself.
 */
public class ArmstrongNumberCheck {
    public static void main(String[] args) {
        int number = 153; // Change this to the number you want to check
        int originalNumber = number;
        int sum = 0;
        int digits = String.valueOf(number).length();
        
        while (number > 0) {
            int digit = number % 10;
            sum += Math.pow(digit, digits);
            number /= 10;
        }
        
        if (sum == originalNumber) {
            System.out.println(originalNumber + " is an Armstrong number.");
        } else {
            System.out.println(originalNumber + " is not an Armstrong number.");
        }
    }
}
