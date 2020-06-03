#include <stdio.h>
int main(void)
{
    int n, N, ans;

    scanf("%d", &N);
    while(N--)
    {
        scanf("%d", &n);
        ans = 2 * n * n - n + 1; /* 推出的公式(详见notability) */
        printf("%d\n", ans);
    }

    return 0;
}