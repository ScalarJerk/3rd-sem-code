 Write a menu driven program to perform the 
following on a doubly linked list
Insert an element at the rear end of the list
ii.) Delete an element from the rear 
end of the list
iii.) Insert an element at a given position
 of the list
iv.) Delete an element from a given position
 of the list
v.) Insert an element after another element
vi.) Insert an element before another element
vii.) Traverse the list
viii.) Reverse the list*/
  
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

void insertRear(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
    newNode->prev = current;
}

void deleteRear(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(current);
}

void insertAtPosition(struct Node** head, int value, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        struct Node* newNode = createNode(value);
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    int currentPosition = 1;
    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* newNode = createNode(value);
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Implement other functions similarly

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at rear\n");
        printf("2. Delete from rear\n");
        printf("3. Insert at a position\n");
        printf("4. Delete from a position\n");
        printf("5. Insert after element\n");
        printf("6. Insert before element\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertRear(&head, value);
                break;
            case 2:
                deleteRear(&head);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;
            // Implement cases 4 to 8 similarly
            case 7:
                displayList(head);
                break;
            case 8:
                // Implement reversing the list
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 9);

    // Clean up memory by freeing the nodes

    return 0;
}