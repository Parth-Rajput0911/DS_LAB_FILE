//WAP TO IMPLEMENT GIVEN FUNCTION USING MAX HEAP.

#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void reheapUp(int index) {
    int parent, temp;

    while (index > 0) {
        parent = (index - 1) / 2;

        if (heap[parent] >= heap[index])
            break;

        temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        index = parent;
    }
}

void reheapDown(int index) {
    int largest, left, right, temp;

    while (1) {
        largest = index;
        left = 2 * index + 1;
        right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest == index)
            break;

        temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;

        index = largest;
    }
}

void insert(int value) {
    if (size == MAX) {
        printf("Heap is full!\n");
        return;
    }

    heap[size] = value;
    reheapUp(size);
    size++;

    printf("Element inserted.\n");
}

void deleteMax() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Deleted maximum element: %d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    if (size > 0)
        reheapDown(0);
}

void display() {
    int i;

    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Max Heap: ");
    for (i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- MAX HEAP ---\n");
        printf("1. Insert\n");
        printf("2. Delete Maximum\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteMax();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
