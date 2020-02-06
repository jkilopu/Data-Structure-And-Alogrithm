#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct _node{
    ElementType value;
    struct _node *next;
} Node;
typedef struct _list{
    Node* head;   
    Node* tail;
} List;
void Add(List *pList, ElementType number) //注意这里传入的指针，实质是Node**
{
    if(number!=-1)
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
void Print(const List *pList)
{
    Node *p;
    for (p = pList->head; p; p = p->next)
    {
        if(p!=pList->head)
            printf(" ");
        printf("%d", p->value);
    }
    printf("\n");
}
int main(void)
{
    List la, lb, lc;
    int n;
    la.head=NULL,lb.head=NULL,lc.head=NULL;
    do{
        scanf("%d", &n);
        Add(&la, n);
    }while(n!=-1);
    do{
        scanf("%d", &n);
        Add(&lb, n);
    }while(n!=-1);
    Merge(&la,&lb,&lc);
    Print(&lc);

    return 0;
}