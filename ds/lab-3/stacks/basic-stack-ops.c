/*
    This program implements a menu-based stack using a structure to represent the stack.
    It provides options to push, pop, and peek at the top item of the stack.

    Algorithm:
    1. Define a structure 'Stack' with an array of items and a top index.
    2. Initialize the stack top to -1 to indicate an empty stack.
    3. Implement functions to check if the stack is empty or full.
    4. Implement push function to add items to the stack.
    5. Implement pop function to remove and return the top item from the stack.
    6. Implement peek function to return the top item without removing it.
    7. Create a menu-driven loop to interact with the stack using switch-case.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Initialize stack
void initStack(struct Stack *stack) {
    stack->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Check if stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push item onto stack
void push(struct Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow, cannot push %d\n", item);
        return;
    }
    stack->top++;
    stack->items[stack->top] = item;
}

// Pop item from stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
        return -1; // Return an error value
    }
    int poppedItem = stack->items[stack->top];
    stack->top--;
    return poppedItem;
}

// Peek at top item of stack
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot peek\n");
        return -1; // Return an error value
    }
    return stack->items[stack->top];
}

int main() {
    struct Stack stack;
    initStack(&stack);
    int choice, item;

    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(&stack, item);
                break;

            case 2:
                item = pop(&stack);
                if (item != -1)
                    printf("Popped item: %d\n", item);
                break;

            case 3:
                item = peek(&stack);
                if (item != -1)
                    printf("Top item: %d\n", item);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice!=4);

    return 0;
}
