#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void getIntersection(struct Node* head1, struct Node* head2) {
    struct Node* ptr1 = head1;
    while (ptr1 != NULL) {
        struct Node* ptr2 = head2;
        while (ptr2 != NULL) {
            if (ptr1->data == ptr2->data) {
                printf("%d ", ptr1->data);
                break;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void getUnion(struct Node* head1, struct Node* head2) {
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
    while (ptr1 != NULL) {
        printf("%d ", ptr1->data);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL) {
        if (!search(head1, ptr2->data)) {
            printf("%d ", ptr2->data);
        }
        ptr2 = ptr2->next;
    }
}

int search(struct Node* head, int x) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == x) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    push(&head1, 10);
    push(&head1, 15);
    push(&head1, 4);
    push(&head1, 20);
    push(&head2, 8);
    push(&head2, 4);
    push(&head2, 2);
    push(&head2, 10);
    printf("First list is ");
    printList(head1);
    printf("Second list is ");
    printList(head2);
    printf("Intersection list is ");
    getIntersection(head1, head2);
    printf("\nUnion list is ");
    getUnion(head1, head2);
    return 0;
}
