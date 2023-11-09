#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int powx;
    int powy;
    struct Node* next;
    struct Node* prev;
};

void add_poly(struct Node* poly1, struct Node* poly2, struct Node* temp) {
    struct Node* start1 = poly1;
    struct Node* start2 = poly2;
    poly1 = poly1->next;
    poly2 = poly2->next;
    while (poly1 != start1 || poly2 != start2) {
        struct Node* r;
        struct Node* z = temp;
        r = (struct Node*)malloc(sizeof(struct Node));
        r->coeff = 0;
        if (poly1->powx > poly2->powx) {
            r->coeff = poly1->coeff;
            r->powx = poly1->powx;
            r->powy = poly1->powy;
            poly1 = poly1->next;
        }
        else if (poly1->powx < poly2->powx) {
            r->coeff = poly2->coeff;
            r->powx = poly2->powx;
            r->powy = poly2->powy;
            poly2 = poly2->next;
        }
        else {
            r->coeff = poly1->coeff + poly2->coeff;
            r->powx = poly1->powx;
            r->powy = poly1->powy;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        if (temp->next == NULL) {
            temp->next = r;
            r->prev = temp;
            r->next = NULL;
        }
        else {
            while (z->next != NULL) {
                z = z->next;
            }
            z->next = r;
            r->prev = z;
            r->next = NULL;
        }
    }
}

void display(struct Node* node) {
    while (node != NULL) {
        printf("%dx^%dy^%d", node->coeff, node->powx, node->powy);
        if (node->next != NULL) {
            printf(" + ");
        }
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* poly2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    poly1->next = poly1->prev = poly1;
    poly2->next = poly2->prev = poly2;
    temp->next = temp->prev = NULL;
    poly1->coeff = 5;
    poly1->powx = 2;
    poly1->powy = 3;
    poly2->coeff = 3;
    poly2->powx = 2;
    poly2->powy = 3;
    add_poly(poly1, poly2, temp);
    printf("First polynomial: ");
    display(poly1->next);
    printf("Second polynomial: ");
    display(poly2->next);
    printf("Resultant polynomial: ");
    display(temp->next);
    return 0;
}
