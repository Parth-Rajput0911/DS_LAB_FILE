//WAP TO PERFORM HASHING USING FOLD SHIFT.
#include <stdio.h>

int foldShift(int key)
{
    int sum = 0;

    while (key > 0)
    {
        sum = sum + key % 100;
        key = key / 100;
    }

    return sum;
}

int main()
{
    int key, result;

    printf("Enter key: ");
    scanf("%d", &key);

    if (key < 0)
    {
        printf("Enter a non-negative key.");
        return 0;
    }

    result = foldShift(key);

    printf("Fold Shift Hash = %d", result);

    return 0;
}