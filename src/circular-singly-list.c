#include "circular-singly-list.h"
CList CreateCList(void)
{
    CList clist = (CList)malloc(2 * sizeof(CNode *));
    if (clist == NULL)
        FatalError("Out of space!");
    CMakeEmpty(clist);
    return clist;
}
CList CAdd(CList clist, ElementType number)
{
    CNode *p = (CNode *)malloc(sizeof(CNode));
    if (p == NULL)
        FatalError("Out of space!");
    p->value = number;
    if (CIsEmpty(clist))
    {
        clist->head = p;
        p->next = clist->head;
        clist->tail = clist->head;
    }
    else
    {
        p->next = clist->head;
        clist->tail->next = p;
        clist->tail = p;
    }
    return clist;
}
CList CDelete_n(CList clist, int order)
{
    CNode *p = clist->head, *front = NULL;
    if (p)
    {
        if (order == 0) //注意删除第0个时的情况
            front = clist->tail;
        while ((order--) > 0)
        {
            front = p;
            p = p->next;
        }
        front->next = p->next;
        if (p == clist->head)
            clist->head = p->next;
        if (p == clist->tail)
            clist->tail = front;
        free(p);
    }
    if (clist->head == NULL)
        return NULL;
    else
        return clist;
}
void CPrint(CList clist)
{
    CNode *p = clist->head;
    while (p->next != clist->head)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    if (clist->tail != NULL) //打印尾巴
        printf("%d", clist->tail->value);
    puts("");
}
CList CClearElement(CList clist)
{
    CNode *p = clist->head, *tmp = NULL;
    while (p->next != clist->head)
    {
        tmp = p->next;
        free(p);
        p = tmp;
    }
    free(p); //free掉tail
    CMakeEmpty(clist);
    return clist;
}
void CClear(CList clist)
{
    CNode *p = clist->head, *tmp = NULL;
    while (p->next != clist->head)
    {
        tmp = p->next;
        free(p);
        p = tmp;
    }
    free(p); //free掉tail
    free(clist);
}
void CMakeEmpty(CList clist)
{
    clist->head = NULL;
    clist->tail = NULL;
}
bool CIsEmpty(CList clist)
{
    return clist->head == NULL;
}
