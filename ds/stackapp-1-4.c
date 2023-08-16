/* Write a program to implement
 queue data structure using stack.
*/
  
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

struct Queue {
    struct Stack s1, s2;
};

void initializeQueue(struct Queue *queue) {
    initialize(&queue->s1);
    initialize(&queue->s2);
}

void enqueue(struct Queue *queue, int item) {
    if (isFull(&queue->s1)) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }

    while (!isEmpty(&queue->s1)) {
        push(&queue->s2, pop(&queue->s1));
    }

    push(&queue->s1, item);

    while (!isEmpty(&queue->s2)) {
        push(&queue->s1, pop(&queue->s2));
    }
}

int dequeue(struct Queue *queue) {
    if (isEmpty(&queue->s1)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    return pop(&queue->s1);
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 5);
    enqueue(&queue, 10);
    enqueue(&queue, 15);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    return 0;
}
