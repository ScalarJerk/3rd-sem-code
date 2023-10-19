#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define STACK_SIZE 100

struct Stack {
    int top;
    int arr[STACK_SIZE];
};

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

void push(struct Stack* stack, int elem) {
    if (stack->top < STACK_SIZE) {
        stack->arr[++stack->top] = elem;
    } else {
        printf("Overflow\n");
    }
}

int pop(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->arr[stack->top--];
    }
    printf("Stack Underflow!\n");
    return -1;
}

int peek(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->arr[stack->top];
    } else {
        printf("Underflow\n");
        return -1;
    }
}

int Operator(char ch, int b, int a) {
    switch (ch) {
        case '*': return a * b;
        case '+': return a + b;
        case '-': return a - b;
        case '/': return a / b;
        case '$':
        case '^': return (int)pow(a, b);
        default:
            return 0;
    }
}

int postEval(const char* post) {
    int l = 0;
    while (post[l] != '\0') {
        l++;
    }

    struct Stack s;
    initializeStack(&s);

    for (int i = 0; i < l; i++) {
        if (isdigit(post[i])) {
            push(&s, post[i] - '0');
        } else {
            push(&s, Operator(post[i], pop(&s), pop(&s)));
        }
    }

    return peek(&s);
}

int main() {
    char s[STACK_SIZE];
    printf("Enter expression: ");
    scanf("%s", s);
    int result = postEval(s);
    printf("%d\n", result);
    return 0;
}

