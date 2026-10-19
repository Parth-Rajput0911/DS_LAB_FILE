//WAP TO CREATE AND IMPLEMENT GIVEN FUNCTION ON BINARY SEARCH TREE.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        printf("Duplicate values are not allowed: %d\n", value);
    }

    return root;
}

int findSmallest(struct Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}

int findLargest(struct Node *root) {
    while (root->right != NULL) {
        root = root->right;
    }

    return root->data;
}

int countNodes(struct Node *root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node *root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        if (scanf("%d", &value) != 1) {
            printf("Invalid input!\n");
            freeTree(root);
            return 1;
        }

        root = insert(root, value);
    }

    if (root == NULL) {
        printf("Tree is empty.\n");
    } else {
        printf("\nSmallest Node: %d\n", findSmallest(root));
        printf("Largest Node: %d\n", findLargest(root));
        printf("Total Number of Nodes: %d\n", countNodes(root));
    }

    freeTree(root);
    return 0;
}
