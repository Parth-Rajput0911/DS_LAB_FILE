//WAP TO PERFORM HASHING USING DIGIT EXTRACTION.
#include <stdio.h>

int digitExtraction(int key)
{
    int hundreds, units;

    hundreds = (key / 100) % 10;
    units = key % 10;

    return hundreds * 10 + units;
}

int main()
{
    int key, result;

    printf("Enter a 4-digit key: ");
    scanf("%d", &key);

    if (key < 1000 || key > 9999)
    {
        printf("Please enter a 4-digit key.");
        return 0;
    }

    result = digitExtraction(key);

    printf("Hash value = %d", result);

    return 0;
}