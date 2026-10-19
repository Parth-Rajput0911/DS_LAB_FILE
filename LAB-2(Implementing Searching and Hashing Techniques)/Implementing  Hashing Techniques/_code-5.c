//WAP TO PERFORM HASHING USING LINEAR PROBING.
#include <stdio.h>
#define SIZE 10

int hashFunction(int key)
{
    return key % SIZE;
}

void insert(int table[], int key)
{
    int index, i;

    index = hashFunction(key);

    for (i = 0; i < SIZE; i++)
    {
        if (table[index] == -1)
        {
            table[index] = key;
            printf("%d inserted at index %d\n", key, index);
            return;
        }

        index = (index + 1) % SIZE;
    }

    printf("Hash table is full!\n");
}

void display(int table[])
{
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("Index %d: ", i);

        if (table[i] == -1)
            printf("Empty\n");
        else
            printf("%d\n", table[i]);
    }
}

int main()
{
    int table[SIZE];
    int n, key, i;

    for (i = 0; i < SIZE; i++)
        table[i] = -1;

    printf("Enter number of keys (maximum 10): ");
    scanf("%d", &n);

    if (n < 1 || n > SIZE)
    {
        printf("Invalid number of keys.");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter key: ");
        scanf("%d", &key);
        insert(table, key);
    }

    display(table);

    return 0;
}