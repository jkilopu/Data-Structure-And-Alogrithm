#include "graph.h"
#include <stdlib.h>

Graph *create_empty_graph(const unsigned int V)
{
    Graph *new_graph = malloc(sizeof(struct _graph));
    new_graph->V = V;
    new_graph->E = 0;
    new_graph->adj = calloc(V, sizeof(struct _node_head));
    return new_graph;
}

Graph *create_graph_with_nodes(const int data[], const unsigned int V, const Edge es[], const unsigned int E)
{
    Graph *new_graph = create_empty_graph(V);
    new_graph->E = E;
    for (unsigned int i = 0; i < V; i++)
        new_graph->adj[i].data = data[i];
    for (unsigned int i = 0; i < E; i++)
    {
        G_Node *g_node = malloc(sizeof(struct _graph_node));
        g_node->pos = es[i].head;
        g_node->next = new_graph->adj[es[i].tail].next;
        new_graph->adj[es[i].tail].next = g_node;
    }
    return new_graph;
}