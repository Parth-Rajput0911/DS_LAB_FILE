//WAP TO PERFORM HASHING USING DIRECT .
#include <stdio.h>
#define SIZE 100

void directHash(int table[], int key)
{
    table[key] = 1;
}

int main()
{
    int table[SIZE] = {0};
    int n, key, i;

    printf("Enter number of keys: ");
    scanf("%d", &n);

    if (n < 1 || n > SIZE)
    {
        printf("Invalid number of keys.");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter key (0-99): ");
        scanf("%d", &key);

        if (key >= 0 && key < SIZE)
            directHash(table, key);
        else
            printf("Invalid key!\n");
    }

    printf("Stored keys: ");

    for (i = 0; i < SIZE; i++)
    {
        if (table[i] == 1)
            printf("%d ", i);
    }

    return 0;
}