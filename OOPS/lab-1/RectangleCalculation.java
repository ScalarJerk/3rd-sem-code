// This program calculates the area and circumference of a rectangle.
// It takes length and breadth as inputs and uses the provided formulas.

import java.util.Scanner;

public class RectangleCalculation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter length of rectangle: ");
        double length = scanner.nextDouble();
        
        System.out.print("Enter breadth of rectangle: ");
        double breadth = scanner.nextDouble();
        
        double area = length * breadth;
        double circumference = 2 * (length + breadth);
        
        System.out.println("Area of rectangle: " + area);
        System.out.println("Circumference of rectangle: " + circumference);
        
        scanner.close();
    }
}