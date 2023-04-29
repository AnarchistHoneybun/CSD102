/*
Question: You are given a weighted undirected graph with 'n' nodes and 'm' edges. Your task is to write a program in C that finds the minimum path between two nodes.

The input for the program should consist of the following:

    The first line should contain two integers, 'n' and 'm', separated by a space, representing the number of nodes and edges in the graph, respectively.
    The next 'm' lines should contain three integers 'u', 'v', and 'w' separated by spaces, representing an undirected edge between nodes 'u' and 'v' with weight 'w'.
    The next line contains two integers 'm' and 'n' which calculate the minimum path between the two nodes

The output of the program should be as follows:

    If there's no path, then print -1
    Else print the weight of the path

Input:

4 4
0 1 2
1 2 3
2 3 1
0 3 4
0 3

Output:

4
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

int dijk(int graph[][MAX_NODES], int src, int dest, int n) {
    int dist[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = minDistance(dist, visited, n);

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return dist[dest];
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int graph[MAX_NODES][MAX_NODES];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int src, dest;

    scanf("%d %d", &src, &dest);

    int shortestPath = dijk(graph, src, dest, n);
    
    if(shortestPath == INT_MAX){
        printf("-1");
    }else{
        printf("%d",shortestPath);
    }

    

    return 0;
}
