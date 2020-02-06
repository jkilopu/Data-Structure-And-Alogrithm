#include "self-adjusting-ar.h"
#include <stdio.h>
int main(void)
{
    Saar sa = CreateSaar(10);

    int i;
    for (i = 1; i <=10; i++)
        SAdd(sa, i);
    SPrint(SFind(sa, 11));

    return 0;
}
