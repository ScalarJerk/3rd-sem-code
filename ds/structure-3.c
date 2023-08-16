/*Write a C program to write the 
students’ records (Name, Roll No., Grade, Branch) 
into a text file. Read the text 
file and store the student records 
branchwise in separate 
files.*/
  
  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_BRANCHES 10

struct Student {
    char name[50];
    int rollNo;
    char grade;
    char branch[50];
};

void writeStudentRecords(FILE *file, struct Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%s %d %c %s\n", students[i].name, students[i].rollNo, students[i].grade, students[i].branch);
    }
}

void storeRecordsByBranch(struct Student students[], int numStudents) {
    FILE *branchFiles[MAX_BRANCHES] = { NULL };
    
    for (int i = 0; i < numStudents; i++) {
        char fileName[50];
        sprintf(fileName, "%s.txt", students[i].branch);

        if (branchFiles[i] == NULL) {
            branchFiles[i] = fopen(fileName, "w");
            if (branchFiles[i] == NULL) {
                perror("Unable to create file");
                exit(1);
            }
        }

        fprintf(branchFiles[i], "%s %d %c %s\n", students[i].name, students[i].rollNo, students[i].grade, students[i].branch);
    }

    for (int i = 0; i < MAX_BRANCHES; i++) {
        if (branchFiles[i] != NULL) {
            fclose(branchFiles[i]);
        }
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNo);
        printf("Grade: ");
        scanf(" %c", &students[i].grade);
        printf("Branch: ");
        scanf("%s", students[i].branch);
    }

    FILE *studentFile = fopen("student_records.txt", "w");
    if (studentFile == NULL) {
        perror("Unable to create file");
        return 1;
    }

    writeStudentRecords(studentFile, students, numStudents);
    fclose(studentFile);
    printf("Student records written to student_records.txt\n");

    storeRecordsByBranch(students, numStudents);
    printf("Student records stored branch-wise in separate files.\n");

    return 0;
}
