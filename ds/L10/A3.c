#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *lc, *rc;
};

struct Node* createTree() {
    int val;
    printf("Enter value (or -1 to exit): ");
    scanf("%d", &val);
    if (val == -1)
        return NULL;

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    
    printf("Left child of %d\n", val);
    temp->lc = createTree();
    
    printf("Right child of %d\n", val);
    temp->rc = createTree();
    
    return temp;
}

void postOrder(struct Node* node) {
    if (node == NULL)
        return;

    postOrder(node->lc);
    postOrder(node->rc);
    printf("%d ", node->data);
}

void copyTree(struct Node** dest, struct Node* src) {
    if (!src)
        return;

    *dest = (struct Node*)malloc(sizeof(struct Node));
    (*dest)->data = src->data;

    copyTree(&((*dest)->lc), src->lc);
    copyTree(&((*dest)->rc), src->rc);
}

int main() {
    struct Node* root1 = NULL;
    printf("Create the first tree:\n");
    root1 = createTree();

    printf("Postorder Traversal of the first tree: ");
    postOrder(root1);
    printf("\n");

    struct Node* root2 = NULL;
    copyTree(&root2, root1);

    printf("Postorder Traversal of the copied tree: ");
    postOrder(root2);
    printf("\n");

    return 0;
}

