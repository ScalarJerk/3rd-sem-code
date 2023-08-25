/**
 * This class represents an employee's salary calculation.
 */
class Employee {
    String name, city;
    double basic, daPercentage, hraPercentage;

    // Constructor to initialize employee data
    Employee(String n, String c, double b, double da, double hra) {
        name = n;
        city = c;
        basic = b;
        daPercentage = da;
        hraPercentage = hra;
    }

    // Method to calculate total salary
    double calculateTotalSalary() {
        double total = basic + basic * (daPercentage / 100) + basic * (hraPercentage / 100);
        return total;
    }
    
    // Method to display employee details
    void display() {
        System.out.println("Employee: " + name);
        System.out.println("City: " + city);
        System.out.println("Total Salary: " + calculateTotalSalary());
    }
}

public class Main {
    public static void main(String[] args) {
        // Create an Employee object
        Employee emp = new Employee("John", "New York", 5000.0, 10.0, 15.0);

        // Display employee details
        emp.display();
    }
}
