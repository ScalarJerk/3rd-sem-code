/* Write a C program to check for matching 
parenthesis in a given expression.*/
  
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

bool areParenthesesMatching(const char expression[]) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(&stack)) {
                return false; // Unmatched closing parenthesis
            }
            
            char topChar = pop(&stack);
            if ((expression[i] == ')' && topChar != '(') ||
                (expression[i] == ']' && topChar != '[') ||
                (expression[i] == '}' && topChar != '{')) {
                return false; // Mismatched parenthesis
            }
        }
    }

    return isEmpty(&stack); // True if all parentheses are matched
}

int main() {
    char expression[MAX_SIZE];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (areParenthesesMatching(expression)) {
        printf("Parentheses are matched.\n");
    } else {
        printf("Parentheses are not matched.\n");
    }

    return 0;
}
