/*算了，完全不会（之前把题意理解错，搞得很复杂）。
与卡特兰数有关，还是动态规划呢。
https://blog.csdn.net/qq_41205417/article/details/95972275
https://www.cnblogs.com/crazily/p/9695267.html*/
#include <stdio.h>
int main(void)
{
    int i, j, n, ktl[30] = {0};

    scanf("%d", &n);
    ktl[0] = ktl[1] = 1;
    for (i = 2; i <= n; i++)
        for (j = 0; j < i; j++)
            ktl[i] += ktl[j] * ktl[i - j - 1];
    printf("%d", ktl[n]);

    return 0;