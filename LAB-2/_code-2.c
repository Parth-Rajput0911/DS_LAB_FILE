//WAP TO SEARCH AN ELEMENT USING BINARY SEARCH.
#include <stdio.h>

int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
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

    printf("Enter elements in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(a, n, key);

    if (result == -1)
        printf("Element not found.");
    else
        printf("Element found at position %d.", result + 1);

    return 0;
}
