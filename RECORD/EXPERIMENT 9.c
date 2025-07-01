#include <stdio.h>
#include <stdlib.h>

int findParent(int parent[], int component) {
    int result;
    if (parent[component] == component)
        return component;
    result = findParent(parent, parent[component]);
    parent[component] = result;
    return result;
}

void unionSet(int u, int v, int parent[], int rank[]) {
    int temp;
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalAlgo(int vertices, int edges[][3], int num_edges) {
    int temp[3], i, j, u, v, weight, minCost, k;
    minCost = 0;

    for (i = 0; i < num_edges - 1; i++) {
        for (j = i + 1; j < num_edges; j++) {
            if (edges[i][2] > edges[j][2]) {
                for (k = 0; k < 3; k++) {
                    temp[k] = edges[i][k];
                    edges[i][k] = edges[j][k];
                    edges[j][k] = temp[k];
                }
            }
        }
    }

    int parent[vertices], rank[vertices];
    for (i = 0; i < vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    printf("Edges in the Minimum Spanning Tree (MST):\n");

    for (i = 0; i < num_edges; i++) {
        u = findParent(parent, edges[i][0]);
        v = findParent(parent, edges[i][1]);
        weight = edges[i][2];

        if (u != v) {
            unionSet(u, v, parent, rank);
            printf("%d -- %d == %d\n", edges[i][0], edges[i][1], weight);
            minCost += weight;
        }
    }

    printf("Total Minimum Cost of Spanning Tree: %d\n", minCost);
}

int main() {
    int vertices, num_edges, i;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    int edges[num_edges][3];

    printf("Enter the edges (format: vertex1 vertex2 weight):\n");
    for (i = 0; i < num_edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    kruskalAlgo(vertices, edges, num_edges);

    return 0;
}

---

findParent

Step 1: Start.

Step 2: If the component is its own parent (i.e., parent[component] == component), return the component as its parent.

Step 3: Otherwise, recursively find the parent of the component.

Step 4: Perform path compression by setting the parent of the component to the found parent.

Step 5: Return the found parent.

Step 6: Stop.


---

unionSet

Step 1: Start.

Step 2: Find the parents of the two components u and v using findParent.

Step 3: If the rank of u is less than the rank of v, set parent[u] = v.

Step 4: If the rank of u is greater than the rank of v, set parent[v] = u.

Step 5: If the rank of u equals the rank of v, set parent[v] = u and increment the rank of u.

Step 6: Stop.


---

kruskalAlgo

Step 1: Start.

Step 2: Sort the edges in non-decreasing order of their weight using a nested loop.

Step 3: Initialize the parent and rank arrays. Set parent[i] = i and rank[i] = 0 for each vertex i.

Step 4: Initialize minCost = 0.

Step 5: For each edge (u, v, weight):

a. Find the parents of u and v.

b. If u and v are not connected (i.e., they belong to different components), add the edge to the MST, update the parent using unionSet, and add the weight to minCost.


Step 6: Print the edges in the MST and the total minimum cost.

Step 7: Stop.


---

main

Step 1: Start.

Step 2: Read the number of vertices and edges.

Step 3: Read the edges (each consisting of two vertices and a weight) into an adjacency list or array.

Step 4: Call kruskalAlgo to compute the Minimum Spanning Tree (MST) using Kruskal's algorithm.

Step 5: Stop.


---
