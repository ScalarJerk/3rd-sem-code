/* Write a program to add 
2 polynomials represented as linked lists.*/
  
  #include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    return newTerm;
}

void insertTerm(struct Term** head, int coeff, int exp) {
    struct Term* newTerm = createTerm(coeff, exp);
    if (*head == NULL || exp > (*head)->exponent) {
        newTerm->next = *head;
        *head = newTerm;
    } else {
        struct Term* current = *head;
        while (current->next != NULL && current->next->exponent >= exp) {
            current = current->next;
        }
        newTerm->next = current->next;
        current->next = newTerm;
    }
}

void displayPolynomial(struct Term* head) {
    struct Term* current = head;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int coeffSum = poly1->coefficient + poly2->coefficient;
            if (coeffSum != 0) {
                insertTerm(&result, coeffSum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    
    return result;
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    
    // Populate poly1 and poly2 with terms
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 5, 0);
    
    insertTerm(&poly2, 2, 3);
    insertTerm(&poly2, -4, 2);
    insertTerm(&poly2, 1, 1);
    
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    
    struct Term* sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    displayPolynomial(sum);
    
    // Clean up memory by freeing the nodes
    
    return 0;
}
