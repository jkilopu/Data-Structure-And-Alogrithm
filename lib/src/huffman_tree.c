#include "huffman_tree.h"
#include <stdio.h>
#include <stdlib.h>

H_Tree *create_huffman_tree(Weighted_Char weighted_chars[], int num)
{
    if (num <= 1)
    {
        fprintf(stderr, "Too few characters\n");
        return NULL;
    }
    H_Node **nodes = create_huffman_nodes(weighted_chars, num);

    int min_1, min_2;
    for (int i = 0; i < num - 1; i++)
    {
        // 一步步缩小规模
        select(nodes, num - i, &min_1, &min_2);
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

static H_Node **create_huffman_nodes(Weighted_Char weighted_chars[], int num)
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
    if (h_tree == NULL)
        return;
    print_huffman_tree_weighted_char(h_tree->left);
    print_huffman_tree_weighted_char(h_tree->right);
    if (h_tree->left == NULL && h_tree->right == NULL)
        printf("%c %d\n", h_tree->wc.val, h_tree->wc.weight);
    else
        printf("%d\n", h_tree->wc.weight);
}

/* 找到权重的最小值和次小值(不重复) */
static void select(H_Node **nodes, int num, int *p_min_1, int *p_min_2)
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
