#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to return precedence of operators
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix expression to postfix expression
char* infixToPostfix(char* infix) {
    int i, j;
    int len = strlen(infix);
    char* postfix = (char*)malloc(sizeof(char) * (len + 2));
    char stack[MAX_SIZE];
    int top = -1;

    for (i = 0, j = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;

        // If the scanned character is an operand, add it to the postfix expression
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        // If the scanned character is '(', push it onto the stack
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }

        // If the scanned character is ')', pop the stack and add to output until '(' is found
        else if (infix[i] == ')') {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else
                top--;
        }

        // If the scanned character is an operator, push it onto the stack
        else if (isOperator(infix[i])) {
            while (top > -1 && getPrecedence(stack[top]) >= getPrecedence(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }

    // Pop all remaining elements from the stack
    while (top > -1) {
        if (stack[top] == '(') {
            return "Invalid Expression";
        }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char infix[MAX_SIZE];
    char repeat;

    do {
        printf("Enter an infix expression: ");
        fgets(infix, MAX_SIZE, stdin);

        // Remove newline character from the input
        int len = strlen(infix);
        if (len > 0 && infix[len - 1] == '\n') {
            infix[len - 1] = '\0';
        }

        // Function call
        char* postfix = infixToPostfix(infix);
        printf("Postfix expression: %s\n", postfix);
        free(postfix);

        printf("Do you want to enter another input? (y/n): ");
        scanf(" %c", &repeat);  // Allowing space before %c to consume any previous newline
        getchar();  // Consume the newline character left in the input buffer

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
