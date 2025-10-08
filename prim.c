#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 20

// Function to find vertex with minimum weight
int minweight(int V, int weight[], bool visited[]) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && weight[v] < min) {
            min = weight[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print MST and total cost
void printMST(int V, int parent[], int graph[MAX][MAX]) {
    int totalCost = 0;
    printf("\nMinimum Spanning Tree (Prim's Algorithm):\n");
    printf("Edge\tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total cost of MST: %d\n", totalCost);
}

// Function to implement Prim's Algorithm
void primMST(int V, int graph[MAX][MAX]) {
    int parent[MAX];
    int weight[MAX];
    bool visited[MAX];

    for (int i = 0; i < V; i++) {
        weight[i] = INT_MAX;
        visited[i] = false;
    }

    weight[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minweight(V, weight, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < weight[v]) {
                parent[v] = u;
                weight[v] = graph[u][v];
            }
        }
    }
    for(int i=0;i<5;i++){
        printf("%d",parent[i]);
    }
    printMST(V, parent, graph);
}

int main() {
    int V, E;
    int graph[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        if (u >= 0 && v >= 0 && u < V && v < V) {
            graph[u][v] = w;
            graph[v][u] = w;  // Undirected graph
        } else {
            printf("Invalid edge! Try again.\n");
            i--; // retry this edge
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }

    primMST(V, graph);

    return 0;
}
