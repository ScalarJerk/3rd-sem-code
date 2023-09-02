package Swap;

public class SwapByReference {
    public static void main(String[] args) {
        int[] arr = { 5 };
        int[] arr2 = { 10 };

        System.out.println("Before swapping - arr: " + arr[0] + ", arr2: " + arr2[0]);

        // Call the swap method with call by reference
        swapByReference(arr, arr2);

        System.out.println("After swapping - arr: " + arr[0] + ", arr2: " + arr2[0]);
    }

    public static void swapByReference(int[] x, int[] y) {
        int temp = x[0];
        x[0] = y[0];
        y[0] = temp;
    }
}
