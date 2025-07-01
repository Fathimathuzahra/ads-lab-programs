#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void bfs(int adj[MAX][MAX], int V, int s) {
    int queue[MAX], front, rear, curr, i;
    bool visited[MAX];
    
    front = 0;
    rear = 0;
    for (i = 0; i < MAX; i++) visited[i] = false; // Initialize visited array
    
    visited[s] = true;
    queue[rear++] = s;

    while (front < rear) {
        curr = queue[front++];
        printf("%d ", curr);

        for (i = 0; i <= V; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
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
        adj[u][v] = adj[v][u] = 1;  // Undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &startVertex);

    bfs(adj, V, startVertex);
    
    return 0;
}



---

bfs

Step 1: Start.

Step 2: Initialize the queue with size MAX, and set front and rear to 0.

Step 3: Initialize the visited array with false values.

Step 4: Mark the starting vertex as visited (visited[s] = true) and enqueue the starting vertex (queue[rear++] = s).

Step 5: While the queue is not empty (front < rear):

a. Dequeue a vertex by setting curr = queue[front++] and print curr.

b. For each adjacent vertex (i from 0 to V):

If adj[curr][i] == 1 and visited[i] == false:

Mark visited[i] as true.

Enqueue i (queue[rear++] = i).

Step 6: Print the traversal result.

Step 7: Stop.


---

main

Step 1: Start.

Step 2: Read the number of vertices (V) and edges (E).

Step 3: Initialize the adjacency matrix adj[MAX][MAX] to 0.

Step 4: For each edge (u, v), update adj[u][v] and adj[v][u] to 1 (undirected graph).

Step 5: Read the starting vertex for BFS.

Step 6: Call bfs(adj, V, startVertex) to perform the BFS traversal.

Step 7: Stop.


---
