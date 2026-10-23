//WAP TO IMPLEMENT SEARCHING TECHNIQUES.
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

int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

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
    int a[100], n, i, key, choice, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid array size!\n");
        return 1;
    }

    printf("Enter elements in ascending order:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    do
    {
        printf("\n--- SEARCH MENU ---\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2)
        {
            printf("Enter element to search: ");
            scanf("%d", &key);

            if (choice == 1)
                result = linearSearch(a, n, key);
            else
                result = binarySearch(a, n, key);

            if (result == -1)
                printf("Element not found.\n");
            else
                printf("Element found at position %d.\n",
                       result + 1);
        }
        else if (choice == 0)
        {
            printf("Program terminated.\n");
        }
        else
        {
            printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
