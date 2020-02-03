#include <stdio.h>
int main(void)
{
    int a, b, c, n, kase = 0;

    while(scanf("%d %d %d", &a, &b, &c) != EOF)
    {
        //求最小n
        for (n = 10; n <= 100; n++)
        {
            if(n % 3 == a && n % 5 == b && n && n % 7 == c)
                break;
        }
        //每个输入样例处理
        if(n <= 100)
            printf("Case %d: %d\n", ++kase, n);
        else
            printf("Case %d: No answer\n", ++kase);
    }

    return 0;
}