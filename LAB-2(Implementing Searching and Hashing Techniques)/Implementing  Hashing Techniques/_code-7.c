//WAP TO PERFORM HASHING USING SUBTRACTION .
#include <stdio.h>

int subtractionHash(int key, int base)
{
    return key - base;
}

int main()
{
    int key, base, result;

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Enter base value: ");
    scanf("%d", &base);

    if (key < base)
    {
        printf("Key must be greater than or equal to base.");
        return 0;
    }

    result = subtractionHash(key, base);

    printf("Hash index = %d", result);

    return 0;
}