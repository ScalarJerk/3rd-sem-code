/*Write a program to add 2
 polynomials using circular doubly 
 linked list with head 
node. */
  
  #include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
    struct Term* prev;
};

struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = newTerm->prev = NULL;
    return newTerm;
}

void insertTerm(struct Term* header, int coeff, int exp) {
    struct Term* newTerm = createTerm(coeff, exp);
    newTerm->next = header->next;
    newTerm->prev = header;
    header->next->prev = newTerm;
    header->next = newTerm;
}

void displayPolynomial(struct Term* header) {
    struct Term* current = header->next;
    while (current != header) {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != header) {
            printf(" + ");
        }
    }
    printf("\n");
}

void addPolynomials(struct Term* poly1, struct Term* poly2, struct Term* result) {
    struct Term* current1 = poly1->next;
    struct Term* current2 = poly2->next;

    while (current1 != poly1 && current2 != poly2) {
        if (current1->exponent > current2->exponent) {
            insertTerm(result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else if (current1->exponent < current2->exponent) {
            insertTerm(result, current2->coefficient, current2->exponent);
            current2 = current2->next;
        } else {
            int sumCoeff = current1->coefficient + current2->coefficient;
            if (sumCoeff != 0) {
                insertTerm(result, sumCoeff, current1->exponent);
            }
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    while (current1 != poly1) {
        insertTerm(result, current1->coefficient, current1->exponent);
        current1 = current1->next;
    }

    while (current2 != poly2) {
        insertTerm(result, current2->coefficient, current2->exponent);
        current2 = current2->next;
    }
}

int main() {
    struct Term* header1 = createTerm(0, -1); // Header node for polynomial 1
    struct Term* header2 = createTerm(0, -1); // Header node for polynomial 2
    struct Term* resultHeader = createTerm(0, -1); // Header node for the result polynomial

    // Populate header1 and header2 with terms
    insertTerm(header1, 3, 2);
    insertTerm(header1, 4, 1);
    insertTerm(header1, 5, 0);

    insertTerm(header2, 2, 3);
    insertTerm(header2, -4, 2);
    insertTerm(header2, 1, 1);

    printf("Polynomial 1: ");
    displayPolynomial(header1);

    printf("Polynomial 2: ");
    displayPolynomial(header2);

    addPolynomials(header1, header2, resultHeader);
    printf("Sum: ");
    displayPolynomial(resultHeader);

    // Clean up memory by freeing the nodes

    return 0;
}
