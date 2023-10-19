#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 100

typedef struct {
    int top;
    char arr[STACK_SIZE][STACK_SIZE];
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, const char *elem) {
    if (s->top < STACK_SIZE - 1) {
        strcpy(s->arr[++s->top], elem);
    } else {
        printf("Stack Overflow!\n");
        exit(1);
    }
}

char *pop(Stack *s) {
    if (s->top >= 0) {
        return s->arr[s->top--];
    }
    printf("Underflow!\n");
    exit(1);
}

char *peek(Stack *s) {
    if (s->top >= 0) {
        return s->arr[s->top];
    }
    printf("Underflow!\n");
    exit(1);
}

char *pretoInfix(const char *pre) {
    Stack s;
    initializeStack(&s);
    char output[STACK_SIZE];
    int l = strlen(pre);

    for (int i = 0; i < l; i++) {
        if (isdigit(pre[i]) || isalpha(pre[i])) {
            char elem[2];
            elem[0] = pre[i];
            elem[1] = '\0';
            push(&s, elem);
        } else {
            char a[STACK_SIZE], b[STACK_SIZE], exp[STACK_SIZE];
            strcpy(a, pop(&s));
            strcpy(b, pop(&s));
            snprintf(exp, STACK_SIZE, ")%s%c%s(", b, pre[i], a);
            push(&s, exp);
        }
    }
    strcpy(output, pop(&s));

    return strdup(output);
}

int main() {
    char inp[STACK_SIZE];
    printf("Enter the expression: ");
    scanf("%s", inp);
    char *result = pretoInfix(inp);
    printf("%s\n", result);
    free(result);
    return 0;
}
