#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct {
    int top;
    char arr[STACK_SIZE];
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, char elem) {
    if (stack->top < STACK_SIZE) {
        stack->arr[++stack->top] = elem;
    } else {
        printf("Overflow\n");
    }
}

char pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->arr[stack->top--];
    }
    return '\0';
}

char peek(Stack *stack) {
    if (stack->top >= 0) {
        return stack->arr[stack->top];
    }
    return '\0';
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

char *preToInfix(const char *pre) {
    Stack s;
    initializeStack(&s);
    char output[STACK_SIZE];
    char final[STACK_SIZE];
    char preCopy[STACK_SIZE];
    strcpy(preCopy, pre);
    reverseString(preCopy);
    int l = strlen(preCopy);
    int outputIndex = 0;

    for (int i = 0; i < l; i++) {
        if (isdigit(preCopy[i]) || isalpha(preCopy[i])) {
            output[outputIndex++] = preCopy[i];
        } else {
            char a = pop(&s);
            char b = pop(&s);
            char exp[3] = { '(', b, preCopy[i] };
            exp[3] = a;
            exp[4] = ')';
            for (int j = 0; exp[j] != '\0'; j++) {
                push(&s, exp[j]);
            }
        }
    }

    while (!isEmpty(&s)) {
        final[outputIndex++] = pop(&s);
    }

    final[outputIndex] = '\0';
    reverseString(final);
    return strdup(final);
}

int getPriority(char c) {
    switch (c) {
        case '-':
        case '+':
            return 1;
        case '*':
        case '/':
            return 2;
        case '$':
        case '^':
            return 3;
        default:
            return 0;
    }
}

char *infixToPostfix(const char *infix) {
    int l = strlen(infix);
    char output[STACK_SIZE];
    Stack s;
    initializeStack(&s);
    int outputIndex = 0;

    for (int i = 0; i < l; i++) {
        if (isalpha(infix[i]) || isdigit(infix[i])) {
            output[outputIndex++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (peek(&s) != '(') {
                output[outputIndex++] = pop(&s);
            }
            pop(&s); // Remove the '(' from the stack
        } else {
            while (getPriority(infix[i]) <= getPriority(peek(&s))) {
                output[outputIndex++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }

    output[outputIndex] = '\0';
    return strdup(output);
}

int main() {
    char inp[STACK_SIZE];
    printf("Enter the expression: ");
    scanf("%s", inp);
    char *infixResult = preToInfix(inp);
    char *postfixResult = infixToPostfix(infixResult);
    printf("Postfix Expression: %s\n", postfixResult);

    free(infixResult);
    free(postfixResult);

    return 0;
}

