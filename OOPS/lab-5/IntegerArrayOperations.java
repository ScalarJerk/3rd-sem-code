import java.util.Arrays;

public class IntegerArrayOperations {
    private int[] array;

    public IntegerArrayOperations() {
        array = new int[10];
    }

    // Method to input values into the array
    public void inputValues(int[] values) {
        if (values.length != 10) {
            System.out.println("Input array should have exactly 10 values.");
            return;
        }
        array = Arrays.copyOf(values, 10);
    }

    // Method to display the values in the array
    public void displayValues() {
        System.out.println("Array values:");
        for (int value : array) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    // Method to display the largest value in the array
    public void displayLargestValue() {
        int max = array[0];
        for (int i = 1; i < array.length; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        System.out.println("Largest value in the array: " + max);
    }

    // Method to display the average of the values in the array
    public void displayAverage() {
        int sum = 0;
        for (int value : array) {
            sum += value;
        }
        double average = (double) sum / array.length;
        System.out.println("Average of the array values: " + average);
    }

    // Method to sort the array in ascending order
    public void sortAscending() {
        Arrays.sort(array);
        System.out.println("Array sorted in ascending order:");
        displayValues();
    }

    public static void main(String[] args) {
        IntegerArrayOperations arrayOperations = new IntegerArrayOperations();
        int[] inputValues = {5, 9, 2, 7, 1, 8, 3, 6, 4, 10};

        arrayOperations.inputValues(inputValues);
        arrayOperations.displayValues();
        arrayOperations.displayLargestValue();
        arrayOperations.displayAverage();
        arrayOperations.sortAscending();
    }
}
