#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* lc;
    struct Node* rc;
};

typedef struct Node Node;

Node* createTree() {
    int val;
    printf(">");
    scanf("%d", &val);
    if (val == -1)
        return NULL;
    
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    temp->data = val;
    printf("Left child of %d\n", val);
    temp->lc = createTree();
    printf("Right child of %d\n", val);
    temp->rc = createTree();
    return temp;
}

void iterativePreorder(Node* root) {
    printf("Iterative Preorder Traversal >> ");
    if (root == NULL)
        return;

    Node* curr;
    Node* stack[1000];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        curr = stack[top--];
        printf("%d ", curr->data);
        if (curr->rc)
            stack[++top] = curr->rc;
        if (curr->lc)
            stack[++top] = curr->lc;
    }
    printf("\n");
}

void iterativeInorder(Node* root) {
    printf("Iterative Inorder Traversal >> ");
    if (root == NULL)
        return;

    Node* curr = root;
    Node* stack[1000];
    int top = -1;

    while (curr != NULL || top >= 0) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->lc;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->rc;
    }
    printf("\n");
}

void iterativePostorder(Node* root) {
    printf("Iterative Postorder Traversal >> ");
    if (root == NULL)
        return;

    Node* curr = root;
    Node* stack[1000];
    int top = -1;

    do {
        while (curr) {
            if (curr->rc)
                stack[++top] = curr->rc;
            stack[++top] = curr;
            curr = curr->lc;
        }
        curr = stack[top--];

        if (curr->rc && stack[top] == curr->rc) {
            top--;
            stack[++top] = curr;
            curr = curr->rc;
        } else {
            printf("%d ", curr->data);
            curr = NULL;
        }
    } while (top >= 0);

    printf("\n");
}

Node* searchParent(Node* curr, int elem) {
    if (curr == NULL)
        return NULL;

    if (curr->lc && curr->lc->data == elem)
        return curr;
    else if (curr->rc && curr->rc->data == elem)
        return curr;

    Node* leftResult = searchParent(curr->lc, elem);
    if (leftResult)
        return leftResult;

    return searchParent(curr->rc, elem);
}

void parent(Node* root, int elem) {
    if (root->data == elem) {
        printf("Root has no parent\n");
        return;
    }

    Node* parent = searchParent(root, elem);
    if (parent) {
        printf("Parent is %d\n", parent->data);
    } else {
        printf("Element does not exist in the tree\n");
    }
}

int counter(Node* node) {
    if (node == NULL)
        return 0;

    int lDepth = counter(node->lc);
    int rDepth = counter(node->rc);

    if (lDepth > rDepth)
        return (lDepth + 1);
    else
        return (rDepth + 1);
}

void level(Node* root) {
    int v = counter(root);
    printf("Total Depth is: %d\n", v);
}

int searchAncestor(Node* node, int elem) {
    if (node == NULL)
        return 0;
    else if (node->data == elem)
        return 1;
    else if (searchAncestor(node->lc, elem) || searchAncestor(node->rc, elem)) {
        printf("%d ", node->data);
        return 1;
    }
    return 0;
}

void ancestors(Node* root, int elem) {
    if (root->data == elem)
        printf("Root element has no ancestor\n");
    else {
        if (!searchAncestor(root, elem))
            printf("Element does not exist in the tree\n");
    }
    printf("\n");
}

int leafcount(Node* node) {
    if (node == NULL)
        return 0;
    else if (!node->lc && !node->rc)
        return 1;
    else
        return leafcount(node->lc) + leafcount(node->rc);
}

void leafs(Node* root) {
    printf("Leafs present: %d\n", leafcount(root));
}

int main() {
    Node* root = createTree();
    iterativeInorder(root);
    iterativePreorder(root);

    int n;
    printf("Find parent of?");
    scanf("%d", &n);
    parent(root, n);
    level(root);

    printf("Find ancestor of?");
    scanf("%d", &n);
    ancestors(root, n);
    leafs(root);

    return 0;
}

