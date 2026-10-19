//WAP TO TRAVERSE A GRAPH USING BREADTH FIRST SEARCH.

#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = -1;

void BFS(int vertices, int start) {
    int i, current;

    visited[start] = 1;
    queue[++rear] = start;

    printf("BFS Traversal: ");

    while (front <= rear) {
        current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    printf("\n");
}

int main() {
    int vertices, edges;
    int i, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    if (vertices < 1 || vertices > MAX) {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    if (edges < 0 || edges > vertices * (vertices - 1) / 2) {
        printf("Invalid number of edges!\n");
        return 1;
    }

    for (i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= vertices || v < 0 ||
            v >= vertices || u == v) {
            printf("Invalid edge!\n");
            i--;
            continue;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting vertex (0 to %d): ", vertices - 1);
    scanf("%d", &start);

    if (start < 0 || start >= vertices) {
        printf("Invalid starting vertex!\n");
        return 1;
    }

    BFS(vertices, start);

    return 0;
}
