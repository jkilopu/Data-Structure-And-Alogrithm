/* 依据一个链表中的升序整数，打印另一个链表中的每一个元素 */
#include <stdio.h>
#include "slist.h"

void PrintList_AccordingTo_PosInList(SList sl, SList sl_pos);

int main(void)
{
    int n;
    int a[] = {9, 7, 2, 3, 5, 8, 1};
    int b[] = {1, 2, 5};
    struct _s_list s1, s2;
    CreateLocalSList(&s1, sizeof(int));
    CreateLocalSList(&s2, sizeof(int));

    /* 将数组a、b按原顺序分别存入两个链表中 */
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        AddTailSList(&s1, &a[i]);
        if (i < sizeof(b) / sizeof(int))
            AddTailSList(&s2, &b[i]);
    }

    /* 输出 */
    PrintList_AccordingTo_PosInList(&s1, &s2);

    DisposeLocalSList(&s1);
    DisposeLocalSList(&s2);

    return 0;
}

/*
 * 参数：sl为储存元素的数组，sl_pos为储存sl中位置的数组
 * 功能：从sl_pos中得到位置，输出对应位置的sl的元素
 */
void PrintList_AccordingTo_PosInList(SList sl, SList sl_pos)
{
    Node p1 = sl->head;
    Node p2 = sl_pos->head;
    int i = 0;
    while (p2)
    {
        int n = *(int *)p2->data;
        while (i < n)
        {
            p1 = p1->next;
            i++;
        }
        printf("%d ", *(int *)p1->data);
        p2 = p2->next;
    }
}
