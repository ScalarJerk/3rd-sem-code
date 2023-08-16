/* Write a program to evaluate prefix 
expression. The input to the program is a prefix 
expression.*/
  
  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int evaluatePrefix(const char prefix[]) {
    struct Stack stack;
    initialize(&stack);

    int length = strlen(prefix);
    for (int i = length - 1; i >= 0; i--) {
        if (prefix[i] >= '0' && prefix[i] <= '9') {
            push(&stack, prefix[i] - '0'); // Convert char digit to integer
        } else {
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);
            
            switch (prefix[i]) {
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
    }

    return pop(&stack);
}

int main() {
    char prefix[MAX_SIZE];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    int result = evaluatePrefix(prefix);
    printf("Result: %d\n", result);

    return 0;
}
