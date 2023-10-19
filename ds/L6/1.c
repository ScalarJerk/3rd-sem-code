#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 100

typedef struct {
    int top;
    char arr[STACK_SIZE];
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char elem) {
    if (s->top < STACK_SIZE) {
        s->arr[++s->top] = elem;
    } else {
        printf("Overflow\n");
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        return s->arr[s->top--];
    }
    return '\0';
}

char peek(Stack *s) {
    if (s->top >= 0) {
        return s->arr[s->top];
    }
    return '\0';
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

char getPriority(char c) {
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

void pretoInfix(const char *pre, char *final) {
    Stack s;
    initialize(&s);
    int l = strlen(pre);
    int j = 0;
    for (int i = l - 1; i >= 0; i--) {
        if (isdigit(pre[i]) || isalpha(pre[i])) {
            final[j++] = pre[i];
        } else {
            char a = pop(&s);
            char b = pop(&s);
            final[j++] = ')';
            final[j++] = b;
            final[j++] = pre[i];
            final[j++] = a;
            final[j++] = '(';
            push(&s, final[j - 1]);
        }
    }
    final[j] = '\0';
}

void infixtoPostfix(const char *infix, char *output) {
    Stack s;
    initialize(&s);
    int l = strlen(infix);
    int j = 0;
    for (int i = 0; i < l; i++) {
        if (isalpha(infix[i]) || isdigit(infix[i])) {
            output[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (peek(&s) != '(') {
                output[j++] = pop(&s);
            }
            pop(&s);
        } else {
            while (getPriority(infix[i]) <= getPriority(peek(&s))) {
                output[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    output[j] = '\0';
}

int main() {
    char inp[STACK_SIZE];
    printf("Enter the expression: ");
    scanf("%s", inp);
    
    char infix[2 * STACK_SIZE]; // Infix can be larger than the input expression
    pretoInfix(inp, infix);
    
    char postfix[2 * STACK_SIZE]; // Postfix can be larger than the infix expression
    infixtoPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}

