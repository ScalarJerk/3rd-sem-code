import java.util.ArrayList;
import java.util.EmptyStackException;

public class Stack<T> {
    private ArrayList<T> stack;

    public Stack() {
        stack = new ArrayList<T>();
    }

    // Push an item onto the stack
    public void push(T item) {
        stack.add(item);
    }

    // Pop an item from the stack
    public T pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        int lastIndex = stack.size() - 1;
        T item = stack.get(lastIndex);
        stack.remove(lastIndex);
        return item;
    }

    // Peek at the top item of the stack without removing it
    public T peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return stack.get(stack.size() - 1);
    }

    // Check if the stack is empty
    public boolean isEmpty() {
        return stack.isEmpty();
    }

    // Get the size of the stack
    public int size() {
        return stack.size();
    }

    // Clear the stack
    public void clear() {
        stack.clear();
    }

    // Display the stack elements
    public void display() {
        System.out.print("Stack (top to bottom): ");
        for (int i = stack.size() - 1; i >= 0; i--) {
            System.out.print(stack.get(i) + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<Integer>();

        stack.push(1);
        stack.push(2);
        stack.push(3);

        System.out.println("Top element: " + stack.peek());
        System.out.println("Stack size: " + stack.size());

        System.out.println("Popping elements:");
        while (!stack.isEmpty()) {
            System.out.println(stack.pop());
        }
    }
}
