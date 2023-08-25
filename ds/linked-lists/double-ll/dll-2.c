
/* Write a program to concatenate two doubly linked
 lists X1 and X2. After 
concatenation X1 is a pointer
 to first node of the resulting lists.*/
   
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

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void concatenate(struct Node** X1, struct Node* X2) {
    if (*X1 == NULL) {
        *X1 = X2;
        return;
    }

    struct Node* current = *X1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = X2;
    if (X2 != NULL) {
        X2->prev = current;
    }
}

int main() {
    struct Node* X1 = NULL;
    struct Node* X2 = NULL;

    // Populate X1 and X2 with elements
    X1 = createNode(1);
    X1->next = createNode(2);
    X1->next->prev = X1;
    X1->next->next = createNode(3);
    X1->next->next->prev = X1->next;

    X2 = createNode(4);
    X2->next = createNode(5);
    X2->next->prev = X2;
    X2->next->next = createNode(6);
    X2->next->next->prev = X2->next;

    printf("Before concatenation:\n");
    printf("X1: ");
    displayList(X1);
    printf("X2: ");
    displayList(X2);

    concatenate(&X1, X2);

    printf("\nAfter concatenation:\n");
    printf("X1: ");
    displayList(X1);

    // Clean up memory by freeing the nodes

    return 0;
}
