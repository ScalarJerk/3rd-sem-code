/*Write a program to input an infix expression 
and convert into its equivalent prefix 
form and display. Operands can be single character.*/
  
  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
    } else {
        stack->items[++stack->top] = item;
    }
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return '\0';
    } else {
        return stack->items[stack->top--];
    }
}

int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    return 0;
}

void reverse(char str[]) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    struct Stack stack;
    initialize(&stack);

    reverse(infix);

    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        if (infix[i] >= 'a' && infix[i] <= 'z') {
            prefix[j++] = infix[i];
        } else if (infix[i] == ')') {
            push(&stack, infix[i]);
        } else if (infix[i] == '(') {
            while (!isEmpty(&stack) && stack.items[stack.top] != ')') {
                prefix[j++] = pop(&stack);
            }
            pop(&stack); // Pop ')' from the stack
        } else {
            while (!isEmpty(&stack) && precedence(stack.items[stack.top]) >= precedence(infix[i])) {
                prefix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
        i++;
    }

    while (!isEmpty(&stack)) {
        prefix[j++] = pop(&stack);
    }
    prefix[j] = '\0';

    reverse(prefix);
}

int main() {
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s
    