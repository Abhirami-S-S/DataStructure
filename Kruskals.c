#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 50
#define INF INT_MAX
#define no_edge -1

int n = 0; // no. of vertices
int edge_count = 0;

struct Edge
{
    int u, v, w;
};

struct Edge edges[MAX * (MAX - 1) / 2];
struct Edge mst[MAX];

int parent[MAX];
int rank_arr[MAX];

int mst_edges = 0;
int min_cost = 0;
int mst_found = 0;

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void union_sets(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
        return;
    if (rank_arr[rootX] < rank_arr[rootY])
        parent[rootX] = rootY;
    else if (rank_arr[rootX] > rank_arr[rootY])
        parent[rootY] = rootX;
    else
    {
        parent[rootY] = rootX;
        rank_arr[rootX]++;
    }
}

void sort_edges()
{
    for (int i = 0; i < edge_count - 1; i++)
    {
        for (int j = 0; j < edge_count - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void read()
{
    printf("Enter the number of vertices (max %d): ", MAX);
    if (scanf("%d", &n) != 1 || n <= 1 || n > MAX)
    {
        printf("Invalid vertex count! Must be between 2 and %d.\n", MAX);
        n = 0;
        return;
    }

    edge_count = 0;
    printf("\nEnter edges in the format: <source> <destination> <weight>\n");
    printf("Example:\n1 2 5\n1 3 2\n2 3 4\n");
    printf("Enter 0 0 0 to stop.\n");

    while (1)
    {
        int u, v, w;
        printf("Edge (u v w): ");
        if (scanf("%d %d %d", &u, &v, &w) != 3)
        {
            printf("Invalid input! Try again.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (u == 0 && v == 0 && w == 0)
            break;

        if (u < 1 || v < 1 || u > n || v > n)
        {
            printf("Invalid vertex number! Must be between 1 and %d.\n", n);
            continue;
        }

        if (w <= 0)
        {
            printf("Weight must be positive!\n");
            continue;
        }

        edges[edge_count].u = u - 1; // 0-based internally
        edges[edge_count].v = v - 1;
        edges[edge_count].w = w;
        edge_count++;
    }

    printf("\nGraph loaded successfully! Total edges: %d\n", edge_count);
    mst_found = 0;
}

void kruskal()
{
    if (n == 0)
    {
        printf("Graph not loaded yet!\n");
        return;
    }

    printf("\n----- Kruskal's Algorithm Running -----\n");

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank_arr[i] = 0;
    }

    sort_edges();

    mst_edges = 0;
    min_cost = 0;

    for (int i = 0; i < edge_count && mst_edges < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV)
        {
            mst[mst_edges++] = edges[i];
            min_cost += w;
            union_sets(rootU, rootV);
        }
    }

    if (mst_edges != n - 1)
    {
        printf("Graph is disconnected! MST could not be formed completely.\n");
        mst_found = mst_edges;
        return;
    }

    mst_found = 1;
    printf("Kruskal’s algorithm completed successfully!\n");
}

void display_mst()
{
    if (n == 0 || !mst_found)
    {
        printf("ERROR: MST not yet calculated. Please select 1 and 2 first.\n");
        return;
    }

    printf("\n----- Minimum Spanning Tree (Kruskal’s) -----\n");
    printf("Total Vertices: %d\n", n);
    printf("Edges in MST:\n");
    for (int i = 0; i < mst_edges; i++)
    {
        printf("%d) (%d, %d) - Cost: %d\n", i + 1, mst[i].u + 1, mst[i].v + 1, mst[i].w);
    }
    printf("Total Minimum Cost: %d\n", min_cost);
}

int main()
{
    printf("\n***** Kruskal's Algorithm *****\n");
    printf("%d is used for No edge (infinity)\n", no_edge);

    int ch;
    while (1)
    {
        printf("\n1) Read Graph (Edge List)\n");
        printf("2) Run Kruskal's Algorithm\n");
        printf("3) Display MST\n");
        printf("4) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch)
        {
        case 1:
            read();
            break;
        case 2:
            kruskal();
            break;
        case 3:
            display_mst();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
