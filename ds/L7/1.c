#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
};

void initLinkedList(struct LinkedList *list) {
    list->head = NULL;
}

void append(struct LinkedList *list, int elem) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = elem;
    temp->next = list->head;
    list->head = temp;
}

void insertAfter(struct LinkedList *list, int elem, int value) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = elem;
    struct Node *trav = list->head;
    int found = 0;

    while (trav != NULL) {
        if (trav->data == value) {
            temp->next = trav->next;
            trav->next = temp;
            found = 1;
            break;
        }
        trav = trav->next;
    }

    if (!found) {
        printf("Element not found!\n");
    }
}

void insertBefore(struct LinkedList *list, int elem, int value) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = elem;
    struct Node *trav = list->head;
    int found = 0;

    if (trav != NULL && trav->data == value) {
        temp->next = trav;
        list->head = temp;
        return;
    }

    while (trav->next != NULL) {
        if (trav->next->data == value) {
            temp->next = trav->next;
            trav->next = temp;
            found = 1;
            break;
        }
        trav = trav->next;
    }

    if (!found) {
        printf("Element not found\n");
    }
}

void removeElement(struct LinkedList *list, int elem) {
    struct Node *trav = list->head;
    int found = 0;

    if (trav != NULL && trav->data == elem) {
        list->head = trav->next;
        free(trav);
        found = 1;
    } else {
        while (trav->next != NULL) {
            if (trav->next->data == elem) {
                struct Node *temp = trav->next;
                trav->next = temp->next;
                free(temp);
                found = 1;
                break;
            }
            trav = trav->next;
        }
    }

    if (!found) {
        printf("Element not found in the list\n");
    }
}

void traverse(struct LinkedList *list) {
    struct Node *trav = list->head;
    while (trav != NULL) {
        printf("%d ", trav->data);
        trav = trav->next;
    }
    printf("\n");
}

void reverse(struct LinkedList *list) {
    struct Node *prev = NULL, *next = NULL, *curr = list->head;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev;
}

void sort(struct LinkedList *list, int rev) {
    // Selection sort
    struct Node *t = list->head, *t2, *min;
    int temp;

    while (t) {
        min = t;
        t2 = t->next;
        while (t2) {
            if (t2->data < min->data)
                min = t2;
            t2 = t2->next;
        }
        if (min != t) {
            temp = min->data;
            min->data = t->data;
            t->data = temp;
        }
        t = t->next;
    }

    if (rev) {
        reverse(list);
    }
}

void deleteAlternate(struct LinkedList *list) {
    struct Node *temp = list->head;
    while (temp != NULL && temp->next != NULL) {
        struct Node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
        temp = temp->next;
    }
}

void insertInOrder(struct LinkedList *list, int elem) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = elem;
    struct Node *trav = list->head;

    if (trav == NULL || trav->data > elem) {
        temp->next = list->head;
        list->head = temp;
        return;
    }

    while (trav->next != NULL) {
        if (trav->next->data > elem) {
            temp->next = trav->next;
            trav->next = temp;
            return;
        }
        trav = trav->next;
    }

    trav->next = temp;
    temp->next = NULL;
}

int main() {
    struct LinkedList L;
    initLinkedList(&L);

    int choice, loc, elem;

    append(&L, 100);
    append(&L, 2100);
    append(&L, 10);
    append(&L, 1420);

    printf("THE FOLLOWING OPERATIONS CAN BE PERFORMED ON THE LINKED LIST:\n");
    printf("1. Insert before another element\n");
    printf("2. Insert after another element\n");
    printf("3. Delete an element\n");
    printf("4. Traverse the list\n");
    printf("5. Reverse the list\n");
    printf("6. Sort the list\n");
    printf("7. Delete alternate elements\n");
    printf("8. Insert in an order\n");
    printf("9. Exit\n");

    while (1) {
        printf(">");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert before: ");
                scanf("%d", &loc);
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                insertBefore(&L, elem, loc);
                break;
            case 2:
                printf("Enter the element to insert after: ");
                scanf("%d", &loc);
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                insertAfter(&L, elem, loc);
                break;
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &elem);
                removeElement(&L, elem);
                break;
            case 4:
                traverse(&L);
                break;
            case 5:
                reverse(&L);
                break;
            case 6:
                printf("0 for Ascending\n1 for Descending: ");
                scanf("%d", &elem);
                sort(&L, elem);
                break;
            case 7:
                deleteAlternate(&L);
                break;
            case 8:
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                insertInOrder(&L, elem);
                break;
            case 9:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
