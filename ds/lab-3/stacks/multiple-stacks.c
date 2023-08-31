#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_X 5
#define MAX_Y 5

// Function to push an item onto stack x
void pushStackX(int *stackX, int *topX) {
    int info;

    if (*topX >= (MAX_X - 1)) {
        printf("\n\nStack X Overflow");
        return;
    } else {
        printf("\n\nEnter the value to push onto Stack X: ");
        scanf("%d", &info);
        (*topX)++;
        stackX[*topX] = info;
    }
}

// Function to push an item onto stack y
void pushStackY(int *stackY, int *topY) {
    int info;

    if (*topY <= MAX_Y) {
        printf("\n\nStack Y Overflow");
        return;
    } else {
        printf("\n\nEnter the value to push onto Stack Y: ");
        scanf("%d", &info);
        (*topY)--;
        stackY[*topY] = info;
    }
}

// Function to pop an item from stack x
void popStackX(int *stackX, int *topX) {
    if (*topX == -1) {
        printf("Stack X Underflow\n");
        return;
    } else {
        printf("Item popped from Stack X: %d\n", stackX[*topX]);
        (*topX)--;
    }
}

// Function to pop an item from stack y
void popStackY(int *stackY, int *topY) {
    if (*topY == 10) {
        printf("Stack Y Underflow\n");
        return;
    } else {
        printf("Item popped from Stack Y: %d\n", stackY[*topY]);
        (*topY)++;
    }
}

// Function to display stack x
void displayStackX(int *stackX, int topX) {
    if (topX == -1) {
        printf("Stack X is Empty\n");
        return;
    } else {
        printf("Stack X: ");
        for (int i = topX; i >= 0; i--) {
            printf("%d, ", stackX[i]);
        }
        printf("\n");
    }
}

// Function to display stack y
void displayStackY(int *stackY, int topY) {
    if (topY == 10) {
        printf("Stack Y is Empty\n");
        return;
    } else {
        printf("Stack Y: ");
        for (int i = topY; i <= 9; i++) {
            printf("%d, ", stackY[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    char ch;
    int stackX[MAX_X + MAX_Y];
    int stackY[MAX_X + MAX_Y];
    int topX = -1; // Initialize top index of stack x
    int topY = 10; // Initialize top index of stack y

    do {
        printf("1. Push to Stack X\n2. Push to Stack Y\n");
        printf("3. Pop from Stack X\n4. Pop from Stack Y\n");
        printf("5. Display Stack X\n6. Display Stack Y\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: pushStackX(stackX, &topX); break;
            case 2: pushStackY(stackY, &topY); break;
            case 3: popStackX(stackX, &topX); break;
            case 4: popStackY(stackY, &topY); break;
            case 5: displayStackX(stackX, topX); break;
            case 6: displayStackY(stackY, topY); break;
            case 7: break;
            default: printf("Invalid Option...\n");
        }
        printf("\n");
    } while (choice != 7);

    return 0;
}
