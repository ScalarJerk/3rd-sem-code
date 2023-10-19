#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Doubly {
    struct Node *head, *tail;
};

void initDoubly(struct Doubly *list) {
    list->head = NULL;
    list->tail = NULL;
}

void append(struct Doubly *list, int elem) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = elem;
    temp->next = NULL;
    if (list->head == NULL) {
        list->head = temp;
        temp->prev = NULL;
    } else {
        temp->prev = list->tail;
        temp->prev->next = temp;
    }
    list->tail = temp;
}

void display(struct Doubly *list) {
    struct Node *trav = list->head;
    while (trav != NULL) {
        printf("%d ", trav->data);
        trav = trav->next;
    }
    printf("\n");
}

void concatenate(struct Doubly *list1, struct Doubly *list2) {
    list1->tail->next = list2->head;
    list2->head->prev = list1->tail;
}

int main() {
    struct Doubly d1, d2;
    initDoubly(&d1);
    initDoubly(&d2);

    printf("Enter list 1 (-1 to break):\n");
    int c;
    while (1) {
        scanf("%d", &c);
        if (c == -1) {
            break;
        }
        append(&d1, c);
    }

    printf("Enter list 2 (-1 to break):\n");
    while (1) {
        scanf("%d", &c);
        if (c == -1) {
            break;
        }
        append(&d2, c);
    }

    display(&d1);
    display(&d2);

    concatenate(&d1, &d2);
    display(&d1);

    return 0;
}

