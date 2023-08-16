/* Write a program that converts 
a prefix expression to a fully parenthesized 
infix 
expression.*/
  
  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE][MAX_SIZE];
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

void push(struct Stack *stack, const char item[]) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
    } else {
        strcpy(stack->items[++stack->top], item);
    }
}

void pop(struct Stack *stack, char result[]) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        strcpy(result, "");
    } else {
        strcpy(result, stack->items[stack->top--]);
    }
}

void prefixToInfix(const char prefix[], char infix[]) {
    struct Stack stack;
    initialize(&stack);

    int length = strlen(prefix);
    for (int i = length - 1; i >= 0; i--) {
        if ((prefix[i] >= 'a' && prefix[i] <= 'z') || (prefix[i] >= 'A' && prefix[i] <= 'Z')) {
            char operand[2] = { prefix[i], '\0' };
            push(&stack, operand);
        } else {
            char operand1[MAX_SIZE], operand2[MAX_SIZE];
            pop(&stack, operand1);
            pop(&stack, operand2);

            char expression[MAX_SIZE];
            snprintf(expression, sizeof(expression), "(%s%c%s)", operand1, prefix[i], operand2);
            push(&stack, expression);
        }
    }

    pop(&stack, infix);
}

int main() {
    char prefix[MAX_SIZE];
    char infix[MAX_SIZE];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    prefixToInfix(prefix, infix);
    printf("Fully parenthesized infix expression: %s\n", infix);

    return 0;
}
