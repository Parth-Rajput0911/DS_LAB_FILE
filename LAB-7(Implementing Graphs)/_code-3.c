//WAP TO IMPLEMENT MINIMUM SPANNING TREE USING KURSKAL ALGORITHM.

#include <stdio.h>
#include <stdlib.h>

#define MAXV 20
#define MAXE 190

struct Edge {
    int u, v, weight;
};

struct Edge edges[MAXE];
int parent[MAXV];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

int compare(const void *a, const void *b) {
    const struct Edge *e1 = a;
    const struct Edge *e2 = b;

    if (e1->weight < e2->weight) return -1;
    if (e1->weight > e2->weight) return 1;
    return 0;
}

int main() {
    int vertices, edgeCount;
    int i, u, v, weight;
    int selected = 0;
    long long totalWeight = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    if (vertices < 1 || vertices > MAXV) {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edgeCount);

    if (edgeCount < 0 || edgeCount > MAXE) {
        printf("Invalid number of edges!\n");
        return 1;
    }

    for (i = 0; i < edgeCount; i++) {
        printf("Enter edge (u v weight): ");
        scanf("%d %d %d", &u, &v, &weight);

        if (u < 0 || u >= vertices || v < 0 ||
            v >= vertices || u == v) {
            printf("Invalid edge!\n");
            return 1;
        }

        edges[i].u = u;
        edges[i].v = v;
        edges[i].weight = weight;
    }

    for (i = 0; i < vertices; i++)
        parent[i] = i;

    qsort(edges, edgeCount, sizeof(struct Edge), compare);

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0; i < edgeCount && selected < vertices - 1; i++) {
        int rootU = find(edges[i].u);
        int rootV = find(edges[i].v);

        if (rootU != rootV) {
            parent[rootU] = rootV;

            printf("%d - %d : %d\n",
                   edges[i].u, edges[i].v, edges[i].weight);

            totalWeight += edges[i].weight;
            selected++;
        }
    }

    if (selected != vertices - 1) {
        printf("Graph is disconnected; no spanning tree exists.\n");
    } else {
        printf("Total MST Weight: %lld\n", totalWeight);
    }

    return 0;
}
