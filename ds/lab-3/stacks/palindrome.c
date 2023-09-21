// Palindrome Checker using Stack
// This program checks if a given string is a palindrome or not by using a stack data structure.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int top = -1;
char stack[MAX];

// Function to push characters onto the stack
void Push(char c) {
    if (top < MAX - 1) {
        top++;
        stack[top] = c;
    }
}

// Function to pop a character from the stack
char Pop() {
    if (top >= 0) {
        char c = stack[top];
        top--;
        return c;
    }
    return '\0';
}

int main() {
    char s[100];
    int flag = 1;

    printf("Enter a string to check if it's a palindrome:\n");
    scanf("%s", s);

    int length = strlen(s);

    // Push the characters of the string onto the stack
    for (int i = 0; i < length; i++) {
        Push(s[i]);
    }

    int i = 0;

    // Compare characters from the stack with the original string
    while (top >= 0) {
        char stackChar = Pop();

        if (stackChar != s[i]) {
            printf("\nEntered String is Not a Palindrome.\n");
            flag = 0;
            break;
        }

        i++;
    }

    if (flag == 1) {
        printf("\nEntered String is a Palindrome.\n");
    }

    return 0;
}
