
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Doubly {
    struct Node* head;
    struct Node* tail;
};

void initDoubly(struct Doubly* d) {
    d->head = NULL;
    d->tail = NULL;
}

struct Node* createNode(int elem) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = elem;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(struct Doubly* d, int elem) {
    struct Node* temp = createNode(elem);
    temp->next = NULL;
    if (d->head == NULL) {
        // List is empty
        temp->prev = NULL;
        d->head = temp;
    } else {
        temp->prev = d->tail;
        d->tail->next = temp;
    }
    d->tail = temp;
}

void deleteEnd(struct Doubly* d) {
    struct Node* temp = d->tail;
    if (temp->prev == NULL) {
        d->head = d->tail = NULL;
        free(temp);
        return;
    }
    temp->prev->next = NULL;
    d->tail = temp->prev;
    free(temp);
}

void insertPos(struct Doubly* d, int elem, int loc) {
    struct Node* temp = createNode(elem);
    struct Node* trav = d->head;
    int count = 0;
    while (trav != NULL) {
        if (count == loc) {
            break;
        }
        count++;
        trav = trav->next;
    }
    if (trav == NULL) {
        append(d, elem);
        return;
    }
    trav->prev->next = temp;
    temp->prev = trav->prev;
    temp->next = trav;
    trav->prev = temp;
}

void deletePos(struct Doubly* d, int loc) {
    struct Node* trav = d->head;
    if (loc == 0) {
        d->head = trav->next;
        free(trav);
        return;
    }
    int count = 0;
    while (trav != NULL) {
        if (count == loc) {
            break;
        }
        count++;
        trav = trav->next;
    }
    if (trav == NULL) {
        deleteEnd(d);
    }
    trav->prev->next = trav->next;
    trav->next->prev = trav->prev;
    free(trav);
}

void insertAfter(struct Doubly* d, int elem, int val) {
    struct Node* temp = createNode(elem);
    struct Node* trav = d->head;
    bool found = false;
    while (trav != NULL) {
        if (val == trav->data) {
            found = true;
            if (trav->next != NULL)
                trav->next->prev = temp;
            else
                d->tail = temp;
            temp->next = trav->next;
            trav->next = temp;
            temp->prev = trav;
            break;
        }
        trav = trav->next;
    }
    if (!found) {
        printf("Element not found\n");
    }
}

void insertBefore(struct Doubly* d, int elem, int val) {
    struct Node* temp = createNode(elem);
    struct Node* trav = d->tail;
    bool found = false;
    while (trav != NULL) {
        if (val == trav->data) {
            found = true;
            if (trav->prev != NULL)
                trav->prev->next = temp;
            else
                d->head = temp;
            temp->prev = trav->prev;
            trav->prev = temp;
            temp->next = trav;
            break;
        }
        trav = trav->prev;
    }
    if (!found) {
        printf("Element not found\n");
    }
}

void display(struct Doubly* d) {
    struct Node* trav = d->head;
    while (trav != NULL) {
        printf("%d ", trav->data);
        trav = trav->next;
    }
    printf("\n");
}

void reverse(struct Doubly* d) {
    struct Node* trav = d->head;
    while (trav != NULL) {
        struct Node* temp = trav->next;
        trav->next = trav->prev;
        trav->prev = temp;
        trav = temp;
    }
    struct Node* temp = d->head;
    d->head = d->tail;
    d->tail = temp;
}

int main() {
    struct Doubly D;
    initDoubly(&D);

    // MENU DRIVEN PROGRAM TO IMPLEMENT THE OPERATIONS
    int choice;
    int loc, elem;
    printf("THE FOLLOWING OPERATIONS CAN BE PERFORMED ON THE DOUBLY LINKED LIST:\n");
    printf("1.Insert at end\n");
    printf("2.Delete from end\n");
    printf("3.Insert at Position\n");
    printf("4.Delete from Position\n");
    printf("5.Insert after another element\n");
    printf("6.Insert before another element\n");
    printf("7.Traverse the list\n");
    printf("8.Reverse the list\n");
    printf("9.Exit\n");

    while (true) {
        printf(">");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                append(&D, elem);
                break;
            case 2:
                deleteEnd(&D);
                break;
            case 3:
                printf("Enter the location: ");
                scanf("%d", &loc);
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                insertPos(&D, elem, loc);
                break;
            case 4:
                printf("Enter the location: ");
                scanf("%d", &loc);
                deletePos(&D, loc);
                break;
            case 5:
                printf("Enter the element to insert after: ");
                scanf("%d", &loc);
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                insertAfter(&D, elem, loc);
                break;
            case 6:
                printf("Enter the element to insert before: ");
                scanf("%d", &loc);
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                insertBefore(&D, elem, loc);
                break;
            case 7:
                display(&D);
                break;
            case 8:
                reverse(&D);
                break;
            case 9:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}
