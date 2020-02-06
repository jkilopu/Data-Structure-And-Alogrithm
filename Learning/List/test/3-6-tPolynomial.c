#include <stdio.h>
#include "polynomial.h"
#include <time.h>
int main(void)
{
    int c1[] = {9, 5, 8, 2, 4, 5, 1, 2, 4, 5, 2, 4, 1, 4, 2}, e1[] = {15, 14, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int c2[] = {1, 1}, e2[] = {3, 2};
    int i;
    clock_t start, stop;
    double duration;
    Polynomial po1 = CreatePolynomial(), po2 = CreatePolynomial(), po_res = CreatePolynomial();
    
    for (i = 0; i < sizeof(c1) / sizeof(int); i++)
        PAdd(po1, c1[i], e1[i]);
    for (i = 0; i < sizeof(c2) / sizeof(int); i++)
        PAdd(po2, c2[i], e2[i]);
    PPrint(po1), PPrint(po2);
    puts("##");
    // PMerge(po1,po2,po_res);
    // start = clock();
    // PMultiply(po1, po1, po_res);
    // stop = clock();
    // duration =  (double)(stop - start) / CLOCKS_PER_SEC;
    // PPrint(po_res), printf("Time spent:%lf\n", duratiogitn);

    // start = clock();
    // PMultiply(po2, po1, po2);           /* 可以自己乘自己*/
    // stop = clock();
    // duration =  (double)(stop - start) / CLOCKS_PER_SEC;
    // PPrint(po2), printf("Time spent:%lf\n", duration);
    
    start = clock();
    PPow(po2, 10, po_res);
    stop = clock();
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    PPrint(po_res), printf("Time spent: %lf\n", duration);
    PPrint(po2);        //验证po2没有被改变
    PClear(po1), PClear(po2), PClear(po_res);

    return 0;
}