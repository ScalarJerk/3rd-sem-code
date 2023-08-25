/*Write a C program to check whether a given 
string is a palindrome or not using stacks.*/
  
  #include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
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

bool isPalindrome(char str[]) {
    struct Stack stack;
    initialize(&stack);

    int length = strlen(str);
    int i;

    for (i = 0; i < length / 2; i++) {
        push(&stack, str[i]);
    }

    if (length % 2 != 0) {
        i++;
    }

    while (str[i] != '\0') {
        char ch = pop(&stack);
        if (ch != str[i]) {
            return false;
        }
        i++;
    }

    return isEmpty(&stack);
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}
