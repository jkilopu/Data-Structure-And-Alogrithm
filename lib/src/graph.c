#include "graph.h"
#include "queue.h"
#include "fatal.h"
#include <string.h>
#include <stdbool.h>

Graph create_empty_graph(const unsigned int V, const size_t elem_size)
{
    Graph new_graph = malloc_fatal(sizeof(struct _graph), "create_empty_graph - new_graph");
    new_graph->V = V;
    new_graph->E = 0;
    new_graph->adj_arr = calloc_fatal(V, sizeof(struct _adjacency_list), "create_empty_graph - new_graph->adj_arr"); // data成员为空，代表图中没有结点
    for (unsigned int i = 0; i < V; i++)
        CreateLocalSList(&new_graph->adj_arr[i].plain_slist, sizeof(unsigned int)); // 邻接表初始化，头指针和尾指针皆为NULL，没有边
    new_graph->elem_size = elem_size;
    return new_graph;
}

Graph create_graph(const void *data_arr, const unsigned int V, const size_t elem_size, const Edge es[], const unsigned int E)
{
    Graph new_graph = create_empty_graph(V, elem_size);
    new_graph->E = E;
    /* 创建结点及其邻接表 */
    for (unsigned int i = 0; i < V; i++)
    {
        new_graph->adj_arr[i].data = malloc_fatal(sizeof(new_graph->elem_size), "create_graph_with_nodes");
        void *src_addr = (unsigned char *)data_arr + elem_size * i; // copy
        memcpy(new_graph->adj_arr[i].data, src_addr, new_graph->elem_size);
    }
    /* 创建边 */
    for (unsigned int i = 0; i < E; i++)
    {
        unsigned int arc_head_idx = es[i].arc_head_idx;
        unsigned int arc_tail_idx = es[i].arc_tail_idx;
        InsertHeadSList(&new_graph->adj_arr[arc_tail_idx].plain_slist, &arc_head_idx); // 尾到头
        InsertHeadSList(&new_graph->adj_arr[arc_head_idx].plain_slist, &arc_tail_idx); // 头到尾
    }
    return new_graph;
}

void dfs_graph(const Graph graph)
{
    if (graph == NULL || graph->V == 0)
        return;
    bool *is_tranversed_arr = calloc_fatal(graph->V, sizeof(bool), "dfs_graph");
    dfs_graph_recursive_helper(graph->adj_arr, 0, is_tranversed_arr);
    free(is_tranversed_arr);
}

static void dfs_graph_recursive_helper(const Adj_List adj_arr, const unsigned int idx, bool is_tranversed_arr[])
{
    if (is_tranversed_arr[idx])
        return;
    printf("%d ", *(int *)adj_arr[idx].data);
    is_tranversed_arr[idx] = true;
    Node p = adj_arr[idx].plain_slist.head;
    while (p)
    {
        unsigned int next_idx = *(unsigned int *)p->data;
        dfs_graph_recursive_helper(adj_arr, next_idx, is_tranversed_arr);
        p = p->next;
    }
}

void bfs_graph(Graph graph)
{
    if (graph == NULL || graph->V == 0)
        return;
    bool *is_tranversed_arr = calloc_fatal(graph->V, sizeof(bool), "bfs_graph");
    bfs_graph_recursive_helper(graph->adj_arr, graph->V, is_tranversed_arr);
    free(is_tranversed_arr);
}

/*
 * 两种bfs的方式：
 * 1. 在入队前访问，并设置标志位
 * 2. 在出队后访问，并设置标志位
 * 
 * 对于树，两者都行，因为树中没有“环”
 * 
 * 对于图，使用第2种方式的话。因为存在环路，可能会Enqueue同一个结点（此时该结点对应的标志位尚未被设置）
 * 所以Queue的长度需要大于V（不知道最大是多少，可能这是一个神奇的数学问题）
 * 
 * 选择第1种方式可以避免这个问题
 */
static void bfs_graph_recursive_helper(const Adj_List adj_arr, const unsigned int V, bool is_tranversed_arr[])
{
    struct QueueRecord local_queue;
    CreateLocalQueue(&local_queue, V, sizeof(unsigned int));
    unsigned int zero_unsigned_int = 0;
    printf("%d ", *(int *)adj_arr[0].data);
    Enqueue(&zero_unsigned_int, &local_queue);
    is_tranversed_arr[0] = true;

    while (!IsEmpty(&local_queue))
    {
        unsigned int idx = *(unsigned int *)FrontAndDequeue(&local_queue);
        for (Node p = adj_arr[idx].plain_slist.head; p; p = p->next)
        {
            unsigned int next_idx = *(unsigned int *)p->data;
            if (!is_tranversed_arr[next_idx])
            {
                is_tranversed_arr[next_idx] = true;
                printf("%d ", *(int *)adj_arr[next_idx].data);
                Enqueue(p->data, &local_queue);
            }
        }
    }

    DisposeLocalQueue(&local_queue);
}
