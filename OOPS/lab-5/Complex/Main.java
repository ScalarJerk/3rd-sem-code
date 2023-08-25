/**
 * This class represents complex numbers and provides methods for addition.
 */
class Complex {
    double real, imag;

    // Constructor to initialize complex number
    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    // Method to add an integer to a complex number
    Complex add(int num) {
        return new Complex(real + num, imag);
    }

    // Method to add two complex numbers
    Complex add(Complex other) {
        return new Complex(real + other.real, imag + other.imag);
    }
}

public class Main {
    public static void main(String[] args) {
        Complex complex1 = new Complex(2.0, 3.0);
        Complex complex2 = new Complex(1.5, 2.5);
        int integer = 5;

        Complex sum1 = complex1.add(integer);
        Complex sum2 = complex1.add(complex2);

        System.out.println("Sum with integer: " + sum1.real + " + " + sum1.imag + "i");
        System.out.println("Sum of complex numbers: " + sum2.real + " + " + sum2.imag + "i");
    }
}
