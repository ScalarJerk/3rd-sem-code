// Write a program to traverse a binary search tree and print it.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    struct TreeNode* root = NULL;
    int n, value;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("In-order traversal of the binary search tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order traversal of the binary search tree: ");
    preorderTraversal(root);
    printf("\n");

    printf("Post-order traversal of the binary search tree: ");
    postorderTraversal(root);
    printf("\n");

    // Clean up memory by freeing the nodes

    return 0;
}
