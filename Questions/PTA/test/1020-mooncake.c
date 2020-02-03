#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
void floatSwap(float *a, float *b);
void intSwap(int *a, int *b);
int main(void)
{
    int n, s, i, t;
    int *p, *q;
    float *r, sum;
    bool isSorted;

    scanf("%d %d", &n, &s);
    p = (int *)malloc(n * sizeof(int));
    q = (int *)malloc(n * sizeof(int));
    r = (float *)malloc(n * sizeof(float));
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &q[i]);
    for (i = 0; i < n; i++)
        r[i] = (float)q[i] / (float)p[i];
    //内部多交换的冒泡排序
    for (isSorted = false, t = n; isSorted = !isSorted; t--)
    {
        for (i = 0; i < t - 1; i++)
        {
            if(r[i + 1] > r[i] && fabs(r[i + 1] - r[i]) > 1e-6)   //浮点数比较大小
            {
                intSwap(&p[i], &p[i + 1]);
                intSwap(&q[i], &q[i + 1]);
                floatSwap(&r[i], &r[i + 1]);     //这里r中的元素也必须交换
                isSorted = false;
            }
        }
        if(isSorted)
            break;
    }
    //计算最优方案下的总收益
    for (i = 0, sum = 0.0; s > 0 && i < n;i++)
    {
        if((s -= p[i]) > 0)          //此处必须有>0
            sum += q[i];
        else
            sum += (float)(s + p[i]) * r[i];
    }
    printf("%.2f\n", sum);

    return 0;
}
void floatSwap(float *a, float *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
void intSwap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}