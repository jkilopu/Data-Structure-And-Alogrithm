#include "huffman_tree.h"
#include <stdio.h>

int main(void)
{
    Weighted_Char arr[10] = {{'a', 2}, {'b', 9}, {'c', 5}, {'d', 7}, {'e', 8}, {'f', 1}, {'g', 3}, {'h', 4}, {'i', 6}, {'j', 0}};
    H_Tree *h_tree = create_huffman_tree(arr, 10);
    print_huffman_tree_weighted_char(h_tree);
    puts("Done.");
    return 0;
}