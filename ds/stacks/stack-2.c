/* Write a C program to convert a given decimal number to a number in any base using stack.*/
  
  #include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int items[MAX_SIZE];
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

bool isFull(struct Stack *stack) {
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

void decimalToBase(int decimalNumber, int base) {
    struct Stack stack;
    initialize(&stack);

    while (decimalNumber > 0) {
        int remainder = decimalNumber % base;
        push(&stack, remainder);
        decimalNumber /= base;
    }

    printf("Equivalent number in base %d: ", base);
    while (!isEmpty(&stack)) {
        int digit = pop(&stack);
        printf("%d", digit);
    }
    printf("\n");
}

int main() {
    int decimalNumber, base;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Enter the base (2 to 16): ");
    scanf("%d", &base);

    if (base >= 2 && base <= 16) {
        decimalToBase(decimalNumber, base);
    } else {
        printf("Invalid base. Please enter a base between 2 and 16.\n");
    }

    return 0;
}
