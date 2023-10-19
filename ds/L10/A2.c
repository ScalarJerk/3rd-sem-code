#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* lc;
    struct Node* rc;
    int data;
};

struct Tree {
    struct Node* root;
};

struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->lc = temp->rc = NULL;
    return temp;
}

struct Tree* createTree(int arr[], int n) {
    struct Tree* tree = (struct Tree*)malloc(sizeof(struct Tree));
    tree->root = insertLevelOrder(arr, 0, n);
    return tree;
}

struct Node* insertLevelOrder(int arr[], int i, int n) {
    if (i >= n)
        return NULL;
    struct Node* temp = createNode(arr[i]);
    temp->lc = insertLevelOrder(arr, 2 * i + 1, n);
    temp->rc = insertLevelOrder(arr, 2 * i + 2, n);
    return temp;
}

int isMirror(struct Node* a, struct Node* b) {
    if (!a && !b)
        return 1;
    if (!a || !b)
        return 0;
    return (a->data == b->data) && isMirror(a->lc, b->rc) && isMirror(a->rc, b->lc);
}

int main() {
    int arr1[] = {2, 3, 4};
    int arr2[] = {2, 4, 3};
    struct Tree* t1 = createTree(arr1, 3);
    struct Tree* t2 = createTree(arr2, 3);
    if (isMirror(t1->root, t2->root))
        printf("Yes");
    else
        printf("No");
    return 0;
}
