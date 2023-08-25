/*Write a recursive function to i) Create a binary tree and 
ii) print a binary tree*/
  
  #include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Helper function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to insert a value into a binary tree
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

// Recursive function to print the binary tree in-order
void printInOrder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

int main() {
    struct TreeNode* root = NULL;
    int n, value;

    printf("Enter the number of elements in the tree: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("In-order traversal of the binary tree: ");
    printInOrder(root);
    printf("\n");

    // Clean up memory by freeing the nodes

    return 0;
}
