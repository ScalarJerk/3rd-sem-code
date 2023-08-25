/**
 * This class represents a number and provides methods to check its properties.
 */
class Number {
    private double value;

    // Constructor to initialize the number
    Number(double v) {
        value = v;
    }

    boolean isZero() {
        return value == 0;
    }

    boolean isPositive() {
        return value > 0;
    }

    boolean isNegative() {
        return value < 0;
    }

    boolean isOdd() {
        return value % 2 != 0;
    }

    boolean isEven() {
        return value % 2 == 0;
    }

    boolean isPrime() {
        if (value <= 1) return false;
        for (int i = 2; i <= Math.sqrt(value); i++) {
            if (value % i == 0) return false;
        }
        return true;
    }

    boolean isArmstrong() {
        int num = (int) value;
        int originalNum = num;
        int sum = 0;
        int numDigits = (int) Math.log10(num) + 1;

        while (num > 0) {
            int digit = num % 10;
            sum += Math.pow(digit, numDigits);
            num /= 10;
        }

        return sum == originalNum;
    }
}

public class Main {
    public static void main(String[] args) {
        Number num = new Number(153);

        System.out.println("Is zero? " + num.isZero());
        System.out.println("Is positive? " + num.isPositive());
        System.out.println("Is negative? " + num.isNegative());
        System.out.println("Is odd? " + num.isOdd());
        System.out.println("Is even? " + num.isEven());
        System.out.println("Is prime? " + num.isPrime());
        System.out.println("Is Armstrong? " + num.isArmstrong());
    }
}
