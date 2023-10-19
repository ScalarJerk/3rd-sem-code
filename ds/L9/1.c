#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct DoublyCircular {
    struct Node* head;
    int counter;
};

void initialize(struct DoublyCircular* dc) {
    dc->head = NULL;
    dc->counter = 0;
}

void insert(struct DoublyCircular* dc, int elem, int loc) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* trav;
    temp->data = elem;
    if (loc == -1) {
        loc = dc->counter;
    }
    // EDGE CASE: Empty List
    if (dc->head == NULL) {
        dc->head = temp;
        temp->next = dc->head;
        temp->prev = dc->head;
        dc->counter++;
        return;
    }
    int count = 0;
    trav = dc->head;
    int found = 0;
    do {
        if (count == loc) {
            found = 1;
            break;
        }
        count++;
        trav = trav->next;
    } while (trav != dc->head);
    if (count < loc) {
        printf("Index out of bound\n");
        return;
    }
    trav->prev->next = temp;
    temp->prev = trav->prev;
    temp->next = trav;
    trav->prev = temp;
    dc->counter++;
    if (loc == 0) {
        dc->head = temp;
    }
}

// TODO: ERROR: Deletion doesn't work if elements are less than 2
void delete_elem(struct DoublyCircular* dc, int elem) {
    struct Node* trav = dc->head;
    int found = 0;
    if (trav == NULL) {
        printf("List empty!\n");
        return;
    }
    // EDGE CASE: Single Element
    else if (trav->next == trav->prev) {
        dc->head = NULL;
        free(trav);
        dc->counter--;
        return;
    }
    do {
        if (trav->data == elem) {
            if (trav->prev) {
                trav->prev->next = trav->next;
            }
            if (trav->next) {
                trav->next->prev = trav->prev;
            }
            if (trav == dc->head) {
                dc->head = trav->next;
            }
            free(trav);
            dc->counter--;
            found = 1;
            break;
        }
        trav = trav->next;
    } while (trav != dc->head);
    if (!found) {
        printf("Element Not found!\n");
    }
}

void display(struct DoublyCircular* dc) {
	if (dc->head == NULL)
		return;
    struct Node* trav;
    trav = dc->head;
    do {
        printf("%d ", trav->data);
        trav = trav->next;
    } while (trav != dc->head);
    printf("\n");
}

int main() {
    struct DoublyCircular DC;
    int choice, loc, elem;
    printf("THE FOLLOWING OPERATIONS CAN BE PERFORMED ON THE CIRCULAR DOUBLY LINKED LIST:\n");
    printf("1. Insert an element at a position\n");
    printf("2. Delete an element\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    initialize(&DC);
    do {
        printf(">");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the location (Enter -1 to append): ");
                scanf("%d", &loc);
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                insert(&DC, elem, loc);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &elem);
                delete_elem(&DC, elem);
                break;
            case 3:
                display(&DC);
                break;
            case 4:
                return 0;
            case -1:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid Choice\n");
        } 
    } while (choice != -1);
    return 0;
}

