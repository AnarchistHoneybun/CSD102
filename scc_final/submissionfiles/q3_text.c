#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 5
#define INF 99999

// Graph representation using adjacency matrix
int graph[MAX_VERTICES][MAX_VERTICES];
int capacity[MAX_VERTICES][MAX_VERTICES];
int flow[MAX_VERTICES][MAX_VERTICES];
int parent[MAX_VERTICES];
bool visited[MAX_VERTICES];

// Initialize the graph and flow networks
void initializeGraph(int V) {
    memset(graph, 0, sizeof(graph));
    memset(capacity, 0, sizeof(capacity));
    memset(flow, 0, sizeof(flow));
}

// Add an edge to the graph
void addEdge(int start, int end, int weight) {
    graph[start][end] = 1; // Mark the edge as present
    capacity[start][end] = weight;
}

// Ford-Fulkerson algorithm to find the maximum flow in the network
int fordFulkerson(int V, int source, int sink) {
    int maxFlow = 0;
    while (true) {
        memset(visited, false, sizeof(visited));
        memset(parent, -1, sizeof(parent));
        visited[source] = true;

        // Depth-First Search to find an augmenting path
        bool foundPath = false;
        int stack[MAX_VERTICES];
        int top = -1;
        stack[++top] = source;

        while (top >= 0) {
            int u = stack[top--];
            for (int v = 0; v < V; v++) {
                if (!visited[v] && capacity[u][v] - flow[u][v] > 0) {
                    parent[v] = u;
                    visited[v] = true;
                    stack[++top] = v;
                    if (v == sink) {
                        foundPath = true;
                        break;
                    }
                }
            }
        }

        // If no augmenting path is found, exit the loop
        if (!foundPath) break;

        // Find the minimum capacity on the augmenting path
        int pathFlow = INF;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = (pathFlow < capacity[u][v] - flow[u][v]) ? pathFlow : capacity[u][v] - flow[u][v];
        }

        // Update the flow network
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            flow[u][v] += pathFlow;
            flow[v][u] -= pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

// Extract k disjoint paths from the flow network
void extractDisjointPaths(int V, int source, int sink, int k) {
    int pathsFound = 0;
    while (pathsFound < k) {
        memset(visited, false, sizeof(visited));
        int stack[MAX_VERTICES];
        int top = -1;
        stack[++top] = source;
        visited[source] = true;

        printf("Path %d: ", pathsFound + 1);

        // Depth-First Search to trace the path from source to sink
        while (top >= 0) {
            int u = stack[top--];
            for (int v = 0; v < V; v++) {
                if (!visited[v] && capacity[u][v] - flow[u][v] > 0 && graph[u][v]) {
                    visited[v] = true;
                    stack[++top] = v;

                    printf("%d -> ", u);

                    // Remove the edge to prevent it from being included in other paths
                    graph[u][v] = 0;
                    graph[v][u] = 1;

                    if (v == sink) {
                        printf("%d\n", v);
                        pathsFound++;
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    int V = 5; // Number of vertices in the graph
    int E = 10; // Number of edges in the graph
    int k = 2; // Number of disjoint paths we want to find

    initializeGraph(V);

    // Dummy data for edges
    int edges[10][3] = {
        {0, 1, 1},
        {0, 2, 1},
        {1, 2, 1},
        {1, 3, 1},
        {2, 1, 1},
        {2, 4, 1},
        {3, 2, 1},
        {3, 4, 1},
        {4, 3, 1},
        {4, 1, 1}
    };

    // Adding edges to the graph
    for (int i = 0; i < E; i++) {
        addEdge(edges[i][0], edges[i][1], edges[i][2]);
    }

    int source = 0; // Source vertex
    int sink = 4;   // Sink vertex

    int maxFlow = fordFulkerson(V, source, sink);

    if (maxFlow < k) {
        printf("No solution exists.\n");
    } else {
        printf("A solution exists.\n");
        extractDisjointPaths(V, source, sink, k);
    }

    return 0;
}