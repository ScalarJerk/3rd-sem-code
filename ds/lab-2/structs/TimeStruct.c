/* Define a structure time with data members hour, min, sec. Write the user defined
functions to (i) Add (ii) To find difference between two objects of class time.
Functions take two-time objects as argument and return time object. Also write the
display and read function.
*/

#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_OBJECTS 50

// Structure definition
struct Time {
    int hour;
    int min;
    int sec;
};

// Function to take in time input
void readTime(struct Time timeObject[]) {
    for (int i = 0; i < 2; i++) {
        printf("Enter details for time %d:\n", i + 1);
        printf("Hour: ");
        scanf("%d", &timeObject[i].hour);
        printf("Minute: ");
        scanf("%d", &timeObject[i].min);
        printf("Second: ");
        scanf(" %d", &timeObject[i].sec);
    }
}

// Function to display student information
void displayTime(struct Time timeObject[]) {
    printf("Time:\n");

    for (int i = 0; i < 2; i++) {
        printf("%d : %d : %d\n", timeObject[i].hour, timeObject[i].min, timeObject[i].sec);
    }
}

// Function to add two time objects
void addTime(struct Time timeObject[]){
    int sumHour=0,sumMin=0,sumSec=0;
    sumHour =timeObject[1].hour+timeObject[0].hour;
    sumMin =timeObject[1].min+timeObject[0].min;
    sumSec =timeObject[1].sec+timeObject[0].sec;

    printf("Resultant time\n");
    printf("%d : %d : %d",sumHour,sumMin,sumSec);
}

// Function to find difference between two time objects
void diffTime(struct Time timeObject[]) {
    int diffHour=0,diffMin=0,diffSec=0;

    diffHour =timeObject[1].hour-timeObject[0].hour;
    diffMin =timeObject[1].min-timeObject[0].min;
    diffSec =timeObject[1].sec-timeObject[0].sec;

    printf("Resultant time\n");
    printf("%d : %d : %d",diffHour,diffMin,diffSec);
}

int main() {
    struct Time timeObject[MAX_OBJECTS];

    readTime(timeObject);

    int option;
    printf("Choose operation\n");
    printf("1. Add time objects\n");
    printf("2. Subtract time objects");
    scanf("%d",&option);

    switch(option){

    case 1:
        addTime(timeObject);
        break;
    case 2:
        diffTime(timeObject);
        break;
    default:
        printf("Not available");
    }

    return 0;
}
