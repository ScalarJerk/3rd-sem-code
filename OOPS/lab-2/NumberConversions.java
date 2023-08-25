/* This program performs various type conversions. */
import java.util.Scanner;

public class NumberConversions {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an int number: ");
        int numInt = scanner.nextInt();
        System.out.print("Enter a double number: ");
        double numDouble = scanner.nextDouble();
        System.out.print("Enter a char: ");
        char charValue = scanner.next().charAt(0);
        
        byte byteFromInt = (byte) numInt;
        int intFromChar = (int) charValue;
        byte byteFromDouble = (byte) numDouble;
        int intFromDouble = (int) numDouble;
        
        System.out.println("Int to Byte: " + byteFromInt);
        System.out.println("Char to Int: " + intFromChar);
        System.out.println("Double to Byte: " + byteFromDouble);
        System.out.println("Double to Int: " + intFromDouble);
        
        scanner.close();
    }
}
