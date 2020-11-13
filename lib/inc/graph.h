#ifndef _GRAPH_H
#define _GRAPH_H

#include "slist.h"

typedef struct _graph_node {
    unsigned int pos;
    struct _graph_node *next;
} G_Node;

typedef struct _node_head {
    int data;
    struct _graph_node *next;
} Node_Head;

typedef struct _graph {
    Node_Head *adj;
    unsigned int V, E;
} Graph;

typedef struct _edge {
    unsigned int tail;
    unsigned int head;
} Edge;

Graph *create_empty_graph(const unsigned int V);
Graph *create_graph_with_nodes(const int data[], const unsigned int V, const Edge es[], const unsigned int E);

#endif
