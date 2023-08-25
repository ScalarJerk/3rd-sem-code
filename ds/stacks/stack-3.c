/* Write a C program to implement 
Multiple stacks using arrays.*/
  
  #include <stdio.h>
#include <stdbool.h>

#define MAX_STACKS 10
#define MAX_SIZE 100

struct MultiStack {
    int top[MAX_STACKS];
    int items[MAX_STACKS][MAX_SIZE];
};

void initialize(struct MultiStack *stacks) {
    for (int i = 0; i < MAX_STACKS; i++) {
        stacks->top[i] = -1;
    }
}

bool isFull(struct MultiStack *stacks, int stackNum) {
    return stacks->top[stackNum] == MAX_SIZE - 1;
}

bool isEmpty(struct MultiStack *stacks, int stackNum) {
    return stacks->top[stackNum] == -1;
}

void push(struct MultiStack *stacks, int stackNum, int item) {
    if (isFull(stacks, stackNum)) {
        printf("Stack %d is full. Cannot push element.\n", stackNum);
    } else {
        stacks->items[stackNum][++stacks->top[stackNum]] = item;
    }
}

int pop(struct MultiStack *stacks, int stackNum) {
    if (isEmpty(stacks, stackNum)) {
        printf("Stack %d is empty. Cannot pop element.\n", stackNum);
        return -1;
    } else {
        return stacks->items[stackNum][stacks->top[stackNum]--];
    }
}

int main() {
    struct MultiStack stacks;
    initialize(&stacks);

    push(&stacks, 0, 5);
    push(&stacks, 1, 10);
    push(&stacks, 0, 7);

    printf("Popped from Stack 0: %d\n", pop(&stacks, 0));
    printf("Popped from Stack 1: %d\n", pop(&stacks, 1));
    printf("Popped from Stack 0: %d\n", pop(&stacks, 0));

    return 0;
}
