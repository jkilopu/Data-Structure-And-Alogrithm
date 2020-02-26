#include "doubly-list.h"
#include <stdio.h>
int main(void)
{
    DList dlist = CreateDList();
    int i, n = 10;
    for (i = 0; i < n; i++)
        DAdd(dlist, i);
    DPrint(dlist);
    // DDelete(dlist, 1);
    // DPrint(dlist);
    printf("%d\n", DPopHead(dlist));
    DPrint(dlist);
    DClear(dlist);
    return 0;
}