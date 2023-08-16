/*Write a program to check if 
one tree is the mirror image of another tree*/
  
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

bool areMirror(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    return (root1->data == root2->data) &&
           areMirror(root1->left, root2->right) &&
           areMirror(root1->right, root2->left);
}

int main() {
    // Create the first binary tree
    struct TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);

    // Create the second binary tree as a mirror image of the first tree
    struct TreeNode* root2 = createNode(1);
    root2->left = createNode(3);
    root2->right = createNode(2);
    root2->right->left = createNode(5);
    root2->right->right = createNode(4);

    if (areMirror(root1, root2)) {
        printf("The two trees are mirror images of each other.\n");
    } else {
        printf("The two trees are not mirror images of each other.\n");
    }

    // Clean up memory by freeing the nodes

    return 0;
}
