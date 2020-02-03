#include <stdio.h>
#include "polynomial.h"
#include <time.h>
int main(void)
{
    int c1[] = {9, 5, 8, 2, 4, 5, 1, 2, 4, 5, 2, 4, 1, 4, 2}, e1[] = {15, 14, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int c2[] = {1, 4}, e2[] = {3, 1};
    int i;
    clock_t start, stop;
    double duration;
    Polynomial po1 = CreatePolynomial(), po2 = CreatePolynomial(), po_sum = CreatePolynomial();
    for (i = 0; i < sizeof(c1) / sizeof(int); i++)
        PAdd(po1, c1[i], e1[i]);
    for (i = 0; i < sizeof(c2) / sizeof(int); i++)
        PAdd(po2, c2[i], e2[i]);
    PPrint(po1), PPrint(po2);
    puts("##");
    // PMerge(po1,po2,po_sum);
    start = clock();
    PMultiply(po1, po2, po_sum);
    stop = clock();
    duration = (stop - start) / CLK_TCK;
    printf("Time spent:%lf ## ", duration), PPrint(po_sum);
    start = clock();
    PMultiply(po2, po1, po_sum);
    stop = clock();
    duration = (stop - start) / CLK_TCK;
    printf("Time spent:%lf ## ", duration), PPrint(po_sum);
    PClear(po1), PClear(po2), PClear(po_sum);

    return 0;
}