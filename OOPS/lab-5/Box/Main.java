/**
 * This class represents a box with dimensions (width, height, depth).
 */
class Box {
    double width, height, depth;

    // Constructor to initialize dimensions
    Box(double w, double h, double d) {
        width = w;
        height = h;
        depth = d;
    }

    // Method to calculate volume
    double calculateVolume() {
        return width * height * depth;
    }
}

public class Main {
    public static void main(String[] args) {
        // Create a Box object with dimensions
        Box box = new Box(5.0, 3.0, 2.0);

        // Calculate and print the volume
        double volume = box.calculateVolume();
        System.out.println("Volume of the box: " + volume);
    }
}
