import java.util.ArrayList;

/**
 * This program searches for a value in a 1D array using for-each loop.
 */
public class SearchInArrayForEachLoop {
    public static void main(String[] args) {
        int[] array = {1, 2, 3, 1, 2, 1, 5, 6, 7}; // Change this to your array
        int searchValue = 1; // Change this to the value you want to search
        
        ArrayList<Integer> locations = new ArrayList<>();
        int index = 0;
        
        for (int element : array) {
            if (element == searchValue) {
                locations.add(index);
            }
            index++;
        }
        
        System.out.print("The value is found at locations: ");
        for (int location : locations) {
            System.out.print("a[" + location + "] ");
        }
    }
}
