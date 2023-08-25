/**
 * This program prints all combinations of four-digit numbers without digit duplication.
 */
public class FourDigitCombinationsWithoutDuplication {
    public static void main(String[] args) {
        int[] digits = {1, 2, 3, 4};
        generateCombinations(digits, "", 4);
    }
    
    static void generateCombinations(int[] digits, String current, int length) {
        if (current.length() == length) {
            System.out.println(current);
            return;
        }
        
        for (int i = 0; i < digits.length; i++) {
            if (!current.contains(String.valueOf(digits[i]))) {
                generateCombinations(digits, current + digits[i], length);
            }
        }
    }
}
