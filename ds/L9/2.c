#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coff;
    int exp;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

struct Poly {
    Node* head;
};

typedef struct Poly Poly;

void append(Poly* poly, int c, int e) {
    Node* temp = (Node*)malloc(sizeof(Node));
    Node* trav = poly->head;

    temp->coff = c;
    temp->exp = e;

    if (trav == NULL) {
        poly->head = temp;
        temp->next = temp;
        temp->prev = temp;
        return;
    }

    trav->prev->next = temp;
    trav->prev = temp;
    temp->next = trav;
    temp->prev = trav->prev;
}

void input(Poly* poly) {
    int c, e;
    printf("Enter the polynomial:\n");
    while (1) {
        printf("Enter the coefficient: ");
        scanf("%d", &c);
        printf("Enter the exponent: ");
        scanf("%d", &e);
        if (e == 0 && c == 0)
            break;
        append(poly, c, e);
        if (e == 0)
            break;
    }
}

Node* adder(Node* p1, Node* p2) {
    if (!p1)
        return p2;
    if (!p2)
        return p1;

    Node* temp = (Node*)malloc(sizeof(Node));
    if (p1->exp == p2->exp) {
        temp->exp = p1->exp;
        temp->coff = p1->coff + p2->coff;
        temp->next = adder(p1->next, p2->next);
    } else if (p1->exp > p2->exp) {
        temp->exp = p1->exp;
        temp->coff = p1->coff;
        temp->next = adder(p1->next, p2);
    } else {
        temp->exp = p2->exp;
        temp->coff = p2->coff;
        temp->next = adder(p1, p2->next);
    }
    return temp;
}

void add(Poly* result, Poly* p1, Poly* p2) {
    result->head = adder(p1->head, p2->head);
}

void display(Poly* poly) {
    Node* trav = poly->head;
    if (trav->next == trav) {
        if (trav->exp == 0)
            printf("%d\n", trav->coff);
        else
            printf("%dx^%d\n", trav->coff, trav->exp);
        return;
    }

    printf("%dx^%d", trav->coff, trav->exp);
    trav = trav->next;

    while (trav->next != poly->head) {
        printf(" + %dx^%d", trav->coff, trav->exp);
        trav = trav->next;
    }
    printf("\n");
}

int main() {
    Poly P1, P2, P3;
    P1.head = NULL;
    P2.head = NULL;
    P3.head = NULL;

    input(&P1);
    input(&P2);
    add(&P3, &P1, &P2);

    printf("Polynomial 1:\n");
    display(&P1);
    printf("Polynomial 2:\n");
    display(&P2);
    printf("Polynomial 3:\n");
    display(&P3);

    // Free memory
    Node* temp = P1.head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        if (next == P1.head) break;
        temp = next;
    }

    temp = P2.head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        if (next == P2.head) break;
        temp = next;
    }

    temp = P3.head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        if (next == P3.head) break;
        temp = next;
    }

    return 0;
}
