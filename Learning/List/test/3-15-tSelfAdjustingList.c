#include "self-adjusting-ar.h"
#include <stdio.h>
int main(void)
{
    Saar sa = CreateSaar(10);

    int i;
    for (i = 1; i <=10; i++)
        SAAdd(sa, i);
    SAPrint(SAFind(sa, 11));

    return 0;
}
