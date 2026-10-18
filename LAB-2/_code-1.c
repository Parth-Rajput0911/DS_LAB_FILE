//WAP TO SEARCH AN ELEMENT USING LINEAR SEARCH.
#include <stdio.h>

int linearSearch(int a[], int n, int key)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
            return i;
    }

    return -1;
}

int main()
{
    int a[100], n, i, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid array size!");
        return 0;
    }

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = linearSearch(a, n, key);

    if (result == -1)
        printf("Element not found.");
    else
        printf("Element found at position %d.", result + 1);

    return 0;
}
