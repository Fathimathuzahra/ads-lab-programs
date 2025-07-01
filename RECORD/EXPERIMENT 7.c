#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void dfs(int adj[MAX][MAX], int V, int s, bool visited[MAX]) {
    int i;
    visited[s] = true;
    printf("%d ", s);
    
    for (i = 0; i <=V; i++) {
        if (adj[s][i] == 1 && !visited[i]) {
            dfs(adj, V, i, visited);
        }
    }
}

int main() {
    int V, E, u, v, startVertex, i;
    int adj[MAX][MAX] = {0};
    
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    
    printf("Enter edges (u v):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }
    
    bool visited[MAX] = {false};
    printf("DFS starting from vertex : ");
    scanf("%d", &startVertex);
    
    dfs(adj, V, startVertex, visited);
    
    return 0;
}







---

dfs

Step 1: Start.

Step 2: Mark the current vertex s as visited (visited[s] = true) and print it.

Step 3: For each vertex i from 0 to V:

a. If the edge between s and i exists (adj[s][i] == 1) and i is not visited, call dfs recursively with vertex i.


Step 4: Stop.


---

main

Step 1: Start.

Step 2: Read the number of vertices V and edges E.

Step 3: Initialize the adjacency matrix adj[MAX][MAX] to 0.

Step 4: For each edge (u, v), set adj[u][v] = adj[v][u] = 1 (undirected graph).

Step 5: Initialize the visited array with false.

Step 6: Read the starting vertex for DFS.

Step 7: Call dfs(adj, V, startVertex, visited) to perform the DFS traversal starting from the given vertex.

Step 8: Stop.


---
