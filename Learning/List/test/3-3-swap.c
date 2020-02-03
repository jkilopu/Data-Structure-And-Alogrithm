#include <stdio.h>
#include "list.h"
#include "doubly-list.h"
int main(void)
{
    int i, n, a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    List list;
    list.head = NULL;
    DList dlist = CreateDList();

    scanf("%d", &n);
    for (i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        Add(&list, a[i]);
        DAdd(dlist, a[i]);
    }
    Print(&list);
    Swap(&list, n);
    Print(&list);

    DPrint(dlist);
    DSwap(dlist, n);
    DPrint(dlist);

    DClear(dlist);
    Clear(&list);
    return 0;
}