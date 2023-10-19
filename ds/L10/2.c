#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *lc, *rc;
    int data;
};

struct Node* createTree() {
    int val;
    printf("Enter value (or -1 to end): ");
    scanf("%d", &val);
    if (val == -1)
        return NULL;

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    printf("Left child of %d\n", val);
    temp->lc = createTree();
    printf("Right child of %d\n", val);
    temp->rc = createTree();
    return temp;
}

void inorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    inorder(node->lc);
    printf("%d ", node->data);
    inorder(node->rc);
}

void print(struct Node* root) {
    inorder(root);
}

int main() {
    struct Node* root = createTree();
    printf("Inorder Traversal: ");
    print(root);
    return 0;
}
