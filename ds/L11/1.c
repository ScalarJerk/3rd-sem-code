#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int elem) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = elem;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int elem) {
    if (root == NULL)
        return createNode(elem);
    if (elem > root->data)
        root->right = insert(root->right, elem);
    else
        root->left = insert(root->left, elem);
    return root;
}

struct Node* search(struct Node* root, int elem) {
    if (root == NULL || root->data == elem)
        return root;
    else if (root->data < elem)
        return search(root->right, elem);
    else
        return search(root->left, elem);
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct Node* deleteNode(struct Node* root, int elem) {
    if (root == NULL)
        return root;
    if (elem > root->data)
        root->right = deleteNode(root->right, elem);
    else if (elem < root->data)
        root->left = deleteNode(root->left, elem);
    else {
        struct Node* temp;
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }
        else {
            // Both children exist
            temp = root;
            while (temp && temp->left) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 30);
    int n, choice;
    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Search an element\n");
    printf("4. Print the array\n");
    while (1) {
        printf(">");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &n);
                insert(root, n);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &n);
                deleteNode(root, n);
                break;
            case 3:
                printf("Enter element: ");
                scanf("%d", &n);
                search(root, n) ? printf("Yes\n") : printf("NO\n");
                break;
            case 4:
                inorder(root);
                printf("\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
