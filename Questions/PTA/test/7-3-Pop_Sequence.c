/*
 * 栈相关的数学问题还真不简单：
 * 1. 栈pop的序列种数问题——分类讨论（得出卡特兰数）
 * 2. 栈pop序列的可能性——排除不可能（关注相邻pop操作）
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    unsigned short M, N, K;
    int16_t *a;

    scanf("%hu%hu%hu", &M, &N, &K);
    a = (int16_t *)malloc(sizeof(int16_t) * N);
    for (unsigned short i = 0; i < K; i++)
    {
        bool yes = true;
        for (unsigned short i = 0; i < N; i++)
            scanf("%hd", a + i);
        for (unsigned short i = 0; i < N; i++)
        {
            /* 超出容量 */
            if (a[i] - i > M)
            {
                yes = false;
                goto YES;
            }
            /* 逆序(eg:7、5)且大小在它们之间的数，在它们后面输出，是不可能的 */
            if (i != N - 1 && a[i] - a[i + 1] > 1)
            {
                for (int j = i + 2; j < N; j++)
                    if (a[j] < a[i] && a[j] > a[i + 1])
                    {
                        yes = false;
                        goto YES;
                    }
            }
        }
        YES: if (yes)
            puts("YES");
        else
            puts("NO");
    }
}