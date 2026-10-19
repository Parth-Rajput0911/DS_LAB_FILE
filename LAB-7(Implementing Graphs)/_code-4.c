//WAP TO IMPLEMENT MINIMUM SPANNING TREE USING PRIM ALGORITHM.

#include <stdio.h>

#define MAX 20
#define INF 1000000000

int main() {
    int graph[MAX][MAX];
    int selected[MAX] = {0};
    int vertices, edges;
    int i, u, v, weight;
    int count = 0;
    long long totalWeight = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    if (vertices < 1 || vertices > MAX) {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    for (i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    if (edges < 0 || edges > vertices * (vertices - 1) / 2) {
        printf("Invalid number of edges!\n");
        return 1;
    }

    for (i = 0; i < edges; i++) {
        printf("Enter edge (u v weight): ");
        scanf("%d %d %d", &u, &v, &weight);

        if (u < 0 || u >= vertices || v < 0 ||
            v >= vertices || u == v) {
            printf("Invalid edge!\n");
            i--;
            continue;
        }

        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    selected[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (count < vertices - 1) {
        int min = INF;
        int from = -1, to = -1;

        for (i = 0; i < vertices; i++) {
            if (selected[i]) {
                for (int j = 0; j < vertices; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        from = i;
                        to = j;
                    }
                }
            }
        }

        if (to == -1) {
            printf("Graph is disconnected; no spanning tree exists.\n");
            return 0;
        }

        printf("%d - %d : %d\n", from, to, min);
        totalWeight += min;
        selected[to] = 1;
        count++;
    }

    printf("Total MST Weight: %lld\n", totalWeight);

    return 0;
}
