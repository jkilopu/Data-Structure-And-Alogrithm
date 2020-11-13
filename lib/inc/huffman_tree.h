#ifndef _HUFFMAN_TREE_H
#define _HUFFMAN_TREE_H

#include <stdbool.h>
#include <limits.h>

#define NUM_CHAR UCHAR_MAX + 1

typedef struct _weighted_char
{
    unsigned char ch;
    int weight;
} Weighted_Char;

typedef struct _h_node
{
    Weighted_Char wc;
    struct _h_node *left, *right;
} H_Node;

/* 位数组：存储哈夫曼编码 */
typedef struct _bit_array
{
    unsigned char *arr;
    unsigned int len;
} Bit_Array;

typedef H_Node H_Tree;

H_Tree *create_huffman_tree(Weighted_Char weighted_chars[], int num);
Bit_Array *create_huffman_code_table(H_Tree *h_tree);
static void create_huffman_code_table_recursive_helper(H_Tree *h_tree, unsigned int code, unsigned int len, Bit_Array *ba);
void print_huffman_tree_weighted_char(H_Tree *h_tree);
void print_huffman_code(H_Tree *h_tree, unsigned int code, unsigned int length);
Bit_Array *create_huffman_code(char *seq, unsigned int num, Bit_Array *ba_table);
void print_bit_array(Bit_Array *ba);
H_Node **create_huffman_nodes(Weighted_Char weighted_chars[], int num);
void select_2_min(H_Node **nodes, int num, int *min_1, int *min_2);
void print_bin(unsigned int code, unsigned int length);
inline static bool is_pow_2(unsigned int a);
void destroy_huffman_code_table(Bit_Array *ba_table);
void destroy_huffman_tree(H_Tree *h_tree);

#endif
