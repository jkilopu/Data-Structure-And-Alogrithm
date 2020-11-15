#include "graph.h"
#include <stdio.h>

#define V 6
#define E 8

int main(void)
{
    int nodes_data[V] = {0, 1, 2, 3, 4, 5};

    Edge es[E] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {3, 5}, {5, 2}, {0, 3}, {4, 5}}; // {tail, head}
    Graph graph = create_graph(nodes_data, V, sizeof(int), es, E);
    dfs_graph(graph);
    putchar('\n');
    bfs_graph(graph);

    return 0;
}