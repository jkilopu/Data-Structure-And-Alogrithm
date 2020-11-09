#include "huffman_tree.h"
#include <stdio.h>

int main(void)
{
    Weighted_Char arr[10] = {{'a', 2}, {'b', 9}, {'c', 5}, {'d', 7}, {'e', 8}, {'f', 1}, {'g', 3}, {'h', 4}, {'i', 6}, {'j', 0}};
    H_Tree *h_tree = create_huffman_tree(arr, 10);
    print_huffman_tree_weighted_char(h_tree);

    puts("\nHuffman code:");
    puts("Format: ch-bits:");
    print_huffman_code(h_tree, 0, 0);

    puts("\nHuffman code in array:");
    Bit_Array *ba = create_huffman_code(h_tree);
    puts("Format: ch-len-bits:");
    for (int i = 0; i < 10; i++)
    {
        unsigned int len = ba['a' + i].len;
        printf("%c-%u-", 'a' + i, len);
        unsigned int bytes_num = len / 8 + (len % 8 ? 1 : 0);
        for (int j = 0; j < bytes_num; j++)
        {
            unsigned int code = (ba['a' + i].arr)[j];
            print_bin(code, (j == bytes_num - 1 ? len % 8 : 8));
            putchar('\n');
        }
    }
    putchar('\n');

    destroy_huffman_tree(h_tree);
    destroy_huffman_code(ba);
    puts("Done.");
    return 0;
}