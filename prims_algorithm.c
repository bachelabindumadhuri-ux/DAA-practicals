#include <stdio.h>

#define MAX 20
#define INF 9999

int main()
{
    int n;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int edges = 0;
    int min, u = 0, v = 0;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    // Start from vertex 0
    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        min = INF;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (min == INF)
        {
            printf("Graph is not connected.\n");
            return 0;
        }

        printf("%d - %d : %d\n", u, v, min);

        totalCost += min;
        visited[v] = 1;
        edges++;
    }

    printf("\nMinimum Cost = %d\n", totalCost);

    return 0;
}