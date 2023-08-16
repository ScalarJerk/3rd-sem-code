// Write a program to create a tree for a postfix expression and evaluate it.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

struct TreeNode* buildExpressionTree(char postfix[]) {
    struct TreeNode* stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            stack[++top] = createNode(postfix[i]);
        } else if (isOperator(postfix[i])) {
            struct TreeNode* operatorNode = createNode(postfix[i]);
            operatorNode->right = stack[top--];
            operatorNode->left = stack[top--];
            stack[++top] = operatorNode;
        }
    }

    return stack[top];
}

int evaluateExpressionTree(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (!isOperator(root->data)) {
        return root->data - '0';
    }

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    switch (root->data) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
        default: return 0;
    }
}

int main() {
    char postfixExpression[100];

    printf("Enter a postfix expression: ");
    scanf("%s", postfixExpression);

    struct TreeNode* root = buildExpressionTree(postfixExpression);
    int result = evaluateExpressionTree(root);

    printf("Result of the expression: %d\n", result);

    // Clean up memory by freeing the nodes

    return 0;
}
