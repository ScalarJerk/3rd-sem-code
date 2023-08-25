/*Let X = (x1, x2….xn) and Y = (y1, y2….yn)
 be 2 linked lists. Assume that, in each list, 
the nodes are in non-decreasing order 
of the data field values. Write an algorithm to 
merge two lists to obtain a new linked
 list Z in which the nodes are also in the non-
decreasing order. Following the merge,
 X and Y do not exist as individual lists. Each 
node initially in X or Y is now in Z.
 Do not use additional nodes.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* mergeLists(struct Node* X, struct Node* Y) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (X != NULL && Y != NULL) {
        if (X->data <= Y->data) {
            tail->next = X;
            X = X->next;
        } else {
            tail->next = Y;
            Y = Y->next;
        }
        tail = tail->next;
    }

    tail->next = (X == NULL) ? Y : X;

    return dummy.next;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create linked lists X and Y
    struct Node* X = (struct Node*)malloc(sizeof(struct Node));
    struct Node* Y = (struct Node*)malloc(sizeof(struct Node));
    
    // Populate X and Y with values
    // ...

    // Merge the lists and obtain list Z
    struct Node* Z = mergeLists(X, Y);

    // Print the merged list Z
    printList(Z);

    // Clean up memory
    free(X);
    free(Y);
    // Remember to free memory allocated for Z as well
    return 0;
}
