/*Write a menu driven program to:
ii) Insert an element 
into a doubly linked circular list
iii) Delete an element from a doubly 
linked circular list. */
 
 #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
}

void delete(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = *head;
    while (current->data != value) {
        current = current->next;
        if (current == *head) {
            printf("Element not found.\n");
            return;
        }
    }

    if (current->next == current) {
        *head = NULL;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        if (current == *head) {
            *head = current->next;
        }
    }

    free(current);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(&head, value);
                break;
            case 3:
                printf("List: ");
                displayList(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    // Clean up memory by freeing the nodes

    return 0;
}
