/*Write a program to check for equality of two trees.*/
  
  #include <stdio.h>
#include <stdbool.h>
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

bool areTreesEqual(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    return (root1->data == root2->data) &&
           areTreesEqual(root1->left, root2->left) &&
           areTreesEqual(root1->right, root2->right);
}

int main() {
    // Create the first binary tree
    struct TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);

    // Create the second binary tree
    struct TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    root2->left->right = createNode(5);

    if (areTreesEqual(root1, root2)) {
        printf("The two trees are equal.\n");
    } else {
        printf("The two trees are not equal.\n");
    }

    // Clean up memory by freeing the nodes

    return 0;
}
