//WAP TO IMPLEMENT ADEQUE USING AN ARRAY.

#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

int isFull()
{
    return (front == 0 && rear == SIZE - 1) ||
           (front == rear + 1);
}

int isEmpty()
{
    return front == -1;
}

void insertFront()
{
    int value;

    if (isFull())
    {
        printf("Deque is full!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (isEmpty())
        front = rear = 0;
    else if (front == 0)
        front = SIZE - 1;
    else
        front--;

    deque[front] = value;

    printf("Element inserted at front.\n");
}

void insertRear()
{
    int value;

    if (isFull())
    {
        printf("Deque is full!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (isEmpty())
        front = rear = 0;
    else if (rear == SIZE - 1)
        rear = 0;
    else
        rear++;

    deque[rear] = value;

    printf("Element inserted at rear.\n");
}

void deleteFront()
{
    if (isEmpty())
    {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deleted element: %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else if (front == SIZE - 1)
        front = 0;
    else
        front++;
}

void deleteRear()
{
    if (isEmpty())
    {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deleted element: %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = SIZE - 1;
    else
        rear--;
}

void display()
{
    int i;

    if (isEmpty())
    {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque: ");
    i = front;

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insertFront(); break;
            case 2: insertRear(); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: display(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
