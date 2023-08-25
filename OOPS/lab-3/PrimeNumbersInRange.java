/**
 * This program generates prime numbers between n and m.
 */
public class PrimeNumbersInRange {
    public static void main(String[] args) {
        int n = 10; // Change this to the starting value of the range
        int m = 50; // Change this to the ending value of the range
        
        for (int num = n; num <= m; num++) {
            if (isPrime(num)) {
                System.out.println(num);
            }
        }
    }
    
    // Function to check if a number is prime
    static boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}
