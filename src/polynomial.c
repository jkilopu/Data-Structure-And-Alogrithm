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
Polynomial PAdd(Polynomial po, ElementType coefficient, ElementType exponent)
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
    return po;
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
void PNClear(PNode *p)
{
    PNode *tmp;
    while (p)
    {
        tmp = p->next;
        free(p);
        p = tmp;
    }
}
void PClear(Polynomial po)
{
    PNClear(po->head);
    free(po);
}
Polynomial PClearElement(Polynomial po)
{
    PNode *p = po->head;
    PNClear(p);
    PMakeEmpty(po);
    return po;
}
Polynomial PMerge(Polynomial po1, Polynomial po2, Polynomial po3)           //不可以自己加自己，不能放到自己的位置
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
    return po3;             //未创建空间
}
Polynomial PMultiply(Polynomial po1, Polynomial po2, Polynomial po3) //可以自己参与运算，并指向自己
{
    int i, len = PLength(po2);
    Polynomial poTmp[5]; /*5个存放位：存放位0、1用来储存po1被po2相邻两项乘后的多项式，
                            存放位2储存0、1合并后多项式，存放位3、4轮流储存结果多项式*/
    PNode *p = po1->head;
    PNode *q = po2->head;
    PNode *p_backup = p, *q_backup = q, *tmp; //po1或po2与po3相同时，必须把po1或po2所指向的空间free
    bool select, is_same1 = false, is_same2 = false;

    if (p == po3->head)
        is_same1 = true;
    else if (q == po3->head)
        is_same2 = true;
    for (i = 0; i < 5; i++)
        poTmp[i] = CreatePolynomial();
    for (i = 0, select = false; q; i++)
    {
        //填充0、1
        while (p)
        {
            PAdd(poTmp[i], p->coefficient * q->coefficient, p->exponent + q->exponent);
            p = p->next;
        }
        //待0、1填充后，合并后放至2处。落单的与空多项式合并
        if (i % 2 == 1 || (i == len - 1 && i % 2 == 0))
        {
            PMerge(poTmp[0], poTmp[1], poTmp[2]);
            //交替使用3、4
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
            //清空0、1
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
    PClear(poTmp[0]), PClear(poTmp[1]), PClear(poTmp[2]);
    //判断po1或po2与po3是否相同
    if (is_same1)
        PNClear(p_backup);
    else if (is_same2)
        PNClear(q_backup);

    return po3; //最终创建了一片空间，po3指向该片空间
}
Polynomial PPow(Polynomial po, unsigned int N, Polynomial po_output) //使用迭代，递归的做法太难受
{
    //清空po_output，仅保留指针
    PClearElement(po_output);
    PAdd(po_output, 1, 0);
    //复制po，防止po被修改
    Polynomial poTmp = CreatePolynomial();
    PCopy(poTmp, po);
    while (N > 0)
    {
        if (N % 2 == 1)
            PMultiply(po_output, poTmp, po_output);
        PMultiply(poTmp, poTmp, poTmp);
        N /= 2;
    }
    PClear(poTmp);
    return po_output;
}
Polynomial PCopy(Polynomial po_target, Polynomial po_source)
{
    PNode *p = po_source->head;
    while (p)
    {
        PAdd(po_target, p->coefficient, p->exponent);
        p = p->next;
    }
    return po_target;
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