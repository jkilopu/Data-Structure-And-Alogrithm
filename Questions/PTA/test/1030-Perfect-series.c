#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX(a, b) a > b ? a : b
int comp(const void *a, const void *b);
int main(void)
{
    int i, j, n, p, max;
    long long *a; /* 用int可能会爆掉，因为有乘法 */

    scanf("%d%d", &n, &p);
    a = (long long *)malloc(n * sizeof(long long));
    for (i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    qsort(a, n, sizeof(long long), comp);
    /* 比较低效的做法（MAX可以少一些），而且不知道哪些地方有错 */
    // for (i = 0; i < n && a[i] <= a[0] * p; i++)
    // {
    //     for (j = 0; j <= i; j++)
    //         if (a[i] <= a[j] * p)
    //             max = MAX(max, i - j + 1);
    //         else
    //             break;
    // }
    /* 思路反过来，从不符合条件的地方开始，直至符合条件（不过还是超时）*/
    // for (i = n - 1, max = 0; i >= 0; i--)
    // {
    //     for (j = i; j <= i; j++)
    //     {
    //         if (a[i] <= a[j] * p)
    //         {
    //             max = MAX(max, i - j + 1);
    //             break;
    //         }
    //     }
    //     if (a[i] <= a[0] * p)
    //     {
    //         max = MAX(max, i + 1);
    //         break;
    //     }
    // }
    for (i = 0; i < n; i++)
    { // 遍历，将a[i]作为最小值
        for (j = i + max; j < n; j++)
        { // j为要满足可以更新数列长度的值，减少循环次数
            if (a[j] > a[i] * p)
                break;
            if (j - i + 1 > max)
                max = j - i + 1;
        }
        printf("%d\n", max);
        free(a);

        return 0;
    }
}
int comp(const void *a, const void *b)
{
    return *(long long *)a - *(long long *)b;
}