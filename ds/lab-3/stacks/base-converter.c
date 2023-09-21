/* This program provides a menu-based interface for converting and printing numbers in different bases.
    It allows the user to input a number and a base, and then converts the number to the specified base, printing the result.
*/
#include <stdio.h>
#include <math.h>

#define MAX_STACK_SIZE 100

int top = -1;
int stack[MAX_STACK_SIZE];

// Function to add an element to the stack
void push(int value) {
    top++;
    if (top < MAX_STACK_SIZE) {
        stack[top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

// Function to convert and print a number in a given base
void convertAndPrint(int num, int base) {
    // Convert the number to the specified base and push remainders onto the stack
    while (num != 0) {
        push(num % base);
        num /= base;
    }

    // Print the converted number
    printf("Converted number: ");
    while (top >= 0) {
        int digit = stack[top--];
        
        if (digit >= 10) {
            // If the digit is greater than 9, print it as a character
            printf("%c", digit + 'A' - 10);
        } else {
            // Print the digit as a number
            printf("%d", digit);
        }
    }
    printf("\n");
}

int main() {
    int choice;
    int num, base;

    // Display a menu for the user
    printf("Menu:\n");
    printf("1. Convert and print a number in a specific base\n");
    printf("2. Exit\n");
    
    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Get the number and base from the user
            printf("Enter a number: ");
            scanf("%d", &num);
            printf("Enter the base: ");
            scanf("%d", &base);

            // Call the conversion function
            convertAndPrint(num, base);
            break;
        
        case 2:
            printf("Exiting the program.\n");
            break;
        
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
