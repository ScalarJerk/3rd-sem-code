/* Write a menu driven program to 
perform the following operations on linked list.
i) Insert an element before another
 element in the existing list
ii) Insert an element after another
 element in the existing list
iii) Delete a given element from the list
iv) Traverse the list
v) Reverse the list
vi) Sort the list
vii) Delete every alternate node in the list
viii) Insert an element in a sorted 
list such that the order is maintained.

*/
  
  #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertBefore(int value, int target) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        printf("List is empty. Inserting as first node.\n");
        newNode->next = NULL;
        head = newNode;
        return;
    }

    if (head->data == target) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data != target) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element not found in the list.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void insertAfter(int value, int target) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* current = head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found in the list.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteElement(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element not found in the list.\n");
        return;
    }

    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void traverse() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void reverse() {
    struct Node *prev = NULL, *current = head, *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
}

void sort() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void deleteAlternate() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }
}

void insertInSorted(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || value < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    int choice, value, target;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert before an element\n");
        printf("2. Insert after an element\n");
        printf("3. Delete an element\n");
        printf("4. Traverse the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert an element in sorted order\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                printf("Enter the element before which to insert: ");
                scanf("%d", &target);
                insertBefore(value, target);
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                printf("Enter the element after which to insert: ");
                scanf("%d", &target);
                insertAfter(value, target);
                break;
            case 3:
                printf("Enter the element to be deleted: ");
                scanf("%d", &value);
                deleteElement(value);
                break;
            case 4:
                traverse();
                break;
            case 5:
                reverse();
                printf("List reversed.\n");
                break;
            case 6:
                sort();
                printf("List sorted.\n");
                break;
            case 7:
                deleteAlternate();
                printf("Alternate nodes deleted.\n");
                break;
            case 8:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insertInSorted(value);
                printf("Element inserted in sorted order.\n");
                break;
            case 9:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    }

    return 0;
}