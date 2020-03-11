/* 
 * 一开始的思路就是推通项公式，但方法不正确（一项一项地推）
 * 以后看到这种非常规的数列还是把所有方法都试一遍吧
 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, i;

    float a0, a_last, *c, a1;
    while (scanf("%d", &n) != EOF)
    {
        scanf("%f%f", &a0, &a_last);
        c = (float *)malloc(sizeof(float) * n);
        for (i = 0; i < n; i++)
            scanf("%f", &c[i]);
        /* 分步计算: (n+1)A1 = nA0 + An+1 - 2[nC1 + (n-1)C2 + ... + 2Cn-1 + Cn] */
        a1 = n * a0 + a_last;
        for (i = 0; i < n; i++)
            a1 -= (n - i) * c[i] * 2;
        a1 /= n + 1;
        printf("%.2f\n", a1);
        free(c);
    }

    return 0;
}