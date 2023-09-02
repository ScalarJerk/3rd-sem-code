class Result {
    private int[][] marks;  // 2D array to store marks of students and subjects
    private int[] totalMarks;  // 1D array to store total marks of each student

    // Constructor to initialize the arrays
    public Result(int[][] marks) {
        this.marks = marks;
        this.totalMarks = new int[marks.length];
    }

    // Method to store marks of 3 subjects obtained by 3 students in the 2D array
    public void storeMarks(int[][] marks) {
        this.marks = marks;
    }

    // Method to calculate and store total marks obtained by each student in the 1D array
    public void calculateTotalMarks() {
        for (int i = 0; i < marks.length; i++) {
            int total = 0;
            for (int j = 0; j < marks[i].length; j++) {
                total += marks[i][j];
            }
            totalMarks[i] = total;
        }
    }

    // Method to find the highest marks in each subject and the roll number of the student who secured it
    public void findHighestMarks() {
        int[] highestMarks = new int[marks[0].length];
        int[] rollNumbers = new int[marks[0].length];

        for (int j = 0; j < marks[0].length; j++) {
            int maxMarks = marks[0][j];
            int studentRoll = 1;

            for (int i = 1; i < marks.length; i++) {
                if (marks[i][j] > maxMarks) {
                    maxMarks = marks[i][j];
                    studentRoll = i + 1;
                }
            }

            highestMarks[j] = maxMarks;
            rollNumbers[j] = studentRoll;
        }

        System.out.println("Highest marks in each subject:");
        for (int j = 0; j < marks[0].length; j++) {
            System.out.println("Subject " + (j + 1) + ": " + highestMarks[j] + " (Student " + rollNumbers[j] + ")");
        }
    }

    // Method to find the student who obtained the highest total marks
    public void findStudentWithHighestTotalMarks() {
        int maxTotalMarks = totalMarks[0];
        int studentRoll = 1;

        for (int i = 1; i < totalMarks.length; i++) {
            if (totalMarks[i] > maxTotalMarks) {
                maxTotalMarks = totalMarks[i];
                studentRoll = i + 1;
            }
        }

        System.out.println("Student with the highest total marks:");
        System.out.println("Student " + studentRoll + " with a total of " + maxTotalMarks + " marks.");
    }

    public static void main(String[] args) {
        int[][] studentMarks = {
            {85, 90, 78},
            {92, 88, 75},
            {78, 82, 95}
        };

        Result result = new Result(studentMarks);

        result.calculateTotalMarks();
        result.findHighestMarks();
        result.findStudentWithHighestTotalMarks();
    }
}
