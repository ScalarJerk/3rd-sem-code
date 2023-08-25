/**
 * This program prints all combinations of four-digit numbers with allowed digit duplication.
 */
public class FourDigitCombinationsWithDuplication {
    public static void main(String[] args) {
        int[] digits = {1, 2, 3, 4};
        generateCombinations(digits, "", 4);
    }
    
    static void generateCombinations(int[] digits, String current, int length) {
        if (current.length() == length) {
            System.out.println(current);
            return;
        }
        
        for (int digit : digits) {
            generateCombinations(digits, current + digit, length);
        }
    }
}

