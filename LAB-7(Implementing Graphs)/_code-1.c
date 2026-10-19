//WAP TO REPRESENT A GRAPH USING ADJACENCY MATRIX.

#include <stdio.h>

#define MAX 20

int main() {
    int graph[MAX][MAX];
    int vertices, edges;
    int i, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    if (vertices < 1 || vertices > MAX) {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    for (i = 0; i < vertices; i++) {
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
        printf("Enter edge (source destination), vertices 0 to %d: ",
               vertices - 1);
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= vertices || v < 0 || v >= vertices || u == v) {
            printf("Invalid edge!\n");
            i--;
            continue;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("\nAdjacency Matrix:\n");

    for (i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
