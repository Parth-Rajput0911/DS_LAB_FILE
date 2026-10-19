//WAP TO IMPLEMENT ADEQUE USING A LINKED LIST.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insertFront(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;

    if (front == NULL) {
        front = rear = newNode;
    } else {
        front->prev = newNode;
        front = newNode;
    }

    printf("%d inserted at front.\n", value);
}

void insertRear(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted at rear.\n", value);
}

void deleteFront() {
    if (front == NULL) {
        printf("Deque is empty!\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted element: %d\n", front->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    } else {
        front->prev = NULL;
    }

    free(temp);
}

void deleteRear() {
    if (rear == NULL) {
        printf("Deque is empty!\n");
        return;
    }

    struct Node *temp = rear;
    printf("Deleted element: %d\n", rear->data);

    rear = rear->prev;

    if (rear == NULL) {
        front = NULL;
    } else {
        rear->next = NULL;
    }

    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Deque is empty!\n");
        return;
    }

    struct Node *temp = front;

    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeDeque() {
    struct Node *temp;

    while (front != NULL) {
        temp = front;
        front = front->next;
        free(temp);
    }

    rear = NULL;
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- DEQUE USING LINKED LIST ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            freeDeque();
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input!\n");
                    freeDeque();
                    return 1;
                }
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input!\n");
                    freeDeque();
                    return 1;
                }
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                freeDeque();
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

