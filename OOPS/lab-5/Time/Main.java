/**
 * This class represents time in hours, minutes, and seconds.
 */
class Time {
    int hours, minutes, seconds;

    // Constructor to initialize time to zero
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    // Constructor to initialize time with given values
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    // Method to display time in hh:mm:ss format
    void displayTime() {
        System.out.println(hours + ":" + minutes + ":" + seconds);
    }

    // Method to add two Time objects
    Time addTime(Time other) {
        Time result = new Time();
        result.seconds = this.seconds + other.seconds;
        result.minutes = this.minutes + other.minutes + result.seconds / 60;
        result.seconds %= 60;
        result.hours = this.hours + other.hours + result.minutes / 60;
        result.minutes %= 60;
        return result;
    }
}

public class Main {
    public static void main(String[] args) {
        // Create two Time objects
        Time time1 = new Time(3, 45, 30);
        Time time2 = new Time(1, 30, 15);

        // Add and display the result
        Time sum = time1.addTime(time2);
        System.out.print("Time 1: ");
        time1.displayTime();
        System.out.print("Time 2: ");
        time2.displayTime();
        System.out.print("Sum: ");
        sum.displayTime();
    }
}
