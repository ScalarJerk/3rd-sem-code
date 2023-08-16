/*Write recursive functions for i) Creating
a linked list ii) Traversing a linked list.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Recursive function to create a linked list
struct Node* createLinkedList() {
    int value;
    struct Node* newNode;

    printf("Enter data (Enter -1 to terminate): ");
    scanf("%d", &value);

    if (value == -1) {
        return NULL;  // Base case: end of list
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = createLinkedList();  // Recursive call
    return newNode;
}

// Recursive function to traverse a linked list
void traverseLinkedList(struct Node* current) {
    if (current == NULL) {
        return;  // Base case: end of list
    }

    printf("%d -> ", current->data);
    traverseLinkedList(current->next);  // Recursive call
}

int main() {
    struct Node* head = NULL;

    printf("Create Linked List:\n");
    head = createLinkedList();

    printf("\nTraverse Linked List:\n");
    traverseLinkedList(head);

    printf("NULL\n");

    return 0;
}
