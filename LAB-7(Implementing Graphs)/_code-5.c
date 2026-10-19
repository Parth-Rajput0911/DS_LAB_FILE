//WAP TO IMPLEMENT DIJKSTAR ALGORITHM.

#include <stdio.h>

#define MAX 20
#define INF 1000000000

int main() {
    int graph[MAX][MAX];
    int distance[MAX];
    int visited[MAX] = {0};
    int vertices, edges;
    int i, u, v, weight, source;

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
            v >= vertices || u == v || weight < 0 ||
            weight >= INF) {
            printf("Invalid edge or weight!\n");
            i--;
            continue;
        }

        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    printf("Enter source vertex (0 to %d): ", vertices - 1);
    scanf("%d", &source);

    if (source < 0 || source >= vertices) {
        printf("Invalid source vertex!\n");
        return 1;
    }

    for (i = 0; i < vertices; i++)
        distance[i] = INF;

    distance[source] = 0;

    for (i = 0; i < vertices; i++) {
        int min = INF;
        int current = -1;

        for (int j = 0; j < vertices; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                current = j;
            }
        }

        if (current == -1)
            break;

        visited[current] = 1;

        for (int j = 0; j < vertices; j++) {
            if (!visited[j] &&
                graph[current][j] != INF &&
                distance[current] <= INF - graph[current][j] &&
                distance[current] + graph[current][j] < distance[j]) {

                distance[j] =
                    distance[current] + graph[current][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < vertices; i++) {
        if (distance[i] == INF)
            printf("To vertex %d: Unreachable\n", i);
        else
            printf("To vertex %d: %d\n", i, distance[i]);
    }

    return 0;
}
