#ifndef _HUFFMAN_TREE_H
#define _HUFFMAN_TREE_H

#include <stdbool.h>

typedef char Element_Type;

typedef struct _weighted_char
{
    Element_Type val;
    int weight;
} Weighted_Char;

typedef struct _h_node
{
    Weighted_Char wc;
    struct _h_node *left, *right;
} H_Node;

typedef H_Node H_Tree;

H_Tree *create_huffman_tree(Weighted_Char weighted_chars[], int num);
void print_huffman_tree_weighted_char(H_Tree *h_tree);
H_Node **create_huffman_nodes(Weighted_Char weighted_chars[], int num);
void select_2_min(H_Node **nodes, int num, int *min_1, int *min_2);
inline static bool is_pow_2(unsigned int a);


#endif