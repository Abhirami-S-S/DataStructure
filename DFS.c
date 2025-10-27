#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int visited[MAX];
void dfs(int g[MAX][MAX], int n, int st)
{
    printf("%d ", st);
    visited[st] = 1;
    for (int i = 0; i < n; i++)
    {
        if (g[st][i] == 1 && visited[i] == 0)
        {
            dfs(g, n, i);
        }
    }
}
void main()
{
    int g[MAX][MAX], n, st, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    printf("Enter the edges (0 < u,v < %d):\nu       v\n", n);
    printf("------------------\n");
    for (int i = 0; i < e; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][v] = 1;
        g[v][u] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("Graph adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &st);
    printf("Depth First Search starting from vertex %d:\n", st);
    dfs(g, n, st);
    printf("\n");
}
