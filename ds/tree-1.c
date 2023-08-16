/*Write user defined functions to perform the following operations on binary trees.
i.) In order traversal (Iterative)
ii.) Post order traversal (Iterative)
iii.) Preorder traversal(Iterative)
iv.) Print the parent of the given element
v.) Print the depth of the tree
vi.) Print the ancestors of a given element
vii.) Count the number of leaf nodes in a binary tree */
  
  #include <stdio.h>
#include <stdlib.h>

struct Node {
    int machineNumber;
    int remainingTime;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int machineNumber, int remainingTime) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->machineNumber = machineNumber;
    newNode->remainingTime = remainingTime;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Node** head, int machineNumber, int time) {
    struct Node* newNode = createNode(machineNumber, time);

    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
}

void dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("No machines in queue.\n");
        return;
    }

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        *head = (*head)->next;
        (*head)->prev = temp->prev;
        temp->prev->next = *head;
        free(temp);
    }
}

void displayQueue(struct Node* head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("Machine %d (Time Remaining: %d minutes)\n", current->machineNumber, current->remainingTime);
        current = current->next;
    } while (current != head);
}

void simulateTimePassing(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    (*head)->remainingTime--;

    if ((*head)->remainingTime == 0) {
        printf("Machine %d has finished. Next machine in queue:\n", (*head)->machineNumber);
        dequeue(head);
        displayQueue(*head);
    }
}

int main() {
    struct Node* head = NULL;

    while (1) {
        int choice;
        printf("\nMenu:\n");
        printf("1. Book Washing Machine\n");
        printf("2. Display Queue\n");
        printf("3. Simulate Time Passing\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int machineNumber, time;
                printf("Enter machine number: ");
                scanf("%d", &machineNumber);
                printf("Enter time duration (in minutes): ");
                scanf("%d", &time);
                enqueue(&head, machineNumber, time);
                break;
            case 2:
                displayQueue(head);
                break;
            case 3:
                simulateTimePassing(&head);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    // Clean up memory by freeing the nodes

    return 0;
}
