/*Let list1 = (x1, x2…..xn) 
and list2= (y1, y2…..ym).
 Write a function to merge list1 and 
list2 to obtain 
list3 = (x1, y1, x2, y2….xm,ym,xm+1…xn)
 for m<=n; and list3=(x1, 
y1,x2,y2…..xn, yn, xn+1….xm) for m>n.*/
  
  #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* list3 = NULL;
    struct Node* tail = NULL;

    while (list1 != NULL || list2 != NULL) {
        if (list1 != NULL) {
            if (list3 == NULL) {
                list3 = tail = list1;
            } else {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;
        }

        if (list2 != NULL) {
            if (list3 == NULL) {
                list3 = tail = list2;
            } else {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;
        }
    }

    if (tail != NULL) {
        tail->next = NULL;
    }

    return list3;
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
    // Create linked lists list1 and list2
    struct Node* list1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* list2 = (struct Node*)malloc(sizeof(struct Node));
    
    // Populate list1 and list2 with values
    // ...

    // Merge the lists and obtain list3
    struct Node* list3 = mergeLists(list1, list2);

    // Print the merged list list3
    printList(list3);

    // Clean up memory
    free(list1);
    free(list2);
    // Remember to free memory allocated for list3 as well
    return 0;
}
