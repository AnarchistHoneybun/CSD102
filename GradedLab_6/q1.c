/*
Problem: You are given a weighted undirected graph with 'n' nodes and 'm' edges. Your task is to write a program in C that finds the graph's minimum spanning tree (MST).

The input for the program should consist of the following:

    The first line should contain two integers, 'n' and 'm', separated by a space, representing the number of nodes and edges in the graph, respectively.
    The next 'm' lines should contain three integers 'u', 'v', and 'w' separated by spaces, representing an undirected edge between nodes 'u' and 'v' with weight 'w'.

The output of the program should be as follows:

    If the given graph is not connected, print "-1".
    Otherwise, print the weight of the MST

Input:

4 5
0 1 2
1 2 3
2 3 4
3 0 5
0 2 1

Output:

10

Note example might be incorrect, kindly just refer to the input & output representation
*/

#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int cmp(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->w - b1->w;
}

int kruskalMST(struct Edge edges[], int n, int m) {
    int* parent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        parent[i] = -1;

    int edgeCount = 0, i = 0, weight = 0;
    while (edgeCount < n - 1 && i < m) {
        struct Edge next_edge = edges[i++];
        int x = find(parent, next_edge.u);
        int y = find(parent, next_edge.v);
        if (x != y) {
            Union(parent, x, y);
            weight += next_edge.w;
            edgeCount++;
        }
    }
    free(parent);
    if (edgeCount != n - 1)
        return -1;  // graph is not connected
    return weight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Edge* edges = (struct Edge*)malloc(m * sizeof(struct Edge));
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    qsort(edges, m, sizeof(struct Edge), cmp);

    int weight = kruskalMST(edges, n, m);
    printf("%d\n", weight);

    free(edges);
    return 0;
}
