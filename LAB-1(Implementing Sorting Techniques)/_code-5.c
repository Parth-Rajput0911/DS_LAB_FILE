//WAP TO SORT AN ARRAY USING RADIX SORT.
#include <stdio.h>

int findMax(int a[], int n)
{
    int max = a[0];
    int i;

    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    return max;
}

void countSort(int a[], int n, int exp)
{
    int output[100];
    int count[10] = {0};
    int i, digit;

    for (i = 0; i < n; i++)
    {
        digit = (a[i] / exp) % 10;
        count[digit]++;
    }

    for (i = 1; i < 10; i++)
        count[i] = count[i] + count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int a[], int n)
{
    int max, exp;

    max = findMax(a, n);

    for (exp = 1; max / exp > 0; exp = exp * 10)
        countSort(a, n, exp);
}

int main()
{
    int a[100], n, i, valid = 1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid size!");
        return 0;
    }

    printf("Enter non-negative elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);

        if (a[i] < 0)
            valid = 0;
    }

    if (!valid)
    {
        printf("Negative numbers are not allowed.");
        return 0;
    }

    radixSort(a, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}