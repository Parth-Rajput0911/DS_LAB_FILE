//WAP TO IMPLEMENT EXPRESSION TREE USING HEAP.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *stack[MAX];
int top = -1;

struct Node *createNode(char value) {
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

int isOperator(char ch) {
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/';
}

void push(struct Node *node) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }

    stack[++top] = node;
}

struct Node *pop() {
    if (top < 0)
        return NULL;

    return stack[top--];
}

void inorder(struct Node *root) {
    if (root != NULL) {
        if (isOperator(root->data))
            printf("(");

        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);

        if (isOperator(root->data))
            printf(")");
    }
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    char postfix[MAX];
    struct Node *root, *left, *right;
    int i, valid = 1;

    printf("Enter postfix expression: ");
    scanf("%99s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isalnum((unsigned char)ch)) {
            push(createNode(ch));
        } else if (isOperator(ch)) {
            right = pop();
            left = pop();

            if (left == NULL || right == NULL) {
                valid = 0;
                break;
            }

            root = createNode(ch);
            root->left = left;
            root->right = right;
            push(root);
        } else {
            valid = 0;
            break;
        }
    }

    if (!valid || top != 0) {
        printf("Invalid postfix expression!\n");

        while (top >= 0)
            freeTree(pop());

        return 1;
    }

    root = pop();

    printf("Inorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");

    freeTree(root);
    return 0;
}
