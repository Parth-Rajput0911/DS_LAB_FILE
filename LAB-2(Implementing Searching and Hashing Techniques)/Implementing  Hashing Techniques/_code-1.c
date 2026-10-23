//WAP TO IMPLEMENT HASHING TECHNIQUES.
#include <stdio.h>

#define MAX 100
#define TABLE 10

// 1. Modulo Division Hashing
int moduloHash(int key)
{
    return key % TABLE;
}

// 2. Digit Extraction Hashing
int digitExtraction(int key)
{
    int digit, result = 0;

    while (key > 0)
    {
        digit = key % 10;
        result = (result + digit) % TABLE;
        key = key / 100;
    }

    return result;
}

// 3. Fold Shift Hashing
int foldShift(int key)
{
    int sum = 0;

    while (key > 0)
    {
        sum += key % 100;
        key /= 100;
    }

    return sum % TABLE;
}

// 4. Fold Boundary Hashing
int foldBoundary(int key)
{
    int part, sum = 0, count = 0;

    while (key > 0)
    {
        part = key % 100;

        if (count % 2 == 1)
        {
            part = (part % 10) * 10 + part / 10;
        }

        sum += part;
        key /= 100;
        count++;
    }

    return sum % TABLE;
}

// 5. Direct Hashing
int directHash(int key)
{
    return key % TABLE;
}

// 6. Subtraction Hashing
int subtractionHash(int key)
{
    int first, second;

    first = key / 100;
    second = key % 100;

    return (first - second + TABLE * 100) % TABLE;
}

// 7. Linear Probing
void linearProbing(int keys[], int n)
{
    int table[TABLE];
    int i, index, count;

    for (i = 0; i < TABLE; i++)
        table[i] = -1;

    for (i = 0; i < n; i++)
    {
        index = moduloHash(keys[i]);
        count = 0;

        while (table[index] != -1 && count < TABLE)
        {
            index = (index + 1) % TABLE;
            count++;
        }

        if (count == TABLE)
            printf("%d cannot be inserted (table full)\n",
                   keys[i]);
        else
            table[index] = keys[i];
    }

    printf("\nHash Table using Linear Probing:\n");

    for (i = 0; i < TABLE; i++)
    {
        if (table[i] == -1)
            printf("Index %d: Empty\n", i);
        else
            printf("Index %d: %d\n", i, table[i]);
    }
}

int main()
{
    int keys[MAX], n, i, choice;

    printf("Enter number of keys (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of keys!\n");
        return 1;
    }

    printf("Enter non-negative integer keys:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &keys[i]);

        if (keys[i] < 0)
        {
            printf("Negative keys are not supported.\n");
            return 1;
        }
    }

    do
    {
        printf("\n--- HASHING MENU ---\n");
        printf("1. Modulo Division\n");
        printf("2. Digit Extraction\n");
        printf("3. Fold Shift\n");
        printf("4. Fold Boundary\n");
        printf("5. Linear Probing\n");
        printf("6. Direct Hashing\n");
        printf("7. Subtraction Hashing\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nModulo Division Hashing:\n");
                for (i = 0; i < n; i++)
                    printf("%d -> %d\n", keys[i],
                           moduloHash(keys[i]));
                break;

            case 2:
                printf("\nDigit Extraction Hashing:\n");
                for (i = 0; i < n; i++)
                    printf("%d -> %d\n", keys[i],
                           digitExtraction(keys[i]));
                break;

            case 3:
                printf("\nFold Shift Hashing:\n");
                for (i = 0; i < n; i++)
                    printf("%d -> %d\n", keys[i],
                           foldShift(keys[i]));
                break;

            case 4:
                printf("\nFold Boundary Hashing:\n");
                for (i = 0; i < n; i++)
                    printf("%d -> %d\n", keys[i],
                           foldBoundary(keys[i]));
                break;

            case 5:
                linearProbing(keys, n);
                break;

            case 6:
                printf("\nDirect Hashing:\n");
                for (i = 0; i < n; i++)
                    printf("%d -> %d\n", keys[i],
                           directHash(keys[i]));
                break;

            case 7:
                printf("\nSubtraction Hashing:\n");
                for (i = 0; i < n; i++)
                    printf("%d -> %d\n", keys[i],
                           subtractionHash(keys[i]));
                break;

            case 0:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
