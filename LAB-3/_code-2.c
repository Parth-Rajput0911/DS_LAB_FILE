//WAP TO IMPLEMENT USING LINKED LIST.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = top;
    top = newnode;

    printf("Element pushed successfully.\n");
}

void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        temp = top;

        printf("Deleted element: %d\n", top->data);

        top = top->next;
        free(temp);
    }
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element: %d\n", top->data);
    }
}

void display()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        temp = top;

        printf("Stack elements are:\n");

        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    while (top != NULL)
    {
        struct node *temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}
