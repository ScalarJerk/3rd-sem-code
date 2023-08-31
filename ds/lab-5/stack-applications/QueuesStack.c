#include <stdio.h>
#include <stdlib.h>

// Global variables
int stack1[100], stack2[100]; // Stacks to simulate queues
int top1 = -1, top2 = -1;     // Top pointers for the stacks
int itemCount = 0;            // Number of elements in the queue

int main()
{
    int choice;
    int num;

    printf("\n1 - Enqueue element into queue");
    printf("\n2 - Dequeue element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");

    initialize(); // Initialize the stacks

    do
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice");
        }
    } while (1);

    return 0;
}

// Function to initialize the stacks
void initialize()
{
    top1 = top2 = -1;
}

// Function to push an element onto the stack
void push(int stack[], int *top, int data)
{
    stack[++(*top)] = data;
}

// Function to pop an element from the stack
int pop(int stack[], int *top)
{
    return stack[(*top)--];
}

// Function to add an element into the queue using stacks
void enqueue()
{
    int data;
    printf("Enter data to enqueue: ");
    scanf("%d", &data);
    push(stack1, &top1, data);
    itemCount++;
}

// Function to delete an element from the queue using stacks
void dequeue()
{
    int i;

    for (i = 0; i < itemCount; i++)
    {
        push(stack2, &top2, pop(stack1, &top1));
    }

    pop(stack2, &top2);
    itemCount--;

    for (i = 0; i < itemCount; i++)
    {
        push(stack1, &top1, pop(stack2, &top2));
    }
}

// Function to display the elements in the queue
void display()
{
    int i;

    for (i = 0; i <= top1; i++)
    {
        printf(" %d ", stack1[i]);
    }
}
