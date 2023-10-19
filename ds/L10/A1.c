#include <stdio.h>
#include <stdbool.h>

struct Node {
    struct Node* lc;
    struct Node* rc;
    int data;
};

typedef struct Node Node;

typedef struct {
    Node* root;
} Tree;

Node* createTree() {
    int val;
    printf(">");
    scanf("%d", &val);
    if (val == -1)
        return NULL;
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    printf("Left child of %d\n", val);
    temp->lc = createTree();
    printf("Right child of %d\n", val);
    temp->rc = createTree();
    return temp;
}

bool isEqualTrees(Tree* t1, Tree* t2) {
    Node* root1 = t1->root;
    Node* root2 = t2->root;

    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    Node* queue1[100];
    Node* queue2[100];
    int front1 = 0, rear1 = -1;
    int front2 = 0, rear2 = -1;

    queue1[++rear1] = root1;
    queue2[++rear2] = root2;

    while (front1 <= rear1 && front2 <= rear2) {
        Node* n1 = queue1[front1++];
        Node* n2 = queue2[front2++];

        if (n1->data != n2->data)
            return false;

        if (n1->lc && n2->lc) {
            queue1[++rear1] = n1->lc;
            queue2[++rear2] = n2->lc;
        } else if (n1->lc || n2->lc)
            return false;

        if (n1->rc && n2->rc) {
            queue1[++rear1] = n1->rc;
            queue2[++rear2] = n2->rc;
        } else if (n1->rc || n2->rc)
            return false;
    }
    return true;
}

int main() {
    Tree t1;
    printf("Enter root of Tree 1:\n");
    t1.root = createTree();

    Tree t2;
    printf("Enter root of Tree 2:\n");
    t2.root = createTree();

    if (isEqualTrees(&t1, &t2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
