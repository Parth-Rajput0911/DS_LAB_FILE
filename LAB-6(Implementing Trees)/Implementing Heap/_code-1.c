//WAP TO IMPLEMENT GIVEN FUNCTION USING MIN HEAP.

#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void reheapUp(int index) {
    int parent, temp;

    while (index > 0) {
        parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        index = parent;
    }
}

void reheapDown(int index) {
    int smallest, left, right, temp;

    while (1) {
        smallest = index;
        left = 2 * index + 1;
        right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;

        index = smallest;
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

void deleteMin() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Deleted minimum element: %d\n", heap[0]);

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

    printf("Min Heap: ");
    for (i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- MIN HEAP ---\n");
        printf("1. Insert\n");
        printf("2. Delete Minimum\n");
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
                deleteMin();
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
