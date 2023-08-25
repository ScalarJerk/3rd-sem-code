/* Write a program that converts 
a post fix expression to a fully 
parenthesized infix 
expression.*/
  
  #include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int items[MAX_SIZE];
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

void push(struct Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
    } else {
        stack->items[++stack->top] = item;
    }
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    } else {
        return stack->items[stack->top--];
    }
}

int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initialize(&stack);

    int i = 0;
    while (postfix[i] != '\0') {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(&stack, postfix[i] - '0'); // Convert char digit to integer
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            
            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
        i++;
    }

    return pop(&stack);
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
