import java.io.*;
import java.util.*;

/**
 * This class represents a book with title, author, and edition.
 */
class Book {
    String title, author, edition;

    // Constructor to initialize book data
    Book(String t, String a, String e) {
        title = t;
        author = a;
        edition = e;
    }

    // Method to write book details to a file
    void writeTo(FileWriter writer) throws IOException {
        writer.write(title + "," + author + "," + edition + "\n");
    }
}

public class Main {
    public static void main(String[] args) {
        ArrayList<Book> books = new ArrayList<>();
        books.add(new Book("Book 1", "Harry", "1st Edition"));
        books.add(new Book("Book 2", "Tom", "2nd Edition"));
        books.add(new Book("Book 3", "Harry", "3rd Edition"));
        books.add(new Book("Book 4", "Sam", "1st Edition"));
        books.add(new Book("Book 5", "Kate", "2nd Edition"));
        books.add(new Book("Book 6", "Harry", "2nd Edition"));

        try {
            FileWriter writer = new FileWriter("books.txt");
            for (Book book : books) {
                book.writeTo(writer);
            }
            writer.close();

            BufferedReader reader = new BufferedReader(new FileReader("books.txt"));
            String line;
            System.out.println("Books by author 'Harry':");
            while ((line = reader.readLine()) != null) {
                String[] data = line.split(",");
                if (data[1].equals("Harry")) {
                    System.out.println("Title: " + data[0] + ", Author: " + data[1] + ", Edition: " + data[2]);
                }
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
