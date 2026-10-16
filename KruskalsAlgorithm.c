
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int u, v, weight;
};

struct Edge edges[MAX];

int parent[MAX];

int find(int i) {
    while (parent[i] != i) {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}

void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootU] = rootV;
}

int main(void) {
    int n, m, selected = 0;
    long long totalCost = 0;

    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter number of edges: ");
    if (scanf("%d", &m) != 1) {
        printf("Invalid number of edges.\n");
        return 1;
    }

    if (n <= 0 || n > MAX || m < 0 || m > MAX) {
        printf("Invalid number of vertices or edges.\n");
        return 1;
    }

    printf("Enter edges (source destination weight):\n");

    for (int i = 0; i < m; i++) {
        if (scanf("%d %d %d",
                  &edges[i].u, &edges[i].v, &edges[i].weight) != 3) {
            printf("Invalid edge input.\n");
            return 1;
        }

        if (edges[i].u < 0 || edges[i].u >= n ||
            edges[i].v < 0 || edges[i].v >= n ||
            edges[i].u == edges[i].v) {
            printf("Invalid edge.\n");
            return 1;
        }
    }

    /* Sort edges by weight using bubble sort */
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("Edges in Minimum Spanning Tree:\n");

    for (int i = 0; i < m && selected < n - 1; i++) {
        int rootU = find(edges[i].u);
        int rootV = find(edges[i].v);

        if (rootU != rootV) {
            printf("%d - %d : %d\n",
                   edges[i].u, edges[i].v, edges[i].weight);

            unionSets(rootU, rootV);
            totalCost += edges[i].weight;
            selected++;
        }
    }

    if (selected != n - 1) {
        printf("Graph is disconnected; MST cannot be formed.\n");
    } else {
        printf("Total minimum cost = %lld\n", totalCost);
    }

    return 0;
}
