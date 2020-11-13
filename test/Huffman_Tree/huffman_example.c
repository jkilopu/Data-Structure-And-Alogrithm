#include "huffman_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    Weighted_Char arr[10] = {{'a', 2}, {'b', 9}, {'c', 5}, {'d', 7}, {'e', 8}, {'f', 1}, {'g', 3}, {'h', 4}, {'i', 6}, {'j', 0}};
    H_Tree *h_tree = create_huffman_tree(arr, 10);
    puts("\nHuffman tree:");
    print_huffman_tree_weighted_char(h_tree);
    putchar('\n');

    puts("\nHuffman code:");
    puts("Format: ch-bits:");
    print_huffman_code(h_tree, 0, 0);
    putchar('\n');

    puts("\nHuffman code in array:");
    Bit_Array *ba_table = create_huffman_code_table(h_tree);
    puts("Format: ch-len-bits:");
    for (int i = 0; i < 10; i++)
    {
        unsigned int len = ba_table['a' + i].len;
        printf("%c-%u-", 'a' + i, len);
        print_bit_array(&ba_table['a' + i]);
        putchar('\n');
    }
    putchar('\n');

    char *seq = "abc";
    printf("\nHuffman coded sequence: %s\n", seq);
    Bit_Array *ba = create_huffman_code(seq, strlen(seq), ba_table);
    for (unsigned int i = 0; i < 3; i++)
        print_bit_array(&ba[i]);
    putchar('\n');

    free(ba);
    destroy_huffman_tree(h_tree);
    destroy_huffman_code_table(ba_table);
    puts("\nDone.");
    return 0;
}
