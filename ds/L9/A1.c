#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the circular doubly linked list
struct Node {
    int coeff;
    int exp;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a new node at the end of the list
void insertEnd(struct Node** head, int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    else {
        newNode->prev = NULL;
    }
    *head = newNode;
}

// Function to multiply two polynomials
struct Node* multiplyPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* ptr1 = poly1;
    struct Node* ptr2 = poly2;

    // Traverse through each term of poly1
    while (ptr1 != NULL) {
        // Traverse through each term of poly2
        while (ptr2 != NULL) {
            // Multiply the coefficients and add the exponents
            int coeff = ptr1->coeff * ptr2->coeff;
            int exp = ptr1->exp + ptr2->exp;

            // Insert the new term into the result polynomial
            insertEnd(&result, coeff, exp);
