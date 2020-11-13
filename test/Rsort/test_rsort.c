//单链表实现基数排序
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "slist.h"
#include "rsort.h"
int main(void)
{
    int i;
    int a[] = {23, 124, 213, -99, 329, 211, 346, 235, 197, 123, 342, 123};
    const int N = 2;
    Rsort(a, N, sizeof(a) / sizeof(int));
    //输出已排序数列
    for (i = 0; i < sizeof(a) / sizeof(int); i++)
        printf("%d ", a[i]);

    return 0;
}