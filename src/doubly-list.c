#include "doubly-list.h"

DList CreateDList(void)
{
    DList d;
    d = (DList)malloc(2 * sizeof(DNode *));
    if (d == NULL)
        FatalError("Out of space!");
    DMakeEmpty(d);
    return d;
}
void DMakeEmpty(DList dlist)
{
    dlist->head = NULL;
    dlist->tail = NULL;
}
void DAdd(DList dlist, ElementType number)
{
    DNode *p;
    p = (DNode *)malloc(sizeof(DNode));
    if (p == NULL)
        FatalError("Out of space!");
    p->value = number;
    p->next = NULL;
    if (DIsEmpty(dlist))
        dlist->head = p;
    else
        dlist->tail->next = p;
    p->front = dlist->tail;
    dlist->tail = p; //尾巴总是为p
}
void DDelete(DList dlist, ElementType number)
{
    DNode *p = DFind(dlist, number);
    if (p != NULL)
    {
        if (p->front != NULL)
            p->front->next = p->next;
        else
            dlist->head = p->next; // 头节点重设
        if (p->next != NULL)
            p->next->front = p->front;
        else
            dlist->tail = p->front; // 尾节点重设
        free(p);
    }
}
int DPopHead(DList dlist)
{
    DNode *p = dlist->head;
    ElementType tmp;
    if (p == NULL)
        Error("Empty head!");
    tmp = p->value;
    dlist->head = dlist->head->next;
    // dlist->head->front = NULL;
    free(p);
    return tmp;
}
void DSwap(DList dlist, ElementType number)
{
    DNode *high = dlist->head;
    int i = 1;
    if (high->next != NULL) //必须有一个节点
    {
        while (i++ < number)
            if (high->next->next)
                high = high->next;
        DNode *low = high->next;
        if (high == dlist->head) //头节点交换
        {
            dlist->head = low;
            low->front = NULL;
        }
        else //处理high的后连接关系
        {
            high->front->next = low;
            low->front = high->front;
        }
        if (low == dlist->tail) //尾节点交换
        {
            dlist->tail = high;
            high->next = NULL;
        }
        else //处理low的前连接关系
        {
            high->next = low->next;
            low->next->front = high;
        }
        low->next = high;
        high->front = low;
    }
}
DNode *DFind(const DList dlist, ElementType number)
{
    DNode *p, *ret = NULL;
    for (p = dlist->head; p; p = p->next)
        if (p->value == number)
        {
            ret = p;
            break;
        }
    return ret;
}
void DPrint(const DList dlist)
{
    for (DNode *p = dlist->head; p; p = p->next)
        printf("%d ", p->value);
    printf("\n");
}
bool DIsEmpty(const DList dlist)
{
    return dlist->head == NULL;
}
void DClear(DList dlist)
{
    DNode *p = dlist->head, *q;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    free(dlist);
}