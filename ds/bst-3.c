/*Write a program to search for a given element in a binary search tree.*/
  
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

struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    
    if (key < root->data) {
        return search(root->left, key);
    }
    
    return search(root->right, key);
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

    int searchKey;
    printf("Enter the element to search: ");
    scanf("%d", &searchKey);
    
    struct TreeNode* result = search(root, searchKey);
    if (result != NULL) {
        printf("%d found in the binary search tree.\n", searchKey);
    } else {
        printf("%d not found in the binary search tree.\n", searchKey);
    }

    // Clean up memory by freeing the nodes

    return 0;
}
