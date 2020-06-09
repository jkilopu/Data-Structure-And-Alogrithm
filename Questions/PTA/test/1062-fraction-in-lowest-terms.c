/* 辗转相除法 */
#include <stdio.h>

int gcd(int a, int b);

int main(void)
{
    int n1, m1, n2, m2, k, res[1000][2];

    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);

    double d1 = (double) n1 / m1, d2 = (double) n2 / m2;
    if (d1 > d2)
    {
        double tmp = d1;
        d1 = d2;
        d2 = tmp;
    }

    /* 处理 */
    int N = 0;
    for (int i = 1; i < k; i++)
    {
        double d = (double) i / k;
        if (gcd(i , k) == 1 && d > d1 && d < d2)
        {
            res[N][0] = i;
            res[N][1] = k;
            N++;
        }
    }

    /* 输出 */
    for (int i = 0; i < N; i++)
    {
        printf("%d/%d", res[i][0], res[i][1]);
        if (i != N - 1)
            putchar(' ');
    }

    return 0;
}

int gcd(int a, int b)
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}