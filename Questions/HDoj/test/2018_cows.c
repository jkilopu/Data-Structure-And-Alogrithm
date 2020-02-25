/* 感觉很有意思的一道题
 * 1. 递归十分简洁，但仍然可以优化
 * 2. 循环感觉很优美
 * 错误：1. 题目描述不清，后面搞懂题目的意思了 
 *      2. 每次应该重新分配a的空间
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// int laomu(int m); //第m天的母牛数
int main(void)
{
    int i, n = 0, cows, adults, *a;

    while (scanf("%d", &n) && n != 0)
    {
        a = (int *)calloc(n, sizeof(int));
        /* 从第二年开始计算（默认第一年不生） */
        for (i = 1, adults = 1, cows = 1; i < n; i++)
        {
            adults += a[i]; /* 之前的小牛成年了 */
            if (i + 3 < n)
                a[i + 3] = adults; /* 今年生的小牛在第四个年头成年 */
            cows += adults;        /* 生下的小牛和成年母牛一样多 */
        }
        printf("%d\n", cows);
        free(a);
    }

    return 0;
}
// 神奇的递归（虽然很慢，但还可以用记忆化搜索优化） 825604416
// int laomu(int m) //第m天的母牛数
// {
//     if (m <= 4)
//         return m;
//     else
//         return laomu(m - 1) + laomu(m - 3);
// }
