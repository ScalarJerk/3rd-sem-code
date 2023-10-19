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
}

int main() {
    struct Node* head = createList();
    traverse(head);
    return 0;
}

