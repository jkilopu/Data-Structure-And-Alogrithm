#include "polynomial.h"
#include "fatal.h"
#include <stdbool.h>
struct _pnode
{
    ElementType coefficient;
    ElementType exponent;
    struct _pnode *next;
};
struct _polynomial
{
    PNode *head;
};
Polynomial CreatePolynomial(void)
{
    Polynomial po = (Polynomial)malloc(sizeof(PNode *));
    if (po == NULL)
        FatalError("Out of space!");
    po->head = NULL;
    PMakeEmpty(po);
    return po;
}
void PAdd(Polynomial po, ElementType coefficient, ElementType exponent)
{
    PNode *p = (PNode *)malloc(sizeof(PNode)), *q;
    if (p == NULL)
        FatalError("Out of space!");
    p->coefficient = coefficient;
    p->exponent = exponent;
    p->next = NULL;
    if (PIsEmpty(po))
        po->head = p;
    else
    {
        for (q = po->head; q->next; q = q->next)
            ;
        q->next = p;
    }
}
int PLength(Polynomial po)
{
    int len = 0;
    PNode *p = po->head;
    while (p)
    {
        p = p->next;
        len++;
    }
    return len;
}
void PClear(Polynomial po)
{
    PNode *p = po->head, *tmp;
    while (p)
    {
        tmp = p->next;
        free(p);
        p = tmp;
    }
    free(po);
}
void PClearElement(Polynomial po)
{
    PNode *p = po->head, *tmp;
    while (p)
    {
        tmp = p->next;
        free(p);
        p = tmp;
    }
    PMakeEmpty(po);
}
Polynomial PMerge(Polynomial po1, Polynomial po2, Polynomial po3)
{
    PNode *p1 = po1->head;
    PNode *p2 = po2->head;
    while (p1 && p2)
    {
        if (p1->exponent > p2->exponent)
        {
            PAdd(po3, p1->coefficient, p1->exponent);
            p1 = p1->next;
        }
        else if (p1->exponent < p2->exponent)
        {
            PAdd(po3, p2->coefficient, p2->exponent);
            p2 = p2->next;
        }
        else
        {
            PAdd(po3, p1->coefficient + p2->coefficient, p1->exponent);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1)
    {
        PAdd(po3, p1->coefficient, p1->exponent);
        p1 = p1->next;
    }
    while (p2)
    {
        PAdd(po3, p2->coefficient, p2->exponent);
        p2 = p2->next;
    }
    return po3;
}
Polynomial PMultiply(Polynomial po1, Polynomial po2, Polynomial po3)
{
    int i, len = PLength(po2);
    Polynomial poTmp[5];    /*5个存放位：存放位0、1用来储存po1被po2相邻两项乘后的多项式，
                            存放位2储存0、1合并后多项式，存放位3、4轮流储存结果多项式*/
    PNode *p = po1->head;
    PNode *q = po2->head;
    bool select;

    for (i = 0; i < 5; i++)
        poTmp[i] = CreatePolynomial();
    for (i = 0, select = false; q; i++)
    {
        while (p)
        {
            PAdd(poTmp[i], p->coefficient * q->coefficient, p->exponent + q->exponent);
            p = p->next;
        }
        if (i % 2 == 1 || (i == len - 1 && i % 2 == 0))
        {
            PMerge(poTmp[0], poTmp[1], poTmp[2]);
            if (select == false)
            {
                PMerge(poTmp[2], poTmp[3], poTmp[4]);
                PClearElement(poTmp[3]);
                select = true;
            }
            else
            {
                PMerge(poTmp[2], poTmp[4], poTmp[3]);
                PClearElement(poTmp[4]);
                select = false;
            }
            PClearElement(poTmp[0]), PClearElement(poTmp[1]), PClearElement(poTmp[2]);
            i = 0;
        }
        p = po1->head;
        q = q->next;
    }
    if (select == false)
    {
        po3->head = poTmp[3]->head;
        free(poTmp[3]);
        PClear(poTmp[4]);
    }
    else
    {
        po3->head = poTmp[4]->head;
        free(poTmp[4]);
        PClear(poTmp[3]);
    }
    PClear(poTmp[0]),PClear(poTmp[1]),PClear(poTmp[2]);
}
void PPrint(const Polynomial po)
{
    PNode *p;
    for (p = po->head; p; p = p->next)
        printf("%d-%d ", p->coefficient, p->exponent);
    printf("\n");
}
void PMakeEmpty(Polynomial po)
{
    po->head = NULL;
}
bool PIsEmpty(Polynomial po)
{
    return po->head == NULL;
}