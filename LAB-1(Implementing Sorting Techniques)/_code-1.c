//WAP TO IMPLEMENT SORTING TECHNIQUES.
#include <stdio.h>

#define MAX 100

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void bubbleSort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}

void insertionSort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void selectionSort(int a[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void shellSort(int a[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = a[i];
            for (j = i; j >= gap && a[j-gap] > temp; j -= gap)
                a[j] = a[j-gap];
            a[j] = temp;
        }
    }
}

int getMax(int a[], int n)
{
    int i, max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void countSort(int a[], int n, int exp)
{
    int output[MAX], count[10] = {0};
    int i, digit;

    for (i = 0; i < n; i++)
    {
        digit = (a[i] / exp) % 10;
        count[digit]++;
    }

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        digit = (a[i] / exp) % 10;
        output[--count[digit]] = a[i];
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int a[], int n)
{
    int exp, max = getMax(a, n);

    for (exp = 1; max / exp > 0; exp *= 10)
        countSort(a, n, exp);
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1, j, temp;

    for (j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    int a[MAX], b[MAX];
    int n, i, choice;

    printf("Enter number of elements (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid array size!\n");
        return 1;
    }

    printf("Enter %d non-negative integers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] < 0)
        {
            printf("Negative numbers are not supported.\n");
            return 1;
        }
    }

    do
    {
        printf("\n--- SORTING MENU ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Shell Sort\n");
        printf("5. Radix Sort\n");
        printf("6. Quick Sort\n");
        printf("7. Display Original Array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        for (i = 0; i < n; i++)
            b[i] = a[i];

        switch (choice)
        {
            case 1:
                bubbleSort(b, n);
                break;

            case 2:
                insertionSort(b, n);
                break;

            case 3:
                selectionSort(b, n);
                break;

            case 4:
                shellSort(b, n);
                break;

            case 5:
                radixSort(b, n);
                break;

            case 6:
                quickSort(b, 0, n - 1);
                break;

            case 7:
                printf("Original array: ");
                display(a, n);
                continue;

            case 0:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
                continue;
        }

        if (choice >= 1 && choice <= 6)
        {
            printf("Sorted array: ");
            display(b, n);
        }

    } while (choice != 0);

    return 0;
}
