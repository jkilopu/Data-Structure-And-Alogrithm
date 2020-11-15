/**
 * 
 * 图：
 * 目前的数据结构：邻接表（用到了SList）
 * 目前构造函数创建的图：无向图
 * 
 * TODO:
 * 1. 图、链表的迭代器？（如何实现？）
 * 2. 删除图、图的本地构造函数
 * 3. 更多种图的储存方法选择（逆邻接表、邻接矩阵、十字链表。。。）
 * 4. 如何区分有向图和无向图，代码有什么区别
 * 5. 单元测试
 * 
 * 小问题：
 * 1. 邻接表种每个元素都是SList，都有elem_size=sizeof(unsigned int)，有点浪费，该怎么办？（分离出新的struct？）
 */
#ifndef _GRAPH_H
#define _GRAPH_H

#include "slist.h"
#include <ctype.h>

typedef struct _adjacency_list { // 继承struct _s_list
    struct _s_list plain_slist; // tail to head
    void *data;
} * Adj_List;

typedef struct _graph {
    Adj_List adj_arr; // 邻接表
    size_t elem_size;
    unsigned int V, E;
} * Graph;

typedef struct _edge {
    unsigned int arc_tail_idx;
    unsigned int arc_head_idx;
} Edge;

/* 创建一个最大结点数为V，元素大小为elem_size的空的泛型图 */
Graph create_empty_graph(const unsigned int V, const size_t elem_size);
/* 创建一个V个结点，E条边的泛型图 */
Graph create_graph(const void *data_arr, const unsigned int V, const size_t elem_size, const Edge es[], const unsigned int E);
void dfs_graph(const Graph graph);
static void dfs_graph_recursive_helper(const Adj_List adj_arr, const unsigned int idx, bool is_tranversed_arr[]);
void bfs_graph(Graph graph);
static void bfs_graph_recursive_helper(const Adj_List adj_arr, const unsigned int V, bool is_tranversed_arr[]);

#endif
