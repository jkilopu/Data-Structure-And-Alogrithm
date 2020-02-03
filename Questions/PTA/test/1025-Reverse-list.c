#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct _node
{
    int value;
    int next;
} Node;
typedef struct _list
{
    int head;
} List;
int main(void)
{
    int n, k, i, j, group, address, tmp;
    int *pre;
    Node* pNode;
    List flist, *elist;

    scanf("%d %d %d", &flist.head, &n, &k);
    group = ceil((double)n / k);
    elist = (List *)malloc(group * sizeof(List));
    pre = (int *)malloc((k - 1) * sizeof(int));
    pNode = (Node *)malloc(100000 * sizeof(Node));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &address);
        scanf("%d %d", &(pNode + address)->value, &(pNode + address)->next);
    }
    //确定每段的头
    for (i = 0; i < n - 1; i++)
    {
        if(i == 0)
            tmp = flist.head;
        else
            tmp = pNode[tmp].next;
        if(i / k)
            elist[i / k].head = tmp;
    }
    //分组反转
    for (i = 0; i < group; i++)
    {
        if(i == group - 1)
            k = n % k;
        //准备反转
        for (j = 0; j < k - 1; j++)
        {
            if(j == 0)
                pre[j] = elist[i].head;
            else
                pre[j] = pNode[pre[j - 1]].next;
        }
        //单一组反转
        for (j = 0; j < k - 1; j++)
        {
            if(j == 0)
                tmp = pNode[elist[i].head].next;
            else
                tmp = pNode[tmp].next;
            pNode[tmp].next = pre[j];
        }
    }
    //连接各组
    
    return 0;
}