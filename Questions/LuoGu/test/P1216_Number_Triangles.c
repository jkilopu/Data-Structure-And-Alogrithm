#include <stdio.h>
#include <stdlib.h>

#define MAX(__x, __y) ((__x > __y) ? (__x) : (__y))

int main(void)
{
    int n = 0, **dp = NULL;

    scanf("%d", &n);
    dp = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
        dp[i] = calloc((n + 1), sizeof(int));

    int max = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            int val = 0;
            scanf("%d", &val);
            dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - 1]) + val; // 递推式
            if (dp[i][j] > max)
                max = dp[i][j];
        }

    printf("%d\n", max);

    for (int i = 0; i <= n; i++)
        free(dp[i]);
    free(dp);

    return 0;
}