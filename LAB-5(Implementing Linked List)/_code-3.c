//WAP TO IMPLEMENT DOUBLY LINKED LIST.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insert() {
    int value;
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node inserted successfully.\n");
}

void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: NULL <-> ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void deleteNode() {
    int value;
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node deleted successfully.\n");
}

void search() {
    int value, position = 1;
    struct Node *temp = head;

    printf("Enter value to search: ");
    scanf("%d", &value);

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value found at position %d.\n", position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Value not found.\n");
}

void count() {
    int total = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        total++;
        temp = temp->next;
    }

    printf("Total nodes: %d\n", total);
}

void freeList() {
    struct Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Count\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            freeList();
            return 1;
        }

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                deleteNode();
                break;

            case 4:
                search();
                break;

            case 5:
                count();
                break;

            case 6:
                freeList();
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
