//WAP TO IMPLEMENT PRIORITY QUEUE USING A LINKED LIST.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *front = NULL;

void insert()
{
    struct node *newnode, *temp;
    int value, p;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    printf("Enter priority (smaller number = higher priority): ");
    scanf("%d", &p);

    newnode->data = value;
    newnode->priority = p;
    newnode->next = NULL;

    if (front == NULL || p < front->priority)
    {
        newnode->next = front;
        front = newnode;
    }
    else
    {
        temp = front;

        while (temp->next != NULL &&
               temp->next->priority <= p)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    printf("Element inserted.\n");
}

void deleteElement()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    temp = front;

    printf("Deleted element: %d\n", front->data);

    front = front->next;
    free(temp);
}

void display()
{
    struct node *temp = front;

    if (front == NULL)
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Value\tPriority\n");

    while (temp != NULL)
    {
        printf("%d\t%d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insert(); break;
            case 2: deleteElement(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    while (front != NULL)
        deleteElement();

    return 0;
}
