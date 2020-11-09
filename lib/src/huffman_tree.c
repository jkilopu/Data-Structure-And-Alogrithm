#include "huffman_tree.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static unsigned int num_nodes;

/* 根据字符及其权重创建哈夫曼树 */
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
    /* 每次循环：找到权重最小的两个结点，作为新结点的左右孩子，计算新结点的权重 */
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

/* 创建最初的叶子结点 */
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

/* 层次遍历打印哈夫曼树 */
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
            printf("%c-%d", node->wc.ch, node->wc.weight);
        else
        {
            printf("%d", node->wc.weight);
            Enqueue(&node->left, sizeof(H_Node *),  q);
            Enqueue(&node->right, sizeof(H_Node *), q);
        }
        next_level++;
        putchar('\t');
    }
    putchar('\n');

    DisposeQueue(q);
}

/* 创建哈夫曼树对应的编码表 */
Bit_Array *create_huffman_code(H_Tree *h_tree)
{
    Bit_Array *ba = calloc(NUM_CHAR, sizeof(Bit_Array));
    create_huffman_code_recursive_helper(h_tree, 0, 0, ba);
    return ba;    
}

static void create_huffman_code_recursive_helper(H_Tree *h_tree, unsigned int code, unsigned int len, Bit_Array *ba)
{
    if (h_tree->left == NULL && h_tree->right == NULL)
    {
        unsigned char ch = h_tree->wc.ch;
        (ba + ch)->len = len;
        size_t bytes_num = len / 8 + (len % 8 ? 1 : 0);             // 储存编码需要的字节数
        (ba + ch)->arr = calloc(bytes_num, sizeof(unsigned char));
        /* 复制code到arr */
        while (len--)
            if (code & (1 << len))
                ((ba + ch)->arr)[len / 8] |= 1 << (len % 8); 
        return;
    }
    create_huffman_code_recursive_helper(h_tree->left, code << 1, len + 1, ba);
    create_huffman_code_recursive_helper(h_tree->right, (code << 1) + 1, len + 1, ba);
}

/* 打印哈夫曼树中每个字符及其编码
 *
 * 参数 code 的类型为 unsigned int，则编码的长度最长为32位
 */
void print_huffman_code(H_Tree *h_tree, unsigned int code, unsigned int length)
{
    if (h_tree->left == NULL && h_tree->right == NULL)
    {
        printf("%c-", h_tree->wc.ch);
        print_bin(code, length);
        putchar('\n');
        return;
    }
    print_huffman_code(h_tree->left, code << 1, length + 1);           // 往左，该位为0
    print_huffman_code(h_tree->right, (code << 1) + 1, length + 1);    // 往右，该位为1
}

/* 打印code的二进制格式 */
void print_bin(unsigned int code, unsigned int length)
{
    while (length--)
    {
        if (code & (1 << length))
            putchar('1');
        else
            putchar('0');
    }
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

/* 删除编码表 */
void destroy_huffman_code(Bit_Array *ba)
{
    for (int i = 0; i < NUM_CHAR; i++)
        if (ba[i].arr)
        {
            free(ba[i].arr);
            ba[i].arr = NULL;
        }
    free(ba);
}

/* 删除哈夫曼树 */
void destroy_huffman_tree(H_Tree *h_tree)
{
    if (h_tree == NULL)
        return;
    destroy_huffman_tree(h_tree->left);
    h_tree->left = NULL;
    destroy_huffman_tree(h_tree->right);
    h_tree->right = NULL;
    free(h_tree);
}
