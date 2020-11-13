#include "graph.h"

int main(void)
{
    int nodes_data[5] = {0, 1, 2, 3, 4};
    Edge es[4] = {{0, 1}, {1, 3}, {2, 3}, {3, 4}};
    Graph *graph = create_graph_with_nodes(nodes_data, 5, es, 4);

}