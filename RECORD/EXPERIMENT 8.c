#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, minIndex, v;
    for (v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(int adj[MAX][MAX], int V) {
    int parent[V], i, count, u, v;
    int key[V];
    bool mstSet[V];
    int totalCost = 0;
    for (i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    for (count = 0; count < V - 1; count++) {
        u = minKey(key, mstSet, V);
        mstSet[u] = true;
        for (v = 0; v < V; v++) {
            if (adj[u][v] != 0 && !mstSet[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }
    printf("Edge \tWeight\n");
    for (i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, adj[i][parent[i]]);
        totalCost += adj[i][parent[i]];
    }
    printf("\nTotal cost of MST: %d\n", totalCost);
}

void addEdge(int adj[MAX][MAX], int u, int v, int weight) {
    adj[u][v] = weight;
    adj[v][u] = weight;
}

int main() {
    int V, E, i;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    int adj[MAX][MAX] = {0};

    printf("Enter the edges in the format (u v weight):\n");
    for (i = 0; i < E; i++) {
        int u, v, weight;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(adj, u, v, weight);
    }

    printf("Minimum Spanning Tree (MST) using Prim's Algorithm:\n");
    primMST(adj, V);

    return 0;
}

minKey

Step 1: Start.

Step 2: Initialize min as INT_MAX and minIndex as an undefined value.

Step 3: Loop through all vertices v from 0 to V-1:

If vertex v is not in the MST (!mstSet[v]) and the key value key[v] is smaller than min, update min and set minIndex = v.


Step 4: Return minIndex.

Step 5: Stop.


---

primMST

Step 1: Start.

Step 2: Initialize arrays:

parent[] to store parent vertices.

key[] to store the minimum key values.

mstSet[] to track included vertices in the MST.
Set key[0] = 0.


Step 3: Repeat V-1 times (as MST will have V-1 edges):

Call minKey() to find vertex u with the minimum key value.

Set mstSet[u] = true.

For each adjacent vertex v of u:

If v is not in MST and adj[u][v] < key[v], update key[v] and set parent[v] = u.



Step 4: After the loop, print each edge from parent[] and its respective weight.

Step 5: Calculate and display the total cost of the MST.

Step 6: Stop.


---

addEdge

Step 1: Start.

Step 2: Set adj[u][v] = weight and adj[v][u] = weight to add the edge between vertices u and v with the given weight.

Step 3: Stop.


---

main

Step 1: Start.

Step 2: Input the number of vertices V and edges E.

Step 3: Initialize the adjacency matrix adj[MAX][MAX] with zeros.

Step 4: Loop to input E edges, for each edge (u, v, weight), call addEdge() to update the adjacency matrix.

Step 5: Call primMST() to compute and display the Minimum Spanning Tree.

Step 6: Stop.
