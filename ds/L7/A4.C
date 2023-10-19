#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    printf(">");
    int elem;
    scanf("%d", &elem);
    if (elem == -1)
        return NULL;
    else {
        temp->data = elem;
        temp->next = createList();
        return temp;
    }
}

void traverse(struct Node* temp) {
    printf("%d ", temp->data);
    if (temp->next)
        traverse(temp->next);
    return;
}

struct Node* merger(struct Node* head1, struct Node* head2) {
    struct Node* head;
    if (!head1 && !head2)
        return NULL;
    else if (!head1)
        return head2;
    else if (!head2)
        return head1;
    if (head1->data < head2->data) {
        head = head1;
        head->next = merger(head1->next, head2);
    }
    else {
        head = head2;
        head->next = merger(head1, head2->next);
    }
    return head;
}

int main() {
    struct Node* head1 = createList();
    traverse(head1);
    printf("\n");

    struct Node* head2 = createList();
    traverse(head2);
    printf("\n");

    struct Node* head3 = merger(head1, head2);
    traverse(head3);
    return 0;
}
