#include <stdio.h>
int pow3(int a, int x);
int main(void)
{
    int a, b, i, res;

    scanf("%d%d", &a, &b);
    while (a != 0 || b != 0)
    {
        // a = pow3(a, b) % 1000;
        res = 1;
        while (b != 0)
        {
            if (b % 2 == 1) /* 神奇... */
                res = res * a % 1000;
            a = a * a % 1000;
            b /= 2;
        }
        printf("%d\n", res);
        scanf("%d%d", &a, &b);
    }

    return 0;
}
// 递归在幂很大时好像就不太行了
// int pow3(int a, int x)
// {
//     if (x == 0)
//         return 1;
//     if (x % 2 == 1)
//         return pow3(a % 1000, x - 1) * (a % 1000);
//     else
//         return pow3((a * a) % 1000, x / 2);
// }