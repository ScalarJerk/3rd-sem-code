/*Write a program to copy one tree to another.*/
  
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

struct TreeNode* copyTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    
    struct TreeNode* newNode = createNode(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);
    
    return newNode;
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    // Create the original binary tree
    struct TreeNode* originalRoot = createNode(1);
    originalRoot->left = createNode(2);
    originalRoot->right = createNode(3);
    originalRoot->left->left = createNode(4);
    originalRoot->left->right = createNode(5);

    // Copy the original binary tree to a new tree
    struct TreeNode* copiedRoot = copyTree(originalRoot);

    printf("Original Tree (In-order): ");
    inorderTraversal(originalRoot);
    printf("\n");

    printf("Copied Tree (In-order): ");
    inorderTraversal(copiedRoot);
    printf("\n");

    // Clean up memory by freeing the nodes

    return 0;
}
