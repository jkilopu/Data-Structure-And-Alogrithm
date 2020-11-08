#include "huffman_tree.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static unsigned int num_nodes;

H_Tree *create_huffman_tree(Weighted_Char weighted_chars[], int num)
{
    if (num <= 1)
    {
        fprintf(stderr, "Too few characters\n");
        return NULL;
    }
    H_Node **nodes = create_huffman_nodes(weighted_chars, num);
    num_nodes = 2 * num - 1;

    int min_1, min_2;
    for (int i = 0; i < num - 1; i++)
    {
        // 一步步缩小规模
        select_2_min(nodes, num - i, &min_1, &min_2);
        H_Node *n = malloc(sizeof(H_Node));
        n->right = nodes[min_1];
        n->left = nodes[min_2];
        n->wc.weight = (nodes[min_1])->wc.weight + (nodes[min_2])->wc.weight; // 每一个结点都有权重
        nodes[min_1] = n; // 最小值被替换为合并后结点
        if (min_2 != num - 1 - i) // 次小值不需要再被搜索
            nodes[min_2] = nodes[num - 1 - i];
    }

    H_Tree *h_tree = nodes[min_1]; // 头结点
    free(nodes);
    return h_tree;
}

H_Node **create_huffman_nodes(Weighted_Char weighted_chars[], int num)
{
    H_Node **nodes = malloc(sizeof(H_Node *) * num);
    for (int i = 0; i < num; i++)
    {
        nodes[i] = malloc(sizeof(H_Node));
        nodes[i]->wc = weighted_chars[i];
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
    }
    return nodes;
}

void print_huffman_tree_weighted_char(H_Tree *h_tree)
{
    Queue q = CreateQueue(num_nodes, sizeof(H_Node *));
    Enqueue(&h_tree, sizeof(H_Tree *), q);

    unsigned int next_level = 1;
    while(!IsEmpty(q))
    {
        H_Node *node = (*(H_Node **)FrontAndDequeue(sizeof(H_Node *), q));
        if (is_pow_2(next_level))
            putchar('\n');
        if (node->left == NULL && node->right == NULL)
            printf("%c-%d", node->wc.val, node->wc.weight);
        else
        {
            printf("%d", node->wc.weight);
            Enqueue(&node->left, sizeof(H_Node *),  q);
            Enqueue(&node->right, sizeof(H_Node *), q);
        }
        next_level++;
        putchar('\t');
    }

    DisposeQueue(q);
}

/* 找到权重的最小值和次小值(不重复)，返回其下标 */
void select_2_min(H_Node **nodes, int num, int *p_min_1, int *p_min_2)
{
    if (num <= 1)
    {
        fprintf(stderr, "Too few elements\n");
        return;
    }
    int min_1, min_2;
    min_1 = nodes[0]->wc.weight < nodes[1]->wc.weight ? 0 : 1;
    min_2 = min_1 ^ 1;
    for (int i = 2; i < num; i++)
    {
        if (nodes[i]->wc.weight < nodes[min_1]->wc.weight)
        {
            min_2 = min_1;
            min_1 = i;
        }
        else if (nodes[i]->wc.weight < nodes[min_2]->wc.weight)
            min_2 = i;
    }
    *p_min_1 = min_1;
    *p_min_2 = min_2;
}

/* 判断一个正整数是否是2的整次幂（0也行） */
inline static bool is_pow_2(unsigned int a)
{
    return !(a & (a - 1));
}