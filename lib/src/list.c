#include "list.h"
void Add(List *pList, ElementType number) //注意这里传入的指针，实质是Node**
{
    Node *p;
    //add to linked-list
    p = (Node *)malloc(sizeof(Node)); //
    p->value = number;
    p->next = NULL;
    //attach
    if (pList->head)
    {
        pList->tail->next = p;
        pList->tail = p;
    }
    else
    {
        pList->head = p;
        pList->tail = pList->head;
    }
}
void Print(const List *pList)
{
    Node *p;
    for (p = pList->head; p; p = p->next)
    {
        if (p != pList->head)
            printf(" ");
        printf("%d", p->value);
    }
    printf("\n");
}
Node *Find(List *pList, ElementType number)
{
    Node *ret = NULL;
    // bool isFound = false;
    Node *p;
    for (p = pList->head; p; p = p->next)
    {
        if (p->value == number)
        {
            // printf("Got it!\n");
            // isFound = true;
            ret = p;
            break;
        }
    }
    // if(!isFound)
    //     printf("Not found.\n");
    return ret;
}
void Delete(List *pList, ElementType number)
{
    Node *p, *q;
    for (q = NULL, p = pList->head; p; q = p, p = p->next) //这里有q=p啊啊
    {
        if (p->value == number)
        {
            if (q)
                q->next = p->next; //不会出现野指针
            else
                pList->head = p->next;
            free(p);
            break;
        }
    }
}
void InsertAfter(List *pList, ElementType nFind, ElementType nInsert)
{
    Node *p, *q;
    if (p = Find(pList, nFind))
    {
        q = (Node *)malloc(sizeof(Node));
        q->value = nInsert;
        q->next = p->next;
        p->next = q;
    }
}
Node *Reverse(List *pList)
{
    Node *p, *next, *prev;
    if (pList->head == NULL || pList->head->next == NULL)
        return pList->head;
    prev = (Node *)malloc(1 * sizeof(Node));
    prev->next = pList->head;
    p = pList->head;
    while (p->next != NULL)
    {
        next = p->next;
        p->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    pList->head = prev->next;
    free(prev);
    return pList->head;
}
void Swap(List *pList, int n)
{
    Node *p = pList->head, *q, *pre;
    int i = 1;
    if (p->next != NULL) //不能只有一个节点
    {
        while (i++ < n)
            if (p->next->next)
            {
                pre = p; //pre必须有
                p = p->next;
            }
        q = p->next;          //q必须有
        if (p == pList->head) //头节点交换
            pList->head = q;
        else
            pre->next = q;
        if (p == pList->tail) //尾节点交换
            pList->tail = p;
        p->next = q->next;
        q->next = p;
    }
}
List *Merge(List *pL1, List *pL2, List *pL3)
{
    Node *p1 = pL1->head;
    Node *p2 = pL2->head;
    while (p1 && p2)
    {
        if (p1->value <= p2->value)
        {
            Add(pL3, p1->value);
            /* p3->next = p1;
             p3 = p1; 不能这么做!!!应为会改变L1或L2的结构 */
            p1 = p1->next;
        }
        else
        {
            Add(pL3, p2->value);
            p2 = p2->next;
        }
    }
    while (p1)
    {
        Add(pL3, p1->value);
        p1 = p1->next;
    }
    while (p2)
    {
        Add(pL3, p2->value);
        p2 = p2->next;
    }
    return pL3;
}
List *Intersect(List *pL1, List *pL2, List *pL3) //交集
{
    Node *p1 = pL1->head;
    Node *p2 = pL2->head;
    while (p1)
    {
        while (p1->value != p2->value && p2->next != NULL)
            p2 = p2->next;
        if (p1->value == p2->value)
            Add(pL3, p1->value);
        p1 = p1->next;
    }
    return pL3;
}
void Bsort(List *pList) //最低效率的冒泡排序
{
    ElementType temp;
    Node *p, *q, *t;
    for (t = pList->head, q = pList->tail; t; t = t->next)
    {
        for (p = pList->head; p != q; p = p->next)
        {
            if (p->value < p->next->value)
            {
                temp = p->value;
                p->value = p->next->value;
                p->next->value = temp;
            }
        }
    }
}
void Clear(List *pList)
{
    Node *p, *q;
    for (p = pList->head; p; p = q)
    {
        q = p->next;
        free(p);
    }
}