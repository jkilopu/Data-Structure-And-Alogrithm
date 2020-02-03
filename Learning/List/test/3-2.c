//依据P中的升序整数，打印L中的每一位
#include <stdio.h>
#include "list.h"
void PrintfLots(List *L, List *P);
int main(void)
{
    int i = 0, n;
    int a[] = {9, 7, 2, 3, 5, 8, 1};
    int b[] = {2, 3, 6};
    List L, P;
    L.head = NULL, P.head = NULL;
    for (i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        Add(&L, a[i]);
        if (i < sizeof(b) / sizeof(int))
            Add(&P, b[i]);
    }
    PrintfLots(&L, &P);

    return 0;
}
void PrintfLots(List *L, List *P)
{
    int i = 1, n;
    Node *l = L->head;
    Node *p = P->head;
    while (p)
    {
        n = p->value;
        while (i < n)
        {
            l = l->next;
            i++;
        }
        printf("%d ", l->value);
        p = p->next;
    }
}