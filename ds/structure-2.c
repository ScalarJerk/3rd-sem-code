/* Write a C program to define a structure
 student with the data members to store name, 
roll no and grade of the student. 
Also write the member functions to read, display, 
and 
sort student information according to
 the roll number of the student. All the member 
functions will have array of objects as arguments.
*/
  
  #include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

// Structure definition
struct student {
    char name[50];
    int rollNo;
    char grade;
};

// Function to read student information
void readStudents(struct student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNo);
        printf("Grade: ");
        scanf(" %c", &students[i].grade);
    }
}

// Function to display student information
void displayStudents(struct student students[], int numStudents) {
    printf("Student Information:\n");
    printf("%-20s %-10s %-6s\n", "Name", "Roll No", "Grade");
    printf("----------------------------------------------\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%-20s %-10d %-6c\n", students[i].name, students[i].rollNo, students[i].grade);
    }
}

// Function to sort students by roll number using bubble sort
void sortStudents(struct student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                struct student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct student students[MAX_STUDENTS];
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    readStudents(students, numStudents);
    
    printf("\nBefore sorting:\n");
    displayStudents(students, numStudents);

    sortStudents(students, numStudents);

    printf("\nAfter sorting by roll number:\n");
    displayStudents(students, numStudents);

    return 0;
}
