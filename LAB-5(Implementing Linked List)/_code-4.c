//WAP TO PERFORM POLYNOMIAL ADDITION USING LINKED LIST.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node *next;
};

struct Node *createNode(int coeff, int power) {
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;

    return newNode;
}

void insertTerm(struct Node **head, int coeff, int power) {
    struct Node *newNode, *temp, *prev;

    if (coeff == 0)
        return;

    newNode = createNode(coeff, power);

    if (*head == NULL || (*head)->power < power) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    temp = *head;
    prev = NULL;

    while (temp != NULL && temp->power > power) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL && temp->power == power) {
        temp->coeff += coeff;
        free(newNode);

        if (temp->coeff == 0) {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
        }
        return;
    }

    newNode->next = temp;

    if (prev != NULL)
        prev->next = newNode;
    else
        *head = newNode;
}

struct Node *readPolynomial() {
    struct Node *head = NULL;
    int n, coeff, power;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &coeff, &power);
        insertTerm(&head, coeff, power);
    }

    return head;
}

struct Node *addPolynomials(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->power == p2->power) {
            insertTerm(&result, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->power > p2->power) {
            insertTerm(&result, p1->coeff, p1->power);
            p1 = p1->next;
        } else {
            insertTerm(&result, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->power);

        if (head->next != NULL)
            printf(" + ");

        head = head->next;
    }

    printf("\n");
}

void freeList(struct Node *head) {
    struct Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node *p1, *p2, *sum;

    printf("Enter first polynomial:\n");
    p1 = readPolynomial();

    printf("\nEnter second polynomial:\n");
    p2 = readPolynomial();

    printf("\nFirst Polynomial: ");
    display(p1);

    printf("Second Polynomial: ");
    display(p2);

    sum = addPolynomials(p1, p2);

    printf("Sum of Polynomials: ");
    display(sum);

    freeList(p1);
    freeList(p2);
    freeList(sum);

    return 0;
}
