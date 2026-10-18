//WAP TO PERFORM HASHING USING FOLD BOUNDARY.
#include <stdio.h>

int reverseTwoDigits(int n)
{
    return (n % 10) * 10 + n / 10;
}

int foldBoundary(int key)
{
    int first, middle, last;

    first = key / 10000;
    middle = (key / 100) % 100;
    last = key % 100;

    return reverseTwoDigits(first)
         + middle
         + reverseTwoDigits(last);
}

int main()
{
    int key, result;

    printf("Enter a 6-digit key: ");
    scanf("%d", &key);

    if (key < 100000 || key > 999999)
    {
        printf("Please enter a 6-digit key.");
        return 0;
    }

    result = foldBoundary(key);

    printf("Fold Boundary Hash = %d", result);

    return 0;
}