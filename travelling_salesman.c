#include <stdio.h>

#define MAX 20
#define INF 999999

int n;
int cost[MAX][MAX];
int visited[MAX];
int minCost = INF;

void tsp(int current, int count, int totalCost)
{

    // All cities visited
    if (count == n)
    {
        if (cost[current][0] != 0)
        {
            int finalCost = totalCost + cost[current][0];

            if (finalCost < minCost)
                minCost = finalCost;
        }
        return;
    }

    // Visit unvisited cities
    for (int i = 0; i < n; i++)
    {

        if (!visited[i] && cost[current][i] != 0)
        {

            visited[i] = 1;

            tsp(i, count + 1,
                totalCost + cost[current][i]);

            visited[i] = 0;
        }
    }
}

int main()
{

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    // Start from city 0
    visited[0] = 1;

    tsp(0, 1, 0);

    if (minCost == INF)
        printf("No possible tour.\n");
    else
        printf("\nMinimum travelling cost = %d\n", minCost);

    return 0;
}