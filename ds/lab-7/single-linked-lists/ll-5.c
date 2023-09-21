/*Write a program to implement
 stack & queue using Singly linked lists.*/
   
   #include <stdio.h>
#include <stdlib.h>

// Structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Structure for a stack
struct Stack {
    struct Node* top;
};

// Structure for a queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize an empty stack
void initStack(struct Stack* stack) {
    stack->top = NULL;
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    
    int value = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

// Initialize an empty queue
void initQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}

// Enqueue an element into the queue
void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    int value = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return value;
}

int main() {
    // Implement and test the stack and queue here
    struct Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Popped from stack: %d\n", pop(&stack));
    
    struct Queue queue;
    initQueue(&queue);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    enqueue(&queue, 60);
    printf("Dequeued from queue: %d\n", dequeue(&queue));

    return 0;
}
