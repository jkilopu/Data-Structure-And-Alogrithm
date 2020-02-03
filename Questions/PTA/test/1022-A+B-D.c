#include <stdio.h>
#include <math.h>
int main(void)
{
    long long int a, b, e;
    int d, i;
    char c[30];

    scanf("%lld %lld %d", &a, &b, &d);
    e = a + b;
    if (e == 0)
        putchar('0');
    for (i = 0; e; i++)
    {
        c[i] = e % d + '0';
        e /= d;
    }
    while(i--)
        putchar(c[i]);

    return 0;
}
/*总结:
1. 2e3表示的是2000,而不是8
2. 谨防数组越界
*/