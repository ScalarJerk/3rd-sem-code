#include <stdio.h>
#include <stdlib.h>

// Define the struct node for the binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function prototypes
struct node* create_node(int data);
struct node* insert(struct node* root, int data);
struct node* delete(struct node* root, int data);
struct node* search(struct node* root, int data);
void level_order_traversal(struct node* root);

// Main function
int main() {
    struct node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Search for an element\n");
        printf("4. Level-order traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                if (search(root, data) == NULL) {
                    printf("Element not found\n");
                } else {
                    printf("Element found\n");
                }
                break;
            case 4:
                printf("Level-order traversal: ");
                level_order_traversal(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

// Function to create a new node
struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert an element into the binary search tree
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to delete an element from the binary search tree
struct node* delete(struct node* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// Function to search for an element in the binary search tree
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to perform level-order traversal of the binary search tree
void level_order_traversal(struct node* root) {
    if (root == NULL) {
        return;
    }
    struct node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct node* current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}
