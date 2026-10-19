//WAP TO IMPLEMENT CIRCULAR LINKED LIST.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
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

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    printf("Node inserted successfully.\n");
}

void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

void deleteNode() {
    int value;
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;
    prev = NULL;

    /* Search for the node */
    while (temp->data != value) {
        prev = temp;
        temp = temp->next;

        if (temp == head) {
            printf("Value not found.\n");
            return;
        }
    }

    /* Only one node in the list */
    if (temp->next == head && temp == head) {
        head = NULL;
    }
    /* Deleting the first node */
    else if (temp == head) {
        struct Node *last = head;

        while (last->next != head) {
            last = last->next;
        }

        head = head->next;
        last->next = head;
    }
    /* Deleting a middle or last node */
    else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Node deleted successfully.\n");
}

void search() {
    int value, position = 1;
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    temp = head;

    do {
        if (temp->data == value) {
            printf("Value found at position %d.\n", position);
            return;
        }

        temp = temp->next;
        position++;

    } while (temp != head);

    printf("Value not found.\n");
}

void count() {
    int total = 0;
    struct Node *temp;

    if (head == NULL) {
        printf("Total nodes: 0\n");
        return;
    }

    temp = head;

    do {
        total++;
        temp = temp->next;
    } while (temp != head);

    printf("Total nodes: %d\n", total);
}

void freeList() {
    struct Node *temp;

    if (head == NULL) {
        return;
    }

    struct Node *current = head->next;

    while (current != head) {
        temp = current;
        current = current->next;
        free(temp);
    }

    free(head);
    head = NULL;
}

int main() {
    int choice;

    while (1) {
        printf("\n--- CIRCULAR LINKED LIST ---\n");
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
