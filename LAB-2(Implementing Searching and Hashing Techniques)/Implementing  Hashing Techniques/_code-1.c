//WAP TO PERFORM HASHING USING MODULO DIVISION.
#include <stdio.h>

int hashFunction(int key, int size)
{
    return key % size;
}

int main()
{
    int key, size, index;

    printf("Enter hash table size: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid table size.");
        return 0;
    }

    printf("Enter key: ");
    scanf("%d", &key);

    index = hashFunction(key, size);

    printf("Hash index = %d", index);

    return 0;
}