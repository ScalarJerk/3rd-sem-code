/*Write a program to implement 
union and intersection of two doubly linked lists. */

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

struct Node* getUnion(struct Node* X1, struct Node* X2) {
    struct Node* result = NULL;

    // Traverse X1 and insert its elements into the result
    struct Node* current = X1;
    while (current != NULL) {
        struct Node* newNode = createNode(current->data);
        if (result == NULL) {
            result = newNode;
        } else {
            struct Node* temp = result;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        current = current->next;
    }

    // Traverse X2 and insert its unique elements into the result
    current = X2;
    while (current != NULL) {
        int exists = 0;
        struct Node* temp = result;
        while (temp != NULL) {
            if (temp->data == current->data) {
                exists = 1;
                break;
            }
            temp = temp->next;
        }
        if (!exists) {
            struct Node* newNode = createNode(current->data);
            if (result == NULL) {
                result = newNode;
            } else {
                struct Node* temp = result;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
            }
        }
        current = current->next;
    }

    return result;
}

struct Node* getIntersection(struct Node* X1, struct Node* X2) {
    struct Node* result = NULL;

    struct Node* current = X1;
    while (current != NULL) {
        int exists = 0;
        struct Node* temp = X2;
        while (temp != NULL) {
            if (temp->data == current->data) {
                exists = 1;
                break;
            }
            temp = temp->next;
        }
        if (exists) {
            struct Node* newNode = createNode(current->data);
            if (result == NULL) {
                result = newNode;
            } else {
                struct Node* temp = result;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
            }
        }
        current = current->next;
    }

    return result;
}

int main() {
    struct Node* X1 = createNode(1);
    X1->next = createNode(2);
    X1->next->prev = X1;
    X1->next->next = createNode(3);
    X1->next->next->prev = X1->next;

    struct Node* X2 = createNode(2);
    X2->next = createNode(3);
    X2->next->prev = X2;

    printf("List X1: ");
    displayList(X1);

    printf("List X2: ");
    displayList(X2);

    struct Node* unionResult = getUnion(X1, X2);
    printf("Union: ");
    displayList(unionResult);

    struct Node* intersectionResult = getIntersection(X1, X2);
    printf("Intersection: ");
    displayList(intersectionResult);

    // Clean up memory by freeing the nodes

    return 0;
}
