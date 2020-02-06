#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
int main(void)
{
    List L1, L2, L3, L4;
    L1.head = NULL, L2.head = NULL, L3.head = NULL, L4.head = NULL;
    int i, a[] = {2, 5, 6, 9, 10}, b[] = {1, 2, 5, 6, 11, 99, 100, 101, 102, 103};
    for (i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        Add(&L1, a[i]);
        if (i < sizeof(b) / sizeof(int))
            Add(&L2, b[i]);
    }
    Print(&L1), Print(&L2);
    puts("#");
    Merge(&L1, &L2, &L3);
    Intersect(&L1,&L2,&L4);
    Print(&L1), Print(&L2), Print(&L3), Print(&L4);
    puts("#");
    Delete(&L3, a[2]); //删除L3的元素并不会影响L1
    Print(&L1), Print(&L2), Print(&L3), Print(&L4);
    Clear(&L1), Clear(&L2), Clear(&L3), Clear(&L4);

    return 0;
}