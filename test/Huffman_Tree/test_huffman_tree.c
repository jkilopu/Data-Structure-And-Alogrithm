#include "huffman_tree.h"
#include "unit_test.h"
#include <stdlib.h>

#define NODES_NUM 5

void test_select_2_min_normal(void);
void test_select_2_min_same_value(void);

int main(void)
{
    test_select_2_min_normal();
    test_select_2_min_same_value();
    test_passed("select_2_min");
}

void test_select_2_min_normal(void)
{
    Weighted_Char wc[NODES_NUM] = {{'a', 90}, {'b', 50}, {'c', 40}, {'d', 60}, {'e', 30}};
    H_Node **nodes = create_huffman_nodes(wc, NODES_NUM);

    int min_1 = 0, min_2 = 0;
    select_2_min(nodes, NODES_NUM, &min_1, &min_2);
    check_int("min_1", 4, min_1);
    check_int("min_2", 2, min_2);

    for (int i = 0; i < NODES_NUM; i++)
        free(nodes[i]);
    free(nodes);
}

void test_select_2_min_same_value(void)
{
    /* First */
    Weighted_Char wc[NODES_NUM] = {{'a', 90}, {'b', 90}, {'c', 90}, {'d', 60}, {'e', 60}};
    H_Node **nodes = create_huffman_nodes(wc, NODES_NUM);

    int min_1 = 0, min_2 = 0;
    select_2_min(nodes, NODES_NUM, &min_1, &min_2);
    check_int("min_1", 3, min_1);
    check_int("min_2", 4, min_2);

    for (int i = 0; i < NODES_NUM; i++)
        free(nodes[i]);
    free(nodes);

    /* Second */
    Weighted_Char wc_2[NODES_NUM] = {{'a', 20}, {'b', 20}, {'c', 30}, {'d', 30}, {'e', 10}};
    nodes = create_huffman_nodes(wc_2, NODES_NUM);

    min_1 = 0, min_2 = 0;
    select_2_min(nodes, NODES_NUM, &min_1, &min_2);
    check_int("min_1", 4, min_1);
    check_int("min_2", 1, min_2);

    for (int i = 0; i < NODES_NUM; i++)
        free(nodes[i]);
    free(nodes);
}