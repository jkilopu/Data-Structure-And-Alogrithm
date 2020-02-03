#include "list.h"
#include "Rsort.h"
#include <stdbool.h>
int GetDigit(int x, int y, int N)
{
    int i, ret, t = 1;
    for (i = 0; i < y; i++)
        t *= N;
    if (y > 0)
        ret = (x % t) / (t / N);
    else
        ret = 0;
    return ret;
}
void Rsort(ElementType a[], int N, int length)
{
    int i = 0, j = 1, k, tmp, passes;              //passes:位的个数（循环、分配次数）
    List *list = (List *)malloc(N * sizeof(List)); //N个基就有N个表
    Node *p;
    bool isHighest = false;
    //头节点初始化为NULL
    for (i = 0; i < N; i++)
    {
        list[i].head = NULL;
        list[i].tail = NULL;
    }
    //检测最高位
    while (!isHighest)
    {
        isHighest = true;
        for (i = 0; i < length; i++)
        {
            tmp = GetDigit(a[i], j, N);
            if (tmp > 0)
                isHighest = false;
        }
        j++;
    }
    //开始排序
    for (passes = j - 1, j = 1; j < passes; j++)
    {
        //删除、分配
        for (i = 0; i < length; i++)
        {
            tmp = GetDigit(a[i], j - 1, N);
            Delete(&list[tmp], a[i]);
            tmp = GetDigit(a[i], j, N);
            Add(&list[tmp], a[i]);
        }
        //重新排列啊!!!!
        for (i = 0, k = 0; i < N; i++)
        {
            p = list[i].head;
            while (p)
            {
                a[k++] = p->value;
                p = p->next;
            }
        }
    }
}