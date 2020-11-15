/* 求两个有序链表的交集和并集 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "slist.h"

void print_int_data(void *data);
int cmp(void *a, void *b);

int main(void)
{
    struct _printable_s_list ps1, ps2, ps3, ps4;
    CreateLocalPrintableSList(&ps1, sizeof(int), print_int_data);
    CreateLocalPrintableSList(&ps2, sizeof(int), print_int_data);
    CreateLocalPrintableSList(&ps3, sizeof(int), print_int_data);
    CreateLocalPrintableSList(&ps4, sizeof(int), print_int_data);

    /* 添加待会要操作的两个链表的元素 */
    int i, a[] = {2, 5, 6, 9, 10}, b[] = {1, 2, 5, 6, 11, 99, 100, 101, 102, 103};
    for (i = 0; i < sizeof(a) / sizeof(int); i++)
        AddTailSList(&ps1.slist, &a[i]);
    for (i = 0; i < sizeof(b) / sizeof(int); i++)
        AddTailSList(&ps2.slist, &b[i]);

    
    PrintSList(&ps1), PrintSList(&ps2);
    puts("#");

    /* 求交集和并集 */
    MergeLocalSList(&ps1.slist, &ps2.slist, &ps3.slist, cmp);
    IntersectLocalSList(&ps1.slist, &ps2.slist, &ps4.slist, cmp);
    PrintSList(&ps1), PrintSList(&ps2), PrintSList(&ps3), PrintSList(&ps4);
    puts("#");

    /* 验证ps3和ps4是否为copy */
    DeleteNodeSList(&ps3.slist, &a[2]); //删除ps3的元素并不会影响ps1
    PrintSList(&ps1), PrintSList(&ps2), PrintSList(&ps3), PrintSList(&ps4);
    DisposeLocalPrintableSList(&ps1), DisposeLocalPrintableSList(&ps2), DisposeLocalPrintableSList(&ps3), DisposeLocalPrintableSList(&ps4);

    return 0;
}

void print_int_data(void *data)
{
    printf("%d", *(int *)data);
}

/* 由小到大 */
int cmp(void *a, void *b)
{
    int x = *(int *)a, y = *(int *)b;
    if (x > y)
        return 1;
    else if (x < y)
        return -1;
    else
        return 0;
    // 不能用，*(int *)a - *(int *)b;，因为可能会溢出
}
